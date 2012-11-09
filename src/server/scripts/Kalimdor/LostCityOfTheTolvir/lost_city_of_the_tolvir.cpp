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
 
#include"ScriptPCH.h"
#include"lost_city_of_the_tolvir.h"

enum Spells
{
    // Blaze of Heavens
    SPELL_BLAZE                 = 48906,

    // Harbinger of Death
    SPELL_SOUL_SEVER            = 82255,
    SPELL_WAIL_DARKNESS         = 82533,
    H_SPELL_WAIL_DARKNESS       = 90038,

    // Minion of Siamat
    SPELL_CHAIN_LIGHTNING       = 44704,
    H_SPELL_CHAIN_LIGHTNING     = 90027,

    // Neferset Darkcaster
    SPELL_HEX                   = 82760,
    SPELL_METEOR                = 84032,
    H_SPELL_METEOR              = 90023,
    SPELL_SHADOW_BOLT           = 82765,
    H_SPELL_SHADOW_BOLT         = 90036,

    // Neferset Plaguebringer
    SPELL_DISEASE_BREATH        = 73976,
    H_SPELL_DISEASE_BREATH      = 90005,
    SPELL_INFECTIOUS_PLAGUE     = 82768,

    // Neferset Theurgist
    SPELL_MIXTURE = 82759,
    SPELL_RITUAL_BLOODLETTING   = 82753,
    H_SPELL_RITUAL_BLOODLETTING = 89993,
    SPELL_VICIOUS_LEECHES       = 82757,

    // Neferset Torturer
    SPELL_BRANDED_TONGUE        = 82744,
    H_SPELL_BRANDED_TONGUE      = 90037,
    SPELL_SERUM_TORMENT         = 82750,
    H_SPELL_SERUM_TORMENT       = 89994,

    // Oathsworn Axemaster
    SPELL_SKULL_CRUSH           = 44922,
    SPELL_SLAM                  = 82763,

    // Oathsworn Captain
    SPELL_SKULL_CRACK           = 82670,

    // Oathsworn Myrmidon
    SPELL_BLADED_SHIELD         = 82671,
    H_SPELL_BLADED_SHIELD       = 95184,
    SPELL_RESISTANCE            = 82673,

    // Oathsworn Pathfinder
    SPELL_CALL_FALCON           = 82792,
    SPELL_SHOOT                 = 83877,
    SPELL_WING_CLIP             = 82764,

    // Oathsworn Scorpid Keeper
    SPELL_BLINK                 = 84123,
    SPELL_CALL_SCORPID          = 84126,
    SPELL_EVASION               = 84122,

    // Oathsworn Skinner
    SPELL_FAN_KNIVES            = 82789,
    H_SPELL_FAN_KNIVES          = 90034,
    SPELL_SPINAL_PIERCE         = 84031,

    // Oathsworn Tamer
    SPELL_FERAL_LINK            = 84230,

    // Wanderer
    SPELL_CALL_CROCO            = 82791,
    SPELL_FORKED_SHOT           = 82794,
    H_SPELL_FORKED_SHOT         = 89992,

    // Pygmy Brute
    SPELL_IMPALE                = 83783,
    H_SPELL_IMPALE              = 89990,
    SPELL_SHOCKWAVE             = 83785,
    H_SPELL_SHOCKWAVE           = 90024,

    // Pygmy Fire Breather
    SPELL_DRAGON_BREATH         = 83776,
    H_SPELL_DRAGON_BREATH       = 90026,
    SPELL_FIRE_BLAST            = 83778,
    H_SPELL_FIREBLAST           = 90025,

    // Pygmy Scout
    SPELL_TOXIC_DART            = 83780,
    H_SPELL_TOXIC_DART          = 89991,

    // Servent of Siamat
    SPELL_LIGHTNING_NOVA        = 84544,
    H_SPELL_LIGHTNING_NOVA      = 90015,
    SPELL_THUNDER_CRASH         = 84521,
};

