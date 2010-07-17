/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Npcs_Special
SD%Complete: 100
SDComment: To be used for special NPCs that are located globally.
SDCategory: NPCs
EndScriptData
*/

/* ContentData
npc_air_force_bots       80%    support for misc (invisible) guard bots in areas where player allowed to fly. Summon guards after a preset time if tagged by spell
npc_lunaclaw_spirit      80%    support for quests 6001/6002 (Body and Heart)
npc_chicken_cluck       100%    support for quest 3861 (Cluck!)
npc_dancing_flames      100%    midsummer event NPC
npc_guardian            100%    guardianAI used to prevent players from accessing off-limits areas. Not in use by SD2
npc_garments_of_quests   80%    NPC's related to all Garments of-quests 5621, 5624, 5625, 5648, 565
npc_injured_patient     100%    patients for triage-quests (6622 and 6624)
npc_doctor              100%    Gustaf Vanhowzen and Gregory Victor, quest 6622 and 6624 (Triage)
npc_kingdom_of_dalaran_quests   Misc NPC's gossip option related to quests 12791, 12794 and 12796
npc_mount_vendor        100%    Regular mount vendors all over the world. Display gossip if player doesn't meet the requirements to buy
npc_rogue_trainer        80%    Scripted trainers, so they are able to offer item 17126 for class quest 6681
npc_sayge               100%    Darkmoon event fortune teller, buff player based on answers given
npc_snake_trap_serpents  80%    AI for snakes that summoned by Snake Trap
npc_shadowfiend         100%   restore 5% of owner's mana when shadowfiend die from damage
npc_locksmith            75%    list of keys needs to be confirmed
EndContentData */

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "World.h"

/*########
# npc_air_force_bots
#########*/

enum SpawnType
{
    SPAWNTYPE_TRIPWIRE_ROOFTOP,                             // no warning, summon Creature at smaller range
    SPAWNTYPE_ALARMBOT,                                     // cast guards mark and summon npc - if player shows up with that buff duration < 5 seconds attack
};

struct SpawnAssociation
{
    uint32 m_uiThisCreatureEntry;
    uint32 m_uiSpawnedCreatureEntry;
    SpawnType m_SpawnType;
};

enum eEnums
{
    SPELL_GUARDS_MARK               = 38067,
    AURA_DURATION_TIME_LEFT         = 5000
};

const float RANGE_TRIPWIRE          = 15.0f;
const float RANGE_GUARDS_MARK       = 50.0f;

SpawnAssociation m_aSpawnAssociations[] =
{
    {2614,  15241, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Alliance)
    {2615,  15242, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Horde)
    {21974, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Area 52)
    {21993, 15242, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Horde - Bat Rider)
    {21996, 15241, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Alliance - Gryphon)
    {21997, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Goblin - Area 52 - Zeppelin)
    {21999, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Alliance)
    {22001, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Horde)
    {22002, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Horde)
    {22003, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Alliance)
    {22063, 21976, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Goblin - Area 52)
    {22065, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Ethereal - Stormspire)
    {22066, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Scryer - Dragonhawk)
    {22068, 22064, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
    {22069, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Stormspire)
    {22070, 22067, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Scryer)
    {22071, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Scryer)
    {22078, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Aldor)
    {22079, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Aldor - Gryphon)
    {22080, 22077, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Aldor)
    {22086, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Sporeggar)
    {22087, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Sporeggar - Spore Bat)
    {22088, 22085, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Sporeggar)
    {22090, 22089, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Toshley's Station - Flying Machine)
    {22124, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Cenarion)
    {22125, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Cenarion - Stormcrow)
    {22126, 22122, SPAWNTYPE_ALARMBOT}                      //Air Force Trip Wire - Rooftop (Cenarion Expedition)
};

struct npc_air_force_botsAI : public ScriptedAI
{
    npc_air_force_botsAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pSpawnAssoc = NULL;
        m_uiSpawnedGUID = 0;

        // find the correct spawnhandling
        static uint32 uiEntryCount = sizeof(m_aSpawnAssociations)/sizeof(SpawnAssociation);

        for (uint8 i=0; i<uiEntryCount; ++i)
        {
            if (m_aSpawnAssociations[i].m_uiThisCreatureEntry == pCreature->GetEntry())
            {
                m_pSpawnAssoc = &m_aSpawnAssociations[i];
                break;
            }
        }

        if (!m_pSpawnAssoc)
            error_db_log("TCSR: Creature template entry %u has ScriptName npc_air_force_bots, but it's not handled by that script", pCreature->GetEntry());
        else
        {
            CreatureInfo const* spawnedTemplate = GetCreatureTemplateStore(m_pSpawnAssoc->m_uiSpawnedCreatureEntry);

            if (!spawnedTemplate)
            {
                m_pSpawnAssoc = NULL;
                error_db_log("TCSR: Creature template entry %u does not exist in DB, which is required by npc_air_force_bots", m_pSpawnAssoc->m_uiSpawnedCreatureEntry);
                return;
            }
        }
    }

    SpawnAssociation* m_pSpawnAssoc;
    uint64 m_uiSpawnedGUID;

    void Reset() {}

    Creature* SummonGuard()
    {
        Creature* pSummoned = me->SummonCreature(m_pSpawnAssoc->m_uiSpawnedCreatureEntry, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

        if (pSummoned)
            m_uiSpawnedGUID = pSummoned->GetGUID();
        else
        {
            error_db_log("TCSR: npc_air_force_bots: wasn't able to spawn Creature %u", m_pSpawnAssoc->m_uiSpawnedCreatureEntry);
            m_pSpawnAssoc = NULL;
        }

        return pSummoned;
    }

    Creature* GetSummonedGuard()
    {
        Creature* pCreature = Unit::GetCreature(*me, m_uiSpawnedGUID);

        if (pCreature && pCreature->isAlive())
            return pCreature;

        return NULL;
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (!m_pSpawnAssoc)
            return;

        if (pWho->isTargetableForAttack() && me->IsHostileTo(pWho))
        {
            Player* pPlayerTarget = pWho->GetTypeId() == TYPEID_PLAYER ? CAST_PLR(pWho) : NULL;

            // airforce guards only spawn for players
            if (!pPlayerTarget)
                return;

            Creature* pLastSpawnedGuard = m_uiSpawnedGUID == 0 ? NULL : GetSummonedGuard();

            // prevent calling Unit::GetUnit at next MoveInLineOfSight call - speedup
            if (!pLastSpawnedGuard)
                m_uiSpawnedGUID = 0;

            switch(m_pSpawnAssoc->m_SpawnType)
            {
                case SPAWNTYPE_ALARMBOT:
                {
                    if (!pWho->IsWithinDistInMap(me, RANGE_GUARDS_MARK))
                        return;

                    Aura* pMarkAura = pWho->GetAura(SPELL_GUARDS_MARK);
                    if (pMarkAura)
                    {
                        // the target wasn't able to move out of our range within 25 seconds
                        if (!pLastSpawnedGuard)
                        {
                            pLastSpawnedGuard = SummonGuard();

                            if (!pLastSpawnedGuard)
                                return;
                        }

                        if (pMarkAura->GetDuration() < AURA_DURATION_TIME_LEFT)
                        {
                            if (!pLastSpawnedGuard->getVictim())
                                pLastSpawnedGuard->AI()->AttackStart(pWho);
                        }
                    }
                    else
                    {
                        if (!pLastSpawnedGuard)
                            pLastSpawnedGuard = SummonGuard();

                        if (!pLastSpawnedGuard)
                            return;

                        pLastSpawnedGuard->CastSpell(pWho, SPELL_GUARDS_MARK, true);
                    }
                    break;
                }
                case SPAWNTYPE_TRIPWIRE_ROOFTOP:
                {
                    if (!pWho->IsWithinDistInMap(me, RANGE_TRIPWIRE))
                        return;

                    if (!pLastSpawnedGuard)
                        pLastSpawnedGuard = SummonGuard();

                    if (!pLastSpawnedGuard)
                        return;

                    // ROOFTOP only triggers if the player is on the ground
                    if (!pPlayerTarget->IsFlying())
                    {
                        if (!pLastSpawnedGuard->getVictim())
                            pLastSpawnedGuard->AI()->AttackStart(pWho);
                    }
                    break;
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_air_force_bots(Creature* pCreature)
{
    return new npc_air_force_botsAI(pCreature);
}

/*######
## npc_lunaclaw_spirit
######*/

enum
{
    QUEST_BODY_HEART_A      = 6001,
    QUEST_BODY_HEART_H      = 6002,

    TEXT_ID_DEFAULT         = 4714,
    TEXT_ID_PROGRESS        = 4715
};

#define GOSSIP_ITEM_GRANT   "You have thought well, spirit. I ask you to grant me the strength of your body and the strength of your heart."

bool GossipHello_npc_lunaclaw_spirit(Player *pPlayer, Creature *pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_BODY_HEART_A) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_BODY_HEART_H) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GRANT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(TEXT_ID_DEFAULT, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_lunaclaw_spirit(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->SEND_GOSSIP_MENU(TEXT_ID_PROGRESS, pCreature->GetGUID());
        pPlayer->AreaExploredOrEventHappens(pPlayer->GetTeam() == ALLIANCE ? QUEST_BODY_HEART_A : QUEST_BODY_HEART_H);
    }
    return true;
}

/*########
# npc_chicken_cluck
#########*/

#define EMOTE_HELLO         -1070004
#define EMOTE_CLUCK_TEXT    -1070006

#define QUEST_CLUCK         3861
#define FACTION_FRIENDLY    35
#define FACTION_CHICKEN     31

struct npc_chicken_cluckAI : public ScriptedAI
{
    npc_chicken_cluckAI(Creature *c) : ScriptedAI(c) {}

    uint32 ResetFlagTimer;

    void Reset()
    {
        ResetFlagTimer = 120000;
        me->setFaction(FACTION_CHICKEN);
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        // Reset flags after a certain time has passed so that the next player has to start the 'event' again
        if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
        {
            if (ResetFlagTimer <= diff)
            {
                EnterEvadeMode();
                return;
            } else ResetFlagTimer -= diff;
        }

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        switch(emote)
        {
            case TEXTEMOTE_CHICKEN:
                if (pPlayer->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_NONE && rand()%30 == 1)
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    me->setFaction(FACTION_FRIENDLY);
                    DoScriptText(EMOTE_HELLO, me);
                }
                break;
            case TEXTEMOTE_CHEER:
                if (pPlayer->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_COMPLETE)
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    me->setFaction(FACTION_FRIENDLY);
                    DoScriptText(EMOTE_CLUCK_TEXT, me);
                }
                break;
        }
    }
};

CreatureAI* GetAI_npc_chicken_cluck(Creature* pCreature)
{
    return new npc_chicken_cluckAI(pCreature);
}

bool QuestAccept_npc_chicken_cluck(Player* /*pPlayer*/, Creature* pCreature, const Quest *_Quest)
{
    if (_Quest->GetQuestId() == QUEST_CLUCK)
        CAST_AI(npc_chicken_cluckAI, pCreature->AI())->Reset();

    return true;
}

bool QuestComplete_npc_chicken_cluck(Player* /*pPlayer*/, Creature* pCreature, const Quest *_Quest)
{
    if (_Quest->GetQuestId() == QUEST_CLUCK)
        CAST_AI(npc_chicken_cluckAI, pCreature->AI())->Reset();

    return true;
}

/*######
## npc_dancing_flames
######*/

#define SPELL_BRAZIER       45423
#define SPELL_SEDUCTION     47057
#define SPELL_FIERY_AURA    45427

struct npc_dancing_flamesAI : public ScriptedAI
{
    npc_dancing_flamesAI(Creature *c) : ScriptedAI(c) {}

    bool active;
    uint32 can_iteract;

    void Reset()
    {
        active = true;
        can_iteract = 3500;
        DoCast(me, SPELL_BRAZIER, true);
        DoCast(me, SPELL_FIERY_AURA, false);
        float x, y, z;
        me->GetPosition(x,y,z);
        me->Relocate(x,y,z + 0.94f);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
        WorldPacket data;                       //send update position to client
        me->BuildHeartBeatMsg(&data);
        me->SendMessageToSet(&data,true);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!active)
        {
            if (can_iteract <= diff){
                active = true;
                can_iteract = 3500;
                me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
            } else can_iteract -= diff;
        }
    }

    void EnterCombat(Unit* /*who*/){}

    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        if (me->IsWithinLOS(pPlayer->GetPositionX(),pPlayer->GetPositionY(),pPlayer->GetPositionZ()) && me->IsWithinDistInMap(pPlayer,30.0f))
        {
            me->SetInFront(pPlayer);
            active = false;

            WorldPacket data;
            me->BuildHeartBeatMsg(&data);
            me->SendMessageToSet(&data,true);
            switch(emote)
            {
                case TEXTEMOTE_KISS:    me->HandleEmoteCommand(EMOTE_ONESHOT_SHY); break;
                case TEXTEMOTE_WAVE:    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE); break;
                case TEXTEMOTE_BOW:     me->HandleEmoteCommand(EMOTE_ONESHOT_BOW); break;
                case TEXTEMOTE_JOKE:    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH); break;
                case TEXTEMOTE_DANCE:
                {
                    if (!pPlayer->HasAura(SPELL_SEDUCTION))
                        DoCast(pPlayer, SPELL_SEDUCTION, true);
                }
                break;
            }
        }
    }
};

