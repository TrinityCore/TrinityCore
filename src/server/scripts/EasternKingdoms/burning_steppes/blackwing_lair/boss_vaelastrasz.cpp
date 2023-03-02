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
SDName: boss_vael
SD%Complete: 75
SDComment: Burning Adrenaline not correctly implemented in core
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    // Last found data : HP : 3,331,000 (+20% = 3997200). Damage: 5,930 - 6,807. Armor: 4,691.
    NPC_VAELASTRAZ              = 13020,
    NPC_LORD_NEFARIAN_VAEL      = 10162,

    // Emotes
    // ------

    SAY_LINE_1                  = -1469026,
    SAY_LINE_2                  = -1469027,
    SAY_LINE_3                  = -1469028,
    SAY_HALFLIFE                = -1469029,
    SAY_KILLTARGET              = -1469030,
    SAY_NEFARIUS_CORRUPT_1      = -1469006,                 // When he corrupts Vaelastrasz
    SAY_NEFARIUS_CORRUPT_2      = -1469037,
    // Spells
    // ------

    // OK
    // This debuff is cast on the raid at the beginning of the encounter and lasts for 3 minutes. Restores 500 Mana per second to mana users. Restores 50 Energy per second to Rogues and Cat Form Druids. Generates 20 Rage per second for Warriors and Bear Form Druids. It essentially means players have infinite mana/rage/energy/runic power for the fight. It is not dispellable, but can be removed by Ice Block or Divine Shield (which is not advised because of it buffing a players damage at such an incredible rate).
    SPELL_ESSENCE_OF_THE_RED    = 23513,

    // OK
    // Inflicts 3063 to 3937 (3500 to 4500?) Fire damage to enemies in a cone in front of the caster. Every flame breath applies a stacking debuff (also called flame breath) that ticks for 1000ish fire damage every few seconds. Its maximum level, which is always reached by the time the MT is burning, ticks for 4600 damage. This debuff plays a huge role. Early in the rotation, the MT takes only 1200dps or so. By the time they are burning, they're taking more like 2000dps. The difference is all in this attack.
    SPELL_FLAME_BREATH          = 23461,

    // OK
    // Inflicts 555-645 Fire damage to nearby enemies.
    SPELL_FIRE_NOVA             = 23462,

    // OK
    // Inflicts 925 to 1075 (600 à 700) damage on enemies in a cone behind the caster, knocking them back.
    SPELL_TAIL_SWEEP            = 15847,

    // TO FIX : explode at the end
    // Damage done increased by 100%. Attack speed increased by 100%. Spells become instant cast. Reduces max health by 5% every second; eventually causes player to die. Vael only casts Burning Adrenaline in two scenarios: He will cast it on random mana users every 15 seconds and he will cast it on the current tank every 45 seconds. When mana-using raid members are afflicted, they must move away to a designated area or bomb the raid with a 4376 to 5624 AoE blast. Non mana users will not be afflicted unless they are currently tanking Vaelastrasz. Note that ice blocks or divine shield will not prevent this debuff from killing the player.
    SPELL_BURNING_ADRENALINE    = 23620, // 18173 ?
    SPELL_BURNING_ADRENALINE2   = 23478, // AOE
    SPELL_BURNING_ADRENALINE3   = 23644, // instakill
    SPELL_BURNING_ADRENALINE4   = 24701, // -75% threat : easy mode ???
    // See the heal of Kazzak

    // TO FIX : The chain effect
    // DB : spell_effect_mod.effectChainTarget = 25;
    // Cleave attack that hits for 2k. This is a chain cleave, so if positioning is poor it can chain to the entire raid, even to behind him. It is critical that nobody be within approximately 10 yards of the main tank for this reason. Offtanks should be generating threat far enough from the MT to avoid chaining the cleave, but close enough to slide into place when BA hits the MT.
    SPELL_CLEAVE                = 22540, // 22540 Chain Cleave hardcoded via the BD (Ustaag) // 19983 // 20684  ? // Chain cleave is most likely named something different and contains a dummy effect
    // change spell.cpp "//FIXME: This very like horrible hack and wrong for most spells"
    // Find out which creatures use both spells in the DB?

    SPELL_BANISHEMENT_OF_SCALE  = 16404,
    SPELL_NEFARIUS_CORRUPTION   = 23642,

    FACTION_MONSTER             = 14,
    FACTION_FRIENDLY            = 35,

    MODEL_INVISIBLE             = 11686,

    GOSSIP_TEXT_VAEL_1          = 7156,
    GOSSIP_TEXT_VAEL_2          = 7256,

    QUEST_NEFARIUS_CORRUPTION   = 8730
};

