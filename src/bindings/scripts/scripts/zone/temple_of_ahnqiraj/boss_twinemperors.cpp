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
SDName: Boss_Twinemperors
SD%Complete: 95
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"
#include "def_temple_of_ahnqiraj.h"
#include "WorldPacket.h"

#include "Item.h"
#include "Spell.h"

#define SPELL_HEAL_BROTHER          7393
#define SPELL_TWIN_TELEPORT         800                     // CTRA watches for this spell to start its teleport timer
#define SPELL_TWIN_TELEPORT_VISUAL  26638                   // visual

#define SPELL_EXPLODEBUG            804
#define SPELL_MUTATE_BUG            802

#define SOUND_VN_DEATH              8660                    //8660 - Death - Feel
#define SOUND_VN_AGGRO              8661                    //8661 - Aggro - Let none
#define SOUND_VN_KILL               8662                    //8661 - Kill - your fate

#define SOUND_VL_AGGRO              8657                    //8657 - Aggro - To Late
#define SOUND_VL_KILL               8658                    //8658 - Kill - You will not
#define SOUND_VL_DEATH              8659                    //8659 - Death

#define PULL_RANGE                  50
#define ABUSE_BUG_RANGE             20
#define SPELL_BERSERK               26662
#define TELEPORTTIME                30000

#define SPELL_UPPERCUT              26007
#define SPELL_UNBALANCING_STRIKE    26613

#define VEKLOR_DIST                 20                      // VL will not come to melee when attacking

#define SPELL_SHADOWBOLT            26006
#define SPELL_BLIZZARD              26607
#define SPELL_ARCANEBURST           568

struct TRINITY_DLL_DECL boss_twinemperorsAI : public ScriptedAI
{
    ScriptedInstance *pInstance;
    uint32 Heal_Timer;
    uint32 Teleport_Timer;
    bool AfterTeleport;
    uint32 AfterTeleportTimer;
    bool DontYellWhenDead;
    uint32 Abuse_Bug_Timer, BugsTimer;
    bool tspellcasted;
    uint32 EnrageTimer;

    virtual bool IAmVeklor() = 0;
    virtual void Reset() = 0;
    virtual void CastSpellOnBug(Creature *target) = 0;

    boss_twinemperorsAI(Creature *c): ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    void TwinReset()
    {
        Heal_Timer = 0;                                     // first heal immediately when they get close together
        Teleport_Timer = TELEPORTTIME;
        AfterTeleport = false;
        tspellcasted = false;
        AfterTeleportTimer = 0;
        Abuse_Bug_Timer = 10000 + rand()%7000;
        BugsTimer = 2000;
        m_creature->clearUnitState(UNIT_STAT_STUNNED);
        DontYellWhenDead = false;
        EnrageTimer = 15*60000;
    }

    Creature *GetOtherBoss()
    {
        if(pInstance)
        {
            return (Creature *)Unit::GetUnit((*m_creature), pInstance->GetData64(IAmVeklor() ? DATA_VEKNILASH : DATA_VEKLOR));
        }
        else
        {
            return (Creature *)0;
        }
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        Unit *pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            float dPercent = ((float)damage) / ((float)m_creature->GetMaxHealth());
            int odmg = (int)(dPercent * ((float)pOtherBoss->GetMaxHealth()));
            int ohealth = pOtherBoss->GetHealth()-odmg;
            pOtherBoss->SetHealth(ohealth > 0 ? ohealth : 0);
            if (ohealth <= 0)
            {
                pOtherBoss->setDeathState(JUST_DIED);
                pOtherBoss->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        Creature *pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            pOtherBoss->SetHealth(0);
            pOtherBoss->setDeathState(JUST_DIED);
            pOtherBoss->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            ((boss_twinemperorsAI *)pOtherBoss->AI())->DontYellWhenDead = true;
        }
        if (!DontYellWhenDead)                              // I hope AI is not threaded
            DoPlaySoundToSet(m_creature, IAmVeklor() ? SOUND_VL_DEATH : SOUND_VN_DEATH);
    }

