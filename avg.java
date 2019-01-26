import java.util.*;

public class Main
{
	public static void main(String[] args) {
Scanner s=new Scanner(System.in);
int n=s.nextInt();
int sum=0;
int avg=0;
for(int i=0;i<n;i++){
    int a=s.nextInt();
    
    sum=sum+a;
}
avg=sum/n;
System.out.println(avg);
	}
}
