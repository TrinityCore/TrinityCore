/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Terestian_Illhoof
SD%Complete: 95
SDComment: Complete! Needs adjustments to use spell though.
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "karazhan.h"
#include "PassiveAI.h"

enum TerestianIllhoof
{
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    SAY_AGGRO                   = 3,
    SAY_SACRIFICE               = 4,
    SAY_SUMMON                  = 5
};

enum Spells
{
    SPELL_SUMMON_DEMONCHAINS    = 30120,               // Summons demonic chains that maintain the ritual of sacrifice.
    SPELL_DEMON_CHAINS          = 30206,                   // Instant - Visual Effect
    SPELL_ENRAGE                = 23537,                   // Increases the caster's attack speed by 50% and the Physical damage it deals by 219 to 281 for 10 min.
    SPELL_SHADOW_BOLT           = 30055,                   // Hurls a bolt of dark magic at an enemy, inflicting Shadow damage.
    SPELL_SACRIFICE             = 30115,                   // Teleports and adds the debuff
    SPELL_BERSERK               = 32965,                   // Increases attack speed by 75%. Periodically casts Shadow Bolt Volley.
    SPELL_SUMMON_FIENDISIMP     = 30184,                   // Summons a Fiendish Imp.
    SPELL_SUMMON_IMP            = 30066,                   // Summons Kil'rek

    SPELL_FIENDISH_PORTAL       = 30171,                   // Opens portal and summons Fiendish Portal, 2 sec cast
    SPELL_FIENDISH_PORTAL_1     = 30179,                   // Opens portal and summons Fiendish Portal, instant cast

    SPELL_FIREBOLT              = 30050,                   // Blasts a target for 150 Fire damage.
    SPELL_BROKEN_PACT           = 30065,                   // All damage taken increased by 25%.
    SPELL_AMPLIFY_FLAMES        = 30053,                   // Increases the Fire damage taken by an enemy by 500 for 25 sec.
};

enum Creatures
{
    NPC_DEMONCHAINS             = 17248,
    NPC_FIENDISHIMP             = 17267,
    NPC_PORTAL                  = 17265,
    NPC_KILREK                  = 17229
};

class npc_kilrek : public CreatureScript
{
public:
    npc_kilrek() : CreatureScript("npc_kilrek") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_kilrekAI(creature);
    }

    struct npc_kilrekAI : public ScriptedAI
    {
        npc_kilrekAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint64 TerestianGUID;

        uint32 AmplifyTimer;

        void Reset() OVERRIDE
        {
            TerestianGUID = 0;
            AmplifyTimer = 2000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (!instance)
            {
                ERROR_INST_DATA(me);
                return;
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
            {
                uint64 TerestianGUID = instance->GetData64(DATA_TERESTIAN);
                if (TerestianGUID)
                {
                    Unit* Terestian = Unit::GetUnit(*me, TerestianGUID);
                    if (Terestian && Terestian->IsAlive())
                        DoCast(Terestian, SPELL_BROKEN_PACT, true);
                }
            } else ERROR_INST_DATA(me);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (AmplifyTimer <= diff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCastVictim(SPELL_AMPLIFY_FLAMES);

                AmplifyTimer = urand(10000, 20000);
            } else AmplifyTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_demon_chain : public CreatureScript
{
public:
    npc_demon_chain() : CreatureScript("npc_demon_chain") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_demon_chainAI(creature);
    }

    struct npc_demon_chainAI : public ScriptedAI
    {
        npc_demon_chainAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 SacrificeGUID;

        void Reset() OVERRIDE
        {
            SacrificeGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}
        void AttackStart(Unit* /*who*/) OVERRIDE {}
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (SacrificeGUID)
            {
                Unit* Sacrifice = Unit::GetUnit(*me, SacrificeGUID);
                if (Sacrifice)
                    Sacrifice->RemoveAurasDueToSpell(SPELL_SACRIFICE);
            }
        }
    };
};

class npc_fiendish_portal : public CreatureScript
{
public:
    npc_fiendish_portal() : CreatureScript("npc_fiendish_portal") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_fiendish_portalAI(creature);
    }

    struct npc_fiendish_portalAI : public PassiveAI
    {
        npc_fiendish_portalAI(Creature* creature) : PassiveAI(creature), summons(me){}

        SummonList summons;

        void Reset() OVERRIDE
        {
            DespawnAllImp();
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            summons.Summon(summon);
            DoZoneInCombat(summon);
        }

        void DespawnAllImp()
        {
            summons.DespawnAll();
        }
    };
};

