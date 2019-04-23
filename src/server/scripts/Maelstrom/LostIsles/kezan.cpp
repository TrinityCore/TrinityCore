/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010 - 2012 Project SkyFire <http://www.projectskyfire.org/>
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

#include "Creature.h"
#include "CreatureTextMgr.h"
#include "CreatureTextMgrImpl.h"
#include "GameObject.h"
#include "Item.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Vehicle.h"
#include "WorldSession.h"

enum NPC_DeffiantTroll
{
    SPELL_RAGE                      = 45111,
    SPELL_SLEEP                     = 62248,
    DEFFIANT_KILL_CREDIT            = 34830,
    SPELL_GOBLIN_BELT_SHOCKER       = 66306,
    QUEST_GOOD_HELP_IS_HARD_TO_FIND = 14069,
    GO_DEPOSIT                      = 195489,
    GO_DEPOSIT_2                    = 195488,
    GO_DEPOSIT_CHUNK                = 195492,
};

// 34830
struct npc_defiant_troll : public ScriptedAI
{
    npc_defiant_troll(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        rebuffTimer = 5000;
    }

    void MovementInform(uint32 /*type*/, uint32 /*id*/) override
    {
        me->HandleEmoteCommand(EMOTE_STATE_WORK_MINING);
        me->LoadEquipment(3, true);
    }

    void JustReachedHome() override { }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!me->HasAura(SPELL_RAGE))
            return;

        if (spell->Id == SPELL_GOBLIN_BELT_SHOCKER && caster->IsPlayer()
            && caster->ToPlayer()->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE)
        {
            caster->ToPlayer()->KilledMonsterCredit(DEFFIANT_KILL_CREDIT, me->GetGUID());
            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
            me->RemoveAllAuras();

            Talk(urand(0, 6), caster);

            if (GameObject* Deposit = me->FindNearestGameObject(GO_DEPOSIT, 20.f))
                me->GetMotionMaster()->MovePoint(1, Deposit->GetPositionX() - 2.f, Deposit->GetPositionY(), Deposit->GetPositionZ());
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasAura(SPELL_RAGE))
            return;

        if (rebuffTimer <= diff)
        {
            switch (irand(0, 2))
            {
                case 0:
                    me->HandleEmoteCommand(EMOTE_STATE_EXCLAIM);
                    break;
                case 1:
                    me->HandleEmoteCommand(EMOTE_STATE_DANCE);
                    break;
                case 2:
                    me->AddAura(SPELL_SLEEP, me);
                    break;
            }

            me->LoadEquipment(urand(1, 2), true);
            rebuffTimer = 60000; //Rebuff again in 1 minutes
            me->NearTeleportTo(me->GetHomePosition());
            me->AddAura(SPELL_RAGE, me);
        }
        else
            rebuffTimer -= diff;
    }

private:
    uint32 rebuffTimer;
};

enum QuestRollingMyHomies
{
    QUEST_ROLLING_WITH_MY_HOMIES            = 14071,
    OBJECTIVE_IZZY_PICKED_UP                = 265516,
    OBJECTIVE_ACE_PICKED_UP                 = 265517,
    OBJECTIVE_GOBBER_PICKED_UP              = 265518,

    NPC_HOT_ROD                             = 34840,

    NPC_IZZY                                = 34890,
    NPC_ACE                                 = 34892,
    NPC_GOBBER                              = 34954,

    NPC_IZZY_SUMMON                         = 34959,
    NPC_ACE_SUMMON                          = 34957,
    NPC_GOBBER_SUMMON                       = 34958,

    SPELL_GENERIC_INVISIBILITY_DETECTION_1  = 49416,
    SPELL_GENERIC_INVISIBILITY_DETECTION_2  = 49417,
    SPELL_GENERIC_INVISIBILITY_DETECTION_3  = 60922,
    SPELL_GENERIC_INVISIBILITY_DETECTION_4  = 90161,

    SPELL_SUMMON_ACE                        = 66597,
    SPELL_SUMMON_GOBBER                     = 66599,
    SPELL_SUMMON_IZZY                       = 66600,

    SPELL_RESUMMON_ACE                      = 66644,
    SPELL_RESUMMON_GOBBER                   = 66645,
    SPELL_RESUMMON_IZZY                     = 66646,

    SPELL_HOT_ROD_KNOCKBACK                 = 66301,

    ACTION_HOMIES_ENTER_VEHICLE             = 1,
};

