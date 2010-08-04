/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "obsidian_sanctum.h"

enum eEnums
{
    //Sartharion Yell
    SAY_SARTHARION_AGGRO                        = -1615018,
    SAY_SARTHARION_BERSERK                      = -1615019,
    SAY_SARTHARION_BREATH                       = -1615020,
    SAY_SARTHARION_CALL_SHADRON                 = -1615021,
    SAY_SARTHARION_CALL_TENEBRON                = -1615022,
    SAY_SARTHARION_CALL_VESPERON                = -1615023,
    SAY_SARTHARION_DEATH                        = -1615024,
    SAY_SARTHARION_SPECIAL_1                    = -1615025,
    SAY_SARTHARION_SPECIAL_2                    = -1615026,
    SAY_SARTHARION_SPECIAL_3                    = -1615027,
    SAY_SARTHARION_SPECIAL_4                    = -1615028,
    SAY_SARTHARION_SLAY_1                       = -1615029,
    SAY_SARTHARION_SLAY_2                       = -1615030,
    SAY_SARTHARION_SLAY_3                       = -1615031,

    WHISPER_LAVA_CHURN                          = -1615032,

    WHISPER_SHADRON_DICIPLE                     = -1615008,
    WHISPER_VESPERON_DICIPLE                    = -1615041,
    WHISPER_HATCH_EGGS                          = -1615017,
    WHISPER_OPEN_PORTAL                         = -1615042, // whisper, shared by two dragons

    //Sartharion Spells
    SPELL_BERSERK                               = 61632,    // Increases the caster's attack speed by 150% and all damage it deals by 500% for 5 min.
    SPELL_CLEAVE                                = 56909,    // Inflicts 35% weapon damage to an enemy and its nearest allies, affecting up to 10 targets.
    SPELL_FLAME_BREATH                          = 56908,    // Inflicts 8750 to 11250 Fire damage to enemies in a cone in front of the caster.
    SPELL_FLAME_BREATH_H                        = 58956,    // Inflicts 10938 to 14062 Fire damage to enemies in a cone in front of the caster.
    SPELL_TAIL_LASH                             = 56910,    // A sweeping tail strike hits all enemies behind the caster, inflicting 3063 to 3937 damage and stunning them for 2 sec.
    SPELL_TAIL_LASH_H                           = 58957,    // A sweeping tail strike hits all enemies behind the caster, inflicting 4375 to 5625 damage and stunning them for 2 sec.
    SPELL_WILL_OF_SARTHARION                    = 61254,    // Sartharion's presence bolsters the resolve of the Twilight Drakes, increasing their total health by 25%. This effect also increases Sartharion's health by 25%.
    SPELL_LAVA_STRIKE                           = 57571,    // (Real spell casted should be 57578) 57571 then trigger visual missile, then summon Lava Blaze on impact(spell 57572)
    SPELL_TWILIGHT_REVENGE                      = 60639,
    NPC_FIRE_CYCLONE                            = 30648,

    SPELL_PYROBUFFET                            = 56916,    // currently used for hard enrage after 15 minutes
    SPELL_PYROBUFFET_RANGE                      = 58907,    // possibly used when player get too far away from dummy creatures (2x Creature entry 30494)

    SPELL_TWILIGHT_SHIFT_ENTER                  = 57620,    // enter phase. Player get this when click GO
    SPELL_TWILIGHT_SHIFT                        = 57874,    // Twilight Shift Aura
    SPELL_TWILIGHT_SHIFT_REMOVAL                = 61187,    // leave phase
    SPELL_TWILIGHT_SHIFT_REMOVAL_ALL            = 61190,    // leave phase (probably version to make all leave)

    //Mini bosses common spells
    SPELL_TWILIGHT_RESIDUE                      = 61885,    // makes immune to shadow damage, applied when leave phase

    //Miniboses (Vesperon, Shadron, Tenebron)
    SPELL_SHADOW_BREATH_H                       = 59126,    // Inflicts 8788 to 10212 Fire damage to enemies in a cone in front of the caster.
    SPELL_SHADOW_BREATH                         = 57570,    // Inflicts 6938 to 8062 Fire damage to enemies in a cone in front of the caster.

    SPELL_SHADOW_FISSURE_H                      = 59127,    // Deals 9488 to 13512 Shadow damage to any enemy within the Shadow fissure after 5 sec.
    SPELL_SHADOW_FISSURE                        = 57579,    // Deals 6188 to 8812 Shadow damage to any enemy within the Shadow fissure after 5 sec.

    //Vesperon
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_VESPERON                     = 31219,    // Acolyte of Vesperon
    SPELL_POWER_OF_VESPERON                     = 61251,    // Vesperon's presence decreases the maximum health of all enemies by 25%.
    SPELL_TWILIGHT_TORMENT_VESP                 = 57948,    // (Shadow only) trigger 57935 then 57988
    SPELL_TWILIGHT_TORMENT_VESP_ACO             = 58853,    // (Fire and Shadow) trigger 58835 then 57988

    //Shadron
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_SHADRON                      = 31218,    // Acolyte of Shadron
    SPELL_POWER_OF_SHADRON                      = 58105,    // Shadron's presence increases Fire damage taken by all enemies by 100%.
    SPELL_GIFT_OF_TWILIGTH_SHA                  = 57835,    // TARGET_SCRIPT shadron
    SPELL_GIFT_OF_TWILIGTH_SAR                  = 58766,    // TARGET_SCRIPT sartharion
    SPELL_VOID_BLAST                            = 57581,    // Twilight Fissure
    SPELL_VOID_BLAST_H                          = 59128,

    //Tenebron
    //in the portal spawns 6 eggs, if not killed in time (approx. 20s)  they will hatch,  whelps can cast 60708
    SPELL_POWER_OF_TENEBRON                     = 61248,    // Tenebron's presence increases Shadow damage taken by all enemies by 100%.
    //Tenebron, dummy spell
    SPELL_SUMMON_TWILIGHT_WHELP                 = 58035,    // doesn't work, will spawn NPC_TWILIGHT_WHELP
    SPELL_SUMMON_SARTHARION_TWILIGHT_WHELP      = 58826,    // doesn't work, will spawn NPC_SHARTHARION_TWILIGHT_WHELP

    SPELL_HATCH_EGGS_H                          = 59189,
    SPELL_HATCH_EGGS                            = 58542,
    SPELL_HATCH_EGGS_EFFECT_H                   = 59190,
    SPELL_HATCH_EGGS_EFFECT                     = 58685,
    NPC_TWILIHT_WHELP                           = 31214,
    NPC_TWILIGHT_EGG                            = 30882,
    NPC_SARTHARION_TWILIGHT_EGG                 = 31204,

