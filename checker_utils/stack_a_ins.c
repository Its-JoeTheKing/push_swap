/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_ins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:07:19 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 13:22:27 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_data *data, int put)
{
	t_list	*tmp;

	if (stack_len(&data->stack_a) < 2)
		return ;
	tmp = data->stack_a->next;
	data->stack_a->next = data->stack_a->next->next;
	tmp->next = data->stack_a;
	data->stack_a = tmp;
	(void)put;
}

void	ft_pa(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_b;
	if (stack_len(&data->stack_b) == 0)
		return ;
	data->stack_b = data->stack_b->next;
	lst_add_front(&data->stack_a, tmp);
}

void	ft_ra(t_data *data, int put)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_len(&data->stack_a) < 2)
		return ;
	last = get_last_node(&data->stack_a);
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	last->next = tmp;
	(void)put;
}

void	ft_rra(t_data *data, int put)
{
	t_list	*last;
	t_list	*last_prev;

	if (stack_len(&data->stack_a) < 2)
		return ;
	last_prev = get_last_before_node(&data->stack_a);
	last = get_last_node(&data->stack_a);
	last_prev->next = NULL;
	lst_add_front(&data->stack_a, last);
	(void)put;
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
}
