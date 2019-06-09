import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String s1=s.nextLine();
		char a[]=s1.toCharArray();
		a[0]=Character.toUpperCase(a[0]);
		int i=0;
		for(i=1;i<s1.length();i++){
		    if(a[i]==' '){
		        a[i+1]=Character.toUpperCase(a[i+1]);
		    }
		}
		for(i=0;i<s1.length();i++){
		    System.out.print(a[i]);
		}
	}
}
