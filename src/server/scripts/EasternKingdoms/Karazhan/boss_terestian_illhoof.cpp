/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_kilrekAI>(creature);
    }

    struct npc_kilrekAI : public ScriptedAI
    {
        npc_kilrekAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            AmplifyTimer = 2000;
        }

        InstanceScript* instance;

        uint32 AmplifyTimer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* /*killer*/) override
        {
            Creature* Terestian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TERESTIAN));
            if (Terestian && Terestian->IsAlive())
                DoCast(Terestian, SPELL_BROKEN_PACT, true);
        }

        void UpdateAI(uint32 diff) override
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_demon_chainAI(creature);
    }

    struct npc_demon_chainAI : public ScriptedAI
    {
        npc_demon_chainAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            SacrificeGUID.Clear();
        }

        ObjectGuid SacrificeGUID;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }
        void AttackStart(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void JustDied(Unit* /*killer*/) override
        {
            if (SacrificeGUID)
            {
                Unit* Sacrifice = ObjectAccessor::GetUnit(*me, SacrificeGUID);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fiendish_portalAI(creature);
    }

    struct npc_fiendish_portalAI : public PassiveAI
    {
        npc_fiendish_portalAI(Creature* creature) : PassiveAI(creature), summons(me){ }

        SummonList summons;

        void Reset() override
        {
            DespawnAllImp();
        }

        void JustSummoned(Creature* summon) override
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fiendish_impAI(creature);
    }

    struct npc_fiendish_impAI : public ScriptedAI
    {
        npc_fiendish_impAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FireboltTimer = 2000;
        }

        uint32 FireboltTimer;

        void Reset() override
        {
            Initialize();

            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_terestianAI>(creature);
    }

    struct boss_terestianAI : public ScriptedAI
    {
        boss_terestianAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
            PortalsCount = 0;
            SacrificeTimer = 30000;
            ShadowboltTimer = 5000;
            SummonTimer = 10000;
            BerserkTimer = 600000;

            SummonedPortals = false;
            Berserk = false;
        }

        InstanceScript* instance;

        ObjectGuid PortalGUID[2];
        uint8 PortalsCount;

        uint32 SacrificeTimer;
        uint32 ShadowboltTimer;
        uint32 SummonTimer;
        uint32 BerserkTimer;

        bool SummonedPortals;
        bool Berserk;

        void Reset() override
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (PortalGUID[i])
                {
                    if (Creature* pPortal = ObjectAccessor::GetCreature(*me, PortalGUID[i]))
                    {
                        ENSURE_AI(npc_fiendish_portal::npc_fiendish_portalAI, pPortal->AI())->DespawnAllImp();
                        pPortal->DespawnOrUnsummon();
                    }

                    PortalGUID[i].Clear();
                }
            }

            Initialize();

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

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
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

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (PortalGUID[i])
                {
                    if (Creature* pPortal = ObjectAccessor::GetCreature((*me), PortalGUID[i]))
                        pPortal->DespawnOrUnsummon();

                    PortalGUID[i].Clear();
                }
            }

            Talk(SAY_DEATH);

            instance->SetData(TYPE_TERESTIAN, DONE);
        }

        void UpdateAI(uint32 diff) override
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
                        ENSURE_AI(npc_demon_chain::npc_demon_chainAI, Chains->AI())->SacrificeGUID = target->GetGUID();
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
                    if (Creature* pPortal = ObjectAccessor::GetCreature(*me, PortalGUID[urand(0, 1)]))
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
