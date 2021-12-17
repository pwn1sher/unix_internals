// Author - 0xpwnisher
// Dynamic loading and un-loading of shared libraries using libdl
// gcc main.c -ldl

#include <stdio.h>
#include <dlfcn.h>

#define LAZY_LOADING RTLD_LAZY 

// Windows equavelent of GetModuleHandle() - dlopen() - load object 
// Windows equavelent of GetProcAddress()  - dlsym() - finds symbols 



int main(){

  unsigned int (*zz_sleep)(unsigned int seconds);

  char function[] = {'s', 'l','e','e','p', 0};

    void* handle = dlopen("libc.so.6", LAZY_LOADING);
    
    if ( handle == NULL ) {
            printf("failed to open libc\n");
            exit(1);
        }

        void* funcAddr = dlsym(handle, function);
        printf( "Address of function %s is %p\n",function, (long)funcAddr);

        // get function pointer
        *(void **)(&zz_sleep) = dlsym(handle, function);
        
        zz_sleep(3);
        
        printf("Executed after Sleep\n");
      // close handle
        dlclose(handle);

return 0;

}
