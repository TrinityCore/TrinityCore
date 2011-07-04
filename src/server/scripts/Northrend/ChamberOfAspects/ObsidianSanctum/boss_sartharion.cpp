/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#define DATA_CAN_LOOT   0

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
    SPELL_TWILIGHT_TORMENT_STACKS               = 57935,

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
    SPELL_FLAME_TSUNAMI_DMG_AURA                = 57492,    // periodic damage, npc has this aura
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
    H_ACHIEV_TWILIGHT_ZONE                      = 2054,
    ACHIEV_GONNA_GO                             = 2047,
    H_ACHIEV_GONNA_GO                           = 2048,
};

//each dragons special points. First where fly to before connect to connon, second where land point is.
Position m_aTene[]=
{
    {3212.854f, 575.597f, 109.856f},                           //init
    {3246.425f, 565.367f, 61.249f}                             //end
};

Position m_aShad[]=
{
    {3293.238f, 472.223f, 106.968f},
    {3271.669f, 526.907f, 61.931f}
};

Position m_aVesp[]=
{
    {3193.310f, 472.861f, 102.697f},
    {3227.268f, 533.238f, 59.995f}
};

#define ACTION_TELEPORT_BACK_SAR 70
#define MAX_WAYPOINT 6
//points around raid "isle", counter clockwise. should probably be adjusted to be more alike
Position m_aDragonCommon[MAX_WAYPOINT]=
{
    {3214.012f, 468.932f, 98.652f},
    {3244.950f, 468.427f, 98.652f},
    {3283.520f, 496.869f, 98.652f},
    {3287.316f, 555.875f, 98.652f},
    {3250.479f, 585.827f, 98.652f},
    {3209.969f, 566.523f, 98.652f}
};
static Position FlameSpawn[] =
{
    // Right
    { 3285.215820f, 516.534100f, 59.188776f, 3.14f },
    { 3284.311035f, 559.839611f, 59.197129f, 3.14f },
    // Left
    { 3209.564697f, 486.982727f, 59.156610f, 0.00f },
    { 3210.280029f, 533.491089f, 59.168331f, 0.00f },
    { 3210.609131f, 579.359375f, 59.120803f, 0.00f }
};

static Position AcolyteofShadron =     { 3363.92f, 534.703f, 97.2683f };
static Position AcolyteofShadron2 =    { 3246.57f, 551.263f, 58.6164f };
static Position AcolyteofVesperon =    { 3145.68f, 520.71f, 89.7f };
static Position AcolyteofVesperon2 =   { 3246.57f, 551.263f, 58.6164f };

Position TwilightEggs[] =
{
    {3219.28f, 669.121f , 88.5549f},
    {3221.55f, 682.852f , 90.5361f},
    {3239.77f, 685.94f , 90.3168f},
    {3250.33f, 669.749f , 88.7637f},
    {3246.6f, 642.365f , 84.8752f},
    {3233.68f, 653.117f , 85.7051f}
};
Position TwilightEggsSarth[] =
{
    {3261.75f, 539.14f , 58.6082f},
    {3257.41f, 512.939f , 58.5432f},
    {3231.04f, 498.281f , 58.6439f},
    {3264.90f, 525.865f , 58.6436f},
    {3257.54f, 502.285f , 58.2077f},
    {3264.26f, 516.364f , 58.8011f}
};

enum Events
{
    EVENT_NONE,
    EVENT_FLAME_BREATH,
    EVENT_TAIL_SWEEP,
    EVENT_CLEAVE,
    EVENT_ENRAGE,

    EVENT_LAVA_STRIKE,    
    EVENT_FLAME_TSUNAMI,

    EVENT_CALL_TENEBRON,
    EVENT_CALL_SHADRON,
    EVENT_CALL_VESPERON
};

/*######
## Boss Sartharion
######*/

class boss_sartharion : public CreatureScript
{
    public:
        boss_sartharion(): CreatureScript("boss_sartharion") {}

    struct boss_sartharionAI : public BossAI
    {
        boss_sartharionAI(Creature* pCreature) : BossAI(pCreature, TYPE_SARTHARION_EVENT){}

        bool m_bIsBerserk;
        bool m_bIsSoftEnraged;

        uint32 achievProgress;
        uint32 Acolytes;

        std::set<uint64> lLavaStriked;

        void Reset()
        {
            _Reset();
            if (instance)
                instance->SetData(TYPE_SARTHARION_EVENT, NOT_STARTED);
            RespawnDrakes();
            DespawnCreatures(NPC_SHARTHARION_TWILIGHT_WHELP, 100);
            DespawnCreatures(NPC_TWILIGHT_WHELP, 100);
            DespawnCreatures(NPC_LAVA_BLAZE, 100);

            m_bIsBerserk = false;
            m_bIsSoftEnraged = false;

            if (me->HasAura(SPELL_TWILIGHT_REVENGE))
                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_REVENGE);

