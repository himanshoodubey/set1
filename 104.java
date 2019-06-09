import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int a=1;
		while(k!=0){
		    a=a*n;
		    k--;
		}
		System.out.println(a);
}
}