std::unordered_map<uint32, std::tuple<uint32, uint32>> const seatPerHomie =
{
    { NPC_ACE_SUMMON,       { 1, SPELL_RESUMMON_ACE }       },
    { NPC_GOBBER_SUMMON,    { 2, SPELL_RESUMMON_GOBBER }    },
    { NPC_IZZY_SUMMON,      { 3, SPELL_RESUMMON_IZZY }      },
};

std::unordered_map<uint32, std::tuple<uint32, uint32, uint32>> const objectiveAndSpellsPerHomie =
{
    { NPC_ACE,      { OBJECTIVE_ACE_PICKED_UP,      SPELL_SUMMON_ACE,       SPELL_GENERIC_INVISIBILITY_DETECTION_1 } },
    { NPC_GOBBER,   { OBJECTIVE_GOBBER_PICKED_UP,   SPELL_SUMMON_GOBBER,    SPELL_GENERIC_INVISIBILITY_DETECTION_2 } },
    { NPC_IZZY,     { OBJECTIVE_IZZY_PICKED_UP,     SPELL_SUMMON_IZZY,      SPELL_GENERIC_INVISIBILITY_DETECTION_3 } },
};

// 14071
class quest_rolling_with_my_homies : public QuestScript
{
public:
    quest_rolling_with_my_homies() : QuestScript("quest_rolling_with_my_homies") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, SPELL_GENERIC_INVISIBILITY_DETECTION_1, true);
            player->CastSpell(player, SPELL_GENERIC_INVISIBILITY_DETECTION_2, true);
            player->CastSpell(player, SPELL_GENERIC_INVISIBILITY_DETECTION_3, true);
        }
    }
};

// 34840
struct npc_hot_rod_rolling_my_homies : public ScriptedAI
{
    npc_hot_rod_rolling_my_homies(Creature* creature) : ScriptedAI(creature) {}

    void OnCharmed(bool /*apply*/) override { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (me->IsSummon() && apply)
        {
            Player* player = who->ToPlayer();
            if (!player)
                return;

            me->GetScheduler().Schedule(250ms, [this, player](TaskContext context)
            {
                if (me->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FORWARD))
                    player->CastSpell(nullptr, SPELL_HOT_ROD_KNOCKBACK, true);

                context.Repeat();
            });

            for (auto itr : seatPerHomie)
            {
                if (Creature* homie = player->GetSummonedCreatureByEntry(itr.first))
                    homie->AI()->DoAction(ACTION_HOMIES_ENTER_VEHICLE);
                else if (player->GetQuestStatus(QUEST_ROLLING_WITH_MY_HOMIES) == QUEST_STATUS_REWARDED)
                {
                    uint32 seatId, resummonSpellId;
                    std::tie(seatId, resummonSpellId) = itr.second;
                    player->CastSpell(nullptr, resummonSpellId, true);
                }
            }
        }
    }
};

class spell_klaxon : public SpellScript
{
    PrepareSpellScript(spell_klaxon);

    void HandleOnHit()
    {
        if (Unit* owner = GetCaster()->GetOwner())
            if (Player* player = owner->ToPlayer())
                GetCaster()->PlayDirectSound(22491, player);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_klaxon::HandleOnHit);
    }
};

#define RADIO 23406

class spell_radio : public SpellScript
{
    PrepareSpellScript(spell_radio);

    void HandleOnHit()
    {
        if (Unit* caster = GetCaster()->GetOwner())
            if (caster->IsPlayer())
                GetCaster()->PlayDistanceSound(RADIO, caster->ToPlayer());
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_radio::HandleOnHit);
    }
};

// 34892 Ace
// 34954 Gobber
// 34890 Izzy
struct npc_homies : public ScriptedAI
{
    npc_homies(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetEntry() != NPC_HOT_ROD || !who->IsVehicle())
            return;

        Unit* driver = who->GetVehicleKit()->GetPassenger(0);
        if (!driver)
            return;

        Player* player = driver->ToPlayer();
        if (!player)
            return;

        if (player->GetQuestStatus(QUEST_ROLLING_WITH_MY_HOMIES) != QUEST_STATUS_INCOMPLETE)
            return;

        if (me->GetDistance(player) > 10.f)
            return;

        uint32 objectiveId, summonSpell, invisibilityDetectionSpell;
        std::tie(objectiveId, summonSpell, invisibilityDetectionSpell) = objectiveAndSpellsPerHomie.at(me->GetEntry());

        if (player->GetQuestObjectiveCounter(objectiveId))
            return;

