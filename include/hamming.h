//
// Created by Alexey Golomedov on 01.05.17.
//

#ifndef LSH_HAMMING_H
#define LSH_HAMMING_H

#include <vector>

namespace yasda {

    using BinaryString = std::vector<uint64_t>;

    bool GetBit(const BinaryString& binaryString, size_t eltIdx);
    void SetBit(BinaryString& binaryString, size_t eltIdx, bool value);
}

#endif //LSH_HAMMING_H
