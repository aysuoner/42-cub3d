/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unwated_elements_ctrl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:15:56 by aoner             #+#    #+#             */
/*   Updated: 2022/11/28 17:37:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int unwanted_element_ctrl(char c)
{
    if (c != '\n')
        return(0);
    return(1);
}
