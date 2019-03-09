import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a=s.nextInt();
		int b=s.nextInt();
		int c=a*b;
		
		int n=(int)Math.sqrt(c);
		if(c==n*n){
		    System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
	}
}
