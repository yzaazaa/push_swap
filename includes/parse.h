/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:17:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/24 10:37:51 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stack.h"
# include "../gnl/get_next_line.h"

void	check_line(t_stack **a, t_stack **b, char *line);
void	parse_args(t_stack **a, t_stack **b, int ac, char **av);

#endif