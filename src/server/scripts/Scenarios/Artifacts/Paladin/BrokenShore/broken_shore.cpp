/*
    http://uwow.biz
    Paladin Specialization: Retribution
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "broken_shore.h"

//Phases: 5171 5940 5942 6181

enum eSpells
{
    SPELL_FINGER_PAIN_VIS_1         = 192497,
    SPELL_FINGER_PAIN_VIS_2         = 192521,
    SPELL_PORTAL_BEAM               = 192578,

    SPELL_INFERNAL_SPAWN            = 185302,


    //DARK_INQUISITOR - 91697
    SPELL_DRAIN_SOUL                = 181965,
    SPELL_SOULGORGED                = 190674,
    SPELL_MIND_REND                 = 187706,
    SPELL_ICY_GRASP                 = 188292,
    
    //JAILER_ZERUS_BOSS - 91672
    SPELL_ZERUS_DRAIN_SOUL_VIS      = 190711,
    SPELL_ZERUS_DRAIN_LIFE          = 182217,
    SPELL_JAILER_PRISON             = 193006,
    SPELL_INQUISITOR_BEAM           = 192596,
    
    //THE_JAILERS_PRISON - 97824
    SPELL_PRISON_JUMP               = 193057,
    SPELL_PRISON_AT                 = 193010,

    //BALNAZZAR - 90981
    SPELL_BALNAZZAR_SPAWN           = 216713,
    SPELL_DOMINATE_MIND             = 180862,
    SPELL_HAZE_DREADLORD            = 196934,
    SPELL_MIND_BLAST                = 196944,
    SPELL_BLINK                     = 196960,
    SPELL_CALL_OF_THE_LEGION        = 196977,
    SPELL_BALNAZZAR_CREDIT          = 227853,

    //Other
    SPELL_FLY_TO_THE_BROKEN_SHORE   = 197545,
    SPELL_RETRIEVING_THE_ASHBRINGER = 180850,
    SPELL_BALNAZZAR_REVEAL          = 192145,
    SPELL_TIRION_SOUL_VISUAL        = 187404,
};

//90883, 91144
class npc_bs_lord_maxwell_tyrosus : public CreatureScript
{
public:
    npc_bs_lord_maxwell_tyrosus() : CreatureScript("npc_bs_lord_maxwell_tyrosus") {}

    struct npc_bs_lord_maxwell_tyrosusAI : ScriptedAI
    {
        npc_bs_lord_maxwell_tyrosusAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
            changePos = false;
            moveToTirion = false;
            introDone = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool changePos;
        bool moveToTirion;
        bool introDone;

        void Reset() override
        {
            events.Reset();
            if (me->GetEntry() == NPC_LORD_MAXWELL_TYROSUS_Q)
            {
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                me->SetReactState(REACT_PASSIVE);
                events.RescheduleEvent(EVENT_1, 500);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (me->GetEntry() == NPC_LORD_MAXWELL_TYROSUS)
            {
                if (instance->getScenarionStep() == DATA_STAGE_1)
                {
                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46018); //Step 2
                }

                me->CallForHelp(50.0f);

                if (!changePos)
                {
                    changePos = true;
                    Position pos;
                    me->GetNearPosition(pos, 20.0f, 0.0f);
                    me->SetHomePosition(pos);
                }
            }
        }
        
        void MoveInLineOfSight(Unit* who) override
        {  
            if (me->GetEntry() != NPC_LORD_MAXWELL_TYROSUS)
                return;
            
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!introDone && me->IsWithinDistInMap(who, 20.0f))
            {
                DoCast(195372);
                introDone = true;
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
                    case EVENT_1:
                        if (Player* player = me->SelectNearestPlayer(20.0f))
                        {
                            if (instance->getScenarionStep() == DATA_STAGE_FINAL)
                            {
                                moveToTirion = true;
                                me->GetMotionMaster()->MovePath((me->GetEntry() * 100), false);
                            }
                        }
                        if (!moveToTirion)
                            events.RescheduleEvent(EVENT_1, 1000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_lord_maxwell_tyrosusAI(creature);
    }
};

//92676
class npc_bs_highlord_tirion_fordring : public CreatureScript
{
public:
    npc_bs_highlord_tirion_fordring() : CreatureScript("npc_bs_highlord_tirion_fordring") {}

    struct npc_bs_highlord_tirion_fordringAI : ScriptedAI
    {
        npc_bs_highlord_tirion_fordringAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            startConvers = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool startConvers;
        bool finded = false;
        uint32 findtimer = 2000;

        void UpdateAI(uint32 diff) override
        {
            if (findtimer <= diff)
            {
                if (instance->getScenarionStep() == DATA_STAGE_FINAL)
                {
                    if (!finded && me->FindNearestCreature(91144, 20.f, true) && me->SelectNearestPlayer(10.f))
                    {
                        finded = true;
                        DoCast(me, 199932, true); //Visual
                        events.RescheduleEvent(EVENT_1, 1000);
                    }
                }
                findtimer = 2000;
            }
            else
                findtimer -= diff;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        if (Player* player = me->SelectNearestPlayer(30.0f))
                        {
                            startConvers = true;
                            DoCast(me, 195445, true); //Conversation
                            events.RescheduleEvent(EVENT_2, 30000);
                        }
                        if (!startConvers)
                            events.RescheduleEvent(EVENT_1, 1000);
                        break;
                    case EVENT_2:
                    {
                        if (Creature* trigger = me->SummonCreature(NPC_TIRION_FORDRING_SOUL, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 7000))
                        {
                            trigger->SetSpeed(MOVE_WALK, 0.3f);
                            trigger->SetSpeed(MOVE_RUN, 0.3f);
                            trigger->SetSpeed(MOVE_FLIGHT, 0.3f);
                            trigger->CastSpell(trigger, SPELL_TIRION_SOUL_VISUAL, true);
                            trigger->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 30.0f, false);
                        }
                        me->RemoveAllAuras();
                        std::list<Creature*> creatureList;
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ARGENT_PHALANX_1, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ARGENT_PHALANX_3, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_RIGHTEOUS_CRUSADER_1, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_RIGHTEOUS_CRUSADER_2, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_RIGHTEOUS_CRUSADER_3, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ARGENT_DAWNBRINGER_1, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ARGENT_DAWNBRINGER_2, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ARGENT_DAWNBRINGER_3, 20.0f);
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_LORD_MAXWELL_TYROSUS_Q, 20.0f);
                        for (auto cre : creatureList)
                            cre->SetStandState(UNIT_STAND_STATE_KNEEL);
                        events.RescheduleEvent(EVENT_3, 10000);
                        break;
                    }
                    case EVENT_3:
                        if (Creature* tyrosus = me->FindNearestCreature(NPC_LORD_MAXWELL_TYROSUS_Q, 20.0f))
                        {
                            tyrosus->SetStandState(UNIT_STAND_STATE_STAND);
                            tyrosus->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        }
                        if (instance->getScenarionStep() == DATA_STAGE_FINAL)
                            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46162); //Step End.
                        break;
                    
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_highlord_tirion_fordringAI(creature);
    }
};

//97621
class npc_bs_jailer_zerus : public CreatureScript
{
public:
    npc_bs_jailer_zerus() : CreatureScript("npc_bs_jailer_zerus") {}

    struct npc_bs_jailer_zerusAI : ScriptedAI
    {
        npc_bs_jailer_zerusAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->SetReactState(REACT_PASSIVE);
            instance = me->GetInstanceScript();
            intro = false;
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        std::list<ObjectGuid> goList;
        bool intro;
        bool changePos;
        uint8 posPoint;
        uint8 sumDiedCount;

        void Reset() override
        {
            posPoint = 0;
            sumDiedCount = 0;
            changePos = false;
            events.RescheduleEvent(EVENT_1, 5000);
            me->SummonCreature(NPC_DARK_INQUISITOR, -2509.27f, 93.65f, 8.54f, 6.19f);
            me->SummonCreature(NPC_DARK_INQUISITOR, -2509.81f, 79.10f, 9.35f, 0.09f);
        }

        void SummonTrash(uint8 id, bool secondSpawn)
        {
            switch (id)
            {
                case 0:
                case 1:
                {
                    if (!secondSpawn)
                    {
                        me->SummonCreature(NPC_WRATHGUARD_CLEAVER_1, portalSpawnPos[id]);
                        me->SummonCreature(NPC_WRATHGUARD_CLEAVER_2, portalSpawnPos[id]);
                        me->SummonCreature(NPC_MOARG_BRUTALIZER, portalSpawnPos[id]);
                        me->SummonCreature(NPC_RAVENOUS_FELSTALKER_1, portalSpawnPos[id]);
                        me->SummonCreature(NPC_WRATHGUARD_CLEAVER_2, portalSpawnPos[id]);
                        me->SummonCreature(NPC_RAVENOUS_FELSTALKER_2, portalSpawnPos[id]);
                    }
                    else
                    {
                        me->SummonCreature(NPC_WRATHGUARD_CLEAVER_1, portalSpawnPos[id]);
                        me->SummonCreature(NPC_WRATHGUARD_CLEAVER_2, portalSpawnPos[id]);
                        me->SummonCreature(NPC_RAVENOUS_FELSTALKER_1, portalSpawnPos[id]);
                    }
                    break;
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_DARK_INQUISITOR)
                return;

            if (posPoint < 12)
            {
                summon->GetMotionMaster()->MovePoint(1, forcesPoint[posPoint]);
                summon->SetHomePosition(forcesPoint[posPoint]);
            }
            else
            {
                if (Creature* tyrosus = instance->instance->GetCreature(instance->GetGuidData(NPC_LORD_MAXWELL_TYROSUS)))
                {
                    Position pos;
                    float dist = frand(5.0, 15.0f);
                    tyrosus->GetNearPosition(pos, dist, frand(3.0f, 6.0f));
                    summon->GetMotionMaster()->MovePoint(1, pos);
                    summon->SetHomePosition(pos);
                }
            }
            posPoint++;
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == NPC_DARK_INQUISITOR || sumDiedCount > 20)
                return;

            sumDiedCount++;

            if (sumDiedCount == 13)
            {
                if (Creature* tyrosus = instance->instance->GetCreature(instance->GetGuidData(NPC_LORD_MAXWELL_TYROSUS)))
                {
                    Position pos;
                    for (uint8 i = 0; i < 2; i++)
                    {
                        tyrosus->GetNearPosition(pos, 10.0f, frand(0.0f, 6.28f));
                        me->SummonCreature(NPC_BURNING_CRUSHER, pos);
                    }
                    events.RescheduleEvent(EVENT_5, 2000);
                }
            }
            else if (sumDiedCount == 20)
            {
                for (auto& guid : goList)
                    if (GameObject* portal = ObjectAccessor::GetGameObject(*me, guid))
                        portal->SetAnimKitId(8547, true); //Visual Destroy Portals
                me->SummonCreature(NPC_DOOMGUARD_INCINERATOR, -2530.51f, 84.51f, 24.55f);
                DoCast(me, 195404, true);
                events.RescheduleEvent(EVENT_6, 1000);
                me->DespawnOrUnsummon(1200);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
             if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                me->SetFacingTo(0.14f);
                events.RescheduleEvent(EVENT_3, 2000);
            }
        }

        void DoAction(int32 const action) override
        {
            if (!changePos)
            {
                changePos = true;
                std::list<GameObject*> getGoList;
                me->GetGameObjectListWithEntryInGrid(getGoList, GO_DEMON_PORTAL_3, 100.0f);
                events.RescheduleEvent(EVENT_2, 5000);
                for (auto& go : getGoList)
                    goList.push_back(go->GetGUID());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        if (!intro)
                        {
                            DoCast(me, SPELL_FINGER_PAIN_VIS_1, true);
                            if (GameObject* portal = me->FindNearestGameObject(GO_DEMON_PORTAL_1, 40.0f))
                                portal->UseDoorOrButton();
                            intro = true;
                            SummonTrash(0, false);
                            events.RescheduleEvent(EVENT_1, 3000);
                        }
                        else
                        {
                            DoCast(me, SPELL_FINGER_PAIN_VIS_2, true);
                            if (GameObject* portal = me->FindNearestGameObject(GO_DEMON_PORTAL_2, 30.0f))
                                portal->UseDoorOrButton();
                            SummonTrash(1, false);
                        }
                        break;
                    case EVENT_2:
                    {
                        bool guardLeft = false;
                        std::list<Creature*> creatureList;
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_DARK_INQUISITOR, 20.0f);
                        for (auto cre : creatureList)
                        {
                            cre->DespawnOrUnsummon(15000);
                            if (!guardLeft)
                            {
                                guardLeft = true;
                                cre->GetMotionMaster()->MovePoint(1, -2569.04f, 75.74f, 24.54f, false);
                            }
                            else
                                cre->GetMotionMaster()->MovePoint(1, -2570.89f, 90.47f, 25.04f, false);
                        }
                        me->GetMotionMaster()->MovePoint(1, -2567.84f, 83.30f, 24.25f, false); //Last pos
                        break;
                    }
                    case EVENT_3:
                        DoCast(me, SPELL_PORTAL_BEAM, true);
                        events.RescheduleEvent(EVENT_4, 11000);
                        break;
                    case EVENT_4:
                    {
                        for (auto& guid : goList)
                        {
                            if (GameObject* portal = ObjectAccessor::GetGameObject(*me, guid))
                            {
                                portal->SetRespawnTime(604800);
                                portal->SetAnimKitId(1254, false);
                                //portal->SetAnimKitId(6974, true); ?
                            }
                        }
                        SummonTrash(0, true);
                        SummonTrash(1, true);
                        break;
                    }
                    case EVENT_5:
                        instance->SetData(DATA_KILL_TRASH, DONE);
                        break;
                    case EVENT_6:
                        for (auto& guid : goList)
                            if (GameObject* portal = ObjectAccessor::GetGameObject(*me, guid))
                                portal->Delete();
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_jailer_zerusAI(creature);
    }
};

//95984,91634,97566,91636,97567,91697,96005
class npc_bs_enemy_forces : public CreatureScript
{
public:
    npc_bs_enemy_forces() : CreatureScript("npc_bs_enemy_forces") {}

    struct npc_bs_enemy_forcesAI : ScriptedAI
    {
        npc_bs_enemy_forcesAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
            into = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool into;

        void Reset() override
        {
            events.Reset();
            if (me->GetEntry() == NPC_DARK_INQUISITOR && !into)
            {
                into = true;
                SetCombatMovement(false);
                events.RescheduleEvent(EVENT_5, 500);
            }
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (me->GetEntry() == NPC_BURNING_CRUSHER)
            {
                DoCast(me, SPELL_INFERNAL_SPAWN, true);
                me->StopAttack();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                events.RescheduleEvent(EVENT_1, 4000);
            }
            if (me->GetEntry() == NPC_DARK_INQUISITOR && summoner->GetEntry() == NPC_JAILER_ZERUS)
            {
                into = true;
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
            }
            if (summoner->GetEntry() == NPC_JAILER_ZERUS_BOSS)
            {
                SetFlyMode(true);
                DoZoneInCombat(me, 100.0f);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (me->GetEntry() == NPC_DARK_INQUISITOR)
                return;

            if (instance->getScenarionStep() == DATA_STAGE_1)
            {
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46018); //Step 2
            if (Unit* owner = me->GetAnyOwner())
                if (Creature* summoner = owner->ToCreature())
                    summoner->AI()->DoAction(true);

                //me->CallForHelp(50.0f);
            }
            if (instance->GetData(DATA_TRASH_FIGHT) != IN_PROGRESS)
                instance->SetData(DATA_TRASH_FIGHT, IN_PROGRESS);
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
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoZoneInCombat(me, 100.0f);
                        break;
                    case EVENT_2:
                    {
                        std::list<Creature*> creatureList;
                        me->GetCreatureListWithEntryInGrid(creatureList, 91755, 20.0f);
                        for (auto cre : creatureList)
                            me->Kill(cre);
                        SetCombatMovement(true);
                        DoCast(me, SPELL_SOULGORGED, true);
                        events.RescheduleEvent(EVENT_3, 3000);
                        events.RescheduleEvent(EVENT_4, 10000);
                        break;
                    }
                    case EVENT_3:
                        DoCastVictim(SPELL_MIND_REND);
                        events.RescheduleEvent(EVENT_3, 8000);
                        break;
                    case EVENT_4:
                        DoCastVictim(SPELL_ICY_GRASP);
                        events.RescheduleEvent(EVENT_4, 10000);
                        break;
                    case EVENT_5:
                    {
                        if (me->GetAnyOwner() && me->GetAnyOwner()->GetEntry() == NPC_JAILER_ZERUS)
                            break;
                        if (Player* player = me->SelectNearestPlayer(35.0f)) 
                            if (player)
                            {
                                events.RescheduleEvent(EVENT_2, 3000);
                                DoCast(me, SPELL_DRAIN_SOUL, true);
                                AttackStart(player);
                                break;
                            }
                        events.RescheduleEvent(EVENT_5, 500);
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_enemy_forcesAI(creature);
    }
};

//95962
class npc_bs_doomguard_incinerator : public CreatureScript
{
public:
    npc_bs_doomguard_incinerator() : CreatureScript("npc_bs_doomguard_incinerator") {}

    struct npc_bs_doomguard_incineratorAI : ScriptedAI
    {
        npc_bs_doomguard_incineratorAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;
        uint8 flameCastCount;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            flameCastCount = 0;
            events.RescheduleEvent(EVENT_1, 1000);
            me->GetMotionMaster()->MovePoint(1, -2622.49f, 23.85f, 69.47f);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                events.Reset();
                me->SetVisible(false);
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
                        events.RescheduleEvent(EVENT_1, 1000);
                        for (uint8 i = 0; i < 3; i++)
                        {
                            me->CastSpell(flameTarget[flameCastCount], 190666, true);
                            flameCastCount++;
                        }
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_doomguard_incineratorAI(creature);
    }
};

//91672
class npc_bs_boss_jailer_zerus : public CreatureScript
{
public:
    npc_bs_boss_jailer_zerus() : CreatureScript("npc_bs_boss_jailer_zerus") {}

    struct npc_bs_boss_jailer_zerusAI : ScriptedAI
    {
        npc_bs_boss_jailer_zerusAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

        SummonList summons;
        EventMap events;
        bool sumHelper;

        void Reset() override
        {
            summons.DespawnAll();
            events.Reset();
            sumHelper = false;
            DoCast(me, SPELL_ZERUS_DRAIN_SOUL_VIS, true);
        }

        void EnterCombat(Unit* /*who*/) override
        //13:37
        {
            me->SummonCreature(NPC_DEMON_PORTAL, demonPortalPos[0]);
            me->SummonCreature(NPC_DEMON_PORTAL, demonPortalPos[1]);

            me->RemoveAurasDueToSpell(SPELL_ZERUS_DRAIN_SOUL_VIS);
            events.RescheduleEvent(EVENT_1, 5000); //13:42, 14:07
            events.RescheduleEvent(EVENT_2, 15000); //13:52, 14:18
        }

        void JustDied(Unit* /*killer*/) override
        {
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType dmgType) override
        {
            if (me->HealthBelowPct(51) && !sumHelper)
            {
                sumHelper = true;
                events.RescheduleEvent(EVENT_3, 500);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                me->SetFacingTo(zerusSumPos[0].GetOrientation());
            }
            else if (id == 2)
            {
                me->SetFacingTo(zerusSumPos[1].GetOrientation());
            }
            DoCast(me, SPELL_INQUISITOR_BEAM, true);
            me->SummonCreature(NPC_DARK_INQUISITOR, zerusSumPos[1 + id]);
            events.RescheduleEvent(EVENT_4, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            EnterEvadeIfOutOfCombatArea(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCastVictim(SPELL_ZERUS_DRAIN_LIFE);
                        events.RescheduleEvent(EVENT_1, 25000);
                        break;
                    case EVENT_2:
                        DoCastVictim(SPELL_JAILER_PRISON);
                        events.RescheduleEvent(EVENT_2, 26000);
                        break;
                    case EVENT_3:
                        me->StopAttack();
                        if (me->GetDistance(zerusSumPos[0]) < me->GetDistance(zerusSumPos[1]))
                            me->GetMotionMaster()->MovePoint(1, zerusSumPos[0]);
                        else
                            me->GetMotionMaster()->MovePoint(2, zerusSumPos[1]);
                        break;
                    case EVENT_4:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_boss_jailer_zerusAI(creature);
    }
};

//97824
class npc_bs_the_jailer_prison : public CreatureScript
{
public:
    npc_bs_the_jailer_prison() : CreatureScript("npc_bs_the_jailer_prison") {}

    struct npc_bs_the_jailer_prisonAI : ScriptedAI
    {
        npc_bs_the_jailer_prisonAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint16 timerAT;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            timerAT = 2000;
        }

        void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId) override
        {
            if (spellId == SPELL_PRISON_JUMP)
                me->RemoveAurasDueToSpell(SPELL_PRISON_AT);
        }

        void UpdateAI(uint32 diff) override
        {
            if (timerAT)
            {
                if (timerAT <= diff)
                {
                    timerAT = 0;
                    DoCast(me, SPELL_PRISON_AT, true);
                }
                else
                    timerAT -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_the_jailer_prisonAI(creature);
    }
};

//90981
class npc_bs_balnazzar : public CreatureScript
{
public:
    npc_bs_balnazzar() : CreatureScript("npc_bs_balnazzar") {}

    struct npc_bs_balnazzarAI : ScriptedAI
    {
        npc_bs_balnazzarAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
            me->SetVisible(false);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
            intro = false;
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        bool intro;
        bool fightEnd;

        void Reset() override
        {
            summons.DespawnAll();
            events.Reset();
            fightEnd = false;
        }

        void EnterCombat(Unit* /*who*/) override
        //21:26
        {
            events.RescheduleEvent(EVENT_5, 11000);
            events.RescheduleEvent(EVENT_6, 3000);
            events.RescheduleEvent(EVENT_7, 16000);
            events.RescheduleEvent(EVENT_8, 1000);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_HAZE_DREADLORD)
            {
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, 196891, true); //AT
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_BALNAZZAR_REVEAL)
                events.RescheduleEvent(EVENT_1, 4000);
        }

        void DoAction(int32 const action) override
        {
            intro = true;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
                damage = 0;

            if (me->HealthBelowPct(15) && !fightEnd)
            {
                fightEnd = true;
                DoCast(me, SPELL_BALNAZZAR_CREDIT, true);
                events.Reset();
                me->StopAttack();
                summons.DespawnAll();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                DoCast(me, 152821, true); //Morph
                me->SendPlaySpellVisualKit(0, 61036); //SMSG_PLAY_SPELL_VISUAL_KIT
                if (instance->getScenarionStep() == DATA_STAGE_6)
                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46149); //Step 7. Final
                me->DespawnOrUnsummon(3000);
            }
        }

        void SummonConvers(uint32 conversID)
        {
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), conversID, me, nullptr, me->GetPosition()))
                delete conversation;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && intro)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        me->SetVisible(true);
                        DoCast(me, SPELL_BALNAZZAR_SPAWN, true);
                        events.RescheduleEvent(EVENT_2, 2000);
                        break;
                    case EVENT_2:
                        //SummonConvers(628);
                        events.RescheduleEvent(EVENT_3, 6000);
                        break;
                    case EVENT_3:
                        DoCast(me, SPELL_DOMINATE_MIND, true);
                        events.RescheduleEvent(EVENT_4, 8000);
                        break;
                    case EVENT_4:
                        //SummonConvers(632);
                        break;
                    case EVENT_5:
                        DoCast(me, SPELL_HAZE_DREADLORD, true);
                        for (uint8 i = 0; i < 10; i++)
                            me->SummonCreature(NPC_HAZE_DREADLORD, hazePos[i]);
                        break;
                    case EVENT_6:
                        if (Unit* target = me->getVictim())
                            if (!me->IsWithinMeleeRange(target))
                                DoCast(target, SPELL_MIND_BLAST);
                        events.RescheduleEvent(EVENT_6, 2000);
                        break;
                    case EVENT_7:
                    {
                        std::list<Creature*> creatureList;
                        me->GetCreatureListWithEntryInGrid(creatureList, NPC_HAZE_DREADLORD, 80.0f);
                        Trinity::Containers::RandomResizeList(creatureList, 1);
                        for (auto target : creatureList)
                            DoCast(target, SPELL_BLINK);
                        events.RescheduleEvent(EVENT_7, 30000);
                        break;
                    }
                    case EVENT_8:
                        if (me->GetPositionZ() > 40.0f)
                            EnterEvadeMode();
                        events.RescheduleEvent(EVENT_8, 1000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_balnazzarAI(creature);
    }
};

