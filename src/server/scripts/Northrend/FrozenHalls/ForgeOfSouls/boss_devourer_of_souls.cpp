/* Copyright (C) 2008 - 2010 TrinityCore <https://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptPCH.h"
#include "forge_of_souls.h"

/*
 * TODO:
 * - Fix model id during unleash soul -> seems DB issue 36503 is missing (likewise 36504 is also missing).
 * - Fix outro npc movement
 */

#define PI                                          3.1415f

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
    SPELL_WELL_OF_SOULS_VIS                       = 68854,
    SPELL_UNLEASHED_SOULS                         = 68939,
    SPELL_WAILING_SOULS_STARTING                  = 68912,  // Initial spell cast at begining of wailing souls phase
    SPELL_WAILING_SOULS_BEAM                      = 68875,  // the beam visual
    SPELL_WAILING_SOULS                           = 68873,  // the actual spell
    H_SPELL_WAILING_SOULS                         = 70324,
//    68871,68873,68875,68876,68899,68912,70324,
// 68899 trigger 68871
};

enum Events
{
    EVENT_NONE,
    EVENT_PHANTOM_BLAST,
    EVENT_MIRRORED_SOUL,
    EVENT_WELL_OF_SOULS,
    EVENT_UNLEASHED_SOULS,
    EVENT_WAILING_SOULS,
    EVENT_WAILING_SOULS_TICK,
    EVENT_FACE_ANGER,
};

enum eEnum
{
    ACHIEV_THREE_FACED                            = 4523,
    DISPLAY_ANGER                                 = 30148,
    DISPLAY_SORROW                                = 30149,
    DISPLAY_DESIRE                                = 30150,
};

