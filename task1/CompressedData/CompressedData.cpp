#include <array>
#include <cstdint>
#include <optional>
#include <vector>
#include <iostream>

template<typename T>
struct Data {
    T value;
    uint8_t count;

    friend bool operator ==(const Data& l, const Data& r)
    {
        return std::tie(l.value, l.count) == std::tie(r.value, r.count);
    }
};

constexpr size_t sizeX{ 16 };
constexpr size_t sizeY{ 32 };

template<typename T>
using Array2D = std::array<std::array<T, sizeX>, sizeY>;

template<typename T>
using CompressedData = std::optional<std::vector<Data<T>>>;

template<typename T>
CompressedData<T> compressData(const Array2D<T>& input) {
    std::vector<Data<T>> compressedData;
    for (size_t i{}; i < input.size(); ++i)
    {
        uint8_t count{1};
        for (size_t j{ 1 }; j < input[i].size(); ++j)
        {
            if (input[i][j] == input[i][j - 1])
                count += 1;                    
            else
            {
                compressedData.push_back( Data{input[i][j - 1], count} );
                count = 1;
            }
        }
        compressedData.push_back(Data{ input[i][input[i].size()-1], count});
    }
    size_t totalCompressedSize = compressedData.size() * sizeof(Data<T>);
    size_t totalInputSize = sizeof(int) * input.size() * input[0].size();

    if (totalCompressedSize > totalInputSize)
        return std::nullopt;
    else
        return compressedData;
}