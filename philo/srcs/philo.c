/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:17:31 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/04 11:24:33 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	take_fork(t_philo *philo)
{
	t_rule	*rule;

	rule = philo->rule_ptr;
	pthread_mutex_lock(&(rule->forks[philo->left_fork_id]));
	output_log(TYPE_FORK, philo->num, rule);
	philo->fork++;
	if (rule->philo_num != 1)
	{
		pthread_mutex_lock(&(rule->forks[philo->right_fork_id]));
		output_log(TYPE_FORK, philo->num, rule);
		philo->fork++;
	}
}

static int	eat_pasta(t_philo *philo)
{
	t_rule	*rule;

	rule = philo->rule_ptr;
	philo->fork = 0;
	pthread_mutex_lock(&(philo->mutex_eat_time));
	take_fork(philo);
	if (philo->fork == 2)
	{
		pthread_mutex_lock(&(rule->mutex_eat_num));
		rule->eat_num ++;
		pthread_mutex_unlock(&(rule->mutex_eat_num));
		output_log(TYPE_EAT, philo->num, rule);
		usleep((rule->t_eat) * 1000);
		philo->eat_time = get_timestamp();
		pthread_mutex_unlock(&(philo->mutex_eat_time));
		pthread_mutex_unlock(&(rule->forks[philo->left_fork_id]));
		pthread_mutex_unlock(&(rule->forks[philo->right_fork_id]));
		return (0);
	}
	pthread_mutex_unlock(&(philo->mutex_eat_time));
	return (-1);
}

static void	get_sleep(t_philo *philo)
{
	t_rule	*rule;

	rule = philo->rule_ptr;
	usleep((rule->t_sleep) * 1000);
	output_log(TYPE_SLEEP, philo->num, rule);
	usleep(3000);
}

void	*philo_life(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->num % 2 != 0)
		usleep(200);
	while (1)
	{
		if (eat_pasta(philo) == 0)
		{
			get_sleep(philo);
			output_log(TYPE_THINK, philo->num, philo->rule_ptr);
		}
		else
			return (NULL);
	}
	return (NULL);
}
