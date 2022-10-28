/*
    Created by Wartk
    Date: 22/10/2022 | 16:08 (-3:00)
*/

#ifndef SUPPORTBITS_H
#define SUPPORTBITS_H

#include <stdio.h>
#include <stdint.h>


typedef struct {
    uint64_t binary_number;
    uint8_t bits_info;
    bool actived = false;
}Bits_Manager;


class SupportBits{
    private:
        Bits_Manager bm[100];

    public:
        bool addBinary(uint64_t bits, uint8_t bits_count, int pos);
        bool printBinary(int pos);

};


bool SupportBits::addBinary(uint64_t bits, uint8_t bits_count, int pos){

    if(bits_count == 8 || bits_count == 16 || bits_count == 32 || bits_count == 64){
        bm[pos].binary_number = bits;
        bm[pos].bits_info = bits_count;
        bm[pos].actived = true;

        return true;
    }

    return false;
}

bool SupportBits::printBinary(int pos){

    if(bm[pos].actived == true){

        int count_bit = 0;

        if(bm[pos].bits_info == 8){
            count_bit = 0x80;
        } else if(bm[pos].bits_info == 16){
            count_bit = 0x800;
        } else if(bm[pos].bits_info == 32){
            count_bit = 0x8000;
        } else if(bm[pos].bits_info == 64){
            count_bit = 0x80000;
        }

        while(count_bit > 0){
           printf("%c", bm[pos].binary_number & count_bit ? '1' : '0');
           count_bit = count_bit / 2;
        }

        return 0;
    }

    return 1;
}




#endif // SUPPORTBITS_H
