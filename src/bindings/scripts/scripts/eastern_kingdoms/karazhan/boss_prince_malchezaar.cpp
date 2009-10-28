/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Prince_Malchezzar
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"
#include "karazhan.h"

#define SAY_AGGRO           -1532091
#define SAY_AXE_TOSS1       -1532092
#define SAY_AXE_TOSS2       -1532093
#define SAY_SPECIAL1        -1532094
#define SAY_SPECIAL2        -1532095
#define SAY_SPECIAL3        -1532096
#define SAY_SLAY1           -1532097
#define SAY_SLAY2           -1532098
#define SAY_SLAY3           -1532099
#define SAY_SUMMON1         -1532100
#define SAY_SUMMON2         -1532101
#define SAY_DEATH           -1532102

// 18 Coordinates for Infernal spawns
struct InfernalPoint
{
    float x,y;
};

#define INFERNAL_Z  275.5

static InfernalPoint InfernalPoints[] =
{
    {-10922.8, -1985.2},
    {-10916.2, -1996.2},
    {-10932.2, -2008.1},
    {-10948.8, -2022.1},
    {-10958.7, -1997.7},
    {-10971.5, -1997.5},
    {-10990.8, -1995.1},
    {-10989.8, -1976.5},
    {-10971.6, -1973.0},
    {-10955.5, -1974.0},
    {-10939.6, -1969.8},
    {-10958.0, -1952.2},
    {-10941.7, -1954.8},
    {-10943.1, -1988.5},
    {-10948.8, -2005.1},
    {-10984.0, -2019.3},
    {-10932.8, -1979.6},
    {-10935.7, -1996.0}
};

#define TOTAL_INFERNAL_POINTS       18

//Enfeeble is supposed to reduce hp to 1 and then heal player back to full when it ends
//Along with reducing healing and regen while enfeebled to 0%
//This spell effect will only reduce healing

#define SPELL_ENFEEBLE              30843                       //Enfeeble during phase 1 and 2
#define SPELL_ENFEEBLE_EFFECT       41624

#define SPELL_SHADOWNOVA            30852                       //Shadownova used during all phases
#define SPELL_SW_PAIN               30854                       //Shadow word pain during phase 1 and 3 (different targeting rules though)
#define SPELL_THRASH_PASSIVE        12787                       //Extra attack chance during phase 2
#define SPELL_SUNDER_ARMOR          30901                       //Sunder armor during phase 2
#define SPELL_THRASH_AURA           12787                       //Passive proc chance for thrash
#define SPELL_EQUIP_AXES            30857                       //Visual for axe equiping
#define SPELL_AMPLIFY_DAMAGE        39095                       //Amplifiy during phase 3
#define SPELL_CLEAVE                30131                       //Same as Nightbane.
#define SPELL_HELLFIRE              30859                       //Infenals' hellfire aura
#define NETHERSPITE_INFERNAL        17646                       //The netherspite infernal creature
#define MALCHEZARS_AXE              17650                       //Malchezar's axes (creatures), summoned during phase 3

#define INFERNAL_MODEL_INVISIBLE    11686                      //Infernal Effects
#define SPELL_INFERNAL_RELAY        30834

#define EQUIP_ID_AXE                33542                      //Axes info

//---------Infernal code first
struct TRINITY_DLL_DECL netherspite_infernalAI : public ScriptedAI
{
    netherspite_infernalAI(Creature *c) : ScriptedAI(c) ,
        malchezaar(0), HellfireTimer(0), CleanupTimer(0), point(NULL) {}

    uint32 HellfireTimer;
    uint32 CleanupTimer;
    uint32 malchezaar;
    InfernalPoint *point;

    void Reset() {}
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (HellfireTimer)
            if (HellfireTimer <= diff)
        {
            DoCast(m_creature, SPELL_HELLFIRE);
            HellfireTimer = 0;
        }
        else HellfireTimer -= diff;

        if (CleanupTimer)
            if (CleanupTimer <= diff)
        {
            Cleanup();
            CleanupTimer = 0;
        } else CleanupTimer -= diff;
    }

    void KilledUnit(Unit *who)
    {
        Unit *pMalchezaar = Unit::GetUnit(*m_creature, malchezaar);
        if (pMalchezaar)
            CAST_CRE(pMalchezaar)->AI()->KilledUnit(who);
    }

    void SpellHit(Unit *who, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_INFERNAL_RELAY)
        {
            m_creature->SetDisplayId(m_creature->GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID));
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            HellfireTimer = 4000;
            CleanupTimer = 170000;
        }
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by->GetGUID() != malchezaar)
            damage = 0;
    }

    void Cleanup();                                         //below ...
};

