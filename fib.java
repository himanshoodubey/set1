import java.util.*;

public class Main
{
	public static void main(String[] args) {
Scanner s=new Scanner(System.in);
int n=s.nextInt();
	int a=0,b=0,c=1;
	for(int i=1;i<=n;i++){
	    a=b;
	    b=c;
	    c=a+b;
	    
	
	System.out.println(b);
	}
	}
}
