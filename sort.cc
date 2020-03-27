#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 快排
void quick_sort(vector<int>& vec, int start, int end);
// 冒泡排序
void bubble_sort(vector<int>& vec);
// 选择排序
void select_sort(vector<int>& vec);
// 插入排序
void insert_sort(vector<int>& vec);
// 希尔排序
void shell_sort(vector<int>& vec);
// 归并排序
void MergeSort(vector<int> &arr,int L,int R);
void merge(vector<int> &arr,int L,int mid,int R);
void sortprocess(vector<int> &arr,int L,int R);
// 堆排序
void heap_sort(vector<int>& vec, int size);
void adjust(vector<int> &arr, int len, int index);
// 计数排序(可理解为简易的桶排序)
void count_sort(vector<int>& vec);
// 桶排序
void bucket_sort(vector<int>& vec);

int main() {
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(2);

    // quick_sort(vec,0,vec.size()-1);
    // bubble_sort(vec);
    // select_sort(vec);
    // insert_sort(vec);
    // MergeSort(vec,0,vec.size()-1);
    // heap_sort(vec,vec.size());
    // count_sort(vec);
    bucket_sort(vec);

    for (auto val : vec) {
        cout << val << endl;
    }
    return 0;
}

void bucket_sort(vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    int bucket_size = 3;
    int max_val = vec[0];
    int min_val = vec[0];

    for (auto x : vec) {
        if (x > max_val) {
            max_val = x;
        }
        if (x < min_val) {
            min_val = x;
        }
    }
    
    // 所有数组元素都相等
    if (max_val == min_val) {
        return;
    }

    // 桶的个数
    int bucket_num = (max_val - min_val)/bucket_size + 1;
    vector<vector<int>> bucket;
    for (int i = 0; i < bucket_num; i++) {
        vector<int> temp_bucket;
        bucket.push_back(temp_bucket);
    }

    for (auto x : vec) {
        for (int i = 0; i < bucket_num; i++) {
            if (x >= (min_val+bucket_size*i) && x < (min_val+bucket_size*(i+1))) {
                bucket[i].push_back(x);
            }
        }
    }

    int current_index = 0;
    for (int i = 0; i < bucket_num; i++) {
        insert_sort(bucket[i]);
        for (auto x : bucket[i]) {
            vec[current_index++] = x;
        }
    }
}

void count_sort(vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    int min_val = vec[0];
    int max_val = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
        if (vec[i] < min_val) {
            min_val = vec[i];
        }
    }
    
    if (max_val == min_val) {
        return;
    }

    int *count = NULL;
    count = (int*)malloc(sizeof(int) * (max_val-min_val+1));
    for (int i = 0; i < (max_val-min_val+1); i++) {
        count[i] = 0;
    }
    for (int i = 0; i < vec.size(); i++) {
        count[vec[i]-min_val] += 1;
    }
    for (int i = 0; i < (max_val-min_val+1); i++) {
        cout << count[i] << endl;
    }
    cout << "fdfdg" << endl;
    int current_num = 0;
    for (int i = 0; i < (max_val-min_val+1); i++) {
        for (int j = 0; j < count[i]; j++) {
            vec[current_num++] = i+min_val;
        }
    }

    free(count);
}
// 堆排序
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点
 
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx]) {
        maxIdx = left;
    }
    if(right<len && arr[right] > arr[maxIdx]) {
        maxIdx = right;
    }
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
void heap_sort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}


// 归并排序
void merge(vector<int> &arr,int L,int mid,int R)
{
	int *help = new int(R-L+1);
	int p1=L,p2=mid+1,i=0;
	while(p1<=mid && p2<=R)
	{
		help[i++] = arr[p1]>arr[p2] ? arr[p2++] : arr[p1++];
	}
	while(p1<=mid)
		help[i++] = arr[p1++];
	while(p2<=R)
		help[i++] = arr[p2++];
 
	for (int i=0;i<R-L+1;i++)
	{
		arr[L+i] = help[i];
	}
}
void sortprocess(vector<int> &arr,int L,int R)
{
	if (L < R)
	{
		int mid = L + ((R-L)>>2);  //  (L+R)/2
		sortprocess(arr,L,mid);
		sortprocess(arr,mid+1,R);
		merge(arr,L,mid,R);
	}
}
 
void MergeSort(vector<int> &arr,int L,int R)
{
	if (arr.size()<2)
		return;
	sortprocess(arr,L,R);
}


void shell_sort(vector<int>& vec) {
}

void insert_sort(vector<int>& vec) {
    for (int i = 0; i < vec.size()-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            if (vec[j] < vec[j-1]) {
                swap(vec[j],vec[j-1]);
            }
        }
    }
}

void select_sort(vector<int>& vec) {
    if (vec.size() <= 1) {
        return;
    }
    int select_pos = 0;
    // int min_val = vec[0];
    for (int i = 0; i < vec.size()-1; i++) {
        int min_val = vec[i];
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[j] < min_val) {
                min_val = vec[j];
                select_pos = j;
            }
        }
        if (select_pos != 0) {
            swap(vec[i],vec[select_pos]);
        }
        select_pos = 0;
    }
}

void bubble_sort(vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    // 遍历完一次，最大值(升序排列)或者最小值（降序排列）会到数组末尾
    // 因此需要 n-1 词遍历
    for (int i = 0; i < vec.size()-1; i++) {
        for (int j = 0; j < vec.size()-1-i; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j],vec[j+1]);
            }
        }
    }
}

void quick_sort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = vec[start];
    int prev_pos = start;
    int back_pos = end;
    while (prev_pos < back_pos) {
        if (vec[prev_pos+1] < pivot) {
            vec[prev_pos] = vec[prev_pos+1];
            prev_pos++;
        } else {
            if (vec[back_pos] < pivot) {
                int temp = vec[prev_pos+1];
                vec[prev_pos] = vec[back_pos];
                vec[back_pos] = temp;
                prev_pos++;
            }
            back_pos--;
        }
    }
    vec[prev_pos] = pivot;
    quick_sort(vec,start,prev_pos-1);
    quick_sort(vec,prev_pos+1,end);
}