//108997
class npc_bs_dominate_mind : public CreatureScript
{
public:
    npc_bs_dominate_mind() : CreatureScript("npc_bs_dominate_mind") {}

    struct npc_bs_dominate_mindAI : ScriptedAI
    {
        npc_bs_dominate_mindAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint16 mindTimer;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            mindTimer = 1000;
            me->NearTeleportTo(-2747.67f, -325.935f, 40.01f, 5.37f);
        }

        void UpdateAI(uint32 diff) override
        {
            if (mindTimer)
            {
                if (mindTimer <= diff)
                {
                    mindTimer = 0;
                    if (Unit* owner = me->GetAnyOwner())
                        owner->CastSpell(me, 52391, true); //Ride Vehicle
                }
                else
                    mindTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_dominate_mindAI(creature);
    }
};

//92940
class npc_bs_argent_hippogryph : public CreatureScript
{
public:
    npc_bs_argent_hippogryph() : CreatureScript("npc_bs_argent_hippogryph") {}

    struct npc_bs_argent_hippogryphAI : ScriptedAI
    {
        npc_bs_argent_hippogryphAI(Creature* creature) : ScriptedAI(creature) {}

        bool summon = false;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summon = true;
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (me->GetMapId() == 0)
                    me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);
                else if (me->GetMapId() == 1220)
                    me->GetMotionMaster()->MovePath(me->GetEntry() * 100 + 1, false);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (id == 4)
            {
                if (me->GetAnyOwner())
                    if (Player* owner = me->GetAnyOwner()->ToPlayer())
                    {
                        owner->SetScenarioId(775);
                        owner->CastSpell(owner, SPELL_FLY_TO_THE_BROKEN_SHORE, true);
                        me->DespawnOrUnsummon(500);
                    }
            }
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (!summon)
            {
                if (Player* player = clicker->ToPlayer())
                {
                    QuestStatus status = player->GetQuestStatus(38376);
                    if (status == QUEST_STATUS_INCOMPLETE)
                    {
                        clicker->CastSpell(clicker, 183677, true);
                        me->DestroyForPlayer(player);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_argent_hippogryphAI(creature);
    }
};

//247318
class go_bs_the_ashbringer : public GameObjectScript
{
public:
    go_bs_the_ashbringer() : GameObjectScript("go_bs_the_ashbringer") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (!target)
            return;

        if (Player* player = target->ToPlayer())
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->getScenarionStep() == DATA_STAGE_4)
                {
                    if (state == GO_JUST_DEACTIVATED || player->HasItemCount(120978))
                    {
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46130); //Step 4
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 775, 1);
                        if (Creature* trigger = go->FindNearestCreature(103454, 10.0f))
                            trigger->DespawnOrUnsummon();

                        player->CastSpell(player, SPELL_RETRIEVING_THE_ASHBRINGER, true);
                        if (state == GO_ACTIVATED)
                            go->Delete();
                    }
                }
        }
    }
};

