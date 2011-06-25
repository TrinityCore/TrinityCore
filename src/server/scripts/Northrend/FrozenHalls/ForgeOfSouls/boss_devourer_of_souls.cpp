/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "forge_of_souls.h"

/*
 * TODO:
 * - Fix model id during unleash soul -> seems DB issue 36503 is missing (likewise 36504 is also missing).
 * - Fix outro npc movement
 */

enum Yells
{
    SAY_FACE_ANGER_AGGRO                          = -1632010,
    SAY_FACE_DESIRE_AGGRO                         = -1632011,
    SAY_FACE_ANGER_SLAY_1                         = -1632012,
    SAY_FACE_SORROW_SLAY_1                        = -1632013,
    SAY_FACE_DESIRE_SLAY_1                        = -1632014,
    SAY_FACE_ANGER_SLAY_2                         = -1632015,
    SAY_FACE_SORROW_SLAY_2                        = -1632016,
    SAY_FACE_DESIRE_SLAY_2                        = -1632017,
    SAY_FACE_SORROW_DEATH                         = -1632019,
    SAY_FACE_DESIRE_DEATH                         = -1632020,
    EMOTE_MIRRORED_SOUL                           = -1632021,
    EMOTE_UNLEASH_SOUL                            = -1632022,
    SAY_FACE_ANGER_UNLEASH_SOUL                   = -1632023,
    SAY_FACE_SORROW_UNLEASH_SOUL                  = -1632024,
    SAY_FACE_DESIRE_UNLEASH_SOUL                  = -1632025,
    EMOTE_WAILING_SOUL                            = -1632026,
    SAY_FACE_ANGER_WAILING_SOUL                   = -1632027,
    SAY_FACE_DESIRE_WAILING_SOUL                  = -1632028,

    SAY_JAINA_OUTRO                               = -1632029,
    SAY_SYLVANAS_OUTRO                            = -1632030,
};

enum Spells
{
    SPELL_PHANTOM_BLAST                           = 68982,
    H_SPELL_PHANTOM_BLAST                         = 70322,
    SPELL_MIRRORED_SOUL                           = 69051,
    SPELL_WELL_OF_SOULS                           = 68820,
    SPELL_UNLEASHED_SOULS                         = 68939,
    SPELL_WAILING_SOULS_STARTING                  = 68912,  // Initial spell cast at begining of wailing souls phase
    SPELL_WAILING_SOULS_BEAM                      = 68875,  // the beam visual
    SPELL_WAILING_SOULS                           = 68873,  // the actual spell
    H_SPELL_WAILING_SOULS                         = 70324,
//    68871, 68873, 68875, 68876, 68899, 68912, 70324,
// 68899 trigger 68871
};

enum Events
{
    EVENT_PHANTOM_BLAST         = 1,
    EVENT_MIRRORED_SOUL         = 2,
    EVENT_WELL_OF_SOULS         = 3,
    EVENT_UNLEASHED_SOULS       = 4,
    EVENT_WAILING_SOULS         = 5,
    EVENT_WAILING_SOULS_TICK    = 6,
    EVENT_FACE_ANGER            = 7,
};

enum eEnum
{
    DISPLAY_ANGER               = 30148,
    DISPLAY_SORROW              = 30149,
    DISPLAY_DESIRE              = 30150,
};

struct outroPosition
{
    uint32 entry[2];
    Position movePosition;
} outroPositions[] =
{
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5590.47f, 2427.79f, 705.935f, 0.802851f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5593.59f, 2428.34f, 705.935f, 0.977384f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5600.81f, 2429.31f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5600.81f, 2421.12f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5601.43f, 2426.53f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5601.55f, 2418.36f, 705.935f, 1.15192f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5598, 2429.14f, 705.935f, 1.0472f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5594.04f, 2424.87f, 705.935f, 1.15192f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5597.89f, 2421.54f, 705.935f, 0.610865f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5598.57f, 2434.62f, 705.935f, 1.13446f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5585.46f, 2417.99f, 705.935f, 1.06465f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5605.81f, 2428.42f, 705.935f, 0.820305f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5591.61f, 2412.66f, 705.935f, 0.925025f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5593.9f, 2410.64f, 705.935f, 0.872665f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5586.76f, 2416.73f, 705.935f, 0.942478f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5592.23f, 2419.14f, 705.935f, 0.855211f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5594.61f, 2416.87f, 705.935f, 0.907571f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5589.77f, 2421.03f, 705.935f, 0.855211f } },

    { { NPC_KORELN, NPC_LORALEN }, { 5602.58f, 2435.95f, 705.935f, 0.959931f } },
    { { NPC_ELANDRA, NPC_KALIRA }, { 5606.13f, 2433.16f, 705.935f, 0.785398f } },
    { { NPC_JAINA_PART2, NPC_SYLVANAS_PART2 }, { 5606.12f, 2436.6f, 705.935f, 0.890118f } },

    { { 0, 0 }, { 0.0f, 0.0f, 0.0f, 0.0f } }
};

