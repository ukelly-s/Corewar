/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbuilder_.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:37:11 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:37:13 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRBUILDER__H
# define STRBUILDER__H

# include "str.h"
# include "list.h"

struct					s_strbuilder
{
	char				*name;
	char				*path;
	int					fd;
	int					enabled;
};

#endif
