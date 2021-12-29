#ifndef _PBLPMM_H_
#define _PBLPMM_H_

void createPPM(const char* path, const int width, const int height, const unsigned char* data)
{
	FILE* f;

	const char lineBreak = 0x0a;
	const char space = ' ';
	const char signature[2] = {'P','6'};
	const char colorDepth[] = "255";
	const int colorDepth_l = 3;
	char width_str[16];
	char height_str[16];
	sprintf(width_str, "%d", width);
	sprintf(height_str, "%d", height);

	uint64_t data_length = (uint64_t)width*(uint64_t)height*(uint64_t)3;

	f = fopen(path, "wb");

	fwrite(signature, sizeof(char), 2, f);
	fwrite(&lineBreak, sizeof(char), 1, f);
	
	int length = strlen(width_str);

	fwrite(width_str, length, 1, f);

	fwrite(&space, sizeof(char), 1, f);

	length = strlen(height_str);

	fwrite(height_str, length, 1, f);

	fwrite(&lineBreak, sizeof(char), 1, f);

	fwrite(&colorDepth, colorDepth_l, 1, f);

	fwrite(&lineBreak, sizeof(char), 1, f);

	uint64_t counter = 0;

	for (uint64_t i = 0; i < data_length; i++)
	{
		uint8_t byte = data[i];

		fwrite(&byte, sizeof(unsigned char), 1, f);

		counter++;
	}

	fclose(f);
}

#endif

