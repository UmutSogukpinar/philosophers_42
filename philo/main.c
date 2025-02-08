#include "stdio.h"
#include "utils.h"
#include "stdlib.h"

static t_bool	main_part_two(t_data *data);

void print_greece(t_greece *greece)
{
    if (!greece)
    {
        printf("Error: greece objesi NULL!\n");
        return;
    }

    printf("\n========== Greece Yapısı Bilgileri ==========\n");

    // Genel simülasyon verileri
    if (greece->data)
    {
        printf("Toplam Filozof Sayısı: %d\n", greece->data->number_phils);
        printf("Ölme Süresi: %d ms\n", greece->data->time_to_die);
        printf("Yeme Süresi: %d ms\n", greece->data->time_to_eat);
        printf("Uyuma Süresi: %d ms\n", greece->data->time_to_sleep);
        printf("Yeme Limiti: %d\n", greece->data->eat_limit);
        printf("Başlangıç Zamanı: %llu ms\n", greece->data->start_time);
        printf("Ölüm Bayrağı: %s\n", greece->data->death_flag ? "EVET" : "HAYIR");
        printf("Yeme Limiti Bayrağı: %s\n", greece->data->eat_limit_flag ? "EVET" : "HAYIR");
    }
    else
    {
        printf("HATA: greece->data NULL!\n");
    }

    // Filozoflar ve durumları
    if (greece->table)
    {
        printf("\n==== Filozof Bilgileri ====\n");
        for (int i = 0; i < greece->data->number_phils; i++)
        {
            t_philo *philo = greece->table[i];
            if (!philo)
            {
                printf("HATA: Filozof %d NULL!\n", i);
                continue;
            }

            printf("\n[Filozof %d]\n", philo->id);
            printf("- Yediği Yemek Sayısı: %d\n", philo->eaten_amount);
            printf("- Son Yemek Yeme Zamanı: %llu ms\n", philo->last_meal_time);
            printf("- Şu Anki Durumu: ");
            
            switch (philo->status)
            {
                case c_eating:
                    printf("Yemek Yiyor 🍽️\n");
                    break;
                case c_thinking:
                    printf("Düşünüyor 🤔\n");
                    break;
                case c_sleeping:
                    printf("Uyuyor 😴\n");
                    break;
                case c_exit:
                    printf("Çıkıyor 🚪\n");
                    break;
                default:
                    printf("Bilinmeyen Durum ⚠️\n");
            }

            // Çatal bilgileri (ID + Durum)
            printf("- Sol Çatal ID: %d, Durumu: %s\n",
                   philo->left_fork ? philo->left_fork->id : -1,
                   philo->left_fork ? (philo->left_fork->is_free ? "Boş 🆓" : "Dolu 🍴") : "NULL");

            printf("- Sağ Çatal ID: %d, Durumu: %s\n",
                   philo->right_fork ? philo->right_fork->id : -1,
                   philo->right_fork ? (philo->right_fork->is_free ? "Boş 🆓" : "Dolu 🍴") : "NULL");
        }
    }
    else
    {
        printf("HATA: greece->table NULL!\n");
    }

    printf("========================================\n\n");
}


int	main(int argn, char **args)
{
	t_data	*data;

	if (!(check_args(argn, args)))
		return (0);
	data = init_data(argn, args);
	if (!data)
	{
		printf("Error on \033[1;31m\"init_data()\"\033[0m function\n");
		return (1);
	}
	if (main_part_two(data))
	{
		free(data);
		return (0);
	}
	free(data);
	return (1);
}

static t_bool	main_part_two(t_data *data)
{
	t_greece	*ancient_greece;

	ancient_greece = init_ancient_greece(data);
	if (!ancient_greece)
	{
		printf("Error on \033[1;31m\"main_part_two()\"\033[0m function\n");
		return (c_false);
	}
    set_table(ancient_greece->table, data);
	print_greece(ancient_greece);
	start_dining(ancient_greece);
	free(ancient_greece);
	return (c_true);
}
