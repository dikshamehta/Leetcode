class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Stores the last index of each character in 's'
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        int partitionEnd = 0, partitionStart = 0;
        vector<int> partitionSizes;
        for (int i = 0; i < s.size(); ++i) {
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
            // End of the current partition
            if (i == partitionEnd) {
                partitionSizes.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partitionSizes;
    }
};

// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         unordered_map<char, int> freq;
//         vector<int> res;
//         int p=0;

//         for(int i=0; i<s.size(); i++){
            
//             if(freq.find(s[i])!=freq.end()){
//                 //find the key
//                 if(freq[s[i]]<res.back()){
//                     res.back() = i;
//                 }
                
//             }
//             else{
//                 p = i;
//                 res.push_back(p);
//             }

//             freq[s[i]] = i;
//         }
//         return res;
//     }
// };