        player->RemoveAurasDueToSpell(invisibilityDetectionSpell);
        player->CastSpell(nullptr, summonSpell, true);
    }
};

// 34957 Ace Summon
// 34958 Gobber Summon
// 34959 Izzy Summon
struct npc_homies_summon : public ScriptedAI
{
    npc_homies_summon(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        if (me->IsSummon())
        {
            if (Unit* owner = me->ToTempSummon()->GetOwner())
            {
                if (Player* player = owner->ToPlayer())
                    player->KilledMonsterCredit(me->GetEntry());

                DoAction(ACTION_HOMIES_ENTER_VEHICLE);
            }
        }
    }

    void DoAction(int32 /*action*/) override
    {
        if (me->IsSummon())
        {
            if (Unit* owner = me->ToTempSummon()->GetOwner())
            {
                if (Vehicle* vehicle = owner->GetVehicle())
                {
                    uint32 seatId, resummonSpellId;
                    std::tie(seatId, resummonSpellId) = seatPerHomie.at(me->GetEntry());
                    me->EnterVehicle(vehicle->GetBase(), seatId);
                }
            }
        }
    }
};

enum NPC_BlingBling
{
    SPELL_OUTFIT            = 66781,
    SPELL_COOL_SHADE        = 66782,
    SPELL_SHINY_BLING       = 66780,
    QUEST_BLINGBLING_MALE   = 14109,
    QUEST_BLINGBLING_FEMALE = 14110,
    NPC_SCABO               = 35128,
    NPC_MISSA               = 35130,
    NPC_DIASTEME            = 35126,
};

class npc_bling_bling : public CreatureScript
{
public:
    npc_bling_bling() : CreatureScript("npc_bling_bling") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (player->GetQuestStatus(QUEST_BLINGBLING_MALE) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_BLINGBLING_FEMALE) == QUEST_STATUS_INCOMPLETE)
        {
            switch (creature->GetEntry())
            {
                case NPC_SCABO:
                    player->CastSpell(player, SPELL_OUTFIT, true);
                    break;
                case NPC_MISSA:
                    player->CastSpell(player, SPELL_COOL_SHADE, true);
                    break;
                case NPC_DIASTEME:
                    player->CastSpell(player, SPELL_SHINY_BLING, true);
                    break;
                default:
                    break;
            }

            return true;
        }

        return false;
    }
};

enum KezanPartygoer: uint32
{
    QUEST_LIFE_OF_THE_PARTY_MALE    = 14113,
    QUEST_LIFE_OF_THE_PARTY_FEMALE  = 14153,

    NPC_PARTYGOER_KILLCREDIT        = 35175,

    SPELL_AWESOME_PARTY_ENSEMBLE    = 66908,
    SPELL_LOTP_OUTFIT_FEMALE        = 66927,
    SPELL_LOTP_OUTFIT_MALE          = 66928,

    SPELL_HAPPY_PARTYGOER           = 66916,
    SPELL_COSMETIC_STUN             = 46957,
    SPELL_COSMETIC_DRUNKEN          = 55664,
    SPELL_FIREWORKS_BLUE            = 66917,
    SPELL_FIREWORKS_GREEN           = 66918,
    SPELL_FIREWORKS_RED             = 66919,
    SPELL_SUMMON_DISCO_BALL         = 66930,
    SPELL_SUMMON_BUCKET             = 66931,

    SPELL_DRINK                     = 66909,
    SPELL_BUCKET                    = 66910,
    SPELL_DANCE                     = 66911,
    SPELL_FIREWORKS                 = 66912,
    SPELL_FOOD                      = 66913,

    SPELL_NEED_DRINK                = 75042,
    SPELL_NEED_BUCKET               = 75044,
    SPELL_NEED_DANCE                = 75046,
    SPELL_NEED_FIREWORKS            = 75048,
    SPELL_NEED_FOOD                 = 75050,

    TALK_NEED_DANCE                 = 0,
    TALK_NEED_BUCKET                = 1,
    TALK_NEED_DRINK                 = 2,
    TALK_NEED_FIREWORKS             = 3,
    TALK_NEED_FOOD                  = 4,

    TALK_DRINK                      = 5,
    TALK_BUCKET                     = 6,
    TALK_DANCE                      = 7,
    TALK_FIREWORKS                  = 8,
    TALK_FOOD                       = 9,
};

// 35175
// 35186
struct npc_kezan_partygoer : public ScriptedAI
{
    npc_kezan_partygoer(Creature* creature) : ScriptedAI(creature) { }

