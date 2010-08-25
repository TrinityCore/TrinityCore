/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss Volkhan
SD%Complete: 60%
SDComment: Not considered complete. Some events may fail and need further development
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptPCH.h"
#include "halls_of_lightning.h"

enum eEnums
{
    SAY_AGGRO                               = -1602032,
    SAY_SLAY_1                              = -1602033,
    SAY_SLAY_2                              = -1602034,
    SAY_SLAY_3                              = -1602035,
    SAY_DEATH                               = -1602036,
    SAY_STOMP_1                             = -1602037,
    SAY_STOMP_2                             = -1602038,
    SAY_FORGE_1                             = -1602039,
    SAY_FORGE_2                             = -1602040,
    EMOTE_TO_ANVIL                          = -1602041,
    EMOTE_SHATTER                           = -1602042,

    SPELL_HEAT_N                            = 52387,
    SPELL_HEAT_H                            = 59528,
    SPELL_SHATTERING_STOMP_N                = 52237,
    SPELL_SHATTERING_STOMP_H                = 59529,

    //unclear how "directions" of spells must be. Last, summoning GO, what is it for? Script depend on:
    SPELL_TEMPER                            = 52238,        //TARGET_SCRIPT boss->anvil
    SPELL_TEMPER_DUMMY                      = 52654,        //TARGET_SCRIPT anvil->boss

    //SPELL_TEMPER_VISUAL                     = 52661,        //summons GO

    SPELL_SUMMON_MOLTEN_GOLEM               = 52405,

    //Molten Golem
    SPELL_BLAST_WAVE                        = 23113,
    SPELL_IMMOLATION_STRIKE_N               = 52433,
    SPELL_IMMOLATION_STRIKE_H               = 59530,
    SPELL_SHATTER_N                         = 52429,
    SPELL_SHATTER_H                         = 59527,

    NPC_VOLKHAN_ANVIL                       = 28823,
    NPC_MOLTEN_GOLEM                        = 28695,
    NPC_BRITTLE_GOLEM                       = 28681,

    POINT_ID_ANVIL                          = 0,
    MAX_GOLEM                               = 2,

    ACHIEVEMENT_SHATTER_RESISTANT            = 2042
};

/*######
## Boss Volkhan
######*/

class boss_volkhan : public CreatureScript
{
public:
    boss_volkhan() : CreatureScript("boss_volkhan") { }

    bool EffectDummyCreature(Unit* pCaster, uint32 uiSpellId, uint32 uiEffIndex, Creature* pCreatureTarget)
    {
        //always check spellid and effectindex
        if (uiSpellId == SPELL_TEMPER_DUMMY && uiEffIndex == 0)
        {
            if (pCaster->GetEntry() != NPC_VOLKHAN_ANVIL || pCreatureTarget->GetEntry() != NPC_VOLKHAN)
                return true;

            for (uint8 i = 0; i < MAX_GOLEM; ++i)
            {
                pCreatureTarget->CastSpell(pCaster, SPELL_SUMMON_MOLTEN_GOLEM, true);
            }

            //always return true when we are handling this spell and effect
            return true;
        }

        return false;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_volkhanAI(pCreature);
    }

    struct boss_volkhanAI : public ScriptedAI
    {
        boss_volkhanAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        std::list<uint64> m_lGolemGUIDList;

        bool m_bHasTemper;
        bool m_bIsStriking;
        bool m_bCanShatterGolem;

        uint8 GolemsShattered;
        uint32 m_uiPause_Timer;
        uint32 m_uiShatteringStomp_Timer;
        uint32 m_uiShatter_Timer;

        uint32 m_uiHealthAmountModifier;

