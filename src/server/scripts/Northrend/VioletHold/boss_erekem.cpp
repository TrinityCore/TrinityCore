/*
 * Copyright (C) 2009 - 2010 Trinity <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_BLOODLUST                             = 54516,
    SPELL_BREAK_BONDS                           = 59463,
    SPELL_CHAIN_HEAL                            = 54481,
    H_SPELL_CHAIN_HEAL                          = 59473,
    SPELL_EARTH_SHIELD                          = 54479,
    H_SPELL_EARTH_SHIELD                        = 59471,
    SPELL_EARTH_SHOCK                           = 54511,
    SPELL_LIGHTNING_BOLT                        = 53044,
    SPELL_STORMSTRIKE                           = 51876
};

enum Yells
{
    SAY_AGGRO                                   = -1608010,
    SAY_SLAY_1                                  = -1608011,
    SAY_SLAY_2                                  = -1608012,
    SAY_SLAY_3                                  = -1608013,
    SAY_DEATH                                   = -1608014,
    SAY_SPAWN                                   = -1608015,
    SAY_ADD_KILLED                              = -1608016,
    SAY_BOTH_ADDS_KILLED                        = -1608017
};

struct boss_erekemAI : public ScriptedAI
{
    boss_erekemAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBloodlustTimer;
    uint32 uiChainHealTimer;
    uint32 uiEarthShockTimer;
    uint32 uiLightningBoltTimer;
    uint32 uiEarthShieldTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiBloodlustTimer = 15000;
        uiChainHealTimer = 0;
        uiEarthShockTimer = urand(2000,8000);
        uiLightningBoltTimer = urand(5000,10000);
        uiEarthShieldTimer = 20000;
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        if (Creature *pGuard1 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_1) : 0))
        {
            if (!pGuard1->isAlive())
                pGuard1->Respawn();
        }
        if (Creature *pGuard2 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_2) : 0))
        {
            if (!pGuard2->isAlive())
                pGuard2->Respawn();
        }
    }

    void AttackStart(Unit* pWho)
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (me->Attack(pWho, true))
        {
            me->AddThreat(pWho, 0.0f);
            me->SetInCombatWith(pWho);
            pWho->SetInCombatWith(me);
            DoStartMovement(pWho);

            if (Creature *pGuard1 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_1) : 0))
            {
                pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                if (!pGuard1->getVictim() && pGuard1->AI())
                    pGuard1->AI()->AttackStart(pWho);
            }
            if (Creature *pGuard2 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_2) : 0))
            {
                pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                if (!pGuard2->getVictim() && pGuard2->AI())
                    pGuard2->AI()->AttackStart(pWho);
            }
        }
    }

    void EnterCombat(Unit* /*pWho*/)
    {
        DoScriptText(SAY_AGGRO, me);
        DoCast(me, SPELL_EARTH_SHIELD);

        if (pInstance)
        {
            if (GameObject *pDoor = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_EREKEM_CELL)))
                if (pDoor->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }

    void MoveInLineOfSight(Unit* /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //spam stormstrike in hc mode if spawns are dead
        if (IsHeroic())
        {
            if (Creature *pGuard1 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_1) : 0))
            {
                if (Creature *pGuard2 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_2) : 0))
                {
                    if (!pGuard1->isAlive() && !pGuard2->isAlive())
                        DoCast(me->getVictim(), SPELL_STORMSTRIKE);
                }
            }
        }

        if (uiEarthShieldTimer <= diff)
        {
            DoCast(me, SPELL_EARTH_SHIELD);
            uiEarthShieldTimer = 20000;
        } else uiEarthShieldTimer -= diff;

        if (uiChainHealTimer <= diff)
        {
            if (uint64 TargetGUID = GetChainHealTargetGUID())
            {
                if (Creature *pTarget = Unit::GetCreature(*me, TargetGUID))
                    DoCast(pTarget, SPELL_CHAIN_HEAL);

                //If one of the adds is dead spawn heals faster
                Creature *pGuard1 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_1) : 0);
                Creature *pGuard2 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_2) : 0);
                uiChainHealTimer = ((pGuard1 && !pGuard1->isAlive()) || (pGuard2 && !pGuard2->isAlive()) ? 3000 : 8000) + rand()%3000;
            }
        } else uiChainHealTimer -= diff;

        if (uiBloodlustTimer <= diff)
        {
            DoCast(me, SPELL_BLOODLUST);
            uiBloodlustTimer = urand(35000,45000);
        } else uiBloodlustTimer -= diff;

        if (uiEarthShockTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_EARTH_SHOCK);
            uiEarthShockTimer = urand(8000,13000);
        } else uiEarthShockTimer -= diff;

        if (uiLightningBoltTimer <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_LIGHTNING_BOLT);
            uiLightningBoltTimer = urand(18000,24000);
        } else uiLightningBoltTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
            {
                pInstance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
            {
                pInstance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 13);
            }
        }
    }

    void KilledUnit(Unit * victim)
    {
        if (victim == me)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
    }

    uint64 GetChainHealTargetGUID()
    {
        if (HealthBelowPct(85))
            return me->GetGUID();

        Creature *pGuard1 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_1) : 0);
        if (pGuard1 && pGuard1->isAlive() && (pGuard1->GetHealth()*100 <= pGuard1->GetMaxHealth() * 75))
            return pGuard1->GetGUID();

        Creature *pGuard2 = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_EREKEM_GUARD_2) : 0);
        if (pGuard2 && pGuard2->isAlive() && (pGuard2->GetHealth()*100 <= pGuard2->GetMaxHealth() * 75))
            return pGuard2->GetGUID();

        return 0;
    }
};

CreatureAI* GetAI_boss_erekem(Creature* pCreature)
{
    return new boss_erekemAI (pCreature);
}

enum GuardSpells
{
    SPELL_GUSHING_WOUND                   = 39215,
    SPELL_HOWLING_SCREECH                 = 54462,
    SPELL_STRIKE                          = 14516
};

struct mob_erekem_guardAI : public ScriptedAI
{
    mob_erekem_guardAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiGushingWoundTimer;
    uint32 uiHowlingScreechTimer;
    uint32 uiStrikeTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiStrikeTimer = urand(4000,8000);
        uiHowlingScreechTimer = urand(8000,13000);
        uiGushingWoundTimer = urand(1000,3000);
    }

    void AttackStart(Unit* pWho)
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (me->Attack(pWho, true))
        {
            me->AddThreat(pWho, 0.0f);
            me->SetInCombatWith(pWho);
            pWho->SetInCombatWith(me);
            DoStartMovement(pWho);
        }
    }

    void MoveInLineOfSight(Unit* /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();

        if (uiStrikeTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_STRIKE);
            uiStrikeTimer = urand(4000,8000);
        } else uiStrikeTimer -= diff;

        if (uiHowlingScreechTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_HOWLING_SCREECH);
            uiHowlingScreechTimer = urand(8000,13000);
        } else uiHowlingScreechTimer -= diff;

        if (uiGushingWoundTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_GUSHING_WOUND);
            uiGushingWoundTimer = urand(7000,12000);
        } else uiGushingWoundTimer -= diff;
    }
};

CreatureAI* GetAI_mob_erekem_guard(Creature* pCreature)
{
    return new mob_erekem_guardAI (pCreature);
}

void AddSC_boss_erekem()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_erekem";
    newscript->GetAI = &GetAI_boss_erekem;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_erekem_guard";
    newscript->GetAI = &GetAI_mob_erekem_guard;
    newscript->RegisterSelf();
}
