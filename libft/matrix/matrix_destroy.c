/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/05/06 16:31:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void			matrix_destroy(t_matrix matrixptr)
{
	size_t			iter;
	size_t			rows;
	t_matrix_sizet	matrix;

	matrix = *(t_matrix_sizet*)matrixptr;
	rows = vec_size(&matrix);
	iter = 0;
	while (iter < rows)
	{
		vec_destroy(matrix + iter);
		++iter;
	}
	vec_destroy(&matrix);
}
