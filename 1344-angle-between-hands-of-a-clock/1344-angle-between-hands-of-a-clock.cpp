class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = 0, minute_angle = 0, diff;
        
        //30 degrees for every hour
        if(hour != 12)
            hour_angle = hour * 30;
        
        //6 degrees for every minute
        minute_angle = minutes * 6;
        
        //diffrential between hour and minute hands
        hour_angle += (minutes / 2.0);
        
        diff = abs(hour_angle - minute_angle);
        if(diff > 180)
            diff = 360 - diff;
        return diff;
    }
};