/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Moroes
SD%Complete: 95
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptPCH.h"
#include "karazhan.h"

#define SAY_AGGRO           -1532011
#define SAY_SPECIAL_1       -1532012
#define SAY_SPECIAL_2       -1532013
#define SAY_KILL_1          -1532014
#define SAY_KILL_2          -1532015
#define SAY_KILL_3          -1532016
#define SAY_DEATH           -1532017

#define SPELL_VANISH        29448
#define SPELL_GARROTE       37066
#define SPELL_BLIND         34694
#define SPELL_GOUGE         29425
#define SPELL_FRENZY        37023

#define POS_Z               81.73f

float Locations[4][3]=
{
    {-10991.0f, -1884.33f, 0.614315f},
    {-10989.4f, -1885.88f, 0.904913f},
    {-10978.1f, -1887.07f, 2.035550f},
    {-10975.9f, -1885.81f, 2.253890f},
};

const uint32 Adds[6]=
{
    17007,
    19872,
    19873,
    19874,
    19875,
    19876,
};

class boss_moroes : public CreatureScript
{
public:
    boss_moroes() : CreatureScript("boss_moroes") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_moroesAI (creature);
    }

    struct boss_moroesAI : public ScriptedAI
    {
        boss_moroesAI(Creature* c) : ScriptedAI(c)
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                AddId[i] = 0;
            }
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint64 AddGUID[4];

        uint32 Vanish_Timer;
        uint32 Blind_Timer;
        uint32 Gouge_Timer;
        uint32 Wait_Timer;
        uint32 CheckAdds_Timer;
        uint32 AddId[4];

        bool InVanish;
        bool Enrage;

        void Reset()
        {
            Vanish_Timer = 30000;
            Blind_Timer = 35000;
            Gouge_Timer = 23000;
            Wait_Timer = 0;
            CheckAdds_Timer = 5000;

            Enrage = false;
            InVanish = false;
            if (me->GetHealth() > 0)
            {
                SpawnAdds();
            }

            if (pInstance)
                pInstance->SetData(TYPE_MOROES, NOT_STARTED);
        }

        void StartEvent()
        {
            if (pInstance)
                pInstance->SetData(TYPE_MOROES, IN_PROGRESS);

            DoZoneInCombat();
        }

        void EnterCombat(Unit* /*who*/)
        {
            StartEvent();

            DoScriptText(SAY_AGGRO, me);
            AddsAttack();
            DoZoneInCombat();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(TYPE_MOROES, DONE);

            DeSpawnAdds();

            //remove aura from spell Garrote when Moroes dies
            if (pInstance)
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROTE);
        }

        void SpawnAdds()
        {
            DeSpawnAdds();
            if (isAddlistEmpty())
            {
                Creature* creature = NULL;
                std::vector<uint32> AddList;

                for (uint8 i = 0; i < 6; ++i)
                    AddList.push_back(Adds[i]);

                while (AddList.size() > 4)
                    AddList.erase((AddList.begin())+(rand()%AddList.size()));

                uint8 i = 0;
                for (std::vector<uint32>::const_iterator itr = AddList.begin(); itr != AddList.end(); ++itr)
                {
                    uint32 entry = *itr;

                    creature = me->SummonCreature(entry, Locations[i][0], Locations[i][1], POS_Z, Locations[i][2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    if (creature)
                    {
                        AddGUID[i] = creature->GetGUID();
                        AddId[i] = entry;
                    }
                    ++i;
                }
            }else
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    Creature* creature = me->SummonCreature(AddId[i], Locations[i][0], Locations[i][1], POS_Z, Locations[i][2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    if (creature)
                    {
                        AddGUID[i] = creature->GetGUID();
                    }
                }
            }
        }

        bool isAddlistEmpty()
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                if (AddId[i] == 0)
                    return true;
            }
            return false;
        }

        void DeSpawnAdds()
        {
            for (uint8 i = 0; i < 4 ; ++i)
            {
                Creature* Temp = NULL;
                if (AddGUID[i])
                {
                    Temp = Creature::GetCreature((*me), AddGUID[i]);
                    if (Temp && Temp->isAlive())
                        Temp->DisappearAndDie();
                }
            }
        }

        void AddsAttack()
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                Creature* Temp = NULL;
                if (AddGUID[i])
                {
                    Temp = Creature::GetCreature((*me), AddGUID[i]);
                    if (Temp && Temp->isAlive())
                    {
                        Temp->AI()->AttackStart(me->getVictim());
                        DoZoneInCombat(Temp);
                    } else
                        EnterEvadeMode();
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (pInstance && !pInstance->GetData(TYPE_MOROES))
            {
                EnterEvadeMode();
                return;
            }

            if (!Enrage && HealthBelowPct(30))
            {
                DoCast(me, SPELL_FRENZY);
                Enrage = true;
            }

            if (CheckAdds_Timer <= diff)
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    Creature* Temp = NULL;
                    if (AddGUID[i])
                    {
                        Temp = Unit::GetCreature((*me), AddGUID[i]);
                        if (Temp && Temp->isAlive())
                            if (!Temp->getVictim())
                                Temp->AI()->AttackStart(me->getVictim());
                    }
                }
                CheckAdds_Timer = 5000;
            } else CheckAdds_Timer -= diff;

            if (!Enrage)
            {
                //Cast Vanish, then Garrote random victim
                if (Vanish_Timer <= diff)
                {
                    DoCast(me, SPELL_VANISH);
                    InVanish = true;
                    Vanish_Timer = 30000;
                    Wait_Timer = 5000;
                } else Vanish_Timer -= diff;

                if (Gouge_Timer <= diff)
                {
                    DoCastVictim(SPELL_GOUGE);
                    Gouge_Timer = 40000;
                } else Gouge_Timer -= diff;

                if (Blind_Timer <= diff)
                {
                    std::list<Unit*> pTargets;
                    SelectTargetList(pTargets, 5, SELECT_TARGET_RANDOM, me->GetMeleeReach()*5, true);
                    for (std::list<Unit*>::const_iterator i = pTargets.begin(); i != pTargets.end(); ++i)
                        if (!me->IsWithinMeleeRange(*i))
                        {
                            DoCast(*i, SPELL_BLIND);
                            break;
                        }
                    Blind_Timer = 40000;
                } else Blind_Timer -= diff;
            }

            if (InVanish)
            {
                if (Wait_Timer <= diff)
                {
                    DoScriptText(RAND(SAY_SPECIAL_1, SAY_SPECIAL_2), me);

                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        pTarget->CastSpell(pTarget, SPELL_GARROTE, true);

                    InVanish = false;
                } else Wait_Timer -= diff;
            }

            if (!InVanish)
                DoMeleeAttackIfReady();
        }
    };

};

