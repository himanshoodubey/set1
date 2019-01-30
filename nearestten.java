import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int n=10000;
		for(int i=a;i<=n;i++){
		    if(i%10==0){
		        System.out.println(i);
		        break;
		    }
		}
		
	}
}
