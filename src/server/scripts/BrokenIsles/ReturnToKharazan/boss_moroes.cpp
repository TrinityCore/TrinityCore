#include "new_karazhan.h"
#include "CreatureGroups.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_GHASTLY_PURGE = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    //Moroes
    SPELL_VANISH_FILTER = 227737,
    SPELL_VANISH = 227736,
    SPELL_GARROTE = 227742,
    SPELL_CONVERS_COAT = 229848,
    SPELL_COAT_CHECK = 227851,
    SPELL_COAT_CHECK_RESIST = 227832,
    SPELL_GHASTLY_PURGE = 227872,

    SPELL_SUMMON_KEYS = 233989,

    ///Trash
    SPELL_DINNER_PARTY = 233669,
    SPELL_DINNER_PARTY_AT = 233671,

    //Baroness Dorothea Millstipe
    SPELL_ARCANE_BLAST = 227575,
    SPELL_MANA_DRAIN = 227545,

    //Lady Catriona Von'Indi
    SPELL_SMITE = 227542,
    SPELL_HEALING_STREAM = 227578,

    //Baron Rafe Dreuger
    SPELL_IRON_WHIRLWIND = 227637,

    //Lady Keira Berrybuck
    SPELL_EMPOWERED_ARMS = 227616,

    //Lord Robin Daris
    SPELL_WHIRLING_EDGE = 227463,
    SPELL_WHIRLING_EDGE_AT = 227472,

    //Lord Crispin Ference
    SPELL_WILL_BREAKER = 227672,

    ///Event scene after death Moroes

    SPELL_VISION = 229485,

    //Medivh
    SPELL_UNCONTROLLABLE_ENERGY = 229571,
    SPELL_UNLEASHED_POWER = 232697,
    SPELL_KNOCKBACK_SELF = 66033,

    //Nielas Aran
    SPELL_PLAY_SCENE = 232486,
    SPELL_FEIGN_DEATH = 145363,
};

enum eEvents
{
    EVENT_VANISH = 1,
    EVENT_COAT_CHECK = 2,
};

//SMSG_SET_AI_ANIM_KIT
enum eAnimKit
{
    //Medivh
    ANIM_MEDIVH_1 = 5874,
    ANIM_MEDIVH_2 = 12168,
    ANIM_MEDIVH_3 = 9569,

    //Nielas Aran
    ANIM_NIELAS_1 = 12310
};

enum MedivhEvents
{
    EVENT_1 = 1,
    EVENT_2, 
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
};

//114312
class boss_rtk_moroes : public CreatureScript
{
public:
    boss_rtk_moroes() : CreatureScript("boss_rtk_moroes") {}

    struct boss_rtk_moroesAI : public BossAI
    {
        boss_rtk_moroesAI(Creature* creature) : BossAI(creature, DATA_MOROES)
        {
            std::vector<uint32> helpersList;
            helpersList.push_back(NPC_BARONESS_DOROTHEA);
            helpersList.push_back(NPC_LADY_CATRIONA);
            helpersList.push_back(NPC_BARON_RAFE);
            helpersList.push_back(NPC_LADY_KEIRA);
            helpersList.push_back(NPC_LORD_ROBIN);
            helpersList.push_back(NPC_LORD_CRISPIN);
            Trinity::Containers::RandomResize(helpersList, 4);
        }

        std::vector<uint32> helpersList;
        //FormationInfo* group_member;
        uint8 healthPct;

        void Reset() override
        {
            _Reset();
            healthPct = 51;

            if (!helpersList.empty())
            {
                for (uint8 i = 0; i < 4; i++)
                    me->SummonCreature(helpersList[i], helperPos[i]);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
            //41:14
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            events.RescheduleEvent(EVENT_VANISH, 7000); //41:21, 41:42 42:02
            events.RescheduleEvent(EVENT_COAT_CHECK, 30000); //41:44 42:20
        }

        void EnterEvadeMode(EvadeReason w) 
        {
            me->NearTeleportTo(me->GetHomePosition());
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            Talk(SAY_DEATH + 1);
            _JustDied();

            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC)
                DoCast(me, SPELL_SUMMON_KEYS, true);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_VANISH)
                DoCast(target, SPELL_GARROTE, true);

            if (spell->Id == SPELL_COAT_CHECK)
                DoCast(target, SPELL_COAT_CHECK_RESIST, true);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->HealthBelowPct(healthPct)) //51%
            {
                healthPct = 0;
                Talk(SAY_GHASTLY_PURGE);
                DoCast(me, SPELL_GHASTLY_PURGE, true);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VANISH:
                    DoCast(me, SPELL_VANISH_FILTER, true);
                    events.RescheduleEvent(EVENT_VANISH, 19000);
                    break;
                case EVENT_COAT_CHECK:
                    DoCast(me, SPELL_CONVERS_COAT, true);
                    DoCastVictim(SPELL_COAT_CHECK);
                    events.RescheduleEvent(EVENT_COAT_CHECK, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rtk_moroesAI(creature);
    }
};

//114316, 114317, 114318, 114319, 114320, 114321
class npc_moroes_trash_generic : public CreatureScript
{
public:
    npc_moroes_trash_generic() : CreatureScript("npc_moroes_trash_generic") {}

