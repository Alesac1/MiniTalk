/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:26 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/01 19:38:34 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if ((len == 0 && start == 0) || (size_t)start >= ft_strlen(s))
	{
		dst = (char *) malloc(sizeof(char) * 1);
		dst[0] = 0;
		return (dst);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dst = (char *) ft_calloc((len + 1), 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