// Coords used to spawn Nefarius at the throne
static float const aNefariusSpawnLoc[4] = { -7466.16f, -1040.80f, 412.053f, 2.14675f};

#define GOSSIP_ITEM_VAEL_1         "I cannot, Vaelastrasz! Surely something can be done to heal you!"
#define GOSSIP_ITEM_VAEL_2         "Vaelastrasz, no!!!"

struct boss_vaelAI : public ScriptedAI
{
    boss_vaelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        if (m_pInstance)
            m_bIntroEvent = m_pInstance->GetData(TYPE_VAEL_EVENT) == DONE;
        else
            m_bIntroEvent = false;
        m_bEngaged = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiSpeechTimer;
    uint32 m_uiSpeechNum;
    uint32 m_uiCleaveTimer;
    uint32 m_uiFlameBreathTimer;
    uint32 m_uiFireNovaTimer;
    uint32 m_uiBurningAdrenalineCasterTimer;
    uint32 m_uiBurningAdrenalineTankTimer;
    uint32 m_uiTailSweepTimer;
    uint32 m_uiSelectableTimer;
    uint32 m_uiInitTimer;
    uint32 m_uiIntroTimer;
    uint32 m_uiIntroPhase;
    bool m_bIntroEvent;
    bool m_bHasYelled;
    bool m_bIsDoingSpeech;
    bool m_bCastedEssenceOfTheRed;
    bool m_bCastedbanishment;
    bool m_bFlagSet;
    bool m_bEngaged;
    ObjectGuid m_playerGuid;
    ObjectGuid m_nefariusGuid;

    void Reset() override
    {
        m_uiSpeechTimer                  = 0;
        m_uiSpeechNum                    = 0;
        m_uiCleaveTimer                  = 6000;
        m_uiFlameBreathTimer             = 8000;
        m_uiBurningAdrenalineCasterTimer = 15000;
        m_uiBurningAdrenalineTankTimer   = 45000;
        m_uiFireNovaTimer                = 4000;
        m_uiTailSweepTimer               = 8000;
        m_uiSelectableTimer              = 0;
        m_uiIntroTimer = 0;
        m_uiIntroPhase = 0;
        m_bHasYelled = false;
        m_bIsDoingSpeech = false;
        m_bCastedEssenceOfTheRed = false;
        m_bCastedbanishment = false;
        m_bFlagSet = false;
        m_uiInitTimer = 2000;
        m_playerGuid.Clear();
        m_nefariusGuid.Clear();

        m_bEngaged = false;

        m_creature->SetHealthPercent(30.0f);
    }

    void BeginSpeech(Unit* target)
    {
        ASSERT(target);
        // Stand up and begin speech
        m_playerGuid = target->GetObjectGuid();
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
        // 10 seconds
        DoScriptText(SAY_LINE_1, m_creature);

        m_uiSpeechTimer = 10000;
        m_uiSpeechNum = 0;
        m_bIsDoingSpeech = true;

        if (nullptr == m_pInstance)
            return;

        // If Nefarius's Corruption has not been accepted by this point, fail Scepter Run
        if (m_pInstance->GetData(TYPE_SCEPTER_RUN) == NOT_STARTED)
            m_pInstance->SetData(TYPE_SCEPTER_RUN, FAIL);

    }

