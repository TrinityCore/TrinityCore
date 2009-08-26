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

#define SPELL_FLAME_CANNON      62395
//#define SPELL_FLAME_CANNON      64692 trigger the same spell

#define SPELL_OVERLOAD_CIRCUIT  62399

#define SPELL_SEARING_FLAME     62402

#define SPELL_BLAZE             62292

#define SPELL_SMOKE_TRAIL       63575

#define SPELL_MIMIRON_INFERNO   62910 // Not Blizzlike

#define SPELL_HODIR_FURY        62297 // Not Blizzlike

enum Mobs
{
    MOB_MECHANOLIFT = 33214,
    MOB_LIQUID      = 33189,
    MOB_CONTAINER   = 33218,
};

enum Events
{
    EVENT_PURSUE = 1,
    EVENT_MISSILE,
    EVENT_VENT,
    EVENT_MIMIRON_INFERNO, // Not Blizzlike
    EVENT_HODIR_FURY,      // Not Blizzlike
};

enum Seats
{
    SEAT_PLAYER = 0,
    SEAT_TURRET = 1,
    SEAT_DEVICE = 2,
};

struct TRINITY_DLL_DECL boss_flame_leviathanAI : public BossAI
{
    boss_flame_leviathanAI(Creature *c) : BossAI(c, BOSS_LEVIATHAN), vehicle(me->GetVehicleKit())
    {
        assert(vehicle);
    }

    Vehicle *vehicle;

    void Reset()
    {
        _Reset();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        me->SetReactState(REACT_DEFENSIVE);
        events.ScheduleEvent(EVENT_PURSUE, 0);
        events.ScheduleEvent(EVENT_MISSILE, 1500);
        events.ScheduleEvent(EVENT_VENT, 20000);
        events.ScheduleEvent(EVENT_MIMIRON_INFERNO, 60000 + (rand()%60000)); // Not Blizzlike
        events.ScheduleEvent(EVENT_HODIR_FURY, 60000 + (rand()%60000));      // Not Blizzlike
        if (Creature *turret = CAST_CRE(vehicle->GetPassenger(7)))
            turret->AI()->DoZoneInCombat();
    }

