/* Copyright (C) 2006 - 2010 TrinityCore <https://www.trinitycore.org/>
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
#include "forge_of_souls.h"

enum Spells
{
    //Spiteful Apparition
    SPELL_SPITE                                 = 68895,
    H_SPELL_SPITE                               = 70212,

    //Spectral Warden
    SPELL_VEIL_OF_SHADOWS                       = 69633,
    SPELL_WAIL_OF_SOULS                         = 69148,
    H_SPELL_WAIL_OF_SOULS                       = 70210,

    //Soulguard Watchman
    SPELL_SHROUD_OF_RUNES                       = 69056,
    SPELL_UNHOLY_RAGE                           = 69053,

    //Soulguard Reaper
    SPELL_FROST_NOVA                            = 69060,
    H_SPELL_FROST_NOVA                          = 70209,
    SPELL_SHADOW_LANCE                          = 69058,

    //Soulguard Bonecaster
    SPELL_BONE_VOLLEY                           = 69080,
    H_SPELL_BONE_VOLLEY                         = 70206,
    SPELL_RAISE_DEAD                            = 69562,
    SPELL_SHIELD_OF_BONES                       = 69069,
    H_SPELL_SHIELD_OF_BONES                     = 70207,

    //Soulguard Animator
    // Raise dead 69562
    SPELL_SHADOW_BOLT                           = 69068,
    H_SPELL_SHADOW_BOLT                         = 70208,
    SPELL_SOUL_SICKNESS                         = 69131,
    SPELL_SOUL_SIPHON                           = 69128,

    //Soulguard Adept
    //Raise dead 69562
    //Shadow Bolt 69068/70208
    SPELL_DRAIN_LIFE                            = 69066,
    H_SPELL_DRAIN_LIFE                          = 70213,
    SPELL_SHADOW_MEND                           = 69564,
    H_SPELL_SHADOW_MEND                         = 70205,

    //Soul Horror
    SPELL_SOUL_STRIKE                           = 69088,
    H_SPELL_SOUL_STRIKE                         = 70211,
};

enum Events
{
    EVENT_NONE,

    // Jaina/Sylvanas Intro
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_INTRO_8,

    //Spiteful Apparition
    EVENT_SPITE,

    //Spectral Warden
    EVENT_VEIL_OF_SHADOWS,
    EVENT_WAIL_OF_SOULS,

    //Soulguard Watchman
    EVENT_SHROUD_OF_RUNES,
    EVENT_UNHOLY_RAGE,

    //Soulguard Reaper
    EVENT_FROST_NOVA,
    EVENT_SHADOW_LANCE,

    //Soulguard Bonecaster
    EVENT_BONE_VOLLEY,
    EVENT_RAISE_DEAD,
    EVENT_SHIELD_OF_BONES,

    //Soulguard Animator
    EVENT_SHADOW_BOLT,
    EVENT_SOUL_SICKNESS,
    EVENT_SOUL_SIPHON,

    //Soulguard Adept
    EVENT_DRAIN_LIFE,
    EVENT_SHADOW_MEND,

    //Soul Horror
    EVENT_SOUL_STRIKE,
};

/****************************************SYLVANAS************************************/
#define GOSSIP_SYLVANAS_ITEM    "What would you have of me, Banshee Queen?"
#define GOSSIP_JAINA_ITEM       "What would you have of me, my lady?"

enum Yells
{
    SAY_JAINA_INTRO_1                           = -1632040,
    SAY_JAINA_INTRO_2                           = -1632041,
    SAY_JAINA_INTRO_3                           = -1632042,
    SAY_JAINA_INTRO_4                           = -1632043,
    SAY_JAINA_INTRO_5                           = -1632044,
    SAY_JAINA_INTRO_6                           = -1632045,
    SAY_JAINA_INTRO_7                           = -1632046,
    SAY_JAINA_INTRO_8                           = -1632047,

    SAY_SYLVANAS_INTRO_1                        = -1632050,
    SAY_SYLVANAS_INTRO_2                        = -1632051,
    SAY_SYLVANAS_INTRO_3                        = -1632052,
    SAY_SYLVANAS_INTRO_4                        = -1632053,
    SAY_SYLVANAS_INTRO_5                        = -1632054,
    SAY_SYLVANAS_INTRO_6                        = -1632055,
};

enum eSylvanas
{
    GOSSIP_SPEECHINTRO                           = 13525,
    ACTION_INTRO,
};

