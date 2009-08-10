/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "precompiled.h"
#include "def_ulduar.h"
#include "Vehicle.h"

#define SPELL_PURSUED           62374
#define SPELL_GATHERING_SPEED   62375
#define SPELL_BATTERING_RAM     62376
#define SPELL_FLAME_VENTS       62396
#define SPELL_MISSILE_BARRAGE   62400
#define SPELL_SYSTEMS_SHUTDOWN  62475

#define SPELL_CANNON            62397

#define SPELL_OVERLOAD_CIRCUIT  62399

#define SPELL_SEARING_FLAME     62402

enum Events
{
    EVENT_PURSUE = 1,
    EVENT_MISSILE,
    EVENT_VENT,
};

struct TRINITY_DLL_DECL boss_flame_leviathanAI : public BossAI
{
    boss_flame_leviathanAI(Creature *c) : BossAI(c, BOSS_LEVIATHAN)
    {
        assert(c->isVehicle());
    }

    uint32 FLAME_VENTS_Timer;
    uint32 BATTERING_RAM_Timer;
    uint32 GATHERING_SPEED_Timer;

    void Reset()
    {
        FLAME_VENTS_Timer = 10000;
        BATTERING_RAM_Timer = 0;
        GATHERING_SPEED_Timer = 0;
    }

    void MoveInLineOfSight(Unit* who) {}

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_PURSUE, 0);
        events.ScheduleEvent(EVENT_MISSILE, 1500);
        events.ScheduleEvent(EVENT_VENT, 20000);
        if(Creature *turret = CAST_CRE(CAST_VEH(me)->GetPassenger(7)))
            turret->AI()->DoZoneInCombat();
    }

    // TODO: effect 0 and effect 1 may be on different target
    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_PURSUED)
            AttackStart(target);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!me->isInCombat())
            return;

        if(me->getThreatManager().isThreatListEmpty())
        {
            EnterEvadeMode();
            return;
        }

        events.Update(diff);

        if( FLAME_VENTS_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FLAME_VENTS);
            FLAME_VENTS_Timer = 30000;
        } else FLAME_VENTS_Timer -= diff;

        if( BATTERING_RAM_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_BATTERING_RAM);
            BATTERING_RAM_Timer = 40000;
        } else BATTERING_RAM_Timer -= diff;

        if( GATHERING_SPEED_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_GATHERING_SPEED);
            GATHERING_SPEED_Timer = 50000;
        } else GATHERING_SPEED_Timer -= diff;

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        uint32 eventId = events.GetEvent();
        if(!me->getVictim())
            eventId = EVENT_PURSUE;

        switch(eventId)
        {
            case 0:
                return;
            case EVENT_PURSUE:
                DoCastAOE(SPELL_PURSUED);
                events.RepeatEvent(35000);
                return;
            case EVENT_MISSILE:
                //TODO: without unittarget no visual effect
                //DoCastAOE(SPELL_MISSILE_BARRAGE);
                DoCast(me->getVictim(), SPELL_MISSILE_BARRAGE);
                events.RepeatEvent(1500);
                return;
            case EVENT_VENT:
                DoCastAOE(SPELL_FLAME_VENTS);
                events.RepeatEvent(20000);
                return;
            default:
                events.PopEvent();
                break;
        }

        DoSpellAttackIfReady(SPELL_BATTERING_RAM);
    }
};


struct TRINITY_DLL_DECL boss_flame_leviathan_turretAI : public ScriptedAI
{
    boss_flame_leviathan_turretAI(Creature *c) : ScriptedAI(c)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset()
    {
        events.Reset();
    }

    EventMap events;

    void EnterCombat(Unit *who)
    {
        events.ScheduleEvent(1, 5000);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateCombatState())
            return;

        events.Update(diff);

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        if(uint32 eventId = events.GetEvent())
        {
            switch(eventId)
            {
                case 1:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_CANNON);
                    events.RepeatEvent(10000);
                    return;
                default:
                    events.PopEvent();
                    break;
            }
        }
    }
};


