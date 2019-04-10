/// O(n^3) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Vector which contains all valid solution triplets
        vector<vector<int>> solutionSet;
        
        // Simplest approach: try all combinations of unique indices (3 for loops)
        for (int a_i = 0; a_i < nums.size(); a_i++)
        {
            for (int b_i = 0; b_i < nums.size(); b_i++)
            {
                for (int c_i = 0; c_i < nums.size(); c_i++)
                {
                    // Make sure we aren't using duplicate elements
                    if (a_i != b_i && b_i != c_i && a_i != c_i)
                    {
                        // Check if the elements add up to zero
                        if ((nums[a_i] + nums[b_i] + nums[c_i]) == 0)
                        {
                            // Order the elements
                            vector<int> solution{nums[a_i], nums[b_i], nums[c_i]};
                            std::sort (solution.begin(), solution.end());
                            
                            // Check if solution is not already in the solution set
                            if (std::find(solutionSet.begin(), solutionSet.end(),solution) == solutionSet.end())
                            {
                                // Add to solution set
                                solutionSet.push_back(solution);      
                            }
                        }
                    }
                }
            }
        }
        
        // return the solution set
        return solutionSet;
    }
};

/// Another O(n^3) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Vector which contains all valid solution triplets
        vector<vector<int>> solutionSet;
        
        // Start with the first index, then solve the remaining two sum problem
        for (int a_i = 0; a_i < nums.size(); a_i++)
        {
            // Calculate the two-sum of b+c
            int twoSum = 0 - nums[a_i];
            
            int a = nums[a_i];
            
            // Remove 'a' from the set
            nums.erase(nums.begin() + a_i);
            
            // Solve the two sum problem
            for (int b_i = 0; b_i < nums.size(); b_i++)
            {
                for (int c_i = 0; c_i < nums.size(); c_i++)
                {
                    if (b_i != c_i)
                    {
                        if (nums[b_i] + nums[c_i] == twoSum)
                        {
                            vector<int> solution{a, nums[b_i], nums[c_i]};
                            
                            std::sort (solution.begin(), solution.end());
                            
                            // Check if solution is not already in the solution set
                            if (std::find(solutionSet.begin(), solutionSet.end(),solution) == solutionSet.end())
                            {
                                // Add to solution set
                                solutionSet.push_back(solution);      
                            }
                        }
                    }
                }
            }
            
            // Put 'a' back
            nums.insert(nums.begin(), a);
        }
        
        // return the solution set
        return solutionSet;
    }
};