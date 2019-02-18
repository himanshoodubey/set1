import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int f=0,a=0;
		a=n/2;
		if(n==0||n==1){
		    System.out.println("no");
		}
		for(int i=2;i<a;i++){
		    if(n%i==0){
		        f=1;
		        break;
		    }
		}
		if(f==1){
		    System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
	}
}
