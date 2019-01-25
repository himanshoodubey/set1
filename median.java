import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	   int n=s.nextInt();
	   int a[]=new int[n];
	   for(int i=0;i<n;i++){
	       a[i]=s.nextInt();
	   }
	   for(int i=0;i<n;i++){
	       for(int j=i;j<n-1;j++){
	           if(a[i]>a[j]){
	               int temp=a[i];
	               a[i]=a[j];
	               a[j]=temp;
	           }
	       }
	   }
	   for(int i=0;i<n;i++){
	       System.out.println(a[i]+" ");
	   }
	   if(a.length%2==0){
	     System.out.println((a[(a.length/2)-1]+a[a.length/2])/2);
	     
	   }
	   else{
	       System.out.println(a[a.length/2]);
	   }
}
}
