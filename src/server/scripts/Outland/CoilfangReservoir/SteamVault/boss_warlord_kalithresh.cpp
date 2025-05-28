/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* Timers requires update
 * Distillers should respawn at some point, probably in case of wipe
 * All distillers should cast SPELL_QUIET_SUICIDE when encounter is finished */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"

enum KalithreshTexts
{
    SAY_INTRO                        = 0,
    SAY_REGEN                        = 1,
    SAY_AGGRO                        = 2,
    SAY_SLAY                         = 3,
    SAY_DEATH                        = 4,
    EMOTE_CHANNEL                    = 5
};

enum KalithreshSpells
{
    SPELL_HEAD_CRACK                 = 16172,
    SPELL_REFLECTION                 = 31534,
    SPELL_IMPALE                     = 39061,

    SPELL_WARLORDS_RAGE              = 37081,
    SPELL_WARLORDS_RAGE_DISTILLER    = 31543,

    // A bunch of NYI serverside spells, some may be not even used
    SPELL_SUMMON_DISTILLER_1         = 31544,
    SPELL_SUMMON_DISTILLER_2         = 31545,
    SPELL_SUMMON_DISTILLER_3         = 31546,

    SPELL_DISTILLER_DUMMY            = 31763,
    SPELL_DISTILLER_DUMMY_DESPAWN    = 31767,
    SPELL_DISTILLER_DUMMY_TRIGGER_1  = 33761,
    SPELL_DISTILLER_DUMMY_COMBAT     = 33769,
    SPELL_DISTILLER_DUMMY_TRIGGER_2  = 34065,
    // Distiller
    SPELL_STUN_SELF                  = 25900,
    SPELL_QUIET_SUICIDE              = 3617
};

enum KalithreshEvents
{
    EVENT_HEAD_CRACK                 = 1,
    EVENT_REFLECTION,
    EVENT_IMPALE,
    EVENT_RAGE
};

enum KalithreshMisc
{
    SOUND_ID_SLAY                    = 10396,
    NPC_NAGA_DISTILLER               = 17954,
    POINT_DISTILLER                  = 1,
    ACTION_DISTILLER_DEAD            = 1,
    ACTION_DISTILLER_CHANNEL         = 1
};

// 17798 - Warlord Kalithresh
struct boss_warlord_kalithresh : public BossAI
{
    boss_warlord_kalithresh(Creature* creature) : BossAI(creature, DATA_WARLORD_KALITHRESH), _introDone(false) { }

    void Reset() override
    {
        _Reset();
        _distillerGUID.Clear();
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_HEAD_CRACK, 10s, 15s);
        events.ScheduleEvent(EVENT_REFLECTION, 15s, 25s);
        events.ScheduleEvent(EVENT_IMPALE, 7s, 14s);
        events.ScheduleEvent(EVENT_RAGE, 10s, 20s);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!_introDone && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 50.0f))
        {
            _introDone = true;
            Talk(SAY_INTRO);
        }

        BossAI::MoveInLineOfSight(who);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_DISTILLER)
        {
            Talk(EMOTE_CHANNEL);
            Talk(SAY_REGEN);
            me->SetReactState(REACT_AGGRESSIVE);
            DoCastSelf(SPELL_WARLORDS_RAGE);

            if (Creature* distiller = ObjectAccessor::GetCreature(*me, _distillerGUID))
                distiller->AI()->DoAction(ACTION_DISTILLER_CHANNEL);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_DISTILLER_DEAD)
            me->RemoveAurasDueToSpell(SPELL_WARLORDS_RAGE);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        if (roll_chance_i(50))
            Talk(SAY_SLAY);
        else
            DoPlaySoundToSet(me, SOUND_ID_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEAD_CRACK:
                    DoCastVictim(SPELL_HEAD_CRACK);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_REFLECTION:
                    DoCastSelf(SPELL_REFLECTION);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_IMPALE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_IMPALE);
                    events.Repeat(7s, 12s);
                    break;
                case EVENT_RAGE:
                    if (Creature* distiller = me->FindNearestCreature(NPC_NAGA_DISTILLER, 150.0f))
                    {
                        _distillerGUID = distiller->GetGUID();
                        me->SetReactState(REACT_PASSIVE);

                        float x, y, z;
                        distiller->GetContactPoint(me, x, y, z);

                        me->GetMotionMaster()->MovePoint(POINT_DISTILLER, x, y, z);
                    }
                    events.Repeat(50s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _introDone;
    ObjectGuid _distillerGUID;
};

// 17954 - Naga Distiller
struct npc_naga_distiller : public ScriptedAI
{
    npc_naga_distiller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetCorpseDelay(2, true);
        DoCastSelf(SPELL_STUN_SELF);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_DISTILLER_CHANNEL)
        {
            // Creature is stunned, cast as triggered
            DoCastSelf(SPELL_WARLORDS_RAGE_DISTILLER, true);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* kalithresh = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_WARLORD_KALITHRESH)))
            kalithresh->AI()->DoAction(ACTION_DISTILLER_DEAD);
    }

private:
    InstanceScript* _instance;
};

void AddSC_boss_warlord_kalithresh()
{
    RegisterSteamVaultCreatureAI(boss_warlord_kalithresh);
    RegisterSteamVaultCreatureAI(npc_naga_distiller);
}
