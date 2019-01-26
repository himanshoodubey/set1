import java.util.*;

public class Main
{
	public static void main(String[] args) {
	Scanner s=new Scanner(System.in);
	String m=s.nextLine();
	int c=0;
	char a;
	for(int i=0;i<m.length();i++){
	    a=m.charAt(i);
	    if(!(a>='a'&&a<='z'||a<='A'&&a>='Z'))
	{
	    c++;
	}
	}
	System.out.println(c);
	
	}
}
