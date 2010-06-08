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
#include "pit_of_saron.h"

/***************************************SPELLS*************************************/
// Ymirjar Wrathbringer
#define SPELL_BLIGHT                      DUNGEON_MODE(69603,70285)

//Ymirjar Skycaller
#define SPELL_FROSTBLADE                  70291
#define SPELL_GLACIAL_STRIKE              70292

//Ymirjar Flamebearer
#define SPELL_FIREBALL                    DUNGEON_MODE(69583,70282)
#define SPELL_HELLFIRE                    DUNGEON_MODE(69586,70283)
#define SPELL_TACTICAL_BLINK              69584

//Ymirjar Deathbringer
#define SPELL_EMPOWERED_SHADOW_BOLT       DUNGEON_MODE(69528,70281)
#define SPELL_SUMMON_UNDEAD               69516

//Wrathbone Laborer
#define SPELL_BLINDING_DIRT               70302
#define SPELL_PUNCTURE_WOUND              DUNGEON_MODE(70278,70279)
#define SPELL_SHOVELLED                   DUNGEON_MODE(69572,70280)

//Wrathbone Coldwraith
#define SPELL_FREEZING_CIRCLE             DUNGEON_MODE(69574,70276)
#define SPELL_FROSTBOLT                   DUNGEON_MODE(69573,70277)

//Stonespine Gargoyle
#define SPELL_GARGOYLE_STRIKE             DUNGEON_MODE(69520,70275)
#define SPELL_STONEFORM                   69575

// Plagueborn Horror
#define SPELL_BLIGHT_BOMB                 69582
#define SPELL_PUSTULANT_FLESH             DUNGEON_MODE(69581,70273)
#define SPELL_TOXIC_WASTE                 70274

//Iceborn Proto-Drake
#define SPELL_FROST_BREATH                DUNGEON_MODE(69527,70272)

//Hungering Ghoul
#define SPELL_DEVOUR_FLESH                70393

//Fallen Warrior
#define SPELL_ARCING_SLICE                69579
#define SPELL_DEMORALIZING_SHOUT          61044
#define SPELL_SHIELD_BLOCK                69580

//Deathwhisper Torturer
#define SPELL_BLACK_BRAND                 70392
#define SPELL_CURSE_OF_AGONY              70391

//Deathwhisper Shadowcaster
#define SPELL_SHADOW_BOLT                 DUNGEON_MODE(70386,70387)

//Deathwhisper Necrolyte
#define SPELL_CONVERSION_BEAM             DUNGEON_MODE(69578,70269)
#define SPELL_SHADOW_BOLT_2               DUNGEON_MODE(69577,70270)

//Wrathbone Sorcerer
#define SPELL_SHADOW_BOLT_3               DUNGEON_MODE(70386,70387)

//Geist Ambusher
#define SPELL_LEAPING_FACE_MAUL           DUNGEON_MODE(69504,70271)

/****************************************EVENTS************************************/
enum eEvents
{
    EVENT_NONE,

    // Ymirjar Wrathbringer
    EVENT_BLIGHT,

    // Ymirjar Skycaller
    EVENT_FROSTBLADE,
    EVENT_GLACIAL_STRIKE,

    // Ymirjar Flamebearer
    EVENT_FIREBALL,
    EVENT_HELLFIRE,
    EVENT_TACTICAL_BLINK,

    //Ymirjar Deathbringer
    EVENT_EMPOWERED_SHADOW_BOLT,
    EVENT_SUMMON_UNDEAD,

    //Wrathbone Laborer
    EVENT_BLINDING_DIRT,
    EVENT_PUNCTURE_WOUND,
    EVENT_SHOVELLED,

    //Wrathbone Coldwraith
    EVENT_FREEZING_CIRCLE,
    EVENT_FROSTBOLT,

    //Stonespine Gargoyle
    EVENT_GARGOYLE_STRIKE,
    EVENT_STONEFORM,

    //Plagueborn Horror
    EVENT_BLIGHT_BOMB,
    EVENT_PUSTULANT_FLESH,
    EVENT_TOXIC_WASTE,

    //Iceborn Proto-Drake
    EVENT_FROST_BREATH,

    //Hungering Ghoul
    EVENT_DEVOUR_FLESH,

    //Fallen Warrior
    EVENT_ARCING_SLICE,
    EVENT_DEMORALIZING_SHOUT,
    EVENT_SHIELD_BLOCK,

