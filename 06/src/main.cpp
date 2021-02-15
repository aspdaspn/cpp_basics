#include <main.h>
#include <cstring>

void writeFile(const char* path, const char* content, int length) {
	FILE* fp = fopen(path, "w");
	fwrite(content, length, 1, fp);
	fclose(fp);
}

char* readFile(const char* path, long &fsize) {
	FILE* fp = fopen(path, "r");
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* buffer = (char*) malloc(fsize);
	fread(buffer, fsize, 1, fp);
	fclose(fp);
	return buffer;
}

int main(int argc, char** args) {
	const char* message1 = "Test message file 1\n";
	const char* message2 = "This is another test message, written into file 2\n";
	writeFile("../data/file_1.dat", message1, strlen(message1) + 1);
	writeFile("../data/file_2.dat", message2, strlen(message2) + 1);
	long len1, len2, len3;
	char* file1 = readFile("../data/file_1.dat", len1);
	char* file2 = readFile("../data/file_2.dat", len2);
	//printf("%s", file1);
	FILE* fp = fopen("../data/file_3.dat", "w");
	fwrite(file1, len1, 1, fp);
	fwrite(file2, len2, 1, fp);
	fclose(fp);
	free(file1);
	free(file2);

	if (args[1]) {
		fp = fopen("../data/file_3.dat", "r");
		char search[255] = {0};
		bool found = false;
		while (fscanf (fp, "%s", search) && !feof(fp)) {	
			if (strcasecmp(search, args[1]) == 0) {
				found = true;
				break;
			}
		}
		if (found)
			printf("String %s is present\n", args[1]);
		else
			printf("String %s is not present\n", args[1]);
		fclose(fp);
	} else
		printf("Files written, check ../data/ directory\n");

	return SUCCESS;
}
