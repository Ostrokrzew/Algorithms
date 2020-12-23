#include "rng.h"

uint8_t random_number_generator(const std::string& output_file) {
    //seed the generator with current time
    time_t t = time(nullptr);
    srand48(t);

    //open the file for write and clear its content
    std::ofstream output;
    output.open(output_file, std::ofstream::trunc);
    if (!output.is_open())
        return ERR_OPEN_FILE;

    //draw the numbers and write them to the file
    for (size_t i = 0; i < AMOUNT; i++) {
        output << mrand48() << std::endl;
    }

    //close the file
    output.close();
    if (output.is_open())
        return ERR_CLOSE_FILE;

    return SUCCESS;
}

uint8_t draw_number(const char *input_file, int32_t &number) {
	int32_t *table = read_to_table(input_file);
	number = table[lrand48() % AMOUNT];
	free(table);

	if (number == NULL)
		return DRAW_NMBR_FAIL;

	return SUCCESS;
}
