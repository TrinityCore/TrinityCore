/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

class npc_sylvanas_fos : public CreatureScript
{
public:
    npc_sylvanas_fos() : CreatureScript("npc_sylvanas_fos") { }

    struct npc_sylvanas_fosAI : public ScriptedAI
    {
        npc_sylvanas_fosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* instance;

        EventMap events;
        Phase phase;

        void Reset()
        {
            events.Reset();
            phase = PHASE_NORMAL;
        }

        void DoAction(const int32 actionId)
        {
            switch (actionId)
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
                if (!instance)
                    return;

                events.Update(diff);
                switch (events.ExecuteEvent())
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
            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->GetEntry() == NPC_JAINA_PART1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();

                if (creature->AI())
                    creature->AI()->DoAction(ACTION_INTRO);
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
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
        npc_jaina_fosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* instance;

        EventMap events;
        Phase phase;

        void Reset()
        {
            events.Reset();
            phase = PHASE_NORMAL;
        }

        void DoAction(const int32 actionId)
        {
            switch (actionId)
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
                if (!instance)
                    return;

                events.Update(diff);
                switch (events.ExecuteEvent())
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

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->GetEntry() == NPC_JAINA_PART1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();

                if (creature->AI())
                    creature->AI()->DoAction(ACTION_INTRO);
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
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
        mob_spiteful_apparitionAI(Creature* creature) : ScriptedAI(creature)
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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPITE:
                        DoCastVictim(SPELL_SPITE);
                        events.RescheduleEvent(EVENT_SPITE, 8000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
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
        mob_spectral_wardenAI(Creature* creature) : ScriptedAI(creature)
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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
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

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soulguard_watchmanAI(Creature* creature) : ScriptedAI(creature) { }

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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
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

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soulguard_reaperAI(Creature* creature) : ScriptedAI(creature) { }

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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FROST_NOVA:
                        DoCast(me, SPELL_FROST_NOVA);
                        events.RescheduleEvent(EVENT_FROST_NOVA, 9600);
                        return;
                    case EVENT_SHADOW_LANCE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_LANCE);
                        events.RescheduleEvent(EVENT_SHADOW_LANCE, 8000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soulguard_bonecasterAI(Creature* creature) : ScriptedAI(creature) { }

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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
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

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soulguard_animatorAI(Creature* creature) : ScriptedAI(creature)
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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISE_DEAD);
                        events.RescheduleEvent(EVENT_RAISE_DEAD, 25000);
                        return;
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, 5000);
                        return;
                    case EVENT_SOUL_SICKNESS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SOUL_SICKNESS);
                        events.RescheduleEvent(EVENT_SOUL_SICKNESS, 10000);
                        return;
                    case EVENT_SOUL_SIPHON:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SOUL_SIPHON);
                        events.RescheduleEvent(EVENT_SOUL_SIPHON, 8000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soulguard_adeptAI(Creature* creature) : ScriptedAI(creature)
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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISE_DEAD);
                        events.RescheduleEvent(EVENT_RAISE_DEAD, 25000);
                        return;
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, 4000);
                        return;
                    case EVENT_DRAIN_LIFE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_DRAIN_LIFE);
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

    CreatureAI* GetAI(Creature* creature) const
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
        mob_soul_horrorAI(Creature* creature) : ScriptedAI(creature) { }

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

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_soul_horrorAI(creature);
    }
};

void AddSC_forge_of_souls()
{
    new npc_sylvanas_fos();
    new npc_jaina_fos();
    new mob_spiteful_apparition();
    new mob_spectral_warden();
    new mob_soulguard_watchman();
    new mob_soulguard_reaper();
    new mob_soulguard_bonecaster();
    new mob_soulguard_animator();
    new mob_soulguard_adept();
    new mob_soul_horror();
}
