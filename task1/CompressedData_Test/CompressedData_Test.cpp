#include "../CompressedData/CompressedData.cpp"
#include "gtest/gtest.h"
TEST(DataCompressionTest, Test1)
{
	static constexpr Array2D<int> testArray{ {{0,0,0,1,1,2,3},{0,0,4,4,4,2,2},{2,2,2,2,2,1,2}} };
	const std::vector<Data<int>> expectedArray{ {
		{0,3},{1,2},{2,1},{3,1},{0,9},
		{0,2},{4,3},{2,2},{0,9},
		{2,5},{1,1},{2,1 },{0,9},
		{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},
		{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},
		{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},{0,16},
		{0,16},{0,16},{0,16},{0,16},{0,16}
	} };
	const std::optional<std::vector<Data<int>>> outputArray{ compressData(testArray) };
	ASSERT_EQ(outputArray, expectedArray);
}

int main()
{
	RUN_ALL_TESTS();
	std::cin.get();
}