            if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SAR))
                me->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SAR);

            Creature* pTenebron = Unit::GetCreature(*me, instance->GetData64(DATA_TENEBRON));
            Creature* pShadron = Unit::GetCreature(*me, instance->GetData64(DATA_SHADRON));
            Creature* pVesperon = Unit::GetCreature(*me, instance->GetData64(DATA_VESPERON));
            if (pTenebron && pTenebron->isAlive())
                pTenebron->ResetLootMode();
            if (pShadron && pShadron->isAlive())
                pShadron->ResetLootMode();
            if (pVesperon && pVesperon->isAlive())
                pVesperon->ResetLootMode();

            me->ResetLootMode();
            me->SetHomePosition(3246.57f, 551.263f, 58.6164f, 4.66003f); 

            achievProgress = 0;
            Acolytes = 2;

            lLavaStriked.clear();

            while (Unit* pTarget = me->FindNearestCreature(NPC_LAVA_BLAZE, 100.0f))
                pTarget->RemoveFromWorld();
        }

        void EnterCombat(Unit* pWho)
        {
            _EnterCombat();
            if (instance)
                instance->SetData(TYPE_SARTHARION_EVENT, IN_PROGRESS);
            DoScriptText(SAY_SARTHARION_AGGRO,me);
            FetchDragons();
            
            events.ScheduleEvent(EVENT_FLAME_TSUNAMI, 30000);
            events.ScheduleEvent(EVENT_FLAME_BREATH, 20000);
            events.ScheduleEvent(EVENT_TAIL_SWEEP, 15000);
            events.ScheduleEvent(EVENT_CLEAVE, 7000);
            events.ScheduleEvent(EVENT_LAVA_STRIKE, 5000);
            events.ScheduleEvent(EVENT_ENRAGE, 15*MINUTE*IN_MILLISECONDS);
            Creature* pTenebron = Unit::GetCreature(*me, instance->GetData64(DATA_TENEBRON));
            Creature* pShadron = Unit::GetCreature(*me, instance->GetData64(DATA_SHADRON));
            Creature* pVesperon = Unit::GetCreature(*me, instance->GetData64(DATA_VESPERON));
            if (pTenebron && pTenebron->isAlive())
                pTenebron->AI()->SetData(DATA_CAN_LOOT,0);
            if (pShadron && pShadron->isAlive())
                pShadron->AI()->SetData(DATA_CAN_LOOT,0);
            if (pVesperon && pVesperon->isAlive())
                pVesperon->AI()->SetData(DATA_CAN_LOOT,0);
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_TELEPORT_BACK_SAR:
                    Acolytes--;
                    break;
            }
        }

        void DespawnCreatures(uint32 entry, float distance, bool discs = false)
        {
            std::list<Creature*> m_pCreatures;
            GetCreatureListWithEntryInGrid(m_pCreatures, me, entry, distance);

            if (m_pCreatures.empty())
                return;

            for(std::list<Creature*>::iterator iter = m_pCreatures.begin(); iter != m_pCreatures.end(); ++iter)
                (*iter)->ForcedDespawn();
        }

        void JustDied(Unit* pKiller)
        {
            _JustDied();
            DoScriptText(SAY_SARTHARION_DEATH,me);
            if (instance)
                instance->SetData(TYPE_SARTHARION_EVENT, DONE);

            if (instance)
            {
                Creature* pTenebron = Unit::GetCreature(*me, instance->GetData64(DATA_TENEBRON));
                Creature* pShadron = Unit::GetCreature(*me, instance->GetData64(DATA_SHADRON));
                Creature* pVesperon = Unit::GetCreature(*me, instance->GetData64(DATA_VESPERON));
                if (pTenebron && pTenebron->isAlive())
                    pTenebron->DisappearAndDie();
                if (pShadron && pShadron->isAlive())
                    pShadron->DisappearAndDie();
                if (pVesperon && pVesperon->isAlive())
                    pVesperon->DisappearAndDie();

                if (achievProgress >= 1)
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ASSIST,H_ACHIEV_TWILIGHT_ASSIST));
                if (achievProgress >= 2)
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_DUO,H_ACHIEV_TWILIGHT_DUO));
                if (achievProgress == 3)
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_TWILIGHT_ZONE,H_ACHIEV_TWILIGHT_ZONE));

                /*AchievementEntry const *achievGonnaGo = GetAchievementStore()->LookupEntry(RAID_MODE(ACHIEV_GONNA_GO, H_ACHIEV_GONNA_GO));
                if (achievGonnaGo)
                {
                    Map::PlayerList const &players = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (lLavaStriked.find(itr->getSource()->GetGUID()) != lLavaStriked.end())
                            continue;
                        else
                            itr->getSource()->CompletedAchievement(achievGonnaGo);
                    }
                }*/

                while (Unit* pTarget = me->FindNearestCreature(NPC_LAVA_BLAZE, 100.0f))
                    pTarget->RemoveFromWorld();
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
            else                                                     // Has no Drake loot modes
                me->AddLootMode(LOOT_MODE_HARD_MODE_1);      // Add 1st Drake loot mode
        }

        void FetchDragons()
        {
            if (!instance)
                return;
            Creature* pFetchTene = Unit::GetCreature(*me, instance->GetData64(DATA_TENEBRON));
            Creature* pFetchShad = Unit::GetCreature(*me, instance->GetData64(DATA_SHADRON));
            Creature* pFetchVesp = Unit::GetCreature(*me, instance->GetData64(DATA_VESPERON));

            //if at least one of the dragons are alive and are being called
            bool bCanUseWill = false;

            if (pFetchTene && pFetchTene->isAlive() && !pFetchTene->getVictim())
            {
                bCanUseWill = true;
                pFetchTene->AddAura(SPELL_POWER_OF_TENEBRON, pFetchTene);
                pFetchTene->AddAura(SPELL_WILL_OF_SARTHARION, pFetchTene);
                AddDrakeLootMode();
                achievProgress++;            
                events.ScheduleEvent(EVENT_CALL_TENEBRON, 30000);
                pFetchTene->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aTene[0]);

                if (!pFetchTene->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    pFetchTene->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pFetchTene->SetReactState(REACT_PASSIVE);
            }

            if (pFetchShad && pFetchShad->isAlive() && !pFetchShad->getVictim())
            {
                bCanUseWill = true;
                pFetchShad->AddAura(SPELL_POWER_OF_SHADRON, pFetchShad);
                pFetchShad->AddAura(SPELL_WILL_OF_SARTHARION, pFetchShad);
                AddDrakeLootMode();
                achievProgress++;
                events.ScheduleEvent(EVENT_CALL_SHADRON, 75000);
                pFetchShad->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aShad[0]);

                if (!pFetchShad->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    pFetchShad->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pFetchShad->SetReactState(REACT_PASSIVE);
            }

            if (pFetchVesp && pFetchVesp->isAlive() && !pFetchVesp->getVictim())
            {
                bCanUseWill = true;
                pFetchVesp->AddAura(SPELL_POWER_OF_VESPERON, pFetchVesp);
                pFetchVesp->AddAura(SPELL_WILL_OF_SARTHARION, pFetchVesp);
                AddDrakeLootMode();
                achievProgress++;
                events.ScheduleEvent(EVENT_CALL_VESPERON, 120000);
                pFetchVesp->GetMotionMaster()->MovePoint(POINT_ID_INIT, m_aVesp[0]);

                if (!pFetchVesp->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    pFetchVesp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pFetchVesp->SetReactState(REACT_PASSIVE);
            }

            if (bCanUseWill)
                DoCast(me, SPELL_WILL_OF_SARTHARION);
        }

        void RespawnDrakes()
        {
            if (!instance)
                return;

            Creature* pTenebron = Unit::GetCreature(*me, instance->GetData64(DATA_TENEBRON));
            Creature* pShadron = Unit::GetCreature(*me, instance->GetData64(DATA_SHADRON));
            Creature* pVesperon = Unit::GetCreature(*me, instance->GetData64(DATA_VESPERON));
            if (pTenebron)
            {
                pTenebron->SetHomePosition(3239.07f, 657.235f, 86.8775f, 4.74729f);
                if(pTenebron->isAlive())
                {
                    if (pTenebron->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pTenebron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pTenebron->SetReactState(REACT_AGGRESSIVE);
                    pTenebron->RemoveAllAuras();
                    pTenebron->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if(instance->GetData(TYPE_TENEBRON_PREKILLED) == false)
                    {
                        pTenebron->Respawn();
                        pTenebron->SetHomePosition(3239.07f, 657.235f, 86.8775f, 4.74729f);
                        pTenebron->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }
            if (pShadron)
            {
                pShadron->SetHomePosition(3363.06f, 525.28f, 98.362f, 4.76475f);
                if (pShadron->isAlive())
                {
                    if (pShadron->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pShadron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pShadron->SetReactState(REACT_AGGRESSIVE);
                    pShadron->RemoveAllAuras();
                    pShadron->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if(instance->GetData(TYPE_SHADRON_PREKILLED) == false)
                    {
                        pShadron->Respawn();
                        pShadron->SetHomePosition(3363.06f, 525.28f, 98.362f, 4.76475f);
                        pShadron->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }
            if (pVesperon)
            {
                pVesperon->SetHomePosition(3145.68f, 520.71f, 89.7f, 4.64258f);
                if(pVesperon->isAlive())
                {
                    if (pVesperon->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        pVesperon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pVesperon->SetReactState(REACT_AGGRESSIVE);
                    pVesperon->RemoveAllAuras();
                    pVesperon->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    if(instance->GetData(TYPE_VESPERON_PREKILLED) == false)
                    {
                        pVesperon->Respawn();
                        pVesperon->SetHomePosition(3145.68f, 520.71f, 89.7f, 4.64258f);
                        pVesperon->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }
        }

        void CallDragon(uint32 uiDataId)
        {
            if (instance)
            {
                if (Creature *pTemp = Unit::GetCreature(*me,instance->GetData64(uiDataId)))
                {
                    if (pTemp->isAlive() && !pTemp->getVictim())
                    {
                        if (pTemp->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                        if (pTemp->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                            pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                        pTemp->SetReactState(REACT_AGGRESSIVE);

                        int32 iTextId = 0;

                        switch(pTemp->GetEntry())
                        {
                            case NPC_TENEBRON:
                                iTextId = SAY_SARTHARION_CALL_TENEBRON;
                                pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aTene[1]);
                                pTemp->AI()->DoZoneInCombat();
                                break;
                            case NPC_SHADRON:
                                iTextId = SAY_SARTHARION_CALL_SHADRON;
                                pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aShad[1]);
                                pTemp->AI()->DoZoneInCombat();
                                break;
                            case NPC_VESPERON:
                                iTextId = SAY_SARTHARION_CALL_VESPERON;
                                pTemp->GetMotionMaster()->MovePoint(POINT_ID_LAND, m_aVesp[1]);
                                pTemp->AI()->DoZoneInCombat();
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

        void SpellHitTarget(Unit* pTarget, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_LAVA_STRIKE)
                if (pTarget->GetTypeId() == TYPEID_PLAYER)
                    lLavaStriked.insert(pTarget->ToPlayer()->GetGUID());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (Acolytes == 0)
            {
                if (instance)
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_ENTER);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            Unit* pTene = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_TENEBRON) : 0);
            Unit* pShad = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_SHADRON) : 0);
            Unit* pVesp = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_VESPERON) : 0);

            //spell will target dragons, if they are still alive at 35%
            if (!m_bIsBerserk && (me->GetHealth()*100 / me->GetMaxHealth()) <= 35
                && ((pTene && pTene->isAlive()) || (pShad && pShad->isAlive()) || (pVesp && pVesp->isAlive())))
            {
                DoScriptText(SAY_SARTHARION_BERSERK, me);
                DoCast(me, SPELL_BERSERK);
                m_bIsBerserk = true;
            }

            //soft enrage
            if (!m_bIsSoftEnraged && (me->GetHealth()*100 / me->GetMaxHealth()) <= 10)
            {
                // m_bIsSoftEnraged is used while determining Lava Strike cooldown.
                m_bIsSoftEnraged = true;
            }

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ENRAGE:
                        DoCast(me, SPELL_PYROBUFFET, true);
                        break;
                    case EVENT_FLAME_TSUNAMI:
                        SendFlameTsunami();
                        if(urand(0,1))
                            for (int8 i = 0; i < 2; i++)
                                me->SummonCreature(NPC_FLAME_TSUNAMI, FlameSpawn[i], TEMPSUMMON_TIMED_DESPAWN, 14000);
                        else
                            for (int8 i = 2; i < 5; i++)
                                me->SummonCreature(NPC_FLAME_TSUNAMI, FlameSpawn[i], TEMPSUMMON_TIMED_DESPAWN, 14000);
                        events.ScheduleEvent(EVENT_FLAME_TSUNAMI, 30000);
                        break;
                    case EVENT_FLAME_BREATH:
                        DoScriptText(SAY_SARTHARION_BREATH, me);
                        DoCast(me->getVictim(), RAID_MODE(SPELL_FLAME_BREATH, SPELL_FLAME_BREATH_H));
                        events.ScheduleEvent(EVENT_FLAME_BREATH, urand(25000,35000));
                        break;
                    case EVENT_TAIL_SWEEP:
                        DoCast(me->getVictim(), RAID_MODE(SPELL_TAIL_LASH, SPELL_TAIL_LASH_H));
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(15000,20000));
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(7000,10000));
                        break;
                    case EVENT_LAVA_STRIKE:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            CastLavaStrikeOnTarget(pTarget);
                            if(urand(0,5) == 0)
                                DoScriptText(RAND(SAY_SARTHARION_SPECIAL_1,SAY_SARTHARION_SPECIAL_2,SAY_SARTHARION_SPECIAL_3), me);
                        }
                        events.ScheduleEvent(EVENT_LAVA_STRIKE, (m_bIsSoftEnraged ? urand(1400, 2000) : urand(5000,20000)));
                        break;
                    case EVENT_CALL_TENEBRON:
                        CallDragon(DATA_TENEBRON);
                        break;
                    case EVENT_CALL_SHADRON:
                        CallDragon(DATA_SHADRON);
                        break;
                    case EVENT_CALL_VESPERON:
                        CallDragon(DATA_VESPERON);
                        break;
                }
            }

            // Don't attack current target if he's not visible for us.
            if(me->getVictim()->HasAura(57874, 0))
                me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(uiDiff);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sartharionAI(pCreature);
    };
};

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

#define ACTION_TELEPORT_BACK                    20
#define SHIELD_ON_SHADRON                       30
#define SHIELD_ON_SARTHARION                    40

//to control each dragons common abilities
struct dummy_dragonAI : public ScriptedAI
{
    dummy_dragonAI(Creature* pCreature) : ScriptedAI(pCreature), lSummons(me)
    {       
        pInstance = pCreature->GetInstanceScript();        
    }

    InstanceScript* pInstance;    

    uint32 m_uiWaypointId;
    uint32 m_uiMoveNextTimer;
    int32 m_iPortalRespawnTime;
    bool m_bCanMoveFree;
    bool m_bCanLoot;
    SummonList lSummons;

    /*void Reset()
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        
        m_uiWaypointId = 0;
        m_uiMoveNextTimer = 500;
        m_iPortalRespawnTime = 30000;
        m_bCanMoveFree = false;
        m_bCanLoot = true;
        lSummons.DespawnAll();
    }*/

    void SetData(uint32 type, uint32 value)
    {
        if (type == DATA_CAN_LOOT)
            m_bCanLoot = value;
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (!pInstance || uiType != POINT_MOTION_TYPE)
            return;

        sLog->outDebug(LOG_FILTER_UNITS, "dummy_dragonAI: %s reached point %u", me->GetName(), uiPointId);

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
            m_bCanMoveFree = false;            
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                me->AI()->AttackStart(pTarget);
            return;
        }

        //increase
        m_uiWaypointId = uiPointId+1;

        //if we have reached a point bigger or equal to count, it mean we must reset to point 0
        if (m_uiWaypointId >= MAX_WAYPOINT)
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
        GameObject* pPortal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL,50.0f);
         if (pPortal && !pPortal->isSpawned())
            pPortal->SetRespawnTime(m_iPortalRespawnTime);

        switch(me->GetEntry())
        {
            case NPC_TENEBRON:
            {
                iTextId = WHISPER_HATCH_EGGS;
                if (pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                {
                    for(uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_SARTHARION_TWILIGHT_EGG, TwilightEggsSarth[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,5000);
                }
                else
                {
                    for(uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_TWILIGHT_EGG, TwilightEggs[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,5000);
                }
                break;
            }
            case NPC_SHADRON:
            {
                iTextId = WHISPER_OPEN_PORTAL;
                DoRaidWhisper(WHISPER_SHADRON_DICIPLE);
                if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron, TEMPSUMMON_CORPSE_TIMED_DESPAWN,5000);
                else
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron2, TEMPSUMMON_CORPSE_TIMED_DESPAWN,5000);

                break;
            }
            case NPC_VESPERON:
            {
                DoRaidWhisper(WHISPER_VESPERON_DICIPLE);
                if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)                
                    me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);                    
                else                
                    me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon2, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);  

                iTextId = WHISPER_OPEN_PORTAL;               
                break;
            }
        }

        DoRaidWhisper(iTextId);        
    }

    void JustSummoned(Creature *summon)
    {
        lSummons.Summon(summon);
    }

    void TeleportBack()
    {
        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);
        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_ENTER);
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
                if(pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                    pInstance->SetData(TYPE_TENEBRON_PREKILLED, 1);
                break;
            case NPC_SHADRON:
                iTextId = SAY_SHADRON_DEATH;
                if(pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                {
                    pInstance->SetData(TYPE_SHADRON_PREKILLED, 1);
                    TeleportBack();
                    lSummons.DespawnAll();
                }                
                break;
            case NPC_VESPERON:
                iTextId = SAY_VESPERON_DEATH;
                if (pInstance && pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                {
                    pInstance->SetData(TYPE_VESPERON_PREKILLED, 1);
                    TeleportBack();
                    lSummons.DespawnAll();
                }
                else
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_STACKS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP);
                }
                break;
        }

        DoScriptText(iTextId, me);

        if (pInstance)
        {
            // not if solo mini-boss fight
            if (pInstance->GetData(TYPE_SARTHARION_EVENT) != IN_PROGRESS)
                return;

            // Twilight Revenge to main boss
            if (Unit* pSartharion = Unit::GetUnit((*me), pInstance->GetData64(DATA_SARTHARION)))
                if (pSartharion->isAlive())
                    pSartharion->CastSpell(pSartharion, SPELL_TWILIGHT_REVENGE, true);
            me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }
    }    

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_bCanMoveFree && m_uiMoveNextTimer)
        {
            if (m_uiMoveNextTimer <= uiDiff)
            {
                if (m_uiWaypointId < MAX_WAYPOINT)
                    me->GetMotionMaster()->MovePoint(m_uiWaypointId, m_aDragonCommon[m_uiWaypointId]);

                sLog->outDebug(LOG_FILTER_UNITS, "dummy_dragonAI: %s moving to point %u", me->GetName(), m_uiWaypointId);
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

class mob_tenebron : public CreatureScript
{
    public:
        mob_tenebron(): CreatureScript("mob_tenebron") {}

    struct mob_tenebronAI : public dummy_dragonAI
    {
        mob_tenebronAI(Creature* pCreature) : dummy_dragonAI(pCreature)
        {        
            pInstance = pCreature->GetInstanceScript();
        }

        uint32 m_uiShadowBreathTimer;
        uint32 m_uiShadowFissureTimer;
        uint32 m_uiHatchEggTimer;
        bool m_bHasPortalOpen;
        uint32 Eggs;

        void Reset()
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            me->SetReactState(REACT_AGGRESSIVE);
        
            m_uiWaypointId = 0;
            m_uiMoveNextTimer = 500;
            m_iPortalRespawnTime = 30000;
            m_bCanMoveFree = false;
            m_bCanLoot = true;
            lSummons.DespawnAll();

            m_uiShadowBreathTimer = 20000;
            m_uiShadowFissureTimer = 5000;
            m_uiHatchEggTimer = 30000;
            m_bHasPortalOpen = false;
        }

        void Aggro(Unit* pWho)
        {
            DoScriptText(SAY_TENEBRON_AGGRO, me);
            DoZoneInCombat();
            DoCast(me, SPELL_POWER_OF_TENEBRON);
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_TELEPORT_BACK:
                    Eggs--;
                    break;
            }
        }

        void JustSummoned(Creature *summon)
        {
            Eggs = 6;
        }

        void KilledUnit(Unit* pVictim)
        {
            DoScriptText(RAND(SAY_TENEBRON_SLAY_1,SAY_TENEBRON_SLAY_2), me);        
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (Eggs == 0)
            {
                if (pInstance)
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_ENTER);
                }
            }
            //if no target, update dummy and return
            if (!UpdateVictim())
            {
                dummy_dragonAI::UpdateAI(uiDiff);
                return;
            }

            // shadow fissure
            if (m_uiShadowFissureTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE));

                m_uiShadowFissureTimer = urand(15000,20000);
            }
            else
                m_uiShadowFissureTimer -= uiDiff;

            // Hach Egg
            if (m_uiHatchEggTimer <= uiDiff)
            {
                if(m_bHasPortalOpen)
                    m_uiHatchEggTimer = 10000;
                else
                {
                    OpenPortal();
                    m_uiHatchEggTimer = urand(40000,50000);
                }
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

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_tenebronAI(pCreature);
    };
};