    //Deathwhisper Torturer
    EVENT_BLACK_BRAND,
    EVENT_CURSE_OF_AGONY,

    //Deathwhisper Shadowcaster
    EVENT_SHADOW_BOLT,

    //Deathwhisper Necrolyte
    EVENT_CONVERSION_BEAM,
    EVENT_SHADOW_BOLT_2,

    EVENT_SHADOW_BOLT_3,

    //Geist Ambusher
    EVENT_LEAPING_FACE_MAUL,
};

/****************************************AI****************************************/
struct mob_ymirjar_wrathbringerAI : public ScriptedAI
{
    mob_ymirjar_wrathbringerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_BLIGHT, 7000);
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
                case EVENT_BLIGHT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_BLIGHT);
                    events.RescheduleEvent(EVENT_BLIGHT, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_ymirjar_skyCallerAI: public ScriptedAI
{
    mob_ymirjar_skyCallerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_FROSTBLADE, 1);
        events.ScheduleEvent(EVENT_GLACIAL_STRIKE, 8000);
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
                case EVENT_GLACIAL_STRIKE:
                    DoCast(me->getVictim(), SPELL_GLACIAL_STRIKE);
                    events.RescheduleEvent(EVENT_GLACIAL_STRIKE, 8000);
                    return;
                case EVENT_FROSTBLADE:
                    DoCast(me, SPELL_FROSTBLADE);
                    events.CancelEvent(EVENT_FROSTBLADE);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_ymirjar_flamebearerAI: public ScriptedAI
{
    mob_ymirjar_flamebearerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_FIREBALL, 4000);
        events.ScheduleEvent(EVENT_HELLFIRE, 8000);
        events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15000);
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
                case EVENT_FIREBALL:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FIREBALL);
                    events.RescheduleEvent(EVENT_FIREBALL, 5000);
                    return;
                case EVENT_HELLFIRE:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_HELLFIRE);
                    events.RescheduleEvent(EVENT_HELLFIRE, 10000);
                    return;
                case EVENT_TACTICAL_BLINK:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_TACTICAL_BLINK);
                    events.RescheduleEvent(EVENT_TACTICAL_BLINK, 12000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_ymirjar_deathbringerAI: public ScriptedAI
{
    mob_ymirjar_deathbringerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_EMPOWERED_SHADOW_BOLT, 8000);
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
                case EVENT_EMPOWERED_SHADOW_BOLT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_EMPOWERED_SHADOW_BOLT);
                    events.RescheduleEvent(EVENT_EMPOWERED_SHADOW_BOLT, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_wrathbone_laborerAI: public ScriptedAI
{
    mob_wrathbone_laborerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_BLINDING_DIRT, 8000);
        events.ScheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
        events.ScheduleEvent(EVENT_SHOVELLED, 5000);
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
                case EVENT_BLINDING_DIRT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_BLINDING_DIRT);
                    events.RescheduleEvent(EVENT_BLINDING_DIRT, 10000);
                    return;
                case EVENT_PUNCTURE_WOUND:
                    DoCast(me->getVictim(), SPELL_PUNCTURE_WOUND);
                    events.RescheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
                    return;
                case EVENT_SHOVELLED:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHOVELLED);
                    events.RescheduleEvent(EVENT_SHOVELLED, 7000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_wrathbone_coldwraithAI: public ScriptedAI
{
    mob_wrathbone_coldwraithAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_FREEZING_CIRCLE, 9000);
        events.ScheduleEvent(EVENT_FROSTBOLT, 5000);
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
                case EVENT_FREEZING_CIRCLE:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FREEZING_CIRCLE);
                    events.RescheduleEvent(EVENT_FREEZING_CIRCLE, 9000);
                    return;
                case EVENT_FROSTBOLT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FROSTBOLT);
                    events.RescheduleEvent(EVENT_FROSTBOLT, 5000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_stonespine_gargoyleAI: public ScriptedAI
{
    mob_stonespine_gargoyleAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_GARGOYLE_STRIKE, 5000);
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
                case EVENT_GARGOYLE_STRIKE:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_GARGOYLE_STRIKE);
                    events.RescheduleEvent(EVENT_GARGOYLE_STRIKE, 6000);
                    return;
                case EVENT_STONEFORM:
                    if (HealthBelowPct(10))
                        DoCast(me, SPELL_STONEFORM);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_plagueborn_horrorAI: public ScriptedAI
{
    mob_plagueborn_horrorAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_BLIGHT_BOMB, 999999);
        events.ScheduleEvent(EVENT_PUSTULANT_FLESH, 5000);
        events.ScheduleEvent(EVENT_TOXIC_WASTE, 8000);
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
                case EVENT_BLIGHT_BOMB:
                    if (HealthBelowPct(15))
                        DoCast(me, SPELL_BLIGHT_BOMB);
                    return;
                case EVENT_PUSTULANT_FLESH:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_PUSTULANT_FLESH);
                    events.RescheduleEvent(EVENT_PUSTULANT_FLESH, 10000);
                    return;
                case EVENT_TOXIC_WASTE:
                    DoCast(me, SPELL_TOXIC_WASTE);
                    events.RescheduleEvent(EVENT_TOXIC_WASTE, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_iceborn_protodrakeAI: public ScriptedAI
{
    mob_iceborn_protodrakeAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_FROST_BREATH, 5000);
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
                case EVENT_FROST_BREATH:
                    DoCast(me->getVictim(), SPELL_FROST_BREATH);
                    events.RescheduleEvent(EVENT_FROST_BREATH, 10000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_hungering_ghoulAI: public ScriptedAI
{
    mob_hungering_ghoulAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_DEVOUR_FLESH, 4000);
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
                case EVENT_DEVOUR_FLESH:
                    DoCast(me->getVictim(), SPELL_DEVOUR_FLESH);
                    events.RescheduleEvent(EVENT_DEVOUR_FLESH, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_fallen_warriorAI: public ScriptedAI
{
    mob_fallen_warriorAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_ARCING_SLICE, 8000);
        events.ScheduleEvent(EVENT_DEMORALIZING_SHOUT, 20000);
        events.ScheduleEvent(EVENT_SHIELD_BLOCK, 8000);
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
                case EVENT_ARCING_SLICE:
                    DoCast(me->getVictim(), SPELL_ARCING_SLICE);
                    events.RescheduleEvent(EVENT_ARCING_SLICE, 10000);
                    return;
                case EVENT_DEMORALIZING_SHOUT:
                    DoCast(me, SPELL_DEMORALIZING_SHOUT);
                    events.RescheduleEvent(EVENT_DEMORALIZING_SHOUT, 20000);
                    return;
                case EVENT_SHIELD_BLOCK:
                    DoCast(me->getVictim(), SPELL_SHIELD_BLOCK);
                    events.RescheduleEvent(EVENT_SHIELD_BLOCK, 8000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_deathwhisper_torturerAI: public ScriptedAI
{
    mob_deathwhisper_torturerAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_BLACK_BRAND, 10000);
        events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 6000);
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
                case EVENT_BLACK_BRAND:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_BLACK_BRAND);
                    events.RescheduleEvent(EVENT_BLACK_BRAND, 10000);
                    return;
                case EVENT_CURSE_OF_AGONY:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_CURSE_OF_AGONY);
                    events.RescheduleEvent(EVENT_CURSE_OF_AGONY, 13000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_deathwhisper_shadowcasterAI: public ScriptedAI
{
    mob_deathwhisper_shadowcasterAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 3000);
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
                case EVENT_SHADOW_BOLT:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_BOLT);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT, 5000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_deathwhisper_necrolyteAI: public ScriptedAI
{
    mob_deathwhisper_necrolyteAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_CONVERSION_BEAM, 12000);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_2, 4000);
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
                case EVENT_CONVERSION_BEAM:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_CONVERSION_BEAM);
                    events.RescheduleEvent(EVENT_CONVERSION_BEAM, 12000);
                    return;
                case EVENT_SHADOW_BOLT_2:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_BOLT_2);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT_2, 5000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_wrathbone_sorcererAI: public ScriptedAI
{
    mob_wrathbone_sorcererAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(EVENT_SHADOW_BOLT_3, 3000);
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
                case EVENT_SHADOW_BOLT_3:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SHADOW_BOLT_3);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT_3, 5000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_geist_ambusherAI: public ScriptedAI
{
    mob_geist_ambusherAI(Creature *c) : ScriptedAI(c)
    {
    }

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        //Only here so when I figure out how to make it cast on an NPC i can do that.
        events.ScheduleEvent(EVENT_LEAPING_FACE_MAUL, 99999);
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
                //Should only be used on NPCs
                case EVENT_LEAPING_FACE_MAUL:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_LEAPING_FACE_MAUL);
                    events.CancelEvent(EVENT_LEAPING_FACE_MAUL);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_ymirjar_wrathbringerAI(Creature* pCreature)
{
    return new mob_ymirjar_wrathbringerAI(pCreature);
}

