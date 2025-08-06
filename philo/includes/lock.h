#ifndef LOCK_H
# define LOCK_H

# include "structs.h"

// * ========================= Setter Flags =========================

void	set_error_flag(t_table *table, t_bool result);
void	set_death_flag(t_table *table, t_bool result);
void	set_full_flag(t_table *table, t_bool result);

// * ========================= Getter Flags =========================

t_bool	get_error_flag(t_table *table);
t_bool	get_death_flag(t_table *table);
t_bool	get_full_flag(t_table *table);

// * =========================== Locks ===========================

void	lock_the_mutex(t_mutex *lock);
void	unlock_the_mutex(t_mutex *lock);

#endif