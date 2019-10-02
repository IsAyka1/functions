#include "tasks.h"
int Words(const char *str);
int NextLine(char **array, const char *str, int words);
void Copy(const char *str, char **array, int Long, int start, int w);
//"hello world 1  3 	& ]"
//hello
//world
//1
//3
//&
//]

char	**ft_splitAyka() {
	char	*str = (char*)calloc(100, sizeof(char));
	char	**array;
	int 	words = 0;
	int 	f = 1;
	if(!str) {
		printf("Can't find free memory!");
		free(str);
		return  NULL;
	}
	printf("Please input your string and press 'enter'\n");
	scanf("%[^\n]%*c", str);
	words = Words(str);
	if(words) {
		array = (char **) calloc(words, sizeof(char*));
	} else {
		printf("Can't find words!");
		return NULL;
	}
	if(!array) {
		printf("Can't find free memory!");
		free(array);
		return  NULL;
	}
	f = NextLine(array, str, words);
	if(f) {
		for (int i = 0; i != words; ++i) {
			printf("%s\n", array[i]);
		}
		return array;
	} else printf("No free memory, GoodBye!\n");
	return 0;
}

 int Words(const char *str) {
	int		w = 0;
	int 	c = 0;
	for(int i = 0; str[i - 1] != '\0'; ++i) {
		if(!((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\n' || str[i] == '\0')) {
			++c;
		} else if(c > 0) {
			++w;
			c = 0;
		}
	}
	return w;
}

int NextLine(char **array, const char *str, int words) {
	int		i = 0;
	int		w = 0;
	int 	c = 0;
	for(i = 0; str[i - 1] != '\0'; ++i) {
		if(!((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\n' || str[i] == '\0')) {
			++c;
		} else if(c > 0) {
			array[w] = (char *) calloc(c + 1, sizeof(char));
			if (!array[w]) {
				printf("Can't find free memory!");
				for(int j = 0; j != w; ++j) {
					free(array[j]);
				}
				free(array);
				return 0;
			}
			Copy(str, array, c, i - c, w);
			++w;
			c = 0;
		}
	}
	return 1;
}
void Copy(const char *str, char **array, int Long, int start, int w) {
	for(int i = 0; i!= Long; ++i) {
		array[w][i] = str[start + i];
	}
	array[w][Long] = '\0';
}