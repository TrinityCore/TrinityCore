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
 SDName: Silithus
 SD%Complete: 100
 SDComment: Quest support: 8304, 8534, 8519.
 SDCategory: Silithus
 EndScriptData */

/* ContentData
 npcs_rutgar_and_frankal
 go_pierre_vents
 EndContentData */

#include "scriptPCH.h"
#include "HardcodedEvents.h"
#include "CreatureGroups.h"

enum
{
    SPELL_SET_AURA            = 24746,
    SPELL_RED_LIGHTNING       = 24240,

    ITEM_SET_ENTRY            = 492,

    ITEM_SET_SHOULDERS        = 20406,
    ITEM_SET_CHEST            = 20407,
    ITEM_SET_HEAD             = 20408,

    SPELL_APPARITION          = 25035,

    GO_TYPE_PIERRE_ERR        = 0,
    GO_TYPE_PIERRE_INF        = 1,
    GO_TYPE_PIERRE_MOYENNE    = 2,
    GO_TYPE_PIERRE_SUP        = 3,

    // Pierre moyenne
    ITEM_ACCES_PIERRE_MOYENNE = 20422,
    AURA_ACCES_PIERRE_MOYENNE = 24748,

    // Pierre superieure
    ITEM_ACCES_PIERRE_SUP     = 20451,
    AURA_ACCES_PIERRE_SUP     = 24782,

    GOSSIP_STONE_FIRST_HELLO    = 69,
    GOSSIP_STONE_FIRST_OPTION   = 10684
};

struct Silithus_WindStonesBossData
{
    int stoneType;
    int action;
    int summonEntry;
    int reqItem;
    int gossipOption;
};
static Silithus_WindStonesBossData const windStonesBosses[] =
{
    {GO_TYPE_PIERRE_INF,    1,  15209,  20416, 10685 },
    {GO_TYPE_PIERRE_INF,    2,  15307,  20419, 10691 },
    {GO_TYPE_PIERRE_INF,    3,  15212,  20418, 10690 },
    {GO_TYPE_PIERRE_INF,    4,  15211,  20420, 10692 },

    {GO_TYPE_PIERRE_MOYENNE,1,  15206,  20432, 10699 },
    {GO_TYPE_PIERRE_MOYENNE,2,  15208,  20435, 10701 },
    {GO_TYPE_PIERRE_MOYENNE,3,  15220,  20433, 10700 },
    {GO_TYPE_PIERRE_MOYENNE,4,  15207,  20436, 10702 },

    {GO_TYPE_PIERRE_SUP,    1,  15203,  20447, 10708 },
    {GO_TYPE_PIERRE_SUP,    2,  15205,  20449, 10710 },
    {GO_TYPE_PIERRE_SUP,    3,  15204,  20448, 10709 },
    {GO_TYPE_PIERRE_SUP,    4,  15305,  20450, 10711 },
};

struct go_pierre_ventsAI: public GameObjectAI
{
    go_pierre_ventsAI(GameObject* pGo) : GameObjectAI(pGo) {}

    uint32 GetStoneType()
    {
        switch (me->GetEntry())
        {
            // Pierre SUP
            case 180466:
            case 180539:
            case 180559:
                return GO_TYPE_PIERRE_SUP;
            // Pierre MOYENNE
            case 180554:
            case 180534:
            case 180502:
            case 180461:
                return GO_TYPE_PIERRE_MOYENNE;
            // Pierre INF
            case 180456:
            case 180518:
            case 180529:
            case 180544:
            case 180549:
            case 180564:
                return GO_TYPE_PIERRE_INF;
            default:
                return GO_TYPE_PIERRE_ERR;
        }
    }
    uint32 SelectRandomBoss(uint32 stoneType)
    {
        std::vector<uint32> possibleBosses;
        for (const auto& stone : windStonesBosses)
            if (stone.stoneType == stoneType)
                possibleBosses.push_back(stone.summonEntry);
        ASSERT(!possibleBosses.empty());
        return possibleBosses[urand(0, possibleBosses.size() - 1)];
    }

    bool CheckPlayerHasAura(uint32 uiReqAura, Player *pUser, uint32 itemToDelete = 0)
    {
        if (uiReqAura && !pUser->HasAura(uiReqAura))
            if (!pUser->IsGameMaster())
                return false;
        return true;
    }

    void UseFailed(Unit* user)
    {
        if (user->IsAlive())
        {
            user->CastSpell(user, SPELL_RED_LIGHTNING, true);
            user->DealDamage(user, user->GetHealth() > 1000 ? 1000 : user->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        }
    }
    bool CanUse(Player* user)
    {
        if (!user || !me->isSpawned())
            return false;

        bool playerHasAura = true;

        ///- Check if allowed to use the stone ?
        switch (GetStoneType())
        {
            // Pierre SUP
            case GO_TYPE_PIERRE_SUP:
                if (!user->HasItemWithIdEquipped(ITEM_ACCES_PIERRE_SUP))
                    playerHasAura = false;
            // Pierre MOYENNE
            case GO_TYPE_PIERRE_MOYENNE:
                if (!user->HasItemWithIdEquipped(ITEM_ACCES_PIERRE_MOYENNE))
                    playerHasAura = false;
            // Pierre INF
            case GO_TYPE_PIERRE_INF:
                if (!user->HasItemWithIdEquipped(ITEM_SET_HEAD) ||
                    !user->HasItemWithIdEquipped(ITEM_SET_SHOULDERS) ||
                    !user->HasItemWithIdEquipped(ITEM_SET_CHEST))
                    playerHasAura = false;
                break;
        }

        if (!playerHasAura)
        {
            UseFailed(user);
            return false;
        }
        return true;
    }

    bool OnUse(Unit* user) override
    {
        Player* player = user->ToPlayer();
        if (!CanUse(player))
            return true;

        uint32 stoneType = GetStoneType();
        player->PlayerTalkClass->ClearMenus();
        //FixMe: Positive ID is broadcast text. I don't understand the thing below.
        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STONE_FIRST_OPTION + stoneType - 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_STONE_FIRST_OPTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        for (const auto& stone : windStonesBosses)
            if (stone.stoneType == stoneType)
                if (player->HasItemCount(stone.reqItem, 1))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, stone.gossipOption, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + stone.action);

        player->SEND_GOSSIP_MENU(GOSSIP_STONE_FIRST_HELLO + stoneType - 1, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 action)
    {
        if (!CanUse(player))
            return true;

        uint32 stoneType = GetStoneType();
        if (!stoneType)
            return true;

        uint32 summonEntry = 0;
        uint32 textId = 0;

        ///- Let's find out which mob we have to summon.
        switch (stoneType)
        {
            case GO_TYPE_PIERRE_SUP:
                textId = 10805;
                break;
            case GO_TYPE_PIERRE_MOYENNE:
                textId = 10802;
                break;
            case GO_TYPE_PIERRE_INF:
                textId = 10686;
                break;
        }

        for (const auto& stone : windStonesBosses)
        {
            if (stone.stoneType == stoneType && action == GOSSIP_ACTION_INFO_DEF + stone.action)
            {
                if (player->HasItemCount(stone.reqItem, 1))
                {
                    summonEntry = stone.summonEntry;
                    player->DestroyItemCount(stone.reqItem, 1, true, false);
                }
            }   
        }

        if (!summonEntry && action != GOSSIP_ACTION_INFO_DEF)
        {
            UseFailed(player);
            return true;
        }

        if (!summonEntry)
            summonEntry = SelectRandomBoss(stoneType);

        if (!summonEntry)
            return true;

        ///- Destroy required items.
        if (!player->ToPlayer()->IsGameMaster())
        {
            switch (stoneType)
            {
                case GO_TYPE_PIERRE_SUP:
                    player->DestroyEquippedItem(ITEM_ACCES_PIERRE_SUP);
                // no break
                case GO_TYPE_PIERRE_MOYENNE:
                    player->DestroyEquippedItem(ITEM_ACCES_PIERRE_MOYENNE);
                // no break
                case GO_TYPE_PIERRE_INF:
                    player->DestroyEquippedItem(ITEM_SET_SHOULDERS);
                    player->DestroyEquippedItem(ITEM_SET_CHEST);
                    player->DestroyEquippedItem(ITEM_SET_HEAD);
                    break;
            }
        }

        ///- Summon the creature
        if (Creature* pInvoc = me->SummonCreature(summonEntry, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), me->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 3600000, false, 5000))
        {
            player->CastSpell(player, SPELL_RED_LIGHTNING, true);
            pInvoc->CastSpell(pInvoc, SPELL_APPARITION, true);
            pInvoc->SetLootRecipient(player); // Force tag for summoner
            if (textId)
                pInvoc->MonsterSay(textId, 0, player);
        }

        ///- Mark stone as used.
        me->UseDoorOrButton();
        if (stoneType == GO_TYPE_PIERRE_SUP)
            me->SetRespawnTime(3600);
        else if (stoneType == GO_TYPE_PIERRE_MOYENNE)
            me->SetRespawnTime(300);
        else if (stoneType == GO_TYPE_PIERRE_INF)
            me->SetRespawnTime(90);
        else
            me->SetRespawnTime(me->ComputeRespawnDelay());
        return true;
    }
};

GameObjectAI* GetAIgo_pierre_vents(GameObject *go)
{
    return new go_pierre_ventsAI(go);
}

bool GossipSelect_go_pierre_vents(Player* user, GameObject* gobj, uint32 sender, uint32 action)
{
    user->CLOSE_GOSSIP_MENU();
    if (go_pierre_ventsAI* ai = dynamic_cast<go_pierre_ventsAI*>(gobj->AI()))
        ai->GossipSelect(user, action);
    return true;
}

enum
{
    SPELL_FOOLS_PLIGHT              = 23504,

    SPELL_SOUL_FLAME                = 23272,
    SPELL_DREADFUL_FRIGHT           = 23275,
    SPELL_CREEPING_DOOM             = 23589,
    SPELL_CRIPPLING_CLIP            = 23279,

    EMOTE_IMMOBILIZED               = -1000650,

    SPELL_FROST_TRAP                = 13810,

    NPC_NELSON_THE_NICE             = 14536,
    NPC_SOLENOR_THE_SLAYER          = 14530,
    NPC_CREEPING_DOOM               = 14761,
    NPC_THE_CLEANER                 = 14503,

    QUEST_STAVE_OF_THE_ANCIENTS     = 7636
};

/*#####
 ## npc_solenor_the_slayer
 ######*/

