#include <stdio.h>
#include <stdlib.h>
#include <libpmem.h>
#include <string.h>
#include <stdint.h>

int main(){
    char myfile[] = "/dev/dax1.1";
    char numberfile[] = "number";
    char *pmemaddr;
    size_t mapped_len;
    int is_pmem;

    uint64_t flen;
    FILE *fp1;
    char buffer[50];
    fp1 = fopen(numberfile,"r");
    fscanf(fp1,"%lu",&flen);
    fclose(fp1);

    if ((pmemaddr = pmem_map_file(myfile,
                        0,
                        PMEM_FILE_CREATE,
                        0666, &mapped_len, &is_pmem)) == NULL) {
                printf("pmem_map_file");
                exit(1);

    }

    // size_t flen = strlen(pmemaddr);
    FILE *fp;
    fp = fopen( "appendonly.aof" , "a+" );
    fwrite(pmemaddr, flen , 1, fp );
    fclose(fp);
    memset(pmemaddr, 0, flen);
    pmem_persist(pmemaddr, flen) ;
    pmem_unmap(pmemaddr, mapped_len);
    return 0;
}