    void KilledUnit(Unit* pVictim) override
    {
        if (!pVictim || pVictim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (urand(0, 4))
            return;

        DoScriptText(SAY_KILLTARGET, m_creature, pVictim);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!m_bCastedEssenceOfTheRed)
        {
            DoCastSpellIfCan(m_creature, SPELL_ESSENCE_OF_THE_RED);
            m_bCastedEssenceOfTheRed = true;
        }
        m_creature->SetInCombatWithZone();
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VAELASTRASZ, IN_PROGRESS);

        if (!m_bEngaged)
        {
            m_bEngaged = true;
            // From 1.8: There is no longer a one-hour time restriction on the Vaelastraz the Corrupt encounter in Blackwing Lair.
            if (sWorld.GetWowPatch() < WOW_PATCH_108)
            {
                m_creature->SetRespawnDelay(43200); // 12h 43200
                m_creature->ForcedDespawn(3600000); // 1h 3600000
            }
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->SetRespawnDelay(604800); // 7 j. 604800
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VAELASTRASZ, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VAELASTRASZ, FAIL);
        m_creature->SetFactionTemplateId(FACTION_MONSTER);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_pInstance)
            return;

        if (!m_bIntroEvent && m_pInstance->GetData(TYPE_VAEL_EVENT) == DONE)
        {
            m_uiIntroTimer = 1000;
            m_bIntroEvent = true;
        }

        if (m_uiIntroTimer)
        {
            if (m_uiIntroTimer <= uiDiff)
            {
                switch (m_uiIntroPhase)
                {
                case 0:
                    if (Creature *pNefarius = m_creature->SummonCreature(NPC_LORD_NEFARIAN_VAEL, aNefariusSpawnLoc[0], aNefariusSpawnLoc[1], aNefariusSpawnLoc[2], aNefariusSpawnLoc[3], TEMPSUMMON_TIMED_DESPAWN, 25000, false, 25000, [](Creature* pCreature) { pCreature->GetMotionMaster()->MoveIdle(); pCreature->SetAI(new NullCreatureAI(pCreature));}))
                    {
                        pNefarius->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        m_nefariusGuid = pNefarius->GetObjectGuid();
                    }
                    m_uiIntroTimer = 1000;
                    break;
                case 1:
                    if (Creature* pNefarius = m_creature->GetMap()->GetCreature(m_nefariusGuid))
                    {
                        pNefarius->SetGuidValue(UNIT_FIELD_CHANNEL_OBJECT, m_creature->GetObjectGuid());
                        pNefarius->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_BANISHEMENT_OF_SCALE);
                        if (SpellAuraHolder* pHolder = m_creature->AddAura(SPELL_NEFARIUS_CORRUPTION))
                        {
                            pHolder->SetAuraMaxDuration(24000);
                            pHolder->SetAuraDuration(24000);
                        }
                        DoScriptText(SAY_NEFARIUS_CORRUPT_1, pNefarius);
                    }
                    m_uiIntroTimer = 15750;
                    break;
                case 2:
                    if (Creature* pNefarius = m_creature->GetMap()->GetCreature(m_nefariusGuid))
                        DoScriptText(SAY_NEFARIUS_CORRUPT_2, pNefarius);
                    m_uiSelectableTimer = 8250;
                    m_bCastedbanishment = true;
                    m_pInstance->SetData(TYPE_VAELASTRASZ, SPECIAL);
                    m_uiIntroTimer = 0;
                    break;
                }
                ++m_uiIntroPhase;
            }
            else
                m_uiIntroTimer -= uiDiff;
        }

        if (!m_creature->IsInCombat() && !m_bFlagSet)
        {
            if (m_uiInitTimer < uiDiff)
            {
                if (m_pInstance->GetData(TYPE_VAEL_EVENT) != DONE)
                {
                    m_creature->SetFactionTemplateId(FACTION_FRIENDLY);
                    m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
                }
                else
                {
                    m_creature->SetFactionTemplateId(FACTION_MONSTER);
                    m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                }
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
                m_bFlagSet = true;
            }
            else
                m_uiInitTimer -= uiDiff;
        }

        if (m_bCastedbanishment)
        {
            if (m_uiSelectableTimer < uiDiff)
            {
                m_bCastedbanishment = false;
                //m_uiSelectableTimer = 0;
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            }
            else
                m_uiSelectableTimer -= uiDiff;
        }

        // Speech
        if (m_bIsDoingSpeech)
        {
            if (m_uiSpeechTimer < uiDiff)
            {
                switch (m_uiSpeechNum)
                {
                    case 0:
                        // 16 seconds till next line
                        DoScriptText(SAY_LINE_2, m_creature);
                        m_uiSpeechTimer = 16000;
                        ++m_uiSpeechNum;
                        break;
                    case 1:
                        // This one is actually 16 seconds but we only go to 10 seconds because he starts attacking after he says "I must fight this!"
                        // (French version should start attacking after 12 seconds)
                        DoScriptText(SAY_LINE_3, m_creature);
                        m_uiSpeechTimer = 10000;
                        ++m_uiSpeechNum;
                        break;
                    case 2:
                        m_creature->SetFactionTemplateId(FACTION_MONSTER);
                        if (m_playerGuid)
                        {
                            if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
                                AttackStart(pPlayer);

                            DoCastSpellIfCan(m_creature, SPELL_ESSENCE_OF_THE_RED);
                            m_bCastedEssenceOfTheRed = true;
                        }
                        m_uiSpeechTimer = 0;
                        m_bIsDoingSpeech = false;
                        break;
                }
            }
            else
                m_uiSpeechTimer -= uiDiff;
        }

        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Burning Adrenaline Caster Timer
        // caster... caster... caster + tank... caster... caster... caster + tank...
        if (m_uiBurningAdrenalineCasterTimer < uiDiff)
        {
            std::vector<ObjectGuid> vPossibleVictim;
            ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
            for (const auto itr : tList)
            {
                Player* pPlayer = m_creature->GetMap()->GetPlayer(itr->getUnitGuid());
                if (pPlayer && pPlayer->IsAlive() && pPlayer->GetPowerType() == POWER_MANA && !pPlayer->HasAura(SPELL_BURNING_ADRENALINE, EFFECT_INDEX_0))
                    vPossibleVictim.push_back(pPlayer->GetObjectGuid());
            }
            if (!vPossibleVictim.empty())
            {
                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(vPossibleVictim[urand(0, vPossibleVictim.size() - 1)]))
                    pPlayer->CastSpell(pPlayer, SPELL_BURNING_ADRENALINE, true);
            }
            m_uiBurningAdrenalineCasterTimer = 15000;
        }
        else
            m_uiBurningAdrenalineCasterTimer -= uiDiff;

        // Burning Adrenaline Tank Timer
        if (m_uiBurningAdrenalineTankTimer < uiDiff)
        {
            // have the victim cast the spell on himself otherwise the third effect aura will be applied
            // to Vael instead of the player
            if (m_creature->GetVictim() && !m_creature->GetVictim()->HasAura(SPELL_BURNING_ADRENALINE) && m_creature->GetVictim()->IsAlive())
            {
                m_creature->GetVictim()->CastSpell(m_creature->GetVictim(), SPELL_BURNING_ADRENALINE, true);
                m_uiBurningAdrenalineTankTimer = 45000;
            }
        }
        else
            m_uiBurningAdrenalineTankTimer -= uiDiff;

        // Yell if hp lower than 15%
        if (m_creature->GetHealthPercent() < 15.0f && !m_bHasYelled)
        {
            DoScriptText(SAY_HALFLIFE, m_creature);
            m_bHasYelled = true;
        }

        // Cleave Timer
        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(5000, 10000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Flame Breath Timer
        if (m_uiFlameBreathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAME_BREATH) == CAST_OK)
                m_uiFlameBreathTimer = urand(5000, 10000);
        }
        else
            m_uiFlameBreathTimer -= uiDiff;

        // Fire Nova Timer
        if (m_uiFireNovaTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FIRE_NOVA) == CAST_OK)
                m_uiFireNovaTimer = 2000;
        }
        else
            m_uiFireNovaTimer -= uiDiff;

        // Tail Sweep Timer
        if (m_uiTailSweepTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TAIL_SWEEP) == CAST_OK)
                m_uiTailSweepTimer = urand(4000, 6000);
        }
        else
            m_uiTailSweepTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