    //Whelps
    NPC_TWILIGHT_WHELP                          = 30890,
    NPC_SHARTHARION_TWILIGHT_WHELP              = 31214,
    SPELL_FADE_ARMOR                            = 60708,    // Reduces the armor of an enemy by 1500 for 15s

    //flame tsunami
    SPELL_FLAME_TSUNAMI                         = 57494,    // the visual dummy
    SPELL_FLAME_TSUNAMI_LEAP                    = 60241,    // SPELL_EFFECT_138 some leap effect, causing caster to move in direction

    SPELL_FLAME_TSUNAMI_DMG_AURA                = 57491,    // periodic damage, npc has this aura
    SPELL_FLAME_TSUNAMI_BUFF                    = 60430,
    

    NPC_FLAME_TSUNAMI                           = 30616,    // for the flame waves
    NPC_LAVA_BLAZE                              = 30643,    // adds spawning from flame strike

    //using these custom points for dragons start and end
    POINT_ID_INIT                               = 100,
    POINT_ID_LAND                               = 200,

    //Achievements
    ACHIEV_TWILIGHT_ASSIST                      = 2049,
    H_ACHIEV_TWILIGHT_ASSIST                    = 2052,
    ACHIEV_TWILIGHT_DUO                         = 2050,
    H_ACHIEV_TWILIGHT_DUO                       = 2053,
    ACHIEV_TWILIGHT_ZONE                        = 2051,
    H_ACHIEV_TWILIGHT_ZONE                      = 2054
};

#define DATA_CAN_LOOT   0

struct Waypoint
{
    float m_fX, m_fY, m_fZ;
};

struct Location
{
    float x,y,z;
};
struct Locations
{
    float x,y,z;
};

//each dragons special points. First where fly to before connect to connon, second where land point is.
Waypoint m_aTene[]=
{
    {3212.854, 575.597, 109.856},                           //init
    {3246.425, 565.367, 61.249}                             //end
};

Waypoint m_aShad[]=
{
    {3293.238, 472.223, 106.968},
    {3271.669, 526.907, 61.931}
};

Waypoint m_aVesp[]=
{
    {3193.310, 472.861, 102.697},
    {3227.268, 533.238, 59.995}
};

#define MAX_WAYPOINT 6
//points around raid "isle", counter clockwise. should probably be adjusted to be more alike
Waypoint m_aDragonCommon[MAX_WAYPOINT]=
{
    {3214.012, 468.932, 98.652},
    {3244.950, 468.427, 98.652},
    {3283.520, 496.869, 98.652},
    {3287.316, 555.875, 98.652},
    {3250.479, 585.827, 98.652},
    {3209.969, 566.523, 98.652}
};

static Location FlameRight1Spawn = { 3200.00, 573.211, 57.1551 };
static Location FlameRight1Direction = { 3289.28, 573.211, 57.1551 };
static Location FlameRight2Spawn = { 3200.00, 532.211, 57.1551 };
static Location FlameRight2Direction = { 3289.28, 532.211, 57.1551 };
static Location FlameRight3Spawn = { 3200.00, 491.211, 57.1551 };
static Location FlameRight3Direction = { 3289.28, 491.211, 57.1551 };
static Location FlameLeft1Spawn = { 3289.28, 511.711, 57.1551 };
static Location FlameLeft1Direction = { 3200.00, 511.711, 57.1551 };
static Location FlameLeft2Spawn = { 3289.28, 552.711, 57.1551 };
static Location FlameLeft2Direction = { 3200.00, 552.711, 57.1551 };

static Location AcolyteofShadron = { 3363.92, 534.703, 97.2683 };
static Location AcolyteofShadron2 = { 3246.57, 551.263, 58.6164 };
static Location AcolyteofVesperon = { 3145.68, 520.71, 89.7 };
static Location AcolyteofVesperon2 = { 3246.57, 551.263, 58.6164 };
Locations TwilightEggs[] =
{
    {3219.28, 669.121 , 88.5549},
    {3221.55, 682.852 , 90.5361},
    {3239.77, 685.94 , 90.3168},
    {3250.33, 669.749 , 88.7637},
    {3246.6, 642.365 , 84.8752},
    {3233.68, 653.117 , 85.7051}
};
Locations TwilightEggsSarth[] =
{
    {3252.73, 515.762 , 58.5501},
    {3256.56, 521.119 , 58.6061},
    {3255.63, 527.513 , 58.7568},
    {3264.90, 525.865 , 58.6436},
    {3264.26, 516.364 , 58.8011},
    {3257.54, 502.285 , 58.2077}
};

/*######
## Boss Sartharion
######*/

struct boss_sartharionAI : public ScriptedAI
{
    boss_sartharionAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool m_bIsBerserk;
    bool m_bIsSoftEnraged;

    uint32 m_uiEnrageTimer;
    bool m_bIsHardEnraged;

    uint32 m_uiTenebronTimer;
    uint32 m_uiShadronTimer;
    uint32 m_uiVesperonTimer;

    uint32 m_uiFlameTsunamiTimer;
    uint32 m_uiFlameBreathTimer;
    uint32 m_uiTailSweepTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiLavaStrikeTimer;

    bool m_bHasCalledTenebron;
    bool m_bHasCalledShadron;
    bool m_bHasCalledVesperon;

    uint32 achievProgress;

