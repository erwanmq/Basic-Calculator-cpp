#include <iostream>
#include <string>

double calculator(std::string calcul_str);

size_t checkOperator(const std::string& calcul_str)
{
	size_t last_operator = calcul_str.find_last_of("+");
	if (last_operator == std::string::npos)
	{
		last_operator = calcul_str.find("*");
		if (last_operator == std::string::npos)
		{
			last_operator = calcul_str.find("/");
		}
	}

	return last_operator;
}


bool isStringNumber(char number) {
	if (number < '0' || number > '9')
		return false;

	return true;
}


void checkMinus(std::string& calcul_str)
{
	size_t index = calcul_str.find('-');
	if (index != std::string::npos && index > 0 && isStringNumber(calcul_str[index - 1]) && isStringNumber(calcul_str[index + 1]))
		calcul_str.insert(index, "+");
}


bool checkParenthesis(std::string& calcul_str)
{
	size_t index = calcul_str.find('(');
	if (index != std::string::npos)
		return true;
	return false;
}


void calculParenthesis(std::string& calcul_str)
{
	size_t parenthesis1 = calcul_str.find('(');
	size_t parenthesis2 = calcul_str.find(')');
	double result = calculator(calcul_str.substr(parenthesis1 + 1, parenthesis2 - parenthesis1));
	calcul_str.replace(parenthesis1, parenthesis2 - parenthesis1, std::to_string(result));
}


double calculator(std::string calcul_str)
{
	std::string equation1;
	std::string equation2;
	char sign;
	double result1;
	double result2;

	checkMinus(calcul_str);
	if (checkParenthesis(calcul_str))
	{
		calculParenthesis(calcul_str);
	}
	size_t last_operator = checkOperator(calcul_str);
	
	if (last_operator == std::string::npos)
		return std::stod(calcul_str);

	sign = calcul_str[last_operator];
	equation1 = calcul_str.substr(0, last_operator);
	equation2 = calcul_str.substr(last_operator + 1, 50);


	result1 = calculator(equation1);
	result2 = calculator(equation2);


	switch (sign)
	{
	case '+':
		return result1 + result2;
	case '*':
		return result1 * result2;
	case '/':
		return result1 / result2;
	}

	return 0;
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
	while (true)
	{
		std::string calcul_str = user();

		double result = calculator(calcul_str);

		std::cout << result << '\n';
	}
	

	return 0;
}
