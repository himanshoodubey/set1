import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=s.nextInt();
		int sum=n+m;
		if(sum%2==0){
		    System.out.println("even");
		}
		else{
		    System.out.println("odd");
		}
}
}
