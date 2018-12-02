import java.util.*;
public class numbers{
public static void main(String args[]){
Scanner s=new Scanner(System.in);
int n=s.nextInt();
int k=s.nextInt();
int sum=0;
int[] arr=new int[n];
for(int i=0;i<n;i++){
arr[i]=s.nextInt();

}
for(int i=0;i<k;i++){
sum=sum+arr[i];
}
System.out.println(sum);
}
}
