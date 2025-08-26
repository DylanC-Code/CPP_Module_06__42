/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:35:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/26 12:49:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cfloat>
#include <climits>
#include <errno.h>

class ScalarConverter
{
private:
	static void handleChar(const std::string &scalar);
	static void handleInt(const std::string &scalar);
	static void handlePseudoLiterals(const std::string &scalar);
	static void handleFloat(const std::string &scalar);
	static void handleDouble(const std::string &scalar);

	static bool isInt(const std::string &scalar);
	static bool isPseudoLiterals(const std::string &scalar);
	static bool isFloat(const std::string &scalar);
	static bool isDouble(const std::string &scalar);

public:
	static void converter(const std::string &scalar);
};

#endif
