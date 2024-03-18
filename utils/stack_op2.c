/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:51:55 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/18 15:11:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_data *data)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	ft_putstr("ss");
}

t_list	*get_last_node(t_list **head)
{
	t_list	*node;

	node = *head;
	if (!head)
		return (NULL);
	if (!*head)
		return (*head);
	while (node->next)
		node = node->next;
	return (node);
}

void	lst_add_back(t_list **head,	t_list *new_node)
{
	t_list	*node;

	if (!new_node || !head)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	node = get_last_node(head);
	node->next = new_node;
}

t_list	*get_last_before_node(t_list **head)
{
	t_list	*node;

	node = *head;
	if (!head)
		return (NULL);
	if (!*head)
		return (*head);
	while (node->next->next)
		node = node->next;
	return (node);
}
