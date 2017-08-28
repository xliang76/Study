/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

      Because nums[0] + nums[1] = 2 + 7 = 9,
      return [0, 1].
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(const vector<int>& nums, const int target) {
    // Since x1 + x2 = target, we can in one loop 
    // mark both x1 and x2 in some additional array where we'll keep indices
    // Though to build that array we'd need another loop

    int min = nums[0], max = min;
    vector<int> result;
    // first loop to find max and min integers
    for (size_t i = 0;i < nums.size();i++)
    {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }
    // valid range for input integers relative to target
    int sMin;
    int sMax;
    if(min < target - max)
        sMin = min;
    else
        sMin = target - max;

    if(max > target - min)
        sMax = max;
    else
        sMax = target - min;

    // array to keep indices of valid input integers
    // initialize with -1
    int size = 1 + sMax - sMin;
    int arr[size];
    // for (int i = 0; i < arr.length;i++)
    //     arr[i] = -1;
    fill(arr,arr+size,-1);
    // second loop
    int offset = -sMin;
    for (size_t i = 0;i < nums.size();i++)
    {
        // Skip if integer is not from a valid range
        if (nums[i] > sMax || nums[i] < sMin)
            continue;
        // if found valid X1 and corresponding element of indices array is still -1
        // then mark its pair X2 = target - X1 in indices array
        if (arr[nums[i] + offset] == -1)
            arr[target-nums[i] + offset] = i;
        else
        {
            result.push_back(arr[nums[i] + offset]);
            result.push_back(i);
            return result;
            //return {arr[nums[i] + offset],i};
        }
    }
    return result;//0,0};
}

/*
vector<int> twoSum_new(const vector<int> &numbers, const int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (size_t i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
            //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);            
            return result;
        }

        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
*/

vector<int> twoSum_new_1(const vector<int> &numbers, const int target)
{
    vector<int> result;
    for(size_t i = 0; i < numbers.size(); i++)
    {
        if(target > numbers[i])
        {
            int numberToFind = target - numbers[i];
            auto mindex = find(numbers.begin(), numbers.end(), numberToFind);
            if (mindex != numbers.end() && i != (mindex - numbers.begin()))
            {
                result.push_back(i);
                result.push_back(mindex - numbers.begin());
                break;
            }
        }
    }
    return result;
}
vector<int> twoSum_new_2(const vector<int> &numbers, const int target)
{
    vector<int> result;
    int low = 0, high = numbers.size() - 1;
    while(low < high)
    {
        if(numbers[low] + numbers[high] == target)
        {
            result.push_back(low + 1);
            result.push_back(high + 1);
            break;
        }
        else
        {
            numbers[low] + numbers[high] > target ? high-- : low++;
        }

    }
    return result;
}

int main()
{
    vector<int> input; //= {2, 7, 11, 15};
    input.push_back(3);
    input.push_back(2);
    input.push_back(4);
    //input.push_back(15);

    cout << "Input array: ";
    for(auto const &it : input)
    {
        cout << it << " "; 
    }

    cout << '\n';

    int target = 6;
    cout << "Target: " << target << '\n';

    //vector<int> result = twoSum_new_2(input, target);
    vector<int> result = twoSum_new_1(input, target);

    cout << "Result: [";

    for(auto const &it : result)
    {
        cout << it << " ";
    }
    cout << "]" << '\n';

    return 0;
}
