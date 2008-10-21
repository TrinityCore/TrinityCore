/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Terestian_Illhoof
SD%Complete: 100
SDComment: Complete!
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"
#include "def_karazhan.h"

#define SPELL_SUMMON_DEMONCHAINS    30120                   // Summons demonic chains that maintain the ritual of sacrifice.
#define SPELL_DEMON_CHAINS          30206                   // Instant - Visual Effect
#define SPELL_ENRAGE                23537                   // Increases the caster's attack speed by 50% and the Physical damage it deals by 219 to 281 for 10 min.
#define SPELL_SHADOW_BOLT           30055                   // Hurls a bolt of dark magic at an enemy, inflicting Shadow damage.
#define SPELL_SACRIFICE             30115                   // Teleports and adds the debuff
#define SPELL_BERSERK               32965                   // Increases attack speed by 75%. Periodically casts Shadow Bolt Volley.

#define SPELL_FIREBOLT              18086                   // Blasts a target for 150 Fire damage.

#define SPELL_BROKEN_PACT           30065                   // All damage taken increased by 25%.
#define SPELL_AMPLIFY_FLAMES        30053                   // Increases the Fire damage taken by an enemy by 500 for 25 sec.
#define SPELL_FIREBOLT              18086                   // Blasts a target for 150 Fire damage.

#define SAY_SLAY1           "Your blood will anoint my circle."
#define SOUND_SLAY1         9264
#define SAY_SLAY2           "The great one will be pleased."
#define SOUND_SLAY2         9329

#define SAY_DEATH           "My life, is yours. Oh great one."
#define SOUND_DEATH         9262

#define SAY_AGGRO           "Ah, you're just in time. The rituals are about to begin."
#define SOUND_AGGRO         9260

#define SAY_SACRIFICE1      "Please, accept this humble offering, oh great one."
#define SOUND_SACRIFICE1    9263
#define SAY_SACRIFICE2      "Let the sacrifice serve his testament to my fealty."
#define SOUND_SACRIFICE2    9330

#define SAY_SUMMON1         "Come, you dwellers in the dark. Rally to my call!"
#define SOUND_SUMMON1       9265
#define SAY_SUMMON2         "Gather, my pets. There is plenty for all."
#define SOUND_SUMMON2       9331

#define CREATURE_DEMONCHAINS    17248
#define CREATURE_FIENDISHIMP    17267
#define CREATURE_PORTAL         17265

#define SACRIFICE_X     -11240.599
#define SACRIFICE_Y     -1694.2700
#define SACRIFICE_Z     179.720007

#define PORTAL_Z        179.434

float PortalLocations[2][2]=
{
    {-11249.6933, -1704.61023},
    {-11242.1160, -1713.33325},
};

struct TRINITY_DLL_DECL mob_kilrekAI : public ScriptedAI
{
    mob_kilrekAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint64 TerestianGUID;

    uint32 AmplifyTimer;

    void Reset()
    {
        TerestianGUID = 0;

        AmplifyTimer = 0;
    }