    std::vector<std::tuple<uint32, uint32, uint32, uint32>> const talkAndSpells =
    {
        { SPELL_DRINK,      SPELL_NEED_DRINK,       TALK_NEED_DRINK,        TALK_DRINK      },
        { SPELL_BUCKET,     SPELL_NEED_BUCKET,      TALK_NEED_BUCKET,       TALK_BUCKET     },
        { SPELL_DANCE,      SPELL_NEED_DANCE,       TALK_NEED_DANCE,        TALK_DANCE      },
        { SPELL_FIREWORKS,  SPELL_NEED_FIREWORKS,   TALK_NEED_FIREWORKS,    TALK_FIREWORKS  },
        { SPELL_FOOD,       SPELL_NEED_FOOD,        TALK_NEED_FOOD,         TALK_FOOD       },
    };

    void Reset() override
    {
        ApplyNeedAura();
    }

    void ApplyNeedAura()
    {
        _selectedNeed = urand(0, 4);
        uint32 needAura = std::get<1>(talkAndSpells[_selectedNeed]);
        me->AddAura(needAura);
        me->RemoveAura(SPELL_HAPPY_PARTYGOER);

        // Specific cosmetics
        switch (needAura)
        {
            case SPELL_NEED_BUCKET:
                me->AddAura(SPELL_COSMETIC_STUN);
                me->AddAura(SPELL_COSMETIC_DRUNKEN);
                break;
            default:
                break;
        }

        me->GetScheduler().Schedule(10s, 120s, [this](TaskContext context)
        {
            Talk(std::get<2>(talkAndSpells[_selectedNeed]));
            context.Repeat(10s, 120s);
        });
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (me->HasAura(SPELL_HAPPY_PARTYGOER))
            return;

        if (spell->Id != std::get<0>(talkAndSpells[_selectedNeed]))
            return;

        Player* player = caster->ToPlayer();
        if (!player)
            return;

        if ((player->GetQuestStatus(QUEST_LIFE_OF_THE_PARTY_MALE)   != QUEST_STATUS_INCOMPLETE &&
            player->GetQuestStatus(QUEST_LIFE_OF_THE_PARTY_FEMALE) != QUEST_STATUS_INCOMPLETE))
            return;

        me->RemoveAllAuras();
        Talk(std::get<3>(talkAndSpells[_selectedNeed]), caster);
        me->AddAura(SPELL_HAPPY_PARTYGOER);
        player->KilledMonsterCredit(NPC_PARTYGOER_KILLCREDIT);

        // Specific cosmetics
        switch (spell->Id)
        {
            case SPELL_BUCKET:
                me->CastSpell(nullptr, SPELL_SUMMON_BUCKET, true);
                break;
            case SPELL_DANCE:
                me->CastSpell(nullptr, SPELL_SUMMON_DISCO_BALL, true);
                break;
            default:
                break;
        }

        me->GetScheduler().CancelAll();
        me->GetScheduler().Schedule(30s, [this](TaskContext /*context*/)
        {
            ApplyNeedAura();
        });
    }

private:
    int8 _selectedNeed;
};

// 66912
class spell_kezan_fireworks : public SpellScript
{
    PrepareSpellScript(spell_kezan_fireworks);