    void Reset()
    {
        m_bIsBerserk = false;
        m_bIsSoftEnraged = false;

        m_uiEnrageTimer = 15*MINUTE*IN_MILLISECONDS;
        m_bIsHardEnraged = false;

        m_uiTenebronTimer = 30000;
        m_uiShadronTimer = 75000;
        m_uiVesperonTimer = 120000;

        m_uiFlameTsunamiTimer = 30000;
        m_uiFlameBreathTimer = 20000;
        m_uiTailSweepTimer = 20000;
        m_uiCleaveTimer = 7000;
        m_uiLavaStrikeTimer = 5000;

        m_bHasCalledTenebron = false;
        m_bHasCalledShadron = false;
        m_bHasCalledVesperon = false;

        if (me->HasAura(SPELL_TWILIGHT_REVENGE))
            me->RemoveAurasDueToSpell(SPELL_TWILIGHT_REVENGE);

        me->ResetLootMode();
        me->SetHomePosition(3246.57, 551.263, 58.6164, 4.66003);

        achievProgress = 0;

        // Drakes respawning system
        if (pInstance)
        {
            Creature* pTenebron = Unit::GetCreature(*me, pInstance->GetData64(DATA_TENEBRON));
            Creature* pShadron = Unit::GetCreature(*me, pInstance->GetData64(DATA_SHADRON));
            Creature* pVesperon = Unit::GetCreature(*me, pInstance->GetData64(DATA_VESPERON));
            if (pTenebron)
            {
                pTenebron->SetHomePosition(3239.07, 657.235, 86.8775, 4.74729);
                if(pTenebron->isAlive())
                {
                    if (pTenebron->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pTenebron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pTenebron->GetMotionMaster()->MoveTargetedHome();
                }else
                {
                    if(pInstance->GetData(TYPE_TENEBRON_PREKILLED) == false)
                    {
                        pTenebron->Respawn();
                        pTenebron->GetMotionMaster()->MoveTargetedHome();
                        pTenebron->AI()->SetData(DATA_CAN_LOOT,0);
                    }
                }
            }
            if (pShadron)
            {
                pShadron->SetHomePosition(3363.06, 525.28, 98.362, 4.76475);
                if(pShadron->isAlive())
                {
                    if (pShadron->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pShadron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pShadron->GetMotionMaster()->MoveTargetedHome();
                }else
                {
                    if(pInstance->GetData(TYPE_SHADRON_PREKILLED) == false)
                    {
                        pShadron->Respawn();
                        pShadron->GetMotionMaster()->MoveTargetedHome();
                        pShadron->AI()->SetData(DATA_CAN_LOOT,0);
                    }
                }
            }
            if (pVesperon)
            {
                pVesperon->SetHomePosition(3145.68, 520.71, 89.7, 4.64258);
                if(pVesperon->isAlive())
                {
                    if (pVesperon->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pVesperon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pVesperon->GetMotionMaster()->MoveTargetedHome();
                }else
                {
                    if(pInstance->GetData(TYPE_VESPERON_PREKILLED) == false)
                    {
                        pVesperon->Respawn();
                        pVesperon->GetMotionMaster()->MoveTargetedHome();
                        pVesperon->AI()->SetData(DATA_CAN_LOOT,0);
                    }
                }
            }
        }
    }

    void JustReachedHome()
    {
        if (pInstance)
            pInstance->SetData(TYPE_SARTHARION_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_SARTHARION_AGGRO,me);
        DoZoneInCombat();

        if (pInstance)
        {
            pInstance->SetData(TYPE_SARTHARION_EVENT, IN_PROGRESS);
            FetchDragons();
        }
    }

    void JustDied(Unit* pKiller)
    {
        DoScriptText(SAY_SARTHARION_DEATH,me);

        if (pInstance)
        {
            Creature* pTenebron = Unit::GetCreature(*me, pInstance->GetData64(DATA_TENEBRON));
            Creature* pShadron = Unit::GetCreature(*me, pInstance->GetData64(DATA_SHADRON));
            Creature* pVesperon = Unit::GetCreature(*me, pInstance->GetData64(DATA_VESPERON));
            if (pTenebron && pTenebron->isAlive())
                pTenebron->DisappearAndDie();
            if (pShadron && pShadron->isAlive())
                pShadron->DisappearAndDie();
            if (pVesperon && pVesperon->isAlive())
                pVesperon->DisappearAndDie();

            if (achievProgress == 1)
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ASSIST,H_ACHIEV_TWILIGHT_ASSIST));
            else if (achievProgress == 2)
            {
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ASSIST,H_ACHIEV_TWILIGHT_ASSIST));
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_DUO,H_ACHIEV_TWILIGHT_DUO));
            }
            else if (achievProgress == 3)
            {
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ASSIST,H_ACHIEV_TWILIGHT_ASSIST));
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_DUO,H_ACHIEV_TWILIGHT_DUO));
                pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ZONE,H_ACHIEV_TWILIGHT_ZONE));
            }
       
            pInstance->SetData(TYPE_SARTHARION_EVENT, DONE);
        }
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(RAND(SAY_SARTHARION_SLAY_1,SAY_SARTHARION_SLAY_2,SAY_SARTHARION_SLAY_3), me);
    }

    // me->ResetLootMode() is called from Reset()
    // AddDrakeLootMode() should only ever be called from FetchDragons(), which is called from Aggro()
    void AddDrakeLootMode()
    {
        if (me->HasLootMode(LOOT_MODE_HARD_MODE_2))      // Has two Drake loot modes
            me->AddLootMode(LOOT_MODE_HARD_MODE_3);      // Add 3rd Drake loot mode
        else if (me->HasLootMode(LOOT_MODE_HARD_MODE_1)) // Has one Drake loot mode
            me->AddLootMode(LOOT_MODE_HARD_MODE_2);      // Add 2nd Drake loot mode
        else                                             // Has no Drake loot modes
            me->AddLootMode(LOOT_MODE_HARD_MODE_1);      // Add 1st Drake loot mode
    }

    void FetchDragons()
    {
        if(!pInstance)
            return;

        me->ResetLootMode();
        achievProgress = 0;

        Creature* pFetchTene = Unit::GetCreature(*me, pInstance->GetData64(DATA_TENEBRON));
        Creature* pFetchShad = Unit::GetCreature(*me, pInstance->GetData64(DATA_SHADRON));
        Creature* pFetchVesp = Unit::GetCreature(*me, pInstance->GetData64(DATA_VESPERON));

        //if at least one of the dragons are alive and are being called
        bool bCanUseWill = false;

        if (pFetchTene && pFetchTene->isAlive() && !pFetchTene->getVictim())
        {
            bCanUseWill = true;
            if(!pFetchTene->isInCombat())
            {
                AddDrakeLootMode();
                achievProgress++;
            }
            pFetchTene->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aTene[0].m_fX, m_aTene[0].m_fY, m_aTene[0].m_fZ);

            if (!pFetchTene->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                pFetchTene->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        if (pFetchShad && pFetchShad->isAlive() && !pFetchShad->getVictim())
        {
            bCanUseWill = true;
            if(!pFetchShad->isInCombat())
            {
                AddDrakeLootMode();
                achievProgress++;
            }
            pFetchShad->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aShad[0].m_fX, m_aShad[0].m_fY, m_aShad[0].m_fZ);

            if (!pFetchShad->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                pFetchShad->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        if (pFetchVesp && pFetchVesp->isAlive() && !pFetchVesp->getVictim())
        {
            bCanUseWill = true;
            if(!pFetchVesp->isInCombat())
            {
                AddDrakeLootMode();
                achievProgress++;
            }
            pFetchVesp->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aVesp[0].m_fX, m_aVesp[0].m_fY, m_aVesp[0].m_fZ);

            if (!pFetchVesp->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                pFetchVesp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        if (bCanUseWill)
            DoCast(me, SPELL_WILL_OF_SARTHARION);
    }

    void CallDragon(uint32 uiDataId)
    {
        if (pInstance)
        {
            if (Creature *pTemp = Unit::GetCreature(*me,pInstance->GetData64(uiDataId)))
            {
                if (pTemp->isAlive() && !pTemp->getVictim())
                {
                    if (pTemp->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                    if (pTemp->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    int32 iTextId = 0;

                    switch(pTemp->GetEntry())
                    {
                        case NPC_TENEBRON:
                            iTextId = SAY_SARTHARION_CALL_TENEBRON;
                            pTemp->AddAura(SPELL_POWER_OF_TENEBRON, pTemp);
                            pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aTene[1].m_fX, m_aTene[1].m_fY, m_aTene[1].m_fZ);
                            break;
                        case NPC_SHADRON:
                            iTextId = SAY_SARTHARION_CALL_SHADRON;
                            pTemp->AddAura(SPELL_POWER_OF_SHADRON, pTemp);
                            pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aShad[1].m_fX, m_aShad[1].m_fY, m_aShad[1].m_fZ);
                            break;
                        case NPC_VESPERON:
                            iTextId = SAY_SARTHARION_CALL_VESPERON;
                            pTemp->AddAura(SPELL_POWER_OF_VESPERON, pTemp);
                            pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aVesp[1].m_fX, m_aVesp[1].m_fY, m_aVesp[1].m_fZ);
                            break;
                    }

                    DoScriptText(iTextId, me);
                }
            }
        }
    }

    void SendFlameTsunami()
    {
        if (Map* pMap = me->GetMap())
            if (pMap->IsDungeon())
            {
                Map::PlayerList const &PlayerList = pMap->GetPlayers();

                if (!PlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        if (i->getSource() && i->getSource()->isAlive())
                            DoScriptText(WHISPER_LAVA_CHURN, me, i->getSource());
            }
    }

    // Selects a random Fire Cyclone and makes it cast Lava Strike.
    // FIXME: Frequency of the casts reduced to compensate 100% chance of spawning a Lava Blaze add
    void CastLavaStrikeOnTarget(Unit* target)
    {
        std::list<Creature*> pFireCyclonesList;
        Trinity::AllCreaturesOfEntryInRange checker(me, NPC_FIRE_CYCLONE, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, pFireCyclonesList, checker);
        me->VisitNearbyObject(200.0f, searcher);

        if(pFireCyclonesList.empty())
            return;

        std::list<Creature*>::iterator itr = pFireCyclonesList.begin();
        uint32 rnd = rand()%pFireCyclonesList.size();

        for(uint32 i = 0; i < rnd; ++i)
            ++itr;

        (*itr)->CastSpell(target, SPELL_LAVA_STRIKE, true);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        Unit* pTene = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_TENEBRON) : 0);
        Unit* pShad = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_SHADRON) : 0);
        Unit* pVesp = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_VESPERON) : 0);

        //spell will target dragons, if they are still alive at 35%
        if (!m_bIsBerserk && (me->GetHealth()*100 / me->GetMaxHealth()) <= 35
            && ((pTene && pTene->isAlive()) || (pShad && pShad->isAlive()) || (pVesp && pVesp->isAlive())))
        {
            DoScriptText(SAY_SARTHARION_BERSERK, me);
            DoCast(me, SPELL_BERSERK);
            m_bIsBerserk = true;
        }

        //soft enrage
        if (!m_bIsSoftEnraged && HealthBelowPct(10))
        {
            // m_bIsSoftEnraged is used while determining Lava Strike cooldown.
            m_bIsSoftEnraged = true;
        }

        // hard enrage
        if (!m_bIsHardEnraged)
        {
            if (m_uiEnrageTimer <= uiDiff)
            {
                DoCast(me, SPELL_PYROBUFFET, true);
                m_bIsHardEnraged = true;
            }
            else
                m_uiEnrageTimer -= uiDiff;
        }

        // flame tsunami
        if (m_uiFlameTsunamiTimer <= uiDiff)
        {
            SendFlameTsunami();
            switch(urand(0,1))
            {
                case 0:
                {
                    Creature *Right1 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight1Spawn.x, FlameRight1Spawn.y , FlameRight1Spawn.z, 0, TEMPSUMMON_TIMED_DESPAWN,12000);
                    Creature *Right2 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight2Spawn.x, FlameRight2Spawn.y , FlameRight2Spawn.z, 0, TEMPSUMMON_TIMED_DESPAWN,12000);
                    Creature *Right3 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameRight3Spawn.x, FlameRight3Spawn.y , FlameRight3Spawn.z, 0, TEMPSUMMON_TIMED_DESPAWN,12000);
                    Right1->GetMotionMaster()->MovePoint(0, FlameRight1Direction.x, FlameRight1Direction.y, FlameRight1Direction.z);
                    Right2->GetMotionMaster()->MovePoint(0, FlameRight2Direction.x, FlameRight2Direction.y, FlameRight2Direction.z);
                    Right3->GetMotionMaster()->MovePoint(0, FlameRight3Direction.x, FlameRight3Direction.y, FlameRight3Direction.z);
                    break;
                }
                case 1:
                {
                    Creature *Left1 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameLeft1Spawn.x, FlameLeft1Spawn.y , FlameLeft1Spawn.z, 0, TEMPSUMMON_TIMED_DESPAWN,12000);
                    Creature *Left2 = me->SummonCreature(NPC_FLAME_TSUNAMI, FlameLeft2Spawn.x, FlameLeft2Spawn.y , FlameLeft2Spawn.z, 0, TEMPSUMMON_TIMED_DESPAWN,12000);
                    Left1->GetMotionMaster()->MovePoint(0, FlameLeft1Direction.x, FlameLeft1Direction.y, FlameLeft1Direction.z);
                    Left2->GetMotionMaster()->MovePoint(0, FlameLeft2Direction.x, FlameLeft2Direction.y, FlameLeft2Direction.z);
                    break;
                }
            }

            m_uiFlameTsunamiTimer = 30000;
        }
        else
            m_uiFlameTsunamiTimer -= uiDiff;

        // flame breath
        if (m_uiFlameBreathTimer <= uiDiff)
        {
            DoScriptText(SAY_SARTHARION_BREATH, me);
            DoCast(me->getVictim(), RAID_MODE(SPELL_FLAME_BREATH, SPELL_FLAME_BREATH_H));
            m_uiFlameBreathTimer = urand(25000,35000);
        }
        else
            m_uiFlameBreathTimer -= uiDiff;

        // Tail Sweep
        if (m_uiTailSweepTimer <= uiDiff)
        {
            DoCast(me->getVictim(), RAID_MODE(SPELL_TAIL_LASH, SPELL_TAIL_LASH_H));
            m_uiTailSweepTimer = urand(15000,20000);
        }
        else
            m_uiTailSweepTimer -= uiDiff;

        // Cleave
        if (m_uiCleaveTimer <= uiDiff)
        {
            DoCast(me->getVictim(), SPELL_CLEAVE);
            m_uiCleaveTimer = urand(7000,10000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Lavas Strike
        if (m_uiLavaStrikeTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                CastLavaStrikeOnTarget(pTarget);

                if(urand(0,5) == 0)
                    DoScriptText(RAND(SAY_SARTHARION_SPECIAL_1,SAY_SARTHARION_SPECIAL_2,SAY_SARTHARION_SPECIAL_3), me);
            }
            m_uiLavaStrikeTimer = (m_bIsSoftEnraged ? urand(1400, 2000) : urand(5000,20000));
        }
        else
            m_uiLavaStrikeTimer -= uiDiff;

        // call tenebron
        if (!m_bHasCalledTenebron && m_uiTenebronTimer <= uiDiff)
        {
            CallDragon(DATA_TENEBRON);
            m_bHasCalledTenebron = true;
        }
        else
            m_uiTenebronTimer -= uiDiff;

        // call shadron
        if (!m_bHasCalledShadron && m_uiShadronTimer <= uiDiff)
        {
            CallDragon(DATA_SHADRON);
            m_bHasCalledShadron = true;
        }
        else
            m_uiShadronTimer -= uiDiff;

        // call vesperon
        if (!m_bHasCalledVesperon && m_uiVesperonTimer <= uiDiff)
        {
            CallDragon(DATA_VESPERON);
            m_bHasCalledVesperon = true;
        }
        else
            m_uiVesperonTimer -= uiDiff;

        // Don't attack current target if he's not visible for us.
        if(me->getVictim() && me->getVictim()->HasAura(57874, 0))
            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

        DoMeleeAttackIfReady();

        EnterEvadeIfOutOfCombatArea(uiDiff);
    }
};

