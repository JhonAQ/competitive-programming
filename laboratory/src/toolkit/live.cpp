#include <iostream>
#include <vector>
#include <string>
#include <libfswatch>
#include "../core/core.h"
   
using namespace std;
using namespace fsw;

const string outputFile = "./a.out";
const string compileCommand = "g++ -std=c++17 -o " + outputFile;

void executeFile(string path) {
    int statusCode = executeWithCode(path.c_str());
    if(!statusCode) {
        cout << "Invalid status code of the compilment" << "\n";
        return;
    }

    cout << "File was compiled to: " + outputFile << "\n";

    int exitStatus = liveLog(compileCommand);
    if(!exitStatus){
        cout << "Invalid pipe when reading was provided" << "\n";
        return;
    }

    cout << "Livelog exited succefully" << "\n";
}

int EVENT_processReciveEvents(const vector<event>& events, void *) {
    for (int i = 0; i < events.size(); i++)
    {
        auto gotEvent = events[i];
        auto flags = events[i].get_flags();
        bool doesFlagsOk = false;

        for(int j = 0; j < flags.size(); j++) {
            if(flags[i] == fsw_event_flag.Updated){
                doesFlagsOk = true;
            }else {
                doesFlagsOk = false;
                break;
            }
        }

        if(!doesFlagsOk) continue;

        string path = gotEvent.get_path();
        executeFile(path);    
    }
}

void startMonitor(vector<int> listenPaths) {
    monitor *active_monitor =
    monitor_factory::create_monitor(fsw_monitor_type::system_default_monitor_type,
                                    listenPaths,
                                    EVENT_processReciveEvents);

    // small configuration
    active_monitor->set_properties(monitor_properties);
    active_monitor->set_allow_overflow(allow_overflow);
    active_monitor->set_latency(latency);
    active_monitor->set_recursive(recursive);
    active_monitor->set_directory_only(directory_only);
    active_monitor->set_event_type_filters(event_filters);
    active_monitor->set_filters(filters);
    active_monitor->set_follow_symlinks(follow_symlinks);
    active_monitor->set_watch_access(watch_access);

    active_monitor->start();
}
   
int main(int argc, char** argv) {
    vector<int> paths(argc);
    for(int i = 0; i < argc; i++) paths[i] = argv[i];

    startMonitor(paths);
}