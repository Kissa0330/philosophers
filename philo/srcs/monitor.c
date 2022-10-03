/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/03 22:44:00 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*dead_monitor(void *philo_ptr)
{
	t_philo	*philo;
	t_rule	*rule;

	philo = philo_ptr;
	rule = philo->rule_ptr;
	if (pthread_mutex_lock(&(philo->monit_mutex)) != 0)
		return (NULL);
	while (1)
	{
		if (get_timestamp() - philo->eat_time > rule->t_death)
		{
			output_log(TYPE_DIED, philo->num, rule);
			break ;
		}
		if (rule->eat_num == rule->must_eat && rule->must_eat != -1)
			break;
	}
	pthread_mutex_unlock(&(rule->mutex_dead));
	if (pthread_mutex_unlock(&(philo->monit_mutex)) != 0)
		return (NULL);
	return (NULL);
}
