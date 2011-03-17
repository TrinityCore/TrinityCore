/*
* Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum Yells
{
    SAY_AGGRO       = -1666063,
    SAY_BELOW_25    = -1666066,
    SAY_ABOVE_75    = -1666065,
    SAY_DEATH       = -1666067,
    SAY_PDEATH      = -1666068,
    SAY_END         = -1666070,
    SAY_FAILURES    = -1666069,
    SAY_OPEN_PORTAL = -1666064
};

enum Spells
{
    SPELL_FEIGN_DEATH                   = 71598,
    SPELL_CORRUPTION    = 70904,
    SPELL_DREAM_SLIP    = 71196,
    SPELL_RAGE          = 71189,
    SPELL_COLUMN_PRE    = 70704,
    SPELL_COLUMN_EFFECT_10N = 70702,
    SPELL_COLUMN_EFFECT_10H_25N = 71746,
    SPELL_COLUMN_EFFECT_25H = 72020,
   
    SPELL_SUMMON_ROT_WORMS_AURA = 70675,
    SPELL_SUMMON_ROT_WORM_VISUAL = 70668,

    SPELL_DREAM_STATE   = 70766,
    SPELL_VIGOR         = 70873,
    SPELL_TWISTED_NIGHTMARES = 71941,
    SPELL_CLOUD_VISUAL  = 70876,
    SPELL_PORTAL_N_PRE  = 71301,
    SPELL_PORTAL_N_NPC  = 71305,
    SPELL_PORTAL_H_PRE  = 71977,
    SPELL_PORTAL_H_NPC  = 71987,
    SPELL_SUMMON_PORTAL_TO_DREAM = 72482,

    SPELL_DREAM_PORTAL_VISUAL = 70763,
    SPELL_NIGHTMARE_PORTAL_VISUAL = 71994,
    SPELL_DREAM_PORTAL_PRE_VISUAL = 71304,
    SPELL_NIGHTMARE_PORTAL_PRE_VISUAL = 71986,

    SPELL_COPY_DAMAGE                   = 71948, 
    //SPELL_SUMMON_SUPPRESSOR_PERIODIC    = 70912,
    //SPELL_SUMMON_FIRE_SKELETON_PERIODIC = 70913,
    //SPELL_SUMMON_ZOMBIE_PERIODIC        = 70914,
    //SPELL_SUMMON_ABOMINATION_PERIODIC   = 70915,
    //SPELL_SUMMON_ARCHMAGE_PERIODIC      = 70916,
    //SPELL_SUMMON_SUPPRESSOR             = 70935,

    SPEEL_CLEAR_AURA                    = 75863,
    SPELL_CANCEL_ALL_AURAS              = 71721, 

    SPELL_NIGHTMARE_DAMAGE              = 71946,

    //Blistering Zombie spells
    SPELL_ACID_BURST_10N                = 70744,
    SPELL_ACID_BURST_10H                = 72017,
    SPELL_ACID_BURST_25N                = 71733,
    SPELL_ACID_BURST_25H                = 72018,

    SPELL_CORROSION_10N                 = 70751,
    SPELL_CORROSION_10H                 = 71738,
    SPELL_CORROSION_25N                 = 72021,
    SPELL_CORROSION_25H                 = 72022,
    //Gluttonous Abomination spell
    SPELL_GUT_SPRAY_10N                 = 70633,
    SPELL_GUT_SPRAY_10H                 = 72025,
    SPELL_GUT_SPRAY_25N                 = 71283,
    SPELL_GUT_SPRAY_25H                 = 72026,

    SPELL_FLESH_ROT_10N                 = 72963,
    SPELL_FLESH_ROT_10H                 = 72964,
    SPELL_FLESH_ROT_25N                 = 72965,
    SPELL_FLESH_ROT_25H                 = 72966,
    //Risen Archmage spells
    SPELL_FROSTBOLT_VOLLEY              = 70759,
    SPELL_SUMMON_MANA_VOID              = 71179,

    SPELL_FIREBALL                      = 70754,
    SPELL_LAY_WASTE                     = 69325,
    SPELL_SUPPRESSION                   = 70588
};

enum eEvents
{
    EVENT_SUMMON_DREAM_CLOUD        = 1,
    EVENT_DESPAWN,
    EVENT_DESPAWN_AND_FAIL_ACHIEVEMENT,
    //Events played when boss is healed up to 100%
    EVENT_BERSERK,
    EVENT_EVADE_TO_DREAM_SLIP,

    //Adds
    EVENT_SUMMON_ZOMBIE_AND_ARCHMAGE,
    EVENT_SUMMON_ZOMBIE,
    EVENT_SUMMON_ARCHMAGE,
    EVENT_SUMMON_ABOMINATION,
    EVENT_SUMMON_SUPPRESSOR,
    EVENT_SUMMON_BLAZING_SKELETON,
    EVENT_CAST_COLUMN_OF_FROST,

    //Portals
    EVENT_SUMMON_PORTALS_TO_DREAM,
    EVENT_OPEN_PORTAL_TO_DREAM,
    EVENT_EXPLODE,
    EVENT_CLOUD_EMULATE_DESPAWN,
    EVENT_CLOUD_EMULATE_RESPAWN,
    EVENT_INTRO,
    EVENT_START_INTRO,

    EVENT_CHECK_WIPE,
    EVENT_CAST_ROT_WORM_SPAWN_ANIMATION,

    EVENT_GUT_SPRAY,
    EVENT_ENABLE_CASTING, 
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_SUMMON_MANA_VOID,
    EVENT_CAST_SUPPRESSION,

    EVENT_CAST_FIREBALL,
    EVENT_CAST_LAY_WASTE
};
enum eValithriaData
{
    DATA_INSTANCE_DIFFICULTY = 1,
    DATA_SUMMONED_LAST_PORTALS = 2
};
enum eActions
{
    ACTION_WIPE = 1
};
#define FACTION_STORMWIND 11
#define FACTION_ORGRIMMAR 1612

const Position Pos[] =
{
    {4239.579102f, 2566.753418f, 364.868439f, 0.0f}, //normal 0,1
    {4240.688477f, 2405.794678f, 364.868591f, 0.0f}, // normal
    {4165.112305f, 2405.872559f, 364.872925f, 0.0f}, //2,3
    {4166.216797f, 2564.197266f, 364.873047f, 0.0f}
};

void Cleanup(Creature *me, InstanceScript *instance, float radius)
{
    //Despawn heroic mode-specific mobs
    UnsummonSpecificCreaturesNearby(me, NPC_PORTAL_HEROIC_MODE_PRE, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_PORTAL_HEROIC_MODE_NPC, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_NIGHTMARE_CLOUD, radius);
    
    //Despawn normal mode-specific mobs
    UnsummonSpecificCreaturesNearby(me, NPC_PORTAL_NORMAL_MODE_PRE, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_PORTAL_NORMAL_MODE_NPC, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_DREAM_CLOUD, radius);

    UnsummonSpecificCreaturesNearby(me, NPC_ZOMBIE, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_SKELETON, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_ARCHMAGE, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_SUPPRESSOR, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_ABOMINATION, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_ROT_WORM, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_COLUMN_OF_FROST, radius);
    UnsummonSpecificCreaturesNearby(me, NPC_MANA_VOID, radius);

    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VIGOR);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWISTED_NIGHTMARES);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DREAM_STATE);
    instance->DoRemoveAurasDueToSpellOnPlayers(((ScriptedAI*)me->AI())->RAID_MODE<uint32>(SPELL_ACID_BURST_10N, SPELL_ACID_BURST_25N, SPELL_ACID_BURST_10H, SPELL_ACID_BURST_25H));
    instance->DoRemoveAurasDueToSpellOnPlayers(((ScriptedAI*)me->AI())->RAID_MODE<uint32>(SPELL_CORROSION_10N, SPELL_CORROSION_25N, SPELL_CORROSION_10H, SPELL_CORROSION_25H));
    instance->DoRemoveAurasDueToSpellOnPlayers(((ScriptedAI*)me->AI())->RAID_MODE<uint32>(SPELL_FLESH_ROT_10N, SPELL_FLESH_ROT_25N, SPELL_FLESH_ROT_10H, SPELL_FLESH_ROT_25H));
}


class boss_valithria : public CreatureScript
{
    public:
        boss_valithria() : CreatureScript("boss_valithria") { }

        struct boss_valithriaAI : public BossAI
        {
            boss_valithriaAI(Creature* pCreature) : BossAI(pCreature, DATA_VALITHRIA_DREAMWALKER_EVENT)
            {
                //Make Valithria immune to column of frost in case it's spawned near her
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->SetSpeed(MOVE_RUN, 0.0f, true);
                me->SetSpeed(MOVE_WALK, 0.0f, true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE); // 3.0.3 - makes you unable to attack everything
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                Map::PlayerList const &players = me->GetMap()->GetPlayers();
                uint32 TeamInInstance = 0;
                if (!players.isEmpty())
                {
                    if (Player* pPlayer = players.begin()->getSource())
                        TeamInInstance = pPlayer->GetTeam();
                }
                if (TeamInInstance == ALLIANCE)
                    me->setFaction(FACTION_STORMWIND);
                else
                    me->setFaction(FACTION_ORGRIMMAR);
                if(SpellEntry* spellSuppression = GET_SPELL(SPELL_SUPPRESSION))
                    spellSuppression->ChannelInterruptFlags &= (~((uint32)(SPELL_INTERRUPT_FLAG_AUTOATTACK)));
            }

            void JustDied(Unit* killer)
            {
                me->Respawn();
                DoCast(me, SPELL_CORRUPTION);
                DoAction(ACTION_WIPE);
            }

            void JustRespawned()
            {
                me->SetHealth(me->GetMaxHealth() / 2);
            }

            void Reset()
            {
                events.Reset();
                DoCast(me, SPEEL_CLEAR_AURA);
                DoCast(me, SPELL_CORRUPTION);
                me->SetHealth(uint32(me->GetMaxHealth() / 2));

                bIntro = false;
                bEnd = false;
                bAboveHP = false;
                bBelowHP = false;
                bSummonedLastPortals = false;
                DoCast(SPELL_COPY_DAMAGE);
                if(SpellEntry* copy = GET_SPELL(SPELL_COPY_DAMAGE))
                    copy->Targets = 18;

            }
            void DoAction(const int32 action)
            {
                if (action == EVENT_INTRO)
                {
                    Reset();
                    if (Creature* combatTrigger = me->GetCreature(*me, instance->GetData64(GUID_VALITHRIA_COMBAT_TRIGGER)))
                        me->getThreatManager().addThreat(combatTrigger, 1.0f);
                    
                    me->GetInstanceScript()->SetData(DATA_PORTAL_JOCKEY_ACHIEVEMENT, (uint32)true);
                    if (IsHeroic())
                        DoCast(me, SPELL_NIGHTMARE_DAMAGE);
                    events.ScheduleEvent(EVENT_INTRO, 10000);
                }
                if (action == ACTION_WIPE)
                {
                    instance->SetData(DATA_VALITHRIA_DREAMWALKER_EVENT, FAIL);
                    Reset();
                    events.Reset();
                    DoScriptText(SAY_FAILURES, me);
                    CastRage();
                    instance->SetBossState(DATA_VALITHRIA_DREAMWALKER_EVENT, FAIL);
                    instance->SetData(DATA_VALITHRIA_DREAMWALKER_EVENT, FAIL);
                    Cleanup(me, instance, 100.0f);
                    if (Creature* combatTrigger = me->GetCreature(*me, instance->GetData64(GUID_VALITHRIA_COMBAT_TRIGGER)))
                        combatTrigger->AI()->EnterEvadeMode();
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_CORRUPTION);
                    me->SetHealth(uint32(me->GetMaxHealth() / 2));
                    EnterEvadeMode();
                    return;
                }
            }
 
            uint32 GetData(uint32 id)
            {
                switch (id)
                {
                    case DATA_INSTANCE_DIFFICULTY:
                        return RAID_MODE(10, 25, 10, 25);
                    case DATA_SUMMONED_LAST_PORTALS:
                        return bSummonedLastPortals;
                }
                return BossAI::GetData(id);
            }

            void CheckHealth()
            {
                //Prevent healing while encounter isn't in progress
                if (instance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT) != IN_PROGRESS)
                {
                    me->SetHealth(uint32(me->GetMaxHealth() / 2));
                    return;
                }
                switch (instance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT))
                {
                    case DONE:
                        return;
                    case NOT_STARTED:
                    {
                        //Disallow healing while encounter isn't in progress
                        if (Creature* combatTrigger = me->GetCreature(*me, instance->GetData64(GUID_VALITHRIA_COMBAT_TRIGGER)))
                            combatTrigger->AI()->EnterEvadeMode();
                        break;
                    }
                    default:
                        break;
                }
                if (HealthBelowPct(2))
                {
                    DoAction(ACTION_WIPE);
                    return;
                }
                if (!bAboveHP && HealthAbovePct(74))
                {
                    DoScriptText(SAY_ABOVE_75, me);
                    float curScale = me->GetFloatValue(OBJECT_FIELD_SCALE_X);
                    me->SetFloatValue(OBJECT_FIELD_SCALE_X, curScale * 1.25f);
                    //Need to increase her in size
                    bAboveHP = true;
                    bBelowHP = false;
                }
                if (!bBelowHP && HealthBelowPct(26))
                {
                    DoScriptText(SAY_BELOW_25, me);
                    //Need to decrease her in size
                    bBelowHP = true;
                    bAboveHP = false;
                }
                if (bSummonedLastPortals && HealthBelowPct(91))
                {
                    //Reset summoning last 3 portals event
                    bSummonedLastPortals = false;
                }
                if (!bSummonedLastPortals && HealthAbovePct(94))
                {
                    bSummonedLastPortals = true;
                    //It's very much worth noting that if Dreamwalker spawns 3 portals when almost healed to 100%
                    for (uint8 i = 0; i < 3; ++i)
                        DoCast(RAID_MODE(SPELL_PORTAL_N_PRE,SPELL_PORTAL_N_PRE,SPELL_PORTAL_H_PRE,SPELL_PORTAL_H_PRE));
                }
                if (!bEnd && HealthAbovePct(99))
                {
                    DoScriptText(SAY_END, me);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(me, SPELL_CANCEL_ALL_AURAS);
                    me->RemoveAurasDueToSpell(SPELL_CORRUPTION);
                    bEnd = true;
                    events.Reset();
                    events.ScheduleEvent(EVENT_BERSERK, 1000);
                    instance->DoCompleteAchievement(RAID_MODE<uint32>(ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_10N, ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_25N, ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_10H, ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_25H));
                    TPlayerList players = GetPlayersInTheMap(me->GetMap());
                    for (TPlayerList::iterator it = players.begin(); it != players.end(); ++it)
                        (*it)->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                    if (instance->GetData(DATA_PORTAL_JOCKEY_ACHIEVEMENT))
                        instance->DoCompleteAchievement(RAID_MODE(ACHIEV_PORTAL_JOCKEY_10, ACHIEV_PORTAL_JOCKEY_25, ACHIEV_PORTAL_JOCKEY_10, ACHIEV_PORTAL_JOCKEY_25)); 
                }
            }

            void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/)
            {
                CheckHealth();
            }

            void HealReceived(Unit* /*done_by*/, uint32& /*addhealth*/)
            {
                CheckHealth();
            }
            void CastRage()
            {
                TPlayerList players = GetPlayersInTheMap(me->GetMap());
                for (TPlayerList::iterator it = players.begin(); it != players.end(); ++it)
                    (*it)->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RAGE, true);
                Unit *summonedMob = NULL;
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_ZOMBIE, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_SKELETON, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_ARCHMAGE, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_SUPPRESSOR, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_ABOMINATION, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_ROT_WORM, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_COLUMN_OF_FROST, 100.0f);
                if (!summonedMob)
                    summonedMob = me->FindNearestCreature(NPC_MANA_VOID, 100.0f);
                if (summonedMob)
                    DoCast(summonedMob, SPELL_RAGE);
                else
                    Cleanup(me, instance, 100.0f);
            }
            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO:
                        {
                            DoScriptText(SAY_AGGRO, me);
                            //events.ScheduleEvent(EVENT_SUMMON_ADDS, 10000);
                            events.ScheduleEvent(EVENT_SUMMON_PORTALS_TO_DREAM, 35000);
                            break;
                        }
                        case EVENT_SUMMON_PORTALS_TO_DREAM:
                        {
                            DoScriptText(SAY_OPEN_PORTAL, me);
                            //DoCast(SPELL_SUMMON_PORTAL_TO_DREAM);
                            //Need to check, maybe, this isn't required
                            for(uint8 p = 0; p < RAID_MODE<uint8>(3, 8, 3, 8); ++p)
                                DoCast(RAID_MODE(SPELL_PORTAL_N_PRE,SPELL_PORTAL_N_PRE,SPELL_PORTAL_H_PRE,SPELL_PORTAL_H_PRE));
                            if (Creature* valithriaAlternative = Unit::GetCreature(*me, instance->GetData64(GUID_VALITHRIA_ALTERNATIVE)))
                                valithriaAlternative->AI()->DoAction(EVENT_SUMMON_DREAM_CLOUD);
                            events.ScheduleEvent(EVENT_SUMMON_PORTALS_TO_DREAM, 50000);
                            break;
                        }
                        case EVENT_BERSERK:
                        {
                            CastRage();
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            events.ScheduleEvent(EVENT_EVADE_TO_DREAM_SLIP, 6000);
                            break;
                        }
                        case EVENT_EVADE_TO_DREAM_SLIP:
                        {
                            DoCast(SPELL_DREAM_SLIP);
                            events.ScheduleEvent(EVENT_DESPAWN, 1000);
                            break;
                        }
                        case EVENT_DESPAWN:
                        {
                            Cleanup(me, instance, 100.0f);
                            instance->SetData(DATA_VALITHRIA_DREAMWALKER_EVENT, DONE);
                            TPlayerList players = GetPlayersInTheMap(me->GetMap());
                            for (TPlayerList::iterator it = players.begin(); it != players.end(); ++it)
                                (*it)->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                            if (Creature* combatTrigger = me->GetCreature(*me, instance->GetData64(GUID_VALITHRIA_COMBAT_TRIGGER)))
                                combatTrigger->DespawnOrUnsummon();
                            me->DespawnOrUnsummon();
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:

            bool bIntro;
            bool bEnd;
            bool bAboveHP;
            bool bBelowHP;
            bool bSummonedLastPortals;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_valithriaAI(pCreature);
        }
};

