#include "Aristote.h"

// 0 died
// 1 alive
char	check_philo_status(int fd, t_args args, char **line)
{
	struct timeval	s;
	struct timeval	e;
	int				waiting_time;

	waiting_time = WAITING_TIME;
	gettimeofday(&s, NULL);
	e = s;
	*line = get_next_line(fd);
	while (ms(e) - ms(s) <= waiting_time + args.dtime)
	{
		gettimeofday(&e, NULL);
		if (*line && strstr(*line, "died"))
		{
			printf("%s", *line);
			return (0);
		}
		free(*line);
		*line = get_next_line(fd);
		if (!*line)
		{
			close(fd);
			fd = open(TMP_FILE, O_RDONLY, PERM);
			*line = get_next_line(fd);
		}
		if (!(ms(e) - ms(s) <= WAITING_TIME + args.dtime) &&
			(args.dtime <= args.etime + args.stime || args.n == 1) &&
			waiting_time == WAITING_TIME)
			waiting_time += EMERGENCY_WAIT;								// timeout sinon
	}
	return (1);
}

void	check_test_result(t_args args, int philo_status, char *param, char *line)
{
	if (philo_status == 0)
	{
		if (args.n == 1)
		{
			if (atoi(line) < 0 || atoi(line) > 1)
				printf("%s%sFAILED not dead at time (0ms)%s\n", BOLD, FORE_RED, DEFAULT);
			else
				printf("%s%sSUCCESS%s\n", BOLD, FORE_GREEN, DEFAULT);
		}
		else if ((atoi(line) < args.dtime - 10 && atoi(line) > args.dtime + 10) ||
				 (atoi(line) < args.dtime + args.etime - 10 && atoi(line) > args.dtime + args.etime + 10))
			printf("%s%sFAILED not dead at time (~%dms or ~%d)%s\n", BOLD, FORE_YELLOW, args.dtime, args.dtime + args.etime, DEFAULT);
		else if (!strcmp("310 200 100", &param[sd_i(param) + 1]) &&
				 args.n > 2)
			printf("%s%sSUCCESS%s\n", BOLD, FORE_GREEN, DEFAULT);
		else if (args.dtime > args.etime + args.stime)
			printf("%s%sFAILED was supposed to live%s\n", BOLD, FORE_RED, DEFAULT);
		else if (args.dtime == args.etime + args.stime)
			printf("%s%sFAILED (eating time + sleeping time = time to die --> so it can die like live)%s\n", BOLD, FORE_YELLOW, DEFAULT);
		else
			printf("%s%sSUCCESS%s\n", BOLD, FORE_GREEN, DEFAULT);
	}
	else
	{
		if (args.n == 1)
			printf("%s%sFAILED%s\n", BOLD, FORE_RED, DEFAULT);
		else if (!strcmp("310 200 100", &param[sd_i(param) + 1]) &&
				 args.n > 2)
			printf("%s%sFAILED not dead%s\n", BOLD, FORE_RED, DEFAULT);
		else if (args.dtime > args.etime + args.stime)
			printf("%s%sSUCCESS%s\n", BOLD, FORE_GREEN, DEFAULT);
		else if (args.dtime == args.etime + args.stime)
			printf("%s%sSUCCESS%s\n", BOLD, FORE_YELLOW, DEFAULT);
		else
			printf("%s%sFAILED not dead%s\n", BOLD, FORE_RED, DEFAULT);
	}
}

void	do_tests(int count, char **params)
{
	char	*join; // a MUST for PHILO() macro
	char	**split; // a MUST for PHILO() macro
	int		philo_processus;
	t_args	args;
	int		philo_status;
	int		fd;

	for (int i = 0 ; params[i] ; i++)
	{
		for (int j = 0 ; j++ < count ; )
		{
			PRINT_TEST(params[i], i);
			fd = open(TMP_FILE, O_RDONLY | O_CREAT | O_TRUNC, PERM);
			write(fd, "", 0);
			philo_processus = fork();
			if (!philo_processus)
			{
				fd = open(TMP_FILE, O_RDWR, PERM);
				dup2(fd, 1);
				close(fd);
				PHILO(params[i]);
			}
			else
			{
				char	*line;

				get_args(params[i], &args);
				philo_status = check_philo_status(fd, args, &line);
				check_test_result(args, philo_status, params[i], line);
				kill(philo_processus, SIGKILL);
				free(line);
				close(fd);
				remove(TMP_FILE);
			}
		}
	}
}

char	**set_def_params()
{
	char	**ret;
	char	*join;

	join = NULL;
	join = ft_strjoin_free(join, TEST_DEFAULT0);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT1);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT2);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT3);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT4);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT5);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT6);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT7);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT8);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT9);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT10);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT11);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT12);
	ret = ft_split(join, '|');
	free(join);
	return (ret);
}

char	**join_params(int ac, char **av)
{
	char	**ret;
	char	*join;

	if (atoi(av[1]))
	{
		av = &av[2];
		ac--;
	}
	else
		av = &av[1];
	join = NULL;
	for (int i = 0 ; i < ac - 1 ; i++)
	{
		join = ft_strjoin_free(join, av[i]);
		join = ft_strjoin_free(join, "|");
	}
	ret = ft_split(join, '|');
	free(join);
	return (ret);
}

int	main(int ac, char **av)
{
	char	default_params;
	char	**params;
	int		count;

	signal(SIGSEGV, seghandle_);
	count = 1;
	default_params = 1;
	if (ac >= 2)
		parse(ac, av, &count, &default_params);
	if (default_params == 0)
		params = join_params(ac, av);
	else
		params = set_def_params();
	do_tests(count, params);
	return (0);
}
