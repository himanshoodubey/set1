import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=s.nextInt();
		for(int i=n;i<m;i++){
		    int flag=0;
		    for(int j=2;j<i;j++){
		        if(i%j==0){
		            flag=1;
		        }
		    }
		    if(flag==0){
		        System.out.println(i);
		    }
		}
	}
}
