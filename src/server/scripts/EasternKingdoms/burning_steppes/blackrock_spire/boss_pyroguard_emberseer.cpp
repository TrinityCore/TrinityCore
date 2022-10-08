/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Pyroguard_Emberseer
SD%Complete: 100
SDComment: Event to activate Emberseer NYI - 'aggro'-text missing
SDCategory: Blackrock Spire
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_spire.h"

enum
{
    SPELL_FIRENOVA          = 23462,
    SPELL_FLAMEBUFFET       = 23341,
    SPELL_PYROBLAST         = 20228,                        // guesswork, but best fitting in spells-area, was 17274 (has mana cost)

    CANALISEURS_ENTRY           = 10316,

    SPELL_MISE_EN_CAGE          = 15281,
    SPELL_SELF_CAGE             = 15282,
    AURA_PLAYER_CANALISATION    = 16532,
    SPELL_PLAYER_MISE_EN_CAGE   = 16045,

    SPELL_LIBERATION            = 16047,
    SPELL_GROWTH                = 16048,

    DOOR_OPEN_ID                = 175705,

    REQUIRED_SUMMONERS          = 3,
    SAY_BOSS_FREE               = 5268
};

struct boss_pyroguard_emberseerAI : public ScriptedAI
{
    boss_pyroguard_emberseerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_blackrock_spire*) pCreature->GetInstanceData();
        initialized = false;
        Reset();
    }

    instance_blackrock_spire* m_pInstance;
    uint32 m_uiFireNovaTimer;
    uint32 m_uiFlameBuffetTimer;
    uint32 m_uiPyroBlastTimer;

    std::set<Player*> sSummoners;

    // NOSTALRIUS
    bool initialized;
    bool bCanalisationEnCours;
    bool bBossEnferme;
    std::vector<ObjectGuid> canaliseurs;

    void RespawnAddWarlocks()
    {
        std::vector<ObjectGuid>::iterator it;
        for (it = canaliseurs.begin(); it != canaliseurs.end(); ++it)
            if (Creature* pCanaliser = m_creature->GetMap()->GetCreature(*it))
            {
                if (!pCanaliser->IsAlive())
                    pCanaliser->Respawn();
                pCanaliser->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
            }
    }

    bool Initialize()
    {
        std::list<Creature*> tmpFoundCrea;
        GetCreatureListWithEntryInGrid(tmpFoundCrea, m_creature, CANALISEURS_ENTRY, 35.0f);
        while (!tmpFoundCrea.empty())
        {
            canaliseurs.push_back(tmpFoundCrea.front()->GetObjectGuid());
            tmpFoundCrea.pop_front();
        }

        if (canaliseurs.empty())
            return false;

        // Tous doivent etre en vie au debut de l'event.
        RespawnAddWarlocks();
        if (!m_creature->HasAura(SPELL_SELF_CAGE))
            m_creature->CastSpell(m_creature, SPELL_SELF_CAGE, false);
        return true;
    }

    // Tous les canaliseurs sont-ils morts ?
    bool AreAllWarlockDead()
    {
        std::vector<ObjectGuid>::iterator it;
        for (it = canaliseurs.begin(); it != canaliseurs.end(); ++it)
            if (Creature* pCanaliser = m_creature->GetMap()->GetCreature(*it))
                if (pCanaliser->IsAlive())
                    return false;
        return true;
    }

    void RefreshCanalisation()
    {
        if (!m_pInstance)
            return;
        std::set<Player*>::iterator it;
        GameObject* pGo = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_BLACKROCK_ALTAR));
        Map::PlayerList const &pl = m_creature->GetMap()->GetPlayers();
        for (const auto& it2 : pl)
        {
            Player* currPlayer = it2.getSource();
            if (currPlayer)
            {
                it = sSummoners.find(currPlayer);
                bool isUsing = pGo->HasUniqueUser(currPlayer);
                if (isUsing && it == sSummoners.end())
                    sSummoners.insert(currPlayer);
                else if (!isUsing && it != sSummoners.end())
                    sSummoners.erase(currPlayer);
            }
        }
    }

    void StartWarlocksCombat()
    {
        std::set<Player*>::const_iterator itSummoners;

        // Le combat avec les adds commence
        m_pInstance->SetData(TYPE_EMBERSEER, SPECIAL);
        for (const auto& guid : canaliseurs)
        {
            Creature *currCanaliseur = m_creature->GetMap()->GetCreature(guid);
            if (!currCanaliseur)
                continue;
            currCanaliseur->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
            currCanaliseur->InterruptNonMeleeSpells(false);
            if (currCanaliseur->AI())
            {
                itSummoners = sSummoners.begin();
                if (itSummoners != sSummoners.end())
                    std::advance(itSummoners, urand(0, sSummoners.size() - 1));
                currCanaliseur->AI()->AttackStart(*itSummoners);
            }
        }
        bCanalisationEnCours = false;
        bBossEnferme = true;
    }

    void EventBossLiberation()
    {
        m_creature->RemoveAllAuras();
        m_creature->CastSpell(m_creature, SPELL_LIBERATION, true);
        m_creature->CastSpell(m_creature, SPELL_GROWTH, true);
        m_creature->MonsterSay(SAY_BOSS_FREE, LANG_UNIVERSAL, 0);

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
        // On attaque tout le monde.
        Map::PlayerList const &pl = m_creature->GetMap()->GetPlayers();
        for (const auto& it2 : pl)
        {
            Player* currPlayer = it2.getSource();
            if (currPlayer && currPlayer->IsAlive() && m_creature->IsInRange(currPlayer, 0.0f, 50.0f))
                AttackStart(currPlayer);
        }
        m_creature->SetInCombatWithZone();

        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE01, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE02, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE03, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE04, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE05, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE06, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_EMBERSEER_RUNE07, 100.0f))
            pGo->SetGoState(GO_STATE_ACTIVE);

    }
    // END NOSTALRIUS

    void Reset() override
    {
        m_uiFireNovaTimer = 6000;
        m_uiFlameBuffetTimer = 3000;
        m_uiPyroBlastTimer = 14000;

        // NOSTALRIUS
        bCanalisationEnCours = true;
        bBossEnferme = true;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void AttackStart(Unit *target) override
    {
        // $target commence a nous attaquer.
        // Pas de combat autorise avec le boss.
        if (bCanalisationEnCours || bBossEnferme)
            return;

        // Sinon, go attaquer.
        if (m_creature->Attack(target, true))
        {
            m_creature->AddThreat(target);
            m_creature->SetInCombatWith(target);
            target->SetInCombatWith(m_creature);

            m_creature->GetMotionMaster()->MoveChase(target);
        }
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EMBERSEER, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EMBERSEER, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EMBERSEER, FAIL);
        RespawnAddWarlocks();
        bCanalisationEnCours = true;
        if (!m_creature->HasAura(SPELL_SELF_CAGE))
            m_creature->CastSpell(m_creature, SPELL_SELF_CAGE, false);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_pInstance)
            return;
        if (!initialized)
        {
            Initialize();
            initialized = true;
        }
        // Return since we have no target
        if (bCanalisationEnCours)
        {
            RefreshCanalisation();
            return;
        }
        if (bBossEnferme)
        {
            if (AreAllWarlockDead())
            {
                bBossEnferme = false;
                EventBossLiberation();
            }
            return;
        }

        // Sinon, on est "normalement" en combat.
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // FireNova Timer
        if (m_uiFireNovaTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_FIRENOVA);
            m_uiFireNovaTimer = 6000;
        }
        else
            m_uiFireNovaTimer -= uiDiff;

        // FlameBuffet Timer
        if (m_uiFlameBuffetTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_FLAMEBUFFET);
            m_uiFlameBuffetTimer = 14000;
        }
        else
            m_uiFlameBuffetTimer -= uiDiff;

        // PyroBlast Timer
        if (m_uiPyroBlastTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCastSpellIfCan(pTarget, SPELL_PYROBLAST);
            m_uiPyroBlastTimer += 15000;
        }
        else
            m_uiPyroBlastTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