    void KilledUnit(Unit* victim)
    {
        DoPlaySoundToSet(m_creature, IAmVeklor() ? SOUND_VL_KILL : SOUND_VN_KILL);
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
        Creature *pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            // TODO: we should activate the other boss location so he can start attackning even if nobody
            // is near I dont know how to do that
            ScriptedAI *otherAI = (ScriptedAI*)pOtherBoss->AI();
            if (!pOtherBoss->isInCombat())
            {
                DoPlaySoundToSet(m_creature, IAmVeklor() ? SOUND_VL_AGGRO : SOUND_VN_AGGRO);
                otherAI->AttackStart(who);
                otherAI->DoZoneInCombat();
            }
        }
    }

    void SpellHit(Unit *caster, const SpellEntry *entry)
    {
        if (caster == m_creature)
            return;

        Creature *pOtherBoss = GetOtherBoss();
        if (entry->Id != SPELL_HEAL_BROTHER || !pOtherBoss)
            return;

        // add health so we keep same percentage for both brothers
        uint32 mytotal = m_creature->GetMaxHealth(), histotal = pOtherBoss->GetMaxHealth();
        float mult = ((float)mytotal) / ((float)histotal);
        if (mult < 1)
            mult = 1.0f/mult;
        #define HEAL_BROTHER_AMOUNT 30000.0f
        uint32 largerAmount = (uint32)((HEAL_BROTHER_AMOUNT * mult) - HEAL_BROTHER_AMOUNT);

        uint32 myh = m_creature->GetHealth();
        uint32 hish = pOtherBoss->GetHealth();
        if (mytotal > histotal)
        {
            uint32 h = m_creature->GetHealth()+largerAmount;
            m_creature->SetHealth(std::min(mytotal, h));
        }
        else
        {
            uint32 h = pOtherBoss->GetHealth()+largerAmount;
            pOtherBoss->SetHealth(std::min(histotal, h));
        }
    }

    void TryHealBrother(uint32 diff)
    {
        if (IAmVeklor())                                    // this spell heals caster and the other brother so let VN cast it
            return;

        if (Heal_Timer < diff)
        {
            Unit *pOtherBoss = GetOtherBoss();
            if (pOtherBoss && (pOtherBoss->GetDistance((const Creature *)m_creature) <= 60))
            {
                DoCast(pOtherBoss, SPELL_HEAL_BROTHER);
                Heal_Timer = 1000;
            }
        } else Heal_Timer -= diff;
    }

    void TeleportToMyBrother()
    {
        if (!pInstance)
            return;

        Teleport_Timer = TELEPORTTIME;

        if(IAmVeklor())
            return;                                         // mechanics handled by veknilash so they teleport exactly at the same time and to correct coordinates

        Creature *pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            //m_creature->MonsterYell("Teleporting ...", LANG_UNIVERSAL, 0);
            float other_x = pOtherBoss->GetPositionX();
            float other_y = pOtherBoss->GetPositionY();
            float other_z = pOtherBoss->GetPositionZ();
            float other_o = pOtherBoss->GetOrientation();

            Map *thismap = m_creature->GetMap();
            thismap->CreatureRelocation(pOtherBoss, m_creature->GetPositionX(),
                m_creature->GetPositionY(),    m_creature->GetPositionZ(), m_creature->GetOrientation());
            thismap->CreatureRelocation(m_creature, other_x, other_y, other_z, other_o);

            SetAfterTeleport();
            ((boss_twinemperorsAI*) pOtherBoss->AI())->SetAfterTeleport();
        }
    }

    void SetAfterTeleport()
    {
        m_creature->InterruptNonMeleeSpells(false);
        DoStopAttack();
        DoResetThreat();
        DoCast(m_creature, SPELL_TWIN_TELEPORT_VISUAL);
        m_creature->addUnitState(UNIT_STAT_STUNNED);
        AfterTeleport = true;
        AfterTeleportTimer = 2000;
        tspellcasted = false;
    }

    bool TryActivateAfterTTelep(uint32 diff)
    {
        if (AfterTeleport)
        {
            if (!tspellcasted)
            {
                m_creature->clearUnitState(UNIT_STAT_STUNNED);
                DoCast(m_creature, SPELL_TWIN_TELEPORT);
                m_creature->addUnitState(UNIT_STAT_STUNNED);
            }

            tspellcasted = true;

            if (AfterTeleportTimer < diff)
            {
                AfterTeleport = false;
                m_creature->clearUnitState(UNIT_STAT_STUNNED);
                Unit *nearu = m_creature->SelectNearestTarget(100);
                //DoYell(nearu->GetName(), LANG_UNIVERSAL, 0);
                if(nearu)
                {
                    AttackStart(nearu);
                    m_creature->getThreatManager().addThreat(nearu, 10000);
                }
                return true;
            }
            else
            {
                AfterTeleportTimer -= diff;
                // update important timers which would otherwise get skipped
                if (EnrageTimer > diff)
                    EnrageTimer -= diff;
                else
                    EnrageTimer = 0;
                if (Teleport_Timer > diff)
                    Teleport_Timer -= diff;
                else
                    Teleport_Timer = 0;
                return false;
            }
        }
        else
        {
            return true;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (attackRadius < PULL_RANGE)
                attackRadius = PULL_RANGE;
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= /*CREATURE_Z_ATTACK_RANGE*/7 /*there are stairs*/)
            {
                //if(who->HasStealthAura())
                //    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
            }
        }
    }

    class AnyBugCheck
    {
        public:
            AnyBugCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) {}
            bool operator()(Unit* u)
            {
                Creature *c = (Creature *)u;
                if (!i_obj->IsWithinDistInMap(c, i_range))
                    return false;
                return (c->GetEntry() == 15316 || c->GetEntry() == 15317);
            }
        private:
            WorldObject const* i_obj;
            float i_range;
    };

    Creature *RespawnNearbyBugsAndGetOne()
    {
        CellPair p(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        std::list<Creature*> unitList;

        AnyBugCheck u_check(m_creature, 150);
        Trinity::CreatureListSearcher<AnyBugCheck> searcher(m_creature, unitList, u_check);
        TypeContainerVisitor<Trinity::CreatureListSearcher<AnyBugCheck>, GridTypeMapContainer >  grid_creature_searcher(searcher);
        CellLock<GridReadGuard> cell_lock(cell, p);
        cell_lock->Visit(cell_lock, grid_creature_searcher, *(m_creature->GetMap()));

        Creature *nearb = NULL;

        for(std::list<Creature*>::iterator iter = unitList.begin(); iter != unitList.end(); ++iter)
        {
            Creature *c = (Creature *)(*iter);
            if (c && c->isDead())
            {
                c->Respawn();
                c->setFaction(7);
                c->RemoveAllAuras();
            }
            if (c->IsWithinDistInMap(m_creature, ABUSE_BUG_RANGE))
            {
                if (!nearb || (rand()%4)==0)
                    nearb = c;
            }
        }
        return nearb;
    }

    void HandleBugs(uint32 diff)
    {
        if (BugsTimer < diff || Abuse_Bug_Timer < diff)
        {
            Creature *c = RespawnNearbyBugsAndGetOne();
            if (Abuse_Bug_Timer < diff)
            {
                if (c)
                {
                    CastSpellOnBug(c);
                    Abuse_Bug_Timer = 10000 + rand()%7000;
                }
                else
                {
                    Abuse_Bug_Timer = 1000;
                }
            }
            else
            {
                Abuse_Bug_Timer -= diff;
            }
            BugsTimer = 2000;
        }
        else
        {
            BugsTimer -= diff;
            Abuse_Bug_Timer -= diff;
        }
    }

    void CheckEnrage(uint32 diff)
    {
        if (EnrageTimer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(true))
            {
                DoCast(m_creature, SPELL_BERSERK);
                EnrageTimer = 60*60000;
            } else EnrageTimer = 0;
        } else EnrageTimer-=diff;
    }
};