/*######
## Mob Shadron
######*/

class mob_shadron : public CreatureScript
{
    public:
        mob_shadron(): CreatureScript("mob_shadron") {}

    struct mob_shadronAI : public dummy_dragonAI
    {
        mob_shadronAI(Creature* pCreature) : dummy_dragonAI(pCreature) {}

        uint32 m_uiShadowBreathTimer;
        uint32 m_uiShadowFissureTimer;
        uint32 m_uiAcolyteShadronTimer;
        bool m_bHasPortalOpen;

        void Reset()
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            me->SetReactState(REACT_AGGRESSIVE);
        
            m_uiWaypointId = 0;
            m_uiMoveNextTimer = 500;
            m_iPortalRespawnTime = 30000;
            m_bCanMoveFree = false;
            m_bCanLoot = true;
            lSummons.DespawnAll();

            m_uiShadowBreathTimer = 20000;
            m_uiShadowFissureTimer = 5000;
            m_uiAcolyteShadronTimer = 60000;
            m_bHasPortalOpen = false;

            if (me->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);

            if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                me->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);
        }

        void Aggro(Unit* pWho)
        {
            DoScriptText(SAY_SHADRON_AGGRO,me);
            DoZoneInCombat();
            DoCast(me, SPELL_POWER_OF_SHADRON);
        }

       /*void JustDied(Unit* pKiller)
        {
            if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
            {
                TeleportBack();
                lSummons.DespawnAll();
            }
        }*/

        void DoAction(const int32 action)
        {
            switch(action)
            {           
                if (pInstance)
                {
                    case SHIELD_ON_SHADRON:
                        if (Creature* pShadron = Unit::GetCreature(*me, pInstance->GetData64(DATA_SHADRON))) 
                            pShadron->AddAura(SPELL_GIFT_OF_TWILIGTH_SHA, me);                    
                        break;
                    case SHIELD_ON_SARTHARION:
                        /*if (Creature* pSartharion = Unit::GetCreature(*me, pInstance->GetData64(DATA_SARTHARION)))                        
                            pSartharion->AddAura(SPELL_GIFT_OF_TWILIGTH_SAR, pSartharion);*/
                        break;
                }
            }
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
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));

                m_uiShadowFissureTimer = urand(15000,20000);
            }
            else
                m_uiShadowFissureTimer -= uiDiff;

            // Portal Event
            if (m_uiAcolyteShadronTimer <= uiDiff)
            {
                if(m_bHasPortalOpen)
                    return;
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

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_shadronAI(pCreature);
    };
};

