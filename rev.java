import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int d=0;
		int rev=0;
		while(n!=0){
		d=n%10;
		rev=rev*10+d;
		n/=10;
		}
		System.out.print(rev);
		
		
}
}
