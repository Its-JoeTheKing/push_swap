/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:26:38 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/15 16:43:06 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_data *data)
{
	ft_sa(data, 1);
}

void	sort_3(t_data *data)
{
	int	first;
	int	sec;
	int	last;

	first = data->stack_a->num;
	sec = get_last_before_node(&data->stack_a)->num;
	last = get_last_node(&data->stack_a)->num;
	if ((first > sec) && (sec < last) && (first < last))
		ft_sa(data, 1);
	else if ((first > sec) && (sec > last) && (last < first))
		(ft_sa(data, 1), ft_rra(data, 1));
	else if ((first > sec) && (sec < last) && (first > last))
		ft_ra(data, 1);
	else if ((first < sec) && (sec > last) && (first < last))
		(ft_sa(data, 1), ft_ra(data, 1));
	else if ((first < sec) && (sec > last) && (first > last))
		ft_rra(data, 1);
	else
		return ;
}

void	sort_4(t_data *data)
{
	int	ra;

	ra = get_pos(&data->stack_a, 0);
	while (ra-- > 0)
		ft_ra(data, 1);
	ft_pb(data);
	sort_3(data);
	ft_pa(data);
}

void	sort_5(t_data *data)
{
	int	ra;

	ra = get_pos(&data->stack_a, 0);
	while (ra-- > 0)
		ft_ra(data, 1);
	ft_pb(data);
	sort_4(data);
	ft_pa(data);
}

void	sort(t_data *data)
{
	if (stack_len(&data->stack_a) == 2)
		sort_2(data);
	else if (stack_len(&data->stack_a) == 3)
		sort_3(data);
	else if (stack_len(&data->stack_a) == 4)
		sort_4(data);
	else if (stack_len(&data->stack_a) == 5)
		sort_5(data);
	else
		big_sort(data);
}