CreatureAI* GetAI_mob_ymirjar_skyCallerAI(Creature* pCreature)
{
    return new mob_ymirjar_skyCallerAI(pCreature);
}

CreatureAI* GetAI_mob_ymirjar_flamebearerAI(Creature* pCreature)
{
    return new mob_ymirjar_flamebearerAI(pCreature);
}

CreatureAI* GetAI_mob_ymirjar_deathbringerAI(Creature* pCreature)
{
    return new mob_ymirjar_deathbringerAI(pCreature);
}

CreatureAI* GetAI_mob_wrathbone_laborerAI(Creature* pCreature)
{
    return new mob_wrathbone_laborerAI(pCreature);
}

CreatureAI* GetAI_mob_wrathbone_coldwraithAI(Creature* pCreature)
{
    return new mob_wrathbone_coldwraithAI(pCreature);
}

CreatureAI* GetAI_mob_stonespine_gargoyleAI(Creature* pCreature)
{
    return new mob_stonespine_gargoyleAI(pCreature);
}

CreatureAI* GetAI_mob_plagueborn_horrorAI(Creature* pCreature)
{
    return new mob_plagueborn_horrorAI(pCreature);
}

CreatureAI* GetAI_mob_iceborn_protodrakeAI(Creature* pCreature)
{
    return new mob_iceborn_protodrakeAI(pCreature);
}

