import java.util.*;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int f=0,n1=0;
        n1=n/2;
        if(n==0||n==1){
            System.out.println("no");
        }
        else{
            for(int i=2;i<=n1;i++){
                if(n%i==0){
                    System.out.println("no");
                    f=1;
                    break;
                }
            }
        }
        if(f==0){
            System.out.println("yes");
        }
    }
}
