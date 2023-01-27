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

#include "scriptPCH.h"
#include "blackwing_lair.h"

// Razorgore Phase 2 Script
enum
{
    MOB_RAZ_TRIGGER            = 14453,
    MOB_GRETHOK                = 12557,
    MOB_GARDE_AILE_NOIRE       = 14456,
    BLACKWING_LEGGIONAIRE      = 12416,
    BLACKWING_MAGE             = 12420,
    DEATH_TALON_DRAGONSPAWN    = 12422,

    SAY_EGGS_BROKEN_1          = -1469022,
    SAY_EGGS_BROKEN_2          = -1469023,
    SAY_EGGS_BROKEN_3          = -1469024,
    SAY_DEATH                  = -1469025,
    EMOTE_FLEE                 = -1469035,

    SPELL_CLEAVE               = 19632,
    SPELL_WARSTOMP             = 24375,
    SPELL_FIREBALL_VOLLEY      = 22425,
    SPELL_CONFLAGRATION        = 23023,
    SPELL_SUMMON_PLAYER        = 24776,
    MODEL_INVISIBLE            = 11686,

    SPELL_EXPLOSION            = 20038,             // TODO : better use?
    SPELL_POSSESS_ORB          = 19832,
    SPELL_POSSESS              = 23014
};

// North
#define SPAWN_X1 -7530.4072f
#define SPAWN_Y1 -1062.4177f
#define SPAWN_Z1 407.2f
// South
#define SPAWN_X2 -7659.7128f
#define SPAWN_Y2 -1043.3569f
#define SPAWN_Z2 407.2f
// Eeast
#define SPAWN_X3 -7607.4643f
#define SPAWN_Y3 -1116.4702f
#define SPAWN_Z3 407.2f
// West
#define SPAWN_X4 -7584.3247f
#define SPAWN_Y4 -990.5787f
#define SPAWN_Z4 407.2f

// North
#define SPAWN_X1_BIS -7547.8886f
#define SPAWN_Y1_BIS -1041.3544f
#define SPAWN_Z1_BIS 407.206f
// South
#define SPAWN_X2_BIS -7643.7973f
#define SPAWN_Y2_BIS -1065.2515f
#define SPAWN_Z2_BIS 407.207f
// Eeast
#define SPAWN_X3_BIS -7623.4433f
#define SPAWN_Y3_BIS -1094.6033f
#define SPAWN_Z3_BIS 407.206f
// West
#define SPAWN_X4_BIS -7567.9516f
#define SPAWN_Y4_BIS -1012.5256f
#define SPAWN_Z4_BIS 407.206f

#define DEBUG_RAZOR(...) //sLog.outString("[MC/Razor] "__VA_ARGS__)
#define DEBUG_EMOTE(s)  //m_creature->MonsterTextEmote(s, nullptr);

struct boss_razorgoreAI : public ScriptedAI
{
    boss_razorgoreAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetUseAiAtControl(true);
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiInit = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiCleaveTimer;
    uint32 m_uiWarStompTimer;
    uint32 m_uiFireballVolleyTimer;
    uint32 m_uiConflagrationTimer;
    uint32 m_uiInitTimer;
    uint32 m_uiOutOfReachTimer;
    bool m_uiInit;

    uint32 m_uiEvadeTroopsTimer;

    void Reset() override
    {
        SetCombatMovement(true);
        m_uiCleaveTimer         = 9000;                       // These times are probably wrong
        m_uiWarStompTimer       = 22000;
        m_uiConflagrationTimer  = 12000;
        m_uiFireballVolleyTimer = 7000;
        m_uiOutOfReachTimer     = 10000;
        m_uiInitTimer           = 5000;

        m_uiEvadeTroopsTimer = 5000;
    }

    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        if (!pTarget)
            return;

