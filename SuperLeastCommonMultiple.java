//超级最小公倍数
//时间限制：8000 ms  |  内存限制：16384 KB
//
//描述
//
//    给2个正整数a,b(1<=a,b<=10^100),求a和b的最小公倍数。
//
//输入
//
//    输入包含多组数据，每组数据一行，包含两个正整数a和b，中间以一个空格隔开。输入以0 0结束。
//输出
//
//    每组数据输出一行，为a,b的最小公倍数。
//样例输入
//
//    123 321
//    123456789 987654321
//    0 0
//
//样例输出
//
//    13161
//    13548070123626141
//
//提示
//
//
//来源
//    BUAA Campus 2007
//用户 	结果 	时间 	内存 	语言 	提交时间
//DawnDIY	正确	514ms	3076KB	java
package com.dawndiy.acm;

import java.math.BigInteger;
import java.util.Scanner;

public class SuperLeastCommonMultiple {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String a, b;
		BigInteger aa, bb;
		while (true) {
			a = in.next();
			b = in.next();
			if ("0".equals(a) && "0".equals(b)) {
				break;
			}
			aa = new BigInteger(a);
			bb = new BigInteger(b);

			System.out.println(aa.multiply(bb).divide(aa.gcd(bb)));

		}
		in.close();

	}

}
