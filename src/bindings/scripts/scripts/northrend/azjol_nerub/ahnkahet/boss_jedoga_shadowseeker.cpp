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
SDName: boss_jedoga_shadowseeker
SDAuthor: WarHead
SD%Complete: 100%
SDComment: Complete - BUT THE TRIGGER NEEDS DATA WHETHER THE PRISON OF TALDARAM IS OFFLINE !
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "ahnkahet.h"

enum Yells
{
    TEXT_AGGRO          = -1619000,
    TEXT_SACRIFICE_1_1  = -1619001,
    TEXT_SACRIFICE_1_2  = -1619002,
    TEXT_SACRIFICE_2_1  = -1619003,
    TEXT_SACRIFICE_2_2  = -1619004,
    TEXT_SLAY_1         = -1619005,
    TEXT_SLAY_2         = -1619006,
    TEXT_SLAY_3         = -1619007,
    TEXT_DEATH          = -1619008,
    TEXT_PREACHING_1    = -1619009,
    TEXT_PREACHING_2    = -1619010,
    TEXT_PREACHING_3    = -1619011,
    TEXT_PREACHING_4    = -1619012,
    TEXT_PREACHING_5    = -1619013
};

enum Spells
{
    SPELL_SPHERE_VISUAL         = 56075,
    SPELL_GIFT_OF_THE_HERALD    = 56219,
    SPELL_CYCLONE_STRIKE        = 56855, // Self
    SPELL_CYCLONE_STRIKE_H      = 60030,
    SPELL_LIGHTNING_BOLT        = 56891, // 40Y
    SPELL_LIGHTNING_BOLT_H      = 60032, // 40Y
    SPELL_THUNDERSHOCK          = 56926, // 30Y
    SPELL_THUNDERSHOCK_H        = 60029 // 30Y
};

float JEDOGA_POS[2][4] =
{
    {372.330994f, -705.278015f, -0.624178f, 5.427970f},
    {372.330994f, -705.278015f, -16.179716f, 5.427970f}
};

