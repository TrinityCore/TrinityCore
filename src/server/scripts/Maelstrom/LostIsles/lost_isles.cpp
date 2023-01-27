/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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

#include "CellImpl.h"
#include "Creature.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "WorldSession.h"
#include <iostream>
using namespace std;

#define SAY_D_A "Ecrouabouille, what are you doing sitting there? You do not recognize the one who is lying?"
#define SAY_D_B  "That's $ N! It is only thanks to $ he: she, if we still breath instead of being pieces of rind grids has Kezan."
#define SAY_D_C  "That's $ N! Sorry, doc, I thought $ ghe death:she death; !"
#define SAY_D_D  "Remains back, I'm $ ghe: she; revive! Hoping that this soggy defibrillator will not kill us all!"
#define SAY_D_E  "Caution! OFF!"
#define SAY_D_F "That's all I can do. C'' is a $ ghe: she; to react now. You hear me, $ N? Come on, wake up now! Do not go to the Light!"
#define SAY_D_G  "You made the right choice. We need you so much, $ N. Try not to get killed here. "
#define SAY_D_H  "There are other survivors that I must attend. I'll see you on the shore."

enum DontGoIntoTheLight
{
    NPC_GIZMO                           = 36600,
    SPELL_DEAD_STILL                    = 69010,

    SPELL_DGITL_QUEST_COMPLETE          = 69013,
    SPELL_DGITL_SUMMON_DOC_ZAPNOZZLE    = 69018,
    SPELL_DGITL_JUMP_CABLES             = 69022,
    SPELL_DGITL_DESPAWN_DOC_ZAPNOZZLE   = 69043,
};

enum Texts
{
    SAY_GYRO = 0
};

// 69010
class spell_lost_isles_near_death : public SpellScript
{
    PrepareSpellScript(spell_lost_isles_near_death);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_DGITL_SUMMON_DOC_ZAPNOZZLE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lost_isles_near_death::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 36608
struct npc_zapnozzle : public ScriptedAI
{
    npc_zapnozzle(Creature* creature) : ScriptedAI(creature) { }

    Position const beachPosition = { 617.317383f, 3142.259277f, -0.114589f, 2.176555f };

    void Reset() override
    {
        me->SetFlying(true);
        me->SetSwim(true);
        me->GetMotionMaster()->MovePoint(1, 538.785034f, 3271.091797f, -1.082726f);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        _playerGuid = summoner->GetGUID();
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case 1:
                me->SetFlying(false);
                me->SetSwim(false);
                me->GetMotionMaster()->MoveJump(537.296875f, 3272.306396f, 0.166942f, 3.011669f, 10.f, 10.f, 2);
                break;
            case 2:
                Talk(0, GetSummoner());
                InitFirstEventSchedulers();
                break;
            case 3:
                me->SetFlying(true);
                me->SetSwim(true);
                Talk(6, GetSummoner());
                me->GetMotionMaster()->MovePoint(4, beachPosition);
                me->DespawnOrUnsummon(5000);
                break;
            default:
                break;
        }
    }

    void InitFirstEventSchedulers()
    {
        me->GetScheduler().
            Schedule(5s, [this](TaskContext /*context*/)
            {
                Talk(1, GetSummoner());
            }).
            Schedule(9s, [this](TaskContext /*context*/)
            {
                if (Creature* gizmo = GetGizmo())
                    gizmo->AI()->Talk(0, GetSummoner());
            }).
            Schedule(15s, [this](TaskContext /*context*/)
            {
                Talk(2, GetSummoner());
            }).
            Schedule(21s, [this](TaskContext /*context*/)
            {
                me->CastSpell(GetSummoner(), SPELL_DGITL_JUMP_CABLES, false);
            }).
            Schedule(27s, [this](TaskContext /*context*/)
            {
                Talk(3, GetSummoner());
            }).
            Schedule(31s, [this](TaskContext /*context*/)
            {
                me->CastSpell(GetSummoner(), SPELL_DGITL_JUMP_CABLES, false);
            }).
            Schedule(37s, [this](TaskContext /*context*/)
            {
                Talk(4, GetSummoner());
                me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            });
    }

    void sQuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == 14239)
            InitSecondEventSchedulers();
    }

    void InitSecondEventSchedulers()
    {
        me->GetScheduler().
            Schedule(1s, [this](TaskContext /*context*/)
            {
                Talk(5, GetSummoner());
            }).
            Schedule(4s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MoveJump(539.637451f, 3266.728516f, -1.139869f, 5.053704f, 10.f, 10.f, 3);
            });
    }

private :
    ObjectGuid _playerGuid;

    Player* GetSummoner()
    {
        return ObjectAccessor::GetPlayer(*me, _playerGuid);
    }

    Creature* GetGizmo()
    {
        return me->FindNearestCreature(NPC_GIZMO, 10.f);
    }
};

enum GoblinEscapePod
{
    SPELL_SUMMON_LIVE_GOBLIN_SURVIVOR   = 66137,
    SPELL_TRADE_PRINCE_CONTROLLER_AURA  = 67433,
    SPELL_SUMMON_TRADE_PRINCE           = 67845,

    NCP_TRADE_PRINCE_GALLYWIX           = 35649
};

// 195188
class gob_goblin_escape_pod : public GameObjectAI
{
public:
    gob_goblin_escape_pod(GameObject* go) : GameObjectAI(go) { }

    void OnStateChanged(uint32 state, Unit* unit) override
    {
        if (unit && state == GO_ACTIVATED)
        {
            if (Player* player = unit->ToPlayer())
            {
                if (!player->HasAura(SPELL_TRADE_PRINCE_CONTROLLER_AURA))
                {
                    player->CastSpell(nullptr, SPELL_SUMMON_TRADE_PRINCE, true);
                    player->CastSpell(nullptr, SPELL_TRADE_PRINCE_CONTROLLER_AURA, true);
                }
                else
                {
                    player->CastSpell(nullptr, SPELL_SUMMON_LIVE_GOBLIN_SURVIVOR, true);
                }

                player->KilledMonsterCredit(34748);
                go->DestroyForPlayer(player);
            }
        }
    }
};

// 34748
// 35649
struct npc_goblin_espace_pod : public ScriptedAI
{
    npc_goblin_espace_pod(Creature* creature) : ScriptedAI(creature) {}

    Position const beachPosition = { 617.317383f, 3142.259277f, -0.114589f, 2.176555f };

    void Reset() override
    {
        me->SetFlying(true);
        me->SetSwim(true);

        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            Player* nearestPlayer = me->SelectNearestPlayer(20.f);

            if (me->GetEntry() == NCP_TRADE_PRINCE_GALLYWIX)
                Talk(0, nearestPlayer);
            else
                Talk(urand(0, 3), nearestPlayer);

        }).Schedule(2s, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePoint(1, beachPosition);
            me->DespawnOrUnsummon(3000);
        });
    }
};

enum BombMonkey
{
    SPELL_MONKEY_COSMETIC_THROW_BOMB= 66142,
    SPELL_NITRO_POTASSIUM_BANANAS   = 67917,
    SPELL_EXPLOSIVE_BANANA          = 67919,

    NPC_MONKEY_KILL_CREDIT          = 35760
};

// 34699
struct npc_bomb_monkey : public ScriptedAI
{
    npc_bomb_monkey(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->GetScheduler().Schedule(5s, 30s, [](TaskContext context)
        {
            GetContextUnit()->CastSpell(nullptr, SPELL_MONKEY_COSMETIC_THROW_BOMB, false);
            context.Repeat(5s, 30s);
        });
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (Player* player = caster->ToPlayer())
        {
            if (spell->Id == SPELL_NITRO_POTASSIUM_BANANAS)
            {
                if (me->IsNonMeleeSpellCast(true))
                    me->InterruptNonMeleeSpells(true);

                player->KilledMonsterCredit(NPC_MONKEY_KILL_CREDIT);
                me->CastSpell(me, SPELL_EXPLOSIVE_BANANA, true);
                me->DespawnOrUnsummon(3000);
            }
        }
    }
};

