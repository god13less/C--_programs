//java代码

import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
        BigDecimal a; int n;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            a = sc.nextBigDecimal();
            n = sc.nextInt();
            String s = a.pow(n).stripTrailingZeros().toPlainString();//首先去掉后缀0,转化为字符串
            if(s.charAt(0)=='0'){//去掉前导0
                s=s.substring(1);
            }
            System.out.println(s);
        }
    }
}