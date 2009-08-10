#pragma once
#include <BWAPI.h>
#include <BWTA.h>
#include <Arbitrator.h>
#include <WorkerManager.h>
#include <SupplyManager.h>
#include <BuildManager.h>
#include <TechManager.h>
#include <UpgradeManager.h>
#include <BaseManager.h>
class BasicAIModule : public BWAPI::AIModule
{
public:
  virtual void onStart();
  virtual void onFrame();
  virtual void onRemoveUnit(BWAPI::Unit* unit);
  virtual bool onSendText(std::string text);
  void showStats(); //not part of BWAPI::AIModule
  void showPlayers();
  void showForces();
  BWTA::Region* home;
  BWTA::Region* enemy_base;
  bool analyzed;
  std::map<BWAPI::Unit*,BWAPI::UnitType> buildings;
  Arbitrator::Arbitrator<BWAPI::Unit*,double> arbitrator;
  WorkerManager* workerManager;
  SupplyManager* supplyManager;
  BuildManager* buildManager;
  TechManager* techManager;
  UpgradeManager* upgradeManager;
  BaseManager* baseManager;
  bool showManagerAssignments;
};