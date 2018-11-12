/*
3 Sum
Problem Statement:
Given an array of N integers, find all triplets that sum to 0 (zero).
Triplets may or may not be consecutive numbers.
The array can include duplicate elements.
Array is not necessarily sorted.
Print output as shown. i.e. as strings, one per line, comma separated elements. See sample for clarity.
Order of elements inside the answer triplets does not matter. i.e. if your output elements are the same, but only in different order, then it's an acceptable solution.
Do not print duplicate triplets. Eg: 1,1,-2 and 1,-2,1 are duplicates.
If no such triplets are found, then print nothing.

Input Format:

Integer array
Input may or may not be sorted
Repeats possible


Output Format:



Return a String array containing all possible triplets who sum to 0. One String for one triplet.

Order of output does not matter. 



Constraints:



1 <= N <= 2000

-10^3 <= element <= 10^3

Given array may contains duplicate numbers.



Sample Test Case:



Sample Input-1:



arr = [10, 3, -4, 1, -6, 9];



Sample Output-1:



10,-4,-6

3,-4,1



Sample Input-2:



arr = [12, 34, -46];



Sample Output-2:



12,-46,34



Sample Input-3:



arr = [0, 0, 0];



Sample Output-3:



0,0,0



Sample Input-4:



arr = [-2, 2, 0 -2, 2];



Sample Output-4:



2,-2,0



*/ 
void find(vector<int> &arr, int num, vector<string> &r, int idx, unordered_set<string> &set) {
    
    int left = idx + 1;
    int right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == num) {
            int rnum = -num;
            
            string s = to_string(rnum) + "," + to_string(arr[left]) + "," + to_string(arr[right]);
            
            if (set.find(s) == set.end()) {
                set.insert(s);
                r.push_back(s);
            }
            
            left++;
        }
        if (sum < num) {
            left++;
        } 
        if (sum > num) {
            right--;
        }
    }
    
}
vector<string> findZeroSum(vector<int> arr) {
    vector<string> r;
    unordered_set<string> s;
    sort(begin(arr), end(arr));
    for (int i = 0; i < arr.size(); i++) {
        int num =  -arr[i];
        find(arr, num, r, i, s);
    }
    return r;   

}


