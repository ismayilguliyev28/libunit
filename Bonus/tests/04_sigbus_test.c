/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sigbus_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:10:21 by abita             #+#    #+#             */
/*   Updated: 2025/07/06 18:10:23 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	sigbus_test(void)
{
	raise(SIGBUS);
	return (TEST_SUCCESS);
}

// int	sigbus_test(void)
// {
// 	FILE	*f;
// 	int		*m;

// 	f = tmpfile();
// 	if (!f)
// 		return (TEST_FAILURE);
// 	m = mmap(0, 4, PROT_WRITE, MAP_PRIVATE, fileno(f), 0);
// 	fclose(f);
// 	*m = 0;
// 	return (TEST_SUCCESS);
// }