enum MinerTroublesQuest
{
    QUEST_MINER_TROUBLES                = 14021,

    SPELL_MINER_TROUBLESQUEST_ACCEPT    = 68061,
    SPELL_MINER_TROUBLESQUEST_COMPLETE  = 68063,
    SPELL_SUMMON_ORE_CART               = 68064,
    SPELL_MINER_TROUBLES_CHAINS         = 68122,

    NPC_FRIGHTENED_MINER                = 35813,
    NPC_ORE_CART                        = 35814,
};

enum CapturingTheUnknown
{
    QUEST_CAPTURING_THE_UNKNOWN         = 14031,
    SPELL_CTU_FLASH                     = 68281,
    SPELL_CTU_BIND_SIGHT                = 70641,
    SPELL_CTU_SCREEN_EFFECT             = 70649,

    SPELL_CTU_SEE_INVIS_1               = 70661,
    SPELL_CTU_SEE_INVIS_2               = 70678,
    SPELL_CTU_SEE_INVIS_3               = 70680,
    SPELL_CTU_SEE_INVIS_4               = 70681,

    NPC_CTU_BUNNY_1                     = 37872,
    NPC_CTU_BUNNY_2                     = 37895,
    NPC_CTU_BUNNY_3                     = 37896,
    NPC_CTU_BUNNY_4                     = 37897,
};

// 35769
struct npc_foreman_dampwick : public ScriptedAI
{
    npc_foreman_dampwick(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_MINER_TROUBLES)
        {
            Talk(0);
            me->CastSpell(player, SPELL_MINER_TROUBLESQUEST_ACCEPT, true);

            if (Creature* miner = player->GetSummonedCreatureByEntry(NPC_FRIGHTENED_MINER))
            {
                miner->CastSpell(nullptr, SPELL_SUMMON_ORE_CART, true);
                if (Creature* oreCart = miner->GetSummonedCreatureByEntry(NPC_ORE_CART))
                {
                    oreCart->CastSpell(miner, SPELL_MINER_TROUBLES_CHAINS, true);
                    oreCart->GetMotionMaster()->MoveFollow(miner, 1.f, float(M_PI));
                }

                CAST_AI(npc_escortAI, (miner->AI()))->Start(false, false, player->GetGUID(), quest);
            }
        }
    }
};

// 35813
struct npc_frightened_miner_escort : public npc_escortAI
{
    npc_frightened_miner_escort(Creature* creature) : npc_escortAI(creature) {}

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
    void EnterEvadeMode(EvadeReason /*why*/) override {}
    void JustDied(Unit* /*killer*/) override {}
    void OnCharmed(bool /*apply*/) override {}

