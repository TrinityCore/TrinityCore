/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*####
## npc_drakuru_shackles
####*/

enum eDrakuruShackles
{
    SPELL_LEFT_CHAIN           = 59951,
    SPELL_RIGHT_CHAIN          = 59952,
    SPELL_UNLOCK_SHACKLE       = 55083,
    SPELL_FREE_RAGECLAW        = 55223,

    NPC_RAGECLAW               = 29686,
    QUEST_TROLLS_IS_GONE_CRAZY = 12861,
};

class npc_drakuru_shackles : public CreatureScript
{
public:
    npc_drakuru_shackles() : CreatureScript("npc_drakuru_shackles") { }

    struct npc_drakuru_shacklesAI : public ScriptedAI
    {
        npc_drakuru_shacklesAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint64 RageclawGUID;

        void Reset()
        {
            RageclawGUID = 0;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            float x, y, z;
            me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, 0.1f);

            if (Unit* summon = me->SummonCreature(NPC_RAGECLAW, x, y, z,
                0, TEMPSUMMON_DEAD_DESPAWN, 1000))
            {
                RageclawGUID = summon->GetGUID();
                LockRageclaw();
            }
        }

        void LockRageclaw()
        {
            Unit *Rageclaw = Unit::GetCreature(*me, RageclawGUID);
            // pointer check not needed
            me->SetInFront(Rageclaw);
            Rageclaw->SetInFront(me);

            DoCast(Rageclaw, SPELL_LEFT_CHAIN, true);
            DoCast(Rageclaw, SPELL_RIGHT_CHAIN, true);
        }

        void UnlockRageclaw(Unit* pWho)
        {
            if (!pWho)
                return;

            Creature *Rageclaw = Unit::GetCreature(*me, RageclawGUID);
            // pointer check not needed
            DoCast(Rageclaw, SPELL_FREE_RAGECLAW, true);

            me->setDeathState(DEAD);

        if(pWho->GetTypeId() == TYPEID_PLAYER)
            pWho->ToPlayer()->KilledMonsterCredit(NPC_RAGECLAW,RageclawGUID);
        }

        void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_UNLOCK_SHACKLE)
            {
                if (pCaster->ToPlayer()->GetQuestStatus(QUEST_TROLLS_IS_GONE_CRAZY) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* pRageclaw = Unit::GetCreature(*me, RageclawGUID))
                    {
                        UnlockRageclaw(pCaster);
                        pCaster->ToPlayer()->KilledMonster(pRageclaw->GetCreatureInfo(), RageclawGUID);
                        me->DisappearAndDie();
                    }
                    else
                        me->setDeathState(JUST_DIED);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_drakuru_shacklesAI(creature);
    }
};

/*####
## npc_captured_rageclaw
####*/

enum eRageclaw
{
    SPELL_UNSHACKLED           = 55085,
    SPELL_KNEEL                = 39656
};

const char * SAY_RAGECLAW_1 =      "I poop on you, trollses!";
const char * SAY_RAGECLAW_2 =      "ARRRROOOOGGGGAAAA!";
const char * SAY_RAGECLAW_3 =      "No more mister nice wolvar!";

#define SAY_RAGECLAW RAND(SAY_RAGECLAW_1, SAY_RAGECLAW_2, SAY_RAGECLAW_3)

class npc_captured_rageclaw : public CreatureScript
{
public:
    npc_captured_rageclaw() : CreatureScript("npc_captured_rageclaw") { }

    struct npc_captured_rageclawAI : public ScriptedAI
    {
        npc_captured_rageclawAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 DespawnTimer;
        bool Despawn;

        void Reset()
        {
            Despawn = false;
            DespawnTimer = 0;
            me->setFaction(35);
            DoCast(me, SPELL_KNEEL, true); // Little Hack for kneel - Thanks Illy :P
        }

        void MoveInLineOfSight(Unit* /*who*/){}

        void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_FREE_RAGECLAW)
            {
                me->RemoveAurasDueToSpell(SPELL_LEFT_CHAIN);

                me->RemoveAurasDueToSpell(SPELL_RIGHT_CHAIN);

                me->RemoveAurasDueToSpell(SPELL_KNEEL);

                me->setFaction(me->GetCreatureInfo()->faction_H);

                DoCast(me, SPELL_UNSHACKLED, true);
                me->MonsterSay(SAY_RAGECLAW, LANG_UNIVERSAL, 0);
                me->GetMotionMaster()->MoveRandom(10);

                DespawnTimer = 10000;
                Despawn = true;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (UpdateVictim())
            {
                DoMeleeAttackIfReady();
                return;
            }

            if (!Despawn)
                return;

            if (DespawnTimer <= uiDiff)
                me->DisappearAndDie();
            else DespawnTimer -= uiDiff;
       }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_captured_rageclawAI(creature);
    }
};

/*####
## npc_gymer
####*/

#define    GOSSIP_ITEM_G "I'm ready, Gymer. Let's go!"

enum eGymer
{
    QUEST_STORM_KING_VENGEANCE    = 12919,
    SPELL_GYMER                   = 55568
};

class npc_gymer : public CreatureScript
{
public:
    npc_gymer() : CreatureScript("npc_gymer") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_STORM_KING_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_G, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(13640, pCreature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_GYMER, true);
        }

        return true;
    }
};

/*####
## npc_gurgthock
####*/

enum eGurgthock
{
    QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON    = 12935,
    QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER  = 12936,
    QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2          = 12954,
    QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1          = 12932,
    QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR          = 12933,
    QUEST_AMPHITHEATER_ANGUISH_FROM_BEYOND        = 12934,

    NPC_ORINOKO_TUSKBREAKER                       = 30020,
    NPC_KORRAK_BLOODRAGER                         = 30023,
    NPC_YGGDRAS                                   = 30014,
    NPC_STINKBEARD                                = 30017,
    NPC_AZ_BARIN                                  = 30026, // air
    NPC_DUKE_SINGEN                               = 30019, // fire
    NPC_ERATHIUS                                  = 30025, // earth
    NPC_GARGORAL                                  = 30024, // water
    NPC_FIEND_WATER                               = 30044,
    NPC_FIEND_AIR                                 = 30045,
    NPC_FIEND_FIRE                                = 30042,
    NPC_FIEND_EARTH                               = 30043,

    SAY_QUEST_ACCEPT_TUSKARRMAGEDON               = -1571031,
    SAY_QUEST_ACCEPT_KORRAK_1                     = -1571033,
    SAY_QUEST_ACCEPT_KORRAK_2                     = -1571034,
    SAY_QUEST_ACCEPT_MAGNATAUR                    = -1571035,