//Dream related NCPs and spells
class npc_valithria_alternative : public CreatureScript
{
    public:
        npc_valithria_alternative() : CreatureScript("npc_valithria_alternative") { }

        struct npc_valithria_alternativeAI : public ScriptedAI
        {
            npc_valithria_alternativeAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                numberOfClouds = RAID_MODE<uint8>(15, 50, 15, 50);
                distMax = RAID_MODE<float>(35.0f, 50.0f, 35.0f, 50.0f);
            }

            void Reset()
            {
                events.Reset();
                me->SetPhaseMask(16, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
                me->SendMovementFlagUpdate();
                me->SetFlying(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                //events.ScheduleEvent(EVENT_SUMMON_DREAM_CLOUD, 15000);
                me->GetPosition(x,y,z);
                bAlreadySummonedClouds = false;
            }
            void DoAction(const int32 action)
            {
                //Clouds do not respawn in heroic mode
                if (action == EVENT_SUMMON_DREAM_CLOUD && !(IsHeroic() && bAlreadySummonedClouds))
                {
                    bAlreadySummonedClouds = true;
                    const uint32 cloudEntry = IsHeroic() ? NPC_NIGHTMARE_CLOUD : NPC_DREAM_CLOUD;
                    UnsummonSpecificCreaturesNearby(me, cloudEntry, 80.0f);
                    float angle, summonX, summonY, summonZ, distMin = 20.0f, zVariation = 15.0f, summonDist;
                    //Summon Dream clouds in a circle pattern, but randomize their positions a little (random angle and random Z coordinate)
                    for(uint8 i = 0; i <= numberOfClouds; ++i) //need correct count
                    {
                        //angle = (float)rand_norm() * static_cast<float>(2 * M_PI);
                        //Distribute portals evenly around the boss, with a little angle variation
                        angle = static_cast<float>(2 * M_PI) * i / numberOfClouds + (float)rand_norm() * 0.07;
                        summonDist = distMin + (distMax - distMin) * (float)rand_norm();
                        summonX = x + summonDist * cos(angle);
                        summonY = y + summonDist * sin(angle);
                        summonZ = z + (float)rand_norm() * zVariation - zVariation / 2.0f;
                        //Trinity::NormalizeMapCoord(summonX);
                        //Trinity::NormalizeMapCoord(summonY);
                        me->SummonCreature(cloudEntry, summonX, summonY, summonZ, 0, TEMPSUMMON_TIMED_DESPAWN, IsHeroic() ? 600000 : 50000);
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            bool bAlreadySummonedClouds;
            float x, y, z, distMax;
            uint8 numberOfClouds;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_valithria_alternativeAI(pCreature);
        }
}; 

class npc_dreamportal_icc : public CreatureScript
{
    public:
        npc_dreamportal_icc() : CreatureScript("npc_dreamportal_icc") { }

        struct npc_dreamportal_iccAI : public Scripted_NoMovementAI
        {
            npc_dreamportal_iccAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                me->SetSpeed(MOVE_WALK, 0.0f);
                me->SetSpeed(MOVE_RUN, 0.0f);
                me->SetReactState(REACT_PASSIVE);
                events.Reset();
                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                    if (valithria->GetAI()->GetData(DATA_SUMMONED_LAST_PORTALS))
                        //Last 3 portals should be opened almost immediately after they were summoned
                        events.ScheduleEvent(EVENT_OPEN_PORTAL_TO_DREAM, 1000);
                    else
                        events.ScheduleEvent(EVENT_OPEN_PORTAL_TO_DREAM, 15000);
                if (IsHeroic())
                    DoCast(me, SPELL_NIGHTMARE_PORTAL_PRE_VISUAL);
                else
                    DoCast(me, SPELL_DREAM_PORTAL_PRE_VISUAL);
            }

            void DoAction(const int32 action)
            {
                if (action == EVENT_SPELLCLICK)
                    events.ScheduleEvent(EVENT_DESPAWN, 100);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_OPEN_PORTAL_TO_DREAM:
                        {
                            if(me->GetEntry() == NPC_PORTAL_NORMAL_MODE_PRE)
                            {
                                me->UpdateEntry(NPC_PORTAL_NORMAL_MODE_NPC);
                                //Portal to Dream or Portal to Nightmare respectively
                                DoCast(me, SPELL_DREAM_PORTAL_VISUAL);
                            }
                            else
                                if(me->GetEntry() == NPC_PORTAL_HEROIC_MODE_PRE)
                                {
                                    me->UpdateEntry(NPC_PORTAL_HEROIC_MODE_NPC);
                                    DoCast(me, SPELL_NIGHTMARE_PORTAL_VISUAL);
                                }
                            events.ScheduleEvent(EVENT_DESPAWN_AND_FAIL_ACHIEVEMENT, 15000);
                            break;
                        }
                        case EVENT_DESPAWN_AND_FAIL_ACHIEVEMENT:
                        {
                            me->GetInstanceScript()->SetData(DATA_PORTAL_JOCKEY_ACHIEVEMENT, (uint32)false);
                            me->DespawnOrUnsummon();
                            break;
                        }
                        case EVENT_DESPAWN:
                        {
                            me->DespawnOrUnsummon();
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            uint32 m_uiChangeTimer;
            InstanceScript *pInstance;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dreamportal_iccAI(pCreature);
        }
};

class npc_dreamcloud_icc : public CreatureScript 
{
    public:
        npc_dreamcloud_icc() : CreatureScript("npc_dreamcloud_icc") { }

        struct npc_dreamcloud_iccAI : public ScriptedAI
        {
            npc_dreamcloud_iccAI(Creature* pCreature) : ScriptedAI(pCreature) { }

            void Reset()
            {
                canApplyBuff = true;
                events.Reset();
                me->SetPhaseMask(16, true);
                DoCast(SPELL_CLOUD_VISUAL);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
                me->SendMovementFlagUpdate();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void MoveInLineOfSight(Unit *who)
            {
                if (canApplyBuff && me->IsWithinDistInMap(who, 5.0f, true) && who->GetTypeId() == TYPEID_PLAYER)
                {
                    canApplyBuff = false;
                    //Cloud will explode in about 1-2 seconds after player touch it
                    events.ScheduleEvent(EVENT_EXPLODE, 1500);
                }
                ScriptedAI::MoveInLineOfSight(who);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EXPLODE:
                        {
                            //Apply buff to player
                            const uint32 spellId = IsHeroic() ? SPELL_TWISTED_NIGHTMARES : SPELL_VIGOR;
                            //Apply buff only if player is within 5 feet of the cloud
                            DoCast(me, spellId, true);

                            //Just show explode animation effect
                            events.ScheduleEvent(EVENT_CLOUD_EMULATE_DESPAWN, 2000);
                            break;
                        }
                        case EVENT_CLOUD_EMULATE_DESPAWN:
                        {
                            me->SetVisible(false);
                            //In normal mode, the clouds have a very fast respawn so you won’t run the risk of running out of them. 
                            if (!IsHeroic())
                                events.ScheduleEvent(EVENT_CLOUD_EMULATE_RESPAWN, 7000);
                            break;
                        }
                        case EVENT_CLOUD_EMULATE_RESPAWN:
                        {
                            me->SetVisible(true);
                            canApplyBuff = true;
                        }
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
            bool canApplyBuff;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dreamcloud_iccAI(pCreature);
        }
};

class spell_valithria_vigor : public SpellScriptLoader
{
    public:
        spell_valithria_vigor() : SpellScriptLoader("spell_valithria_vigor") { }

        class spell_valithria_vigor_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valithria_vigor_SpellScript);

            bool Load()
            {
                playersAuraStacks.clear();
                return true;
            }

            void EnsureThatAurasStack()
            {
                if (!(GetHitUnit() && GetHitUnit()->isAlive()))
                    return;
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;

                if (Unit *who = GetHitUnit())
                {
                    uint32 curSpellId = GetSpellInfo()->Id;
                    if (Aura* existingAura = who->GetAura(curSpellId))
                    {
                        playersAuraStacks[who->GetGUID()] = existingAura->GetStackAmount();
                    }
                }
            }

            void RemoveImmunity()
            {
                if (Unit* target = GetHitUnit())
                {
                    if (playersAuraStacks[target->GetGUID()])
                    {
                        if (Aura* existingAura = GetHitUnit()->GetAura(GetSpellInfo()->Id))
                        {
                            existingAura->SetStackAmount(playersAuraStacks[target->GetGUID()]+1);
                            existingAura->RefreshDuration();
                        }
                    }
                }
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_valithria_vigor_SpellScript::EnsureThatAurasStack);
                AfterHit += SpellHitFn(spell_valithria_vigor_SpellScript::RemoveImmunity);
            }
        private:
            std::map<uint64, uint8> playersAuraStacks;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_valithria_vigor_SpellScript();
        }
};

class spell_dream_state : public SpellScriptLoader
{
    public:
        spell_dream_state() : SpellScriptLoader("spell_dream_state") { }

        class spell_dream_state_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dream_state_SpellScript);

            void OnEnterDreamState()
            {
                if (!(GetHitUnit() && GetHitUnit()->isAlive()))
                    return;
                //Clear threat list before entering Dream State
                GetHitUnit()->getThreatManager().clearReferences();
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_dream_state_SpellScript::OnEnterDreamState);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dream_state_SpellScript();
        }
};

//End of Dream related NPCs and spells
class npc_column_of_frost_icc : public CreatureScript 
{
    public:
        npc_column_of_frost_icc() : CreatureScript("npc_column_of_frost_icc") { }

        struct npc_column_of_frost_iccAI : public ScriptedAI
        {
            npc_column_of_frost_iccAI(Creature* pCreature) : ScriptedAI(pCreature) { }
            void Reset()
            {
                events.ScheduleEvent(EVENT_CAST_COLUMN_OF_FROST, 2000);
                //Knockback value fix
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 50.0f);
            }
            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_COLUMN_OF_FROST:
                        {
                            uint32 effectId = RAID_MODE<uint32>(SPELL_COLUMN_EFFECT_10N, SPELL_COLUMN_EFFECT_10H_25N, SPELL_COLUMN_EFFECT_10H_25N, SPELL_COLUMN_EFFECT_25H);
                            DoCast(me, effectId, true);
                            events.ScheduleEvent(EVENT_DESPAWN, 3500);
                            break;
                        }
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_column_of_frost_iccAI(pCreature);
        }
};

class npc_icc_combat_stalker : public CreatureScript
{
    public:
        npc_icc_combat_stalker() : CreatureScript("npc_icc_combat_stalker") { }