bool GossipSelect_boss_vael(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_VAEL_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_VAEL_2, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+2: // Fight Time
            pPlayer->CLOSE_GOSSIP_MENU();
            if (boss_vaelAI* pVaelAI = dynamic_cast<boss_vaelAI*>(pCreature->AI()))
                pVaelAI->BeginSpeech((Unit*)pPlayer);
            break;
    }

    return true;
}

bool GossipHello_boss_vael(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();

    if (nullptr == m_pInstance)
        return false;

    if (m_pInstance->GetData(TYPE_RAZORGORE) != DONE && !pPlayer->IsGameMaster())
        return false;

    if (pCreature->IsQuestGiver())
        if (m_pInstance->GetData(TYPE_SCEPTER_RUN) == NOT_STARTED)
            pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_VAEL_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_VAEL_1, pCreature->GetObjectGuid());

    return true;
}

bool QuestAccept_vaelastrasz(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    ScriptedInstance* m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();

    if (nullptr == m_pInstance)
        return false;

    if (pQuest->GetQuestId() == QUEST_NEFARIUS_CORRUPTION)
    {
            // Only one may accept
            if (m_pInstance->GetData(TYPE_SCEPTER_RUN) != NOT_STARTED)
            {
                pPlayer->FailQuest(QUEST_NEFARIUS_CORRUPTION);
                return false;
            }

            m_pInstance->SetData(TYPE_SCEPTER_RUN, SPECIAL);
            m_pInstance->SetData(DATA_SCEPTER_CHAMPION, pPlayer->GetObjectGuid());

            // Permanently bind player to instance
            pCreature->GetMap()->BindToInstanceOrRaid(pPlayer, pCreature->GetRespawnTimeEx(), true);

            return true;
    }

    return false;
}

