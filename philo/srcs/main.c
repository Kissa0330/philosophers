/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:23 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/30 17:47:36 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_dead(t_philo *philo)
{
	while (1)
	{
		if (philo->rule->died > 1)
		{
			usleep(10);
			printf("somebody is died! wow! let's free!\n");
			free_philos(philo);
			printf("free is end\n");
			return ;
		}
	}
}

int	main(int ac, char *av[])
{
	t_rule	*rule;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (-1);
	rule = malloc(sizeof(rule));
	if (rule == NULL)
		return (-1);
	if (rule_init(ac, av, rule) == -1)
	{
		free(rule);
		return (-1);
	}
	philo = malloc(sizeof(t_philo) * rule->n_o_p);
	if (philo == NULL)
		return (-1);
	if (philo_life(rule, philo) == -1)
		return (-1);
	check_dead(philo);
	return (0);
}
