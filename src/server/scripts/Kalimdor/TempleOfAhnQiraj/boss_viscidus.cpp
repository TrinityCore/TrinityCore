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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "temple_of_ahnqiraj.h"

enum Spells
{
    SPELL_POISON_SHOCK          = 25993,
    SPELL_POISONBOLT_VOLLEY     = 25991,
    SPELL_TOXIN                 = 26575,
    SPELL_VISCIDUS_SLOWED       = 26034,
    SPELL_VISCIDUS_SLOWED_MORE  = 26036,
    SPELL_VISCIDUS_FREEZE       = 25937,
    SPELL_REJOIN_VISCIDUS       = 25896,
    SPELL_VISCIDUS_EXPLODE      = 25938,
    SPELL_VISCIDUS_SUICIDE      = 26003,
    
    SPELL_MEMBRANE_VISCIDUS     = 25994,                   // damage reduction spell - removed from DBC
    SPELL_VISCIDUS_WEAKNESS     = 25926,                   // aura which procs at damage - should trigger the slow spells - removed from DBC
    SPELL_VISCIDUS_SHRINKS      = 25893,                   // (6) Apply Aura #61: Mod Scale Value: -4 - removed from DBC
    SPELL_VISCIDUS_GROWS        = 25897,                   // removed from DBC
    SPELL_SUMMON_GLOBS          = 25885,                   // summons npc 15667 using spells from 25865 to 25884; All spells have target coords - removed from DBC
    SPELL_VISCIDUS_TELEPORT     = 25904,                   // removed from DBC
};

enum Events
{ 
    EVENT_POISONBOLT_VOLLEY     = 1,
    EVENT_POISON_SHOCK          = 2,
    EVENT_RESET_PHASE           = 3
};

enum Phases
{
    PHASE_FROST                 = 1,
    PHASE_MELEE                 = 2,
    PHASE_GLOB                  = 3
};

enum HitCounter
{
    HITCOUNTER_SLOW             = 100, // "Viscidus begins to slow."
    HITCOUNTER_SLOW_MORE        = 150, // "Viscidus begins to freeze."
    HITCOUNTER_FREEZE           = 200, // "Viscidus is frozen solid."

    // 4.3.4 data
    HITCOUNTER_CRACK            = 50, // "Viscidus begins to crack."
    HITCOUNTER_SHATTER          = 100, // "Viscidus looks ready to shatter."
    HITCOUNTER_EXPLODE          = 150, // "Viscidus explodes."

    // 1.12 data
    // HITCOUNTER_EXPLODE          = 75
};

enum MovePoints
{
    ROOM_CENTER                 = 1
};

Position const ViscidusCoord = { -7992.36f, 908.19f, -52.62f, 1.68f }; // TODO: Visci ain't room middle
float const RoomRadius = 40.0f; // TODO: Not sure if its correct

class boss_viscidus : public CreatureScript
{
    public:
        boss_viscidus() : CreatureScript("boss_viscidus") { }

        struct boss_viscidusAI : public BossAI
        {
            boss_viscidusAI(Creature* creature) : BossAI(creature, DATA_VISCIDUS)
            {
                Reset();
            }

            uint8 Hitcounter;
            uint8 Phase;