CreatureAI* GetAI_boss_sartharion(Creature* pCreature)
{
    return new boss_sartharionAI(pCreature);
}

enum TeneText
{
    SAY_TENEBRON_AGGRO                      = -1615009,
    SAY_TENEBRON_SLAY_1                     = -1615010,
    SAY_TENEBRON_SLAY_2                     = -1615011,
    SAY_TENEBRON_DEATH                      = -1615012,
    SAY_TENEBRON_BREATH                     = -1615013,
    SAY_TENEBRON_RESPOND                    = -1615014,
    SAY_TENEBRON_SPECIAL_1                  = -1615015,
    SAY_TENEBRON_SPECIAL_2                  = -1615016
};

enum ShadText
{
    SAY_SHADRON_AGGRO                       = -1615000,
    SAY_SHADRON_SLAY_1                      = -1615001,
    SAY_SHADRON_SLAY_2                      = -1615002,
    SAY_SHADRON_DEATH                       = -1615003,
    SAY_SHADRON_BREATH                      = -1615004,
    SAY_SHADRON_RESPOND                     = -1615005,
    SAY_SHADRON_SPECIAL_1                   = -1615006,
    SAY_SHADRON_SPECIAL_2                   = -1615007
};

enum VespText
{
    SAY_VESPERON_AGGRO                      = -1615033,
    SAY_VESPERON_SLAY_1                     = -1615034,
    SAY_VESPERON_SLAY_2                     = -1615035,
    SAY_VESPERON_DEATH                      = -1615036,
    SAY_VESPERON_BREATH                     = -1615037,
    SAY_VESPERON_RESPOND                    = -1615038,
    SAY_VESPERON_SPECIAL_1                  = -1615039,
    SAY_VESPERON_SPECIAL_2                  = -1615040
};

