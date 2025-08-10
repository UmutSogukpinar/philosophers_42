#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdint.h>
# include <stddef.h>

/* ========================= Constants ========================= */
# define SUCCESS			0
# define NEWLINE			"\n"

# define A_BILLION			"1000000000"

# ifndef MAX_INT
#  define MAX_INT			2147483647
# endif

# define FORK_MSG			"has taken a fork"
# define EAT_MSG			"is eating"
# define SLEEP_MSG			"is sleeping"
# define THINK_MSG			"is thinking"
# define DEATH_MSG			"died"

/* ========================= Semaphore Names ========================= */
/* Use fixed names; parent must sem_unlink() before open to avoid leftovers */

#define SEM_FORKS   "/philo_forks"
#define SEM_PRINT   "/philo_print"
#define SEM_DEATH   "/philo_death"
#define SEM_FULL    "/philo_full"
#define SEM_LIMIT   "/philo_limit"   /* K = floor(N/2) tokens */


/* ========================= Typedefs ========================= */
typedef uint64_t	t_ms;

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef enum e_status
{
	PICKING_UP_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}					t_status;

/* ========================= Config (copied into each child) ========================= */
/* Immutable simulation parameters shared logically (not shared memory) */
typedef struct s_data
{
	size_t	number_of_phils; /* N */
	int		eat_limit;       /* <=0 means infinite */
	t_ms	time_to_die;     /* ms */
	t_ms	time_to_eat;     /* ms */
	t_ms	time_to_sleep;   /* ms */
	t_ms	start_ts;        /* simulation epoch (parent sets once) */
}	t_data;

/* ========================= Named semaphore bundle ========================= */
typedef struct s_semaphores
{
	sem_t	*forks;   /* pool of forks: initial = N */
	sem_t	*print;   /* serialize stdout: initial = 1 */
	sem_t	*death;   /* death/all-full event: initial = 0 */
	sem_t	*full;    /* count full philosophers: initial = 0 */
	sem_t	*limit;   /* admission tokens: initial = floor(N/2) (or 1 if N==1) */
	sem_t	*start;   /* start barrier: parent posts N once all children forked */
}	t_semaphores;

/* ========================= Child-local process state ========================= */
/* Lives ONLY in the child address space (no globals, no shared memory) */
typedef struct s_philo
{
	int				id;            /* 1..N (stable) */
	int				meals;         /* eaten count */
	t_ms			last_meal_ts;  /* last eat timestamp (ms) */
	t_data			data;           /* local copy of config */
	t_semaphores	sems;          /* handles to named semaphores */
}	t_philo;

/* ========================= Parent table (master context) ========================= */
/* Lives ONLY in parent; children get only their own pid and cfg copy */
typedef struct s_table
{
	t_data			data;     /* canonical config */
	t_semaphores	sems;    /* created by parent */
	pid_t			*pids;   /* size = N, allocated in parent */
}	t_table;

#endif
