void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của phần chưa sắp xếp
        swap(arr[i], arr[minIndex]);
    }
}
