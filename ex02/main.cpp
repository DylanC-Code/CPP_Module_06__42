/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:49:53 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/27 14:04:20 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <stdlib.h>
#include <ctime>

int main()
{
	srand(time(NULL));
	Base *base = generate();
	if (!base)
		return 1;
	identify(base);
	identify(*base);
	delete base;

	return 0;
}
