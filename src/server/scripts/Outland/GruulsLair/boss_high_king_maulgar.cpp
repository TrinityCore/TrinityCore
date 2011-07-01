/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "gruuls_lair.h"

#define SAY_AGGRO               -1565000
#define SAY_ENRAGE              -1565001
#define SAY_OGRE_DEATH1         -1565002
#define SAY_OGRE_DEATH2         -1565003
#define SAY_OGRE_DEATH3         -1565004
#define SAY_OGRE_DEATH4         -1565005
#define SAY_SLAY1               -1565006
#define SAY_SLAY2               -1565007
#define SAY_SLAY3               -1565008
#define SAY_DEATH               -1565009

// High King Maulgar
#define SPELL_ARCING_SMASH      39144
#define SPELL_MIGHTY_BLOW       33230
#define SPELL_WHIRLWIND         33238
#define SPELL_BERSERKER_C       26561
#define SPELL_ROAR              16508
#define SPELL_FLURRY            33232
#define SPELL_DUAL_WIELD        29651 //used in phase

// Olm the Summoner
#define SPELL_DARK_DECAY        33129
#define SPELL_DEATH_COIL        33130
#define SPELL_SUMMON_WFH        33131

//Kiggler the Craed
#define SPELL_GREATER_POLYMORPH     33173
#define SPELL_LIGHTNING_BOLT        36152
#define SPELL_ARCANE_SHOCK          33175
#define SPELL_ARCANE_EXPLOSION      33237

//Blindeye the Seer
#define SPELL_GREATER_PW_SHIELD         33147
#define SPELL_HEAL                      33144
#define SPELL_PRAYER_OH                 33152

//Krosh Firehand
#define SPELL_GREATER_FIREBALL  33051
#define SPELL_SPELLSHIELD       33054
#define SPELL_BLAST_WAVE        33061

bool CheckAllBossDied(InstanceScript* pInstance, Creature* me)
{
    if (!pInstance || !me)
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

    MaulgarGUID = pInstance->GetData64(DATA_MAULGAR);
    KigglerGUID = pInstance->GetData64(DATA_KIGGLERTHECRAZED);
    BlindeyeGUID = pInstance->GetData64(DATA_BLINDEYETHESEER);
    OlmGUID = pInstance->GetData64(DATA_OLMTHESUMMONER);
    KroshGUID = pInstance->GetData64(DATA_KROSHFIREHAND);

    Maulgar = (Unit::GetCreature((*me), MaulgarGUID));
    Kiggler = (Unit::GetCreature((*me), KigglerGUID));
    Blindeye = (Unit::GetCreature((*me), BlindeyeGUID));
    Olm = (Unit::GetCreature((*me), OlmGUID));
    Krosh = (Unit::GetCreature((*me), KroshGUID));

    if (!Maulgar || !Kiggler || !Blindeye || !Olm || !Krosh)
        return false;

    if (!Maulgar->isAlive() && !Kiggler->isAlive() && !Blindeye->isAlive() && !Olm->isAlive() && !Krosh->isAlive())
        return true;

    return false;
}

