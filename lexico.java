import java.util.*;
public class Main{
    void bubbleSort(char a[]){
        int n=a.length;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1])
                {
                    char temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
        public static void main(String args[])
        {
            Scanner s=new Scanner(System.in);
            String s1=s.nextLine();
            
            char a[]=s1.toCharArray();
            Main m=new Main();
            m.bubbleSort(a);
            
           
            for(int i=0;i<a.length;i++){
                System.out.print(a[i]);
            }
        }
    }
      
