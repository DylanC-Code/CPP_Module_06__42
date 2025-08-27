/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:40:07 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/27 14:08:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "type: unknow" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "type: A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "type: B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "type: C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "type: unknow" << std::endl;
			}
		}
	}
}
