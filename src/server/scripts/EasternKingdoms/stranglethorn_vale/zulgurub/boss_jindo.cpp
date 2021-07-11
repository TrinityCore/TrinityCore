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
SDName: Boss_Jin'do the Hexxer
SD%Complete: 85
SDComment: Mind Control not working because of core bug. Shades visible for all.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    SAY_AGGRO                       = 10449,

    SPELL_BRAIN_WASH_TOTEM          = 24262,
    SPELL_POWERFULL_HEALING_WARD    = 24309,
    SPELL_HEX                       = 24053,
    SPELL_DELUSIONS_OF_JINDO        = 24306,
    SPELL_SHADE_OF_JINDO            = 24308,
    // Brainwash Totem spells
    SPELL_BRAINWASH                 = 24261,
    // Healing Ward spells
    SPELL_HEAL                      = 24311,
    // Shade of Jindo spells
    SPELL_SHADOWSHOCK               = 24458,
    SPELL_INVISIBLE                 = 24307,

    NPC_SHADE                       = 14986,
    NPC_BRAINWASH_TOTEM             = 15112,
    NPC_POWERFULL_HEALING_WARD      = 14987
};

struct boss_jindoAI : public ScriptedAI
{
    boss_jindoAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 BrainWashTotem_Timer;
    uint32 HealingWard_Timer;
    uint32 Hex_Timer;
    uint32 Delusions_Timer;
    uint32 Teleport_Timer;

    uint32 CheckBrainWash_Timer;

    uint64 HexGuid;
    float HexAggro;

    std::list<uint64> BrainWashedPlayerGuid;
    std::list<float> BrainWashedPlayerAggro;
    std::list<ObjectGuid> summonedCreatures;

