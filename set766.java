import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int f=0;
		int m=n/2;
		if(n==0&&n==1){
		    
		}
		for(int i=2;i<=m;i++){
		    if(n%i==0){
		        
		        f=1;
		    }
		}
		if(f==0){
		    System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
}
}