    void WaypointReached(uint32 pointId) override
    {
        switch(pointId)
        {
            case 3:
                TalkToEscortPlayer(1);
                break;
            case 4:
            case 7:
            case 10:
            case 12:
                me->HandleEmoteCommand(467);
                break;
            case 13:
                SetRun(true);
                TalkToEscortPlayer(5);
                if (Player *player = GetPlayerForEscort())
                    player->KilledMonsterCredit(35816);

                if (Creature* oreCart = me->GetSummonedCreatureByEntry(NPC_ORE_CART))
                    oreCart->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void WaypointStart(uint32 pointId) override
    {
        me->HandleEmoteCommand(0);
        switch(pointId)
        {
            case 0:
                TalkToEscortPlayer(0);
                break;
            case 4:
                TalkToEscortPlayer(2);
                break;
            case 8:
                TalkToEscortPlayer(3);
                break;
            case 10:
                TalkToEscortPlayer(4);
                break;
            case 13:
                SetRun(true);
                TalkToEscortPlayer(5);
                if (Player *player = GetPlayerForEscort())
                    player->KilledMonsterCredit(35816);

                if (Creature* oreCart = me->GetSummonedCreatureByEntry(NPC_ORE_CART))
                    oreCart->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }
};

std::map<uint32, uint32> const ctuSpellByBunny
{
    { NPC_CTU_BUNNY_1,  SPELL_CTU_SEE_INVIS_1 },
    { NPC_CTU_BUNNY_2,  SPELL_CTU_SEE_INVIS_2 },
    { NPC_CTU_BUNNY_3,  SPELL_CTU_SEE_INVIS_3 },
    { NPC_CTU_BUNNY_4,  SPELL_CTU_SEE_INVIS_4 },
};

// 68280
class spell_ctu_snapflash : public SpellScript
{
    PrepareSpellScript(spell_ctu_snapflash);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unit = GetHitUnit())
        {
            if (Player* casterPlayer = GetCaster()->ToPlayer())
            {
                casterPlayer->RemoveAurasDueToSpell(ctuSpellByBunny.at(unit->GetEntry()));

                casterPlayer->CastSpell(nullptr, SPELL_CTU_BIND_SIGHT, true);
                casterPlayer->CastSpell(nullptr, SPELL_CTU_SCREEN_EFFECT, true);

                casterPlayer->GetScheduler().Schedule(3s, [unit](TaskContext context)
                {
                    GetContextPlayer()->RemoveAurasDueToSpell(SPELL_CTU_SCREEN_EFFECT);
                    GetContextPlayer()->KilledMonsterCredit(unit->GetEntry(), unit->GetGUID());
                });
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ctu_snapflash::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 70641
class spell_ctu_bind_sight : public SpellScript
{
    PrepareSpellScript(spell_ctu_bind_sight);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unit = GetHitUnit())
            unit->CastSpell(unit, SPELL_CTU_FLASH, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ctu_bind_sight::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

enum LostIslesWeed
{
    QUEST_WEED_WHAKER       = 14236,
    SPELL_WEED_WHACKER_AURA = 68212
};

struct npc_lost_isles_weed : public ScriptedAI
{
    npc_lost_isles_weed(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (me->IsAlive())
        {
            if (spell->Id == 68213)
            {
                if (Player* player = caster->ToPlayer())
                {
                    player->KilledMonsterCredit(35897);
                    player->Kill(me);
                }
            }
        }
    }

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
};

class spell_weed_whacker : public SpellScript
{
    PrepareSpellScript(spell_weed_whacker);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCastItem())
        {
            if (Unit* caster = GetCastItem()->GetOwner())
            {
                if (Player* player = caster->ToPlayer())
                {
                    if (player->HasAura(SPELL_WEED_WHACKER_AURA))
                        player->RemoveAura(SPELL_WEED_WHACKER_AURA);
                    else if (player->GetQuestStatus(QUEST_WEED_WHAKER) == QUEST_STATUS_INCOMPLETE)
                        player->CastSpell(player, SPELL_WEED_WHACKER_AURA, true);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_weed_whacker::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum Infrared
{
    QUEST_INFRARED_INFRADEAD        = 14238,
    QUEST_TO_THE_CLIFFS             = 14240,

    NPC_ORC_SCOUT                   = 36100,
    NPC_CLIFF_BASTIA                = 36585,

    SPELL_INFRARED_QUEST_ACCEPT     = 68344,
    SPELL_INFRARED_ORC_SCOUT_AURA   = 68338,
    SPELL_CLIFF_SUMMON_BASTIA       = 68973,
};

// 35917
struct npc_killag_sangrecroc : public ScriptedAI
{
    npc_killag_sangrecroc(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_INFRARED_INFRADEAD)
        {
            Talk(0, player);
            me->CastSpell(player, SPELL_INFRARED_QUEST_ACCEPT, true);
        }

        if (quest->GetQuestId() == QUEST_TO_THE_CLIFFS)
        {
            player->CastSpell(player, SPELL_CLIFF_SUMMON_BASTIA, true);

            if (Creature* bastia = player->GetSummonedCreatureByEntry(NPC_CLIFF_BASTIA))
            {
                Talk(1, player);
                CAST_AI(npc_escortAI, bastia->AI())->Start(false, true, player->GetGUID(), quest);
            }
        }
    }

    void sQuestReward(Player* player, const Quest* quest, uint32 ) override
    {
        if (quest->GetQuestId() == QUEST_INFRARED_INFRADEAD)
            player->RemoveAurasDueToSpell(SPELL_INFRARED_ORC_SCOUT_AURA);
    }
};

// 68338
class aura_infrared_orc_scout : public AuraScript
{
    PrepareAuraScript(aura_infrared_orc_scout);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* orcScout = GetTarget()->GetSummonedCreatureByEntry(NPC_ORC_SCOUT))
            orcScout->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(aura_infrared_orc_scout::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 36578
struct npc_cliff_bastia : public npc_escortAI
{
    npc_cliff_bastia(Creature* creature) : npc_escortAI(creature) {}

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
    void EnterEvadeMode(EvadeReason /*why*/) override {}
    void OnCharmed(bool /*apply*/) override {}

    void Reset() override
    {
        me->SetSpeed(MOVE_RUN, 14.f);
    }

    void WaypointReached(uint32 pointId) override
    {
        if (pointId == 20)
            me->DespawnOrUnsummon();
    }
};

enum PreciousCargo
{
    QUEST_PRECIOUS_CARO                 = 14242,
    QUEST_MEET_ME_UP_TOP                = 14326,

    SPELL_PRECIOUS_CARGO_QUEST_ACCEPT   = 68386,
    SPELL_PRECIOUS_CARGO_KILL_CREDIT    = 69081,

    NPC_GYROCOPTER                      = 36143,

    GOB_ARCANE_CAGE                     = 195704,
};

// 36127
struct npc_gyrocopterequest_giver : public ScriptedAI
{
    npc_gyrocopterequest_giver(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_PRECIOUS_CARO)
        {
            player->CastSpell(player, SPELL_PRECIOUS_CARGO_QUEST_ACCEPT, true);

            if (Creature* gyrocopter = player->GetSummonedCreatureByEntry(NPC_GYROCOPTER))
                CAST_AI(npc_escortAI, gyrocopter->AI())->Start(false, true, player->GetGUID(), quest);
        }
    }
};

// 36143
struct npc_precious_cargo_gyrocopter : public npc_escortAI
{
    npc_precious_cargo_gyrocopter(Creature* creature) : npc_escortAI(creature) {}

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
    void EnterEvadeMode(EvadeReason /*why*/) override {}
    void OnCharmed(bool /*apply*/) override {}

    void Reset() override
    {
        me->SetCanFly(true);
        me->SetSpeed(MOVE_FLIGHT, 21.0f);
    }

    void WaypointReached(uint32 pointId) override
    {
        if (pointId == 3)
        {
            if (Player* player = GetPlayerForEscort())
                me->CastSpell(player, SPELL_PRECIOUS_CARGO_KILL_CREDIT, true);

            me->DespawnOrUnsummon();
        }
    }
};

// 36145
struct npc_lost_isles_thrall_prisonner : public ScriptedAI
{
    npc_lost_isles_thrall_prisonner(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (player->GetQuestStatus(QUEST_PRECIOUS_CARO) == QUEST_STATUS_INCOMPLETE)
                if (player->GetDistance(me) < 5.f)
                    player->KilledMonsterCredit(me->GetEntry());
    }

    void sQuestAccept(Player* player, const Quest* /*quest*/) override
    {
        Talk(0, player);
    }
};

enum WarchiefsRevenge
{
    QUEST_WARCHIEF_REVENGE  = 14243,

    SPELL_WR_QUEST_ACCEPT   = 68408,

    NPC_WR_CYCLONE          = 36178,
};

// 36127
struct npc_lost_isles_thrall_top_boat : public ScriptedAI
{
    npc_lost_isles_thrall_top_boat(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_WARCHIEF_REVENGE)
        {
            player->CastSpell(player, SPELL_WR_QUEST_ACCEPT, true);

            if (Creature* cyclone = player->GetSummonedCreatureByEntry(NPC_WR_CYCLONE))
                cyclone->AI()->DoAction(0);
        }
    }
};

// 36178
struct npc_warchief_revenge_cyclone : public npc_escortAI
{
    npc_warchief_revenge_cyclone(Creature* creature) : npc_escortAI(creature) {}

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
    void EnterEvadeMode(EvadeReason /*why*/) override {}
    void OnCharmed(bool /*apply*/) override {}

    void Reset() override
    {
        me->SetCanFly(true);
        me->SetSpeed(MOVE_FLIGHT, 7.0f);
    }

    void DoAction(int32 /*action*/) override
    {
        me->GetMotionMaster()->MovePoint(1001, 1001.373047f, 3832.485840f, 14.062465f);

        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (Vehicle* vehicle = me->GetVehicleKit())
            {
                if (Unit* passenger = vehicle->GetPassenger(0))
                {
                    if (Player* player = passenger->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_WARCHIEF_REVENGE) == QUEST_STATUS_COMPLETE)
                        {
                            SetEscortPaused(true);
                            me->SetSpeed(MOVE_FLIGHT, 35.0f);
                            me->GetMotionMaster()->MovePoint(1002, 885.869568f, 3104.882324f, 175.560944f, false);
                        }
                        else
                            context.Repeat();
                    }
                }
            }
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case 1001:
                Start(false, true, ObjectGuid::Empty, nullptr, false, true);
                break;
            case 1002:
                me->GetMotionMaster()->MovePoint(1003, 863.672180f, 2778.023193f, 126.243454f, false);
                break;
            case 1003:
                //Add teleport cuz the npc drops you mid air before reaching the wp for some reason
                if (Vehicle* vehicle = me->GetVehicleKit())
                    if (Unit* passenger = vehicle->GetPassenger(0))
                        if (Player* player = passenger->ToPlayer())
                            player->NearTeleportTo(863.672180f, 2778.023193f, 126.243454f, 0, false);
                if (me->IsAlive())
                    me->KillSelf();
               // me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }
};

enum UpUpAndAway
{
    QUEST_UP_UP_AND_AWAY            = 14244,

    SPELL_ROCKET_BLAST              = 66110,
    SPELL_SUMMON_CHARACTER_ROCKET   = 68806,
    SPELL_UUAA_KILL_CREDIT          = 68813,
    SPELL_SUMMON_GALLYWIX           = 68815,
    SPELL_SUMMON_GALLYWIX_ROCKET    = 68819,

    NPC_GALLYWIX_ROCKET             = 36514
};

// 36425
struct npc_sassy_rocket_sling : public ScriptedAI
{
    npc_sassy_rocket_sling(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_UP_UP_AND_AWAY)
            player->CastSpell(player, SPELL_SUMMON_GALLYWIX, true);
    }
};

// 36513
struct npc_gallywix_sling_rocket : public ScriptedAI
{
    npc_gallywix_sling_rocket(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        Talk(0);

        me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
        {
            Talk(1);
        }).Schedule(5s, [this](TaskContext /*context*/)
        {
            if (me->ToTempSummon())
                Talk(2, me->ToTempSummon()->GetSummoner());
        });

        me->CastSpell(me, SPELL_SUMMON_GALLYWIX_ROCKET, true);

        if (Creature* rocket = me->GetSummonedCreatureByEntry(NPC_GALLYWIX_ROCKET))
        {
            rocket->SetCanFly(true);
            rocket->SetSpeed(MOVE_FLIGHT, 21.f);
        }

        me->GetMotionMaster()->MovePoint(1, 869.895996f, 2744.302246f, 122.355782f);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == 1)
        {
            if (Creature* rocket = me->GetSummonedCreatureByEntry(NPC_GALLYWIX_ROCKET))
            {
                me->EnterVehicle(rocket);

                me->GetScheduler().Schedule(2s, [rocket](TaskContext /*context*/)
                {
                    rocket->CastSpell(rocket, SPELL_ROCKET_BLAST, true);
                    rocket->GetMotionMaster()->MovePoint(1, 907.387085f, 2662.028320f, 193.833740f);
                    rocket->DespawnOrUnsummon(5000);
                });
            }
        }
    }
};

// 196439
class gob_rocket_sling : public GameObjectAI
{
public:
    gob_rocket_sling(GameObject* go) : GameObjectAI(go) { }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (player->GetQuestStatus(QUEST_UP_UP_AND_AWAY) != QUEST_STATUS_NONE)
            player->CastSpell(player, SPELL_SUMMON_CHARACTER_ROCKET, true);

        return true;
    }
};

// 36505
struct npc_sling_rocket : public npc_escortAI
{
    npc_sling_rocket(Creature* creature) : npc_escortAI(creature) {}

    void AttackStart(Unit* /*who*/) override {}
    void EnterCombat(Unit* /*who*/) override {}
    void EnterEvadeMode(EvadeReason /*why*/) override {}
    void OnCharmed(bool /*apply*/) override {}

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            me->SetCanFly(true);
            me->SetFlying(true);
            me->SetSpeed(MOVE_FLIGHT, 21.0f);
            me->CastSpell(me, SPELL_ROCKET_BLAST, true);
            Start(false, true, who->GetGUID());
        }
    }

