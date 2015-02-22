
#ifndef _DISTANCE_PARENT
#define _DISTANCE_PARENT

class DistanceParent {
public:
	   int weight;
       int parentNodeIndex;
       DistanceParent(int index, int wt):parentNodeIndex(index),weight(wt) { }
};


#endif 