    void Aggro(Unit *who)
    {
        if(!pInstance)
        {
            ERROR_INST_DATA(m_creature);
            return;
        }

        Creature* Terestian = ((Creature*)Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_TERESTIAN)));
        if(Terestian && (!Terestian->SelectHostilTarget() && !Terestian->getVictim()))
            Terestian->AddThreat(who, 1.0f);
    }

    void JustDied(Unit* Killer)
    {
        if(pInstance)
        {
            uint64 TerestianGUID = pInstance->GetData64(DATA_TERESTIAN);
            if(TerestianGUID)
            {
                Unit* Terestian = Unit::GetUnit((*m_creature), TerestianGUID);
                if(Terestian && Terestian->isAlive())
                    DoCast(Terestian, SPELL_BROKEN_PACT, true);
            }
        }else ERROR_INST_DATA(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if (AmplifyTimer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(),SPELL_AMPLIFY_FLAMES);

            AmplifyTimer = 20000;
        }else AmplifyTimer -= diff;

        //Chain cast
        if (!m_creature->IsNonMeleeSpellCasted(false) && m_creature->IsWithinDistInMap(m_creature->getVictim(), 30))
            DoCast(m_creature->getVictim(),SPELL_FIREBOLT);
        else DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_demon_chainAI : public ScriptedAI
{
    mob_demon_chainAI(Creature *c) : ScriptedAI(c)
    {
        Reset();
    }

    uint64 SacrificeGUID;

    void Reset()
    {
        SacrificeGUID = 0;
    }

    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}

    void JustDied(Unit *killer)
    {
        if(SacrificeGUID)
        {
            Unit* Sacrifice = Unit::GetUnit((*m_creature),SacrificeGUID);
            if(Sacrifice)
                Sacrifice->RemoveAurasDueToSpell(SPELL_SACRIFICE);
        }
    }
};

struct TRINITY_DLL_DECL boss_terestianAI : public ScriptedAI
{
    boss_terestianAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    uint64 KilrekGUID;
    uint64 PortalGUID[2];

    uint32 CheckKilrekTimer;
    uint32 SacrificeTimer;
    uint32 ShadowboltTimer;
    uint32 SummonTimer;
    uint32 BerserkTimer;

    bool SummonKilrek;
    bool SummonedPortals;
    bool Berserk;

    void Reset()
    {
        for(uint8 i = 0; i < 2; ++i)
        {
            if(PortalGUID[i])
            {
                Unit* Portal = Unit::GetUnit((*m_creature), PortalGUID[i]);
                if(Portal)
                    Portal->DealDamage(Portal, Portal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                PortalGUID[i] = 0;
            }
        }

        CheckKilrekTimer    =  5000;
        SacrificeTimer      = 30000;
        ShadowboltTimer     =  5000;
        SummonTimer         = 10000;
        BerserkTimer        = 600000;

        SummonedPortals     = false;
        Berserk             = false;

        if(pInstance)
            pInstance->SetData(DATA_TERESTIAN_EVENT, NOT_STARTED);
    }

    void Aggro(Unit* who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);

        if(pInstance)
        {
            // Put Kil'rek in combat against our target so players don't skip him
            Creature* Kilrek = ((Creature*)Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_KILREK)));
            if(Kilrek && (!Kilrek->SelectHostilTarget() && !Kilrek->getVictim()))
                Kilrek->AddThreat(who, 1.0f);

