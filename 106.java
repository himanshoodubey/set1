import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int a[]=new int[n];
		int i=0;
		for(i=0;i<n;i++){
		    a[i]=s.nextInt();
		}
		if(a[k]%2==0){
		    System.out.println(a[k-1]);
		}
		else{
		    System.out.println(a[k]);
		}
}
}
