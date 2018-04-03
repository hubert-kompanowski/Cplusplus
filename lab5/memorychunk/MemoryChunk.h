//
// Created by hubert on 25.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>
#include <cstring>


namespace memorychunk {

    class MemoryChunk {

    public:
        MemoryChunk();
        MemoryChunk(const MemoryChunk &mem_chunk);             //1. konstruktor kopiujący
        MemoryChunk(MemoryChunk &&mem_chunk);                  //2. konstruktor przenoszący
        MemoryChunk &operator=(const MemoryChunk &mem_chunk);  //3. operator przypisania kopiujący
        MemoryChunk &operator=(MemoryChunk &&mem_chunk);       //4. operator przypisania przenoszący
        ~MemoryChunk();                                        //5. destruktor

        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

    private:
        size_t rozmiar;
        int8_t* wskaznik;

        void CopyMemory(const MemoryChunk &mem_chunk);
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
