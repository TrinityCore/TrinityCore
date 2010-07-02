/* Copyright (C) 2008 - 2010 TrinityCore <https://www.trinitycore.org/>
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
#include "pit_of_saron.h"

/*
 * SDComment: TODO:
 *  - implement aura for spell Overlord Brand.
 *  - Intro/Outro
 *  - improve script of Rimefang
 */

enum Yells
{
    SAY_AMBUSH_1                                = -1658050,
    SAY_AMBUSH_2                                = -1658051,
    SAY_GAUNTLET_START                          = -1658052,
    SAY_INTRO_1                                 = -1658053,
    SAY_INTRO_2                                 = -1658054,

    SAY_AGGRO                                   = -1658055,
    SAY_SLAY_1                                  = -1658056,
    SAY_SLAY_2                                  = -1658057,
    SAY_DEATH                                   = -1658058,
    SAY_MARK_RIMEFANG_1                         = -1658059,
    SAY_MARK_RIMEFANG_2                         = -1658060,
    SAY_DARK_MIGHT_1                            = -1658061,
    SAY_DARK_MIGHT_2                            = -1658062,

    SAY_GORKUN_OUTRO_1                          = -1658063,
    SAY_GORKUN_OUTRO_2                          = -1658064,
    SAY_JAYNA_OUTRO_3                           = -1658065,
    SAY_SYLVANAS_OUTRO_3                        = -1658066,
    SAY_JAYNA_OUTRO_4                           = -1658067,
    SAY_SYLVANAS_OUTRO_4                        = -1658068,
    SAY_JAYNA_OUTRO_5                           = -1658069,
};

enum Spells
{
    SPELL_FORCEFUL_SMASH                        = 69155,
    H_SPELL_FORCEFUL_SMASH                      = 69627,
    SPELL_OVERLORDS_BRAND                       = 69172,
    SPELL_DARK_MIGHT                            = 69167,
    H_SPELL_DARK_MIGHT                          = 69629,
    SPELL_HOARFROST                             = 69246,
    SPELL_MARK_OF_RIMEFANG                      = 69275,
    SPELL_ICY_BLAST                             = 69233,
    H_SPELL_ICY_BLAST                           = 69646,
    SPELL_ICY_BLAST_2                           = 69238,
    H_SPELL_ICY_BLAST_2                         = 69628,
};

enum Events
{
    EVENT_NONE,
    EVENT_FORCEFUL_SMASH,
    EVENT_OVERLORDS_BRAND,
    EVENT_DARK_MIGHT,

    // Rimefang
    EVENT_MARK_OF_RIMEFANG,
    EVENT_HOARFROST,
    EVENT_ICY_BLAST,
    EVENT_ICY_BLAST_2,
};

enum Misc
{
    SEAT_TYRANNUS = 0
};

struct boss_tyrannusAI : public ScriptedAI
{
    boss_tyrannusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    EventMap events;

    void Reset()
    {
        events.Reset();

        if (pInstance)
            pInstance->SetData(DATA_TYRANNUS_EVENT, NOT_STARTED);
    }

    Creature* GetRimefang()
    {
        return me->GetCreature(*me, pInstance->GetData64(DATA_RIMEFANG));
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
        me->ExitVehicle();

        // restore health if any damage done during intro
        me->SetHealth(me->GetMaxHealth());

        if (pInstance)
            pInstance->SetData(DATA_TYRANNUS_EVENT, IN_PROGRESS);

        events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 10000);
        events.ScheduleEvent(EVENT_OVERLORDS_BRAND, 35000);
        events.ScheduleEvent(EVENT_DARK_MIGHT, 40000);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
        {
            pInstance->SetData(DATA_TYRANNUS_EVENT, DONE);
            if (Creature* pRimefang = GetRimefang())
                pRimefang->ForcedDespawn();
        }
    }

    void UpdateAI(const uint32 diff)
    {
         //Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_FORCEFUL_SMASH:
                    DoCast(me->getVictim(), SPELL_FORCEFUL_SMASH);
                    events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 10000);
                    return;
                case EVENT_OVERLORDS_BRAND:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_OVERLORDS_BRAND);
                    events.ScheduleEvent(EVENT_OVERLORDS_BRAND, 45000);
                    return;
                case EVENT_DARK_MIGHT:
                    DoScriptText(SAY_DARK_MIGHT_1, me);
                    DoScriptText(SAY_DARK_MIGHT_2, me);
                    DoCast(me, SPELL_DARK_MIGHT);
                    events.ScheduleEvent(EVENT_DARK_MIGHT, 60000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_rimefangAI : public ScriptedAI
{
    boss_rimefangAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    EventMap events;

    void Reset()
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        me->InterruptSpell(CURRENT_GENERIC_SPELL);
        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        me->InterruptSpell(CURRENT_GENERIC_SPELL);
        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, 25000);
        events.ScheduleEvent(EVENT_ICY_BLAST, 35000);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_MARK_OF_RIMEFANG:
                    DoScriptText(SAY_MARK_RIMEFANG_1, me);
                    DoScriptText(SAY_MARK_RIMEFANG_2, me);

                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_MARK_OF_RIMEFANG);
                    events.ScheduleEvent(EVENT_HOARFROST, 5000);
                    return;
                case EVENT_HOARFROST:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_HOARFROST);
                    events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, 20000);
                    return;
                case EVENT_ICY_BLAST:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_ICY_BLAST);
                    events.ScheduleEvent(EVENT_ICY_BLAST_2, 5000);
                    return;
                case EVENT_ICY_BLAST_2:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget->getVictim(), SPELL_ICY_BLAST_2);
                    events.ScheduleEvent(EVENT_ICY_BLAST, 30000);
                    return;
            }
        }
    }
};

CreatureAI* GetAI_boss_tyrannus(Creature* pCreature)
{
    return new boss_tyrannusAI(pCreature);
}

CreatureAI* GetAI_boss_rimefang(Creature* pCreature)
{
    return new boss_rimefangAI(pCreature);
}

void AddSC_boss_tyrannus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_tyrannus";
    newscript->GetAI = &GetAI_boss_tyrannus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_rimefang";
    newscript->GetAI = &GetAI_boss_rimefang;
    newscript->RegisterSelf();
}
