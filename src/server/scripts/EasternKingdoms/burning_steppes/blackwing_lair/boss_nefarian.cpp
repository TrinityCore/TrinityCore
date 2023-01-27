/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
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
SDName: Boss_Nefarian
SD%Complete: 80
SDComment: Some issues with class calls effecting more than one class
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    SAY_AGGRO                   = 9973,
    SAY_SHADOWFLAME             = 9974,
    SAY_RAISE_SKELETONS         = 9883,
    SAY_SLAY                    = 9972,
    SAY_DEATH                   = 9971,

    SAY_MAGE                    = 9850,
    SAY_WARRIOR                 = 9855,
    SAY_DRUID                   = 9851,
    SAY_PRIEST                  = 9848,
    SAY_PALADIN                 = 9853,
    SAY_SHAMAN                  = 9854,
    SAY_WARLOCK                 = 9852,
    SAY_HUNTER                  = 9849,
    SAY_ROGUE                   = 9856,

    SPELL_SHADOWFLAME_INITIAL   = 22992,                // old spell id 22972 -> wrong
    SPELL_SHADOWFLAME           = 22539,
    SPELL_BELLOWING_ROAR        = 22686,
    SPELL_VEIL_OF_SHADOW        = 22687,                // old spell id 7068 -> wrong
    SPELL_CLEAVE                = 20691,
    SPELL_TAIL_LASH             = 23364,
    SPELL_BONE_CONTRUST         = 23363,
    SPELL_RAISE_DRAKONID        = 23362,

    SPELL_MAGE                  = 23410,                // wild magic
    SPELL_WARRIOR               = 23397,                // beserk
    SPELL_DRUID                 = 23398,                // cat form
    SPELL_PRIEST                = 23401,                // corrupted healing
    SPELL_PALADIN               = 23418,                // syphon blessing
    SPELL_SHAMAN                = 23425,                // totems
    SPELL_CORRUPTED_TOTEM       = 23424,
    SPELL_WARLOCK               = 23427,                // infernals    -> should trigger 23426
    SPELL_HUNTER                = 23436,                // bow broke
    SPELL_ROGUE                 = 23414,                // Paralise

    SPELL_POLYMORPH             = 23603,

    NPC_BONE_CONSTRUCT          = 14605,
};

struct ClassCallInfo
{
    ClassCallInfo(uint8 uiClass, int32 uiYell) : m_uiClass(uiClass), m_uiYell(uiYell) {}
    uint8 m_uiClass;
    int32 m_uiYell;
};

struct boss_nefarianAI : ScriptedAI
{
    explicit boss_nefarianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(pCreature->GetInstanceData());

        boss_nefarianAI::Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiShadowFlameTimer;
    uint32 m_uiBellowingRoarTimer;
    uint32 m_uiVeilOfShadowTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiTailLashTimer;
    uint32 m_uiClassCallTimer;
    bool m_bPhase3;
    uint8 m_uiTransitionStage;
    uint32 m_uiTransitionTimer;
    bool m_bTransitionDone;
    bool m_bWarriorStance;

    std::vector<ClassCallInfo> m_vPossibleCalls;
    std::list<ObjectGuid> MagePlayerGUID;
    uint32 m_uiMageTriggerTimer;

