/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
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
SDName: Boss_Ragnaros
SD%Complete:
SDComment:
SDCategory: Molten Core
EndScriptData */

/*
    Can't get Ragnaros to stay in EMOTE_STATE_SUBMERGED during combat,
    so just created a dummy visual creature to spawn in his place
*/

#include "scriptPCH.h"
#include "molten_core.h"

enum
{
    SAY_REINFORCEMENTS1       = -1409013,
    SAY_REINFORCEMENTS2       = -1409014,
    SAY_HAND                  = -1409015,
    SAY_WRATH                 = -1409016,
    SAY_KILL                  = -1409017,
    SAY_MAGMABURST            = -1409018,
    SAY_ARRIVAL5_RAG          = -1409012,

    SPELL_ELEMENTAL_FIRE_KILL = 19773, // Kill Majordomo

    SPELL_ELEMENTAL_FIRE_AURA = 20563, // Aura: trigger Elemental Fire (20564) on every hit
    SPELL_MELT_WEAPON_AURA    = 21387, // Aura: trigger Melt Weapon (21388) on melee damage taken
    SPELL_WRATH_OF_RAGNAROS   = 20566, // PBAOE Knockback
    SPELL_MAGMA_BLAST         = 20565, // Ranged attack when no one in melee range
    SPELL_MIGHT_OF_RAGNAROS   = 21154, // Summon Flame of Ragnaros trigger to deal Knockback
    SPELL_INTENSE_HEAT        = 21155, // Knockback cast by Might of Ragnaros triggers
    SPELL_LAVASHIELD          = 21857, // Son of Flame mana drain aura -- this is applied in creature_template_addon

    SPELL_SUBMERGE_VISUAL     = 26234,
    SPELL_SUBMERGE_FADE       = 21107, // Stealth aura
    SPELL_SUBMERGE_EFFECT     = 21859,
    SPELL_EMERGE_VISUAL       = 20568,

    NPC_FLAME_OF_RAGNAROS     = 13148,
    NPC_SON_OF_FLAME          = 12143,

    NPC_SUBMERGED_VISUAL      = 21000, // dummy visual for flames/sound in lava pool where Rag submerges

    GO_LAVA_BURST             = 178088,

    MAX_ADDS_IN_SUBMERGE      = 8
};

// Lava Burst locations
float PositionOfLavaBursts[9][3]=
{
    {812.0f, -821.0f, -232.0f},
    {832.0f, -798.0f, -232.0f},
    {820.0f, -745.0f, -232.0f},
    {865.0f, -807.0f, -232.0f},
    {894.0f, -792.0f, -232.0f},
    {874.0f, -839.0f, -232.0f},
    {862.0f, -869.0f, -232.0f}, 
    {827.0f, -873.0f, -231.3f},
    {760.0f, -827.0f, -232.0f}
};

// Sons of Ragnaros spawn positions
float PositionOfAdds[8][4]=
{
    {848.740356f, -816.103455f, -229.743270f, 2.615287f},
    {852.560791f, -849.861511f, -228.560974f, 2.836073f},
    {808.710632f, -852.845764f, -227.914963f, 0.964207f},
    {786.597107f, -821.132874f, -226.350128f, 0.949377f},
    {796.219116f, -800.948059f, -226.010361f, 0.560603f},
    {821.602539f, -782.744109f, -226.023575f, 6.157440f},
    {844.924744f, -769.453735f, -225.521698f, 4.4539958f},
    {839.823364f, -810.869385f, -229.683182f, 4.693108f}
};

class ThreatListCopier : public ThreatListProcesser
{
public:
    explicit ThreatListCopier(Unit* destination) : _dest(destination) {}

    bool Process(Unit* unit) override
    {
        _dest->AI()->AttackStart(unit);
        return false;
    }

    Unit* _dest;
};

struct boss_ragnarosAI : ScriptedAI
{
    explicit boss_ragnarosAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(pCreature->GetInstanceData());
        SetCombatMovement(false);

