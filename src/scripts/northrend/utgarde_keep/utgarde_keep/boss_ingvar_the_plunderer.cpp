/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Ingvar_The_Plunderer
SD%Complete: 95
SDComment: Some Problems with Annhylde Movement, Blizzlike Timers
SDCategory: Udgarde Keep
EndScriptData */

#include "ScriptedPch.h"
#include "utgarde_keep.h"

enum Yells
{
    //Yells Ingvar
    YELL_AGGRO_1                                = -1574005,
    YELL_AGGRO_2                                = -1574006,

    YELL_DEAD_1                                 = -1574007,
    YELL_DEAD_2                                 = -1574008,

    YELL_KILL_1                                 = -1574009,
    YELL_KILL_2                                 = -1574010,
};

enum Creatures
{
    MOB_INGVAR_HUMAN                            = 23954,
    MOB_ANNHYLDE_THE_CALLER                     = 24068,
    MOB_INGVAR_UNDEAD                           = 23980,
};

enum Spells
{
    //Ingvar Spells human form
    SPELL_CLEAVE                                = 42724,
    SPELL_SMASH                                 = 42669,
    H_SPELL_SMASH                               = 59706,
    SPELL_STAGGERING_ROAR                       = 42708,
    H_SPELL_STAGGERING_ROAR                     = 59708,
    SPELL_ENRAGE                                = 42705,
    H_SPELL_ENRAGE                              = 59707,

    SPELL_INGVAR_FEIGN_DEATH                    = 42795,
    SPELL_SUMMON_BANSHEE                        = 42912,
    SPELL_SCOURG_RESURRECTION                   = 42863, // Spawn resurrect effect around Ingvar

    //Ingvar Spells undead form
    SPELL_DARK_SMASH                            = 42723,
    SPELL_DREADFUL_ROAR                         = 42729,
    H_SPELL_DREADFUL_ROAR                       = 59734,
    SPELL_WOE_STRIKE                            = 42730,
    H_SPELL_WOE_STRIKE                          = 59735,

    ENTRY_THROW_TARGET                          = 23996,
    SPELL_SHADOW_AXE_SUMMON                     = 42749
};

struct boss_ingvar_the_plundererAI : public ScriptedAI
{
    boss_ingvar_the_plundererAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool bIsUndead;
    bool bEventInProgress;

    uint32 uiCleaveTimer;
    uint32 uiSmashTimer;
    uint32 uiEnrageTimer;
    uint32 uiRoarTimer;
    uint32 uiSpawnResTimer;

    void Reset()
    {
        if (bIsUndead)
            m_creature->UpdateEntry(MOB_INGVAR_HUMAN);

        bIsUndead = false;
        bEventInProgress = false;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        uiCleaveTimer = 2000;
        uiSmashTimer = 5000;
        uiEnrageTimer = 10000;
        uiRoarTimer = 15000;

        uiSpawnResTimer = 3000;

        if (pInstance)
            pInstance->SetData(DATA_INGVAR_EVENT, NOT_STARTED);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (damage >= m_creature->GetHealth() && !bIsUndead)
        {
            //DoCast(m_creature, SPELL_INGVAR_FEIGN_DEATH, true);  // Dont work ???
            // visuel hack
            m_creature->SetHealth(0);
            m_creature->InterruptNonMeleeSpells(true);
            m_creature->RemoveAllAuras();
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            m_creature->GetMotionMaster()->MovementExpired(false);
            m_creature->GetMotionMaster()->MoveIdle();
            m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
            // visuel hack end

            bEventInProgress = true;
            bIsUndead = true;

            DoScriptText(YELL_DEAD_1,m_creature);
        }

        if (bEventInProgress)
        {
            damage = 0;
        }
    }

    void StartZombiePhase()
    {
        bIsUndead = true;
        bEventInProgress = false;
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->UpdateEntry(MOB_INGVAR_UNDEAD);
        m_creature->SetInCombatWith(m_creature->getVictim());
        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());

        DoScriptText(YELL_AGGRO_2,m_creature);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(YELL_AGGRO_1,m_creature);

