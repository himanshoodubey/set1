import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String n=s.nextLine();
		int f=0;
		int low=0;
		int high=n.length()-1;
		for(int i=0;i<n.length();i++){
		
		    
		    char a=n.charAt(low);
		    char b=n.charAt(high);
		    if(a!=b){
		        
		        f=1;
		    }
		    low++;
		        high--;
		
		}
		if(f==0){
		System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
	}
}
