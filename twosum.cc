#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using std::cout;
using std::cin;
using std::map;
using std::vector;
using std::unordered_map;

vector<int> twoSum(vector<int>& nums, int value) {
  // map vs unordered_map
  // keep in mind, map keeps keys in sorted order
  // unordered_map is good for pure key/value insert/retrieval
  map<int,int> map;
  vector<int> indices;
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    if (map.find(nums[i]) != map.end()) {
      indices.push_back(map[nums[i]]);
      indices.push_back(i);
      return indices;
    } else {
      map[value-nums[i]] = i;
    }
  }
  return indices;
}

int main() {
  vector<int> nums{1,2,3,4,5};

  vector<int> res = twoSum(nums, 6);

  for (auto i : res) {
    cout << i << "\n";
  }

  map<int,int> m {
    {3,3},
    {7,7},
    {4,4},
    {1,1}
  };

  unordered_map<int,int> um {
    {3,3},
    {7,7},
    {4,4},
    {1,1}
  };

  cout << "map\n";
  for (auto i : m) {
    cout << i.first << ' ' << i.second << '\n';
  }
  cout << "\nunordered_map\n";
  for (auto i : um) {
    cout << i.first << ' ' << i.second << '\n';
  }

  for (auto i = um.begin(); i != um.end(); i++) {
    cout << i->first << ' ' << i->second << '\n';
  }
}

