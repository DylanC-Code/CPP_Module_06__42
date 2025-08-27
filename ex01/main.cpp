/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:15:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/27 12:09:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <ostream>
#include <iostream>

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	Data data;
	data.jambon = 42;

	Serializer serializer;
	uintptr_t raw = serializer.serialize(&data);
	Data *deserializedData = serializer.deserialize(raw);
	if (&data == deserializedData)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	return 0;
}
