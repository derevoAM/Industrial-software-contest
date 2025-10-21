#include <iostream>
#include <vector>

using namespace std;
template<typename T>
std::pair<T, std::vector<T>> minimumPath(std::vector<std::vector<T>>& triangle) {
    int n = triangle.size();
    std::vector<std::vector<std::pair<T, int>>> triangle_temp(n);
    for(int i = 0; i < n; i ++){
        triangle_temp[i].resize(i + 1);
        for(int j = 0; j <= i; j ++) triangle_temp[i][j].first = triangle[i][j];
    }

    for (int i = n - 2; i >= 0; i --)
    {

        for (int j = 0; j <= i; j ++)
        {
            int ind;
            if (triangle_temp[i + 1][j].first <= triangle_temp[i + 1][j + 1].first) ind = j;
            else ind = j + 1;
            triangle_temp[i][j] = std::pair(std::min(triangle_temp[i + 1][j].first, triangle_temp[i + 1][j + 1].first) + triangle[i][j], ind);
        }
    }

    std::vector<T> minPath(n);
    minPath[0] = triangle[0][0];
    int column = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        column = triangle_temp[i][column].second;
        minPath[i + 1] = triangle[i + 1][column];

    }
    return std::pair(triangle_temp[0][0].first, minPath);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j)
        {
            std::cin >> triangle[i][j];
        }
    }

    auto result = minimumPath(triangle);
    std::cout << "Минимальная сумма пути: " << result.first << "\n";
    std::cout << "Путь: ";
    for(int i = 0; i < n; i++) std::cout  << result.second[i] << " ";
}
