#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <utility>
#include <unordered_map>

class Huffman
{

public:
    Huffman(std::array<std::size_t, 256> &freq_simbols);
    ~Huffman();

    std::vector<bool> encode(std::uint8_t simbol);
    bool decode(bool bit);
    std::uint8_t get_current_simbol();

private:
    void create_tree(std::array<std::size_t, 256> &freq_simbols);
    void generate_map();

    struct Node
    {
        Node(const std::uint8_t simbol, const std::size_t freq, const bool is_leaf) : left{nullptr}, right{nullptr}, freq{freq}, simbol{simbol}, is_leaf{is_leaf}
        {
        }

        void search(std::unordered_map<std::uint8_t, std::vector<bool>> &code_map, std::vector<bool> &code)
        {
            if (this->is_leaf)
            {
                code_map[this->simbol] = code;
                return;
            }
            std::vector<bool> code_right = code;
            code_right.push_back(true);
            if (this->right)
            {
                this->right->search(code_map, code_right);
            }

            std::vector<bool> code_left = code;
            code_left.push_back(false);
            if (this->left)
            {
                this->left->search(code_map, code_left);
            }
        }

        Node *left;
        Node *right;
        std::size_t freq;
        std::uint8_t simbol;
        bool is_leaf;
    };

    void delete_node(Node *n);

    Node *root;
    Node *cursor;
    std::unordered_map<std::uint8_t, std::vector<bool>> code_map;
    size_t size;
    std::uint8_t current_simbol;
};

#endif