//High King Maulgar AI
class boss_high_king_maulgar : public CreatureScript
{
public:
    boss_high_king_maulgar() : CreatureScript("boss_high_king_maulgar") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_high_king_maulgarAI (pCreature);
    }

    struct boss_high_king_maulgarAI : public ScriptedAI
    {
        boss_high_king_maulgarAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            for (uint8 i = 0; i < 4; ++i)
                Council[i] = 0;
        }

        InstanceScript* pInstance;

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

            Creature* pCreature = NULL;
            for (uint8 i = 0; i < 4; ++i)
            {
                if (Council[i])
                {
                    pCreature = (Unit::GetCreature((*me), Council[i]));
                    if (pCreature && !pCreature->isAlive())
                    {
                        pCreature->Respawn();
                        pCreature->AI()->EnterEvadeMode();
                    }
                }
            }

            //reset encounter
            if (pInstance)
                pInstance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2, SAY_SLAY3), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (CheckAllBossDied(pInstance, me))
                pInstance->SetData(DATA_MAULGAREVENT, DONE);
        }

           void AddDeath()
           {
                DoScriptText(RAND(SAY_OGRE_DEATH1, SAY_OGRE_DEATH2, SAY_OGRE_DEATH3, SAY_OGRE_DEATH4), me);
           }

        void EnterCombat(Unit* who)
        {
            StartEvent(who);
        }

        void GetCouncil()
        {
            if (pInstance)
            {
                //get council member's guid to respawn them if needed
                Council[0] = pInstance->GetData64(DATA_KIGGLERTHECRAZED);
                Council[1] = pInstance->GetData64(DATA_BLINDEYETHESEER);
                Council[2] = pInstance->GetData64(DATA_OLMTHESUMMONER);
                Council[3] = pInstance->GetData64(DATA_KROSHFIREHAND);
            }
        }

        void StartEvent(Unit* who)
        {
            if (!pInstance)
                return;

            GetCouncil();

            DoScriptText(SAY_AGGRO, me);

            pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            pInstance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);

            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->isInCombat() && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

                if (pTarget)
                {
                    AttackStart(pTarget);
                    GetCouncil();
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //ArcingSmash_Timer
            if (ArcingSmash_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCING_SMASH);
                ArcingSmash_Timer = 10000;
            } else ArcingSmash_Timer -= diff;

            //Whirlwind_Timer
                   if (Whirlwind_Timer <= diff)
                   {
                        DoCast(me->getVictim(), SPELL_WHIRLWIND);
                        Whirlwind_Timer = 55000;
                   } else Whirlwind_Timer -= diff;

            //MightyBlow_Timer
            if (MightyBlow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MIGHTY_BLOW);
                MightyBlow_Timer = 30000+rand()%10000;
            } else MightyBlow_Timer -= diff;

            //Entering Phase 2
            if (!Phase2 && HealthBelowPct(50))
            {
                Phase2 = true;
                DoScriptText(SAY_ENRAGE, me);

                DoCast(me, SPELL_DUAL_WIELD, true);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
            }

            if (Phase2)
            {
                //Charging_Timer
                if (Charging_Timer <= diff)
                {
                    Unit* pTarget = NULL;
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (pTarget)
                    {
                        AttackStart(pTarget);
                        DoCast(pTarget, SPELL_BERSERKER_C);
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_olm_the_summonerAI (pCreature);
    }

    struct boss_olm_the_summonerAI : public ScriptedAI
    {
        boss_olm_the_summonerAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 DarkDecay_Timer;
        uint32 Summon_Timer;
           uint32 DeathCoil_Timer;

        InstanceScript* pInstance;

        void Reset()
        {
            DarkDecay_Timer = 10000;
            Summon_Timer = 15000;
            DeathCoil_Timer = 20000;

            //reset encounter
            if (pInstance)
                pInstance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, true))
            {
                me->AddThreat(pWho, 0.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);

                me->GetMotionMaster()->MoveChase(pWho, 30.0f);
            }
        }

        void EnterCombat(Unit* who)
        {
            if (pInstance)
            {
                pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                pInstance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), pInstance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(pInstance, me))
                    pInstance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->isInCombat() && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

                if (pTarget)
                {
                    AttackStart(pTarget);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //DarkDecay_Timer
            if (DarkDecay_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DARK_DECAY);
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
                Unit* pTarget = NULL;
                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (pTarget)
                    DoCast(pTarget, SPELL_DEATH_COIL);
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

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new boss_kiggler_the_crazedAI (pCreature);
    }

    struct boss_kiggler_the_crazedAI : public ScriptedAI
    {
        boss_kiggler_the_crazedAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 GreaterPolymorph_Timer;
        uint32 LightningBolt_Timer;
        uint32 ArcaneShock_Timer;
        uint32 ArcaneExplosion_Timer;

        InstanceScript* pInstance;

        void Reset()
        {
            GreaterPolymorph_Timer = 5000;
            LightningBolt_Timer = 10000;
            ArcaneShock_Timer = 20000;
            ArcaneExplosion_Timer = 30000;

            //reset encounter
            if (pInstance)
                pInstance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (pInstance)
            {
                pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                pInstance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), pInstance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(pInstance, me))
                    pInstance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->isInCombat() && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

                if (pTarget)
                {
                    AttackStart(pTarget);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //GreaterPolymorph_Timer
            if (GreaterPolymorph_Timer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (pTarget)
                    DoCast(pTarget, SPELL_GREATER_POLYMORPH);

                GreaterPolymorph_Timer = 15000 + rand()%5000;
            } else GreaterPolymorph_Timer -= diff;

            //LightningBolt_Timer
            if (LightningBolt_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
                LightningBolt_Timer = 15000;
            } else LightningBolt_Timer -= diff;

            //ArcaneShock_Timer
            if (ArcaneShock_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCANE_SHOCK);
                ArcaneShock_Timer = 20000;
            } else ArcaneShock_Timer -= diff;

            //ArcaneExplosion_Timer
            if (ArcaneExplosion_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCANE_EXPLOSION);
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

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new boss_blindeye_the_seerAI (pCreature);
    }

    struct boss_blindeye_the_seerAI : public ScriptedAI
    {
        boss_blindeye_the_seerAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 GreaterPowerWordShield_Timer;
        uint32 Heal_Timer;
        uint32 PrayerofHealing_Timer;

        InstanceScript* pInstance;

        void Reset()
        {
            GreaterPowerWordShield_Timer = 5000;
            Heal_Timer = 25000 + rand()%15000;
            PrayerofHealing_Timer = 45000 + rand()%10000;

            //reset encounter
            if (pInstance)
                pInstance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (pInstance)
            {
                pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                pInstance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), pInstance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(pInstance, me))
                    pInstance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

         void UpdateAI(const uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->isInCombat() && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

                if (pTarget)
                {
                    AttackStart(pTarget);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
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
                Heal_Timer = 15000 + rand()%25000;
            } else Heal_Timer -= diff;

            //PrayerofHealing_Timer
            if (PrayerofHealing_Timer <= diff)
            {
                DoCast(me, SPELL_PRAYER_OH);
                PrayerofHealing_Timer = 35000 + rand()%15000;
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

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new boss_krosh_firehandAI (pCreature);
    }

    struct boss_krosh_firehandAI : public ScriptedAI
    {
        boss_krosh_firehandAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 GreaterFireball_Timer;
        uint32 SpellShield_Timer;
        uint32 BlastWave_Timer;

        InstanceScript* pInstance;

        void Reset()
        {
            GreaterFireball_Timer = 1000;
            SpellShield_Timer = 5000;
            BlastWave_Timer = 20000;

            //reset encounter
            if (pInstance)
                pInstance->SetData(DATA_MAULGAREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            if (pInstance)
            {
                pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                pInstance->SetData(DATA_MAULGAREVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                Creature* Maulgar = NULL;
                Maulgar = (Unit::GetCreature((*me), pInstance->GetData64(DATA_MAULGAR)));

                if (Maulgar)
                    CAST_AI(boss_high_king_maulgar::boss_high_king_maulgarAI, Maulgar->AI())->AddDeath();

                if (CheckAllBossDied(pInstance, me))
                    pInstance->SetData(DATA_MAULGAREVENT, DONE);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Only if not incombat check if the event is started
            if (!me->isInCombat() && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

                if (pTarget)
                {
                    AttackStart(pTarget);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //someone evaded!
            if (pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            {
                EnterEvadeMode();
                return;
            }

            //GreaterFireball_Timer
            if (GreaterFireball_Timer < diff || me->IsWithinDist(me->getVictim(), 30))
            {
                DoCast(me->getVictim(), SPELL_GREATER_FIREBALL);
                GreaterFireball_Timer = 2000;
            } else GreaterFireball_Timer -= diff;

            //SpellShield_Timer
            if (SpellShield_Timer <= diff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me->getVictim(), SPELL_SPELLSHIELD);
                SpellShield_Timer = 30000;
            } else SpellShield_Timer -= diff;

            //BlastWave_Timer
            if (BlastWave_Timer <= diff)
            {
                Unit* pTarget = NULL;
                std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                std::vector<Unit* > target_list;
                for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                                                //15 yard radius minimum
                    if (pTarget && pTarget->IsWithinDist(me, 15, false))
                        target_list.push_back(pTarget);
                    pTarget = NULL;
                }
                if (target_list.size())
                    pTarget = *(target_list.begin()+rand()%target_list.size());

                me->InterruptNonMeleeSpells(false);
                DoCast(pTarget, SPELL_BLAST_WAVE);
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