struct TRINITY_DLL_DECL boss_malchezaarAI : public ScriptedAI
{
    boss_malchezaarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    uint32 EnfeebleTimer;
    uint32 EnfeebleResetTimer;
    uint32 ShadowNovaTimer;
    uint32 SWPainTimer;
    uint32 SunderArmorTimer;
    uint32 AmplifyDamageTimer;
    uint32 Cleave_Timer;
    uint32 InfernalTimer;
    uint32 AxesTargetSwitchTimer;
    uint32 InfernalCleanupTimer;

    std::vector<uint64> infernals;
    std::vector<InfernalPoint*> positions;

    uint64 axes[2];
    uint64 enfeeble_targets[5];
    uint64 enfeeble_health[5];

    uint32 phase;

    void Reset()
    {
        AxesCleanup();
        ClearWeapons();
        InfernalCleanup();
        positions.clear();

        for (uint8 i =0; i < 5; ++i)
            enfeeble_targets[i] = 0;

        for (uint8 i = 0; i < TOTAL_INFERNAL_POINTS; ++i)
            positions.push_back(&InfernalPoints[i]);

        EnfeebleTimer = 30000;
        EnfeebleResetTimer = 38000;
        ShadowNovaTimer = 35500;
        SWPainTimer = 20000;
        AmplifyDamageTimer = 5000;
        Cleave_Timer = 8000;
        InfernalTimer = 45000;
        InfernalCleanupTimer = 47000;
        AxesTargetSwitchTimer = 7500 + rand()%12500;
        SunderArmorTimer = 5000 + rand()%5000;
        phase = 1;

        if (pInstance)
            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_NETHER_DOOR), true);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2,SAY_SLAY3), m_creature);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        AxesCleanup();
        ClearWeapons();
        InfernalCleanup();
        positions.clear();

        for (uint8 i = 0; i < TOTAL_INFERNAL_POINTS; ++i)
            positions.push_back(&InfernalPoints[i]);

        if (pInstance)
            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_NETHER_DOOR), true);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_NETHER_DOOR), false); // Open the door leading further in
    }

    void InfernalCleanup()
    {
        //Infernal Cleanup
        for (std::vector<uint64>::iterator itr = infernals.begin(); itr!= infernals.end(); ++itr)
        {
            Unit *pInfernal = Unit::GetUnit(*m_creature, *itr);
            if (pInfernal && pInfernal->isAlive())
            {
                pInfernal->SetVisibility(VISIBILITY_OFF);
                pInfernal->setDeathState(JUST_DIED);
            }
        }
        infernals.clear();
    }

    void AxesCleanup()
    {
        for (uint8 i=0; i<2; ++i)
        {
            Unit *axe = Unit::GetUnit(*m_creature, axes[i]);
            if (axe && axe->isAlive())
                axe->Kill(axe);
            axes[i] = 0;
        }
    }

    void ClearWeapons()
    {
        SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);

        //damage
        const CreatureInfo *cinfo = m_creature->GetCreatureInfo();
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, cinfo->mindmg);
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, cinfo->maxdmg);
        m_creature->UpdateDamagePhysical(BASE_ATTACK);
    }

    void EnfeebleHealthEffect()
    {
        const SpellEntry *info = GetSpellStore()->LookupEntry(SPELL_ENFEEBLE_EFFECT);
        if (!info)
            return;

        std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
        std::vector<Unit *> targets;

        if (!t_list.size())
            return;

        //begin + 1 , so we don't pTarget the one with the highest threat
        std::list<HostilReference *>::iterator itr = t_list.begin();
        std::advance(itr, 1);
        for (; itr!= t_list.end(); ++itr)                   //store the threat list in a different container
        {
            Unit *pTarget = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                                                            //only on alive players
            if (pTarget && pTarget->isAlive() && pTarget->GetTypeId() == TYPEID_PLAYER)
                targets.push_back(pTarget);
        }

        //cut down to size if we have more than 5 targets
        while(targets.size() > 5)
            targets.erase(targets.begin()+rand()%targets.size());

        int i = 0;
        for (std::vector<Unit *>::iterator iter = targets.begin(); iter!= targets.end(); ++iter, ++i)
        {
            Unit *pTarget = *iter;
            if (pTarget)
            {
                enfeeble_targets[i] = pTarget->GetGUID();
                enfeeble_health[i] = pTarget->GetHealth();

                pTarget->CastSpell(pTarget, SPELL_ENFEEBLE, true, 0, 0, m_creature->GetGUID());
                pTarget->SetHealth(1);
            }
        }

    }

    void EnfeebleResetHealth()
    {
        for (uint8 i = 0; i < 5; ++i)
        {
            Unit *pTarget = Unit::GetUnit(*m_creature, enfeeble_targets[i]);
            if (pTarget && pTarget->isAlive())
                pTarget->SetHealth(enfeeble_health[i]);
            enfeeble_targets[i] = 0;
            enfeeble_health[i] = 0;
        }
    }

    void SummonInfernal(const uint32 diff)
    {
        InfernalPoint *point = NULL;
        Position pos;
        if ((m_creature->GetMapId() != 532) || positions.empty())
            me->GetRandomNearPosition(pos, 60);
        else
        {
            std::vector<InfernalPoint*>::iterator itr = positions.begin()+rand()%positions.size();
            point = *itr;
            positions.erase(itr);
            pos.Relocate(point->x, point->y, INFERNAL_Z);
        }

        Creature *Infernal = m_creature->SummonCreature(NETHERSPITE_INFERNAL, pos, TEMPSUMMON_TIMED_DESPAWN, 180000);

        if (Infernal)
        {
            Infernal->SetDisplayId(INFERNAL_MODEL_INVISIBLE);
            Infernal->setFaction(m_creature->getFaction());
            if (point)
                CAST_AI(netherspite_infernalAI, Infernal->AI())->point=point;
            CAST_AI(netherspite_infernalAI, Infernal->AI())->malchezaar=m_creature->GetGUID();

            infernals.push_back(Infernal->GetGUID());
            DoCast(Infernal, SPELL_INFERNAL_RELAY);
        }

        DoScriptText(RAND(SAY_SUMMON1,SAY_SUMMON2), m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (EnfeebleResetTimer)
            if (EnfeebleResetTimer <= diff)                  //Let's not forget to reset that
        {
            EnfeebleResetHealth();
            EnfeebleResetTimer=0;
        } else EnfeebleResetTimer -= diff;

        if (m_creature->hasUnitState(UNIT_STAT_STUNNED))     //While shifting to phase 2 malchezaar stuns himself
            return;

        if (m_creature->GetUInt64Value(UNIT_FIELD_TARGET)!=m_creature->getVictim()->GetGUID())
            m_creature->SetUInt64Value(UNIT_FIELD_TARGET, m_creature->getVictim()->GetGUID());

        if (phase == 1)
        {
            if ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 60)
            {
                m_creature->InterruptNonMeleeSpells(false);

                phase = 2;

                //animation
                DoCast(m_creature, SPELL_EQUIP_AXES);

                //text
                DoScriptText(SAY_AXE_TOSS1, m_creature);

                //passive thrash aura
                m_creature->CastSpell(m_creature, SPELL_THRASH_AURA, true);

                //models
                SetEquipmentSlots(false, EQUIP_ID_AXE, EQUIP_ID_AXE, EQUIP_NO_CHANGE);

                //damage
                const CreatureInfo *cinfo = m_creature->GetCreatureInfo();
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, 2*cinfo->mindmg);
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, 2*cinfo->maxdmg);
                m_creature->UpdateDamagePhysical(BASE_ATTACK);

                m_creature->SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, cinfo->mindmg);
                m_creature->SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, cinfo->maxdmg);
                //Sigh, updating only works on main attack, do it manually ....
                m_creature->SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, cinfo->mindmg);
                m_creature->SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, cinfo->maxdmg);

                m_creature->SetAttackTime(OFF_ATTACK, (m_creature->GetAttackTime(BASE_ATTACK)*150)/100);
            }
        }
        else if (phase == 2)
        {
            if ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 30)
            {
                InfernalTimer = 15000;

                phase = 3;

                ClearWeapons();

                //remove thrash
                m_creature->RemoveAurasDueToSpell(SPELL_THRASH_AURA);

                DoScriptText(SAY_AXE_TOSS2, m_creature);

                Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                for (uint8 i = 0; i < 2; ++i)
                {
                    Creature *axe = m_creature->SummonCreature(MALCHEZARS_AXE, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
                    if (axe)
                    {
                        axe->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        axe->setFaction(m_creature->getFaction());
                        axes[i] = axe->GetGUID();
                        if (pTarget)
                        {
                            axe->AI()->AttackStart(pTarget);
                            // axe->getThreatManager().tauntApply(pTarget); //Taunt Apply and fade out does not work properly
                                                            // So we'll use a hack to add a lot of threat to our target
                            axe->AddThreat(pTarget, 10000000.0f);
                        }
                    }
                }

                if (ShadowNovaTimer > 35000)
                    ShadowNovaTimer = EnfeebleTimer + 5000;

                return;
            }

            if (SunderArmorTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_SUNDER_ARMOR);
                SunderArmorTimer = urand(10000,18000);

            } else SunderArmorTimer -= diff;

            if (Cleave_Timer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = urand(6000,12000);

            } else Cleave_Timer -= diff;
        }
        else
        {
            if (AxesTargetSwitchTimer <= diff)
            {
                AxesTargetSwitchTimer = urand(7500,20000);

                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    for (uint8 i = 0; i < 2; ++i)
                    {
                        if (Unit *axe = Unit::GetUnit(*m_creature, axes[i]))
                        {
                            float threat = 1000000.0f;
                            if (axe->getVictim())
                                DoModifyThreatPercent(axe->getVictim(), -100);
                            if (pTarget)
                                axe->AddThreat(pTarget, threat);
                            //axe->getThreatManager().tauntFadeOut(axe->getVictim());
                            //axe->getThreatManager().tauntApply(pTarget);
                        }
                    }
                }
            } else AxesTargetSwitchTimer -= diff;

            if (AmplifyDamageTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_AMPLIFY_DAMAGE);
                AmplifyDamageTimer = urand(20000,30000);
            } else AmplifyDamageTimer -= diff;
        }

        //Time for global and double timers
        if (InfernalTimer <= diff)
        {
            SummonInfernal(diff);
            InfernalTimer = phase == 3 ? 14500 : 44500;    //15 secs in phase 3, 45 otherwise
        } else InfernalTimer -= diff;

        if (ShadowNovaTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOWNOVA);
            ShadowNovaTimer = phase == 3 ? 31000 : 4294967295;
        } else ShadowNovaTimer -= diff;

        if (phase != 2)
        {
            if (SWPainTimer <= diff)
            {
                Unit *pTarget = NULL;
                if (phase == 1)
                    pTarget = m_creature->getVictim();        // the tank
                else                                         // anyone but the tank
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);

                if (pTarget)
                    DoCast(pTarget, SPELL_SW_PAIN);

                SWPainTimer = 20000;
            } else SWPainTimer -= diff;
        }

        if (phase != 3)
        {
            if (EnfeebleTimer <= diff)
            {
                EnfeebleHealthEffect();
                EnfeebleTimer = 30000;
                ShadowNovaTimer = 5000;
                EnfeebleResetTimer = 9000;
            } else EnfeebleTimer -= diff;
        }

        if (phase == 2)
            DoMeleeAttacksIfReady();
        else
            DoMeleeAttackIfReady();
    }

    void DoMeleeAttacksIfReady()
    {
        if (m_creature->IsWithinMeleeRange(m_creature->getVictim()) && !m_creature->IsNonMeleeSpellCasted(false))
        {
            //Check for base attack
            if (m_creature->isAttackReady() && m_creature->getVictim())
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
            //Check for offhand attack
            if (m_creature->isAttackReady(OFF_ATTACK) && m_creature->getVictim())
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim(), OFF_ATTACK);
                m_creature->resetAttackTimer(OFF_ATTACK);
            }
        }
    }

    void Cleanup(Creature *infernal, InfernalPoint *point)
    {
        for (std::vector<uint64>::iterator itr = infernals.begin(); itr!= infernals.end(); ++itr)
            if (*itr == infernal->GetGUID())
        {
            infernals.erase(itr);
            break;
        }

        positions.push_back(point);
    }
};

void netherspite_infernalAI::Cleanup()
{
    Unit *pMalchezaar = Unit::GetUnit(*m_creature, malchezaar);

    if (pMalchezaar && pMalchezaar->isAlive())
        CAST_AI(boss_malchezaarAI, CAST_CRE(pMalchezaar)->AI())->Cleanup(m_creature, point);
}

CreatureAI* GetAI_netherspite_infernal(Creature* pCreature)
{
    return new netherspite_infernalAI (pCreature);
}

CreatureAI* GetAI_boss_malchezaar(Creature* pCreature)
{
    return new boss_malchezaarAI (pCreature);
}

void AddSC_boss_malchezaar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_malchezaar";
    newscript->GetAI = &GetAI_boss_malchezaar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "netherspite_infernal";
    newscript->GetAI = &GetAI_netherspite_infernal;
    newscript->RegisterSelf();
}