CreatureAI* GetAI_boss_vael(Creature* pCreature)
{
    return new boss_vaelAI(pCreature);
}

/**************************
*** Death Talon Captain ***
***************************/

enum
{
    MOB_RONGE_GRIFFEMORT        = 12464,
    MOB_WYRMIDE_GRIFFEMORT      = 12465,
    MOB_FLAMMECAILLE_GRIFFEMORT = 12463,

    SPELL_MARK_DETONATION       = 22438,
    SPELL_MARK_FLAMES           = 25050,
    SPELL_COMMANDING_SHOUT      = 22440,
    SPELL_CLEAVE2               = 15496,
    SPELL_AURA_FLAMES           = 22436
};

struct npc_death_talon_CaptainAI : public ScriptedAI
{
    npc_death_talon_CaptainAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiMarkDetonationTimer;
    uint32 m_uiMarkFlamesTimer;
    uint32 m_uiCommandingShoutTimer;
    uint32 m_uiCleaveTimer;

    void Reset() override
    {
        m_uiMarkDetonationTimer     = 10000;
        m_uiMarkFlamesTimer         = 6000;
        m_uiCommandingShoutTimer    = urand(12000, 25000);
        m_uiCleaveTimer             = urand(4000, 8000);
        DoCastSpellIfCan(m_creature, SPELL_AURA_FLAMES, CF_AURA_NOT_PRESENT);
        SetAuraFlames(false);
    }

    void MoveInLineOfSight(Unit *pUnit) override
    {
        if (!pUnit || m_creature->GetVictim())
            return;

        if (pUnit->IsPlayer() && m_creature->GetDistance2d(pUnit) < 29.0f && m_creature->IsWithinLOSInMap(pUnit)
          && pUnit->IsTargetable(true, false) && pUnit->IsInAccessablePlaceFor(m_creature))
            AttackStart(pUnit);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!m_creature->HasAura(SPELL_AURA_FLAMES))
            m_creature->AddAura(SPELL_AURA_FLAMES, ADD_AURA_PERMANENT);

