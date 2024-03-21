/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:13:04 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 15:14:34 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	free_stack_a(t_list **list, int isError)
{
	t_list	*next;

	while ((*list))
	{
		next = (*list)->next;
		(*list)->num = 0;
		(*list)->index = 0;
		free((*list));
		(*list) = next;
	}
	if (isError)
		write(2, "Error", 5);
}
