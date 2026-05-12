#include <stdio.h>

int parse_args(char *input, char **argv, int max_args)
{
	char *p = input;
	int argc = 0;

	if (input == NULL || argv == NULL || max_args <= 0) {
		return 0;
	}

	while (*p != '\0') {
		while (*p == ' ') {
			p++;
		}

		if (*p == '\0' || argc >= max_args) {
			break;
		}

		if (*p == '"') {
			p++;
			argv[argc] = p;
			argc++;

			while (*p != '\0' && *p != '"') {
				p++;
			}

			if (*p != '"') {
				return -1;
			}

			*p = '\0';
			p++;
		} else {
			argv[argc] = p;
			argc++;

			while (*p != '\0' && *p != ' ') {
				p++;
			}

			if (*p == ' ') {
				*p = '\0';
				p++;
			}
		}
	}

	return argc;
}

int main(void)
{
	char input[] = "run -f \"hello world.txt\" --count 10";
	char *argv[10];

	int argc = parse_args(input, argv, 10);

	if (argc < 0) {
		printf("parse error: unclosed quote\n");
		return 1;
	}

	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	return 0;
}
