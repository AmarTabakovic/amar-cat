#include <stdio.h>

/**
 * @brief Reads and prints the content of an existing file with a given file name.
 * 
 * @param file_name file name
 */
void read_contents(char *file_name)
{
	FILE *file_pointer;
	char character;

	file_pointer = fopen(file_name, "r");

	while((character = fgetc(file_pointer)) != EOF)
	{
		printf("%c", character);
	}

	printf("\n");

	fclose(file_pointer);
}

/**
 * @brief Checks whether a file with a given file name exists.
 * 
 * @param file_name file name
 * @return int 0 if the file exists, -1 if the file doesn't exist
 */
int check_file_exists(char* file_name)
{
	FILE *file_pointer;
	
	if((file_pointer = fopen(file_name, "r")) == NULL)
	{
		return -1;
	}

	fclose(file_pointer);

	return 0;
}

/**
 * @brief Entry point of the application.
 * 
 * @param argc number of command line arguments
 * @param argv command line arguments 
 * @return int exit code
 */
int main(int argc, char **argv) 
{
	if(2 > argc)
	{
		fprintf(stderr, "amar-cat: Please enter at least 1 filename\n");	
	}

	int file_ok = 0;
	
	for(int i = 1; i < argc; i++)
	{
		if(check_file_exists(argv[i]) != 0)
		{
			file_ok = -1;
			fprintf(stderr, "amar-cat: No such file: %s\n", argv[i]);
		}
	}
	
	if(file_ok == 0) 
	{
		for(int i = 1; i < argc; i++)
		{
			read_contents(argv[i]);
		}
	}
	
	return 0;
}
