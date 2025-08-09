#ifndef STRUCTS_H
# define STRUCTS_H

# include "pthread.h"
# include "stdint.h"

# define SUCCESS 0
# define NEWLINE "\n"

# define A_BILLION "1000000000"

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DEATH_MSG	"died"

typedef uint64_t		t_ms;
typedef pthread_mutex_t	t_mutex;

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef enum e_status
{
	PICKING_UP_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}						t_status;

typedef struct s_locks
{
	t_mutex				full;
	t_mutex				print;
	t_mutex				death;
	t_mutex				error;
	t_mutex				meal;
	t_bool				meal_init;
	t_bool				error_init;
	t_bool				print_init;
	t_bool				full_init;
	t_bool				death_init;
}						t_locks;

typedef struct s_custom_data
{
	int					eat_limit;
	int					number_eat;
	size_t				number_of_phils;
	t_ms				lifetime;
	t_ms				meal_time;
	t_ms				sleep_time;
	t_ms				last_meal_time;	
	t_ms				milestone;
}						t_custom_data;

typedef struct s_shared_data
{
	t_bool				error_flag;
	t_bool				does_death_exist;
	t_bool				are_philos_full;
}						t_shared_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	t_bool				is_alive;
	t_bool				is_full;
	t_mutex				*left_fork;
	t_mutex				*right_fork;
	t_mutex				*first_fork;
	t_mutex				*last_fork;
	t_custom_data		data;
	t_shared_data		*shared_data;
	t_locks				*locks;
}						t_philo;

typedef struct s_table
{
	t_philo				*philos;
	pthread_t			monitor;
	t_locks				*locks;
	t_custom_data		data;
	t_shared_data		*shared_data;
}						t_table;

#endif