/*######
## Mob Vesperon
######*/

class mob_vesperon : public CreatureScript
{
    public:
        mob_vesperon(): CreatureScript("mob_vesperon") {}

    struct mob_vesperonAI : public dummy_dragonAI
    {
        mob_vesperonAI(Creature* pCreature) : dummy_dragonAI(pCreature) {}

        uint32 m_uiShadowBreathTimer;
        uint32 m_uiShadowFissureTimer;
        uint32 m_uiAcolyteVesperonTimer;
        bool m_bHasPortalOpen;

        void Reset()
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            me->SetReactState(REACT_AGGRESSIVE);
        
            m_uiWaypointId = 0;
            m_uiMoveNextTimer = 500;
            m_iPortalRespawnTime = 30000;
            m_bCanMoveFree = false;
            m_bCanLoot = true;
            lSummons.DespawnAll();

            m_uiShadowBreathTimer = 20000;
            m_uiShadowFissureTimer = 5000;
            m_uiAcolyteVesperonTimer = 60000;
            m_bHasPortalOpen = false;        
        }

        void Aggro(Unit* pWho)
        {
            DoScriptText(SAY_VESPERON_AGGRO,me);
            DoZoneInCombat();
            DoCast(me, SPELL_POWER_OF_VESPERON);
        }

