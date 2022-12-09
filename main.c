#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include "thpool.h"
#include "encryptDecryptUtils.h"
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // read the file
    FILE *f = fopen("encryptFile.txt", "w");
    if (f == NULL) {
        printf("Failed to open the file!");
        exit(0);
    }
    printf("File is opened successfully!\n");

    int i;
    /**
     * Read the flag from the command line and check if it is valid or not
     *  coder key -e < my_original_file > encripted_file
   argv[0] = coder key
   argv[1] = -e, -d
   argv[2] = my_original_file
   argv[3] = encripted_file
     */
    if (argc != 4) {
        printf("Invalid number of arguments!");
        exit(0);
    }
    if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0) {
        printf("Invalid flag!");
        exit(0);
    }
    for (i = 0; i < strlen(argv[2]); i++) {
        if (!isdigit(argv[2][i])) {
            printf("Invalid key!");
            exit(0);
        }
    }
    int key = atoi(argv[2]);
    if (key < 0 || key > 25) {
        printf("Invalid key!");
        exit(0);
    }
    // read the file
    FILE *f1 = fopen(argv[3], "r");
    if (f1 == NULL) {
        printf("Failed to open the file!");
        exit(0);
    }

    printf("File is opened successfully!\n");
    char c;
    char s[100];
    int j = 0;
    while ((c = fgetc(f1)) != EOF) {
        s[j] = c;
        j++;
    }
    s[j] = '\0';
    printf("The string is: %s\n", s);
    fclose(f1);

    /**
  * 1. Create a thread pool with 4 threads in it.
  * 2. Create a job and add it to the thread pool.
  * 3. Wait for all the jobs to finish.
  * 4. Destroy the thread pool.
  * 5. Exit.
  *  Note: You can add more jobs to the thread pool after step 2.
  *  Note: You can add more threads to the thread pool after step 1.
  *     The thread pool will automatically create the new threads.
  *     You can also remove threads from the thread pool.
  *     The thread pool will automatically destroy the threads.
  */
    // create the thread pool
    threadPool *thPool;
    thPool = thPoolInit(4);
    // create the job and add it to the thread pool
    if (strcmp(argv[1], "-e") == 0) {
        for (i = 0; i < j; i++) {
            job *j;
            j = getJob(encrypt, (void *) &s[i]);
            addJob(thPool, j);
        }
    } else { if (strcmp(argv[1], "-d") == 0) {
            for (i = 0; i < j; i++) {
                job *j;
                j = getJob(decrypt, (void *) &s[i]);
                addJob(thPool, j);
            }
        }
    }

    paramsToJob *params = (paramsToJob *) malloc(sizeof(paramsToJob));
    params->arr = s;
    params->key = key;

    if (strcmp(argv[1], "-e") == 0) {
        params->func = encrypt;
    } else {
        params->func = decrypt;
    }

    addJob(thPool, getJob(encryptDecryptWrapper, (void *) params));
    while (numTasksAlive(thPool) > 0) {
        printf("Waiting for all jobs to finish...\n");
        sleep(1);
    }



    if (addJob(encryptDecryptWrapper, params, &thPool) != 0) {
        printf("Error adding job to thread pool");
        return -1;
    }
    // destroy the thread pool
    poolRelease(thPool);
    // write the file
    fprintf(f, "%s", s);
    fclose(f);
    return 0;

//	printf("length of args %s \n",argv[1]);
//	char data[] = "m";
//	int key = 12;
//
//	encrypt(data,key);
//	printf("encripted data: %s\n",data);
//
//	decrypt(data,key);
//	printf("decripted data: %s\n",data);
//
//	return 0;
}
