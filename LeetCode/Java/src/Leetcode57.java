/**
 * Created by ganjun on 2017/9/26.
 */
import  java.util.*;
class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}
public class Leetcode57 {
    /**
     * Definition for an interval.*/



    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> ret = new ArrayList<>();
        if(intervals.size() == 0){
            ret.add(newInterval);
            return ret;
        }
        if(newInterval.end < intervals.get(0).start){
            ret.add(newInterval);
            for(Interval val:intervals){
                ret.add(val);
            }
        }
        else if(newInterval.start > intervals.get(intervals.size()-1).end){
            for(Interval val:intervals){
                ret.add(val);
            }
            ret.add(newInterval);
        }
        else{
            int left = 100000000 , right = 100000000;
            for(int i=0 ; i<intervals.size() ; i++){
                Interval val = intervals.get(i);
                if(i == 0 && val.start > newInterval.end) ret.add(newInterval);
                else if(i>0 && (val.start > newInterval.end) && (intervals.get(i-1).end < newInterval.start)) ret.add(newInterval);
                if(val.start > newInterval.end || val.end < newInterval.start){
                    if(left < 100000000){
                        ret.add(new Interval(left,right));
                        left = 100000000;
                    }
                    ret.add(val);
                }
                else{
                    if(val.start <= newInterval.start){
                        left = Math.min(left,val.start);
                    }else{
                        left = Math.min(left,newInterval.start);
                    }
                    right = Math.max(val.end , newInterval.end);
                }
            }
            if(left < 100000000){
                ret.add(new Interval(left,right));
                left = 100000000;
            }
        }
        return ret;
    }

    public static void main(String [] args){
        Interval a = new Interval(1,3);
        Interval b = new Interval(6,9);
        Interval c = new Interval(6,7);
        Interval d = new Interval(8,10);
        Interval e = new Interval(12,16);
        Leetcode57 sol = new Leetcode57();
        List<Interval> lists = new ArrayList<Interval>();
        lists.add(a);
        lists.add(b);
//        lists.add(c);
//        lists.add(d);
//        lists.add(e);
        List<Interval> ret = sol.insert(lists, new Interval(2,5));
        for(Interval val: ret){
            System.out.println(val.start+" "+val.end);
        }
    }
}