#define DATA_THREE_FACED        1

class boss_devourer_of_souls : public CreatureScript
{
    public:
        boss_devourer_of_souls() : CreatureScript("boss_devourer_of_souls") { }

        struct boss_devourer_of_soulsAI : public BossAI
        {
            boss_devourer_of_soulsAI(Creature *creature) : BossAI(creature, DATA_DEVOURER_EVENT)
            {
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(FoSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetDisplayId(DISPLAY_ANGER);
                me->SetReactState(REACT_AGGRESSIVE);

                events.Reset();
                summons.DespawnAll();

                threeFaced = true;
                mirroredSoulTarget = 0;

                instance->SetData(DATA_DEVOURER_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_FACE_ANGER_AGGRO, SAY_FACE_DESIRE_AGGRO), me);

                events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
                events.ScheduleEvent(EVENT_MIRRORED_SOUL, 8000);
                events.ScheduleEvent(EVENT_WELL_OF_SOULS, 30000);
                events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 20000);
                events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000, 70000));

                instance->SetData(DATA_DEVOURER_EVENT, IN_PROGRESS);
            }

            void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
            {
                if (mirroredSoulTarget && me->HasAura(SPELL_MIRRORED_SOUL))
                {
                    if (Player* player = Unit::GetPlayer(*me, mirroredSoulTarget))
                    {
                        if (player->GetAura(SPELL_MIRRORED_SOUL))
                        {
                            int32 mirrorDamage = (uiDamage * 45)/100;
                            me->CastCustomSpell(player, 69034, &mirrorDamage, 0, 0, true);
                        }
                        else
                            mirroredSoulTarget = 0;
                    }
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                int32 textId = 0;
                switch (me->GetDisplayId())
                {
                    case DISPLAY_ANGER:
                        textId = RAND(SAY_FACE_ANGER_SLAY_1, SAY_FACE_ANGER_SLAY_2);
                        break;
                    case DISPLAY_SORROW:
                        textId = RAND(SAY_FACE_SORROW_SLAY_1, SAY_FACE_SORROW_SLAY_2);
                        break;
                    case DISPLAY_DESIRE:
                        textId = RAND(SAY_FACE_DESIRE_SLAY_1, SAY_FACE_DESIRE_SLAY_2);
                        break;
                    default:
                        break;
                }

                if (textId)
                    DoScriptText(textId, me);
            }

            void JustDied(Unit* /*killer*/)
            {
                summons.DespawnAll();

                Position spawnPoint = {5618.139f, 2451.873f, 705.854f, 0};

                DoScriptText(RAND(SAY_FACE_SORROW_DEATH, SAY_FACE_DESIRE_DEATH), me);

                instance->SetData(DATA_DEVOURER_EVENT, DONE);

                int32 entryIndex;
                if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    entryIndex = 0;
                else
                    entryIndex = 1;

                for (int8 i = 0; outroPositions[i].entry[entryIndex] != 0; ++i)
                {
                    if (Creature *summon = me->SummonCreature(outroPositions[i].entry[entryIndex], spawnPoint, TEMPSUMMON_DEAD_DESPAWN))
                    {
                        summon->GetMotionMaster()->MovePoint(0, outroPositions[i].movePosition);
                        if (summon->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_OUTRO, summon);
                        else if (summon->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANAS_OUTRO, summon);
                    }
                }
            }

            void SpellHitTarget(Unit* /*target*/, const SpellEntry *spell)
            {
                if (spell->Id == H_SPELL_PHANTOM_BLAST)
                    threeFaced = false;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_THREE_FACED)
                    return threeFaced;

                return 0;
            }

            void UpdateAI(const uint32 diff)
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_PHANTOM_BLAST:
                            DoCastVictim(SPELL_PHANTOM_BLAST);
                            events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
                            break;
                        case EVENT_MIRRORED_SOUL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                mirroredSoulTarget = target->GetGUID();
                                DoCast(target, SPELL_MIRRORED_SOUL);
                                DoScriptText(EMOTE_MIRRORED_SOUL, me);
                            }
                            events.ScheduleEvent(EVENT_MIRRORED_SOUL, urand(15000, 30000));
                            break;
                        case EVENT_WELL_OF_SOULS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_WELL_OF_SOULS);
                            events.ScheduleEvent(EVENT_WELL_OF_SOULS, 20000);
                            break;
                        case EVENT_UNLEASHED_SOULS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_UNLEASHED_SOULS);
                            me->SetDisplayId(DISPLAY_SORROW);
                            DoScriptText(RAND(SAY_FACE_ANGER_UNLEASH_SOUL, SAY_FACE_SORROW_UNLEASH_SOUL, SAY_FACE_DESIRE_UNLEASH_SOUL), me);
                            DoScriptText(EMOTE_UNLEASH_SOUL, me);
                            events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 30000);
                            events.ScheduleEvent(EVENT_FACE_ANGER, 5000);
                            break;
                        case EVENT_FACE_ANGER:
                            me->SetDisplayId(DISPLAY_ANGER);
                            break;

                        case EVENT_WAILING_SOULS:
                            me->SetDisplayId(DISPLAY_DESIRE);
                            DoScriptText(RAND(SAY_FACE_ANGER_WAILING_SOUL, SAY_FACE_DESIRE_WAILING_SOUL), me);
                            DoScriptText(EMOTE_WAILING_SOUL, me);
                            DoCast(me, SPELL_WAILING_SOULS_STARTING);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                me->SetOrientation(me->GetAngle(target));
                                DoCast(me, SPELL_WAILING_SOULS_BEAM);
                            }

                            beamAngle = me->GetOrientation();

                            beamAngleDiff = M_PI/30.0f; // PI/2 in 15 sec = PI/30 per tick
                            if (RAND(true, false))
                                beamAngleDiff = -beamAngleDiff;

                            me->InterruptNonMeleeSpells(false);
                            me->SetReactState(REACT_PASSIVE);

                            //Remove any target
                            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);

                            me->GetMotionMaster()->Clear();
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                            wailingSoulTick = 15;
                            events.DelayEvents(18000); // no other events during wailing souls
                            events.ScheduleEvent(EVENT_WAILING_SOULS_TICK, 3000); // first one after 3 secs.
                            break;

                        case EVENT_WAILING_SOULS_TICK:
                            beamAngle += beamAngleDiff;
                            me->SetOrientation(beamAngle);
                            me->StopMoving();

                            DoCast(me, SPELL_WAILING_SOULS);

                            if (--wailingSoulTick)
                                events.ScheduleEvent(EVENT_WAILING_SOULS_TICK, 1000);
                            else
                            {
                                me->SetReactState(REACT_AGGRESSIVE);
                                me->SetDisplayId(DISPLAY_ANGER);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                me->GetMotionMaster()->MoveChase(me->getVictim());
                                events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000, 70000));
                            }
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool threeFaced;

            // wailing soul event
            float beamAngle;
            float beamAngleDiff;
            int8 wailingSoulTick;

            uint64 mirroredSoulTarget;
        };

        CreatureAI *GetAI(Creature* creature) const
        {
            return new boss_devourer_of_soulsAI(creature);
        }
};

class achievement_three_faced : public AchievementCriteriaScript
{
    public:
        achievement_three_faced() : AchievementCriteriaScript("achievement_three_faced")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (Creature* Devourer = target->ToCreature())
                if (Devourer->AI()->GetData(DATA_THREE_FACED))
                    return true;

            return false;
        }
};

void AddSC_boss_devourer_of_souls()
{
    new boss_devourer_of_souls();
    new achievement_three_faced();
}