    void Reset() override
    {
        m_uiShadowFlameTimer    = urand(18000, 25000);
        m_uiBellowingRoarTimer  = urand(25000, 30000);
        m_uiVeilOfShadowTimer   = 15000;
        m_uiCleaveTimer         = urand(7000, 10000);
        m_uiTailLashTimer       = 10000;
        m_uiClassCallTimer      = urand(25000, 35000);                            // 25-35 seconds
        m_bPhase3               = false;
        m_bTransitionDone       = false;
        m_bWarriorStance        = false;
        m_uiTransitionStage     = 0;
        m_uiTransitionTimer     = 100;
        m_uiMageTriggerTimer    = 0;

        MagePlayerGUID.clear();
        m_vPossibleCalls.clear();
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_WARRIOR, SAY_WARRIOR));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_PALADIN, SAY_PALADIN));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_HUNTER, SAY_HUNTER));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_ROGUE, SAY_ROGUE));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_PRIEST, SAY_PRIEST));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_SHAMAN, SAY_SHAMAN));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_MAGE, SAY_MAGE));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_WARLOCK, SAY_WARLOCK));
        m_vPossibleCalls.push_back(ClassCallInfo(CLASS_DRUID, SAY_DRUID));
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (urand(0, 4))
            return;

        DoScriptText(SAY_SLAY, m_creature, pVictim);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_NEFARIAN, DONE);
    }

    void EnterEvadeMode() override
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_NEFARIAN, FAIL);
            if (Creature* pNefarius = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_NEFARIUS_GUID)))
                pNefarius->AI()->EnterEvadeMode();
        }
        m_creature->DeleteLater();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->SetInCombatWithZone();
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiPointId)
        {
            case 1:
                m_creature->GetMotionMaster()->MovePoint(2, -7495.964f, -1252.402f, 476.795f, MOVE_FORCE_DESTINATION, 17.0f);
                m_uiTransitionTimer = 0;
                break;
            case 2:
                m_creature->GetMotionMaster()->MoveIdle();
                m_uiTransitionTimer = 100;
                break;
            default:
                break;
        }
    }

    /*
    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell)
    {
        if (!pTarget)
            return;

        if (pSpell->Id == SPELL_BELLOWING_ROAR)
            if (SpellAuraHolder* holder = pTarget->GetSpellAuraHolder(SPELL_BELLOWING_ROAR))
                holder->SetTargetSecondaryThreatFocus(true);
    }
    */

    bool HandleClassCall(uint8 ClassCalled)
    {
        if (!ClassCalled)
            return false;

        Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
        if (players.isEmpty())
            return false;

        bool bClassFound = false;
        // Clear mage GUIDs or we'll be adding the same players again for subsequent
        // mage class calls, resulting in far more polymorphs than intended
        MagePlayerGUID.clear();
        for (const auto& itr : players)
        {
            Player* pPlayer = itr.getSource();
            if (pPlayer && pPlayer->IsAlive())
            {
                if (pPlayer->GetClass() == ClassCalled)
                {
                    bClassFound = true;
                    switch (ClassCalled)
                    {
                    case CLASS_WARRIOR:
                        pPlayer->AddAura(SPELL_WARRIOR); //OK
                        break;
                    case CLASS_PALADIN:
                        pPlayer->CastSpell(pPlayer, SPELL_PALADIN, true); // OK
                        break;
                    case CLASS_HUNTER:
                        pPlayer->CastSpell(pPlayer, SPELL_HUNTER, true); // OK
                        break;
                    case CLASS_ROGUE:
                    {
                        WorldLocation loc;
                        double dang = frand(0, M_PI_F * 2);
                        double dsin = sin(dang);
                        double dcos = cos(dang);
                        m_creature->GetPosition(loc);
                        loc.x += 5.0f * dcos;
                        loc.y += 5.0f * dsin;
                        loc.z += 0.5f;
                        loc.o = dang - M_PI_F;
                        pPlayer->TeleportTo(loc);
                        pPlayer->AddAura(SPELL_ROGUE); // OK
                        break;
                    }
                    case CLASS_PRIEST:
                        pPlayer->AddAura(SPELL_PRIEST); // OK
                        break;
                    case CLASS_SHAMAN:
                        pPlayer->AddAura(SPELL_SHAMAN); // OK
                        break;
                    case CLASS_MAGE:
                        pPlayer->AddAura(SPELL_MAGE); // OK
                        MagePlayerGUID.push_back(pPlayer->GetObjectGuid());
                        break;
                    case CLASS_WARLOCK:
                        pPlayer->CastSpell(pPlayer, SPELL_WARLOCK, true); // OK
                        m_creature->SummonCreature(14668,
                            pPlayer->GetPositionX(),
                            pPlayer->GetPositionY(),
                            pPlayer->GetPositionZ(),
                            pPlayer->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                        m_creature->SummonCreature(14668,
                            pPlayer->GetPositionX(),
                            pPlayer->GetPositionY(),
                            pPlayer->GetPositionZ(),
                            pPlayer->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                        break;
                    case CLASS_DRUID:
                        pPlayer->AddAura(SPELL_DRUID); // OK
                        break;
                    }
                }
            }
        }
        m_bWarriorStance = bClassFound && ClassCalled == CLASS_WARRIOR;

        return bClassFound;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiTransitionTimer && !m_bTransitionDone)
        {
            if (m_uiTransitionTimer <= uiDiff)
            {
                switch (m_uiTransitionStage)
                {
                    case 0:
                        SetCombatMovement(false);
                        m_creature->SetInCombatWithZone();
                        m_creature->SetFly(true);

                        m_creature->CastSpell(m_creature, SPELL_SHADOWFLAME_INITIAL, true); // Test speed 17 / fire damage on the initial ??? Oo

                        DoScriptText(SAY_AGGRO, m_creature);

                        m_creature->GetMotionMaster()->MovePoint(1, -7449.145f, -1320.647f, 476.795f);
                        //m_creature->MonsterMove(-7449.145f, -1320.647f, 476.795f);
                        m_creature->MonsterMoveWithSpeed(-7449.145f, -1320.647f, 476.795f, -10.0f, 17, uint32(MOVE_FORCE_DESTINATION));
                        m_uiTransitionTimer = 0;
                        break;
                    case 1:
                        m_creature->SetFly(false);
                        DoScriptText(SAY_SHADOWFLAME, m_creature);
                        m_creature->HandleEmote(EMOTE_ONESHOT_LAND);
                        m_uiTransitionTimer = 1000;
                        break;
                    case 2:
                        m_creature->SetWalk(true);
                        m_creature->RemoveAurasDueToSpell(17131);
                        if (Unit* pTarget = m_creature->GetVictim())
                        {
                            //m_creature->AI()->AttackStart(pTarget);
                            //m_creature->GetMotionMaster()->Clear(false);
                            m_creature->GetMotionMaster()->MoveChase(pTarget);
                            SetCombatMovement(true);
                        }
                        m_bTransitionDone = true;
                        break;
                }
                ++m_uiTransitionStage;
            }
            else
                m_uiTransitionTimer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || !m_bTransitionDone)
            return;

        // ShadowFlame_Timer
        if (m_uiShadowFlameTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SHADOWFLAME) == CAST_OK)
                m_uiShadowFlameTimer = urand(18000, 25000);
        }
        else
            m_uiShadowFlameTimer -= uiDiff;

        // BellowingRoar_Timer
        if (m_uiBellowingRoarTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BELLOWING_ROAR) == CAST_OK)
                m_uiBellowingRoarTimer = urand(25000, 30000);
        }
        else
            m_uiBellowingRoarTimer -= uiDiff;

        // VeilOfShadow_Timer
        if (m_uiVeilOfShadowTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VEIL_OF_SHADOW) == CAST_OK)
                m_uiVeilOfShadowTimer = urand(10000, 15000);
        }
        else
            m_uiVeilOfShadowTimer -= uiDiff;

        // Cleave_Timer
        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(7000, 10000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // TailLash_Timerm_uiWindfuryTimer
        if (m_uiTailLashTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TAIL_LASH) == CAST_OK)
                m_uiTailLashTimer = urand(4000, 8000);
        }
        else
            m_uiTailLashTimer -= uiDiff;

        // ClassCall_Timer
        if (m_uiClassCallTimer < uiDiff)
        {
            //Cast a random class call
            //On official it is based on what classes are currently on the hostil list
            //but we can't do that yet so just randomly call one
            // We do it now
            if (!m_vPossibleCalls.empty())
            {
                uint8 uiRandClass = urand(0, m_vPossibleCalls.size() - 1);
                if (HandleClassCall(m_vPossibleCalls[uiRandClass].m_uiClass))
                {
                    DoScriptText(m_vPossibleCalls[uiRandClass].m_uiYell, m_creature);
                    m_uiClassCallTimer = urand(25000, 35000);
                }
                else
                    m_vPossibleCalls.erase(m_vPossibleCalls.begin() + uiRandClass);
            }
        }
        else
            m_uiClassCallTimer -= uiDiff;

        if (!MagePlayerGUID.empty())
        {
            if (m_uiMageTriggerTimer < uiDiff)
            {
                for (const auto& guid : MagePlayerGUID)
                {
                    if (Player* pMage = m_creature->GetMap()->GetPlayer(guid))
                    {
                        if (pMage->HasAura(SPELL_MAGE))
                        {
                            std::vector<ObjectGuid> m_vPossibleVictim;
                            ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                            for (const auto itr2 : tList)
                            {
                                Unit* pUnit = m_creature->GetMap()->GetUnit(itr2->getUnitGuid());
                                if (pUnit && pUnit->IsCreature() && pUnit->ToCreature()->IsTotem())
                                    pUnit = nullptr;
                                if (pUnit && pUnit->GetDistance(pMage) < 60.0f && !pUnit->HasAura(SPELL_POLYMORPH))
                                    m_vPossibleVictim.push_back(pUnit->GetObjectGuid());
                            }

                            if (m_vPossibleVictim.empty())
                                continue;

                            if (Unit *pTarget = m_creature->GetMap()->GetUnit(m_vPossibleVictim[urand(0, m_vPossibleVictim.size() - 1)]))
                            {
                                pMage->InterruptNonMeleeSpells(false);
                                pMage->CastSpell(pTarget, SPELL_POLYMORPH, false); //cast polymorph
                                if (pTarget != pMage)
                                    pTarget->CastSpell(pTarget, SPELL_POLYMORPH, true); //cast polymorph
                            }
                        }
                    }
                }
                m_uiMageTriggerTimer = 5000;
            }
            else
                m_uiMageTriggerTimer -= uiDiff;
        }

        // Phase3 begins when we are below X health
        if (!m_bPhase3 && m_creature->GetHealthPercent() < 20.0f)
        {
            m_bPhase3 = true;
            DoScriptText(SAY_RAISE_SKELETONS, m_creature);
            m_creature->CastSpell(m_creature, SPELL_RAISE_DRAKONID, true);
        }

        if (DoMeleeAttackIfReady())
            if (m_creature->HasAura(10612) && !m_creature->HasAura(10610))
                if (!urand(0, 4))
                    m_creature->CastSpell(m_creature, 10610, true);
    }
};

