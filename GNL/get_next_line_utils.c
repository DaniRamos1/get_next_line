/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danramos <danramos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:41:20 by danramos          #+#    #+#             */
/*   Updated: 2025/01/15 18:36:02 by danramos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str2;

	i = -1;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	str2 = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (str2 == NULL)
		return (NULL);
	if (str)
	{
		while (str[++i] != '\0')
			str2[i] = str[i];
	}
	while (buffer[j] != '\0')
		str2[i++] = buffer[j++];
	str2[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	return (free(str), str = NULL, str2);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	str2 = (char *)malloc(sizeof(char) * (i + 2));
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str2)
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}
