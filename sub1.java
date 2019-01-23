import java.util.*;
import java.math.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
	    int h1=s.nextInt();
	    int m1=s.nextInt();
	    int h2=s.nextInt();
	    int m2=s.nextInt();
	    int sub1=h1-h2;
	    int sub2=m1-m2;
	    System.out.println(Math.abs(sub1)+" "+Math.abs(sub2));
	}
}
