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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_DECREPIT_FEVER    = 29998, // 25-man: 55011
    SPELL_SPELL_DISRUPTION  = 29310,
    SPELL_PLAGUE_CLOUD      = 29350,
    SPELL_TELEPORT_SELF     = 30211
};

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_TAUNT               = 2,
    SAY_DEATH               = 3,

    EMOTE_DANCE             = 4,
    EMOTE_DANCE_END         = 5,
};

enum Events
{
    EVENT_DISRUPT = 1,
    EVENT_FEVER,
    EVENT_ERUPT,
    EVENT_DANCE,
    EVENT_DANCE_END
};

enum Phases
{
    PHASE_FIGHT = 1,
    PHASE_DANCE
};

enum Misc
{
    DATA_SAFETY_DANCE               = 19962139
};

static const uint32 firstEruptionDBGUID = 84980;
static const uint8 numSections = 4;
static const uint8 numEruptions[numSections] = { // count of sequential GO DBGUIDs in the respective section of the room
    15,
    25,
    23,
    13
};

struct boss_heigan : public BossAI
{
    boss_heigan(Creature* creature) : BossAI(creature, BOSS_HEIGAN), _safeSection(0), _danceDirection(false), _safetyDance(false) { }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        _Reset();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_SLAY);
            _safetyDance = false;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        return (type == DATA_SAFETY_DANCE && _safetyDance) ? 1u : 0u;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        _safeSection = 0;
        events.ScheduleEvent(EVENT_DISRUPT, randtime(Seconds(15), Seconds(20)), 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_FEVER, randtime(Seconds(10), Seconds(20)), 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_DANCE, Minutes(1) + Seconds(30), 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_ERUPT, 15s);

        _safetyDance = true;

        // figure out the current GUIDs of our eruption tiles and which segment they belong in
        std::unordered_multimap<uint32, GameObject*> const& mapGOs = me->GetMap()->GetGameObjectBySpawnIdStore();
        uint32 spawnId = firstEruptionDBGUID;
        for (uint8 section = 0; section < numSections; ++section)
        {
            _eruptTiles[section].clear();
            for (uint8 i = 0; i < numEruptions[section]; ++i)
            {
                auto tileIt = mapGOs.equal_range(spawnId++);
                for (auto it = tileIt.first; it != tileIt.second; ++it)
                    _eruptTiles[section].push_back(it->second->GetGUID());
            }
        }
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
                case EVENT_DISRUPT:
                    DoCastAOE(SPELL_SPELL_DISRUPTION);
                    events.Repeat(Seconds(11));
                    break;
                case EVENT_FEVER:
                    DoCastAOE(SPELL_DECREPIT_FEVER);
                    events.Repeat(randtime(Seconds(20), Seconds(25)));
                    break;
                case EVENT_DANCE:
                    events.SetPhase(PHASE_DANCE);
                    Talk(SAY_TAUNT);
                    Talk(EMOTE_DANCE);
                    _safeSection = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->StopMoving();
                    DoCast(SPELL_TELEPORT_SELF);
                    DoCastAOE(SPELL_PLAGUE_CLOUD);
                    events.ScheduleEvent(EVENT_DANCE_END, Seconds(45), 0, PHASE_DANCE);
                    events.RescheduleEvent(EVENT_ERUPT, Seconds(10));
                    break;
                case EVENT_DANCE_END:
                    events.SetPhase(PHASE_FIGHT);
                    Talk(EMOTE_DANCE_END);
                    _safeSection = 0;
                    events.ScheduleEvent(EVENT_DISRUPT, randtime(Seconds(10), Seconds(25)), 0, PHASE_FIGHT);
                    events.ScheduleEvent(EVENT_FEVER, randtime(Seconds(15), Seconds(20)), 0, PHASE_FIGHT);
                    events.ScheduleEvent(EVENT_DANCE, Minutes(1) + Seconds(30), 0, PHASE_FIGHT);
                    events.RescheduleEvent(EVENT_ERUPT, Seconds(15));
                    me->CastStop();
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                case EVENT_ERUPT:
                    TeleportCheaters();
                    for (uint8 section = 0; section < numSections; ++section)
                        if (section != _safeSection)
                            for (ObjectGuid tileGUID : _eruptTiles[section])
                                if (GameObject* tile = ObjectAccessor::GetGameObject(*me, tileGUID))
                                {
                                    tile->SendCustomAnim(0);
                                    CastSpellExtraArgs args;
                                    args.OriginalCaster = me->GetGUID();
                                    tile->CastSpell(tile, tile->GetGOInfo()->trap.spellId, args);
                                }

                    if (_safeSection == 0)
                        _danceDirection = true;
                    else if (_safeSection == numSections-1)
                        _danceDirection = false;

                    _danceDirection ? ++_safeSection : --_safeSection;

                    events.Repeat(events.IsInPhase(PHASE_DANCE) ? Seconds(3) : Seconds(10));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    private:
        std::vector<ObjectGuid> _eruptTiles[numSections]; // populated on encounter start

        uint32 _safeSection; // 0 is next to the entrance
        bool _danceDirection; // true is counter-clockwise, false is clock-wise
        bool _safetyDance; // is achievement still possible? (= no player deaths yet)
};

// 29371 - Eruption
class spell_heigan_eruption : public SpellScript
{
    PrepareSpellScript(spell_heigan_eruption);

    void HandleScript(SpellEffIndex /*eff*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !GetHitUnit())
            return;

        if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (Creature* Heigan = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_HEIGAN)))
                    Heigan->AI()->KilledUnit(GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_heigan_eruption::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class achievement_safety_dance : public AchievementCriteriaScript
{
    public:
        achievement_safety_dance() : AchievementCriteriaScript("achievement_safety_dance") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Heigan = target->ToCreature())
                if (Heigan->AI()->GetData(DATA_SAFETY_DANCE))
                    return true;

            return false;
        }
};

void AddSC_boss_heigan()
{
    RegisterNaxxramasCreatureAI(boss_heigan);
    RegisterSpellScript(spell_heigan_eruption);
    new achievement_safety_dance();
}
