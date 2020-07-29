/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:29 by dbendu            #+#    #+#             */
/*   Updated: 2020/05/06 16:29:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void			matrix_clear(t_matrix matrix)
{
	t_matrix_sizet	m;
	size_t			rows;
	size_t			cols;
	size_t			iter;
	size_t			typesize;

	m = *(size_t***)matrix;
	rows = matrix_rows(&m);
	cols = matrix_cols(&m);
	typesize = vec_typesize(&m[0]);
	iter = 0;
	while (iter < rows)
	{
		ft_memset(m[iter], 0, typesize * cols);
		++iter;
	}
}
