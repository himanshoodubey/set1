import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int k=s.nextInt();
	     int f=0;
	    int c=0;
	    int a[]=new int[n];
	    for(int i=0;i<n;i++){
	        a[i]=s.nextInt();
	        
	        if(a[i]==k){
	           
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
