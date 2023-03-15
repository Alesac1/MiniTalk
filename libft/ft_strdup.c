/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:59:04 by asacchin          #+#    #+#             */
/*   Updated: 2023/01/30 16:04:28 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*s2;

	len_s = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s, (len_s + 1));
	return (s2);
}