    void HandleFireworks(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, RAND(SPELL_FIREWORKS_BLUE, SPELL_FIREWORKS_GREEN, SPELL_FIREWORKS_RED), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kezan_fireworks::HandleFireworks, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum GreatBankHeist
{
    NPC_FBOK_VAULT              = 35486,

    SPELL_CONTROL_VEHICLE       = 67476,
    SPELL_BLASTCRACKERS         = 67508,
    SPELL_KAJAMITE_DRILL        = 67522,
    SPELL_EAR_O_SCOPE           = 67524,
    SPELL_INFINIFOLD_LOCKPICK   = 67525,
    SPELL_AMAZIN_G_RAY          = 67526,

    SPELL_POWER_CORRECT         = 67493,
    SPELL_POWER_INCORRECT       = 67494,

    SPELL_TIMER                 = 67502,

    SPELL_SUCCESS_CREATE_ITEM   = 67492,

    TALK_TRIPLE_DOT             = 0,
    TALK_INTRO_1                = 1,
    TALK_INTRO_2                = 2,
    TALK_INTRO_3                = 3,
    TALK_INTRO_4                = 4,
    TALK_CORRECT                = 5,
    TALK_TIMED_OUT              = 6,
    TALK_INCORRECT              = 7,
    TALK_USE_BLASTCRACKERS      = 8,
    TALK_USE_EAR_O_SCOPE        = 9,
    TALK_USE_INFINIFOLD_LOCKPICK= 10,
    TALK_USE_KAJAMITE_DRILL     = 11,
    TALK_USE_AMAZIN_G_RAY       = 12,
    TALK_SUCCESS                = 13,
};

// 67555
class spell_great_bank_heist_vault_interact : public SpellScript
{
    PrepareSpellScript(spell_great_bank_heist_vault_interact);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->IsOnVehicle())
            return;

        if (!GetCaster()->IsPlayer())
            return;

        if (Creature* vault = GetCaster()->SummonCreature(NPC_FBOK_VAULT, GetCaster()->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
            GetCaster()->CastSpell(vault, SPELL_CONTROL_VEHICLE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_great_bank_heist_vault_interact::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 35486
struct npc_first_bank_of_kezan_vault : public ScriptedAI
{
    npc_first_bank_of_kezan_vault(Creature* creature) : ScriptedAI(creature), _player(nullptr) {}

    std::vector<std::tuple<uint32, uint32>> const talkAndSpells =
    {
        { SPELL_BLASTCRACKERS,          TALK_USE_BLASTCRACKERS          },
        { SPELL_KAJAMITE_DRILL,         TALK_USE_KAJAMITE_DRILL         },
        { SPELL_EAR_O_SCOPE,            TALK_USE_EAR_O_SCOPE            },
        { SPELL_INFINIFOLD_LOCKPICK,    TALK_USE_INFINIFOLD_LOCKPICK    },
        { SPELL_AMAZIN_G_RAY,           TALK_USE_AMAZIN_G_RAY           },
    };

    void OnCharmed(bool /*apply*/) override { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
        {
            me->DespawnOrUnsummon(2000);
            return;
        }

        if (who->IsPlayer())
        {
            _player = who->ToPlayer();
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 0);
            me->SetControlled(true, UNIT_STATE_ROOT);
            InitializeEvent();
        }
    }

    void InitializeEvent()
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            VaultTalk(TALK_INTRO_1);
        }).Schedule(6s, [this](TaskContext /*context*/)
        {
            VaultTalk(TALK_INTRO_2);
        }).Schedule(13s, [this](TaskContext /*context*/)
        {
            VaultTalk(TALK_INTRO_3);
        }).Schedule(20s, [this](TaskContext /*context*/)
        {
            VaultTalk(TALK_INTRO_4);
        }).Schedule(23s, [this](TaskContext /*context*/)
        {
            SelectNextAction();
        });
    }

    void SelectNextAction()
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            _nextAction = urand(0, 4);
            VaultTalk(std::get<1>(talkAndSpells[_nextAction]));
            DoCast(_player, SPELL_TIMER);

            me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
            {
                VaultTalk(TALK_TIMED_OUT);
                SelectNextAction();
            });
        });
    }

    void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_TIMER)
            return;

        if (!_player || !_player->HasAura(SPELL_TIMER))
            return;

        me->GetScheduler().CancelAll();
        _player->RemoveAurasDueToSpell(SPELL_TIMER);

        uint32 requiredSpell = std::get<0>(talkAndSpells[_nextAction]);
        if (requiredSpell != spell->Id)
        {
            VaultTalk(TALK_INCORRECT);
            DoCast(SPELL_POWER_INCORRECT);
            SelectNextAction();
            return;
        }

        VaultTalk(TALK_CORRECT);
        DoCast(SPELL_POWER_CORRECT);

        if (me->GetPower(POWER_MANA) >= 100)
        {
            VaultTalk(TALK_SUCCESS);
            _player->KilledMonsterCredit(me->GetEntry());
            DoCast(_player, SPELL_SUCCESS_CREATE_ITEM);
            me->KillSelf();
        }
        else
            SelectNextAction();
    }

    void VaultTalk(uint8 id)
    {
        Talk(id, _player);
        Talk(TALK_TRIPLE_DOT, _player);
    }

private:
    Player* _player;
    uint8 _nextAction = 0;
};

enum
{
    NPC_MOOK_DISGUISE   = 48925
};

// 67435
class aura_hobart_ingenious_cap_of_mook_foolery : public AuraScript
{
    PrepareAuraScript(aura_hobart_ingenious_cap_of_mook_foolery);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* mookDisguise = GetTarget()->SummonCreature(NPC_MOOK_DISGUISE, *GetTarget(), TEMPSUMMON_MANUAL_DESPAWN))
            mookDisguise->EnterVehicle(GetTarget());
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* mookDisguise = GetTarget()->GetSummonedCreatureByEntry(NPC_MOOK_DISGUISE))
            mookDisguise->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_hobart_ingenious_cap_of_mook_foolery::OnApply, EFFECT_1, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(aura_hobart_ingenious_cap_of_mook_foolery::OnRemove, EFFECT_1, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
    }
};