struct MANGOS_DLL_DECL boss_jedoga_shadowseekerAI : public ScriptedAI
{
    boss_jedoga_shadowseekerAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        FirstTime = true;
        predone = false;
    }

    ScriptedInstance* pInstance;

    uint32 uiOpFerTimer,
        uiCycloneTimer,
        uiBoltTimer,
        uiThunderTimer;

    bool predone,
        bOpFerok,
        bOnGround,
        bOpFerokFail,
        bCanDown;

    bool FirstTime;

    void Reset()
    {
        uiOpFerTimer = urand(15000,20000);

        uiCycloneTimer = 3000;
        uiBoltTimer = 7000;
        uiThunderTimer = 12000;

        bOpFerok = false;
        bOpFerokFail = false;
        bOnGround = false;
        bCanDown = false;

        if (pInstance)
        {
            if (!FirstTime)
                pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, FAIL);

            pInstance->SetData64(DATA_PL_JEDOGA_TARGET, 0);
            pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);
            pInstance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
        }
        MoveUp();

        FirstTime = false;
    }

    void EnterCombat(Unit* who)
    {
        if (!pInstance || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == 30181))
            return;

        DoScriptText(TEXT_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
        pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, IN_PROGRESS);
    }

    void AttackStart(Unit* who)
    {
        if (!who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == 30181))
            return;

        ScriptedAI::AttackStart(who);
    }

    void KilledUnit(Unit* Victim)
    {
        if (!Victim || Victim->GetTypeId() != TYPEID_PLAYER)
		    return;

        DoScriptText(RAND(TEXT_SLAY_1, TEXT_SLAY_2, TEXT_SLAY_3), m_creature);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(TEXT_DEATH, m_creature);
        if (pInstance)
            pInstance->SetData(DATA_JEDOGA_SHADOWSEEKER_EVENT, DONE);
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (!pInstance || !who || (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == 30181))
            return;

        if (!predone && who->GetTypeId() == TYPEID_PLAYER && m_creature->GetDistance(who) < 100.0f)
        {
            DoScriptText(RAND(TEXT_PREACHING_1, TEXT_PREACHING_2, TEXT_PREACHING_3, TEXT_PREACHING_4, TEXT_PREACHING_5), m_creature);
            predone = true;
        }

        if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS || !bOnGround)
            return;

        if (!m_creature->getVictim() && who->isTargetableForAttack() && m_creature->IsHostileTo(who) && who->isInAccessiblePlaceFor(m_creature))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if (!m_creature->getVictim())
                {
                    who->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                    AttackStart(who);
                }
                else if (m_creature->GetMap()->IsDungeon())
                {
                    who->SetInCombatWith(m_creature);
                    m_creature->AddThreat(who, 0.0f);
                }
            }
        }
    }

    void MoveDown()
    {
        if (!pInstance)
            return;

        bOpFerokFail = false;

        pInstance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 0);
        m_creature->GetMotionMaster()->MovePoint(1, JEDOGA_POS[1][0], JEDOGA_POS[1][1], JEDOGA_POS[1][2]);

        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
        m_creature->SendMonsterMove(JEDOGA_POS[1][0], JEDOGA_POS[1][1], JEDOGA_POS[1][2], 0, MOVEFLAG_JUMP, 0);
        m_creature->Relocate(JEDOGA_POS[1][0], JEDOGA_POS[1][1], JEDOGA_POS[1][2], JEDOGA_POS[1][3]);
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_WALK_MODE);

        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

        m_creature->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);

        bOnGround = true;

        if (UpdateVictim())
        {
            AttackStart(m_creature->getVictim());
            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }
        else
        {
            if (Unit* pTarget = Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_PL_JEDOGA_TARGET)))
            {
                AttackStart(pTarget);
                pInstance->SetData(DATA_JEDOGA_RESET_INITIANDS, 0);
                if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS)
                    EnterCombat(pTarget);
            }
            else if (!m_creature->isInCombat())
                EnterEvadeMode();
        }
    }

    void MoveUp()
    {
        if (!pInstance)
            return;

        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

        m_creature->AttackStop();
        m_creature->RemoveAllAuras();
        m_creature->LoadCreaturesAddon();
        m_creature->GetMotionMaster()->MovePoint(0, JEDOGA_POS[0][0], JEDOGA_POS[0][1], JEDOGA_POS[0][2]);

        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
        m_creature->SendMonsterMove(JEDOGA_POS[0][0], JEDOGA_POS[0][1], JEDOGA_POS[0][2], 0, MOVEFLAG_JUMP, 0);
        m_creature->Relocate(JEDOGA_POS[0][0], JEDOGA_POS[0][1], JEDOGA_POS[0][2], JEDOGA_POS[0][3]);
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->StopMoving();

        pInstance->SetData(DATA_JEDOGA_TRIGGER_SWITCH, 1);
        if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) OpferRufen();

        bOnGround = false;
        uiOpFerTimer = urand(15000,30000);
    }

    void OpferRufen()
    {
        if (!pInstance)
            return;

        uint64 opfer = pInstance->GetData64(DATA_ADD_JEDOGA_INITIAND);

        if (opfer)
        {
            DoScriptText(RAND(TEXT_SACRIFICE_1_1, TEXT_SACRIFICE_1_2), m_creature);
            pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, opfer);
        } else
            bCanDown = true;
    }

    void Opfern()
    {
        DoScriptText(RAND(TEXT_SACRIFICE_2_1, TEXT_SACRIFICE_2_2), m_creature);

        m_creature->InterruptNonMeleeSpells(false);
        m_creature->CastSpell(m_creature, SPELL_GIFT_OF_THE_HERALD, false);

        bOpFerok = false;
        bCanDown = true;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!pInstance)
            return;

        if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS && pInstance->GetData(DATA_ALL_INITIAND_DEAD))
            MoveDown();

        if (bOpFerok && !bOnGround && !bCanDown) Opfern();

        if (bOpFerokFail && !bOnGround && !bCanDown)
            bCanDown = true;

        if (bCanDown)
        {
            MoveDown();
            bCanDown = false;
        }

        if (bOnGround)
        {
            if (!UpdateVictim())
                return;

            if (uiCycloneTimer < diff)
            {
                m_creature->CastSpell(m_creature, HEROIC(SPELL_CYCLONE_STRIKE, SPELL_CYCLONE_STRIKE_H), false);
                uiCycloneTimer = urand(15000,30000);
            } else uiCycloneTimer -= diff;

            if (uiBoltTimer < diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    m_creature->CastSpell(pTarget, HEROIC(SPELL_LIGHTNING_BOLT, SPELL_LIGHTNING_BOLT_H), false);

                uiBoltTimer = urand(15000,30000);
            } else uiBoltTimer -= diff;

            if (uiThunderTimer < diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    m_creature->CastSpell(pTarget, HEROIC(SPELL_THUNDERSHOCK, SPELL_THUNDERSHOCK_H), false);

                uiThunderTimer = urand(15000,30000);
            } else uiThunderTimer -= diff;

            if (uiOpFerTimer < diff)
                MoveUp();
            else
                uiOpFerTimer -= diff;

            DoMeleeAttackIfReady();
        }
    }
};

