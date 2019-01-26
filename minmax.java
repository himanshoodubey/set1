import java.util.*;

public class Main
{
	public static void main(String[] args) {
Scanner s=new Scanner(System.in);
int n=s.nextInt();
int a[]=new int[n];
for(int i=0;i<n;i++){
    a[i]=s.nextInt();
}
for(int i=0;i<n;i++){
    for(int j=1;j<n-1;j++){
        if(a[i]>a[j]){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
int max=a[0];
int min=a[0];
for(int i=0;i<n;i++){
    if(max<a[i]){
        max=a[i];
    }
    if(min>a[i]){
        min=a[i];
    }
}
System.out.println(min+" "+max);

	}
}