        void Reset()
        {
            m_bIsStriking = false;
            m_bHasTemper = false;
            m_bCanShatterGolem = false;

            m_uiPause_Timer = 3500;
            m_uiShatteringStomp_Timer = 0;
            m_uiShatter_Timer = 5000;
            GolemsShattered = 0;

            m_uiHealthAmountModifier = 1;

            DespawnGolem();
            m_lGolemGUIDList.clear();

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, NOT_STARTED);
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, IN_PROGRESS);
        }

        void AttackStart(Unit* pWho)
        {
            if (me->Attack(pWho, true))
            {
                me->AddThreat(pWho, 0.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);

                if (!m_bHasTemper)
                    me->GetMotionMaster()->MoveChase(pWho);
            }
        }

        void JustDied(Unit* /*pKiller*/)
        {
            DoScriptText(SAY_DEATH, me);
            DespawnGolem();

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, DONE);

            if (IsHeroic() && GolemsShattered < 5)
            {
                AchievementEntry const *AchievShatterResistant = GetAchievementStore()->LookupEntry(ACHIEVEMENT_SHATTER_RESISTANT);
                if (AchievShatterResistant)
                {
                    Map* pMap = me->GetMap();
                    if (pMap && pMap->IsDungeon())
                    {
                        Map::PlayerList const &players = pMap->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            itr->getSource()->CompletedAchievement(AchievShatterResistant);
                    }
                }
            }
        }

        void KilledUnit(Unit* /*pVictim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
        }

        void DespawnGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                {
                    if (pTemp->isAlive())
                        pTemp->ForcedDespawn();
                }
            }

            m_lGolemGUIDList.clear();
        }

        void ShatterGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                {
                    // only shatter brittle golems
                    if (pTemp->isAlive() && pTemp->GetEntry() == NPC_BRITTLE_GOLEM)
                    {
                        pTemp->CastSpell(pTemp, DUNGEON_MODE(SPELL_SHATTER_N, SPELL_SHATTER_H), false);
                        GolemsShattered += 1;
                    }
                }
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_TEMPER_DUMMY)
                m_bIsStriking = true;
        }

        void JustSummoned(Creature* pSummoned)
        {
            if (pSummoned->GetEntry() == NPC_MOLTEN_GOLEM)
            {
                m_lGolemGUIDList.push_back(pSummoned->GetGUID());

                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    pSummoned->AI()->AttackStart(pTarget);

                //why healing when just summoned?
                pSummoned->CastSpell(pSummoned, DUNGEON_MODE(SPELL_HEAT_N, SPELL_HEAT_H), false, NULL, NULL, me->GetGUID());
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (m_bIsStriking)
            {
                if (m_uiPause_Timer <= uiDiff)
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    {
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                    }

                    m_bHasTemper = false;
                    m_bIsStriking = false;
                    m_uiPause_Timer = 3500;
                }
                else
                    m_uiPause_Timer -= uiDiff;

                return;
            }

            // When to start shatter? After 60, 40 or 20% hp?
            if (!m_bHasTemper && m_uiHealthAmountModifier >= 3)
            {
                if (m_uiShatteringStomp_Timer <= uiDiff)
                {
                    //should he stomp even if he has no brittle golem to shatter?

                    DoScriptText(RAND(SAY_STOMP_1,SAY_STOMP_2), me);

                    DoCast(me, SPELL_SHATTERING_STOMP_N);

                    DoScriptText(EMOTE_SHATTER, me);

                    m_uiShatteringStomp_Timer = 30000;
                    m_bCanShatterGolem = true;
                }
                else
                    m_uiShatteringStomp_Timer -= uiDiff;
            }

            // Shatter Golems 3 seconds after Shattering Stomp
            if (m_bCanShatterGolem)
            {
                if (m_uiShatter_Timer <= uiDiff)
                {
                    ShatterGolem();
                    m_uiShatter_Timer = 3000;
                    m_bCanShatterGolem = false;
                }
                else
                    m_uiShatter_Timer -= uiDiff;
            }

            // Health check
            if (!m_bCanShatterGolem && me->HealthBelowPct(100 - 20 * m_uiHealthAmountModifier))
            {
                ++m_uiHealthAmountModifier;

                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                DoScriptText(RAND(SAY_FORGE_1,SAY_FORGE_2), me);

                m_bHasTemper = true;

                DoCast(me, SPELL_TEMPER, false);
            }

            DoMeleeAttackIfReady();
        }
    };

};



/*######
## npc_volkhan_anvil
######*/

class npc_volkhan_anvil : public CreatureScript
{
public:
    npc_volkhan_anvil() : CreatureScript("npc_volkhan_anvil") { }

    bool EffectDummyCreature(Unit* pCaster, uint32 uiSpellId, uint32 uiEffIndex, Creature* pCreatureTarget)
    {
        //always check spellid and effectindex
        if (uiSpellId == SPELL_TEMPER && uiEffIndex == 0)
        {
            if (pCaster->GetEntry() != NPC_VOLKHAN || pCreatureTarget->GetEntry() != NPC_VOLKHAN_ANVIL)
                return true;

            Creature *cre = CAST_CRE(pCaster);

            DoScriptText(EMOTE_TO_ANVIL, pCaster);

            float fX, fY, fZ;
            pCreatureTarget->GetContactPoint(pCaster, fX, fY, fZ, INTERACTION_DISTANCE);

            pCaster->AttackStop();

            if (pCaster->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
                pCaster->GetMotionMaster()->MovementExpired();

            cre->GetMap()->CreatureRelocation(cre, fX, fY, fZ, pCreatureTarget->GetOrientation());
            cre->SendMonsterMove(fX, fY, fZ, 0, cre->GetUnitMovementFlags(), 1);

            pCreatureTarget->CastSpell(pCaster, SPELL_TEMPER_DUMMY, false);

            //always return true when we are handling this spell and effect
            return true;
        }

        return false;
    }

};

/*######
## mob_molten_golem
######*/

class mob_molten_golem : public CreatureScript
{
public:
    mob_molten_golem() : CreatureScript("mob_molten_golem") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_molten_golemAI(pCreature);
    }

    struct mob_molten_golemAI : public ScriptedAI
    {
        mob_molten_golemAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
        }

        bool m_bIsFrozen;

        uint32 m_uiBlast_Timer;
        uint32 m_uiDeathDelay_Timer;
        uint32 m_uiImmolation_Timer;

        void Reset()
        {
            m_bIsFrozen = false;

            m_uiBlast_Timer = 20000;
            m_uiDeathDelay_Timer = 0;
            m_uiImmolation_Timer = 5000;
        }

        void AttackStart(Unit* pWho)
        {
            if (me->Attack(pWho, true))
            {
                me->AddThreat(pWho, 0.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);

                if (!m_bIsFrozen)
                    me->GetMotionMaster()->MoveChase(pWho);
            }
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            if (uiDamage > me->GetHealth())
            {
                me->UpdateEntry(NPC_BRITTLE_GOLEM);
                me->SetHealth(1);
                uiDamage = 0;
                me->RemoveAllAuras();
                me->AttackStop();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
                    me->GetMotionMaster()->MovementExpired();
                m_bIsFrozen = true;
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
        {
            //this is the dummy effect of the spells
            if (pSpell->Id == SPELL_SHATTER_N || pSpell->Id == SPELL_SHATTER_H)
            {
                if (me->GetEntry() == NPC_BRITTLE_GOLEM)
                    me->ForcedDespawn();
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target or if we are frozen
            if (!UpdateVictim() || m_bIsFrozen)
                return;

            if (m_uiBlast_Timer <= uiDiff)
            {
                DoCast(me, SPELL_BLAST_WAVE);
                m_uiBlast_Timer = 20000;
            }
            else
                m_uiBlast_Timer -= uiDiff;

            if (m_uiImmolation_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_IMMOLATION_STRIKE_N);
                m_uiImmolation_Timer = 5000;
            }
            else
                m_uiImmolation_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};


void AddSC_boss_volkhan()
{
    new boss_volkhan();
    new npc_volkhan_anvil();
    new mob_molten_golem();
}
