//Assumption: both the files contain equal number of movies and they are ordered in the same manner
//i.e. they are identical  by the movie name in each line
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
				}
			}
		}
	} 
			
//external class of movie type to store data from both files merged
class Movie{
	String name = null;
	String Director = null;
	int year = 0;
	String genre = null;
	String[] Actors = null;
	float rating = 0;
}
	
