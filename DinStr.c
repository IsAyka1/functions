#include "tasks.h"

void	DinStr() {
	int 	lenght;
	int		k = 0;

	scanf("%d", &lenght);
	char	*str = (char*)malloc(sizeof(char) * (lenght + 1));
	if(str) {
		gets(str);
	} else {
		exit(-1);
	}

	for(int i = 0; str[i] != '\0'; ++i) {
		if(str[i] == '+') {
			if((str[i + 1] >= '0') && (str[i + 1]  <= '9'))  {
				++k;
				continue;
			} else {
				str[i - k] = str[i];
				if(str[i + k] == '\0') {
					str[i] = '\0';
				}
			}
		} else {
			str[i - k] = str[i];
			if(str[i + k] == '\0') {
				str[i] = '\0';
			}
		}

	}
	printf("\n %s", str);
}

