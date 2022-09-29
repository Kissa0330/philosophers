/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:45 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 21:29:17 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_rule {
	int	n_o_p;
	int	t_t_s;
	int	t_t_e;
	int	t_t_d;
	int	must_eat;
}				t_rule;

typedef struct s_philo {
	t_rule	rule;
	int		num;
	int		*forks;
	int		*eat_time;
	pthread_t	*monitor_handle;
	pthread_t	*philo_handle;
}				t_philo;

int		rule_init(int ac, char *av[], t_rule *rule);
int		*init_forks(int	num)
int		philo_life(t_rule rule);
void	output_log(int type, int ph_num);
int		ft_atoi(const char *str);

#endif