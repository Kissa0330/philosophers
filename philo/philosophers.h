/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:45 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/05 02:00:40 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo {
	int					num;
	long long			eat_time;
	int					fork;
	int					left_fork_id;
	int					right_fork_id;
	pthread_mutex_t		mutex_eat_time;
	struct s_rule		*rule_ptr;
}				t_philo;

typedef struct s_rule {
	int					philo_num;
	int					t_sleep;
	int					t_eat;
	int					t_death;
	int					must_eat;
	int					eat_num;
	pthread_mutex_t		mutex_eat_num;
	pthread_mutex_t		mutex_finish;
	pthread_mutex_t		mutex_dead_log;
	pthread_mutex_t		mutex_writing;
	pthread_mutex_t		forks[250];
	t_philo				philo[250];
}				t_rule;

# define TYPE_FORK 1
# define TYPE_EAT 2
# define TYPE_SLEEP 3
# define TYPE_THINK 4
# define TYPE_DIED 5

int			rule_init(int ac, char *av[], t_rule *rule);
int			philo_init(t_rule *rule);
int			*init_forks(int num);
void		*philo_life(void *rule);
void		*monitor(void *philo_ptr);
long long	get_timestamp(void);
void		output_log(int type, int ph_num, t_rule *rule);
int			ft_atoi(const char *str);
void		free_philos(t_philo *philo);

#endif