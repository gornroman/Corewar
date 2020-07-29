/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:53:33 by user              #+#    #+#             */
/*   Updated: 2020/06/04 17:15:17 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static void			check_player(t_vm *vm, t_car *car)
{
	int8_t				player;
	int8_t				id;
	char				*name;

	player = read_four_bytes(vm, (car->position + 1) % MEM_SIZE) * -1;
	if (player > 0 && player <= vm->players.size)
	{
		vm->winner_id = player;
		id = player + '0';
		name = vm->players.arr[player - 1]->name;
		if (vm->aff)
		{
			write(1, "A process shows that player ", 28);
			write(1, &id, 1);
			write(1, " (", 2);
			write(1, name, ft_strlen(name));
			write(1, ") is alive\n", 11);
		}
	}
}

void				op_live(t_vm *vm, t_car *car, t_arg *arg)
{
	(void)arg->first;
	vm->count_live++;
	car->last_live_cycle = 0;
	check_player(vm, car);
	car->position = (car->position + 5) % MEM_SIZE;
	car->step = OP_BYTE;
}
