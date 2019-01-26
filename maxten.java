import java.util.*;

public class Main
{
	public static void main(String[] args) {
	Scanner s=new Scanner(System.in);
	
	int max=Integer.MIN_VALUE;
	for(int i=1;i<=10;i++){
	    int n=s.nextInt();
	    if(n>max){
	        max=n;
	    }
	}
	
	System.out.println(max);
	}
}
