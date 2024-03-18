/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:57:33 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/18 14:59:20 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_flow(int sign, int res)
{
	if ((sign == 1 && res < 0) || (sign == -1 && - res > 0))
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (2);
}

t_num	ft_atoi(const char *str)
{
	int		i;
	t_num	res;
	int		sign;

	sign = 1;
	i = 0;
	res.num = 0;
	res.is_flow = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res.num *= 10;
		res.num += str[i] - '0';
		if (check_flow(sign, res.num) != 2)
			res.is_flow = 1;
		i++;
	}
	return ((t_num){res.num * sign, res.is_flow});
}

int	is_valid_string(char *str)
{
	int	signs;
	int	i;
	int	len;

	signs = 0;
	i = 0;
	len = 0;
	if (!str)
		return (1);
	if (str[0] == '0' && !str[1])
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		len++;
		i++;
	}
	if (signs > 1 || len == 0)
		return (0);
	return (1);
}

int	parse_and_check(char **tmp, t_data *data)
{
	int		j;
	int		num;

	j = 0;
	while (tmp[j])
	{
		if (!is_valid_string(tmp[j]) || ft_atoi(tmp[j]).is_flow)
			return (0);
		num = ft_atoi(tmp[j]).num;
		if (is_already(data->stack_a, num) == 1)
			return (0);
		lst_add_back(&data->stack_a, create_node(num, 0));
		j++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}
