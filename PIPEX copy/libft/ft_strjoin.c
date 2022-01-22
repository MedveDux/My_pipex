/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:46:53 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/22 12:47:00 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(const char));
	if (!s)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		s[i] = s2[k];
		i++;
		k++;
	}
	s[i] = '\0';
	return (s);
}