CreatureAI* GetAI_npc_dancing_flames(Creature* pCreature)
{
    return new npc_dancing_flamesAI(pCreature);
}

/*######
## Triage quest
######*/

//signed for 9623
#define SAY_DOC1    -1000201
#define SAY_DOC2    -1000202
#define SAY_DOC3    -1000203

#define DOCTOR_ALLIANCE     12939
#define DOCTOR_HORDE        12920
#define ALLIANCE_COORDS     7
#define HORDE_COORDS        6

struct Location
{
    float x, y, z, o;
};

static Location AllianceCoords[]=
{
    {-3757.38, -4533.05, 14.16, 3.62},                      // Top-far-right bunk as seen from entrance
    {-3754.36, -4539.13, 14.16, 5.13},                      // Top-far-left bunk
    {-3749.54, -4540.25, 14.28, 3.34},                      // Far-right bunk
    {-3742.10, -4536.85, 14.28, 3.64},                      // Right bunk near entrance
    {-3755.89, -4529.07, 14.05, 0.57},                      // Far-left bunk
    {-3749.51, -4527.08, 14.07, 5.26},                      // Mid-left bunk
    {-3746.37, -4525.35, 14.16, 5.22},                      // Left bunk near entrance
};

//alliance run to where
#define A_RUNTOX -3742.96
#define A_RUNTOY -4531.52
#define A_RUNTOZ 11.91

static Location HordeCoords[]=
{
    {-1013.75, -3492.59, 62.62, 4.34},                      // Left, Behind
    {-1017.72, -3490.92, 62.62, 4.34},                      // Right, Behind
    {-1015.77, -3497.15, 62.82, 4.34},                      // Left, Mid
    {-1019.51, -3495.49, 62.82, 4.34},                      // Right, Mid
    {-1017.25, -3500.85, 62.98, 4.34},                      // Left, front
    {-1020.95, -3499.21, 62.98, 4.34}                       // Right, Front
};

//horde run to where
#define H_RUNTOX -1016.44
#define H_RUNTOY -3508.48
#define H_RUNTOZ 62.96

const uint32 AllianceSoldierId[3] =
{
    12938,                                                  // 12938 Injured Alliance Soldier
    12936,                                                  // 12936 Badly injured Alliance Soldier
    12937                                                   // 12937 Critically injured Alliance Soldier
};

const uint32 HordeSoldierId[3] =
{
    12923,                                                  //12923 Injured Soldier
    12924,                                                  //12924 Badly injured Soldier
    12925                                                   //12925 Critically injured Soldier
};

/*######
## npc_doctor (handles both Gustaf Vanhowzen and Gregory Victor)
######*/

struct npc_doctorAI : public ScriptedAI
{
    npc_doctorAI(Creature *c) : ScriptedAI(c) {}

    uint64 PlayerGUID;

    uint32 SummonPatient_Timer;
    uint32 SummonPatientCount;
    uint32 PatientDiedCount;
    uint32 PatientSavedCount;

    bool Event;

    std::list<uint64> Patients;
    std::vector<Location*> Coordinates;

    void Reset()
    {
        PlayerGUID = 0;

        SummonPatient_Timer = 10000;
        SummonPatientCount = 0;
        PatientDiedCount = 0;
        PatientSavedCount = 0;

        Patients.clear();
        Coordinates.clear();

        Event = false;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void BeginEvent(Player* pPlayer);
    void PatientDied(Location* Point);
    void PatientSaved(Creature* soldier, Player* pPlayer, Location* Point);
    void UpdateAI(const uint32 diff);

    void EnterCombat(Unit* /*who*/){}
};

/*#####
## npc_injured_patient (handles all the patients, no matter Horde or Alliance)
#####*/

struct npc_injured_patientAI : public ScriptedAI
{
    npc_injured_patientAI(Creature *c) : ScriptedAI(c) {}

    uint64 Doctorguid;
    Location* Coord;

    void Reset()
    {
        Doctorguid = 0;
        Coord = NULL;

        //no select
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        //no regen health
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

        //to make them lay with face down
        me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);

        uint32 mobId = me->GetEntry();

        switch (mobId)
        {                                                   //lower max health
            case 12923:
            case 12938:                                     //Injured Soldier
                me->SetHealth(uint32(me->GetMaxHealth()*.75));
                break;
            case 12924:
            case 12936:                                     //Badly injured Soldier
                me->SetHealth(uint32(me->GetMaxHealth()*.50));
                break;
            case 12925:
            case 12937:                                     //Critically injured Soldier
                me->SetHealth(uint32(me->GetMaxHealth()*.25));
                break;
        }
    }

    void EnterCombat(Unit* /*who*/){}

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (caster->GetTypeId() == TYPEID_PLAYER && me->isAlive() && spell->Id == 20804)
        {
            if ((CAST_PLR(caster)->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (CAST_PLR(caster)->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE))
                if (Doctorguid)
                    if (Creature* Doctor = Unit::GetCreature(*me, Doctorguid))
                        CAST_AI(npc_doctorAI, Doctor->AI())->PatientSaved(me, CAST_PLR(caster), Coord);

            //make not selectable
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            //regen health
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

            //stand up
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);

            DoScriptText(RAND(SAY_DOC1,SAY_DOC2,SAY_DOC3), me);

            uint32 mobId = me->GetEntry();
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

            switch (mobId)
            {
                case 12923:
                case 12924:
                case 12925:
                    me->GetMotionMaster()->MovePoint(0, H_RUNTOX, H_RUNTOY, H_RUNTOZ);
                    break;
                case 12936:
                case 12937:
                case 12938:
                    me->GetMotionMaster()->MovePoint(0, A_RUNTOX, A_RUNTOY, A_RUNTOZ);
                    break;
            }
        }
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        //lower HP on every world tick makes it a useful counter, not officlone though
        if (me->isAlive() && me->GetHealth() > 6)
        {
            me->SetHealth(uint32(me->GetHealth()-5));
        }

