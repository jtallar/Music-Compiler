#ifndef _ENDIANNESS_H_
#define _ENDIANNESS_H_

int isBigEndian();
void reverseEndianness(const long long int size, void* value);
void toBigEndian(const long long int size, void* value);
void toLittleEndian(const long long int size, void* value);

#endif /* _ENDIANNESS_H_ */