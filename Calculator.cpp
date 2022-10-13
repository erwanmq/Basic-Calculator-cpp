#include <iostream>
#include <string>

bool findSign(const std::string& calcul_str)
{
	return calcul_str.find_first_of("+-*/") != std::string::npos;
}

size_t checkOperator(const std::string& calcul_str)
{
	size_t last_operator = calcul_str.find_last_of("+");
	if (last_operator == std::string::npos)
	{
		last_operator = calcul_str.find("*");
		if (last_operator == std::string::npos)
		{
			last_operator = calcul_str.find("/");
			if (last_operator == std::string::npos)
				return std::stod(calcul_str);
		}

	}
}

double calculator(std::string calcul_str)
{
	std::string equation1;
	std::string equation2;
	char sign;
	double result1;
	double result2;

	size_t last_operator = checkOperator(calcul_str);

	sign = calcul_str[last_operator];
	equation1 = calcul_str.substr(0, last_operator);
	equation2 = calcul_str.substr(last_operator + 1, 50);


	if (findSign(equation1))
		result1 = calculator(equation1);
	else
		result1 = std::stod(equation1);
	if (findSign(equation2))
		result2 = calculator(equation2);
	else
		result2 = std::stod(equation2);


	switch (sign)
	{
	case '+':
		return result1 + result2;
	case '-':
		return result1 - result2;
	case '*':
		return result1 * result2;
	case '/':
		return result1 / result2;
	}


}

std::string user()
{
	std::string calcul_str;
	std::cout << "Entrez le calcul: ";
	std::cin >> calcul_str;
	return calcul_str;
}


int main()
{
	std::string calcul_str = user();

	double result = calculator(calcul_str);

	std::cout << result;

	return 0;
}