/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:36:03 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/10 17:39:02 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmpr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

void	ft_write_itoa(unsigned int n)
{
	write(1, "Number of steps: ", 17);
	ft_itoa(n);
	write(1, "\n", 1);	
}
