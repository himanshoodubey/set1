import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int l=s.nextInt();
		int r=s.nextInt();
		int f=0;
		for(int i=l+1;i<r;i++){
		    if(i==n){
		        f=1;
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
