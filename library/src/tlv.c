#include <stdint.h>
#include <string.h>

#include "tlv.h"

void myprint(const char* msg)
{
   printf("%s", msg);
   return;
}

void parseTlv(uint8_t* values, size_t* size, uint8_t begin)
{
    if(*size == 0) {
        return;
    }

    char* space = begin ? "" : "    ";

    //le o primeiro byte e ver o bits 7/8
    uint8_t classValue = (*values >> SHIFTBIT_APP_CLASS);
    printf("%sTAG - 0x%02X ( ", space, *values);
    if(classValue > APPLICATION_CLASS_SIZE) {
        printf("%sUNKOWN CLASS", space);
    } else {
        printf("%s - ", APPLICATION_CLASS_ARRAY[classValue]);
    }

    //le se o bit 6 está ligado 1 ou nao 0 e pega o valor do array conforme valor
    uint8_t dataObjectValue = ((*values & MASK_DATA_OBJECT) >> SHITBIT_DATA_OBJECT);
    printf("%s )\n", DATA_OBJECT[dataObjectValue]);

    //verifica se os bits 1 a 5 estão ligados e se estiverem, iremos tratar o proximo byte
    if((*values & MASK_SUBSEQUENCE_BYTES) == MASK_SUBSEQUENCE_BYTES) {
       ++values;
       size_t index = 0;
       uint8_t arraySize[sizeof(uint16_t)];
       memset(arraySize, 10, sizeof(uint16_t));
       while((*values & MASK_BYTE_FOLLOWS) == MASK_BYTE_FOLLOWS) {
          arraySize[index++] = *(values++) & MASK_TAG_NUMBER;
          --(*size);
       }
       if(index > sizeof(uint32_t) -1) {
           printf("Error : valor maior que um int32");
           return;
       }
       arraySize[index++] = *(values) & MASK_TAG_NUMBER;
       --(*size);
       uint32_t newSize = (arraySize[0] << 7) | arraySize[1];
       printf("%sLEN - %d bytes\n", space, newSize);
    } else {
        printf("%sLEN - %d bytes\n", space, *(++values));
        *size-=2;
    }

    if(begin) {
        parseTlv(++values, size, 0);
    } else {
        size_t sizeTemp = *values;
        if(sizeTemp > 0) {
            printf("%sVAL - ", space);

            for(size_t x = 1; x <= sizeTemp; ++x) {
                printf("0x%02X ", *(++values));
                --(*size);
            }
        }

        printf("\n\n");
        parseTlv(++values, size, 0);
    }
}

