class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map <int, int> mp;
        vector <int> temp = arr;
        int rank = 1; 
        // sorting the array
        sort(temp.begin(),temp.end()); 
        // deleting repeated element
        vector<int>::iterator it;
        it = unique(temp.begin(), temp.end());
        temp.resize(distance(temp.begin(), it));
        //assinging rank
        for(int i=0;i<temp.size();i++)
            mp[temp[i]] = rank,++rank;
        for(int i = 0; i < arr.size(); i++)
            arr[i] = mp[arr[i]];
        return arr;
      
};