        struct npc_icc_combat_stalkerAI : public ScriptedAI
        {
            npc_icc_combat_stalkerAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                pInstance = me->GetInstanceScript();
            }

            void DamageTaken(Unit* /*done_by*/, uint32& damage)
            {
                damage = 0;
                me->SetFullHealth();
            }
            void JustDied(Unit* killer)
            {
                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                    DoScriptText(SAY_FAILURES, me);
            }
            void EnterCombat(Unit* who)
            {   
                bSummonColumns = false;
                bSummonZombies = true;
                bSummonAbominations = true;
                bSummonArchmages = true;
                bSummonSkeletons = true;
                bSummonSuppressors = true;

                events.Reset();
                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                    AttackStart(valithria);
                me->getThreatManager().addThreat(who, 5000);
                DoZoneInCombat(me);
                m_uiSummonSkeletonTimer = 70000;
                m_uiSummonSuppressorTimer = 60000;
                uint32 delayForKill4Mages = 0;
                if (me->FindNearestCreature(NPC_ARCHMAGE, 100.0f, true))
                    delayForKill4Mages = RAID_MODE<uint32>(20000, 25000, 20000, 25000);
                //Timings were taken from http://www.youtube.com/watch?v=TgSBYWdBaaE (Champions of Warcraft vs Valithria Dreamwalker 10man, Hunter's Point of View)
                //and http://www.youtube.com/watch?v=s7CRfoFNxnA (Valithria Dreamwalker Mage POV Live servers 25 man)
                if (Is25ManRaid())
                {
                    events.ScheduleEvent(EVENT_SUMMON_ABOMINATION, delayForKill4Mages+9000);
                    events.ScheduleEvent(EVENT_SUMMON_SUPPRESSOR, delayForKill4Mages+14000);
                    events.ScheduleEvent(EVENT_SUMMON_ZOMBIE_AND_ARCHMAGE, delayForKill4Mages+16000);
                    events.ScheduleEvent(EVENT_SUMMON_BLAZING_SKELETON, delayForKill4Mages+27000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_SUMMON_ABOMINATION, delayForKill4Mages+1000);
                    events.ScheduleEvent(EVENT_SUMMON_SUPPRESSOR, delayForKill4Mages+10000);
                    events.ScheduleEvent(EVENT_SUMMON_ZOMBIE_AND_ARCHMAGE, delayForKill4Mages+20000);
                    events.ScheduleEvent(EVENT_SUMMON_BLAZING_SKELETON, delayForKill4Mages+30000);
                }
                events.ScheduleEvent(EVENT_CHECK_WIPE, 2000);
                pInstance->SetData(DATA_VALITHRIA_DREAMWALKER_EVENT, IN_PROGRESS);
                events.ScheduleEvent(EVENT_START_INTRO, delayForKill4Mages);
            }

