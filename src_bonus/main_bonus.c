/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:36:31 by mgaudin           #+#    #+#             */
/*   Updated: 2024/12/13 17:59:52 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;

	ft_check_ac(av, ac);
	ft_init_pipex(&pipex, av, ac);
	ft_parse_args(pipex, av, ac);
	ft_parse_paths(pipex, envp);
	ft_create_pipes(pipex);
	ft_exec(pipex, envp);
	ft_clean(pipex);
	return (0);
}
