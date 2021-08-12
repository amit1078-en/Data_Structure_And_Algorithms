/*
Circular tour 
Medium Accuracy: 33.91% Submissions: 64591 Points: 4
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Your Task:
Your task is to complete the function tour() which takes the required data as inputs and returns an integer denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). If there exists multiple such starting points, then the function must return the first one out of those. (return -1 otherwise)

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)

Constraints:
2 = N = 10000
1 = petrol, distance = 1000
*/

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        //considering first petrol pump as a starting point.
        int start = 0;
        int end=1;
        int cur_pet = p[start].petrol-p[start].distance;
        
        //we run a loop while all petrol pumps are not visited and we have 
        //reached first petrol pump again with 0 or more petrol.
        while(end!=start or cur_pet <0)
        {
            //if current amount of petrol in truck becomes less than 0,
            //then remove the starting petrol pump from tour.
            while(cur_pet<0 and  start!=end)
            {
                //removing starting petrol pump and changing starting point. 
                cur_pet -=p[start].petrol-p[start].distance;
                start=(start+1)%n;
                
                //if 0 is being considered as start again, then there 
                //is no possible solution.
                if(start==0)
                    return -1;
            }
            //adding a petrol pump to current tour.
            cur_pet +=p[end].petrol - p[end].distance;
            end=(end+1)%n;
        }
        //returning starting point. 
        return start;
    }
};