// Return true to avoid db script attempt
bool ProcessEventId_event_free_pyroguard_emberseer(uint32 eventId, Object* source, Object* target, bool isStart)
{
    if (!source || source->GetTypeId() != TYPEID_PLAYER)
        return true;

    // Cannot find altar
    if (!target)
        return true;

    if (ScriptedInstance* instance = dynamic_cast<ScriptedInstance*>(((Player*)source)->GetInstanceData()))
        if (Creature* pyroguardEmberseer = source->ToPlayer()->GetMap()->GetCreature(instance->GetData64(NPC_PYROGUARD_EMBERSEER)))
            if (boss_pyroguard_emberseerAI* bossAI = dynamic_cast<boss_pyroguard_emberseerAI*>(pyroguardEmberseer->AI()))
                bossAI->StartWarlocksCombat();
    return true;
}

CreatureAI* GetAI_boss_pyroguard_emberseer(Creature* pCreature)
{
    return new boss_pyroguard_emberseerAI(pCreature);
}

struct npc_geolier_main_noireAI : public ScriptedAI
{
    npc_geolier_main_noireAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_blackrock_spire*) pCreature->GetInstanceData();
        Reset();
    }

    instance_blackrock_spire* m_pInstance;
    uint32 MiseEnCage_Timer;
    uint32 Frappe_Timer;
    bool fled;
    // END NOSTALRIUS

    void Reset() override
    {
        MiseEnCage_Timer = urand(5000, 40000);
        Frappe_Timer     = urand(2000, 12100);
        fled = false;
    }

    void AttackStart(Unit *target) override
    {
        if (!m_pInstance)
            return;
        // Pas pret (event pas commence)
        if (m_pInstance->GetData(TYPE_EMBERSEER) != SPECIAL)
            return;

        // Sinon, go attaquer.
        if (m_creature->Attack(target, true))
        {
            m_creature->AddThreat(target);
            m_creature->SetInCombatWith(target);
            target->SetInCombatWith(m_creature);

            m_creature->GetMotionMaster()->MoveChase(target);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_EMBERSEER) != SPECIAL)
        {
            // Pas de combat autorise pour l'instant.
            if (!m_creature->IsNonMeleeSpellCasted(false, false, true))
                m_creature->CastSpell(m_creature, SPELL_MISE_EN_CAGE, false);
            // Regen vie
            m_creature->RegenerateHealth();
            return;
        }
        // Sinon go.
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        if (MiseEnCage_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (pTarget->IsWithinLOSInMap(m_creature) && !pTarget->HasAura(SPELL_PLAYER_MISE_EN_CAGE))
                {
                    m_creature->CastSpell(pTarget, SPELL_PLAYER_MISE_EN_CAGE, false);
                    MiseEnCage_Timer = urand(20000, 40000);
                }
            }
        }
        else
            MiseEnCage_Timer -= uiDiff;

        if (Frappe_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), 15580) == CAST_OK)
                Frappe_Timer = urand(7900, 14000);
        }
        else
            Frappe_Timer -= uiDiff;
        if (!fled && m_creature->GetHealthPercent() < 15.0f)
        {
            m_creature->DoFlee();
            fled = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_geolier_main_noire(Creature* pCreature)
{
    return new npc_geolier_main_noireAI(pCreature);
}

void AddSC_boss_pyroguard_emberseer()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_pyroguard_emberseer";
    pNewScript->GetAI = &GetAI_boss_pyroguard_emberseer;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_geolier_main_noire";
    pNewScript->GetAI = &GetAI_npc_geolier_main_noire;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "event_free_pyroguard_emberseer";
    pNewScript->pProcessEventId = &ProcessEventId_event_free_pyroguard_emberseer;
    pNewScript->RegisterSelf();
}