CreatureAI* GetAI_mob_hungering_ghoulAI(Creature* pCreature)
{
    return new mob_hungering_ghoulAI(pCreature);
}

CreatureAI* GetAI_mob_fallen_warriorAI(Creature* pCreature)
{
    return new mob_fallen_warriorAI(pCreature);
}

CreatureAI* GetAI_mob_deathwhisper_torturerAI(Creature* pCreature)
{
    return new mob_deathwhisper_torturerAI(pCreature);
}

CreatureAI* GetAI_mob_deathwhisper_shadowcasterAI(Creature* pCreature)
{
    return new mob_deathwhisper_shadowcasterAI(pCreature);
}

CreatureAI* GetAI_mob_deathwhisper_necrolyteAI(Creature* pCreature)
{
    return new mob_deathwhisper_necrolyteAI(pCreature);
}

CreatureAI* GetAI_mob_wrathbone_sorcererAI(Creature* pCreature)
{
    return new mob_wrathbone_sorcererAI(pCreature);
}

CreatureAI* GetAI_mob_geist_ambusherAI(Creature* pCreature)
{
    return new mob_geist_ambusherAI(pCreature);
}

void AddSC_pit_of_saron()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="mob_ymirjar_wrathbringer";
    newscript->GetAI = &GetAI_mob_ymirjar_wrathbringerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ymirjar_skycaller";
    newscript->GetAI = &GetAI_mob_ymirjar_skyCallerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ymirjar_flamebearer";
    newscript->GetAI = &GetAI_mob_ymirjar_flamebearerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ymirjar_deathbringer";
    newscript->GetAI = &GetAI_mob_ymirjar_deathbringerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_wrathbone_laborer";
    newscript->GetAI = &GetAI_mob_wrathbone_laborerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_wrathbone_coldwraith";
    newscript->GetAI = &GetAI_mob_wrathbone_coldwraithAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_stonespine_gargoyle";
    newscript->GetAI = &GetAI_mob_stonespine_gargoyleAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_plagueborn_horror";
    newscript->GetAI = &GetAI_mob_plagueborn_horrorAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_iceborn_protodrake";
    newscript->GetAI = &GetAI_mob_iceborn_protodrakeAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_hungering_ghoul";
    newscript->GetAI = &GetAI_mob_hungering_ghoulAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_fallen_warrior";
    newscript->GetAI = &GetAI_mob_fallen_warriorAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_deathwhisper_torturer";
    newscript->GetAI = &GetAI_mob_deathwhisper_torturerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_deathwhisper_shadowcaster";
    newscript->GetAI = &GetAI_mob_deathwhisper_shadowcasterAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_deathwhisper_necrolyte";
    newscript->GetAI = &GetAI_mob_deathwhisper_necrolyteAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_wrathbone_sorcerer";
    newscript->GetAI = &GetAI_mob_wrathbone_sorcererAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_geist_ambusher";
    newscript->GetAI = &GetAI_mob_geist_ambusherAI;
    newscript->RegisterSelf();
}
