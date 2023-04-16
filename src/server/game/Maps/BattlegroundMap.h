//#pragma once
//
//#include "Common.h"
//#include "Map.h"
//
//class Battleground;
//enum Difficulty : uint8;
//
//class BattlegroundMap : public Map
//{
//    Battleground* m_bg;
//public:
//    //BattlegroundMap(uint32 id, time_t, uint32 instanceId, Map* parent, Difficulty difficulty);
//    ~BattlegroundMap() override;
//
//    bool AddPlayerToMap(Player*, bool initPlayer = true) override;
//    void RemovePlayerFromMap(Player*, bool) override;
//    //bool CanEnter(Player* player) override;
//    void SetUnload();
//    void RemoveAllPlayers() override;
//    void InitVisibilityDistance() override;
//    Battleground* GetBG();
//    void SetBG(Battleground* bg);
//
//    /*void Update(const uint32 diff) override;
//    void InsureCommander(uint8 bgType) override;
//    void InitCommander() override;
//    void ResetCommander() override;
//    void ReadyCommander() override;
//    void StartCommander() override;*/
//    CommandBG* GetCommander(TeamId team);
//    CommandBG* m_pAllianceCommander{ nullptr };
//    CommandBG* m_pHordeCommander{ nullptr };
//};
