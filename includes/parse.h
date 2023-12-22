/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:17:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/22 10:50:22 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stack.h"
# include "../gnl/get_next_line.h"

void	ft_puterr(char *s, t_stack **a, t_stack **b, char **splitted);
void	check_line(t_stack **a, t_stack **b, char *line);
char	*get_next_line(int fd);
void	parse_args(t_stack **a, t_stack **b, int ac, char **av);

#endif