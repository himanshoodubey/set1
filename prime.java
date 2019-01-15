import java.util.*;
import java.util.Scanner;
public class prime{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int flag=0,m=0;
        m=n/2;
        if(n==0||n==1){
            System.out.println("no");
        }
        else{
            for(int i=2;i<=m;i++){
                if(n%i==0){
                    System.out.println("no");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            System.out.println("yes");
        }
    }
}
