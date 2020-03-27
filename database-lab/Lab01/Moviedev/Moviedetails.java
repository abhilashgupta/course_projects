//Assumption: both the files contain equal number of movies and they are ordered in the same manner
//i.e. they are identical  by the movie name in each line
package moviedev;
import java.util.*;
import java.lang.*;
import java.io.*;
public class Moviedetails{

	public static void main(String[] args0) throws IOException{
		
		BufferedReader br = null;
		BufferedReader br1 = null;
		//try {
 
			String s1,s2;
			//iniatilising readers for bith csv files
			br = new BufferedReader(new FileReader("movieinfo.csv"));
			br1 = new BufferedReader(new FileReader("movieratings.csv"));
			HashMap<String,Movie> film = new HashMap<String,Movie>();//hashmap to store data
			
			//reading data from csv files and storing into hashmap
			while (((s1 = br.readLine()) != null) && ((s2 = br1.readLine()) != null)) {
				
				String[] broken2 = s2.split(":");
				s1 = s1 +":" +broken2[1];
				
				String[] broken1 = s1.split(":");
				String[] broken3 = broken1[4].split(",");
				for(int k =0;k<broken3.length;k++) {
					broken3[k] = broken3[k].trim();
				}
				;
				Movie mo1 = new Movie();
				mo1.name = broken1[0].trim();
				mo1.Director = broken1[1].trim();
				mo1.year = Integer.parseInt(broken1[2].trim());
				mo1.genre = broken1[3].trim();
				mo1.Actors = broken3;
				mo1.rating = Float.parseFloat(broken1[5].trim());
				
				film.put(broken1[0],mo1);
				
				
				
			}
			
			
			
			
			while(true) {
				String sa = null;
				//reading input from user
				try{
					BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
					sa = br2.readLine();
				} catch (IOException e){
					e.printStackTrace();
				}
				
				String[] sa1 =  sa.split(" ");
				//q0 condition
				if (sa1.length == 1){
					if (sa1[0].equals("q0")){
						return;
					}
					
						
				}
				
				else if(sa1.length >=1) {
					//q2 condition
					if (sa1[0].equals("q1")){
						sa = sa.substring(sa1[0].length()+1);
					
						Movie mn = new Movie();
						mn = film.get(sa);
						if (mn == null) {
							System.out.println("Oops! No such movie in database");
						}
						else
						System.out.println(mn.Director);
						
							}
					//q2 condition
					else if (sa1[0].equals("q2")){
						ArrayList<String> sq = new ArrayList<String>();
						String sd = sa.substring(sa1[0].length()+1);
						
						
						for (Map.Entry<String,Movie> entry : film.entrySet()) {
							
							for ( String kidding: entry.getValue().Actors) {
								if (sd.equals(kidding)){
									
									sq.add(entry.getKey());
								}
								
							}
							
						}
					
						if (sq.size() == 0){
								System.out.println("Oops! The Given Actor hasn't acted in a single movie listed in the database");
							}
							else {
								for (String item: sq){
									System.out.println(item);
								}
							}
					}
					//q3 condition
					else if (sa1[0].equals("q3")){
						int ik = Integer.parseInt(sa1[1]);
						String ig = null;
						double fl =0.0;
						
						for (Map.Entry<String,Movie> entry : film.entrySet()) {
							
							
								if (ik == entry.getValue().year && entry.getValue().rating > fl){
									ig = entry.getValue().name;
									fl = entry.getValue().rating;
								}
								
							
						}
						if (ig != null){
						
						System.out.println(ig);
						}
						else System.out.println("Oops! the database doesn't contain any movie in the given year");
					}
					//q4 condition, inserting a new movie
					else if(sa1[0].equals("q4")){
						Movie moi = new Movie();
						moi.name = sa1[1];
						moi.Director = sa1[2];
						moi.year = Integer.parseInt(sa1[3]);
						moi.genre = sa1[4];
						moi.rating = Float.parseFloat(sa1[5]);
						int leng = 0;
						for (int ok = 0;ok<=5;ok++) {
							leng = leng +sa1[ok].length() +1;
						}
						moi.Actors = sa.substring(leng).split(" ");
						int flag =0;
						for (Map.Entry<String,Movie> entry : film.entrySet()) {
							
							
								if (moi.equals(entry)) {
									System.out.println(" The movie is already in the database");
									flag =1;
									break;
								}
								
							
						}
						if ( flag ==1){
							continue;
						}
						
						try{
							String info = moi.name+":"+moi.Director+":"+moi.year+":"+moi.genre+":";
							for (int eh = 0 ;eh< moi.Actors.length;eh++) {
							info = info + moi.Actors[eh] + ",";
							}
							info = info.substring(0,info.length()-1) +"\n";
							String rating =moi.name +":"+moi.rating+"\n"; 
							//System.out.println(info);
							//System.out.println(rating);
							File file =new File("../movieinfo.csv");
							File ratingfile = new File ("../movieratings.csv");
				 
							//if file doesnt exists, then create it
							if(!file.exists()){
								file.createNewFile();
							}
							if(!ratingfile.exists()){
								ratingfile.createNewFile();
							}
							//true = append file
							FileWriter fileWritter = new FileWriter(file.getName(),true);
								BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
								bufferWritter.write(info);
								bufferWritter.close();
								
							FileWriter fileWritter1 = new FileWriter(ratingfile.getName(),true);
								BufferedWriter bufferWritter1 = new BufferedWriter(fileWritter1);
								bufferWritter1.write(rating);
								bufferWritter1.close();
				 
							//System.out.println("Done");
				 
						}catch(IOException e){
							e.printStackTrace();
						}
					}
					// q5 deleting a movie.
					else if  (sa1[0].equals("q5")){
							sa = sa.substring(sa1[0].length() +1);
							for (Map.Entry<String,Movie> entry : film.entrySet()){
								if(entry.getKey().equals(sa)) {
									film.remove(entry.getKey());
									break;
								}
							}
							try{
							
							
							File file =new File("../movieinfo.csv");
							File file1 =new File("../movieratings.csv");
							//if file doesnt exists, then create it
							if(!file.exists()){
								file.createNewFile();
							}
							//if file1 doesnt exists, then create it
							if(!file1.exists()){
								file1.createNewFile();
							}
							//true = append file
							FileWriter fileWritter = new FileWriter(file.getName());
								BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
								FileWriter fileWritter1 = new FileWriter(file1.getName());
								BufferedWriter bufferWritter1 = new BufferedWriter(fileWritter1);
								for (Map.Entry<String,Movie> entry : film.entrySet()) {
									Movie moi = new Movie();
									moi.name = entry.getKey();
									moi.Director = entry.getValue().Director;
									moi.year = entry.getValue().year;
									moi.genre = entry.getValue().genre;
									moi.rating = entry.getValue().rating;
									moi.Actors = entry.getValue().Actors;
									String info = moi.name+":"+moi.Director+":"+moi.year+":"+moi.genre+":";
									for (int eh = 0 ;eh< moi.Actors.length;eh++) {
									info = info + moi.Actors[eh] + ",";
									}
									info = info.substring(0,info.length()-1)+"\n";
									String rating =moi.name +":"+moi.rating+"\n"; 
									//System.out.println(info);
									//System.out.println(rating);
									bufferWritter.write(info);
									bufferWritter1.write(rating);
								}
								
								bufferWritter.close();
								bufferWritter1.close();
							//System.out.println("Done");
				 
						}catch(IOException e){
							e.printStackTrace();
						}
							
					}
					else if (sa1[0].equals("q6")) {
						if (sa1[1].equals("rating")) {
							System.out.println("Enter the movie name and its rating in the follwoing order:");
							System.out.println("Moviename rating");
							try{
								BufferedReader br3 = new BufferedReader(new InputStreamReader(System.in));
								sa = br3.readLine();
							} catch (IOException e){
								e.printStackTrace();
							}
							String[] sa2 = sa.split(" ");
							int size1 = sa2.length;
							String name1 = sa.substring(0,sa.length() - (sa2[size1-1].length())).trim();
							System.out.println(name1);
							for (Map.Entry<String,Movie> entry : film.entrySet()){
									if(entry.getKey().equals(name1)) {
										entry.getValue().rating = Float.parseFloat(sa2[size1-1]);
										break;
									}
							}
							
							
							try{
							
							
							File file =new File("../movieratings.csv");
							//File file1 =new File("../movieratings.csv");
							//if file doesnt exists, then create it
							if(!file.exists()){
								file.createNewFile();
							}
							
							//true = append file
							FileWriter fileWritter = new FileWriter(file.getName());
								BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
								
								for (Map.Entry<String,Movie> entry : film.entrySet()) {
									Movie moi = new Movie();
									moi.name = entry.getKey();
									//moi.Director = entry.getValue().Director;
									//moi.year = entry.getValue().year;
									//moi.genre = entry.getValue().genre;
									moi.rating = entry.getValue().rating;
									//moi.Actors = entry.getValue().Actors;
									//String info = moi.name+":"+moi.Director+":"+moi.year+":"+moi.genre+":";
									
									String rating =moi.name +":"+moi.rating+"\n"; 
									//System.out.println(info);
									//System.out.println(rating);
									bufferWritter.write(rating);
									//bufferWritter1.write(rating);
								}
								
								bufferWritter.close();
								//bufferWritter1.close();
							//System.out.println("Done");
				 
						}catch(IOException e){
							e.printStackTrace();
						}
							
								
						}
						
						 else if (sa1[1].equals("info")) {
							System.out.println("Enter the movie name and its details in the following order, separted by colons,including each actor:");
							System.out.println("Moviename Director Year Genre List of Actors");
							try{
								BufferedReader br3 = new BufferedReader(new InputStreamReader(System.in));
								sa = br3.readLine();
							} catch (IOException e){
								e.printStackTrace();
							}
							String[] sa2 = sa.split(":");
							int leng = 0;
							String ska ="";
							for (Map.Entry<String,Movie> entry : film.entrySet()){
									if(entry.getKey().equals((sa2[0]).trim())) {
										entry.getValue().Director = sa2[1].trim();
										
										entry.getValue().year = Integer.parseInt((sa2[2]).trim());
										entry.getValue().genre = sa2[3].trim();
										for( int gh = 4;gh<sa2.length;gh++){
											 ska = ska+":"+sa2[gh];
										}
										entry.getValue().Actors = ska.split(":");
										
										break;
									}
							}
							
							
							try{
							
							
							File file =new File("../movieinfo.csv");
							//File file1 =new File("../movieratings.csv");
							//if file doesnt exists, then create it
							if(!file.exists()){
								file.createNewFile();
							}
							
							//true = append file
							FileWriter fileWritter = new FileWriter(file.getName());
								BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
								
								for (Map.Entry<String,Movie> entry : film.entrySet()) {
									Movie moi = new Movie();
									moi.name = entry.getKey();
									moi.Director = entry.getValue().Director;
									moi.year = entry.getValue().year;
									moi.genre = entry.getValue().genre;
									//moi.rating = entry.getValue().rating;
									moi.Actors = entry.getValue().Actors;
									String info = moi.name+":"+moi.Director+":"+moi.year+":"+moi.genre+":";
									for (int eh = 0 ;eh< moi.Actors.length;eh++) {
									info = info + moi.Actors[eh] + ",";
									}
									info = info.substring(0,info.length()-1)+"\n";
									//String rating =moi.name +":"+moi.rating+"\n"; 
									//System.out.println(info);
									//System.out.println(rating);
									bufferWritter.write(info);
									//bufferWritter1.write(rating);
								}
								
								bufferWritter.close();
								//bufferWritter1.close();
							//System.out.println("Done");
				 
								}catch(IOException e){
									e.printStackTrace();
								}
						}
					}
					
				}
			}
		}
}
