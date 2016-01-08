/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Shadowmoon_Valley
SD%Complete: 100
SDComment: Quest support: 10583, 10601, 10804, 10854, 10458, 10481, 10480, 10781, 10451. Vendor Drake Dealer Hurlunk.
SDCategory: Shadowmoon Valley
EndScriptData */

/* ContentData
npc_invis_infernal_caster
npc_infernal_attacker
npc_mature_netherwing_drake
npc_enslaved_netherwing_drake
npc_drake_dealer_hurlunk
npcs_flanis_swiftwing_and_kagrosh
npc_karynaku
npc_earthmender_wilda
npc_torloth_the_magnificent
npc_illidari_spawn
npc_lord_illidan_stormrage
go_crystal_prison
npc_enraged_spirit
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Group.h"
#include "SpellScript.h"
#include "Player.h"
#include "WorldSession.h"

/*#####
# npc_invis_infernal_caster
#####*/

enum InvisInfernalCaster
{
    EVENT_CAST_SUMMON_INFERNAL = 1,
    NPC_INFERNAL_ATTACKER      = 21419,
    MODEL_INVISIBLE            = 20577,
    MODEL_INFERNAL             = 17312,
    SPELL_SUMMON_INFERNAL      = 37277,
    TYPE_INFERNAL              = 1,
    DATA_DIED                  = 1
};

class npc_invis_infernal_caster : public CreatureScript
{
public:
    npc_invis_infernal_caster() : CreatureScript("npc_invis_infernal_caster") { }

    struct npc_invis_infernal_casterAI : public ScriptedAI
    {
        npc_invis_infernal_casterAI(Creature* creature) : ScriptedAI(creature)
        {
            ground = 0.f;
        }

        void Reset() override
        {
            ground = me->GetMap()->GetHeight(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
            SummonInfernal();
            events.ScheduleEvent(EVENT_CAST_SUMMON_INFERNAL, urand(1000, 3000));
        }

        void SetData(uint32 id, uint32 data) override
        {
            if (id == TYPE_INFERNAL && data == DATA_DIED)
                SummonInfernal();
        }

        void SummonInfernal()
        {
            Creature* infernal = me->SummonCreature(NPC_INFERNAL_ATTACKER, me->GetPositionX(), me->GetPositionY(), ground + 0.05f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
            infernalGUID = infernal->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_SUMMON_INFERNAL:
                {
                    if (Unit* infernal = ObjectAccessor::GetUnit(*me, infernalGUID))
                        if (infernal->GetDisplayId() == MODEL_INVISIBLE)
                            me->CastSpell(infernal, SPELL_SUMMON_INFERNAL, true);
                    events.ScheduleEvent(EVENT_CAST_SUMMON_INFERNAL, 12000);
                    break;
                }
                default:
                    break;
                }
            }
        }

    private:
        EventMap events;
        ObjectGuid infernalGUID;
        float ground;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invis_infernal_casterAI(creature);
    }
};

/*#####
# npc_infernal_attacker
#####*/

class npc_infernal_attacker : public CreatureScript
{
public:
    npc_infernal_attacker() : CreatureScript("npc_infernal_attacker") { }

    struct npc_infernal_attackerAI : public ScriptedAI
    {
        npc_infernal_attackerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetDisplayId(MODEL_INVISIBLE);
            me->GetMotionMaster()->MoveRandom(5.0f);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->ToCreature())
                casterGUID = summoner->ToCreature()->GetGUID();;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* caster = ObjectAccessor::GetCreature(*me, casterGUID))
                caster->AI()->SetData(TYPE_INFERNAL, DATA_DIED);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_SUMMON_INFERNAL)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_PACIFIED | UNIT_FLAG_NOT_SELECTABLE);
                me->SetDisplayId(MODEL_INFERNAL);
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        ObjectGuid casterGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_infernal_attackerAI(creature);
    }
};

/*#####
# npc_mature_netherwing_drake
#####*/

enum MatureNetherwing
{
    SAY_JUST_EATEN              = 0,

    SPELL_PLACE_CARCASS         = 38439,
    SPELL_JUST_EATEN            = 38502,
    SPELL_NETHER_BREATH         = 38467,
    POINT_ID                    = 1,

    GO_CARCASS                  = 185155,

    QUEST_KINDNESS              = 10804,
    NPC_EVENT_PINGER            = 22131
};

