/* Copyright(C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
*(at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: boss_alar
SD%Complete: 95
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "precompiled.h"
#include "def_the_eye.h"

#define SPELL_FLAME_BUFFET            34121 // Flame Buffet - every 1,5 secs in phase 1 if there is no victim in melee range and after Dive Bomb in phase 2 with same conditions
#define SPELL_FLAME_QUILLS            34229 // Randomly after changing position in phase after watching tonns of movies, set probability 20%
#define SPELL_REBIRTH                 34342 // Rebirth - beginning of second phase(after loose all health in phase 1)
#define SPELL_REBIRTH_2               35369 // Rebirth(another, without healing to full HP) - after Dive Bomb in phase 2
#define SPELL_MELT_ARMOR              35410 // Melt Armor - every 60 sec in phase 2
#define SPELL_CHARGE                  35412 // Charge - 30 sec cooldown
#define SPELL_DIVE_BOMB_VISUAL        35367 // Bosskillers says 30 sec cooldown, wowwiki says 30 sec colldown, DBM and BigWigs addons says ~47 sec
#define SPELL_DIVE_BOMB               35181 // after watching tonns of movies, set cooldown to 40+rand()%5.
#define SPELL_BERSERK                 45078 // 10 minutes after phase 2 starts(id is wrong, but proper id is unknown)

#define CREATURE_EMBER_OF_ALAR        19551 // Al'ar summons one Ember of Al'ar every position change in phase 1 and two after Dive Bomb. Also in phase 2 when Ember of Al'ar dies, boss loose 3% health.
#define SPELL_EMBER_BLAST             34133 // When Ember of Al'ar dies, it casts Ember Blast

#define CREATURE_FLAME_PATCH_ALAR     20602 // Flame Patch - every 30 sec in phase 2
#define SPELL_FLAME_PATCH             35380 //

static float waypoint[6][3] =
{
    {340.15, 58.65, 17.71},
    {388.09, 31.54, 20.18},
    {388.18, -32.85, 20.18},
    {340.29, -60.19, 17.72},
    {332, 0.01, 39}, // better not use the same xy coord
    {331, 0.01, -2.39}
};

enum WaitEventType
{
    WE_NONE     = 0,
    WE_DUMMY    = 1,
    WE_PLATFORM = 2,
    WE_QUILL    = 3,
    WE_DIE      = 4,
    WE_REVIVE   = 5,
    WE_CHARGE   = 6,
    WE_METEOR   = 7,
    WE_DIVE     = 8,
    WE_LAND     = 9,
    WE_SUMMON   = 10
};

struct TRINITY_DLL_DECL boss_alarAI : public ScriptedAI
{
    boss_alarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance =c->GetInstanceData();
        DefaultMoveSpeedRate = m_creature->GetSpeedRate(MOVE_RUN);
    }

    ScriptedInstance *pInstance;

    WaitEventType WaitEvent;
    uint32 WaitTimer;

    bool AfterMoving;

    uint32 Platforms_Move_Timer;
    uint32 DiveBomb_Timer;
    uint32 MeltArmor_Timer;
    uint32 Charge_Timer;
    uint32 FlamePatch_Timer;
    uint32 Berserk_Timer;

    float DefaultMoveSpeedRate;

    bool Phase1;
    bool ForceMove;
    uint32 ForceTimer;

    int8 cur_wp;

    void Reset()
    {
        if(pInstance)
            pInstance->SetData(DATA_ALAREVENT, NOT_STARTED);

        Berserk_Timer = 1200000;
        Platforms_Move_Timer = 0;

        Phase1 = true;
        WaitEvent = WE_NONE;
        WaitTimer = 0;
        AfterMoving = false;
        ForceMove = false;
        ForceTimer = 5000;

        cur_wp = 4;

        m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
        m_creature->SetSpeed(MOVE_RUN, DefaultMoveSpeedRate);
        //m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
        //m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->setActive(false);
    }

    void EnterCombat(Unit *who)
    {
        if(pInstance)
            pInstance->SetData(DATA_ALAREVENT, IN_PROGRESS);

        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING); // after enterevademode will be set walk movement
        DoZoneInCombat();
        m_creature->setActive(true);
    }

    void JustDied(Unit *victim)
    {
        if(pInstance)
            pInstance->SetData(DATA_ALAREVENT, DONE);
    }

    void JustSummoned(Creature *summon)
    {
        if(summon->GetEntry() == CREATURE_EMBER_OF_ALAR)
            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                summon->AI()->AttackStart(target);
    }

    void MoveInLineOfSight(Unit *who) {}

    void AttackStart(Unit* who)
    {
        if(Phase1)
            AttackStartNoMove(who);
        else
            ScriptedAI::AttackStart(who);
    }

    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth() && Phase1)
        {
            damage = 0;
            if(!WaitEvent)
            {
                WaitEvent = WE_DIE;
                WaitTimer = 0;
                m_creature->SetHealth(0);
                m_creature->InterruptNonMeleeSpells(true);
                m_creature->RemoveAllAuras();
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->AttackStop();
                m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                m_creature->SetSpeed(MOVE_RUN, 5.0f);
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MovePoint(0, waypoint[5][0], waypoint[5][1], waypoint[5][2]);
            }
        }
    }

    void SpellHit(Unit*, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_DIVE_BOMB_VISUAL)
        {
            m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
            m_creature->SetDisplayId(11686);
            //m_creature->SendUpdateObjectToAllExcept(NULL);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type == POINT_MOTION_TYPE)
        {
            WaitTimer = 1;
            AfterMoving = true;
            ForceMove = false;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->isInCombat()) // sometimes isincombat but !incombat, faction bug?
            return;

        if(Berserk_Timer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            Berserk_Timer = 60000;
        }else Berserk_Timer -= diff;

        if(ForceMove)
        {
            if(ForceTimer < diff)
            {
                m_creature->GetMotionMaster()->MovePoint(0, waypoint[cur_wp][0], waypoint[cur_wp][1], waypoint[cur_wp][2]);
                ForceTimer = 5000;
            }else ForceTimer -= diff;

        }
        if(WaitEvent)
        {
            if(WaitTimer)
            {
                if(WaitTimer <= diff)
                {
                    if(AfterMoving)
                    {
                        m_creature->GetMotionMaster()->MoveIdle();
                        AfterMoving = false;
                    }

                    switch(WaitEvent)
                    {
                    case WE_PLATFORM:
                        Platforms_Move_Timer = 30000+rand()%5000;
                        break;
                    case WE_QUILL:
                        m_creature->CastSpell(m_creature, SPELL_FLAME_QUILLS, true);
                        Platforms_Move_Timer = 1;
                        WaitTimer = 10000;
                        WaitEvent = WE_DUMMY;
                        return;
                    case WE_DIE:
                        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
                        WaitTimer = 5000;
                        WaitEvent = WE_REVIVE;
                        return;
                    case WE_REVIVE:
                        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);
                        m_creature->SetHealth(m_creature->GetMaxHealth());
                        m_creature->SetSpeed(MOVE_RUN, DefaultMoveSpeedRate);
                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        DoResetThreat();
                        DoZoneInCombat();
                        m_creature->CastSpell(m_creature, SPELL_REBIRTH, true);
                        MeltArmor_Timer = 60000;
                        Charge_Timer = 7000;
                        DiveBomb_Timer = 40000+rand()%5000;
                        FlamePatch_Timer = 30000;
                        Phase1 = false;
                        break;
                    case WE_METEOR:
                        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                        m_creature->CastSpell(m_creature, SPELL_DIVE_BOMB_VISUAL, false);
                        WaitEvent = WE_DIVE;
                        WaitTimer = 4000;
                        return;
                    case WE_DIVE:
                        if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        {
                            m_creature->RemoveAurasDueToSpell(SPELL_DIVE_BOMB_VISUAL);
                            m_creature->CastSpell(target, SPELL_DIVE_BOMB, true);
                            float dist = m_creature->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            if (dist < 5.0f) dist = 5.0f;
                            WaitTimer = 1000 + floor(dist / 80 * 1000.0f);
                            m_creature->Relocate(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            m_creature->StopMoving();
                            WaitEvent = WE_LAND;
                        }
                        else
                        {
                            EnterEvadeMode();
                            return;
                        }
                    case WE_LAND:
                        WaitEvent = WE_SUMMON;
                        WaitTimer = 2000;
                        return;
                    case WE_SUMMON:
                        for(uint8 i = 0; i < 2; ++i)
                            DoSpawnCreature(CREATURE_EMBER_OF_ALAR, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
                        m_creature->CastSpell(m_creature, SPELL_REBIRTH_2, true);
                        break;
                    case WE_DUMMY:
                    default:
                        break;
                    }

                    WaitEvent = WE_NONE;
                    WaitTimer = 0;
                }else WaitTimer -= diff;
            }
            return;
        }

        if(Phase1)
        {
            if(m_creature->getThreatManager().getThreatList().empty())
            {
                EnterEvadeMode();
                return;
            }

            if(Platforms_Move_Timer < diff)
            {
                if(cur_wp == 4)
                {
                    cur_wp = 0;
                    WaitEvent = WE_PLATFORM;
                }
                else
                {
                    if(rand()%5) // next platform
                    {
                        DoSpawnCreature(CREATURE_EMBER_OF_ALAR, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        if(cur_wp == 3)
                            cur_wp = 0;
                        else
                            cur_wp++;
                        WaitEvent = WE_PLATFORM;
                    }
                    else // flame quill
                    {
                        cur_wp = 4;
                        WaitEvent = WE_QUILL;
                    }
                }
                ForceMove = true;
                ForceTimer = 5000;
                m_creature->GetMotionMaster()->MovePoint(0, waypoint[cur_wp][0], waypoint[cur_wp][1], waypoint[cur_wp][2]);
                WaitTimer = 0;
                return;
            }else Platforms_Move_Timer -= diff;
        }
        else
        {
            if(!UpdateVictim())
                return;

            if(Charge_Timer < diff)
            {
                Unit *target= SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                if(target)
                    DoCast(target, SPELL_CHARGE);
                Charge_Timer = 30000;
            }else Charge_Timer -= diff;

            if(MeltArmor_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_MELT_ARMOR);
                MeltArmor_Timer = 60000;
            }else MeltArmor_Timer -= diff;

            if(DiveBomb_Timer < diff)
            {
                m_creature->AttackStop();
                m_creature->GetMotionMaster()->MovePoint(6, waypoint[4][0], waypoint[4][1], waypoint[4][2]);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 50);
                WaitEvent = WE_METEOR;
                WaitTimer = 0;
                DiveBomb_Timer = 40000+rand()%5000;
                return;
            }else DiveBomb_Timer -= diff;

            if(FlamePatch_Timer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    Creature* Summoned = m_creature->SummonCreature(CREATURE_FLAME_PATCH_ALAR, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 120000);
                    if(Summoned)
                    {
                        Summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Summoned->SetFloatValue(OBJECT_FIELD_SCALE_X, Summoned->GetFloatValue(OBJECT_FIELD_SCALE_X)*2.5f);
                        Summoned->SetDisplayId(11686);
                        Summoned->setFaction(m_creature->getFaction());
                        Summoned->SetLevel(m_creature->getLevel());
                        Summoned->CastSpell(Summoned, SPELL_FLAME_PATCH, false);
                    }
                }
                FlamePatch_Timer = 30000;
            }else FlamePatch_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void DoMeleeAttackIfReady()
    {
        if(m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
        {
            if(m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
            else
            {
                Unit *target = NULL;
                target = m_creature->SelectNearestTarget(5);
                if(Phase1 && target)
                    m_creature->AI()->AttackStart(target);
                else
                {
                    m_creature->CastSpell(m_creature, SPELL_FLAME_BUFFET, true);
                    m_creature->setAttackTimer(BASE_ATTACK, 1500);
                }
            }
        }
    }
};

CreatureAI* GetAI_boss_alar(Creature *_Creature)
{
    return new boss_alarAI(_Creature);
}

struct TRINITY_DLL_DECL mob_ember_of_alarAI : public ScriptedAI
{
    mob_ember_of_alarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
    }

    ScriptedInstance *pInstance;
    bool toDie;

    void Reset() {toDie = false;}
    void EnterCombat(Unit *who) {DoZoneInCombat();}
    void EnterEvadeMode() {m_creature->setDeathState(JUST_DIED);}

    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth() && pKiller != m_creature && !toDie)
        {
            damage = 0;
            m_creature->CastSpell(m_creature, SPELL_EMBER_BLAST, true);
            m_creature->SetDisplayId(11686);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            if(pInstance && pInstance->GetData(DATA_ALAREVENT) == 2)
            {
                if(Unit* Alar = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_ALAR)))
                {
                    int AlarHealth = Alar->GetHealth() - Alar->GetMaxHealth()*0.03;
                    if(AlarHealth > 0)
                        Alar->SetHealth(AlarHealth);
                    else
                        Alar->SetHealth(1);
                }
            }
            toDie = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(toDie)
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            //m_creature->SetVisibility(VISIBILITY_OFF);
        }

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_mob_ember_of_alar(Creature *_Creature)
{
    return new mob_ember_of_alarAI(_Creature);
}

struct TRINITY_DLL_DECL mob_flame_patch_alarAI : public ScriptedAI
{
    mob_flame_patch_alarAI(Creature *c) : ScriptedAI(c) {}
    void Reset() {}
    void EnterCombat(Unit *who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}
};

CreatureAI* GetAI_mob_flame_patch_alar(Creature *_Creature)
{
    return new mob_flame_patch_alarAI(_Creature);
}

void AddSC_boss_alar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_alar";
    newscript->GetAI = &GetAI_boss_alar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ember_of_alar";
    newscript->GetAI = &GetAI_mob_ember_of_alar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_flame_patch_alar";
    newscript->GetAI = &GetAI_mob_flame_patch_alar;
    newscript->RegisterSelf();
}

