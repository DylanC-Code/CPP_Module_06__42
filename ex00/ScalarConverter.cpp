/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:38:20 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/03 09:35:09 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>

void ScalarConverter::converter(const std::string &scalar)
{
	ScalarConverter::handleChar(scalar);
	if (isPseudoLiterals(scalar))
		ScalarConverter::handlePseudoLiterals(scalar);
	else if (isInt(scalar))
		ScalarConverter::handleInt(scalar);
	else if (isFloat(scalar))
		ScalarConverter::handleFloat(scalar);
	else if (isDouble(scalar))
		ScalarConverter::handleDouble(scalar);
	else
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

/* Handlers */

void ScalarConverter::handleChar(const std::string &scalar)
{
	double val = toDouble(scalar);

	if (val >= 33 && val <= 126)
	{
		char c = static_cast<char>(val);
		std::cout << "char: " << c << std::endl;
		return;
	}
	std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::handleInt(const std::string &scalar)
{
	int val = atoi(scalar.c_str());

	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void ScalarConverter::handlePseudoLiterals(const std::string &scalar)
{
	if (scalar == "nan" || scalar == "nanf")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (scalar == "-inff" || scalar == "-inf")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (scalar == "+inff" || scalar == "+inf")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void ScalarConverter::handleFloat(const std::string &scalar)
{
	size_t len = scalar.length();
	std::string number = scalar.substr(0, len - 1);
	float val = atof(number.c_str());

	if (val < static_cast<float>(INT_MIN) || val > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << val << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void ScalarConverter::handleDouble(const std::string &scalar)
{
	char *end;
	double val = std::strtod(scalar.c_str(), &end);

	if (val < INT_MIN || val > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	// std::cout << std::fixed << std::setprecision(1);
	if (val < -FLT_MAX || val > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << val << std::endl;
}

double ScalarConverter::toDouble(const std::string &scalar)
{
	char *end;
	double val = std::strtod(scalar.c_str(), &end);
	if (*end != '\0' && *end != 'f')
		return 0.0;
	return val;
}

/* Checkers */

bool ScalarConverter::isInt(const std::string &scalar)
{
	int out = 0;
	std::istringstream iss(scalar);
	iss >> out;
	return !(iss.fail() || !iss.eof());
}

bool ScalarConverter::isPseudoLiterals(const std::string &scalar)
{
	const std::string literals[6] = {"nan", "nanf", "-inff", "+inff", "-inf", "+inf"};

	for (size_t i = 0; i < 6; i++)
		if (literals[i] == scalar)
			return true;
	return false;
}

bool ScalarConverter::isFloat(const std::string &scalar)
{
	size_t len = scalar.length();

	if (len < 2 || scalar[len - 1] != 'f')
		return false;

	std::string number = scalar.substr(0, len - 1);
	errno = 0;
	char *end;
	double val = std::strtod(number.c_str(), &end);

	if (*end != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	if (val == 0.0 && errno == ERANGE)
		return false;
	if (val > static_cast<double>(FLT_MAX) || val < -static_cast<double>(FLT_MAX))
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &scalar)
{
	errno = 0;
	char *end;
	double val = std::strtod(scalar.c_str(), &end);

	if (*end != '\0')
		return false;
	if ((val == HUGE_VAL || val == -HUGE_VAL) && errno == ERANGE)
		return false;
	if (val == 0.0 && errno == ERANGE)
		return false;
	return true;
}