struct npc_solenorAI : public ScriptedAI
{
    npc_solenorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_bTransform      = false;
        m_uiDespawn_Timer = 0;
        Reset();
    }

    uint32 m_uiTransform_Timer;
    uint32 m_uiTransformEmote_Timer;
    bool m_bTransform;

    ObjectGuid m_hunterGuid;
    uint32 m_uiDreadfulFright_Timer;
    uint32 m_uiCreepingDoom_Timer;
    uint32 m_uiCastSoulFlame_Timer;
    uint32 m_uiDespawn_Timer;

    void Reset() override
    {
        switch (m_creature->GetEntry())
        {
            case NPC_NELSON_THE_NICE:
                m_creature->SetRespawnDelay(35*MINUTE);
                m_creature->SetRespawnTime(35*MINUTE);
                m_creature->SetHomePosition(-7724.21f, 1676.43f, 7.0571f, 4.80044f);
                m_creature->NearTeleportTo(-7724.21f, 1676.43f, 7.0571f, 4.80044f);
                if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != WAYPOINT_MOTION_TYPE)
                {
                    m_creature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
                    m_creature->GetMotionMaster()->Initialize();
                }

                m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                m_uiTransform_Timer      = 10000;
                m_uiTransformEmote_Timer = 5000;
                m_bTransform             = false;
                m_uiDespawn_Timer        = 0;
                m_uiCastSoulFlame_Timer  = 0;
                break;
            case NPC_SOLENOR_THE_SLAYER:
                if (!m_uiDespawn_Timer)
                {
                    m_uiDespawn_Timer = 20*MINUTE*IN_MILLISECONDS;
                    m_uiCastSoulFlame_Timer  = 150;
                    m_creature->AddAura(SPELL_SOUL_FLAME); // apply on spawn in case of instant Freezing Trap
                }

                m_hunterGuid.Clear();
                m_uiDreadfulFright_Timer = urand(10000, 15000);
                m_uiCreepingDoom_Timer   = urand(3000, 6000);
                break;
        }
    }

    /** Nelson the Nice */
    void Transform()
    {
        m_creature->UpdateEntry(NPC_SOLENOR_THE_SLAYER);
        m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation());
        m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);
        m_creature->GetMotionMaster()->Initialize();
        Reset();
    }

    void BeginEvent(ObjectGuid playerGuid)
    {
        m_hunterGuid = playerGuid;
        m_creature->GetMotionMaster()->Clear(false);
        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        m_bTransform = true;
    }

    /** Solenor the Slayer */
    void Aggro(Unit* pWho) override
    {
        if (pWho->GetClass() == CLASS_HUNTER && (m_hunterGuid.IsEmpty() || m_hunterGuid == pWho->GetObjectGuid())/*&& pWho->GetQuestStatus(QUEST_STAVE_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE*/)
        {
            m_hunterGuid = pWho->GetObjectGuid();
        }
        else
            DemonDespawn();
    }

    void EnterEvadeMode() override
    {
        m_creature->RemoveGuardians();

        ScriptedAI::EnterEvadeMode();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (m_creature->GetVictim())
            pSummoned->AI()->AttackStart(m_creature->GetVictim());
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->SetHomePosition(-7724.21f, 1676.43f, 7.0571f, 4.80044f);
        // DRSS
        uint32 m_respawn_delay_Timer = 3*HOUR;
        if (sWorld.GetActiveSessionCount() > BLIZZLIKE_REALM_POPULATION)
            m_respawn_delay_Timer *= float(BLIZZLIKE_REALM_POPULATION) / float(sWorld.GetActiveSessionCount());

        m_creature->SetRespawnDelay(m_respawn_delay_Timer);
        m_creature->SetRespawnTime(m_respawn_delay_Timer);
        m_creature->SaveRespawnTime();
    }

    void DemonDespawn(bool triggered = true)
    {
        m_creature->RemoveGuardians();
        m_creature->SetHomePosition(-7724.21f, 1676.43f, 7.0571f, 4.80044f);
        m_creature->SetRespawnDelay(15*MINUTE);
        m_creature->SetRespawnTime(15*MINUTE);
        m_creature->SaveRespawnTime();

        if (triggered)
        {
            Creature* pCleaner = m_creature->SummonCreature(NPC_THE_CLEANER, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 20*MINUTE*IN_MILLISECONDS);
            if (pCleaner)
            {
                ThreatList const& tList = m_creature->GetThreatManager().getThreatList();

                for (const auto itr : tList)
                {
                    if (Unit* pUnit = m_creature->GetMap()->GetUnit(itr->getUnitGuid()))
                    {
                        if (pUnit->IsAlive())
                        {
                            pCleaner->SetInCombatWith(pUnit);
                            pCleaner->AddThreat(pUnit);
                            pCleaner->AI()->AttackStart(pUnit);
                        }
                    }
                }
            }
        }

        m_creature->ForcedDespawn();
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {

        if (pSpell && pSpell->Id == 14268)   // Wing Clip (Rank 3)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_CRIPPLING_CLIP, CF_TRIGGERED) == CAST_OK)
                DoScriptText(EMOTE_IMMOBILIZED, m_creature);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /** Nelson the Nice */
        if (m_bTransform)
        {
            if (m_uiTransformEmote_Timer)
            {
                if (m_uiTransformEmote_Timer <= uiDiff)
                {
                    m_creature->HandleEmote(EMOTE_ONESHOT_LAUGH);
                    m_uiTransformEmote_Timer = 0;
                }
                else
                    m_uiTransformEmote_Timer -= uiDiff;
            }

            if (m_uiTransform_Timer < uiDiff)
            {
                m_bTransform = false;
                Transform();
            }
            else
                m_uiTransform_Timer -= uiDiff;
        }

        /** Solenor the Slayer */
        if (m_uiDespawn_Timer)
        {
            if (m_uiDespawn_Timer <= uiDiff)
            {
                if (m_creature->IsAlive() && !m_creature->IsInCombat())
                    DemonDespawn(false);
            }
            else
                m_uiDespawn_Timer -= uiDiff;
        }

        if (m_uiCastSoulFlame_Timer)
        {
            if (m_uiCastSoulFlame_Timer <= uiDiff)
            {
                // delay this cast so spell animation is visible to the player
                m_creature->CastSpell(m_creature, SPELL_SOUL_FLAME, false);
                m_uiCastSoulFlame_Timer = 0;
            }
            else
                m_uiCastSoulFlame_Timer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->HasAura(SPELL_SOUL_FLAME) && m_creature->HasAura(SPELL_FROST_TRAP))
                m_creature->RemoveAurasDueToSpell(SPELL_SOUL_FLAME);

        if (m_creature->GetThreatManager().getThreatList().size() > 1 /*|| pHunter->IsDead()*/)
            DemonDespawn();

        if (m_uiCreepingDoom_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_CREEPING_DOOM);
            m_uiCreepingDoom_Timer = 15000;
        }
        else
            m_uiCreepingDoom_Timer -= uiDiff;

        if (m_uiDreadfulFright_Timer < uiDiff)
        {
            if (Unit* pUnit = m_creature->GetVictim())
            {
                if (m_creature->GetDistance2d(pUnit) > 5.0f)
                {
                    if (DoCastSpellIfCan(pUnit, SPELL_DREADFUL_FRIGHT) == CAST_OK)
                        m_uiDreadfulFright_Timer = urand(15000, 20000);
                }
            }
        }
        else
            m_uiDreadfulFright_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void OnScriptEventHappened(uint32 uiEvent, uint32 uiData, WorldObject* pInvoker) override
    {
        if (pInvoker && pInvoker->IsPlayer())
            BeginEvent(pInvoker->GetObjectGuid());
    }
};

CreatureAI* GetAI_npc_solenor(Creature* pCreature)
{
    return new npc_solenorAI(pCreature);
}

/*#####
 ## npc_creeping_doom
 ######*/

struct npc_creeping_doomAI : public ScriptedAI
{
    npc_creeping_doomAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    void Reset() override {};

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        Unit* pOwner = m_creature->GetCharmerOrOwner();
        if (pDoneBy && pOwner)
        {
            pOwner->AddThreat(pDoneBy);
            pOwner->SetInCombatWith(pDoneBy);
        }
        ScriptedAI::DamageTaken(pDoneBy, uiDamage);
    }
};

CreatureAI* GetAI_npc_creeping_doom(Creature* pCreature)
{
    return new npc_creeping_doomAI(pCreature);
}

/*#####
 ## npc_prince_thunderaan
 ######*/

enum
{
    SPELL_TENDRILS_OF_AIR           = 23009, // KB
    SPELL_TEARS_OF_THE_WIND_SEEKER    = 23011
};

struct npc_prince_thunderaanAI : public ScriptedAI
{
    npc_prince_thunderaanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        engaged = false;
        emerged = false;
        Reset();
    }

    uint32 m_uiTendrilsTimer;
    uint32 m_uiTearsTimer;
    bool engaged;
    bool emerged;

    void Reset() override
    {
        m_uiTendrilsTimer   = 8000;
        m_uiTearsTimer      = 15000;
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pCaster->GetTypeId() != TYPEID_PLAYER)
            return;

        if (pSpell->Id == SPELL_TENDRILS_OF_AIR)
            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -100);
    }

    void Aggro(Unit* pWho) override
    {
        if (!engaged)
        {
            m_creature->MonsterYell("My power is discombobulatingly devastating! It is ludicrous that these mortals even attempt to enter my realm!", 0);
            engaged = true;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!emerged)
        {
            m_creature->CastSpell(m_creature, 20568, false);     // Ragnaros Emerge
            emerged = true;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiTendrilsTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TENDRILS_OF_AIR) == CAST_OK) // KB
                m_uiTendrilsTimer = urand(12000, 20000);
        }
        else
            m_uiTendrilsTimer -= uiDiff;

        if (m_uiTearsTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TEARS_OF_THE_WIND_SEEKER) == CAST_OK)
                m_uiTearsTimer = urand(8000, 11000);
        }
        else
            m_uiTearsTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_prince_thunderaan(Creature* pCreature)
{
    return new npc_prince_thunderaanAI(pCreature);
}


/*#####
 ## npc_colossus
 ######*/

enum
{
    SPELL_COLOSSAL_SMASH            = 26167, // Maxi KB
    NPC_COLOSSUS_ZORA               = 15740,
    NPC_COLOSSUS_REGAL              = 15741,
    NPC_COLOSSUS_ASHI               = 15742,

    TEXT_COLOSSUS_ASHI = -1000009,
    TEXT_COLOSSUS_REGAL = -1000016,
    TEXT_COLOSSUS_ZORA = -1000017,
};

struct npc_colossusAI : public ScriptedAI
{
    npc_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        int text = 0;
        switch (m_creature->GetEntry())
        {
            case NPC_COLOSSUS_ASHI:
                text = TEXT_COLOSSUS_ASHI;
                break;
            case NPC_COLOSSUS_REGAL:
                text = TEXT_COLOSSUS_REGAL;
                break;
            case NPC_COLOSSUS_ZORA:
                text = TEXT_COLOSSUS_ZORA;
                break;
        }

        if (text)
            m_creature->MonsterScriptToZone(text, CHAT_MSG_MONSTER_EMOTE);

        Reset();
    }

    uint32 m_uiColossalSmashTimer;
    uint32 m_uiColossalSmashEmoteTimer;
    bool firstSmash;

    void Reset() override
    {
        firstSmash = true;
        m_uiColossalSmashTimer = 60000;
        m_uiColossalSmashEmoteTimer = 0;
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
    }

    void Aggro(Unit* pWho) override
    {
    }

    void EnterEvadeMode() override
    {
        // Ustaag <Nostalrius> : Must neither resume life if Evade, nor return to its starting point
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        // To avoid jerky movements after aggro end
        m_creature->GetMotionMaster()->MoveIdle();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiColossalSmashTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_COLOSSAL_SMASH) == CAST_OK) // Maxi KB
            {
                m_creature->MonsterTextEmote("Colossus begins to cast Colossus Smash", nullptr);
                m_uiColossalSmashTimer = firstSmash ? 10000 : 60000;
                m_uiColossalSmashEmoteTimer = 5000;

                firstSmash = !firstSmash;
            }
        }
        else
            m_uiColossalSmashTimer -= uiDiff;

        if (m_uiColossalSmashEmoteTimer && m_uiColossalSmashEmoteTimer < uiDiff)
        {
            m_creature->MonsterTextEmote("Colossus lets loose a massive attack", nullptr);
            m_uiColossalSmashEmoteTimer = 0;
        }
        else
            m_uiColossalSmashEmoteTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller) override
    {
        // Spawn the event quest that lets players attain a reward for the
        // death of the colossus.
        // Note that it is not thread-safe to start events inside a map update.
        // Instead, set a saved var and the event update will read it
        uint32 eventFlag = sObjectMgr.GetSavedVariable(VAR_WE_HIVE_REWARD, 0);
        switch (m_creature->GetEntry())
        {
            case NPC_COLOSSUS_ZORA:
                eventFlag |= WAR_EFFORT_ZORA_REWARD;
                break;
            case NPC_COLOSSUS_ASHI:
                eventFlag |= WAR_EFFORT_ASHI_REWARD;
                break;
            case NPC_COLOSSUS_REGAL:
                eventFlag |= WAR_EFFORT_REGAL_REWARD;
                break;
        }

        // Don't save to DB - event will not resume on crash, requires colossus to be
        // slain again
        if (eventFlag)
        {
            sObjectMgr.SetSavedVariable(VAR_WE_HIVE_REWARD, eventFlag);
            // Trigger event update on next world tick
            sWorld.SetWorldUpdateTimer(WUPDATE_EVENTS, sWorld.GetWorldUpdateTimerInterval(WUPDATE_EVENTS)+1);
        }

        ScriptedAI::JustDied(pKiller);
    }
};

CreatureAI* GetAI_npc_colossus(Creature* pCreature)
{
    return new npc_colossusAI(pCreature);
}



/*###
 ## npc_Geologist_Larksbane
 ###*/

/*UPDATE `gameobject_template` SET `size` = 1.5, `data2` = 39321600, `type` = 1 WHERE `entry` = 210342;
 UPDATE `gameobject_template` SET data2 = 39321600 WHERE `entry` = 180514;
 DELETE FROM `gameobject` WHERE `id` IN (180514, 210342);
 UPDATE `creature_template` SET `script_name` = 'npc_Geologist_Larksbane' WHERE `entry` = 15183;*/

enum
{
    GO_GLYPHED_CRYSTAL      = 180514,
    GO_GLYPHED_CRYSTAL_BIG  = 210342
};

struct npc_Geologist_LarksbaneAI : public ScriptedAI
{
    npc_Geologist_LarksbaneAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    std::list<uint64> lCrystalGUIDs;
    uint32 uiNextActionTimer;
    uint32 uiCurrAction;

    void Reset() override
    {
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        lCrystalGUIDs.clear();
        uiCurrAction = 0;
        uiNextActionTimer = 0;
    }