    void WaypointReached(uint32 pointId) override
    {
        if (pointId == 3)
        {
            if (Vehicle* vehicle = me->GetVehicleKit())
                if (Unit* passenger = vehicle->GetPassenger(0))
                    me->CastSpell(passenger, SPELL_UUAA_KILL_CREDIT, true);

            me->DespawnOrUnsummon();
        }
    }
};

// 71091
class spell_tiab_effect2 : public SpellScript
{
    PrepareSpellScript(spell_tiab_effect2);

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Player* casterPlayer = GetCaster()->ToPlayer())
            casterPlayer->KilledMonsterCredit(38024);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tiab_effect2::HandleDummy, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class npc_poule : public CreatureScript
{
public:
    npc_poule() : CreatureScript("npc_poule") { }

    struct npc_pouleAI : public ScriptedAI
    {
        npc_pouleAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->GetMotionMaster()->MoveRandom(10.0f);
        }

        void DoAction(const int32 /*param*/) override
        {
            me->CastSpell(me, 67919, true);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == 67917)
            {
                if (me->IsNonMeleeSpellCast(true))
                    me->InterruptNonMeleeSpells(true);
                if (Creature *t = me->SummonCreature(me->GetEntry(), me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ(),
                                                     me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                {
                    t->AI()->DoAction(0);
                    t->DespawnOrUnsummon(3000);
                }
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pouleAI (creature);
    }
};

#define GO_PIEGE 201972

class spell_egg_gob : public SpellScriptLoader
{
public:
    spell_egg_gob() : SpellScriptLoader("spell_egg_gob") { }

    class spell_egg_gobSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_egg_gobSpellScript);

        bool Validate(SpellInfo const* /*spellEntry*/) override
        {
            return true;
        }


        bool Load() override
        {
            if (Unit* caster = GetCastItem()->GetOwner())
            {
                if (GameObject* go = caster->FindNearestGameObject(GO_PIEGE, 5))
                {
                    if (Creature *c = go->FindNearestCreature(38187, 20))
                        c->AI()->DoAction(1);
                }
            }
            return true;
        }


        void HandleActivateGameobject(SpellEffIndex /*effIndex*/)
        {

        }


        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_egg_gobSpellScript::HandleActivateGameobject,EFFECT_0,SPELL_EFFECT_ACTIVATE_OBJECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_egg_gobSpellScript();
    }
};

class npc_raptore_gob : public CreatureScript
{
public:
    npc_raptore_gob() : CreatureScript("npc_raptore_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_raptore_gobAI(creature);
    }

    struct npc_raptore_gobAI : public ScriptedAI
    {
        npc_raptore_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            start = true;
            me->GetMotionMaster()->MoveRandom(20);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 42 && !start)
            {
                if (Player *player = me->SelectNearestPlayer(20))
                    player->SummonGameObject(201974, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, QuaternionData(), 10*IN_MILLISECONDS);
                me->Kill(me);
            }
        }

        void DoAction(const int32 param) override
        {
            if (param == 1)
            {
                if (GameObject* go = me->FindNearestGameObject(GO_PIEGE, 25))
                {
                    start = false;
                    me->CastSpell(me, 66726, true);
                    me->GetMotionMaster()->MovePoint(42, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ());
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            DoMeleeAttackIfReady();
        }

    private :
        bool start;
    };
};

class SparkSearcher
{
public:
    SparkSearcher(Creature const* source, float range) : _source(source), _range(range) {}

    bool operator()(Unit* unit)
    {
        if (!unit->IsAlive())
            return false;

        switch (unit->GetEntry())
        {
            case 38318:
                break;
            default:
                return false;
        }

        if (!unit->IsWithinDist(_source, _range, false))
            return false;

        return true;
    }

private:
    Creature const* _source;
    float _range;
};

class gob_spark_gobelin : public GameObjectScript
{
public:
    gob_spark_gobelin() : GameObjectScript("gob_spark_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->GetQuestStatus(24817) == QUEST_STATUS_INCOMPLETE)
        {
            /*if (Creature* t = player->SummonCreature(38318, go->GetPositionX(), go->GetPositionY(),  go->GetPositionZ() + 2,  go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*IN_MILLISECONDS))
            {

                std::list<Unit*> temp;
                SparkSearcher check(t, 100.0f);
                Trinity::UnitListSearcher<SparkSearcher> searcher(t, temp, check);
                Cell::VisitAllObjects(t, searcher, 25.0f);
                for (std::list<Unit*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                    if ((*itr)->ToTempSummon())
                        if ((*itr)->ToTempSummon()->GetSummoner())
                            if ((*itr)->ToTempSummon()->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
                                if ((*itr)->ToTempSummon()->GetSummoner()->GetGUID() == player->GetGUID() && (*itr)->GetGUID() != t->GetGUID())
                                    (*itr)->ToTempSummon()->DespawnOrUnsummon();
                player->EnterVehicle(t);
            }
            return true;*/
            player->KilledMonsterCredit(38318);
            player->CastSpell(nullptr, 71648);
        }
        return true;
    }
};

class npc_young_naga_gob : public CreatureScript
{
public:
    npc_young_naga_gob() : CreatureScript("npc_young_naga_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_young_naga_gobAI(creature);
    }

    struct npc_young_naga_gobAI : public ScriptedAI
    {
        npc_young_naga_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            ui_findPlayer = 1000;
            me->GetMotionMaster()->MoveRandom(5);
        }

        void UpdateAI(uint32 diff) override
        {
            if (ui_findPlayer <= diff)
            {
                if (Player *player = me->SelectNearestPlayer(10))
                {
                    if (player->HasAura(71914) && player->GetQuestStatus(24864) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (Creature *naga = player->SummonCreature(44589, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 40*IN_MILLISECONDS))
                        {
                            naga->CastSpell(naga, 71917, true);
                            naga->GetMotionMaster()->MoveFollow(player, urand (urand(urand(1, 2), urand(3, 4)), urand(5, 6)),  urand(urand(urand(1, 2), urand(3, 4)), urand(5, 6)));
                            player->KilledMonsterCredit(38413);
                        }
                        me->DespawnOrUnsummon();
                    }
                }
                ui_findPlayer = 1000;
            }
            else
                ui_findPlayer -= diff;

            DoMeleeAttackIfReady();
        }

    private :
        uint32 ui_findPlayer;

    };
};

#define SPELL_CRACK_INVOK 72058

// (Chef des nagas)
#define NAGA_SAY_A "WHO OSE?"
#define NAGA_SAY_B "Small goblins? I remember the creation of your race."
#define NAGA_SAY_C "Your threats do not impress me, nor the naga. Get ready to disappear from this reality."
#define NAGA_SAY_D  "Now, young $ N, you will die!"
//                    (Crack)
//-Quand on rend la quete d'avant
#define QUEST_RENDER_CRACK "I want to let these little demons, $ N. Nagas will never attack until we have grandchildren."

