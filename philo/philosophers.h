/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:45 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 11:14:41 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo {
	int	n_o_p;
	int	t_t_s;
	int	t_t_e;
	int	t_t_d;
	int	must_eat;
}				t_philo;

void	output_log(int type, int ph_num);
int		ft_atoi(const char *str);

#endif