struct TRINITY_DLL_DECL boss_flame_leviathan_seatAI : public ScriptedAI
{
    boss_flame_leviathan_seatAI(Creature *c) : ScriptedAI(c)
    {
        assert(c->isVehicle());
        if(const CreatureInfo *cInfo = me->GetCreatureInfo())
            me->SetDisplayId(cInfo->DisplayID_A[0]); // 0 invisible, 1 visible
    }

    void Reset()
    {
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void MoveInLineOfSight(Unit *who) // for test
    {
        if(who->GetTypeId() == TYPEID_PLAYER && !who->m_Vehicle
            && !CAST_VEH(me)->GetPassenger(0) && CAST_VEH(me)->GetPassenger(2))
            who->EnterVehicle(CAST_VEH(me), 0);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!CAST_VEH(me)->GetPassenger(2))
            if(Unit *who = CAST_VEH(me)->GetPassenger(0))
                who->ExitVehicle();
    }
};

struct TRINITY_DLL_DECL boss_flame_leviathan_defense_turretAI : public ScriptedAI
{
    boss_flame_leviathan_defense_turretAI(Creature *c) : ScriptedAI(c)
    {
    }

    void Reset()
    {
    }

    void DamageTaken(Unit *who, uint32 &damage)
    {
        if(!who->m_Vehicle || who->m_Vehicle->GetEntry() != 33114)
            damage = 0;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if(me->getVictim())
            return;

        if(who->GetTypeId() != TYPEID_PLAYER || !who->m_Vehicle || who->m_Vehicle->GetEntry() != 33114)
            return;

        AttackStart(who);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        DoCast(me->getVictim(), SPELL_SEARING_FLAME);
    }
};

struct TRINITY_DLL_DECL boss_flame_leviathan_overload_deviceAI : public ScriptedAI
{
    boss_flame_leviathan_overload_deviceAI(Creature *c) : ScriptedAI(c)
    {
        if(const CreatureInfo *cInfo = me->GetCreatureInfo())
            me->SetDisplayId(cInfo->DisplayID_H[0]); // A0 gm, H0 device
    }

    void Reset()
    {
    }

    void DamageTaken(Unit *who, uint32 &damage)
    {
        if(damage >= me->GetHealth())
        {
            damage = 0;
            if(!me->hasUnitState(UNIT_STAT_CASTING))
                DoCastAOE(SPELL_OVERLOAD_CIRCUIT);
        }
    }
};

CreatureAI* GetAI_boss_flame_leviathan(Creature *_Creature)
{
    return new boss_flame_leviathanAI (_Creature);
}

CreatureAI* GetAI_boss_flame_leviathan_turret(Creature *_Creature)
{
    return new boss_flame_leviathan_turretAI (_Creature);
}

CreatureAI* GetAI_boss_flame_leviathan_seat(Creature *_Creature)
{
    return new boss_flame_leviathan_seatAI (_Creature);
}

CreatureAI* GetAI_boss_flame_leviathan_defense_turret(Creature *_Creature)
{
    return new boss_flame_leviathan_defense_turretAI (_Creature);
}

CreatureAI* GetAI_boss_flame_leviathan_overload_device(Creature *_Creature)
{
    return new boss_flame_leviathan_overload_deviceAI (_Creature);
}

void AddSC_boss_flame_leviathan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_flame_leviathan";
    newscript->GetAI = &GetAI_boss_flame_leviathan;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_flame_leviathan_turret";
    newscript->GetAI = &GetAI_boss_flame_leviathan_turret;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_flame_leviathan_seat";
    newscript->GetAI = &GetAI_boss_flame_leviathan_seat;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_flame_leviathan_defense_turret";
    newscript->GetAI = &GetAI_boss_flame_leviathan_defense_turret;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_flame_leviathan_overload_device";
    newscript->GetAI = &GetAI_boss_flame_leviathan_overload_device;
    newscript->RegisterSelf();
}
