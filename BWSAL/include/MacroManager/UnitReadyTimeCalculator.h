#pragma once
#include <BWAPI.h>
#include <map>
#include <Task.h>
namespace UnitReadyTimeStatus
{
  enum Enum
  {
    Waiting_For_Worker_To_Be_Ready,
    Waiting_For_Required_Units,
    Waiting_For_Required_Tech,
    Waiting_For_Required_Upgrade,
    Waiting_For_Supply,
    Waiting_For_Gas,
    Waiting_For_Minerals
  };
};
class UnitReadyTimeCalculator
{
  public:
    static void init();
    static int getReadyTime(BWAPI::Unit* unit, bool considerTasks = false);
    static int getReadyTime(BWAPI::Unit* unit, const Task &task, UnitReadyTimeStatus::Enum &reason, bool considerResources = true, bool considerTasks = false);
    static std::set<BWAPI::UnitType> getPossibleUnitTypes(BWAPI::Unit* unit, int time = BWAPI::Broodwar->getFrameCount(), bool considerResources = true, bool considerTasks = false);
//    static std::set<BWAPI::UpgradeType> getPossibleUpgradeTypes(BWAPI::Unit* unit, int time = BWAPI::Broodwar->getFrameCount());
//    static std::set<BWAPI::TechType> getPossibleTechTypes(BWAPI::Unit* unit, int time = BWAPI::Broodwar->getFrameCount());
};