import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	   int f=0;
	  String n=s.nextLine();
	  for(int i=0;i<n.length();i++){
	      char a=n.charAt(i);
           if(!(a>='0'&&a<='9'||a=='.')){
               f=1;
           }
	  }
	  if(f==0){
	      System.out.println("yes");
	  }
	  else{
	      System.out.println("no");
	  }
	  
}
}
