/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_typesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:42 by dbendu            #+#    #+#             */
/*   Updated: 2020/05/06 16:25:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

inline int	vec_typesize(const t_vector vector)
{
	return ((t_vector_s*)(*(void**)vector - sizeof(t_vector_s)))->typesize;
}
