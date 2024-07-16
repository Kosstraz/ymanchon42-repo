#include "Aristote.h"

// skip digits without int ptr
int	sd_i(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}

static void	skip_digits(char *str, int *start)
{
	while (str[*start] && (str[*start] >= '0' && str[*start] <= '9'))
		(*start)++;
}

static void	skip_spaces(char *str, int *start)
{
	while (str[*start] && str[*start] == ' ')
		(*start)++;
}

void	get_args(char *param, t_args *args)
{
	int	i;

	i = 0;
	args->n = atoi(param);
	skip_digits(&param[i], &i);
	skip_spaces(&param[i], &i);

	args->dtime = atoi(&param[i]);
	skip_digits(&param[i], &i);
	skip_spaces(&param[i], &i);

	args->etime = atoi(&param[i + 1]);
	skip_digits(&param[i], &i);
	skip_spaces(&param[i], &i);

	args->stime = atoi(&param[i + 4]);
}

void	parse(int ac, char **av, int *count, char *default_params)
{
	int	_atoi;

	_atoi = atoi(av[1]);
	if (ac == 2)
	{
		if (_atoi == 0)
			*default_params = 0;
		else
			*count = _atoi;
	}
	else
	{
		*default_params = 0;
		if (_atoi != 0)
			*count = _atoi;
	}
}