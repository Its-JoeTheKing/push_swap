/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:30:09 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/15 15:24:58 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	indexing(&data);
	sort(&data);
	free_stack_a(&data);
}
