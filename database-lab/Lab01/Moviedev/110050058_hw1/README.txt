**************************************README*******************************************
Roll No: 110050058

Since no name has been specified for the main class file to execute the assignment,
I have named the class Moviedetails for the execution of all the above said commmands
There is another class by the name movie which defines the struct of the object to be saved

Therefore for compilation, the following commands will suffice:

javac -d . Movie.java
javac -d . Moviedetails.java
java moviedev.Moviedetails

The two bytecode files will be created in a folder named moviedev which will also be created by itself.
*************The csv files are to be kept in the same folder as the source files****************

Like the previous submission. the following submissions remain the same:
Assumptions:
Like the testcases given to us, I have assumed That the two csv files to be used,
one for details and other for ratings, will have same number of entries and they would be ordered
in the same order in both the files by their movie names.
If not, this code can be tweaked for proper storage in the hashmap by running a linear search.
Since nothing was told, I took the liberty of taking this assumption.
Also if any of the csv files doesn't have a entry, then also it should cause no problems 
except for numerical comparisons as hashmaps include "null" by default whereever an entry is missing


For the execution of the old queries, the details remain the same as used in previous submission, as defined by problem statement
For the execution of the three new queries asked, the following commands are to be used:
For adding a new movie:
q4 Moviename Director year genre rating Actor1 Actor2 Actor3..... each separated by a space
For Deleting a movie:
q5 moviename
For editng the values, since their are two different files, I have executed in it two ways:
To change the ratings value:
First we type 
q6 rating
and then upon prompt
moviename rating

To change other information:
First we type 
q6 info
and  then upon prompt
moviename:director:year:genre:Actor1:Actor2:Actor3....each separated by a colon

More Assumptions:
for q4, add any movie, by default it is assumed that the movie inserted will have at least 
one single different attribute( same movie names exist e.g. Devdas)
for q5, it is assumed that the movie to be deleted exists in the database
for q6, it is assumed that the movie to be deleted exists in the database.

I, also, hereby state that all of hte work is completely done by me solely.

References:
http://www.tutorialspoint.com/java
http://stackoverflow.com
http://www.vogella.com/articles/JavaRegularExpressions/article.html
http://javarevisited.blogspot.in
http://docs.oracle.com/javase/7/docs/api/