//to control each dragons common abilities
struct dummy_dragonAI : public ScriptedAI
{
    dummy_dragonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 m_uiWaypointId;
    uint32 m_uiMoveNextTimer;
    int32 m_iPortalRespawnTime;
    bool m_bCanMoveFree;
    bool m_bCanLoot;

    void Reset()
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        m_uiWaypointId = 0;
        m_uiMoveNextTimer = 500;
        m_iPortalRespawnTime = 30000;
        m_bCanMoveFree = false;
        m_bCanLoot = true;
    }

    void SetData(uint32 type, uint32 value)
    {
        if (type == DATA_CAN_LOOT)
            m_bCanLoot = value;
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (!pInstance || uiType != POINT_MOTION_TYPE)
            return;

//        debug_log("dummy_dragonAI: %s reached point %u", me->GetName(), uiPointId);

        //if healers messed up the raid and we was already initialized
        if (pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
        {
            EnterEvadeMode();
            return;
        }

        //this is end, if we reach this, don't do much
        if (uiPointId == POINT_ID_LAND)
        {
            me->GetMotionMaster()->Clear();
            me->SetInCombatWithZone();
            if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
            {
                me->AddThreat(target, 1.0f);
                me->Attack(target, true);
                me->GetMotionMaster()->MoveChase(target);
            }

            m_bCanMoveFree = false;
            return;
        }

        //get amount of common points
        uint32 uiCommonWPCount = sizeof(m_aDragonCommon)/sizeof(Waypoint);

        //increase
        m_uiWaypointId = uiPointId+1;

        //if we have reached a point bigger or equal to count, it mean we must reset to point 0
        if (m_uiWaypointId >= uiCommonWPCount)
        {
            if (!m_bCanMoveFree)
                m_bCanMoveFree = true;

            m_uiWaypointId = 0;
        }

        m_uiMoveNextTimer = 500;
    }

    //used when open portal and spawn mobs in phase
    void DoRaidWhisper(int32 iTextId)
    {
        Map* pMap = me->GetMap();

        if (pMap && pMap->IsDungeon())
        {
            Map::PlayerList const &PlayerList = pMap->GetPlayers();

            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    DoScriptText(iTextId, me, i->getSource());
            }
        }
    }

    //"opens" the portal and does the "opening" whisper
    void OpenPortal()
    {
        int32 iTextId = 0;

        //there are 4 portal spawn locations, each are expected to be spawned with negative spawntimesecs in database

        //using a grid search here seem to be more efficient than caching all four guids
        //in instance script and calculate range to each.
        GameObject* pPortal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL,50.0f);

        switch(me->GetEntry())
        {
            case NPC_TENEBRON:
            {
                iTextId = WHISPER_HATCH_EGGS;
                if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS) 
                {
                    for(uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_TWILIGHT_EGG, TwilightEggs[i].x, TwilightEggs[i].y, TwilightEggs[i].z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                }
                else
                {
                    for(uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_SARTHARION_TWILIGHT_EGG, TwilightEggsSarth[i].x, TwilightEggsSarth[i].y, TwilightEggsSarth[i].z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                }
                break;
            }
            case NPC_SHADRON:
            {
                iTextId = WHISPER_OPEN_PORTAL;
                if(pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron.x, AcolyteofShadron.y , AcolyteofShadron.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28000);
                else
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron2.x, AcolyteofShadron2.y , AcolyteofShadron2.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28000);

                break;
            }
            case NPC_VESPERON:
            {
                iTextId = WHISPER_OPEN_PORTAL;
                if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                {
                    if(Creature* Acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon.x, AcolyteofVesperon.y , AcolyteofVesperon.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000))
                    {
                        me->InterruptNonMeleeSpells(true);
                        Acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }
                else
                {
                    if(Creature* Acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon2.x, AcolyteofVesperon2.y , AcolyteofVesperon2.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000))
                    {
                        me->InterruptNonMeleeSpells(true);
                        Acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }

                 break;
            }
        }

        DoRaidWhisper(iTextId);

        //By using SetRespawnTime() we will actually "spawn" the object with our defined time.
        //Once time is up, portal will disappear again.
        if (pPortal && !pPortal->isSpawned())
            pPortal->SetRespawnTime(m_iPortalRespawnTime);

        //Unclear what are expected to happen if one drake has a portal open already
        //Refresh respawnTime so time again are set to 30secs?
    }

    void JustDied(Unit* pKiller)
    {
        if (!m_bCanLoot)
            me->SetLootRecipient(NULL);

        int32 iTextId = 0;
        uint32 uiSpellId = 0;

        switch(me->GetEntry())
        {
            case NPC_TENEBRON:
                iTextId = SAY_TENEBRON_DEATH;
                uiSpellId = SPELL_POWER_OF_TENEBRON;
                if(pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                    pInstance->SetData(TYPE_TENEBRON_PREKILLED, 1);
                break;
            case NPC_SHADRON:
                iTextId = SAY_SHADRON_DEATH;
                uiSpellId = SPELL_POWER_OF_SHADRON;
                if(pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                    pInstance->SetData(TYPE_SHADRON_PREKILLED, 1);
                if(Creature* pAcolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_SHADRON, 100.0f))
                {
                    pAcolyte->Kill(pAcolyte);
                }
                break;
            case NPC_VESPERON:
                iTextId = SAY_VESPERON_DEATH;
                uiSpellId = SPELL_POWER_OF_VESPERON;
                if(pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                    pInstance->SetData(TYPE_VESPERON_PREKILLED, 1);
                if(Creature* pAcolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_VESPERON, 100.0f))
                {
                    pAcolyte->Kill(pAcolyte);
                }
                break;
        }

        DoScriptText(iTextId, me);

        me->RemoveAurasDueToSpell(uiSpellId);

        if (pInstance)
        {
            pInstance->DoRemoveAurasDueToSpellOnPlayers(uiSpellId);

            // not if solo mini-boss fight
            if (pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                return;

            // Twilight Revenge to main boss
            if (Unit* pSartharion = Unit::GetUnit((*me), pInstance->GetData64(DATA_SARTHARION)))
                if (pSartharion->isAlive())
                {
                    pSartharion->RemoveAurasDueToSpell(uiSpellId);
                    DoCast(pSartharion, SPELL_TWILIGHT_REVENGE, true);
                }
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_bCanMoveFree && m_uiMoveNextTimer)
        {
            if (m_uiMoveNextTimer <= uiDiff)
            {
                if(m_uiWaypointId < MAX_WAYPOINT)
                    me->GetMotionMaster()->MovePoint(m_uiWaypointId,
                        m_aDragonCommon[m_uiWaypointId].m_fX, m_aDragonCommon[m_uiWaypointId].m_fY, m_aDragonCommon[m_uiWaypointId].m_fZ);

//                debug_log("dummy_dragonAI: %s moving to point %u", me->GetName(), m_uiWaypointId);
                m_uiMoveNextTimer = 0;
            }
            else
                m_uiMoveNextTimer -= uiDiff;
        }
    }
};

/*######
## Mob Tenebron
######*/

struct mob_tenebronAI : public dummy_dragonAI
{
    mob_tenebronAI(Creature* pCreature) : dummy_dragonAI(pCreature) {}

    uint32 m_uiShadowBreathTimer;
    uint32 m_uiShadowFissureTimer;
    uint32 m_uiHatchEggTimer;

    bool m_bHasPortalOpen;

    void Reset()
    {
        m_uiShadowBreathTimer = 20000;
        m_uiShadowFissureTimer = 5000;
        m_uiHatchEggTimer = 30000;

        m_bHasPortalOpen = false;
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_TENEBRON_AGGRO, me);
        DoZoneInCombat();
        DoCast(me, SPELL_POWER_OF_TENEBRON);
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(RAND(SAY_TENEBRON_SLAY_1,SAY_TENEBRON_SLAY_2), me);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //if no target, update dummy and return
        if (!UpdateVictim())
        {
            dummy_dragonAI::UpdateAI(uiDiff);
            return;
        }

        // shadow fissure
        if (m_uiShadowFissureTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE));

            m_uiShadowFissureTimer = urand(15000,20000);
        }
        else
            m_uiShadowFissureTimer -= uiDiff;

        // Hatch Egg
        if (m_uiHatchEggTimer <= uiDiff)
        {
            OpenPortal();
            m_uiHatchEggTimer = 30000;
        }
        else
             m_uiHatchEggTimer -= uiDiff;

        // shadow breath
        if (m_uiShadowBreathTimer <= uiDiff)
        {
            DoScriptText(SAY_TENEBRON_BREATH, me);
            DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
            m_uiShadowBreathTimer = urand(20000,25000);
        }
        else
            m_uiShadowBreathTimer -= uiDiff;

        // Don't attack current target if he's not visible for us.
        if(me->getVictim() && me->getVictim()->HasAura(57874, 0))
            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_tenebron(Creature* pCreature)
{
    return new mob_tenebronAI(pCreature);
}