            void MoveInLineOfSight(Unit *who)
            {
                if (!pInstance)
                    return;
                if (pInstance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT) == IN_PROGRESS)
                    return;
                if (me->IsWithinDistInMap(who, 80.0f, true) && who->GetTypeId() == TYPEID_PLAYER)
                    AttackStart(who);
                ScriptedAI::MoveInLineOfSight(who);
            }

            void EnterEvadeMode()
            {
                me->getThreatManager().clearReferences();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                summons.DespawnAll();
                events.Reset();
                ScriptedAI::EnterEvadeMode();
            }

            void JustSummoned(Creature* pSummoned)
            {
                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                    pSummoned->AI()->AttackStart(valithria);
                summons.Summon(pSummoned);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                    DoScriptText(SAY_PDEATH, valithria);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!pInstance || pInstance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT) != IN_PROGRESS)
                    return;
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_INTRO:
                        {
                            if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                                valithria->AI()->DoAction(EVENT_INTRO);
                            break;
                        }
                        case EVENT_CHECK_WIPE:
                        {
                            if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                            {
                                if (Creature* valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                                    valithria->AI()->DoAction(ACTION_WIPE);
                                Reset();
                                return;
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);
                            break;
                        }
                        case EVENT_SUMMON_ZOMBIE_AND_ARCHMAGE:
                        {
                            //According to videos, zombies and archmages are summoned in pairs, but they appear from different gates and with delay one from another
                            uint8 pattern[4] = {0, 1, 2, 3};
                            std::random_shuffle(pattern, pattern + RAID_MODE<uint8>(1, 3, 1, 3));
                            m_uiZombieGate = pattern[0];
                            m_uiArchmageGate = pattern[1];
                            uint32 delay = RAID_MODE<uint32>(2000, 9000, 2000, 9000);
                            uint32 summonZombieDelay = 1000 + (urand(0, 1) ? 0 : delay);
                            uint32 summonArchmageDelay = 1000 + delay - summonZombieDelay;
                            events.ScheduleEvent(EVENT_SUMMON_ZOMBIE, summonZombieDelay);
                            events.ScheduleEvent(EVENT_SUMMON_ARCHMAGE, summonArchmageDelay);
                            events.ScheduleEvent(EVENT_SUMMON_ZOMBIE_AND_ARCHMAGE, 25000);
                            break;
                        }
                        case EVENT_SUMMON_ARCHMAGE:
                        {
                            if (bSummonArchmages)
                                DoSummon(NPC_ARCHMAGE, Pos[m_uiArchmageGate]);
                            break;
                        }
                        case EVENT_SUMMON_ZOMBIE:
                        {
                            if (bSummonZombies)
                                DoSummon(NPC_ZOMBIE, Pos[m_uiZombieGate]);
                            break;
                        }
                        case EVENT_SUMMON_ABOMINATION:
                        {
                            //One abomination at once
                            if (bSummonAbominations)
                                DoSummon(NPC_ABOMINATION, Pos[urand(0, RAID_MODE(1, 3, 1, 3))]);
                            events.ScheduleEvent(EVENT_SUMMON_ABOMINATION, RAID_MODE<uint32>(60000, 50000, 60000, 50000));
                            break;
                        }
                        case EVENT_SUMMON_SUPPRESSOR:
                        {
                            //Suppressors can appear from any gate in any pattern, just their total amount is always the same
                            if (bSummonSuppressors)
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                    DoSummon(NPC_SUPPRESSOR, Pos[urand(0, RAID_MODE<uint8>(1, 3, 1, 3))]);
                                m_uiSummonSuppressorTimer -= 2000;
                                if (m_uiSummonSuppressorTimer < 2000)
                                    m_uiSummonSuppressorTimer = 2000;
                            }
                            events.ScheduleEvent(EVENT_SUMMON_SUPPRESSOR, m_uiSummonSuppressorTimer);
                            break;
                        }
                        case EVENT_SUMMON_BLAZING_SKELETON:
                        {
                            //One Blazing Skeleton at once
                            if (bSummonSkeletons)
                            {
                                DoSummon(NPC_SKELETON, Pos[urand(0, RAID_MODE<uint8>(1, 3, 1, 3))]);
                                m_uiSummonSkeletonTimer -= 5000;
                                if (m_uiSummonSkeletonTimer < 5000)
                                    m_uiSummonSkeletonTimer = 5000;
                            }
                            events.ScheduleEvent(EVENT_SUMMON_BLAZING_SKELETON, m_uiSummonSkeletonTimer);
                            break;
                        }       
                        default: 
                            break;
                    }
                }

            }
            private:
                InstanceScript* pInstance;

                uint32 m_uiSummonSkeletonTimer, m_uiSummonSuppressorTimer, m_uiZombieGate, m_uiArchmageGate;
                SummonList summons;
                EventMap events;
                bool bSummonColumns, bSummonZombies, bSummonSuppressors, bSummonArchmages, bSummonSkeletons, bSummonAbominations;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_combat_stalkerAI(pCreature);
        }
};
class npc_icc_valithria_rot_worm : public CreatureScript
{
    public:
        npc_icc_valithria_rot_worm() : CreatureScript("npc_icc_valithria_rot_worm") { }

