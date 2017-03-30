//
// Created by janek on 28.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memory{
    class MemoryChunk{

    public:

        //Rule of five://
        //1. konstruktor kopiujący
        MemoryChunk(const MemoryChunk &xxx);
        //2. konstruktor przenoszący
        MemoryChunk(MemoryChunk &&xxx);
        //3. operator przypisania kopiujący
        MemoryChunk &operator=(const MemoryChunk &xxx);
        //4. operator przypisania przenoszący
        MemoryChunk &operator=(MemoryChunk &&xxx);
        //5. Destruktor
        ~MemoryChunk();


        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

    private:
        int8_t *ptr;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
