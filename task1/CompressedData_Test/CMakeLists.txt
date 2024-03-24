cmake_minimum_required(VERSION 3.14)

project(CompressedData_Test VERSION 1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable (CompressedData_Test "CompressedData_Test.cpp" )
target_link_libraries(${PROJECT_NAME}
	gtest_main
)
