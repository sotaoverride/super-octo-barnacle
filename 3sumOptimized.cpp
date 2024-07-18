class Solution {
public:
    #define LARGEST 100000
    #define SMALLEST -100000
    #define length (100000 * 4)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> found;
        int* head = (int*)&nums[0];
        int* tail = (int*)&nums[0] + nums.size() - 1;
        bool foundUnique = false;
        int arr[length]={0};
        int thirdVal = 0;
        vector<int> triplet;
        for (size_t i = 0; i < nums.size(); i++) {
            arr[nums[i]+LARGEST]++;
        }
            while (tail > &nums[0]) {
                head = (int*)&nums[0];
                while (head < &nums[nums.size()]) {
                    triplet={};
                    int k = *head + *tail;
                    thirdVal=k*-1;
                    arr[*head+LARGEST]--;
                    arr[*tail+LARGEST]--;
                    if(arr[thirdVal+LARGEST] > 0  && head != tail){
                        if(thirdVal <= *head && thirdVal <= *tail && *head <= *tail){
                            triplet={thirdVal, *head, *tail};
                            goto add;

                        }
                        else if(thirdVal <= *head && thirdVal <= *tail && *tail <= *head){
                            triplet={thirdVal,*tail,*head};
                            goto add;
                        } 
                        else if( (*head <= thirdVal && *head <= *tail) && thirdVal <= *tail){
                            triplet={*head,thirdVal,*tail};
                            goto add;

                        }
                        else if(*head <=thirdVal && *head <= *tail && *tail <= thirdVal){
                            triplet={*head,*tail,thirdVal};
                            goto add;
                        }
                        else if (*tail <= thirdVal && *tail <= *head && *head <= thirdVal){
                            triplet={*tail,*head,thirdVal};
                            goto add;
                        }
                        else if (*tail <=thirdVal && *tail <= *head && thirdVal <= * head){
                            triplet={*tail, thirdVal, *head};
                            goto add;
                        }
                        else triplet={500,500,500};
                        add:
                        foundUnique=true;
                        if (found.size() > 0){ 
                            int firstArr[found.size()];
                            int secondArr[found.size()];
                            int thirdArr[found.size()];
                            for (int j=0;j<found.size();j++){
                                firstArr[j]=found[j][0];
                                secondArr[j]=found[j][1];
                                thirdArr[j]=found[j][2];
                            }
                            for (int j=0;j<found.size();j++){
                                if(firstArr[j]==triplet[0] &&
                                secondArr[j]==triplet[1] &&
                                thirdArr[j]==triplet[2]){
                                    foundUnique=false;
                                    arr[*head+LARGEST]++;
                                    arr[*tail+LARGEST]++;
                                    //arr[thirdVal+LARGEST]++
                                    break;
                                }
                            }
                        }
                        //foundUnique = true;
                        if (foundUnique){
                            found.push_back(triplet);
                            arr[*head+LARGEST]++;
                            arr[*tail+LARGEST]++;
                            //break;
                        }
                    }
                    else{  
                    arr[*head+LARGEST]++;
                    arr[*tail+LARGEST]++;
                    }      
                    head = head + 1;
                }
                tail -= 1;
            }
            if (found.size() == 0) return found;
        return found;
    }
};
int main(){
	Solution sol;
	vector<int> tmp({-1,0,1,2,-1,-4});
	vector<int> tmp2({-10,-7,-3,-9,-8,-9,-5,6,0,6,4,-15,-12,3,-12,-10,-5,-5,2,-4,13,8,-9,6,-11,11,3,-13,-3,14,-9,2,14,-5,8,-9,-7,-12,5,1,2,-6,1,5,4,-4,3,7,-2,12,10,-3,6,-14,-12,10,12,7,12,-14,-2,11,4,-10,13,-11,-4,-8,-15,-14,8,-6,-12,-14,6,7,-3,-14,-1,11,14,-6,-15,5,-13,-12,0,14,2,-11,-14,8,-15,-3,13,14,-7,-14,13,-15,10,-2,-14,13});
	vector<int> tmp3({-1,0,1,2,-1,-4,-2,-3,3,0,4});
	vector<vector <int>> result=sol.threeSum(tmp3);
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