        if (me->isAlive() && me->GetHealth() <= 6)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setDeathState(JUST_DIED);
            me->SetFlag(UNIT_DYNAMIC_FLAGS, 32);

            if (Doctorguid)
            {
                if (Creature* Doctor = Unit::GetCreature((*me), Doctorguid))
                    CAST_AI(npc_doctorAI, Doctor->AI())->PatientDied(Coord);
            }
        }
    }
};

CreatureAI* GetAI_npc_injured_patient(Creature* pCreature)
{
    return new npc_injured_patientAI (pCreature);
}

/*
npc_doctor (continue)
*/

void npc_doctorAI::BeginEvent(Player* pPlayer)
{
    PlayerGUID = pPlayer->GetGUID();

    SummonPatient_Timer = 10000;
    SummonPatientCount = 0;
    PatientDiedCount = 0;
    PatientSavedCount = 0;

    switch(me->GetEntry())
    {
        case DOCTOR_ALLIANCE:
            for (uint8 i = 0; i < ALLIANCE_COORDS; ++i)
                Coordinates.push_back(&AllianceCoords[i]);
            break;
        case DOCTOR_HORDE:
            for (uint8 i = 0; i < HORDE_COORDS; ++i)
                Coordinates.push_back(&HordeCoords[i]);
            break;
    }

    Event = true;
    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
}

void npc_doctorAI::PatientDied(Location* Point)
{
    Player* pPlayer = Unit::GetPlayer(PlayerGUID);
    if (pPlayer && ((pPlayer->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (pPlayer->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)))
    {
        ++PatientDiedCount;

        if (PatientDiedCount > 5 && Event)
        {
            if (pPlayer->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                pPlayer->FailQuest(6624);
            else if (pPlayer->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                pPlayer->FailQuest(6622);

            Reset();
            return;
        }

        Coordinates.push_back(Point);
    }
    else
        // If no player or player abandon quest in progress
        Reset();
}

void npc_doctorAI::PatientSaved(Creature* /*soldier*/, Player* pPlayer, Location* Point)
{
    if (pPlayer && PlayerGUID == pPlayer->GetGUID())
    {
        if ((pPlayer->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (pPlayer->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE))
        {
            ++PatientSavedCount;

            if (PatientSavedCount == 15)
            {
                if (!Patients.empty())
                {
                    std::list<uint64>::const_iterator itr;
                    for (itr = Patients.begin(); itr != Patients.end(); ++itr)
                    {
                        if (Creature* Patient = Unit::GetCreature((*me), *itr))
                            Patient->setDeathState(JUST_DIED);
                    }
                }

                if (pPlayer->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->AreaExploredOrEventHappens(6624);
                else if (pPlayer->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->AreaExploredOrEventHappens(6622);

                Reset();
                return;
            }

            Coordinates.push_back(Point);
        }
    }
}

void npc_doctorAI::UpdateAI(const uint32 diff)
{
    if (Event && SummonPatientCount >= 20)
    {
        Reset();
        return;
    }

    if (Event)
    {
        if (SummonPatient_Timer <= diff)
        {
            Creature* Patient = NULL;
            Location* Point = NULL;

                if (Coordinates.empty())
                return;

            std::vector<Location*>::iterator itr = Coordinates.begin()+rand()%Coordinates.size();
            uint32 patientEntry = 0;

            switch(me->GetEntry())
            {
                case DOCTOR_ALLIANCE: patientEntry = AllianceSoldierId[rand()%3]; break;
                case DOCTOR_HORDE:    patientEntry = HordeSoldierId[rand()%3]; break;
                default:
                    error_log("TSCR: Invalid entry for Triage doctor. Please check your database");
                    return;
            }

            Point = *itr;

            Patient = me->SummonCreature(patientEntry, Point->x, Point->y, Point->z, Point->o, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);

            if (Patient)
            {
                //303, this flag appear to be required for client side item->spell to work (TARGET_SINGLE_FRIEND)
                Patient->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

                Patients.push_back(Patient->GetGUID());
                CAST_AI(npc_injured_patientAI, Patient->AI())->Doctorguid = me->GetGUID();

                if (Point)
                    CAST_AI(npc_injured_patientAI, Patient->AI())->Coord = Point;

                Coordinates.erase(itr);
            }
            SummonPatient_Timer = 10000;
            ++SummonPatientCount;
        } else SummonPatient_Timer -= diff;
    }
}

bool QuestAccept_npc_doctor(Player* pPlayer, Creature* pCreature, Quest const *quest)
{
    if ((quest->GetQuestId() == 6624) || (quest->GetQuestId() == 6622))
        CAST_AI(npc_doctorAI, pCreature->AI())->BeginEvent(pPlayer);

    return true;
}

CreatureAI* GetAI_npc_doctor(Creature* pCreature)
{
    return new npc_doctorAI (pCreature);
}

/*######
## npc_garments_of_quests
######*/

//TODO: get text for each NPC

enum eGarments
{
    SPELL_LESSER_HEAL_R2    = 2052,
    SPELL_FORTITUDE_R1      = 1243,

    QUEST_MOON              = 5621,
    QUEST_LIGHT_1           = 5624,
    QUEST_LIGHT_2           = 5625,
    QUEST_SPIRIT            = 5648,
    QUEST_DARKNESS          = 5650,

    ENTRY_SHAYA             = 12429,
    ENTRY_ROBERTS           = 12423,
    ENTRY_DOLF              = 12427,
    ENTRY_KORJA             = 12430,
    ENTRY_DG_KEL            = 12428,

    //used by 12429,12423,12427,12430,12428, but signed for 12429
    SAY_COMMON_HEALED       = -1000164,
    SAY_DG_KEL_THANKS       = -1000165,
    SAY_DG_KEL_GOODBYE      = -1000166,
    SAY_ROBERTS_THANKS      = -1000167,
    SAY_ROBERTS_GOODBYE     = -1000168,
    SAY_KORJA_THANKS        = -1000169,
    SAY_KORJA_GOODBYE       = -1000170,
    SAY_DOLF_THANKS         = -1000171,
    SAY_DOLF_GOODBYE        = -1000172,
    SAY_SHAYA_THANKS        = -1000173,
    SAY_SHAYA_GOODBYE       = -1000174, //signed for 21469
};

struct npc_garments_of_questsAI : public npc_escortAI
{
    npc_garments_of_questsAI(Creature *c) : npc_escortAI(c) {Reset();}

    uint64 caster;

    bool bIsHealed;
    bool bCanRun;

    uint32 RunAwayTimer;

    void Reset()
    {
        caster = 0;

        bIsHealed = false;
        bCanRun = false;

        RunAwayTimer = 5000;

        me->SetStandState(UNIT_STAND_STATE_KNEEL);
        //expect database to have RegenHealth=0
        me->SetHealth(int(me->GetMaxHealth()*0.7));
    }

    void EnterCombat(Unit * /*who*/) {}

    void SpellHit(Unit* pCaster, const SpellEntry *Spell)
    {
        if (Spell->Id == SPELL_LESSER_HEAL_R2 || Spell->Id == SPELL_FORTITUDE_R1)
        {
            //not while in combat
            if (me->isInCombat())
                return;

            //nothing to be done now
            if (bIsHealed && bCanRun)
                return;

            if (pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                switch(me->GetEntry())
                {
                    case ENTRY_SHAYA:
                        if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_MOON) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                            {
                                DoScriptText(SAY_SHAYA_THANKS,me,pCaster);
                                bCanRun = true;
                            }
                            else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                            {
                                caster = pCaster->GetGUID();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_COMMON_HEALED,me,pCaster);
                                bIsHealed = true;
                            }
                        }
                        break;
                    case ENTRY_ROBERTS:
                        if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_LIGHT_1) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                            {
                                DoScriptText(SAY_ROBERTS_THANKS,me,pCaster);
                                bCanRun = true;
                            }
                            else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                            {
                                caster = pCaster->GetGUID();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_COMMON_HEALED,me,pCaster);
                                bIsHealed = true;
                            }
                        }
                        break;
                    case ENTRY_DOLF:
                        if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_LIGHT_2) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                            {
                                DoScriptText(SAY_DOLF_THANKS,me,pCaster);
                                bCanRun = true;
                            }
                            else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                            {
                                caster = pCaster->GetGUID();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_COMMON_HEALED,me,pCaster);
                                bIsHealed = true;
                            }
                        }
                        break;
                    case ENTRY_KORJA:
                        if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_SPIRIT) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                            {
                                DoScriptText(SAY_KORJA_THANKS,me,pCaster);
                                bCanRun = true;
                            }
                            else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                            {
                                caster = pCaster->GetGUID();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_COMMON_HEALED,me,pCaster);
                                bIsHealed = true;
                            }
                        }
                        break;
                    case ENTRY_DG_KEL:
                        if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_DARKNESS) == QUEST_STATUS_INCOMPLETE)
                        {
                            if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                            {
                                DoScriptText(SAY_DG_KEL_THANKS,me,pCaster);
                                bCanRun = true;
                            }
                            else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                            {
                                caster = pCaster->GetGUID();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_COMMON_HEALED,me,pCaster);
                                bIsHealed = true;
                            }
                        }
                        break;
                }

                //give quest credit, not expect any special quest objectives
                if (bCanRun)
                    CAST_PLR(pCaster)->TalkedToCreature(me->GetEntry(),me->GetGUID());
            }
        }
    }

    void WaypointReached(uint32 /*uiPoint*/)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (bCanRun && !me->isInCombat())
        {
            if (RunAwayTimer <= diff)
            {
                if (Unit *pUnit = Unit::GetUnit(*me,caster))
                {
                    switch(me->GetEntry())
                    {
                        case ENTRY_SHAYA: DoScriptText(SAY_SHAYA_GOODBYE,me,pUnit); break;
                        case ENTRY_ROBERTS: DoScriptText(SAY_ROBERTS_GOODBYE,me,pUnit); break;
                        case ENTRY_DOLF: DoScriptText(SAY_DOLF_GOODBYE,me,pUnit); break;
                        case ENTRY_KORJA: DoScriptText(SAY_KORJA_GOODBYE,me,pUnit); break;
                        case ENTRY_DG_KEL: DoScriptText(SAY_DG_KEL_GOODBYE,me,pUnit); break;
                    }

                    Start(false,true,true);
                }
                else
                    EnterEvadeMode();                       //something went wrong

                RunAwayTimer = 30000;
            } else RunAwayTimer -= diff;
        }

    npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_garments_of_quests(Creature* pCreature)
{
    return new npc_garments_of_questsAI(pCreature);
}