        /*void JustDied(Unit* pKiller)
        {
            if (pInstance && !pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
            {
                TeleportBack();
                lSummons.DespawnAll();
            }
            else
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_STACKS);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP);
            }
        }*/

        void KilledUnit(Unit* pVictim)
        {
            DoScriptText(RAND(SAY_VESPERON_SLAY_1,SAY_VESPERON_SLAY_2), me);
        }

        void JustSummoned(Creature *summon)
        {        
            lSummons.Summon(summon);        
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
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));

                m_uiShadowFissureTimer = urand(15000,20000);
            }
            else
                m_uiShadowFissureTimer -= uiDiff;

            // Portal Event
            if (m_uiAcolyteVesperonTimer <= uiDiff)
            {
                if(m_bHasPortalOpen)
                    return;
                else
                {
                    DoCast(me->getVictim(), SPELL_TWILIGHT_TORMENT_VESP, true);
                    OpenPortal();
                    m_bHasPortalOpen = true;
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

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_vesperonAI(pCreature);
    };
};

/*######
## Mob Acolyte of Shadron
######*/

class mob_acolyte_of_shadron : public CreatureScript
{
    public:
        mob_acolyte_of_shadron(): CreatureScript("mob_acolyte_of_shadron") {}
            
    struct mob_acolyte_of_shadronAI : public ScriptedAI
    {
        mob_acolyte_of_shadronAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();            
            me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);
        }

        InstanceScript* pInstance;
        uint32 uiShiftEffectTimer;
        uint32 uiShieldTimer;
        bool shield;

        void Reset()
        {
            uiShieldTimer = 1000;
            uiShiftEffectTimer = 1000;
            shield = false;        
        }

        void JustDied(Unit* killer)
        {
            if (pInstance)
            {
                if (pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                {
                    if (Creature* pSartharion = me->GetCreature(*me, pInstance->GetData64(DATA_SARTHARION)))
                        pSartharion->AI()->DoAction(ACTION_TELEPORT_BACK_SAR);

                    //not solo fight, so main boss has deduff
                    Creature* pDebuffTarget = NULL;
                    pDebuffTarget = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SARTHARION));
                    if (pDebuffTarget && pDebuffTarget->isAlive() && pDebuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SAR))
                        pDebuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SAR);
                }
                else
                {                                
                    Creature* pDebuffTarget = NULL;
                    //event not in progress, then solo fight and must remove debuff mini-boss
                    pDebuffTarget = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SHADRON));
                    if (pDebuffTarget && pDebuffTarget->isAlive() && pDebuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                        pDebuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);                
                }
            
                Creature* Shadron = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SHADRON));
                if(Shadron)
                    (CAST_AI(mob_shadron::mob_shadronAI,Shadron->AI()))->m_bHasPortalOpen = false;                
                
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_ENTER);                
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!shield && uiShieldTimer <= uiDiff)
            {
                Creature* pShadron = Unit::GetCreature(*me, pInstance->GetData64(DATA_SHADRON));
                if (pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                    pShadron->AI()->DoAction(SHIELD_ON_SARTHARION);
                else            
                    pShadron->AI()->DoAction(SHIELD_ON_SHADRON);
                    
                uiShieldTimer = 5000;
                shield = true;
            } else uiShieldTimer -= uiDiff;

            if (!UpdateVictim())
                return;
            
            // Don't attack current target if he's not visible for us.
            if(!me->getVictim()->HasAura(57874, 0))
                me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    { 
        return new mob_acolyte_of_shadronAI(pCreature);
    };
};

