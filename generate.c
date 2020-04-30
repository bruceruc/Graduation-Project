#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>


#define VALUESIZE 535822336

int main(){
    char a[62];
    a[0] = '0';
    a[1] = '1';
    a[2] = '2';
    a[3] = '3';
    a[4] = '4';
    a[5] = '5';
    a[6] = '6';
    a[7] = '7';
    a[8] = '8';
    a[9] = '9';

    a[10] = 'a';
    a[11] = 'b';
    a[12] = 'c';
    a[13] = 'd';
    a[14] = 'e';
    a[15] = 'f';
    a[16] = 'g';
    a[17] = 'h';
    a[18] = 'i';
    a[19] = 'j';
    a[20] = 'k';
    a[21] = 'l';
    a[22] = 'm';
    a[23] = 'n';
    a[24] = 'o';
    a[25] = 'p';
    a[26] = 'q';
    a[27] = 'r';
    a[28] = 's';
    a[29] = 't';
    a[30] = 'u';
    a[31] = 'v';
    a[32] = 'w';
    a[33] = 'x';
    a[34] = 'y';
    a[35] = 'z';
    a[36] = 'A';
    a[37] = 'B';
    a[38] = 'C';
    a[39] = 'D';
    a[40] = 'E';
    a[41] = 'F';
    a[42] = 'G';
    a[43] = 'H';
    a[44] = 'I';
    a[45] = 'J';
    a[46] = 'K';
    a[47] = 'L';
    a[48] = 'M';
    a[49] = 'N';
    a[50] = 'O';
    a[51] = 'P';
    a[52] = 'Q';
    a[53] = 'R';
    a[54] = 'S';
    a[55] = 'T';
    a[56] = 'U';
    a[57] = 'V';
    a[58] = 'W';
    a[59] = 'X';
    a[60] = 'Y';
    a[61] = 'Z';

    FILE *fp;
    fp = fopen("d.txt","w");

    
    char *value;
    value = (char*)malloc(sizeof(char) * (VALUESIZE+1));
  
  for(int times=0;times<1;times++){  
    memset(value,0,VALUESIZE+1);
    srand((unsigned)time(NULL));
    for(uint64_t i=0;i<VALUESIZE;++i){
        value[i] = a[rand()%62];
    }
    fprintf(fp,"set key%d %s\n",times,value);
  }
    fclose(fp);






    return 0;
}
