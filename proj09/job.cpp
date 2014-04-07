/* 
 * Project 9
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the job cpp which controls the private data members for arrive_time, service_time, and job id.
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
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::make_pair;
using std::pair;
#include "job.h"
/*
 * get_job_id
 * returns int 
 */
int Job::get_job_id() {
  return jobID;
}
/*
 * get_arrival_time
 * returns int 
 */
int Job::get_arrival_time() {
  return arrivalTime; 
}
/*
 * get_time_left
 * returns int 
 */
int Job::get_time_left() {
  return timeLeft;
}
/*
 * uptime_time_left 
 * updates private data member timeLeft
 * returns void 
 */
void Job::update_time_left(int timeSpent) {
  timeLeft -= timeSpent; 
}
/*
 * set_finish_time
 * updates private data member timeFinished
 * returns void 
 */
void Job::set_finish_time(int final) {
  timeFinished = final;
}
/*
 * get_finish_time 
 * returns timeFinished
 * returns int 
 */
int Job::get_finish_time() {
  return timeFinished;
}
