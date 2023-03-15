/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:26:00 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/01 18:33:11 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((s1[a] != '\0' || s2[a] != '\0') && a <= (n - 1))
	{
		if (s1[a] == s2[a])
			a++;
		else
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
