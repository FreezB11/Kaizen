
template<typename T>
class vector{
private:
    T *data;
    ll size;
    ll max =0;
    ll min = MadMax;
public:
    vector(ll n){
        size = n;
        data = (T*)malloc(n*sizeof(T));
        if (!data) {throw std::bad_alloc();}
        for (size_t i = 0; i < n; i++){new(&data[i]) T();}
    }
    T& operator[](std::size_t index) {
        if (index >= size) {throw std::out_of_range("Index out of range");}
        return data[index];
    }
};