struct TRINITY_DLL_DECL boss_veknilashAI : public boss_twinemperorsAI
{
    bool IAmVeklor() {return false;}
    boss_veknilashAI(Creature *c) : boss_twinemperorsAI(c) {}

    uint32 UpperCut_Timer;
    uint32 UnbalancingStrike_Timer;
    uint32 Scarabs_Timer;
    int Rand;
    int RandX;
    int RandY;

    Creature* Summoned;

    void Reset()
    {
        TwinReset();
        UpperCut_Timer = 14000 + rand()%15000;
        UnbalancingStrike_Timer = 8000 + rand()%10000;
        Scarabs_Timer = 7000 + rand()%7000;

                                                            //Added. Can be removed if its included in DB.
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
    }

    void CastSpellOnBug(Creature *target)
    {
        target->setFaction(14);
        (target->AI())->AttackStart(m_creature->getThreatManager().getHostilTarget());
        SpellEntry *spell = (SpellEntry *)GetSpellStore()->LookupEntry(SPELL_MUTATE_BUG);
        uint8 eff_mask=0;
        for (int i=0; i<3; i++)
        {
            if (!spell->Effect[i])
                continue;
            eff_mask|=1<<i;
        }
        target->AddAura(new Aura(spell, eff_mask, NULL, target, target));
        target->SetHealth(target->GetMaxHealth());
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!TryActivateAfterTTelep(diff))
            return;

