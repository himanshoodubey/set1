/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    String n=s.nextLine();
	    String m=s.nextLine();
	    
	    if(n.equals(m)){
	        System.out.println(n);
	    }
	    int comp=n.compareTo(m);
	    if(comp>0){
	        System.out.println(n);
	    }
	    else{
	        System.out.println(m);
	    }
	}
}
