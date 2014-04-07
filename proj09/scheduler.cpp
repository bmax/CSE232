/* 
 * Project 9
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the scheduler cpp which controls the round robin scheduling for all jobs.
 *
 */
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> 
using std::sort;
using std::string;
using std::ifstream;
using std::cout;
using std::copy;
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::make_pair;
using std::pair;
#include <iomanip>
using std::setw;
using std::setfill;
#include "scheduler.h"
/*
 * func compare function for sort
 * takes a vector with pair<long,long> and compares the first and second to each other
 * returns bool 
 */
bool func(pair<long,long> first, pair<long,long> second)  {
  return (first.second < second.second);
}
/*
 * cmpfinal compare function for sort
 * takes a vector with Job datatype and compares the first and second arrival time to each other
 * returns bool 
 */
bool cmpfinal(Job first, Job second)  {
  return (first.get_arrival_time() < second.get_arrival_time());
}
/*
 * Scheduler load jobs
 * takes in a string that contains the jobs.txt and puts them into a nice sorted vector to pass into round_robin function
 * returns void 
 */
void Scheduler::load_jobs(string jobfile) {
  ifstream job(jobfile);
  vector<pair<long,long>> JobsByArrivalTime;
  map<long,long> JobsServiceTime; 
  int JobID,arrivalTime,serviceTime;
  /* add pairs of Job ID and Arrival time to vector */
  while (job >> JobID >> arrivalTime >> serviceTime) {
    JobsByArrivalTime.push_back(make_pair(JobID,arrivalTime));
    JobsServiceTime[JobID] = serviceTime;
  }
  /* Sort by ArrivalTime */
  sort(JobsByArrivalTime.begin(),JobsByArrivalTime.end(),&func);
  /* Call Job Class and add to vector of jobs */
  for (auto ele : JobsByArrivalTime) {
    Job j(ele.first,ele.second,JobsServiceTime[ele.first]); 
    ArrivalQueue.push_back(j);
  }
}
/*
 * Scheduler finished 
 * returns true only if both ArrivalQueue and ProcessingQueue are empty
 * returns bool 
 */
bool Scheduler::finished() {
  return (ArrivalQueue.empty() && ProcessingQueue.empty()) ; 
}
/*
 * Scheduler round_robin 
 * does all logic for the round robin scheduling process which consists of checking for new jobs and putting them into proccessqueue as well as counting time units.
 * returns void 
 */
void Scheduler::round_robin() {
  vector<Job> addProcess;
  long time_clock =0;
  while (!finished()) {
    for (auto theJob = ArrivalQueue.begin();theJob!=ArrivalQueue.end();theJob++) {
      if (theJob->get_arrival_time() <= time_clock) {
        ProcessingQueue.push_back(*theJob);
        theJob = --ArrivalQueue.erase(theJob);
      }
    }
    for ( auto process = ProcessingQueue.begin(); process!=ProcessingQueue.end();) {
      time_clock++;
      process->update_time_left(1);
      if (process->get_time_left() == 0) {
        process->set_finish_time(time_clock);
        //make a copy later for display
        finalQueue.push_back(*process);
      } else {
        addProcess.push_back(*process);
      }
      process = ProcessingQueue.erase(process);
    }
    for ( auto add = addProcess.begin();add!=addProcess.end();add++) {
      ProcessingQueue.push_back(*add);
    }
    addProcess.clear();
  }
}
/*
 * Scheduler display 
 * Displays the final results for round robin schedule
 * returns void 
 */
void Scheduler::display() {
  double avg;
  sort(finalQueue.begin(),finalQueue.end(),&cmpfinal);
  cout << "--------------------------------------------------------------------------"<<endl;
  cout << setw(10)<<"JobID "<<setw(30)<<" Arrival Time "<<setw(30)<<" Finish Time"<<endl;
  for ( auto i = finalQueue.begin();i!=finalQueue.end();i++) {
    avg+=i->get_finish_time()-i->get_arrival_time();
    cout <<setw(10)<<i->get_job_id()<<setw(25)<<i->get_arrival_time()<<setw(30)<<i->get_finish_time()<<endl;
  }
  cout << "Average amount of time to finish one job: "<<avg/finalQueue.size()<<" time units"<<endl;
  cout << "--------------------------------------------------------------------------"<<endl;
}
