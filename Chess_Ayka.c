#include <stdio.h>

#define Input  x, y, ac, av
#define Output  int x, int y, int ac, char *av[]

int Queen(Output);
int Rook(Output);
int Elephant(Output);
int Pawn(Output);

void	Chess_Ayka(int ac, char *av[]){
	int		x = 0;
	int 	y = 0;
	int 	Success = 0;

	//printf("%s\n",av[0]);
	for(int i = 1; i!= ac; ++i) {
		for(int j = 0; av[i][j] != '\0'; ++j) {
			if (!Success) {
				if (av[i][j] != 'K') {
					if (av[i][j] == 'Q') {
						x = i;
						y = j; printf("q ");
						Success = Queen(Input);
					} else if (av[i][j] == 'R') {
						x = i;
						y = j;printf("r ");
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
	int 	f1 = 1;
	int 	f2 = 1;
	int		f3 = 1;
	int 	f4 = 1;
	int 	f5 = 1;
	int 	f6 = 1;
	int		f7 = 1;
	int 	f8 = 1;
	for(int k = 1; (x + k != ac) || (av[x][y + k] != '\0'); ++k) {
		if (av[x + k][y] != '.') {
			if (f1) {
				if (av[x + k][y] == 'K') return 1;
				else f1 = 0;
			}
		}
		if (av[x][y + k] != '.') {
			if (f2) {
				if (av[x][y + k] == 'K') return 1;
				else f2 = 0;
			}
		}
		if (av[x - k][y] != '.') {
			if (f3) {
				if (av[x - k][y] == 'K') return 1;
				else f3 = 0;
			}
		}
		if (av[x][y - k] != '.') {
			if (f4) {
				if (av[x][y - k] == 'K') return 1;
				else f4 = 0;
			}
		}
		if (av[x + k][y + k] != '.') {
			if (f5) {
				if (av[x + k][y + k] == 'K') return 1;
				else f5 = 0;
			}
		}
		if (av[x - k][y + k] != '.') {
			if (f6) {
				if (av[x - k][y + k] == 'K') return 1;
				else f6 = 0;
			}
		}
		if (av[x + k][y - k] != '.') {
			if (f7) {
				if (av[x + k][y - k] == 'K') return 1;
				else f7 = 0;
			}
		}
		if (av[x - k][y - k] != '.') {
			if (f8) {
				if (av[x - k][y - k] == 'K') return 1;
				else f8 = 0;
			}
		}
	}
	return 0;
}

int Rook(Output) {
	int 	f1 = 1;
	int 	f2 = 1;
	int		f3 = 1;
	int 	f4 = 1;
	for(int k = 1; (x + k != ac) || (av[x][y + k] != '\0'); ++k) {
		if (av[x + k][y] != '.') {
			if (f1) {
				if (av[x + k][y] == 'K') return 1;
				else f1 = 0;
			}
		}
		if (av[x][y + k] != '.') {
			if (f2) {
				if (av[x][y + k] == 'K') return 1;
				else f2 = 0;
			}
		}
		if (av[x - k][y] != '.') {
			if (f3) {
				if (av[x - k][y] == 'K') return 1;
				else f3 = 0;
			}
		}
		if (av[x][y - k] != '.') {
			if (f4) {
				if (av[x][y - k] == 'K') return 1;
				else f4 = 0;
			}
		}
	}
	return 0;
}

int Elephant(Output) {
	int 	f1 = 1;
	int 	f2 = 1;
	int		f3 = 1;
	int 	f4 = 1;
	for(int k = 1; (x + k != ac) || (av[x][y + k] != '\0'); ++k) { //////out
		if (av[x + k][y + k] != '.') {
			if (f1) {
				if (av[x + k][y + k] == 'K') return 1;
				else f1 = 0;
			}
		}
		if (av[x - k][y + k] != '.') {
			if (f2) {
				if (av[x - k][y + k] == 'K') return 1;
				else f2 = 0;
			}
		}
		if (av[x + k][y - k] != '.') {
			if (f3) {
				if (av[x + k][y - k] == 'K') return 1;
				else f3 = 0;
			}
		}
		if (av[x - k][y - k] != '.') {
			if (f4) {
				if (av[x - k][y - k] == 'K') return 1;
				else f4 = 0;
			}
		}
	}
	return 0;
}

int Pawn(Output) {
	if(x != 1 && y != 0 && x != ac && av[x][y] != '\0') {
		if (av[x - 1][y - 1] == 'K') return 1;
		else if (av[x - 1][y + 1] == 'K') return 1;
		else return 0;
	}
}

