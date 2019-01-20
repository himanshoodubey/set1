
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int sum=1;
		while(n!=0){
		  
		  sum=sum*n;
		  n--;
		 
		}
		System.out.println(sum); 
	}
}
