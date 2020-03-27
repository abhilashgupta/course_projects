#include <pthread.h>
#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#define NUM_THREADS 4
using  namespace std;

//int thread_ids[3] = {0,1,2};
pthread_mutex_t buff_mutex;
pthread_cond_t buff_cond[4];
pthread_cond_t send_cond;
int count;
int blocked;
int running;

typedef struct {
	int target_id;
	int sender_id;
	char msg[100];
} data;

queue<data> mydata[4];
int state[4];
void check_status() {
	
	if (blocked == running && running > 0) {
		for( int i =0 ; i <4 ; i++) {
			if (state[i] == 2 && mydata[i].empty() == 0) {
				return;
			}
			else if (state[i] == 1 && count < 20){
				return;
			}
		}
		cout<<"deadlock found\n";
		exit(0);
	}
}

string recv (int i) {
	int id = i;
	pthread_mutex_lock(&buff_mutex);
	if (mydata[id].empty()) {
	//	cout<<"blocked : "<<id<<endl;
		blocked++;
		state[i] = 2;
		check_status();
		pthread_cond_wait(&buff_cond[i], &buff_mutex);
		blocked--;
		state[i] = 0;
		//check_status();
	}		
		
		
	//	cout<<"freed : "<<id<<endl;
		string s = mydata[id].front().msg;
		mydata[id].pop();
		count--;
		pthread_cond_signal(&send_cond);
		pthread_mutex_unlock(&buff_mutex);
		
		return s;
}

void send (data d) {

	pthread_mutex_lock(&buff_mutex);
	int id = d.target_id;
	if (count == 20) {
		blocked++;
		state[d.sender_id] = 1;
		check_status();
		pthread_cond_wait(&send_cond, &buff_mutex);
		blocked--;
		state[d.sender_id] = 0;
		//check_status();
	}
	
	
//	 cout<<"freed_s : "<<d.sender_id<<endl;
	
	 cout<<"sent message, sid: "<<d.sender_id <<" tid: "<<id <<" msg: "<<d.msg<<endl;;
	 
	 mydata[id].push(d);
	 count++;
	
	 
	pthread_cond_signal(&buff_cond[id]);
	pthread_mutex_unlock(&buff_mutex);
}
   					 
void *PrintHello(void *threadid)
{
	long hid,tid; //host or sender thread id, target id
	hid = (long)threadid;
	pthread_mutex_lock(&buff_mutex);
	running++;
	state[hid] = 0;
	check_status();
	pthread_mutex_unlock(&buff_mutex);
   
   vector<string> rcvdmsgs;
   char line[100];
   string word;
   //printf("Hello World! It's me, thread #%ld!\n", hid);
   	char fname[100];
	sprintf(fname, "%ld.txt", hid);
    ifstream ifs(fname);
    //cout<<fname<<" : filename "<<endl;
    while (ifs.good()) {
    	//if (ifs.good()) {
    		ifs >> word;
    		if (word == "send") {
    			data dt;
    			ifs >> tid;
    			ifs  >> line;
    			dt.target_id = tid;
    			dt.sender_id = hid;
    			strcpy(dt.msg, line);
    			send(dt);	
    		}
    		else if (word == "recv") {
				string s = recv(hid);
				rcvdmsgs.push_back(s);
    		}
    		
    	//}
    	//else cout<<"file end reached\n";
    }
    	
 	
 	pthread_mutex_lock(&buff_mutex);
  cout<<"closing thread : "<<hid<<endl;
   running--;
   check_status();
   pthread_mutex_unlock(&buff_mutex);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	int rc;
	long t;
	data mydat;
	count = blocked = running  = 0;
	/*
	for (int i =0 ; i<4 ;i++){
		blocked[i] = running[i] = 0;
	}
	/* Initialize mutex and condition variable objects */
	pthread_mutex_init(&buff_mutex, NULL);
	pthread_cond_init (&buff_cond[1], NULL);
	pthread_cond_init (&buff_cond[2], NULL);
	pthread_cond_init (&buff_cond[3], NULL);
	pthread_cond_init (&buff_cond[4], NULL);
	pthread_cond_init (&send_cond, NULL);

	/* For portability, explicitly create threads in a joinable state */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for(t=0; t<NUM_THREADS; t++){
		printf("In main: creating thread %ld\n", t);
		/*cin>>mydat.target_id;
		cin>>mydat.sender_id;
		cin>>mydat.msg;*/
		rc = pthread_create(&threads[t], &attr, PrintHello, (void *)t);
		if (rc){
			 printf("ERROR; return code from pthread_create() is %d\n", rc);
			 exit(-1);
		}
   	}

   	/* Wait for all threads to complete */
	  for (int i=0; i<NUM_THREADS; i++) {
	    pthread_join(threads[i], NULL);
	   // cout<< "exitted for "<<i+1<<"th time"<<endl;
	  }
   
   

	/* Clean up and exit */
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&buff_mutex);
	pthread_cond_destroy(&send_cond);
	pthread_cond_destroy(&buff_cond[0]);
	pthread_cond_destroy(&buff_cond[1]);
	pthread_cond_destroy(&buff_cond[2]);
	pthread_cond_destroy(&buff_cond[3]);
	//cout<<"hahaha\n";

	pthread_exit(NULL);
return 0;
}
