import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int l=s.nextInt();
		int b=s.nextInt();
		int h=s.nextInt();
		int sa=0,v=0;
		sa=2*l*b+2*b*h+2*l*b;
		v=(l*b*h);
		System.out.println(sa+" "+v);
	}
}
