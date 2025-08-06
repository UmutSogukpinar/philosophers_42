#ifndef LOCK_H
# define LOCK_H

# include "structs.h"

// * ============================ Setter Flags ============================

void	set_error_flag(t_shared_data *data, t_locks *locks, t_bool result);
void	set_death_flag(t_shared_data *data, t_locks *locks, t_bool result);
void	set_full_flag(t_shared_data *data, t_locks *locks, t_bool result);

// * =========================== Getter Flags ===========================

t_bool	get_error_flag(t_shared_data *data, t_locks *locks);
t_bool	get_death_flag(t_shared_data *data, t_locks *locks);
t_bool	get_full_flag(t_shared_data *data, t_locks *locks);

// * ============================ Locks ============================

void	lock_the_mutex(t_mutex *lock);
void	unlock_the_mutex(t_mutex *lock);

#endif