class npc_mature_netherwing_drake : public CreatureScript
{
public:
    npc_mature_netherwing_drake() : CreatureScript("npc_mature_netherwing_drake") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mature_netherwing_drakeAI(creature);
    }

    struct npc_mature_netherwing_drakeAI : public ScriptedAI
    {
        npc_mature_netherwing_drakeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiPlayerGUID.Clear();

            bCanEat = false;
            bIsEating = false;

            EatTimer = 5000;
            CastTimer = 5000;
        }

        ObjectGuid uiPlayerGUID;

        bool bCanEat;
        bool bIsEating;

        uint32 EatTimer;
        uint32 CastTimer;

        void Reset() override
        {
            Initialize();
        }

        void SpellHit(Unit* pCaster, SpellInfo const* spell) override
        {
            if (bCanEat || bIsEating)
                return;

            if (pCaster->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_PLACE_CARCASS && !me->HasAura(SPELL_JUST_EATEN))
            {
                uiPlayerGUID = pCaster->GetGUID();
                bCanEat = true;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == POINT_ID)
            {
                bIsEating = true;
                EatTimer = 7000;
                me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (bCanEat || bIsEating)
            {
                if (EatTimer <= diff)
                {
                    if (bCanEat && !bIsEating)
                    {
                        if (Unit* unit = ObjectAccessor::GetUnit(*me, uiPlayerGUID))
                        {
                            if (GameObject* go = unit->FindNearestGameObject(GO_CARCASS, 10))
                            {
                                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                                    me->GetMotionMaster()->MovementExpired();

                                me->GetMotionMaster()->MoveIdle();
                                me->StopMoving();

                                me->GetMotionMaster()->MovePoint(POINT_ID, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ());
                            }
                        }
                        bCanEat = false;
                    }
                    else if (bIsEating)
                    {
                        DoCast(me, SPELL_JUST_EATEN);
                        Talk(SAY_JUST_EATEN);

                        if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                        {
                            player->KilledMonsterCredit(NPC_EVENT_PINGER);

                            if (GameObject* go = player->FindNearestGameObject(GO_CARCASS, 10))
                                go->Delete();
                        }

                        Reset();
                        me->GetMotionMaster()->Clear();
                    }
                }
                else
                    EatTimer -= diff;

            return;
            }

            if (!UpdateVictim())
                return;

            if (CastTimer <= diff)
            {
                DoCastVictim(SPELL_NETHER_BREATH);
                CastTimer = 5000;
            } else CastTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

/*###
# npc_enslaved_netherwing_drake
####*/

enum EnshlavedNetherwingDrake
{
    // Factions
    FACTION_DEFAULT                 = 62,
    FACTION_FRIENDLY                = 1840, // Not sure if this is correct, it was taken off of Mordenai.

    // Spells
    SPELL_HIT_FORCE_OF_NELTHARAKU   = 38762,
    SPELL_FORCE_OF_NELTHARAKU       = 38775,

    // Creatures
    NPC_DRAGONMAW_SUBJUGATOR        = 21718,
    NPC_ESCAPE_DUMMY                = 22317

};

class npc_enslaved_netherwing_drake : public CreatureScript
{
public:
    npc_enslaved_netherwing_drake() : CreatureScript("npc_enslaved_netherwing_drake") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enslaved_netherwing_drakeAI(creature);
    }

    struct npc_enslaved_netherwing_drakeAI : public ScriptedAI
    {
        npc_enslaved_netherwing_drakeAI(Creature* creature) : ScriptedAI(creature)
        {
            Tapped = false;
            Reset();
        }

        ObjectGuid PlayerGUID;
        uint32 FlyTimer;
        bool Tapped;

        void Reset() override
        {
            if (!Tapped)
                me->setFaction(FACTION_DEFAULT);

            FlyTimer = 10000;
            me->SetDisableGravity(false);
            me->SetVisible(true);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (!caster)
                return;

            if (caster->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_HIT_FORCE_OF_NELTHARAKU && !Tapped)
            {
                Tapped = true;
                PlayerGUID = caster->GetGUID();

                me->setFaction(FACTION_FRIENDLY);
                DoCast(caster, SPELL_FORCE_OF_NELTHARAKU, true);

                Unit* Dragonmaw = me->FindNearestCreature(NPC_DRAGONMAW_SUBJUGATOR, 50);
                if (Dragonmaw)
                {
                    me->AddThreat(Dragonmaw, 100000.0f);
                    AttackStart(Dragonmaw);
                }

                HostileReference* ref = me->getThreatManager().getOnlineContainer().getReferenceByTarget(caster);
                if (ref)
                    ref->removeReference();
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (PlayerGUID)
                {
                    Unit* player = ObjectAccessor::GetUnit(*me, PlayerGUID);
                    if (player)
                        DoCast(player, SPELL_FORCE_OF_NELTHARAKU, true);

                    PlayerGUID.Clear();
                }
                me->SetVisible(false);
                me->SetDisableGravity(false);
                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                me->RemoveCorpse();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                if (Tapped)
                {
                    if (FlyTimer <= diff)
                    {
                        Tapped = false;
                        if (PlayerGUID)
                        {
                            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
                            if (player && player->GetQuestStatus(10854) == QUEST_STATUS_INCOMPLETE)
                            {
                                DoCast(player, SPELL_FORCE_OF_NELTHARAKU, true);
                                /*
                                float x, y, z;
                                me->GetPosition(x, y, z);

                                float dx, dy, dz;
                                me->GetRandomPoint(x, y, z, 20, dx, dy, dz);
                                dz += 20; // so it's in the air, not ground*/

                                Position pos;
                                if (Unit* EscapeDummy = me->FindNearestCreature(NPC_ESCAPE_DUMMY, 30))
                                    pos = EscapeDummy->GetPosition();
                                else
                                {
                                    pos = me->GetRandomNearPosition(20);
                                    pos.m_positionZ += 25;
                                }

                                me->SetDisableGravity(true);
                                me->GetMotionMaster()->MovePoint(1, pos);
                            }
                        }
                    } else FlyTimer -= diff;
                }
                return;
            }

            DoMeleeAttackIfReady();
        }
    };
};

/*#####
# npc_dragonmaw_peon
#####*/

class npc_dragonmaw_peon : public CreatureScript
{
public:
    npc_dragonmaw_peon() : CreatureScript("npc_dragonmaw_peon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dragonmaw_peonAI(creature);
    }

    struct npc_dragonmaw_peonAI : public ScriptedAI
    {
        npc_dragonmaw_peonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PlayerGUID.Clear();
            Tapped = false;
            PoisonTimer = 0;
        }

        ObjectGuid PlayerGUID;
        bool Tapped;
        uint32 PoisonTimer;

        void Reset() override
        {
            Initialize();
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (!caster)
                return;

            if (caster->GetTypeId() == TYPEID_PLAYER && spell->Id == 40468 && !Tapped)
            {
                PlayerGUID = caster->GetGUID();

                Tapped = true;
                float x, y, z;
                caster->GetClosePoint(x, y, z, me->GetObjectSize());

                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, x, y, z);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id)
            {
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_EAT);
                PoisonTimer = 15000;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (PoisonTimer)
            {
                if (PoisonTimer <= diff)
                {
                    if (PlayerGUID)
                    {
                        Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
                        if (player && player->GetQuestStatus(11020) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(23209);
                    }
                    PoisonTimer = 0;
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                } else PoisonTimer -= diff;
            }
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## npc_drake_dealer_hurlunk
######*/

class npc_drake_dealer_hurlunk : public CreatureScript
{
public:
    npc_drake_dealer_hurlunk() : CreatureScript("npc_drake_dealer_hurlunk") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsVendor() && player->GetReputationRank(1015) == REP_EXALTED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

/*######
## npc_flanis_swiftwing_and_kagrosh
######*/

#define GOSSIP_HSK1 "Take Flanis's Pack"
#define GOSSIP_HSK2 "Take Kagrosh's Pack"

class npcs_flanis_swiftwing_and_kagrosh : public CreatureScript
{
public:
    npcs_flanis_swiftwing_and_kagrosh() : CreatureScript("npcs_flanis_swiftwing_and_kagrosh") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 30658, 1, NULL);
            if (msg == EQUIP_ERR_OK)
            {
                player->StoreNewItem(dest, 30658, true);
                player->PlayerTalkClass->ClearMenus();
            }
        }
        if (action == GOSSIP_ACTION_INFO_DEF+2)
        {
            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 30659, 1, NULL);
            if (msg == EQUIP_ERR_OK)
            {
                player->StoreNewItem(dest, 30659, true);
                player->PlayerTalkClass->ClearMenus();
            }
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(10583) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(30658, 1, true))
            player->ADD_GOSSIP_ITEM(0, GOSSIP_HSK1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        if (player->GetQuestStatus(10601) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(30659, 1, true))
            player->ADD_GOSSIP_ITEM(0, GOSSIP_HSK2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

/*######
# npc_karynaku
####*/

enum Karynaku
{
    QUEST_ALLY_OF_NETHER    = 10870,
    QUEST_ZUHULED_THE_WACK  = 10866,

    NPC_ZUHULED_THE_WACKED  = 11980,

    TAXI_PATH_ID            = 649,
};

class npc_karynaku : public CreatureScript
{
    public:
        npc_karynaku() : CreatureScript("npc_karynaku") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ALLY_OF_NETHER)
                player->ActivateTaxiPathTo(TAXI_PATH_ID);

            if (quest->GetQuestId() == QUEST_ZUHULED_THE_WACK)
                creature->SummonCreature(NPC_ZUHULED_THE_WACKED, -4204.94f, 316.397f, 122.508f, 1.309f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000);

            return true;
        }
};

/*####
# npc_earthmender_wilda
####*/

enum Earthmender
{
    SAY_WIL_START               = 0,
    SAY_WIL_AGGRO               = 1,
    SAY_WIL_PROGRESS1           = 2,
    SAY_WIL_PROGRESS2           = 3,
    SAY_WIL_FIND_EXIT           = 4,
    SAY_WIL_JUST_AHEAD          = 5,
    SAY_WIL_END                 = 6,

    SPELL_CHAIN_LIGHTNING       = 16006,
    SPELL_EARTHBING_TOTEM       = 15786,
    SPELL_FROST_SHOCK           = 12548,
    SPELL_HEALING_WAVE          = 12491,

    QUEST_ESCAPE_COILSCAR       = 10451,
    NPC_COILSKAR_ASSASSIN       = 21044,
    FACTION_EARTHEN             = 1726                      //guessed
};

class npc_earthmender_wilda : public CreatureScript
{
public:
    npc_earthmender_wilda() : CreatureScript("npc_earthmender_wilda") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_ESCAPE_COILSCAR)
        {
            creature->AI()->Talk(SAY_WIL_START, player);
            creature->setFaction(FACTION_EARTHEN);

            if (npc_earthmender_wildaAI* pEscortAI = CAST_AI(npc_earthmender_wilda::npc_earthmender_wildaAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), quest);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_earthmender_wildaAI(creature);
    }

    struct npc_earthmender_wildaAI : public npc_escortAI
    {
        npc_earthmender_wildaAI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_uiHealingTimer = 0;
        }

        uint32 m_uiHealingTimer;

        void Reset() override
        {
            Initialize();
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 13:
                    Talk(SAY_WIL_PROGRESS1, player);
                    DoSpawnAssassin();
                    break;
                case 14:
                    DoSpawnAssassin();
                    break;
                case 15:
                    Talk(SAY_WIL_FIND_EXIT, player);
                    break;
                case 19:
                    DoRandomSay();
                    break;
                case 20:
                    DoSpawnAssassin();
                    break;
                case 26:
                    DoRandomSay();
                    break;
                case 27:
                    DoSpawnAssassin();
                    break;
                case 33:
                    DoRandomSay();
                    break;
                case 34:
                    DoSpawnAssassin();
                    break;
                case 37:
                    DoRandomSay();
                    break;
                case 38:
                    DoSpawnAssassin();
                    break;
                case 39:
                    Talk(SAY_WIL_JUST_AHEAD, player);
                    break;
                case 43:
                    DoRandomSay();
                    break;
                case 44:
                    DoSpawnAssassin();
                    break;
                case 50:
                    Talk(SAY_WIL_END, player);
                    player->GroupEventHappens(QUEST_ESCAPE_COILSCAR, me);
                    break;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_COILSKAR_ASSASSIN)
                summoned->AI()->AttackStart(me);
        }

        //this is very unclear, random say without no real relevance to script/event
        void DoRandomSay()
        {
            Talk(SAY_WIL_PROGRESS2);
        }

        void DoSpawnAssassin()
        {
            //unknown where they actually appear
            DoSummon(NPC_COILSKAR_ASSASSIN, me, 15.0f, 5000, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
        }

        void EnterCombat(Unit* who) override
        {
            //don't always use
            if (rand32() % 5)
                return;

            //only aggro text if not player
            if (who->GetTypeId() != TYPEID_PLAYER)
            {
                //appears to be random
                if (urand(0, 1))
                    Talk(SAY_WIL_AGGRO);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            /// @todo add more abilities
            if (!HealthAbovePct(30))
            {
                if (m_uiHealingTimer <= uiDiff)
                {
                    DoCast(me, SPELL_HEALING_WAVE);
                    m_uiHealingTimer = 15000;
                }
                else
                    m_uiHealingTimer -= uiDiff;
            }
        }
    };
};

/*#####
# Quest: Battle of the crimson watch
#####*/

/* ContentData
Battle of the crimson watch - creatures, gameobjects and defines
npc_illidari_spawn : Adds that are summoned in the Crimson Watch battle.
npc_torloth_the_magnificent : Final Creature that players have to face before quest is completed
npc_lord_illidan_stormrage : Creature that controls the event.
go_crystal_prison : GameObject that begins the event and hands out quest
EndContentData */

#define QUEST_BATTLE_OF_THE_CRIMSON_WATCH 10781
#define EVENT_AREA_RADIUS 65 //65yds
#define EVENT_COOLDOWN 30000 //in ms. appear after event completed or failed (should be = Adds despawn time)

struct TorlothCinematic
{
    uint32 creature, Timer;
};

// Creature 0 - Torloth, 1 - Illidan
static TorlothCinematic TorlothAnim[]=
{
    {0, 2000},
    {1, 7000},
    {0, 3000},
    {0, 2000}, // Torloth stand
    {0, 1000},
    {0, 3000},
    {0, 0}
};

//Cordinates for Spawns
static Position SpawnLocation[]=
{
    //Cords used for:
    {-4615.8556f, 1342.2532f, 139.9f, 1.612f}, //Illidari Soldier
    {-4598.9365f, 1377.3182f, 139.9f, 3.917f}, //Illidari Soldier
    {-4598.4697f, 1360.8999f, 139.9f, 2.427f}, //Illidari Soldier
    {-4589.3599f, 1369.1061f, 139.9f, 3.165f}, //Illidari Soldier
    {-4608.3477f, 1386.0076f, 139.9f, 4.108f}, //Illidari Soldier
    {-4633.1889f, 1359.8033f, 139.9f, 0.949f}, //Illidari Soldier
    {-4623.5791f, 1351.4574f, 139.9f, 0.971f}, //Illidari Soldier
    {-4607.2988f, 1351.6099f, 139.9f, 2.416f}, //Illidari Soldier
    {-4633.7764f, 1376.0417f, 139.9f, 5.608f}, //Illidari Soldier
    {-4600.2461f, 1369.1240f, 139.9f, 3.056f}, //Illidari Mind Breaker
    {-4631.7808f, 1367.9459f, 139.9f, 0.020f}, //Illidari Mind Breaker
    {-4600.2461f, 1369.1240f, 139.9f, 3.056f}, //Illidari Highlord
    {-4631.7808f, 1367.9459f, 139.9f, 0.020f}, //Illidari Highlord
    {-4615.5586f, 1353.0031f, 139.9f, 1.540f}, //Illidari Highlord
    {-4616.4736f, 1384.2170f, 139.9f, 4.971f}, //Illidari Highlord
    {-4627.1240f, 1378.8752f, 139.9f, 2.544f} //Torloth The Magnificent
};

struct WaveData
{
    uint8 SpawnCount, UsedSpawnPoint;
    uint32 CreatureId, SpawnTimer, YellTimer;
};

static WaveData WavesInfo[]=
{
    {9, 0, 22075, 10000, 7000},   //Illidari Soldier
    {2, 9, 22074, 10000, 7000},   //Illidari Mind Breaker
    {4, 11, 19797, 10000, 7000},  //Illidari Highlord
    {1, 15, 22076, 10000, 7000}   //Torloth The Magnificent
};

struct SpawnSpells
{
 uint32 Timer1, Timer2, SpellId;
};

static SpawnSpells SpawnCast[]=
{
    {10000, 15000, 35871},  // Illidari Soldier Cast - Spellbreaker
    {10000, 10000, 38985},  // Illidari Mind Breake Cast - Focused Bursts
    {35000, 35000, 22884},  // Illidari Mind Breake Cast - Psychic Scream
    {20000, 20000, 17194},  // Illidari Mind Breake Cast - Mind Blast
    {8000, 15000, 38010},   // Illidari Highlord Cast - Curse of Flames
    {12000, 20000, 16102},  // Illidari Highlord Cast - Flamestrike
    {10000, 15000, 15284},  // Torloth the Magnificent Cast - Cleave
    {18000, 20000, 39082},  // Torloth the Magnificent Cast - Shadowfury
    {25000, 28000, 33961}   // Torloth the Magnificent Cast - Spell Reflection
};

/*######
# npc_torloth_the_magnificent
#####*/

class npc_torloth_the_magnificent : public CreatureScript
{
public:
    npc_torloth_the_magnificent() : CreatureScript("npc_torloth_the_magnificent") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return new npc_torloth_the_magnificentAI(c);
    }

    struct npc_torloth_the_magnificentAI : public ScriptedAI
    {
        npc_torloth_the_magnificentAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SpellTimer1 = 0;
            SpellTimer2 = 0;
            SpellTimer3 = 0;
        }

        void Initialize()
        {
            AnimationTimer = 4000;
            AnimationCount = 0;
            LordIllidanGUID.Clear();
            AggroTargetGUID.Clear();
            Timers = false;
        }

        uint32 AnimationTimer, SpellTimer1, SpellTimer2, SpellTimer3;

        uint8 AnimationCount;

        ObjectGuid LordIllidanGUID;
        ObjectGuid AggroTargetGUID;

        bool Timers;

        void Reset() override
        {
            Initialize();

            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetTarget(ObjectGuid::Empty);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void HandleAnimation()
        {
            Creature* creature = me;

            if (TorlothAnim[AnimationCount].creature == 1)
            {
                creature = (ObjectAccessor::GetCreature(*me, LordIllidanGUID));

                if (!creature)
                    return;
            }

            AnimationTimer = TorlothAnim[AnimationCount].Timer;

            switch (AnimationCount)
            {
            case 0:
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 8);
                break;
            case 3:
                me->RemoveFlag(UNIT_FIELD_BYTES_1, 8);
                break;
            case 5:
                if (Player* AggroTarget = ObjectAccessor::GetPlayer(*me, AggroTargetGUID))
                {
                    me->SetTarget(AggroTarget->GetGUID());
                    me->AddThreat(AggroTarget, 1);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                }
                break;
            case 6:
                if (Player* AggroTarget = ObjectAccessor::GetPlayer(*me, AggroTargetGUID))
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->ClearUnitState(UNIT_STATE_ROOT);

                    float x, y, z;
                    AggroTarget->GetPosition(x, y, z);
                    me->GetMotionMaster()->MovePoint(0, x, y, z);
                }
                break;
            }
            ++AnimationCount;
        }

        void UpdateAI(uint32 diff) override
        {
            if (AnimationTimer)
            {
                if (AnimationTimer <= diff)
                {
                    HandleAnimation();
                } else AnimationTimer -= diff;
            }

            if (AnimationCount < 6)
            {
                me->CombatStop();
            } else if (!Timers)
            {
                SpellTimer1 = SpawnCast[6].Timer1;
                SpellTimer2 = SpawnCast[7].Timer1;
                SpellTimer3 = SpawnCast[8].Timer1;
                Timers = true;
            }

            if (Timers)
            {
                if (SpellTimer1 <= diff)
                {
                    DoCastVictim(SpawnCast[6].SpellId);//Cleave
                    SpellTimer1 = SpawnCast[6].Timer2 + (rand32() % 10 * 1000);
                } else SpellTimer1 -= diff;

                if (SpellTimer2 <= diff)
                {
                    DoCastVictim(SpawnCast[7].SpellId);//Shadowfury
                    SpellTimer2 = SpawnCast[7].Timer2 + (rand32() % 5 * 1000);
                } else SpellTimer2 -= diff;

                if (SpellTimer3 <= diff)
                {
                    DoCast(me, SpawnCast[8].SpellId);
                    SpellTimer3 = SpawnCast[8].Timer2 + (rand32() % 7 * 1000);//Spell Reflection
                } else SpellTimer3 -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            switch (killer->GetTypeId())
            {
                case TYPEID_UNIT:
                    if (Unit* owner = killer->GetOwner())
                        if (Player* player = owner->ToPlayer())
                            player->GroupEventHappens(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, me);
                    break;
                case TYPEID_PLAYER:
                    if (Player* player = killer->ToPlayer())
                        player->GroupEventHappens(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, me);
                    break;
                default:
                    break;
            }

            if (Creature* LordIllidan = (ObjectAccessor::GetCreature(*me, LordIllidanGUID)))
                LordIllidan->AI()->EnterEvadeMode();
        }
    };
};

