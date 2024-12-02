/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:26:18 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 14:35:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

char	*super_join(char **argv);
void	duble_push(t_list **lst_a, t_list **lst_b);
int		check_error_2(int argc, char **argv);
void	little_sort(t_list **lst_a, t_list **lst_b);
int		check_dubble(char *argv);
void	aff(t_list *lst_a, t_list *lst_b);
int		is_sort(t_list *lst_a, t_list *lst_b, int n);
int		get_min(t_list *lst, int n);
int		get_max(t_list *lst, int n);
int		where(t_list *node, t_list **lst);
int		va(int i);
int		max_min(t_list *lst, int n);
int		min_max(t_list **lst, int n);
t_list	*ft_lstsecondlast(t_list *lst);
t_list	*search_b(t_list *lst_a, t_list *lst_b);
void	duble_r(t_list *node, t_list **lst_a, t_list **lst_b);
void	ft_rra(t_list **lst, int min);
void	ft_ra(t_list **lst, int min);
void	finish(t_list **lst);
void	finish_b(t_list **lst);
void	sort_last_3(t_list **lst);
void	sort_b(t_list **lst_b, t_list **lst_a);
void	sort(t_list **lst_a, t_list **lst_b);
void	r(t_list **lst);
void	rr(t_list **lst);
void	swap(t_list *lst);
void	push(t_list **lst_a, t_list **lst_b);

#endif
