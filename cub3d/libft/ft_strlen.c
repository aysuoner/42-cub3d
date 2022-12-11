/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:04:45 by aoner             #+#    #+#             */
/*   Updated: 2022/02/03 21:16:24 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	leng;

	leng = 0;
	while (s[leng] != '\0')
		leng++;
	return (leng);
}
/*int main()
{
	char set[15] = "inimini";
	
	printf("origin length %lu\n", strlen(set));
	printf("test length %zu", ft_strlen(set));
	
	
	return(0);
}*/