    struct npc_moroes_trash_genericAI : public ScriptedAI
    {
        npc_moroes_trash_genericAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override
        {
            events.Reset();
            DoCast(me, SPELL_DINNER_PARTY, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
            //41:14
        {
            DoCast(me, SPELL_DINNER_PARTY_AT, true);

            switch (me->GetEntry())
            {
            case NPC_BARONESS_DOROTHEA:
                events.RescheduleEvent(EVENT_1, 1000); //41:15
                events.RescheduleEvent(EVENT_2, 9000); //41:23
                break;
            case NPC_LADY_CATRIONA:
                events.RescheduleEvent(EVENT_3, 1000);
                events.RescheduleEvent(EVENT_4, 20000);
                break;
            case NPC_BARON_RAFE:
                events.RescheduleEvent(EVENT_5, 5000); //41:19
                break;
            case NPC_LADY_KEIRA:
                events.RescheduleEvent(EVENT_6, 10000);
                break;
            case NPC_LORD_ROBIN:
                events.RescheduleEvent(EVENT_7, 1000);
                break;
            case NPC_LORD_CRISPIN:
                events.RescheduleEvent(EVENT_8, 11000); //41:25
                break;
            }
            DoZoneInCombat(me, 100.0f);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_ARCANE_BLAST);
                    events.RescheduleEvent(EVENT_1, 4000);
                    break;
                case EVENT_2:
                {
                    std::list<Player*> playersList;
                    GetPlayerListInGrid(playersList, me, 80.0f);
                    if (!playersList.empty())
                    {
                        Trinity::Containers::RandomResize(playersList, 1);
                        for (auto const& player : playersList)
                            if (player->GetPower(POWER_MANA) > 0)
                                DoCast(player, SPELL_MANA_DRAIN);
                    }
                    events.RescheduleEvent(EVENT_2, 15000);
                    break;
                }
                case EVENT_3:
                    DoCastVictim(SPELL_SMITE);
                    events.RescheduleEvent(EVENT_3, 4000);
                    break;
                case EVENT_4:
                    DoCast(SPELL_HEALING_STREAM);
                    events.RescheduleEvent(EVENT_4, 30000);
                    break;
                case EVENT_5:
                    DoCast(me, SPELL_IRON_WHIRLWIND, true);
                    events.RescheduleEvent(EVENT_5, 10000);
                    break;
                case EVENT_6:
                    DoCast(SPELL_EMPOWERED_ARMS);
                    events.RescheduleEvent(EVENT_6, 12000);
                    break;
                case EVENT_7:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        if (Unit* owner = me->GetOwner())
                            me->CastSpell(target, SPELL_WHIRLING_EDGE, false, nullptr, nullptr, owner->GetGUID());
                    }
                    events.RescheduleEvent(EVENT_7, 18000);
                    break;
                case EVENT_8:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        me->SetFacingToObject(target);
                        DoCast(SPELL_WILL_BREAKER);
                    }
                    events.RescheduleEvent(EVENT_8, 18000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_moroes_trash_genericAI(creature);
    }
};

//114327
class npc_moroes_whirling_edge : public CreatureScript
{
public:
    npc_moroes_whirling_edge() : CreatureScript("npc_moroes_whirling_edge") {}

    struct npc_moroes_whirling_edgeAI : public Scripted_NoMovementAI
    {
        npc_moroes_whirling_edgeAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_WHIRLING_EDGE_AT, true);
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_moroes_whirling_edgeAI(creature);
    }
};

//115426, 115427
class npc_moroes_after_scene : public CreatureScript
{
public:
    npc_moroes_after_scene() : CreatureScript("npc_moroes_after_scene") {}

    struct npc_moroes_after_sceneAI : public ScriptedAI
    {
        npc_moroes_after_sceneAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetWalk(true);
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            DoCast(me, SPELL_VISION, true);

            if (me->GetEntry() == NPC_NIELAS_ARAN)
                events.RescheduleEvent(EVENT_1, 500);
            else
                events.RescheduleEvent(EVENT_2, 500);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_UNLEASHED_POWER && target->GetEntry() == NPC_NIELAS_ARAN)
            {
                me->RemoveAurasDueToSpell(SPELL_UNCONTROLLABLE_ENERGY);
                me->RemoveAurasDueToSpell(SPELL_UNLEASHED_POWER);
                target->CastSpell(target, SPELL_FEIGN_DEATH, true);
                target->SetUnitFlags2(UNIT_FLAG2_FEIGN_DEATH);
                DoCast(me, SPELL_KNOCKBACK_SELF, true);
                events.RescheduleEvent(EVENT_4, 3000);
            }
            if (spell->Id == SPELL_PLAY_SCENE)
                target->CastSpell(target, 232480, true);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1)
                events.RescheduleEvent(EVENT_6, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1: //42:56
                    DoCast(me, SPELL_PLAY_SCENE, true);
                    DelayTalk(me, 9, 1, nullptr);
                    break;
                case EVENT_2: //42:56
                    DoCast(me, SPELL_UNCONTROLLABLE_ENERGY, true);
                    DelayTalk(me, 13, 1, nullptr);
                    events.RescheduleEvent(EVENT_3, 17000);
                    break;
                case EVENT_3:
                    DoCast(SPELL_UNLEASHED_POWER);
                    break;
                case EVENT_4:
                    DelayTalk(me, 1, 1, nullptr);
                    events.RescheduleEvent(EVENT_5, 3500);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(1, -10983.81f, -1882.08f, 81.72f);
                    break;
                case EVENT_6:
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_moroes_after_sceneAI(creature);
    }
};

void AddSC_boss_moroes_new()
{
    new boss_rtk_moroes();
    new npc_moroes_trash_generic();
    new npc_moroes_whirling_edge();
    new npc_moroes_after_scene();
}
