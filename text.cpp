#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// 二叉搜索树结点结构
typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode;

typedef BSTNode* BSTree;

// 创建新结点
BSTNode* createNode(int data) {
    BSTNode* node = new BSTNode;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// 插入结点到二叉搜索树
void insert(BSTree& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// 查找与K差绝对值最小的结点
void findMinDiffNodes(BSTree root, int K, int& minDiff, std::vector<int>& result) {
    if (root == nullptr) return;//递归基：空树
    
    // 计算当前结点与K的差值
    int currentDiff = abs(root->data - K);//
    
    // 如果当前差值更小，更新最小差值并重置结果列表
    if (currentDiff < minDiff) {
        minDiff = currentDiff;
        result.clear();
        result.push_back(root->data);
    }
    // 如果差值相等，添加到结果列表
    else if (currentDiff == minDiff) {
        result.push_back(root->data);
    }
    
    // 根据BST性质选择遍历方向
    if (K < root->data) {
        findMinDiffNodes(root->left, K, minDiff, result);
    } else {
        findMinDiffNodes(root->right, K, minDiff, result);
    }
}

// 中序遍历输出（验证BST正确性）
void inOrder(BSTree root) {
    if (root == nullptr) return;
    inOrder(root->left);//递归遍历左子树
    std::cout << root->data << " ";


    inOrder(root->right);
}

int main() {
    // 构建二叉搜索树
    BSTree root = nullptr;
    int values[] = {5, 3, 8, 2, 4, 7, 9, 5};  // 包含重复值5
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        insert(root, values[i]);
    }
    
    std::cout << "二叉搜索树中序遍历：";
    inOrder(root);
    std::cout << std::endl;
    
    // 测试查找
    int K;
    std::cout << "请输入整数K：";
    std::cin >> K;
    
    int minDiff = INT_MAX;
    std::vector<int> result;
    
    findMinDiffNodes(root, K, minDiff, result);
    
    // 输出结果
    std::cout << "最小绝对值差为：" << minDiff << std::endl;
    std::cout << "与K之差绝对值最小的结点关键字：";
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;
    
    return 0;
}