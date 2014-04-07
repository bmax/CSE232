/* 
 * Project 9
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the job cpp which controls the private data members for arrive_time, service_time, and job id.
 *
 */
#ifndef JOB_H
#define JOB_H

class Job {
  private:
    int jobID, arrivalTime,timeLeft,timeFinished;
  public:
    /*
     * default costructor for Job
     */
    Job();
    /*
     * costructor for Job
     * takes in three ints and set's private datamembers
     */
    Job(int j, int a, int s) : jobID(j), arrivalTime(a), timeLeft(s) {};
    /*
     * get_job_id
     * returns int 
     */
    int get_job_id();
    /*
     * get_arrival_time
     * returns int 
     */
    int get_arrival_time();
    /*
     * get_time_left
     * returns int 
     */
    int get_time_left();
    /*
     * uptime_time_left 
     * updates private data member timeLeft
     * returns void 
     */
    void update_time_left(int);
    /*
     * set_finish_time
     * updates private data member timeFinished
     * returns void 
     */
    void set_finish_time(int);
    /*
     * get_finish_time 
     * returns timeFinished
     * returns int 
     */
    int get_finish_time();
};
#endif
