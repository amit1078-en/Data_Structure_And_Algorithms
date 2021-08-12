/*
1185. Day of the Week
Easy

177

1568

Add to List

Share
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
Accepted
34,258
Submissions
56,609
*/


//code

bool flag  =true;
unordered_map<string,int> help;
int track[7];
class Solution {
public:
    Solution()
    {
        if(flag){
            int tot =0;
            flag = false;
            for(int year = 1971 ;year<=2100;year++)
            {
                
               //january
                for(int day = 1;day<=31;day++){
                    help[to_string(day)+"1"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                
                if(year%4==0 && (year%100!=0 || year%400==0))
                {
                 
                    //feb of leap year
                      for(int day = 1;day<=29;day++){
                    help[to_string(day)+"2"+to_string(year)] = tot;
                 track[tot%7] = tot%7;
                    tot++;
                }
                }
                else
                {
                     for(int day = 1;day<=28;day++){
                    help[to_string(day)+"2"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                }
                
                //march
                for(int day = 1;day<=31;day++)
                {
                    help[to_string(day)+"3"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                
                }
                //april
                for(int day = 1;day<=30;day++)
                {
                    help[to_string(day)+"4"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                //may
                for(int day = 1;day<=31;day++)
                {
                    help[to_string(day)+"5"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                
                //june
                for(int day = 1;day<=30;day++)
                {
                    help[to_string(day)+"6"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                //july
                for(int day = 1;day<=31;day++)
                {
                    help[to_string(day)+"7"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                //august
                for(int day = 1;day<=31;day++)
                {
                    help[to_string(day)+"8"+to_string(year)] = tot;
                    track[tot%7] = tot%7;
                    tot++;
                }
                
                //september
                 for(int day = 1;day<=30;day++)
                { help[to_string(day)+"9"+to_string(year)] = tot;
               track[tot%7] = tot%7;
                    tot++;
                    
                }
                
                //october
                 for(int day = 1;day<=31;day++)
                {
                     help[to_string(day)+"10"+to_string(year)] = tot;
                track[tot%7] = tot%7;
                    tot++;
                }
                
                //novomber 
                for(int day = 1;day<=30;day++)
                {
                     help[to_string(day)+"11"+to_string(year)] = tot;
                  track[tot%7] = tot%7;
                    tot++;
                }
                
                //december
                 for(int day = 1;day<=31;day++)
                {
                     help[to_string(day)+"12"+to_string(year)] = tot;
                     track[tot%7] = tot%7;
                    tot++;
                }
            }
        }
    }
    string get(int i)
    {
        switch(i){
           
            case 0:return "Friday";
            case 1:return "Saturday";
            case 2:return "Sunday";
            case 3:return "Monday";
            case 4:return "Tuesday";
            case 5:return "Wednesday";
            case 6:return "Thursday";
        }
        return "i";
    }
    string dayOfTheWeek(int day, int month, int year) {
        ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        return get(track[help[to_string(day)+to_string(month)+to_string(year)]%7]);
    }
};
