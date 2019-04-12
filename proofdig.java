import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int d=0;
		int pro=1;
		while(n!=0){
		d=n%10;
		n/=10;
		pro*=d;
		}
		System.out.print(pro);
		
}
}
