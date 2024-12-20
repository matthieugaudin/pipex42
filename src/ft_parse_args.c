/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:49 by mgaudin           #+#    #+#             */
/*   Updated: 2024/12/12 19:11:33 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_fill_cmds_args(t_pipex *pipex, char **av)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmds)
	{
		pipex->cmds_args[i] = ft_split(av[i + 2], ' ');
		if (!pipex->cmds_args[i])
			ft_fail_and_clean(pipex, "malloc", 1);
		i++;
	}
}

void	ft_parse_args(t_pipex *pipex, char **av, int ac)
{
	pipex->nb_cmds = ac - 3;
	pipex->cmds_args = malloc(sizeof(char **) * (pipex->nb_cmds + 1));
	if (!pipex->cmds_args)
		ft_fail_and_clean(pipex, "malloc", 1);
	pipex->cmds_args[pipex->nb_cmds] = NULL;
	ft_fill_cmds_args(pipex, av);
}