        struct npc_icc_valithria_rot_wormAI : public ScriptedAI
        {

            npc_icc_valithria_rot_wormAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
            }
            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CAST_ROT_WORM_SPAWN_ANIMATION, 500);
            }
            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_ROT_WORM_SPAWN_ANIMATION:  
                            DoCast(me, SPELL_SUMMON_ROT_WORM_VISUAL);
                            break;
                        default: 
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_rot_wormAI(pCreature);
        }
};

class npc_icc_valithria_gluttonous_abomination : public CreatureScript
{
    public:
        npc_icc_valithria_gluttonous_abomination() : CreatureScript("npc_icc_valithria_gluttonous_abomination") { }

        struct npc_icc_valithria_gluttonous_abominationAI : public ScriptedAI
        {

            npc_icc_valithria_gluttonous_abominationAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER));
            }
            void Reset()
            {
                bGutSprayReady = false;
                events.Reset();
            }
            void JustDied(Unit *pKiller)
            {
                Position pos;
                me->GetPosition(&pos);
                Creature *rotSummoner = DoSummon(NPC_TRIGGER, pos, 3000, TEMPSUMMON_TIMED_DESPAWN);
                rotSummoner->CastSpell(rotSummoner, SPELL_SUMMON_ROT_WORMS_AURA, true);
                rotSummoner->SetVisible(false);
                rotSummoner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (!me->isInCombat())
                    return;
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        case EVENT_GUT_SPRAY:
                            bGutSprayReady = true;
                            events.ScheduleEvent(EVENT_GUT_SPRAY, 5000);
                            break;
                        default:
                            break;
                    }
                }
                if (me->IsWithinMeleeRange(me->getVictim()))
                    if (bGutSprayReady)
                        bGutSprayReady = !DoSpellAttackIfReady(RAID_MODE<uint32>(SPELL_GUT_SPRAY_10N, SPELL_GUT_SPRAY_25N, SPELL_GUT_SPRAY_10H, SPELL_GUT_SPRAY_25H));
                DoMeleeAttackIfReady();
            }
        private:
            bool bGutSprayReady;
            EventMap events;  
            InstanceScript *pInstance;
            Creature *valithria;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_gluttonous_abominationAI(pCreature);
        }
};

