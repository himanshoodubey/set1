import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String s1=s.nextLine();
		char a[]=s1.toCharArray();
		for(int i=s1.length()-1;i>=0;i--){
		    System.out.print(a[i]);
		}
	}
}
