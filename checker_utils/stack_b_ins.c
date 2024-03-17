/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_ins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:19:35 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 14:39:55 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_sb(t_data *data, int put)
{
	t_list	*tmp;

	if (stack_len(&data->stack_b) < 2)
		return ;
	tmp = data->stack_b->next;
	data->stack_b->next = data->stack_b->next->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
	(void)put;
}

void	ft_pb(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	if (stack_len(&data->stack_a) == 0)
		return ;
	data->stack_a = data->stack_a->next;
	lst_add_front(&data->stack_b, tmp);
}

void	ft_rb(t_data *data, int put)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_len(&data->stack_b) < 2)
		return ;
	last = get_last_node(&data->stack_b);
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	last->next = tmp;
	(void)put;
}

void	ft_rrb(t_data *data, int put)
{
	t_list	*last;
	t_list	*last_prev;

	if (stack_len(&data->stack_b) < 2)
		return ;
	last_prev = get_last_before_node(&data->stack_b);
	last = get_last_node(&data->stack_b);
	last_prev->next = NULL;
	lst_add_front(&data->stack_b, last);
	(void)put;
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
}
