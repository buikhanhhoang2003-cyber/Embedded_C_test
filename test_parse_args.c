#include <stdio.h>
#include <string.h>

int parse_args(char *input, char **argv, int max_args)
{
	char *p = input;
	char **out = argv;
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
			*out = p;
			out++;
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
			*out = p;
			out++;
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

static void test_case(const char *test_name, char *input, int expected_argc)
{
	char *argv[10];
	int argc = parse_args(input, argv, 10);
	int i = 0;

	printf("=== Test: %s ===\n", test_name);
	printf("Input: \"%s\"\n", input);

	if (argc < 0) {
		printf("Result: parse error (unclosed quote)\n");
		printf("Status: %s\n", expected_argc < 0 ? "PASS" : "FAIL");
		printf("\n");
		return;
	}

	printf("argc = %d\n", argc);
	while (i < argc) {
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}

	printf("Status: %s\n", argc == expected_argc ? "PASS" : "FAIL");
	printf("\n");
}

int main(void)
{
	char test1[] = "run -f \"hello world.txt\" --count 10";
	char test2[] = "copy \"my file.txt\" \"backup folder\"";
	char test3[] = "  build   --target   \"arm cortex\"   ";
	char test4[] = "run \"bad quote";

	printf("====================================\n");
	printf("PARSE_ARGS TEST SUITE\n");
	printf("====================================\n\n");

	test_case("Basic command with quoted string", test1, 5);
	test_case("Multiple quoted strings", test2, 3);
	test_case("Extra spaces handling", test3, 3);
	test_case("Unclosed quote error", test4, -1);

	printf("====================================\n");
	printf("All tests completed!\n");
	printf("====================================\n");

	return 0;
}
