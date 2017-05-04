//
// Created by Alexey Golomedov on 01.05.17.
//

#include "hamming.h"
#include <cassert>

#include <iostream>

namespace yasda {

    static const size_t groupSize = 64;

    bool GetBit(const yasda::BinaryString& binaryString, size_t eltIdx) {
        size_t groups = binaryString.size();

        size_t group = eltIdx / groupSize;
        size_t elt = eltIdx % groupSize;

        if (group >= groups) {
            return false;
        }

        return (binaryString[group] & (1 << elt)) > 0;
    }
    void SetBit(yasda::BinaryString& binaryString, size_t eltIdx, bool value) {
        size_t groups = binaryString.size();

        size_t group = eltIdx / groupSize;
        size_t elt = eltIdx % groupSize;

        assert(group < groups);
        assert(elt < groupSize);

        if (value) {
            binaryString[group] = (binaryString[group] | (1 << elt)) ;
        } else {
            binaryString[group] = (binaryString[group] & (~(1 << elt))) ;
        }

    }

    size_t GetHammingDistance(const BinaryString& left, const BinaryString& right) {
        assert(left.size() == right.size());

        size_t distance = 0;
        for (size_t groupIdx=0; groupIdx < left.size(); ++groupIdx) {
            size_t missedFeatures = (left[groupIdx] ^ right[groupIdx]);

            while (missedFeatures != 0) {
                distance += (missedFeatures & 1);
                missedFeatures = (missedFeatures >> 1);
            }
        }

        return distance;
    }

    bool BinaryStringsAreSame(const BinaryString& left, const BinaryString& right) {
        if (left.size() != right.size()) {
            return false;
        }

        for (size_t bitGroupId=0; bitGroupId < left.size(); ++bitGroupId) {
            if (left[bitGroupId] != right[bitGroupId]) {
                return false;
            }
        }

        return true;
    }
}
