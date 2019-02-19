import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int a[]=new int[n];
		int i=0;
		int b=n;
		while(b>0){
		    a[i]=b%10;
		    b=b/10;
		    i++;

		}
		for(i=n-1;i>=0;i--){
		    if(a[i]%2!=0){
		       System.out.println(a[i]+" ");
		    }
		}
		
	}
}