    void QuestCompleted(Player* pPlayer, Quest const* pQuest)
    {
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        if (GameObject* pGo = m_creature->SummonGameObject(GO_GLYPHED_CRYSTAL, -6826.51f, 809.082f, 51.8577f, 0.259445f))
            lCrystalGUIDs.push_back(pGo->GetGUID());
        if (GameObject* pGo = m_creature->SummonGameObject(GO_GLYPHED_CRYSTAL, -6827.54f, 806.711f, 51.9809f, 2.2241f))
            lCrystalGUIDs.push_back(pGo->GetGUID());
        if (GameObject* pGo = m_creature->SummonGameObject(GO_GLYPHED_CRYSTAL_BIG, -6825.31f, 805.146f, 51.9435f, -1.255528f))
            lCrystalGUIDs.push_back(pGo->GetGUID());

        uiCurrAction = 1;
        uiNextActionTimer = 4000;
    }

    void Larksbane_DoAction()
    {
        switch (uiCurrAction)
        {
            case 1:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10762);
                uiNextActionTimer = 4000;
                break;
            }
            case 2:
            {
                for (const auto& guid : lCrystalGUIDs)
                {
                    if (GameObject* pCrystal = m_creature->GetMap()->GetGameObject(guid))
                        pCrystal->Use(m_creature);
                }
                uiNextActionTimer = 5000;
                break;
            }
            case 3:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10829);
                uiNextActionTimer = 7000;
                break;
            }
            case 4:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10830);
                uiNextActionTimer = 11000;
                break;
            }
            case 5:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10831);
                uiNextActionTimer = 9000;
                break;
            }
            case 6:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10832);
                uiNextActionTimer = 11000;
                break;
            }
            case 7:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10833);
                uiNextActionTimer = 11000;
                break;
            }
            case 8:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                m_creature->MonsterSay(10836);
                uiNextActionTimer = 9000;
                break;
            }
            case 9:
            {
                m_creature->MonsterTextEmote(10837, nullptr, false);
                uiNextActionTimer = 3000;
                break;
            }
            case 10:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10838);
                uiNextActionTimer = 4000;
                break;
            }
            case 11:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10839);
                uiNextActionTimer = 12000;
                break;
            }
            case 12:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                m_creature->MonsterSay(10840);
                uiNextActionTimer = 9000;
                break;
            }
            case 13:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10841);
                uiNextActionTimer = 9000;
                break;
            }
            case 14:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10842);
                uiNextActionTimer = 12000;
                break;
            }
            case 15:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10843);
                uiNextActionTimer = 12000;
                break;
            }
            case 16:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10844);
                uiNextActionTimer = 12000;
                break;
            }
            case 17:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10845);
                uiNextActionTimer = 12000;
                break;
            }
            case 18:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10846);
                uiNextActionTimer = 12000;
                break;
            }
            case 19:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10847);
                uiNextActionTimer = 12000;
                break;
            }
            case 20:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10848);
                uiNextActionTimer = 9000;
                break;
            }
            case 21:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10849);
                uiNextActionTimer = 3000;
                break;
            }
            case 22:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10850);
                uiNextActionTimer = 12000;
                break;
            }
            case 23:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10851);
                uiNextActionTimer = 9000;
                break;
            }
            case 24:
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_creature->MonsterSay(10852);
                uiNextActionTimer = 3000;
                break;
            }
            case 25:
            {
                if (Creature* Crea = m_creature->FindNearestCreature(15180, 50.0f))    // Baristolth of the Shifting Sands
                    Crea->MonsterTextEmote(10853, nullptr, false);
                uiNextActionTimer = 4000;
                break;
            }
            case 26:
            {
                if (Creature* Crea = m_creature->FindNearestCreature(15180, 50.0f))    // Baristolth of the Shifting Sands
                    Crea->MonsterSay(10854);
                uiNextActionTimer = 5000;
                break;
            }
            case 27:
            {
                for (const auto& guid : lCrystalGUIDs)
                {
                    if (GameObject* pCrystal = m_creature->GetMap()->GetGameObject(guid))
                        pCrystal->Delete();
                }
                lCrystalGUIDs.clear();
                uiNextActionTimer = 5000;
                break;
            }
            case 28:
            {
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                uiCurrAction = 0;
                uiNextActionTimer = 0;
                return;
            }
            default:
            {
                uiNextActionTimer = 4000;
                break;
            }
        }
        ++uiCurrAction;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (uiCurrAction)
        {
            if (uiNextActionTimer < uiDiff)
                Larksbane_DoAction();
            else
                uiNextActionTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_Geologist_Larksbane(Creature* pCreature)
{
    return new npc_Geologist_LarksbaneAI(pCreature);
}

bool QuestComplete_npc_Geologist_Larksbane(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    if (pQuest->GetQuestId() != 8315) // The Calling
        return false;

    if (npc_Geologist_LarksbaneAI* pLark = dynamic_cast<npc_Geologist_LarksbaneAI*>(pQuestGiver->AI()))
        pLark->QuestCompleted(pPlayer, pQuest);
    return true;
}

/*###
 ## npc_Emissary_Romankhan
 ###*/

/*
 UPDATE `creature_template` SET `minmana` = 432240, `maxmana` = 434240, `armor` = 3769, `speed_walk` = 1.24, `speed_run` = 1.24, `base_attack_time` = 1280,
 `resistance1` = 0, `mingold` = 4031, `maxgold` = 4031, `mechanic_immune_mask` = 650854367, `MovementType` = 1,
 `script_name` = 'npc_Emissary_Romankhan' WHERE `entry` = 14862;
 */

enum
{
    SPELL_WILT                  = 23772,
    SPELL_SUFFERING_OF_SANITY   = 23773,
    SPELL_SYSTEM_SHOCK          = 23774
};

struct npc_Emissary_RomankhanAI : public ScriptedAI
{
    npc_Emissary_RomankhanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        pCreature->SetVisibility(VISIBILITY_OFF);

        OverlordCount = 0;
        if (Creature* add = pCreature->SummonCreature(15288, -7233.39f, 906.415f, -1.76649f, 1.81259f, TEMPSUMMON_DEAD_DESPAWN, 0))   // Aluntir
            add->JoinCreatureGroup(pCreature, 0, 0, OPTION_RESPAWN_TOGETHER);
        if (Creature* add = pCreature->SummonCreature(15286, -7212.16f, 911.711f, -1.76649f, 2.58543f, TEMPSUMMON_DEAD_DESPAWN, 0))   // Xil'xix
            add->JoinCreatureGroup(pCreature, 0, 0, OPTION_RESPAWN_TOGETHER);
        if (Creature* add = pCreature->SummonCreature(15290, -7210.3f, 895.014f, -1.76649f, 0.544185f, TEMPSUMMON_DEAD_DESPAWN, 0))   // Arakis
            add->JoinCreatureGroup(pCreature, 0, 0, OPTION_RESPAWN_TOGETHER);
        Reset();
    }

    int OverlordCount;
    uint32 m_uiWiltTimer;
    uint32 m_uiSchockTimer;
    uint32 m_uiSanityTimer;
    uint32 m_uiCheckPlayerTimer;
    uint64 PlayerGuids[60];

    bool m_bNeedCheck;

    void Reset() override
    {
        m_uiWiltTimer = urand(3000, 5000);
        m_uiSchockTimer = urand(8000, 12000);
        m_uiSanityTimer = 1;
        m_uiCheckPlayerTimer = 1000;
        m_bNeedCheck = false;
        m_creature->ClearCreatureState(CSTATE_REGEN_MANA);
        m_creature->SetPower(POWER_MANA, 0);

        for (uint64 & guid : PlayerGuids)
            guid = 0;
    }

    void SummonedCreatureJustDied(Creature* unit) override
    {
        ++OverlordCount;
        if (OverlordCount >= 3)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            m_creature->SetVisibility(VISIBILITY_ON);
        }
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->AddCreatureState(CSTATE_REGEN_MANA);
    }

    inline float GetManaPercent()
    {
        return (((float)m_creature->GetPower(POWER_MANA) / (float)m_creature->GetMaxPower(POWER_MANA)) * 100);
    }

    void SpellHitTarget(Unit* target, SpellEntry const* pSpell) override
    {
        if (!target || !target->IsPlayer())
            return;

        if (pSpell->Id == SPELL_WILT || pSpell->Id == SPELL_SUFFERING_OF_SANITY || pSpell->Id == SPELL_SYSTEM_SHOCK)
        {
            for (uint64 guid : PlayerGuids)
                if (guid == target->GetGUID())
                    return;

            for (uint64 & guid : PlayerGuids)
            {
                if (guid == 0)
                {
                    guid = target->GetGUID();
                    break;
                }
            }
            m_bNeedCheck = true;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiSchockTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (pTarget->GetTypeId() == TYPEID_PLAYER)
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_SYSTEM_SHOCK) == CAST_OK)
                        m_uiSchockTimer = urand(6000, 10000);
                }
                else
                    m_uiSchockTimer = 1000;
            }
        }
        else
            m_uiSchockTimer -= uiDiff;

        if (m_uiWiltTimer < uiDiff)
        {
            for (uint64 & guid : PlayerGuids)
                guid = 0;
            if (DoCastSpellIfCan(m_creature, SPELL_WILT) == CAST_OK)
                m_uiWiltTimer = urand(3000, 5000);
        }
        else
            m_uiWiltTimer -= uiDiff;

        if (GetManaPercent() == 100.0f)
        {
            if (m_uiSanityTimer < uiDiff)
            {
                for (uint64 & guid : PlayerGuids)
                    guid = 0;
                if (DoCastSpellIfCan(m_creature, SPELL_SUFFERING_OF_SANITY) == CAST_OK)
                    m_uiSanityTimer = 1000;
            }
            else
                m_uiSanityTimer -= uiDiff;
        }
        else if (m_uiSanityTimer != 1)
            m_uiSanityTimer = 1;

        DoMeleeAttackIfReady();

        if (!m_bNeedCheck)
            return;

        if (m_uiCheckPlayerTimer < uiDiff)
        {
            for (uint64 & guid : PlayerGuids)
            {
                if (guid == 0)
                    continue;

                if (Unit* pTarget = m_creature->GetMap()->GetUnit(guid))
                {
                    pTarget->SetInCombatWith(m_creature);
                    if (pTarget->IsDead())
                    {
                        // + 2% MP at each death
                        float currMana = m_creature->GetPower(POWER_MANA);
                        float MaxMana = m_creature->GetMaxPower(POWER_MANA);
                        m_creature->SetPower(POWER_MANA, (currMana + MaxMana * 0.02f) < MaxMana ? (currMana + MaxMana * 0.02f) : MaxMana);

                        guid = 0;
                    }
                }
            }
            m_bNeedCheck = false;
            m_uiCheckPlayerTimer = 1000;
        }
        else
            m_uiCheckPlayerTimer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_Emissary_Romankhan(Creature* pCreature)
{
    return new npc_Emissary_RomankhanAI(pCreature);
}

/*###
 ## npc_anachronos_the_ancient
 ###*/

enum
{
    // Dragons
    NPC_MERITHRA_OF_THE_DREAM = 15378,
    NPC_CAELESTRASZ = 15379,
    NPC_ARYGOS = 15380,
    NPC_ANACHRONOS_THE_ANCIENT = 15381,
    NPC_ANACHRONOS_QUEST_TRIGGER = 15454, // marks some movement for the dragons

    // Elfs
    NPC_FANDRAL_STAGHELM = 15382,
    NPC_KALDOREI_INFANTRY = 15423,

    // Qiraji warriors
    NPC_QIRAJI_WASP = 15414,
    NPC_QIRAJI_DRONE = 15421,
    NPC_QIRAJI_TANK = 15422,
    NPC_ANUBISATH_CONQUEROR = 15424,

    QUEST_A_PAWN_ON_THE_ETERNAL_BOARD = 8519,

    // Yells -> in chronological order
    SAY_ANACHRONOS_INTRO_1 = -1000753,
    SAY_FANDRAL_INTRO_2 = -1000754,
    SAY_MERITHRA_INTRO_3 = -1000755,
    EMOTE_ARYGOS_NOD = -1000756,
    SAY_CAELESTRASZ_INTRO_4 = -1000757,
    EMOTE_MERITHRA_GLANCE = -1000758,
    SAY_MERITHRA_INTRO_5 = -1000759,

    SAY_MERITHRA_ATTACK_1 = -1000760,
    SAY_ARYGOS_ATTACK_2 = -1000761,
    SAY_ARYGOS_ATTACK_3 = -1000762,
    SAY_CAELESTRASZ_ATTACK_4 = -1000763,
    SAY_CAELESTRASZ_ATTACK_5 = -1000764,

    SAY_ANACHRONOS_SEAL_1 = -1000765,
    SAY_FANDRAL_SEAL_2 = -1000766,
    SAY_ANACHRONOS_SEAL_3 = -1000767,
    SAY_ANACHRONOS_SEAL_4 = -1000768,
    SAY_ANACHRONOS_SEAL_5 = -1000769,
    SAY_FANDRAL_SEAL_6 = -1000770,