/*######
## Mob Shadron
######*/

struct mob_shadronAI : public dummy_dragonAI
{
    mob_shadronAI(Creature* pCreature) : dummy_dragonAI(pCreature) {}

    uint32 m_uiShadowBreathTimer;
    uint32 m_uiShadowFissureTimer;
    uint32 m_uiAcolyteShadronTimer;

    bool m_bHasPortalOpen;

    void Reset()
    {
        m_uiShadowBreathTimer = 20000;
        m_uiShadowFissureTimer = 5000;
        m_uiAcolyteShadronTimer = 60000;

        if (me->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
            me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);

        if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
            me->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);

        m_bHasPortalOpen = false;
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_SHADRON_AGGRO,me);
        DoZoneInCombat();
        DoCast(me, SPELL_POWER_OF_SHADRON);
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(RAND(SAY_SHADRON_SLAY_1,SAY_SHADRON_SLAY_2), me);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //if no target, update dummy and return
        if (!UpdateVictim())
        {
            dummy_dragonAI::UpdateAI(uiDiff);
            return;
        }

        // shadow fissure
        if (m_uiShadowFissureTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));

            m_uiShadowFissureTimer = urand(15000,20000);
        }
        else
            m_uiShadowFissureTimer -= uiDiff;

        // Portal Event
        if (m_uiAcolyteShadronTimer <= uiDiff)
        {
            if(m_bHasPortalOpen)
                m_uiAcolyteShadronTimer = 10000;
            else
            {
                if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                    return;

                OpenPortal();
                m_bHasPortalOpen = true;
                m_uiAcolyteShadronTimer = urand(60000,65000);
            }
        }
        else
            m_uiAcolyteShadronTimer -= uiDiff;

        // shadow breath
        if (m_uiShadowBreathTimer <= uiDiff)
        {
            DoScriptText(SAY_SHADRON_BREATH, me);
            DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
            m_uiShadowBreathTimer = urand(20000,25000);
        }
        else
            m_uiShadowBreathTimer -= uiDiff;

        // Don't attack current target if he's not visible for us.
        if(me->getVictim() && me->getVictim() && me->getVictim()->HasAura(57874, 0))
            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_shadron(Creature* pCreature)
{
    return new mob_shadronAI(pCreature);
}

