/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:08:39 by asacchin          #+#    #+#             */
/*   Updated: 2023/01/30 17:36:50 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{	
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}
