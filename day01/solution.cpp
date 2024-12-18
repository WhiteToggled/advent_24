#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

class Codes {
public:

    void print_arrays() {
        std::cout << arr1.size() << "\n";
        for (size_t i = 0; i < arr1.size(); ++i)
            std::cout << arr1[i] << " " << arr2[i] << "\n";
    }

    int load_data(char* file) {
        std::ifstream input_file(file);

        if (!input_file.is_open()) {
            std::cout << "Unable to open file\n";
            return 0;
        }

        int n1 = 0, n2 = 0;
        while (input_file >> n1 >> n2) {
            arr1.push_back(n1);
            arr2.push_back(n2);
        }

        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());

        input_file.close();
        return 1;
    }

    int solution1() {
        int sum = 0;
        for (size_t i = 0; i < arr1.size(); ++i) {
            sum += std::abs(arr1[i] - arr2[i]);
        }
        return sum;
    }

    int solution2() {
        int total_similarity = 0;

        for (int n: arr1) {
            int n_similarity = 0;

            for (int val: arr2) {
                if (val == n) {
                    n_similarity += 1;
                }
            }
            total_similarity += (n * n_similarity);
        }

        return total_similarity;
    }

private:
    std::vector<int> arr1;
    std::vector<int> arr2;
};


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Incorrect Usage. Try ./solution <filename>\n";
        return -1;
    }

    Codes codes;

    codes.load_data(argv[1]);
    int sum = codes.solution1();
    int similarity = codes.solution2();

    std::cout << "Sum is: " << sum << "\n";
    std::cout << "Similarity is: " << similarity << "\n";
    return 0;
}
