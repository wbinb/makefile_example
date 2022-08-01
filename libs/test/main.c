#include "math_add.h"
#include "stdio.h"

#ifdef LINK_SO
#include "stdlib.h"
#include "dlfcn.h"
#define LIB_CACULATE_PATH "../shared/libtestmath.so"
typedef int (*lmath_func)(int, int);
#endif

int main(int argv, char *argc[])
{
    int a = 0, b = 1, c = 2;
    #ifdef LINK_SO
    void *handle;
    lmath_func sub_func = NULL;
    handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
    if( !handle )
    {
        printf("%s\n", dlerror());
        return -1;
    }
    sub_func = (lmath_func)dlsym(handle, "lmath_sub");
    if( sub_func != NULL )
        printf("sub:%d-%d=%d\n",1,2,sub_func(1,2));
    dlclose(handle);
    #else
    a = lmath_sub(b, c);
    printf("sub:%d-%d=%d\n",b,c,a);
    a = lmath_add(b, c);
    printf("add:%d+%d=%d\n",b,c,a);
    #endif

    return 0;
}