#ifndef __CLY_AADATA_H__
#define __CLY_AADATA_H__

#include <iostream>
#include <stdint.h>
#include "World.h"
#include "DatabaseEnv.h"

using namespace std;

class Player;

class AAData
{
private:
    AAData(){};
    ~AAData(){};
public:
    
    /*Character*/
    void AA_REP_Character_Juanxian(Player* player, CharacterDatabaseTransaction& trans);
    void AA_UPD_Character_Paihang(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Character_Instance(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Characters(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Systems(CharacterDatabaseTransaction& trans);
    void AA_REP_Characters_Dianfeng(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Characters_Douqi(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Characters_Junxian(Player *player, CharacterDatabaseTransaction& trans);
    
    void AA_REP_Player_Map_Value(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Player_Zone_Value(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Player_Area_Value(Player *player, CharacterDatabaseTransaction& trans);
    void AA_REP_Player_Instance_Value(Player *player, CharacterDatabaseTransaction& trans);
    
    void AA_REP_Map_Map_Value(CharacterDatabaseTransaction& trans);
    void AA_REP_Map_Zone_Value(CharacterDatabaseTransaction& trans);
    void AA_REP_Map_Area_Value(CharacterDatabaseTransaction& trans);
    void AA_REP_Map_Instance_Value(CharacterDatabaseTransaction& trans);
    
    void AA_REP_Item_Instance(CharacterDatabaseTransaction& trans);
    
    /*Account*/
    void AA_REP_Account(Player *player, LoginDatabaseTransaction& trans);
    
    static AAData* instance();
};

#define sAAData AAData::instance()

#endif
