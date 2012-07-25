import java.util.*;
import java.math.*;
import java.io.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.System.*;
import static java.util.Collections.*;


public class Main {
	Scanner cin;

	void run(){
		cin=new Scanner(System.in);
		while(cin.hasNext()){
			int n=cin.nextInt();
			BigInteger p=cin.nextBigInteger();
			int low=1,high=(int)1e9+1;
			while(low+1<high){
				BigInteger mid=BigInteger.valueOf((low+high)/2);
				if(mid.pow(n).compareTo(p)<=0){
					low=(low+high)/2;
				}else{
					high=(low+high)/2;
				}
			}
			printf("%d\n",low);
		}
	}

	void printf(String format,Object... args){
		System.out.printf(format, args);
	}

	void debug(Object... args){
		System.err.println(deepToString(args));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}