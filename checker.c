/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:30:09 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 14:53:21 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_2d(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

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
	else if (ft_strncmp("rrr\n", str) == 0)
		ft_rrr(data);
	else if (ft_strncmp("rr\n", str) == 0)
		ft_rr(data);
	else if (ft_strncmp("ss\n", str) == 0)
		ft_ss(data);
	else
		return (ft_putstr("Error"), -1);
	return (0);
}

int	check(t_data *data)
{
	char	*ar;

	ar = get_next_line(0);
	while (ar)
	{
		if (exec_instra(ar, data))
			return (free(ar) ,0);
		free(ar);
		ar = get_next_line(0);
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
		if (!tmp || !tmp[0])
			return (free_stacks(&data), free_2d(tmp), 0);
		if (!parse_and_check(tmp, &data))
			return (free_stacks(&data), free_2d(tmp), 0);
		free_2d(tmp);
	}
	check(&data);
	free_stacks(&data);
}
