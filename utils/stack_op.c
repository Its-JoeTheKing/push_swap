/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:22:14 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/14 13:53:30 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_node(int num, int index)
{
	t_list	*data;

	data = malloc(sizeof(struct s_list));
	if (!data)
		return (NULL);
	data->index = index;
	data->num = num;
	data->next = NULL;
	return (data);
}

void	lst_add_front(t_list **head, t_list *new_node)
{
	t_list	*node;

	if (!new_node)
		return ;
	node = *head;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = node;
	*head = new_node;
}

int	sorted(t_list *head)
{
	int	sorted;

	sorted = 1;
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->num > head->next->num)
			sorted = 0;
		head = head->next;
	}
	return (sorted);
}

int	stack_len(t_list **head)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!head)
		return (0);
	if (!*head)
		return (0);
	node = *head;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	is_already(t_list *head, int num)
{
	if (!head || !head)
		return (0);
	while (head)
	{
		if (head->num == num)
			return (1);
		head = head->next;
	}
	return (0);
}
