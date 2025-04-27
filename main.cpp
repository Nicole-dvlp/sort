// Задание 6. Вариант 3. sort - s
//
// Написать 4 функции, сортирующие массив 4 способами: методом пузырька, вставки, выбора и быстрой сортировкой.
// 3 вариант - массив строк.
// Эти функции поместить в отдельный файл, сделать к нему заголовочный файл.
//
// Программа должна запускаться из командной строки :
// sort[-s | -b | -i | -q] <имя файла> (по умолчанию - q)
//
// - s - сортировка методом выбора
// - b - методом пузырька
// - i - методом вставки
// - q - быстрая сортировка
// (по умолчанию - q)
//
// Числа, символы или строки читаются из указанного файла, сортируются указанным способом и выводятся на экран.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sort_algorithms.h"
using namespace std;


int main(int argc, char* argv[]) {
    
    string method;
    string filename;

    // Parse arguments
    if (argc == 3) {
        method = argv[1];
        filename = argv[2];
    }
    else if (argc == 2) {
        filename = argv[1];
        method = "-q"; // Default is quick sort
    }
    else {
        cout << "Use: sort [-s|-b|-i|-q] <filename>" << endl;
        cout << " -s : Selection sort" << endl;
        cout << " -b : Bubble sort" << endl;
        cout << " -i : Insertion sort" << endl;
        cout << " -q : Quick sort (default)" << endl;
        return 1;
    }

    // Open file or output the error
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Read strings from file
    vector<string> strings;
    string line;
    int flag = 0;
    while (getline(file, line)) {
        flag = 1;
        strings.push_back(line);
    }
    file.close();
    
    // Check. Is file empty?
    if (flag == 0) {
        cerr << "File " << filename << " is empty." << endl;
        return 1;
    }

    // Output strings from file
    cout << "Before sorting:" << endl;
    for (const auto& line : strings) {
        cout << line << endl;
    }
    cout << endl;

    // Sort the strings based on the chosen method
    if (method == "-s") {
        selectionSort(strings);
    }
    else if (method == "-b") {
        bubbleSort(strings);
    }
    else if (method == "-i") {
        insertionSort(strings);
    }
    else { // Default to quick sort
        quickSort(strings, 0, strings.size() - 1);
    }


    // Output sorted strings
    cout << "Sorted strings: " << endl;
    for (const auto& str : strings) {
        cout << str << endl;
    }

    return 0;
}