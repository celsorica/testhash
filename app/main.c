#include <stdio.h>
#include <stdint.h>

#include "tlv.h"

int main()
{
   myprint("Hash demo application\n");
   size_t objLen = 13;
   uint8_t tlvObject[] = {
      0xE1, 0x0B, 0xC1, 0x03, 0x01, 0x02,
      0x03, 0xC2, 0x00, 0xC3, 0x02, 0xAA,
      0xBB
   };
   parseTlv(tlvObject, &objLen, 1);
   return 0;
}

