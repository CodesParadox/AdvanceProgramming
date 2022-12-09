#include "codec.h"

typedef struct paramsToJob{
	int key;
	char* arr;
	void (*func)(char* s, int key);

}paramsToJob;

void encryptDecryptWrapper(void* args) {
    paramsToJob *params = (paramsToJob *) args;
    params->func(params->arr, params->key);
}

//    int main(int argc, char *argv[]) {
//        int numThreads = 5;
//        char s[100];
//        int key;
//        threadPool thPool;
//
//        if (initThreadPool(&thPool, numThreads) != 0) {
//            printf("Error creating thread pool");
//            return -1;
//        }
//
//        while (1) {
//            printf("Enter a string: ");
//            scanf("%s", s);
//            printf("Enter a key: ");
//            scanf("%d", &key);
//
//            paramsToJob *params = (paramsToJob *) malloc(sizeof(paramsToJob));
//            params->arr = s;
//            params->key = key;
//            params->func = encrypt;
//
//            if (addJob(encryptDecryptWrapper, params, &thPool) != 0) {
//                printf("Error adding job to thread pool");
//                return -1;
//            }
//        }
//
//        return 0;
//    }
//


//{
//	struct paramsToJob prms = *((struct paramsToJob* ) args);
//	prms.func(arr,prms.key);
//
//}