    EMOTE_FANDRAL_EXHAUSTED = -1000771,
    SAY_ANACHRONOS_EPILOGUE_1 = -1000772,
    SAY_ANACHRONOS_EPILOGUE_2 = -1000773,
    SAY_ANACHRONOS_EPILOGUE_3 = -1000774,
    EMOTE_ANACHRONOS_SCEPTER = -1000775,
    SAY_FANDRAL_EPILOGUE_4 = -1000776,
    SAY_FANDRAL_EPILOGUE_5 = -1000777,
    EMOTE_FANDRAL_SHATTER = -1000778,
    SAY_ANACHRONOS_EPILOGUE_6 = -1000779,
    SAY_FANDRAL_EPILOGUE_7 = -1000780,
    EMOTE_ANACHRONOS_DISPPOINTED = -1000781,
    EMOTE_ANACHRONOS_PICKUP = -1000782,
    SAY_ANACHRONOS_EPILOGUE_8 = -1000783,

    // The transform spell for Anachronos was removed from DBC
    //DISPLAY_ID_BRONZE_DRAGON = 15500,

    // Spells
    SPELL_GREEN_DRAGON_TRANSFORM = 25105,
    SPELL_RED_DRAGON_TRANSFORM = 25106,
    SPELL_BLUE_DRAGON_TRANSFORM = 25107,
    SPELL_BRONZE_DRAGON_TRANSFORM = 25108, // Spell was removed - exists only before 2.0.1

    SPELL_MERITHRA_WAKE = 25145, // should trigger 25172 on targets
    SPELL_WAKE_VISUAL = 25172,
    GO_MERITHRA_WAKE =  180604,  // For green fog visual
    SPELL_ARYGOS_VENGEANCE = 25149,
    SPELL_VENGEANCE_VISUAL = 25168,
    SPELL_CAELESTRASZ_MOLTEN_RAIN = 25150,
    SPELL_MOLTEN_RAIN_VISUAL = 25169,
    SPELL_MOLTEN_RAIN_DAMAGE = 25170,

    SPELL_TIME_STOP = 25158, // Anachronos stops the battle - should trigger 25171
    SPELL_GLYPH_OF_WARDING = 25166, // Sends event 9427 - should activate Go 176148
    SPELL_PRISMATIC_BARRIER = 25159, // Sends event 9425 - should activate Go 176146
    SPELL_CALL_ANCIENTS = 25167, // Sends event 9426 - should activate Go 176147
    SPELL_SHATTER_HAMMER = 25182, // Breakes the scepter - needs DB coords

    POINT_ID_DRAGON_ATTACK = 0,
    POINT_ID_EXIT = 1,
    POINT_ID_GATE = 2,
    POINT_ID_SCEPTER = 3,
    POINT_ID_SCEPTER_1 = 4,
    POINT_ID_SCEPTER_2 = 5,
    POINT_ID_EPILOGUE = 6,

    MAX_DRAGONS = 4,
    MAX_CONQUERORS = 3,
    MAX_QIRAJI = 6,
    MAX_KALDOREI = 20,

    GO_AQ_BARRIER           = 176146,
    GO_AQ_GATE_ROOTS        = 176147,
    GO_AQ_GATE_RUNES        = 176148,
    GO_AQ_GHOST_GATE        = 180322,

    AQ_OPEN_IF_CLOSED = 0,
    AQ_PREPARE_CLOSE = 1,
    AQ_CLOSE = 2,
    AQ_RESET = 3,
    AQ_CLOSE_QUIETLY = 4,

    SCENE_BLOCK_TIME = 15 * MINUTE * IN_MILLISECONDS,
};

struct EventLocations
{
    float m_fX, m_fY, m_fZ, m_fO;
    uint32 m_uiEntry;
};

static EventLocations aEternalBoardNPCs[MAX_DRAGONS] =
{
    { -8029.301f, 1534.612f, 2.609f, 3.121f, NPC_FANDRAL_STAGHELM},
    { -8034.227f, 1536.580f, 2.609f, 6.161f, NPC_ARYGOS},
    { -8031.935f, 1532.658f, 2.609f, 1.012f, NPC_CAELESTRASZ},
    { -8034.106f, 1534.224f, 2.609f, 0.290f, NPC_MERITHRA_OF_THE_DREAM},
};

static EventLocations aQirajiWarriors[MAX_CONQUERORS] =
{
    { -8092.12f, 1508.32f, 2.94f, 0.0f, 0},
    { -8096.54f, 1525.84f, 2.83f, 0.0f, 0}, // Also used as an anchor point for the rest of the summons
    { -8097.81f, 1541.74f, 2.88f, 0.0f, 0},
};

static EventLocations aEternalBoardMovement[] =
{
    { -8250.951f, 1500.241f, 110.0f, 0.0f, 0}, // Flight position for dragons
    { -8107.867f, 1526.102f, 2.645f, 0.0f, 0}, // Anachronos gate location
    { -8103.861f, 1525.923f, 2.677f, 0.0f, 0}, // Fandral gate location
    { -8110.313f, 1522.049f, 2.618f, 0.0f, 0}, // Shattered scepter
    { -8100.921f, 1527.740f, 2.871f, 0.0f, 0}, // Fandral epilogue location
    { -8115.270f, 1515.926f, 3.305f, 0.0f, 0}, // Anachronos gather broken scepter 1
    { -8116.879f, 1530.615f, 3.762f, 0.0f, 0}, // Anachronos gather broken scepter 2
    { -7997.790f, 1548.664f, 3.738f, 0.0f, 0}, // Fandral exit location
    { -8061.933f, 1496.196f, 2.556f, 0.0f, 0}, // Anachronos launch location
    { -8008.705f, 1446.063f, 44.104f, 0.0f, 0}, // Anachronos flight location
};

struct npc_anachronos_the_ancientAI : public ScriptedAI
{
    npc_anachronos_the_ancientAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiEventTimer;

    uint8 m_uiEventStage;

    ObjectGuid m_uiFandralGUID;
    ObjectGuid m_uiMerithraGUID;
    ObjectGuid m_uiCaelestraszGUID;
    ObjectGuid m_uiArygosGUID;
    ObjectGuid m_uiPlayerGUID;
    ObjectGuid m_uiTriggerGUID;

    GameObject* go_aq_barrier;
    GameObject* go_aq_gate_runes;
    GameObject* go_aq_gate_roots;

    std::list<uint64> m_lQirajiWarriorsList;

    // Needed to restore gate to state before scene
    bool AQopen;

