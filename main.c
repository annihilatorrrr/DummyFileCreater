#include <Windows.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 4096 // 4 KB
#define DEFAULT_FILENAME "output.bin"
#define DEFAULT_FILESIZE 1000 // 1 KB

int main() {
  printf_s("I'm a dummy file generater!\nEnter the password to use it: \n");
  char passs[] = "64linesofcode", input_password[14];
  scanf_s("%15s", &input_password, 14);
  if (strcmp(input_password, passs) != 0) {
    printf("Error: Wrong password nigga! Get it from @annihilatorrrr\n");
    system("pause");
    return 1;
  }
  system("cls");
  printf_s("I'm a dummy file generater!\n");
  char filename[256], buffer[BLOCK_SIZE] = {0};
  printf_s("Enter the name of the file to create (or press Enter for default "
           "'%s'): \n",
           DEFAULT_FILENAME);
  fflush(stdin);
  scanf_s("%255[^\n]", filename, sizeof(filename));
  if (strcmp(filename, "") == 0) {
    strcpy(filename, DEFAULT_FILENAME);
  }
  printf_s("Processing input ...!\n");
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf_s("Error: could not open output file for operation; Give the name "
             "with extension properly!\n");
    system("pause");
    return 1;
  }
  long long total_size;
  char size_input[256];
  printf_s("Enter output file size in bytes (or press Enter to use default "
           "size of 1000B): \n");
  fflush(stdin);
  fgets(size_input, 256, stdin);
  printf_s("Processing input ...!\n");
  if (size_input[0] == '\n') {
    total_size = DEFAULT_FILESIZE;
  } else {
    int num_scanned = sscanf_s(size_input, "%lld", &total_size);
    if (num_scanned == 0 || total_size < 0) {
      fclose(fp);
      remove(filename);
      printf_s("Error: total size must be a non-negative integer!\n");
      system("pause");
      return 1;
    }
  }
  long long block_count = total_size / BLOCK_SIZE,
            remainder = total_size % BLOCK_SIZE;
  printf_s("Doing ...!\n");
  for (long long i = 0; i < block_count; i++) {
    fwrite(buffer, BLOCK_SIZE, 1, fp);
  }
  if (remainder != 0) {
    fwrite(buffer, remainder, 1, fp);
  }
  fclose(fp);
  printf_s("Done!\n");
  system("pause");
  return 0;
}