struct boss_moroes_guestAI : public ScriptedAI
{
    InstanceScript* pInstance;

    uint64 GuestGUID[4];

    boss_moroes_guestAI(Creature* c) : ScriptedAI(c)
    {
        for (uint8 i = 0; i < 4; ++i)
            GuestGUID[i] = 0;

        pInstance = c->GetInstanceScript();
    }

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(TYPE_MOROES, NOT_STARTED);
    }

    void AcquireGUID()
    {
        if (!pInstance)
            return;

        uint64 MoroesGUID = pInstance->GetData64(DATA_MOROES);
        Creature* Moroes = (Unit::GetCreature((*me), MoroesGUID));
        if (Moroes)
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                uint64 GUID = CAST_AI(boss_moroes::boss_moroesAI, Moroes->AI())->AddGUID[i];
                if (GUID)
                    GuestGUID[i] = GUID;
            }
        }
    }

    Unit* SelectGuestTarget()
    {
        uint64 TempGUID = GuestGUID[rand()%4];
        if (TempGUID)
        {
            Unit* pUnit = Unit::GetUnit((*me), TempGUID);
            if (pUnit && pUnit->isAlive())
                return pUnit;
        }

        return me;
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        if (pInstance && !pInstance->GetData(TYPE_MOROES))
            EnterEvadeMode();

        DoMeleeAttackIfReady();
    }
};

#define SPELL_MANABURN       29405
#define SPELL_MINDFLY        29570
#define SPELL_SWPAIN         34441
#define SPELL_SHADOWFORM     29406

#define SPELL_HAMMEROFJUSTICE       13005
#define SPELL_JUDGEMENTOFCOMMAND    29386
#define SPELL_SEALOFCOMMAND         29385

#define SPELL_DISPELMAGIC           15090                   //Self or other guest+Moroes
#define SPELL_GREATERHEAL           29564                   //Self or other guest+Moroes
#define SPELL_HOLYFIRE              29563
#define SPELL_PWSHIELD              29408

#define SPELL_CLEANSE               29380                   //Self or other guest+Moroes
#define SPELL_GREATERBLESSOFMIGHT   29381                   //Self or other guest+Moroes
#define SPELL_HOLYLIGHT             29562                   //Self or other guest+Moroes
#define SPELL_DIVINESHIELD          41367

#define SPELL_HAMSTRING         9080
#define SPELL_MORTALSTRIKE      29572
#define SPELL_WHIRLWIND         29573

#define SPELL_DISARM            8379
#define SPELL_HEROICSTRIKE      29567
#define SPELL_SHIELDBASH        11972
#define SPELL_SHIELDWALL        29390

