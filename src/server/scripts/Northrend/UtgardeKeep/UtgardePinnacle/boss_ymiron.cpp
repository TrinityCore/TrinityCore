/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "utgarde_pinnacle.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_BANE                                = 48294,
    SPELL_BANE_HIT                            = 59203, // Checked for King's Bane achievement.
    SPELL_DARK_SLASH                          = 48292,
    SPELL_FETID_ROT                           = 48291,
    SPELL_SCREAMS_OF_THE_DEAD                 = 51750,
    SPELL_SPIRIT_BURST                        = 48529,
    SPELL_SPIRIT_STRIKE                       = 48423,
    SPELL_ANCESTORS_VENGEANCE                 = 16939,

    SPELL_SUMMON_AVENGING_SPIRIT              = 48592,
    SPELL_SUMMON_SPIRIT_FOUNT                 = 48386,

    SPELL_CHANNEL_SPIRIT_TO_YMIRON            = 48316,
    SPELL_CHANNEL_YMIRON_TO_SPIRIT            = 48307,

    SPELL_SPIRIT_FOUNT                        = 48380
};

enum Texts
{
    SAY_AGGRO                               = 0,
    SAY_SLAY                                = 1,
    SAY_DEATH                               = 2,
    SAY_SUMMON_BJORN                        = 3,
    SAY_SUMMON_HALDOR                       = 4,
    SAY_SUMMON_RANULF                       = 5,
    SAY_SUMMON_TORGYN                       = 6
};

enum Events
{
    EVENT_BANE = 1,
    EVENT_FETID_ROT,
    EVENT_DARK_SLASH,
    EVENT_ANCESTORS_VENGEANCE,
    EVENT_RESUME_COMBAT,                  // Handles react state and schedules the next event after roleplay ends.
    EVENT_BJORN_SPIRIT_FOUNT,
    EVENT_HALDOR_SPIRIT_STRIKE,
    EVENT_RANULF_SPIRIT_BURST,
    EVENT_TORGYN_SUMMON_AVENGING_SPIRITS
};

enum EventGroups
{
    EVENT_GROUP_BASE_SPELLS = 1
};

enum MovePoints
{
    POINT_BOAT
};

struct ActiveBoatStruct
{
    uint32 npc;
    int32 say;
    float MoveX, MoveY, MoveZ, SpawnX, SpawnY, SpawnZ, SpawnO;
    uint32 event;
};

static ActiveBoatStruct ActiveBoat[4] =
{
    {NPC_BJORN_VISUAL,  SAY_SUMMON_BJORN,  404.379f, -335.335f, 104.756f, 413.594f, -335.408f, 107.995f, 3.157f, EVENT_BJORN_SPIRIT_FOUNT},
    {NPC_HALDOR_VISUAL, SAY_SUMMON_HALDOR, 380.813f, -335.069f, 104.756f, 369.994f, -334.771f, 107.995f, 6.232f, EVENT_HALDOR_SPIRIT_STRIKE},
    {NPC_RANULF_VISUAL, SAY_SUMMON_RANULF, 381.546f, -314.362f, 104.756f, 370.841f, -314.426f, 107.995f, 6.232f, EVENT_RANULF_SPIRIT_BURST},
    {NPC_TORGYN_VISUAL, SAY_SUMMON_TORGYN, 404.310f, -314.761f, 104.756f, 413.992f, -314.703f, 107.995f, 3.157f, EVENT_TORGYN_SUMMON_AVENGING_SPIRITS}
};

enum Misc
{
    DATA_KINGS_BANE                 = 2157
};

class boss_ymiron : public CreatureScript
{
public:
    boss_ymiron() : CreatureScript("boss_ymiron") { }

    struct boss_ymironAI : public BossAI
    {
        boss_ymironAI(Creature* creature) : BossAI(creature, DATA_KING_YMIRON)
        {
            Initialize();
            // This ensures a random sequence of ancestors. Not sure if the order should change on reset or not, reason why this is left out of Initialize().
            for (int i = 0; i < 4; ++i)
                ActiveOrder[i] = i;
            for (int i = 0; i < 3; ++i)
            {
                int r = i + (rand32() % (4 - i));
                int temp = ActiveOrder[i];
                ActiveOrder[i] = ActiveOrder[r];
                ActiveOrder[r] = temp;
            }
        }

        void Initialize()
        {
            kingsBane = true;
            ActivedNumber = 0;
            HealthAmountModifier = 1;
            HealthAmountMultipler = DUNGEON_MODE(20, 25);
            ActiveAncestorGUID.Clear();
            SpiritFountGUID.Clear();
        }

        void Reset() override
        {
            _Reset();
            Initialize();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_BANE, urand(18000, 23000), EVENT_GROUP_BASE_SPELLS);
            events.ScheduleEvent(EVENT_FETID_ROT, urand(8000, 13000), EVENT_GROUP_BASE_SPELLS);
            events.ScheduleEvent(EVENT_DARK_SLASH, urand(28000, 33000), EVENT_GROUP_BASE_SPELLS);
            events.ScheduleEvent(EVENT_ANCESTORS_VENGEANCE, DUNGEON_MODE(60000, 45000), EVENT_GROUP_BASE_SPELLS);
        }

