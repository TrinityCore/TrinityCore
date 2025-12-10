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
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellScript.h"

/*
 * Some quick facts about the event:
 *
 * Event can be completed with or without Andorov, waves will be engaged one after one
 * Looks like waves aren't linked in some order, for example engaging and killing all waves at once will engage Rajaxx
   without any issues. Engaging and killing several waves at once will engage next wave. It is unclear what happens if
   random waves are engaged and killed, probably linked to them waves will be engaged. As well it is unclear what happens
   if waves are engaged and killed in reverse order
 * There is a bug on retail when all waves respawn. It is unclear how exactly waves should respawn, NYI
 * According to patch notes, Andorov should respawn after 15 min if killed, NYI
 * It is unclear if next wave should be started after specific amount of time even if previous is not yet defeated
 * Entire event requires additional research since some things may be missing or implemented wrongly
 */

enum AndorovTexts
{
    SAY_PROGRESS_1             = 0,
    SAY_PROGRESS_2             = 1,
    SAY_PROGRESS_3             = 2,
    SAY_PROGRESS_4             = 3,
    SAY_PROGRESS_5             = 4,
    SAY_PROGRESS_6             = 5
};

enum AndorovSpells
{
    SPELL_STRIKE               = 22591,
    SPELL_BASH                 = 25515,
    SPELL_AURA_OF_COMMAND      = 25516
};

enum AndorovEvents
{
    EVENT_INTRO_1              = 1,

    EVENT_PROGRESS_1,
    EVENT_PROGRESS_2,
    EVENT_PROGRESS_3,
    EVENT_PROGRESS_4,
    EVENT_PROGRESS_5,
    EVENT_PROGRESS_6,

    EVENT_OUTRO_1,
    EVENT_OUTRO_2,

    EVENT_STRIKE,
    EVENT_BASH,
    EVENT_AURA_OF_COMMAND
};

enum AndorovMisc
{
    PATH_SPAWN                 = 4,
    PATH_EVENT                 = 5,

    GOSSIP_MENU_NOT_STARTED    = 6629,
    GOSSIP_MENU_IN_PROGRESS    = 7048,
    GOSSIP_MENU_FINISHED       = 7047,

    NPC_KALDOREI_ELITE         = 15473
};

