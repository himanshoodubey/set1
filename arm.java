import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int temp=0,sum=0,r=0;
        temp=n;
        while(n!=0){
            r=n%10;
            sum=(r*r*r)+sum;
            n=n/10;
        }
        if(temp==sum){
            System.out.println("yes");
        }
        else{
            System.out.println("no");
        }
    }
}
