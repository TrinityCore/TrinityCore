#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectMgr.h"

//TODO: DB work

enum
{
	QUEST_DESCENT_ALLIANCE = 54969,
	QUEST_DESCENT_HORDE = 54018,
    QUEST_FORTUNATE_SOULS_ALLIANCE = 56640,
    QUEST_FORTUNATE_SOULS_HORDE = 54012,
    GO_GLIMMERING_CHEST = 322413,
    QUEST_SCRYING_STONES_HORDE = 56210,
    QUEST_SCRYING_STONES_ALLIANCE = 56210,
    QUEST_UP_AGAINST_IT_HORDE = 56429,
    QUEST_UP_AGAINST_IT_ALLIANCE = 56644,
    SCENE_SEEING_THE_ARMY = 2619,
    QUEST_SCOUTING_THE_PALACE_HORDE = 55481,
    QUEST_SCOUTING_THE_PALACE_ALLIANCE = 56350,
    SCENE_SCOUTING_THE_TIDESTONE = 2625,
    QUEST_DISRUPTION_OF_POWER_ALLIANCE = 56641,
    QUEST_DISRUPTION_OF_POWER_HORDE = 55092,
    QUEST_DARK_TIDES_HORDE = 56063,
    QUEST_DARK_TIDES_ALLIANCE = 56642,
    QUEST_WHERE_THE_ROAD_LEADS_ALLIANCE = 55175,
    QUEST_STAY_FAST_STAY_LOW_HORDE = 55094,
    SCENE_MEETING_AZSHARA_ALLIANCE = 2671,
    SCENE_MEETING_AZSHARA_HORDE = 2672,
    QUEST_A_WAY_HOME_ALLIANCE = 54972,
    QUEST_A_BOLT_HOLE_ALLIANCE = 55558,
    QUEST_WHAT_REMAINS_OF_ZIN_ASHARI_ALLIANCE = 55561,
    QUEST_SECRETS_IN_THE_RUINS = 55570,
    QUEST_HELP_THEM_SEE_THE_TRUTH = 55571,
};

//150101
struct npc_jaina_150101 : public ScriptedAI
{
    npc_jaina_150101(Creature* c) : ScriptedAI(c) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_DESCENT_ALLIANCE)
        {
            player->CastSpell(player, 130);
            player->KilledMonsterCredit(153399);
        }
        if (quest->GetQuestId() == QUEST_SCOUTING_THE_PALACE_ALLIANCE)
        {
            player->GetSceneMgr().PlaySceneByPackageId(SCENE_SCOUTING_THE_TIDESTONE);
            player->KilledMonsterCredit(152613);
        }
        if (quest->GetQuestId() == QUEST_A_WAY_HOME_ALLIANCE)
        {
            me->SummonCreature(me->GetEntry(), me->GetPosition()), TEMPSUMMON_TIMED_DESPAWN, 30000;
            player->GetScheduler().Schedule(38s, [player, this] (TaskContext /*context*/)
            {
                player->KilledMonsterCredit(150101);
            });
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        me->SetWalk(true);
        me->GetMotionMaster()->MovePoint(1, 1288.510f, -106.201f, -330.623f, true);
        this->portal_prepared = false;
        me->DespawnOrUnsummon(40s);
    }

    void MovementInform(uint32 type, uint32 pointID) override
    {
        if (type != POINT_MOTION_TYPE || pointID != 1)
            return;

        if (pointID && !this->portal_prepared)
        {
            this->portal_prepared = true;

            if (this->portal_prepared)
            {
                me->SetFacingTo(2.03f);
                me->CastSpell(nullptr, false);
                me->GetScheduler().Schedule(3s, [this] (TaskContext /*context*/)
                {
                    Talk(0);
                });
                me->GetScheduler().Schedule(5s, [this] (TaskContext /*context*/)
                {
                    me->SummonGameObject(287164, 1292.530f, -106.669f, -330.105f, 2.41f, QuaternionData(), false);
                    Talk(1);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MoveTargetedHome();
                });
            }
        }
    }

