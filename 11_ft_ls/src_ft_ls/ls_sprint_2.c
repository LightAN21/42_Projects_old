/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sprint_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:45:40 by jtsai             #+#    #+#             */
/*   Updated: 2019/10/15 01:23:12 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	extended_attribute(char *path)
{
	ssize_t	xattr;
	acl_t	acl;

	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		return ('@');
	else
	{
		acl = NULL;
		acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
		if (acl)
		{
			acl_free(acl);
			return ('+');
		}
	}
	return (' ');
}

void	file_permission(mode_t m, char *path, char bits[PATH_MAX])
{
	bits[0] = file_type(m);
	bits[1] = (m & S_IRUSR) ? 'r' : '-';
	bits[2] = (m & S_IWUSR) ? 'w' : '-';
	bits[3] = (m & S_IXUSR) ? 'x' : '-';
	bits[4] = (m & S_IRGRP) ? 'r' : '-';
	bits[5] = (m & S_IWGRP) ? 'w' : '-';
	bits[6] = (m & S_IXGRP) ? 'x' : '-';
	bits[7] = (m & S_IROTH) ? 'r' : '-';
	bits[8] = (m & S_IWOTH) ? 'w' : '-';
	bits[9] = (m & S_IXOTH) ? 'x' : '-';
	if (m & S_ISUID)
		bits[3] = (m & S_IXUSR) ? 's' : 'S';
	if (m & S_ISGID)
		bits[6] = (m & S_IXGRP) ? 's' : 'l';
	if (m & S_ISVTX)
		bits[9] = (m & S_IXOTH) ? 't' : 'T';
	bits[10] = extended_attribute(path);
	bits[11] = '\0';
}

void	ls_flag_l_time_and_name(struct stat data, t_ls_data msg, char *path)
{
	time_t	seconds;
	char	*t;
	char	buff[PATH_MAX];

	ft_memset(buff, 0, PATH_MAX);
	t = ctime(&data.st_mtime);
	time(&seconds);
	write(1, t + 4, 7);
	if (seconds - (time_t)data.st_mtimespec.tv_sec > TIME_DIFF)
		write(1, t + 19, 5);
	else
		write(1, t + 11, 5);
	ft_printf(" %s", msg.name);
	if (msg.type == 'l')
	{
		readlink(path, buff, PATH_MAX);
		ft_printf(" -> %s", buff);
	}
	ft_printf("\n");
}

void	ls_flag_l(t_ls_data msg, char *path)
{
	struct stat		data;
	char			bits[12];
	unsigned int	maj;
	unsigned int	min;

	data = msg.data;
	file_permission(data.st_mode, path, bits);
	ft_printf("%s ", bits);
	ft_printf("%4d\t", data.st_nlink);
	ft_printf("%s\t", getpwuid(data.st_uid)->pw_name);
	ft_printf("%s\t", getgrgid(data.st_gid)->gr_name);
	if (msg.type != 'b' && msg.type != 'c')
		ft_printf("%6lld\t", data.st_size);
	else
	{
		maj = 0;
		min = 0;
		maj = major(data.st_rdev);
		min = minor(data.st_rdev);
		ft_printf("%3u, %3u ", maj, min);
	}
	ls_flag_l_time_and_name(data, msg, path);
}