class boss_baroness_dorothea_millstipe : public CreatureScript
{
public:
    boss_baroness_dorothea_millstipe() : CreatureScript("boss_baroness_dorothea_millstipe") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_baroness_dorothea_millstipeAI (creature);
    }

    struct boss_baroness_dorothea_millstipeAI : public boss_moroes_guestAI
    {
        //Shadow Priest
        boss_baroness_dorothea_millstipeAI(Creature* c) : boss_moroes_guestAI(c) {}

        uint32 ManaBurn_Timer;
        uint32 MindFlay_Timer;
        uint32 ShadowWordPain_Timer;

        void Reset()
        {
            ManaBurn_Timer = 7000;
            MindFlay_Timer = 1000;
            ShadowWordPain_Timer = 6000;

            DoCast(me, SPELL_SHADOWFORM, true);

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (MindFlay_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MINDFLY);
                MindFlay_Timer = 12000;                         // 3 sec channeled
            } else MindFlay_Timer -= diff;

            if (ManaBurn_Timer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    if (pTarget->getPowerType() == POWER_MANA)
                        DoCast(pTarget, SPELL_MANABURN);
                ManaBurn_Timer = 5000;                          // 3 sec cast
            } else ManaBurn_Timer -= diff;

            if (ShadowWordPain_Timer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    DoCast(pTarget, SPELL_SWPAIN);
                    ShadowWordPain_Timer = 7000;
                }
            } else ShadowWordPain_Timer -= diff;
        }
    };

};

class boss_baron_rafe_dreuger : public CreatureScript
{
public:
    boss_baron_rafe_dreuger() : CreatureScript("boss_baron_rafe_dreuger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_baron_rafe_dreugerAI (creature);
    }

    struct boss_baron_rafe_dreugerAI : public boss_moroes_guestAI
    {
        //Retr Pally
        boss_baron_rafe_dreugerAI(Creature* c) : boss_moroes_guestAI(c){}

        uint32 HammerOfJustice_Timer;
        uint32 SealOfCommand_Timer;
        uint32 JudgementOfCommand_Timer;

        void Reset()
        {
            HammerOfJustice_Timer = 1000;
            SealOfCommand_Timer = 7000;
            JudgementOfCommand_Timer = SealOfCommand_Timer + 29000;

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (SealOfCommand_Timer <= diff)
            {
                DoCast(me, SPELL_SEALOFCOMMAND);
                SealOfCommand_Timer = 32000;
                JudgementOfCommand_Timer = 29000;
            } else SealOfCommand_Timer -= diff;

            if (JudgementOfCommand_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_JUDGEMENTOFCOMMAND);
                JudgementOfCommand_Timer = SealOfCommand_Timer + 29000;
            } else JudgementOfCommand_Timer -= diff;

            if (HammerOfJustice_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HAMMEROFJUSTICE);
                HammerOfJustice_Timer = 12000;
            } else HammerOfJustice_Timer -= diff;
        }
    };

};

class boss_lady_catriona_von_indi : public CreatureScript
{
public:
    boss_lady_catriona_von_indi() : CreatureScript("boss_lady_catriona_von_indi") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lady_catriona_von_indiAI (creature);
    }

    struct boss_lady_catriona_von_indiAI : public boss_moroes_guestAI
    {
        //Holy Priest
        boss_lady_catriona_von_indiAI(Creature* c) : boss_moroes_guestAI(c) {}

        uint32 DispelMagic_Timer;
        uint32 GreaterHeal_Timer;
        uint32 HolyFire_Timer;
        uint32 PowerWordShield_Timer;

        void Reset()
        {
            DispelMagic_Timer = 11000;
            GreaterHeal_Timer = 1500;
            HolyFire_Timer = 5000;
            PowerWordShield_Timer = 1000;

            AcquireGUID();

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (PowerWordShield_Timer <= diff)
            {
                DoCast(me, SPELL_PWSHIELD);
                PowerWordShield_Timer = 15000;
            } else PowerWordShield_Timer -= diff;

            if (GreaterHeal_Timer <= diff)
            {
                Unit* pTarget = SelectGuestTarget();

                DoCast(pTarget, SPELL_GREATERHEAL);
                GreaterHeal_Timer = 17000;
            } else GreaterHeal_Timer -= diff;

            if (HolyFire_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HOLYFIRE);
                HolyFire_Timer = 22000;
            } else HolyFire_Timer -= diff;

            if (DispelMagic_Timer <= diff)
            {
                if (Unit* pTarget = RAND(SelectGuestTarget(), SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true)))
                    DoCast(pTarget, SPELL_DISPELMAGIC);

                DispelMagic_Timer = 25000;
            } else DispelMagic_Timer -= diff;
        }
    };

};

