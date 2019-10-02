#include "tasks.h"

typedef struct	s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

t_list	*createElem(char c) {
	t_list	*new = NULL;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL) {
		return NULL;
	}
	new->c = c;
	new->next = NULL;
	return new;
}

void	pushBack(t_list **beginList, t_list *new) {
	t_list	*tmp = NULL;

	if (beginList == NULL || new == NULL) {
		printf("Invalid params\n");
		return ;
	}
	tmp = *beginList;
	if (tmp == NULL) {
		beginList = &new;
	} else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	pushBegin(t_list **beginList, t_list *new) {
	t_list	*tmp = NULL;

	if (new == NULL || beginList == NULL) {
		printf("Invalid params\n");
		return ;
	}
	tmp = *beginList;
	beginList = &new;
	new->next = tmp;
}

t_list	*getNElem(t_list **beginList, size_t n) {
	t_list	*tmp = NULL;
	size_t	i = -1;

	if (beginList == NULL) {
		printf("Invalid params\n");
		return NULL;
	}
	tmp = *beginList;
	while (++i < n && tmp != NULL) {
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		printf("List have no N element\n");
		return NULL;
	} else {
		return tmp;
	}
}

void	delNElem(t_list **beginList, size_t n) {
	t_list	*tmp = NULL;
	t_list	*del = NULL;
	t_list	*prev = NULL;
	size_t	i = -1;

	if (beginList == NULL) {
		printf("Invalid params\n");
		return ;
	}
	if (n == 0) {
		if (*beginList == NULL) {
			printf("List have no N element\n");
			return ;
		} else {
			del = *beginList;
			beginList = &((*beginList)->next);
			free(del);
		}
	} else {
		tmp = *beginList;
		while (++i < n && tmp != NULL) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			printf("List have no N element\n");
			return ;
		} else {
			if (tmp->next == NULL) {
				prev->next = NULL;
				del = tmp;
				free(del);
			} else {
				prev->next = tmp->next;
				del = tmp;
				free(del);
			}
		}
	}
}

void	revers(t_list **beginList) {
	t_list	*tmp = NULL;
	t_list	*prev = NULL;
	t_list	*next = NULL;

	if (beginList == NULL || *beginList == NULL || (*beginList)->next == NULL) {
		printf("Invalid params\n");
		return ;
	} else {
		tmp = *beginList;
		while (tmp->next != NULL) {
			next = tmp->next;
			prev = tmp;
			tmp = tmp->next;
			next->next = prev;
		}
		beginList = &next;
	}
}

void	pushNElem(t_list **beginList, t_list *new, size_t n) {
	t_list	*tmp = NULL;
	t_list	*prev = NULL;
	size_t	i = -1;

	if (n == 0) {
		pushBegin(beginList, new);
		return ;
	}
	if (beginList == NULL || *beginList == NULL) {
		printf("Invalid params\n");
		return ;
	} else {
		tmp = *beginList;
		while (++i < n && tmp != NULL) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			printf("List have no N element\n");
			return ;
		} else {
			prev->next = new;
			new->next = tmp;
		}
	}
}

void	ft_list() {
}
