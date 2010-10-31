#include <UnitCompositionProducer.h>
#include <BasicTaskExecutor.h>
#include <SpiralBuildingPlacer.h>
#include <UnitPump.h>
#include <TerminateIfWorkerLost.h>
#include <TerminateIfEmpty.h>
#include <BasicWorkerFinder.h>
using namespace BWAPI;
using namespace std;
UnitCompositionProducer::UnitCompositionProducer(BWAPI::UnitType workerType)
{
  this->workerType=workerType;
}
void UnitCompositionProducer::attached(TaskStream* ts)
{
  streams.insert(ts);
}
void UnitCompositionProducer::detached(TaskStream* ts)
{
  streams.erase(ts);
}
void UnitCompositionProducer::update()
{
  std::set<Unit*> units=Broodwar->self()->getUnits();
  for each(Unit* u in units)
  {
    if (u->getType()==workerType && u->exists() && u->isCompleted())
    {
      TaskStream* ts = TheMacroManager->getTaskStream(u);
      if (ts==NULL)
      {
        ts = new TaskStream();
        TheMacroManager->taskStreams.push_back(ts);
        ts->setWorker(u);
        ts->attach(BasicTaskExecutor::getInstance(),false);
        ts->attach(this,false);
        ts->attach(new TerminateIfWorkerLost(),true);
      }
    }
  }

  actualUnitCounts.clear();
  for each(std::pair<UnitType, double> t in unitCompositionWeights)
  {
    actualUnitCounts[t.first]=TheMacroManager->uctl.getFinalCount(t.first);
  }
  for each(TaskStream* ts in streams)
  {
    if (ts->getTask()==NULL)
    {
      UnitType t=getNextUnitType();
      ts->setTask(Task(t));
      actualUnitCounts[t]++;
    }
  }
  for each(TaskStream* ts in streams)
  {
    if (ts->getNextTask()==NULL)
    {
      UnitType t=getNextUnitType();
      ts->setNextTask(Task(t));
      actualUnitCounts[t]++;
    }
  }
}
UnitType UnitCompositionProducer::getNextUnitType()
{
  double aTc = 0;
  double cTc = 0;
  for each(std::pair<UnitType, double> t in unitCompositionWeights)
  {
    aTc+=actualUnitCounts[t.first]*t.second;
    cTc+=t.second*t.second;
  }
  double r= aTc/cTc;
  for each(std::pair<UnitType, double> t in unitCompositionWeights)
  {
    desiredUnitCounts[t.first]=t.second*r;
  }
  double maxDiff=-1;
  UnitType nextType;
  for each(std::pair<UnitType, double> t in unitCompositionWeights)
  {
    double d=desiredUnitCounts[t.first]-actualUnitCounts[t.first];
    if (d>maxDiff)
    {
      maxDiff=d;
      nextType=t.first;
    }
  }
  return nextType;
}
void UnitCompositionProducer::setUnitWeight(BWAPI::UnitType t, double weight)
{
  unitCompositionWeights[t]=weight;
}