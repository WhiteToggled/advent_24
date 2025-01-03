#include <bits/stdc++.h>

class Solution {
public:
    bool is_valid(std::vector<int> data) {
        size_t len = data.size();

        if (len <= 1) return true;

        bool asc = true;
        bool dsc = true;

        for (size_t i = 1; i < len; ++i) {
            int diff = data[i] - data[i-1];

            if (std::abs(diff) >= 4) return false;
            
            if (diff > 0) asc = false;
            if (diff < 0) dsc = false;

            if (!diff) return false;
            if (!asc && !dsc) return false;
        }
        return asc ^ dsc;
    }

    int load_data(const char* file) {
        std::ifstream input_file(file);

        if (!input_file.is_open()) {
            std::cout << "Unable to open file\n";
            return 0;
        }

        std::string in = "";
        while (getline(input_file, in)) {

            std::vector<int> row;
            std::istringstream ss(in);

            int digit = 0;
            while (ss >> digit) {
                row.emplace_back(digit);
            }

            data.push_back(row);
        }

        input_file.close();
        return 1;
    }

    const int solution1() {
        int safe = 0;
        for (std::vector<int> line: data) {
            if (is_valid(line))
                safe += 1;
        }

        return safe;
    }

    const int solution2() {
        int safe = 0;

        // TODO
        return safe;
    }

private:
    std::vector<std::vector<int>> data;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect Usage. Try ./solution <filename>\n";
        return -1;
    }

    Solution solution;
    solution.load_data(argv[1]);

    int full_safe = solution.solution1();
    
    std::cout << "Completely safe: " << full_safe << std::endl;
    return 0;
}
