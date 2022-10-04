/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:23 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/04 11:47:51 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	create_monitor_thread(t_rule *rule)
{
	pthread_t		thread;
	int				i;

	i = 0;
	while (i < rule->philo_num)
	{
		if (pthread_create(&thread, NULL, dead_monitor, &rule->philo[i]) != 0)
			return (1);
		pthread_detach(thread);
		i ++;
	}
	return (0);
}

static int	create_philo_thread(t_rule *rule)
{
	pthread_t		thread;
	int				i;

	i = 0;
	while (i < rule->philo_num)
	{
		if (pthread_create(&thread, NULL, philo_life, &rule->philo[i]) != 0)
			return (1);
		pthread_detach(thread);
		i += 2;
	}
	i = 1;
	while (i < rule->philo_num)
	{
		if (pthread_create(&thread, NULL, philo_life, &rule->philo[i]) != 0)
			return (1);
		pthread_detach(thread);
		i += 2;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_rule	rule;

	if (ac != 5 && ac != 6)
		return (-1);
	if (rule_init(ac, av, &rule) == -1)
		return (-1);
	if (philo_init(&rule) == -1)
		return (-1);
	if (create_philo_thread(&rule) == -1)
		return (-1);
	if (create_monitor_thread(&rule) == -1)
		return (-1);
	pthread_mutex_lock(&(rule.mutex_dead));
	pthread_mutex_lock(&(rule.mutex_writing));
	pthread_mutex_unlock(&(rule.mutex_writing));
	pthread_mutex_unlock(&(rule.mutex_dead));
	return (0);
}
