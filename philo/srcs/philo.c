/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:17:31 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 22:10:03 by takanoraika      ###   ########.fr       */
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
	pthread_t	*monit_handle;
	pthread_t	*philo_handle;

	if (pthread_create(&monit_handle, NULL, dead_monit, &philo) != 0)
		return (-1);
	if (pthread_detach(monit_handle) != 0)
		return (-1);
	if (pthread_create(&philo_handle, NULL, philo_cycle, &philo) != 0)
		return (-1);
	if (pthread_detach(philo_handle) != 0)
		return (-1);
	return (0);
}

int	philo_life(t_rule *rule)
{
	t_philo	*philo;
	size_t	i;
	int		*forks;

	i = 0;
	forks = init_forks(rule->n_o_p);
	philo = malloc(sizeof(t_philo) * rule->n_o_p);
	if (philo == NULL)
		return (-1);
	while (i < rule->n_o_p)
	{
		philo[i].num = i + 1;
		philo[i].rule = rule;
		philo[i].forks = forks;
		if (create_thread(&philo[i]) == -1)
		{
			free_philos(philo):
			return (-1);
		}
	}
	return (0);
}
