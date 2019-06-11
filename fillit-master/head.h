/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 15:17:32 by asvirido          #+#    #+#             */
/*   Updated: 2017/01/01 18:26:22 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 21
# define DEF1 tet->tetrim[1][0]
# define DEF2 tet->tetrim[1][1]
# define DEF3 tet->tetrim[2][0]
# define DEF4 tet->tetrim[2][1]
# define DEF5 tet->tetrim[3][0]
# define DEF6 tet->tetrim[3][1]
# define DEF7 tet->tetrim[4][0]
# define DEF8 tet->tetrim[4][1]

void				error(void);
void				ft_putstr(const char *s);
int					ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memset(void *d, int c, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					**valid(char *s);
void				ft_bzero(void *s, size_t n);
void				ft_print(char **s);
typedef struct		s_list
{
	int				**tetrim;
	char			letter;
	struct s_list	*next;
}					t_list;
t_list				*ft_nlstnew(int **tet, char let);
t_list				*open_read_close_file(char *file_name);
void				ft_nlstadd(t_list *nlst, int **tet);
char				**algoritm(t_list *new);
int					map_size(t_list *tet);
char				**create_map(int size);
char				**backtracking(char **map, t_list *tet);
int					is_place(char **map, t_list *tet);
int					place(char **map, t_list *tet, int y, int x);
void				fill(char **map, t_list *tet, int y, int x);
void				deleted(char **map, char letter);

#endif
