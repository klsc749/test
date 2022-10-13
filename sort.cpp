#include <iostream>
#include <vector>
void intersectionSort(std::vector<int>& a){
    int n = a.size();
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && key < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void shell_sort(std::vector<int>& a){
    int n = a.size();
    for(int gap = n >> 1; gap > 0; gap >>= 1){
        for(int i = gap; i < n; i ++){
            int j = i - gap;
            int key = a[i];
            while(j >= 0 && key < a[j]){
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = key;
        }
    }
}

void merge_sort_recursive(std::vector<int>& a, std::vector<int>& reg, int start, int end){
    if(start >= end){
        return;
    }
    int mid = ((end - start)>> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(a, reg, start1, end1);
    merge_sort_recursive(a, reg, start2, end2);
    int k = start;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++]; 
    }
    while(start1 <= end1){
        reg[k++] = a[start1++];
    }
    while (start2 <= end2)
    {
        reg[k++] = a[start2++];
    }

    for(k = start; k <= end; k++){
        a[k] = reg[k];
    }
    
}

void quick_sort_recursive(std::vector<int>& a, int start, int end){
    if(start >= end){
        return;
    }
    int left = start, right = end - 1, pivot = a[end];
    while (left < right)
    {
        while(a[left] < pivot && left < right){
            left++;
        }
        while (a[right] >= pivot && left < right)
        {
            right--;
        }
        std::swap(a[left], a[right]);
    }
    if(a[left] > pivot){
        std::swap(a[left], a[end]);
    }
    else
        left++;
    quick_sort_recursive(a, start, left - 1);
    quick_sort_recursive(a, left + 1, end);
}

void quick_sort(std::vector<int>& a){
    quick_sort_recursive(a, 0, a.size() - 1);
}

void merge_sort(std::vector<int>& a){
    int n = a.size();
    std::vector<int> reg(n);
    merge_sort_recursive(a, reg, 0, n - 1);
}

int main(int argc,char** argv){
    std::vector<int> a{4, 3, 9, 10, 1, 2};
    merge_sort(a);
    for(int& b : a){
        std::cout << b << ",";
    }
    return 1;
}