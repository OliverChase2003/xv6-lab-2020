#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user.h"

int main()
{
    struct sysinfo sinfo;
    sysinfo(&sinfo);
    printf("freemem: %d\nproc: %d", sinfo.freemem/1024, sinfo.nproc);
    exit(0);
}