        boss_ragnarosAI::Reset();
    }

    uint32 m_uiWrathOfRagnarosTimer;
    uint32 m_uiMightOfRagnarosTimer;
    uint32 m_uiMagmaBlastTimer;
    uint32 m_uiLavaBurstTimer;
    uint32 m_uiLavaBurstSecondaryTimer;
    uint32 m_uiLavaBurstTertiaryTimer;
    uint32 m_uiRestoreTargetTimer;
    uint32 m_uiSubmergeTimer;
    uint32 m_uiAttackTimer;

    uint32 m_uiSubmergeStateTimer;
    uint32 m_uiEmergeStateTimer;

    uint32 m_uiEnterCombatTimer;

    bool HasYelledAggro;
    bool HasYelledMagmaBlast;
    bool HasSubmergedOnce;
    bool IsBanished;
    bool HasAura;
    bool Explosion;
    bool m_bInMelee;

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        m_uiMagmaBlastTimer         = 2000;
        m_uiWrathOfRagnarosTimer    = urand(25000, 30000);
        m_uiMightOfRagnarosTimer    = urand(10000, 15000);
        m_uiRestoreTargetTimer      = 0;
        m_uiLavaBurstTimer          = urand(10000, 15000);
        m_uiLavaBurstSecondaryTimer = 0;
        m_uiLavaBurstTertiaryTimer  = 0;

        m_uiSubmergeTimer           = 3*MINUTE*IN_MILLISECONDS;   // P1
        m_uiAttackTimer             = 1.5*MINUTE*IN_MILLISECONDS; // P2
        m_uiSubmergeStateTimer      = 0;
        m_uiEmergeStateTimer        = 0;

        m_uiEnterCombatTimer        = 0;

        HasYelledMagmaBlast         = false;
        HasSubmergedOnce            = false;
        IsBanished                  = false;
        Explosion                   = false;
        HasYelledAggro              = false;
        m_bInMelee                  = false;

        HasAura = true;

        if (m_pInstance && m_creature->IsAlive())
        {
            m_pInstance->SetData(TYPE_RAGNAROS, NOT_STARTED);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        }

        // clean up dummy visual if raid wiped during P2
        if (Creature* pVisual = m_creature->FindNearestCreature(NPC_SUBMERGED_VISUAL, 50.0f, true))
            pVisual->RemoveFromWorld();
    }

    void Aggro(Unit* pWho) override
    {
        if (pWho->GetTypeId() == TYPEID_UNIT && pWho->GetEntry() == NPC_DOMO)
            return;

        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_RAGNAROS, IN_PROGRESS);
            if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC))
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
        m_creature->SetInCombatWithZone();
        DoCastSpellIfCan(m_creature, SPELL_MELT_WEAPON_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);        
        DoCastSpellIfCan(m_creature, SPELL_ELEMENTAL_FIRE_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);
    }

    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        // As Majordomo is now killed, the last timer (until attacking) must be handled with Ragnaros script
        if (pSpell->Id == SPELL_ELEMENTAL_FIRE_KILL && pTarget->GetTypeId() == TYPEID_UNIT && pTarget->GetEntry() == NPC_DOMO)
            m_uiEnterCombatTimer = 7000;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAGNAROS, DONE);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetEntry() == 12018)
            return;

        DoScriptText(SAY_KILL, m_creature);
    }

    void SummonSonsOfFlame() const
    {
        for (const auto& position : PositionOfAdds)
        {
            ThreatListCopier* dataCopier = new ThreatListCopier(m_creature);
            if (Creature* Crea = m_creature->SummonCreature(NPC_SON_OF_FLAME, 
                position[0],
                position[1],
                position[2],
                position[3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
            {
                m_creature->ProcessThreatList(dataCopier);
                if (Unit* randomTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    Crea->GetThreatManager().modifyThreatPercent(randomTarget, 90);
                    Crea->AI()->AttackStart(randomTarget);
                    Crea->GetMotionMaster()->MoveChase(randomTarget);
                }
            }
            delete dataCopier;
        }
    }

    void UpdateLavaBurstAI(uint32 diff)
    {
        // Lava Bursts spawn in waves of three
        if (m_uiLavaBurstTimer < diff)
        {
            DoLavaBurst();
            m_uiLavaBurstTimer = urand (15000, 20000);
            m_uiLavaBurstSecondaryTimer = urand (2000, 4000);
        }
        else
            m_uiLavaBurstTimer -= diff;
            
        if (m_uiLavaBurstSecondaryTimer)
        {
            if (m_uiLavaBurstSecondaryTimer < diff)
            {
                DoLavaBurst();
                m_uiLavaBurstSecondaryTimer = 0;
                m_uiLavaBurstTertiaryTimer = urand (2000, 4000);
            }
            else
                m_uiLavaBurstSecondaryTimer -= diff;
        }
        
        if (m_uiLavaBurstTertiaryTimer)
        {
            if (m_uiLavaBurstTertiaryTimer < diff)
            {
                DoLavaBurst();
                m_uiLavaBurstTertiaryTimer = 0;
            }
            else
                m_uiLavaBurstTertiaryTimer -= diff;
        }
    }

    void DoLavaBurst() const
    {
        uint8 m_uiLavaBurstPoint = urand(0, 8);
        if (GameObject* pGo = m_creature->SummonGameObject(GO_LAVA_BURST, 
            PositionOfLavaBursts[m_uiLavaBurstPoint][0], 
            PositionOfLavaBursts[m_uiLavaBurstPoint][1], 
            PositionOfLavaBursts[m_uiLavaBurstPoint][2], frand(0, M_PI_F), 0, 0, 0, 0, 0))
        {
            pGo->Use(m_creature);            
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        // After killing Majordomo
        if (m_uiEnterCombatTimer)
        {
            if (m_uiEnterCombatTimer <= diff)
            {
                if (!HasYelledAggro)
                {
                    // 7 seconds have passed, do emote and yell
                    m_creature->HandleEmote(EMOTE_ONESHOT_ROAR);
                    DoScriptText(SAY_ARRIVAL5_RAG, m_creature);
                    m_creature->SetInCombatWithZone();
                    HasYelledAggro = true;
                    m_uiEnterCombatTimer = 3000;
                    return;
                }
                else
                {
                    // 10 seconds have passed, engage the raid
                    m_creature->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
                    m_uiEnterCombatTimer = 0;
                }
            }
            else
            {
                m_uiEnterCombatTimer -= diff;
                return;
            }
        }

        if (m_creature->GetUInt32Value(UNIT_FIELD_FLAGS) == UNIT_FLAG_NON_ATTACKABLE)
            return;

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC))
            return;

        // For transition back to P1, return during emerge visual cast animation
        if (m_uiEmergeStateTimer)
        {
            if (m_uiEmergeStateTimer <= diff)
                m_uiEmergeStateTimer = 0;
            else
            {
                m_uiEmergeStateTimer -= diff;
                return;
            }
        }

        // Phase 2 -----------------------------------------------------------------------------------

        if (IsBanished && m_uiAttackTimer < diff)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_SUBMERGE_FADE);
            m_creature->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
            m_creature->SetFactionTemplateId(14);
            m_creature->SetVisibility(VISIBILITY_ON);

            if (DoCastSpellIfCan(m_creature, SPELL_EMERGE_VISUAL) == CAST_OK)
            {
                // remove dummy visual
                if (Creature* pVisual = m_creature->FindNearestCreature(NPC_SUBMERGED_VISUAL, 50.0f, true))
                    pVisual->RemoveFromWorld();
                // Become unbanished again
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                IsBanished = false;
                m_uiMagmaBlastTimer = 3000;
                HasYelledMagmaBlast = false;
                m_uiEmergeStateTimer = 2900;
                return;
            }

            sLog.outError("[MoltenCore.Ragnaros] Cast %u impossible.", SPELL_EMERGE_VISUAL);
        }
        else if (IsBanished)
        {
            m_uiAttackTimer -= diff;
            if (m_uiAttackTimer > 1500)
            {
                bool Allbanished = true;
                std::list<Creature*> FilsListe;
                GetCreatureListWithEntryInGrid(FilsListe, m_creature, NPC_SON_OF_FLAME, 150.0f);

                for (const auto& itr : FilsListe)
                {
                    if (itr->IsAlive())
                    {
                        if (!itr->HasUnitState(UNIT_STAT_ISOLATED)) // banished
                        {
                            Allbanished = false;
                            break;
                        }
                    }
                }
                if (Allbanished)
                    m_uiAttackTimer = 0;
            }

            if (m_uiSubmergeStateTimer)
            {
                if (m_uiSubmergeStateTimer <= diff)
                {
                    // create dummy to handle sound and lava flame visual
                    if (Creature* pVisual = m_creature->SummonCreature(NPC_SUBMERGED_VISUAL, 
                        m_creature->GetPositionX(), 
                        m_creature->GetPositionY(), 
                        m_creature->GetPositionZ(), 
                        m_creature->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 95000))
                    {
                       pVisual->HandleEmoteState(EMOTE_STATE_SUBMERGED);                        
                    }

                    m_creature->SetVisibility(VISIBILITY_OFF);
                    m_creature->SetFactionTemplateId(35);
                    m_uiSubmergeStateTimer = 0;
                }
                else
                    m_uiSubmergeStateTimer -= diff;
            }
            else if (!m_creature->HasAura(SPELL_SUBMERGE_FADE))
                m_creature->CastSpell(m_creature, SPELL_SUBMERGE_FADE, false);

            UpdateLavaBurstAI(diff);
            return;
        }

        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Phase 1 -----------------------------------------------------------------------------------

        UpdateLavaBurstAI(diff);

        // Restore target after casting Might of Ragnaros
        if (m_uiRestoreTargetTimer)
        {
            if (m_uiRestoreTargetTimer <= diff)
            {
                if (Unit *pTarget = m_creature->GetVictim())
                {
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_creature->SetFacingToObject(pTarget);
                    m_uiRestoreTargetTimer = 0;
                }
            }
            else
                m_uiRestoreTargetTimer -= diff;
        }

        // Timer to Phase 2
        if (!IsBanished && m_uiSubmergeTimer < diff)
        {
            //Creature spawning and ragnaros becomming unattackable
            //is not very well supported in the core
            //so added normaly spawning and banish workaround and attack again after 90 secs.

            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (DoCastSpellIfCan(m_creature, SPELL_SUBMERGE_VISUAL, CF_INTERRUPT_PREVIOUS) == CAST_OK)
            {
                //Root self
                DoCastSpellIfCan(m_creature, 17507);

                DoScriptText(HasSubmergedOnce ? SAY_REINFORCEMENTS2 : SAY_REINFORCEMENTS1, m_creature);

                SummonSonsOfFlame();

                HasSubmergedOnce  = true;
                IsBanished        = true;
                m_uiSubmergeTimer = 3*MINUTE*IN_MILLISECONDS;
                m_uiAttackTimer   = 1.5*MINUTE*IN_MILLISECONDS;
                m_uiSubmergeStateTimer = 1500;
                return;
            }
        }
        else if (m_uiSubmergeTimer >= diff)
            m_uiSubmergeTimer -= diff;

        // Wrath of Ragnaros
        if (m_uiWrathOfRagnarosTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_WRATH_OF_RAGNAROS) == CAST_OK)
            {
                DoResetThreat();
                m_uiWrathOfRagnarosTimer = urand(25000, 30000);
                DoScriptText(SAY_WRATH, m_creature);
            }
        }
        else
            m_uiWrathOfRagnarosTimer -= diff;

        // Might of Ragnaros
        if (m_uiMightOfRagnarosTimer < diff)
        {
            std::vector<Player*> manaPlayers;

            ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
            for (const auto itr : tList)
            {
                Player* pPlayer = m_creature->GetMap()->GetPlayer(itr->getUnitGuid());
                if (pPlayer && pPlayer->IsAlive() && pPlayer->GetPowerType() == POWER_MANA && !pPlayer->IsGameMaster())
                    manaPlayers.push_back(pPlayer);
            }
            if (!manaPlayers.empty())
            {
                if (Player* pTarget = manaPlayers[urand(0, manaPlayers.size() - 1)])
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_MIGHT_OF_RAGNAROS) == CAST_OK)
                    {
                        m_creature->SetInFront(pTarget);
                        m_creature->SetTargetGuid(pTarget->GetObjectGuid());  // Ragnaros faces targets he casts Might of Ragnaros on
                        m_uiMightOfRagnarosTimer = urand(9000, 14000);
                        m_uiRestoreTargetTimer = 800;
                        if (urand(0, 1))
                            DoScriptText(SAY_HAND, m_creature);
                    }
                }
            }
        }
        else
            m_uiMightOfRagnarosTimer -= diff;

        // every tick we check for melee targets to attack
        CheckForMelee();

        if (m_bInMelee && HasYelledMagmaBlast)
        {
            HasYelledMagmaBlast = false;
            m_uiMagmaBlastTimer = 3000;
        }

        // no one is engaged in melee for some seconds - burn, baby, burn
        if (!m_bInMelee)
        {
            // Magma Blast
            if (m_uiMagmaBlastTimer < diff)
            {
                if (!HasYelledMagmaBlast)
                {
                    DoScriptText(SAY_MAGMABURST, m_creature);
                    HasYelledMagmaBlast = true;
                }

                // at first we try to select player, then pet
                Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM);
                
                if (!target)
                    target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PET);

                if (target)
                {
                    auto canCastResult = DoCastSpellIfCan(target, SPELL_MAGMA_BLAST);

                    if (!canCastResult)
                        m_uiMagmaBlastTimer = 2500;
                    else
                        sLog.outError("[MoltenCore.Ragnaros] Magma Blast failed with reason <%u>.", canCastResult);

                    return;
                }

                sLog.outError("[MoltenCore.Ragnaros] No target to Magma Blast.");
            }
            else
                m_uiMagmaBlastTimer -= diff;
        }
    }

    void CheckForMelee()
    {
        // at first we check for the current player-type target
        Unit* pMainTarget = m_creature->GetVictim();
        if (pMainTarget && pMainTarget->IsPlayer() && !pMainTarget->ToPlayer()->IsGameMaster() && 
            m_creature->CanReachWithMeleeAutoAttack(pMainTarget) && m_creature->IsWithinLOSInMap(pMainTarget))
        {
            m_bInMelee = true;

            if (m_creature->IsAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->AttackerStateUpdate(pMainTarget);
                m_creature->ResetAttackTimer();
            }

            return;
        }

        // at second we look for any melee player-type target (if current target is not reachable)
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0, nullptr, 
            SELECT_FLAG_PLAYER_NOT_GM | SELECT_FLAG_IN_LOS | SELECT_FLAG_IN_MELEE_RANGE))
        {
            m_bInMelee = true;

            // erase current target's threat as soon as we switch the target now
            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            // give the new target aggro
            m_creature->GetThreatManager().modifyThreatPercent(pTarget, 100);

            if (m_creature->IsAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->AttackerStateUpdate(pTarget);
                m_creature->ResetAttackTimer();
            }

            return;
        }

        // reaching this point means there are no more reachable player-type targets in melee range
        m_bInMelee = false;
        
        // at third we take any melee pet target just to punch in the face
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0, nullptr,
            SELECT_FLAG_PET | SELECT_FLAG_IN_LOS | SELECT_FLAG_IN_MELEE_RANGE))
        {
            // erase current target's threat as soon as we switch the target now
            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            // give the new target aggro
            m_creature->GetThreatManager().modifyThreatPercent(pTarget, 100);

            if (m_creature->IsAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->AttackerStateUpdate(pTarget);
                m_creature->ResetAttackTimer();
            }

            return;
        }

        // at fourth we take anything to wipe it out and log (whatever, just in case)
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0, nullptr,
            SELECT_FLAG_NOT_PLAYER | SELECT_FLAG_IN_LOS | SELECT_FLAG_IN_MELEE_RANGE))
        {
            // erase current target's threat as soon as we switch the target now
            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            // give the new target aggro
            m_creature->GetThreatManager().modifyThreatPercent(pTarget, 100);

            if (m_creature->IsAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->AttackerStateUpdate(pTarget);
                m_creature->ResetAttackTimer();
            }

            //sLog.outError("[MoltenCore.Ragnaros] Target type #4 reached with name <%s> and entry <%u>.", pTarget->GetName(), pTarget->GetEntry());
        }

        // nothing in melee at all
        //sLog.outError("[MoltenCore.Ragnaros] CheckForMelee hits the end. Nothing in melee.");
    }
};

CreatureAI* GetAI_boss_ragnaros(Creature* pCreature)
{
    return new boss_ragnarosAI(pCreature);
}



void AddSC_boss_ragnaros()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_ragnaros";
    newscript->GetAI = &GetAI_boss_ragnaros;
    newscript->RegisterSelf();

}
