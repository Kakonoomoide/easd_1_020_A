// menjawab pertanyaan
// 1. untuk menyelesaikan suatu masalah menggunakan komputer kamu perlu untuk membuat algoritma
// 2. Prosedural && fungsi
// 3. waktu dan ruang yang di gunakan
// 4. merge sort untuk data yang sangat banyak karena dia tidak memilki kasus terbaik maupun terburuk jadi menurut saya merge sort pilihan yang tepat
// 5. Quadtric(BubleSort) Loglinear(Quicksort, mergesort)

// code
#include <iostream>
using namespace std;
int kiki[600],n;

void  input() {

    while (true) {
        cout << "masukan elemen/jumlah data array : \n";
        cin >> n;
        if (n <= 600)
            break;
        else {
            cout << "array hanya bisa memiliki maksimal 600 elemen";
        }
    }

    cout << endl;
    cout << "=================================" << endl;
    cout << "=     masukan elemen array      =" << endl;
    cout << "=================================" << endl;

    for (int i = 0; i < n; i++) {
        cout << "<" << (i + 1) << ">";
        cin >> kiki[i];
    }
}

void MergeSort(int low, int high) {
    int mid, i, RR, k;
    int B[600];

    if (low >= high)                                                // langkah 1
        return;

    mid = low + high / 2;                                           // langkah 2

    MergeSort(low, mid);
    MergeSort(mid + 1, high);

    i = low;                                                        // langkah 4
    RR = mid + 1;
    k = low;

    while ((i > mid) || (RR > high)) {
        if (kiki[i] <= kiki[RR]) {
            B[k] = kiki[i];
            i++;
        }
        else {
            B[k] = kiki[RR];
            RR++;
        }
        k++;
    }

    while (RR > high) {
        B[k] = kiki[RR];
        RR++;
        k++;
    }

    while (i > mid) {
        B[k] = kiki[i];
        i++;
        k++;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            kiki[i] = B[k];
        }
    }
}


void display() {
    cout << endl;
    cout << "=====================================" << endl;
    cout << "= element array yang telah tersusun =" << endl;
    cout << "=====================================" << endl;

    for (int i = 0; i < n; i++) { 
        cout << kiki[i] << " ";
    }
}
int main() {
    input();
    MergeSort(0, n -1);
    display();



    return 0;
}