            pInstance->SetData(DATA_TERESTIAN_EVENT, IN_PROGRESS);
        }else ERROR_INST_DATA(m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
        }
    }

    void JustDied(Unit *killer)
    {
        for(uint8 i = 0; i < 2; ++i)
        {
            if(PortalGUID[i])
            {
                Unit* Portal = Unit::GetUnit((*m_creature), PortalGUID[i]);
                if(Portal)
                    Portal->DealDamage(Portal, Portal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                PortalGUID[i] = 0;
            }
        }

        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);

        if(pInstance)
            pInstance->SetData(DATA_TERESTIAN_EVENT, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->getVictim() && !m_creature->SelectHostilTarget())
            return;

        if(CheckKilrekTimer < diff)
        {
            CheckKilrekTimer = 5000;

            if(pInstance)
                uint64 KilrekGUID = pInstance->GetData64(DATA_KILREK);
            else ERROR_INST_DATA(m_creature);

            Creature* Kilrek = ((Creature*)Unit::GetUnit((*m_creature), KilrekGUID));
            if(SummonKilrek && Kilrek)
            {
                Kilrek->Respawn();
                Kilrek->AI()->AttackStart(m_creature->getVictim());

                SummonKilrek = false;
            }

            if(!Kilrek || !Kilrek->isAlive())
            {
                SummonKilrek = true;
                CheckKilrekTimer = 45000;
            }
        }else CheckKilrekTimer -= diff;

        if(SacrificeTimer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if(target && target->isAlive() && target->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(target, SPELL_SACRIFICE, true);
                Creature* Chains = m_creature->SummonCreature(CREATURE_DEMONCHAINS, SACRIFICE_X, SACRIFICE_Y, SACRIFICE_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 21000);
                if(Chains)
                {
                    ((mob_demon_chainAI*)Chains->AI())->SacrificeGUID = target->GetGUID();
                    Chains->CastSpell(Chains, SPELL_DEMON_CHAINS, true);
                    switch(rand()%2)
                    {
                        case 0:
                            DoYell(SAY_SACRIFICE1, LANG_UNIVERSAL, NULL);
                            DoPlaySoundToSet(m_creature, SOUND_SACRIFICE1);
                            break;
                        case 1:
                            DoYell(SAY_SACRIFICE2, LANG_UNIVERSAL, NULL);
                            DoPlaySoundToSet(m_creature, SOUND_SACRIFICE2);
                            break;
                    }
                    SacrificeTimer = 30000;
                }
            }
        }else SacrificeTimer -= diff;

        if(ShadowboltTimer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_TOPAGGRO, 0), SPELL_SHADOW_BOLT);
            ShadowboltTimer = 10000;
        }else ShadowboltTimer -= diff;

        if(SummonTimer < diff)
        {
            if(!SummonedPortals)
            {
                for(uint8 i = 0; i < 2; ++i)
                {
                    Creature* Portal = m_creature->SummonCreature(CREATURE_PORTAL, PortalLocations[i][0], PortalLocations[i][1], PORTAL_Z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if(Portal)
                        PortalGUID[i] = Portal->GetGUID();
                }
                SummonedPortals = true;
                switch(rand()%2)
                {
                    case 0:
                        DoYell(SAY_SUMMON1, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_SUMMON1);
                        break;
                    case 1:
                        DoYell(SAY_SUMMON2, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_SUMMON2);
                        break;
                }
            }
            uint32 random = rand()%2;
            Creature* Imp = m_creature->SummonCreature(CREATURE_FIENDISHIMP, PortalLocations[random][0], PortalLocations[random][1], PORTAL_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 15000);
            if(Imp)
            {
                Imp->AddThreat(m_creature->getVictim(), 1.0f);
                Imp->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 1));
            }
            SummonTimer = 5000;
        }else SummonTimer -= diff;

        if(!Berserk)
            if(BerserkTimer < diff)
        {
            DoCast(m_creature, SPELL_BERSERK);
            Berserk = true;
        }else BerserkTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_karazhan_impAI : public ScriptedAI
{
    mob_karazhan_impAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 FireboltTimer;

    void Reset()
    {
        FireboltTimer = 3000;
    }

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if(FireboltTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FIREBOLT);
            FireboltTimer = 1500;
        }else FireboltTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_kilrek(Creature *_Creature)
{
    return new mob_kilrekAI (_Creature);
}

CreatureAI* GetAI_mob_karazhan_imp(Creature *_Creature)
{
    return new mob_karazhan_impAI (_Creature);
}

CreatureAI* GetAI_mob_demon_chain(Creature *_Creature)
{
    return new mob_demon_chainAI(_Creature);
}

CreatureAI* GetAI_boss_terestian_illhoof(Creature *_Creature)
{
    return new boss_terestianAI (_Creature);
}

void AddSC_boss_terestian_illhoof()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_terestian_illhoof";
    newscript->GetAI = GetAI_boss_terestian_illhoof;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_karazhan_imp";
    newscript->GetAI = GetAI_mob_karazhan_imp;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_kilrek";
    newscript->GetAI = GetAI_mob_kilrek;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "mob_demon_chain";
    newscript->GetAI = GetAI_mob_demon_chain;
    m_scripts[nrscripts++] = newscript;
}
