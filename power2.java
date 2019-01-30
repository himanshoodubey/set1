import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
	    int n=1000;
	    for(int i=m+1;i<=n;i++){
	        int a=i;
	        while(a%2==0){
	            a=a/2;
	            
	    }
	    
	    if(a==1){
	                System.out.println(i);break;
	            }
	    }    
	}
}