//-Quand on commence la quete
#define QUEST_RESET_CRACK "You are $ gpret, ready to force their leader to get $ gmy friend: my friend; ?"

//Quand on se rend syur place
#define CRACK_PROVOC "Come on, Chief naga, come out of your hiding and surrendered for $ N and Bilgewater Cartel!"
#define CRACK_EVADE "Hula treasure, it smells bad. I am size!"

#define NPC_CRACK 39198

class YoungNagaSearcher
{
public:
    YoungNagaSearcher(Creature const* source, float range) : _source(source), _range(range) {}

    bool operator()(Creature* creature)
    {
        if (!creature->IsAlive())
            return false;

        switch (creature->GetEntry())
        {
            case 44580:
                break;
            case 44579:
                break;
            case 44578:
                break;
            case 38412:
                break;
            default:
                return false;
        }

        if (!creature->IsWithinDist(_source, _range, false))
            return false;

        return true;
    }

private:
    Creature const* _source;
    float _range;
};

class npc_megs_isle_gob : public CreatureScript
{
public:
    npc_megs_isle_gob() : CreatureScript("npc_megs_isle_gob") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest) override
    {
        if (quest->GetQuestId() == 24868)
            player->SummonCreature(NPC_CRACK, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
        else if (quest->GetQuestId() == 24897)
            player->CastSpell(player, 68481, true);
        return true;
    }

    bool OnQuestReward(Player* player, Creature* creature, const Quest* quest, uint32 ) override
    {
        if (quest->GetQuestId() == 24864)
        {
            std::list<Creature*> temp;
            YoungNagaSearcher check(creature, 900.0f);
            Trinity::CreatureListSearcher<YoungNagaSearcher> searcher(creature, temp, check);
            Cell::VisitAllObjects(creature, searcher, 900.0f);
            for (std::list<Creature*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                if ((*itr)->ToTempSummon())
                    if ((*itr)->ToTempSummon()->GetSummoner())
                        if ((*itr)->ToTempSummon()->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
                            if ((*itr)->ToTempSummon()->GetSummoner()->GetGUID() == player->GetGUID())
                                (*itr)->DespawnOrUnsummon();
        }
        return true;
    }
};


class npc_crack_isle_gob : public CreatureScript
{
public:
  npc_crack_isle_gob() : CreatureScript("npc_crack_isle_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_crack_isle_gobAI(creature);
    }

    struct npc_crack_isle_gobAI : public ScriptedAI
    {
        npc_crack_isle_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            playerGUID = ObjectGuid::Empty;
            if (Unit *p = me->ToTempSummon()->GetSummoner())
                if (p->GetTypeId() == TYPEID_PLAYER)
                    playerGUID = p->GetGUID();
            if (playerGUID.IsEmpty())
            {
                me->DespawnOrUnsummon();
                return;
            }
            if (Player *player = ObjectAccessor::GetPlayer(*me, playerGUID))
            {
                me->GetMotionMaster()->MoveFollow(player, 1.0f, 1.0f);
                me->Say(QUEST_RESET_CRACK, LANG_UNIVERSAL, player);
            }
            else
                me->DespawnOrUnsummon();
            ui_findPlayer = 1000;
            start = false;
            event = false;
            combats = false;
            mui_event = 2000;
            event_p = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!start)
            {
                if (ui_findPlayer <= diff)
                {
                    if (Creature *zone = me->FindNearestCreature(38450, 3))
                    {
                        if (Player* player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                        {
                            me->Say(CRACK_PROVOC, LANG_UNIVERSAL, player);
                            naga = player->SummonCreature(38448, zone->GetPositionX(), zone->GetPositionY(), zone->GetPositionZ() + 2, zone->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60 * IN_MILLISECONDS);
                            if (naga)
                                naga->SetFaction(35);
                        }
                        zone->DespawnOrUnsummon();
                        start = true;
                        event = true;
                    }
                    ui_findPlayer = 1000;
                }
                else
                    ui_findPlayer -= diff;
            }
            else if (event)
            {
                if (mui_event <= diff)
                {
                    mui_event  = 4000;
                    switch (event_p)
                    {
                    case 0 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_A, LANG_UNIVERSAL, player);
                        break;
                    case 1 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_B, LANG_UNIVERSAL, player);
                        break;
                    case 2 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_C, LANG_UNIVERSAL, player);
                        break;
                    case 3 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_D, LANG_UNIVERSAL, player);
                        break;
                    default :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            me->Yell(CRACK_EVADE, LANG_UNIVERSAL, player);
                        mui_event = 2000;
                        event = false;
                        combats = true;
                        break;
                    }
                    event_p++;
                }
                else mui_event -= diff;
            }
            else if (combats)
            {
                if (mui_event <= diff)
                {
                    combats = false;
                    naga->SetFaction(14);
                    mui_event  = 4000;
                    me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());

                    naga->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    if (Player *player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        naga->JumpTo(player, 20);
                }
                else
                    mui_event -= diff;
            }
            else
            {
                if (mui_event <= diff)
                    me->DespawnOrUnsummon();
                else
                    mui_event -= diff;
            }
        }

    private :
        uint32 ui_findPlayer;
        Creature *naga;
        ObjectGuid playerGUID;
        bool start, event, combats;
        uint32 mui_event;
        int event_p;
    };
};


class npc_canon_gob : public CreatureScript
{
public:
    npc_canon_gob() : CreatureScript("npc_canon_gob") { }

    struct npc_canon_gobAI : public npc_escortAI
    {
        npc_canon_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void Reset() override
        {
            _checkQuest = 1000;
            isBoarded = false;
            CreatureAI::Reset();
        }

        void OnDamage(Unit* attacker, Unit* /*victim*/, uint32& damage, SpellInfo const* /*spellProto*/)
        {
            if (attacker->IsFriendlyTo(me))
                damage = 0;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        /*void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }*/

        void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool /*apply*/) override{}

        void UpdateEscortAI(const uint32 diff) override
        {
            if (_checkQuest <= diff)
            {
                /*if (!isBoarded)
                {
                    if (Creature *player = me->FindNearestCreature(38745,1))
                    {
                        player->EnterVehicle(me);
                        isBoarded = true;
                    }
                    else if (Creature *player = me->FindNearestCreature(38409,1))
                    {
                        player->EnterVehicle(me);
                        isBoarded = true;
                    }
                }*/
                /*else
                {
                    if (Creature *oomlot = me->FindNearestCreature(38531,80))
                    {
                        me->CastSpell(oomlot, 72206, true);
                        isBoarded = true;
                    }
                }*/
                _checkQuest = urand(7000, 13333);
            }
            else
                _checkQuest -= diff;
        }

    private :
        uint32 _checkQuest;
        bool isBoarded;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_canon_gobAI (creature);
    }
};

class npc_oom_isle_gob : public CreatureScript
{
public:
    npc_oom_isle_gob() : CreatureScript("npc_oom_isle_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oom_isle_gobAI(creature);
    }

    struct npc_oom_isle_gobAI : public ScriptedAI
    {
        npc_oom_isle_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
        }

        void OnDamage(Unit* attacker, Unit* /*victim*/, uint32& damage, SpellInfo const* /*spellProto*/)
        {
            if (attacker->IsCreature())
                damage = 0;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 72207)
            {
                if (Unit* charmer = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    if (Player* player = charmer->ToPlayer())
                    {
                        player->KilledMonsterCredit(38536);
                        //caster->Kill(me);
                    }
                }
            }
        }
    };
};

class npc_ceint : public CreatureScript
{
public:
    npc_ceint() : CreatureScript("npc_ceint") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == 24952)
        {
            player->GetMotionMaster()->MoveJump(1480.31f, 1269.97f, 110.0f, 50.0f, 50.0f, 300.0f);
            player->KilledMonsterCredit(38842);
        }
        return true;
    }

    bool OnQuestReward(Player* player, Creature* /*creature*/, const Quest* quest, uint32 ) override
    {
        if (quest->GetQuestId() == 24942)
        {
            if (Creature *c = player->FindNearestCreature(38802, 10))
            {
                player->RemoveAura(72889);
                player->RemoveAura(72885);
                c->Kill(c);
            }
        }
        return true;
    }
};

