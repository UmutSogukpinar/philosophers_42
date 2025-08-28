#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include "error_log_bonus.h"
# include "structs_bonus.h"

// ===================== Initialization =====================


// ===================== Free Function(s) =====================

void	free_table(t_table *table);

// ===================== Checker Function(s) =====================

t_bool	check_args(int argc, char **argv);

t_bool  init_table(t_table *table, int argc, char **argv);
t_bool	init_sems(t_table *table);
void    unlink_common_sems(void);
void    close_common_sems(t_semaphores *s);

// ======================= Utils =======================

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
size_t	ft_atoui(const char *str);

t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);

void	ft_putendl(char *str, int fd);

t_bool	display_err_msg(char *msg);

// ! For Debug

#endif