import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner n=new Scanner(System.in);
		String s=n.nextLine();
		char a=0;
		for(int i=0;i<s.length();i++){
		    a=s.charAt(i);
		}
		if(a=='0'||a=='1'){
		    System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
	}
}