struct MANGOS_DLL_DECL mob_jedoga_initiandAI : public ScriptedAI
{
    mob_jedoga_initiandAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 checktimer;

    bool walking;

    void Reset()
    {
        if (!pInstance)
            return;

        walking = false;
        checktimer = 2000;

        if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
            m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
            m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
        }
        else
        {
            m_creature->CastSpell(m_creature, SPELL_SPHERE_VISUAL, false);
            m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
            m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    void JustDied(Unit* Killer)
    {
        if (!Killer || !pInstance) return;

        if (walking)
        {
            Creature* boss = m_creature->GetMap()->GetCreature(pInstance->GetData64(DATA_JEDOGA_SHADOWSEEKER));
            if (boss && !CAST_AI(boss_jedoga_shadowseekerAI, boss->AI())->bOpFerok) CAST_AI(boss_jedoga_shadowseekerAI, boss->AI())->bOpFerokFail = true;

            if (Killer->GetTypeId() == TYPEID_PLAYER) pInstance->SetData(DATA_INITIAND_KILLED, 1);
            pInstance->SetData64(DATA_ADD_JEDOGA_OPFER, 0);

            walking = false;
        }
        if (Killer->GetTypeId() == TYPEID_PLAYER) pInstance->SetData64(DATA_PL_JEDOGA_TARGET, Killer->GetGUID());
    }

    void EnterCombat(Unit* who)
    {
        if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !who) return;
    }

    void AttackStart(Unit* victim)
    {
        if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !victim) return;

        ScriptedAI::AttackStart(victim);
    }

    void MoveInLineOfSight(Unit* who)
    {
        if ((pInstance && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS) || !who) return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE || !pInstance) return;

        switch(uiPointId)
        {
            case 1:
                {
                    Creature* boss = m_creature->GetMap()->GetCreature(pInstance->GetData64(DATA_JEDOGA_SHADOWSEEKER));
                    if (boss)
                    {
                        CAST_AI(boss_jedoga_shadowseekerAI, boss->AI())->bOpFerok = true;
                        CAST_AI(boss_jedoga_shadowseekerAI, boss->AI())->bOpFerokFail = false;
                        m_creature->Kill(m_creature);
                    }
                }
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (pInstance && checktimer < diff)
        {
            if (m_creature->GetGUID() == pInstance->GetData64(DATA_ADD_JEDOGA_OPFER) && !walking)
            {
                m_creature->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);

                float distance = m_creature->GetDistance(JEDOGA_POS[1][0], JEDOGA_POS[1][1], JEDOGA_POS[1][2]);

                if (distance < 9.0f)
                    m_creature->SetSpeed(MOVE_WALK, 0.5f, true);
                else if (distance < 15.0f)
                    m_creature->SetSpeed(MOVE_WALK, 0.75f, true);
                else if (distance < 20.0f)
                    m_creature->SetSpeed(MOVE_WALK, 1.0f, true);

                m_creature->GetMotionMaster()->Clear(false);
                m_creature->GetMotionMaster()->MovePoint(1, JEDOGA_POS[1][0], JEDOGA_POS[1][1], JEDOGA_POS[1][2]);
                walking = true;
            }
            if (!walking)
            {
                if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) != IN_PROGRESS && m_creature->HasAura(SPELL_SPHERE_VISUAL))
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_SPHERE_VISUAL);
                    m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, false);
                    m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, false);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == IN_PROGRESS && !m_creature->HasAura(SPELL_SPHERE_VISUAL))
                {
                    m_creature->CastSpell(m_creature, SPELL_SPHERE_VISUAL, false);
                    m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                    m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                }
            }
            checktimer = 2000;
        } else checktimer -= diff;

        //Return since we have no target
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// ------------------------------------------------------------------------------------------------------------
// Jedogas Aufseher - Entry: 30181
// ------------------------------------------------------------------------------------------------------------
enum AufseherSpell
{
  SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_1    = 60342,
  SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_2    = 56312
};