// 67682
class spell_kabummbomb : public SpellScript
{
    PrepareSpellScript(spell_kabummbomb);

    void HandleActivateGameobject(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCastItem()->GetOwner())
        {
            if (caster->ToPlayer()->GetQuestStatus(14124) != QUEST_STATUS_INCOMPLETE)
                return;

            if (GameObject* Deposit = caster->FindNearestGameObject(GO_DEPOSIT_2, 20))
            {
                caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY(), Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY()-1, Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY()+1, Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                Deposit->Delete();
            }
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kabummbomb::HandleActivateGameobject,EFFECT_0,SPELL_EFFECT_ACTIVATE_OBJECT);
    }
};

enum
{
    NPC_KEZAN_CITIZEN   = 35063,
    NPC_HIRED_LOOTER    = 35234,
};

struct npc_citoyen_gob : public ScriptedAI
{
    npc_citoyen_gob(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id != SPELL_HOT_ROD_KNOCKBACK)
            return;

        if (!caster->IsPlayer())
            return;

        me->GetScheduler().CancelAll();

        if (me->GetEntry() == NPC_HIRED_LOOTER)
        {
            me->KillSelf();
            if (caster->IsPlayer())
                if (caster->ToPlayer()->GetQuestStatus(14121) == QUEST_STATUS_INCOMPLETE)
                    caster->ToPlayer()->AddItem(47530, 1);

            return;
        }

        if (me->GetEntry() == NPC_KEZAN_CITIZEN)
            if (roll_chance_f(50.f))
                Talk(urand(0, 7));

        me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MoveTargetedHome();
        });
    }
};

class gob_canon_gobelin : public GameObjectScript
{
public:
    gob_canon_gobelin() : GameObjectScript("gob_canon_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        player->GetMotionMaster()->MoveJump( -7851.79f, 1838.72f, 8.0f, 0.0f, 20.0f, 20.0f);
        return true;
    }
};

enum
{
    SPELL_GASBOT_SUMMON         = 70252,
    SPELL_GASBOT_SUMMON_VISUAL  = 70254,
    SPELL_GASBOT_GAS_STREAM     = 70256,
    SPELL_GASBOT_BIG_FIRE       = 70259,
    SPELL_GASBOT_EXPLOSION      = 70262,
};

// 70253
class spell_summon_gasbot : public SpellScript
{
    PrepareSpellScript(spell_summon_gasbot);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_GASBOT_SUMMON, true);
        GetCaster()->CastSpell(nullptr, SPELL_GASBOT_SUMMON_VISUAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_summon_gasbot::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37598
struct npc_kezan_gasbot : public ScriptedAI
{
    npc_kezan_gasbot(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        DoCast(SPELL_GASBOT_GAS_STREAM);

        me->GetScheduler().Schedule(500ms, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePoint(1, -8423.85f, 1365.88f, 104.7f);
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == 1)
        {
            DoCast(SPELL_GASBOT_BIG_FIRE);
            DoCast(SPELL_GASBOT_EXPLOSION);

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (Player* player = summoner->ToPlayer())
                        player->KilledMonsterCredit(me->GetEntry());
        }
    }
};

enum
{
    QUEST_NECESSARY_ROUGHNESS           = 24502,
    QUEST_FOURTH_AND_GOAL               = 28414,

    SPELL_DESPAWN_SHARKS                = 69987,
    SPELL_SUMMON_BILGWATER_BUCCANEER    = 70015,
    SPELL_SUMMON_BILGWATER_BUCCANEER_2  = 70075,
    SPELL_GROUND_RUMBLE_EARTHQUAKE      = 78607,

    SPELL_THROW_FOOTBOMB                = 69993,
    SPELL_KICK_FOOTBOMB                 = 70052,

    SPELL_SUMMON_DEATHWING              = 66322,

    NPC_SUMMON_BILGWATER_BUCCANEER      = 37179,
    NPC_SUMMON_BILGWATER_BUCCANEER_2    = 37213,
};

// 24502
// 28414
class quest_fourth_and_goal : public QuestScript
{
public:
    quest_fourth_and_goal() : QuestScript("quest_fourth_and_goal") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_INCOMPLETE)
        {
            player->ExitVehicle();

            player->GetScheduler().Schedule(1s, [player](TaskContext /*context*/)
            {
                player->RemoveAurasDueToSpell(SPELL_GENERIC_INVISIBILITY_DETECTION_4);
                player->NearTeleportTo(-8250.910156f, 1484.290039f, 41.499901f, 3.124140f);

                player->GetScheduler().Schedule(1s, [player](TaskContext /*context*/)
                {
                    player->CastSpell(nullptr, SPELL_SUMMON_BILGWATER_BUCCANEER_2, true);
                });
            });
        }
        else if (newStatus == QUEST_STATUS_COMPLETE)
        {
            player->CastSpell(player, SPELL_GROUND_RUMBLE_EARTHQUAKE, true);
            player->CastSpell(nullptr, SPELL_SUMMON_DEATHWING, true);
        }
        else if (newStatus == QUEST_STATUS_REWARDED)
        {
            player->CastSpell(player, SPELL_GROUND_RUMBLE_EARTHQUAKE, true);
        }
    }
};

