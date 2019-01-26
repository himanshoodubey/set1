import java.util.*;

public class Main
{
	public static void main(String[] args) {
Scanner s=new Scanner(System.in);
int n=s.nextInt();
int r=0;
int c=1;
	for(int i=0;i<n;i++){
	    r=n%10;
	    c++;
	    n=n/10;
	    
	    
	}
	System.out.println(c);
	}
}
