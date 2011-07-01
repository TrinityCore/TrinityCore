/*
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

/* ScriptData
SDName: Boss_Muru
SD%Complete: 80
SDComment: all sounds, black hole effect triggers to often (46228)
*/

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

// Muru & Entropius's spells
enum Spells
{
    SPELL_ENRAGE                = 26662,

    // Muru's spells
    SPELL_NEGATIVE_ENERGY        = 46009, //(this trigger 46008)
    SPELL_DARKNESS                = 45999,
    SPELL_OPEN_ALL_PORTALS        = 46177,
    SPELL_OPEN_PORTAL            = 45977,
    SPELL_OPEN_PORTAL_2            = 45976,
    SPELL_SUMMON_BERSERKER        = 46037,
    SPELL_SUMNON_FURY_MAGE        = 46038,
    SPELL_SUMMON_VOID_SENTINEL    = 45988,
    SPELL_SUMMON_ENTROPIUS        = 46217,

    // Entropius's spells
    SPELL_DARKNESS_E            = 46269,
    SPELL_BLACKHOLE             = 46282,
    SPELL_NEGATIVE_ENERGY_E     = 46284,
    SPELL_ENTROPIUS_SPAWN        = 46223,

    // Shadowsword Berserker's spells
    SPELL_FLURRY                = 46160,
    SPELL_DUAL_WIELD            = 29651,

    // Shadowsword Fury Mage's spells
    SPELL_FEL_FIREBALL          = 46101,
    SPELL_SPELL_FURY            = 46102,

    // Void Sentinel's spells
    SPELL_SHADOW_PULSE          = 46087,
    SPELL_VOID_BLAST            = 46161,

    // Void Spawn's spells
    SPELL_SHADOW_BOLT_VOLLEY    = 46082,

    //Dark Fiend Spells
    SPELL_DARKFIEND_AOE            = 45944,
    SPELL_DARKFIEND_VISUAL        = 45936,
    SPELL_DARKFIEND_SKIN        = 45934,

    //Black Hole Spells
    SPELL_BLACKHOLE_SPAWN        = 46242,
    SPELL_BLACKHOLE_GROW        = 46228
};

enum BossTimers{
    TIMER_DARKNESS                = 0,
    TIMER_HUMANOIDES            = 1,
    TIMER_PHASE                    = 2,
    TIMER_SENTINEL                = 3
};

float DarkFiends[8][4] =
{
    {1819.9f,    609.80f,    69.74f,    1.94f},
    {1829.39f,   617.89f,    69.73f,    2.61f},
    {1801.98f,   633.62f,    69.74f,    5.71f},
    {1830.88f,   629.99f,    69.73f,    3.52f},
    {1800.38f,   621.41f,    69.74f,    0.22f},
    {1808.3f ,   612.45f,    69.73f,    1.02f},
    {1823.9f ,   639.69f,    69.74f,    4.12f},
    {1811.85f,   640.46f,    69.73f,    4.97f}
};

float Humanoides[6][5] =
{
    {CREATURE_FURY_MAGE, 1780.16f,    666.83f,    71.19f,    5.21f},
    {CREATURE_FURY_MAGE, 1847.93f,    600.30f,    71.30f,    2.57f},
    {CREATURE_BERSERKER, 1779.97f,    660.64f,    71.19f,    5.28f},
    {CREATURE_BERSERKER, 1786.2f ,    661.01f,    71.19f,    4.51f},
    {CREATURE_BERSERKER, 1845.17f,    602.63f,    71.28f,    2.43f},
    {CREATURE_BERSERKER, 1842.91f,    599.93f,    71.23f,    2.44f}
};

