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
SDName: Boss_High_King_Maulgar
SD%Complete: 90
SDComment: Correct timers, after whirlwind melee attack bug, prayer of healing
SDCategory: Gruul's Lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "gruuls_lair.h"

enum HighKingMaulgar
{
    SAY_AGGRO                   = 0,
    SAY_ENRAGE                  = 1,
    SAY_OGRE_DEATH              = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,

    // High King Maulgar
    SPELL_ARCING_SMASH          = 39144,
    SPELL_MIGHTY_BLOW           = 33230,
    SPELL_WHIRLWIND             = 33238,
    SPELL_BERSERKER_C           = 26561,
    SPELL_ROAR                  = 16508,
    SPELL_FLURRY                = 33232,
    SPELL_DUAL_WIELD            = 29651,

    // Olm the Summoner
    SPELL_DARK_DECAY            = 33129,
    SPELL_DEATH_COIL            = 33130,
    SPELL_SUMMON_WFH            = 33131,

    //Kiggler the Craed
    SPELL_GREATER_POLYMORPH     = 33173,
    SPELL_LIGHTNING_BOLT        = 36152,
    SPELL_ARCANE_SHOCK          = 33175,
    SPELL_ARCANE_EXPLOSION      = 33237,

    //Blindeye the Seer
    SPELL_GREATER_PW_SHIELD     = 33147,
    SPELL_HEAL                  = 33144,
    SPELL_PRAYER_OH             = 33152,

    //Krosh Firehand
    SPELL_GREATER_FIREBALL      = 33051,
    SPELL_SPELLSHIELD           = 33054,
    SPELL_BLAST_WAVE            = 33061
};

bool CheckAllBossDied(InstanceScript* instance, Creature* me)
{
    if (!instance || !me)
        return false;

    uint64 MaulgarGUID = 0;
    uint64 KigglerGUID = 0;
    uint64 BlindeyeGUID = 0;
    uint64 OlmGUID = 0;
    uint64 KroshGUID = 0;

    Creature* Maulgar = NULL;
    Creature* Kiggler = NULL;
    Creature* Blindeye = NULL;
    Creature* Olm = NULL;
    Creature* Krosh = NULL;

    MaulgarGUID = instance->GetData64(DATA_MAULGAR);
    KigglerGUID = instance->GetData64(DATA_KIGGLERTHECRAZED);
    BlindeyeGUID = instance->GetData64(DATA_BLINDEYETHESEER);
    OlmGUID = instance->GetData64(DATA_OLMTHESUMMONER);
    KroshGUID = instance->GetData64(DATA_KROSHFIREHAND);

    Maulgar = (Unit::GetCreature((*me), MaulgarGUID));
    Kiggler = (Unit::GetCreature((*me), KigglerGUID));
    Blindeye = (Unit::GetCreature((*me), BlindeyeGUID));
    Olm = (Unit::GetCreature((*me), OlmGUID));
    Krosh = (Unit::GetCreature((*me), KroshGUID));

    if (!Maulgar || !Kiggler || !Blindeye || !Olm || !Krosh)
        return false;

    if (!Maulgar->IsAlive() && !Kiggler->IsAlive() && !Blindeye->IsAlive() && !Olm->IsAlive() && !Krosh->IsAlive())
        return true;

    return false;
}

//High King Maulgar AI
class boss_high_king_maulgar : public CreatureScript
{
public:
    boss_high_king_maulgar() : CreatureScript("boss_high_king_maulgar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_high_king_maulgarAI (creature);
    }

    struct boss_high_king_maulgarAI : public ScriptedAI
    {
        boss_high_king_maulgarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            for (uint8 i = 0; i < 4; ++i)
                Council[i] = 0;
        }

        InstanceScript* instance;

        uint32 ArcingSmash_Timer;
        uint32 MightyBlow_Timer;
        uint32 Whirlwind_Timer;
        uint32 Charging_Timer;
        uint32 Roar_Timer;

        bool Phase2;

        uint64 Council[4];

        void Reset()
        {
            ArcingSmash_Timer = 10000;
            MightyBlow_Timer = 40000;
            Whirlwind_Timer = 30000;
            Charging_Timer = 0;
            Roar_Timer = 0;

            DoCast(me, SPELL_DUAL_WIELD, false);

            Phase2 = false;

            Creature* creature = NULL;
            for (uint8 i = 0; i < 4; ++i)
            {
                if (Council[i])
                {
                    creature = (Unit::GetCreature((*me), Council[i]));
                    if (creature && !creature->IsAlive())
                    {
                        creature->Respawn();
                        creature->AI()->EnterEvadeMode();
                    }
                }
            }

            //reset encounter
            if (instance)
                instance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (CheckAllBossDied(instance, me))
                instance->SetData(DATA_MAULGAREVENT, DONE);
        }

           void AddDeath()
           {
                Talk(SAY_OGRE_DEATH);
           }

        void EnterCombat(Unit* who)
        {
            StartEvent(who);
        }

