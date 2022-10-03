/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/04 02:04:17 by takanoraika      ###   ########.fr       */
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
		pthread_mutex_lock(&(rule->mutex_eat));
		time = get_timestamp();
		if (time - philo->eat_time > rule->t_death)
		{
			output_log(TYPE_DIED, philo->num, rule);
			break ;
		}
		if (rule->eat_num == rule->must_eat && rule->must_eat != -1)
			break ;
		pthread_mutex_unlock(&(rule->mutex_eat));
		usleep(5000);
	}
	pthread_mutex_unlock(&(rule->mutex_dead));
	return (NULL);
}