// 37106
class npc_coach_crosscheck: public CreatureScript
{
public:
    npc_coach_crosscheck() : CreatureScript("npc_coach_crosscheck") {}

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_NECESSARY_ROUGHNESS)
        {
            player->CastSpell(nullptr, SPELL_SUMMON_BILGWATER_BUCCANEER, true);
            player->RemoveAurasDueToSpell(SPELL_GENERIC_INVISIBILITY_DETECTION_4);
        }

        return false;
    }
};

const Position SharkPos[8] =
{
    { -8278.00f, 1485.00f, 43.14f, 6.28f },
    { -8285.00f, 1485.00f, 43.90f, 6.28f },
    { -8285.61f, 1489.94f, 43.90f, 6.28f },
    { -8285.76f, 1480.03f, 43.90f, 6.28f },
    { -8290.68f, 1475.38f, 43.95f, 6.28f },
    { -8291.06f, 1480.00f, 43.98f, 6.28f },
    { -8290.98f, 1487.85f ,43.99f, 6.28f },
    { -8290.90f, 1492.98f, 43.90f, 6.28f },
};

// 37179
// 37213
struct npc_boucanier_gob : public ScriptedAI
{
    npc_boucanier_gob(Creature* creature) : ScriptedAI(creature){ }

    void Reset() override
    {
        if (me->GetEntry() == NPC_SUMMON_BILGWATER_BUCCANEER_2)
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (summoner->IsPlayer())
                        summoner->EnterVehicle(me);
    }

    void OnCharmed(bool /*apply*/) override { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        Player* player = who->ToPlayer();
        if (!player)
            return;

        if (apply)
        {
            me->SetSpeed(MOVE_RUN, 0.001f);
            player->RemoveAurasDueToSpell(SPELL_GENERIC_INVISIBILITY_DETECTION_4);

            if (player->GetQuestStatus(QUEST_NECESSARY_ROUGHNESS) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(48271, me->GetGUID());
                me->AddAura(70016, me);

                for (uint8 count = 0; count < 8; ++count)
                    me->SummonCreature(37114, SharkPos[count], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120 * IN_MILLISECONDS);
            }
            else if (player->GetQuestStatus(QUEST_FOURTH_AND_GOAL) == QUEST_STATUS_INCOMPLETE)
                me->AddAura(70065, me);
        }
        else
        {
            player->CastSpell(player, SPELL_GENERIC_INVISIBILITY_DETECTION_4, true);
            me->CastSpell(nullptr, SPELL_DESPAWN_SHARKS, true);
            me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                me->DespawnOrUnsummon();
            });
        }
    }
};

// 37114
struct npc_shark_gob : public ScriptedAI
{
    npc_shark_gob(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetWalk(true);

        me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePoint(1, -8260.0f, me->GetPositionY(), me->GetPositionZ());
        });
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_THROW_FOOTBOMB)
        {
            if (caster->GetVehicleKit())
                if (Unit* passenger = caster->GetVehicleKit()->GetPassenger(0))
                    if (Player* player = passenger->ToPlayer())
                        player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());

            caster->Kill(me);
        }
    }

    void JustReachedHome() override { }
};

// 70052
class npc_fourth_and_goal_kick_footbomb : public SpellScript
{
    PrepareSpellScript(npc_fourth_and_goal_kick_footbomb);