class spell_boot_gob : public SpellScriptLoader
{
public:
    spell_boot_gob() : SpellScriptLoader("spell_boot_gob") { }


    class spell_boot_gobSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_boot_gobSpellScript);

        bool Validate(SpellInfo const* /*spellEntry*/) override
        {
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* playerCaster = caster->ToPlayer())
                {
                    playerCaster->KilledMonsterCredit(38842);
                    playerCaster->GetMotionMaster()->MoveJump(1480.31f, 1269.97f, 110.0f, 50.0f, 50.0f, 300.0f);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_boot_gobSpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_boot_gobSpellScript();
    }
};

class npc_izzy_airplane : public CreatureScript
{
public:
    npc_izzy_airplane() : CreatureScript("npc_izzy_airplane") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest) override
    {
        if (quest->GetQuestId() == 25023)
        {
            //hackfix teleport since the wp isn't implemented and instead of mount the second seat the player just makes the npc dismount and gets into the first one
            player->NearTeleportTo(1581.0f, 2722.0f, 83.20f, 0, true);
            /*
            if (Creature *airplane = player->SummonCreature(38929, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),  creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
            {
                airplane->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 2, airplane, false);
                if (Creature *t = player->SummonCreature(38869, creature->GetPositionX(),  creature->GetPositionY(),  creature->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 750000))
                    t->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, airplane, false);
            }*/
        }
        return true;
    }
};

class npc_avion_gob : public CreatureScript
{
public:
    npc_avion_gob() : CreatureScript("npc_avion_gob") { }

    struct npc_avion_gobAI : public npc_escortAI
    {
        npc_avion_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 6.0f);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (apply)
                    Start(false, true, who->GetGUID());
        }

        void WaypointReached(uint32 i) override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 6.0f);
            Creature *chipie = me->FindNearestCreature(38869, 5, true);
            if (!chipie)
                return;
            switch(i)
            {
                case 1:
                    if (Player *player = me->SelectNearestPlayer(10))
                        chipie->Say("Hang on $ N! We need makes a clearance here, NOW!", LANG_UNIVERSAL, player);
                    break;
                case 4 :
                    chipie->Say("OH MY GOD! BEHIND YOU!", LANG_UNIVERSAL, 0);
                    break;
                case 8:
                    chipie->Say("WE BURN !!", LANG_UNIVERSAL, 0);
                    break;
                case 17 :
                {
                    Creature* chipie = nullptr;
                    Player* player = nullptr;
                    if (Unit *unit = me->GetVehicleKit()->GetPassenger(0))
                        chipie = unit->ToCreature();
                    if (Unit *unit = me->GetVehicleKit()->GetPassenger(1))
                        player = unit->ToPlayer();
                    if (chipie && player)
                    {
                        me->GetVehicleKit()->RemoveAllPassengers();
                        player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 3, me, false);
                        chipie->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, me, false);
                        me->RemoveAura(73149);
                    }
                    chipie->Say("Climb in the back. We're going. I know where are our old friends the orcs", LANG_UNIVERSAL, 0);
                    break;
                }
                case 26 :
                {
                    me->GetVehicleKit()->RemoveAllPassengers();
                    if (Creature *chip = me->FindNearestCreature(38869, 5, true))
                        chip->DespawnOrUnsummon();
                    me->DespawnOrUnsummon();
                    break;
                }
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_avion_gobAI (creature);
    }
};


class npc_tremblement_volcano : public CreatureScript
{
public:
    npc_tremblement_volcano() : CreatureScript("npc_tremblement_volcano") { }

    struct npc_tremblement_volcanoAI : public ScriptedAI
    {
        npc_tremblement_volcanoAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            mui_soufle = 2000;
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (mui_soufle <= diff)
            {
                me->CastSpell(me, 69235, true);
                mui_soufle = 3000;
            }
            else
                mui_soufle -= diff;
        }

    private :
        uint32 mui_soufle;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tremblement_volcanoAI (creature);
    }
};

class npc_meteor2_gob : public CreatureScript
{
public:
    npc_meteor2_gob() : CreatureScript("npc_meteor2_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_meteor2_gobAI(creature);
    }

    struct npc_meteor2_gobAI : public ScriptedAI
    {
        npc_meteor2_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            _a = urand(15000, 20200);
            _b = 600000;
            _c = 600000;
        }

        void JustReachedHome() override
        {

        }

        void UpdateAI(uint32 diff) override
        {
            if (_a <= diff)
            {
                me->CastSpell(me, 93668, true);
                _a = urand(15000, 20200);
                _b = 800;
            }
            else _a -= diff;
            if (_b <= diff)
            {
                me->CastSpell(me, 87701, true);
                _b = 600000;
                _c = 500;
            }
            else _b -= diff;
            if (_c <= diff)
            {
                me->CastSpell(me, 69235, true);
                _c = 600000;
            }
            else _c -= diff;
        }

    private :
        uint32 _a, _b, _c;
    };
};

class npc_explosion_volcano : public CreatureScript
{
public:
    npc_explosion_volcano() : CreatureScript("npc_explosion_volcano") { }

    struct npc_explosion_volcanoAI : public ScriptedAI
    {
        npc_explosion_volcanoAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            mui_soufle = urand(1100, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (mui_soufle <= diff)
            {
                me->CastSpell(me, 73193, true);
                mui_soufle = urand(4000, 5200);
            }
            else
                mui_soufle -= diff;
        }

    private :
        uint32 mui_soufle;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_explosion_volcanoAI (creature);
    }
};



class npc_killag_2 : public CreatureScript
{
public:
    npc_killag_2() : CreatureScript("npc_killag_2") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest) override
    {
        if (quest->GetQuestId() == 25100)
        {
            //just tp instead of wp
            player->NearTeleportTo(1831.0f, 1959.0f, 220.92f, 3.75f);

            //if (Creature *pant = player->SummonCreature(39152, player->GetPositionX(), player->GetPositionY(),
            //                                           player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
            //    player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, pant, false);
        }
        return true;
    }
};

class npc_Chariot : public CreatureScript
{
public:
    npc_Chariot() : CreatureScript("npc_Chariot") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == 25184)
        {
            if (Creature *chariot = player->SummonCreature(39329, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),  creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
            {
                int cnt = 1;
                chariot->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, chariot, false);
                for (Unit::ControlList::iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                    if ((*itr)->GetTypeId() == TYPEID_UNIT && ((*itr)->GetEntry() == 34957 || (*itr)->GetEntry() == 39199 || (*itr)->GetEntry() == 34959 || (*itr)->GetEntry() == 39205))
                    {
                        cnt++;
                        (*itr)->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, cnt, chariot, false);
                    }
                CAST_AI(npc_escortAI, (chariot->AI()))->Start(false, true, player->GetGUID(), quest);
            }
        }
        return true;
    }
};

class npc_Chariot2 : public CreatureScript
{
public:
    npc_Chariot2() : CreatureScript("npc_Chariot2") { }

    struct npc_Chariot2AI : public npc_escortAI
    {
        npc_Chariot2AI(Creature* creature) : npc_escortAI(creature) {}

