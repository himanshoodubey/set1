import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int r=0;
	    int c=0;
	    int a=n;
	    while(n>0){
	        r=n%10;
	        n=n/10;
	      c++;
	      
	    }
	    int b[]=new int[c];
	    int i=0;
	    while(a>0){
	        b[i]=a%10;
	        a=a/10;
	        i++;
	    }
	    for(int i1=c-1;i1>=0;i1--){
	        System.out.println(b[i1]+" ");
	    }
	    
	}
}
