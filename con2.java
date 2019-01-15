import java.util.*;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int m=s.nextInt();
        for(int i=n+1;i<m;i++){
            if(i%2==0){
                System.out.println(i);
            }
        }
}
}