    void DespawnAllSummons()
    {
        while (!summonedCreatures.empty())
        {
            ObjectGuid const& g = *(summonedCreatures.begin());
            summonedCreatures.pop_front();
            switch (g.GetEntry())
            {
                case NPC_BRAINWASH_TOTEM:
                case NPC_SHADE:
                case NPC_POWERFULL_HEALING_WARD:
                    if (Creature* c = m_creature->GetMap()->GetCreature(g))
                        c->AddObjectToRemoveList();
                    break;
            }
        }
        while (Creature* Crea = m_creature->FindNearestCreature(NPC_BRAINWASH_TOTEM, 150.0f))
            Crea->DisappearAndDie();
    }
    void JustSummoned(Creature* c) override
    {
        summonedCreatures.push_back(c->GetObjectGuid());
        ScriptedAI::JustSummoned(c);
    }
    void Reset() override
    {
        BrainWashTotem_Timer    = 22000;
        HealingWard_Timer       = 12000;
        Hex_Timer               = 8000;
        Delusions_Timer         = 10000;
        Teleport_Timer          = 5000;
        CheckBrainWash_Timer    = 1000;

        HexGuid                 = 0;
        HexAggro                = 0;

        BrainWashedPlayerGuid.clear();
        BrainWashedPlayerAggro.clear();

        DespawnAllSummons();

        if (m_pInstance)
            m_pInstance->SetData(TYPE_JINDO, NOT_STARTED);
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_HEX)
        {
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            HexGuid = pCaster->GetGUID();
            HexAggro = m_creature->GetThreatManager().getThreat(pCaster);

            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -100);
        }
    }

    void JustDied(Unit* pKiller) override
    {
        DespawnAllSummons();
        if (m_pInstance)
            m_pInstance->SetData(TYPE_JINDO, DONE);
    }

    void Aggro(Unit *who) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if (m_pInstance)
            m_pInstance->SetData(TYPE_JINDO, IN_PROGRESS);
    }

    void DoSummonSkeleton(float addx, float addy, Unit* initialTarget)
    {
        Creature* Skeleton = m_creature->SummonCreature(14826, -11583.7783f + addx, -1249.4278f + addy, 77.5471f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
        if (Skeleton && Skeleton->AI())
            Skeleton->AI()->AttackStart(initialTarget);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (HexGuid)
        {
            Player* hexPlayer = m_creature->GetMap()->GetPlayer(HexGuid);
            if (hexPlayer && !hexPlayer->HasAura(SPELL_HEX))
            {
                m_creature->GetThreatManager().addThreatDirectly(hexPlayer, HexAggro);
                HexGuid = 0;
                HexAggro = 0;
            }
            else if (!hexPlayer)
                HexGuid = HexAggro = 0;
        }

        //BrainWashTotem_Timer
        if (BrainWashTotem_Timer < diff)
        {
            // Il faut au moins 2 personnes dans le threatlist de Jin'do, sinon il va reset !
            if (m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1))
                if (DoCastSpellIfCan(m_creature, SPELL_BRAIN_WASH_TOTEM) == CAST_OK)
                    BrainWashTotem_Timer = urand(18000, 22000);
        }
        else
            BrainWashTotem_Timer -= diff;

        // Ustaag : gestion de l'aggro des joueurs MC
        if (!BrainWashedPlayerGuid.empty() && !BrainWashedPlayerAggro.empty())
        {
            if (CheckBrainWash_Timer < diff)
            {
                uint64 PlayerBrainWashedGuid = 0;
                bool PlayerDead = false;
                bool AuraRemoved = false;

                uint32 var = 0;
                for (const auto& guid : BrainWashedPlayerGuid)
                {
                    if (Player* pTarget = m_creature->GetMap()->GetPlayer(guid))
                    {
                        if ((pTarget->IsAlive() && !pTarget->HasAura(24261, EFFECT_INDEX_0)) || pTarget->IsDead()) // SPELL_BRAINWASH 24261
                        {
                            PlayerBrainWashedGuid = guid;
                            if (pTarget->IsDead())
                                PlayerDead = true;
                            else
                                AuraRemoved = true;
                            break;
                        }
                        ++var;
                    }
                }

                if (PlayerDead || AuraRemoved)
                {
                    std::list<float>::const_iterator Iter = BrainWashedPlayerAggro.begin();
                    for (uint32 i = 0; i < var; ++i)
                        ++Iter;
                    Player* playerBrainWashed = m_creature->GetMap()->GetPlayer(PlayerBrainWashedGuid);
                    if (AuraRemoved)
                    {
                        m_creature->GetThreatManager().modifyThreatPercent(playerBrainWashed, -100);
                        m_creature->GetThreatManager().addThreatDirectly(playerBrainWashed, (*Iter));
                    }

                    BrainWashedPlayerGuid.remove(PlayerBrainWashedGuid);
                    BrainWashedPlayerAggro.remove(*Iter);
                }
            }
            else
                CheckBrainWash_Timer -= diff;
        }

        //HealingWard_Timer
        if (HealingWard_Timer < diff)
        {
            if (!m_creature->FindNearestCreature(NPC_POWERFULL_HEALING_WARD, 200.0f))
            {
                DoCastSpellIfCan(m_creature, SPELL_POWERFULL_HEALING_WARD);
                //m_creature->SummonCreature(NPC_POWERFULL_HEALING_WARD, m_creature->GetPositionX() + 3, m_creature->GetPositionY() - 2, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                HealingWard_Timer = urand(18000, 22000);
            }
        }
        else
            HealingWard_Timer -= diff;

        //Hex_Timer
        if (Hex_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HEX) == CAST_OK)
                Hex_Timer = urand(12000, 20000);
        }
        else
            Hex_Timer -= diff;

        //Casting the delusion curse with a shade. So shade will attack the same target with the curse.
        if (Delusions_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER))
            {
                if (DoCastSpellIfCan(target, SPELL_DELUSIONS_OF_JINDO) == CAST_OK)
                {
                    Creature *Shade = m_creature->SummonCreature(NPC_SHADE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                    if (Shade)
                    {
                        // Ajoute les ennemis du boss dans sa liste de menace.
                        Shade->AddThreatsOf(m_creature);
                        Shade->AI()->AttackStart(target);
                    }
                    Delusions_Timer = urand(4000, 12000);
                }
            }

        }
        else Delusions_Timer -= diff;

        //Teleporting a random gamer and spawning 9 skeletons that will attack this gamer
        if (Teleport_Timer < diff)
        {
            Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target && target->GetTypeId() == TYPEID_PLAYER)
                DoTeleportPlayer(target, -11583.7783f, -1249.4278f, 77.5471f, 4.745f);

            Teleport_Timer = urand(15000, 23000);
        }
        else
            Teleport_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Shade of Jindo
