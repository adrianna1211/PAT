/*
���������ת��Ϊ���ʽ��ʽ
���ŵ�λ�ã������������ڣ������������⡣    (-1 1/3)
��������Ϊ0ʱ������������֣����ʽ����Ϊ0ʱҲ�����
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;
//�������Լ��
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
//ת��Ϊ���ʽ��ʽ
string properFraction(long long a, long long b)
{
	// �����߽硢��������
	if (a == 0) {
		return "0";
	}
	bool isMinus = false;
	string str = "";
	if (a*b < 0) {
		isMinus = true; a = abs(a);//����ֵ
		b = abs(b); str = "(-";
	}
	//Լ��
	long long gcd = greatestCommonDivisor(a, b);
	a /= gcd; b /= gcd; //���
	long long integer = a / b;//��������
	long long frac = a%b;//���Ӳ���
	stringstream ss; ss << integer;
	string intPart, fracPart;
	ss >> intPart;
	stringstream ss2; ss2 << frac;
	ss2 >> fracPart;
	if (integer>0) {//����������
		str += intPart;
	}
	if (frac)>0) {//�з��Ӳ���
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
	// ��������
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