        if (pInstance)
            pInstance->SetData(DATA_INGVAR_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(YELL_DEAD_2,m_creature);

        if (pInstance)
            pInstance->SetData(DATA_INGVAR_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (bIsUndead)
            DoScriptText(YELL_KILL_1,m_creature);
        else
            DoScriptText(YELL_KILL_2,m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (bEventInProgress)
        {
            if (uiSpawnResTimer)
                if (uiSpawnResTimer <= diff)
                {
                    DoCast(m_creature, SPELL_SUMMON_BANSHEE); // Summons directly on caster position
                    // DoCast(m_creature, SPELL_SCOURG_RESURRECTION, true); // Not needed ?
                    uiSpawnResTimer = 0;
                } else uiSpawnResTimer -= diff;

            return;
        }

        if (uiCleaveTimer <= diff)
        {
            if (!m_creature->hasUnitState(UNIT_STAT_CASTING))
            {
                if (bIsUndead)
                    DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_WOE_STRIKE, H_SPELL_WOE_STRIKE));
                else
                    DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                uiCleaveTimer = rand()%5000 + 2000;
            }
        } else uiCleaveTimer -= diff;

        if (uiSmashTimer <= diff)
        {
            if (!m_creature->hasUnitState(UNIT_STAT_CASTING))
            {
                if (bIsUndead)
                    DoCast(m_creature->getVictim(), SPELL_DARK_SMASH);
                else
                    DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_SMASH, H_SPELL_SMASH));
                uiSmashTimer = 10000;
            }
        } else uiSmashTimer -= diff;

        if (!bIsUndead)
        {
            if (uiEnrageTimer <= diff)
            {
                DoCast(m_creature, DUNGEON_MODE(SPELL_ENRAGE, H_SPELL_ENRAGE));
                uiEnrageTimer = 10000;
            } else uiEnrageTimer -= diff;
        } else // In Undead form used to summon weapon
        {
            if (uiEnrageTimer <= diff)
            {
                if (!m_creature->hasUnitState(UNIT_STAT_CASTING))
                {
                    // Spawn target for Axe
                    Unit *pTarget = SelectUnit(SELECT_TARGET_TOPAGGRO, 1);
                    if (pTarget)
                    {
                        Creature* temp = m_creature->SummonCreature(ENTRY_THROW_TARGET,pTarget->GetPositionX(),pTarget->GetPositionY(),pTarget->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,2000);

                        DoCast(m_creature, SPELL_SHADOW_AXE_SUMMON);
                    }
                    uiEnrageTimer = 30000;
                }
            } else uiEnrageTimer -= diff;
        }

        if (uiRoarTimer <= diff)
        {
            if (!m_creature->hasUnitState(UNIT_STAT_CASTING))
            {
                if (bIsUndead)
                    DoCast(m_creature, DUNGEON_MODE(SPELL_DREADFUL_ROAR, H_SPELL_DREADFUL_ROAR));
                else
                    DoCast(m_creature, DUNGEON_MODE(SPELL_STAGGERING_ROAR, H_SPELL_STAGGERING_ROAR));
                uiRoarTimer = 10000;
            }
        } else uiRoarTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ingvar_the_plunderer(Creature* pCreature)
{
    return new boss_ingvar_the_plundererAI(pCreature);
}

enum eSpells
{
//we don't have that text in db so comment it until we get this text
//    YELL_RESSURECT                      = -1574025,

//Spells for Annhylde
    SPELL_SCOURG_RESURRECTION_HEAL              = 42704, //Heal Max + DummyAura
    SPELL_SCOURG_RESURRECTION_BEAM              = 42857, //Channeling Beam of Annhylde
    SPELL_SCOURG_RESURRECTION_DUMMY             = 42862, //Some Emote Dummy?
    SPELL_INGVAR_TRANSFORM                      = 42796
};

struct mob_annhylde_the_callerAI : public ScriptedAI
{
    mob_annhylde_the_callerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    float x,y,z;
    ScriptedInstance* pInstance;
    uint32 uiResurectTimer;
    uint32 uiResurectPhase;

    void Reset()
    {
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_HOVER);
        m_creature->SetSpeed(MOVE_SWIM , 1.0f);
        m_creature->SetSpeed(MOVE_RUN , 1.0f);
        m_creature->SetSpeed(MOVE_WALK , 1.0f);
        //m_creature->SetSpeed(MOVE_FLIGHT , 1.0f);

        m_creature->GetPosition(x,y,z);
        DoTeleportTo(x+1,y,z+30);

