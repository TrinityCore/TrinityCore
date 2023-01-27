/*
    http://uwow.biz
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GameObjectAI.h"
#include "army_training.h"
#include "WorldPacket.h"
#include "SpellPackets.h"

/*
SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_10_WITHERED                    = 293, // Requires at least 10 living withered
SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_14_WITHERED                    = 294, // Requires at least 14 living withered
SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_18_WITHERED                    = 295, // Requires at least 18 living withered
SPELL_CUSTOM_ERROR_REQUIRES_2_WITHERED_MANA_RAGERS                  = 296, // Requires 2 Withered Mana-Ragers
SPELL_CUSTOM_ERROR_REQUIRES_1_WITHERED_BERSERKE                     = 297, // Requires 1 Withered Berserker
SPELL_CUSTOM_ERROR_REQUIRES_2_WITHERED_BERSERKER                    = 298, // Requires 2 Withered Berserkers
*/

std::map<uint32, uint32> spellSummonMinion
{
    { ARMY_UNIT_COMMON, SPELL_SUMMON_COMMON },
    { ARMY_UNIT_BERSERK, SPELL_SUMMON_BERSERK },
    { ARMY_UNIT_MANA, SPELL_SUMMON_WANTED_MANA },
    { ARMY_UNIT_MAGE, SPELL_SUMMON_MAGE },
};

std::map<uint32, uint32> typeMinionByEntry
{
    { NPC_COMMON_MINION , ARMY_UNIT_COMMON },
    { NPC_BERSERK , ARMY_UNIT_BERSERK },
    { NPC_WANTED_MANA , ARMY_UNIT_MANA },
    { NPC_MAGE , ARMY_UNIT_MAGE },
};


// 109008
class npc_army_training_talysra : public CreatureScript
{
public:
    npc_army_training_talysra() : CreatureScript("npc_army_training_talysra") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript *script = player->GetInstanceScript();

        if (!script)
            return true;

        switch (script->getScenarionStep())
        {
        case 0:
            player->ADD_GOSSIP_ITEM_DB(19952, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(29660, creature->GetGUID());
            break;
        case 1:
            player->ADD_GOSSIP_ITEM_DB(19952, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(29660, creature->GetGUID());
            break;
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
            {
                uint32& maxUnits = player->armyTrainingInfo.buyedNowUnits;

                //maxUnits = 20;
                player->SendUpdateWorldState(12103, maxUnits, false);

                // start check from uncommon units. If player has it, then summon it
                for (uint8 i = ARMY_UNIT_BERSERK; i < ARMY_UNITS_MAX && maxUnits; ++i)
                    for (uint8 j = 0; j < player->armyTrainingInfo.justOpenedUnits[i-1] && maxUnits; ++j, --maxUnits)
                        player->CastSpellDelay(player, spellSummonMinion[i], true, 10*i+10*j);

                // then summon others common units
                for (;maxUnits; --maxUnits)
                    player->CastSpellDelay(player, spellSummonMinion[ARMY_UNIT_COMMON], true, 10* maxUnits);

                player->CastSpell(player, SPELL_STARTED_OVERRIDE);
                player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, CRITERIA_FIRST);

                player->CreateConversation(3429);

                player->SendUpdateWorldState(12104, 1, false);
                player->SendUpdateWorldState(12106, 2, false);
                player->SendUpdateWorldState(12174, 1, false);
                player->SendUpdateWorldState(12155, 1, false);
                player->SendUpdateWorldState(12156, 2, false);
                //player->SendUpdateWorldState(12882, 0, false);
                //player->SendUpdateWorldState(12884, 0, false);
                break;
            }
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->CastSpell(player, SPELL_TELE_END, true);
                break;
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }
};

// 109011, 109012, 109013, 109014
struct npc_army_training_minions : public ScriptedAI
{
    npc_army_training_minions(Creature* creature) : ScriptedAI(creature) {}

    ObjectGuid chest{};
    EventMap events;
    bool moreFixate{}, moreBrave{};

    uint32 fearedTime;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* who) override
    {
        if(me->GetEntry() != NPC_BERSERK)
            events.RescheduleEvent(EVENT_1, (me->HasAura(SPELL_AURA_RAGE_MODE) ? urand(1000, 2000) : urand(3000, 4000)));
        else
        {
            DoCast(37548);
            DoCast(140107);
            events.RescheduleEvent(EVENT_2, urand(12000, 15000));
            events.RescheduleEvent(EVENT_3, urand(12000, 15000));
        }

        Player* player = me->GetAnyOwner()->ToPlayer();
        if (!player)
            return;

        for (uint8 i = ARMY_UNIT_COMMON; i < ARMY_UNITS_MAX; ++i)
            for (auto guid : player->armyTrainingInfo.currentUnits[i])
                if (Creature* summon = Unit::GetCreature(*player, guid))
                    DoZoneInCombat(summon);
    }

