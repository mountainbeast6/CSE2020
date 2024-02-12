template <typename T>
class Vector50{
  public:
    Vector50(int initSize=0)
      : size(initSize),
        capacity(50+SPARE_CAPACITY)
      {data = new T[capacity];}
    Vector50(const Vector50& rhs)
      : size(rhs.size),
        capacity(rhs.capacity),
        data(nullptr)
      {
        data = new T[capacity];
        for(int i=0; i<capacity; i++){
          data[i]=rhs.data[i];
        }
      }
    Vector50& operator=(Vector50&& rhs)
      {
        std::swap(size, rhs.size);
        std::swap(capacity, rhs.capacity);
        std::swap(data, rhs.data);
        return this*;
      }

  private:

    int size;
    int capacity;
    T* data;
}
