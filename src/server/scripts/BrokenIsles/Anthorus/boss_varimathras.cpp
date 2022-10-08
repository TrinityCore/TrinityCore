/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "antorus_the_burning_throne.h"


enum Spells
{
    //Torments of the Shivarra
    SPELL_TORMENT_OF_FLAMES = 243967,// 5s
    SPELL_TORMENT_OF_FLAMES_DMG = 243968,//243968
    SPELL_TORMENT_OF_FROST = 243976,// 61s
    SPELL_TORMENT_OF_FEL = 243979,// 61s
    SPELL_TORMENT_OF_SHADOWS = 243974,// 61s
    //The Fallen Nathrezim
    SPELL_SHADOW_STRIKE = 243960,  //  9s
    SPELL_CONTROL_AURA = 243975,
    SPELL_DARK_FISSURE = 243999, //17 18s   32s 244003
    SPELL_DARK_FISSURE_VISUAL = 244003,
    SPELL_DARK_FISSURE_DMG = 244005,//244005
    SPELL_MARKED_PREY = 244042, //25s  30s
    SPELL_NECROTIC_EMBRACE = 244093, //35s  30s
    //SPELL_SHADOW_STRIKE = 257644,
    SPELL_MISERY = 243961,

    //(ability.id = 243968 or ability.id = 243977 or ability.id = 243980 or ability.id = 243973)
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_ENTERCOMBAT,             EVENT_TYPE_TALK,            0 },
    { SPELL_MARKED_PREY,                EVENT_TYPE_TALK,            1 },
    { SPELL_DARK_FISSURE,               EVENT_TYPE_TALK,            2 },
    { EVENT_ON_JUSTDIED,                EVENT_TYPE_TALK,            5 },
};

struct boss_varimathras : public BossAI
{
    boss_varimathras(Creature* creature) : BossAI(creature, DATA_VARIMATHRAS) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID(2069);
        LoadTalkData(&talkData);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SetBossState(DATA_VARIMATHRAS, DONE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TORMENT_OF_FLAMES_DMG);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_TORMENT_OF_FLAMES, 5s);
        //events.ScheduleEvent(SPELL_TORMENT_OF_FROST, 5s);
        //events.ScheduleEvent(SPELL_TORMENT_OF_FEL, 5s);
        //events.ScheduleEvent(SPELL_TORMENT_OF_SHADOWS, 5s);
        events.ScheduleEvent(SPELL_SHADOW_STRIKE, 9s);
        //events.ScheduleEvent(SPELL_CONTROL_AURA, 5s);
        events.ScheduleEvent(SPELL_DARK_FISSURE, 17s, 18s);
        events.ScheduleEvent(SPELL_MARKED_PREY, 25s);
        events.ScheduleEvent(SPELL_NECROTIC_EMBRACE, 35s);

        events.ScheduleEvent(SPELL_MISERY, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {


        switch (eventId)
        {
        case SPELL_TORMENT_OF_FLAMES:
        {
            DoCast(SPELL_TORMENT_OF_FLAMES);
            instance->DoAddAuraOnPlayers(SPELL_TORMENT_OF_FLAMES_DMG);
            //events.Repeat(5s);
            break;
        }
        case SPELL_TORMENT_OF_FROST:
        {
            DoCast(SPELL_TORMENT_OF_FROST);
            events.Repeat(61s);
            break;
        }
        case SPELL_TORMENT_OF_FEL:
        {
            DoCast(SPELL_TORMENT_OF_FEL);
            events.Repeat(61s);
            break;
        }
        case SPELL_TORMENT_OF_SHADOWS:
        {
            DoCast(SPELL_TORMENT_OF_SHADOWS);
            events.Repeat(61s);
            break;
        }
        case SPELL_SHADOW_STRIKE:
        {
            DoCast(SPELL_SHADOW_STRIKE);
            //257644
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, 257644, false);
            events.Repeat(9s);
            break;
        }
        case SPELL_DARK_FISSURE:
        {
            GetTalkData(SPELL_DARK_FISSURE);
            DoCast(SPELL_DARK_FISSURE);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->CastSpell(target1, SPELL_DARK_FISSURE_VISUAL, false);
                me->CastSpell(target1, SPELL_DARK_FISSURE_DMG, false);
            }
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->CastSpell(target1, SPELL_DARK_FISSURE_VISUAL, false);
                me->CastSpell(target1, SPELL_DARK_FISSURE_DMG, false);
            }
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->CastSpell(target1, SPELL_DARK_FISSURE_VISUAL, false);
                me->CastSpell(target1, SPELL_DARK_FISSURE_DMG, false);
            }
            events.Repeat(32s);
            break;
        }
        case SPELL_MARKED_PREY:
        {
            GetTalkData(SPELL_MARKED_PREY);
            DoCast(SPELL_MARKED_PREY);
            events.Repeat(30s);
            break;
        }
        case SPELL_NECROTIC_EMBRACE:
        {
            DoCast(SPELL_NECROTIC_EMBRACE);
            events.Repeat(30s);
            break;
        }
        case SPELL_MISERY:
        {
            instance->DoCastSpellOnPlayers(SPELL_MISERY);
            events.Repeat(25s);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            //instance->DoPlayConversation(5750);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }
    uint8 PhaseStatus;
    bool IsLock;
};

void AddSC_boss_varimathras()
{
    RegisterCreatureAI(boss_varimathras);
}
