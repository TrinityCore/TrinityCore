#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "Creature.h"
#include "TemporarySummon.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GridNotifiersImpl.h"
#include "theramore_ruins.h"
#include "DatabaseEnv.h"
#include "Mail.h"

class JainaStandEvent : public BasicEvent
{
public:
    JainaStandEvent(Creature* owner, Player* player) : owner(owner), stage(0), player(player)
    {
        kinndy = owner->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 40.f);
    }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        switch (stage)
        {
            case 0:
                owner->AI()->Talk(SAY_IRIS_1);
                owner->SetWalk(true);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 3000);
                return false;
            case 1:
                owner->SetStandState(UNIT_STAND_STATE_STAND);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 2000);
                return false;
            case 2:
                kinndy->SetVisible(false);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 2000);
                return false;
            case 3:
                owner->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                owner->SetFacingToObject(player);
                return true;
            default:
                break;
        }
        return true;
    }

private:
    Creature* owner;
    Creature* kinndy;
    Player* player;
    uint8 stage;
};

class npc_jaina_ruins : public CreatureScript
{
    public:
    npc_jaina_ruins() : CreatureScript("npc_jaina_ruins") {}

    struct npc_jaina_ruinsAI : public ScriptedAI
    {
        npc_jaina_ruinsAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            canSayIntro = false;
            canSayEnd = false;
            canSayDestruction = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();
            if (!player)
                return;

            switch (me->GetMapId())
            {
                case 1:
                {
                    if (canSayDestruction)
                        return;

                    if (me->IsWithinDist(player, 30.f))
                    {
                        if (player->GetQuestStatus(QUEST_LIMIT_THE_NUKE) == QUEST_STATUS_COMPLETE)
                        {
                            playerForQuest = player;

                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            me->SetStandState(UNIT_STAND_STATE_STAND);

                            Quest const* limitTheNuke = sObjectMgr->GetQuestTemplate(QUEST_LIMIT_THE_NUKE);
                            player->RewardQuest(limitTheNuke, 0, me);

                            Quest const* returnToTheramore = sObjectMgr->GetQuestTemplate(QUEST_RETURN_TO_THERAMORE);
                            player->AddQuestAndCheckCompletion(returnToTheramore, me);

                            SetData(EVENT_START_RETURN, 1U);

                            canSayDestruction = true;
                        }
                    }

                    break;
                }

                case 725:
                {
                    if (canSayIntro && canSayEnd)
                        return;

                    if (me->IsWithinDist(player, 6.f))
                    {
                        if (!canSayIntro && player->GetQuestStatus(QUEST_RETURN_TO_THERAMORE) == QUEST_STATUS_COMPLETE)
                        {
                            playerForQuest = player;

                            me->m_Events.AddEvent(new JainaStandEvent(me, player), me->m_Events.CalculateTime(1000));
                            canSayIntro = true;
                        }

                        if (!canSayEnd && player->GetQuestStatus(QUEST_DESTROY_THE_DESTROYER) == QUEST_STATUS_COMPLETE)
                        {
                            playerForQuest = player;

                            canSayEnd = true;
                            Talk(SAY_IRIS_3);
                            events.ScheduleEvent(EVENT_IRIS_4, 3s);
                        }
                    }

                    break;
                }
            }
        }

        void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
        {
            playerForQuest = player;

            switch (quest->GetQuestId())
            {
                case QUEST_RETURN_TO_THERAMORE:
                    SetData(EVENT_START_IRIS, 1U);
                    break;
            }
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetSheath(SHEATH_STATE_UNARMED);

            switch (id)
            {
                case EVENT_START_RETURN:
                    events.ScheduleEvent(EVENT_RETURN_1, 5s);
                    break;

                case EVENT_START_IRIS:
                    events.ScheduleEvent(EVENT_IRIS_1, 0s);
                    break;

                default:
                    break;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, 0s);
            events.ScheduleEvent(CASTING_FROSTBOLT, 3s);
            events.ScheduleEvent(CASTING_FROST_RUNE, 20s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                DoStartMovement(who, 20.f);
                SetCombatMovement(false);
            }
        }

        void Reset() override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            // Combat
            if (!UpdateVictim())
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Event - Return to Theramore
                        #pragma region THERAMORE

