/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Chromaggus
SD%Complete: 95
SDComment: Chromatic Mutation disabled due to lack of core support
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    EMOTE_GENERIC_FRENZY_KILL   = 7797,
    EMOTE_SHIMMER               = -1469003,

    // These spells are actually called elemental shield
    // What they do is decrease all damage by 75% then they increase
    // One school of damage by 1100%
    SPELL_FIRE_VULNERABILITY    = 22277,
    SPELL_FROST_VULNERABILITY   = 22278,
    SPELL_SHADOW_VULNERABILITY  = 22279,
    SPELL_NATURE_VULNERABILITY  = 22280,
    SPELL_ARCANE_VULNERABILITY  = 22281,
    SPELL_CHROMA_HEAL           = 23168,

    MAX_BREATHS                 = 5,
    SPELL_INCINERATE            = 23308,                    // Incinerate 23308,23309
    SPELL_TIME_LAPSE            = 23310,                    // Time lapse 23310, 23311(old threat mod that was removed in 2.01)
    SPELL_CORROSIVE_ACID        = 23313,                    // Corrosive Acid 23313, 23314
    SPELL_IGNITE_FLESH          = 23315,                    // Ignite Flesh 23315,23316
    SPELL_FROST_BURN            = 23187,                    // Frost burn 23187, 23189

    // Brood Affliction 23173 - Scripted Spell that cycles through all targets within 100 yards and has a chance to cast one of the afflictions on them
    // Since Scripted spells aren't coded I'll just write a function that does the same thing
    SPELL_BROODAF_BLUE          = 23153,                    // Blue affliction 23153
    SPELL_BROODAF_BLACK         = 23154,                    // Black affliction 23154
    SPELL_BROODAF_RED           = 23155,                    // Red affliction 23155 (23168 on death)
    SPELL_BROODAF_BRONZE        = 23170,                    // Bronze Affliction  23170
    SPELL_BROODAF_GREEN         = 23169,                    // Brood Affliction Green 23169

    SPELL_CHROMATIC_MUT_1       = 23174,                    // Spell cast on player if they get all 5 debuffs

    SPELL_FRENZY                = 23128,                    // 28371 The frenzy spell may be wrong
    SPELL_ENRAGE                = 28747
};

static uint32 const aPossibleBreaths[MAX_BREATHS] = {SPELL_INCINERATE, SPELL_TIME_LAPSE, SPELL_CORROSIVE_ACID, SPELL_IGNITE_FLESH, SPELL_FROST_BURN};

struct TimeLapseInfo
{
    TimeLapseInfo(ObjectGuid const targetGuid, float const targetThreat, uint32 const targetHealth) : m_targetGuid(targetGuid), m_targetThreat(targetThreat), m_targetHealth(targetHealth) { }
    ObjectGuid const m_targetGuid;
    float const m_targetThreat;
    uint32 const m_targetHealth;
};