enum eEvents
{
    EVENT_NONE,
    EVENT_BLAZE,
    EVENT_SOUL_SEVER,
    EVENT_WAIL_DARKNESS,
    EVENT_CHAIN_LIGHTNING,
    EVENT_HEX,
    EVENT_METEOR,
    EVENT_SHADOW_BOLT,
    EVENT_DISEASE_BREATH,
    EVENT_INFECTIOUS_PLAGUE,
    EVENT_MIXTURE,
    EVENT_RITUAL_BLOODLETTING,
    EVENT_VICIOUS_LEECHES,
    EVENT_BRANDED_TONGUE,
    EVENT_SERUM_TORMENT,
    EVENT_SKULL_CRUSH,
    EVENT_SLAM,
    EVENT_SKULL_CRACK,
    EVENT_BLADED_SHIELD,
    EVENT_RESISTANCE,
    EVENT_CALL_FALCON,
    EVENT_SHOOT,
    EVENT_WING_CLIP,
    EVENT_BLINK,
    EVENT_CALL_SCORPID,
    EVENT_EVASION,
    EVENT_FAN_KNIVES,
    EVENT_SPINAL_PIERCE,
    EVENT_FERAL_LINK,
    EVENT_CALL_CROCO,
    EVENT_FORKED_SHOT,
    EVENT_IMPALE,
    EVENT_SHOCKWAVE,
    EVENT_DRAGON_BREATH,
    EVENT_FIRE_BLAST,
    EVENT_TOXIC_DART,
    EVENT_LIGHTNING_NOVA,
    EVENT_THUNDER_CRASH,
};

