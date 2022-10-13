#include <vector>
#include <iostream>

void printVector(const std::vector<int>& v){
    for(const int a : v){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}


void bubbleSort(std::vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(v[j] > v[j + 1]){
                std::swap(v[j], v[j + 1]);
            }
        }
    }
    std::cout << "Bubble Sort: ";
}

void selectionSort(std::vector<int>& v){
    int len = v.size(), minIndex;
    for(int i = 0; i < len - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < len; j++){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        std::swap(v[i], v[minIndex]);
    }
    std::cout << "Selection Sort: ";
}

void intersectionSort(std::vector<int>& v){
    int len = v.size(), key;
    for(int i = 1; i < len; i++){
        int j = i - 1;
        key = v[i];
        while(j > -1 && key < v[j]){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
    std::cout << "Intersection Sort: ";
}

void shellSort(std::vector<int>& v){
    int len = v.size(), key;
    int h = 1;
    while (h < len / 3)
    {
        h = h * 3 + 1;
    }
    while (h >= 1)
    {
        for(int i = h; i < len; i++){
            int j = i - h;
            key = v[i];
            while (j >= 0 && key < v[j])
            {
                v[j + h] = v[j];
                j -= h;
            }
            v[j + h] = key;
            
        }
        h /= 3;
    }
    std::cout << "Shell Sort: ";
}


void ShellSortTest(std::vector<int>& v){
    int n = v.size();
    int gap = 1;
    while(gap < n / 3){
        gap = gap * 3 + 1;
    }
    while(gap >= 1){
        for(int i = gap; i < n; i++){
            int preIndex = i - gap;
            int current = v[i];
            while (preIndex >= 0 && v[preIndex] > current)
            {
                v[preIndex + gap] = v[preIndex];
                preIndex -= gap;
            }
            v[preIndex + gap] = current;
        }
        gap /= 3;        
    }

}
void MergeSortCursive(std::vector<int>& v, std::vector<int> tmp, int begin, int end){
    if(begin >= end){
        return;
    }

    int mid = ((end - begin) >> 1) + begin;
    int start1 = begin, end1 = mid;
    int start2 = mid + 1, end2 = end;
    MergeSortCursive(v, tmp, start1, end1);
    MergeSortCursive(v, tmp,start2, end2);

    int curIndex = begin;
    while(start1 <= end1 && start2 <= end2){
        tmp[curIndex++] = v[start1] < v[start2] ? v[start1++] : v[start2++];
    }
    while(start1 <= end1){
        tmp[curIndex++] = v[start1++];
    }
    while(start2 <= end2){
        tmp[curIndex++] = v[start2++];
    }

    for(int i = begin; i<= end; i++){
        v[i] = tmp[i];
    }
}


void MergeSort(std::vector<int>& v){
    int n = v.size();
    std::vector<int> tmp(n, 0);
    MergeSortCursive(v, tmp, 0, n - 1);
}

int Median3(std::vector<int>& v, int begin, int end){
    int center = (end + begin)/ 2;
    if(v[begin] > v[end])
    std::swap(v[end], v[begin]);
    if(v[begin] > v[center])
    std::swap(v[end], v[center]);
    if(v[center] > v[end])
    std::swap(v[end], v[center]);

    std::swap(v[center], v[end - 1]);

    return v[end - 1];
}

void intersectionQSort(std::vector<int>& v, int begin, int end){
    int len = v.size(), key;
    for(int i = begin; i <= end; i++){
        int j = i - 1;
        key = v[i];
        while(j > -1 && key < v[j]){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void QSort(std::vector<int>& v, int begin, int end){
    int i, j;
    int pivot;
    if(begin + 3 <= end){
        pivot = Median3(v, begin, end);
        i = begin - 1; 
        j = end - 1;
        for(;;){
            while(v[++i] < pivot){};
            while(v[--j] > pivot){};
            if(i < j){
                std::swap(v[i], v[j]);
            }
            else{
                break;
            }
        }
        std::swap(v[i], v[end - 1]);
        QSort(v, begin, i - 1);
        QSort(v, i + 1, end);
    }
    else{
        intersectionQSort(v, begin, end);
    }
}

void QuickSort(std::vector<int>& v){
    QSort(v, 0, v.size() - 1);
    std::cout << "Quick Sort: ";
}


int main(int argc, char const *argv[])
{ 
    std::vector<int> v = {4, 2, 9, 6, 5,  -2,7, 9, 13, 45, 21, 15};
    QuickSort(v);
    printVector(v);
    return 0;
}
