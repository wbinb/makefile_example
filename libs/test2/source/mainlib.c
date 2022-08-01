#include "math_add.h"
#include "stdio.h"

#ifdef LINK_SO
#include "stdlib.h"
#include "dlfcn.h"
#define LIB_CACULATE_PATH "../../shared/libtestmath.so"
typedef int (*lmath_func)(int, int);
#endif

int main_sub(int a, int b)
{
    int ret = 0;
    printf("%s\n",__func__);
    #ifdef LINK_SO
    void *handle;
    lmath_func sub_func = NULL;
    printf("main_sub shared to test_sub\n");
    handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
    if( !handle )
    {
        printf("%s\n", dlerror());
        return -1;
    }
    sub_func = (lmath_func)dlsym(handle, "lmath_sub");
    if( sub_func != NULL )
       ret = sub_func(a,b);
    dlclose(handle);
    #else
    printf("main_sub static to test_sub\n");
    ret = lmath_sub(a, b);
    #endif
    return ret ;
}