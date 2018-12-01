import java.util.*;

public class even{

public static void main(String args[]){

Scanner s=new Scanner(System.in);

char n=s.next().charAt(0);
if((n>='a' && n<='z')||(n>='A' && n<='Z')){

System.out.println("alphabet");
}


else{
System.out.println("no");
}
}
}
