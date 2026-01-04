/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:36:40 by iguliyev          #+#    #+#             */
/*   Updated: 2025/07/06 20:36:42 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ft_clean(t_unit_test **tests, int log_fd, char *name)
{
	ft_printf("%s failed\n", name);
	free_tests(tests);
	close(log_fd);
	exit(EXIT_FAILURE);
}

int	open_log_file(t_unit_test **tests)
{
	int		fd;
	char	*filename;
	size_t	str1_len;
	size_t	str2_len;

	str1_len = strlen((*tests)->fun_name);
	str2_len = strlen(".log");
	filename = malloc(str1_len + str2_len + 1);
	if (!filename)
	{
		free_tests(tests);
		exit(EXIT_FAILURE);
	}
	strcpy(filename, (*tests)->fun_name);
	strcat(filename, ".log");
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(filename);
	if (fd < 0)
	{
		free_tests(tests);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_print_results(int count, int success, char *fun_name, int log_fd)
{
	int	code;

	code = 0;
	if (count == success)
	{
		ft_printf(GREEN "%d/%d" RESET " tests checked for %s\n",
			success, count, fun_name);
		dprintf(log_fd, "%s: %d/%d tests passed\n",
			fun_name, success, count);
		code = 0;
	}
	else
	{
		ft_printf(YELLOW "%d/%d" RESET " tests checked for %s\n",
			success, count, fun_name);
		dprintf(log_fd, "%s: %d/%d tests passed\n", fun_name, success, count);
		code = -1;
	}
	return (code);
}

void	ft_print_single_result(t_unit_test *test, int log_fd, int i)
{
	if (i == TEST_SUCCESS)
	{
		ft_printf("%s: %s : " GREEN "[OK]" RESET "\n",
			test->fun_name, test->test_name);
		dprintf(log_fd, "%s: %s : [OK]\n",
			test->fun_name, test->test_name);
	}
	else if (i == TEST_FAILURE)
	{
		ft_printf("%s: %s : " RED "[KO]" RESET "\n",
			test->fun_name, test->test_name);
		dprintf(log_fd, "%s: %s : [KO]\n",
			test->fun_name, test->test_name);
	}
	else
	{
		ft_printf("%s: %s : " RED "[UNKNOWN]" RESET "\n",
			test->fun_name, test->test_name);
		dprintf(log_fd, "%s: %s : [UNKNOWN]\n",
			test->fun_name, test->test_name);
	}
}