struct mob_shade_of_jindoAI : public ScriptedAI
{
    mob_shade_of_jindoAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 ShadowShock_Timer;

    void Reset() override
    {
        ShadowShock_Timer = 1000;
        m_creature->AddAura(SPELL_INVISIBLE, ADD_AURA_PERMANENT);
    }

    void DamageTaken(Unit *done_by, uint32 &damage) override
    {
        if (done_by && !done_by->HasAura(SPELL_DELUSIONS_OF_JINDO))
            damage = 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetVictim()->HasAura(SPELL_HEX))
            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

        //ShadowShock_Timer
        if (ShadowShock_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWSHOCK);
            ShadowShock_Timer = 2000;
        }
        else
            ShadowShock_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_brain_wash_totemAI : public ScriptedAI
{
    mob_brain_wash_totemAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint64 PlayerMCGuid;
    uint32 CheckTimer;

    void Reset() override
    {
        PlayerMCGuid = 0;
        CheckTimer = 0;

        m_creature->AddAura(23198, ADD_AURA_PERMANENT); // Avoidance : pas touché par les AOE
        m_creature->AddUnitState(UNIT_STAT_ROOT);
        SetCombatMovement(false);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || !m_pInstance)
        {
            m_creature->DisappearAndDie();
            return;
        }

        m_creature->AddUnitState(UNIT_STAT_ROOT);

        if (!m_creature->IsInCombat())
            m_creature->SetInCombatWithZone();

        // Deja en train de CM le joueur
        if (PlayerMCGuid)
            if (Player* pPlayer = m_creature->GetMap()->GetPlayer(PlayerMCGuid))
                if (pPlayer->IsAlive() && pPlayer->HasAura(24261, EFFECT_INDEX_0))
                    return;


        if (Creature* pJindo = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_JINDO)))
        {
            // Il faut au moins 2 personnes dans le threatlist de Jin'do, sinon il va reset !
            if (pJindo->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1))
            {
                Unit* pTarget = pJindo ? pJindo->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0) : nullptr;
                if (pTarget && pTarget->IsAlive() && pTarget->IsPlayer() && !pTarget->HasAura(SPELL_HEX) && !pTarget->HasAura(SPELL_BRAINWASH))
                {
                    if (boss_jindoAI* pJindoAI = dynamic_cast<boss_jindoAI*>(pJindo->AI()))
                    {
                        pJindoAI->BrainWashedPlayerGuid.push_back(pTarget->GetGUID());
                        pJindoAI->BrainWashedPlayerAggro.push_back(pJindo->GetThreatManager().getThreat(pTarget));
                        if (DoCastSpellIfCan(pTarget, SPELL_BRAINWASH) == CAST_OK)
                        {
                            PlayerMCGuid = pTarget->GetGUID();
                            pJindoAI->CheckBrainWash_Timer = 1000;
                        }
                    }
                }
            }
        }
    }
};

CreatureAI* GetAI_boss_jindo(Creature* pCreature)
{
    return new boss_jindoAI(pCreature);
}

CreatureAI* GetAI_mob_shade_of_jindo(Creature* pCreature)
{
    return new mob_shade_of_jindoAI(pCreature);
}

CreatureAI* GetAI_mob_brain_wash(Creature* pCreature)
{
    return new mob_brain_wash_totemAI(pCreature);
}

// UPDATE `creature_template` SET `ai_name` = '', `script_name` = 'mob_brain_wash' WHERE `entry` = 15112;
void AddSC_boss_jindo()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_jindo";
    newscript->GetAI = &GetAI_boss_jindo;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_shade_of_jindo";
    newscript->GetAI = &GetAI_mob_shade_of_jindo;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_brain_wash";
    newscript->GetAI = &GetAI_mob_brain_wash;
    newscript->RegisterSelf();
}
