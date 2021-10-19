#ifndef TLV_H
#define TLV_H

#include <stdio.h>

/** Definição de posição do array de Application Class */
#define UNIVERSAL_CLASS         0x00
#define APPLICATION_CLASS       0x01
#define CONTEXT_CLASS           0x02
#define PRIVATE_CLASS           0x04

/** Numero de bits deslocados para pegar o Application Class */
#define SHIFTBIT_APP_CLASS      0x06

/** Mascara usada para verificar os bits 1 a 5 ver se precisamos tratar o byte seguinte */
#define MASK_SUBSEQUENCE_BYTES	0x1F

/** Mascara usada para verificar se o bit 8 está ligado e precisamos pegar o proximo byte */
#define MASK_BYTE_FOLLOWS       0x80

/** Mascara usada para pegar os primeiros 7 bits */
#define MASK_TAG_NUMBER         0X7F

/** Numero e bits deslocados para pegar o Data Object */
#define SHITBIT_DATA_OBJECT     0x05

/** Mascara usada para pegar o Data Object */
#define MASK_DATA_OBJECT        0x20

/** Array com definições para Application Class */
const char* APPLICATION_CLASS_ARRAY[] = {"UNIVERSAL CLASS", "APPLICATION CLASS", "CONTEXT CLASS", "PRIVATE CLASS"};

/** Array com definições para Data Object */
const char* DATA_OBJECT[] = {"PRIMITIVE DATA OBJECT", "CONSTRUCTED DATA OBJECT"};

#define APPLICATION_CLASS_SIZE  4
#define DATA_OBJECT_SIZE        2


/** 
 * Imprime uma mensagem no console
 * @param[in] msg - mensagem a ser impressa
*/
void myprint(const char* msg);

/** 
 * Decodifica e imprime um array de bytes tlv
 * @param[in] values - array de bytes com os dados
 * @param[in] size - tamanho do array
 * @param[in] begin - por se tratar de uma funcao recursiva, indica se é a primeira vez que irá ser executada
*/
void parseTlv(uint8_t* values, size_t* size, uint8_t begin);

#endif //TLV_H

