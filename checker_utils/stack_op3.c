/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:13:04 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 14:42:04 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	bigger_than(t_list **head, int num)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = *head;
	while (stack)
	{
		if (stack->num < num)
			i++;
		stack = stack->next;
	}
	return (i);
}

void	indexing(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (data->stack_a)
	{
		data->stack_a->index = bigger_than(&tmp, data->stack_a->num);
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = tmp;
}

int	get_pos(t_list **head, int indx)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!head || !*head)
		return (-1);
	node = *head;
	while (node)
	{
		if (node->index == indx)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

void	free_stack_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (data->stack_a)
	{
		free(data->stack_a);
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = tmp;
	tmp = data->stack_b;
	while (data->stack_b)
	{
		free(data->stack_b);
		data->stack_b = data->stack_b->next;
	}
	data->stack_b = tmp;
}
