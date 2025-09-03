/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:15:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/03 09:38:01 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <ostream>
#include <iostream>

int main()
{
	Data data;
	data.nothing_but_something = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data *deserializedData = Serializer::deserialize(raw);
	if (&data == deserializedData)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	return 0;
}
