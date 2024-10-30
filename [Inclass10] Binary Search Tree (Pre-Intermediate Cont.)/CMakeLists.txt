add_executable(test_Bai01_JustABinaryTree
    tests/test_Bai01_JustABinaryTree.cpp
)

target_link_libraries(test_Bai01_JustABinaryTree
    gtest
    gtest_main
)

add_test(NAME test_Bai01_JustABinaryTree COMMAND test_Bai01_JustABinaryTree)