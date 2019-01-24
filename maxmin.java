/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	   int a[]=new int[n];
	   int i;
	   for(i=0;i<n;i++);
	   {
	       a[i]=s.nextInt();
	   }
	   int min=a[0];
	   for(i=0;i<n;i++){
	       if(min>a[i]){
	           min=a[i];
	       }
	   }
	   System.out.println(min);
	   int max=a[0];
	   for(i=0;i<n;i++){
	       if(max<a[i]){
	           max=a[i];
	       }
	       
	   }
	   System.out.println(max);
	    
	}
}