struct MANGOS_DLL_DECL npc_jedogas_aufseher_triggerAI : public Scripted_NoMovementAI
{
    npc_jedogas_aufseher_triggerAI(Creature* c) : Scripted_NoMovementAI(c)
    {
        pInstance = c->GetInstanceData();
        c->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
        c->setFaction(35);
        removed = false;
        removed2 = false;
        casted = false;
        casted2 = false;
    }

    ScriptedInstance* pInstance;

    bool removed,
        removed2,
        casted,
        casted2;

    void Reset() {}
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* victim) {}
    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!pInstance)
            return;

        if (!removed && m_creature->GetPositionX() > 440.0f)
        {   /* NEEDS DATA WHETHER THE PRISON OF TALDARAM IS OFFLINE !
            if (pInstance->GetData(EVENT_VORRICHTUNGEN))
            {
                m_creature->InterruptNonMeleeSpells(true);
                removed = true;
                return;
            }*/
            if (pInstance->GetData(DATA_PRINCE_TALDARAM_EVENT) == DONE)
            {
                m_creature->InterruptNonMeleeSpells(true);
                removed = true;
                return;
            }
            if (!casted)
            {
                m_creature->CastSpell(m_creature, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_1, false);
                casted = true;
            }
        }
        if (!removed2 && m_creature->GetPositionX() < 440.0f)
        {
            if (!casted2 && pInstance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
            {
                m_creature->CastSpell(m_creature, SPELL_BEAM_VISUAL_JEDOGAS_AUFSEHER_2, false);
                casted2 = true;
            }
            if (casted2 && !pInstance->GetData(DATA_JEDOGA_TRIGGER_SWITCH))
            {
                m_creature->InterruptNonMeleeSpells(true);
                casted2 = false;
            }
            if (!removed2 && pInstance->GetData(DATA_JEDOGA_SHADOWSEEKER_EVENT) == DONE)
            {
                m_creature->InterruptNonMeleeSpells(true);
                removed2 = true;
            }
        }
    }
};

CreatureAI* GetAI_boss_jedoga_shadowseeker(Creature* pCreature)
{
    return new boss_jedoga_shadowseekerAI (pCreature);
}

CreatureAI* GetAI_mob_jedoga_initiand(Creature* pCreature)
{
    return new mob_jedoga_initiandAI (pCreature);
}

CreatureAI* GetAI_npc_jedogas_aufseher_trigger(Creature* pCreature)
{
    return new npc_jedogas_aufseher_triggerAI (pCreature);
}

void AddSC_boss_jedoga_shadowseeker()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_jedoga_shadowseeker";
    newscript->GetAI = &GetAI_boss_jedoga_shadowseeker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_jedoga_initiand";
    newscript->GetAI = &GetAI_mob_jedoga_initiand;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_jedogas_aufseher_trigger";
    newscript->GetAI = &GetAI_npc_jedogas_aufseher_trigger;
    newscript->RegisterSelf();
}
