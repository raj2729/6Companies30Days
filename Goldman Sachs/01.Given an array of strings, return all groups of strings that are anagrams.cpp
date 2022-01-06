class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        // The order of the string in the array will be same as the 
        // order in the given question.

        vector<vector<string>> ans;

        map<vector<int>,vector<string>> mp;
        // map to store strings with similar characters.
        map<vector<int>,int> ordering;
        // map to maintain the order of the string elements,
        // so the element that is has a lower index in string_list,
        // is printed before, either in its same group or overall.

        vector<pair<int,vector<int>>> vp;
        // pair to sort the ordering

        for(auto &eachString: string_list) {
            vector<int> v(26,0);
            for(auto &eachChar: eachString) {
                v[eachChar-'a']++;
            }
            mp[v].push_back(eachString);
            if(ordering.find(v)==ordering.end()) {
                ordering[v] = ordering.size();
            }
        }

        // Sorting the ordering
        for(auto &it: ordering) {
            vp.push_back({it.second,it.first});
        }
        sort(vp.begin(),vp.end());
        
        for(auto &it: vp) {
            vector<string> eachAns;
            for(auto &eachString: mp[it.second]) {
                eachAns.push_back(eachString);
            }
            ans.push_back(eachAns);
        }
        return ans;
    }
};