class npc_neferset_darkcaster : public CreatureScript
{
public:
    npc_neferset_darkcaster() : CreatureScript("npc_neferset_darkcaster") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_neferset_darkcasterAI(creature);
    }

    struct npc_neferset_darkcasterAI : public ScriptedAI
    {
        npc_neferset_darkcasterAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_HEX, 8000);
            events.ScheduleEvent(EVENT_METEOR, 5000);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 6000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HEX:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_HEX);
                        events.RescheduleEvent(EVENT_HEX, 5000);
                        return;
                    case EVENT_METEOR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_METEOR);
                        events.RescheduleEvent(EVENT_METEOR, 5000);
                        return;
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, 3000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_neferset_plaguebringer : public CreatureScript
{
public:
    npc_neferset_plaguebringer() : CreatureScript("npc_neferset_plaguebringer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_neferset_plaguebringerAI(creature);
    }

    struct npc_neferset_plaguebringerAI : public ScriptedAI
    {
        npc_neferset_plaguebringerAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_DISEASE_BREATH, 5000);
            events.ScheduleEvent(EVENT_INFECTIOUS_PLAGUE, 7000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DISEASE_BREATH:
                        DoCast(me->getVictim(), SPELL_DISEASE_BREATH);
                        events.RescheduleEvent(EVENT_DISEASE_BREATH, 5000);
                        return;
                    case EVENT_INFECTIOUS_PLAGUE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_INFECTIOUS_PLAGUE);
                        events.RescheduleEvent(EVENT_INFECTIOUS_PLAGUE, 5000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_neferset_theurgist : public CreatureScript
{
public:
    npc_neferset_theurgist() : CreatureScript("npc_neferset_theurgist"){ }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_neferset_theurgistAI(creature);
    }

    struct npc_neferset_theurgistAI : public ScriptedAI
    {
        npc_neferset_theurgistAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_MIXTURE, 10000);
            events.ScheduleEvent(EVENT_RITUAL_BLOODLETTING, 4000);
            events.ScheduleEvent(EVENT_VICIOUS_LEECHES, 7000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MIXTURE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_MIXTURE);
                        events.RescheduleEvent(EVENT_MIXTURE, 6000);
                        return;
                    case EVENT_RITUAL_BLOODLETTING:
                        DoCast(me->getVictim(), SPELL_RITUAL_BLOODLETTING);
                        events.RescheduleEvent(EVENT_RITUAL_BLOODLETTING, 2000);
                        return;
                    case EVENT_VICIOUS_LEECHES:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_VICIOUS_LEECHES);
                        events.RescheduleEvent(EVENT_VICIOUS_LEECHES, 5000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_neferset_torturer : public CreatureScript
{
public:
    npc_neferset_torturer() : CreatureScript("npc_neferset_torturer"){ }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_neferset_torturerAI(creature);
    }

    struct npc_neferset_torturerAI : public ScriptedAI
    {
        npc_neferset_torturerAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_BRANDED_TONGUE, 5000);
            events.ScheduleEvent(EVENT_SERUM_TORMENT, 4000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BRANDED_TONGUE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_BRANDED_TONGUE);
                        events.RescheduleEvent(EVENT_BRANDED_TONGUE, 3000);
                        return;
                    case EVENT_SERUM_TORMENT:
                        DoCast(me->getVictim(), SPELL_SERUM_TORMENT);
                        events.RescheduleEvent(EVENT_SERUM_TORMENT, 2000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_axemaster : public CreatureScript
{
public:
    npc_oathsworn_axemaster() : CreatureScript("npc_oathsworn_axemaster") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_axemasterAI(creature);
    }

    struct npc_oathsworn_axemasterAI : public ScriptedAI
    {
        npc_oathsworn_axemasterAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SKULL_CRUSH, 5000);
            events.ScheduleEvent(EVENT_SLAM, 3000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SKULL_CRUSH:
                        DoCast(me->getVictim(), SPELL_SKULL_CRUSH);
                        events.RescheduleEvent(EVENT_SKULL_CRUSH, 3000);
                        return;
                    case EVENT_SLAM:
                        DoCast(me->getVictim(), SPELL_SLAM);
                        events.RescheduleEvent(EVENT_SLAM, 2000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_captain : public CreatureScript
{
public:
    npc_oathsworn_captain() : CreatureScript("npc_oathsworn_captain") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_captainAI(creature);
    }

    struct npc_oathsworn_captainAI : public ScriptedAI
    {
        npc_oathsworn_captainAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SKULL_CRACK, 3000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SKULL_CRACK:
                        DoCast(me->getVictim(), SPELL_SKULL_CRACK);
                        events.RescheduleEvent(EVENT_SKULL_CRACK, 3000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_myrmidon : public CreatureScript
{
public:
    npc_oathsworn_myrmidon() : CreatureScript("npc_oathsworn_myrmidon") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_myrmidonAI(creature);
    }

    struct npc_oathsworn_myrmidonAI : public ScriptedAI
    {
        npc_oathsworn_myrmidonAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_BLADED_SHIELD, 5000);
            events.ScheduleEvent(EVENT_RESISTANCE, 11000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BLADED_SHIELD:
                        DoCast(me->getVictim(), SPELL_BLADED_SHIELD);
                        events.RescheduleEvent(EVENT_BLADED_SHIELD, 5000);
                        return;
                    case EVENT_RESISTANCE:
                        DoCast(me->getVictim(), SPELL_SLAM);
                        events.RescheduleEvent(EVENT_RESISTANCE, 11000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_pathfinder : public CreatureScript
{
public:
    npc_oathsworn_pathfinder() : CreatureScript("npc_oathsworn_pathfinder") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_pathfinderAI(creature);
    }

    struct npc_oathsworn_pathfinderAI : public ScriptedAI
    {
        npc_oathsworn_pathfinderAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CALL_FALCON, 8000);
            events.ScheduleEvent(EVENT_SHOOT, 2000);
            events.ScheduleEvent(EVENT_WING_CLIP, 4000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CALL_FALCON:
                        DoCast(me->getVictim(), SPELL_CALL_FALCON);
                        events.RescheduleEvent(EVENT_CALL_FALCON, 8000);
                        return;
                    case EVENT_SHOOT:
                        DoCast(me->getVictim(), SPELL_SHOOT);
                        events.RescheduleEvent(EVENT_SHOOT, 1000);
                        return;
                    case EVENT_WING_CLIP:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_WING_CLIP);
                        events.RescheduleEvent(EVENT_WING_CLIP, 3000);
                        return;
                 }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_scorpid_keeper : public CreatureScript
{
public:
    npc_oathsworn_scorpid_keeper() : CreatureScript("npc_oathsworn_scorpid_keeper") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_scorpid_keeperAI(creature);
    }

    struct npc_oathsworn_scorpid_keeperAI : public ScriptedAI
    {
        npc_oathsworn_scorpid_keeperAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CALL_SCORPID, 8000);
            events.ScheduleEvent(EVENT_EVASION, 4000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CALL_SCORPID:
                        DoCast(me->getVictim(), SPELL_CALL_SCORPID);
                        events.RescheduleEvent(EVENT_CALL_SCORPID, 8000);
                        return;
                    case EVENT_EVASION:
                        DoCast(me->getVictim(), SPELL_EVASION);
                        events.RescheduleEvent(EVENT_EVASION, 5000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oathsworn_skinner : public CreatureScript
{
public:
    npc_oathsworn_skinner() : CreatureScript("npc_oathsworn_skinner") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oathsworn_skinnerAI(creature);
    }

    struct npc_oathsworn_skinnerAI : public ScriptedAI
    {
        npc_oathsworn_skinnerAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FAN_KNIVES, 5000);
            events.ScheduleEvent(EVENT_SPINAL_PIERCE, 7000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FAN_KNIVES:
                        DoCast(me->getVictim(), SPELL_FAN_KNIVES);
                        events.RescheduleEvent(EVENT_FAN_KNIVES, 3000);
                        return;
                    case EVENT_SPINAL_PIERCE:
                        DoCast(me->getVictim(), SPELL_SPINAL_PIERCE);
                        events.RescheduleEvent(EVENT_SPINAL_PIERCE, 7000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_pygmy_brute : public CreatureScript
{
public:
    npc_pygmy_brute() : CreatureScript("npc_pygmy_brute") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_pygmy_bruteAI(creature);
    }

    struct npc_pygmy_bruteAI : public ScriptedAI
    {
        npc_pygmy_bruteAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_IMPALE, 1000);
            events.ScheduleEvent(EVENT_SHOCKWAVE, 5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_IMPALE:
                        DoCast(me->getVictim(), SPELL_IMPALE);
                        events.RescheduleEvent(EVENT_IMPALE, 1000);
                        return;
                    case EVENT_SHOCKWAVE:
                        DoCast(me->getVictim(), SPELL_SHOCKWAVE);
                        events.RescheduleEvent(EVENT_SHOCKWAVE, 4000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_pygmy_firebreather : public CreatureScript
{
public:
    npc_pygmy_firebreather() : CreatureScript("npc_pygmy_firebreather") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_pygmy_firebreatherAI(creature);
    }

    struct npc_pygmy_firebreatherAI : public ScriptedAI
    {
        npc_pygmy_firebreatherAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_DRAGON_BREATH, 3000);
            events.ScheduleEvent(EVENT_FIRE_BLAST, 4000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SKULL_CRACK:
                        DoCast(me->getVictim(), SPELL_SKULL_CRACK);
                        events.RescheduleEvent(SPELL_DRAGON_BREATH, 3000);
                        return;
                    case EVENT_FIRE_BLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FIRE_BLAST);
                        events.RescheduleEvent(EVENT_FIRE_BLAST, 2000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_pygmy_scout : public CreatureScript
{
public:
    npc_pygmy_scout() : CreatureScript("npc_pygmy_scout") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_pygmy_scoutAI(creature);
    }

    struct npc_pygmy_scoutAI : public ScriptedAI
    {
        npc_pygmy_scoutAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_TOXIC_DART, 1000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TOXIC_DART:
                        DoCast(me->getVictim(), SPELL_TOXIC_DART);
                        events.RescheduleEvent(EVENT_TOXIC_DART, 1000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_lost_city_of_the_tolvir()
{
    new npc_neferset_darkcaster();
    new npc_neferset_plaguebringer();
    new npc_neferset_theurgist();
    new npc_neferset_torturer();
    new npc_oathsworn_axemaster();
    new npc_oathsworn_captain();
    new npc_oathsworn_myrmidon();
    new npc_oathsworn_pathfinder();
    new npc_oathsworn_scorpid_keeper();
    new npc_oathsworn_skinner();
    new npc_pygmy_brute();
    new npc_pygmy_firebreather();
    new npc_pygmy_scout();
}