    void Reset() override
    {
        // We summon the rest of the dragons on timer
        m_uiEventTimer = 0;
        m_uiEventStage = 0;

        m_uiFandralGUID.Clear();
        m_uiMerithraGUID.Clear();
        m_uiCaelestraszGUID.Clear();
        m_uiArygosGUID.Clear();
        m_uiPlayerGUID.Clear();
        m_uiTriggerGUID.Clear();

        go_aq_barrier = nullptr;
        go_aq_gate_runes = nullptr;
        go_aq_gate_roots = nullptr;

        AQopen = true;

        m_creature->SetRespawnDelay(DAY);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void BeginScene()
    {
        m_uiEventTimer = 100;
    }

    void AbortScene()
    {
        m_uiEventStage = 0;
        m_uiEventTimer = 0;

        DoUnsummonArmy();

        // Despawn Dragons + Fandral
        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
            pFandral->ForcedDespawn();

        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
            pMerithra->ForcedDespawn();

        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
            pCaelestrasz->ForcedDespawn();

        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
            pArygos->ForcedDespawn();

        // Close AQ gates quietly
        SetupAQGate(AQ_CLOSE_QUIETLY);

        // Anachronos will go invisible, blocking new attempts to
        // start the scene until the time is up
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->ForcedDespawn(SCENE_BLOCK_TIME);
    }

    void JustDied(Unit* killer) override
    {
        AbortScene();
    }

    void SetupAQGate(uint32 phase)
    {
        if (AQ_OPEN_IF_CLOSED == phase)
        {
            go_aq_barrier = GetClosestGameObjectWithEntry(m_creature, GO_AQ_BARRIER, 200);
            go_aq_gate_runes = GetClosestGameObjectWithEntry(m_creature, GO_AQ_GATE_RUNES, 200);
            go_aq_gate_roots = GetClosestGameObjectWithEntry(m_creature, GO_AQ_GATE_ROOTS, 200);
        }

        AnimateAQGate(go_aq_barrier, phase);
        AnimateAQGate(go_aq_gate_runes, phase);
        AnimateAQGate(go_aq_gate_roots, phase);
    }

    void AnimateAQGate(GameObject* go, uint32 phase = AQ_CLOSE)
    // Phase 0: Open, make invisible
    // Phase 1: Make (open) doors visible
    // Phase 2: Close doors
    // Phase 3: Return to original state if required
    {
        if (nullptr == go)
            return;

        switch (phase)
        {
            case AQ_OPEN_IF_CLOSED:
                // Check if AQ currently closed
                if (go->GetGoState() == GO_STATE_READY)
                {
                    AQopen = false;

                    // Set to open without animation
                    go->SetGoState(GO_STATE_ACTIVE);
                    go->SetVisible(false);
                }

                break;

            case AQ_PREPARE_CLOSE:
                // Prepare for close visual
                go->SetVisible(true);
                break;

            case AQ_CLOSE:

                // Close gates with animation
                go->ResetDoorOrButton();
                go->SetGoState(GO_STATE_READY);

                break;

            case AQ_CLOSE_QUIETLY:
                go->SetVisible(false);
                AnimateAQGate(go, AQ_CLOSE);
                go->SetVisible(true);

                break;

            case AQ_RESET:

                // Return to original state, if necessary
                if (AQopen)
                {
                    go->SetGoState(GO_STATE_ACTIVE);
                    go->SetVisible(false);
                    go->SetVisible(true);
                }
                break;

        }
    }

    void DoSummonDragons()
    {
        for (const auto& spawnData : aEternalBoardNPCs)
            m_creature->SummonCreature(spawnData.m_uiEntry, spawnData.m_fX, spawnData.m_fY, spawnData.m_fZ, spawnData.m_fO, TEMPSUMMON_CORPSE_DESPAWN, 0);
    }

    void DoSummonWarriors()
    {
        float fX, fY, fZ;
        // Summon kaldorei warriors
        for (uint8 i = 0; i < MAX_KALDOREI; ++i)
        {
            m_creature->GetRandomPoint(aQirajiWarriors[1].m_fX, aQirajiWarriors[1].m_fY, aQirajiWarriors[1].m_fZ, 20.0f, fX, fY, fZ);
            m_creature->SummonCreature(NPC_KALDOREI_INFANTRY, fX, fY, fZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }

        // Summon Qiraji warriors
        for (uint8 i = 0; i < MAX_QIRAJI; ++i)
        {
            m_creature->GetRandomPoint(aQirajiWarriors[1].m_fX, aQirajiWarriors[1].m_fY, aQirajiWarriors[1].m_fZ, 20.0f, fX, fY, fZ);
            m_creature->SummonCreature(NPC_QIRAJI_WASP, fX, fY, fZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

            m_creature->GetRandomPoint(aQirajiWarriors[1].m_fX, aQirajiWarriors[1].m_fY, aQirajiWarriors[1].m_fZ, 20.0f, fX, fY, fZ);
            m_creature->SummonCreature(NPC_QIRAJI_DRONE, fX, fY, fZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

            m_creature->GetRandomPoint(aQirajiWarriors[1].m_fX, aQirajiWarriors[1].m_fY, aQirajiWarriors[1].m_fZ, 20.0f, fX, fY, fZ);
            m_creature->SummonCreature(NPC_QIRAJI_TANK, fX, fY, fZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }

        // Also summon the 3 anubisath conquerors
        for (const auto& spawnData : aQirajiWarriors)
            m_creature->SummonCreature(NPC_ANUBISATH_CONQUEROR, spawnData.m_fX, spawnData.m_fY, spawnData.m_fZ, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
    }

    void DoUnsummonArmy()
    {
        for (const auto& guid : m_lQirajiWarriorsList)
        {
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(guid))
                pTemp->DisappearAndDie();
        }
    }

    void AddKaldoreiThreat(Creature* npc)
    {
        for (const auto& guid : m_lQirajiWarriorsList)
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(guid))
                if (pTemp->GetEntry() == NPC_KALDOREI_INFANTRY)
                    npc->AddThreat(pTemp, 100.0f);

    }

    void JustSummoned(Creature* pSummoned) override
    {
        // Also remove npc flags where needed
        switch (pSummoned->GetEntry())
        {
            case NPC_FANDRAL_STAGHELM:
                m_uiFandralGUID = pSummoned->GetObjectGuid();
                break;
            case NPC_MERITHRA_OF_THE_DREAM:
                m_uiMerithraGUID = pSummoned->GetObjectGuid();
                pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                break;
            case NPC_CAELESTRASZ:
                m_uiCaelestraszGUID = pSummoned->GetObjectGuid();
                pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                break;
            case NPC_ARYGOS:
                m_uiArygosGUID = pSummoned->GetObjectGuid();
                pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                break;
            case NPC_ANUBISATH_CONQUEROR:
            case NPC_QIRAJI_WASP:
            case NPC_QIRAJI_DRONE:
            case NPC_QIRAJI_TANK:
                pSummoned->SetFactionTemplateId(14);
                //pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_lQirajiWarriorsList.push_back(pSummoned->GetObjectGuid());

                AddKaldoreiThreat(pSummoned);

                // Commence hostilities
                if(Creature* target = GetClosestCreatureWithEntry(pSummoned, NPC_KALDOREI_INFANTRY, 40.0f))
                {
                    pSummoned->AddThreat(target, 100.0f);
                    m_creature->GetMotionMaster()->MoveChase(target);
                    pSummoned->AI()->AttackStart(target);

                    target->AddThreat(pSummoned, 100.0f);
                    target->GetMotionMaster()->MoveChase(pSummoned);
                    target->AI()->AttackStart(pSummoned);
                }

                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);

                break;
            case NPC_KALDOREI_INFANTRY:
                pSummoned->SetFactionTemplateId(1608);
                m_lQirajiWarriorsList.push_back(pSummoned->GetObjectGuid());
                break;
        }

        pSummoned->SetRespawnDelay(DAY);
    }

    void DoCastTriggerSpellOnEnemies(uint32 spell)
    {
        for (const auto& guid : m_lQirajiWarriorsList)
        {
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(guid))
            {
                // Cast trigger spell only on enemies
                if (pTemp->GetEntry() == NPC_ANUBISATH_CONQUEROR || pTemp->GetEntry() == NPC_QIRAJI_DRONE ||
                    pTemp->GetEntry() == NPC_QIRAJI_TANK || pTemp->GetEntry() == NPC_QIRAJI_WASP)
                {
                    if (spell == SPELL_WAKE_VISUAL)
                    {
                        if(pTemp->GetEntry() == NPC_ANUBISATH_CONQUEROR)
                        {
                            pTemp->CastSpell(pTemp, spell, true);
                            pTemp->SummonGameObject(GO_MERITHRA_WAKE, pTemp->GetPositionX(), pTemp->GetPositionY(), pTemp->GetPositionZ(), 0);
                        }
                    }
                    else
                        pTemp->CastSpell(pTemp, spell, true);
                }
            }
        }
    }

    void DoTimeStopArmy()
    {
        for (const auto& guid : m_lQirajiWarriorsList)
        {
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(guid))
            {
                // Stop movement/attacks and freeze whole combat
                pTemp->RemoveAllAttackers();
                pTemp->AttackStop();
                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pTemp->AI()->EnterEvadeMode();
                pTemp->StopMoving();
                pTemp->GetMotionMaster()->Clear(true);
                pTemp->CastSpell(pTemp, 25171, true);
            }
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiPointId)
        {
            case POINT_ID_GATE:
                // Cast time stop when he reaches the gate
                DoScriptText(SAY_ANACHRONOS_SEAL_4, m_creature);
                DoCastSpellIfCan(m_creature, SPELL_TIME_STOP);
                DoTimeStopArmy();
                m_uiEventTimer = 7000;
                break;
            case POINT_ID_SCEPTER_1:
                // Pickup the pieces

                DoScriptText(EMOTE_ANACHRONOS_PICKUP, m_creature);
                m_uiEventTimer = 2000;
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;

            case POINT_ID_SCEPTER_2:

                DoScriptText(SAY_ANACHRONOS_EPILOGUE_8, m_creature);
                m_uiEventTimer = 4000;
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;

            case POINT_ID_EXIT:
                m_uiEventTimer = 1000;
                break;
        }
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (pSummoned->GetEntry() == NPC_FANDRAL_STAGHELM)
        {
            switch (uiPointId)
            {
                case POINT_ID_EPILOGUE:
                    DoScriptText(SAY_FANDRAL_EPILOGUE_7, pSummoned);
                    pSummoned->SetFacingToObject(m_creature);
                    DoUnsummonArmy();
                    SetupAQGate(AQ_RESET);
                    m_uiEventTimer = 8000;
                    break;
                case POINT_ID_SCEPTER:
                    pSummoned->GetMotionMaster()->MovePoint(POINT_ID_EPILOGUE, aEternalBoardMovement[4].m_fX, aEternalBoardMovement[4].m_fY, aEternalBoardMovement[4].m_fZ);
                    break;
                case POINT_ID_EXIT:
                    pSummoned->ForcedDespawn();
                    break;
            }
        }
        else if (uiPointId == POINT_ID_DRAGON_ATTACK)
        {
            switch (pSummoned->GetEntry())
            {
                case NPC_MERITHRA_OF_THE_DREAM:
                    DoScriptText(SAY_MERITHRA_ATTACK_1, pSummoned);
                    m_uiEventTimer = 5000;
                    break;
                case NPC_CAELESTRASZ:
                    DoScriptText(SAY_CAELESTRASZ_ATTACK_5, pSummoned);
                    m_uiEventTimer = 3000;
                    break;
                case NPC_ARYGOS:
                    DoScriptText(SAY_ARYGOS_ATTACK_3, pSummoned);
                    m_uiEventTimer = 4000;
                    break;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiEventTimer)
        {
            if (m_uiEventTimer <= uiDiff)
            {
                switch (m_uiEventStage)
                {
                    case 0:
                        // Summon the other dragons
                        DoSummonDragons();
                        m_uiEventTimer = 2000;
                        break;
                    case 1:
                        DoScriptText(SAY_ANACHRONOS_INTRO_1, m_creature);
                        m_uiEventTimer = 3000;
                        break;
                    case 2:
                        // Summon warriors
                        DoSummonWarriors();
                        SetupAQGate(AQ_OPEN_IF_CLOSED);

                        m_creature->HandleEmote(EMOTE_ONESHOT_SHOUT);
                        m_uiEventTimer = 3000;
                        break;
                    case 3:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->SetFacingToObject(m_creature);
                            DoScriptText(SAY_FANDRAL_INTRO_2, pFandral);
                        }
                        m_uiEventTimer = 6000;
                        break;
                    case 4:
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                        {
                            if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                                pFandral->SetFacingToObject(pMerithra);

                            DoScriptText(EMOTE_MERITHRA_GLANCE, pMerithra);
                        }
                        m_uiEventTimer = 2000;
                        break;
                    case 5:
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                            DoScriptText(SAY_MERITHRA_INTRO_3, pMerithra);
                        m_uiEventTimer = 3000;
                        break;
                    case 6:
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                        {
                            DoScriptText(EMOTE_ARYGOS_NOD, pArygos);
                            pArygos->HandleEmote(EMOTE_ONESHOT_YES);
                        }
                        m_uiEventTimer = 4000;
                        break;
                    case 7:
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                            DoScriptText(SAY_CAELESTRASZ_INTRO_4, pCaelestrasz);
                        m_uiEventTimer = 9000;
                        break;
                    case 8:
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                            DoScriptText(SAY_MERITHRA_INTRO_5, pMerithra);
                        m_uiEventTimer = 5000;
                        break;
                    case 9:
                        // Send Merithra to attack - continue when point is reached
                        if (Creature* pTrigger = GetClosestCreatureWithEntry(m_creature, NPC_ANACHRONOS_QUEST_TRIGGER, 60.0f))
                        {
                            m_uiTriggerGUID = pTrigger->GetObjectGuid();
                            if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                            {
                                pMerithra->SetWalk(false);
                                pMerithra->GetMotionMaster()->MovePoint(POINT_ID_DRAGON_ATTACK, pTrigger->GetPositionX(), pTrigger->GetPositionY(), pTrigger->GetPositionZ());
                                pMerithra->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pMerithra->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pMerithra->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                        }
                        m_uiEventTimer = 0;
                        break;
                    case 10:
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                            pMerithra->CastSpell(pMerithra, SPELL_GREEN_DRAGON_TRANSFORM, false);
                        m_uiEventTimer = 2000;
                        break;
                    case 11:
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                            pMerithra->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
                        m_uiEventTimer = 1000;
                        break;
                    case 12:
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                            DoScriptText(SAY_ARYGOS_ATTACK_2, pArygos);

                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                        {
                            pMerithra->AddAura(17131); // hover
                            pMerithra->CastSpell(pMerithra, SPELL_MERITHRA_WAKE, false);
                        }
                        m_uiEventTimer = 3000;
                        break;

                    case 13:
                        DoCastTriggerSpellOnEnemies(SPELL_WAKE_VISUAL);
                        m_uiEventTimer = 5000;
                        break;

                    case 14:
                        // Send Merithra on flight
                        if (Creature* pMerithra = m_creature->GetMap()->GetCreature(m_uiMerithraGUID))
                        {
                            pMerithra->SetFly(true);
                            pMerithra->GetMotionMaster()->MovePoint(POINT_ID_EXIT, aEternalBoardMovement[0].m_fX, aEternalBoardMovement[0].m_fY, aEternalBoardMovement[0].m_fZ);
                            pMerithra->ForcedDespawn(20000);
                        }
                        m_uiEventTimer = 1000;
                        break;

                    case 15:
                        // Send Arygos in combat
                        if (Creature* pTrigger = m_creature->GetMap()->GetCreature(m_uiTriggerGUID))
                        {
                            if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                            {
                                pArygos->SetWalk(false);
                                pArygos->GetMotionMaster()->MovePoint(POINT_ID_DRAGON_ATTACK, pTrigger->GetPositionX(), pTrigger->GetPositionY(), pTrigger->GetPositionZ());
                                pArygos->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pArygos->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pArygos->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                        }
                        m_uiEventTimer = 0;
                        break;

                    case 16:
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                            pArygos->CastSpell(pArygos, SPELL_BLUE_DRAGON_TRANSFORM, false);
                        m_uiEventTimer = 2000;
                        break;
                    case 17:
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                            pArygos->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
                        m_uiEventTimer = 1000;
                        break;
                    case 18:
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                        {
                            pArygos->AddAura(17131); // hover
                            pArygos->CastSpell(pArygos, SPELL_ARYGOS_VENGEANCE, false);
                        }
                        m_uiEventTimer = 3000;
                        break;

                    case 19:
                        DoCastTriggerSpellOnEnemies(SPELL_VENGEANCE_VISUAL);
                        m_uiEventTimer = 3000;
                        break;

                    case 20:
                        SetupAQGate(AQ_PREPARE_CLOSE);
                        // Send Arygos on flight
                        if (Creature* pArygos = m_creature->GetMap()->GetCreature(m_uiArygosGUID))
                        {
                            pArygos->SetFly(true);
                            pArygos->GetMotionMaster()->MovePoint(POINT_ID_EXIT, aEternalBoardMovement[0].m_fX, aEternalBoardMovement[0].m_fY, aEternalBoardMovement[0].m_fZ);
                            pArygos->ForcedDespawn(20000);
                        }
                        m_uiEventTimer = 1000;
                        break;
                    case 21:
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                            DoScriptText(SAY_CAELESTRASZ_ATTACK_4, pCaelestrasz);
                        m_uiEventTimer = 1000;
                        break;
                    case 22:
                        // Send Caelastrasz in combat
                        if (Creature* pTrigger = m_creature->GetMap()->GetCreature(m_uiTriggerGUID))
                        {
                            if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                            {
                                pCaelestrasz->SetWalk(false);
                                pCaelestrasz->GetMotionMaster()->MovePoint(POINT_ID_DRAGON_ATTACK, pTrigger->GetPositionX(), pTrigger->GetPositionY(), pTrigger->GetPositionZ());
                                pCaelestrasz->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pCaelestrasz->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pCaelestrasz->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                        }
                        m_uiEventTimer = 0;
                        break;
                    case 23:
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                            pCaelestrasz->CastSpell(pCaelestrasz, SPELL_RED_DRAGON_TRANSFORM, false);
                        m_uiEventTimer = 2000;
                        break;
                    case 24:
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                            pCaelestrasz->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
                        m_uiEventTimer = 1000;
                        break;
                    case 25:
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                        {
                            pCaelestrasz->AddAura(17131); // hover
                            pCaelestrasz->CastSpell(pCaelestrasz, SPELL_CAELESTRASZ_MOLTEN_RAIN, false);
                        }
                        m_uiEventTimer = 3000;
                        break;
                    case 26:
                        DoCastTriggerSpellOnEnemies(SPELL_MOLTEN_RAIN_VISUAL);
                        DoCastTriggerSpellOnEnemies(SPELL_MOLTEN_RAIN_DAMAGE);
                        m_uiEventTimer = 5000;
                        break;

                    case 27:
                        // Send Caelestrasz on flight
                        if (Creature* pCaelestrasz = m_creature->GetMap()->GetCreature(m_uiCaelestraszGUID))
                        {
                            pCaelestrasz->SetFly(true);
                            pCaelestrasz->GetMotionMaster()->MovePoint(POINT_ID_EXIT, aEternalBoardMovement[0].m_fX, aEternalBoardMovement[0].m_fY, aEternalBoardMovement[0].m_fZ);
                            pCaelestrasz->ForcedDespawn(20000);
                        }
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                            m_creature->SetFacingToObject(pFandral);
                        DoScriptText(SAY_ANACHRONOS_SEAL_1, m_creature);
                        m_uiEventTimer = 5000;
                        break;
                    case 28:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->SetFacingToObject(m_creature);
                            DoScriptText(SAY_FANDRAL_SEAL_2, pFandral);
                        }
                        m_uiEventTimer = 3000;
                        break;
                    case 29:
                        DoScriptText(SAY_ANACHRONOS_SEAL_3, m_creature);
                        m_uiEventTimer = 1000;
                        break;
                    case 30:
                        // Send Anachronos and Fandral to the gate
                        m_creature->SetWalk(false);
                        m_creature->GetMotionMaster()->MovePoint(POINT_ID_GATE, aEternalBoardMovement[1].m_fX, aEternalBoardMovement[1].m_fY, aEternalBoardMovement[1].m_fZ);
                        m_uiEventTimer = 1000;
                        break;
                    case 31:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->SetWalk(false);
                            pFandral->GetMotionMaster()->MovePoint(POINT_ID_GATE, aEternalBoardMovement[2].m_fX, aEternalBoardMovement[2].m_fY, aEternalBoardMovement[2].m_fZ);
                        }
                        m_uiEventTimer = 0;
                        break;
                    case 32:
                        DoCastSpellIfCan(m_creature, SPELL_PRISMATIC_BARRIER);

                        AnimateAQGate(go_aq_barrier);


                        m_uiEventTimer = 5000;
                        break;
                    case 33:
                        DoCastSpellIfCan(m_creature, SPELL_GLYPH_OF_WARDING);

                        AnimateAQGate(go_aq_gate_runes);

                        m_uiEventTimer = 4000;
                        break;
                    case 34:
                        DoScriptText(SAY_ANACHRONOS_SEAL_5, m_creature);
                        m_uiEventTimer = 3000;
                        break;
                    case 35:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->CastSpell(pFandral, SPELL_CALL_ANCIENTS, false);

                            AnimateAQGate(go_aq_gate_roots);
                            DoScriptText(SAY_FANDRAL_SEAL_6, pFandral);
                        }
                        m_uiEventTimer = 9000;
                        break;
                    case 36:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            DoScriptText(EMOTE_FANDRAL_EXHAUSTED, pFandral);
                            pFandral->SetStandState(UNIT_STAND_STATE_KNEEL);
                            m_creature->SetFacingToObject(pFandral);
                        }
                        m_uiEventTimer = 1000;
                        break;
                    case 37:
                        DoScriptText(SAY_ANACHRONOS_EPILOGUE_1, m_creature);
                        m_uiEventTimer = 6000;
                        break;
                    case 38:
                        DoScriptText(SAY_ANACHRONOS_EPILOGUE_2, m_creature);
                        m_uiEventTimer = 5000;
                        break;
                    case 39:
                        DoScriptText(SAY_ANACHRONOS_EPILOGUE_3, m_creature);
                        m_uiEventTimer = 15000;
                        break;
                    case 40:
                        // ToDo: Make Fandral equip the scepter
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                            DoScriptText(EMOTE_ANACHRONOS_SCEPTER, m_creature, pFandral);
                        m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                        m_uiEventTimer = 3000;
                        break;
                    case 41:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(SAY_FANDRAL_EPILOGUE_4, pFandral);
                        }
                        m_uiEventTimer = 3000;
                        break;
                    case 42:
                        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                        m_uiEventTimer = 4000;
                        break;
                    case 43:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                            DoScriptText(SAY_FANDRAL_EPILOGUE_5, pFandral);
                        m_uiEventTimer = 9000;
                        break;
                    case 44:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->CastSpell(pFandral, SPELL_SHATTER_HAMMER, false);
                            DoScriptText(EMOTE_FANDRAL_SHATTER, pFandral);
                        }
                        m_uiEventTimer = 3000;
                        break;
                    case 45:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->SetWalk(true);
                            pFandral->GetMotionMaster()->MovePoint(POINT_ID_SCEPTER, aEternalBoardMovement[3].m_fX, aEternalBoardMovement[3].m_fY, aEternalBoardMovement[3].m_fZ);
                        }
                        DoScriptText(SAY_ANACHRONOS_EPILOGUE_6, m_creature);
                        m_uiEventTimer = 0;
                        break;
                    case 46:
                        if (Creature* pFandral = m_creature->GetMap()->GetCreature(m_uiFandralGUID))
                        {
                            pFandral->GetMotionMaster()->MovePoint(POINT_ID_EXIT, aEternalBoardMovement[7].m_fX, aEternalBoardMovement[7].m_fY, aEternalBoardMovement[7].m_fZ);
                            pFandral->ForcedDespawn(15000);
                        }
                        m_uiEventTimer = 4000;
                        break;
                    case 47:
                        DoScriptText(EMOTE_ANACHRONOS_DISPPOINTED, m_creature);
                        m_uiEventTimer = 1000;
                        break;
                    case 48:
                        m_creature->SetWalk(true);
                        m_creature->GetMotionMaster()->MovePoint(POINT_ID_SCEPTER_1, aEternalBoardMovement[5].m_fX, aEternalBoardMovement[5].m_fY, aEternalBoardMovement[5].m_fZ);
                        m_uiEventTimer = 0;
                        break;
                    case 49:
                        m_creature->GetMotionMaster()->MovePoint(POINT_ID_SCEPTER_2, aEternalBoardMovement[6].m_fX, aEternalBoardMovement[6].m_fY, aEternalBoardMovement[6].m_fZ);
                        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                        m_uiEventTimer = 0;
                        break;
                    case 50:
                        // Complete quest and despawn gate
                        if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_uiPlayerGUID))
                            pPlayer->GroupEventHappens(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD, m_creature);

                        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                        m_uiEventTimer = 4000;
                        break;
                    case 51:
                        // Move to exit
                        m_creature->SetWalk(false);
                        m_creature->GetMotionMaster()->MovePoint(POINT_ID_EXIT, aEternalBoardMovement[8].m_fX, aEternalBoardMovement[8].m_fY, aEternalBoardMovement[8].m_fZ);
                        m_uiEventTimer = 0;
                        break;
                    case 52:
                        // Spell was removed, manually change the display
                        //DoCastSpellIfCan(m_creature, SPELL_BRONZE_DRAGON_TRANSFORM);
                        //m_creature->SetDisplayId(DISPLAY_ID_BRONZE_DRAGON);
                        m_creature->SetWalk(true);
                        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                        m_creature->CastSpell(m_creature, SPELL_BRONZE_DRAGON_TRANSFORM, false);
                        m_uiEventTimer = 1000;
                        break;
                    case 53:
                        m_creature->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
                        m_uiEventTimer = 1000;
                        break;
                    case 54:
                        m_creature->ForcedDespawn(5000);
                        m_creature->SetFly(true);
                        m_creature->GetMotionMaster()->MovePoint(0, aEternalBoardMovement[9].m_fX, aEternalBoardMovement[9].m_fY, aEternalBoardMovement[9].m_fZ);
                        m_uiEventTimer = 0;
                        break;
                }
                ++m_uiEventStage;
            }
            else
                m_uiEventTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_anachronos_the_ancient(Creature* pCreature)
{
    return new npc_anachronos_the_ancientAI(pCreature);
}

