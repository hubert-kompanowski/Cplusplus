//
// Created by hubert on 25.03.18.
//

#include "MemoryChunk.h"

using namespace memorychunk;

memorychunk::MemoryChunk::MemoryChunk(size_t sz) {
    rozmiar = sz;
    wskaznik = new int8_t[rozmiar];
}

size_t memorychunk::MemoryChunk::ChunkSize() const {
    return rozmiar;
}

int8_t* memorychunk::MemoryChunk::MemoryAt(size_t offset) const {
    if(wskaznik == nullptr){
        return nullptr;
    }
    if(offset >= this->rozmiar){
        return nullptr;
    }
    if(offset < 0){
        return nullptr;
    }
    return &wskaznik[offset];
}

// rule of five:
// konstruktor kopiujący
memorychunk::MemoryChunk::MemoryChunk(const MemoryChunk &mem_chunk) {
    CopyMemory(mem_chunk);
}

void MemoryChunk::CopyMemory(const MemoryChunk &mem_chunk) {
    rozmiar = mem_chunk.rozmiar;
    wskaznik = new int8_t[rozmiar];
    std::copy(mem_chunk.wskaznik, mem_chunk.wskaznik + mem_chunk.rozmiar, wskaznik);
}

//konstruktor przenoszący
memorychunk::MemoryChunk::MemoryChunk(MemoryChunk &&mem_chunk) : wskaznik(mem_chunk.wskaznik) {
    rozmiar = mem_chunk.ChunkSize();
    mem_chunk.rozmiar = 0;
    mem_chunk.wskaznik = nullptr;
}
//operator przypisania kopiujący
MemoryChunk& memorychunk::MemoryChunk::operator=(const MemoryChunk &mem_chunk) {
    if(this == &mem_chunk){
        return *this;
    }
    delete[] wskaznik;
    CopyMemory(mem_chunk);
    return *this;
}
//operator przypisania przenoszący
MemoryChunk& memorychunk::MemoryChunk::operator=(MemoryChunk &&mem_chunk) {
    if(this == &mem_chunk){
        return *this;
    }
    delete[] wskaznik;
    wskaznik = mem_chunk.wskaznik;
    rozmiar = mem_chunk.ChunkSize();
    mem_chunk.rozmiar = 0;
    mem_chunk.wskaznik = nullptr;
}
//destruktor
memorychunk::MemoryChunk::~MemoryChunk() {
    rozmiar = 0;
    delete[] wskaznik;
}