private:
    bool portal_prepared;
};

//npc_nathanos_brightcaller_150187

//150206
struct npc_chief_telemancer_oculeth : public ScriptedAI
{
    npc_chief_telemancer_oculeth(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->SetFlying(true);
        me->AddAura(1706, me); //Levitate
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_DESCENT_HORDE)
        {
            player->CastSpell(nullptr, 130);
            player->ForceCompleteQuest(QUEST_DESCENT_HORDE);
        }
    }
};

//Both

//154943 horde, 150355 ali
struct npc_generic_soldier_fortunate_souls : public ScriptedAI
{
    npc_generic_soldier_fortunate_souls(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (Player* player = clicker->ToPlayer())
        {
            switch (me->GetEntry())
            {
            case 154943:
                if (player->GetTeam() == HORDE && player->GetQuestStatus(QUEST_FORTUNATE_SOULS_HORDE) == QUEST_STATUS_INCOMPLETE)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    player->KilledMonsterCredit(154943);
                    me->ForcedDespawn(0, 15s);
                }
                break;

            case 150355:
                if (player->GetTeam() == ALLIANCE && player->GetQuestStatus(QUEST_FORTUNATE_SOULS_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    player->KilledMonsterCredit(150355);
                    me->ForcedDespawn(0, 15s);
                }
                break;
            }
        }
    }
};

//Nazjatar worldbosses
enum Wekemara
{
    DATA_WEKEMARA = 1,
    NPC_SPAWN_OF_WEKEMARA = 155702,
    NPC_WEKEMARA_HANDLER = 500516,
    EVENT_SPLIT = 1,
    EVENT_BIOELETRIC_BLAST,
    EVENT_SUBMERGE,
    EVENT_SPAWN,
    EVENT_SHOCK_BURST,
    EVENT_ELECTRIC_DISCHARGE,
    EVENT_ELECTRIFIED_SPLASH,
    EVENT_SUBMERGE_END,
    SPELL_SPIT = 303332,
    SPELL_BIOELETRIC_BLAST_CREATE_AT = 303319,
    SPELL_ELECTRIFIED_GROUND_AT_DAMAGE = 303324,
    SPELL_SHOCK_BURST_PERIODIC = 303491,
    SPELL_SHOCK_BURST_EXP = 303498,
    SPELL_ELETRIC_DISCHARGE_TRIGGER = 303451,
    SPELL_ELETRIC_DISCHARGE_DAMAGE = 303454,
    SPELL_ELETRIFIED_SPLASH_TRIGGER = 303379,
};

const Position electrified_splash_pos = { 576.556f, -225.939f, -195.691f, 4.64f };
const Position handler_spawn_at_selector_pos = { 555.200f, -180.898f, -194.454f, 5.0f };

