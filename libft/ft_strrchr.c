/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:09:16 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/01 19:23:20 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
