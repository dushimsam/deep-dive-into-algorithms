int longestIncreasingSubsequence(vector<int> elements)
{
    int cols = elements.size();
    vector<int> dp_arr(cols, 1);

    for (int i = 1; i < cols; i++)
    {
        for(int k = i-1 ; k >=0 ;k--){
            if(elements[i] > elements[k]){
                dp_arr[i] = 1 + dp_arr[k];
                break;
            }
        }
        dp_arr[i] = max(dp_arr[i],dp_arr[i-1]);
    }

    for(int i=0;i<cols;i++) cout<<dp_arr[i]<<" ";
    cout<<"\n";
    return dp_arr[cols-1];
}
