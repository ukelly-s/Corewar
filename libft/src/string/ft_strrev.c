/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:37:49 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:38:02 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrev(register char *begin, register char *end)
{
	register char	tmp;

	while (end > begin)
	{
		tmp = *end;
		*end-- = *begin;
		*begin++ = tmp;
	}
}
