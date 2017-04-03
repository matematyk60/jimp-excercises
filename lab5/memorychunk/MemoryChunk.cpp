//
// Created by matematyk60 on 28.03.17.
//
#include <iostream>
#include "MemoryChunk.h"
#include <cstdint>
#include <algorithm>

namespace memory{
    MemoryChunk::MemoryChunk(std::size_t sz) {
        ptr_ = new   int8_t[sz];
    }

    MemoryChunk::~MemoryChunk() {
        delete[] ptr_;
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return nullptr;
    }

    size_t MemoryChunk::ChunkSize() const {
        return 0;
    }
}