/*######
## Mob Acolyte of Vesperon
######*/

class mob_acolyte_of_vesperon : public CreatureScript
{
    public:
        mob_acolyte_of_vesperon(): CreatureScript("mob_acolyte_of_vesperon") {}

    struct mob_acolyte_of_vesperonAI : public ScriptedAI
    {
        mob_acolyte_of_vesperonAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();

            me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);
            ToInterrupt = true;
            CheckForInterrupt = 2000;
        }

        InstanceScript* pInstance; 
        bool ToInterrupt;
        uint32 CheckForInterrupt;

        void Reset()
        {
            ToInterrupt = true;
            CheckForInterrupt = 2000;            
        }

        void EnterCombat(Unit* who){}
        
        void JustDied(Unit* pKiller)
        {
            // remove twilight torment on Vesperon
            if (pInstance)
            {
                Creature* pVesperon = pInstance->instance->GetCreature(pInstance->GetData64(DATA_VESPERON));
                if (pVesperon)
                    (CAST_AI(mob_vesperon::mob_vesperonAI,pVesperon->AI()))->m_bHasPortalOpen = false;

                if (pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                {
                    if (Creature* pSartharion = me->GetCreature(*me, pInstance->GetData64(DATA_SARTHARION)))
                        pSartharion->AI()->DoAction(ACTION_TELEPORT_BACK_SAR);
                }
                else
                {                
                    Creature* Shadron = pInstance->instance->GetCreature(pInstance->GetData64(DATA_SHADRON));
                    if(Shadron)
                        (CAST_AI(mob_shadron::mob_shadronAI,Shadron->AI()))->m_bHasPortalOpen = false;

                    pInstance->DoRemoveAurasDueToSpellOnPlayers(57935);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_ENTER);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);                
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {  
            // This is needed for interrupt Vesperon.
            if (ToInterrupt && CheckForInterrupt <= uiDiff)
            {
                Creature* pTarget = pInstance->instance->GetCreature(pInstance->GetData64(DATA_VESPERON));
                if (pTarget)
                {
                    pTarget->InterruptNonMeleeSpells(true, 0, true);
                    ToInterrupt = false;
                    CheckForInterrupt = 5000;
                }
            }
            else
                CheckForInterrupt -= uiDiff;

            if (!UpdateVictim())
                return;

            if(!me->getVictim()->HasAura(57874, 0))
                me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_acolyte_of_vesperonAI(pCreature);
    };
};

/*######
## Mob Twilight Eggs
######*/

class mob_twilight_eggs : public CreatureScript
{
    public:
            mob_twilight_eggs(): CreatureScript("mob_twilight_eggs") {}

    struct mob_twilight_eggsAI : public Scripted_NoMovementAI
    {
        mob_twilight_eggsAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }
        uint32 m_uiFadeArmorTimer;
        uint32 m_uiHatchEggTimer;    

        InstanceScript* pInstance;

        void Reset()
        {
            if(pInstance)
            {
                me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER,me);
            }
            m_uiHatchEggTimer = 20000;
            m_uiFadeArmorTimer = 1000;        
        }
        void JustDied (Unit *victim)
        {
            if (Creature* pTenebron = me->GetCreature(*me, pInstance->GetData64(DATA_TENEBRON)))
            pTenebron->AI()->DoAction(ACTION_TELEPORT_BACK);
        }
        void SpawnWhelps()
        {
            if (!pInstance->GetData(TYPE_SARTHARION_EVENT) == IN_PROGRESS)
                me->SummonCreature(NPC_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
            else
                me->SummonCreature(NPC_SHARTHARION_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);        
        }
        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiHatchEggTimer <= uiDiff)
            {
                Creature* Tenebron = pInstance->instance->GetCreature(pInstance->GetData64(DATA_TENEBRON));
                if(Tenebron)
                    (CAST_AI(mob_tenebron::mob_tenebronAI,Tenebron->AI()))->m_bHasPortalOpen = false;
                SpawnWhelps();
            }
            else
                m_uiHatchEggTimer -= uiDiff;
        }
        void JustSummoned(Creature *summon)
        {
            summon->AI()->DoZoneInCombat();
            summon->DealDamage(me, me->GetHealth());       
        }    
        void AttackStart(Unit* pWho) {}
        void MoveInLineOfSight(Unit* pWho) {}
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_twilight_eggsAI(pCreature);
    };
};

