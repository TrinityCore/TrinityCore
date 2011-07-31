/*
 * Copyright (C) 2009-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
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
#include "forge_of_souls.h"

enum Spells_and_NPCs
{
        //Spiteful Apparition
        SPITEFUL_APPARITION                 = 36551,
        SPITEFUL_APPARITION_DEKO            = 36967,
#define SPELL_SPITEFUL_APPARITION_SPITE     DUNGEON_MODE(68895,70212)
        SPELL_SPITEFUL_APPARITION_VISUAL_1  = 69136,
        SPELL_SPITEFUL_APPARITION_VISUAL_2  = 69658,
        SPELL_FLOATING_SKULL_DND            = 36727,

        //Spectral Warden
        SPELL_VEIL_OF_SHADOWS               = 69633,
#define SPELL_WAIL_OF_SOULS                 DUNGEON_MODE(69148,70210)

        //Soulguard Watchman
        SPELL_SHROUD_OF_RUNES               = 69056,
        SPELL_UNHOLY_RAGE                   = 69053,

        //Soulguard Reaper
#define SPELL_FROST_NOVA                    DUNGEON_MODE(69060,70209)
        SPELL_SHADOW_LANCE                  = 69058,

        //Soulguard Bonecaster
#define SPELL_BONE_VOLLEY                   DUNGEON_MODE(69080,70206)
        SPELL_RAISE_DEAD                    = 69562,
#define SPELL_SHIELD_OF_BONES               DUNGEON_MODE(69069,70207)

        //Soulguard Animator
        // Raise dead 69562
#define SPELL_SHADOW_BOLT                   DUNGEON_MODE(69068,70208)
        SPELL_SOUL_SICKNESS                 = 69131,
        SPELL_SOUL_SIPHON                   = 69128

        //Soulguard Adept
        //Raise dead 69562
        //Shadow Bolt 69068/70208
#define SPELL_DRAIN_LIFE                    DUNGEON_MODE(69066,70213)
#define SPELL_SHADOW_MEND                   DUNGEON_MODE(69564,70205)

        //Soul Horror
#define SPELL_SOUL_STRIKE                   DUNGEON_MODE(69088,70211)
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
    EVENT_SPITEFUL_APPARITION_SPITE,

    //Spectral Warden
    EVENT_VEIL_OF_SHADOWS,
    EVENT_WAIL_OF_SOULS,

    //Soulguard Watchman
    EVENT_SHROUD_OF_RUNES,

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

class npc_sylvanas_fos : public CreatureScript
{
public:
    npc_sylvanas_fos() : CreatureScript("npc_sylvanas_fos") { }

    struct npc_sylvanas_fosAI : public ScriptedAI
    {
        npc_sylvanas_fosAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* pInstance;

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

            if (!UpdateVictim())
                return;

            events.Update(diff);
            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
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

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_sylvanas_fosAI(creature);
    }
};

class npc_jaina_fos : public CreatureScript
{
public:
    npc_jaina_fos() : CreatureScript("npc_jaina_fos") { }

    struct npc_jaina_fosAI: public ScriptedAI
    {
        npc_jaina_fosAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* pInstance;

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

            if (!UpdateVictim())
                return;

            events.Update(diff);

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
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

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_jaina_fosAI(creature);
    }
};

class mob_spiteful_apparition : public CreatureScript
{
public:
    mob_spiteful_apparition() : CreatureScript("mob_spiteful_apparition") { }

    struct mob_spiteful_apparitionAI: public ScriptedAI
    {
        mob_spiteful_apparitionAI(Creature *c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset()
        {
            switch(me->GetEntry())
            {
                case SPITEFUL_APPARITION:
                    me->SetDisplayId(11686);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(SPELL_SPITEFUL_APPARITION_VISUAL_1);
                    events.Reset();
                    break;
                case SPITEFUL_APPARITION_DEKO:
                    me->SetReactState(REACT_PASSIVE);
                    me->SetDisplayId(25942);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_SPITEFUL_APPARITION_VISUAL_2);
                    DoCast(me, SPELL_FLOATING_SKULL_DND, true);
                    break;
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            switch(me->GetEntry())
            {
                case SPITEFUL_APPARITION:
                    if (me->IsHostileTo(who))
                    {
                        float fAttackRadius = me->GetAttackDistance(who);
                        if (me->IsWithinDistInMap(who, fAttackRadius))
                        {
                            if (!me->getVictim())
                            {
                                who->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                                AttackStart(who);
                            }
                            else
                            {
                                who->SetInCombatWith(me);
                                me->AddThreat(who, 0.0f);
                            }
                        }
                    }
                    break;
            }
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            switch(me->GetEntry())
            {
                case SPITEFUL_APPARITION:
                    if (uiDamage >= me->GetHealth() && !me->HasUnitState(UNIT_STAT_CASTING))
                    {
                        DoCast(me, SPELL_SPITEFUL_APPARITION_SPITE);
                        uiDamage = 0;
                    }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            switch(me->GetEntry())
            {
                case SPITEFUL_APPARITION:
                    me->SetDisplayId(25942);
                    DoCast(me, SPELL_SPITEFUL_APPARITION_VISUAL_1);
                    DoCast(me, SPELL_FLOATING_SKULL_DND, true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    events.ScheduleEvent(EVENT_SPITEFUL_APPARITION_SPITE, urand(3000,5000));
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(me->GetEntry())
                {
                    case SPITEFUL_APPARITION:
                        switch(eventId)
                        {
                            case EVENT_SPITEFUL_APPARITION_SPITE:
                                DoCast(me, SPELL_SPITEFUL_APPARITION_SPITE);
                                events.CancelEvent(EVENT_SPITEFUL_APPARITION_SPITE);
                                me->ForcedDespawn(3500);
                                break;
                        }
                        break;
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_spiteful_apparitionAI(creature);
    }
};

class mob_spectral_warden : public CreatureScript
{
public:
    mob_spectral_warden() : CreatureScript("mob_spectral_warden") { }

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
            events.ScheduleEvent(EVENT_VEIL_OF_SHADOWS, urand(3000,5000));
            events.ScheduleEvent(EVENT_WAIL_OF_SOULS, 10000);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_VEIL_OF_SHADOWS:
                        DoCastVictim(SPELL_VEIL_OF_SHADOWS);
                        events.RescheduleEvent(EVENT_VEIL_OF_SHADOWS, 10000);
                        return;
                    case EVENT_WAIL_OF_SOULS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_WAIL_OF_SOULS);
                        events.RescheduleEvent(EVENT_WAIL_OF_SOULS, 5000);
                        return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_spectral_wardenAI(creature);
    }
};

class mob_soulguard_watchman : public CreatureScript
{
public:
    mob_soulguard_watchman() : CreatureScript("mob_soulguard_watchman") { }

    struct mob_soulguard_watchmanAI: public ScriptedAI
    {
        mob_soulguard_watchmanAI(Creature *c) : ScriptedAI(c)
        {
        }

        EventMap events;
        bool rage;

        void Reset()
        {
            rage = false;
            events.Reset();
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            if (!rage && me->HealthBelowPctDamaged(25, uiDamage))
            {
                DoCast(me, SPELL_UNHOLY_RAGE);
                rage = true;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHROUD_OF_RUNES, urand(5000,15000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SHROUD_OF_RUNES:
                        DoCast(me, SPELL_SHROUD_OF_RUNES);
                        events.CancelEvent(EVENT_SHROUD_OF_RUNES);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soulguard_watchmanAI(creature);
    }
};

class mob_soulguard_reaper : public CreatureScript
{
public:
    mob_soulguard_reaper() : CreatureScript("mob_soulguard_reaper") { }

    struct mob_soulguard_reaperAI: public ScriptedAI
    {
        mob_soulguard_reaperAI(Creature *c) : ScriptedAI(c) { }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FROST_NOVA, urand(5000,10000));
            events.ScheduleEvent(EVENT_SHADOW_LANCE, urand(5000,10000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FROST_NOVA:
                        DoCast(me, SPELL_FROST_NOVA);
                        events.RescheduleEvent(EVENT_FROST_NOVA, urand(10000,20000));
                        break;
                    case EVENT_SHADOW_LANCE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOW_LANCE);
                        events.RescheduleEvent(EVENT_SHADOW_LANCE, urand(5000,10000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soulguard_reaperAI(creature);
    }
};

class mob_soulguard_bonecaster : public CreatureScript
{
public:
    mob_soulguard_bonecaster() : CreatureScript("mob_soulguard_bonecaster") { }

    struct mob_soulguard_bonecasterAI: public ScriptedAI
    {
        mob_soulguard_bonecasterAI(Creature *c) : ScriptedAI(c) { }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_BONE_VOLLEY, urand(100,3000));
            events.ScheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
            events.ScheduleEvent(EVENT_SHIELD_OF_BONES, urand(4000,8000));

            me->CallForHelp(20);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_BONE_VOLLEY:
                        DoCastAOE(SPELL_BONE_VOLLEY);
                        events.RescheduleEvent(EVENT_BONE_VOLLEY, urand(5000,15000));
                        break;
                    case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISE_DEAD);
                        events.RescheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
                        break;
                    case EVENT_SHIELD_OF_BONES:
                        DoCast(me, SPELL_SHIELD_OF_BONES);
                        events.RescheduleEvent(EVENT_SHIELD_OF_BONES, urand(10000,20000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soulguard_bonecasterAI(creature);
    }
};

class mob_soulguard_animator : public CreatureScript
{
public:
    mob_soulguard_animator() : CreatureScript("mob_soulguard_animator") { }

    struct mob_soulguard_animatorAI : public ScriptedAI
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
            events.ScheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(100, 5000));
            events.ScheduleEvent(EVENT_SOUL_SICKNESS, urand(10000,20000));
            events.ScheduleEvent(EVENT_SOUL_SIPHON, urand(10000,20000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISE_DEAD);
                        events.RescheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
                        break;
                    case EVENT_SHADOW_BOLT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, urand(5000,10000));
                        break;
                    case EVENT_SOUL_SICKNESS:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SOUL_SICKNESS);
                        events.RescheduleEvent(EVENT_SOUL_SICKNESS, urand(10000,20000));
                        break;
                    case EVENT_SOUL_SIPHON:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SOUL_SIPHON);
                        events.RescheduleEvent(EVENT_SOUL_SIPHON, urand(10000,20000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soulguard_animatorAI(creature);
    }
};

class mob_soulguard_adept : public CreatureScript
{
public:
    mob_soulguard_adept() : CreatureScript("mob_soulguard_adept") { }

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
            events.ScheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(100,3000));
            events.ScheduleEvent(EVENT_DRAIN_LIFE, urand(5000,15000));
            events.ScheduleEvent(EVENT_SHADOW_MEND, urand(15000,25000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISE_DEAD);
                        events.RescheduleEvent(EVENT_RAISE_DEAD, urand(25000,35000));
                        break;
                    case EVENT_SHADOW_BOLT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, urand(5000,10000));
                        break;
                    case EVENT_DRAIN_LIFE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_DRAIN_LIFE);
                        events.RescheduleEvent(EVENT_DRAIN_LIFE, urand(10000,20000));
                        break;
                    case EVENT_SHADOW_MEND:
                        if (Unit* pTarget = DoSelectLowestHpFriendly(39, 11000))
                            DoCast(pTarget, SPELL_SHADOW_MEND);
                        else
                            DoCast(me, SPELL_SHADOW_MEND);
                        events.RescheduleEvent(EVENT_SHADOW_MEND, urand(10000,20000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soulguard_adeptAI(creature);
    }
};

class mob_soul_horror : public CreatureScript
{
public:
    mob_soul_horror() : CreatureScript("mob_soul_horror") { }

    struct mob_soul_horrorAI : public ScriptedAI
    {
        mob_soul_horrorAI(Creature *c) : ScriptedAI(c) { }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SOUL_STRIKE, urand(100,3000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SOUL_STRIKE:
                        DoCast(me->getVictim(), SPELL_SOUL_STRIKE);
                        events.RescheduleEvent(EVENT_SOUL_STRIKE, urand(3000,8000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_soul_horrorAI(creature);
    }
};

void AddSC_forge_of_souls()
{
    new npc_sylvanas_fos;
    new npc_jaina_fos;
    new mob_spiteful_apparition;
    new mob_spectral_warden;
    new mob_soulguard_watchman;
    new mob_soulguard_reaper;
    new mob_soulguard_bonecaster;
    new mob_soulguard_animator;
    new mob_soulguard_adept;
    new mob_soul_horror;
}
