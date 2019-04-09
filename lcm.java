import java.util.*;
import java.io.*;
public class Main{
    static int gcd(int a,int b){
        if(a==0){
            return 0;
        }
        if(b==0){
            return 0;
        }
        if(a==b){
            return a;
        }
        if(a>b)
            return gcd(a-b,b);
            return gcd(a,b-a);
        
    }
    static int lcm(int a,int b){
        return (a*b)/gcd(a,b);
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n1=s.nextInt();
        int n2=s.nextInt();
        System.out.println(lcm(n1,n2));
     }
}