            void Reset()
            {
                _Reset();
                Hitcounter = 0;
                Phase = PHASE_FROST;
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {                    
                if (Phase != PHASE_MELEE)
                    return;
                
                ++Hitcounter;
                
                if (attacker->HasUnitState(UNIT_STATE_MELEE_ATTACKING) && Hitcounter >= HITCOUNTER_EXPLODE)
                {
                    events.Reset();
                    Phase = PHASE_GLOB;
                    DoCast(me, SPELL_VISCIDUS_EXPLODE);
                    me->SetVisible(false);
                    me->RemoveAura(SPELL_TOXIN);
                    me->RemoveAura(SPELL_VISCIDUS_FREEZE);

                    uint8 NumGlobes = me->GetHealthPct() / 5;
                    for (uint8 i = 0; i < NumGlobes; ++i)
                    {
                        float Angle = i * 2 * PI / NumGlobes;
                        float X = ViscidusCoord.GetPositionX() + std::cos(Angle) * RoomRadius;
                        float Y = ViscidusCoord.GetPositionY() + std::sin(Angle) * RoomRadius;
                        float Z = -35;

                        TempSummon* Glob = me->SummonCreature(NPC_GLOB_OF_VISCIDUS, X, Y, Z);
                        Glob->UpdateAllowedPositionZ(X, Y, Z);
                        Glob->NearTeleportTo(X, Y, Z, 0);
                        Glob->GetMotionMaster()->MovePoint(ROOM_CENTER, ViscidusCoord);
                    }
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if ((spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST) && Phase == PHASE_FROST && me->GetHealthPct() > 5)
                {
                    ++Hitcounter;

                    if (Hitcounter >= HITCOUNTER_FREEZE)
                    {
                        Phase = PHASE_MELEE;
                        DoCast(me, SPELL_VISCIDUS_FREEZE);
                        me->RemoveAura(SPELL_VISCIDUS_SLOWED_MORE);
                        events.ScheduleEvent(EVENT_RESET_PHASE, 15000);
                    }
                    else if (Hitcounter >= HITCOUNTER_SLOW_MORE)
                    {
                        me->RemoveAura(SPELL_VISCIDUS_SLOWED);
                        DoCast(me, SPELL_VISCIDUS_SLOWED_MORE);
                    }
                    else if (Hitcounter >= HITCOUNTER_SLOW)
                        DoCast(me, SPELL_VISCIDUS_SLOWED);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.Reset();
                InitSpells();
            }
            
            void InitSpells()
            {
                DoCast(me, SPELL_TOXIN);
                events.ScheduleEvent(EVENT_POISONBOLT_VOLLEY, urand(10000, 15000));
                events.ScheduleEvent(EVENT_POISON_SHOCK, urand(7000, 12000));
            }

            void EnterEvadeMode()
            {
                summons.DespawnAll();
                ScriptedAI::EnterEvadeMode();
            }
            
            void JustDied(Unit* /*killer*/)
            {
                DoCast(me, SPELL_VISCIDUS_SUICIDE);
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                if (Phase == PHASE_GLOB && summons.empty())
                {
                    me->NearTeleportTo(ViscidusCoord.GetPositionX(),
                                       ViscidusCoord.GetPositionY(),
                                       ViscidusCoord.GetPositionZ(),
                                       ViscidusCoord.GetOrientation());
                    Hitcounter = 0;
                    Phase = PHASE_FROST;
                    InitSpells();
                    me->SetVisible(true);
                }
                
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_POISONBOLT_VOLLEY:
                        DoCast(me, SPELL_POISONBOLT_VOLLEY);
                        events.ScheduleEvent(EVENT_POISONBOLT_VOLLEY, urand(10000, 15000));
                        break;
                    case EVENT_POISON_SHOCK:
                        DoCast(me, SPELL_POISON_SHOCK);
                        events.ScheduleEvent(EVENT_POISON_SHOCK, urand(7000, 12000));
                        break;
                    case EVENT_RESET_PHASE:
                        Hitcounter = 0;
                        Phase = PHASE_FROST;
                        break;
                    default:
                        break;
                    }
                }

                if (Phase != PHASE_GLOB)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_viscidusAI (creature);
        }
};

class npc_glob_of_viscidus : public CreatureScript
{
    public:
        npc_glob_of_viscidus() : CreatureScript("boss_glob_of_viscidus") { }

        struct npc_glob_of_viscidusAI : public ScriptedAI
        {
            npc_glob_of_viscidusAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
                InstanceScript* Instance = me->GetInstanceScript();
                
                if (!Instance)
                    return;
                
                if (Creature* Viscidus = me->GetMap()->GetCreature(Instance->GetData64(DATA_VISCIDUS)))
                {
                    if (BossAI* ViscidusAI = dynamic_cast<BossAI*>(Viscidus->GetAI()))
                        ViscidusAI->SummonedCreatureDespawn(me);
                                        
                    if (Viscidus->isAlive() && Viscidus->GetHealthPct() < 5)
                    {
                        Viscidus->SetVisible(true);
                        Viscidus->getVictim()->Kill(Viscidus);
                    }
                    else
                    {
                        Viscidus->SetHealth(Viscidus->GetHealth() - Viscidus->GetMaxHealth() / 20);
                        Viscidus->SetObjectScale(Viscidus->GetFloatValue(OBJECT_FIELD_SCALE_X) - 0.05f); // TODO: Not sure if blizzlike
                    }
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id)
            {
                if (id == ROOM_CENTER)
                {
                    DoCast(me, SPELL_REJOIN_VISCIDUS);
                    ((TempSummon*)me)->UnSummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_glob_of_viscidusAI (creature);
        }
};

void AddSC_boss_viscidus()
{
    new boss_viscidus();
    new npc_glob_of_viscidus();
}
