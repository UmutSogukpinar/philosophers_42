#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdint.h>
# include <stddef.h>
# include <sys/types.h>

/* ========================= Constants ========================= */

# ifndef SUCCESS
#  define SUCCESS			0
# endif

# ifndef NEWLINE
#  define NEWLINE			"\n"
# endif

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
#define SEM_FINISH  "/philo_finish"


/* ========================= Typedefs ========================= */

/* Time in milliseconds */
typedef uint64_t	t_ms;

/* ========================== Enums ========================== */

/* Boolean type */
typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

/* Philosopher status */
typedef enum e_status
{
	PICKING_UP_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}					t_status;

/* =========================== Config =========================== */
/* Immutable simulation parameters shared logically (not shared memory) */
typedef struct s_data
{
	t_ms	time_to_die;
	t_ms	time_to_eat;
	t_ms	time_to_sleep;
	t_ms	milestone;
	size_t	number_of_phils;
	int		eat_limit;
}				t_data;

/* ========================= Named semaphore bundle ========================= */
typedef struct s_semaphores
{
	sem_t	*forks;   /* pool of forks: initial = N */
	sem_t	*print;   /* serialize stdout: initial = 1 */
	sem_t	*death;   /* death/all-full event: initial = 0 */
	sem_t	*finish;  /* count full philosophers: initial = 0 */
}				t_semaphores;

/* ========================= Philosopher Struct ========================= */
typedef struct s_philo
{
	t_data			data;			/* local copy of data */
	t_semaphores	sems;           /* semaphore bundle */
	pthread_t		monitor;		/* monitor thread */
	sem_t			*meal;			/* meal semaphore */
	sem_t			*full;			/* full semaphore */
	t_ms			last_meal;		/* last eat timestamp (ms) */
	int				id; 			/* ID */
	int				meals;			/* eaten count */
}				t_philo;

/* ========================= Parent table ========================= */

typedef struct s_table
{
	t_data			data;	/* canonical data */
	t_semaphores	sems;	/* semaphore bundle */
	pid_t			*pids;	/* process ID's */
}				t_table;

#endif
