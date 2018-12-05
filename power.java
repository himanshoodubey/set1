import java.util.*;
public class power {
    public static void main(String args[]) {
       Scanner s=new Scanner(System.in);
       int n=s.nextInt();
       int k=s.nextInt();
       int m=1;
      while(k!=0){
          m=m*n;
          k--;
      }
       System.out.println(m);
      
    }
}
