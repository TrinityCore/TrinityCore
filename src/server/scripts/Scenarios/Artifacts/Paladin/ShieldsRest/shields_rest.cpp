/*
    http://uwow.biz
    Paladin Specialization: Protection
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shields_rest.h"

//Phases: 6363

//105910, 105694
class npc_sr_orik_trueheart_intro : public CreatureScript
{
public:
    npc_sr_orik_trueheart_intro() : CreatureScript("npc_sr_orik_trueheart_intro") {}

    struct npc_sr_orik_trueheart_introAI : ScriptedAI
    {
        npc_sr_orik_trueheart_introAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = creature->GetInstanceScript();
            intro = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool intro;

        void Reset() override {}

        void MoveInLineOfSight(Unit* pTarget) override
        {
            if (pTarget->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(pTarget) < 20.0f && !intro)
            {
                intro = true;
                events.RescheduleEvent(EVENT_1, 3000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        Talk(0);
                        events.RescheduleEvent(EVENT_2, 6000);
                        break;
                    case EVENT_2:
                        if (Creature* cato = me->FindNearestCreature(NPC_CATO_INTRO, 20.0f, true))
                            cato->AI()->Talk(0);
                        events.RescheduleEvent(EVENT_3, 4000);
                        break;
                    case EVENT_3:
                        Talk(1);
                        events.RescheduleEvent(EVENT_4, 8000);
                        break;
                    case EVENT_4:
                        if (Unit* player = me->SelectNearestPlayer(40.0f))
                            Talk(2, player->GetGUID());
                        events.RescheduleEvent(EVENT_5, 2000);
                        break;
                    case EVENT_5:
                        if (instance->getScenarionStep() == DATA_STAGE_1)
                        {
                            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50497); //Step 2
                            me->SummonCreature(NPC_DRAKE_SHAE, 4804.64f, 148.32f, 22.38f, 4.38f);
                            if (Creature* cato = me->FindNearestCreature(NPC_CATO_INTRO, 20.0f, true))
                                cato->DespawnOrUnsummon();
                            me->DespawnOrUnsummon();
                        }
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_orik_trueheart_introAI(creature);
    }
};

//105911, 105912
class npc_sr_orik_cato_script : public CreatureScript
{
public:
    npc_sr_orik_cato_script() : CreatureScript("npc_sr_orik_cato_script") {}

    struct npc_sr_orik_cato_scriptAI : ScriptedAI
    {
        npc_sr_orik_cato_scriptAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            for (uint8 i = EVENT_7; i < EVENT_14 + 1; i++)
                events.CancelEvent(i);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (instance)
                if (instance->GetData(DATA_YRGRIM_EVENT) < 5)
                    if (me->GetEntry() == NPC_ORIK_TRUEHEART_PET)
                        events.RescheduleEvent(EVENT_1, 1000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (me->GetEntry() == NPC_CATO_PET)
            {
                events.RescheduleEvent(EVENT_7, 3000); //Cato
                events.RescheduleEvent(EVENT_8, 4000); //Cato
                events.RescheduleEvent(EVENT_9, 7000); //Cato
                events.RescheduleEvent(EVENT_10, 9000); //Cato
            }
            else
            {
                events.RescheduleEvent(EVENT_11, 2000); //Orik
                events.RescheduleEvent(EVENT_12, 6000); //Orik
                events.RescheduleEvent(EVENT_13, 15000); //Orik
                events.RescheduleEvent(EVENT_14, 8000); //Orik
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                attacker->getThreatManager().modifyThreatPercent(me, -90);
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 215980) //Player Blocking Event
            {
                if (me->GetEntry() == NPC_CATO_PET)
                {
                    Talk(0);
                    DoCast(caster, SPELL_CATO_HOLY_LIGHT_2, false);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                events.RescheduleEvent(EVENT_4, 3000);
            }
        }

        void DoAction(int32 const action) override
        {
            events.RescheduleEvent(EVENT_5, 10000);
        }

        void MoveToGo(uint32 entry)
        {
            if (GameObject* go = me->FindNearestGameObject(entry, 30.0f))
            {
                Position pos;
                me->GetNearPosition(pos, me->GetDistance(go) - 3.0f, me->GetRelativeAngle(go));
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovePoint(1, pos);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (!instance || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1: //Orik
                    {
                        events.RescheduleEvent(EVENT_1, 1000);
                        if (!me->isInCombat())
                        {
                            switch (instance->GetData(DATA_YRGRIM_EVENT))
                            {
                                case 0:
                                {
                                    if (me->GetDistance(igrimEventPos[0]) < 15.0f)
                                    {
                                        instance->SetData(DATA_YRGRIM_EVENT, 1);
                                        Talk(0);
                                        MoveToGo(GO_YRGRIM_JOURNEY);
                                    }
                                    break;
                                }
                                case 1:
                                {
                                    if (me->GetDistance(igrimEventPos[1]) < 15.0f)
                                        instance->SetData(DATA_YRGRIM_EVENT, 2);
                                    break;
                                }
                                case 3:
                                    if (me->GetDistance(igrimEventPos[2]) < 15.0f)
                                    {
                                        instance->SetData(DATA_YRGRIM_EVENT, 4);
                                        events.RescheduleEvent(EVENT_2, 1000);
                                        MoveToGo(GO_YRGRIM_CHALLENGE);
                                    }
                                    break;
                                case 5:
                                    if (me->GetDistance(igrimEventPos[3]) < 10.0f)
                                    {
                                        instance->SetData(DATA_YRGRIM_EVENT, 6);
                                        events.CancelEvent(EVENT_1);
                                        MoveToGo(GO_YRGRIMS_REST);
                                        //Talk(?);
                                    }
                                    break;
                            }
                        }
                        break;
                    }
                    case EVENT_2: //Orik
                        Talk(1);
                        events.RescheduleEvent(EVENT_3, 7000);
                        break;
                    case EVENT_3: //Orik
                        if (instance->getScenarionStep() == DATA_STAGE_2)
                        {
                            Talk(2);
                            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50500); //Step 3
                            instance->SetData(DATA_YRGRIM_EVENT, 5);
                        }
                        break;
                    case EVENT_4: //Orik
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        EnterEvadeMode();
                        break;
                    case EVENT_5: //Orik and Cato
                        if (me->GetEntry() == NPC_ORIK_TRUEHEART_PET)
                            Talk(3);
                        me->GetMotionMaster()->Clear(false);
                        events.RescheduleEvent(EVENT_6, 6000);
                        break;
                    case EVENT_6: //Orik and Cato
                        me->DespawnOrUnsummon(4000);
                        DoCast(me, SPELL_DIVINE_SHIELD, true);
                        DoCast(SPELL_COSMETIC_HEARTHSTONE);
                        break;
                    case EVENT_7: //Cato
                        if (Unit* owner = me->GetAnyOwner())
                            DoCast(owner, SPELL_CATO_HOLY_LIGHT_1);
                        events.RescheduleEvent(EVENT_7, 9000);
                        break;
                    case EVENT_8: //Cato
                        DoCastVictim(SPELL_CATO_DENOUNCE);
                        events.RescheduleEvent(EVENT_8, 4000);
                        break;
                    case EVENT_9: //Cato
                        DoCastVictim(SPELL_CATO_HOLY_SHOCK);
                        events.RescheduleEvent(EVENT_9, 7000);
                        break;
                    case EVENT_10: //Cato
                        DoCast(SPELL_CATO_LIGHT_OF_DAWN);
                        events.RescheduleEvent(EVENT_10, 10000);
                        break;
                    case EVENT_11: //Orik
                        DoCastVictim(SPELL_ORIK_CRUSADER_STRIKE);
                        events.RescheduleEvent(EVENT_11, 5000);
                        break;
                    case EVENT_12: //Orik
                        DoCast(SPELL_ORIK_DIVINE_STORM);
                        events.RescheduleEvent(EVENT_12, 9000);
                        break;
                    case EVENT_13: //Orik
                        DoCastVictim(SPELL_ORIK_HAMMER_JUSTICE);
                        events.RescheduleEvent(EVENT_13, 30000);
                        break;
                    case EVENT_14: //Orik
                        DoCastVictim(SPELL_ORIK_JUDGMENT);
                        events.RescheduleEvent(EVENT_14, 8000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_orik_cato_scriptAI(creature);
    }
};

//106245, 106246
class npc_sr_cryptstalker_event : public CreatureScript
{
public:
    npc_sr_cryptstalker_event() : CreatureScript("npc_sr_cryptstalker_event") {}

    struct npc_sr_cryptstalker_eventAI : ScriptedAI
    {
        npc_sr_cryptstalker_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        EventMap events;
        bool checkFall;

        void Reset() override
        {
            events.Reset();
            if (checkFall)
            {
                SetFlyMode(true);
                me->GetMotionMaster()->MovePoint(0, 4807.0f, 148.82f, -7.3f);
            }
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (me->GetEntry() == NPC_DRAKE_SHAE)
            {
                checkFall = false;
                SetCombatMovement(false);
                SetFlyMode(true);
                events.RescheduleEvent(EVENT_1, 2000); //Drake
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            if (me->GetEntry() == NPC_DRAKE_SHAE)
            {
                events.RescheduleEvent(EVENT_4, 1000); //Drake
            }
            else
            {
                events.RescheduleEvent(EVENT_5, 2000); //Inna
                events.RescheduleEvent(EVENT_6, 8000); //Inna
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (me->GetEntry() == NPC_DRAKE_SHAE)
                {
                    if (me->GetVehicleKit())
                        me->GetVehicleKit()->RemoveAllPassengers();
                }
                else
                {
                    Talk(1);
                    me->SetFacingTo(4.15f);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_RANGED);
                    me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_READY_BOW);
                if (Unit* owner = me->GetAnyOwner())
                    if (Creature* summoner = owner->ToCreature())
                    {
                        summoner->SetReactState(REACT_AGGRESSIVE);
                        summoner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    }
                }
            }
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (!apply)
            {
                if (Creature* pass = who->ToCreature())
                    pass->AI()->DoAction(true);
            }
        }

        void DoAction(int32 const action) override
        {
            events.RescheduleEvent(EVENT_2, 1000); //Inna
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 210704 && !checkFall)
                if (me->GetEntry() == NPC_DRAKE_SHAE)
                {
                    checkFall = true;
                    SetFlyMode(true);
                    me->GetMotionMaster()->MovePoint(0, 4807.0f, 148.82f, -7.3f);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1: //Drake
                        me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 22.0f);
                        break;
                    case EVENT_2: //Inna
                        Talk(0);
                        events.RescheduleEvent(EVENT_3, 3000);
                        break;
                    case EVENT_3: //Inna
                        me->GetMotionMaster()->MovePoint(1, 4808.66f, 135.47f, -8.28f);
                        me->SetHomePosition(4808.66f, 135.47f, -8.28f, 4.15f);
                        break;
                    case EVENT_4: //Drake
                        DoCastVictim(SPELL_LIGHTNING_BLAST);
                        events.RescheduleEvent(EVENT_4, 3000);
                        break;
                    case EVENT_5: //Inna
                        DoCastVictim(SPELL_INNA_SHOOT);
                        events.RescheduleEvent(EVENT_5, 5000);
                        break;
                    case EVENT_6: //Inna
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, false))
                            DoCast(target, SPELL_INNA_PIN_DOWN);
                        events.RescheduleEvent(EVENT_6, 40000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_cryptstalker_eventAI(creature);
    }
};

//106230
class npc_sr_quicksteel_arrow : public CreatureScript
{
public:
    npc_sr_quicksteel_arrow() : CreatureScript("npc_sr_quicksteel_arrow") {}

    struct npc_sr_quicksteel_arrowAI : ScriptedAI
    {
        npc_sr_quicksteel_arrowAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        bool checkClick;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            checkClick = false;
            DoCast(me, 210400, true); //Visual
            DoCast(me, 210399, true); //Dmg
        }

        void SpellHit(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == 210402)
                me->DespawnOrUnsummon();
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (!checkClick)
            {
                checkClick = true;
                clicker->CastSpell(me, 210402, true);
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_quicksteel_arrowAI(creature);
    }
};

//105968
class npc_sr_spectral_windshaper : public CreatureScript
{
public:
    npc_sr_spectral_windshaper() : CreatureScript("npc_sr_spectral_windshaper") {}

    struct npc_sr_spectral_windshaperAI : ScriptedAI
    {
        npc_sr_spectral_windshaperAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_DEFENSIVE);
            checkWindPos = false;
        }

        EventMap events;
        bool checkWindPos;
        uint32 windSpell;

        void Reset() override
        {
            events.Reset();
            events.RescheduleEvent(EVENT_1, urand(1, 6) * IN_MILLISECONDS);
            DoCast(me, SPELL_SHADOWY_GHOST_VISUAL, true);

            if (!checkWindPos)
            {
                checkWindPos = true;
                for (uint8 i = 0; i < 3; i++)
                    if (me->GetDistance(windshaperPos[i]) < 1.0f)
                        windSpell = SPELL_FIERCE_WINDS + i;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.CancelEvent(EVENT_1);
            events.RescheduleEvent(EVENT_2, 2000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(windSpell);
                        events.RescheduleEvent(EVENT_1, urand(6, 12) * IN_MILLISECONDS);
                        break;
                    case EVENT_2:
                        DoCastVictim(SPELL_COLDWIND_BLAST);
                        events.RescheduleEvent(EVENT_2, urand(5000, 7000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_spectral_windshaperAI(creature);
    }
};

//106432
class npc_sr_fierce_winds : public CreatureScript
{
public:
    npc_sr_fierce_winds() : CreatureScript("npc_sr_fierce_winds") {}

    struct npc_sr_fierce_windsAI : ScriptedAI
    {
        npc_sr_fierce_windsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint16 startTimer;

        void Reset() override {}
        
        void IsSummonedBy(Unit* summoner) override
        {
            startTimer = 500;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (me->GetVehicleKit())
            {
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon(100);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (startTimer)
            {
                if (startTimer <= diff)
                {
                    startTimer = 0;
                    DoCast(me, SPELL_FIERCE_WINDS_AT, true);

                    for (uint8 i = 0; i < 3; i++)
                        if (me->GetDistance(windshaperPos[i]) < 2.0f)
                            me->GetMotionMaster()->MovePoint(1, windEndPos[i].GetPositionX(), windEndPos[i].GetPositionY(), windEndPos[i].GetPositionZ(), false);
                }
                else
                    startTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_fierce_windsAI(creature);
    }
};

//105695, 106202
class npc_sr_yrgrim_the_truthseeker : public CreatureScript
{
public:
    npc_sr_yrgrim_the_truthseeker() : CreatureScript("npc_sr_yrgrim_the_truthseeker") {}

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        if (pPlayer->isInCombat())
            return true;

        pPlayer->ADD_GOSSIP_ITEM_DB(19563, 0, 19563, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if (sender == 19563 && action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->AI()->Talk(1);
            creature->setFaction(14);
        }
        return true;
    }

    struct npc_sr_yrgrim_the_truthseekerAI : ScriptedAI
    {
        npc_sr_yrgrim_the_truthseekerAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
            introOne = false;
            introSecond = false;
            fightComplete = false;
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        bool introOne;
        bool introSecond;
        bool fightComplete;

        void Reset() override
        {
            if (me->GetEntry() == NPC_YRGRIM_TRUTHSEEKER_2)
                return;

            summons.DespawnAll();

            if (!introOne)
            {
                //me->SetAnimKitId(3647);
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
            }

            if (!fightComplete)
            {
                events.Reset();
                me->SummonCreature(NPC_RUNESHAPER_GRISELDA, 4891.20f, 529.05f, -49.01f, 4.02f);
            }
        }

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(EVENT_3, 3000);
        }

        void EnterCombat(Unit* /*who*/) override
        //16:03
        {
            if (fightComplete)
                return;

            events.RescheduleEvent(EVENT_5, 6000);
            events.RescheduleEvent(EVENT_6, 10000);
            events.RescheduleEvent(EVENT_7, 17000);

            EntryCheckPredicate pred(NPC_RUNESHAPER_GRISELDA);
            summons.DoAction(ACTION_1, pred);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (instance->getScenarionStep() != DATA_STAGE_4)
                return;

            if ((me->GetDistance(who) < 100.0f) && !introOne)
            {
                introOne = true;
                //me->SetAnimKitId(0);
                me->SetStandState(UNIT_STAND_STATE_STAND);
                
                me->SetFacingToObject(who);
                who->CastSpell(who, SPELL_SCENE_YRGRIM, true);
            }
            if ((me->GetDistance(who) < 60.0f) && !introSecond)
            {
                if (instance->getScenarionStep() == DATA_STAGE_4)
                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50581); //Step 5
                introSecond = true;
                ZoneTalk(0);
                me->GetMotionMaster()->MoveJump(4878.13f, 522.01f, -49.09f, 20.0f, 10.0f);
                me->SetHomePosition(4878.13f, 522.01f, -49.09f, 4.51f);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth() || me->HealthBelowPct(10))
            {
                damage = 0;

                if (!fightComplete)
                {
                    fightComplete = true;
                    me->SetHealth(me->GetMaxHealth());
                    me->RemoveAllAuras();
                    me->SetHomePosition(me->GetPosition());
                    me->setFaction(35);
                    events.Reset();
                    Talk(2);
                    EnterEvadeMode();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NON_ATTACKABLE);
                    events.RescheduleEvent(EVENT_1, 3000);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            switch (type)
            {
                case POINT_MOTION_TYPE:
                {
                    if (id == 1)
                    {
                        me->SetFacingTo(6.08f);
                        //me->SetAnimKitId(1320);
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        events.RescheduleEvent(EVENT_2, 5000);
                    }
                    if (id == 2)
                    {
                        me->SetFacingTo(4.50f);
                        Talk(0);
                        events.RescheduleEvent(EVENT_4, 10000);
                    }
                    break;
                }
                case EFFECT_MOTION_TYPE:
                    if (id == 111)
                    {
                        me->SetFacingTo(4.50f);
                        DoCast(me, SPELL_PETRIFIED, true);
                    }
                    break;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (me->GetDistance(me->GetHomePosition()) >= 60.0f)
            {
                EnterEvadeMode();
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        me->GetMotionMaster()->MovePoint(1, 4871.29f, 508.14f, -49.09f);
                        break;
                    case EVENT_2:
                        //me->SetAnimKitId(0);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        SetEquipmentSlots(false, 0, 0, 0);
                        if (instance->getScenarionStep() == DATA_STAGE_5)
                        {
                            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50598); //Step 6
                            if (GameObject* chest = me->FindNearestGameObject(GO_ART_CHEST, 60.0f))
                                chest->SetRespawnTime(604800);
                            me->SummonCreature(NPC_TRUTHGUARD_OATHSEEKER, 4874.88f, 507.55f, -48.84f, 1.39f);
                        }
                        me->SummonCreature(NPC_YRGRIM_TRUTHSEEKER_2, me->GetPosition());
                        me->DespawnOrUnsummon();
                        break;
                    case EVENT_3:
                        me->GetMotionMaster()->MovePoint(2, 4878.36f, 523.51f, -49.09f);
                        break;
                    case EVENT_4:
                        me->GetMotionMaster()->MoveJump(4880.58f, 532.99f, -43.42f, 20.0f, 10.0f, 111);
                        me->SetHomePosition(4880.58f, 532.99f, -43.42f, 1.57f);
                        break;
                    case EVENT_5:
                        DoCast(SPELL_PENTA_STRIKE);
                        events.RescheduleEvent(EVENT_5, 17000);
                        break;
                    case EVENT_6:
                        DoCast(SPELL_BLADESTORM);
                        events.RescheduleEvent(EVENT_6, 21000);
                        break;
                    case EVENT_7:
                        DoCastVictim(SPELL_SHIELD_BASH);
                        events.RescheduleEvent(EVENT_7, 9000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_yrgrim_the_truthseekerAI(creature);
    }
};

//106172
class npc_sr_runeshaper_griselda : public CreatureScript
{
public:
    npc_sr_runeshaper_griselda() : CreatureScript("npc_sr_runeshaper_griselda") {}

    struct npc_sr_runeshaper_griseldaAI : ScriptedAI
    {
        npc_sr_runeshaper_griseldaAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        EventMap events;
        bool switchTarget;

        void Reset() override
        {
            events.Reset();
            DoCast(me, SPELL_GOLDEN_GHOST_VISUAL, true);
            SetCombatMovement(false);
            switchTarget = false;
        }

        void EnterCombat(Unit* /*who*/) override
        //16:16
        {
            events.RescheduleEvent(EVENT_2, 1000);
            events.RescheduleEvent(EVENT_3, 7000);
            events.RescheduleEvent(EVENT_4, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(3);
        }

        void DoAction(int32 const action) override
        {
            events.RescheduleEvent(EVENT_1, 13000);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
            DoZoneInCombat(me, 100.0f);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_RAZOR_ICE)
                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    Position pos;
                    float dist = 5.0f;
                    for (uint8 i = 0; i < 17; i++)
                    {
                        target->GetNearPosition(pos, dist + frand(2.0, 8.0f), frand(0, 6.0f));

                        if (Unit* owner = me->GetAnyOwner())
                            if (Creature* summon = owner->SummonCreature(NPC_RAZOR_ICE, pos, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            {
                                summon->SetReactState(REACT_PASSIVE);
                                summon->CastSpell(summon, SPELL_RAZOR_ICE_AT, true);
                                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                            }
                    }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (me->GetDistance(me->GetHomePosition()) >= 60.0f)
            {
                EnterEvadeMode();
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        Talk(0);
                        me->GetMotionMaster()->MovePoint(1, 4881.51f, 511.34f, -48.90f);
                        break;
                    case EVENT_2:
                        DoCastVictim(SPELL_FROSTBOLT);
                        events.RescheduleEvent(EVENT_2, 4000);
                        break;
                    case EVENT_3:
                        Talk(2);
                        if (Unit* player = me->SelectNearestPlayer(40.0f))
                            DoCast(player, SPELL_RAZOR_ICE, false);
                        events.RescheduleEvent(EVENT_3, 31000);
                        break;
                    case EVENT_4:
                        Talk(1);
                        if (!switchTarget)
                        {
                            switchTarget = true;
                            if (Unit* owner = me->GetAnyOwner())
                                owner->AddAura(SPELL_ICE_BLOCK_TARGET_AURA, owner);
                        }
                        else
                        {
                            switchTarget = false;
                            me->AddAura(SPELL_ICE_BLOCK_TARGET_AURA, me);
                        }
                        DoCast(SPELL_ICE_BLOCK);
                        events.RescheduleEvent(EVENT_4, 29000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_runeshaper_griseldaAI(creature);
    }
};

//105883, 105886, 106203, 106205
class npc_sr_argent_hippogryph : public CreatureScript
{
public:
    npc_sr_argent_hippogryph() : CreatureScript("npc_sr_argent_hippogryph") {}

    struct npc_sr_argent_hippogryphAI : ScriptedAI
    {
        npc_sr_argent_hippogryphAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply && (me->GetMapId() == 1220 || me->GetMapId() == 1495))
                me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (id == 4 && me->GetAnyOwner())
            {
                if (Player* owner = me->GetAnyOwner()->ToPlayer())
                {
                    if (me->GetEntry() == NPC_HIPPOGRYPH_DALARAN_SUM)
                    {
                        owner->SetScenarioId(1082);
                        owner->CastSpell(owner, SPELL_FLY_TO_STORMHEIM, true);
                    }
                    if (me->GetEntry() == NPC_HIPPOGRYPH_SCENARIO_SUM)
                    {
                        owner->CastSpell(owner, SPELL_RETURN_TO_DALARAN, true);
                    }
                    me->DespawnOrUnsummon(500);
                }
            }
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (me->isSummon())
                return;

            if (Player* player = clicker->ToPlayer())
            {
                if (me->GetEntry() == NPC_HIPPOGRYPH_DALARAN)
                {
                    QuestStatus status = player->GetQuestStatus(42017);
                    if (status == QUEST_STATUS_INCOMPLETE)
                    {
                        player->CastSpell(player, SPELL_SUMMON_HIPPO, true);
                        me->DestroyForPlayer(player);
                    }
                }
                if (me->GetEntry() == NPC_HIPPOGRYPH_SCENARIO)
                {
                    if (InstanceScript* instance = player->GetInstanceScript())
                        if (instance->GetData(DATA_YRGRIM_EVENT) == 7)
                        {
                            player->CastSpell(player, SPELL_SUMMON_HIPPO_INST, true);
                            me->DestroyForPlayer(player);
                        }
                }
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sr_argent_hippogryphAI(creature);
    }
};

//249420
class go_sr_truthguard : public GameObjectScript
{
public:
    go_sr_truthguard() : GameObjectScript("go_sr_truthguard") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (!target)
            return;

        if (Player* player = target->ToPlayer())
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->getScenarionStep() == DATA_STAGE_FINAL)
                {
                    if (state == GO_JUST_DEACTIVATED || player->HasItemCount(128866))
                    {
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50545); //Step End
                        if (instance->GetData(DATA_YRGRIM_EVENT) == 6)
                            instance->SetData(DATA_YRGRIM_EVENT, 7);
                        player->CastSpell(player, SPELL_TRUTHGUARD_CREDIT, true);
                        player->CastSpell(player, SPELL_TRUTHGUARD_SCENE, true);
                        if (Creature* trigger = go->FindNearestCreature(NPC_TRUTHGUARD_OATHSEEKER, 20.0f, true))
                            trigger->DespawnOrUnsummon();

                        if (state == GO_ACTIVATED)
                            go->Delete();
                    }
                }
        }
    }
};

void AddSC_shields_rest()
{
    new npc_sr_orik_trueheart_intro();
    new npc_sr_orik_cato_script();
    new npc_sr_cryptstalker_event();
    new npc_sr_quicksteel_arrow();
    new npc_sr_spectral_windshaper();
    new npc_sr_fierce_winds();
    new npc_sr_yrgrim_the_truthseeker();
    new npc_sr_runeshaper_griselda();
    new npc_sr_argent_hippogryph();
    new go_sr_truthguard();
};
