import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int f=0;
		char a=0;
		for(int i=0;i<s.length();i++){
		    a=s.charAt(i);
		    if(a!='0'&&a!='1'){
		        f=1;
		       
		    }
		}
		if(f==0){
		    System.out.println("Yes");
		}
		else{
		    System.out.println("No");
		}
		
	}
}
