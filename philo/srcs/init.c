/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:28:19 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/04 11:31:24 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	rule_mutex_init(t_rule *rule)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(rule->mutex_eat_num), NULL);
	pthread_mutex_init(&(rule->mutex_dead), NULL);
	pthread_mutex_init(&(rule->mutex_writing), NULL);
	while (i < rule->philo_num)
	{
		pthread_mutex_init(&(rule->forks[i]), NULL);
		i++;
	}
	pthread_mutex_lock(&(rule->mutex_dead));
}

int	rule_init(int ac, char *av[], t_rule *rule)
{
	rule->philo_num = ft_atoi(av[1]);
	if (rule->philo_num < 1)
		return (-1);
	rule->t_death = ft_atoi(av[2]);
	if (rule->t_death < 1)
		return (-1);
	rule->t_eat = ft_atoi(av[3]);
	if (rule->t_eat < 1)
		return (-1);
	rule->t_sleep = ft_atoi(av[4]);
	if (rule->t_sleep < 1)
		return (-1);
	if (ac == 6)
	{
		rule->must_eat = ft_atoi(av[5]);
		if (rule->must_eat < 0)
			return (-1);
	}
	else
		rule->must_eat = -1;
	rule_mutex_init(rule);
	return (0);
}

int	philo_init(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->philo_num)
	{
		rule->philo[i].num = i;
		rule->philo[i].fork = 0;
		rule->philo[i].right_fork_id = rule->philo[i].num;
		rule->philo[i].left_fork_id = (rule->philo[i].num + 1) % rule->philo_num;
		rule->philo[i].rule_ptr = rule;
		rule->philo[i].eat_time = get_timestamp();
		pthread_mutex_init(&(rule->philo[i].mutex_eat_time), NULL);
		i ++;
	}
	return (0);
}