        void SpellHitTarget(Unit* who, SpellInfo const* spell) override
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_BANE_HIT)
                kingsBane = false;
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_KINGS_BANE)
                return kingsBane ? 1 : 0;

            return 0;
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == POINT_BOAT) // Check might not be needed.
            {
                Talk(ActiveBoat[ActiveOrder[ActivedNumber]].say);
                if (Creature* ancestor = me->SummonCreature(ActiveBoat[ActiveOrder[ActivedNumber]].npc, ActiveBoat[ActiveOrder[ActivedNumber]].SpawnX, ActiveBoat[ActiveOrder[ActivedNumber]].SpawnY, ActiveBoat[ActiveOrder[ActivedNumber]].SpawnZ, ActiveBoat[ActiveOrder[ActivedNumber]].SpawnO, TEMPSUMMON_CORPSE_DESPAWN, 0))
                {
                    DoCast(ancestor, SPELL_CHANNEL_YMIRON_TO_SPIRIT);
                    ancestor->CastSpell(me, SPELL_CHANNEL_SPIRIT_TO_YMIRON, true);
                    ancestor->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    ancestor->SetDisableGravity(true);
                    ActiveAncestorGUID = ancestor->GetGUID();
                }
                events.ScheduleEvent(EVENT_RESUME_COMBAT, 5000);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_SPIRIT_FOUNT:
                    summon->CastSpell(summon, SPELL_SPIRIT_FOUNT, true);
                    summon->SetDisplayId(11686);
                    SpiritFountGUID = summon->GetGUID();
                    break;
                case NPC_AVENGING_SPIRIT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        summon->AddThreat(target, 0.0f);
                        summon->AI()->AttackStart(target);
                    }
                    break;
                default:
                    break;
            }

            summons.Summon(summon);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(100 - HealthAmountMultipler * HealthAmountModifier, damage) && !(damage >= me->GetHealth()))
            {
                uint8 Order = HealthAmountModifier - 1;
                ++HealthAmountModifier;

                me->InterruptNonMeleeSpells(true);
                DoCast(me, SPELL_SCREAMS_OF_THE_DEAD);

                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(POINT_BOAT, ActiveBoat[ActiveOrder[Order]].MoveX, ActiveBoat[ActiveOrder[Order]].MoveY, ActiveBoat[ActiveOrder[Order]].MoveZ);

                DespawnBoatGhosts(ActiveAncestorGUID);
                DespawnBoatGhosts(SpiritFountGUID);

                events.CancelEvent(ActiveBoat[ActiveOrder[ActivedNumber]].event); // Cancels the event started on the previous transition.
                events.DelayEvents(10000, EVENT_GROUP_BASE_SPELLS);

                ActivedNumber = Order;
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_BANE:
                    DoCast(SPELL_BANE);
                    events.ScheduleEvent(EVENT_BANE, urand(20000, 25000));
                    break;
                case EVENT_FETID_ROT:
                    DoCastVictim(SPELL_FETID_ROT);
                    events.ScheduleEvent(EVENT_FETID_ROT, urand(10000, 15000));
                    break;
                case EVENT_DARK_SLASH:
                    DoCastVictim(SPELL_DARK_SLASH);
                    events.ScheduleEvent(EVENT_DARK_SLASH, urand(30000, 35000));
                    break;
                case EVENT_ANCESTORS_VENGEANCE:
                    DoCast(me, SPELL_ANCESTORS_VENGEANCE);
                    events.ScheduleEvent(EVENT_ANCESTORS_VENGEANCE, DUNGEON_MODE(urand(60000, 65000), urand(45000, 50000)));
                    break;
                case EVENT_RESUME_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(ActiveBoat[ActiveOrder[ActivedNumber]].event, 5000);
                    break;
                case EVENT_BJORN_SPIRIT_FOUNT:
                    DoCast(SPELL_SUMMON_SPIRIT_FOUNT);
                    break;
                case EVENT_HALDOR_SPIRIT_STRIKE:
                    DoCastVictim(SPELL_SPIRIT_STRIKE);
                    events.ScheduleEvent(EVENT_HALDOR_SPIRIT_STRIKE, 5000);
                    break;
                case EVENT_RANULF_SPIRIT_BURST:
                    DoCast(me, SPELL_SPIRIT_BURST);
                    events.ScheduleEvent(EVENT_RANULF_SPIRIT_BURST, 10000);
                    break;
                case EVENT_TORGYN_SUMMON_AVENGING_SPIRITS:
                    for (uint8 i = 0; i < 4; ++i)
                        DoCast(SPELL_SUMMON_AVENGING_SPIRIT);
                    events.ScheduleEvent(EVENT_TORGYN_SUMMON_AVENGING_SPIRITS, 15000);
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DespawnBoatGhosts(ObjectGuid& CreatureGUID)
        {
            // @todo: fire visual after ancestor despawns.
            if (CreatureGUID)
                if (Creature* temp = ObjectAccessor::GetCreature(*me, CreatureGUID))
                    temp->DisappearAndDie();

            CreatureGUID.Clear();
        }

    private:
        bool kingsBane; // Achievement King's Bane
        uint8 ActiveOrder[4];
        uint8 ActivedNumber;
        uint32 HealthAmountModifier;
        uint32 HealthAmountMultipler;
        ObjectGuid ActiveAncestorGUID;
        ObjectGuid SpiritFountGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_ymironAI>(creature);
    }
};

class achievement_kings_bane : public AchievementCriteriaScript
{
    public:
        achievement_kings_bane() : AchievementCriteriaScript("achievement_kings_bane") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Ymiron = target->ToCreature())
                if (Ymiron->AI()->GetData(DATA_KINGS_BANE))
                    return true;

            return false;
        }
};

void AddSC_boss_ymiron()
{
    new boss_ymiron();
    new achievement_kings_bane();
}
