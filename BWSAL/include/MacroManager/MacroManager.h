#pragma once
#include <BWAPI.h>
#include <Arbitrator.h>
class TaskStream;
class MacroManager
{
  public:
    MacroManager(Arbitrator::Arbitrator<BWAPI::Unit*,double>* arbitrator);
    void update();

    std::list< TaskStream > taskStreams;
    TaskStream* getTaskStream(BWAPI::Unit* unit);
private:
    std::map< BWAPI::Unit*, TaskStream* > unitToTaskStream;
};
extern MacroManager* TheMacroManager;
extern Arbitrator::Arbitrator<BWAPI::Unit*,double>* TheArbitrator;