        void GetCouncil()
        {
            if (instance)
            {
                //get council member's guid to respawn them if needed
                Council[0] = instance->GetData64(DATA_KIGGLERTHECRAZED);
                Council[1] = instance->GetData64(DATA_BLINDEYETHESEER);
                Council[2] = instance->GetData64(DATA_OLMTHESUMMONER);
                Council[3] = instance->GetData64(DATA_KROSHFIREHAND);
            }
        }

        void StartEvent(Unit* who)
        {
            if (!instance)
                return;

            GetCouncil();

            Talk(SAY_AGGRO);

            instance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            instance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);

            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->IsInCombat() && instance && instance->GetData(DATA_MAULGAREVENT))
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_MAULGAREVENT_TANK));

                if (target)
                {
                    AttackStart(target);
                    GetCouncil();
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (instance && !instance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //ArcingSmash_Timer
            if (ArcingSmash_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_ARCING_SMASH);
                ArcingSmash_Timer = 10000;
            } else ArcingSmash_Timer -= diff;

            //Whirlwind_Timer
                   if (Whirlwind_Timer <= diff)
                   {
                        DoCast(me->GetVictim(), SPELL_WHIRLWIND);
                        Whirlwind_Timer = 55000;
                   } else Whirlwind_Timer -= diff;

            //MightyBlow_Timer
            if (MightyBlow_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_MIGHTY_BLOW);
                MightyBlow_Timer = 30000+rand()%10000;
            } else MightyBlow_Timer -= diff;

            //Entering Phase 2
            if (!Phase2 && HealthBelowPct(50))
            {
                Phase2 = true;
                Talk(SAY_ENRAGE);

                DoCast(me, SPELL_DUAL_WIELD, true);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
            }

            if (Phase2)
            {
                //Charging_Timer
                if (Charging_Timer <= diff)
                {
                    Unit* target = NULL;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (target)
                    {
                        AttackStart(target);
                        DoCast(target, SPELL_BERSERKER_C);
                    }
                    Charging_Timer = 20000;
                } else Charging_Timer -= diff;

                //Intimidating Roar
                if (Roar_Timer <= diff)
                {
                    DoCast(me, SPELL_ROAR);
                    Roar_Timer = 40000+(rand()%10000);
                } else Roar_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

//Olm The Summoner AI
class boss_olm_the_summoner : public CreatureScript
{
public:
    boss_olm_the_summoner() : CreatureScript("boss_olm_the_summoner") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_olm_the_summonerAI (creature);
    }

    struct boss_olm_the_summonerAI : public ScriptedAI
    {
        boss_olm_the_summonerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 DarkDecay_Timer;
        uint32 Summon_Timer;
           uint32 DeathCoil_Timer;

        InstanceScript* instance;

        void Reset()
        {
            DarkDecay_Timer = 10000;
            Summon_Timer = 15000;
            DeathCoil_Timer = 20000;

            //reset encounter
            if (instance)
                instance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                me->GetMotionMaster()->MoveChase(who, 30.0f);
            }
        }

        void EnterCombat(Unit* who)
        {
            if (instance)
            {
                instance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                instance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), instance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(instance, me))
                    instance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->IsInCombat() && instance && instance->GetData(DATA_MAULGAREVENT))
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_MAULGAREVENT_TANK));

                if (target)
                {
                    AttackStart(target);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (instance && !instance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //DarkDecay_Timer
            if (DarkDecay_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_DARK_DECAY);
                DarkDecay_Timer = 20000;
            } else DarkDecay_Timer -= diff;

            //Summon_Timer
            if (Summon_Timer <= diff)
            {
                DoCast(me, SPELL_SUMMON_WFH);
                Summon_Timer = 30000;
            } else Summon_Timer -= diff;

            //DeathCoil Timer /need correct timer
            if (DeathCoil_Timer <= diff)
            {
                Unit* target = NULL;
                target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target)
                    DoCast(target, SPELL_DEATH_COIL);
                DeathCoil_Timer = 20000;
            } else DeathCoil_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

//Kiggler The Crazed AI
class boss_kiggler_the_crazed : public CreatureScript
{
public:
    boss_kiggler_the_crazed() : CreatureScript("boss_kiggler_the_crazed") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kiggler_the_crazedAI (creature);
    }

    struct boss_kiggler_the_crazedAI : public ScriptedAI
    {
        boss_kiggler_the_crazedAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 GreaterPolymorph_Timer;
        uint32 LightningBolt_Timer;
        uint32 ArcaneShock_Timer;
        uint32 ArcaneExplosion_Timer;

        InstanceScript* instance;

        void Reset()
        {
            GreaterPolymorph_Timer = 5000;
            LightningBolt_Timer = 10000;
            ArcaneShock_Timer = 20000;
            ArcaneExplosion_Timer = 30000;

            //reset encounter
            if (instance)
                instance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (instance)
            {
                instance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                instance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), instance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(instance, me))
                    instance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->IsInCombat() && instance && instance->GetData(DATA_MAULGAREVENT))
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_MAULGAREVENT_TANK));

                if (target)
                {
                    AttackStart(target);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (instance && !instance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //GreaterPolymorph_Timer
            if (GreaterPolymorph_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_GREATER_POLYMORPH);

                GreaterPolymorph_Timer = urand(15000, 20000);
            } else GreaterPolymorph_Timer -= diff;

            //LightningBolt_Timer
            if (LightningBolt_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_LIGHTNING_BOLT);
                LightningBolt_Timer = 15000;
            } else LightningBolt_Timer -= diff;

            //ArcaneShock_Timer
            if (ArcaneShock_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_ARCANE_SHOCK);
                ArcaneShock_Timer = 20000;
            } else ArcaneShock_Timer -= diff;

            //ArcaneExplosion_Timer
            if (ArcaneExplosion_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_ARCANE_EXPLOSION);
                ArcaneExplosion_Timer = 30000;
            } else ArcaneExplosion_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

