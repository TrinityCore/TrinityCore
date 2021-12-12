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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_gen_".
 */

 /* ContentData
 npc_pet_gen_pandaren_monk          100%    Pandaren Monk drinks and bows with you
 EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum PandarenMonkMisc
{
    SPELL_PANDAREN_MONK = 69800,
    EVENT_FOCUS = 1,
    EVENT_EMOTE = 2,
    EVENT_FOLLOW = 3,
    EVENT_DRINK = 4
};

struct npc_pet_gen_pandaren_monk : public NullCreatureAI
{
    npc_pet_gen_pandaren_monk(Creature* creature) : NullCreatureAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FOCUS, 1s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;

        Reset();
    }

    void ReceiveEmote(Player* /*player*/, uint32 emote) override
    {
        me->InterruptSpell(CURRENT_CHANNELED_SPELL);
        me->StopMoving();

        switch (emote)
        {
        case TEXT_EMOTE_BOW:
            _events.ScheduleEvent(EVENT_FOCUS, 1s);
            break;
        case TEXT_EMOTE_DRINK:
            _events.ScheduleEvent(EVENT_DRINK, 1s);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (Unit* owner = me->GetCharmerOrOwner())
            if (!me->IsWithinDist(owner, 30.f))
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FOCUS:
                if (Unit* owner = me->GetCharmerOrOwner())
                    me->SetFacingToObject(owner);
                _events.ScheduleEvent(EVENT_EMOTE, 1s);
                break;
            case EVENT_EMOTE:
                me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                _events.ScheduleEvent(EVENT_FOLLOW, 1s);
                break;
            case EVENT_FOLLOW:
                if (Unit* owner = me->GetCharmerOrOwner())
                    me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            case EVENT_DRINK:
                me->CastSpell(me, SPELL_PANDAREN_MONK, false);
                break;
            default:
                break;
            }
        }
    }

private:
    EventMap _events;
};

enum SoulTrader
{
    SAY_SOUL_TRADER_INTRO           = 0,

    SPELL_ETHEREAL_ONSUMMON         = 50052,
    SPELL_ETHEREAL_PET_REMOVE_AURA  = 50055
};

struct npc_pet_gen_soul_trader : public ScriptedAI
{
    npc_pet_gen_soul_trader(Creature* creature) : ScriptedAI(creature) { }

    void LeavingWorld() override
    {
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_ETHEREAL_PET_REMOVE_AURA);
    }

    void JustAppeared() override
    {
        Talk(SAY_SOUL_TRADER_INTRO);
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_ETHEREAL_ONSUMMON);

        CreatureAI::JustAppeared();
    }
};

enum LichPet
{
    SPELL_LICH_ONSUMMON     = 69735,
    SPELL_LICH_REMOVE_AURA  = 69736
};

struct npc_pet_lich : public ScriptedAI
{
    npc_pet_lich(Creature* creature) : ScriptedAI(creature) { }

    void LeavingWorld() override
    {
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_LICH_REMOVE_AURA);
    }

    void JustAppeared() override
    {
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_LICH_ONSUMMON);

        CreatureAI::JustAppeared();
    }
};

void AddSC_generic_pet_scripts()
{
    RegisterCreatureAI(npc_pet_gen_pandaren_monk);
    RegisterCreatureAI(npc_pet_gen_soul_trader);
    RegisterCreatureAI(npc_pet_lich);
}