class npc_icc_valithria_mana_void : public CreatureScript
{
    public:
        npc_icc_valithria_mana_void() : CreatureScript("npc_icc_valithria_mana_void") { }

        struct npc_icc_valithria_mana_voidAI : public ScriptedAI
        {

            npc_icc_valithria_mana_voidAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
            }
            void Reset()
            {
                events.ScheduleEvent(EVENT_DESPAWN, 30000);
            }
            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                    }
                }
            }
        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_mana_voidAI(pCreature);
        }
};

class npc_icc_valithria_blistering_zombie : public CreatureScript
{
    public:
        npc_icc_valithria_blistering_zombie() : CreatureScript("npc_icc_valithria_blistering_zombie") { }

        struct npc_icc_valithria_blistering_zombieAI : public ScriptedAI
        {

            npc_icc_valithria_blistering_zombieAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER));
                isAlreadyExploding = false;
            }
            void Reset()
            {
                events.Reset();
            }
            void DamageTaken(Unit * /*done_by*/, uint32& /*damage*/)
            {
                if (HealthBelowPct(11) && !isAlreadyExploding)
                {
                    isAlreadyExploding = true;
                    DoCast(me, RAID_MODE<uint32>(SPELL_ACID_BURST_10N, SPELL_ACID_BURST_25N, SPELL_ACID_BURST_10H, SPELL_ACID_BURST_25H));
                    events.ScheduleEvent(EVENT_DESPAWN, 1000);
                }
            }
            void DamageDealt(Unit* target, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != DIRECT_DAMAGE)
                    return;
                DoCast(target, RAID_MODE<uint32>(SPELL_CORROSION_10N, SPELL_CORROSION_25N, SPELL_CORROSION_10H, SPELL_CORROSION_25H));
            }
            void EnterCombat(Unit *who)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_EXPLODE, 25000);
            }
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (!me->isInCombat())
                    return;
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            InstanceScript *pInstance;
            Creature *valithria;
            bool isAlreadyExploding;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_blistering_zombieAI(pCreature);
        }
};

