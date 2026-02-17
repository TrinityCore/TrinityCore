/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "wailing_caverns.h"

/*
 * Spawns are supposed to be pooled, NYI
 * Some spawns attack on spawn, some moves to position, NYI, all attacks on spawn currently
 * This is based on Cata sniffs and WotLK classic video, timers were changed in Cata and requires to be revisited
 */

enum DiscipleTexts
{
    // Disciple
    SAY_ALL_DONE                  = 0,
    SAY_PROGRESS_1                = 1,
    SAY_PROGRESS_2                = 2,
    SAY_PROGRESS_3                = 3,
    SAY_PROGRESS_4                = 4,
    SAY_PROGRESS_5                = 5,
    SAY_PROGRESS_6                = 6,
    SAY_PROGRESS_7                = 7,
    SAY_PROGRESS_8                = 8,
    SAY_PROGRESS_9                = 9,
    SAY_AGGRO                     = 10,

    // Naralex
    EMOTE_AWAKENING_1             = 0,
    EMOTE_AWAKENING_2             = 1,
    EMOTE_AWAKENING_3             = 2,
    SAY_AWAKENING_4               = 3,
    SAY_AWAKENING_5               = 4,
    SAY_AWAKENING_6               = 5
};

enum DiscipleSpells
{
    SPELL_MARK_OF_THE_WILD        = 5232,
    SPELL_SERPENTINE_CLEANSING    = 6270,
    SPELL_NARALEXS_AWAKENING      = 6271,
    SPELL_OWL_FORM                = 8153,

    SPELL_SLEEP                   = 1090,
    SPELL_DRUIDS_POTION           = 8141
};

enum DiscipleEvents
{
    EVENT_PROGRESS_1              = 1,
    EVENT_PROGRESS_2,
    EVENT_PROGRESS_3,
    EVENT_PROGRESS_4,
    EVENT_PROGRESS_5,
    EVENT_PROGRESS_6,
    EVENT_PROGRESS_7,
    EVENT_PROGRESS_8,
    EVENT_PROGRESS_9,
    EVENT_PROGRESS_10,
    EVENT_PROGRESS_11,
    EVENT_PROGRESS_12,
    EVENT_PROGRESS_13,
    EVENT_PROGRESS_14,
    EVENT_PROGRESS_15,
    EVENT_PROGRESS_16,
    EVENT_PROGRESS_17,
    EVENT_PROGRESS_18,
    EVENT_PROGRESS_19,
    EVENT_PROGRESS_20,
    EVENT_PROGRESS_21,
    EVENT_PROGRESS_22,
    EVENT_PROGRESS_23,
    EVENT_PROGRESS_24,
    EVENT_PROGRESS_25,
    EVENT_PROGRESS_26,
    EVENT_PROGRESS_27,

    EVENT_SLEEP,
    EVENT_DRUIDS_POTION
};

enum DisciplePaths
{
    PATH_PROGRESS_1               = 367800,
    PATH_PROGRESS_2               = 367801,
    PATH_PROGRESS_3               = 367802,
    PATH_PROGRESS_4               = 367803,
    PATH_PROGRESS_5               = 367804,
    PATH_NARALEX                  = 367900
};

enum DiscipleSummonGroups
{
    SUMMON_GROUP_1                = 0,
    SUMMON_GROUP_2                = 1,
    SUMMON_GROUP_3                = 2,
    SUMMON_GROUP_4                = 3,
    SUMMON_GROUP_5                = 4
};

enum DiscipleMisc
{
    GOSSIP_MENU_EVENT             = 202
};

