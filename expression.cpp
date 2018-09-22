#include<vector>
#include<string>
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int expression(string &s) {
	int i = 0;
	stack<long long int> num;
	stack<char> op;
	op.push('#');
    if (s[i] =='-') {
        i++;
        long long int temp=0;
		while (i<s.size()&&(s[i] >= '0' && s[i] <= '9'))
			temp = temp * 10 + (s[i++] - '0');
		num.push(-temp);
	}
	while (i < s.size()) {
		long long int temp = 0;
		if (s[i] >= '0' && s[i] <= '9') {
			while (i<s.size()&&(s[i] >= '0' && s[i] <= '9'))
				temp = temp * 10 + (s[i++] - '0');
			num.push(temp);
		}
		else {
			if (s[i] != '*')
				if (op.top() == '*') {
					while (op.top() == '*') {
						op.pop();
						long long int num2 = num.top();
						num.pop();
						long long int num1 = num.top();
						num.pop();
						num.push(num1*num2);
					}
				}
				else if (op.top() == '+') {
					op.pop();
					long long int num2 = num.top();
					num.pop();
					int num1 = num.top();
					num.pop();
					num.push(num1 + num2);
				}
				else if (op.top() == '-') {
					op.pop();
					long long int num2 = num.top();
					num.pop();
					long long int num1 = num.top();
					num.pop();
					num.push(num1 - num2);
				}
				op.push(s[i++]);
		}
	}
	while (op.top() != '#') {
		char op1 = op.top();
		op.pop();
		long long int num2 = num.top();
		num.pop();
		long long int num1 = num.top();
		num.pop();
		if (op1 == '-')
			num.push(num1 - num2);
		else if (op1 == '+')
			num.push(num1 + num2);
		else if (op1 == '*')
			num.push(num1*num2);
	}
	return num.top();
}
int main() {
	string temp;
	vector<long long int> buffer;
	while (1) {
		cin >> temp;
		if (temp == "END")
			break;
		buffer.push_back(expression(temp));
	}
	for (int i = 0; i<buffer.size(); i++) {
		printf("%d\n", buffer[i]);
	}
	return 0;
}