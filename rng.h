#ifndef ENGINEERPROJECT_RNG_H
#define ENGINEERPROJECT_RNG_H

#include "headers.h"

static u8 random_number_generator(const std::string &output_file) {
	//seed the generator with current time
	time_t t = time(nullptr);
	srand48(t);

	//open the file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	//draw the numbers and write them to the file
	for (size_t i = 0; i < AMOUNT; i++)
		output << mrand48() << std::endl;

	//close the file
	output.close();
	if (output.is_open())
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static u8 draw_number(const char *input_file, i32 &number) {
	//open the file with generated data to sort for read
	FILE *input = fopen(input_file, "r");
	if (!input)
		return ERR_OPEN_FILE;
	char *line = nullptr;
	size_t len = 0;
	for (size_t i = 0; i < (lrand48() % AMOUNT); ++i) {
		if (getline(&line, &len, input) == -1) {
			free(line);
			return ERR_READ_DATA;
		}
	}
	number = atol(line);
	free(line);

	if (fclose(input))
		return ERR_CLOSE_FILE;

	if (!number)
		return DRAW_NMBR_FAIL;

	return SUCCESS;
}

#endif //ENGINEERPROJECT_RNG_H