CreatureAI* GetAI_boss_nefarian(Creature* pCreature)
{
    return new boss_nefarianAI(pCreature);
}

enum
{
    SPELL_ROOT_SELF     = 17507,
};

struct npc_corrupted_totemAI : ScriptedAI
{
    explicit npc_corrupted_totemAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_uiCreatureEntry = pCreature->GetEntry();

        uint32 HP = urand(200, 2000);
        pCreature->SetMaxHealth(HP);
        pCreature->SetHealth(HP);

        m_bAuraAdded = false;

        npc_corrupted_totemAI::Reset();
    }

    uint32 m_uiCreatureEntry;
    uint32 m_uiCheckTimer;
    bool m_bAuraAdded;

    void Reset() override
    {
        m_creature->AddUnitState(UNIT_STAT_ROOT);

        if (!m_creature->HasAura(SPELL_ROOT_SELF))
            m_creature->AddAura(SPELL_ROOT_SELF);

        m_creature->AddAura(23198, ADD_AURA_PERMANENT); // Avoidance: not affected by AoE
        m_uiCheckTimer = 1000;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        switch (m_uiCreatureEntry)
        {
            case 14663:
                SetAura(false, 10405);
                break;    // Corrupted Stoneskin Totem VI
            case 14664:
                SetAura(false, 10461);
                break;    // Corrupted Healing Stream Totem V
            case 14666:
                SetAura(false, 10612);
                break;    // Corrupted Windfury Totem III
            default:
                break;
        }
    }

    void SetAura(bool on, uint32 uiSpellId) const
    {
        int damage = 0;
        switch (uiSpellId)
        {
            case 10405:
                damage = -310;
                break;     // Stoneskin : base -31
            case 10461:
                damage = 14000;
                break;     // Healing Stream : base 14
            default:
                damage = 0;
                break;
        }

        std::vector<uint32> mobsEntries;
        std::vector<uint32>::iterator entriesIt;
        mobsEntries.push_back(11583); // Nefarian
        mobsEntries.push_back(14605); // Bone Construct
        mobsEntries.push_back(14263); // NPC_BRONZE_DRAKANOID
        mobsEntries.push_back(14261); // NPC_BLUE_DRAKANOID
        mobsEntries.push_back(14264); // NPC_RED_DRAKANOID
        mobsEntries.push_back(14262); // NPC_GREEN_DRAKANOID
        mobsEntries.push_back(14265); // NPC_BLACK_DRAKANOID
        mobsEntries.push_back(14302); // NPC_CHROMATIC_DRAKANOID

        for (entriesIt = mobsEntries.begin(); entriesIt != mobsEntries.end(); ++entriesIt)
        {
            std::list<Creature*> tmpMobsList;
            GetCreatureListWithEntryInGrid(tmpMobsList, m_creature, *entriesIt, 55.0f);
            while (!tmpMobsList.empty())
            {
                Creature* curr = tmpMobsList.front();
                tmpMobsList.pop_front();

                if (!curr->IsAlive())
                    continue;

                if (on && m_creature->IsAlive())
                {
                    if (m_creature->IsWithinDistInMap(curr, 40.0f))
                    {
                        if (!curr->HasAura(uiSpellId))
                        {
                            if (damage)
                                curr->CastCustomSpell(curr, uiSpellId, damage, {}, {}, true);
                            else
                                curr->AddAura(uiSpellId);
                        }
                    }
                    else
                    {
                        if (curr->HasAura(uiSpellId))
                            curr->RemoveAurasDueToSpell(uiSpellId);
                    }
                }
                else
                    curr->RemoveAurasDueToSpell(uiSpellId);
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->HasAura(SPELL_ROOT_SELF))
            m_creature->AddAura(SPELL_ROOT_SELF);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        uint32 addAuraEntry = 0;
        switch (m_uiCreatureEntry)
        {
            case 14662:         // Corrupted Fire Nova Totem V
                if (!m_bAuraAdded)
                {
                    m_creature->AddAura(11311);  // Fire Nova
                    m_bAuraAdded = true;
                    m_creature->DeleteLater();
                    return;
                }
                break;
            case 14663:         // Corrupted Stoneskin Totem VI
                addAuraEntry = 10405;    // Stoneskin -30 dmg really ???
                break;
            case 14664:         // Corrupted Healing Stream Totem V
                addAuraEntry = 10461;    // Healing Stream +14 hp really ???
                break;
            case 14666:         // Corrupted Windfury Totem III
                addAuraEntry = 10612;    // Windfury Totem Passive
                break;
        }
        if (!addAuraEntry)
            return;

        if (m_uiCheckTimer < uiDiff)
        {
            m_uiCheckTimer = 1000; // Add immune to AoE + fear
            SetAura(true, addAuraEntry);    // Stoneskin -30 dmg really ???
        }
        else
            m_uiCheckTimer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_corrupted_totem(Creature* pCreature)
{
    return new npc_corrupted_totemAI(pCreature);
}

void AddSC_boss_nefarian()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_nefarian";
    pNewScript->GetAI = &GetAI_boss_nefarian;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_corrupted_totem";
    pNewScript->GetAI = &GetAI_npc_corrupted_totem;
    pNewScript->RegisterSelf();
}
