import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int a=s.nextInt();
		int d=s.nextInt();
		int sum=0;
		for(int i=0;i<n;i++){
		    sum=sum+a;
		    a=a+d;
		   
		}
		 System.out.println(sum);
	}
}