class boss_lady_keira_berrybuck : public CreatureScript
{
public:
    boss_lady_keira_berrybuck() : CreatureScript("boss_lady_keira_berrybuck") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lady_keira_berrybuckAI (creature);
    }

    struct boss_lady_keira_berrybuckAI : public boss_moroes_guestAI
    {
        //Holy Pally
        boss_lady_keira_berrybuckAI(Creature* c) : boss_moroes_guestAI(c)  {}

        uint32 Cleanse_Timer;
        uint32 GreaterBless_Timer;
        uint32 HolyLight_Timer;
        uint32 DivineShield_Timer;

        void Reset()
        {
            Cleanse_Timer = 13000;
            GreaterBless_Timer = 1000;
            HolyLight_Timer = 7000;
            DivineShield_Timer = 31000;

            AcquireGUID();

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (DivineShield_Timer <= diff)
            {
                DoCast(me, SPELL_DIVINESHIELD);
                DivineShield_Timer = 31000;
            } else DivineShield_Timer -= diff;

            if (HolyLight_Timer <= diff)
            {
                Unit* pTarget = SelectGuestTarget();

                DoCast(pTarget, SPELL_HOLYLIGHT);
                HolyLight_Timer = 10000;
            } else HolyLight_Timer -= diff;

            if (GreaterBless_Timer <= diff)
            {
                Unit* pTarget = SelectGuestTarget();

                DoCast(pTarget, SPELL_GREATERBLESSOFMIGHT);

                GreaterBless_Timer = 50000;
            } else GreaterBless_Timer -= diff;

            if (Cleanse_Timer <= diff)
            {
                Unit* pTarget = SelectGuestTarget();

                DoCast(pTarget, SPELL_CLEANSE);

                Cleanse_Timer = 10000;
            } else Cleanse_Timer -= diff;
        }
    };

};

class boss_lord_robin_daris : public CreatureScript
{
public:
    boss_lord_robin_daris() : CreatureScript("boss_lord_robin_daris") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lord_robin_darisAI (creature);
    }

    struct boss_lord_robin_darisAI : public boss_moroes_guestAI
    {
        //Arms Warr
        boss_lord_robin_darisAI(Creature* c) : boss_moroes_guestAI(c) {}

        uint32 Hamstring_Timer;
        uint32 MortalStrike_Timer;
        uint32 WhirlWind_Timer;

        void Reset()
        {
            Hamstring_Timer = 7000;
            MortalStrike_Timer = 10000;
            WhirlWind_Timer = 21000;

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (Hamstring_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HAMSTRING);
                Hamstring_Timer = 12000;
            } else Hamstring_Timer -= diff;

            if (MortalStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTALSTRIKE);
                MortalStrike_Timer = 18000;
            } else MortalStrike_Timer -= diff;

            if (WhirlWind_Timer <= diff)
            {
                DoCast(me, SPELL_WHIRLWIND);
                WhirlWind_Timer = 21000;
            } else WhirlWind_Timer -= diff;
        }
    };

};

class boss_lord_crispin_ference : public CreatureScript
{
public:
    boss_lord_crispin_ference() : CreatureScript("boss_lord_crispin_ference") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lord_crispin_ferenceAI (creature);
    }

    struct boss_lord_crispin_ferenceAI : public boss_moroes_guestAI
    {
        //Arms Warr
        boss_lord_crispin_ferenceAI(Creature* c) : boss_moroes_guestAI(c) {}

        uint32 Disarm_Timer;
        uint32 HeroicStrike_Timer;
        uint32 ShieldBash_Timer;
        uint32 ShieldWall_Timer;

        void Reset()
        {
            Disarm_Timer = 6000;
            HeroicStrike_Timer = 10000;
            ShieldBash_Timer = 8000;
            ShieldWall_Timer = 4000;

            boss_moroes_guestAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_moroes_guestAI::UpdateAI(diff);

            if (Disarm_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DISARM);
                Disarm_Timer = 12000;
            } else Disarm_Timer -= diff;

            if (HeroicStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HEROICSTRIKE);
                HeroicStrike_Timer = 10000;
            } else HeroicStrike_Timer -= diff;

            if (ShieldBash_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHIELDBASH);
                ShieldBash_Timer = 13000;
            } else ShieldBash_Timer -= diff;

            if (ShieldWall_Timer <= diff)
            {
                DoCast(me, SPELL_SHIELDWALL);
                ShieldWall_Timer = 21000;
            } else ShieldWall_Timer -= diff;
        }
    };

};

void AddSC_boss_moroes()
{
    new boss_moroes();
    new boss_baroness_dorothea_millstipe();
    new boss_baron_rafe_dreuger();
    new boss_lady_catriona_von_indi();
    new boss_lady_keira_berrybuck();
    new boss_lord_robin_daris();
    new boss_lord_crispin_ference();
}
