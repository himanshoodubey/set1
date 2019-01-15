import java.util.*;
import java.util.Scanner;
public class con{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int m=s.nextInt();
        int o=n+1;
        for(int i=o;i<m;i++){
            if(i%2!=0){
                System.out.println(i);
            }
        }
}
}