uint32 EnrageTimer = 600000;
class boss_entropius : public CreatureScript
{
public:
    boss_entropius() : CreatureScript("boss_entropius") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_entropiusAI (pCreature);
    }

    struct boss_entropiusAI : public ScriptedAI
    {
        boss_entropiusAI(Creature* c) : ScriptedAI(c), Summons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        SummonList Summons;

        uint32 BlackHoleSummonTimer;

        void Reset()
        {
            BlackHoleSummonTimer = 15000;
            DoCastAOE(SPELL_NEGATIVE_ENERGY_E, false);

            Summons.DespawnAll();

            if (pInstance)
                pInstance->SetData(DATA_MURU_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCastAOE(SPELL_NEGATIVE_ENERGY_E, true);
            DoCast(me, SPELL_ENTROPIUS_SPAWN, false);

            if (pInstance)
                pInstance->SetData(DATA_MURU_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summoned)
        {
            switch(summoned->GetEntry())
            {
                case CREATURE_DARK_FIENDS:
                    summoned->CastSpell(summoned, SPELL_DARKFIEND_VISUAL, false);
                    break;
                case CREATURE_DARKNESS:
                    summoned->AddUnitState(UNIT_STAT_STUNNED);
                    float x, y, z, o;
                    summoned->GetHomePosition(x, y, z, o);
                    me->SummonCreature(CREATURE_DARK_FIENDS, x, y, z, o, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            }
            summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true));
            Summons.Summon(summoned);
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();

            if (pInstance)
                pInstance->SetData(DATA_MURU_EVENT, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (EnrageTimer < diff && !me->HasAura(SPELL_ENRAGE, 0))
            {
                DoCast(me, SPELL_ENRAGE, false);
            } else EnrageTimer -= diff;

            if (BlackHoleSummonTimer <= diff)
            {
                Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (!random)
                    return;

                DoCast(random, SPELL_DARKNESS_E, false);

                random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (!random)
                    return;

                random->CastSpell(random, SPELL_BLACKHOLE, false);
                BlackHoleSummonTimer = 15000;
            } else BlackHoleSummonTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_muru : public CreatureScript
{
public:
    boss_muru() : CreatureScript("boss_muru") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_muruAI (pCreature);
    }

    struct boss_muruAI : public Scripted_NoMovementAI
    {
        boss_muruAI(Creature* c) : Scripted_NoMovementAI(c), Summons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        SummonList Summons;

        uint8 Phase;
        uint32 Timer[4];

        bool DarkFiend;

        void Reset()
        {
            DarkFiend = false;
            Phase = 1;

            EnrageTimer = 600000;
            Timer[TIMER_DARKNESS] = 45000;
            Timer[TIMER_HUMANOIDES] = 10000;
            Timer[TIMER_PHASE] = 2000;
            Timer[TIMER_SENTINEL] = 31500;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetVisible(true);

            Summons.DespawnAll();

            if (pInstance)
                pInstance->SetData(DATA_MURU_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCastAOE(SPELL_NEGATIVE_ENERGY, false);

            if (pInstance)
                pInstance->SetData(DATA_MURU_EVENT, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage > me->GetHealth() && Phase == 1)
            {
                damage = 0;
                Phase = 2;
                me->RemoveAllAuras();
                DoCast(me, SPELL_OPEN_ALL_PORTALS, false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
            if (Phase > 1 && Phase < 4)
                damage = 0;
        }

        void JustSummoned(Creature* summoned)
        {
            switch(summoned->GetEntry())
            {
                case BOSS_ENTROPIUS:
                    me->SetVisible(false);
                    break;
                case CREATURE_DARK_FIENDS:
                    summoned->CastSpell(summoned, SPELL_DARKFIEND_VISUAL, false);
                    break;
            }
            summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true));
            Summons.Summon(summoned);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Phase == 3)
            {
                if (Timer[TIMER_PHASE] <= diff)
                {
                    if (!pInstance)
                        return;
                    switch(pInstance->GetData(DATA_MURU_EVENT))
                    {
                        case NOT_STARTED:
                            Reset();
                            break;
                        case DONE:
                            Phase = 4;
                            me->DisappearAndDie();
                            break;
                    }
                    Timer[TIMER_PHASE] = 3000;
                } else Timer[TIMER_PHASE] -= diff;
                return;
            }

            if (EnrageTimer < diff && !me->HasAura(SPELL_ENRAGE, 0))
            {
                DoCast(me, SPELL_ENRAGE, false);
            } else EnrageTimer -= diff;

            for (uint8 i = 0; i < 4; ++i)
            {
                if (Timer[i] <= diff)
                {
                    switch(i)
                    {
                        case TIMER_DARKNESS:
                            if (!DarkFiend)
                            {
                                DoCastAOE(SPELL_DARKNESS, false);
                                Timer[TIMER_DARKNESS] = 3000;
                                DarkFiend = true;
                            }
                            else
                            {
                                DarkFiend = false;
                                for (uint8 i = 0; i < 8; ++i)
                                    me->SummonCreature(CREATURE_DARK_FIENDS, DarkFiends[i][0], DarkFiends[i][1], DarkFiends[i][2], DarkFiends[i][3], TEMPSUMMON_CORPSE_DESPAWN, 0);
                                Timer[TIMER_DARKNESS] = 42000;
                            }
                            break;
                        case TIMER_HUMANOIDES:
                            for (uint8 i = 0; i < 6; ++i)
                                me->SummonCreature(uint32(Humanoides[i][0]), Humanoides[i][1], Humanoides[i][2], Humanoides[i][3], Humanoides[i][4], TEMPSUMMON_CORPSE_DESPAWN, 0);
                            Timer[TIMER_HUMANOIDES] = 60000;
                            break;
                        case TIMER_PHASE:
                            me->RemoveAllAuras();
                            DoCast(me, SPELL_SUMMON_ENTROPIUS, false);
                            Timer[TIMER_PHASE] = 3000;
                            Phase = 3;
                            return;
                        case TIMER_SENTINEL:
                            DoCastAOE(SPELL_OPEN_PORTAL_2, false);
                            Timer[TIMER_SENTINEL] = 30000;
                            break;
                    }
                    break;
                }
            }

            //Timer
            for (uint8 i = 0; i < 4; ++i)
            {
                if (i != TIMER_PHASE)Timer[i] -= diff;
                else if (Phase == 2) Timer[i] -= diff;
            }
        }
    };

};

class npc_muru_portal : public CreatureScript
{
public:
    npc_muru_portal() : CreatureScript("npc_muru_portal") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_muru_portalAI (pCreature);
    }

    struct npc_muru_portalAI : public Scripted_NoMovementAI
    {
        npc_muru_portalAI(Creature* c) : Scripted_NoMovementAI(c), Summons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        SummonList Summons;

        bool SummonSentinel;
        bool InAction;

        uint32 SummonTimer;

        void Reset()
        {
            SummonTimer = 5000;

            InAction = false;
            SummonSentinel = false;

            me->AddUnitState(UNIT_STAT_STUNNED);

            Summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned)
        {
            if (pInstance)
                if (Player* Target = Unit::GetPlayer(*me, pInstance->GetData64(DATA_PLAYER_GUID)))
                    summoned->AI()->AttackStart(Target);

            Summons.Summon(summoned);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry* Spell)
        {
            float x, y, z, o;
            me->GetHomePosition(x, y, z, o);
            DoTeleportTo(x, y, z);
            InAction = true;
            switch(Spell->Id)
            {
                case SPELL_OPEN_ALL_PORTALS:
                    DoCastAOE(SPELL_OPEN_PORTAL, false);
                    break;
                case SPELL_OPEN_PORTAL_2:
                    DoCastAOE(SPELL_OPEN_PORTAL, false);
                    SummonSentinel = true;
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!SummonSentinel)
            {
                if (InAction && pInstance && pInstance->GetData(DATA_MURU_EVENT) == NOT_STARTED)
                    Reset();
                return;
            }
            if (SummonTimer <= diff)
            {
                DoCastAOE(SPELL_SUMMON_VOID_SENTINEL, false);
                SummonTimer = 5000;
                SummonSentinel = false;
            } else SummonTimer -= diff;
        }
    };

};

class npc_dark_fiend : public CreatureScript
{
public:
    npc_dark_fiend() : CreatureScript("npc_dark_fiend") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dark_fiendAI (pCreature);
    }

    struct npc_dark_fiendAI : public ScriptedAI
    {
        npc_dark_fiendAI(Creature* c) : ScriptedAI(c) {}

        uint32 WaitTimer;
        bool InAction;

        void Reset()
        {
            WaitTimer = 2000;
            InAction = false;

            me->AddUnitState(UNIT_STAT_STUNNED);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry* Spell)
        {
            for (uint8 i = 0; i < 3; ++i)
                if (Spell->Effect[i] == 38)
                    me->DisappearAndDie();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (WaitTimer <= diff)
            {
                if (!InAction)
                {
                    me->ClearUnitState(UNIT_STAT_STUNNED);
                    DoCastAOE(SPELL_DARKFIEND_SKIN, false);
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true));
                    InAction = true;
                    WaitTimer = 500;
                }
                else
                {

                    if (me->IsWithinDist(me->getVictim(), 5))
                    {
                        DoCastAOE(SPELL_DARKFIEND_AOE, false);
                        me->DisappearAndDie();
                    }
                    WaitTimer = 500;
                }
            } else WaitTimer -= diff;
        }
    };

};

