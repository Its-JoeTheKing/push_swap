/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:30:09 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 15:03:20 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;
	int	r;

	i = 0;
	if (!s2)
		return (2);
	while (s1[i] || s2[i])
	{
		r = s1[i] - s2[i];
		if (r > 0)
			return (1);
		if (r < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	exec_instra(char *str, t_data *data)
{
	if (ft_strncmp("sb\n", str) == 0)
		ft_sb(data, 0);
	else if (ft_strncmp("sa\n", str) == 0)
		ft_sa(data, 0);
	else if (ft_strncmp("pb\n", str) == 0)
		ft_pb(data);
	else if (ft_strncmp("pa\n", str) == 0)
		ft_pa(data);
	else if (ft_strncmp("rb\n", str) == 0)
		ft_rb(data, 0);
	else if (ft_strncmp("ra\n", str) == 0)
		ft_ra(data, 0);
	else if (ft_strncmp("rrb\n", str) == 0)
		ft_rrb(data, 0);
	else if (ft_strncmp("rra\n", str) == 0)
		ft_rra(data, 0);
	else if (ft_strncmp(0, str) == 2)
		return (0);
	else
		return (ft_putstr("Error"), -1);
	return (0);
}

int	check(t_data *data)
{
	char	*ar;

	ar = get_next_line(0);
	exec_instra(ar, data);
	free(ar);
	while (ar)
	{
		ar = get_next_line(0);
		if (exec_instra(ar, data))
			return (free_stack_a(data), 0);
		free(ar);
	}
	if (sorted(data->stack_a))
		return (ft_putstr("OK"), 0);
	return (ft_putstr("KO"), 0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**tmp;
	int		i;

	data.stack_a = 0;
	data.stack_b = 0;
	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (0);
		if (!parse_and_check(tmp, &data))
			return (free_stack_a(&data), 0);
	}
	if (sorted(data.stack_a))
		return (free_stack_a(&data), 0);
	check(&data);
}
