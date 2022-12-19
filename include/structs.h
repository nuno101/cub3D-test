/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 07:27:53 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#define NO 100
#define SO 101
#define WE 102
#define EA 103

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
	char	*_NO;
	char	*_SO;
	char	*_WE;
	char	*_EA;
	int		F[3];
	int		C[3];
}	t_data;

#endif