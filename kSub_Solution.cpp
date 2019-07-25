/**
 * The time complexity of this algorithm is O(n), and does not involve with any multiplication or division.
 * Where most Linear time algorithm online is O(n + k) with a multiplication and a division.
 *
 * This algorithm defeated 96% of submission in speed and 90% in memory usage. 
 */


long kSub(int k, vector<int> nums)
{
  int sumMod[nums.size()];
  sumMod[0] = nums[0] % k;
  if (sumMod[0] < 0)
    sumMod[0] += k;
  for (int i = 1; i < nums.size(); i++)
  {
    sumMod[i] = (sumMod[i - 1] + nums[i]) % k;
    if (sumMod[i] < 0)
      sumMod[i] += k;
  }

  int modCounts[k];
  for (int i = 0; i < k; i++)
    modCounts[i] = 0;

  int ans = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    modCounts[sumMod[i]]++;
    if (sumMod[i] == 0)
      ans++;
  }

  modCounts[sumMod[0]]--;

  for (int i = 1; i < nums.size(); i++)
  {
    int target = (sumMod[i] - (nums[i] % k) + k) % k;
    ans += modCounts[target];
    modCounts[sumMod[i]]--;
  }

  return ans;
}

int main() {
  vector<int> nums;
  // nums.push_back(4);
  // nums.push_back(7);
  // nums.push_back(2);
  // nums.push_back(3);
  // nums.push_back(5);
  // nums.push_back(6);
  // nums.push_back(7);
  // nums.push_back(4);
  // nums.push_back(3);
  // int k = 8;

  // nums.push_back(3);
  // nums.push_back(5);
  // nums.push_back(1);
  // nums.push_back(2);
  // nums.push_back(3);
  // nums.push_back(4);
  // nums.push_back(1);
  // int k = 3;

  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(0);
  nums.push_back(5);
  nums.push_back(7);
  nums.push_back(4);
  int k = 5;

  cout << kSub(k, nums);
  //cout << -5 % 6;
}
