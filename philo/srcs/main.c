/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:23 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 22:12:27 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int main(int ac, char *av[])
{
	t_rule	*rule;

	rule = malloc(sizeof(rule));
	if (ac != 5 && ac != 6)
		return (-1);
	if (rule_init(ac, av, rule) == -1)
		return (-1);
	if (philo_life(rule) == -1)
		return (-1);
	while (1)
	{
		if (rule->died > 1)
			return (0);
	}
}
