#include <iostream>
#include <airport.h>
#include "../linklist/queue.h"
using namespace std;

int main()
{
   unsigned int time_to_land = 5;
   unsigned int time_to_take_off = 15;
   double landing_probability = 0.1;
   double takeoff_probability = 0.08;
   unsigned int fuel_limit =20;
   unsigned int simulation_time = 100000;

   cout<<"time to take off "<<time_to_take_off<<endl;
   cout<<"time to land "<<time_to_land<<endl;
   cout<<"probability of landing "<<landing_probability<<endl;
   cout<<"probability of takeoff "<<takeoff_probability<<endl;
   cout<<"fuel: time to crash "<<fuel_limit<<endl;
   cout<<"total simulation time "<<simulation_time<<endl;


   landing_stripe machine;
   averager landing_wait_time;
   averager takingoff_wait_time;

   Queue<unsigned int> landing;
   Queue<unsigned int> takingoff;
   int count_of_crash=0;
   bool debug=false;
   for (unsigned int current_second = 1; current_second <= simulation_time; current_second++)
   {

       Bool_probability landing_plane(landing_probability);
       Bool_probability takingoff_plane(takeoff_probability);

       if(landing_plane.query())  //any landing plane added
       {
           landing.push(current_second);
       }

       if(takingoff_plane.query())   //any takeoff plane added
       {
           takingoff.push(current_second);
       }


       if(!machine.is_busy() && !landing.empty())  //landing check first
       {
           unsigned int next_landing=landing.front();
           landing.pop();
           if(current_second-next_landing>=fuel_limit) //check any crash plane
           {

               count_of_crash++;
           }else
           {

               landing_wait_time.next_number(current_second-next_landing);
               machine.set_time(time_to_land);
               machine.start();
           }

       }

       if(!machine.is_busy() && landing.empty() && !takingoff.empty())  //takeoff check
       {
            unsigned int next_takingoff=takingoff.front();

            takingoff.pop();
            takingoff_wait_time.next_number(current_second-next_takingoff);
            machine.set_time(time_to_take_off);
            machine.start();
       }

       machine.one_second();

   }
   int plane_in_landingqueue=0;
   int plane_in_takeoffqueue=0;
   while(!landing.empty())  //any left in the queue
   {
       landing.pop();
       plane_in_landingqueue++;
   }
   while(!takingoff.empty())
   {
       takingoff.pop();
       plane_in_takeoffqueue++;
   }

   if(landing_wait_time.count_of_plane()==0|| takingoff_wait_time.count_of_plane()==0) //error checking.
   {
       debug=true;
       cout<<"Error! Count of plane is 0 and not able to calculate the average"<<endl;
       assert(!debug);

   }


   cout<<". . . . . . . . . . . . . . . . . . . . . . . "<<endl;
   cout<<"landed plane "<<landing_wait_time.count_of_plane()<<endl;
   cout<<"took off "<<takingoff_wait_time.count_of_plane()<<endl;
   cout<<count_of_crash<<" plane crashed"<<endl;
   cout<<"Average waiting time to land:"<<landing_wait_time.average()<<endl;
   cout<<"Average waiting time to take off:"<<takingoff_wait_time.average()<<endl;
   cout<<"planes in landing queue "<<plane_in_landingqueue<<endl;
   cout<<"planes in take off queue "<<plane_in_takeoffqueue<<endl;



    return 0;
}
