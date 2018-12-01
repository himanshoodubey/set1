import java.util.*;
public class Letter{
public static void main(String args[]){
Scanner s=new Scanner(System.in);
char n=s.next().charAt();
if((n>='a' && n<='z')||(n>='A' && n<='Z')){
if(n=='a' || n=='e' || n=='i' || n=='o' || n=='u'){
System.out.println("vowel");
}
else{
System.out.println("consonant");
}
}
else{
System.out.println("not valid");
}
}
}