        if (pSpell->Id == SPELL_WARSTOMP)
            m_creature->GetThreatManager().modifyThreatPercent(pTarget, -30);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!m_pInstance)
            return;

        m_pInstance->SetData(TYPE_RAZORGORE, IN_PROGRESS);
        if (Creature* pTrigger = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_TRIGGER_GUID)))
        {
            pTrigger->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
            pTrigger->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
        }
        m_creature->SetInCombatWithZone();
    }

    void MortPhaseUn()
    {
        DEBUG_RAZOR("MortPhaseUn");
        Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
        for (const auto& i : liste)
        {
            if (i.getSource() && i.getSource()->IsAlive())
                i.getSource()->CastSpell(i.getSource(), SPELL_EXPLOSION, true);
        }

        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAZORGORE, FAIL);

        m_creature->Respawn();
        SituationInitiale();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        DEBUG_RAZOR("Razor JustDied");
        if (m_pInstance)
        {
            if (m_pInstance->GetData64(DATA_EGG) == DONE)
            {
                m_pInstance->SetData(TYPE_RAZORGORE, DONE);
                return;
            }
        }
        MortPhaseUn();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAZORGORE, FAIL);

        SituationInitiale();
        m_creature->MonsterYell("I'm free! That device shall never torment me again!",0,0);
    }

    void SituationInitiale()
    {
        m_uiInit = true;
        if (!m_pInstance)
            return;
        if (m_pInstance->GetData(TYPE_RAZORGORE) != IN_PROGRESS)
        {
            std::list<Creature *> lCreature;
            m_creature->GetCreatureListWithEntryInGrid(lCreature, BLACKWING_LEGGIONAIRE, 250.0f);
            m_creature->GetCreatureListWithEntryInGrid(lCreature, BLACKWING_MAGE, 250.0f);
            m_creature->GetCreatureListWithEntryInGrid(lCreature, DEATH_TALON_DRAGONSPAWN, 250.0f);

            for (const auto& itr : lCreature)
                itr->DeleteLater();

            if (GameObject* pGO = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(DATA_ORB_DOMINATION_GUID)))
            {
                if (Creature* pCreature = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_TRIGGER_GUID)))
                {
                    pCreature->AI()->EnterEvadeMode();
                    pCreature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, m_creature->GetObjectGuid());
                    pCreature->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_POSSESS);
                    pCreature->SetDisplayId(MODEL_INVISIBLE);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
                else if (Creature* pCreature = m_creature->SummonCreature(MOB_RAZ_TRIGGER, pGO->GetPositionX(), pGO->GetPositionY(), pGO->GetPositionZ(), pGO->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, DAY * IN_MILLISECONDS))
                {
                    pCreature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, m_creature->GetObjectGuid());
                    pCreature->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_POSSESS);
                    pCreature->SetDisplayId(MODEL_INVISIBLE);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            std::list<Creature*> GardesListe;
            GetCreatureListWithEntryInGrid(GardesListe, m_creature, MOB_GARDE_AILE_NOIRE, 150.0f);
            GetCreatureListWithEntryInGrid(GardesListe, m_creature, MOB_GRETHOK, 150.0f);

            for (const auto& itr : GardesListe)
            {
                if (!itr->IsAlive())
                    itr->Respawn();
                if (itr->GetEntry() == MOB_GRETHOK)
                    itr->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_POSSESS_ORB);
            }

            if (GameObject* pOrb = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(DATA_ORB_DOMINATION_GUID)))
                pOrb->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        }
        // TP to the right place
        float x, y, z, o;
        m_creature->GetRespawnCoord(x, y, z, &o);
        m_creature->NearTeleportTo(x, y, z, o);

        DEBUG_RAZOR("Initial situation");
    }

    void EvadeTroops()
    {
        std::list<Creature*> lCreatureNear;
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, BLACKWING_LEGGIONAIRE, 250.0f);
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, BLACKWING_MAGE, 250.0f);
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, DEATH_TALON_DRAGONSPAWN, 250.0f);

        for (const auto& it : lCreatureNear)
        {
            if (it->IsAlive())
                it->AI()->EnterEvadeMode();
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_creature->HasUnitState(UNIT_STAT_POSSESSED))
        {
            ScriptedAI::UpdateAI(uiDiff);
            return;
        }

        if (!m_uiInit)
        {
            if (m_uiInitTimer < uiDiff)
                SituationInitiale();
            else
                m_uiInitTimer -= uiDiff;
            // No AI without initial situation
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_pInstance->GetData64(DATA_EGG) == DONE)
        {
            // backup Evade Troops call, in case mages are re-aggroed by their in-flight Fireballs
            if (m_uiEvadeTroopsTimer)
            {
                if (m_uiEvadeTroopsTimer <= uiDiff)
                {
                    EvadeTroops();
                    m_uiEvadeTroopsTimer = 0;
                }
                else
                    m_uiEvadeTroopsTimer -= uiDiff;
            }
        }

        // World of Warcraft Client Patch 1.8.0 (2005-10-11)
        // - Razorgore now has the ability to summon players to him if he cannot 
        //   reach them for a time.
        if ((sWorld.GetWowPatch() >= WOW_PATCH_108) && m_creature->CantPathToVictim())
        {
            if (m_uiOutOfReachTimer < uiDiff)
            {
                DEBUG_EMOTE("summon");
                if (m_creature->TryToCast(m_creature->GetVictim(), SPELL_SUMMON_PLAYER, CF_TRIGGERED, 100) == SPELL_CAST_OK)
                    m_uiOutOfReachTimer = 10000;
            }
            else
                m_uiOutOfReachTimer -= uiDiff;
        }

        if (m_uiCleaveTimer < uiDiff)
        {
            DEBUG_EMOTE("cleave");
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(5000, 10000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // War Stomp
        if (m_uiWarStompTimer < uiDiff)
        {
            DEBUG_EMOTE("War stomp");
            if (DoCastSpellIfCan(m_creature, SPELL_WARSTOMP) == CAST_OK)
                m_uiWarStompTimer = urand(25000, 45000);
        }
        else
            m_uiWarStompTimer -= uiDiff;

        // Fireball Volley
        if (m_uiFireballVolleyTimer < uiDiff)
        {
            DEBUG_EMOTE("FB");
            if (DoCastSpellIfCan(m_creature, SPELL_FIREBALL_VOLLEY) == CAST_OK)
                m_uiFireballVolleyTimer = urand(15000, 20000);
        }
        else
            m_uiFireballVolleyTimer -= uiDiff;

        // Conflagration
        if (m_uiConflagrationTimer < uiDiff)
        {
            DEBUG_RAZOR("confl");
            if (DoCastSpellIfCan(m_creature, SPELL_CONFLAGRATION) == CAST_OK)
                m_uiConflagrationTimer = urand(15000, 25000);
        }
        else
            m_uiConflagrationTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void GetAIInformation(ChatHandler& handler) override
    {
        handler.PSendSysMessage("* CombatMovement : %s", IsCombatMovementEnabled() ? "OUI" : "NON");
    }
};

CreatureAI* GetAI_boss_razorgore(Creature* pCreature)
{
    return new boss_razorgoreAI(pCreature);
}

struct trigger_orb_of_commandAI : public ScriptedAI
{
    trigger_orb_of_commandAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiPopTimer;
    uint32 m_uiCheckTimer;
    bool m_uiRazorgorePhase;
    bool m_uiCombatStarted;
    ObjectGuid m_uiPossesseurGuid;

    void Reset() override
    {
        m_uiPopTimer = 45000; // Timer confirmed by BigWigs
        m_uiCheckTimer = 5000;
        m_uiRazorgorePhase = true;
        m_uiCombatStarted = false;
        m_uiPossesseurGuid.Clear();
        DEBUG_RAZOR("Reset NPC orb");
    }

    void PhaseSwitch()
    {
        ASSERT(m_pInstance);
        DEBUG_RAZOR("Passage en P2");
        DoScriptText(EMOTE_FLEE, m_creature);

        std::list<Creature*> lCreatureNear;
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, BLACKWING_LEGGIONAIRE, 250.0f);
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, BLACKWING_MAGE, 250.0f);
        GetCreatureListWithEntryInGrid(lCreatureNear, m_creature, DEATH_TALON_DRAGONSPAWN, 250.0f);

        for (const auto& it : lCreatureNear)
        {
            if (it->IsAlive())
            {
                it->SetHomePosition(-7555.55f, -1025.16f, 408.4914f, 0.65f);
                it->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
                it->AI()->EnterEvadeMode();
            }
        }

        m_creature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
        m_creature->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

        m_uiRazorgorePhase = false;

        if (GameObject* pOrb = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(DATA_ORB_DOMINATION_GUID)))
            pOrb->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);

        // Restore Razorgore
        if (Creature* pRazorgore = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_RAZORGORE_GUID)))
        {
            ((ScriptedAI*)pRazorgore->AI())->DoResetThreat();
            ((ScriptedAI*)pRazorgore->AI())->SetCombatMovement(true);
            if (Unit* pPossesser = m_creature->GetMap()->GetUnit(m_uiPossesseurGuid))
            {
                pRazorgore->AI()->AttackStart(pPossesser);
                pRazorgore->GetMotionMaster()->MoveChase(pPossesser);
                pRazorgore->AddThreat(pPossesser, 1000000); // Endless threat
            }
            pRazorgore->SetInCombatWithZone();
        }
        m_creature->DeleteLater();
    }

    void PopAdd(uint32 uiHow)
    {
        ASSERT(m_pInstance);
        Creature* pRazorgore = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_RAZORGORE_GUID));
        if (!pRazorgore)
            return;
        uint32 uiID = 0;
        float x = 0;
        float y = 0;
        float z = 0;
        float x_bis = 0;
        float y_bis = 0;
        float z_bis = 0;
        bool bSpawnTwo = false;

        // Counting spawned mobs
        std::list<Creature*> lDrake;
        std::list<Creature*> lOrc;
        uint32 uiType = 0;

        GetCreatureListWithEntryInGrid(lDrake, m_creature, DEATH_TALON_DRAGONSPAWN, 250.0f);
        GetCreatureListWithEntryInGrid(lOrc, m_creature, BLACKWING_LEGGIONAIRE, 250.0f);
        GetCreatureListWithEntryInGrid(lOrc, m_creature, BLACKWING_MAGE, 250.0f);

        if ((lDrake.size() >= 12) && (lOrc.size() >= 40))
            return;
        else if (lDrake.size() >= 12)
            uiType = urand(1, 2);
        else if (lOrc.size() >= 40)
            uiType = 3;
        else
            uiType = urand(1, 3);

        switch (uiType)
        {
            case 1:
                uiID = BLACKWING_LEGGIONAIRE;
                if (rand() % 2)
                    bSpawnTwo = true;
                break;
            case 2:
                uiID = BLACKWING_MAGE;
                if (rand() % 2)
                    bSpawnTwo = true;
                break;
            case 3:
                uiID = DEATH_TALON_DRAGONSPAWN;
                break;
        }

        if (!bSpawnTwo)
        {
            bool bSide = urand(0, 1) != 0;
            switch (uiHow)
            {
                case 0:
                    x = bSide ? SPAWN_X1 : SPAWN_X1_BIS;
                    y = bSide ? SPAWN_Y1 : SPAWN_Y1_BIS;
                    z = bSide ? SPAWN_Z1 : SPAWN_Z1_BIS;
                    break;
                case 1:
                    x = bSide ? SPAWN_X2 : SPAWN_X2_BIS;
                    y = bSide ? SPAWN_Y2 : SPAWN_Y2_BIS;
                    z = bSide ? SPAWN_Z2 : SPAWN_Z2_BIS;
                    break;
                case 2:
                    x = bSide ? SPAWN_X3 : SPAWN_X3_BIS;
                    y = bSide ? SPAWN_Y3 : SPAWN_Y3_BIS;
                    z = bSide ? SPAWN_Z3 : SPAWN_Z3_BIS;
                    break;
                case 3:
                    x = bSide ? SPAWN_X4 : SPAWN_X4_BIS;
                    y = bSide ? SPAWN_Y4 : SPAWN_Y4_BIS;
                    z = bSide ? SPAWN_Z4 : SPAWN_Z4_BIS;
                    break;
            }
        }
        else
        {
            switch (uiHow)
            {
                case 0:
                    x = SPAWN_X1;
                    x_bis = SPAWN_X1_BIS;
                    y = SPAWN_Y1;
                    y_bis = SPAWN_Y1_BIS;
                    z = SPAWN_Z1;
                    z_bis = SPAWN_Z1_BIS;
                    break;
                case 1:
                    x = SPAWN_X2;
                    x_bis = SPAWN_X2_BIS;
                    y = SPAWN_Y2;
                    y_bis = SPAWN_Y2_BIS;
                    z = SPAWN_Z2;
                    z_bis = SPAWN_Z2_BIS;
                    break;
                case 2:
                    x = SPAWN_X3;
                    x_bis = SPAWN_X3_BIS;
                    y = SPAWN_Y3;
                    y_bis = SPAWN_Y3_BIS;
                    z = SPAWN_Z3;
                    z_bis = SPAWN_Z3_BIS;
                    break;
                case 3:
                    x = SPAWN_X4;
                    x_bis = SPAWN_X4_BIS;
                    y = SPAWN_Y4;
                    y_bis = SPAWN_Y4_BIS;
                    z = SPAWN_Z4;
                    z_bis = SPAWN_Z4_BIS;
                    break;
            }
        }

        if (Creature* pCreature = m_creature->SummonCreature(uiID, x, y, z, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0))
        {
            pCreature->SetInCombatWithZone();
            pCreature->AI()->AttackStart(pRazorgore);
            pCreature->AddThreat(pRazorgore, 10.0f);
        }
        if (bSpawnTwo)
        {
            if (Creature* pCreature = m_creature->SummonCreature(uiID, x_bis, y_bis, z_bis, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0))
            {
                pCreature->SetInCombatWithZone();
                pCreature->AI()->AttackStart(pRazorgore);
                pCreature->AddThreat(pRazorgore, 10.0f);
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_pInstance)
            return;

        if (!m_uiCombatStarted && m_pInstance->GetData(TYPE_RAZORGORE) == IN_PROGRESS)
        {
            if (Creature* pRazorgore = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_RAZORGORE_GUID)))
            {
                m_uiCombatStarted = true;
                m_creature->SetInCombatWithZone();
                pRazorgore->SetInCombatWithZone();

                std::list<Creature*> lGuards;
                GetCreatureListWithEntryInGrid(lGuards, m_creature, MOB_GARDE_AILE_NOIRE, 150.0f);
                GetCreatureListWithEntryInGrid(lGuards, m_creature, MOB_GRETHOK, 150.0f);

                for (const auto& pGuard : lGuards)
                {
                    if (!pGuard->IsInCombat())
                    {
                        pGuard->SetInCombatWithZone();
                        if (pGuard->GetEntry() == MOB_GRETHOK)
                            pGuard->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
                    }
                }
            }
            else
                sLog.outError("[MC/Razor] Razorgore not found (GUID %lu)", m_pInstance->GetData64(DATA_RAZORGORE_GUID));
        }

        if (m_uiRazorgorePhase && m_uiCombatStarted)
        {
            if (m_pInstance->GetData64(DATA_EGG) == DONE)
            {
                PhaseSwitch();
                return;
            }
            if (Creature* pRazorgore = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_RAZORGORE_GUID)))
            {
                if (pRazorgore->HasAura(SPELL_POSSESS_ORB))
                {
                    if (!m_uiPossesseurGuid)
                    {
                        m_uiPossesseurGuid = pRazorgore->GetCharmerGuid();
                        DEBUG_RAZOR("Possessed by %s", pRazorgore->GetCharmerGuid().GetString().c_str());
                        ((ScriptedAI*)pRazorgore->AI())->SetCombatMovement(false);
                        pRazorgore->GetMotionMaster()->Initialize();
                        pRazorgore->StopMoving();
                    }

                    pRazorgore->SetMaxHealth(225000);

                    if (Unit* pChanneler = m_creature->GetMap()->GetUnit(m_uiPossesseurGuid))
                    {
                        if (pChanneler->IsDead())
                        {
                            pRazorgore->RemoveAurasDueToSpell(SPELL_POSSESS_ORB);
                            if (pRazorgore->GetThreatManager().isThreatListEmpty())
                                pRazorgore->AI()->EnterEvadeMode();
                        }

                        std::list<Creature*> lCreature;
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, DEATH_TALON_DRAGONSPAWN, 150.0f);
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, BLACKWING_LEGGIONAIRE, 150.0f);
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, BLACKWING_MAGE, 150.0f);

                        for (const auto& itr : lCreature)
                        {
                            if (itr->GetThreatManager().getThreat(pRazorgore))
                            {
                                itr->GetThreatManager().modifyThreatPercent(pChanneler, -100);
                                itr->AddThreat(pChanneler, itr->GetThreatManager().getThreat(pRazorgore));
                            }
                        }
                    }
                }
                else if (!pRazorgore->HasAura(SPELL_POSSESS_ORB) && m_uiPossesseurGuid) // Possess finished
                {
                    if (pRazorgore->GetMaxHealth() != 450000)
                        pRazorgore->SetMaxHealth(450000);

                    pRazorgore->GetMotionMaster()->Initialize();
                    m_creature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
                    m_creature->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
                    if (Unit* pPossesser = m_creature->GetMap()->GetUnit(m_uiPossesseurGuid))
                    {
                        std::list<Creature*> lCreature;
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, DEATH_TALON_DRAGONSPAWN, 150.0f);
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, BLACKWING_LEGGIONAIRE, 150.0f);
                        GetCreatureListWithEntryInGrid(lCreature, m_creature, BLACKWING_MAGE, 150.0f);

                        for (const auto& itr : lCreature)
                            itr->GetThreatManager().modifyThreatPercent(pRazorgore, -100);

                        // Razorgore must attack the possessor
                        ((ScriptedAI*)pRazorgore->AI())->DoResetThreat();
                        ((ScriptedAI*)pRazorgore->AI())->SetCombatMovement(true);
                        pRazorgore->AI()->AttackStart(pPossesser);
                        pRazorgore->GetMotionMaster()->MoveChase(pPossesser);
                        pRazorgore->AddThreat(pPossesser, 1000000); // Endless threat
                        pRazorgore->SetInCombatWithZone();
                        m_uiPossesseurGuid.Clear();
                    }
                    else
                        sLog.outError("[MC/Razor] Unable to find the controller (%s)", m_uiPossesseurGuid.GetString().c_str());
                }
            }
            else
                sLog.outError("[MC/Razor] Razorgore not found (GUID %lu)", m_pInstance->GetData64(DATA_RAZORGORE_GUID));
            if (m_uiPopTimer < uiDiff)
            {
                for (uint8 i = 0; i < 4; ++i)
                    PopAdd(i);

                m_uiPopTimer = 15000;
            }
            else
                m_uiPopTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_trigger_orb_of_command(Creature* pCreature)
{
    return new trigger_orb_of_commandAI(pCreature);
}

void AddSC_boss_razorgore()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_razorgore";
    pNewScript->GetAI = &GetAI_boss_razorgore;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "trigger_orb_of_command";
    pNewScript->GetAI = &GetAI_trigger_orb_of_command;
    pNewScript->RegisterSelf();
}
