import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int m=n%60;
	    int o=n/60;
	    System.out.println(o+" "+m);
	}
}