bool QuestAcceptGO_crystalline_tear(Player* pPlayer, GameObject* pGo, Quest const* pQuest)
{
    // Summon the controller dragon at GO position (orientation is wrong - hardcoded)
    if (pQuest->GetQuestId() == QUEST_A_PAWN_ON_THE_ETERNAL_BOARD)
    {
        // Check if event is already in progress first
        if (Creature* pAnachronos = GetClosestCreatureWithEntry(pGo, NPC_ANACHRONOS_THE_ANCIENT, 180.0f))
            return true;

        if (Creature* pAnachronos = pPlayer->SummonCreature(NPC_ANACHRONOS_THE_ANCIENT, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), 3.75f, TEMPSUMMON_CORPSE_DESPAWN, 0))
        {
            // Send the player's guid in order to handle quest completion
            if (npc_anachronos_the_ancientAI* pAnachronosAI = dynamic_cast<npc_anachronos_the_ancientAI*>(pAnachronos->AI()))
            {
                pAnachronosAI->m_uiPlayerGUID = pPlayer->GetObjectGuid();
                pAnachronosAI->BeginScene();
            }

            return true;
        }
    }

    return false;
}

enum
{
    QUEST_BANG_A_GONG       = 8743,

    GLOBAL_TEXT_CHAMPION    = -1000007,

    STAGE_OPEN_GATES        = 0,
    STAGE_WAR               = 1,
    STAGE_RESET             = 2,

    SOUND_ROOTS_OPEN        = 7114,
    SOUND_DOOR_OPEN         = 7115,
    SOUND_RUNES_OPEN        = 7116
};

struct scarab_gongAI: public GameObjectAI
{
    scarab_gongAI(GameObject* go) : GameObjectAI(go)
    {
        eventTimer = 0;
        eventStep = 0;
        eventStage = STAGE_OPEN_GATES;
    }

    uint32 eventTimer;
    uint32 eventStep;
    uint32 eventStage;

    GameObject* go_aq_barrier;
    GameObject* go_aq_gate_runes;
    GameObject* go_aq_gate_roots;
    // Invisible AQ barrier
    GameObject* go_aq_ghost_gate;

    void UpdateAI(uint32 const uiDiff) override
    {
        if (eventTimer)
        {
            if (eventTimer <= uiDiff)
            {
                switch (eventStage)
                {
                    case STAGE_OPEN_GATES: return HandleOpeningStage();
                    case STAGE_WAR:         return HandleWarStage();
                    case STAGE_RESET:      return ResetAQGates();
                }

            }
            else eventTimer -= uiDiff;
        }

    }

    void NextStage(uint32 timeUntil = 100)
    {
        eventStage++;
        eventStep = 0;
        eventTimer = timeUntil;
    }

    void HandleOpeningStage()
    {
        switch (eventStep)
        {
            case 0:
                go_aq_gate_roots->ResetDoorOrButton();
                go_aq_gate_roots->UseDoorOrButton();
                me->PlayDirectSound(SOUND_ROOTS_OPEN);

                eventTimer = 5000;
                break;

            case 1:
                go_aq_gate_runes->ResetDoorOrButton();
                go_aq_gate_runes->UseDoorOrButton();
                me->PlayDirectSound(SOUND_RUNES_OPEN);

                eventTimer = 8000;
                break;
            case 2:
                go_aq_barrier->ResetDoorOrButton();
                go_aq_barrier->UseDoorOrButton();
                me->PlayDirectSound(SOUND_DOOR_OPEN);

                NextStage(10000);
                return;
        }

        eventStep++;
    }

    void HandleWarStage()
    {
        sObjectMgr.SetSavedVariable(VAR_WE_GONG_TIME, time(nullptr), true);
        // Trigger a game event update asap so we can start the next events
        sWorld.SetWorldUpdateTimer(WUPDATE_EVENTS, sWorld.GetWorldUpdateTimerInterval(WUPDATE_EVENTS) + 1);

        EventDone();
    }


    void BeginAQOpeningEvent(Player* player)
    {
        if (!player)
            return;

        go_aq_barrier    = GetClosestGameObjectWithEntry(me, GO_AQ_BARRIER, 150);
        go_aq_gate_runes = GetClosestGameObjectWithEntry(me, GO_AQ_GATE_RUNES, 150);
        go_aq_gate_roots = GetClosestGameObjectWithEntry(me, GO_AQ_GATE_ROOTS, 150);
        go_aq_ghost_gate = GetClosestGameObjectWithEntry(me, GO_AQ_GHOST_GATE, 150);

        if (!go_aq_barrier || !go_aq_gate_runes || !go_aq_gate_roots || !go_aq_ghost_gate)
            return;

        // Abort "Pawn on the Eternal Board" scene if currently active.
        if (Creature* pAnachronos = GetClosestCreatureWithEntry(me, NPC_ANACHRONOS_THE_ANCIENT, 180.0f))
        {
            if (npc_anachronos_the_ancientAI* pAnachronosAI = dynamic_cast<npc_anachronos_the_ancientAI*>(pAnachronos->AI()))
            {
                pAnachronosAI->AbortScene();
                eventTimer += 8000;
            }
        }

        // Should not be open
        if (go_aq_barrier->GetGoState() == GO_STATE_ACTIVE)
            return;

        // Announce Champion to the world
        sWorld.SendWorldText(GLOBAL_TEXT_CHAMPION, player->GetName());

        eventTimer += 1000;
        eventStage = STAGE_OPEN_GATES;
    }

