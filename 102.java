import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		if(n%2==0){
		    n=n/2;
		    System.out.println(n);
		}
		else{
		    System.out.println(n);
		}
	}
}
