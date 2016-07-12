/*
所有输出均转换为真分式形式
负号的位置，负号在括号内，不是在括号外。    (-1 1/3)
整数部分为0时不输出整数部分，真分式部分为0时也不输出
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;
//计算最大公约数
long long greatestCommonDivisor(long long a, long long b)
{
	long long remain, min, max;
	min = (a>b) ? b : a;
	max = (a>b) ? a : b;
	remain = max%min;
	while (remain)
	{
		max = min;
		min = remain;
		remain = max%min;
	}
	return min;
}
//转化为真分式形式
string properFraction(long long a, long long b)
{
	// 基本边界、基本变量
	if (a == 0) {
		return "0";
	}
	bool isMinus = false;
	string str = "";
	if (a*b < 0) {
		isMinus = true; a = abs(a);//绝对值
		b = abs(b); str = "(-";
	}
	//约分
	long long gcd = greatestCommonDivisor(a, b);
	a /= gcd; b /= gcd; //最简
	long long integer = a / b;//整数部分
	long long frac = a%b;//分子部分
	stringstream ss; ss << integer;
	string intPart, fracPart;
	ss >> intPart;
	stringstream ss2; ss2 << frac;
	ss2 >> fracPart;
	if (integer>0) {//有整数部分
		str += intPart;
	}
	if (frac)>0) {//有分子部分
		if ((integer)>0) {
			str += " ";
		}
		str += fracPart; str += '/';
		stringstream ss3; string temp;
		ss3 << b; ss3 >> temp;
		str += temp;
	}
	if (isMinus) {
		str += ')';
	}
	return str;
}

int main(){
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	// 四则运算
	string first = properFraction(a1, b1);
	string second = properFraction(a2, b2);
	// +
	long long a = a1*b2 + a2*b1;
	long long b = b1*b2;
	string third = properFraction(a, b);
	cout << first << " + " << second << " = " << third << endl;

	// -
	a = a1*b2 - a2*b1;
	b = b1*b2;
	third = properFraction(a, b);
	cout << first << " - " << second << " = " << third << endl;

	// *
	a = a1*a2;
	b = b1*b2;
	third = properFraction(a, b);
	cout << first << " * " << second << " = " << third << endl;

	// /
	a = a1*b2;
	b = b1*a2;
	if (b == 0) {
		cout << first << " / " << second << " = Inf" << endl;
	}
	else{
		third = properFraction(a, b);
		cout << first << " / " << second << " = " << third << endl;
	}

	return 0;
}