                        case EVENT_RETURN_1:
                            me->GetMotionMaster()->MovePoint(0, -2690.53f, -4765.79f, 13.76f, true, 2.03f);
                            events.ScheduleEvent(EVENT_RETURN_2, 6s);
                            break;

                        case EVENT_RETURN_2:
                            if (Creature * portal = me->SummonCreature(NPC_INVISIBLE_STALKER, -2678.14f, -4774.18f, 14.16f, 2.55f, TEMPSUMMON_TIMED_DESPAWN, 20000))
                            {
                                portal->AddAura(SPELL_OPENED_PORTAL, portal);
                                if (kalecgos = portal->SummonCreature(NPC_KALECGOS, -2678.14f, -4774.18f, 14.16f, 2.55f, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    kalecgos->SetWalk(true);
                                    kalecgos->GetMotionMaster()->MovePoint(0, -2685.95f, -4768.93f, 13.94f, true, 2.55f);
                                }
                            }
                            events.ScheduleEvent(EVENT_RETURN_3, 4s);
                            break;

                        case EVENT_RETURN_3:
                            me->SetFacingToObject(kalecgos);
                            kalecgos->AI()->Talk(SAY_RETURN_1);
                            events.ScheduleEvent(EVENT_RETURN_4, 1s);
                            break;

                        case EVENT_RETURN_4:
                            Talk(SAY_RETURN_2);
                            events.ScheduleEvent(EVENT_RETURN_5, 7s);
                            break;

                        case EVENT_RETURN_5:
                            Talk(SAY_RETURN_3);
                            events.ScheduleEvent(EVENT_RETURN_6, 11s);
                            break;

                        case EVENT_RETURN_6:
                            kalecgos->AI()->Talk(SAY_RETURN_4);
                            events.ScheduleEvent(EVENT_RETURN_7, 15s);
                            break;

                        case EVENT_RETURN_7:
                            Talk(SAY_RETURN_5);
                            events.ScheduleEvent(EVENT_RETURN_8, 6s);
                            break;

                        case EVENT_RETURN_8:
                            kalecgos->AI()->Talk(SAY_RETURN_6);
                            events.ScheduleEvent(EVENT_RETURN_9, 4s);
                            break;

                        case EVENT_RETURN_9:
                            Talk(SAY_RETURN_7);
                            events.ScheduleEvent(EVENT_RETURN_10, 15s);
                            break;

                        case EVENT_RETURN_10:
                            kalecgos->AI()->Talk(SAY_RETURN_8);
                            events.ScheduleEvent(EVENT_RETURN_11, 5s);
                            break;

                        case EVENT_RETURN_11:
                            Talk(SAY_RETURN_9);
                            events.ScheduleEvent(EVENT_RETURN_12, 4s);
                            break;

                        case EVENT_RETURN_12:
                            kalecgos->AI()->Talk(SAY_RETURN_10);
                            events.ScheduleEvent(EVENT_RETURN_13, 7s);
                            break;

                        case EVENT_RETURN_13:
                            kalecgos->AI()->Talk(SAY_RETURN_11);
                            events.ScheduleEvent(EVENT_RETURN_14, 15s);
                            break;

                        case EVENT_RETURN_14:
                            Talk(SAY_RETURN_12);
                            events.ScheduleEvent(EVENT_RETURN_15, 14s);
                            break;

                        case EVENT_RETURN_15:
                            me->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                            events.ScheduleEvent(EVENT_RETURN_16, 1s);
                            break;

                        case EVENT_RETURN_16:
                            me->SetVisible(false);
                            kalecgos->AI()->Talk(SAY_RETURN_13);
                            kalecgos->SetFacingToObject(playerForQuest);
                            events.ScheduleEvent(EVENT_RETURN_17, 3s);
                            break;

                        case EVENT_RETURN_17:
                            kalecgos->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            if (Player * player = me->SelectNearestPlayer(50.f))
                                player->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                            events.ScheduleEvent(EVENT_RETURN_18, 1s);
                            break;

                        case EVENT_RETURN_18:
                            kalecgos->DespawnOrUnsummon(3s);
                            playerForQuest->CompleteQuest(QUEST_RETURN_TO_THERAMORE);
                            playerForQuest->SetPhaseMask(1, true);
                            playerForQuest->TeleportTo(725, -3755.96f, -4479.34f, 0.018f, 0.25f);
                            break;

                            #pragma endregion

                        // Event - Protect the artefact
                        #pragma region ARTEFACT

                        case EVENT_IRIS_1:
                            me->GetMotionMaster()->MovePoint(0, -3710.42f, -4468.33f, -20.67f, true, 0.02f);
                            events.ScheduleEvent(EVENT_IRIS_2, 8s);
                            break;

                        case EVENT_IRIS_2:
                            Talk(SAY_IRIS_2);
                            events.ScheduleEvent(EVENT_IRIS_3, 10s);
                            break;

                        case EVENT_IRIS_3:
                        {
                            Quest const* quest = sObjectMgr->GetQuestTemplate(QUEST_DESTROY_THE_DESTROYER);
                            if (playerForQuest->CanAddQuest(quest, true))
                                playerForQuest->AddQuestAndCheckCompletion(quest, me);

                            if (Creature * dummy = me->SummonCreature(NPC_INVISIBLE_STALKER, -3698.69f, -4467.94f, -20.87f, 3.55f, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                me->CastSpell(dummy, SPELL_CANALISATION);
                                channelTarget = dummy;
                            }

                            break;
                        }

                        case EVENT_IRIS_4:
                        {
                            Quest const* destroyTheDestroyer = sObjectMgr->GetQuestTemplate(QUEST_DESTROY_THE_DESTROYER);
                            Quest const* protectTheArtefact = sObjectMgr->GetQuestTemplate(QUEST_PROTECT_THE_ARTEFACT);
                            playerForQuest->RewardQuest(destroyTheDestroyer, 0, me);
                            if (playerForQuest->CanAddQuest(protectTheArtefact, true))
                                playerForQuest->AddQuestAndCheckCompletion(protectTheArtefact, me);

                            channelTarget->RemoveAllAuras();
                            me->RemoveAllAuras();

                            events.ScheduleEvent(EVENT_IRIS_5, 3s);
                            break;
                        }

                        case EVENT_IRIS_5:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            me->CastSpell(me, 62849, true);
                            for (uint8 i = 0; i < 2; ++i)
                                elementals[i] = me->SummonCreature(NPC_WATER_ELEMENTAL, ElementalsPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            events.ScheduleEvent(EVENT_IRIS_6, 1s);
                            break;

                        case EVENT_IRIS_6:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            events.ScheduleEvent(EVENT_IRIS_7, 2s);
                            break;

                        case EVENT_IRIS_7:
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->CastSpell(me, SPELL_ARCANE_CANALISATION, true);
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                elementals[i]->GetMotionMaster()->MovePoint(0, ElementalsPos[i + 2], false, ElementalsPos[i + 2].GetOrientation());
                                elementals[i]->SetHomePosition(ElementalsPos[i + 2]);
                            }
                            events.ScheduleEvent(EVENT_IRIS_8, 5s);
                            break;

                        case EVENT_IRIS_8:
                            for (int i = 0; i < 12; ++i)
                            {
                                uint32 entry = Soldiers[i].entry;
                                if (!entry)
                                    entry = RAND(NPC_ROK_NAH_GRUNT, NPC_ROK_NAH_SOLDIER, NPC_ROK_NAH_HAG, NPC_ROK_NAH_FELCASTER, NPC_ROK_NAH_LOA_SINGER);

                                if (Creature * temp = me->SummonCreature(entry, Soldiers[i].position, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    temp->SetReactState(REACT_PASSIVE);

                                    if (entry == NPC_WARLORD_ROK_NAH)
                                        warlord = temp;
                                    else
                                        soldiers.push_back(temp);
                                }
                            }
                            events.ScheduleEvent(EVENT_IRIS_9, 2s);
                            break;

                        case EVENT_IRIS_9:
                            warlord->AI()->Talk(SAY_IRIS_4);
                            events.ScheduleEvent(EVENT_IRIS_10, 7s);
                            break;

                        case EVENT_IRIS_10:
                            Talk(SAY_IRIS_5);
                            events.ScheduleEvent(EVENT_IRIS_11, 9s);
                            break;

                        case EVENT_IRIS_11:
                            warlord->AI()->Talk(SAY_IRIS_6);
                            events.ScheduleEvent(EVENT_IRIS_12, 6s);
                            break;

                        case EVENT_IRIS_12:
                            Talk(SAY_IRIS_7);
                            events.ScheduleEvent(EVENT_IRIS_13, 9s);
                            break;

                        case EVENT_IRIS_13:
                            warlord->AI()->Talk(SAY_IRIS_8);
                            events.ScheduleEvent(EVENT_IRIS_14, 3s);
                            break;

                        case EVENT_IRIS_14:
                        {
                            warlord->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            warlord->SetReactState(REACT_AGGRESSIVE);
                            warlord->Attack(playerForQuest, true);
                            warlord->GetMotionMaster()->MoveChase(playerForQuest, 1.f);

                            for (Creature* soldier : soldiers)
                            {
                                soldier->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                soldier->SetReactState(REACT_AGGRESSIVE);

                                if (soldier->GetPositionY() <= -4468.18f)
                                {
                                    soldier->Attack(elementals[1], true);
                                    soldier->GetMotionMaster()->MoveChase(elementals[1], 1.f);
                                }
                                else
                                {
                                    soldier->Attack(elementals[0], true);
                                    soldier->GetMotionMaster()->MoveChase(elementals[0], 1.f);
                                }
                            }

                            events.ScheduleEvent(EVENT_IRIS_15, 5s);
                            break;
                        }

                        case EVENT_IRIS_15:
                        {
                            if (warlord->GetHealthPct() < 10.f || playerForQuest->GetHealthPct() <= 20.f)
                            {
                                warlord->RemoveAllAuras();
                                warlord->SetImmuneToAll(true);
                                warlord->SetRegenerateHealth(false);
                                warlord->SetControlled(true, UNIT_STATE_ROOT);

                                float currentHealth = warlord->GetHealth() * 0.5f;
                                warlord->SetHealth((uint32)currentHealth);

                                events.CancelEvent(EVENT_IRIS_15);
                                events.ScheduleEvent(EVENT_IRIS_16, 1s);
                            }
                            else
                                events.RescheduleEvent(EVENT_IRIS_15, 1s);
                            break;
                        }

                        case EVENT_IRIS_16:
                        {
                            playerForQuest->ResurrectPlayer(10.f);

                            warlord->CombatStop(true);
                            warlord->GetMotionMaster()->Clear();
                            warlord->GetMotionMaster()->MoveIdle();
                            warlord->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            warlord->SetReactState(REACT_PASSIVE);
                            warlord->SetStandState(UNIT_STAND_STATE_KNEEL);

                            CastSpellExtraArgs args;
                            args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
                            me->CastSpell(me, SPELL_ICE_NOVA, args);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);

                            for (Creature* soldier : soldiers)
                            {
                                if (!soldier || (soldier && !soldier->IsAlive()))
                                    continue;

                                Unit::Kill(me, soldier);
                            }

                            for (uint8 i = 0; i < 2; ++i)
                            {
                                if (!elementals[i] || (elementals[i] && !elementals[i]->IsAlive()))
                                    continue;

                                elementals[i]->GetMotionMaster()->Clear();
                                elementals[i]->GetMotionMaster()->MovePoint(0, ElementalsPos[i], false, ElementalsPos[i].GetOrientation());
                                elementals[i]->SetHomePosition(ElementalsPos[i]);
                            }

                            events.ScheduleEvent(EVENT_IRIS_17, 2s);
                            break;
                        }

                        case EVENT_IRIS_17:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            if (GameObject * temp = GetClosestGameObjectWithEntry(me, 190561, 100))
                            {
                                float distanceToTravel = me->GetExactDist2d(temp->GetPosition()) - 1.5f;
                                float angle = me->GetAbsoluteAngle(temp);
                                float destx = me->GetPositionX() + distanceToTravel * cosf(angle);
                                float desty = me->GetPositionY() + distanceToTravel * sinf(angle);

                                me->GetMotionMaster()->MovePoint(0, destx, desty, temp->GetPositionZ());
                                mirror = temp;
                            }
                            events.ScheduleEvent(EVENT_IRIS_18, 7s);
                            break;

                        case EVENT_IRIS_18:
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            events.ScheduleEvent(EVENT_IRIS_19, 2s);
                            break;

                        case EVENT_IRIS_19:
                        {
                            mirror->Delete();
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            events.ScheduleEvent(EVENT_IRIS_20, 2s);
                            break;
                        }

                        case EVENT_IRIS_20:
                        {
                            float distanceToTravel = me->GetExactDist2d(warlord->GetPosition()) - 1.5f;
                            float angle = me->GetAbsoluteAngle(warlord);
                            float destx = me->GetPositionX() + distanceToTravel * cosf(angle);
                            float desty = me->GetPositionY() + distanceToTravel * sinf(angle);

                            me->GetMotionMaster()->MovePoint(0, destx, desty, warlord->GetPositionZ());

                            events.ScheduleEvent(EVENT_IRIS_21, ((distanceToTravel / me->GetSpeed(MOVE_WALK)) + 2) * IN_MILLISECONDS);
                            break;
                        }

                        case EVENT_IRIS_21:
                        {
                            Quest const* protectTheArtefact = sObjectMgr->GetQuestTemplate(QUEST_PROTECT_THE_ARTEFACT);
                            playerForQuest->CompleteQuest(QUEST_PROTECT_THE_ARTEFACT);
                            playerForQuest->RewardQuest(protectTheArtefact, 0, me);

                            Unit::Kill(me, warlord);

                            me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                            events.ScheduleEvent(EVENT_IRIS_22, 2s);
                            break;
                        }

                        case EVENT_IRIS_22:
                            Talk(SAY_IRIS_9);
                            me->SetFacingToObject(playerForQuest);
                            events.ScheduleEvent(EVENT_IRIS_23, 8s);
                            break;

                        case EVENT_IRIS_23:
                            Talk(SAY_IRIS_10);
                            events.ScheduleEvent(EVENT_IRIS_24, 12s);
                            break;

                        case EVENT_IRIS_24:
                            if (elementals[0] && elementals[0]->IsAlive()) elementals[0]->DespawnOrUnsummon();
                            if (elementals[1] && elementals[1]->IsAlive()) elementals[1]->DespawnOrUnsummon();
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            me->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                            events.ScheduleEvent(EVENT_IRIS_25, 1830);
                            break;

                        case EVENT_IRIS_25:
                            SendMailToPlayer(playerForQuest);
                            me->SetVisible(false);
                            me->SummonGameObject(500015, me->GetPosition(), QuaternionData(), 0);
                            break;

                        #pragma endregion

                        default:
                            break;
                    }
                }
            }
            else
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_FIREBALL:
                            DoCastVictim(SPELL_FIREBALL);
                            events.RescheduleEvent(CASTING_FIREBALL, 1542);
                            break;

                        case CASTING_FROSTBOLT:
                            DoCastVictim(SPELL_FROSTBOLT);
                            events.RescheduleEvent(CASTING_FROSTBOLT, 3s, 5s);
                            break;

                        case CASTING_FROST_RUNE:
                            DoCastVictim(SPELL_FROST_RUNE);
                            me->PlayDirectSound(28139);
                            events.ScheduleEvent(CASTING_FROST_RUNE, 1min, 3min);
                            break;

                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        }

        private:
        EventMap events;
        std::vector<Creature*> soldiers;
        Creature* kalecgos;
        Creature* warlord;
        Creature* channelTarget;
        Creature* elementals[2];
        Player* playerForQuest;
        GameObject* mirror;
        bool canSayIntro, canSayEnd, canSayDestruction;

        void SendMailToPlayer(Player* player) const
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            int16 deliverDelay = irand(MAIL_DELIVER_DELAY_MIN, MAIL_DELIVER_DELAY_MAX);
            MailDraft(MAIL_TIDES_ENTRY, true).SendMailTo(trans, MailReceiver(player), MailSender(MAIL_CREATURE, me->GetEntry()), MAIL_CHECK_MASK_NONE, deliverDelay);
            CharacterDatabase.CommitTransaction(trans);
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_jaina_ruinsAI(creature);
    }
};

class npc_warlord_roknah : public CreatureScript
{
    public:
    npc_warlord_roknah() : CreatureScript("npc_warlord_roknah") {}

    struct npc_warlord_roknahAI : public ScriptedAI
    {
        npc_warlord_roknahAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize() { }

        void Reset() override { }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetMaxHealth() || HealthBelowPct(10))
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_warlord_roknahAI(creature);
    }
};

void AddSC_theramore_ruins()
{
    new npc_jaina_ruins();
    new npc_warlord_roknah();
}
