#ifndef AC_ARENA_ALLOCATOR_H
#define AC_ARENA_ALLOCATOR_H

#include <cassert>
#include <cstdlib>
#include <vector>

using namespace std;

#define DEFAULT_ARENA_SIZE 5000000

namespace arena_alloc {
  
  class arena_allocator {
  protected:
    char* start;
    char* current;
    size_t size;
    size_t space_left;
    
  public:
    arena_allocator() {
      size = DEFAULT_ARENA_SIZE;
      space_left = size;
      start = static_cast<char*>(malloc(size));
      current = start;
    }

    arena_allocator(const size_t size_) : size(size_) {
      space_left = size;
      start = static_cast<char*>(malloc(size));
      current = start;
    }
    
    size_t get_size_left() const { return space_left; }

    ~arena_allocator() {
      free(start);
    }

    void* alloc(size_t s) {
      space_left = space_left - s;
      assert(space_left > 0);
      void* to_alloc = current;
      current += s;
      return to_alloc;
    }

    template<typename T>
    T* allocate() {
      size_t s = sizeof(T);
      space_left = space_left - s;
      assert(space_left > 0);
      void* to_alloc = current;
      current += s;
      return static_cast<T*>(to_alloc);
    }

  };

}

#endif