    void IsSummonedBy(Unit* owner) override
    {
        if (!owner->IsPlayer() || !owner->ToPlayer()->IsInArmyTraining())
        {
            me->DespawnOrUnsummon();
            return;
        }

        Player* player = owner->ToPlayer();
        if (!player)
            return;

        player->CastSpell(player, SPELL_COUNT_MINIONS);
        player->armyTrainingInfo.currentUnits[typeMinionByEntry[me->GetEntry()]].push_back(me->GetGUID());

        if (me->GetEntry() != NPC_BERSERK)
        {
           // me->m_CombatDistance = 30.0f;
            me->SetAttackDist(30.0f);
        }

        for (uint8 i =0; i < player->armyTrainingInfo.moreHP; ++i)
        {
            me->CastSpell(me, SPELL_ADDITIONAL_HP);
            me->SetMaxHealth(me->GetMaxHealth() * 1.25f);
            me->SetHealth(me->GetMaxHealth());
        }

        for (uint8 i = 0; i < player->armyTrainingInfo.moreDMG; ++i)
            me->CastSpell(me, SPELL_ADDITIONAL_DMG);

        moreFixate = player->armyTrainingInfo.moreFixate;
        moreBrave = player->armyTrainingInfo.moreBrave;

        me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

        fearedTime = urand(80000, 210000);
    }

    void JustDied(Unit* who) override
    {
        Unit* owner = me->GetAnyOwner();

        if (!owner || !owner->IsPlayer() || !owner->ToPlayer()->IsInArmyTraining())
        {
            me->DespawnOrUnsummon();
            return;
        }

        Player* player = owner->ToPlayer();
        if (!player)
            return;

        player->SetAuraStack(SPELL_COUNT_MINIONS, player, -1);
        player->armyTrainingInfo.currentUnits[typeMinionByEntry[me->GetEntry()]].remove(me->GetGUID());

        me->DespawnOrUnsummon(100);
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply) override
    {
        if (spellId == SPELL_FEARED)
        {
            if (apply)
            {
                me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->GetMotionMaster()->MoveRandom(10.0f);
            }
            else if (mode == AURA_REMOVE_BY_EXPIRE)
                //JustDied(me);
                me->Kill(me);
            else
            {
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->GetMotionMaster()->MoveFollow(me->GetAnyOwner(), me->GetFollowDistance(), me->GetFollowAngle());
            }
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        chest = guid;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == 1)
        {
            if (!chest.IsEmpty() && me->GetInstanceScript())
                if (GameObject* go =  me->GetInstanceScript()->instance->GetGameObject(chest))
                    go->AI()->SetData(1, 1);

            me->CastSpell(me, SPELL_VISUAL_PICKUP_CHEST, false);

            me->AddDelayedEvent(3000, [this]() -> void
            {
                me->Kill(me);
                //JustDied(me);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (fearedTime <= diff)
        {
            if (!moreBrave || (moreBrave && urand(1, 3 == 1)))
            {
                me->CastSpell(me, SPELL_FEARED);
                me->CreateConversation(CONV_FEARED);
            }
            fearedTime = urand(120000, 210000);
        }
        else if (me->GetHealthPct() < 80 && urand(1, 3) == 1)
            if (me->isInCombat() || urand(1, 1000) == 5)
                fearedTime -= diff;

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (me->GetEntry() == NPC_COMMON_MINION || me->GetEntry() == NPC_MAGE)
                    DoCast(moreFixate ? 218897 :218894);
                else
                    DoCast(23106);
                events.RescheduleEvent(EVENT_1, (me->HasAura(SPELL_AURA_RAGE_MODE) ? urand(1000, 2000) : urand(3000, 4000)));
                break;
            case EVENT_2:
                DoCast(148743);
                events.RescheduleEvent(EVENT_2, urand(12000, 15000));
                break;
            case EVENT_3:
                DoCast(140396);
                events.RescheduleEvent(EVENT_3, urand(12000, 15000));
                break;
            }
        }

        if (me->GetEntry() == NPC_BERSERK)
            DoMeleeAttackIfReady();
    }
};

// 251728 251665 251739 251742 251730 251743 251725 251732 251724 251666 251740 251741 251726 251744
struct go_army_training_chests : public GameObjectAI
{
    go_army_training_chests(GameObject* go) : GameObjectAI(go) {}

