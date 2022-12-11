/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:02:39 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:35:17 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/* 
int main()
{
	
	int a = 47, b = 48;
	
	printf("origin a: %d     b:%d\n", isdigit(a), isdigit(b));
	printf("test   a: %d     b: %d", ft_isdigit(a), ft_isdigit(b));
	
	return(0);
}
*/
