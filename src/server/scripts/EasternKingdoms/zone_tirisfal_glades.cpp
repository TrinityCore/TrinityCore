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

/* ScriptData
SDName: Tirisfal_Glades
SD%Complete: 100
SDComment: Quest support: 590, 1819
SDCategory: Tirisfal Glades
EndScriptData */

/* ContentData
npc_calvin_montague
go_mausoleum_door
go_mausoleum_trigger
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"

/*######
## npc_calvin_montague
######*/

enum Calvin
{
    SAY_COMPLETE = 0,
    SPELL_DRINK  = 7737, // Possibly incorrect spell, but both duration and icon are correct
    QUEST_590    = 590,

    EVENT_EMOTE_RUDE          = 1,
    EVENT_TALK                = 2,
    EVENT_DRINK               = 3,
    EVENT_SET_QUESTGIVER_FLAG = 4,
    EVENT_STAND               = 5
};

class npc_calvin_montague : public CreatureScript
{
public:
    npc_calvin_montague() : CreatureScript("npc_calvin_montague") { }

    struct npc_calvin_montagueAI : public ScriptedAI
    {
        npc_calvin_montagueAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->RestoreFaction();
            if (!me->IsImmuneToPC())
                me->SetImmuneToPC(true);
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (damage > me->GetHealth() || me->HealthBelowPctDamaged(15, damage))
            {
                damage = 0;
                me->CombatStop(true);
                EnterEvadeMode();
                _events.ScheduleEvent(EVENT_EMOTE_RUDE, 3s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMOTE_RUDE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                        _events.ScheduleEvent(EVENT_TALK, 2s);
                        break;
                    case EVENT_TALK:
                        Talk(SAY_COMPLETE);
                        _events.ScheduleEvent(EVENT_DRINK, 5s);
                        break;
                    case EVENT_DRINK:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->AreaExploredOrEventHappens(QUEST_590);
                        _playerGUID.Clear();
                        DoCastSelf(SPELL_DRINK);
                        _events.ScheduleEvent(EVENT_SET_QUESTGIVER_FLAG, 12s);
                        break;
                    case EVENT_SET_QUESTGIVER_FLAG:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        _events.ScheduleEvent(EVENT_STAND, 3s);
                        break;
                    case EVENT_STAND:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_590)
            {
                _playerGUID = player->GetGUID();
                me->SetFaction(FACTION_ENEMY);
                me->SetImmuneToPC(false);
                AttackStart(player);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
        }

    private:
        EventMap _events;
        ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_calvin_montagueAI(creature);
    }
};

void AddSC_tirisfal_glades()
{
    new npc_calvin_montague();
}
