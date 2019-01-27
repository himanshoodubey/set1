import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int m=s.nextInt();
	    int o=m*n;
	    if(o%2==0){
	    System.out.println("even");
	    }
	    else{
	        System.out.println("no");
	    }
	}
}