/*######
## npc_guardian
######*/

#define SPELL_DEATHTOUCH                5

struct npc_guardianAI : public ScriptedAI
{
    npc_guardianAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        if (!UpdateVictim())
            return;

        if (me->isAttackReady())
        {
            DoCast(me->getVictim(), SPELL_DEATHTOUCH, true);
            me->resetAttackTimer();
        }
    }
};

CreatureAI* GetAI_npc_guardian(Creature* pCreature)
{
    return new npc_guardianAI (pCreature);
}

/*######
## npc_kingdom_of_dalaran_quests
######*/

enum eKingdomDalaran
{
    SPELL_TELEPORT_DALARAN  = 53360,
    ITEM_KT_SIGNET          = 39740,
    QUEST_MAGICAL_KINGDOM_A = 12794,
    QUEST_MAGICAL_KINGDOM_H = 12791,
    QUEST_MAGICAL_KINGDOM_N = 12796
};

#define GOSSIP_ITEM_TELEPORT_TO "I am ready to be teleported to Dalaran."

bool GossipHello_npc_kingdom_of_dalaran_quests(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->HasItemCount(ITEM_KT_SIGNET,1) && (!pPlayer->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_A) ||
        !pPlayer->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_H) || !pPlayer->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_N)))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT_TO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_kingdom_of_dalaran_quests(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer,SPELL_TELEPORT_DALARAN,false);
    }
    return true;
}

/*######
## npc_mount_vendor
######*/