        uint32 krennansay;
        bool AfterJump;
        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_UNIT)
                if (!apply)
                    who->ToCreature()->DespawnOrUnsummon();
        }

        void WaypointReached(uint32 i) override
        {
            switch(i)
            {
            case 33:
                me->GetVehicleKit()->RemoveAllPassengers();
                if (Creature *t = me->SummonCreature(41505, me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ(),  me->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
                {
                    t->CastSpell(t, 93569, true);
                    t->CastSpell(t, 71094, true);
                    //set phase 184

                }
                me->DespawnOrUnsummon();
                if (Unit *player = me->ToTempSummon()->GetSummoner())
                {
                    player->GetMotionMaster()->MoveJump(2354.36f, 1943.21f, 24.0f, 0.0f, 20.0f, 20.0f);
                    if (Player* creditTo = player->ToPlayer())
                        creditTo->KilledMonsterCredit(39335);
                }
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Chariot2AI (creature);
    }
};

class gob_red_but : public GameObjectScript
{
public:
    gob_red_but() : GameObjectScript("gob_red_but") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(25207) == QUEST_STATUS_INCOMPLETE)
        {
            if (player->GetPhaseShift().HasPhase(32768))
                return false;

            player->CastSpell(player, 69077, true);
            player->AddAura(90418, player);
            player->KilledMonsterCredit(39393);
            if (Creature *t = player->SummonCreature(41505, 2477.0f, 2082.0f,  14.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                PhasingHandler::AddPhase(t, 32768);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            if (Creature *t = player->SummonCreature(41505, 2499.28f, 2091.48f,  17.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                PhasingHandler::AddPhase(t, 32768);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            if (Creature *t = player->SummonCreature(41505, 2450.424f, 2068.89f,  28.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                PhasingHandler::AddPhase(t, 32768);
                t->SetCanFly(true);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            return true;
        }
        return true;
    }
};

class npc_grilly_2 : public CreatureScript
{
public:
    npc_grilly_2() : CreatureScript("npc_grilly_2") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest) override
    {
        if (quest->GetQuestId() == 25213)
        {
            if (Creature *pant = player->SummonCreature(47956, player->GetPositionX(), player->GetPositionY(),
                                                        player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, pant, false);
        }
        return true;
    }
};

class npc_Prince : public CreatureScript
{
public:
    npc_Prince() : CreatureScript("npc_Prince") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_PrinceAI(creature);
    }

    struct npc_PrinceAI : public ScriptedAI
    {
        npc_PrinceAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            eventTalk = 0;
            eventTalk2 = 0;
            mui_talk = 2000;
            mui_talk2 = 2000;
            isEventInProgress = false;
            start = false;
            end = false;
            mui1 = 10000;
            mui2 = 30000;
            mui3 = 50000;
            mui4 = 40000;
            mui5 = 60000;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (isEventInProgress)
                return;
            if (who->ToPlayer())
                return;
            if (!me->IsWithinDistInMap(who, 5.0f))
                return ;
            if (end)
                return;
            if (who->GetEntry() == 39592)
            {
                isEventInProgress = true;
                me->SetFaction(14);
                //Talk(-1039585, me);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (end)
            {
                damage = 0;
                return;
            }
            if (damage >= me->GetHealth())
            {
                damage = 0;
                me->SetFaction(35);
                //Talk(-1039588, me);
                end = true;
                if (Creature *c = me->FindNearestCreature(39592, 30))
                    c->DespawnOrUnsummon();
                if (Player *pl = me->SelectNearestPlayer(10))
                    pl->KilledMonsterCredit(39582);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!isEventInProgress)
                return;
            if (end)
            {
                if (mui_talk <= diff)
                {
                    mui_talk = 10000;
                    switch (eventTalk)
                    {
                        case 0 :
                            //          Talk(-1039590, me);
                            break;
                        case 1 :
                            /*if (Creature *c = me->FindNearestCreature(39594, 30))
                            {
                                //              Talk(-1039591, c);
                            }*/
                            break;
                        case 2 :
                            //          Talk(-1039589, me);
                            break;
                        case 3 :
                            /*if (Creature *c = me->FindNearestCreature(39594, 30))
                            {
                                //              Talk(-1039592, c);
                            }*/
                            break;
                        case 4 :
                            /*if (Creature *c = me->FindNearestCreature(39594, 30))
                            {
                                //              Talk(-1039593, c);
                            }*/
                            break;
                        case 5 :
                            me->DespawnOrUnsummon();
                            if (Creature *c = me->FindNearestCreature(39594, 30))
                            {
                                c->DespawnOrUnsummon();
                            }
                            break;
                        default :
                            break;
                    }
                    eventTalk++;
                }
                else
                    mui_talk -= diff;
            }
            else
            {
                if (!me->GetVictim())
                    return;
                if (mui1 <= diff)
                {
                    switch (urand(0, 4))
                    {
                    case 0 :
                        me->CastSpell(me->GetVictim(), 74005, true);
                        //          Talk(-1039583, me);
                        break;
                    case 1 :
                        me->CastSpell(me->GetVictim(), 74000, true);
                        //          Talk(-1039584, me);
                        break;
                    case 2 :
                        me->CastSpell(me->GetVictim(), 74004, true);
                        //          Talk(-1039586, me);
                        break;
                    case 3 :
                        me->CastSpell(me->GetVictim(), 81000, true);
                        //          Talk(-1039582, me);
                        break;
                    case 4 :
                        me->CastSpell(me->GetVictim(), 74003, true);
                        break;
                    default :
                        me->CastSpell(me->GetVictim(), 74003, true);
                        break;
                    }
                    mui1 = 5000;
                }
                else
                    mui1 -= diff;
            }
            DoMeleeAttackIfReady();
        }

    private :
        bool isEventInProgress, start, end;
        uint32 mui_talk, mui_talk2, mui1, mui2, mui3, mui4, mui5;
        unsigned int eventTalk, eventTalk2;
    };
};


class npc_boot : public CreatureScript
{
public:
  npc_boot() : CreatureScript("npc_boot") { }

  bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest) override
  {
    if (quest->GetQuestId() == 25265)
    {
        player->AddAura(72971, player);
        player->CastSpell(player, 67789, true);
        player->AddAura(90418, player);
        player->GetMotionMaster()->MoveJump(2352.31f, 2483.97f, 13.0f, 15.0f, 20.0f, 150.0f);
    }

    if (quest->GetQuestId() == 25066)
    {
        player->CastSpell(nullptr, 73430);
        if (Unit* vehicle = player->FindNearestCreature(39074, 50.0, true))
        {
            vehicle->SetUnitMovementFlags(75497984);
            vehicle->SetExtraUnitMovementFlags(276);

            vehicle->SetFlying(true);
            vehicle->CanFly();
            vehicle->SetCanTransitionBetweenSwimAndFly(true);
        }
        /*if (Creature *t = player->SummonCreature(39074, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),
                                                 player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
        {
            player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
            t->SetCanFly(true);
            t->SetSpeed(MOVE_FLIGHT, 6.0f);
        }*/
    }

    if (quest->GetQuestId() == 25251)
    {
        if (Creature *t = player->SummonCreature(39592, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(),
            player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3 * IN_MILLISECONDS))
            t->setActive(1);
            //player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
        //player->CastSpell(nullptr, 73989);

    }

    return true;
  }

  bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
  {
      if (player->HasQuest(25066))
      {
          player->CastSpell(nullptr, 73430);
          if (Unit* vehicle = player->FindNearestCreature(39074, 50.0, true))
          {
              vehicle->SetCanFly(true);
              vehicle->SetSpeed(MOVE_FLIGHT, 6.0f);
              vehicle->SetUnitMovementFlags(75497984);
              vehicle->SetExtraUnitMovementFlags(276);
          }
      }
      else if (player->HasQuest(25266))
      {
          player->TeleportTo(1468, Position(-5012.0f, 13.0f, 3.26f));
      }
      return true;
  }
};

class npc_flying_bomber : public npc_escortAI
{
public:
    npc_flying_bomber(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetSpeed(MOVE_FLIGHT, 26);
        me->SetSpeed(MOVE_RUN, 26);
        me->SetSpeed(MOVE_WALK, 26);
    }

    void OnCharmed(bool /*apply*/) override
    {
        // Make sure the basic cleanup of OnCharmed is done to avoid looping problems
        if (me->NeedChangeAI)
            me->NeedChangeAI = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }
};


class BootSearcher
{
public:
    bool operator()(WorldObject* object)
    {
        if (!object)
            return true;
        Unit* unit = object->ToUnit();
        if (!unit || !unit->IsAlive() || unit->GetTypeId() == TYPEID_PLAYER)
            return true;

        if (unit->ToCreature())
        {
            switch (unit->ToCreature()->GetEntry())
            {
                case 38753:
                    return false;
                default:
                    break;
            }
        }
        return true;
    }
};

class gob_fronde_gobelin : public GameObjectScript
{
public:
    gob_fronde_gobelin() : GameObjectScript("gob_fronde_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(14244) != QUEST_STATUS_NONE)
        {
            if (Creature *t = player->SummonCreature(36514, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ() + 7, go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
            return true;
        }
        return true;
    }
};

class gob_dyn_gobelin : public GameObjectScript
{
public:
    gob_dyn_gobelin() : GameObjectScript("gob_dyn_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(14245) != QUEST_STATUS_NONE)
        {
            player->CastSpell(player, 68935, true);
            if (Creature *t = player->SummonCreature(9100000, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ() + 2, go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30 * IN_MILLISECONDS))
            {
               // t->SetPhaseMask(4, true);
                t->CastSpell(t, 71093, true);
                t->CastSpell(t, 71095, true);
                t->CastSpell(t, 71096, true);
                t->CastSpell(t, 71097, true);
            }
            return true;
        }
        return true;
    }
};

class npc_fusee_gob : public CreatureScript
{
public:
    npc_fusee_gob() : CreatureScript("npc_fusee_gob") { }

    struct npc_fusee_gobAI : public npc_escortAI
    {
        npc_fusee_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            me->SetCanFly(true);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
                Start(false, true, who->GetGUID());
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 5.0f);
        }

        void WaypointReached(uint32 i) override
        {
            if (i == 3)
            {
                me->CastSpell(me, 66127, true);
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fusee_gobAI(creature);
    }
};

class npc_girocoptere : public CreatureScript
{
public:
    npc_girocoptere() : CreatureScript("npc_girocoptere") { }

    struct npc_girocoptereAI : public npc_escortAI
    {
        npc_girocoptereAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            _checkQuest = 1000;
            isBoarded = false;
        }

        void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool /*apply*/) override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
        }

        void WaypointReached(uint32 i) override
        {
            me->SetCanFly(true);
            switch (i)
            {
            case 19:
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon();
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {

        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }

        void UpdateEscortAI(const uint32 /*diff*/) override
        {
        }

    private:
        uint32 _checkQuest;
        bool isBoarded;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_girocoptereAI(creature);
    }
};

class npc_gyrocoptere_quest_giver : public CreatureScript
{
public:
    npc_gyrocoptere_quest_giver() : CreatureScript("npc_gyrocoptere_quest_giver") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 14242)
        {
            if (Creature *t = player->SummonCreature(39074, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(),
                creature->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
            {
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
                CAST_AI(npc_escortAI, (t->AI()))->Start(false, true, player->GetGUID(), _Quest);
                t->AI()->Talk(SAY_GYRO, player);
            }
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14242) != QUEST_STATUS_NONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Would you take a gyrocopter?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

};

class npc_phaseswift : public CreatureScript
{
public:
    npc_phaseswift() : CreatureScript("npc_phaseswift") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_phaseswiftAI(creature);
    }

    struct npc_phaseswiftAI : public ScriptedAI
    {
        npc_phaseswiftAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            mui_talk = 5000;
            cnt = 6;
        }

        void DoAction(const int32 /*param*/) override
        {
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* /*spell*/) override
        {
        }

        void JustReachedHome() override
        {

        }

        void MovementInform(uint32 /*type*/, uint32 /*id*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (mui_talk <= diff)
            {
                if (Unit *p = me->ToTempSummon()->GetSummoner())
                    if (Player* player = p->ToPlayer())
                    {
                        std::set<uint32> terrainswap;
                        std::set<uint32> phaseId;
                        std::set<uint32> worldMapAreaSwap;
                        terrainswap.insert(661);
                        phaseId.insert(180);
                        player->CastSpell(p->ToPlayer(), 68750, true);
                        player->KilledMonsterCredit(38024);
                        //player->GetSession()->SendSetPhaseShift(phaseId, terrainswap, worldMapAreaSwap);
                    }
                me->DespawnOrUnsummon();
                mui_talk = 6000;
            }
            else
                mui_talk -= diff;
        }

    private:
        uint32 mui_talk;
        int cnt;
    };
};

#define FLASH_EFFECT 70649

class spell_68281 : public SpellScriptLoader
{
public:
    spell_68281() : SpellScriptLoader("spell_68281") { }

    class  spell_68281SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_68281SpellScript);

        bool Validate(SpellInfo const* /*spellEntry*/) override
        {
            st = false;
            st2 = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleBeforeHit(SpellMissInfo /*missInfo*/)
        {
            if (st2)
                return;

            if (GetCastItem())
                if (Unit* caster = GetCastItem()->GetOwner())
                    caster->CastSpell(caster, FLASH_EFFECT, true);
            st2 = true;
        }

        void HandleAfterHit()
        {
            if (st)
                return;
            st = true;
        }

        void Unload() override
        {
            if (GetCastItem())
                if (Unit* caster = GetCastItem()->GetOwner())
                    caster->RemoveAura(FLASH_EFFECT);
        }

    private:
        bool st, st2;

        void Register() override
        {
            BeforeHit += BeforeSpellHitFn(spell_68281SpellScript::HandleBeforeHit);
            AfterHit += SpellHitFn(spell_68281SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_68281SpellScript();
    }
};

void AddSC_lost_isle()
{
    RegisterSpellScript(spell_lost_isles_near_death);
    RegisterCreatureAI(npc_zapnozzle);
    RegisterGameObjectAI(gob_goblin_escape_pod);
    RegisterCreatureAI(npc_goblin_espace_pod);
    RegisterCreatureAI(npc_bomb_monkey);
    RegisterCreatureAI(npc_foreman_dampwick);
    RegisterCreatureAI(npc_frightened_miner_escort);
    RegisterSpellScript(spell_ctu_snapflash);
    RegisterSpellScript(spell_ctu_bind_sight);
    RegisterCreatureAI(npc_lost_isles_weed);
    RegisterSpellScript(spell_weed_whacker);
    RegisterCreatureAI(npc_killag_sangrecroc);
    RegisterAuraScript(aura_infrared_orc_scout);
    RegisterCreatureAI(npc_cliff_bastia);
    RegisterCreatureAI(npc_gyrocopterequest_giver);
    RegisterCreatureAI(npc_precious_cargo_gyrocopter);
    RegisterCreatureAI(npc_lost_isles_thrall_prisonner);
    RegisterCreatureAI(npc_lost_isles_thrall_top_boat);
    RegisterCreatureAI(npc_warchief_revenge_cyclone);
    RegisterCreatureAI(npc_sassy_rocket_sling);
    RegisterCreatureAI(npc_gallywix_sling_rocket);
    RegisterGameObjectAI(gob_rocket_sling);
    RegisterCreatureAI(npc_sling_rocket);
    RegisterSpellScript(spell_tiab_effect2);
    new npc_poule();
    new npc_raptore_gob();
    new gob_spark_gobelin();
    new npc_young_naga_gob();
    new npc_megs_isle_gob();
    new npc_crack_isle_gob();
    new npc_canon_gob();
    new npc_fusee_gob();
    new spell_boot_gob();
    new npc_oom_isle_gob();
    new npc_ceint();
    new npc_izzy_airplane();
    new npc_avion_gob();
    new npc_meteor2_gob();
    new npc_tremblement_volcano();
    new npc_explosion_volcano();
    new npc_killag_2();
    new npc_Chariot();
    new npc_Chariot2();
    new gob_red_but();
    new gob_fronde_gobelin();
    new gob_dyn_gobelin();
    new npc_grilly_2();
    new npc_Prince();
    new npc_boot();
    new npc_girocoptere();
    new npc_gyrocoptere_quest_giver();
    new npc_phaseswift();
    RegisterCreatureAI(npc_flying_bomber);
    new spell_68281();
}
