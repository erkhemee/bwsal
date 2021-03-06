#pragma once
#include <BWAPI.h>
#include <BWTA.h>
#include <BWSAL/Arbitrator.h>
#include <BWSAL/Base.h>
#include <BWSAL/BaseManager.h>
#include <BWSAL/BFSBuildingPlacer.h>
#include <BWSAL/BorderManager.h>
#include <BWSAL/BuildEvent.h>
#include <BWSAL/BuildEventTimeline.h>
#include <BWSAL/BuildingPlacer.h>
#include <BWSAL/BuildState.h>
#include <BWSAL/BuildType.h>
#include <BWSAL/BuildUnit.h>
#include <BWSAL/BuildOrderManager.h>
#include <BWSAL/BuildUnitManager.h>
#include <BWSAL/Controller.h>
#include <BWSAL/DefenseManager.h>
#include <BWSAL/Heap.h>
#include <BWSAL/InformationManager.h>
#include <BWSAL/MacroTask.h>
#include <BWSAL/MetaUnit.h>
#include <BWSAL/MetaUnitVariable.h>
#include <BWSAL/RectangleArray.h>
#include <BWSAL/ReservedMap.h>
#include <BWSAL/ScoutManager.h>
#include <BWSAL/SupplyManager.h>
#include <BWSAL/Task.h>
#include <BWSAL/TaskExecutor.h>
#include <BWSAL/TaskScheduler.h>
#include <BWSAL/TaskState.h>
#include <BWSAL/Types.h>
#include <BWSAL/UnitGroup.h>
#include <BWSAL/UnitGroupManager.h>
#include <BWSAL/Util.h>
#include <BWSAL/WorkerManager.h>

namespace BWSAL
{
  void BWSAL_init();
}