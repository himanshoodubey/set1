import java.util.*;
import java.util.Arrays;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();
        String a[]=s1.split("");
        int f=0;
        for(int i=0;i<s1.length();i++){
            int c=0;
            for(int j=0;j<s1.length();j++){
                
            
        
        
            if(a[i].equals(a[j])){
               c++;
            }
            
            
        }
        if(c>1)
        f=1;
            break;
        }
        if(f==1){
            System.out.print("no");
        }
        else{
            System.out.print("yes");
        }
        
    }
}
