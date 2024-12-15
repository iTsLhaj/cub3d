/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:00:43 by agaougao          #+#    #+#             */
/*   Updated: 2024/12/09 03:23:37 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ncollector.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	int				pid;
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// libc functions :)
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *str2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
void				*ft_calloc(size_t s, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);

//	additional functions :)
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);

//	bonus part :)
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);

// garbage collected :)
char				*ftgc_strtrim(char const *s1, char const *set,
						t_ncollector **collector);
void				*ftgc_calloc(size_t s, size_t size,
						t_ncollector **collector);
t_list				*ftgc_lstnew(void *content, t_ncollector **collector);
char				*ftgc_itoa(int n, t_ncollector **collector);
char				*ftgc_substr(char const *s, unsigned int start, size_t len,
						t_ncollector **collector);
char				*ftgc_strdup(const char *s, t_ncollector **collector);
char				*ftgc_strmapi(char const *s, char (*f)(unsigned int, char),
						t_ncollector **collector);
char				*ftgc_strjoin(char const *s1, char const *s2,
						t_ncollector **collector);
char				**ftgc_split(char const *s, char c,
						t_ncollector **collector);

#endif