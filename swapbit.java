import java.util.*;

public class Main
{
	public static void main(String[] args) {
	Scanner s=new Scanner(System.in);
	int n=s.nextInt();
	int m=s.nextInt();
	n=n^m;
	m=n^m;
	n=n^m;
	System.out.println(n+" "+m);
	}
}
