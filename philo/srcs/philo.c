/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:17:31 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 21:31:10 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_cycle(t_philo *philo)
{
	while (1)
	{
		if (philo->num % 2 == 1)
			usleep(200);
		take_fork();
		eat_pasta();
		get_sleep();
	}
}

int	create_thread(t_philo philo)
{
	
}

int	philo_life(t_rule rule)
{
	t_philo	*philo;
	size_t	i;
	int		*forks;

	i = 1;
	forks = init_forks(rule.n_o_p);
	philo = malloc(sizeof(t_philo) * rule.n_o_p);
	if (philo == NULL)
		return (-1);
	while (i <= rule.n_o_p)
	{
		philo[i].num = i;
		philo[i].rule = rule;
		philo[i].forks = forks;
		if (create_thread(&philo[i]) == -1)
			return (-1);
	}
	return (0);
}