//152671
struct boss_wekemara : public BossAI
{
    boss_wekemara(Creature* creature) : BossAI(creature, DATA_WEKEMARA) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_MANA);
        me->SetPower(POWER_MANA, 100);
        me->NearTeleportTo(me->GetHomePosition());
        me->AddUnitState(UNIT_STATE_ROOT);
        submerged = false;        
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/)// override
    {
        this->charges = 0;
        events.ScheduleEvent(EVENT_SPLIT, 1s);
        events.ScheduleEvent(EVENT_ELECTRIC_DISCHARGE, 3s);
        events.ScheduleEvent(EVENT_BIOELETRIC_BLAST, 6s);
        events.ScheduleEvent(EVENT_SHOCK_BURST, 11s);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SPAWN_OF_WEKEMARA:            
            summon->UpdatePosition(PosZ, summon->GetOrientation());
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f))
                summon->AI()->AttackStart(target);
            break;

        case NPC_WEKEMARA_HANDLER:
            if (summon->GetPositionZ() == -194.454f)
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    summon->CastSpell(target->GetPosition(), SPELL_BIOELETRIC_BLAST_CREATE_AT, false);

            if (summon->GetPositionZ() == -195.691f)
                summon->CastSpell(nullptr, SPELL_ELETRIFIED_SPLASH_TRIGGER, true);
            break;
        }
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(51) && !submerged)
        {
            submerged = true;
            events.ScheduleEvent(EVENT_ELECTRIFIED_SPLASH, 1s);
            events.ScheduleEvent(EVENT_SPAWN, 3s);
        }
    }
    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _DespawnAtEvade();
      //  me->DespawnCreaturesInArea(NPC_SPAWN_OF_WEKEMARA, 125.0f);
     //   me->DespawnCreaturesInArea(NPC_WEKEMARA_HANDLER, 125.0f);
        me->RemoveAllAreaTriggers();
    }

    void ExecuteEvent(uint32 eventid) override
    {        
        std::list<Player*> p_list;
        p_list.clear();
        me->GetPlayerListInGrid(p_list, 100.0f);
        if (p_list.empty())
            me->DespawnOrUnsummon(0, 15s);
   
        switch (eventid)
        {
        case EVENT_SPLIT:
            DoCastVictim(SPELL_SPIT, false);
            events.Repeat(2s);
            break;

        case EVENT_ELECTRIC_DISCHARGE:
            DoCastSelf(SPELL_ELETRIC_DISCHARGE_TRIGGER);
            this->charges = 0;
            if (this->charges < 3)
            {
                me->GetScheduler().Schedule(1s, [this] (TaskContext context)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->CastSpell(target, SPELL_ELETRIC_DISCHARGE_DAMAGE, true);
                        charges++;
                        if (this->charges < 3)
                            context.Repeat(2s);
                    }
                });
            }
            events.Repeat(20s);
            break;

        case EVENT_BIOELETRIC_BLAST:
        {
            me->SummonCreature(NPC_WEKEMARA_HANDLER, handler_spawn_at_selector_pos, TEMPSUMMON_TIMED_DESPAWN, 29000);
            events.Repeat(30s);
            break;
        }

        case EVENT_SHOCK_BURST:
        {
            UnitList tarlist;
           // SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : tarlist)
            {
                DoCast(targets, SPELL_SHOCK_BURST_PERIODIC, true);
                targets->GetScheduler().Schedule(12s, [this, targets] (TaskContext context)
                {
                    me->CastSpell(targets, SPELL_SHOCK_BURST_EXP, true);
                });
            }
            events.Repeat(33s);
            break;
        }

        case EVENT_SUBMERGE:
            me->AddUnitState(UNIT_STAND_STATE_SUBMERGED);
            events.CancelEvent(EVENT_SPLIT);
            events.CancelEvent(EVENT_BIOELETRIC_BLAST);
            events.CancelEvent(EVENT_SHOCK_BURST);
            events.ScheduleEvent(EVENT_SUBMERGE_END, 30s);
            me->GetScheduler().Schedule(30s, [this] (TaskContext context)
            {
                me->RemoveAura(SPELL_ELETRIFIED_SPLASH_TRIGGER);
            });
            break;

        case EVENT_SUBMERGE_END:
            me->ClearUnitState(UNIT_STAND_STATE_SUBMERGED);
            events.ScheduleEvent(EVENT_SPLIT, 1s);
            events.ScheduleEvent(EVENT_ELECTRIC_DISCHARGE, 3s);
            events.ScheduleEvent(EVENT_BIOELETRIC_BLAST, 6s);
            events.ScheduleEvent(EVENT_SHOCK_BURST, 11s);
            break;

        case EVENT_ELECTRIFIED_SPLASH:
        //    me->DespawnCreaturesInArea(NPC_WEKEMARA_HANDLER, 125.0f);
            me->SummonCreature(NPC_WEKEMARA_HANDLER, electrified_splash_pos, TEMPSUMMON_TIMED_DESPAWN, 30000);            
            break;

        case EVENT_SPAWN:
            for (uint8 i = 0; i < 21; i++)
            {
                me->SummonCreature(NPC_SPAWN_OF_WEKEMARA, me->GetRandomPoint(me->GetHomePosition(), 80.0f));
            }
            break;
        }
    }
