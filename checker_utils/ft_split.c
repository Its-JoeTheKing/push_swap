/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:55:52 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 15:14:14 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c, int indx)
{
	int		i;
	int		j;
	int		count;
	char	*word;

	j = 0;
	i = indx;
	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		count++;
	}
	i = indx;
	word = malloc(count + 1);
	if (!word)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	skip(const char *s, char c, int *l)
{
	int	i;

	i = *l;
	while (s[i] == c && s[i])
		i++;
	*l = i;
}

static void	*free2d(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		skip(s, c, &i);
		if (s[i] != c && s[i])
		{
			res[j] = get_word(s, c, i++);
			if (!res[j++])
				return (free2d(res));
		}
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = 0;
	return (res);
}
