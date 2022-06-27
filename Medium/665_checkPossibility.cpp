class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int check = 0;
        for (int i = 1; i < nums.size(); i++)
        {

            // decreasing sequence found
            if (nums[i] < nums[i - 1])
            {

                // if count after increasing becomes more than 1 then false
                if (++check > 1)
                    return false;

                // in case of the 2nd element as i[1] < i[0] so make i[0] = i[1]
                // if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                if (i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];

                // if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                else
                    nums[i] = nums[i - 1];
            }
        }

        return true;
    }
};

// easy question but difficult to handle cases
// 2 cases

// case 1: num[i-2] <= nums[i]
//         5
// 	      / \
// 	     /    4------                      4 __ 4
//      /                                 /
//     3-------------     ->             3               Decrease middle element to right one
//    /                                 /
//   2                                 2
//  /                                 /
// 1                                 1

//         5
// 	      / \
// 	     /   \                   
//      /     \                           
//     3-------3-------     ->           3 __ 3 __ 3        Decrease  middle element to right and left one
//    /                                 /
//   2                                 2
//  /                                 /
// 1                                 1

// case 2: nums[i-2] > nums[i]
//         5                                  5 __ 5 
// 	      / \                                /
// 	     4---\---------                     4
//      /     \                            /
//     3       3-------      ->           3                  Increse right element to middle one
//    /                                  /
//   2                                  2
//  /                                  /
// 1                                  1