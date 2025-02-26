int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans  = 0;
        while(i<j){
            int mini = min(height[i], height[j]);
            ans = max(ans, mini*(j-i));
            if(mini == height[i]) i++;
            else j--;
        }
        return ans;
    }
};