/*#####
# npc_lord_illidan_stormrage
#####*/

class npc_lord_illidan_stormrage : public CreatureScript
{
public:
    npc_lord_illidan_stormrage() : CreatureScript("npc_lord_illidan_stormrage") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return new npc_lord_illidan_stormrageAI(c);
    }

    struct npc_lord_illidan_stormrageAI : public ScriptedAI
    {
        npc_lord_illidan_stormrageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PlayerGUID.Clear();

            WaveTimer = 10000;
            AnnounceTimer = 7000;
            LiveCount = 0;
            WaveCount = 0;

            EventStarted = false;
            Announced = false;
            Failed = false;
        }

        ObjectGuid PlayerGUID;

        uint32 WaveTimer;
        uint32 AnnounceTimer;

        int8 LiveCount;
        uint8 WaveCount;

        bool EventStarted;
        bool Announced;
        bool Failed;

        void Reset() override
        {
            Initialize();

            me->SetVisible(false);
        }

        void EnterCombat(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }

        void AttackStart(Unit* /*who*/) override { }

        void SummonNextWave();

        void CheckEventFail()
        {
            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);

            if (!player)
                return;

            if (Group* EventGroup = player->GetGroup())
            {
                uint8 GroupMemberCount = 0;
                uint8 DeadMemberCount = 0;
                uint8 FailedMemberCount = 0;

                Group::MemberSlotList const& members = EventGroup->GetMemberSlots();

                for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
                {
                    Player* GroupMember = ObjectAccessor::GetPlayer(*me, itr->guid);
                    if (!GroupMember)
                        continue;
                    if (!GroupMember->IsWithinDistInMap(me, EVENT_AREA_RADIUS) && GroupMember->GetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) == QUEST_STATUS_INCOMPLETE)
                    {
                        GroupMember->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
                        ++FailedMemberCount;
                    }
                    ++GroupMemberCount;

                    if (GroupMember->isDead())
                        ++DeadMemberCount;
                }

                if (GroupMemberCount == FailedMemberCount)
                {
                    Failed = true;
                }

                if (GroupMemberCount == DeadMemberCount)
                {
                    for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
                    {
                        if (Player* groupMember = ObjectAccessor::GetPlayer(*me, itr->guid))
                            if (groupMember->GetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) == QUEST_STATUS_INCOMPLETE)
                                groupMember->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
                    }
                    Failed = true;
                }
            } else if (player->isDead() || !player->IsWithinDistInMap(me, EVENT_AREA_RADIUS))
            {
                player->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
                Failed = true;
            }
        }

        void LiveCounter()
        {
            --LiveCount;
            if (!LiveCount)
                Announced = false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!PlayerGUID || !EventStarted)
                return;

            if (!LiveCount && WaveCount < 4)
            {
                if (!Announced && AnnounceTimer <= diff)
                {
                    Announced = true;
                }
                else
                    AnnounceTimer -= diff;

                if (WaveTimer <= diff)
                {
                    SummonNextWave();
                }
                else
                    WaveTimer -= diff;
            }
            CheckEventFail();

            if (Failed)
                EnterEvadeMode();
        }
    };
};

