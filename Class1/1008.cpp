#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	cout << setprecision(9) << fixed;
	cout << a / b;
}