private:
    bool submerged;
    uint8 charges;
    float PosZ = -194.0388f;
};

//21646
struct at_wakemara_bioeletric_blast : AreaTriggerAI
{
    at_wakemara_bioeletric_blast(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(30000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (target->IsPlayer())
            at->GetCaster()->CastSpell(target, SPELL_ELECTRIFIED_GROUND_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (target->IsPlayer())
            target->RemoveAura(SPELL_ELECTRIFIED_GROUND_AT_DAMAGE);
    }
};

//50516
struct npc_wekemara_handler : public ScriptedAI
{
    npc_wekemara_handler(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->CanFly();
        me->SetFlying(true);
    }
};

//150710
struct npc_hidden_treasure : public ScriptedAI
{
    npc_hidden_treasure(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
   //     me->SummonGameObject(GO_GLIMMERING_CHEST, me->GetPosition(), QuaternionData(), 60000, false);
    }
};

//322413
class go_glimmering_chest : public GameObjectScript
{
public:
    go_glimmering_chest() : GameObjectScript("go_glimmering_chest") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->AddFlag(GO_FLAG_IN_USE);
        go->GetScheduler().Schedule(100ms, [go, player] (TaskContext /*context*/)
        {            
            player->ModifyCurrency(1560, 26, true, true);
            player->ModifyCurrency(1721, 5, true, true);
            player->ModifyCurrency(1587, 16, true, true);
        });
        go->GetScheduler().Schedule(15s, [go, player] (TaskContext /*context*/)
        {
            go->RemoveFromWorld();
        });
        go->GetScheduler().Schedule(30s, [go, player] (TaskContext /*context*/)
        {
            go->AddToWorld();
        });
        if (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE || (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE))
            player->KilledMonsterCredit(154373);

        if (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE || (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE))
            player->KilledMonsterCredit(154399);

        if (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE || (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE))
            player->KilledMonsterCredit(154410);

        if (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE || (player->GetQuestStatus(QUEST_SCRYING_STONES_HORDE) == QUEST_STATUS_INCOMPLETE))
            player->KilledMonsterCredit(154411);

        return false;
    }

    void UpdateAI(uint32 diff)
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

enum ArcanoFiend
{
    SPELL_ARCANE_BLAST = 207196,
    SPELL_ARCANE_BOLT = 15254,
    SPELL_EMPOWERED_SUMMON = 303681,
    SPELL_ENCHANTED_WATERS = 298347,
    SPELL_INSTABILITY = 302210,
    SPELL_PROXIMAL_CHAOS_MISSILE = 302203, // 5 targets
    SPELL_UNLEASHED_ARCANOSPAWN_MISSILE = 302176,

    EVENT_ARCANE_BLAST = 1,
    EVENT_ARCANE_BOLT,
    EVENT_EMPOWERED_SUMMON,
    EVENT_INSTABILITY,
    EVENT_PROXIMAL_CHAOS,
    EVENT_UNLEASHED_ARCANOSPAWN
};

//153307
struct npc_unleashed_arcano_fiend : public ScriptedAI
{
    npc_unleashed_arcano_fiend(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
      //  me->DespawnCreaturesInArea(153307);
    }

    void EnterCombat(Unit* unit)// override
    {
        events.ScheduleEvent(EVENT_ARCANE_BLAST, 1s);
        events.ScheduleEvent(EVENT_ARCANE_BOLT, 5s);
        events.ScheduleEvent(EVENT_PROXIMAL_CHAOS, 10s);
        events.ScheduleEvent(EVENT_UNLEASHED_ARCANOSPAWN, 12s);
    }

    void ExecuteEvent(uint32 eventid)// override
    {
        switch (eventid)
        {
        case EVENT_ARCANE_BLAST:
            DoCastVictim(SPELL_ARCANE_BLAST, false);
            events.Repeat(2500ms);
            break;

        case EVENT_ARCANE_BOLT:
            DoCastRandom(SPELL_ARCANE_BOLT, 100.0f, false);
            events.Repeat(10s);
            break;

        case EVENT_PROXIMAL_CHAOS:
            for (uint8 i = 0; i < 6; i++)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->CastSpell(target, SPELL_PROXIMAL_CHAOS_MISSILE, true);
                }
            }
            events.Repeat(15s);
            break;

        case EVENT_UNLEASHED_ARCANOSPAWN:
            DoCastRandom(SPELL_UNLEASHED_ARCANOSPAWN_MISSILE, 100.0f, true);
            events.Repeat(17s);
            break;
        }
    }
private:
    EventMap events;
};

