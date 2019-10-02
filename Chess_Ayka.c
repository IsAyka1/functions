#include <stdio.h>

#define Input  x, y, ac, av
#define Output  int x, int y, int ac, char *av[]

int Queen(Output);
int Rook(Output);
int Elephant(Output);
int Pawn(Output);

void	main(int ac, char *av[]){
	int		x = 0;
	int 	y = 0;
	int 	Success = 0;

	for(int i = 1; i < ac; ++i) {
		for(int j = 0; av[i][j] != '\0'; ++j) {
			if (!Success) {
				if (av[i][j] != 'K') {
					if (av[i][j] == 'Q') {
						x = i;
						y = j; printf("q ");
						Success = Queen(Input);
					} else if (av[i][j] == 'R') {
						x = i;
						y = j; printf("r ");
						Success = Rook(Input);
					} else if (av[i][j] == 'E') {
						x = i;
						y = j; printf("e ");
						Success = Elephant(Input);
					} else if (av[i][j] == 'P') {
						x = i;
						y = j; printf("p ");
						Success = Pawn(Input);
					}
				}
			} else {
				printf("Success\n");
				return;
			}
		}
	}
	printf("Fail\n");
}

int Queen(Output) {
	short i, j;
	if((i = (short)Elephant(Input)) + (j = (short)Rook(Input))) {
		return 1;
	} else return 0;
}

int Rook(Output) {
	for(int k = 1; x + k < ac && av[x + k][y] != '\0'; ++k) {
		if(av[x + k][y] != '.') {
			if (av[x + k][y] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; x - k != 1 && av[x - k][y] != '\0'; ++k) {
		if(av[x - k][y] != '.') {
			if (av[x - k][y] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; av[x][y + k] != '\0'; ++k) {
		if(av[x][y + k] != '.') {
			if (av[x][y + k] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; y - k >= 0 && av[x][y - k] != '\0'; ++k) {
		if(av[x][y - k] != '.') {
			if (av[x][y - k] == 'K') return 1;
			else break;
		}
	}
	return 0;
}

int Elephant(Output) {
	for(int k = 1; x + k < ac && av[x + k][y + k] != '\0'; ++k) {
		if(av[x + k][y + k] != '.') {
			if (av[x + k][y + k] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; x - k != 1 && av[x - k][y + k] != '\0'; ++k) {
		if(av[x - k][y + k] != '.') {
			if (av[x - k][y + k] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; x + k < ac && y - k >= 0 && av[x + k][y - k] != '\0'; ++k) {
		if(av[x + k][y - k] != '.') {
			if (av[x + k][y - k] == 'K') return 1;
			else break;
		}
	}
	for(int k = 1; x - k != 1 && y - k >= 0 && av[x - k][y - k] != '\0'; ++k) {
		if(av[x - k][y - k] != '.') {
			if (av[x - k][y - k] == 'K') return 1;
			else break;
		}
	}
	return 0;
}

int Pawn(Output) {
	if(x != 1 && y != 0 && x < ac && av[x][y] != '\0') {
		if (av[x - 1][y - 1] == 'K') return 1;
		else if (av[x - 1][y + 1] == 'K') return 1;
		else return 0;
	}
}