/*

https://leetcode.com/problems/time-based-key-value-store/

981. Time Based Key-Value Store
Medium

1454

165

Add to List

Share
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "ba2r" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
 

Constraints:

1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.

*/
class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>> helper;
    TimeMap() {
        helper.clear();
    }
    
    void set(string key, string value, int timestamp) 
    {
        helper[key].push_back({timestamp,value});
    }
    int help(int t,string key){
     int l = 0;
      int ans = 0;
      int r = helper[key].size()-1;
     int index = 0;
      while(l<=r)
      {
        int mid = (l+r)/2;
        if(helper[key][mid].first==t)
        {
          return mid;
        }
        if(helper[key][mid].first>t)
        {
          r = mid-1;
        }
        else
        {
          ans = mid;
          l = mid+1;
        }
      }
      return ans;
    }
    string get(string key, int timestamp) {
      if(helper[key].empty())
      {
        return "";
      }
   
       if(helper[key][0].first>timestamp)
      {
        return "";
      }
      
     
         if(helper[key][helper[key].size()-1].first<=timestamp)
      {
        return helper[key][helper[key].size()-1].second;
      }
      int index = help(timestamp,key);
      
      if(helper[key][index].first>timestamp)
      {
        return helper[key][index-1].second;
      }
      return helper[key][index].second;
    }
};


