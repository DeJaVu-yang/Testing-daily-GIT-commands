#include <iostream>
#include <algorithm>

void calMulMax(int A[], int res[], int n) {
    if (n <= 0) return;
    
    int currentMax = A[n-1];
    int currentMin = A[n-1];
    res[n-1] = A[n-1] * A[n-1];
    
    for (int i = n-2; i >= 0; i--) {
        // 先更新区间 [i, n-1] 的最大/最小值（只比较元素本身）
        currentMax = std::max(A[i], currentMax);
        currentMin = std::min(A[i], currentMin);
        
        // 再计算结果
        if (A[i] > 0) {
            res[i] = A[i] * currentMax;
        } else if (A[i] < 0) {
            res[i] = A[i] * currentMin;
        } else {
            res[i] = 0;
        }
    }
}
// 添加 main 函数用于测试
int main() {
    // 测试用例
    int A[] = {1, 4, -9, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int res[100] = {0};
    
    calMulMax(A, res, n);
    
    std::cout << "数组: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "结果: ";
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}