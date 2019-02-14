import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String n=s.nextLine();
		int f=0;
		for(int i=0;i<n.length();i++){
		
		    
		    char a=n.charAt(i);
		    
		    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
		        
		        f=1;
		    }
		}
		if(f==1){
		System.out.println("yes");
		}
		else{
		    System.out.println("no");
		}
	}
}