/*######
## Mob Vesperon
######*/

struct mob_vesperonAI : public dummy_dragonAI
{
    mob_vesperonAI(Creature* pCreature) : dummy_dragonAI(pCreature) {}

    uint32 m_uiShadowBreathTimer;
    uint32 m_uiShadowFissureTimer;
    uint32 m_uiAcolyteVesperonTimer;

    bool m_bHasPortalOpen;

    void Reset()
    {
        m_uiShadowBreathTimer = 20000;
        m_uiShadowFissureTimer = 5000;
        m_uiAcolyteVesperonTimer = 60000;

        m_bHasPortalOpen = false;
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_VESPERON_AGGRO,me);
        DoZoneInCombat();
        DoCast(me, SPELL_POWER_OF_VESPERON);
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(RAND(SAY_VESPERON_SLAY_1,SAY_VESPERON_SLAY_2), me);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //if no target, update dummy and return
        if (!UpdateVictim())
        {
            dummy_dragonAI::UpdateAI(uiDiff);
            return;
        }

        // shadow fissure
        if (m_uiShadowFissureTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));

            m_uiShadowFissureTimer = urand(15000,20000);
        }
        else
            m_uiShadowFissureTimer -= uiDiff;

        // Portal Event
        if (m_uiAcolyteVesperonTimer <= uiDiff)
        {
            if(m_bHasPortalOpen)
                m_uiAcolyteVesperonTimer = 10000;
            else
            {
                OpenPortal();
                DoCast(me->getVictim(), SPELL_TWILIGHT_TORMENT_VESP);            
                m_uiAcolyteVesperonTimer = urand(60000,70000);
            }
        }
        else
            m_uiAcolyteVesperonTimer -= uiDiff;

        // shadow breath
        if (m_uiShadowBreathTimer <= uiDiff)
        {
            DoScriptText(SAY_VESPERON_BREATH, me);
            DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
            m_uiShadowBreathTimer = urand(20000,25000);
        }
        else
            m_uiShadowBreathTimer -= uiDiff;

        // Don't attack current target if he's not visible for us.
        if(me->getVictim() && me->getVictim()->HasAura(57874, 0))
            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_vesperon(Creature* pCreature)
{
    return new mob_vesperonAI(pCreature);
}

/*######
## Mob Acolyte of Shadron
######*/

struct mob_acolyte_of_shadronAI : public ScriptedAI
{
    mob_acolyte_of_shadronAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* pInstance;
    uint32 uiDespawnTimer;
 
    void Reset()
    {
        uiDespawnTimer = 28000;
        if (pInstance)
        {
            Creature* pTarget = NULL;
            //if not solo figth, buff main boss, else place debuff on mini-boss. both spells TARGET_SCRIPT
            if (pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
            {
                if(pTarget = (Unit::GetCreature((*me), pInstance->GetData64(DATA_SARTHARION))))
                    pTarget->AddAura(SPELL_GIFT_OF_TWILIGTH_SAR, pTarget);
            }
            else
            {
                if(pTarget = (Unit::GetCreature((*me), pInstance->GetData64(DATA_SHADRON))))
                    pTarget->AddAura(SPELL_GIFT_OF_TWILIGTH_SHA, pTarget);
            }
         }
        me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER,me);
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            Creature* Shadron = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SHADRON));
            if(Shadron)
            {
                (CAST_AI(mob_shadronAI,Shadron->AI()))->m_bHasPortalOpen = false;
            }

            Creature* pDebuffTarget = NULL;
            Map *map = me->GetMap();
            if (map->IsDungeon())
            {
                Map::PlayerList const &PlayerList = map->GetPlayers();
 
                if (PlayerList.isEmpty())
                    return;

                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource()->isAlive() && i->getSource()->HasAura(SPELL_TWILIGHT_SHIFT,0) && !i->getSource()->getVictim())
                    {
                        i->getSource()->CastSpell(i->getSource(),SPELL_TWILIGHT_SHIFT_REMOVAL_ALL,true);
                        i->getSource()->CastSpell(i->getSource(),SPELL_TWILIGHT_RESIDUE,true);
                        i->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                        i->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
                    }
               }
            }

            //not solo fight, so main boss has deduff
            pDebuffTarget = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SARTHARION));
            if (pDebuffTarget && pDebuffTarget->isAlive() && pDebuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SAR))
                pDebuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SAR);

            //event not in progress, then solo fight and must remove debuff mini-boss
            pDebuffTarget = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SHADRON));
            if (pDebuffTarget && pDebuffTarget->isAlive() && pDebuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                pDebuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if(uiDespawnTimer < uiDiff)
        {
            me->SetVisibility(VISIBILITY_OFF);
            me->Kill(me);
            uiDespawnTimer = 28000;
            return;
        }else uiDespawnTimer -= uiDiff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_acolyte_of_shadron(Creature* pCreature)
{
    return new mob_acolyte_of_shadronAI(pCreature);
}

/*######
## Mob Acolyte of Vesperon
######*/

struct mob_acolyte_of_vesperonAI : public ScriptedAI
{
    mob_acolyte_of_vesperonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 uiDespawnTimer;

    void Reset()
    {
        uiDespawnTimer = 28000;
        if (pInstance)
        {
            me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER,me);                
        }
        DoCast(me, SPELL_TWILIGHT_TORMENT_VESP_ACO);
    }

    void JustDied(Unit* pKiller)
    {
        me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP_ACO);     

        // remove twilight torment on Vesperon
        if (pInstance)
        {
            Creature* pVesperon = pInstance->instance->GetCreature(pInstance->GetData64(DATA_VESPERON));
            if (pVesperon)
                (CAST_AI(mob_vesperonAI,pVesperon->AI()))->m_bHasPortalOpen = false;

            if (pVesperon && pVesperon->isAlive() && pVesperon->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
                pVesperon->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
            
            Map *map = me->GetMap();
            if (map->IsDungeon())
            {
                Map::PlayerList const &PlayerList = map->GetPlayers();

                if (PlayerList.isEmpty())
                    return;

                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource()->isAlive() && i->getSource()->HasAura(SPELL_TWILIGHT_SHIFT,0) && !i->getSource()->getVictim())
                    {
                        i->getSource()->CastSpell(i->getSource(),SPELL_TWILIGHT_SHIFT_REMOVAL_ALL,true);
                        i->getSource()->CastSpell(i->getSource(),SPELL_TWILIGHT_RESIDUE,true);
                        i->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                        i->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
                    }
                    if (i->getSource()->isAlive() && i->getSource()->HasAura(SPELL_TWILIGHT_TORMENT_VESP,0) && !i->getSource()->getVictim())
                        i->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
                }
            }

            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP_ACO);
            pInstance->DoRemoveAurasDueToSpellOnPlayers(57935);
            pInstance->DoRemoveAurasDueToSpellOnPlayers(58835); // Components of spell Twilight Torment
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if(uiDespawnTimer < uiDiff)
        {
            me->SetVisibility(VISIBILITY_OFF);
            me->Kill(me);
            uiDespawnTimer = 28000;
            return;
        }else uiDespawnTimer -= uiDiff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_acolyte_of_vesperon(Creature* pCreature)
{
    return new mob_acolyte_of_vesperonAI(pCreature);
}

