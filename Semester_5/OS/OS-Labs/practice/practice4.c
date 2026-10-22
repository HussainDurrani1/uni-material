#include <stdio.h>

int main(){

	FILE *fptr = fopen("records.txt", "w");
	if (fptr == NULL){
		printf("Error opening the file for writing.");
		return 1;
	}

	printf("Writing the file.\n");
	// fwrite() for binary data (very fast)
	// fprintf() for formatted strings (comparatively slow but human-readable)
	fprintf(fptr, "HussainDurrani - 0937\n");
	fprintf(fptr, "AliHamza - 1037\n");

	fclose(fptr);

	fptr = fopen("records.txt", "r");
	if (fptr == NULL){
		printf("Error opening the file for reading.");
		return 1;
	}

	printf("Reading from the file.\n");
	
	// fgets() {  reads a full line of text (including spaces and punctuation) up to the buffer size limit or until it encounters a newline character (\n) }
	// char buffer[100];
	// while(fgets(buffer, sizeof(buffer), fptr) != NULL){
	// 	printf("Line read: %s", buffer);
	// }
	// fscanf() { reads input separated by whitespace (spaces, tabs, or newlines) }
	// while (fscanf(fp, " %49[^- ] - %d", name, &roll_no) == 2) {
		//	printf("Name: [%s] | Roll No: %d\n", name, roll_no);
	// }
    
	char name[35];
	int roll;
	// %49s: Max 34 chars, stop on ' - ', and then reads int roll
	while (fscanf(fptr, "%34s - %d", name, &roll) == 2) {
		printf("Name: [%s] | Roll No: %d\n", name, roll);
	}
	fclose(fptr);

	printf("Appending to the file.\n");
	fptr = fopen("records.txt", "a+");
	if (fptr == NULL){
		printf("Error opening the file for appending and reading.");
		return 1;
	}

	fprintf(fptr, "TalhaKhurram - 0938\n");
	rewind(fptr);
	printf("Reading from the file after appending.\n");

	while (fscanf(fptr, "%34s - %d", name, &roll) == 2) {
		printf("Name: [%s] | Roll No: %d\n", name, roll);
	}
	fclose(fptr);	


	return 0;
}
