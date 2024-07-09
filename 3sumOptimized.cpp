#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums)
		#define LARGEST 100000
		#define SMALLEST -100000
		#define length (100000 * 2)
		{
			vector<vector<int>> found; 
			int * head= (int*)&nums[0];
			int * tail= (int*)&nums[0]+nums.size()-1;
			bool foundUnique = false;
			long unsigned int size=nums.size();
			int arr[length]={0};
			int thirdVal=0;
			for (size_t i=0; i<size; i++){
				arr[nums[i]+LARGEST+SMALLEST]++;
			}
				while(tail>=(int *)&nums[0]){
					head=(int *)&nums[0];

					while (head<&nums[0]+nums.size()){
						int k = *head + *tail;
						thirdVal=k*-1;
						//int index = thirdVal+LARGEST+SMALLEST;
						arr[*head+LARGEST+SMALLEST]--;
						arr[*tail+LARGEST+SMALLEST]--;
					        if(arr[thirdVal+LARGEST+SMALLEST] > 0) { arr[thirdVal+LARGEST+SMALLEST]--;} else break;	
						vector<int> triplet({thirdVal,*head,*tail});
						vector<int> triplet1({thirdVal,*tail,*head});
						vector<int> triplet2({*tail,thirdVal,*head});
						vector<int> triplet3({*tail,*head,thirdVal});
						vector<int> triplet4({*head,*tail,thirdVal});
						vector<int> triplet5({*head,thirdVal,*tail});
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
						head=head+1;
					}
					tail-=1;
				}
			return found;        
		}
};
int main(){
	Solution sol;
	vector<int> tmp({-1,0,1,2,-1,-4});
	vector<int> tmp2({-10,-7,-3,-9,-8,-9,-5,6,0,6,4,-15,-12,3,-12,-10,-5,-5,2,-4,13,8,-9,6,-11,11,3,-13,-3,14,-9,2,14,-5,8,-9,-7,-12,5,1,2,-6,1,5,4,-4,3,7,-2,12,10,-3,6,-14,-12,10,12,7,12,-14,-2,11,4,-10,13,-11,-4,-8,-15,-14,8,-6,-12,-14,6,7,-3,-14,-1,11,14,-6,-15,5,-13,-12,0,14,2,-11,-14,8,-15,-3,13,14,-7,-14,13,-15,10,-2,-14,13});
	vector<vector <int>> result=sol.threeSum(tmp2);
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