enum Urduu
{
    SPELL_ANGRY_STOMP = 299807,
    SPELL_CORAL_GROWTH = 299584,
    SPELL_OCEANS_CALL_MISSILE = 299418,

    EVENT_ANGRY_STOMP = 1,
    EVENT_CORAL_GROWTH,
    EVENT_OCEANS_CALL
};

//152568
struct npc_urduu : public ScriptedAI
{
    npc_urduu(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* unit)// override
    {
        events.ScheduleEvent(EVENT_ANGRY_STOMP, 3s);
        events.ScheduleEvent(EVENT_CORAL_GROWTH, 5s);
        events.ScheduleEvent(EVENT_OCEANS_CALL, 10s);
    }

    void ExecuteEvent(uint32 eventid) //override
    {
        switch (eventid)
        {
        case EVENT_ANGRY_STOMP:
            DoCastAOE(SPELL_ANGRY_STOMP, false);
            events.Repeat(20s);
            break;

        case EVENT_CORAL_GROWTH:
            DoCastSelf(SPELL_CORAL_GROWTH);
            events.Repeat(30s);
            break;

        case EVENT_OCEANS_CALL:
            for (uint8 i = 0; i < 4; i++)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->CastSpell(target, SPELL_OCEANS_CALL_MISSILE, true);
                }
            }
            events.Repeat(15s);
            break;
        }
    }

    void JustDied(Unit* unit) override
    {
        std::list<Player*> p_list;
        me->GetPlayerListInGrid(p_list, 100.0f);
        for (auto& players : p_list)
        {
            if (players->IsInSameGroupWith(players))
            {
                players->ModifyCurrency(1553, 76, true, true);
                players->ModifyCurrency(1721, 3, true, true);
            }
        }
    };
private:
    EventMap events;
};

//500517
struct npc_up_against_scene_trigger : public ScriptedAI
{
    npc_up_against_scene_trigger(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 15.0f)
        {
            if (Player* player = unit->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_UP_AGAINST_IT_HORDE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->ForceCompleteQuest(QUEST_UP_AGAINST_IT_HORDE);
                    player->GetSceneMgr().PlaySceneByPackageId(SCENE_SEEING_THE_ARMY);
                }
                else if (player->GetQuestStatus(QUEST_UP_AGAINST_IT_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->ForceCompleteQuest(QUEST_UP_AGAINST_IT_ALLIANCE);
                    player->GetSceneMgr().PlaySceneByPackageId(SCENE_SEEING_THE_ARMY);
                }
                me->ForcedDespawn(0, 15s);
            }
        }
    }
};

//150196
struct npc_thalyssra_150196 : public ScriptedAI
{
    npc_thalyssra_150196(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_UP_AGAINST_IT_HORDE)
            player->SummonCreature(155137, me->GetPosition()), me->GetGUID();
    }
};

struct npc_thalyssra_155137 : public ScriptedAI
{
    npc_thalyssra_155137(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetWalk(false);
        me->GetMotionMaster()->MoveFollow(summoner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }
};

//151848
struct npc_lorthemar_theron_151848 : public ScriptedAI
{
    npc_lorthemar_theron_151848(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player * plr, Quest const* quest) override
    {        
        if (plr->GetQuestStatus(QUEST_SCOUTING_THE_PALACE_HORDE) == QUEST_STATUS_INCOMPLETE)
        {
            plr->GetSceneMgr().PlaySceneByPackageId(SCENE_SCOUTING_THE_TIDESTONE);
            plr->KilledMonsterCredit(152613);
        }
    }
};

//152529
struct npc_spiritwalker_ussoh : public ScriptedAI
{
    npc_spiritwalker_ussoh(Creature* creature) : ScriptedAI(creature) { }

