import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    String n=s.nextLine();
	    char a=0;
	    int f1=0;
	    int f2=0;
	    for(int i=0;i<n.length();i++){
	        a=n.charAt(i);
	    
	    if(a>='a'&&a<='z'||a>='A'&&a<='Z'){
	        f1=1;
	       
	    }
	    if(a>='0'&&a<='9'){
	        f2=1;
	    }
	    }
	    if(f1==1&&f2==1){
	        System.out.println("Yes");
	    }
	    else{
	        System.out.println("No");
	    }
	}
}
