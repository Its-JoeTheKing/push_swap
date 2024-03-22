/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:30:09 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 15:18:46 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**tmp;
	int		i;

	data.stack_a = 0;
	data.stack_b = 0;
	i = 0;
	if (argc < 2)
		return (write(2, "Error", 5), -1);
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || !tmp[0])
			return (free_stack_a(&data.stack_a, 1), free_2d(tmp), -1);
		if (!parse_and_check(tmp, &data))
			return (free_stack_a(&data.stack_a, 1), free_2d(tmp), -1);
		free_2d(tmp);
	}
	if (sorted(data.stack_a))
		return (free_stack_a(&data.stack_a, 0), 0);
	indexing(&data);
	sort(&data);
	free_stack_a(&data.stack_a, 0);
}
