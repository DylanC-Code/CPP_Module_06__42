/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:16:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/27 11:49:03 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

struct Data
{
	int jambon;
};

class Serializer
{
public:
	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};

#endif
