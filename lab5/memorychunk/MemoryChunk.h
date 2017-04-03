//
// Created by matematyk60 on 28.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


namespace memory{

    class MemoryChunk{

    public:
        MemoryChunk(std::size_t sz);
        ~MemoryChunk();
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    private:
            int8_t *ptr_;

    };
}


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
