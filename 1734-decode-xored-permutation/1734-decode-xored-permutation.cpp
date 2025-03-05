class Solution {
public:
    vector<int> decode(vector<int>& encoded) 
{
	int n=encoded.size();
	vector<int> result(n+1);
	result[0]=1-(n/2)%2;
	for(int i=1;i<n;i+=2) result[0]^=encoded[i]; 
	for(int i=1;i<=n;i++) result[i]=result[i-1]^encoded[i-1]; 
	return result;
}
};