enum Phase
{
    PHASE_NORMAL,
    PHASE_INTRO,
};

struct npc_sylvanas_fosAI: public ScriptedAI
{
    npc_sylvanas_fosAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    ScriptedInstance* pInstance;

    EventMap events;
    Phase phase;

    void Reset()
    {
        events.Reset();
        phase = PHASE_NORMAL;
    }

    void DoAction(const int32 actionId)
    {
        switch(actionId)
        {
            case ACTION_INTRO:
            {
                phase = PHASE_INTRO;
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                events.Reset();
                events.ScheduleEvent(EVENT_INTRO_1, 1000);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (phase == PHASE_INTRO)
        {
            if (!pInstance)
                return;

            events.Update(diff);
            switch(events.ExecuteEvent())
            {
                case EVENT_INTRO_1:
                    DoScriptText(SAY_SYLVANAS_INTRO_1, me);
                    events.ScheduleEvent(EVENT_INTRO_2, 11500);
                    break;

                case EVENT_INTRO_2:
                    DoScriptText(SAY_SYLVANAS_INTRO_2, me);
                    events.ScheduleEvent(EVENT_INTRO_3, 10500);
                    break;

                case EVENT_INTRO_3:
                    DoScriptText(SAY_SYLVANAS_INTRO_3, me);
                    events.ScheduleEvent(EVENT_INTRO_4, 9500);
                    break;

                case EVENT_INTRO_4:
                    DoScriptText(SAY_SYLVANAS_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_5, 10500);
                    break;

                case EVENT_INTRO_5:
                    DoScriptText(SAY_SYLVANAS_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_6, 9500);
                    break;

                case EVENT_INTRO_6:
                    DoScriptText(SAY_SYLVANAS_INTRO_6, me);
                    // End of Intro
                    phase = PHASE_NORMAL;
                    break;
            }
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        //if (me->hasUnitState(UNIT_STAT_CASTING))
        //    return;

        //while (uint32 eventId = events.ExecuteEvent())
        //{
        //    switch(eventId)
        //    {
        //    }
        //}

        DoMeleeAttackIfReady();
    }
};

struct npc_jaina_fosAI: public ScriptedAI
{
    npc_jaina_fosAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    ScriptedInstance* pInstance;

    EventMap events;
    Phase phase;

    void Reset()
    {
        events.Reset();
        phase = PHASE_NORMAL;
    }

    void DoAction(const int32 actionId)
    {
        switch(actionId)
        {
            case ACTION_INTRO:
            {
                phase = PHASE_INTRO;
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                events.Reset();
                events.ScheduleEvent(EVENT_INTRO_1, 1000);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (phase == PHASE_INTRO)
        {
            if (!pInstance)
                return;

            events.Update(diff);
            switch(events.ExecuteEvent())
            {
                case EVENT_INTRO_1:
                    DoScriptText(SAY_JAINA_INTRO_1, me);
                    events.ScheduleEvent(EVENT_INTRO_2, 8000);
                    break;

                case EVENT_INTRO_2:
                    DoScriptText(SAY_JAINA_INTRO_2, me);
                    events.ScheduleEvent(EVENT_INTRO_3, 8500);
                    break;

                case EVENT_INTRO_3:
                    DoScriptText(SAY_JAINA_INTRO_3, me);
                    events.ScheduleEvent(EVENT_INTRO_4, 8000);
                    break;

                case EVENT_INTRO_4:
                    DoScriptText(SAY_JAINA_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_5, 10000);
                    break;

                case EVENT_INTRO_5:
                    DoScriptText(SAY_JAINA_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_6, 8000);
                    break;

                case EVENT_INTRO_6:
                    DoScriptText(SAY_JAINA_INTRO_6, me);
                    events.ScheduleEvent(EVENT_INTRO_7, 12000);
                    break;

                case EVENT_INTRO_7:
                    DoScriptText(SAY_JAINA_INTRO_7, me);
                    events.ScheduleEvent(EVENT_INTRO_8, 8000);
                    break;

                case EVENT_INTRO_8:
                    DoScriptText(SAY_JAINA_INTRO_8, me);
                    // End of Intro
                    phase = PHASE_NORMAL;
                    break;
            }
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        //if (me->hasUnitState(UNIT_STAT_CASTING))
        //    return;

        //while (uint32 eventId = events.ExecuteEvent())
        //{
        //    switch(eventId)
        //    {
        //    }
        //}

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_jaina_or_slyvanas_fos(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->GetEntry() == NPC_JAINA_PART1)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    else
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_jaina_or_slyvanas_fos(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();

            if (pCreature->AI())
                pCreature->AI()->DoAction(ACTION_INTRO);
            break;
    }

    return true;
}

struct mob_spiteful_apparitionAI: public ScriptedAI
{
    mob_spiteful_apparitionAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_SPITE, 8000);
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
                case EVENT_SPITE:
                    DoCast(me->getVictim(), SPELL_SPITE);
                    events.RescheduleEvent(EVENT_SPITE, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_spectral_wardenAI: public ScriptedAI
{
    mob_spectral_wardenAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_VEIL_OF_SHADOWS, 5000);
        events.ScheduleEvent(EVENT_WAIL_OF_SOULS, 10000);
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
                case EVENT_VEIL_OF_SHADOWS:
                    DoCast(me->getVictim(), SPELL_VEIL_OF_SHADOWS);
                    events.RescheduleEvent(EVENT_VEIL_OF_SHADOWS, 10000);
                    return;
                case EVENT_WAIL_OF_SOULS:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_WAIL_OF_SOULS);
                    events.RescheduleEvent(EVENT_WAIL_OF_SOULS, 5000);
                    return;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct mob_soulguard_watchmanAI: public ScriptedAI
{
    mob_soulguard_watchmanAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_SHROUD_OF_RUNES, 1000);
        events.ScheduleEvent(EVENT_UNHOLY_RAGE, 1000);
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
                case EVENT_SHROUD_OF_RUNES:
                    DoCast(me, SPELL_SHROUD_OF_RUNES);
                    events.RescheduleEvent(EVENT_SHROUD_OF_RUNES, 5000);
                    return;
                case EVENT_UNHOLY_RAGE:
                    DoCast(me, SPELL_UNHOLY_RAGE);
                    events.RescheduleEvent(EVENT_UNHOLY_RAGE, 99999);
                    return;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct mob_soulguard_reaperAI: public ScriptedAI
{
    mob_soulguard_reaperAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_FROST_NOVA, 8000);
        events.ScheduleEvent(EVENT_SHADOW_LANCE, 5000);
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
                case EVENT_FROST_NOVA:
                    DoCast(me, SPELL_FROST_NOVA);
                    events.RescheduleEvent(EVENT_FROST_NOVA, 9600);
                    return;
                case EVENT_SHADOW_LANCE:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_LANCE);
                    events.RescheduleEvent(EVENT_SHADOW_LANCE, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct  mob_soulguard_bonecasterAI: public ScriptedAI
{
    mob_soulguard_bonecasterAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_BONE_VOLLEY, 6000);
        events.ScheduleEvent(EVENT_RAISE_DEAD, 25000);
        events.ScheduleEvent(EVENT_SHIELD_OF_BONES, 6000);
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
                case EVENT_BONE_VOLLEY:
                    DoCastAOE(SPELL_BONE_VOLLEY);
                    events.RescheduleEvent(EVENT_BONE_VOLLEY, 7000);
                    return;
                case EVENT_RAISE_DEAD:
                    DoCast(me, SPELL_RAISE_DEAD);
                    events.RescheduleEvent(EVENT_RAISE_DEAD, 25000);
                    return;
                case EVENT_SHIELD_OF_BONES:
                    DoCast(me, SPELL_SHIELD_OF_BONES);
                    events.RescheduleEvent(EVENT_SHIELD_OF_BONES, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_soulguard_animatorAI: public ScriptedAI
{
    mob_soulguard_animatorAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_RAISE_DEAD, 25000);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 5000);
        events.ScheduleEvent(EVENT_SOUL_SICKNESS, 8000);
        events.ScheduleEvent(EVENT_SOUL_SIPHON, 10000);
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
                case EVENT_RAISE_DEAD:
                    DoCast(me, SPELL_RAISE_DEAD);
                    events.RescheduleEvent(EVENT_RAISE_DEAD, 25000);
                    return;
                case EVENT_SHADOW_BOLT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_BOLT);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT, 5000);
                    return;
                case EVENT_SOUL_SICKNESS:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SOUL_SICKNESS);
                    events.RescheduleEvent(EVENT_SOUL_SICKNESS, 10000);
                    return;
                case EVENT_SOUL_SIPHON:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SOUL_SIPHON);
                    events.RescheduleEvent(EVENT_SOUL_SIPHON, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_soulguard_adeptAI: public ScriptedAI
{
    mob_soulguard_adeptAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_RAISE_DEAD, 25000);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 8000);
        events.ScheduleEvent(EVENT_DRAIN_LIFE, 7000);
        events.ScheduleEvent(EVENT_SHADOW_MEND, 35000);
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
                case EVENT_RAISE_DEAD:
                    DoCast(me, SPELL_RAISE_DEAD);
                    events.RescheduleEvent(EVENT_RAISE_DEAD, 25000);
                    return;
                case EVENT_SHADOW_BOLT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_BOLT);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT, 4000);
                    return;
                case EVENT_DRAIN_LIFE:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_DRAIN_LIFE);
                    events.RescheduleEvent(EVENT_DRAIN_LIFE, 9000);
                    return;
                case EVENT_SHADOW_MEND:
                    DoCast(me, SPELL_SHADOW_MEND);
                    events.RescheduleEvent(EVENT_SHADOW_MEND, 20000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_soul_horrorAI: public ScriptedAI
{
    mob_soul_horrorAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_SOUL_STRIKE, 6000);
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
                case EVENT_SOUL_STRIKE:
                    DoCast(me->getVictim(), SPELL_SOUL_STRIKE);
                    events.RescheduleEvent(EVENT_SOUL_STRIKE, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_jaina_fosAI(Creature* pCreature)
{
    return new npc_jaina_fosAI(pCreature);
};

CreatureAI* GetAI_npc_sylvanas_fosAI(Creature* pCreature)
{
    return new npc_sylvanas_fosAI(pCreature);
};

CreatureAI* GetAI_mob_spiteful_apparitionAI(Creature* pCreature)
{
    return new mob_spiteful_apparitionAI(pCreature);
}

CreatureAI* GetAI_mob_spectral_wardenAI(Creature* pCreature)
{
    return new mob_spectral_wardenAI(pCreature);
}

CreatureAI* GetAI_mob_soulguard_watchmanAI(Creature* pCreature)
{
    return new mob_soulguard_watchmanAI(pCreature);
}

CreatureAI* GetAI_mob_soulguard_reaperAI(Creature* pCreature)
{
    return new mob_soulguard_reaperAI(pCreature);
}

CreatureAI* GetAI_mob_soulguard_bonecasterAI(Creature* pCreature)
{
    return new mob_soulguard_bonecasterAI(pCreature);
}

CreatureAI* GetAI_mob_soulguard_animatorAI(Creature* pCreature)
{
    return new mob_soulguard_animatorAI(pCreature);
}

CreatureAI* GetAI_mob_soulguard_adeptAI(Creature* pCreature)
{
    return new mob_soulguard_adeptAI(pCreature);
}

CreatureAI* GetAI_mob_soul_horrorAI(Creature* pCreature)
{
    return new mob_soul_horrorAI(pCreature);
}

void AddSC_forge_of_souls()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_sylvanas_fos";
    newscript->GetAI = &GetAI_npc_sylvanas_fosAI;
    newscript->pGossipHello = &GossipHello_npc_jaina_or_slyvanas_fos;
    newscript->pGossipSelect = &GossipSelect_npc_jaina_or_slyvanas_fos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_jaina_fos";
    newscript->GetAI = &GetAI_npc_jaina_fosAI;
    newscript->pGossipHello = &GossipHello_npc_jaina_or_slyvanas_fos;
    newscript->pGossipSelect = &GossipSelect_npc_jaina_or_slyvanas_fos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_spiteful_apparition";
    newscript->GetAI = &GetAI_mob_spiteful_apparitionAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_spectral_warden";
    newscript->GetAI = &GetAI_mob_spectral_wardenAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soulguard_watchman";
    newscript->GetAI = &GetAI_mob_soulguard_watchmanAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soulguard_reaper";
    newscript->GetAI = &GetAI_mob_soulguard_reaperAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soulguard_bonecaster";
    newscript->GetAI = &GetAI_mob_soulguard_bonecasterAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soulguard_animator";
    newscript->GetAI = &GetAI_mob_soulguard_animatorAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soulguard_adept";
    newscript->GetAI = &GetAI_mob_soulguard_adeptAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_soul_horror";
    newscript->GetAI = &GetAI_mob_soul_horrorAI;
    newscript->RegisterSelf();
}
