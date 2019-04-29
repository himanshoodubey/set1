import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();
        char a[]=s1.toCharArray();
        for(int i=0;i<s1.length();i++){
            if(a[i]=='0-9'){
                System.out.print(a[i]);
            }
        }
    }
}
