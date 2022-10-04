/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/04 18:46:58 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*dead_monitor(void *philo_ptr)
{
	t_philo		*philo;
	t_rule		*rule;
	long long	time;

	philo = philo_ptr;
	rule = philo->rule_ptr;
	while (1)
	{
		pthread_mutex_lock(&(philo->mutex_eat_time));
		time = get_timestamp();
		if (time - philo->eat_time > rule->t_death)
		{
			pthread_mutex_lock(&(rule->mutex_dead_log));
			output_log(TYPE_DIED, philo->num, rule);
			break ;
		}
		pthread_mutex_unlock(&(philo->mutex_eat_time));
		pthread_mutex_lock(&(rule->mutex_eat_num));
		if (rule->eat_num >= rule->must_eat && rule->must_eat != -1)
			break ;
		pthread_mutex_unlock(&(rule->mutex_eat_num));
		usleep(500);
	}
	pthread_mutex_unlock(&(rule->mutex_dead));
	return (NULL);
}