// 3678 - Disciple of Naralex
struct npc_disciple_of_naralex : public ScriptedAI
{
    npc_disciple_of_naralex(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _combatEvents.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        _combatEvents.ScheduleEvent(EVENT_SLEEP, 5s, 10s);
        _combatEvents.ScheduleEvent(EVENT_DRUIDS_POTION, 5s, 10s);

        if (roll_chance_i(30))
            Talk(SAY_AGGRO, who);
    }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(me);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ALL_DONE)
            Talk(SAY_ALL_DONE);
    }

    void WaypointPathEnded(uint32/* waypointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_PROGRESS_1:
                _events.ScheduleEvent(EVENT_PROGRESS_4, 1s);
                break;
            case PATH_PROGRESS_2:
                _events.ScheduleEvent(EVENT_PROGRESS_8, 0s);
                break;
            case PATH_PROGRESS_3:
                _events.ScheduleEvent(EVENT_PROGRESS_12, 1s);
                break;
            case PATH_PROGRESS_4:
                _events.ScheduleEvent(EVENT_PROGRESS_14, 1s);
                break;
            case PATH_PROGRESS_5:
                _events.ScheduleEvent(EVENT_PROGRESS_27, 0s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!me->IsInCombat())
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_PROGRESS_1:
                        me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_ACTIVE);
                        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        _events.ScheduleEvent(EVENT_PROGRESS_2, 10s);
                        break;
                    case EVENT_PROGRESS_2:
                        Talk(SAY_PROGRESS_1);
                        _events.ScheduleEvent(EVENT_PROGRESS_3, 3500ms);
                        break;
                    case EVENT_PROGRESS_3:
                        me->GetMotionMaster()->MovePath(PATH_PROGRESS_1, false);
                        break;

                    case EVENT_PROGRESS_4:
                        Talk(SAY_PROGRESS_2);
                        _events.ScheduleEvent(EVENT_PROGRESS_5, 7s);
                        break;
                    case EVENT_PROGRESS_5:
                        me->SummonCreatureGroup(SUMMON_GROUP_1);
                        _events.ScheduleEvent(EVENT_PROGRESS_6, 10s);
                        break;
                    case EVENT_PROGRESS_6:
                        me->SetFacingTo(5.742133140563964843f);
                        Talk(SAY_PROGRESS_3);
                        _events.ScheduleEvent(EVENT_PROGRESS_7, 3s);
                        break;
                    case EVENT_PROGRESS_7:
                        me->GetMotionMaster()->MovePath(PATH_PROGRESS_2, false);
                        break;

                    case EVENT_PROGRESS_8:
                        DoCastSelf(SPELL_SERPENTINE_CLEANSING);
                        Talk(SAY_PROGRESS_4);
                        _events.ScheduleEvent(EVENT_PROGRESS_9, 18s);
                        break;
                    case EVENT_PROGRESS_9:
                        me->SummonCreatureGroup(SUMMON_GROUP_2);
                        _events.ScheduleEvent(EVENT_PROGRESS_10, 12s);
                        break;
                    case EVENT_PROGRESS_10:
                        Talk(SAY_PROGRESS_5);
                        _events.ScheduleEvent(EVENT_PROGRESS_11, 5s);
                        break;
                    case EVENT_PROGRESS_11:
                        me->GetMotionMaster()->MovePath(PATH_PROGRESS_3, false);
                        break;

                    case EVENT_PROGRESS_12:
                        Talk(SAY_PROGRESS_6);
                        _events.ScheduleEvent(EVENT_PROGRESS_13, 5s);
                        break;
                    case EVENT_PROGRESS_13:
                        me->GetMotionMaster()->MovePath(PATH_PROGRESS_4, false);
                        break;

                    case EVENT_PROGRESS_14:
                        Talk(SAY_PROGRESS_7);
                        _events.ScheduleEvent(EVENT_PROGRESS_15, 5s);
                        break;
                    case EVENT_PROGRESS_15:
                        DoCastSelf(SPELL_NARALEXS_AWAKENING);
                        Talk(SAY_PROGRESS_8);
                        _events.ScheduleEvent(EVENT_PROGRESS_16, 4s);
                        break;
                    case EVENT_PROGRESS_16:
                        me->SummonCreatureGroup(SUMMON_GROUP_3);
                        _events.ScheduleEvent(EVENT_PROGRESS_17, 15s);
                        break;
                    case EVENT_PROGRESS_17:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->AI()->Talk(EMOTE_AWAKENING_1);
                        _events.ScheduleEvent(EVENT_PROGRESS_18, 25s);
                        break;
                    case EVENT_PROGRESS_18:
                        me->SummonCreatureGroup(SUMMON_GROUP_4);
                        _events.ScheduleEvent(EVENT_PROGRESS_19, 20s);
                        break;
                    case EVENT_PROGRESS_19:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->AI()->Talk(EMOTE_AWAKENING_2);
                        _events.ScheduleEvent(EVENT_PROGRESS_20, 30s);
                        break;
                    case EVENT_PROGRESS_20:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->AI()->Talk(EMOTE_AWAKENING_3);
                        me->SummonCreatureGroup(SUMMON_GROUP_5);
                        _events.ScheduleEvent(EVENT_PROGRESS_21, 25s);
                        break;
                    case EVENT_PROGRESS_21:
                    {
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                        {
                            naralex->SetStandState(UNIT_STAND_STATE_STAND);
                            naralex->AI()->Talk(SAY_AWAKENING_4);
                        }
                        _events.ScheduleEvent(EVENT_PROGRESS_22, 3s);
                        break;
                    }
                    case EVENT_PROGRESS_22:
                        me->RemoveAurasDueToSpell(SPELL_NARALEXS_AWAKENING);
                        Talk(SAY_PROGRESS_9);
                        _events.ScheduleEvent(EVENT_PROGRESS_23, 3s);
                        break;
                    case EVENT_PROGRESS_23:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->AI()->Talk(SAY_AWAKENING_5);
                        _events.ScheduleEvent(EVENT_PROGRESS_24, 6s);
                        break;
                    case EVENT_PROGRESS_24:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->AI()->Talk(SAY_AWAKENING_6);
                        _events.ScheduleEvent(EVENT_PROGRESS_25, 3s);
                        break;
                    case EVENT_PROGRESS_25:
                        DoCastSelf(SPELL_OWL_FORM);
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->CastSpell(naralex, SPELL_OWL_FORM);
                        me->SetFaction(FACTION_FRIENDLY);
                        _events.ScheduleEvent(EVENT_PROGRESS_26, 8s);
                        break;
                    case EVENT_PROGRESS_26:
                    {
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                        {
                            naralex->SetDisableGravity(true);
                            naralex->GetMotionMaster()->MovePath(PATH_NARALEX, false);
                        }
                        me->SetDisableGravity(true);
                        me->GetMotionMaster()->MovePath(PATH_PROGRESS_5, false);
                        break;
                    }

                    case EVENT_PROGRESS_27:
                        if (Creature* naralex = _instance->GetCreature(DATA_NARALEX))
                            naralex->DespawnOrUnsummon();
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        _combatEvents.Update(diff);

        while (uint32 eventId = _combatEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SLEEP:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_SLEEP);
                    _combatEvents.Repeat(20s, 30s);
                    break;
                case EVENT_DRUIDS_POTION:
                    if (HealthBelowPct(80))
                        DoCastSelf(SPELL_DRUIDS_POTION);
                    _combatEvents.Repeat(10s, 15s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    bool OnGossipHello(Player* player) override
    {
        DoCast(player, SPELL_MARK_OF_THE_WILD);

        if (_instance->GetBossState(DATA_LORD_COBRAHN) == DONE && _instance->GetBossState(DATA_LORD_PYTHAS) == DONE
            && _instance->GetBossState(DATA_LADY_ANACONDRA) == DONE && _instance->GetBossState(DATA_LORD_SERPENTIS) == DONE)
        {
            player->PrepareGossipMenu(me, GOSSIP_MENU_EVENT, true);
            player->SendPreparedGossip(me);
            return true;
        }

        return false;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        CloseGossipMenuFor(player);
        _events.ScheduleEvent(EVENT_PROGRESS_1, 0s);

        return false;
    }

private:
    EventMap _events;
    EventMap _combatEvents;
    InstanceScript* _instance;
};

void AddSC_wailing_caverns()
{
    RegisterWailingCavernsCreatureAI(npc_disciple_of_naralex);
}
