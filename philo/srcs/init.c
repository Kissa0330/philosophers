/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:28:19 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 22:12:11 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	rule_init(int ac, char *av[], t_rule *rule)
{
	rule->n_o_p = ft_atoi(av[1]);
	if (rule->n_o_p < 1)
		return (-1);
	rule->t_t_d = ft_atoi(av[2]);
	if (rule->t_t_d < 1)
		return (-1);
	rule->t_t_e = ft_atoi(av[3]);
	if (rule->t_t_e < 1)
		return (-1);
	rule->t_t_s = ft_atoi(av[4]);
	if (rule->t_t_s < 1)
		return (-1);
	if (ac == 6)
	{
		rule->must_eat = ft_atoi(av[5]);
		if (rule->must_eat < 0)
			return (-1);
	}
	else
		rule->must_eat = -1;
	rule->died = 0;
	return (0);
}

int	*init_forks(int	num)
{
	size_t	i;
	int		*forks;

	i = 0;
	forks = malloc(sizeof(int) * num);
	while (i < num)
	{
		forks[i] = 1;
		i ++;
	}
	return (forks);
}