        //UnbalancingStrike_Timer
        if (UnbalancingStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_UNBALANCING_STRIKE);
            UnbalancingStrike_Timer = 8000+rand()%12000;
        }else UnbalancingStrike_Timer -= diff;

        if (UpperCut_Timer < diff)
        {
            Unit* randomMelee = SelectTarget(SELECT_TARGET_RANDOM, 0, NOMINAL_MELEE_RANGE, true);
            if (randomMelee)
                DoCast(randomMelee,SPELL_UPPERCUT);
            UpperCut_Timer = 15000+rand()%15000;
        }else UpperCut_Timer -= diff;

        HandleBugs(diff);

        //Heal brother when 60yrds close
        TryHealBrother(diff);

        //Teleporting to brother
        if(Teleport_Timer < diff)
        {
            TeleportToMyBrother();
        }else Teleport_Timer -= diff;

        CheckEnrage(diff);

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL boss_veklorAI : public boss_twinemperorsAI
{
    bool IAmVeklor() {return true;}
    boss_veklorAI(Creature *c) : boss_twinemperorsAI(c) {}

    uint32 ShadowBolt_Timer;
    uint32 Blizzard_Timer;
    uint32 ArcaneBurst_Timer;
    uint32 Scorpions_Timer;
    int Rand;
    int RandX;
    int RandY;

    Creature* Summoned;

    void Reset()
    {
        TwinReset();
        ShadowBolt_Timer = 0;
        Blizzard_Timer = 15000 + rand()%5000;;
        ArcaneBurst_Timer = 1000;
        Scorpions_Timer = 7000 + rand()%7000;

        //Added. Can be removed if its included in DB.
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, 0);
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, 0);
    }

    void CastSpellOnBug(Creature *target)
    {
        target->setFaction(14);
        SpellEntry *spell = (SpellEntry *)GetSpellStore()->LookupEntry(SPELL_EXPLODEBUG);
        uint8 eff_mask=0;
        for (int i=0; i<3; i++)
        {
            if (!spell->Effect[i])
                continue;
            eff_mask|=1<<i;
        }
        target->AddAura(new Aura(spell, eff_mask, NULL, target, target));
        target->SetHealth(target->GetMaxHealth());
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        // reset arcane burst after teleport - we need to do this because
        // when VL jumps to VN's location there will be a warrior who will get only 2s to run away
        // which is almost impossible
        if (AfterTeleport)
            ArcaneBurst_Timer = 5000;
        if (!TryActivateAfterTTelep(diff))
            return;

        //ShadowBolt_Timer
        if (ShadowBolt_Timer < diff)
        {
            if (m_creature->GetDistance(m_creature->getVictim()) > 45)
                m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim(), VEKLOR_DIST, 0);
            else
                DoCast(m_creature->getVictim(),SPELL_SHADOWBOLT);
            ShadowBolt_Timer = 2000;
        }else ShadowBolt_Timer -= diff;

        //Blizzard_Timer
        if (Blizzard_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45, true);
            if (target)
                DoCast(target,SPELL_BLIZZARD);
            Blizzard_Timer = 15000+rand()%15000;
        }else Blizzard_Timer -= diff;

        if (ArcaneBurst_Timer < diff)
        {
            Unit *mvic;
            if ((mvic=SelectTarget(SELECT_TARGET_NEAREST, 0, NOMINAL_MELEE_RANGE, true))!=NULL)
            {
                DoCast(mvic,SPELL_ARCANEBURST);
                ArcaneBurst_Timer = 5000;
            }
        }else ArcaneBurst_Timer -= diff;

        HandleBugs(diff);

        //Heal brother when 60yrds close
        TryHealBrother(diff);

        //Teleporting to brother
        if(Teleport_Timer < diff)
        {
            TeleportToMyBrother();
        }else Teleport_Timer -= diff;

        CheckEnrage(diff);

        //VL doesn't melee
        //DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (who->isTargetableForAttack())
        {
            // VL doesn't melee
            if ( m_creature->Attack(who, false) )
            {
                m_creature->GetMotionMaster()->MoveChase(who, VEKLOR_DIST, 0);
                m_creature->AddThreat(who, 0.0f);
            }
        }
    }
};

CreatureAI* GetAI_boss_veknilash(Creature *_Creature)
{
    return new boss_veknilashAI (_Creature);
}

CreatureAI* GetAI_boss_veklor(Creature *_Creature)
{
    return new boss_veklorAI (_Creature);
}

void AddSC_boss_twinemperors()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_veknilash";
    newscript->GetAI = &GetAI_boss_veknilash;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_veklor";
    newscript->GetAI = &GetAI_boss_veklor;
    newscript->RegisterSelf();
}