/*######
## Flame Tzunami
######*/

class npc_flame_tsunami : public CreatureScript
{
    public:
        npc_flame_tsunami(): CreatureScript("npc_flame_tsunami") {}

    struct npc_flame_tsunamiAI : public ScriptedAI
    {
        npc_flame_tsunamiAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->AddAura(SPELL_FLAME_TSUNAMI, me);        
            me->SetFlying(true);
            //me->SetSpeed(MOVE_FLIGHT, 2.1f, true);
        }

        uint32 uiStartMove;
        bool bMoved;

        void Reset()
        {
            uiStartMove = 3 * IN_MILLISECONDS;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            bMoved = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!bMoved)
            {
                if (uiStartMove <= diff)
                {
                    Position pos;
                    me->GetPosition(&pos);
                    DoCast(me, SPELL_FLAME_TSUNAMI_DMG_AURA);
                    pos.m_positionX -= pos.GetPositionX() < 3240.0f ? -82.0f : 82.0f;
                    me->GetMotionMaster()->MovePoint(0, pos);
                    bMoved = true;
                }
                else uiStartMove -= diff;
            }
        }
    };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_flame_tsunamiAI(pCreature);
    };
};

/*######
## Twilight Fissure
######*/

class npc_twilight_fissure : public CreatureScript
{
    public:
        npc_twilight_fissure(): CreatureScript("npc_twilight_fissure") {}
        
