/* 
 * Project 9
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the scheduler cpp which controls the round robin scheduling for all jobs.
 *
 */
#ifndef SCHEDULER_H 
#define SCHEDULER_H 
#include "job.h"
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::make_pair;
using std::pair;
class Scheduler {
  private:
    vector<Job> ArrivalQueue;
    vector<Job> ProcessingQueue;
    vector<Job> finalQueue;
  public:
/*
 * Scheduler load jobs
 * takes in a string that contains the jobs.txt and puts them into a nice sorted vector to pass into round_robin function
 * returns void 
 */
    void load_jobs(string);
/*
 * Scheduler round_robin 
 * does all logic for the round robin scheduling process which consists of checking for new jobs and putting them into proccessqueue as well as counting time units.
 * returns void 
 */
    void round_robin();
/*
 * Scheduler finished 
 * returns true only if both ArrivalQueue and ProcessingQueue are empty
 * returns bool 
 */
    bool finished();
/*
 * Scheduler display 
 * Displays the final results for round robin schedule
 * returns void 
 */
    void display();
};
#endif