    EMOTE_YGGDRAS_SPAWN                           = -1571039,
    SAY_STINKBEARD_SPAWN                          = -1571040,
    SAY_GURGTHOCK_ELEMENTAL_SPAWN                 = -1571041,

    SPELL_CRASHING_WAVE                           = 55909, // water
    SPELL_SHOCKWAVE                               = 55918, // earth
    SPELL_BLAST_OF_AIR                            = 55912, // air
    SPELL_MAGMA_WAVE                              = 55916, // fire

    SPELL_ORB_OF_WATER                             = 55888, // fiend of water spell
    SPELL_ORB_OF_STORMS                            = 55882, // fiend of air spell
    SPELL_BOULDER                                  = 55886, // fiend of earth spell
    SPELL_ORB_OF_FLAME                             = 55872, // fiend of fire spell
};

struct BossAndAdd
{
    uint32 uiBoss;
    uint32 uiAdd;
    uint32 uiSpell;
    uint32 uiAddSpell;
};

static BossAndAdd Boss[]=
{
    {NPC_GARGORAL, NPC_FIEND_WATER, SPELL_CRASHING_WAVE, SPELL_ORB_OF_WATER},
    {NPC_AZ_BARIN, NPC_FIEND_AIR, SPELL_BLAST_OF_AIR, SPELL_ORB_OF_STORMS},
    {NPC_DUKE_SINGEN, NPC_FIEND_FIRE, SPELL_MAGMA_WAVE, SPELL_ORB_OF_FLAME},
    {NPC_ERATHIUS, NPC_FIEND_EARTH, SPELL_SHOCKWAVE, SPELL_BOULDER},
};

const Position SpawnPosition[] =
{
    {5754.692f, -2939.46f, 286.276123f, 5.156380f}, // stinkbeard || orinoko || korrak
    {5762.054199f, -2954.385010f, 273.826955f, 5.108289f},  //yggdras
    {5776.855f, -2989.77979f, 272.96814f, 5.194f} // elementals
};

const Position AddSpawnPosition[] =
{
    {5722.487f, -3010.75f, 312.751648f, 0.478f}, // caster location
    {5724.983f, -2969.89551f, 286.359619f, 0.478f},
    {5733.76025f, -3000.34644f, 286.359619f, 0.478f},
    {5739.8125f, -2981.524f, 290.7671f, 0.478f}, // caster location
    {5742.101f, -2950.75586f, 286.2643f, 5.21f},
    {5743.305f, -3011.29736f, 290.7671f, 0.478f}, // caster location
    {5744.417f, -3025.528f, 286.35965f, 0.478f},
    {5763.189f, -3029.67529f, 290.7671f, 0.478f},
    {5769.401f, -2935.121f, 286.335754f, 5.21f},
    {5793.061f, -2934.593f, 286.359619f, 3.53f},
    {5797.32129f, -2955.26855f, 290.7671f, 3.53f}, // caster location
    {5813.94531f, -2956.74683f, 286.359619f, 3.53f},
    {5816.85547f, -2974.476f, 290.7671f, 3.53f}, // caster location
    {5820.30859f, -3002.83716f, 290.7671f, 3.53f}, // caster location
    {5828.50244f, -2981.737f, 286.359619f, 3.53f},
    {5828.899f, -2960.15479f, 312.751648f, 3.53f}, // caster location
};

class npc_gurgthock : public CreatureScript
{
public:
    npc_gurgthock() : CreatureScript("npc_gurgthock") { }

    struct npc_gurgthockAI : public ScriptedAI
    {
        npc_gurgthockAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint64 SummonGUID;
        uint64 uiPlayerGUID;

        uint32 uiTimer;
        uint32 uiPhase;
        uint32 uiRemoveFlagTimer;
        uint32 uiQuest;
        uint8 uiBossRandom;

        bool bRemoveFlag;

        void Reset()
        {
            SummonGUID = 0;
            uiPlayerGUID = 0;

            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            uiTimer = 0;
            uiPhase = 0;
            uiQuest = 0;
            uiRemoveFlagTimer = 5000;

            uiBossRandom = 0;

            bRemoveFlag = false;
        }

        void SetGUID(const uint64 &guid, int32 /*id*/)
        {
            uiPlayerGUID = guid;
        }

        void SetData(uint32 uiId, uint32 uiValue)
        {
            bRemoveFlag = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            switch(uiId)
            {
                case 1:
                    switch(uiValue)
                    {
                        case QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON:
                            DoScriptText(SAY_QUEST_ACCEPT_TUSKARRMAGEDON, me);
                            uiPhase = 1;
                            uiTimer = 4000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER:
                            DoScriptText(SAY_QUEST_ACCEPT_KORRAK_1, me);
                            uiPhase = 3;
                            uiTimer = 3000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2:
                        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1:
                            uiPhase = 6;
                            uiTimer = 3000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR:
                            uiTimer = 5000;
                            uiPhase = 7;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_FROM_BEYOND:
                            uiTimer = 2000;
                            uiPhase = 12;
                            break;
                   }
                        break;
                }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (bRemoveFlag)
            {
                if (uiRemoveFlagTimer <= uiDiff)
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    bRemoveFlag = false;

                    uiRemoveFlagTimer = 10000;
                } else uiRemoveFlagTimer -= uiDiff;
            }

