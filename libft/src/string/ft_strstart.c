/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:36:59 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:37:02 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_strstart(const char *str, const char *prefix)
{
	return (ft_strnequ(str, prefix, ft_strlen(prefix)));
}
