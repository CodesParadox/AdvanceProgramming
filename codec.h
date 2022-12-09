#ifndef __CODEC__
#include "thpool.h"
#define __CODEC__

void encrypt(char *s,int key);

void decrypt(char *s,int key);


#endif

//#include "codec.h"
//#include "encryptDecryptUtils.h"
//#include "thpool.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <pthread.h>
//#include <unistd.h>
//
//
//void encrypt(char *s,int key)
//{
//	int i;
//	for(i=0;i<strlen(s);i++)
//	{
//		s[i] = s[i] + key;
//	}
//}
//
//void decrypt(char *s,int key)
//{
//	int i;
//	for(i=0;i<strlen(s);i++)
//	{
//		s[i] = s[i] - key;
//	}
//}
//
// int initThreadPool(threadPool* thPool, int numThreads)
// {
//     int i;
//     thPool->jobMutex = (pthread_t*) malloc(numThreads * sizeof(pthread_t));
//     if (thPool->jobsTail == NULL)
//     {
//         return -1;
//     }
//
//     thPool->jobMutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
//     pthread_mutex_init(thPool->jobMutex, NULL);
//
//     thPool->mutexCond = (pthread_cond_t*) malloc(sizeof(pthread_cond_t));
//     pthread_cond_init(thPool->mutexCond, NULL);
//
//     thPool->jobsHead = NULL;
//     thPool->jobsTail = NULL;
//
//     for (i = 0; i < numThreads; i++)
//     {
//         if (pthread_create(&(thPool->aliveMutex[i]), NULL, runThreadWrapper, thPool) != 0)
//         {
//             return -1;
//         }
//     }
//
//     return 0;
// }
//
// void destroyThreadPool(threadPool* thPool)
// {
//     free(thPool->aliveMutex);
//     free(thPool->jobMutex);
//     free(thPool->mutexCond);
// }
//
//

//int main(int argc, char *argv[])
//{
//	int numThreads = 5;
//	char s[100];
//	int key;
//	threadPool thPool;
//
//	if (initThreadPool(&thPool, numThreads) != 0) {
//		printf("Error creating thread pool");
//		return -1;
//	}
//
//	while (1) {
//		printf("Enter a string: ");
//		scanf("%s", s);
//		printf("Enter a key: ");
//		scanf("%d", &key);
//
//		paramsToJob *params = (paramsToJob *) malloc(sizeof(paramsToJob));
//		params->arr = s;
//		params->key = key;
//		params->func = encrypt;
//
//		if (addJob(encryptDecryptWrapper, params, &thPool) != 0) {
//			printf("Error adding job to thread pool");
//			return -1;
//		}
//	}
//
//	return 0;
//}








