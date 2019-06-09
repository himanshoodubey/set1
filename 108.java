import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++){
		    a[i]=s.nextInt();
		}
		for(int i=0;i<n-1;i++){
		    for(int j=1;j<n-i-1;j++){
		        if(a[j-1]>a[j]){
		            int t=a[j];
		            a[j]=a[j-1];
		            a[j-1]=t;
		        }
		    }
		}
		System.out.print(a[k-1]);
		
}
}
