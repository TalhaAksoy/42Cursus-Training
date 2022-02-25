/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:45:21 by saksoy            #+#    #+#             */
/*   Updated: 2022/02/24 12:00:38 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_in(char c, char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int	i = 0;
	while(str[i] && str)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	*s1 = argv[1];
		char	*s2 = argv[2];
		int		i;
		while(s1[i])
		{
			if(!is_in(s1[i],s1,i))
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while(s2[i])
		{
			if(!is_in(s2[i],s2,i) && !is_in(s2[i],s1,ft_strlen(s1)))
				write(1, &s2[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
