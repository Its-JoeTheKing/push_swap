/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:01:00 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/15 16:43:44 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	re_range(t_data *data)
{
	int	offset;

	offset = 16;
	if (stack_len(&data->stack_a) >= 300)
		offset = 32;
	while (data->stack_a)
	{
		if (data->stack_a->index <= stack_len(&data->stack_b))
			ft_pb(data);
		else if (data->stack_a->index <= offset + stack_len(&data->stack_b))
		{
			ft_pb(data);
			ft_rb(data, 1);
		}
		else
			ft_ra(data, 1);
	}
}

void	big_sort(t_data *data)
{
	int	pos;

	pos = 0;
	re_range(data);
	while (data->stack_b)
	{
		while (data->stack_b->index != stack_len(&data->stack_b) - 1)
		{
			pos = get_pos(&data->stack_b, stack_len(&data->stack_b) - 1);
			if (pos <= stack_len(&data->stack_b) / 2)
				ft_rb(data, 1);
			else
				ft_rrb(data, 1);
		}
		ft_pa(data);
	}
}
