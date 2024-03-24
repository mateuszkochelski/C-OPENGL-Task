#include "CompressedData/CompressedData.cpp"

int main() {
    static constexpr Array2D<int> testArray{ {{0,0,0,1,1,2,3},{0,0,4,4,4,2,2},{2,2,2,2,2,1,2}} };
    const std::optional<std::vector<Data<int>>> result{ compressData(testArray) };
    for (const auto& x : result.value())
    {
        std::cout << x.value << ":" << x.count << std::endl;
    }
    std::cin.get();
} 