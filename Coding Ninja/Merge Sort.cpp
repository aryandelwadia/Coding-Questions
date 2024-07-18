//Link
//https://www.naukri.com/code360/problems/merge-sort_920442

void merge(vector<int> &arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int firstpartlength = mid - s + 1;
    int secondpartlength = e - mid;

    int i = 0;
    int j = 0;
    
    int* first = new int[firstpartlength];
    int* second = new int[secondpartlength];

    int k = s;
    for(int l = 0; l < firstpartlength; l++){
        first[l] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int l = 0; l < secondpartlength; l++){
        second[l] = arr[k];
        k++;
    }

    k = s;

    while(i < firstpartlength && j < secondpartlength){
        if(first[i] < second[j]){
            arr[k] = first[i];
            i++;
            k++;
        }
        else{
            arr[k] = second[j];
            j++;
            k++;
        }
    }

    while (i < firstpartlength){
        arr[k] = first[i];
        i++;
        k++;
    }
    while (j < secondpartlength){
        arr[k] = second[j];
        j++;
        k++;
    }
}

void divide(vector<int> &arr, int s, int e) {
  if (s >= e) {
    return;
  }

  int mid = s + (e - s) / 2;

  divide(arr, s, mid);
  divide(arr, mid + 1, e);

  merge(arr, s, e);
}

void mergeSort(vector<int> &arr, int n) {
  // Write your code here.
  int s = 0;
  int e = n - 1;

  divide(arr, s, e);
}