/*######
## Mob Twilight Eggs
######*/

struct mob_twilight_eggsAI : public Scripted_NoMovementAI
{
    mob_twilight_eggsAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {        
        pInstance = pCreature->GetInstanceData();
    }

    uint32 m_uiFadeArmorTimer;
    uint32 m_uiHatchEggTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        if(pInstance)
        {
            me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER,me);
        }
        m_uiFadeArmorTimer = 1000;
        m_uiHatchEggTimer = 20000;
    }
    
    void SpawnWhelps()
    {
        me->RemoveAllAuras();

        if (!pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
            me->SummonCreature(NPC_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
        else                      
            me->SummonCreature(NPC_SHARTHARION_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
        me->DealDamage(me, me->GetHealth());
    }
    
    void JustSummoned(Creature* pWho)
    {
        pWho->SetInCombatWithZone();
    }
    
    void UpdateAI(const uint32 uiDiff)
    {
        if (m_uiHatchEggTimer <= uiDiff)
        {
            Creature* Tenebron = pInstance->instance->GetCreature(pInstance->GetData64(DATA_TENEBRON));
            if(Tenebron)
                (CAST_AI(mob_tenebronAI,Tenebron->AI()))->m_bHasPortalOpen = false;
            SpawnWhelps();
        }
        else
            m_uiHatchEggTimer -= uiDiff;      
    }
    

    void AttackStart(Unit* pWho) {}
    void MoveInLineOfSight(Unit* pWho) {}
};

CreatureAI* GetAI_mob_twilight_eggs(Creature* pCreature)
{
    return new mob_twilight_eggsAI(pCreature);
}

/*######
## Mob Flame Tsunami
######*/
struct npc_flame_tsunamiAI : public ScriptedAI
{
    npc_flame_tsunamiAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        me->SetDisplayId(11686);
        me->AddAura(SPELL_FLAME_TSUNAMI, me);
    }

    uint32 Tsunami_Timer;
    uint32 TsunamiBuff_timer;
    uint32 entry;

    void Reset()
    {
        Tsunami_Timer = 100;
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        TsunamiBuff_timer = 1000;
        entry = 0;
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (Tsunami_Timer <= diff)
        {
            DoCast(me,SPELL_FLAME_TSUNAMI_DMG_AURA);
            Tsunami_Timer = 500;
        }else Tsunami_Timer -= diff;
        
        if(TsunamiBuff_timer <= diff)
        {
            if (Unit* LavaBlaze = GetClosestCreatureWithEntry(me,NPC_LAVA_BLAZE, 10.0f, true))
                LavaBlaze->CastSpell(LavaBlaze, SPELL_FLAME_TSUNAMI_BUFF, true);
            TsunamiBuff_timer = 1000;
        }else TsunamiBuff_timer -= diff;
    }
};

// Twilight Fissure
struct npc_twilight_fissureAI : public Scripted_NoMovementAI
{
    npc_twilight_fissureAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {
        Reset();
    }

    uint32 VoidBlast_Timer;

    void Reset()
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->AddAura( 46265 , me ); // Wrong, can't find proper visual
        me->AddAura( 69422 , me );
        VoidBlast_Timer = 5000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (VoidBlast_Timer <= diff)
        {
            DoCastAOE(RAID_MODE(SPELL_VOID_BLAST, SPELL_VOID_BLAST_H));
            ////twilight realm
            //DoCast(me->getVictim(), 57620, true);
            //DoCast(me->getVictim(), 57874, true);
            VoidBlast_Timer = 9000;
            me->RemoveAllAuras();
            me->Kill(me);
        } else VoidBlast_Timer -= diff;
    }
};


CreatureAI* GetAI_npc_flame_tsunami(Creature* pCreature)
{
    return new npc_flame_tsunamiAI(pCreature);
}

CreatureAI* GetAI_npc_twilight_fissure(Creature* pCreature)
{
    return new npc_twilight_fissureAI(pCreature);
}

/*######
## Mob Twilight Whelps
######*/

struct mob_twilight_whelpAI : public ScriptedAI
{
    mob_twilight_whelpAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFadeArmorTimer;

    void Reset()
    {
        me->RemoveAllAuras();
        me->SetInCombatWithZone();
        m_uiFadeArmorTimer = 1000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        // twilight torment
        if (m_uiFadeArmorTimer <= uiDiff)
        {
            DoCast(me->getVictim(), SPELL_FADE_ARMOR);
            m_uiFadeArmorTimer = urand(5000,10000);
        }
        else
            m_uiFadeArmorTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_twilight_whelp(Creature* pCreature)
{
    return new mob_twilight_whelpAI(pCreature);
}

void AddSC_boss_sartharion()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_sartharion";
    newscript->GetAI = &GetAI_boss_sartharion;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_vesperon";
    newscript->GetAI = &GetAI_mob_vesperon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_shadron";
    newscript->GetAI = &GetAI_mob_shadron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_tenebron";
    newscript->GetAI = &GetAI_mob_tenebron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_acolyte_of_shadron";
    newscript->GetAI = &GetAI_mob_acolyte_of_shadron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_acolyte_of_vesperon";
    newscript->GetAI = &GetAI_mob_acolyte_of_vesperon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_twilight_eggs";
    newscript->GetAI = &GetAI_mob_twilight_eggs;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_flame_tsunami";
    newscript->GetAI = &GetAI_npc_flame_tsunami;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_twilight_fissure";
    newscript->GetAI = &GetAI_npc_twilight_fissure;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_twilight_whelp";
    newscript->GetAI = &GetAI_mob_twilight_whelp;
    newscript->RegisterSelf();
}