//Blindeye The Seer AI
class boss_blindeye_the_seer : public CreatureScript
{
public:
    boss_blindeye_the_seer() : CreatureScript("boss_blindeye_the_seer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_blindeye_the_seerAI (creature);
    }

    struct boss_blindeye_the_seerAI : public ScriptedAI
    {
        boss_blindeye_the_seerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 GreaterPowerWordShield_Timer;
        uint32 Heal_Timer;
        uint32 PrayerofHealing_Timer;

        InstanceScript* instance;

        void Reset()
        {
            GreaterPowerWordShield_Timer = 5000;
            Heal_Timer = urand(25000, 40000);
            PrayerofHealing_Timer = urand(45000, 55000);

            //reset encounter
            if (instance)
                instance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (instance)
            {
                instance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                instance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), instance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(instance, me))
                    instance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

         void UpdateAI(uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->IsInCombat() && instance && instance->GetData(DATA_MAULGAREVENT))
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_MAULGAREVENT_TANK));

                if (target)
                {
                    AttackStart(target);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (instance && !instance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //GreaterPowerWordShield_Timer
            if (GreaterPowerWordShield_Timer <= diff)
            {
                DoCast(me, SPELL_GREATER_PW_SHIELD);
                GreaterPowerWordShield_Timer = 40000;
            } else GreaterPowerWordShield_Timer -= diff;

            //Heal_Timer
            if (Heal_Timer <= diff)
            {
                DoCast(me, SPELL_HEAL);
                Heal_Timer = urand(15000, 40000);
            } else Heal_Timer -= diff;

            //PrayerofHealing_Timer
            if (PrayerofHealing_Timer <= diff)
            {
                DoCast(me, SPELL_PRAYER_OH);
                PrayerofHealing_Timer = urand(35000, 50000);
            } else PrayerofHealing_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

//Krosh Firehand AI
class boss_krosh_firehand : public CreatureScript
{
public:
    boss_krosh_firehand() : CreatureScript("boss_krosh_firehand") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_krosh_firehandAI (creature);
    }

    struct boss_krosh_firehandAI : public ScriptedAI
    {
        boss_krosh_firehandAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 GreaterFireball_Timer;
        uint32 SpellShield_Timer;
        uint32 BlastWave_Timer;

        InstanceScript* instance;

        void Reset()
        {
            GreaterFireball_Timer = 1000;
            SpellShield_Timer = 5000;
            BlastWave_Timer = 20000;

            //reset encounter
            if (instance)
                instance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (instance)
            {
                instance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                instance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), instance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(instance, me))
                    instance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->IsInCombat() && instance && instance->GetData(DATA_MAULGAREVENT))
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_MAULGAREVENT_TANK));

                if (target)
                {
                    AttackStart(target);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (instance && !instance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //GreaterFireball_Timer
            if (GreaterFireball_Timer < diff || me->IsWithinDist(me->GetVictim(), 30))
            {
                DoCast(me->GetVictim(), SPELL_GREATER_FIREBALL);
                GreaterFireball_Timer = 2000;
            } else GreaterFireball_Timer -= diff;

            //SpellShield_Timer
            if (SpellShield_Timer <= diff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me->GetVictim(), SPELL_SPELLSHIELD);
                SpellShield_Timer = 30000;
            } else SpellShield_Timer -= diff;

            //BlastWave_Timer
            if (BlastWave_Timer <= diff)
            {
                Unit* target = NULL;
                std::list<HostileReference*> t_list = me->getThreatManager().getThreatList();
                std::vector<Unit*> target_list;
                for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                                                //15 yard radius minimum
                    if (target && target->IsWithinDist(me, 15, false))
                        target_list.push_back(target);
                    target = NULL;
                }
                if (!target_list.empty())
                    target = *(target_list.begin()+rand()%target_list.size());

                me->InterruptNonMeleeSpells(false);
                DoCast(target, SPELL_BLAST_WAVE);
                BlastWave_Timer = 60000;
            } else BlastWave_Timer -= diff;
        }
    };
};

void AddSC_boss_high_king_maulgar()
{
    new boss_high_king_maulgar();
    new boss_kiggler_the_crazed();
    new boss_blindeye_the_seer();
    new boss_olm_the_summoner();
    new boss_krosh_firehand();
}