    void EventDone()
    {
        NextStage(0);
        eventStage = STAGE_OPEN_GATES;
    }

    void ResetAQGates()
    {
        go_aq_ghost_gate->SetGoState(GO_STATE_READY);
        go_aq_barrier->SetGoState(GO_STATE_READY);
        go_aq_gate_runes->SetGoState(GO_STATE_READY);
        go_aq_gate_roots->ResetDoorOrButton();
        go_aq_gate_roots->SetGoState(GO_STATE_READY);

        EventDone();
    }
};

GameObjectAI* GetAIscarab_gong(GameObject *go)
{
    return new scarab_gongAI(go);
}

bool GOHello_scarab_gong(Player* player, GameObject* go)
{
    if (go->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
        return false;

    player->PrepareQuestMenu(go->GetObjectGuid());
    player->SendPreparedQuest(go->GetObjectGuid());

    return true;
}

bool QuestRewarded_scarab_gong(Player* player, GameObject* go, Quest const* quest)
{
    if (quest->GetQuestId() != QUEST_BANG_A_GONG)
        return false;

    uint32 crystalsAwarded = sObjectMgr.GetSavedVariable(VAR_WE_GONG_BANG_TIMES, 0);

    // Increment number of black crystals given
    sObjectMgr.SetSavedVariable(VAR_WE_GONG_BANG_TIMES, crystalsAwarded + 1, true);

    // Special case for first to ring the Gong
    if (0 == crystalsAwarded)
    {
        if (scarab_gongAI* gongAI = dynamic_cast<scarab_gongAI*>(go->AI()))
            gongAI->BeginAQOpeningEvent(player);
    }

    return true;
}



/*########################
 ## npc_Krug_SkullSplit ##
 ########################*/

#define GOSSIP_ITEM_KRUG_SKULLSPLIT_1 "Continue."
#define GOSSIP_ITEM_KRUG_SKULLSPLIT_2 "Very well, let's go!"

/* Hunterkiller */
#define HUNTERKILLER_SPAWN_POS_X -7765.0f
#define HUNTERKILLER_SPAWN_POS_Y 536.0f
#define HUNTERKILLER_SPAWN_POS_Z -43.0f

#define HUNTERKILLER_DEST_POS_X -7549.78f
#define HUNTERKILLER_DEST_POS_Y 711.901f
#define HUNTERKILLER_DEST_POS_Z -16.4527f

struct HunterMove
{
    float X;
    float Y;
    float Z;
    float O;
};

#define HUNTERKILLER_WAYPOINTS_NUMBER 16
static HunterMove HunterKillerWaypoint[HUNTERKILLER_WAYPOINTS_NUMBER] =
{
    { -7769.14f, 549.365f, -44.1111f, 0.868761f},
    { -7762.88f, 564.709f, -45.9125f, 1.17899f},
    { -7749.28f, 589.14f, -47.1617f, 1.05334f},
    { -7748.5f, 622.853f, -45.2946f, 0.982653f},
    { -7730.37f, 643.343f, -46.7866f, 0.456442f},
    { -7694.24f, 660.321f, -51.0377f, 0.441519f},
    { -7674.25f, 671.264f, -50.4592f, 0.0841609f},
    { -7655.01f, 671.601f, -47.9161f, 1.13424f},
    { -7634.07f, 672.497f, -47.8617f, 0.0857299f},
    { -7603.06f, 667.321f, -48.6429f, 6.0249f},
    { -7571.59f, 665.263f, -48.3899f, 0.0480175f},
    { -7562.58f, 687.328f, -49.9864f, 1.36749f},
    { -7559.18f, 689.958f, -40.8654f, 1.44927f},
    { -7555.3f, 692.953f, -30.7562f, 0.671711f},
    { -7548.27f, 697.037f, -25.6632f, 1.09582f},
    { -7547.07f, 706.949f, -17.7001f, 4.68419f},
};

/* Shai */
#define SHAI_SPAWN_POS_X -7556.600098f
#define SHAI_SPAWN_POS_Y 749.007019f
#define SHAI_SPAWN_POS_Z -17.578800f

#define SHAI_DEST_POS_X -7553.46f
#define SHAI_DEST_POS_Y 720.924f
#define SHAI_DEST_POS_Z -16.715f

/* Merok */
#define MEROK_SPAWN_POS_X -7537.149902f
#define MEROK_SPAWN_POS_Y 731.184021f
#define MEROK_SPAWN_POS_Z -16.418100f

#define MEROK_DEST_POS_X -7542.45f
#define MEROK_DEST_POS_Y 720.155f
#define MEROK_DEST_POS_Z -15.6801f

enum
{
    QUEST_FIELD_DUTY = 8731,
    QUEST_FIELD_DUTY_PAPERS = 8732,

    NPC_HUNTERKILLER = 15620,
    NPC_KRUG_SKULLSPLIT = 15612,
    NPC_MEROK_LONGSTRIDE = 15613,
    NPC_SHADOW_PRIESTESS_SHAI = 15615,
    NPC_ORGRIMMAR_LEGION_GRUNT = 15616,

    /* Emotes */
    SAY_LINE_1 = -1780131, //Spawn
    SAY_LINE_2 = -1780132,
    SAY_LINE_3 = -1780133,
    SAY_LINE_4 = -1780134,
    SAY_LINE_5 = -1780135,
    SAY_LINE_6 = -1780136,
    SAY_LINE_7 = -1780137,
    SAY_LINE_8 = -1780138,
    SAY_LINE_9 = -1780139,

    /* Hunterkiller */
    SPELL_THUNDERCLAP = 15588,
    SPELL_CHARGE = 25821,
    SPELL_CLEAVE = 11427,
    SPELL_FEAR = 25815,

    /* Merok */
    SPELL_HEALING_WAVE = 15982,

    /* Shai */
    SPELL_FLASH_HEAL = 17138
};

struct mob_HiveRegal_HunterKillerAI : public ScriptedAI
{
    mob_HiveRegal_HunterKillerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_bReachedCamp = false;
        m_uiMoveTimer = 0;
        m_uiWaypoint = 0;
        pCreature->SetFactionTemplateId(35);
    }

    uint32 m_uiThunderClapTimer;
    uint32 m_uiChargeTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiFearTimer;
    uint32 m_uiMoveTimer;
    uint32 m_uiWaypoint;

    bool m_bReachedCamp;

    void Reset() override
    {
        m_uiThunderClapTimer = 17000;
        m_uiChargeTimer = urand(15000, 20000);
        m_uiCleaveTimer = urand(4000, 8000);
        m_uiFearTimer = urand(5000, 10000);
        // m_creature->MonsterTextEmote("Reset", nullptr); // pour debug
    }

    Unit* GetVictimInRangePlayerOnly(float min, float max)
    {
        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
        for (const auto itr : tList)
        {
            if (ObjectGuid uiTargetGuid = itr->getUnitGuid())
            {
                if (Unit* pTarget = m_creature->GetMap()->GetUnit(uiTargetGuid))
                {
                    if (pTarget->GetTypeId() == TYPEID_PLAYER && m_creature->IsInRange(pTarget, min, max))
                        return pTarget;
                }
            }
        }
        return nullptr;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_bReachedCamp)
        {
            if (m_uiMoveTimer < uiDiff)
            {
                if (m_uiWaypoint == HUNTERKILLER_WAYPOINTS_NUMBER)
                {
                    m_creature->SetFactionTemplateId(14);
                    if (Creature* krug = GetClosestCreatureWithEntry(m_creature, NPC_KRUG_SKULLSPLIT, 50.0f))
                        AttackStart(krug);

                    // Update home position to the camp in the case that the killer evades for whatever reason
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation());
                    m_bReachedCamp = true;
                }
                else
                {
                    float X = 0.0f;
                    float Y = 0.0f;
                    m_creature->GetMotionMaster()->MovePoint(0, HunterKillerWaypoint[m_uiWaypoint].X, HunterKillerWaypoint[m_uiWaypoint].Y, HunterKillerWaypoint[m_uiWaypoint].Z);
                    X = m_creature->GetPositionX() - HunterKillerWaypoint[m_uiWaypoint].X;
                    Y = m_creature->GetPositionY() - HunterKillerWaypoint[m_uiWaypoint].Y;
                    m_uiMoveTimer = sqrt((X * X) + (Y * Y)) / (m_creature->GetSpeed(MOVE_WALK) * 0.003f);
                }
                m_uiWaypoint++;
            }
            else
                m_uiMoveTimer -= uiDiff;

            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        // THUNDERCLAP
        if (m_uiThunderClapTimer <= uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THUNDERCLAP);
            m_uiThunderClapTimer = 20000;
        }
        else
            m_uiThunderClapTimer -= uiDiff;

        // CHARGE
        if (m_uiChargeTimer <= uiDiff)
        {
            if (Unit* pTarget = GetVictimInRangePlayerOnly(5.0f, 30.0f))
            {
                DoCastSpellIfCan(pTarget, SPELL_CHARGE);
                m_uiChargeTimer = urand(30000, 35000);
            }
        }
        else
            m_uiChargeTimer -= uiDiff;

        // CLEAVE
        if (m_uiCleaveTimer <= uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE);
            m_uiCleaveTimer = urand(5000, 12000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // FEAR
        if (m_uiFearTimer <= uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FEAR);
            m_uiFearTimer = urand(58000, 63000);
        }
        else
            m_uiFearTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

/* TODO: Fixer les lanceurs de hache au sol */

CreatureAI* GetAI_mob_HiveRegal_HunterKiller(Creature* pCreature)
{
    return new mob_HiveRegal_HunterKillerAI(pCreature);
}


typedef enum
{
    EVENT_NOT_STARTED,
    EVENT_STARTED,
    EVENT_COMPLETE
} FieldDutyPaperEventStatus;

/**
 * Originally written by Ivina & Malkins < Nostalrius >
 * Various improvements by additional authors
 */