    void After()
    {
        if (GetCaster()->IsVehicle())
            if (Unit* passenger = GetCaster()->GetVehicleKit()->GetPassenger(0))
                if (Player* player = passenger->ToPlayer())
                    player->KilledMonsterCredit(37203);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(npc_fourth_and_goal_kick_footbomb::After);
    }
};

// 37203
struct npc_fourth_and_goal_target : public ScriptedAI
{
    npc_fourth_and_goal_target(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->setActive(true);
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_KICK_FOOTBOMB)
        {
            if (caster->GetVehicleKit())
                if (Unit* passenger = caster->GetVehicleKit()->GetPassenger(0))
                    if (Player* player = passenger->ToPlayer())
                        player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
        }
    }

    void JustReachedHome() override { }
};

// 48572
struct npc_fourth_and_goal_deathwing : public ScriptedAI
{
    npc_fourth_and_goal_deathwing(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->setActive(true);

        // TODO waypoints when parser is available
    }
};

// 69987
class spell_kezan_despawn_sharks : public SpellScript
{
    PrepareSpellScript(spell_kezan_despawn_sharks);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            if (creature->IsSummon())
                if (creature->ToTempSummon()->GetSummoner() == GetCaster())
                    creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kezan_despawn_sharks::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum EndHotRod: uint32
{
    PATH_END_HOT_ROD    = 2102191151,
};

// 37676
struct npc_end_hot_rod : public ScriptedAI
{
    npc_end_hot_rod(Creature* creature) : ScriptedAI(creature) {}

    void EnterEvadeMode(EvadeReason /*why*/) override {}

    void Reset() override
    {
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        me->SetSpeed(MOVE_RUN, 20.f);
        me->SetSpeed(MOVE_WALK, 20.f);
    }

    void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool /*apply*/) override
    {
        me->GetMotionMaster()->MovePath(PATH_END_HOT_ROD, false);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != WAYPOINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case 4:
                SassyTalk(0);
                break;
            case 14:
                SassyTalk(1);
                break;
            case 47:
                SassyTalk(2);
                break;
            case 48:
                me->KillSelf();
                break;
            default:
                break;
        }
    }

    void SassyTalk(uint8 id)
    {
        if (me->GetVehicleKit())
            if (Unit* sassy = me->GetVehicleKit()->GetPassenger(0))
                if (sassy->IsCreature())
                    sCreatureTextMgr->SendChat(sassy->ToCreature(), id, me->GetVehicleKit()->GetPassenger(1));
    }
};

// 91847
class spell_life_saving_complete : public SpellScript
{
    PrepareSpellScript(spell_life_saving_complete);

    void HandleHit(SpellMissInfo /*missInfo*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->AddMovieDelayedAction(22, [player]
            {
                player->RemoveAurasDueToSpell(91847);
                player->CastSpell(nullptr, 74100, true); // Life Savings: Teleport & Bind to the Lost Isles
            });
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_life_saving_complete::HandleHit);
    }
};

void AddSC_kezan()
{
    RegisterCreatureAI(npc_defiant_troll);
    new quest_rolling_with_my_homies();
    RegisterCreatureAI(npc_hot_rod_rolling_my_homies);
    RegisterSpellScript(spell_klaxon);
    RegisterSpellScript(spell_radio);
    RegisterCreatureAI(npc_homies);
    RegisterCreatureAI(npc_homies_summon);
    new npc_bling_bling();
    RegisterCreatureAI(npc_kezan_partygoer);
    RegisterSpellScript(spell_kezan_fireworks);
    RegisterSpellScript(spell_kabummbomb);
    new quest_fourth_and_goal();
    new npc_coach_crosscheck();
    RegisterCreatureAI(npc_shark_gob);
    RegisterCreatureAI(npc_boucanier_gob);
    RegisterSpellScript(npc_fourth_and_goal_kick_footbomb);
    RegisterCreatureAI(npc_fourth_and_goal_target);
    RegisterCreatureAI(npc_fourth_and_goal_deathwing);
    RegisterCreatureAI(npc_citoyen_gob);
    RegisterSpellScript(spell_great_bank_heist_vault_interact);
    RegisterCreatureAI(npc_first_bank_of_kezan_vault);
    RegisterAuraScript(aura_hobart_ingenious_cap_of_mook_foolery);
    RegisterSpellScript(spell_summon_gasbot);
    RegisterCreatureAI(npc_kezan_gasbot);
    RegisterCreatureAI(npc_end_hot_rod);
    new gob_canon_gobelin();
    RegisterSpellScript(spell_life_saving_complete);
}