            if (uiPhase)
            {
                Player* pPlayer = me->GetPlayer(*me, uiPlayerGUID);

                if (uiTimer <= uiDiff)
                {
                    switch(uiPhase)
                    {
                        case 1:
                            if (Creature* pSummon = me->SummonCreature(NPC_ORINOKO_TUSKBREAKER, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                SummonGUID = pSummon->GetGUID();
                            uiPhase = 2;
                            uiTimer = 4000;
                            break;
                         case 2:
                            if (Creature* pSummon = Unit::GetCreature(*me, SummonGUID))
                                pSummon->GetMotionMaster()->MoveJump(5776.319824f, -2981.005371f, 273.100037f, 10.0f, 20.0f);
                            uiPhase = 0;
                            SummonGUID = 0;
                            break;
                        case 3:
                            DoScriptText(SAY_QUEST_ACCEPT_KORRAK_2, me);
                            uiTimer = 3000;
                            uiPhase = 4;
                            break;
                        case 4:
                            if (Creature* pSummon = me->SummonCreature(NPC_KORRAK_BLOODRAGER, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                SummonGUID = pSummon->GetGUID();
                            uiTimer = 3000;
                            uiPhase = 0;
                            break;
                        case 6:
                            {
                                if (!pPlayer)
                                    return;

                                std::string sText = ("The grand Amphitheater of Anguish awaits, " + std::string(pPlayer->GetName()) + ". Remember, once a battle starts you have to stay in the area. WIN OR DIE!");

                                me->MonsterSay(sText.c_str(), LANG_UNIVERSAL, 0);
                                uiTimer = 5000;
                                uiPhase = 9;
                            }
                            break;
                        case 7:
                            {
                               if (!pPlayer)
                                   return;

                                std::string sText = ("Prepare to make you stand, " + std::string(pPlayer->GetName()) + "! Get in the Amphitheater and stand ready! Remember, you and your opponent must stay in the arena at all times or you will be disqualified!");
                                me->MonsterSay(sText.c_str(), LANG_UNIVERSAL, 0);
                                uiTimer = 3000;
                                uiPhase = 8;
                            }
                            break;
                        case 8:
                            DoScriptText(SAY_QUEST_ACCEPT_MAGNATAUR, me);
                            uiTimer = 5000;
                            uiPhase = 11;
                            break;
                        case 9:
                            {
                                if (!pPlayer)
                                    return;

                                std::string sText = ("Here we are once again, ladies and gentlemen. The epic struggle between life and death in the Amphitheater of Anguish! For this round we have " + std::string(pPlayer->GetName()) + " versus the hulking jormungar, Yg... Yggd? Yggdoze? Who comes up with these names?! " + std::string(pPlayer->GetName()) + " versus big worm!");
                                me->MonsterYell(sText.c_str(), LANG_UNIVERSAL, 0);
                                uiTimer = 10000;
                                uiPhase = 10;
                            }
                            break;
                        case 10:
                            me->SummonCreature(NPC_YGGDRAS, SpawnPosition[1], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                            DoScriptText(EMOTE_YGGDRAS_SPAWN, me);
                            uiPhase = 0;
                            break;
                        case 11:
                            if (Creature* pCreature = me->SummonCreature(NPC_STINKBEARD, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                DoScriptText(SAY_STINKBEARD_SPAWN, pCreature);
                            uiPhase = 0;
                            break;
                        case 12:
                        {
                            if (!pPlayer)
                                return;

                            std::string sText = ("Prepare to make you stand, " + std::string(pPlayer->GetName()) + "! Get in the Amphitheater and stand ready! Remember, you and your opponent must stay in the arena at all times or you will be disqualified!");
                            me->MonsterSay(sText.c_str(), LANG_UNIVERSAL, 0);
                            uiTimer = 5000;
                            uiPhase = 13;
                        }
                        break;
                        case 13:
                            DoScriptText(SAY_GURGTHOCK_ELEMENTAL_SPAWN, me);
                            uiTimer = 3000;
                            uiPhase = 14;
                            break;
                        case 14:
                            uiBossRandom = urand(0, 3);
                            if (Creature* pCreature = me->SummonCreature(Boss[uiBossRandom].uiBoss, SpawnPosition[2], TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                pCreature->AI()->SetData(1, uiBossRandom);
                            uiPhase = 0;
                            break;
                    }
                }else uiTimer -= uiDiff;
            }
        }
    };

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        switch (pQuest->GetQuestId())
        {
            case QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON:
                pCreature->AI()->SetData(1, pQuest->GetQuestId());
                break;
            case QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER:
                pCreature->AI()->SetData(1, pQuest->GetQuestId());
                break;
            case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2:
            case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1:
                pCreature->AI()->SetData(1, pQuest->GetQuestId());
                break;
            case QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR:
                pCreature->AI()->SetData(1, pQuest->GetQuestId());
                break;
            case QUEST_AMPHITHEATER_ANGUISH_FROM_BEYOND:
                pCreature->AI()->SetData(1, pQuest->GetQuestId());
                break;
        }

        pCreature->AI()->SetGUID(pPlayer->GetGUID());

        return false;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_gurgthockAI(creature);
    }
};

/*####
## npc_orinoko_tuskbreaker
####*/

enum eOrinokoTuskbreaker
{
    SPELL_BATTLE_SHOUT      = 32064,
    SPELL_FISHY_SCENT       = 55937,
    SPELL_IMPALE            = 55929,
    SPELL_SUMMON_WHISKER    = 55946,

    NPC_WHISKER             = 30113,
    NPC_HUNGRY_PENGUIN      = 30110,

    SAY_CALL_FOR_HELP       = -1571032
};

class npc_orinoko_tuskbreaker : public CreatureScript
{
public:
    npc_orinoko_tuskbreaker() : CreatureScript("npc_orinoko_tuskbreaker") { }

    struct npc_orinoko_tuskbreakerAI : public ScriptedAI
    {
        npc_orinoko_tuskbreakerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        bool bSummoned;
        bool bBattleShout;
        bool bFishyScent;

        uint32 uiBattleShoutTimer;
        uint32 uiFishyScentTimer;

        uint64 AffectedGUID;
        uint64 uiWhisker;

        void Reset()
        {
            bSummoned           = false;
            bBattleShout        = false;
            bFishyScent         = false;
            uiBattleShoutTimer  = 0;
            uiFishyScentTimer   = 20000;
            uiWhisker           = 0;
            AffectedGUID        = 0;
        }

        void EnterEvadeMode()
        {
            if (Creature *pWhisker = me->GetCreature(*me, uiWhisker))
                pWhisker->RemoveFromWorld();
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            uiBattleShoutTimer  = 7000;
        }

        void EnterCombat(Unit* pWho)
        {
            DoCast(pWho, SPELL_IMPALE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!bBattleShout && uiBattleShoutTimer <= uiDiff)
            {
                DoCast(me, SPELL_BATTLE_SHOUT);
                bBattleShout = true;
            } else uiBattleShoutTimer -= uiDiff;

            if (uiFishyScentTimer <= uiDiff)
            {
                if (Unit *pAffected = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(pAffected, SPELL_FISHY_SCENT);
                    AffectedGUID = pAffected->GetGUID();
                }
                uiFishyScentTimer = 20000;
            } else uiFishyScentTimer -= uiDiff;

            if (!bSummoned && !HealthAbovePct(50))
            {
                DoScriptText(SAY_CALL_FOR_HELP , me);
                //DoCast(me->getVictim(), SPELL_SUMMON_WHISKER); petai is not working correctly???

                if (Creature *pWhisker = me->SummonCreature(NPC_WHISKER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
                    uiWhisker = pWhisker->GetGUID();
                bSummoned = true;
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* pSummon)
        {
            switch(pSummon->GetEntry())
            {
                case NPC_WHISKER:
                    pSummon->AI()->AttackStart(me->getVictim());
                    break;
                case NPC_HUNGRY_PENGUIN:
                    if (Unit *pAffected = Unit::GetUnit(*me, AffectedGUID))
                    {
                        if (pAffected->isAlive())
                            pSummon->AI()->AttackStart(pAffected);
                    }
                    break;
            }
        }

        void JustDied(Unit* pKiller)
        {
            if (uiWhisker)
                if (Creature *pWhisker = me->GetCreature(*me, uiWhisker))
                    pWhisker->RemoveFromWorld();

            if (pKiller->GetTypeId() == TYPEID_PLAYER)
                pKiller->GetCharmerOrOwnerPlayerOrPlayerItself()->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON, pKiller);

        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_orinoko_tuskbreakerAI(creature);
    }
};

/*####
## npc_korrak_bloodrager
####*/

enum eKorrakBloodrager
{
    SPELL_GROW     = 55948,
    SPELL_CHARGE   = 24193,
    SPELL_UPPERCUT = 30471,
    SPELL_ENRAGE   = 42745
};

class npc_korrak_bloodrager : public CreatureScript
{
public:
    npc_korrak_bloodrager() : CreatureScript("npc_korrak_bloodrager") { }

    struct npc_korrak_bloodragerAI : public npc_escortAI
    {
        npc_korrak_bloodragerAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            Start(true, true, 0, NULL);
            SetDespawnAtEnd(false);
        }

        uint32 uiChargeTimer;
        uint32 uiUppercutTimer;

        bool bEnrage;

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            uiChargeTimer = 15000;
            uiUppercutTimer = 12000;
            bEnrage = false;
        }

        void WaypointReached(uint32 uiI)
        {
            switch(uiI)
            {
                case 6:
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
            }
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoCast(me, SPELL_GROW);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            if (uiUppercutTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                    DoCast(pTarget, SPELL_UPPERCUT);
                uiUppercutTimer = 12000;
            } else uiUppercutTimer -= uiDiff;

            if (uiChargeTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0))
                    DoCast(pTarget, SPELL_CHARGE);
                uiChargeTimer = 15000;
            } else uiChargeTimer -= uiDiff;

            if (!bEnrage && !HealthAbovePct(20))
            {
                DoCast(me, SPELL_ENRAGE);
                bEnrage = true;
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            if (Player* pPlayer = pKiller->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER, pKiller);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_korrak_bloodragerAI(creature);
    }
};

/*####
## npc_yggdras
####*/

enum eYggdras
{
    SPELL_CLEAVE            = 40504,
    SPELL_CORRODE_FLESH     = 57076,
    SPELL_JORMUNGAR_SPAWN   = 55859
};

class npc_yggdras : public CreatureScript
{
public:
    npc_yggdras() : CreatureScript("npc_yggdras") { }

    struct npc_yggdrasAI : public ScriptedAI
    {
        npc_yggdrasAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiCleaveTimer;
        uint32 uiCorrodeFleshTimer;

        void Reset()
        {
            uiCleaveTimer = 9000;
            uiCorrodeFleshTimer = 6000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (me->getVictim()->GetPositionZ() >= 286.276f)
            {
                std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    if (Unit* pUnit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        if (pUnit->GetPositionZ() <= 286.276f)
                        {
                            me->getThreatManager().resetAllAggro();
                            me->AddThreat(pUnit, 5.0f);
                            break;
                        }
                        EnterEvadeMode();
                    }
                }
            }

            if (uiCleaveTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                uiCleaveTimer = 9000;
            } else uiCleaveTimer -= uiDiff;

            if (uiCorrodeFleshTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_CORRODE_FLESH);
                uiCorrodeFleshTimer = 6000;
            } else uiCorrodeFleshTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
            {
                std::string sText = (std::string(pKiller->GetName()) + " has defeated Yg.. Yggg-really big worm!");
                pSummoner->MonsterYell(sText.c_str(), LANG_UNIVERSAL, 0);
            }

            if (Player* pPlayer = pKiller->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                pPlayer->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1, pKiller);
                pPlayer->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2, pKiller);
            }

            for (uint8 i = 0; i < 3; ++i)
                DoCast(pKiller, SPELL_JORMUNGAR_SPAWN, true);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_yggdrasAI(creature);
    }
};

/*####
## npc_stinkbeard
####*/

enum eStinkbeard
{
    SPELL_ENRAGE_STINKBEARD = 50420,
    SPELL_KNOCK_AWAY        = 31389,
    SPELL_STINKY_BEARD      = 55867,
    SPELL_THUNDERBLADE      = 55866,
    SPELL_THUNDERCLAP       = 15588
};

class npc_stinkbeard : public CreatureScript
{
public:
    npc_stinkbeard() : CreatureScript("npc_stinkbeard") { }

    struct npc_stinkbeardAI : public npc_escortAI
    {
        npc_stinkbeardAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            Start(true, true, 0, NULL);
            SetDespawnAtEnd(false);
        }

        uint32 uiKnockAwayTimer;
        uint32 uiStinkyBeardTimer;

        bool bEnrage;
        bool bThunderClap;

        void Reset()
        {
            me->AddAura(SPELL_THUNDERBLADE, me);
            uiKnockAwayTimer   = 10000;
            uiStinkyBeardTimer = 15000;
            bEnrage = false;
            bThunderClap = false;
        }

        void WaypointReached(uint32 uiI)
        {
            switch(uiI)
            {
                case 7:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            if (Unit* victim = me->getVictim())
            {
                if (victim->GetPositionZ() >= 286.276f)
                {
                    std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                    for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                    {
                        if (Unit* pUnit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                        {
                            if (pUnit->GetPositionZ() <= 286.276f)
                            {
                                me->getThreatManager().resetAllAggro();
                                me->AddThreat(pUnit, 5.0f);
                                break;
                            }
                            EnterEvadeMode();
                        }
                    }
                }
            }

            if (bThunderClap && !HealthAbovePct(10))
            {
                DoCastAOE(SPELL_THUNDERCLAP);
                bThunderClap = true;
            }

            if (uiKnockAwayTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget, SPELL_KNOCK_AWAY);
                }
                uiKnockAwayTimer = 10000;
            } else uiKnockAwayTimer -= uiDiff;

            if (uiStinkyBeardTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (pTarget && pTarget->isAlive())
                        DoCast(pTarget, SPELL_STINKY_BEARD);
                }
                uiStinkyBeardTimer = 15000;
            } else uiStinkyBeardTimer -= uiDiff;

            if (!bEnrage && !HealthAbovePct(20))
            {
                DoCast(me, SPELL_ENRAGE_STINKBEARD);
                bEnrage = true;
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            if (Player* pPlayer = pKiller->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->GetCharmerOrOwnerPlayerOrPlayerItself()->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR, pKiller);

            std::string sText = ("And with AUTHORITY, " + std::string(pKiller->GetName()) + " dominates the magnataur lord! Stinkbeard's clan is gonna miss him back home in the Dragonblight!");
            me->MonsterYell(sText.c_str(), LANG_UNIVERSAL, 0);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_stinkbeardAI(creature);
    }
};

/*####
## npc_elemental_lord
####*/

class npc_elemental_lord : public CreatureScript
{
public:
    npc_elemental_lord() : CreatureScript("npc_elemental_lord") { }

    struct npc_elemental_lordAI : public ScriptedAI
    {
        npc_elemental_lordAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        std::list<uint64> SummonList;

        uint32 uiElementalSpellTimer;

        uint8 uiBossRandom;
        uint32 uiSpellEntry;

        bool bAddAttack;

        void Reset()
        {
            uiBossRandom = 0;
            uiSpellEntry = 0;
            uiElementalSpellTimer = urand(5000, 8000);

            bAddAttack = false;
        }

        void SetData(uint32 uiData, uint32 uiValue)
        {
            if (uiData == 1)
            {
                uiBossRandom = uiValue;
                SummonAdds();
            }
        }

        void SummonAdds()
        {
            if (!Boss[uiBossRandom].uiAdd)
                return;

            SummonList.clear();

            for (uint8 uiI = 0; uiI < 16 ; uiI++)
            {
                if (Creature* pSummon = me->SummonCreature(Boss[uiBossRandom].uiAdd, AddSpawnPosition[uiI]))
                {
                    pSummon->AI()->SetData(1, uiBossRandom);
                    SummonList.push_back(pSummon->GetGUID());
                }
            }

        }

        void EnterCombat(Unit* pUnit)
        {
            if (!SummonList.empty())
                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                    {
                        pTemp->m_CombatDistance = 100.0f; // ugly hack? we are not in a instance sorry. :(
                        pTemp->AI()->AttackStart(pUnit);
                    }
                }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (me->getVictim()->GetPositionZ() >= 286.276f)
            {
                std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    if (Unit* pUnit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        if (pUnit->GetPositionZ() <= 286.276f)
                        {
                            me->getThreatManager().resetAllAggro();
                            me->AddThreat(pUnit, 5.0f);
                            break;
                        }
                        EnterEvadeMode();
                    }
                }
            }

            if (uiElementalSpellTimer <= uiDiff)
            {
                DoCastVictim(Boss[uiBossRandom].uiSpell);

                uiElementalSpellTimer = urand(5000, 8000);
            } else uiElementalSpellTimer -= uiDiff;

            if (!bAddAttack && !HealthAbovePct(20))
            {
                if (!SummonList.empty())
                    for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                    {
                        if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                        {
                            if (pTemp->GetPositionZ() >= 287.00f)
                                continue;

                            if (pTemp->getVictim())
                                pTemp->GetMotionMaster()->MoveChase(pTemp->getVictim());
                        }
                    }

                bAddAttack = true;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            if (!SummonList.empty())
                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                    if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                        pTemp->DespawnOrUnsummon();

            if (Player* pPlayer = pKiller->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->GetCharmerOrOwnerPlayerOrPlayerItself()->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_FROM_BEYOND, pKiller);

            std::string sText = (std::string(pKiller->GetName()) + " is victorious once more!");

            if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                pSummoner->MonsterYell(sText.c_str(), LANG_UNIVERSAL, 0);
        }
    };

    CreatureAI *GetAI(Creature* creature) const
    {
        return new npc_elemental_lordAI(creature);
    }
};

/*####
## npc_fiend_elemental
####*/

class npc_fiend_elemental : public CreatureScript
{
public:
    npc_fiend_elemental() : CreatureScript("npc_fiend_elemental") { }

    struct npc_fiend_elementalAI : public ScriptedAI
    {
        npc_fiend_elementalAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiMissleTimer;
        uint32 uiSpell;

        void Reset()
        {
            if (me->GetPositionZ() >= 287.0f)
                me->GetMotionMaster()->MoveIdle();

            uiSpell = 0;
            uiMissleTimer = urand(2000, 7000);
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            AttackStartNoMove(pWho);
        }

        void SetData(uint32 uiData, uint32 uiValue)
        {
            if (uiData == 1)
                uiSpell = Boss[uiValue].uiAddSpell;

        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (me->GetPositionZ() >= 287.0f)
            {
                if (uiMissleTimer <= uiDiff)
                {
                    DoCast(me, uiSpell); // this spell is not supported ... YET!
                    uiMissleTimer = urand(2000, 7000);

                } else uiMissleTimer -= uiDiff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_fiend_elementalAI(creature);
    }
};

/*####
## npc_released_offspring_harkoa
####*/

class npc_released_offspring_harkoa : public CreatureScript
{
public:
    npc_released_offspring_harkoa() : CreatureScript("npc_released_offspring_harkoa") { }

    struct npc_released_offspring_harkoaAI : public ScriptedAI
    {
        npc_released_offspring_harkoaAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        void Reset()
        {
            float x, y, z;
            me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, 25.0f);
            me->GetMotionMaster()->MovePoint(0, x, y, z);
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;
            me->DisappearAndDie();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_released_offspring_harkoaAI(creature);
    }
};

/*######
## npc_crusade_recruit
######*/

enum eCrusade_recruit
{
    SPELL_QUEST_CREDIT                            = 50633,

    QUEST_TROLL_PATROL_INTESTINAL_FORTITUDE       = 12509,

    GOSSIP_CRUSADE_TEXT                           = 13069,

    SAY_RECRUIT_1                                 = -1571036,
    SAY_RECRUIT_2                                 = -1571037,
    SAY_RECRUIT_3                                 = -1571038
};

#define GOSSIP_ITEM_1 "Get out there and make those Scourge wish they were never reborn!"

class npc_crusade_recruit : public CreatureScript
{
public:
    npc_crusade_recruit() : CreatureScript("npc_crusade_recruit") { }

    struct npc_crusade_recruitAI : public ScriptedAI
    {
        npc_crusade_recruitAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint8 m_uiPhase;                  //The current phase we are in
        uint32 m_uiTimer;                 //Timer until phase transition
        float m_heading;                  //Store creature heading

        void Reset()
        {
            m_uiTimer = 0;
            m_uiPhase = 0;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
            m_heading = me->GetOrientation();
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiPhase)
            {
                if (m_uiTimer <= uiDiff)
                {
                    switch(m_uiPhase)
                    {
                        case 1:
                            // say random text
                            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            DoScriptText(RAND(SAY_RECRUIT_1, SAY_RECRUIT_2, SAY_RECRUIT_3), me);
                            m_uiTimer = 3000;
                            m_uiPhase = 2;
                            break;
                        case 2:
                            // walk forward
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (cos(m_heading) * 10), me->GetPositionY() + (sin(m_heading) * 10), me->GetPositionZ());
                            m_uiTimer = 5000;
                            m_uiPhase = 3;
                            break;
                        case 3:
                            // despawn
                            me->DisappearAndDie();
                            m_uiTimer = 0;
                            m_uiPhase = 0;
                            break;
                    }
                }
                else
                m_uiTimer -= uiDiff;
            }
            ScriptedAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_TROLL_PATROL_INTESTINAL_FORTITUDE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_CRUSADE_TEXT, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->CastSpell(pPlayer, SPELL_QUEST_CREDIT, true);
            CAST_AI(npc_crusade_recruit::npc_crusade_recruitAI, (pCreature->AI()))->m_uiPhase = 1;
            pCreature->SetInFront(pPlayer);
            pCreature->SendMovementFlagUpdate();
        }

        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_crusade_recruitAI(creature);
    }

};

/*######
## npc_captain_brandon_zu
######*/

#define QUEST_SOMETHING_FOR_THE_PAIN                12597
#define QUEST_CAN_YOU_DIG_IT                        12588
#define QUEST_HIGH_STANDARDS                        12502
#define QUEST_D_SOMETHING_FOR_THE_PAIN              12564

#define TROLL_PATROL_KILL_CREDIT                    28042

class npc_captain_brandon_zu : public CreatureScript
{
public:
    npc_captain_brandon_zu() : CreatureScript("npc_captain_brandon_zu") { }

    bool OnQuestReward(Player *player, Creature *_Creature, Quest const *_Quest, uint32 /*item*/)
    {
        switch(_Quest->GetQuestId())
        {
        case QUEST_SOMETHING_FOR_THE_PAIN:
        case QUEST_CAN_YOU_DIG_IT:
        case QUEST_HIGH_STANDARDS:
        case QUEST_D_SOMETHING_FOR_THE_PAIN:
            player->KilledMonsterCredit(TROLL_PATROL_KILL_CREDIT,_Creature->GetGUID());
            break;
        }
        return true;
    }

};

/*######
## npc_alchemist_finklestein
######*/

#define GOSSIP_START                                "I'm ready to begin. What is the first Ingredient you require?"
#define QUEST_TROLL_PATROL_ALCHEMIST_APPRENTICE     12541
#define ENTRY_ALCHEMIST_CREDIT                      28248
#define SPELL_THROW_INGREDIENT                      51025

static const char * Intro_sayings[6] =
{
    "Quickly, get me some...",
    "Find me some...",
    "I think it needs...",
    "Alright, now fetch me some...",
    "Before it thickens, we must add...",
    "It's thickening! Quickly, get some...",
};
static const char * Ingredients[] =
{
      "Hairy Herring Heads",
      "Icecrown Bottled Water",
      "Knotroot",
      "Muddy Mire Maggots",
      "Pickled Eagle Egg",
      "Pulverized Gargoyle Teeth",
      "Putrid Pirate Perspiration",
      "Seasoned Slider Cider",
      "Speckled Guano",
      "Spiky Spider Eggs",
      "Withered Batwing",

      "Prismatic Mojo",
      "Raptor Claw",
      "Amberseed",
      //"Ancient Ectoplasm",
      "Shrunken Dragon's Claw",
      "Wasp's Wings",

      "Abomination Guts",
      "Blight Crystal",
      "Chilled Serpent Mucus",
      "Crushed Basilisk Crystals",
      "Frozen Spider Ichor",
      "Crystallized Hogsnot",
      "Ghoul Drool",
      "Trollbane"
};
/*
(190480,190482,190466,190478,190467,190477,190481,190476,190470,190479,190473,190468,
190469,190459,190464,190472,191180,191182,190462,190474,190465,190463,191181,190471)
*/
//1te Spell ist Debuff Castet von Finklestone *Fetch*
//2te Spell ist eine unsichtbarer Spell vom gelootet Item (?) *Have*
static const uint32 Ingredients_Spells[24][3] =
{
    {51072,51075,38396},//Hairy Herring Heads
    {51079,51080,38398},//Icecrown Bottled Water
    {51018,51047,38338},//Knotroot
    {51067,51068,38386},//Muddy Mire Maggots
    {51055,51056,38341},//Pickled Eagle Egg
    {51064,51065,38384},//Pulverized Gargoyle Teeth
    {51077,51078,38397},//Putrid Pirate Perspiration
    {51062,51063,38381},//Seasoned Cider Slider
    {51057,51058,38337},//Speckled Guano
    {51069,51070,38393},//Spiky Spider Eggs
    {51059,51060,38339},//Withered Batwing

    {51083,51084,38343},//Prismatic Mojo
    {51085,51086,38370},//Raptor Claw
    {51087,51088,38340},//Amberseed
    //{51089,51090,38335},//Ancient Ectoplasm //Nicht benutzt
    {51091,51092,38344},//Shrunken Dragon's Claw
    {51081,51082,38369},//Wasp's Wings

    {53150,53147,39668},//Abomination Guts
    {53158,53149,39670},//Blight Crystal
    {51093,51094,38346},//Chilled Serpent Mucus
    {51097,51098,38379},//Crushed Basilisk Crystals
    {51102,51104,38345},//Frozen Spider Ichor
    {51095,51096,38336},//Crystallized Hogsnot
    {53153,53146,39669},//Ghoul Drool
    {51100,51101,38342} //Trollbane
};

class npc_alchemist_finklestein : public CreatureScript
{
public:
    npc_alchemist_finklestein() : CreatureScript("npc_alchemist_finklestein") { }

    struct npc_alchemist_finklesteinAI : public ScriptedAI
    {
        npc_alchemist_finklesteinAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint8 m_uiPhase;                  //The current phase we are in
        uint32 m_uiTimer;                 //Timer until phase transition
        uint64 StarterGUID;
        uint32 Next_Incedient;
    
        bool hasFound;
        bool shortbreak;

        void Reset()
        {
            m_uiTimer = 0;
            m_uiPhase = 0;
            Next_Incedient = 999;
            hasFound = false;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void StartTruthSerum(Player* pStarter)
        {
            if(!pStarter)
                return;

            hasFound = true;
            shortbreak = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            StarterGUID = pStarter->GetGUID();
            m_uiPhase = 1;
        }

        void Next_Phase()
        {
            if(!hasFound)
            {
                if(Player *pPlayer = Unit::GetPlayer(*me,StarterGUID))
                {
                    //pPlayer->CastSpell(me,SPELL_THROW_INGREDIENT,false);
                    pPlayer->RemoveAurasDueToSpell(Ingredients_Spells[Next_Incedient][0]);
                    hasFound = true;
                    m_uiTimer = 2000;
                    shortbreak = true;
                    m_uiPhase++;

                    if(m_uiPhase > 6)
                    {
                        pPlayer->KilledMonsterCredit(ENTRY_ALCHEMIST_CREDIT,me->GetGUID());
                        pPlayer->CompleteQuest(QUEST_TROLL_PATROL_ALCHEMIST_APPRENTICE);
                        EnterEvadeMode();
                        return;
                    }
                }
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(hasFound)
                return;

            if(who->GetTypeId() == TYPEID_PLAYER && who->ToPlayer()->GetGUID() == StarterGUID && me->IsWithinDist(who,5))
            {
                if(who->ToPlayer()->HasItemCount(Ingredients_Spells[Next_Incedient][2],1))
                {
                    Next_Phase();
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiPhase)
            {
                if(Player* pPlayer = Unit::GetPlayer(*me,StarterGUID))
                {
                    if(pPlayer->isDead() || pPlayer->GetDistance2d(me) > 200)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    if (m_uiTimer <= uiDiff)
                    {
                        if(shortbreak)
                        {
                            if(!hasFound)
                            {
                                pPlayer->FailQuest(QUEST_TROLL_PATROL_ALCHEMIST_APPRENTICE);
                                EnterEvadeMode();
                                return;
                            }else
                            {
                                me->MonsterTextEmote(Intro_sayings[m_uiPhase-1],StarterGUID,true);
                                shortbreak = false;
                                m_uiTimer = 2000;
                            }
                        }else
                        {
                            uint32 New_Incedient;
                            switch(m_uiPhase)
                            {
                                case 1:
                                case 2:
                                case 3:
                                    do
                                    {
                                        New_Incedient = urand(0,10);
                                    }while (New_Incedient == Next_Incedient);
                                    Next_Incedient = New_Incedient;
                                    break;
                                case 4:
                                case 5:
                                    do
                                    {
                                        New_Incedient = urand(11,15);
                                    }while (New_Incedient == Next_Incedient);
                                    Next_Incedient = New_Incedient;
                                    break;
                                case 6:
                                    Next_Incedient = urand(16,23);
                                    break;
                            }
                            me->MonsterTextEmote(Ingredients[Next_Incedient],StarterGUID,true);
                            if(Player* pPlayer = Unit::GetPlayer(*me,StarterGUID))
                                me->CastSpell(pPlayer,Ingredients_Spells[Next_Incedient][0],true);

                            shortbreak = true;
                            hasFound = false;
                            m_uiTimer = 45000;
                        }
                    }
                    else m_uiTimer -= uiDiff;
                }else 
                {
                    EnterEvadeMode();
                    return;
                }
            }
            //ScriptedAI::UpdateAI(uiDiff);

            //if (!UpdateVictim())
            //    return;
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_alchemist_finklesteinAI, (pCreature->AI()))->StartTruthSerum(pPlayer);
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());


        if (CAST_AI(npc_alchemist_finklesteinAI, (pCreature->AI()))->m_uiPhase == 0 && pPlayer->GetQuestStatus(QUEST_TROLL_PATROL_ALCHEMIST_APPRENTICE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_alchemist_finklesteinAI (pCreature);
    }

};

/*######
## npc_argent_soldier_12504
######*/

#define GOSSIP_LEAVING                      "Soldier, you have new orders. You're to pull back and report to the sergeant!"
#define QUEST_WE_ARE_LEAVING                12504
#define ENTRY_ARGENT_SOLDIER_CREDIT         28041

#define SPELL_ARGENT_SUNDER_ARMOR           50370

class npc_argent_soldier_12504 : public CreatureScript
{
public:
    npc_argent_soldier_12504() : CreatureScript("npc_argent_soldier_12504") { }

    struct npc_argent_soldier_12504AI : public ScriptedAI
    {
        npc_argent_soldier_12504AI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 m_uiTimer;
        uint32 sunder_Timer;

        void Reset()
        {
            m_uiTimer = 10000;
            sunder_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            {
                if(m_uiTimer <= diff)
                {
                    me->DealDamage(me, me->GetHealth());
                    m_uiTimer = 30000;
                }else m_uiTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if( sunder_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_ARGENT_SUNDER_ARMOR);
                sunder_Timer = urand(10000,15000);
            }else sunder_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
        {
            pPlayer->KilledMonsterCredit(ENTRY_ARGENT_SOLDIER_CREDIT,pCreature->GetGUID());
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_WE_ARE_LEAVING) == QUEST_STATUS_INCOMPLETE && !pCreature->isInCombat())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LEAVING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_argent_soldier_12504AI (pCreature);
    }

};

/*######
## Quest 12916: Our Only Hope!
## go_scourge_enclosure
######*/

enum eScourgeEnclosure
{
    QUEST_OUR_ONLY_HOPE                           = 12916,
    NPC_GYMER_DUMMY                               = 29928   //from quest template
};

class go_scourge_enclosure : public GameObjectScript
{
public:
    go_scourge_enclosure() : GameObjectScript("go_scourge_enclosure") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGO)
    {
        if (pPlayer->GetQuestStatus(QUEST_OUR_ONLY_HOPE) == QUEST_STATUS_INCOMPLETE)
        {
            Creature* pGymerDummy = pGO->FindNearestCreature(NPC_GYMER_DUMMY, 20.0f);
            if (pGymerDummy)
            {
                pGO->UseDoorOrButton();
                pPlayer->KilledMonsterCredit(pGymerDummy->GetEntry(), pGymerDummy->GetGUID());
                pGymerDummy->CastSpell(pGymerDummy, 55529, true);
                pGymerDummy->DisappearAndDie();
            }
        }
        return true;
    }
};


/*######
## npc_bloodrose_datura
######*/

//TODO DB-Eintraege erstellen
#define GOSSIP_BLOODROSE                 "Stefan told me you would demonstrate the purpose of this item."
#define TEXT1                            "Indeed. Watch this, $R."
#define TEXT2                            "Here, troll... a gift!"
#define TEXT3                            "For me? Really, mon?"
#define TEXT4                            "It....it be beautiful!"
#define TEXT5                            "Ugh... disgusting!"

#define QUEST_NEAR_MISS                  12637
#define QUEST_CLOSE_CALL                 12638
#define NPC_CAPTURED_DRAKKARI_SCOUT      28541
#define NPC_WITHERED_TROLL               28519
#define ENTRY_BLOODROSE_CREDIT           28532

class npc_bloodrose_datura : public CreatureScript
{
public:
    npc_bloodrose_datura() : CreatureScript("npc_bloodrose_datura") { }

    struct npc_bloodrose_daturaAI : public ScriptedAI
    {
        npc_bloodrose_daturaAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiTimer;
        uint8 uiStep;
        bool stepping;

        void Reset()
        {
            stepping = false;
            uiTimer = 0;
            uiStep = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (stepping)
            {
                if (uiTimer < uiDiff)
                {
                    Creature* pScout = me->FindNearestCreature(NPC_CAPTURED_DRAKKARI_SCOUT, 10.0f);
                    Creature* pTroll = me->FindNearestCreature(NPC_WITHERED_TROLL, 2.0f);

                    if (pScout || pTroll)
                    {
                        switch (uiStep)
                        {
                            case 1:
                                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                me->GetMotionMaster()->MovePoint(0, 5203.73f, -1317.08f, 242.767f);
                                uiTimer = 3000;
                                uiStep = 2;
                                break;
                            case 2:
                                pScout->UpdateEntry(NPC_WITHERED_TROLL);
                                uiTimer = 5000;
                                uiStep = 3;
                                break;
                            case 3:
                                me->DealDamage(pTroll, pTroll->GetMaxHealth());
                                me->GetMotionMaster()->MoveTargetedHome();
                                stepping = false;
                                uiStep = 0;
                                break;
                        }
                    } else Reset();

                } else uiTimer -= uiDiff;
            }
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if ((pPlayer->GetQuestStatus(QUEST_NEAR_MISS) == QUEST_STATUS_INCOMPLETE) || (pPlayer->GetQuestStatus(QUEST_CLOSE_CALL) == QUEST_STATUS_INCOMPLETE))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BLOODROSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        else
            pPlayer->SEND_GOSSIP_MENU(13289, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        npc_bloodrose_daturaAI* pAI = CAST_AI(npc_bloodrose_datura::npc_bloodrose_daturaAI, pCreature->AI());

        if (!pAI)
            return false;

        if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->KilledMonsterCredit(ENTRY_BLOODROSE_CREDIT, pCreature->GetGUID());
         
            pAI->stepping = true;
            pAI->uiStep = 1;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_bloodrose_daturaAI (pCreature);
    }
};

/*####
## npc_nass
####*/

enum eNass
{
    SPELL_KICK_NASS            = 51866,
    SPELL_NASS_KILL_CREDIT     = 51871,
    ENTRY_WITHERED_TROLL       = 28519
};

class npc_nass : public CreatureScript
{
public:
    npc_nass() : CreatureScript("npc_nass") { }

    struct npc_nassAI : public ScriptedAI
    {
        npc_nassAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint64 uiTrollGUID;
        bool collecting;

        void Reset()
        {
            uiTrollGUID = 0;
            collecting = false;
        }

        void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_KICK_NASS)
            {
                if (Creature* pTroll = me->FindNearestCreature(ENTRY_WITHERED_TROLL, 20.0f, false))
                {
                    if (!collecting && pTroll->getDeathState() == CORPSE)
                    {
                        collecting = true;
                        uiTrollGUID = pTroll->GetGUID();
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MovePoint(1, pTroll->GetPositionX(), pTroll->GetPositionY(), pTroll->GetPositionZ());
                    }
                }
            }
        }

        void MovementInform(uint32 uiType, uint32 uiId)
        {
            if (uiType != POINT_MOTION_TYPE || uiId != 1)
                return;

            Creature* pTroll = me->GetCreature(*me, uiTrollGUID);
            Player* pOwner = me->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!pOwner)
                return;

            if (pTroll)
            {
                pTroll->RemoveCorpse();
                DoCast(pOwner, SPELL_NASS_KILL_CREDIT);
            }

            me->GetMotionMaster()->MoveFollow(pOwner, 0.0f, 0.0f);
            collecting = false;
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_nassAI(creature);
    }
};

/*######
## npc_commander_kunz
######*/
enum eCommanderKunz
{
    QUEST_PATROLL     = 12596,
    QUEST_RUPERT_A    = 12598,
    QUEST_RUPERT_B    = 12606,
    SPELL_RUPERT      = 50634,
    QUEST_GRONDEL     = 12599,
    SPELL_GRONDEL     = 51233,
    QUEST_FINKLESTEIN = 12557,
    SPELL_FINKLESTEIN = 51232,
    QUEST_BRANDON     = 12597,
    CREDIT_BRANDON    = 28042
};

class npc_commander_kunz : public CreatureScript
{
public:
    npc_commander_kunz() : CreatureScript("npc_commander_kunz") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_PATROLL)
        {
            if (player->GetQuestRewardStatus(QUEST_RUPERT_A) || player->GetQuestRewardStatus(QUEST_RUPERT_B))
                creature->CastSpell(player, SPELL_RUPERT, true);
            if (player->GetQuestRewardStatus(QUEST_GRONDEL))
                creature->CastSpell(player, SPELL_GRONDEL, true);
            if (player->GetQuestRewardStatus(QUEST_FINKLESTEIN))
                creature->CastSpell(player, SPELL_FINKLESTEIN, true);
            if (player->GetQuestRewardStatus(QUEST_BRANDON))
                player->KilledMonsterCredit(CREDIT_BRANDON, 0);
        }

        return true;
    }
};

void AddSC_zuldrak()
{
    new npc_drakuru_shackles();
    new npc_captured_rageclaw();
    new npc_gymer();
    new npc_gurgthock();
    new npc_orinoko_tuskbreaker();
    new npc_korrak_bloodrager();
    new npc_yggdras();
    new npc_stinkbeard();
    new npc_released_offspring_harkoa();
    new npc_crusade_recruit();
    new npc_elemental_lord();
    new npc_fiend_elemental();
    new npc_captain_brandon_zu();
    new npc_alchemist_finklestein();
    new npc_argent_soldier_12504();
    new go_scourge_enclosure();
    new npc_bloodrose_datura();
    new npc_nass();
    new npc_commander_kunz();
}
