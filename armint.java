import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int m=s.nextInt();
        int temp=0,r=0;
        
        for(int i=n;i<m;i++){
            temp=i;
            int sum=0;
        while(temp!=0){
            r=temp%10;
            sum=(r*r*r)+sum;
            temp=temp/10;
        }
        if(i==sum){
            System.out.println(i);
        }
        
    }
    }
}
