#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	int tmp = (int)sqrt(n);

	for (int i = 3; i <= tmp; i+=2)
		if (n % i == 0)
			return false;
		else
			continue;

	return true;
}

int fun(vector<int> primes, int n)
{
	int start, end;
	// 該數字必須被夾在兩個質數中間才算，回傳結果為夾住n的兩質數差，此差即為n的Prime Gap
	for (int i = 0; i < primes.size() - 1; ++i)
		if (primes.at(i) < n && n < primes.at(i + 1))
			return primes.at(i + 1) - primes.at(i);
	return 0;
}

int main()
{
	vector<int> primes;
	vector<int> input_data;
	vector<int> output_data;

	// 建立所有的質數
	primes.push_back(2);
	for (int i = 3; i <= 1299709; i += 2)
	{
		if (isPrime(i))
			primes.push_back(i);
	}

	int input;
	// 取得輸入資料
	while (true)
	{
		cin >> input;
		if (!input)
			break;
		else
			input_data.push_back(input);
	}
	// 計算 Prive Gap
	for (int i = 0; i < input_data.size(); ++i)
	{
		output_data.push_back(fun(primes, input_data.at(i)));
	}
	// 印出輸出
	for (int i = 0; i < output_data.size(); ++i)
		cout << output_data.at(i) << endl;
}