class npc_icc_valithria_risen_archmage : public CreatureScript
{
    public:
        npc_icc_valithria_risen_archmage() : CreatureScript("npc_icc_valithria_risen_archmage") { }

        struct npc_icc_valithria_risen_archmageAI : public ScriptedAI
        {

            npc_icc_valithria_risen_archmageAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER));
            }
            void Reset()
            {
                events.Reset();
            }
            void EnterCombat(Unit *who)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CAST_COLUMN_OF_FROST, 20000);
                events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 15000);
                events.ScheduleEvent(EVENT_SUMMON_MANA_VOID, 20000);
            }
            void KilledUnit(Unit* victim)
            {
                DoStopAttack();
                DoResetThreat();
            }
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (!me->isInCombat())
                    return;
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_COLUMN_OF_FROST:
                            if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(pTarget, SPELL_COLUMN_PRE);
                            events.ScheduleEvent(EVENT_CAST_COLUMN_OF_FROST, 10000);
                            break;
                        case EVENT_FROSTBOLT_VOLLEY:
                            DoCast(me, SPELL_FROSTBOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 15000);
                            break;
                        case EVENT_SUMMON_MANA_VOID:
                        {
                            if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(pTarget, SPELL_SUMMON_MANA_VOID);
                            events.ScheduleEvent(EVENT_SUMMON_MANA_VOID, 40000);
                            break;
                        }
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            InstanceScript *pInstance;
            Creature *valithria;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_risen_archmageAI(pCreature);
        }
};