    bool despawn = false;
    bool justTalk = false;

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 /*action*/)
    {
        if (justTalk)
            return false;

        bool isBig = (go->GetEntry() == 251739 || go->GetEntry() == 251742 || go->GetEntry() == 251743 || go->GetEntry() == 251740 || go->GetEntry() == 251741 || go->GetEntry() == 251744);

        uint8 req = (isBig ? 10 : 5);

        if (player->GetAuraCount(SPELL_COUNT_MINIONS) >= req)
        {
            justTalk = true;
            std::list<std::pair<ObjectGuid, int8>> units{};

            for (uint8 i = ARMY_UNIT_COMMON; i < (units.size() < req ? ARMY_UNITS_MAX : 0); ++i)
                for (auto guid : player->armyTrainingInfo.currentUnits[i])
                    units.push_back({ guid, i });

            units.sort([player](std::pair<ObjectGuid, int8>& a_, std::pair<ObjectGuid, int8>& b_) {
                ObjectGuid a = a_.first;
                ObjectGuid b = b_.first;
                Creature* _a = Unit::GetCreature(*player, a);
                Creature* _b = Unit::GetCreature(*player, b);
                if (!_a)
                    return false;
                if (!_b)
                    return false;
                return _a->GetHealth() < _b->GetHealth();
            });

            for (uint8 i = 0; i < req && !units.empty(); ++i)
            {
                auto itr = units.begin();
                if (Creature* add = Unit::GetCreature(*player, itr->first))
                {
                    add->StopAttack();
                    add->AI()->SetGUID(go->GetGUID());
                    add->GetMotionMaster()->MovePoint(1, go->GetPositionX() + frand(-3.0f, 3.0f), go->GetPositionY() + frand(-3.0f, 3.0f), go->GetPositionZ());
                    add->AddDelayedEvent(9000, [add]() -> void // if it was bug...
                    {
                        //add->AI()->JustDied(add);
                        add->Kill(add);
                    });
                }

                player->armyTrainingInfo.currentUnits[itr->second].remove(itr->first);
                units.pop_front();
            }
            
            if (InstanceScript* instance = go->GetInstanceScript())
                instance->SetData(go->GetEntry(), 1);

            player->CreateConversation(CONV_CHEST);
        }
        else
        {
            WorldPackets::Spells::CastFailed packet(SMSG_CAST_FAILED);
            packet.Reason = SPELL_FAILED_CUSTOM_ERROR;
            packet.FailedArg1 = SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_WITHERED;
            player->SendDirectMessage(packet.Write());
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type && value && !despawn)
        {
            despawn = true;
            go->AddDelayedEvent(3000, [&]() -> void
            {
                go->SetPhaseMask(2, true);
            });
        }
    }
};

// 227261
class spell_army_training_tick : public AuraScript
{
    PrepareAuraScript(spell_army_training_tick);

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster() || !GetCaster()->IsPlayer())
        {
            GetAura()->Remove();
            return;
        }

        Player* player = GetCaster()->ToPlayer();
        if (!player || !player->IsInArmyTraining())
        {
            GetAura()->Remove();
            return;
        }

        float bp0 = 0;
        uint32 countUnits = 0;
        for (uint8 i = ARMY_UNIT_COMMON; i < ARMY_UNITS_MAX; ++i)
            for (auto guid : player->armyTrainingInfo.currentUnits[i])
                if (Creature* summon = Unit::GetCreature(*player, guid))
                {
                    bp0 += summon->GetHealthPct();
                    ++countUnits;
                }

        if (!countUnits) 
        {
            GetAura()->Remove();
            return;
        }
        else
            bp0 /= countUnits;
        
        GetAura()->GetEffect(EFFECT_0)->ChangeAmount(bp0);

    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_army_training_tick::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_army_training_open : public SpellScript
{
    PrepareSpellScript(spell_army_training_open);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        Player* player = caster->ToPlayer();
        if (!player)
            return;

        switch (GetSpellInfo()->Id)
        {
        case SPELL_OPEN_BERSERK:
            ++player->armyTrainingInfo.justOpenedUnits[ARMY_UNIT_BERSERK - 1];
            break;
        case SPELL_OPEN_MAGE:
            ++player->armyTrainingInfo.justOpenedUnits[ARMY_UNIT_MAGE - 1];
            break;
        case SPELL_OPEN_WANTED_MANA:
            ++player->armyTrainingInfo.justOpenedUnits[ARMY_UNIT_MANA - 1];
            break;
        case SPELL_OPEN_HP:
            ++player->armyTrainingInfo.moreHP;
            break;
        case SPELL_OPEN_DMG:
            ++player->armyTrainingInfo.moreDMG;
            break;
        case SPELL_OPEN_EFFICIENT:
            player->armyTrainingInfo.moreFixate = true;
            break;
        case SPELL_OPEN_BRAVE:
            player->armyTrainingInfo.moreBrave = true;
            break;
        }
        player->armyTrainingInfo.needSave = true;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_army_training_open::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
    }
};


void AddSC_army_training()
{
    new npc_army_training_talysra();
    RegisterCreatureAI(npc_army_training_minions);
    RegisterGameObjectAI(go_army_training_chests);
    RegisterAuraScript(spell_army_training_tick);
    RegisterSpellScript(spell_army_training_open);
};