struct boss_chromaggusAI : public ScriptedAI
{
    boss_chromaggusAI(Creature* pCreature) : ScriptedAI(pCreature), m_uiBreathOneSpell(0), m_uiBreathTwoSpell(0)
    {
        // Select the 2 different breaths that we are going to use until despawned
        // 5 possiblities for the first breath, 4 for the second, 20 total possiblites

        // select two different numbers between 0..MAX_BREATHS-1
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        if (m_pInstance)
        {
            const static uint32 NUM_BREATHS = sizeof(aPossibleBreaths) / sizeof(aPossibleBreaths[0]);
            uint32 breaths = m_pInstance->GetData64(DATA_CHROM_BREATH);
            m_uiBreathOneSpell = aPossibleBreaths[breaths % NUM_BREATHS];
            uint32 idx2 = breaths / NUM_BREATHS;
            if (idx2 >= (breaths % NUM_BREATHS))
                ++idx2;
            m_uiBreathTwoSpell = aPossibleBreaths[idx2 % NUM_BREATHS];
        }
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
        m_bEngagedOnce = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiMovetoLeverTimer;

    uint32 m_uiBreathOneSpell;
    uint32 m_uiBreathTwoSpell;
    uint32 m_uiCurrentVulnerabilitySpell;

    uint32 m_uiShimmerTimer;
    uint32 m_uiBreathOneTimer;
    uint32 m_uiBreathTwoTimer;
    uint32 m_uiAfflictionTimer;
    uint32 m_uiFrenzyTimer;
    bool m_bEnraged;
    bool m_bEngagedOnce;

    std::vector<TimeLapseInfo*> m_vTimeLapseInfo;
    typedef std::vector<ObjectGuid> AfflictionGuids;
    AfflictionGuids m_lRedAfflictionPlayerGUID;
    AfflictionGuids m_lChromaticPlayerGUID;

    void Reset() override
    {
        m_uiMovetoLeverTimer = 2000;

        m_uiCurrentVulnerabilitySpell = 0;                  // We use this to store our last vulnerability spell so we can remove it later

        m_uiShimmerTimer    = 0;                            // Time till we change vurlnerabilites
        m_uiBreathOneTimer  = 30000;                        // First breath is 30 seconds
        m_uiBreathTwoTimer  = 60000;                        // Second is 1 minute so that we can alternate
        m_uiAfflictionTimer = 4000;                        // This is special - 5 seconds means that we cast this on 1 pPlayer every 5 sconds
        m_uiFrenzyTimer     = 15000;

        m_bEnraged          = false;
        m_lRedAfflictionPlayerGUID.clear();

        for (const auto& guid : m_lChromaticPlayerGUID)
        {
            if (Player* pTarget = m_creature->GetMap()->GetPlayer(guid))
            {
                pTarget->RemoveAurasDueToSpell(23175);
                pTarget->RemoveAurasDueToSpell(23177);
                pTarget->DealDamage(pTarget, pTarget->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
            }
        }
        m_lChromaticPlayerGUID.clear();

        if (GameObject* pGO = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(DATA_DOOR_CHROMAGGUS_SIDE)))
        {
            if (pGO->GetGoState() == GO_STATE_ACTIVE) // Door open
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            else
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
        }

        for (const auto& itr : m_vTimeLapseInfo)
            delete itr;
        m_vTimeLapseInfo.clear();
    }

    void MoveInLineOfSight(Unit *pUnit) override
    {
        if (!pUnit || m_creature->GetVictim())
            return;

        if (m_bEngagedOnce && pUnit->IsPlayer() && m_creature->GetDistance2d(pUnit) < 55.0f && m_creature->IsWithinLOSInMap(pUnit)
          && pUnit->IsTargetable(true, false) && pUnit->IsInAccessablePlaceFor(m_creature))
            AttackStart(pUnit);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_CHROMAGGUS, IN_PROGRESS);

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_CHROMAGGUS, DONE);
        for (const auto& itr : m_vTimeLapseInfo)
            delete itr;
        m_vTimeLapseInfo.clear();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_CHROMAGGUS, FAIL);
    }

    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        if (!pTarget)
            return;

        if (pSpell->Id == SPELL_TIME_LAPSE)
        {
            if (SpellAuraHolder* holder = pTarget->GetSpellAuraHolder(SPELL_TIME_LAPSE))
                holder->SetTargetSecondaryThreatFocus(true);
            if (pTarget->GetTypeId() != TYPEID_PLAYER)
                return;
            m_vTimeLapseInfo.push_back(new TimeLapseInfo(pTarget->GetObjectGuid(), m_creature->GetThreatManager().getThreat(pTarget), pTarget->GetHealth()));
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiPointId)
        {
            case 0:
                // walk to Flamegor's room on first pull of lever
                m_creature->GetMotionMaster()->MovePoint(1, -7379.223f, -1002.1122f, 477.0402f, 0, 0.0f, 3.7662f);
                break;
            case 1:
                // didn't find anyone! walk back to home position
                m_creature->GetMotionMaster()->MovePoint(2, -7484.609385f, -1075.678101f, 477.144623f, 0, 0.0f, 0.616172f);
                break;
            case 2:
                m_creature->GetMotionMaster()->MoveTargetedHome();
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->IsInCombat() && !m_bEngagedOnce)
        {
            if (GameObject* pGO = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(DATA_DOOR_CHROMAGGUS_SIDE)))
            {
                if (pGO->GetGoState() == GO_STATE_ACTIVE) // Door open
                {
                    if (m_uiMovetoLeverTimer < uiDiff)
                    {
                        float x = -7484.609385f;
                        float y = -1075.678101f;
                        float z =   477.144623f;
                        float o =     0.616172f;
                        m_creature->SetHomePosition(x, y, z, o);
                        m_creature->SetWalk(true);
                        m_creature->GetMotionMaster()->MovePoint(0, x, y, z, MOVE_PATHFINDING);
                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                        m_bEngagedOnce = true;
                    }
                    else
                        m_uiMovetoLeverTimer -= uiDiff;
                }
                else if (!m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
            }
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        for (std::vector<TimeLapseInfo*>::iterator itr = m_vTimeLapseInfo.begin(); itr != m_vTimeLapseInfo.end(); ++itr)
            if (Player* pTarget = m_creature->GetMap()->GetPlayer((*itr)->m_targetGuid))
            {
                if (!pTarget->HasAura(SPELL_TIME_LAPSE) && pTarget->IsAlive())
                {
                    if ((*itr)->m_targetHealth >= (pTarget->GetMaxHealth() / 2))
                        pTarget->SetHealth(pTarget->GetMaxHealth());
                    delete *itr;
                    m_vTimeLapseInfo.erase(itr--);
                }
            }
            else
                m_vTimeLapseInfo.erase(itr--);

        // Shimmer Timer Timer
        if (m_uiShimmerTimer < uiDiff)
        {
            // Remove old vulnerability spell
            if (m_uiCurrentVulnerabilitySpell)
                m_creature->RemoveAurasDueToSpell(m_uiCurrentVulnerabilitySpell);

            // Cast new random vurlnabilty on self
            uint32 uiSpell;
            switch (urand(0, 4))
            {
                case 0:
                    uiSpell = SPELL_FIRE_VULNERABILITY;
                    break;
                case 1:
                    uiSpell = SPELL_FROST_VULNERABILITY;
                    break;
                case 2:
                    uiSpell = SPELL_SHADOW_VULNERABILITY;
                    break;
                case 3:
                    uiSpell = SPELL_NATURE_VULNERABILITY;
                    break;
                case 4:
                    uiSpell = SPELL_ARCANE_VULNERABILITY;
                    break;
            }

            if (DoCastSpellIfCan(m_creature, uiSpell) == CAST_OK)
            {
                m_uiCurrentVulnerabilitySpell = uiSpell;

                DoScriptText(EMOTE_SHIMMER, m_creature);
                m_uiShimmerTimer = 45000;
            }
        }
        else
            m_uiShimmerTimer -= uiDiff;

        // Breath One Timer
        if (m_uiBreathOneTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, m_uiBreathOneSpell) == CAST_OK)
                m_uiBreathOneTimer = 60000;
        }
        else
            m_uiBreathOneTimer -= uiDiff;

        // Breath Two Timer
        if (m_uiBreathTwoTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, m_uiBreathTwoSpell) == CAST_OK)
                m_uiBreathTwoTimer = 60000;
        }
        else
            m_uiBreathTwoTimer -= uiDiff;

        // Affliction Timer
        if (m_uiAfflictionTimer < uiDiff)
        {
            uint32 m_uiSpellAfflict = 0;

            switch (urand(0, 4))
            {
                case 0:
                    m_uiSpellAfflict = SPELL_BROODAF_BLUE;
                    break;
                case 1:
                    m_uiSpellAfflict = SPELL_BROODAF_BLACK;
                    break;
                case 2:
                    m_uiSpellAfflict = SPELL_BROODAF_RED;
                    m_lRedAfflictionPlayerGUID.clear();
                    break;
                case 3:
                    m_uiSpellAfflict = SPELL_BROODAF_BRONZE;
                    break;
                case 4:
                    m_uiSpellAfflict = SPELL_BROODAF_GREEN;
                    break;
            }

            std::vector<ObjectGuid> m_vPossibleVictim;
            ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
            for (const auto itr : tList)
                if (Player* target = m_creature->GetMap()->GetPlayer(itr->getUnitGuid()))
                    m_vPossibleVictim.push_back(target->GetObjectGuid());

            int affli_rand = urand(0, 18);
            for (int i = 0; i < affli_rand; ++i)
            {
                if (m_vPossibleVictim.empty())
                    break;
                std::vector<ObjectGuid>::iterator it = m_vPossibleVictim.begin() + urand(0, m_vPossibleVictim.size() - 1);
                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(*it))
                {
                    // Cast affliction
                    if (DoCastSpellIfCan(pPlayer, m_uiSpellAfflict, CF_TRIGGERED) == CAST_OK)
                    {
                        if (m_uiSpellAfflict == SPELL_BROODAF_RED)
                            m_lRedAfflictionPlayerGUID.push_back(pPlayer->GetObjectGuid());
                    }
                    // Chromatic mutation if target is effected by all afflictions
                    if (pPlayer->HasAura(SPELL_BROODAF_BLUE)
                            && pPlayer->HasAura(SPELL_BROODAF_BLACK)
                            && pPlayer->HasAura(SPELL_BROODAF_RED)
                            && pPlayer->HasAura(SPELL_BROODAF_BRONZE)
                            && pPlayer->HasAura(SPELL_BROODAF_GREEN))
                    {
                        pPlayer->RemoveAurasDueToSpell(SPELL_BROODAF_BLUE);
                        pPlayer->RemoveAurasDueToSpell(SPELL_BROODAF_BLACK);
                        pPlayer->RemoveAurasDueToSpell(SPELL_BROODAF_RED);
                        pPlayer->RemoveAurasDueToSpell(SPELL_BROODAF_BRONZE);
                        pPlayer->RemoveAurasDueToSpell(SPELL_BROODAF_GREEN);

                        if (DoCastSpellIfCan(pPlayer, SPELL_CHROMATIC_MUT_1) == CAST_OK)
                        {
                            // More Chromatic Mutation buffs
                            pPlayer->AddAura(23175); //Mod DMG 500% + Mod Haste Melee 100 + Mod Haste Spell 300
                            pPlayer->AddAura(23177); //Max Health 10000 + Mod healing 1000%
                            m_lChromaticPlayerGUID.push_back(pPlayer->GetObjectGuid());
                        }
                    }
                }
                m_vPossibleVictim.erase(it);
            }
            m_uiAfflictionTimer = 4000;
        }
        else
            m_uiAfflictionTimer -= uiDiff;

        // If player dies from a direct hit or dot while he had the aura SPELL_BROODAF_RED
        for (AfflictionGuids::iterator itr = m_lRedAfflictionPlayerGUID.begin(); itr != m_lRedAfflictionPlayerGUID.end();)
        {
            Player* pTarget = m_creature->GetMap()->GetPlayer(*itr);
            if (pTarget && pTarget->IsAlive() && !pTarget->HasAura(SPELL_BROODAF_RED, EFFECT_INDEX_0))
            {
                itr = m_lRedAfflictionPlayerGUID.erase(itr);
                continue;
            }

            if (!pTarget || pTarget->IsDead())
            {
                if (DoCastSpellIfCan(m_creature, SPELL_CHROMA_HEAL) == CAST_OK) //Heal 150000 HP
                    m_lRedAfflictionPlayerGUID.erase(itr);
                break;
            }
            ++itr;
        }

        // If player dies from a direct hit or dot while he had the aura SPELL_CHROMATIC_MUT_1
        for (AfflictionGuids::iterator itr = m_lChromaticPlayerGUID.begin(); itr != m_lChromaticPlayerGUID.end();)
        {
            if (Player* pTarget = m_creature->GetMap()->GetPlayer(*itr))
            {
                if (pTarget->IsDead())
                {
                    pTarget->RemoveAurasDueToSpell(23175);
                    pTarget->RemoveAurasDueToSpell(23177);
                    if (DoCastSpellIfCan(m_creature, 23168) == CAST_OK) //Heal 150000 HP
                        itr = m_lChromaticPlayerGUID.erase(itr);
                    break;
                }
            }
            ++itr;
        }
        // Frenzy Timer
        if (m_uiFrenzyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                m_uiFrenzyTimer = 15000;
            }
        }
        else
            m_uiFrenzyTimer -= uiDiff;

        // Enrage if not already enraged and below 20%
        if (!m_bEnraged && m_creature->GetHealthPercent() < 20.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CAST_OK)
                m_bEnraged = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_chromaggus(Creature* pCreature)
{
    return new boss_chromaggusAI(pCreature);
}

void AddSC_boss_chromaggus()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_chromaggus";
    pNewScript->GetAI = &GetAI_boss_chromaggus;
    pNewScript->RegisterSelf();
}
