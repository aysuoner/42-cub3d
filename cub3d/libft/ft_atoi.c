/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:58 by aoner             #+#    #+#             */
/*   Updated: 2022/02/03 21:18:03 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] == ' ') || (str[c] == '\n') || \
		(str[c] == '\t') || (str[c] == '\v') || \
		(str[c] == '\f') || (str[c] == '\r'))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - 48);
		c++;
	}
	return (res * s);
}
/*
int main()
{
	char dizi[] = "b1tk1";
	char rakamsal[] = "87878787";
	char dizrak[] = "kral10";
	char rakdiz[] = "01kral";
	char eksirak[] = " \n\t\r-39i1";

	printf("%d\n",ft_atoi(dizi));
	printf("%d\n",atoi(dizi));
	printf("%d\n",ft_atoi(rakamsal));
	printf("%d\n",atoi(rakamsal));	
	printf("%d\n",ft_atoi(dizrak));
	printf("%d\n",atoi(dizrak));
	printf("%d\n",ft_atoi(rakdiz));
	printf("%d\n",atoi(rakdiz));
	printf("%d\n",ft_atoi(eksirak));
	printf("%d\n",atoi(eksirak));
	return (0);
}*/
