import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a=s.nextInt();
		int b=s.nextInt();
		int c=s.nextInt();
		int sn=0;
		int x=2*a+(c-1)*b;
		sn=c/2*x;
		System.out.println(sn);
	}
}