bool GossipHello_npc_mount_vendor(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    bool canBuy;
    canBuy = false;
    uint32 vendor = pCreature->GetEntry();
    uint8 race = pPlayer->getRace();

    switch (vendor)
    {
        case 384:                                           //Katie Hunter
        case 1460:                                          //Unger Statforth
        case 2357:                                          //Merideth Carlson
        case 4885:                                          //Gregor MacVince
            if (pPlayer->GetReputationRank(72) != REP_EXALTED && race != RACE_HUMAN)
                pPlayer->SEND_GOSSIP_MENU(5855, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 1261:                                          //Veron Amberstill
            if (pPlayer->GetReputationRank(47) != REP_EXALTED && race != RACE_DWARF)
                pPlayer->SEND_GOSSIP_MENU(5856, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 3362:                                          //Ogunaro Wolfrunner
            if (pPlayer->GetReputationRank(76) != REP_EXALTED && race != RACE_ORC)
                pPlayer->SEND_GOSSIP_MENU(5841, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 3685:                                          //Harb Clawhoof
            if (pPlayer->GetReputationRank(81) != REP_EXALTED && race != RACE_TAUREN)
                pPlayer->SEND_GOSSIP_MENU(5843, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 4730:                                          //Lelanai
            if (pPlayer->GetReputationRank(69) != REP_EXALTED && race != RACE_NIGHTELF)
                pPlayer->SEND_GOSSIP_MENU(5844, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 4731:                                          //Zachariah Post
            if (pPlayer->GetReputationRank(68) != REP_EXALTED && race != RACE_UNDEAD_PLAYER)
                pPlayer->SEND_GOSSIP_MENU(5840, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 7952:                                          //Zjolnir
            if (pPlayer->GetReputationRank(530) != REP_EXALTED && race != RACE_TROLL)
                pPlayer->SEND_GOSSIP_MENU(5842, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 7955:                                          //Milli Featherwhistle
            if (pPlayer->GetReputationRank(54) != REP_EXALTED && race != RACE_GNOME)
                pPlayer->SEND_GOSSIP_MENU(5857, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 16264:                                         //Winaestra
            if (pPlayer->GetReputationRank(911) != REP_EXALTED && race != RACE_BLOODELF)
                pPlayer->SEND_GOSSIP_MENU(10305, pCreature->GetGUID());
            else canBuy = true;
            break;
        case 17584:                                         //Torallius the Pack Handler
            if (pPlayer->GetReputationRank(930) != REP_EXALTED && race != RACE_DRAENEI)
                pPlayer->SEND_GOSSIP_MENU(10239, pCreature->GetGUID());
            else canBuy = true;
            break;
    }

    if (canBuy)
    {
        if (pCreature->isVendor())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_mount_vendor(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

    return true;
}

/*######
## npc_rogue_trainer
######*/

#define GOSSIP_HELLO_ROGUE1 "I wish to unlearn my talents"
#define GOSSIP_HELLO_ROGUE2 "<Take the letter>"
#define GOSSIP_HELLO_ROGUE3 "Purchase a Dual Talent Specialization."

bool GossipHello_npc_rogue_trainer(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isTrainer())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

    if (pCreature->isCanTrainingAndResetTalentsOf(pPlayer))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_HELLO_ROGUE1, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_UNLEARNTALENTS);

    if (!(pPlayer->GetSpecsCount() == 1 && pCreature->isCanTrainingAndResetTalentsOf(pPlayer) && !(pPlayer->getLevel() < sWorld.getConfig(CONFIG_MIN_DUALSPEC_LEVEL))))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_HELLO_ROGUE3, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_LEARNDUALSPEC);

    if (pPlayer->getClass() == CLASS_ROGUE && pPlayer->getLevel() >= 24 && !pPlayer->HasItemCount(17126,1) && !pPlayer->GetQuestRewardStatus(6681))
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_ROGUE2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(5996, pCreature->GetGUID());
    } else
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_rogue_trainer(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer,21100,false);
            break;
        case GOSSIP_ACTION_TRAIN:
            pPlayer->SEND_TRAINERLIST(pCreature->GetGUID());
            break;
        case GOSSIP_OPTION_UNLEARNTALENTS:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->SendTalentWipeConfirm(pCreature->GetGUID());
            break;
        case GOSSIP_OPTION_LEARNDUALSPEC:
            if (pPlayer->GetSpecsCount() == 1 && !(pPlayer->getLevel() < sWorld.getConfig(CONFIG_MIN_DUALSPEC_LEVEL)))
            {
                if (pPlayer->GetMoney() < 10000000)
                {
                    pPlayer->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                    pPlayer->PlayerTalkClass->CloseGossip();
                    break;
                }
                else
                {
                    pPlayer->ModifyMoney(-10000000);

                    // Cast spells that teach dual spec
                    // Both are also ImplicitTarget self and must be cast by player
                    pPlayer->CastSpell(pPlayer,63680,true,NULL,NULL,pPlayer->GetGUID());
                    pPlayer->CastSpell(pPlayer,63624,true,NULL,NULL,pPlayer->GetGUID());

                    // Should show another Gossip text with "Congratulations..."
                    pPlayer->PlayerTalkClass->CloseGossip();
                }
            }
            break;
    }
    return true;
}

/*######
## npc_sayge
######*/

#define SPELL_DMG       23768                               //dmg
#define SPELL_RES       23769                               //res
#define SPELL_ARM       23767                               //arm
#define SPELL_SPI       23738                               //spi
#define SPELL_INT       23766                               //int
#define SPELL_STM       23737                               //stm
#define SPELL_STR       23735                               //str
#define SPELL_AGI       23736                               //agi
#define SPELL_FORTUNE   23765                               //faire fortune

#define GOSSIP_HELLO_SAYGE  "Yes"
#define GOSSIP_SENDACTION_SAYGE1    "Slay the Man"
#define GOSSIP_SENDACTION_SAYGE2    "Turn him over to liege"
#define GOSSIP_SENDACTION_SAYGE3    "Confiscate the corn"
#define GOSSIP_SENDACTION_SAYGE4    "Let him go and have the corn"
#define GOSSIP_SENDACTION_SAYGE5    "Execute your friend painfully"
#define GOSSIP_SENDACTION_SAYGE6    "Execute your friend painlessly"
#define GOSSIP_SENDACTION_SAYGE7    "Let your friend go"
#define GOSSIP_SENDACTION_SAYGE8    "Confront the diplomat"
#define GOSSIP_SENDACTION_SAYGE9    "Show not so quiet defiance"
#define GOSSIP_SENDACTION_SAYGE10   "Remain quiet"
#define GOSSIP_SENDACTION_SAYGE11   "Speak against your brother openly"
#define GOSSIP_SENDACTION_SAYGE12   "Help your brother in"
#define GOSSIP_SENDACTION_SAYGE13   "Keep your brother out without letting him know"
#define GOSSIP_SENDACTION_SAYGE14   "Take credit, keep gold"
#define GOSSIP_SENDACTION_SAYGE15   "Take credit, share the gold"
#define GOSSIP_SENDACTION_SAYGE16   "Let the knight take credit"
#define GOSSIP_SENDACTION_SAYGE17   "Thanks"

bool GossipHello_npc_sayge(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->HasSpellCooldown(SPELL_INT) ||
        pPlayer->HasSpellCooldown(SPELL_ARM) ||
        pPlayer->HasSpellCooldown(SPELL_DMG) ||
        pPlayer->HasSpellCooldown(SPELL_RES) ||
        pPlayer->HasSpellCooldown(SPELL_STR) ||
        pPlayer->HasSpellCooldown(SPELL_AGI) ||
        pPlayer->HasSpellCooldown(SPELL_STM) ||
        pPlayer->HasSpellCooldown(SPELL_SPI))
        pPlayer->SEND_GOSSIP_MENU(7393, pCreature->GetGUID());
    else
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SAYGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(7339, pCreature->GetGUID());
    }

    return true;
}

void SendAction_npc_sayge(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE1,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE2,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE3,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE4,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            pPlayer->SEND_GOSSIP_MENU(7340, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE5,            GOSSIP_SENDER_MAIN+1, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE6,            GOSSIP_SENDER_MAIN+2, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE7,            GOSSIP_SENDER_MAIN+3, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(7341, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE8,            GOSSIP_SENDER_MAIN+4, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE9,            GOSSIP_SENDER_MAIN+5, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE10,           GOSSIP_SENDER_MAIN+2, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(7361, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE11,           GOSSIP_SENDER_MAIN+6, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE12,           GOSSIP_SENDER_MAIN+7, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE13,           GOSSIP_SENDER_MAIN+8, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(7362, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE14,           GOSSIP_SENDER_MAIN+5, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE15,           GOSSIP_SENDER_MAIN+4, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE16,           GOSSIP_SENDER_MAIN+3, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(7363, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE17,           GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            pPlayer->SEND_GOSSIP_MENU(7364, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pCreature->CastSpell(pPlayer, SPELL_FORTUNE, false);
            pPlayer->SEND_GOSSIP_MENU(7365, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_npc_sayge(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiSender)
    {
        case GOSSIP_SENDER_MAIN:
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+1:
            pCreature->CastSpell(pPlayer, SPELL_DMG, false);
            pPlayer->AddSpellCooldown(SPELL_DMG,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+2:
            pCreature->CastSpell(pPlayer, SPELL_RES, false);
            pPlayer->AddSpellCooldown(SPELL_RES,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+3:
            pCreature->CastSpell(pPlayer, SPELL_ARM, false);
            pPlayer->AddSpellCooldown(SPELL_ARM,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+4:
            pCreature->CastSpell(pPlayer, SPELL_SPI, false);
            pPlayer->AddSpellCooldown(SPELL_SPI,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+5:
            pCreature->CastSpell(pPlayer, SPELL_INT, false);
            pPlayer->AddSpellCooldown(SPELL_INT,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+6:
            pCreature->CastSpell(pPlayer, SPELL_STM, false);
            pPlayer->AddSpellCooldown(SPELL_STM,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+7:
            pCreature->CastSpell(pPlayer, SPELL_STR, false);
            pPlayer->AddSpellCooldown(SPELL_STR,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
        case GOSSIP_SENDER_MAIN+8:
            pCreature->CastSpell(pPlayer, SPELL_AGI, false);
            pPlayer->AddSpellCooldown(SPELL_AGI,0,time(NULL) + 7200);
            SendAction_npc_sayge(pPlayer, pCreature, uiAction);
            break;
    }
    return true;
}

struct npc_steam_tonkAI : public ScriptedAI
{
    npc_steam_tonkAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit * /*who*/) {}

    void OnPossess(bool apply)
    {
        if (apply)
        {
            // Initialize the action bar without the melee attack command
            me->InitCharmInfo();
            me->GetCharmInfo()->InitEmptyActionBar(false);

            me->SetReactState(REACT_PASSIVE);
        }
        else
            me->SetReactState(REACT_AGGRESSIVE);
    }

};

CreatureAI* GetAI_npc_steam_tonk(Creature* pCreature)
{
    return new npc_steam_tonkAI(pCreature);
}

#define SPELL_TONK_MINE_DETONATE 25099

struct npc_tonk_mineAI : public ScriptedAI
{
    npc_tonk_mineAI(Creature *c) : ScriptedAI(c)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint32 ExplosionTimer;

    void Reset()
    {
        ExplosionTimer = 3000;
    }

    void EnterCombat(Unit * /*who*/) {}
    void AttackStart(Unit * /*who*/) {}
    void MoveInLineOfSight(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (ExplosionTimer <= diff)
        {
            DoCast(me, SPELL_TONK_MINE_DETONATE, true);
            me->setDeathState(DEAD); // unsummon it
        } else
            ExplosionTimer -= diff;
    }
};

CreatureAI* GetAI_npc_tonk_mine(Creature* pCreature)
{
    return new npc_tonk_mineAI(pCreature);
}

/*####
## npc_brewfest_reveler
####*/

struct npc_brewfest_revelerAI : public ScriptedAI
{
    npc_brewfest_revelerAI(Creature* c) : ScriptedAI(c) {}
    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        if (!IsHolidayActive(HOLIDAY_BREWFEST))
            return;

        if (emote == TEXTEMOTE_DANCE)
            me->CastSpell(pPlayer, 41586, false);
    }
};

CreatureAI* GetAI_npc_brewfest_reveler(Creature* pCreature)
{
    return new npc_brewfest_revelerAI(pCreature);
}

/*####
## npc_winter_reveler
####*/

struct npc_winter_revelerAI : public ScriptedAI
{
    npc_winter_revelerAI(Creature* c) : ScriptedAI(c) {}
    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        if (!IsHolidayActive(HOLIDAY_FEAST_OF_WINTER_VEIL))
            return;
        //TODO: check auralist.
        if (pPlayer->HasAura(26218))
            return;

        if (emote == TEXTEMOTE_KISS)
        {
            me->CastSpell(me, 26218, false);
            pPlayer->CastSpell(pPlayer, 26218, false);
            switch (urand(0,2))
            {
                case 0: me->CastSpell(pPlayer, 26207, false); break;
                case 1: me->CastSpell(pPlayer, 26206, false); break;
                case 2: me->CastSpell(pPlayer, 45036, false); break;
            }
        }
    }
};

CreatureAI* GetAI_npc_winter_reveler(Creature* pCreature)
{
    return new npc_winter_revelerAI(pCreature);
}


/*####
## npc_snake_trap_serpents
####*/

#define SPELL_MIND_NUMBING_POISON    25810   //Viper
#define SPELL_DEADLY_POISON          34655   //Venomous Snake
#define SPELL_CRIPPLING_POISON       30981   //Viper

#define VENOMOUS_SNAKE_TIMER 1500
#define VIPER_TIMER 3000

#define C_VIPER 19921

#define RAND 5

struct npc_snake_trap_serpentsAI : public ScriptedAI
{
    npc_snake_trap_serpentsAI(Creature *c) : ScriptedAI(c) {}

    uint32 SpellTimer;
    bool IsViper;
    bool Spawn;

    void EnterCombat(Unit * /*who*/) {}

    void Reset()
    {
        Spawn = true;
        SpellTimer = 0;

        CreatureInfo const *Info = me->GetCreatureInfo();

        if (Info->Entry == C_VIPER)
            IsViper = true;
        else
            IsViper = false;

        //Add delta to make them not all hit the same time
        uint32 delta = (rand() % 7) * 100;
        me->SetStatFloatValue(UNIT_FIELD_BASEATTACKTIME, Info->baseattacktime + delta);
        me->SetStatFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER , Info->attackpower);
    }

    //Redefined for random target selection:
    void MoveInLineOfSight(Unit *who)
    {
        if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)) && who->isInAccessiblePlaceFor(me))
        {
            if (me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = me->GetAttackDistance(who);
            if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
            {
                if (!(rand() % RAND))
                {
                    me->setAttackTimer(BASE_ATTACK, (rand() % 10) * 100);
                    SpellTimer = (rand() % 10) * 100;
                    AttackStart(who);
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (Spawn)
        {
            Spawn = false;
            // Start attacking attacker of owner on first ai update after spawn - move in line of sight may choose better target
            if (!me->getVictim() && me->isSummon())
                if (Unit * Owner = CAST_SUM(me)->GetSummoner())
                    if (Owner->getAttackerForHelper())
                        AttackStart(Owner->getAttackerForHelper());
        }

        if (!me->getVictim())
        {
            if (me->isInCombat())
                DoStopAttack();
            return;
        }

        if (SpellTimer <= diff)
        {
            if (IsViper) //Viper
            {
                if (urand(0,2) == 0) //33% chance to cast
                {
                    uint32 spell;
                    if (urand(0,1) == 0)
                        spell = SPELL_MIND_NUMBING_POISON;
                    else
                        spell = SPELL_CRIPPLING_POISON;

                    DoCast(me->getVictim(), spell);
                }

                SpellTimer = VIPER_TIMER;
            }
            else //Venomous Snake
            {
                if (urand(0,2) == 0) //33% chance to cast
                    DoCast(me->getVictim(), SPELL_DEADLY_POISON);
                SpellTimer = VENOMOUS_SNAKE_TIMER + (rand() %5)*100;
            }
        } else SpellTimer -= diff;
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_snake_trap_serpents(Creature* pCreature)
{
    return new npc_snake_trap_serpentsAI(pCreature);
}

#define SAY_RANDOM_MOJO0    "Now that's what I call froggy-style!"
#define SAY_RANDOM_MOJO1    "Your lily pad or mine?"
#define SAY_RANDOM_MOJO2    "This won't take long, did it?"
#define SAY_RANDOM_MOJO3    "I thought you'd never ask!"
#define SAY_RANDOM_MOJO4    "I promise not to give you warts..."
#define SAY_RANDOM_MOJO5    "Feelin' a little froggy, are ya?"
#define SAY_RANDOM_MOJO6a   "Listen, "
#define SAY_RANDOM_MOJO6b   ", I know of a little swamp not too far from here...."
#define SAY_RANDOM_MOJO7    "There's just never enough Mojo to go around..."

struct mob_mojoAI : public ScriptedAI
{
    mob_mojoAI(Creature *c) : ScriptedAI(c) {Reset();}
    uint32 hearts;
    uint64 victimGUID;
    void Reset()
    {
        victimGUID = 0;
        hearts = 15000;
        if (Unit* own = me->GetOwner())
            me->GetMotionMaster()->MoveFollow(own,0,0);
    }
    void Aggro(Unit * /*who*/){}
    void UpdateAI(const uint32 diff)
    {
        if (me->HasAura(20372))
        {
            if (hearts <= diff)
            {
                me->RemoveAurasDueToSpell(20372);
                hearts = 15000;
            } hearts -= diff;
        }
    }
    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        me->HandleEmoteCommand(emote);
        Unit* own = me->GetOwner();
        if (!own || own->GetTypeId() != TYPEID_PLAYER || CAST_PLR(own)->GetTeam() != pPlayer->GetTeam())
            return;
        if (emote == TEXTEMOTE_KISS)
        {
            std::string whisp = "";
            switch (rand()%8)
            {
                case 0:whisp.append(SAY_RANDOM_MOJO0);break;
                case 1:whisp.append(SAY_RANDOM_MOJO1);break;
                case 2:whisp.append(SAY_RANDOM_MOJO2);break;
                case 3:whisp.append(SAY_RANDOM_MOJO3);break;
                case 4:whisp.append(SAY_RANDOM_MOJO4);break;
                case 5:whisp.append(SAY_RANDOM_MOJO5);break;
                case 6:
                    whisp.append(SAY_RANDOM_MOJO6a);
                    whisp.append(pPlayer->GetName());
                    whisp.append(SAY_RANDOM_MOJO6b);
                    break;
                case 7:whisp.append(SAY_RANDOM_MOJO7);break;
            }
            me->MonsterWhisper(whisp.c_str(),pPlayer->GetGUID());
            if (victimGUID)
            {
                Player* victim = Unit::GetPlayer(victimGUID);
                if (victim)
                    victim->RemoveAura(43906);//remove polymorph frog thing
            }
            me->AddAura(43906,pPlayer);//add polymorph frog thing
            victimGUID = pPlayer->GetGUID();
            DoCast(me, 20372, true);//tag.hearts
            me->GetMotionMaster()->MoveFollow(pPlayer,0,0);
            hearts = 15000;
        }
    }
};

CreatureAI* GetAI_mob_mojo(Creature* pCreature)
{
    return new mob_mojoAI (pCreature);
}

struct npc_mirror_image : CasterAI
{
    npc_mirror_image(Creature *c) : CasterAI(c) {}

    void InitializeAI()
    {
        CasterAI::InitializeAI();
        Unit * owner = me->GetOwner();
        if (!owner)
            return;
        // Inherit Master's Threat List (not yet implemented)
        owner->CastSpell((Unit*)NULL, 58838, true);
        // here mirror image casts on summoner spell (not present in client dbc) 49866
        // here should be auras (not present in client dbc): 35657, 35658, 35659, 35660 selfcasted by mirror images (stats related?)
        // Clone Me!
        owner->CastSpell(me, 45204, false);
    }

    // Do not reload Creature templates on evade mode enter - prevent visual lost
    void EnterEvadeMode()
    {
        if (me->IsInEvadeMode() || !me->isAlive())
            return;

        Unit *owner = me->GetCharmerOrOwner();

        me->CombatStop(true);
        if (owner && !me->hasUnitState(UNIT_STAT_FOLLOW))
        {
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
        }
    }
};

CreatureAI* GetAI_npc_mirror_image(Creature* pCreature)
{
    return new npc_mirror_image (pCreature);
}

struct npc_ebon_gargoyleAI : CasterAI
{
    npc_ebon_gargoyleAI(Creature *c) : CasterAI(c) {}

    int despawnTimer;

    void InitializeAI()
    {
        CasterAI::InitializeAI();
        Unit * owner = me->GetOwner();
        if (!owner)
            return;
        // Not needed to be despawned now
        despawnTimer = 0;
        // Find victim of Summon Gargoyle spell
        std::list<Unit*> targets;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
        me->VisitNearbyObject(30, searcher);
        for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
            if ((*iter)->GetAura(49206,owner->GetGUID()))
            {
                me->Attack((*iter),false);
                break;
            }
    }

    void JustDied(Unit * /*killer*/)
    {
        // Stop Feeding Gargoyle when it dies
        if (Unit *owner = me->GetOwner())
            owner->RemoveAurasDueToSpell(50514);
    }

    // Fly away when dismissed
    void SpellHit(Unit *source, const SpellEntry *spell)
    {
        if (spell->Id != 50515 || !me->isAlive())
            return;

        Unit *owner = me->GetOwner();

        if (!owner || owner != source)
            return;

        // Stop Fighting
        me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);
        // Sanctuary
        me->CastSpell(me, 54661, true);
        me->SetReactState(REACT_PASSIVE);

        // Fly Away
        me->AddUnitMovementFlag(MOVEMENTFLAG_FLY_MODE|MOVEMENTFLAG_ASCEND|MOVEMENTFLAG_FLYING);
        me->SetSpeed(MOVE_FLIGHT, 0.75f, true);
        me->SetSpeed(MOVE_RUN, 0.75f, true);
        float x = me->GetPositionX() + 20 * cos(me->GetOrientation());
        float y = me->GetPositionY() + 20 * sin(me->GetOrientation());
        float z = me->GetPositionZ() + 40;
        me->GetMotionMaster()->Clear(false);
        me->GetMotionMaster()->MovePoint(0, x, y, z);

        // Despawn as soon as possible
        despawnTimer = 4 * IN_MILISECONDS;
    }

    void UpdateAI(const uint32 diff)
    {
        if (despawnTimer > 0)
        {
            if (despawnTimer > diff)
                despawnTimer -= diff;
            else
            {
                me->ForcedDespawn();
            }
            return;
        }
        CasterAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_ebon_gargoyle(Creature* pCreature)
{
    return new npc_ebon_gargoyleAI (pCreature);
}

struct npc_lightwellAI : public PassiveAI
{
    npc_lightwellAI(Creature *c) : PassiveAI(c) {}

    void Reset()
    {
        DoCast(me, 59907, false); // Spell for Lightwell Charges
    }
};

CreatureAI* GetAI_npc_lightwellAI(Creature* pCreature)
{
    return new npc_lightwellAI (pCreature);
}

struct npc_training_dummy : Scripted_NoMovementAI
{
    npc_training_dummy(Creature *c) : Scripted_NoMovementAI(c)
    {
        m_Entry = c->GetEntry();
    }

    uint64 m_Entry;
    uint32 ResetTimer;
    uint32 DespawnTimer;
    void Reset()
    {
        me->SetControlled(true,UNIT_STAT_STUNNED);//disable rotate
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);//imune to knock aways like blast wave
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        ResetTimer = 10000;
        DespawnTimer = 15000;
    }

    void EnterEvadeMode()
    {
        if (!_EnterEvadeMode())
            return;

        Reset();
    }

    void DamageTaken(Unit * /*done_by*/, uint32 &damage)
    {
        ResetTimer = 10000;
        damage = 0;
    }

    void EnterCombat(Unit * /*who*/)
    {
        if (m_Entry != 2674 && m_Entry != 2673)
            return;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (!me->hasUnitState(UNIT_STAT_STUNNED))
            me->SetControlled(true,UNIT_STAT_STUNNED);//disable rotate

        if (m_Entry != 2674 && m_Entry != 2673)
        {
            if (ResetTimer <= diff)
            {
                EnterEvadeMode();
                ResetTimer = 10000;
            }
            else
                ResetTimer -= diff;
            return;
        }
        else
        {
            if (DespawnTimer <= diff)
                me->ForcedDespawn();
            else
                DespawnTimer -= diff;
        }
    }
    void MoveInLineOfSight(Unit * /*who*/){return;}
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummy (pCreature);
}

/*######
# npc_shadowfiend
######*/
#define GLYPH_OF_SHADOWFIEND_MANA         58227
#define GLYPH_OF_SHADOWFIEND              58228

struct npc_shadowfiendAI : public ScriptedAI
{
    npc_shadowfiendAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void DamageTaken(Unit* /*pKiller*/, uint32 &damage)
    {
        if (me->isSummon())
            if (Unit* pOwner = CAST_SUM(me)->GetSummoner())
            {
                if (pOwner->HasAura(GLYPH_OF_SHADOWFIEND))
                    if (damage >= me->GetHealth())
                        pOwner->CastSpell(pOwner,GLYPH_OF_SHADOWFIEND_MANA,true);
            }
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_shadowfiend(Creature* pCreature)
{
    return new npc_shadowfiendAI(pCreature);
}

/*######
# npc_wormhole
######*/

#define GOSSIP_ENGINEERING1   "Borean Tundra."
#define GOSSIP_ENGINEERING2   "Howling Fjord."
#define GOSSIP_ENGINEERING3   "Sholazar Basin."
#define GOSSIP_ENGINEERING4   "Icecrown."
#define GOSSIP_ENGINEERING5   "Storm Peaks."

enum eWormhole
{
    SPELL_HOWLING_FJORD         = 67838,
    SPELL_SHOLAZAR_BASIN        = 67835,
    SPELL_ICECROWN              = 67836,
    SPELL_STORM_PEAKS           = 67837,

    TEXT_WORMHOLE               = 907
};

bool GossipHello_npc_wormhole(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isSummon())
    {
        if (pPlayer == CAST_SUM(pCreature)->GetSummoner())
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);

            pPlayer->PlayerTalkClass->SendGossipMenu(TEXT_WORMHOLE, pCreature->GetGUID());
        }
    }
    return true;
}

bool GossipSelect_npc_wormhole(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    bool roll = urand(0,1);

    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1: //Borean Tundra
            pPlayer->CLOSE_GOSSIP_MENU();
            if (roll) //At the moment we don't have chance on spell_target_position table so we hack this
                pPlayer->TeleportTo(571, 4305.505859, 5450.839844, 63.005806, 0.627286);
            else
                pPlayer->TeleportTo(571, 3201.936279, 5630.123535, 133.658798, 3.855272);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2: //Howling Fjord
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_HOWLING_FJORD, true);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3: //Sholazar Basin
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_SHOLAZAR_BASIN, true);
            break;
        case GOSSIP_ACTION_INFO_DEF + 4: //Icecrown
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_ICECROWN, true);
            break;
        case GOSSIP_ACTION_INFO_DEF + 5: //Storm peaks
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_STORM_PEAKS, true);
            break;
    }
    return true;
}

/*###### 
## npc_pet_trainer 
######*/ 

enum ePetTrainer
{
    TEXT_ISHUNTER               = 5838,
    TEXT_NOTHUNTER              = 5839,
    TEXT_PETINFO                = 13474,
    TEXT_CONFIRM                = 7722
};

#define GOSSIP_PET1             "How do I train my pet?"
#define GOSSIP_PET2             "I wish to untrain my pet."
#define GOSSIP_PET_CONFIRM      "Yes, please do."

bool GossipHello_npc_pet_trainer(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->getClass() == CLASS_HUNTER)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        if (pPlayer->GetPet() && pPlayer->GetPet()->getPetType() == HUNTER_PET)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        pPlayer->PlayerTalkClass->SendGossipMenu(TEXT_ISHUNTER, pCreature->GetGUID());
        return true;
    }
    pPlayer->PlayerTalkClass->SendGossipMenu(TEXT_NOTHUNTER, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_pet_trainer(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->PlayerTalkClass->SendGossipMenu(TEXT_PETINFO, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET_CONFIRM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                pPlayer->PlayerTalkClass->SendGossipMenu(TEXT_CONFIRM, pCreature->GetGUID());
            }
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            {
                pPlayer->ResetPetTalents();
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
    }
    return true;
}

/*######
## npc_locksmith
######*/

enum eLockSmith
{
    QUEST_HOW_TO_BRAKE_IN_TO_THE_ARCATRAZ = 10704,
    QUEST_DARK_IRON_LEGACY                = 3802,
    QUEST_THE_KEY_TO_SCHOLOMANCE_A        = 5505,
    QUEST_THE_KEY_TO_SCHOLOMANCE_H        = 5511,
    QUEST_HOTTER_THAN_HELL_A              = 10758,
    QUEST_HOTTER_THAN_HELL_H              = 10764,
    QUEST_RETURN_TO_KHAGDAR               = 9837,
    QUEST_CONTAINMENT                     = 13159,

    ITEM_ARCATRAZ_KEY                     = 31084,
    ITEM_SHADOWFORGE_KEY                  = 11000,
    ITEM_SKELETON_KEY                     = 13704,
    ITEM_SHATTERED_HALLS_KEY              = 28395,
    ITEM_THE_MASTERS_KEY                  = 24490,
    ITEM_VIOLET_HOLD_KEY                  = 42482,

    SPELL_ARCATRAZ_KEY                    = 54881,
    SPELL_SHADOWFORGE_KEY                 = 54882,
    SPELL_SKELETON_KEY                    = 54883,
    SPELL_SHATTERED_HALLS_KEY             = 54884,
    SPELL_THE_MASTERS_KEY                 = 54885,
    SPELL_VIOLET_HOLD_KEY                 = 67253
};

#define GOSSIP_LOST_ARCATRAZ_KEY         "I've lost my key to the Arcatraz."
#define GOSSIP_LOST_SHADOWFORGE_KEY      "I've lost my key to the Blackrock Depths."
#define GOSSIP_LOST_SKELETON_KEY         "I've lost my key to the Scholomance."
#define GOSSIP_LOST_SHATTERED_HALLS_KEY  "I've lost my key to the Shattered Halls."
#define GOSSIP_LOST_THE_MASTERS_KEY      "I've lost my key to the Karazhan."
#define GOSSIP_LOST_VIOLET_HOLD_KEY      "I've lost my key to the Violet Hold."


bool GossipHello_npc_locksmith(Player* pPlayer, Creature* pCreature)
{

    // Arcatraz Key
    if (pPlayer->GetQuestRewardStatus(QUEST_HOW_TO_BRAKE_IN_TO_THE_ARCATRAZ) && !pPlayer->HasItemCount(ITEM_ARCATRAZ_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_ARCATRAZ_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +1);

    // Shadowforge Key
    if (pPlayer->GetQuestRewardStatus(QUEST_DARK_IRON_LEGACY) && !pPlayer->HasItemCount(ITEM_SHADOWFORGE_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SHADOWFORGE_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +2);

    // Skeleton Key
    if ((pPlayer->GetQuestRewardStatus(QUEST_THE_KEY_TO_SCHOLOMANCE_A) || pPlayer->GetQuestRewardStatus(QUEST_THE_KEY_TO_SCHOLOMANCE_H)) &&
        !pPlayer->HasItemCount(ITEM_SKELETON_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SKELETON_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +3);

    // Shatered Halls Key
    if ((pPlayer->GetQuestRewardStatus(QUEST_HOTTER_THAN_HELL_A) || pPlayer->GetQuestRewardStatus(QUEST_HOTTER_THAN_HELL_H)) &&
        !pPlayer->HasItemCount(ITEM_SHATTERED_HALLS_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SHATTERED_HALLS_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +4);

    // Master's Key
    if (pPlayer->GetQuestRewardStatus(QUEST_RETURN_TO_KHAGDAR) && !pPlayer->HasItemCount(ITEM_THE_MASTERS_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_THE_MASTERS_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +5);

    // Violet Hold Key
    if (pPlayer->GetQuestRewardStatus(QUEST_CONTAINMENT) && !pPlayer->HasItemCount(ITEM_VIOLET_HOLD_KEY, 1, true))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_VIOLET_HOLD_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +6);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_locksmith(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_ARCATRAZ_KEY, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_SHADOWFORGE_KEY, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_SKELETON_KEY, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_SHATTERED_HALLS_KEY, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_THE_MASTERS_KEY, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_VIOLET_HOLD_KEY, false);
            break;
    }
    return true;
}

/*###### 
## npc_tabard_vendor 
######*/ 
 
enum 
{ 
    QUEST_TRUE_MASTERS_OF_LIGHT = 9737, 
    QUEST_THE_UNWRITTEN_PROPHECY = 9762, 
    QUEST_INTO_THE_BREACH = 10259, 
    QUEST_BATTLE_OF_THE_CRIMSON_WATCH = 10781, 
    QUEST_SHARDS_OF_AHUNE = 11972, 
 
    ACHIEVEMENT_EXPLORE_NORTHREND = 45, 
    ACHIEVEMENT_TWENTYFIVE_TABARDS = 1021, 
    ACHIEVEMENT_THE_LOREMASTER_A = 1681, 
    ACHIEVEMENT_THE_LOREMASTER_H = 1682, 
 
    ITEM_TABARD_OF_THE_HAND = 24344, 
    ITEM_TABARD_OF_THE_BLOOD_KNIGHT = 25549, 
    ITEM_TABARD_OF_THE_PROTECTOR = 28788, 
    ITEM_OFFERING_OF_THE_SHATAR = 31408, 
    ITEM_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI = 31404, 
    ITEM_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI = 31405, 
    ITEM_TABARD_OF_THE_SUMMER_SKIES = 35279, 
    ITEM_TABARD_OF_THE_SUMMER_FLAMES = 35280, 
    ITEM_TABARD_OF_THE_ACHIEVER = 40643, 
    ITEM_LOREMASTERS_COLORS = 43300, 
    ITEM_TABARD_OF_THE_EXPLORER = 43348, 
 
    SPELL_TABARD_OF_THE_BLOOD_KNIGHT = 54974, 
    SPELL_TABARD_OF_THE_HAND = 54976, 
    SPELL_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI = 54977, 
    SPELL_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI = 54982, 
    SPELL_TABARD_OF_THE_ACHIEVER = 55006, 
    SPELL_TABARD_OF_THE_PROTECTOR = 55008, 
    SPELL_LOREMASTERS_COLORS = 58194, 
    SPELL_TABARD_OF_THE_EXPLORER = 58224, 
    SPELL_TABARD_OF_SUMMER_SKIES = 62768, 
    SPELL_TABARD_OF_SUMMER_FLAMES = 62769 
}; 

#define GOSSIP_LOST_TABARD_OF_BLOOD_KNIGHT "I've lost my Tabard of Blood Knight." 
#define GOSSIP_LOST_TABARD_OF_THE_HAND "I've lost my Tabard of the Hand." 
#define GOSSIP_LOST_TABARD_OF_THE_PROTECTOR "I've lost my Tabard of the Protector." 
#define GOSSIP_LOST_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI "I've lost my Green Trophy Tabard of the Illidari." 
#define GOSSIP_LOST_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI "I've lost my Purple Trophy Tabard of the Illidari." 
#define GOSSIP_LOST_TABARD_OF_SUMMER_SKIES "I've lost my Tabard of Summer Skies." 
#define GOSSIP_LOST_TABARD_OF_SUMMER_FLAMES "I've lost my Tabard of Summer Flames." 
#define GOSSIP_LOST_LOREMASTERS_COLORS "I've lost my Loremaster's Colors." 
#define GOSSIP_LOST_TABARD_OF_THE_EXPLORER "I've lost my Tabard of the Explorer." 
#define GOSSIP_LOST_TABARD_OF_THE_ACHIEVER "I've lost my Tabard of the Achiever." 
 
bool GossipHello_npc_tabard_vendor(Player* pPlayer, Creature* pCreature) 
{ 
    bool m_bLostBloodKnight = false; 
    bool m_bLostHand = false; 
    bool m_bLostProtector = false; 
    bool m_bLostIllidari = false; 
    bool m_bLostSummer = false; 
 
    //Tabard of the Blood Knight 
    if (pPlayer->GetQuestRewardStatus(QUEST_TRUE_MASTERS_OF_LIGHT) && !pPlayer->HasItemCount(ITEM_TABARD_OF_THE_BLOOD_KNIGHT, 1, true)) 
        m_bLostBloodKnight = true; 
 
    //Tabard of the Hand 
    if (pPlayer->GetQuestRewardStatus(QUEST_THE_UNWRITTEN_PROPHECY) && !pPlayer->HasItemCount(ITEM_TABARD_OF_THE_HAND, 1, true)) 
        m_bLostHand = true; 
 
    //Tabard of the Protector 
    if (pPlayer->GetQuestRewardStatus(QUEST_INTO_THE_BREACH) && !pPlayer->HasItemCount(ITEM_TABARD_OF_THE_PROTECTOR, 1, true)) 
        m_bLostProtector = true; 
 
    //Green Trophy Tabard of the Illidari 
    //Purple Trophy Tabard of the Illidari 
    if (pPlayer->GetQuestRewardStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) && 
        (!pPlayer->HasItemCount(ITEM_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, 1, true) && 
        !pPlayer->HasItemCount(ITEM_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, 1, true) && 
        !pPlayer->HasItemCount(ITEM_OFFERING_OF_THE_SHATAR, 1, true))) 
        m_bLostIllidari = true; 
 
    //Tabard of Summer Skies 
    //Tabard of Summer Flames 
    if (pPlayer->GetQuestRewardStatus(QUEST_SHARDS_OF_AHUNE) && 
        !pPlayer->HasItemCount(ITEM_TABARD_OF_THE_SUMMER_SKIES, 1, true) && 
        !pPlayer->HasItemCount(ITEM_TABARD_OF_THE_SUMMER_FLAMES, 1, true)) 
        m_bLostSummer = true; 
 
    if (m_bLostBloodKnight || m_bLostHand || m_bLostProtector || m_bLostIllidari || m_bLostSummer) 
    { 
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE); 
 
        if (m_bLostBloodKnight) 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_BLOOD_KNIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +1); 
 
        if (m_bLostHand) 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_THE_HAND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +2); 
 
        if (m_bLostProtector) 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_THE_PROTECTOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3); 
 
        if (m_bLostIllidari) 
        { 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4); 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5); 
        } 
 
        if (m_bLostSummer) 
        { 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_SUMMER_SKIES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6); 
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_SUMMER_FLAMES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7); 
        } 
 
        pPlayer->SEND_GOSSIP_MENU(13583, pCreature->GetGUID()); 
    } 
    else 
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID()); 
 
    return true; 
} 
 
bool GossipSelect_npc_tabard_vendor(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction) 
{ 
    switch(uiAction) 
    { 
        case GOSSIP_ACTION_TRADE: 
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID()); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+1: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_TABARD_OF_THE_BLOOD_KNIGHT, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+2: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_TABARD_OF_THE_HAND, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+3: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_TABARD_OF_THE_PROTECTOR, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+4: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+5: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+6: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_TABARD_OF_SUMMER_SKIES, false); 
            break; 
        case GOSSIP_ACTION_INFO_DEF+7: 
            pPlayer->CLOSE_GOSSIP_MENU(); 
            pPlayer->CastSpell(pPlayer, SPELL_TABARD_OF_SUMMER_FLAMES, false); 
            break; 
    } 
    return true; 
}

