/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:17:31 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/03 22:52:33 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	take_fork(t_philo *philo)
{
	t_rule *rule;

	rule = philo->rule_ptr;
	pthread_mutex_lock(&(rule->forks[philo->num - 1]));
	output_log(TYPE_FORK, philo->num, rule);
	pthread_mutex_unlock(&(rule->forks[philo->num - 1]));
	if (philo->num == rule->philo_num)
	{
		pthread_mutex_lock(&(rule->forks[0]));
		output_log(TYPE_FORK, philo->num, rule);
		pthread_mutex_unlock(&(rule->forks[0]));
	}
	else
	{
		pthread_mutex_lock(&(rule->forks[philo->num]));
		output_log(TYPE_FORK, philo->num, rule);
		pthread_mutex_unlock(&(rule->forks[philo->num]));
	}
}

static void	eat_pasta(t_philo *philo)
{
	t_rule *rule;

	rule = philo->rule_ptr;
	take_fork(philo);
	usleep(rule->t_eat);
	pthread_mutex_lock(&(rule->mutex_eat_time));
	rule->eat_num ++;
	pthread_mutex_unlock(&(rule->mutex_eat_time));
	output_log(TYPE_EAT, philo->num, rule);
	philo->eat_time = get_timestamp();
}

static void	get_sleep(t_philo *philo)
{
	t_rule *rule;

	rule = philo->rule_ptr;
	usleep(rule->t_sleep);
	output_log(TYPE_SLEEP, philo->num, rule);
}

void	*philo_life(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->num % 2 != 0)
		usleep(1000);
	while (1)
	{
		eat_pasta(philo);
		get_sleep(philo);
		output_log(TYPE_THINK, philo->num, philo->rule_ptr);
	}
	return (NULL);
}