class npc_fiendish_imp : public CreatureScript
{
public:
    npc_fiendish_imp() : CreatureScript("npc_fiendish_imp") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_fiendish_impAI(creature);
    }

    struct npc_fiendish_impAI : public ScriptedAI
    {
        npc_fiendish_impAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 FireboltTimer;

        void Reset() OVERRIDE
        {
            FireboltTimer = 2000;

            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (FireboltTimer <= diff)
            {
                DoCastVictim(SPELL_FIREBOLT);
                FireboltTimer = 2200;
            } else FireboltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_terestian_illhoof : public CreatureScript
{
public:
    boss_terestian_illhoof() : CreatureScript("boss_terestian_illhoof") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_terestianAI(creature);
    }

    struct boss_terestianAI : public ScriptedAI
    {
        boss_terestianAI(Creature* creature) : ScriptedAI(creature)
        {
            for (uint8 i = 0; i < 2; ++i)
                PortalGUID[i] = 0;
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint64 PortalGUID[2];
        uint8 PortalsCount;

        uint32 SacrificeTimer;
        uint32 ShadowboltTimer;
        uint32 SummonTimer;
        uint32 BerserkTimer;

        bool SummonedPortals;
        bool Berserk;

        void Reset() OVERRIDE
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (PortalGUID[i])
                {
                    if (Creature* pPortal = Unit::GetCreature(*me, PortalGUID[i]))
                    {
                        CAST_AI(npc_fiendish_portal::npc_fiendish_portalAI, pPortal->AI())->DespawnAllImp();
                        pPortal->DespawnOrUnsummon();
                    }

                    PortalGUID[i] = 0;
                }
            }

            PortalsCount        =     0;
            SacrificeTimer      = 30000;
            ShadowboltTimer     =  5000;
            SummonTimer         = 10000;
            BerserkTimer        = 600000;

            SummonedPortals     = false;
            Berserk             = false;

            if (instance)
                instance->SetData(TYPE_TERESTIAN, NOT_STARTED);

            me->RemoveAurasDueToSpell(SPELL_BROKEN_PACT);

            if (Minion* Kilrek = me->GetFirstMinion())
            {
                if (!Kilrek->IsAlive())
                {
                    Kilrek->UnSummon();
                    DoCast(me, SPELL_SUMMON_IMP, true);
                }
            }
            else DoCast(me, SPELL_SUMMON_IMP, true);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            if (summoned->GetEntry() == NPC_PORTAL)
            {
                PortalGUID[PortalsCount] = summoned->GetGUID();
                ++PortalsCount;

                if (summoned->GetUInt32Value(UNIT_CREATED_BY_SPELL) == SPELL_FIENDISH_PORTAL_1)
                {
                    Talk(SAY_SUMMON);
                    SummonedPortals = true;
                }
            }
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (PortalGUID[i])
                {
                    if (Creature* pPortal = Unit::GetCreature((*me), PortalGUID[i]))
                        pPortal->DespawnOrUnsummon();

                    PortalGUID[i] = 0;
                }
            }

            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(TYPE_TERESTIAN, DONE);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (SacrificeTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                if (target && target->IsAlive())
                {
                    DoCast(target, SPELL_SACRIFICE, true);
                    DoCast(target, SPELL_SUMMON_DEMONCHAINS, true);

                    if (Creature* Chains = me->FindNearestCreature(NPC_DEMONCHAINS, 5000))
                    {
                        CAST_AI(npc_demon_chain::npc_demon_chainAI, Chains->AI())->SacrificeGUID = target->GetGUID();
                        Chains->CastSpell(Chains, SPELL_DEMON_CHAINS, true);
                        Talk(SAY_SACRIFICE);
                        SacrificeTimer = 30000;
                    }
                }
            } else SacrificeTimer -= diff;

            if (ShadowboltTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO, 0), SPELL_SHADOW_BOLT);
                ShadowboltTimer = 10000;
            } else ShadowboltTimer -= diff;

            if (SummonTimer <= diff)
            {
                if (!PortalGUID[0])
                    DoCastVictim(SPELL_FIENDISH_PORTAL, false);

                if (!PortalGUID[1])
                    DoCastVictim(SPELL_FIENDISH_PORTAL_1, false);

                if (PortalGUID[0] && PortalGUID[1])
                {
                    if (Creature* pPortal = Unit::GetCreature(*me, PortalGUID[urand(0, 1)]))
                        pPortal->CastSpell(me->GetVictim(), SPELL_SUMMON_FIENDISIMP, false);
                    SummonTimer = 5000;
                }
            } else SummonTimer -= diff;

            if (!Berserk)
            {
                if (BerserkTimer <= diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    Berserk = true;
                } else BerserkTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_terestian_illhoof()
{
    new boss_terestian_illhoof();
    new npc_fiendish_imp();
    new npc_fiendish_portal();
    new npc_kilrek();
    new npc_demon_chain();
}
