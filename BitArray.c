#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned int *bits;
    int size; 
} BitArray;

BitArray* createBitArray(int size) 
{
    BitArray* bitArray = (BitArray*)malloc(sizeof(BitArray));
    bitArray->size = size;
    int numIntegers = size / (sizeof(unsigned int) * 8) + 1;
    bitArray->bits = (unsigned int*)calloc(numIntegers, sizeof(unsigned int));
    return bitArray;
}

void setBit(BitArray* bitArray, int index) 
{
    if (index >= bitArray->size) 
    {
        printf("Error: Index out of range.\n");
        return;
    }
    int intIndex = index / (sizeof(unsigned int) * 8);
    int bitIndex = index % (sizeof(unsigned int) * 8);
    bitArray->bits[intIndex] |= (1 << bitIndex);
}

void clearBit(BitArray* bitArray, int index) 
{
    if (index >= bitArray->size) 
    {
        printf("Error: Index out of range.\n");
        return;
    }
    int intIndex = index / (sizeof(unsigned int) * 8);
    int bitIndex = index % (sizeof(unsigned int) * 8);
    bitArray->bits[intIndex] &= ~(1 << bitIndex);
}

int isBitSet(BitArray* bitArray, int index) 
{
    if (index >= bitArray->size) 
    {
        printf("Error: Index out of range.\n");
        return -1;
    }
    int intIndex = index / (sizeof(unsigned int) * 8);
    int bitIndex = index % (sizeof(unsigned int) * 8);
    return (bitArray->bits[intIndex] >> bitIndex) & 1;
}

void freeBitArray(BitArray* bitArray) 
{
    free(bitArray->bits);
    free(bitArray);
}

int main() 
{
    int size = 20;
    BitArray* bitArray = createBitArray(size);

    setBit(bitArray, 2);
    setBit(bitArray, 5);
    setBit(bitArray, 10);

    printf("Bit at index 2 is set? %d\n", isBitSet(bitArray, 2)); 
    printf("Bit at index 3 is set? %d\n", isBitSet(bitArray, 3)); 

    clearBit(bitArray, 5);

    printf("Bit at index 5 is set? %d\n", isBitSet(bitArray, 5)); 

    freeBitArray(bitArray);

    return 0;
}
