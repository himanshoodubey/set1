import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int a=1;
		while(n>0){
		    a=a*n;
		    n--;
		    
		}
		System.out.println(a);
	}
}
