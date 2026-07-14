#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
int main() {
std::vector<int> result = {1, 2, 3, 4, 5};

// 遍历 vector 的标准写法
for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";  // 输出：1 2 3 4 5  

}
std::cout << std::endl;
std::cout << "total number of elements in result is:" << result.size() << std::endl;
}
