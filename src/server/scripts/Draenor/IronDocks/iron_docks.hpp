
#include "Vehicle.h"
#include "GameObjectAI.h"

#ifndef IRON_DOCKS_HPP
# define IRON_DOCKS_HPP

Position const g_StunnedAdds[3] =
{
    { 6848.13f, -557.67f, 5.134f, 0.167117f },
    { 6856.76f, -570.57f, 4.741f, 1.034980f },
    { 6868.90f, -571.93f, 5.115f, 2.466761f }
};

Position const g_CheeringSoldiers[6] =
{
    /// Right
    { 6807.25f, -676.79f, 4.835f, 5.925450f },
    { 6806.89f, -683.76f, 4.997f, 5.921500f },
    { 6806.85f, -690.98f, 4.922f, 6.282260f },
    /// Left
    { 6841.64f, -683.00f, 4.835f, 3.288370f },
    { 6841.33f, -690.54f, 4.835f, 3.146160f },
    { 6846.15f, -696.68f, 4.914f, 2.999297f }
};

Position const g_PracticingWarriors[2] =
{
    { 6826.10f, -688.61f, 4.835f, 2.412430f },
    { 6823.62f, -686.06f, 4.835f, 5.513440f }
};

Position const g_CheeringSoldiers2[10] =
{
    { 6620.58f, -676.56f, 4.599f, 3.959485f },
    { 6623.64f, -680.51f, 4.601f, 3.774916f },
    { 6624.83f, -687.18f, 4.618f, 3.158379f },
    { 6623.84f, -694.58f, 4.607f, 2.514352f },
    { 6620.52f, -697.97f, 4.615f, 2.202549f },
    { 6612.53f, -698.07f, 4.660f, 1.637062f },
    { 6604.38f, -697.10f, 4.623f, 0.887006f },
    { 6601.72f, -693.82f, 4.629f, 0.741707f },
    { 6600.86f, -687.21f, 4.658f, 6.278765f },
    { 6603.08f, -678.38f, 4.626f, 5.607255f }
};

Position const g_PracticingWarriors2[2] =
{
    { 6614.71f, -688.92f, 4.763f, 2.389464f },
    { 6611.09f, -685.70f, 4.773f, 5.494924f }
};

Position const g_OutTeleportPos = { 8852.49f, 1364.35f, 97.0f, 1.581f };

Position const g_TrainSpawnPos  = { 6617.87f, -1200.69f, 9.801f, 3.089053f };

Position const g_TrainMovePos[2]  = 
{ 
    { 6503.10f, -1200.09f, 9.802f, 3.282539f },
    { 6407.73f, -1200.30f, 9.800f, 3.126752f }  
};

#define FriendlyFaction 35
#define HostileFaction 16
#define InvisibleDisplay 11686

static void DespawnCreaturesInArea(uint32 p_Entry, WorldObject* p_Object)
{
    std::list<Creature*> l_CreaturesList;
    GetCreatureListWithEntryInGrid(l_CreaturesList, p_Object, p_Entry, 2000.0f);

    if (l_CreaturesList.empty())
        return;

    for (std::list<Creature*>::iterator iter = l_CreaturesList.begin(); iter != l_CreaturesList.end(); ++iter)
        (*iter)->DespawnOrUnsummon();
}

enum eIronDocksDatas
{
    DataMountWolf = 99,
    /// Boss states
    DataNokgar = 0,
    DataGrimrail,
    DataOshir,
    DataSkulloc,
    DataGrimrailMakogg,
    DataGrimrailNoxx,
    DataGrimrailDuguru,
    DataTurret,
    /// Mini bosses
    DataDaruna,
    DataGwarnok,
    DataOlugar,
    /// Off topic boss
    DataZuggosh,
    DataKoramar,
    /// Datas
    DataSecondEvent,
    DataThirdEvent,
    /// Encounter Gates
    DataEncounterGateOshir,
};

