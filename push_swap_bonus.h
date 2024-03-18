/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:06:46 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/18 14:08:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
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
void	free_stack_a(t_data *data);
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
void	ft_putstr(char *str);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *str);
char	*_get_line(char *line);
char	*get_rem(char *line);
char	*get_next_line(int fd);

#endif