        DoCastSpellIfCan(m_creature, SPELL_COMMANDING_SHOUT, CF_TRIGGERED);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        SetAuraFlames(false);
    }

    void SetAuraFlames(bool on)
    {
        std::list<Creature *> lCreature;
        GetCreatureListWithEntryInGrid(lCreature, m_creature, MOB_FLAMMECAILLE_GRIFFEMORT, 50.0f);
        GetCreatureListWithEntryInGrid(lCreature, m_creature, MOB_WYRMIDE_GRIFFEMORT, 50.0f);
        GetCreatureListWithEntryInGrid(lCreature, m_creature, MOB_RONGE_GRIFFEMORT, 50.0f);

        for (const auto& itr : lCreature)
        {
            if (!itr->IsAlive())
                continue;

            if (on && m_creature->IsAlive())
            {
                if (m_creature->IsWithinDistInMap(itr, 15.0f))
                {
                    if (!itr->HasAura(SPELL_AURA_FLAMES))
                        itr->AddAura(SPELL_AURA_FLAMES);
                }
                else
                    itr->RemoveAurasDueToSpell(SPELL_AURA_FLAMES);
            }
            else
                itr->RemoveAurasDueToSpell(SPELL_AURA_FLAMES);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        SetAuraFlames(true);

        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE2) == CAST_OK)
                m_uiCleaveTimer = urand(4000, 8000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        if (m_uiCommandingShoutTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_COMMANDING_SHOUT) == CAST_OK)
                m_uiCommandingShoutTimer = urand(12000, 25000);
        }
        else
            m_uiCommandingShoutTimer -= uiDiff;

        if (m_uiMarkFlamesTimer < uiDiff)
        {
            if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pUnit, SPELL_MARK_FLAMES) == CAST_OK)
                    m_uiMarkFlamesTimer = 15000;
            }
        }
        else
            m_uiMarkFlamesTimer -= uiDiff;

        if (m_uiMarkDetonationTimer < uiDiff)
        {
            if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (pUnit->IsAlive())
                {
                    pUnit->CastSpell(pUnit, SPELL_MARK_DETONATION, true);
                    m_uiMarkDetonationTimer = 20000;
                }
            }
        }
        else
            m_uiMarkDetonationTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_death_talon_Captain(Creature* pCreature)
{
    return new npc_death_talon_CaptainAI(pCreature);
}

/**************************
*** Death Talon Seether ***
***************************/

enum
{
    SPELL_FRENZY         = 22428,
    SPELL_FLAME_BUFFET   = 22433,

    EMOTE_FRENZY         = 7797
};

struct npc_death_talon_SeetherAI : public ScriptedAI
{
    npc_death_talon_SeetherAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFlameBuffetTimer;
    uint32 m_uiFrenzyTimer;
    bool m_bEngaged;

    void Reset() override
    {
        m_uiFlameBuffetTimer = urand(5000, 10000);
        m_uiFrenzyTimer     = 15000;
        m_bEngaged          = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiFrenzyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_FRENZY, m_creature);
                m_uiFrenzyTimer = 15000;
            }
        }
        else m_uiFrenzyTimer -= uiDiff;

        if (!m_bEngaged)
        {
            if (m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
                m_bEngaged = true;
        }
        else
        {
            if (m_uiFlameBuffetTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAME_BUFFET) == CAST_OK)
                    m_uiFlameBuffetTimer = urand(8000, 12000);
            }
            else m_uiFlameBuffetTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_death_talon_Seether(Creature* pCreature)
{
    return new npc_death_talon_SeetherAI(pCreature);
}

void AddSC_boss_vael()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_vaelastrasz";
    pNewScript->GetAI = &GetAI_boss_vael;
    pNewScript->pGossipHello = &GossipHello_boss_vael;
    pNewScript->pGossipSelect = &GossipSelect_boss_vael;
    pNewScript->pQuestAcceptNPC = &QuestAccept_vaelastrasz;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_death_talon_Captain";
    pNewScript->GetAI = &GetAI_npc_death_talon_Captain;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_death_talon_Seether";
    pNewScript->GetAI = &GetAI_npc_death_talon_Seether;
    pNewScript->RegisterSelf();
}