    bool GossipSelect(Player* plr, uint32 sender, uint32 action) override
    {
        return true;
    }
};

//500518
struct npc_where_the_road_leads : public ScriptedAI
{
    npc_where_the_road_leads(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 15.0f)
        {
            if (Player* player = unit->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_WHERE_THE_ROAD_LEADS_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->ForceCompleteQuest(QUEST_WHERE_THE_ROAD_LEADS_ALLIANCE);
                    player->GetSceneMgr().PlaySceneByPackageId(SCENE_MEETING_AZSHARA_ALLIANCE);
                }
                if (player->GetQuestStatus(QUEST_STAY_FAST_STAY_LOW_HORDE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->ForceCompleteQuest(QUEST_STAY_FAST_STAY_LOW_HORDE);
                    player->GetSceneMgr().PlaySceneByPackageId(SCENE_MEETING_AZSHARA_HORDE);
                }
                me->ForcedDespawn(0, 15s);
            }
        }
    }
};

//152889
struct npc_hirano : public ScriptedAI
{
    npc_hirano(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 15.0f)
            if (Player* player = unit->ToPlayer())
                if (player->GetQuestStatus(QUEST_A_BOLT_HOLE_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(152300);
    }
};

//153617
struct npc_shandris_feathermoon : public ScriptedAI
{
    npc_shandris_feathermoon(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player * plr, Quest const* quest) override
    {
        //Tempfix
        if (plr->GetQuestStatus(QUEST_SECRETS_IN_THE_RUINS) == QUEST_STATUS_INCOMPLETE) 
            plr->ForceCompleteQuest(QUEST_SECRETS_IN_THE_RUINS);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 15.0f)
            if (Player* player = unit->ToPlayer())
                if (player->GetQuestStatus(QUEST_WHAT_REMAINS_OF_ZIN_ASHARI_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->ForceCompleteQuest(QUEST_WHAT_REMAINS_OF_ZIN_ASHARI_ALLIANCE);
                    Talk(0);
                    me->GetScheduler().Schedule(6s, [player, this] (TaskContext /*context*/)
                    {
                        Talk(1);
                    });
                }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//152238
struct npc_riathia_silverstar : public ScriptedAI
{
    npc_riathia_silverstar(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 15.0f)
            if (Player* player = unit->ToPlayer())
                if (player->GetQuestStatus(QUEST_HELP_THEM_SEE_THE_TRUTH) == QUEST_STATUS_INCOMPLETE)
                    player->ForceCompleteQuest(QUEST_HELP_THEM_SEE_THE_TRUTH);
    }
};

void AddSC_nazjatar()
{
    RegisterCreatureAI(boss_wekemara);
    RegisterAreaTriggerAI(at_wakemara_bioeletric_blast);    
    RegisterCreatureAI(npc_wekemara_handler);
    RegisterCreatureAI(npc_jaina_150101);
    RegisterCreatureAI(npc_generic_soldier_fortunate_souls);
    RegisterCreatureAI(npc_hidden_treasure);
    new go_glimmering_chest();
    RegisterCreatureAI(npc_unleashed_arcano_fiend);
    RegisterCreatureAI(npc_urduu);
    RegisterCreatureAI(npc_up_against_scene_trigger);
    RegisterCreatureAI(npc_thalyssra_150196);
    RegisterCreatureAI(npc_thalyssra_155137);
    RegisterCreatureAI(npc_lorthemar_theron_151848);
    RegisterCreatureAI(npc_spiritwalker_ussoh);
    RegisterCreatureAI(npc_where_the_road_leads);
    RegisterCreatureAI(npc_hirano);
    RegisterCreatureAI(npc_shandris_feathermoon);
    RegisterCreatureAI(npc_riathia_silverstar);
}