// 15471 - Lieutenant General Andorov
struct npc_andorov : public ScriptedAI
{
    npc_andorov(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void Reset() override
    {
        _combatEvents.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _combatEvents.ScheduleEvent(EVENT_STRIKE, 10s, 15s);
        _combatEvents.ScheduleEvent(EVENT_BASH, 15s, 25s);
        _combatEvents.ScheduleEvent(EVENT_AURA_OF_COMMAND, 10s, 20s);
    }

    void WaypointPathEnded(uint32 /*waypointId*/, uint32 pathId) override
    {
        if (pathId == PATH_EVENT)
            _events.ScheduleEvent(EVENT_PROGRESS_3, 0s);
    }

    void DoAction(int32 action) override
    {
        /// @todo: This part is guessed, nothing is changed when Rajaxx is defeated
        /// but we want to enable vendor, perform emote and despawn. Maybe it is delayed a little?
        if (action == ACTION_RAJAXX_DEFEATED && me->IsAlive())
            _events.ScheduleEvent(EVENT_OUTRO_1, 0s);
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
                    case EVENT_INTRO_1:
                        me->RemoveNpcFlag(UNIT_NPC_FLAG_VENDOR);
                        me->GetMotionMaster()->MovePath(PATH_SPAWN, false);
                        break;

                    case EVENT_PROGRESS_1:
                    {
                        _instance->SetData(DATA_ANDOROV_EVENT_STATE, SPECIAL);

                        Talk(SAY_PROGRESS_1);

                        std::vector<Creature*> elites;
                        GetCreatureListWithEntryInGrid(elites, me, NPC_KALDOREI_ELITE, 50.0f);
                        for (Creature* elite : elites)
                            elite->SetImmuneToNPC(false);
                        me->SetImmuneToNPC(false);
                        _events.ScheduleEvent(EVENT_PROGRESS_2, 3s);
                        break;
                    }
                    case EVENT_PROGRESS_2:
                        Talk(SAY_PROGRESS_2);
                        me->GetMotionMaster()->MovePath(PATH_EVENT, false);
                        break;

                    case EVENT_PROGRESS_3:
                        Talk(SAY_PROGRESS_3);
                        _events.ScheduleEvent(EVENT_PROGRESS_4, 4s);
                        break;
                    case EVENT_PROGRESS_4:
                        Talk(SAY_PROGRESS_4);
                        _events.ScheduleEvent(EVENT_PROGRESS_5, 6s);
                        break;
                    case EVENT_PROGRESS_5:
                        Talk(SAY_PROGRESS_5);
                        _events.ScheduleEvent(EVENT_PROGRESS_6, 1s);
                        break;
                    case EVENT_PROGRESS_6:
                    {
                        _instance->SetData(DATA_ANDOROV_EVENT_STATE, IN_PROGRESS);

                        std::vector<Creature*> elites;
                        GetCreatureListWithEntryInGrid(elites, me, NPC_KALDOREI_ELITE, 50.0f);
                        for (Creature* elite : elites)
                            elite->SetEmoteState(EMOTE_STATE_READY1H);
                        me->SetEmoteState(EMOTE_STATE_READY1H);
                        break;
                    }

                    case EVENT_OUTRO_1:
                        me->SetNpcFlag(UNIT_NPC_FLAG_VENDOR);
                        _events.ScheduleEvent(EVENT_OUTRO_2, 2min);
                        break;
                    case EVENT_OUTRO_2:
                    {
                        Talk(SAY_PROGRESS_6);

                        std::vector<Creature*> elites;
                        GetCreatureListWithEntryInGrid(elites, me, NPC_KALDOREI_ELITE, 50.0f);
                        for (Creature* elite : elites)
                            elite->DespawnOrUnsummon();
                        me->DespawnOrUnsummon();
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        _combatEvents.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _combatEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STRIKE:
                    DoCastVictim(SPELL_STRIKE);
                    _combatEvents.Repeat(10s, 15s);
                    break;
                case EVENT_BASH:
                    DoCastVictim(SPELL_BASH);
                    _combatEvents.Repeat(20s, 25s);
                    break;
                case EVENT_AURA_OF_COMMAND:
                    DoCastSelf(SPELL_AURA_OF_COMMAND);
                    _combatEvents.Repeat(30s, 50s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    bool OnGossipHello(Player* player) override
    {
        switch (_instance->GetData(DATA_ANDOROV_EVENT_STATE))
        {
            case NOT_STARTED:
                player->PrepareGossipMenu(me, GOSSIP_MENU_NOT_STARTED, true);
                player->SendPreparedGossip(me);
                return true;
            case SPECIAL:
            case IN_PROGRESS:
                player->PrepareGossipMenu(me, GOSSIP_MENU_IN_PROGRESS, true);
                player->SendPreparedGossip(me);
                return true;
            case DONE:
                player->PrepareGossipMenu(me, GOSSIP_MENU_FINISHED, true);
                player->SendPreparedGossip(me);
                return true;
            default:
                break;
        }
        return false;
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENU_NOT_STARTED)
        {
            /// @todo: This part requires additional research.
            /// What should happen if event wasn't started but Rajaxx was defeated?
            if (_instance->GetBossState(DATA_RAJAXX) != DONE)
            {
                CloseGossipMenuFor(player);
                _events.ScheduleEvent(EVENT_PROGRESS_1, 0s);
            }
        }
        return false;
    }

private:
    EventMap _events;
    EventMap _combatEvents;
    InstanceScript* _instance;
};

enum AQ20Itch
{
    SPELL_HIVEZARA_CATALYST        = 25187
};

// 25185 - Itch
class spell_ruins_of_ahnqiraj_itch : public AuraScript
{
    PrepareAuraScript(spell_ruins_of_ahnqiraj_itch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HIVEZARA_CATALYST });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_HIVEZARA_CATALYST, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ruins_of_ahnqiraj_itch::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_ruins_of_ahnqiraj()
{
    RegisterAQ20CreatureAI(npc_andorov);
    RegisterSpellScript(spell_ruins_of_ahnqiraj_itch);
}