/*######
# npc_illidari_spawn
######*/

class npc_illidari_spawn : public CreatureScript
{
public:
    npc_illidari_spawn() : CreatureScript("npc_illidari_spawn") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return new npc_illidari_spawnAI(c);
    }

    struct npc_illidari_spawnAI : public ScriptedAI
    {
        npc_illidari_spawnAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SpellTimer1 = 0;
            SpellTimer2 = 0;
            SpellTimer3 = 0;
        }

        void Initialize()
        {
            LordIllidanGUID.Clear();
            Timers = false;
        }

        ObjectGuid LordIllidanGUID;
        uint32 SpellTimer1, SpellTimer2, SpellTimer3;
        bool Timers;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* /*killer*/) override
        {
            me->RemoveCorpse();
            if (Creature* LordIllidan = (ObjectAccessor::GetCreature(*me, LordIllidanGUID)))
                if (LordIllidan)
                    ENSURE_AI(npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI, LordIllidan->AI())->LiveCounter();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!Timers)
            {
                if (me->GetEntry() == 22075)//Illidari Soldier
                {
                    SpellTimer1 = SpawnCast[0].Timer1 + (rand32() % 4 * 1000);
                }
                if (me->GetEntry() == 22074)//Illidari Mind Breaker
                {
                    SpellTimer1 = SpawnCast[1].Timer1 + (rand32() % 10 * 1000);
                    SpellTimer2 = SpawnCast[2].Timer1 + (rand32() % 4 * 1000);
                    SpellTimer3 = SpawnCast[3].Timer1 + (rand32() % 4 * 1000);
                }
                if (me->GetEntry() == 19797)// Illidari Highlord
                {
                    SpellTimer1 = SpawnCast[4].Timer1 + (rand32() % 4 * 1000);
                    SpellTimer2 = SpawnCast[5].Timer1 + (rand32() % 4 * 1000);
                }
                Timers = true;
            }
            //Illidari Soldier
            if (me->GetEntry() == 22075)
            {
                if (SpellTimer1 <= diff)
                {
                    DoCastVictim(SpawnCast[0].SpellId);//Spellbreaker
                    SpellTimer1 = SpawnCast[0].Timer2 + (rand32() % 5 * 1000);
                } else SpellTimer1 -= diff;
            }
            //Illidari Mind Breaker
            if (me->GetEntry() == 22074)
            {
                if (SpellTimer1 <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (target->GetTypeId() == TYPEID_PLAYER)
                        {
                            DoCast(target, SpawnCast[1].SpellId); //Focused Bursts
                            SpellTimer1 = SpawnCast[1].Timer2 + (rand32() % 5 * 1000);
                        } else SpellTimer1 = 2000;
                    }
                } else SpellTimer1 -= diff;

                if (SpellTimer2 <= diff)
                {
                    DoCastVictim(SpawnCast[2].SpellId);//Psychic Scream
                    SpellTimer2 = SpawnCast[2].Timer2 + (rand32() % 13 * 1000);
                } else SpellTimer2 -= diff;

                if (SpellTimer3 <= diff)
                {
                    DoCastVictim(SpawnCast[3].SpellId);//Mind Blast
                    SpellTimer3 = SpawnCast[3].Timer2 + (rand32() % 8 * 1000);
                } else SpellTimer3 -= diff;
            }
            //Illidari Highlord
            if (me->GetEntry() == 19797)
            {
                if (SpellTimer1 <= diff)
                {
                    DoCastVictim(SpawnCast[4].SpellId);//Curse Of Flames
                    SpellTimer1 = SpawnCast[4].Timer2 + (rand32() % 10 * 1000);
                } else SpellTimer1 -= diff;

                if (SpellTimer2 <= diff)
                {
                    DoCastVictim(SpawnCast[5].SpellId);//Flamestrike
                    SpellTimer2 = SpawnCast[5].Timer2 + (rand32() % 7 * 13000);
                } else SpellTimer2 -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI::SummonNextWave()
{
    uint8 count = WavesInfo[WaveCount].SpawnCount;
    uint8 locIndex = WavesInfo[WaveCount].UsedSpawnPoint;
    uint8 FelguardCount = 0;
    uint8 DreadlordCount = 0;

    for (uint8 i = 0; i < count; ++i)
    {
        Creature* Spawn = me->SummonCreature(WavesInfo[WaveCount].CreatureId, SpawnLocation[locIndex + i], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        ++LiveCount;

        if (Spawn)
        {
            Spawn->LoadCreaturesAddon();

            if (WaveCount == 0)//1 Wave
            {
                if (rand32() % 3 == 1 && FelguardCount<2)
                {
                    Spawn->SetDisplayId(18654);
                    ++FelguardCount;
                }
                else if (DreadlordCount < 3)
                {
                    Spawn->SetDisplayId(19991);
                    ++DreadlordCount;
                }
                else if (FelguardCount<2)
                {
                    Spawn->SetDisplayId(18654);
                    ++FelguardCount;
                }
            }

            if (WaveCount < 3)//1-3 Wave
            {
                if (PlayerGUID)
                {
                    if (Player* target = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    {
                        float x, y, z;
                        target->GetPosition(x, y, z);
                        Spawn->GetMotionMaster()->MovePoint(0, x, y, z);
                    }
                }
                ENSURE_AI(npc_illidari_spawn::npc_illidari_spawnAI, Spawn->AI())->LordIllidanGUID = me->GetGUID();
            }

            if (WavesInfo[WaveCount].CreatureId == 22076) // Torloth
            {
                ENSURE_AI(npc_torloth_the_magnificent::npc_torloth_the_magnificentAI, Spawn->AI())->LordIllidanGUID = me->GetGUID();
                if (PlayerGUID)
                    ENSURE_AI(npc_torloth_the_magnificent::npc_torloth_the_magnificentAI, Spawn->AI())->AggroTargetGUID = PlayerGUID;
            }
        }
    }
    ++WaveCount;
    WaveTimer = WavesInfo[WaveCount].SpawnTimer;
    AnnounceTimer = WavesInfo[WaveCount].YellTimer;
}

/*#####
# go_crystal_prison
######*/

class go_crystal_prison : public GameObjectScript
{
public:
    go_crystal_prison() : GameObjectScript("go_crystal_prison") { }

    bool OnQuestAccept(Player* player, GameObject* /*go*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_BATTLE_OF_THE_CRIMSON_WATCH)
        {
            Creature* Illidan = player->FindNearestCreature(22083, 50);

            if (Illidan && !ENSURE_AI(npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI, Illidan->AI())->EventStarted)
            {
                ENSURE_AI(npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI, Illidan->AI())->PlayerGUID = player->GetGUID();
                ENSURE_AI(npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI, Illidan->AI())->LiveCount = 0;
                ENSURE_AI(npc_lord_illidan_stormrage::npc_lord_illidan_stormrageAI, Illidan->AI())->EventStarted = true;
            }
        }
     return true;
    }
};

/*####
# npc_enraged_spirits
####*/

enum Enraged_Dpirits
{
// QUESTS
    QUEST_ENRAGED_SPIRITS_FIRE_EARTH        = 10458,
    QUEST_ENRAGED_SPIRITS_AIR               = 10481,
    QUEST_ENRAGED_SPIRITS_WATER             = 10480,

    // Totem
    ENTRY_TOTEM_OF_SPIRITS                  = 21071,
    RADIUS_TOTEM_OF_SPIRITS                 = 15,

    // SPIRITS
    NPC_ENRAGED_EARTH_SPIRIT                = 21050,
    NPC_ENRAGED_FIRE_SPIRIT                 = 21061,
    NPC_ENRAGED_AIR_SPIRIT                  = 21060,
    NPC_ENRAGED_WATER_SPIRIT                = 21059,

    // SOULS
    NPC_EARTHEN_SOUL                        = 21073,
    NPC_FIERY_SOUL                          = 21097,
    NPC_ENRAGED_AIRY_SOUL                   = 21116,
    NPC_ENRAGED_WATERY_SOUL                 = 21109, // wrong model

    // SPELL KILLCREDIT - not working!?! - using KilledMonsterCredit
    SPELL_EARTHEN_SOUL_CAPTURED_CREDIT      = 36108,
    SPELL_FIERY_SOUL_CAPTURED_CREDIT        = 36117,
    SPELL_AIRY_SOUL_CAPTURED_CREDIT         = 36182,
    SPELL_WATERY_SOUL_CAPTURED_CREDIT       = 36171,

    // KilledMonsterCredit Workaround
    NPC_CREDIT_FIRE                         = 21094,
    NPC_CREDIT_WATER                        = 21095,
    NPC_CREDIT_AIR                          = 21096,
    NPC_CREDIT_EARTH                        = 21092,

    // Captured Spell / Buff
    SPELL_SOUL_CAPTURED                     = 36115,

    // Factions
    FACTION_ENRAGED_SOUL_FRIENDLY           = 35,
    FACTION_ENRAGED_SOUL_HOSTILE            = 14
};

class npc_enraged_spirit : public CreatureScript
{
public:
    npc_enraged_spirit() : CreatureScript("npc_enraged_spirit") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
    return new npc_enraged_spiritAI(creature);
    }

    struct npc_enraged_spiritAI : public ScriptedAI
    {
        npc_enraged_spiritAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* /*killer*/) override
        {
            // always spawn spirit on death
            // if totem around
            // move spirit to totem and cast kill count
            uint32 entry = 0;
            uint32 credit = 0;

            switch (me->GetEntry())
            {
                  case NPC_ENRAGED_FIRE_SPIRIT:
                    entry  = NPC_FIERY_SOUL;
                    //credit = SPELL_FIERY_SOUL_CAPTURED_CREDIT;
                    credit = NPC_CREDIT_FIRE;
                    break;
                  case NPC_ENRAGED_EARTH_SPIRIT:
                    entry  = NPC_EARTHEN_SOUL;
                    //credit = SPELL_EARTHEN_SOUL_CAPTURED_CREDIT;
                    credit = NPC_CREDIT_EARTH;
                    break;
                  case NPC_ENRAGED_AIR_SPIRIT:
                    entry  = NPC_ENRAGED_AIRY_SOUL;
                    //credit = SPELL_AIRY_SOUL_CAPTURED_CREDIT;
                    credit = NPC_CREDIT_AIR;
                    break;
                  case NPC_ENRAGED_WATER_SPIRIT:
                    entry  = NPC_ENRAGED_WATERY_SOUL;
                    //credit = SPELL_WATERY_SOUL_CAPTURED_CREDIT;
                    credit = NPC_CREDIT_WATER;
                    break;
                default:
                    break;
            }

            // Spawn Soul on Kill ALWAYS!
            Creature* Summoned = NULL;
            Unit* totemOspirits = NULL;

            if (entry != 0)
                Summoned = DoSpawnCreature(entry, 0, 0, 1, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);

            // FIND TOTEM, PROCESS QUEST
            if (Summoned)
            {
                 totemOspirits = me->FindNearestCreature(ENTRY_TOTEM_OF_SPIRITS, RADIUS_TOTEM_OF_SPIRITS);
                 if (totemOspirits)
                 {
                     Summoned->setFaction(FACTION_ENRAGED_SOUL_FRIENDLY);
                     Summoned->GetMotionMaster()->MovePoint(0, totemOspirits->GetPositionX(), totemOspirits->GetPositionY(), Summoned->GetPositionZ());

                     if (Unit* owner = totemOspirits->GetOwner())
                         if (Player* player = owner->ToPlayer())
                             player->KilledMonsterCredit(credit);
                     DoCast(totemOspirits, SPELL_SOUL_CAPTURED);
                 }
            }
        }
    };
};

enum ZuluhedChains
{
    NPC_KARYNAKU    = 22112,
};

class spell_unlocking_zuluheds_chains : public SpellScriptLoader
{
    public:
        spell_unlocking_zuluheds_chains() : SpellScriptLoader("spell_unlocking_zuluheds_chains") { }

        class spell_unlocking_zuluheds_chains_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_unlocking_zuluheds_chains_SpellScript);

            void HandleAfterHit()
            {
                if (Player* caster = GetCaster()->ToPlayer())
                    if (Creature* karynaku = caster->FindNearestCreature(NPC_KARYNAKU, 15.0f))
                        caster->KilledMonsterCredit(NPC_KARYNAKU, karynaku->GetGUID());
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_unlocking_zuluheds_chains_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_unlocking_zuluheds_chains_SpellScript();
        }
};

enum ShadowMoonTuberEnum
{
    SPELL_WHISTLE               = 36652,
    SPELL_SHADOWMOON_TUBER      = 36462,

    NPC_BOAR_ENTRY              = 21195,
    GO_SHADOWMOON_TUBER_MOUND   = 184701,

    POINT_TUBER                 = 1,
    TYPE_BOAR                   = 1,
    DATA_BOAR                   = 1
};

class npc_shadowmoon_tuber_node : public CreatureScript
{
public:
    npc_shadowmoon_tuber_node() : CreatureScript("npc_shadowmoon_tuber_node") { }

    struct npc_shadowmoon_tuber_nodeAI : public ScriptedAI
    {
        npc_shadowmoon_tuber_nodeAI(Creature* creature) : ScriptedAI(creature) { }

        void SetData(uint32 id, uint32 data) override
        {
            if (id == TYPE_BOAR && data == DATA_BOAR)
            {
                // Spawn chest GO
                DoCast(SPELL_SHADOWMOON_TUBER);

                // Despawn the tuber
                if (GameObject* tuber = me->FindNearestGameObject(GO_SHADOWMOON_TUBER_MOUND, 5.0f))
                {
                    tuber->SetLootState(GO_JUST_DEACTIVATED);
                    me->DespawnOrUnsummon();
                }
            }
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_WHISTLE)
            {
                if (Creature* boar = me->FindNearestCreature(NPC_BOAR_ENTRY, 30.0f))
                {
                    boar->SetWalk(false);
                    boar->GetMotionMaster()->MovePoint(POINT_TUBER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowmoon_tuber_nodeAI(creature);
    }
};

void AddSC_shadowmoon_valley()
{
    new npc_invis_infernal_caster();
    new npc_infernal_attacker();
    new npc_mature_netherwing_drake();
    new npc_enslaved_netherwing_drake();
    new npc_dragonmaw_peon();
    new npc_drake_dealer_hurlunk();
    new npcs_flanis_swiftwing_and_kagrosh();
    new npc_karynaku();
    new npc_earthmender_wilda();
    new npc_lord_illidan_stormrage();
    new go_crystal_prison();
    new npc_illidari_spawn();
    new npc_torloth_the_magnificent();
    new npc_enraged_spirit();
    new spell_unlocking_zuluheds_chains();
    new npc_shadowmoon_tuber_node();
}
