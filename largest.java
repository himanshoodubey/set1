import java.util.*;
public class largest{
public static void main(String args[]){
Scanner s=new Scanner(System.in);
int a=s.nextInt();
int b=s.nextInt();
int c=s.nextInt();
if(a>b && a>c){
System.out.println(a);
}
if(b>c && b>a){
System.out.println(b);
}
if(c>a && c>b){
System.out.println(c);
}
}
}
