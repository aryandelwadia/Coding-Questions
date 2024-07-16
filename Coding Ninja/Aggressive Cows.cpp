//Link
//https://www.naukri.com/code360/problems/aggressive-cows_1082559

bool isPossible(vector<int> &stalls, int k, int mid) {

  int cowcount = 1;

  int lastPos = stalls[0];

  for (int i = 0; i < stalls.size(); i++) {

    if (stalls[i] - lastPos >= mid) {

      cowcount++;

      if (cowcount == k) {

        return true;
      }

      lastPos = stalls[i];
    }
  }

  return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
  //    Write your code here.
  sort(stalls.begin(), stalls.end());
  int s = 0;
  int m = -1;
  for (int i = 0; i < stalls.size(); i++) {
    m = max(m,stalls[i]);
  }
  int e = m;
  int mid = s + (e - s) / 2;
  int ans = -1;

  while (s <= e) {
    if (isPossible(stalls, k, mid)) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}