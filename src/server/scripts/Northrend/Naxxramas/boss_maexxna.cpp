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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_WEB_WRAP              = 28622,
    SPELL_WEB_SPRAY             = 29484,
    SPELL_POISON_SHOCK          = 28741,
    SPELL_NECROTIC_POISON       = 28776,
    SPELL_FRENZY                = 54123
};
#define SPELL_FRENZY_HELPER RAID_MODE(54123,54124)

enum Emotes
{
    EMOTE_SPIDERS           = 0,
    EMOTE_WEB_WRAP          = 1,
    EMOTE_WEB_SPRAY         = 2
};

enum Creatures
{
    NPC_WEB_WRAP                = 16486,
    NPC_SPIDERLING              = 17055,
};

#define MAX_WRAP_POSITION  7
const Position WrapPositions[MAX_WRAP_POSITION] =
{
    {3453.818f, -3854.651f, 308.7581f, 4.362833f},
    {3535.042f, -3842.383f, 300.795f,  3.179324f},
    {3538.399f, -3846.088f, 299.964f,  4.310297f},
    {3548.464f, -3854.676f, 298.6075f, 4.546609f},
    {3557.663f, -3870.123f, 297.5027f, 3.756433f},
    {3560.546f, -3879.353f, 297.4843f, 2.508937f},
    {3562.535f, -3892.507f, 298.532f,  6.022466f},
};

enum Events
{
    EVENT_NONE,
    EVENT_SPRAY,
    EVENT_SHOCK,
    EVENT_POISON,
    EVENT_WRAP,
    EVENT_SUMMON,
};

const float WEB_WRAP_MOVE_SPEED = 20.0f;

struct WebTargetSelector
{
    WebTargetSelector(Unit* maexxna) : _maexxna(maexxna) {}
    bool operator()(Unit const* target) const
    {
        if (target->GetTypeId() != TYPEID_PLAYER) // never web nonplayers (pets, guardians, etc.)
            return false;
        if (_maexxna->GetVictim() == target) // never target tank
            return false;
        if (target->HasAura(SPELL_WEB_WRAP)) // never target targets that are already webbed
            return false;
        return true;
    }

    private:
        Unit const* _maexxna;
};

struct boss_maexxna : public BossAI
{
    boss_maexxna(Creature* creature) : BossAI(creature, BOSS_MAEXXNA)  {  }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_WRAP, 20s);
        events.ScheduleEvent(EVENT_SPRAY, 40s);
        events.ScheduleEvent(EVENT_SHOCK, randtime(Seconds(5), Seconds(10)));
        events.ScheduleEvent(EVENT_POISON, randtime(Seconds(10), Seconds(15)));
        events.ScheduleEvent(EVENT_SUMMON, 30s);
    }

    void Reset() override
    {
        _Reset();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEB_WRAP);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (HealthBelowPct(30) && !me->HasAura(SPELL_FRENZY_HELPER))
        {
            DoCast(SPELL_FRENZY);
        }

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WRAP:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, RAID_MODE(1, 2), SelectTargetMethod::Random, 1, WebTargetSelector(me));
                    if (!targets.empty())
                    {
                        Talk(EMOTE_WEB_WRAP);
                        int8 wrapPos = -1;
                        for (Unit* target : targets)
                        {
                            if (wrapPos == -1) // allow all positions on the first target
                                wrapPos = urand(0, MAX_WRAP_POSITION - 1);
                            else // on subsequent iterations, only allow positions that are not equal to the previous one (this is sufficient since we should only have two targets at most, ever)
                                wrapPos = (wrapPos + urand(1, MAX_WRAP_POSITION - 1)) % MAX_WRAP_POSITION;

                            target->RemoveAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_WEB_SPRAY, me));
                            if (Creature* wrap = DoSummon(NPC_WEB_WRAP, WrapPositions[wrapPos], 70s, TEMPSUMMON_TIMED_DESPAWN))
                            {
                                wrap->AI()->SetGUID(target->GetGUID()); // handles application of debuff
                                target->GetMotionMaster()->MoveJump(WrapPositions[wrapPos], WEB_WRAP_MOVE_SPEED, WEB_WRAP_MOVE_SPEED); // move after stun to avoid stun cancelling move
                            }
                        }
                    }
                    events.Repeat(Seconds(40));
                    break;
                }
                case EVENT_SPRAY:
                    Talk(EMOTE_WEB_SPRAY);
                    DoCastAOE(SPELL_WEB_SPRAY);
                    events.Repeat(Seconds(40));
                    break;
                case EVENT_SHOCK:
                    DoCastAOE(SPELL_POISON_SHOCK);
                    events.Repeat(randtime(Seconds(10), Seconds(20)));
                    break;
                case EVENT_POISON:
                    DoCastVictim(SPELL_NECROTIC_POISON);
                    events.Repeat(randtime(Seconds(10), Seconds(20)));
                    break;
                case EVENT_SUMMON:
                    Talk(EMOTE_SPIDERS);
                    uint8 amount = urand(8, 10);
                    for (uint8 i = 0; i < amount; ++i)
                        DoSummon(NPC_SPIDERLING, me, 4.0f, 5s, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    events.Repeat(Seconds(40));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_webwrap : public NullCreatureAI
{
    npc_webwrap(Creature* creature) : NullCreatureAI(creature), visibleTimer(0) { }

    ObjectGuid victimGUID;
    uint32 visibleTimer;

    void InitializeAI() override
    {
        me->SetVisible(false);
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!guid)
            return;
        victimGUID = guid;
        if (Unit* victim = ObjectAccessor::GetUnit(*me, victimGUID))
        {
            visibleTimer = (me->GetDistance2d(victim)/WEB_WRAP_MOVE_SPEED + 0.5f) * IN_MILLISECONDS;
            victim->CastSpell(victim, SPELL_WEB_WRAP, me->GetGUID());
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!visibleTimer)
            return;

        if (diff >= visibleTimer)
        {
            visibleTimer = 0;
            me->SetVisible(true);
        }
        else
            visibleTimer -= diff;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (victimGUID)
            if (Unit* victim = ObjectAccessor::GetUnit(*me, victimGUID))
                victim->RemoveAurasDueToSpell(SPELL_WEB_WRAP, me->GetGUID());

        me->DespawnOrUnsummon(5s);
    }
};

void AddSC_boss_maexxna()
{
    RegisterNaxxramasCreatureAI(boss_maexxna);
    RegisterNaxxramasCreatureAI(npc_webwrap);
}
