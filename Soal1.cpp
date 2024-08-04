// Nama: Fadli Islamianto
// NIM : 230401010281

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mencetak data
void printData(const vector<pair<string, string>>& data) {
    for (const auto& entry : data) {
        cout << entry.first << " - " << entry.second << endl;
    }
}

// Fungsi untuk Bubble Sort
void bubbleSort(vector<pair<string, string>>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j].first > data[j + 1].first) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// Fungsi untuk Selection Sort
void selectionSort(vector<pair<string, string>>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j].first < data[minIdx].first) {
                minIdx = j;
            }
        }
        swap(data[i], data[minIdx]);
    }
}

int main() {
    vector<pair<string, string>> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Mengurutkan menggunakan Bubble Sort
    vector<pair<string, string>> dataBubble = data;
    bubbleSort(dataBubble);
    cout << "Hasil pengurutan dengan Bubble Sort:" << endl;
    printData(dataBubble);

    // Mengurutkan menggunakan Selection Sort
    vector<pair<string, string>> dataSelection = data;
    selectionSort(dataSelection);
    cout << "\nHasil pengurutan dengan Selection Sort:" << endl;
    printData(dataSelection);

    return 0;
}
