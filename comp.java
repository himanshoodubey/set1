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
	    else{
	    int comp=n.compareTo(m);
	    if(comp>0){
	        System.out.println(n);
	    }
	    else{
	        System.out.println(m);
	    }
	}
	}
}