        Unit* ingvar = Unit::GetUnit(*m_creature, pInstance ? pInstance->GetData64(DATA_INGVAR) : 0);
        if (ingvar)
        {
            m_creature->GetMotionMaster()->MovePoint(1,x,y,z+15);

//            DoScriptText(YELL_RESSURECT,m_creature);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;
        Unit* ingvar = Unit::GetUnit((*m_creature), pInstance ? pInstance->GetData64(DATA_INGVAR) : 0);
        if (ingvar)
        {
            switch (id)
            {
            case 1:
                ingvar->RemoveAura(SPELL_SUMMON_BANSHEE);
                ingvar->CastSpell(ingvar,SPELL_SCOURG_RESURRECTION_DUMMY,true);
                DoCast(ingvar, SPELL_SCOURG_RESURRECTION_BEAM);
                uiResurectTimer = 8000;
                uiResurectPhase = 1;
                break;
            case 2:
                m_creature->SetVisibility(VISIBILITY_OFF);
                m_creature->DealDamage(m_creature,m_creature->GetHealth());
                m_creature->RemoveCorpse();
                break;
            }
        }
    }

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void EnterCombat(Unit *who) {}
    void UpdateAI(const uint32 diff)
    {
        if (uiResurectTimer)
            if (uiResurectTimer <= diff)
            {
                if (uiResurectPhase == 1)
                {
                    Unit* ingvar = Unit::GetUnit(*m_creature, pInstance ? pInstance->GetData64(DATA_INGVAR) : 0);
                    if (ingvar)
                    {
                        ingvar->SetStandState(UNIT_STAND_STATE_STAND);
                        ingvar->CastSpell(ingvar,SPELL_SCOURG_RESURRECTION_HEAL,false);
                    }
                    uiResurectTimer = 3000;
                    uiResurectPhase = 2;
                }
                else if (uiResurectPhase == 2)
                {
                    if (Creature* ingvar = Unit::GetCreature(*m_creature, pInstance ? pInstance->GetData64(DATA_INGVAR) : 0))
                    {
                        ingvar->RemoveAurasDueToSpell(SPELL_SCOURG_RESURRECTION_DUMMY);

                        if (boss_ingvar_the_plundererAI* pAI = CAST_AI(boss_ingvar_the_plundererAI, ingvar->AI()))
                            pAI->StartZombiePhase();

                        m_creature->GetMotionMaster()->MovePoint(2,x+1,y,z+30);
                        ++uiResurectPhase;
                        uiResurectTimer = 0;
                    }
                }

            } else uiResurectTimer -= diff;
    }
};

CreatureAI* GetAI_mob_annhylde_the_caller(Creature* pCreature)
{
    return new mob_annhylde_the_callerAI (pCreature);
}

enum eShadowAxe
{
    SPELL_SHADOW_AXE_DAMAGE                     = 42750,
    H_SPELL_SHADOW_AXE_DAMAGE                   = 59719
};

struct mob_ingvar_throw_dummyAI : public ScriptedAI
{
    mob_ingvar_throw_dummyAI(Creature *c) : ScriptedAI(c)
    {
    }

    uint32 uiDespawnTimer;

    void Reset()
    {
        Unit *pTarget = m_creature->FindNearestCreature(ENTRY_THROW_TARGET,50);
        if (pTarget)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_SHADOW_AXE_DAMAGE, H_SPELL_SHADOW_AXE_DAMAGE));
            float x,y,z;
            pTarget->GetPosition(x,y,z);
            m_creature->GetMotionMaster()->MovePoint(0,x,y,z);
        }
        uiDespawnTimer = 7000;
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void EnterCombat(Unit *who) {}
    void UpdateAI(const uint32 diff)
    {
        if (uiDespawnTimer <= diff)
        {
            m_creature->DealDamage(m_creature,m_creature->GetHealth());
            m_creature->RemoveCorpse();
            uiDespawnTimer = 0;
        } else uiDespawnTimer -= diff;
    }
};

CreatureAI* GetAI_mob_ingvar_throw_dummy(Creature* pCreature)
{
    return new mob_ingvar_throw_dummyAI (pCreature);
}

void AddSC_boss_ingvar_the_plunderer()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_ingvar_the_plunderer";
    newscript->GetAI = &GetAI_boss_ingvar_the_plunderer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_annhylde_the_caller";
    newscript->GetAI = &GetAI_mob_annhylde_the_caller;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ingvar_throw_dummy";
    newscript->GetAI = &GetAI_mob_ingvar_throw_dummy;
    newscript->RegisterSelf();
}
