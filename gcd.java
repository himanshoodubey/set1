import java.util.*;
import java.io.*;
public class Main{
    static int gcd(int a,int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a==b){
            return a;
        }
        if(a>b)
            return gcd(a-b,b);
            return gcd(a,b-a);
        
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n1=s.nextInt();
        int n2=s.nextInt();
        System.out.println(gcd(n1,n2));
     }
}
