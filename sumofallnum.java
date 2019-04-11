import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int c=0;
		for(int i=0;i<n;i++){
		    int a=s.nextInt();
		    c+=a;
		}
		System.out.println(c);
	}
}