struct
{
    uint32 entry[2];
    Position movePosition;
} outroPositions[] =
{
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5590.47, 2427.79, 705.935, 0.802851 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5593.59, 2428.34, 705.935, 0.977384 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5600.81, 2429.31, 705.935, 0.890118 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5600.81, 2421.12, 705.935, 0.890118 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5601.43, 2426.53, 705.935, 0.890118 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5601.55, 2418.36, 705.935, 1.15192 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5598, 2429.14, 705.935, 1.0472 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5594.04, 2424.87, 705.935, 1.15192 } },
    { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE, { 5597.89, 2421.54, 705.935, 0.610865 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5598.57, 2434.62, 705.935, 1.13446 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5585.46, 2417.99, 705.935, 1.06465 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5605.81, 2428.42, 705.935, 0.820305 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5591.61, 2412.66, 705.935, 0.925025 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5593.9, 2410.64, 705.935, 0.872665 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE, { 5586.76, 2416.73, 705.935, 0.942478 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE, { 5592.23, 2419.14, 705.935, 0.855211 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE, { 5594.61, 2416.87, 705.935, 0.907571 } },
    { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE, { 5589.77, 2421.03, 705.935, 0.855211 } },

    { NPC_KORELN, NPC_LORALEN, { 5602.58, 2435.95, 705.935, 0.959931 } },
    { NPC_ELANDRA, NPC_KALIRA, { 5606.13, 2433.16, 705.935, 0.785398 } },
    { NPC_JAINA_PART2, NPC_SYLVANAS_PART2, { 5606.12, 2436.6, 705.935, 0.890118 } },

    { 0, 0, { 0, 0, 0, 0 } }
};

struct boss_devourer_of_soulsAI : public ScriptedAI
{
    boss_devourer_of_soulsAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    bool bThreeFaceAchievement;

    ScriptedInstance* pInstance;
    EventMap events;

    // wailing soul event
    float beamAngle;
    float beamAngleDiff;
    int8 wailingSoulTick;

    uint64 uiMirroredSoulTarget;

    void Reset()
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        me->SetDisplayId(DISPLAY_ANGER);
        me->SetReactState(REACT_AGGRESSIVE);

        events.Reset();

        bThreeFaceAchievement = true;
        uiMirroredSoulTarget = 0;

        if (pInstance)
            pInstance->SetData(DATA_DEVOURER_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_DEVOURER_EVENT, IN_PROGRESS);

        DoScriptText(RAND(SAY_FACE_ANGER_AGGRO,SAY_FACE_DESIRE_AGGRO), me);

        events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
        events.ScheduleEvent(EVENT_MIRRORED_SOUL, 8000);
        events.ScheduleEvent(EVENT_WELL_OF_SOULS, 30000);
        events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 20000);
        events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000,70000));
    }

    void DamageTaken(Unit * /*pDoneBy*/, uint32 &uiDamage)
    {
        if (uiMirroredSoulTarget && me->HasAura(SPELL_MIRRORED_SOUL))
        {
            if (Player *pPlayer = Unit::GetPlayer(uiMirroredSoulTarget))
            {
                if (Aura *pAura = pPlayer->GetAura(SPELL_MIRRORED_SOUL))
                {
                    int32 mirrorDamage = (uiDamage * 45)/100;
                    me->CastCustomSpell(pPlayer, 69034, &mirrorDamage, 0, 0, true);
//                    me->DealDamage(pPlayer, (uiDamage * 45)/100, 0, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_SHADOW);
                }
                else
                    uiMirroredSoulTarget = 0;
            }
        }
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_FACE_ANGER_SLAY_1,SAY_FACE_SORROW_SLAY_1,SAY_FACE_DESIRE_SLAY_1,
            SAY_FACE_ANGER_SLAY_2,SAY_FACE_SORROW_SLAY_2,SAY_FACE_DESIRE_SLAY_2), me);
    }

    void JustDied(Unit* /*killer*/)
    {
        Position spawnPoint = { 5618.139, 2451.873, 705.854 };

        DoScriptText(RAND(SAY_FACE_SORROW_DEATH,SAY_FACE_DESIRE_DEATH), me);

        if (pInstance)
        {
            pInstance->SetData(DATA_DEVOURER_EVENT, DONE);

            if (bThreeFaceAchievement && IsHeroic())
                pInstance->DoCompleteAchievement(ACHIEV_THREE_FACED);

            int32 entryIndex;
            if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                entryIndex = 0;
            else
                entryIndex = 1;

            for (int8 i = 0; outroPositions[i].entry[entryIndex] != 0; ++i)
            {
                if (Creature *pSummon = me->SummonCreature(outroPositions[i].entry[entryIndex], spawnPoint, TEMPSUMMON_DEAD_DESPAWN))
                {
                    pSummon->GetMotionMaster()->MovePoint(0, outroPositions[i].movePosition);

                    if (pSummon->GetEntry() == NPC_JAINA_PART2)
                        DoScriptText(SAY_JAINA_OUTRO, pSummon);
                    else if (pSummon->GetEntry() == NPC_SYLVANAS_PART2)
                        DoScriptText(SAY_SYLVANAS_OUTRO, pSummon);
                }
            }
        }
    }

    void SpellHitTarget(Unit* /*pTarget*/, const SpellEntry *pSpell)
    {
        if (pSpell->Id == H_SPELL_PHANTOM_BLAST)
            bThreeFaceAchievement = false;
    }

    void UpdateAI(const uint32 diff)
    {
        // Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_PHANTOM_BLAST:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_TOPAGGRO, 0))
                        DoCast(pTarget, SPELL_PHANTOM_BLAST);
                    events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
                    break;
                case EVENT_MIRRORED_SOUL:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        uiMirroredSoulTarget = pTarget->GetGUID();
                        DoCast(pTarget, SPELL_MIRRORED_SOUL);
                        DoScriptText(EMOTE_MIRRORED_SOUL, me);
                    }
                    events.ScheduleEvent(EVENT_MIRRORED_SOUL, urand(15000,30000));
                    break;
                case EVENT_WELL_OF_SOULS:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_WELL_OF_SOULS);
                    events.ScheduleEvent(EVENT_WELL_OF_SOULS, 20000);
                    break;
                case EVENT_UNLEASHED_SOULS:
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_UNLEASHED_SOULS);
                    me->SetDisplayId(DISPLAY_SORROW);
                    DoScriptText(RAND(SAY_FACE_ANGER_UNLEASH_SOUL,SAY_FACE_SORROW_UNLEASH_SOUL,SAY_FACE_DESIRE_UNLEASH_SOUL), me);
                    DoScriptText(EMOTE_UNLEASH_SOUL, me);
                    events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 30000);
                    events.ScheduleEvent(EVENT_FACE_ANGER, 5000);
                    break;
                case EVENT_FACE_ANGER:
                    me->SetDisplayId(DISPLAY_ANGER);
                    break;

                case EVENT_WAILING_SOULS:
                    me->SetDisplayId(DISPLAY_DESIRE);
                    DoScriptText(RAND(SAY_FACE_ANGER_WAILING_SOUL,SAY_FACE_DESIRE_WAILING_SOUL), me);
                    DoScriptText(EMOTE_WAILING_SOUL, me);
                    DoCast(me, SPELL_WAILING_SOULS_STARTING);

                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    {
                        me->SetOrientation(me->GetAngle(pTarget));
                        DoCast(me, SPELL_WAILING_SOULS_BEAM);
                    }

                    beamAngle = me->GetOrientation();

                    beamAngleDiff = PI/30.0f; // PI/2 in 15 sec = PI/30 per tick
                    if (RAND(true,false))
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
                        events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000,70000));
                    }
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_devourer_of_souls(Creature* pCreature)
{
    return new boss_devourer_of_soulsAI(pCreature);
}

void AddSC_boss_devourer_of_souls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_devourer_of_souls";
    newscript->GetAI = &GetAI_boss_devourer_of_souls;
    newscript->RegisterSelf();
}