enum eIronDocksCreatures
{
    /// Bosses and Etc
    CreatureFleshrenderNokgar            = 81305,  ///< http://www.wowhead.com/npc=81305/fleshrender-nokgar
    CreatureDreadfang                    = 81297,  ///< http://www.wowhead.com/npc=81297/dreadfang
    CreatureOshir                         = 79852,  ///< http://www.wowhead.com/npc=79852/oshir
    CreatureSkulloc                      = 83612,  ///< http://www.wowhead.com/npc=83612/skulloc
    CreatureTurret                       = 84215,
    CreatureZoggosh                      = 83616,  ///< http://www.wowhead.com/npc=83616/zoggosh
    CreatureKoramar                      = 83613,  ///< http://www.wowhead.com/npc=83613/koramar
    CreatureMakogg                       = 86231,  ///< http://www.wowhead.com/npc=80805/makogg-emberblade
    CreatureNox                          = 80808,  ///< http://www.wowhead.com/npc=80808/neesa-nox
    CreatureDuguru                       = 80816,
    /// Boss Adds
    CreatureGromkarFlameslinger          = 81279,  ///< http://www.wowhead.com/npc=81279/gromkar-flameslinger
    /// Mini bosses
    CreatureChampionDruna                = 81603,  ///< http://www.wowhead.com/npc=81603/champion-druna
    CreatureSiegemasterOlugar            = 83026,  ///< http://www.wowhead.com/npc=83026/siegemaster-olugar
    CreaturePitwardenGwarnok             = 84520,  ///< http://www.wowhead.com/npc=84520/pitwarden-gwarnok
    /// Trash
    CreatureGromkarFootSoldier           = 85997,  ///< http://www.wowhead.com/npc=85997/gromkar-footsoldier
    CreatureGromkarDeckhand              = 83762,  ///< http://www.wowhead.com/npc=83762/gromkar-deckhand
    /// Triggers
    CreatureArcheryTarget                = 79423,
    CreatureCannonBarrageTarget          = 99657,
    CreatureCannonBarrageTarget2         = 100981,
    CreatureCannonBarrageTarget3         = 100982,
    CreatureCannonBarrageInBossFight     = 354315,
    /// Custom
    CreatureGromkarFootSoldier2          = 859977, ///< http://www.wowhead.com/npc=85997/gromkar-footsoldier
    /// MISV
    CreatureIronStar                     = 81247,
    CreatureTrain                        = 83673
};

enum eIronDocksAchievements
{
    AchievementMilitaristicExpansionist    = 9083,
    AchievementHeroicIronDocks             = 9047,
    AchievementNormalIronDocks             = 9038
};

enum eIronDocksSpell
{
    SpellCannonBarrageAura = 168537
};

enum eIronDocksActions
{
    ActionActivateGrimrailEvent = 1,
    ActionActivateBridgeBombardmement,
    ActionUnloadPassengerShootIronStar,
    ActionAcitvateIronStar,
    ActionLeaveTurret,
    ActionBombardBridge,
    ActionFireArrows,
    ActionBurningArrowSingle,
    ActionBarbedArrowSingle,
    ActionTrainMoveWheels
};

enum eIronDocksScenario
{
    /// Normal/Heroic Mode
    /// ScenarioID
    IronDocksScenarioID         = 685,
    /// Bosses
    IronDocksNokgar             = 25108,
    IronDocksGrimrail           = 25109,
    IronDocksOshir              = 25110,
    IronDocksSkulloc            = 25111,
    /// Challenge Mode
    /// ScenarioID
    IronDocksChallengeID        = 426,
    IronDocksKillCount          = 44,
    IronDocksEnnemies           = 26362,

    DailyChallengeQuestID       = 37262,
    DailyChallengeKillCredit    = 79116
};

enum eIronDocksGameObject
{
    GameObjectChallengeModeDoor = 211989,
    GameObjectIronHordeCageDoor01 = 239229,
    GameObjectIronHordeCageDoor02 = 239218,
    GameObjectIronHordeCageDoor03 = 239221,
    GameObjectIronHordeCageDoor04 = 239219,
    GameObjectIronHordeCageDoor05 = 239230,
    GameObjectIronHordeCageDoor06 = 239216,
    GameObjectIronHordeCageDoor07 = 239227,
    GameObjectEncounterGateOshir  = 233817
};

#endif ///< IRON_DOCKS_HPP
