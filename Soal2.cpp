// Nama: Fadli Islamianto
// NIM : 230401010281

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk mencetak array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Fungsi untuk melakukan binary search dan mencari semua indeks dari elemen target
vector<int> binarySearchAllIndices(const vector<int>& arr, int target) {
    vector<int> indices;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            // Cari semua indeks target di sekitar mid
            indices.push_back(mid);
            int l = mid - 1;
            while (l >= 0 && arr[l] == target) {
                indices.push_back(l);
                l--;
            }
            int r = mid + 1;
            while (r < arr.size() && arr[r] == target) {
                indices.push_back(r);
                r++;
            }
            sort(indices.begin(), indices.end());
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return indices;
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};

    // Mengurutkan array terlebih dahulu
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    cout << "Array setelah diurutkan: ";
    printArray(sortedArr);

    // Meminta input dari pengguna
    int target;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> target;

    // Mencari angka dalam array
    vector<int> result = binarySearchAllIndices(sortedArr, target);

    if (result.empty()) {
        cout << "Angka " << target << " tidak ada dalam array" << endl;
    } else {
        cout << "Angka " << target << " ada di indeks ke ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << " dan ";
            }
        }
        cout << endl;
    }

    return 0;
}