class npc_icc_valithria_supressor : public CreatureScript
{
    public:
        npc_icc_valithria_supressor() : CreatureScript("npc_icc_valithria_supressor") { }

        struct npc_icc_valithria_supressorAI : public ScriptedAI
        {
            npc_icc_valithria_supressorAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER));
                me->SetReactState(REACT_PASSIVE);
            }
            void Reset()
            {
                events.Reset();
            }
            void EnterCombat(Unit *who)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CAST_SUPPRESSION, 1000);
            }
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (!me->isInCombat())
                    return;
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_SUPPRESSION:
                        {
                            if (Creature *valithria = ObjectAccessor::GetCreature(*me, me->GetInstanceScript()->GetData64(GUID_VALITHRIA_DREAMWALKER)))
                            {
                                if (valithria->HasAura(SPELL_SUPPRESSION, me->GetGUID()))
                                    return;
                                if (me->GetDistance2d(valithria) > 10.0f)
                                {
                                    //Come closer to boss
                                    AttackStart(valithria);
                                }
                                else
                                {

                                    DoCast(valithria, SPELL_SUPPRESSION);
                                }
                                events.ScheduleEvent(EVENT_CAST_SUPPRESSION, 1000);
                            }
                            else
                            {
                                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                                    AttackStart(target);
                            }
                            break;
                        }
                    }
                }
                //Doesn't attack, only channel Suppression debuff on Valithria
                //DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            InstanceScript *pInstance;
            Creature *valithria;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_supressorAI(pCreature);
        }
};

class npc_icc_valithria_blazing_skeleton : public CreatureScript
{
    public:
        npc_icc_valithria_blazing_skeleton() : CreatureScript("npc_icc_valithria_blazing_skeleton") { }

        struct npc_icc_valithria_blazing_skeletonAI : public ScriptedAI
        {
            npc_icc_valithria_blazing_skeletonAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                valithria = Unit::GetCreature(*me, pInstance->GetData64(GUID_VALITHRIA_DREAMWALKER));
            }
            void Reset()
            {
                events.Reset();
            }
            void EnterCombat(Unit *who)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CAST_FIREBALL, 4000);
                events.ScheduleEvent(EVENT_CAST_LAY_WASTE, 20000);
            }
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (!me->isInCombat())
                    return;
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_FIREBALL:
                            DoCast(me->getVictim(), SPELL_FIREBALL);
                            events.ScheduleEvent(EVENT_CAST_FIREBALL, 5000);
                            break;
                        case EVENT_CAST_LAY_WASTE:
                            //continue using it until killed
                            events.CancelEvent(EVENT_CAST_FIREBALL);
                            DoCast(SPELL_LAY_WASTE);
                            events.ScheduleEvent(EVENT_CAST_LAY_WASTE, 11000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            InstanceScript *pInstance;
            Creature *valithria;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_icc_valithria_blazing_skeletonAI(pCreature);
        }
};

void AddSC_boss_valithria()
{
    new boss_valithria();
    new npc_dreamportal_icc();
    new npc_dreamcloud_icc();
    new npc_icc_combat_stalker();
    new npc_valithria_alternative();
    new spell_valithria_vigor();
    new spell_dream_state();
    new npc_column_of_frost_icc();
    new npc_icc_valithria_gluttonous_abomination();
    new npc_icc_valithria_mana_void();
    new npc_icc_valithria_rot_worm();
    new npc_icc_valithria_blistering_zombie();
    new npc_icc_valithria_supressor();
    new npc_icc_valithria_risen_archmage();
    new npc_icc_valithria_blazing_skeleton();
}