struct npc_Krug_SkullSplitAI : public ScriptedAI
{
    npc_Krug_SkullSplitAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        ResetEvent();
    }

    FieldDutyPaperEventStatus eEventStatus;
    uint32 m_uiEventResetTimer;
    uint32 m_uiSpeechNum;
    uint32 m_uiGruntSpeachTimer;
    uint32 m_uiMoveTimer;
    uint32 InitTimer;
    uint32 m_uiSpeechTimer;
    bool m_bAlreadyMoved;
    bool m_bIsDoingSpeach;
    bool m_bGruntSpeech;
    ObjectGuid m_uiShaiGUID;
    ObjectGuid m_uiMerokGUID;
    ObjectGuid m_uiHunterKillerGUID;

    void Reset() override
    {
    }

    FieldDutyPaperEventStatus GetEventStatus()
    {
        return eEventStatus;
    }

    void ResetEvent()
    {
        eEventStatus = EVENT_NOT_STARTED;
        if (Creature* pHunterKiller = m_creature->GetMap()->GetCreature(m_uiHunterKillerGUID))
        {
            pHunterKiller->ForcedDespawn();
            pHunterKiller->AddObjectToRemoveList();
        }
        m_uiSpeechTimer = 0;
        m_uiSpeechNum = 0;
        m_uiHunterKillerGUID.Clear();
        m_uiEventResetTimer = 120000;
        m_bAlreadyMoved = true;
        m_bIsDoingSpeach = false;
        m_bGruntSpeech = false;
        m_uiMoveTimer = 10000;
        ResetOtherNPCsPosition();
        InitTimer = 2000;

        //m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }

    void StartEvent()
    {
        if (eEventStatus == EVENT_NOT_STARTED)
        {
            DoScriptText(SAY_LINE_1, m_creature);

            m_uiGruntSpeachTimer = 3000;
            m_uiSpeechTimer = 10000;
            m_uiSpeechNum = 0;
            m_bIsDoingSpeach = true;
            m_bGruntSpeech = false;

            Creature* pHunterKiller = m_creature->SummonCreature(NPC_HUNTERKILLER,
                                      HUNTERKILLER_SPAWN_POS_X, HUNTERKILLER_SPAWN_POS_Y, HUNTERKILLER_SPAWN_POS_Z, 0.8f,
                                      TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 450000, true);
            if (pHunterKiller)
            {
                pHunterKiller->SetRespawnDelay(460);
                eEventStatus = EVENT_STARTED;
                m_bAlreadyMoved = false;
                m_uiHunterKillerGUID = pHunterKiller->GetObjectGuid();
                InitOtherNPCsGuids();
                pHunterKiller->SetFactionTemplateId(35);
            }

            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }
    }

    void CompleteEvent()
    {
        m_uiEventResetTimer = 1800000;
        eEventStatus = EVENT_COMPLETE;
        m_bIsDoingSpeach = false;
        m_bGruntSpeech = true;

        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }

    void InitOtherNPCsGuids()
    {
        m_uiMerokGUID = 0;
        m_uiShaiGUID = 0;

        if (Creature* pMerok = m_creature->FindNearestCreature(15613, 100.0f, true))
            m_uiMerokGUID = pMerok->GetObjectGuid();

        if (Creature* pShai = m_creature->FindNearestCreature(15615, 100.0f, true))
            m_uiShaiGUID = pShai->GetObjectGuid();
    }

    void ResetOtherNPCsPosition()
    {
        if (Creature* pMerok = m_creature->GetMap()->GetCreature(m_uiMerokGUID))
            pMerok->GetMotionMaster()->MovePoint(0, MEROK_SPAWN_POS_X, MEROK_SPAWN_POS_Y, MEROK_SPAWN_POS_Z);

        if (Creature* pShai = m_creature->GetMap()->GetCreature(m_uiShaiGUID))
            pShai->GetMotionMaster()->MovePoint(0, SHAI_SPAWN_POS_X, SHAI_SPAWN_POS_Y, SHAI_SPAWN_POS_Z);
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetObjectGuid() == m_uiHunterKillerGUID)
        {
            CompleteEvent();
        }
    }

    void SummonedCreatureDespawn(Creature* pSummoned) override
    {
        if (pSummoned->GetObjectGuid() == m_uiHunterKillerGUID && eEventStatus != EVENT_COMPLETE)
        {
            ResetEvent();
        }
    }

    void JustDied(Unit* pKiller) override
    {
        ResetEvent();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /**
         * Note: The blizzlike behaviour here is probably to require the Hunter-Killer
         * to be killed much more often than our current timers. It'd be pretty aids
         * killing it every run though or requiring many players to wait each attempt.
         */
        if (eEventStatus == EVENT_COMPLETE)
        {
            if (m_uiEventResetTimer <= uiDiff)
            {
                ResetEvent();
            }
            else
                m_uiEventResetTimer -= uiDiff;
        }

        /* Speech */
        if (m_bIsDoingSpeach)
        {
            if (m_uiSpeechTimer < uiDiff)
            {
                switch (m_uiSpeechNum)
                {
                    case 0:
                        // 8 seconds till next line
                        DoScriptText(SAY_LINE_2, m_creature);
                        m_uiSpeechTimer = 10000;
                        ++m_uiSpeechNum;
                        break;
                    case 1:
                        // 8 seconds till next line
                        DoScriptText(SAY_LINE_3, m_creature);
                        m_uiSpeechTimer = 10000;
                        ++m_uiSpeechNum;
                        break;
                    case 2:
                        // 8 seconds till next line
                        DoScriptText(SAY_LINE_4, m_creature);
                        m_uiSpeechTimer = 10000;
                        ++m_uiSpeechNum;
                        break;
                    case 3:
                        // 6,5 seconds till next line
                        DoScriptText(SAY_LINE_5, m_creature);
                        m_uiSpeechTimer = 6500;
                        ++m_uiSpeechNum;
                        break;
                    case 4:
                        // 2 seconds till next line
                        DoScriptText(SAY_LINE_6, m_creature);
                        m_uiSpeechTimer = 1000;
                        ++m_uiSpeechNum;
                        break;
                    case 5:
                        if (Creature* pMerok = m_creature->GetMap()->GetCreature(m_uiMerokGUID))
                            pMerok->GetMotionMaster()->MovePoint(0, MEROK_DEST_POS_X, MEROK_DEST_POS_Y, MEROK_DEST_POS_Z);

                        if (Creature* pShai = m_creature->GetMap()->GetCreature(m_uiShaiGUID))
                            pShai->GetMotionMaster()->MovePoint(0, SHAI_DEST_POS_X, SHAI_DEST_POS_Y, SHAI_DEST_POS_Z);
                        // 7 seconds till next line
                        DoScriptText(SAY_LINE_7, m_creature);
                        m_uiSpeechTimer = 6000;
                        ++m_uiSpeechNum;
                        break;
                    case 6:
                        DoScriptText(SAY_LINE_8, m_creature);
                        ++m_uiSpeechNum;
                        break;
                }
            }
            else
                m_uiSpeechTimer -= uiDiff;
        }

        /* Grunt */
        if (m_bGruntSpeech)
        {
            if (m_uiGruntSpeachTimer < uiDiff)
            {
                std::list<Creature*> gruntList;
                m_creature->GetCreatureListWithEntryInGrid(gruntList, NPC_ORGRIMMAR_LEGION_GRUNT, 100.0f);

                if (!gruntList.empty())
                {
                    for (const auto& itr : gruntList)
                    {
                        if (itr->IsAlive())
                            DoScriptText(SAY_LINE_9, itr);
                    }
                }
                m_bGruntSpeech = false;
            }
            else
                m_uiGruntSpeachTimer -= uiDiff;
        }

        /* Clean unwanted states */
        if (Creature* pHunterKiller = m_creature->GetMap()->GetCreature(m_uiHunterKillerGUID))
        {
            if (eEventStatus == EVENT_NOT_STARTED)
            {
                pHunterKiller->ForcedDespawn();
                pHunterKiller->AddObjectToRemoveList();
            }
        }
        else
        {
            if (eEventStatus == EVENT_STARTED)
            {
                ResetEvent();
            }
        }

        /* Start of combat script */
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_npc_Krug_SkullSplit(Creature* pCreature)
{
    return new npc_Krug_SkullSplitAI(pCreature);
}


bool GossipHello_npc_Krug_SkullSplit(Player* pPlayer, Creature* pCreature)
{
    /* TO DO : la tous les SEND_GOSSIP_MENU renvoient le menu par defaut,
       or il faut mettre le gossip adapte a chaque cas */
    FieldDutyPaperEventStatus eEventStatus = EVENT_NOT_STARTED;

    if (npc_Krug_SkullSplitAI* pKrugSkullSplitAI = dynamic_cast<npc_Krug_SkullSplitAI*>(pCreature->AI()))
        eEventStatus = pKrugSkullSplitAI->GetEventStatus();

    if ((pPlayer->GetQuestStatus(QUEST_FIELD_DUTY) == QUEST_STATUS_INCOMPLETE)
            && (eEventStatus == EVENT_NOT_STARTED))
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KRUG_SKULLSPLIT_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }
    else if ((pPlayer->GetQuestStatus(QUEST_FIELD_DUTY) == QUEST_STATUS_INCOMPLETE)
             && (eEventStatus == EVENT_COMPLETE))
    {
        if (pCreature->IsQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}


bool GossipSelect_npc_Krug_SkullSplit(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KRUG_SKULLSPLIT_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }

    if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
    {
        if (npc_Krug_SkullSplitAI* pKrugSkullSplitAI = dynamic_cast<npc_Krug_SkullSplitAI*>(pCreature->AI()))
            pKrugSkullSplitAI->StartEvent();
        pPlayer->CLOSE_GOSSIP_MENU();
    }
    return true;
}

struct npc_MerokAI : public ScriptedAI
{
    npc_MerokAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiHealingWave;

    void Reset() override
    {
        m_uiHealingWave = 12000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        // HEALING WAVE
        if (m_uiHealingWave <= uiDiff)
        {
            Unit* pUnit = m_creature->FindLowestHpFriendlyUnit(60.0f, 1);
            if (!pUnit)
                return;

            if (DoCastSpellIfCan(pUnit, SPELL_HEALING_WAVE) == CAST_OK)
                m_uiHealingWave = 12000;
        }
        else
            m_uiHealingWave -= uiDiff;

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_npc_Merok(Creature* pCreature)
{
    return new npc_MerokAI(pCreature);
}


struct npc_ShaiAI : public ScriptedAI
{
    npc_ShaiAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFlashHeal;

    void Reset() override
    {
        m_uiFlashHeal = 12000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        // FLASH HEAL
        if (m_uiFlashHeal <= uiDiff)
        {
            Unit* pUnit = m_creature->FindLowestHpFriendlyUnit(60.0f, 1);
            if (!pUnit)
                return;

            if (DoCastSpellIfCan(pUnit, SPELL_FLASH_HEAL) == CAST_OK)
                m_uiFlashHeal = 12000;
        }
        else
            m_uiFlashHeal -= uiDiff;

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_npc_Shai(Creature* pCreature)
{
    return new npc_ShaiAI(pCreature);
}

/** EVENT NOSTALRIUS VAM ,SAND PRINCE */

enum
{
    SPELL_CHARGE_VAM     = 26561,
    SPELL_IMPALE         = 28783,
    SPELL_ENRAGE         = 34624,
};

struct boss_vamAI : public ScriptedAI
{
    boss_vamAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Charge_Timer;
    uint32 KnockBack_Timer;
    uint32 Enrage_Timer;

    bool Enraged;

    void Reset() override
    {
        Charge_Timer = urand(15000, 27000);
        KnockBack_Timer = urand(8000, 20000);
        Enrage_Timer = 240000;

        Enraged = false;
    }

    void Aggro(Unit *who) override
    {
    }

    void JustDied(Unit* Killer) override
    {
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Charge_Timer
        if (Charge_Timer < diff)
        {
            Charge_Timer = 10000;
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(target, SPELL_CHARGE_VAM) == CAST_OK)
                    Charge_Timer = urand(8000, 16000);
            }
        }
        else Charge_Timer -= diff;

        //KnockBack_Timer
        if (KnockBack_Timer < diff)
        {
            KnockBack_Timer = 15000;
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(target, SPELL_IMPALE) == CAST_OK)
                    KnockBack_Timer = urand(15000, 25000);
            }
        }
        else KnockBack_Timer -= diff;

        //Enrage_Timer
        if (!Enraged && Enrage_Timer < diff)
            Enraged = true;
        else if (Enraged)
            DoCastSpellIfCan(m_creature, SPELL_ENRAGE, CF_AURA_NOT_PRESENT);
        else
            Enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_vamAI(Creature* pCreature)
{
    return new boss_vamAI(pCreature);
}


void AddSC_silithus()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "go_pierre_vents";
    pNewScript->pGOGossipSelect =  &GossipSelect_go_pierre_vents;
    pNewScript->GOGetAI = &GetAIgo_pierre_vents;
    pNewScript->RegisterSelf();

    /*########################
    ##      Nostalrius      ##
    ########################*/

    pNewScript = new Script;
    pNewScript->Name = "npc_prince_thunderaan";
    pNewScript->GetAI = &GetAI_npc_prince_thunderaan;
    pNewScript->RegisterSelf();

    // AQ WAR
    pNewScript = new Script;
    pNewScript->Name = "npc_colossus";
    pNewScript->GetAI = &GetAI_npc_colossus;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_Geologist_Larksbane";
    pNewScript->GetAI = &GetAI_npc_Geologist_Larksbane;
    pNewScript->pQuestRewardedNPC = &QuestComplete_npc_Geologist_Larksbane;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_Emissary_Romankhan";
    pNewScript->GetAI = &GetAI_npc_Emissary_Romankhan;
    pNewScript->RegisterSelf();


    // FIELD PAPERS - Ivina & Malkins
    pNewScript = new Script;
    pNewScript->Name = "npc_Krug_SkullSplit";
    pNewScript->GetAI = &GetAI_npc_Krug_SkullSplit;
    pNewScript->pGossipHello = &GossipHello_npc_Krug_SkullSplit;
    pNewScript->pGossipSelect = &GossipSelect_npc_Krug_SkullSplit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_HiveRegal_HunterKiller";
    pNewScript->GetAI = &GetAI_mob_HiveRegal_HunterKiller;
    pNewScript->RegisterSelf();
    /*
    pNewScript = new Script;
    pNewScript->Name = "npc_Merok";
    pNewScript->GetAI = &GetAI_npc_Merok;
    pNewScript->RegisterSelf();
    */
    pNewScript = new Script;
    pNewScript->Name = "npc_Shai";
    pNewScript->GetAI = &GetAI_npc_Shai;
    pNewScript->RegisterSelf();

    /** Event Nostalrius */
    pNewScript = new Script;
    pNewScript->Name = "npc_boss_vam";
    pNewScript->GetAI = &GetAI_boss_vamAI;
    pNewScript->RegisterSelf();

    // End Nostalrius

    pNewScript = new Script;
    pNewScript->Name = "npc_anachronos_the_ancient";
    pNewScript->GetAI = &GetAI_npc_anachronos_the_ancient;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_crystalline_tear";
    pNewScript->pGOQuestAccept = &QuestAcceptGO_crystalline_tear;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_solenor";
    pNewScript->GetAI = &GetAI_npc_solenor;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_creeping_doom";
    pNewScript->GetAI = &GetAI_npc_creeping_doom;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_scarab_gong";
    pNewScript->GOGetAI = &GetAIscarab_gong;
    pNewScript->pQuestRewardedGO = &QuestRewarded_scarab_gong;
    pNewScript->pGOGossipHello = &GOHello_scarab_gong;
    pNewScript->RegisterSelf();
}