    // TODO: effect 0 and effect 1 may be on different target
    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_PURSUED)
            AttackStart(target);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if(spell->Id == 62472)
            vehicle->InstallAllAccessories();
    }

    void JustSummoned(Creature *summon)
    {
        if(summon->GetEntry() == MOB_MECHANOLIFT)
        {
            summons.Summon(summon);
        }
    }

    void SummonedCreatureDespawn(Creature *summon)
    {
        if(summon->GetEntry() == MOB_MECHANOLIFT)
        {
            summons.Despawn(summon);
            if(Creature* container = DoSummon(MOB_CONTAINER, summon, 0, 0))
                container->GetMotionMaster()->MovePoint(1, container->GetPositionX(), container->GetPositionY(), me->GetPositionZ());
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!me->isInCombat())
            return;

        if (me->getThreatManager().isThreatListEmpty()) // This is wrong, Flame Leviathan isn't even supposed to have a threat list, he just "switches to another Siege Engine/Demolisher every 30 seconds"
        {
            EnterEvadeMode();
            me->SetHealth(me->GetMaxHealth()); // EnterEvadeMode(); does not work against vehicles
            return;
        }

        if(summons.size() < 4)
            if(Creature *lift = DoSummonFlyer(MOB_MECHANOLIFT, me, 50, rand()%20 + 20, 0))
                lift->GetMotionMaster()->MoveRandom(100);

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        uint32 eventId = events.GetEvent();
        if (!me->getVictim())
            eventId = EVENT_PURSUE;

        switch(eventId)
        {
            case 0: break; // this is a must
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
            case EVENT_MIMIRON_INFERNO: // Not Blizzlike
                DoCast(me->getVictim(), SPELL_MIMIRON_INFERNO);
                events.RepeatEvent(60000 + (rand()%60000));
                return;
            case EVENT_HODIR_FURY:      // Not Blizzlike
                DoCast(me->getVictim(), SPELL_HODIR_FURY);
                events.RepeatEvent(60000 + (rand()%60000));
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

    void AttackStart(Unit *who)
    {
        if(who)
            me->Attack(who, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateCombatState())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        if (uint32 eventId = events.GetEvent())
        {
            switch(eventId)
            {
                case 1:
                    DoCast(me->getVictim(), SPELL_FLAME_CANNON);
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
                    events.RepeatEvent(3000);
                    return;
                default:
                    events.PopEvent();
                    break;
            }
        }
    }
};

//#define BOSS_DEBUG

struct TRINITY_DLL_DECL boss_flame_leviathan_seatAI : public PassiveAI
{
    boss_flame_leviathan_seatAI(Creature *c) : PassiveAI(c), vehicle(c->GetVehicleKit())
    {
        assert(vehicle);
#ifdef BOSS_DEBUG
        me->SetReactState(REACT_AGGRESSIVE);
#endif
    }

    Vehicle *vehicle;

#ifdef BOSS_DEBUG
    void MoveInLineOfSight(Unit *who)
    {
        if(who->GetTypeId() == TYPEID_PLAYER && CAST_PLR(who)->isGameMaster()
            && !who->GetVehicle() && vehicle->GetPassenger(SEAT_TURRET))
            who->EnterVehicle(vehicle, SEAT_PLAYER);
    }
#endif

    void PassengerBoarded(Unit *who, int8 seatId)
    {
        if(!me->GetVehicle())
            return;

        if(seatId == SEAT_PLAYER)
        {
            if(Creature *turret = CAST_CRE(vehicle->GetPassenger(SEAT_TURRET)))
            {
                turret->setFaction(me->GetVehicleBase()->getFaction());
                turret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                turret->AI()->AttackStart(who);
            }
            if(Unit *device = vehicle->GetPassenger(SEAT_DEVICE))
            {
                device->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                device->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
        }
    }

    void PassengerLeft(Unit *who, int8 seatId)
    {
        if(seatId == SEAT_TURRET)
        {
            if(Unit *device = vehicle->GetPassenger(SEAT_DEVICE))
            {
                device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                device->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
            }
        }
    }
};

struct TRINITY_DLL_DECL boss_flame_leviathan_defense_turretAI : public ScriptedAI
{
    boss_flame_leviathan_defense_turretAI(Creature *c) : ScriptedAI(c), timer(2000) {}

    uint32 timer;

    void DamageTaken(Unit *who, uint32 &damage)
    {
        if (!who->GetVehicle() || who->GetVehicleBase()->GetEntry() != 33114)
            damage = 0;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (me->getVictim())
            return;

        if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != 33114)
            return;

        AttackStart(who);
    }

    void AttackStart(Unit *who)
    {
        if(who)
            me->Attack(who, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        if(timer > diff)
            timer -= diff;
        else
        {
            timer = 2000;
            DoCast(me->getVictim(), SPELL_SEARING_FLAME);
        }
    }
};

struct TRINITY_DLL_DECL boss_flame_leviathan_overload_deviceAI : public PassiveAI
{
    boss_flame_leviathan_overload_deviceAI(Creature *c) : PassiveAI(c) {}

    void DoAction(const int32 param)
    {
        if(param == EVENT_SPELLCLICK)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            if(me->GetVehicle())
            {
                if(Unit *player = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                {
                    player->ExitVehicle();
                    me->GetVehicleBase()->CastSpell(player, SPELL_SMOKE_TRAIL, true);
                    if(Unit *leviathan = me->GetVehicleBase()->GetVehicleBase())
                        player->GetMotionMaster()->MoveKnockbackFrom(leviathan->GetPositionX(), leviathan->GetPositionY(), 30, 30);
                }
            }                    
        }
    }
};

struct TRINITY_DLL_DECL spell_pool_of_tarAI : public TriggerAI
{
    spell_pool_of_tarAI(Creature *c) : TriggerAI(c)
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void DamageTaken(Unit *who, uint32 &damage)
    {
        damage = 0;
    }

    void SpellHit(Unit* caster, const SpellEntry *spell)
    {
        if(spell->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
            me->CastSpell(me, SPELL_BLAZE, true);
    }
};

CreatureAI* GetAI_boss_flame_leviathan(Creature* pCreature)
{
    return new boss_flame_leviathanAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_turret(Creature* pCreature)
{
    return new boss_flame_leviathan_turretAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_seat(Creature* pCreature)
{
    return new boss_flame_leviathan_seatAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_defense_turret(Creature* pCreature)
{
    return new boss_flame_leviathan_defense_turretAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_overload_device(Creature* pCreature)
{
    return new boss_flame_leviathan_overload_deviceAI (pCreature);
}

CreatureAI* GetAI_spell_pool_of_tar(Creature* pCreature)
{
    return new spell_pool_of_tarAI (pCreature);
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

    newscript = new Script;
    newscript->Name="spell_pool_of_tar";
    newscript->GetAI = &GetAI_spell_pool_of_tar;
    newscript->RegisterSelf();
}
