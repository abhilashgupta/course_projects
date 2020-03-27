import java.io.*;
import java.sql.*;
import java.lang.*;


public class JDBCSample {
	
	
		public static int countChars(char c, String s) {
			int result = 0;
			for (int i = 0, n = s.length(); i < n; i++) {
				if (s.charAt(i) == c) {
					result++;
				}
			}
			return result;
		}
		
        public static void main(String[] args) throws IOException{

		//Load the PostgreSQL JDBC driver class
                try{
                    Class.forName("org.postgresql.Driver");
                } catch (ClassNotFoundException cnfe){
                    System.out.println("Could not find the JDBC driver!");
                    System.exit(1);
                }
	        
		//Enter the connection details
		String hostname = "10.105.1.51:5432";	// If PostgreSQL is running on some other machine enter the IP address of the machine here
		String username = "cs110050058"; // Enter your PostgreSQL username
		String password = "850050011"; // Enter your PostgreSQL password
		String dbName = "cs110050058"; // Enter the name of the database that has the university tables.
		String connectionUrl = "jdbc:postgresql://" + hostname +  "/" + dbName;
		Connection conn = null;

		//Connect to the database
                try {
                    conn = DriverManager.getConnection(connectionUrl,username, password);
                    System.out.println("Connected successfullly");
                } catch (SQLException sqle) {
                       System.out.println("Connection failed");
						System.out.println(sqle);
		       // Uncomment the below line for a more detailed stack trace
		       // sqle.printStackTrace();
                       System.exit(1);
                }

		//Execute the query and print the results
		try {		//Movie (MovieName, Year of Release, Producer, Director)
		
					
                    Statement pstmt1=conn.createStatement();
                    pstmt1.execute("DROP TABLE IF EXISTS movie cascade;");
                    pstmt1.execute("create table movie (Moviename varchar(40) PRIMARY KEY, year varchar(10), Producer varchar(40), Director varchar(40));");
                    Statement pstmt2=conn.createStatement();
                    //MoviePerson(Name, Address, Phone Number, emailid)
                    pstmt2.execute("Drop table if exists MoviePerson cascade;");
                    pstmt2.execute("create table moviePerson (name varchar(40) PRIMARY KEY, Address varchar(100), Phonenumber varchar(10), emailID varchar(40));");
                    //MovieAwards(MovieName (foreign key into Movie), Year of Award, AwardName)
                    pstmt2.execute("Drop table if exists Movieawards cascade;");
                    pstmt2.execute("create table Movieawards (Moviename varchar(40) references Movie(Moviename), yearaward varchar(10), Awardname varchar(40));");
                    //Castings(MovieName (foreign key into Movie), Actor (foreign key into MoviePerson))
                    pstmt2.execute("Drop table if exists Casting cascade;");
                    pstmt2.execute("create table casting (Moviename varchar(40) references Movie(Moviename), Actor varchar(40) references MoviePerson(name));");
                    
                    long starttime  = System.nanoTime();
                    BufferedReader br = new BufferedReader(new FileReader("MoviePersons.csv"));
                    String s;
                    while ( (s = br.readLine()) != null) {
						String[] moviepersons = s.split(",");
						//moviepersons = Name,Address,Phone Number,Email
						pstmt2.execute ("INSERT into movieperson values('" + moviepersons[0] +"','"+ moviepersons[1]+"','"+
						moviepersons[2]+"','"+moviepersons[3]+"')");
					}
					
					BufferedReader br1 = new BufferedReader(new FileReader("Movies.csv"));
                    //String s;
                    while ( (s = br1.readLine()) != null) {
						String[] movies = s.split(",");
						//Movie (MovieName, Year of Release, Producer, Director)
						pstmt2.execute ("INSERT into movie values('" + movies[0] +"','"+ movies[1]+"','"+
						movies[2]+"','"+movies[3]+"')");
					}
					
					BufferedReader br2 = new BufferedReader(new FileReader("MovieAwards.csv"));
                    //String s;
                    while ( (s = br2.readLine()) != null) {
						String[] movieawards = s.split(",");
						//MovieAwards(MovieName (foreign key into Movie), Year of Award, AwardName)
						pstmt2.execute ("INSERT into movieawards values('" + movieawards[0] +"','"+ movieawards[1]+"','"+
						movieawards[2]+"')");
					}
					
					BufferedReader br3 = new BufferedReader(new FileReader("Casting.csv"));
                    //String s;
                    while ( (s = br3.readLine()) != null) {
						String[] casting = s.split(",");
						//Castings(MovieName (foreign key into Movie), Actor (foreign key into MoviePerson))
						pstmt2.execute ("INSERT into casting values('" + casting[0] +"','"+ casting[1]+"')");
					}
					
					long endtime = System.nanoTime();
					
					System.out.println("The time taken in statement case is: "+ 1.0*(endtime - starttime)/1000000000 +" seconds.");
                    

                   /* while(rs.next()){
                            String name = rs.getString("movie_name");
                            System.out.println(name);
                    }
					*/
					
					//Statement pstmt1=conn.createStatement();
                    pstmt1.execute("DROP TABLE IF EXISTS movie cascade;");
                    pstmt1.execute("create table movie (Moviename varchar(40) PRIMARY KEY, year varchar(10), Producer varchar(40), Director varchar(40));");
                    //Statement pstmt2=conn.createStatement();
                    //MoviePerson(Name, Address, Phone Number, emailid)
                    pstmt2.execute("Drop table if exists MoviePerson cascade;");
                    pstmt2.execute("create table moviePerson (name varchar(40) PRIMARY KEY, Address varchar(100), Phonenumber varchar(10), emailID varchar(40));");
                    //MovieAwards(MovieName (foreign key into Movie), Year of Award, AwardName)
                    pstmt2.execute("Drop table if exists Movieawards cascade;");
                    pstmt2.execute("create table Movieawards (Moviename varchar(40) references Movie(Moviename), yearaward varchar(10), Awardname varchar(40));");
                    //Castings(MovieName (foreign key into Movie), Actor (foreign key into MoviePerson))
                    pstmt2.execute("Drop table if exists Casting cascade;");
                    pstmt2.execute("create table casting (Moviename varchar(40) references Movie(Moviename), Actor varchar(40) references MoviePerson(name));");
					//Movie (MovieName, Year of Release, Producer, Director)
					//MovieAwards(MovieName (foreign key into Movie), Year of Award, AwardName)
					//Castings(MovieName (foreign key into Movie), Actor (foreign key into MoviePerson))
					//moviepersons = Name,Address,Phone Number,Email
					
					starttime  = System.nanoTime();
					PreparedStatement pstMovie  = conn.prepareStatement ( "Insert into movie values(?,?,?,?);");
					PreparedStatement pstMovieawards  = conn.prepareStatement ( "Insert into movieawards values(?,?,?);");
					PreparedStatement pstMoviepersons  = conn.prepareStatement ( "Insert into movieperson values(?,?,?,?);");
					PreparedStatement pstcasting  = conn.prepareStatement ( "Insert into casting values(?,?);");
					
					br = new BufferedReader(new FileReader("MoviePersons.csv"));
					while ( (s = br.readLine()) != null) {
						String[] moviepersons = s.split(",");
						pstMoviepersons.setString(1,moviepersons[0]);
						pstMoviepersons.setString(2,moviepersons[1]);
						pstMoviepersons.setString(3,moviepersons[2]);
						pstMoviepersons.setString(4,moviepersons[3]);
						pstMoviepersons.execute();
					}
					
					br = new BufferedReader(new FileReader("Movies.csv"));
					while ( (s = br.readLine()) != null) {
						String[] Movie = s.split(",");
						pstMovie.setString(1,Movie[0]);
						pstMovie.setString(3,Movie[2]);
						pstMovie.setString(2,Movie[1]);
						pstMovie.setString(4,Movie[3]);
						pstMovie.execute();
					}
					
					br = new BufferedReader(new FileReader("Casting.csv"));
					while ( (s = br.readLine()) != null) {
						String[] casting = s.split(",");
						pstcasting.setString(1,casting[0]);
						pstcasting.setString(2,casting[1]);
						//pstcasting.setInt(2,casting[1]));
						//pstcasting.setString(4,casting[3]);
						pstcasting.execute();
					}
					
					br = new BufferedReader(new FileReader("MovieAwards.csv"));
					while ( (s = br.readLine()) != null) {
						String[] Movieawards = s.split(",");
						pstMovieawards.setString(1,Movieawards[0]);
						pstMovieawards.setString(3,Movieawards[2]);
						pstMovieawards.setString(2,Movieawards[1]);
						//pstMovieawards.setString(4,Movieawards[3]);
						pstMovieawards.execute();
					}
					
					endtime = System.nanoTime();
					
					System.out.println("The time taken in prepstatement case is: "+ 1.0*(endtime - starttime)/1000000000 +" seconds.");
					
					
					///// 2nd part
					System.out.println("Input MovieName, Year of Release, Producer, Director, separated by commas");
					
					 BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
				     s = reader.readLine();
					 String[] Movie1 = s.split(",");
										
                    PreparedStatement pstmtk=conn.prepareStatement("select moviename from movie where moviename =?;");
                    pstmtk.setString(1, Movie1[0]);
                    ResultSet rs = pstmtk.executeQuery();
                    //Movie (MovieName, Year of Release, Producer, Director)
                    boolean h = rs.next();
                    //System.out.println(""+h);
                    if ( h ) {
						pstmt1.executeUpdate("UPDATE movie SET year = '"+ Movie1[1] + "', Producer = '"+ Movie1[2]+"' , Director = '"+ Movie1[3] +"' WHERE Moviename = '" +Movie1[0]+"';");
					}
					else {
						//System.out.println("yeah!");
						pstmt1.executeUpdate("INSERT into movie values('" + Movie1[0] +"','"+ Movie1[1]+"','"+
						Movie1[2]+"','"+Movie1[3]+"');");
					}
                    
                    
                    
					//// 3rd part
					System.out.println("Input the parametrized query");
					//reader = new BufferedReader(new InputStreamReader(System.in));
				    s = reader.readLine();
				    int count = countChars('?',s);
					//System.out.println (""+count);
					pstmtk=conn.prepareStatement(s);
					
					if ( count != 0){
						for ( int count1 = 1; count1<=count;count1++) {
							System.out.println("Input the parameter no."+ count1+ " :");
							s = reader.readLine();
							pstmtk.setString( count1,s);
						}
					}
					
					conn.setAutoCommit(false);
					pstmtk.setFetchSize(1);
					rs = pstmtk.executeQuery();
					//pstmtk.executeQuery()
					
					int no_cols = rs.getMetaData().getColumnCount();
				
					for(int i = 0; i < no_cols; i++) {
						System.out.print(String.format("%30s", rs.getMetaData().getColumnLabel(i+1)));
					}
					System.out.println();
					
					while (rs.next()) {
					 for(int i = 0; i < no_cols; i++)
							System.out.print(String.format("%30s", rs.getString(i+1))); 
					 System.out.println();
					}	
					
					pstmtk.setFetchSize(0);
					rs.close();
                    conn.close();
					System.out.println("Connection closed successfully");
                } catch (SQLException sqle) {
                       System.out.println(sqle);
                       System.exit(1);
                }
        }
}
