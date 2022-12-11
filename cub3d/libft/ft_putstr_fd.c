/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:33:42 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:08:05 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*write(dosya_no, yazılacaklar, yazılacak_byte)
*dosya_no bilgilerin yazılacağı dosyayı temsil eder*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int main()
{
	char set[15] = "fdstringyaz";
	ft_putstr_fd(set, 2);
	
	return(0);
	
}*/
