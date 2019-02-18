import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String n=s.nextLine();
		char a[]=new char[n.length()];
		int i=0;
		for(i=0;i<n.length();i++){
		    a[i]=n.charAt(i);
		}
		if(n.length()%2==0){
		    i=n.length()/2;
		    a[i-1]='*';
		    a[i]='*';
		}
		else{
		    i=n.length()/2;
		    a[i]='*';
		}
		for(i=0;i<n.length();i++){
		    System.out.print(a[i]);
		}
	}
}
