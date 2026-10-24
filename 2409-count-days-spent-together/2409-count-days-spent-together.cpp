class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // convert input strings to integers so that we can calculate days
        int arrMonA = 10 * (arriveAlice[0] - '0') + arriveAlice[1] - '0';
        int arrMonB = 10 * (arriveBob[0] - '0') + arriveBob[1] - '0';
        int arrDayA = 10 * (arriveAlice[3] - '0') + arriveAlice[4] - '0';
        int arrDayB = 10 * (arriveBob[3] - '0') + arriveBob[4] - '0';
        int leaveMonA = 10 * (leaveAlice[0] - '0') + leaveAlice[1] - '0';
        int leaveMonB = 10 * (leaveBob[0] - '0') + leaveBob[1] - '0';
        int leaveDayA = 10 * (leaveAlice[3] - '0') + leaveAlice[4] - '0';
        int leaveDayB = 10 * (leaveBob[3] - '0') + leaveBob[4] - '0';
        
        // derive start date and end date they both stay in Rome
        int arrM, arrD, leaveM, leaveD;
        
        if (arrMonA == arrMonB) {
            arrM = arrMonA;
            arrD = max(arrDayA, arrDayB);
        }
        else if (arrMonA < arrMonB) {
            arrM = arrMonB;
            arrD = arrDayB;
        }
        else {
            arrM = arrMonA;
            arrD = arrDayA;
        }

        if (leaveMonA == leaveMonB) {
            leaveM = leaveMonA;
            leaveD = min(leaveDayA, leaveDayB);
        }
        else if (leaveMonA < leaveMonB) {
            leaveM = leaveMonA;
            leaveD = leaveDayA;
        }
        else {
            leaveM = leaveMonB;
            leaveD = leaveDayB;
        }
        
        // calculate the answer
        if (arrM == leaveM) {
            return max(leaveD - arrD + 1, 0);
        }
        else if (arrM > leaveM) return 0;
    
        int ans = 0;
        while (arrM != leaveM) {
            ans += monthDay[arrM - 1] - arrD + 1;
            arrM++;
            arrD = 1;
        }
        ans += leaveD;
        return ans; 
    }
};