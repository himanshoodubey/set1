import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int c=0;
	    int r=0;
	    while(n>0){
	        r=n%10;
	        n=n/10;
	        c++;
	    }
	    System.out.println(c);
	    
}
}
