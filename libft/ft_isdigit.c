/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:58:39 by pnielly           #+#    #+#             */
/*   Updated: 2021/05/08 12:09:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (i > 0 && ft_isdigit(s[i - 1]) && ft_strchr("-+", s[i]))
			return (0);
		else if (ft_strchr("-+", s[i]) && !ft_isdigit(s[i + 1]))
			return (0);
		else if (!ft_isdigit(s[i]) && !ft_strchr("-+", s[i])
			&& !ft_isdelim(s[i]))
			return (0);
	}
	return (1);
}