//183677
class spell_fly_to_broken_shore : public SpellScriptLoader
{
    public:
        spell_fly_to_broken_shore() : SpellScriptLoader("spell_fly_to_broken_shore") {}

        class spell_fly_to_broken_shore_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_fly_to_broken_shore_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(EFFECT_0);

                if (Unit* caster = GetCaster())
                {
                    if (caster->GetMapId() == 1220) //New Dalaran
                        GetHitDest()->Relocate(-839.61f, 4253.69f, 746.44f, 1.34f);
                    else
                        GetHitDest()->Relocate(2278.23f, -5277.41f, 82.236f, 2.61f);
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_fly_to_broken_shore_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_fly_to_broken_shore_SpellScript();
        }
};

//216690
class spell_bs_dominate_mind : public SpellScriptLoader
{
    public:
        spell_bs_dominate_mind() : SpellScriptLoader("spell_bs_dominate_mind") { }

        class spell_bs_dominate_mind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_bs_dominate_mind_AuraScript);

            bool unbrekable = false;
            uint16 timer = 4000;

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (Creature* trigger = GetTarget()->FindNearestCreature(NPC_DOMINATE_MIND, 30.0f))
                    trigger->DespawnOrUnsummon();
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (Creature* balnazzar = GetTarget()->FindNearestCreature(NPC_BALNAZZAR, 30.0f))
                    balnazzar->AI()->DoAction(true);
            }

            void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
            {
                if (timer)
                {
                    if (!GetCaster())
                        return;

                    if (!unbrekable)
                    {
                        if (timer <= diff)
                        {
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (instance->getScenarionStep() == DATA_STAGE_4)
                                {
                                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46130); //Step 5
                                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46506); //Step 5
                                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52186); //Step 5
                                }
                            unbrekable = true;
                            timer = 8000;
                        }
                        else timer -= diff;
                    }
                    else
                    {
                        if (timer <= diff)
                        {
                            GetCaster()->CastSpell(GetCaster(), 217042, true);
                            timer = 0;
                        }
                        else timer -= diff;
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_bs_dominate_mind_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_bs_dominate_mind_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
                OnEffectUpdate += AuraEffectUpdateFn(spell_bs_dominate_mind_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_MOD_FACTION);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_bs_dominate_mind_AuraScript();
        }
};

void AddSC_broken_shore()
{
    new npc_bs_lord_maxwell_tyrosus();
    new npc_bs_highlord_tirion_fordring();
    new npc_bs_jailer_zerus();
    new npc_bs_enemy_forces();
    new npc_bs_doomguard_incinerator();
    new npc_bs_boss_jailer_zerus();
    new npc_bs_the_jailer_prison();
    new npc_bs_balnazzar();
    new npc_bs_dominate_mind();
    new npc_bs_argent_hippogryph();
    new go_bs_the_ashbringer();
    new spell_fly_to_broken_shore();
    new spell_bs_dominate_mind();
}