class npc_void_sentinel : public CreatureScript
{
public:
    npc_void_sentinel() : CreatureScript("npc_void_sentinel") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_void_sentinelAI (pCreature);
    }

    struct npc_void_sentinelAI : public ScriptedAI
    {
        npc_void_sentinelAI(Creature* c) : ScriptedAI(c){}

        uint32 PulseTimer;
        uint32 VoidBlastTimer;

        void Reset()
        {
            PulseTimer = 3000;
            VoidBlastTimer = 45000; //is this a correct timer?

            float x, y, z, o;
            me->GetHomePosition(x, y, z, o);
            DoTeleportTo(x, y, 71);
        }

        void JustDied(Unit* /*killer*/)
        {
            for (uint8 i = 0; i < 8; ++i)
                me->SummonCreature(CREATURE_VOID_SPAWN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), float(rand()%6), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (PulseTimer <= diff)
            {
                DoCastAOE(SPELL_SHADOW_PULSE, true);
                PulseTimer = 3000;
            } else PulseTimer -= diff;

            if (VoidBlastTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_VOID_BLAST, false);
                VoidBlastTimer = 45000;
            } else VoidBlastTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_blackhole : public CreatureScript
{
public:
    npc_blackhole() : CreatureScript("npc_blackhole") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_blackholeAI (pCreature);
    }

    struct npc_blackholeAI : public ScriptedAI
    {
        npc_blackholeAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 DespawnTimer;
        uint32 SpellTimer;
        uint8 Phase;
        uint8 NeedForAHack;

        void Reset()
        {
            DespawnTimer = 15000;
            SpellTimer = 5000;
            Phase = 0;

            me->AddUnitState(UNIT_STAT_STUNNED);
            DoCastAOE(SPELL_BLACKHOLE_SPAWN, true);
        }

        void UpdateAI(const uint32 diff)
        {
            if (SpellTimer <= diff)
            {
                Unit* Victim = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_PLAYER_GUID) : 0);
                switch (NeedForAHack)
                {
                    case 0:
                        me->ClearUnitState(UNIT_STAT_STUNNED);
                        DoCastAOE(SPELL_BLACKHOLE_GROW, false);
                        if (Victim)
                            AttackStart(Victim);
                        SpellTimer = 700;
                        NeedForAHack = 2;
                        break;
                    case 1:
                        me->AddAura(SPELL_BLACKHOLE_GROW, me);
                        NeedForAHack = 2;
                        SpellTimer = 600;
                        break;
                    case 2:
                        SpellTimer = 400;
                        NeedForAHack = 3;
                        me->RemoveAura(SPELL_BLACKHOLE_GROW, 1);
                        break;
                    case 3:
                        SpellTimer = urand(400, 900);
                        NeedForAHack = 1;
                        if (Unit* Temp = me->getVictim())
                        {
                            if (Temp->GetPositionZ() > 73 && Victim)
                                AttackStart(Victim);
                        } else
                            return;
                }
            } else SpellTimer -= diff;

            if (DespawnTimer <= diff)
                me->DisappearAndDie();
            else DespawnTimer -= diff;
        }
    };

};

void AddSC_boss_muru()
{
    new boss_muru();
    new boss_entropius();
    new npc_muru_portal();
    new npc_dark_fiend();
    new npc_void_sentinel();
    new npc_blackhole();
}