/*###### 
## npc_experience 
######*/ 

#define EXP_COST                100000//10 00 00 copper (10golds)
#define GOSSIP_TEXT_EXP         14736
#define GOSSIP_XP_OFF            "I no longer wish to gain experience."
#define GOSSIP_XP_ON           "I wish to start gaining experience again."


bool GossipHello_npc_experience(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_XP_OFF, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_XP_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_EXP, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_experience(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    bool noXPGain = pPlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
    bool doSwitch = false;

    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1://xp off
            {
                if (!noXPGain)//does gain xp
                    doSwitch = true;//switch to don't gain xp
            }
            break;
        case GOSSIP_ACTION_INFO_DEF + 2://xp on
            {
                if (noXPGain)//doesn't gain xp
                    doSwitch = true;//switch to gain xp
            }
            break;
    }
    if (doSwitch)
    {
        if (pPlayer->GetMoney() < EXP_COST)
            pPlayer->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
        else if (noXPGain)
        {
            pPlayer->ModifyMoney(-EXP_COST);
            pPlayer->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
        }
        else if (!noXPGain)
        {
            pPlayer->ModifyMoney(-EXP_COST);
            pPlayer->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
        }
    }
    pPlayer->PlayerTalkClass->CloseGossip();
    return true;
}

void AddSC_npcs_special()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_air_force_bots";
    newscript->GetAI = &GetAI_npc_air_force_bots;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lunaclaw_spirit";
    newscript->pGossipHello =  &GossipHello_npc_lunaclaw_spirit;
    newscript->pGossipSelect = &GossipSelect_npc_lunaclaw_spirit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_chicken_cluck";
    newscript->GetAI = &GetAI_npc_chicken_cluck;
    newscript->pQuestAccept =   &QuestAccept_npc_chicken_cluck;
    newscript->pQuestComplete = &QuestComplete_npc_chicken_cluck;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dancing_flames";
    newscript->GetAI = &GetAI_npc_dancing_flames;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_injured_patient";
    newscript->GetAI = &GetAI_npc_injured_patient;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_doctor";
    newscript->GetAI = &GetAI_npc_doctor;
    newscript->pQuestAccept = &QuestAccept_npc_doctor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_garments_of_quests";
    newscript->GetAI = &GetAI_npc_garments_of_quests;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_guardian";
    newscript->GetAI = &GetAI_npc_guardian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_kingdom_of_dalaran_quests";
    newscript->pGossipHello =  &GossipHello_npc_kingdom_of_dalaran_quests;
    newscript->pGossipSelect = &GossipSelect_npc_kingdom_of_dalaran_quests;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mount_vendor";
    newscript->pGossipHello =  &GossipHello_npc_mount_vendor;
    newscript->pGossipSelect = &GossipSelect_npc_mount_vendor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rogue_trainer";
    newscript->pGossipHello =  &GossipHello_npc_rogue_trainer;
    newscript->pGossipSelect = &GossipSelect_npc_rogue_trainer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_sayge";
    newscript->pGossipHello = &GossipHello_npc_sayge;
    newscript->pGossipSelect = &GossipSelect_npc_sayge;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_steam_tonk";
    newscript->GetAI = &GetAI_npc_steam_tonk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tonk_mine";
    newscript->GetAI = &GetAI_npc_tonk_mine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_winter_reveler";
    newscript->GetAI = &GetAI_npc_winter_reveler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_brewfest_reveler";
    newscript->GetAI = &GetAI_npc_winter_reveler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_snake_trap_serpents";
    newscript->GetAI = &GetAI_npc_snake_trap_serpents;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mirror_image";
    newscript->GetAI = &GetAI_npc_mirror_image;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ebon_gargoyle";
    newscript->GetAI = &GetAI_npc_ebon_gargoyle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lightwell";
    newscript->GetAI = &GetAI_npc_lightwellAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_mojo";
    newscript->GetAI = &GetAI_mob_mojo;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_training_dummy";
    newscript->GetAI = &GetAI_npc_training_dummy;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_shadowfiend";
    newscript->GetAI = &GetAI_npc_shadowfiend;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_wormhole";
    newscript->pGossipHello =  &GossipHello_npc_wormhole;
    newscript->pGossipSelect = &GossipSelect_npc_wormhole;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_pet_trainer";
    newscript->pGossipHello =  &GossipHello_npc_pet_trainer;
    newscript->pGossipSelect = &GossipSelect_npc_pet_trainer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_locksmith";
    newscript->pGossipHello =  &GossipHello_npc_locksmith;
    newscript->pGossipSelect = &GossipSelect_npc_locksmith;
    newscript->RegisterSelf();
    
    newscript = new Script; 
    newscript->Name = "npc_tabard_vendor"; 
    newscript->pGossipHello = &GossipHello_npc_tabard_vendor; 
    newscript->pGossipSelect = &GossipSelect_npc_tabard_vendor; 
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_experience";
    newscript->pGossipHello =  &GossipHello_npc_experience;
    newscript->pGossipSelect = &GossipSelect_npc_experience;
    newscript->RegisterSelf();
}

