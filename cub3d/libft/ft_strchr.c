/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:18:36 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:06:50 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*c'nin (unsigned char olarak değerlendirilir) ilk geçtiği yeri arar,
return olarak bulunan değerden sonrasını döndürür*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
/*int main()
{
	char set[6] = "123456";
	printf("o strchr : %s\n", strchr(set, '5'));
	printf("t strchr : %s", ft_strchr(set, '5'));
	
	return(0);
}*/
