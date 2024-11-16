#include <iostream>
#include <vector>
#include <string>

void backtrack(std::string current, int open_round, int close_round, int open_square, int close_square, int n, int m, std::vector<std::string>& result) {
    // If all parentheses are correctly closed, add them to the result list.
    if (open_round == close_round && open_round == n && open_square == close_square && open_square == m) {
        result.push_back(current);
        return;
    }

    // The condition for adding parentheses.
    if (open_round < n) {
        backtrack(current + "(", open_round + 1, close_round, open_square, close_square, n, m, result);
    }

    if (close_round < open_round) {
        backtrack(current + ")", open_round, close_round + 1, open_square, close_square, n, m, result);
    }

    // The condition for adding square brackets: Only add square brackets after ensuring that the round parentheses are closed.
    if (open_square < m && open_round == close_round) {
        backtrack(current + "[", open_round, close_round, open_square + 1, close_square, n, m, result);
    }

    if (close_square < open_square && open_round == close_round) {
        backtrack(current + "]", open_round, close_round, open_square, close_square + 1, n, m, result);
    }
}

std::vector<std::string> generate_sequences(int n, int m) {
    std::vector<std::string> result;
    backtrack("", 0, 0, 0, 0, n, m, result);
    return result;
}

int main() {
    int n, m;
    std::cout << "Please enter the number of pairs of parentheses. n: ";
    std::cin >> n;
    std::cout << "Please enter the number of pairs of brackets. m: ";
    std::cin >> m;

    std::vector<std::string> sequences = generate_sequences(n, m);
    for (const auto& seq : sequences) {
        std::cout << seq << std::endl;
    }
  
    return 0;
}
