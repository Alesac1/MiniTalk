/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:19:18 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/01 17:52:39 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
