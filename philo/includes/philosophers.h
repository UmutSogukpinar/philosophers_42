#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "error_log.h"
# include "structs.h"

// ===================== Initialization =====================

t_bool	init_table(char **argv, int argc);

// ===================== Free Function(s) =====================

void	free_table(t_table *table);

// ===================== Checker Function(s) =====================

t_bool	check_args(int argc, char **argv);

// ======================= Utils =======================

size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);

void	ft_putstr(char *str, int fd);
void	ft_putendl(char *str, int fd);
t_bool	display_err_msg(char *msg);

#endif