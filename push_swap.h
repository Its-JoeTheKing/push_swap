/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:22:38 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 15:14:42 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char	*input;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

typedef struct s_num
{
	int		num;
	int		is_flow;
}	t_num;

t_list	*create_node(int num, int index);
void	lst_add_back(t_list **head,	t_list *new_node);
void	lst_add_front(t_list **head, t_list *new_node);
int		sorted(t_list *head);
int		stack_len(t_list **head);
int		parse_and_check(char **tmp, t_data *data);
void	free_stack_a(t_list **list, int isError);
void	indexing(t_data *data);
int		bigger_than(t_list **head, int num);
t_list	*get_last_node(t_list **head);
t_list	*get_last_before_node(t_list **head);
int		get_pos(t_list **head, int indx);
int		is_already(t_list *head, int num);
char	**ft_split(char const *s, char c);
int		is_valid_string(char *str);
t_num	ft_atoi(const char *str);
void	ft_sb(t_data *data, int put);
void	ft_sa(t_data *data, int put);
void	ft_pb(t_data *data);
void	ft_pa(t_data *data);
void	ft_rb(t_data *data, int put);
void	ft_ra(t_data *data, int put);
void	ft_rrb(t_data *data, int put);
void	ft_rra(t_data *data, int put);
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);
void	sort(t_data *data);
void	re_range(t_data *data);
void	big_sort(t_data *data);
void	ft_putstr(char *str);

#endif