/// Naive solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                // Can't use same element twice
                if (i != j)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        // Make sure the element doesn't already exist
                        if (std::find(solution.begin(), solution.end(),i)==solution.end())
                        {
                            solution.push_back(i);
                            solution.push_back(j);
                        }
                    }
                }
            }
        }
        return solution;
    }
};

// Brute force solution O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            // You can start from i + 1 because there's only one unique solution
            for(int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                        vector<int> solution{i,j};
                        return solution;
                }
            }
        }
        throw;
    }
};

// O(n) - uses map, two passes
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map values to indices
        map<int,int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i ++)
        {
            auto found = hash.find(target - nums[i]);
            if (found != hash.end() && found->second != i)
            {
                vector<int> solution{i, hash[target - nums[i]]};
                return solution;
            }
        }
        
        throw;
    }
};

// O(n) - uses map, one pass
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map values to indices
        map<int,int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            auto found = hash.find(complement);
            if (found != hash.end())
            {
                vector<int> solution{i, hash[target - nums[i]]};
                return solution;
            }
            hash[nums[i]] = i;
        }
        throw;
    }
};

