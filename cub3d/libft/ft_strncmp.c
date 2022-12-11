/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:48:26 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:56:23 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*str1 ve str2'yi ilk karakterden 
 * itibaren N kadar karşılaştırır.
 *`\0'den sonra karşılaştırılmaz. 
 *tüm karakterler aynı ise sıfır değeri.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*int main()
{
	char set1[20] = "12557";
	char set2[20] = "12468";

	printf("o : %d\n", strncmp(set1, set2, 4));
	printf("t : %d", ft_strncmp(set1, set2, 4));
	
	return(0);
}*/
