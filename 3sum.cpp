#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums)
		{
			vector<vector<int>> found; 

			int * head= (int*)&nums[0];
			int * tail= (int*)&nums[0]+nums.size()-1;
			bool foundUnique = false;
			long unsigned int size=nums.size();

			for (size_t i=0; i<size; i++){
				while(tail>=(int *)&nums[0]){
					while (head<&nums[0]+nums.size()){
						if((int *)&nums[i]!=tail && (int*)&nums[i]!=head && head!=tail){
							if (nums[i]+(int)*tail+(int)*head==0){
								vector<int> triplet({nums[i],*head,*tail});
								vector<int> triplet1({nums[i],*tail,*head});
								vector<int> triplet2({*tail,nums[i],*head});
								vector<int> triplet3({*tail,*head,nums[i]});
								vector<int> triplet4({*head,*tail,nums[i]});
								vector<int> triplet5({*head,nums[i],*tail});
								foundUnique=true;
								for(size_t j=0;j<found.size();j++){


									if(found[j]==triplet ||
											found[j]==triplet1||
											found[j] ==triplet2 ||
											found[j]==triplet3 ||
											found[j]==triplet4 ||
											found[j]==triplet5
									  ) foundUnique=false;

								}
								if(foundUnique){
									printf("found some");
									found.push_back(triplet);
								}
							}
						}
						head+=sizeof(int);
						//tail-=sizeof(int);
					}
					tail-=sizeof(int);

				}
				tail = (int *)&nums[0]+nums.size()-1;
				head=(int *)&nums[0];
			}
			return found;        
		}
};
int main(){
	Solution sol;
	vector<int> tmp({-1,0,1,2,-1,-4});

	vector<vector <int>> result=sol.threeSum(tmp);
	printf("%s ", "[");
	for (size_t i=0;i<result.size();i++) {
		printf("%s", "[");
		for (size_t j=0;j<result[i].size();j++) {
			printf("%d,", result[i][j]);
		}
		printf("%s", "]");
	}
	return 0;


}