    struct npc_twilight_fissureAI : public Scripted_NoMovementAI
    {
        npc_twilight_fissureAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) {}

        uint32 VoidBlast_Timer;

        void Reset()
        {
            VoidBlast_Timer = 5000;        
        }

        void UpdateAI(const uint32 diff)
        {
            if (VoidBlast_Timer <= diff)
            {
                DoCast(RAID_MODE(SPELL_VOID_BLAST,SPELL_VOID_BLAST_H ));
                VoidBlast_Timer = 9000;
                //me->Kill(me);
                me->DisappearAndDie();
            } else VoidBlast_Timer -= diff;
        }
    };   

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_twilight_fissureAI(pCreature);
    };
};

/*######
## Mob Twilight Whelps
######*/

class mob_twilight_whelp : public CreatureScript
{
    public:
        mob_twilight_whelp(): CreatureScript("mob_twilight_whelp") {}

    struct mob_twilight_whelpAI : public ScriptedAI
    {
        mob_twilight_whelpAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 m_uiFadeArmorTimer;

        void Reset()
        {        
            me->RemoveAllAuras();
            m_uiFadeArmorTimer = 1000;
            me->SetPhaseMask(1, true);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            me->SetInCombatWithZone();
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_twilight_whelpAI(pCreature);
    };
};

void AddSC_boss_sartharion()
{
    new boss_sartharion();
    new mob_vesperon();
    new mob_shadron();
    new mob_tenebron();
    new mob_acolyte_of_shadron();
    new mob_acolyte_of_vesperon();
    new mob_twilight_eggs();
    new npc_flame_tsunami();
    new npc_twilight_fissure();
    new mob_twilight_whelp();
}