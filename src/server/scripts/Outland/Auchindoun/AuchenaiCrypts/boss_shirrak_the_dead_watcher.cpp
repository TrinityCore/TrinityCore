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

/* Old comment: "Inhibit Magic should stack slower far from the boss" - really? */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "auchenai_crypts.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum ShirrakTexts
{
    EMOTE_FOCUSED                  = 0
};

enum ShirrakSpells
{
    SPELL_INHIBIT_MAGIC_PERIODIC   = 33460,     // NYI
    SPELL_INHIBIT_MAGIC            = 32264,

    SPELL_ATTRACT_MAGIC            = 32265,
    SPELL_CARNIVOROUS_BITE         = 36383,
    SPELL_FOCUS_FIRE_AURA          = 32291,

    SPELL_BIRTH                    = 26262,
    SPELL_FOCUS_TARGET_VISUAL      = 32286,
    SPELL_FIERY_BLAST              = 32302,

    SPELL_FOCUS_FIRE_DUMMY         = 32300,
    SPELL_PING_SHIRRAK             = 32301
};

enum ShirrakEvents
{
    EVENT_ATTRACT_MAGIC            = 1,
    EVENT_CARNIVOROUS_BITE,
    EVENT_FOCUS_FIRE
};

struct boss_shirrak_the_dead_watcher : public BossAI
{
    boss_shirrak_the_dead_watcher(Creature* creature) : BossAI(creature, DATA_SHIRRAK_THE_DEAD_WATCHER)
    {
        Initialize();
    }

    void Initialize()
    {
        Inhibitmagic_Timer = 0;
    }

    uint32 Inhibitmagic_Timer;

    void Reset() override
    {
        Initialize();
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_ATTRACT_MAGIC, 30s);
        events.ScheduleEvent(EVENT_CARNIVOROUS_BITE, 5s, 10s);
        events.ScheduleEvent(EVENT_FOCUS_FIRE, 20s, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        /// @todo: Do it in aura script
        if (Inhibitmagic_Timer <= diff)
        {
            float dist;
            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if (Player* i_pl = i->GetSource())
                    if (i_pl->IsAlive() && (dist = i_pl->GetDistance(me)) < 45)
                    {
                        i_pl->RemoveAurasDueToSpell(SPELL_INHIBIT_MAGIC);
                        me->AddAura(SPELL_INHIBIT_MAGIC, i_pl);
                        if (dist < 35)
                            me->AddAura(SPELL_INHIBIT_MAGIC, i_pl);
                        if (dist < 25)
                            me->AddAura(SPELL_INHIBIT_MAGIC, i_pl);
                        if (dist < 15)
                            me->AddAura(SPELL_INHIBIT_MAGIC, i_pl);
                    }
            Inhibitmagic_Timer = 3000 + (rand32() % 1000);
        } else Inhibitmagic_Timer -= diff;

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ATTRACT_MAGIC:
                    DoCastSelf(SPELL_ATTRACT_MAGIC);
                    events.Repeat(30s);
                    break;
                case EVENT_CARNIVOROUS_BITE:
                    DoCastSelf(SPELL_CARNIVOROUS_BITE);
                    events.Repeat(5s, 10s);
                    break;
                case EVENT_FOCUS_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 50, true))
                    {
                        DoCast(target, SPELL_FOCUS_FIRE_AURA);
                        Talk(EMOTE_FOCUSED, target);
                    }
                    events.Repeat(15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_focus_fire : public ScriptedAI
{
    npc_focus_fire(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        // Should be in this sniffed order but makes it ignore other spell casts, so disabled
        // DoCastSelf(SPELL_BIRTH);
        DoCastSelf(SPELL_FOCUS_TARGET_VISUAL);
        DoCastSelf(SPELL_PING_SHIRRAK);

        _scheduler.Schedule(5s, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_FIERY_BLAST);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 32301 - Ping Shirrak
class spell_shirrak_ping_shirrak : public SpellScript
{
    PrepareSpellScript(spell_shirrak_ping_shirrak);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUS_FIRE_DUMMY });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_FOCUS_FIRE_DUMMY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shirrak_ping_shirrak::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_shirrak_the_dead_watcher()
{
    RegisterAuchenaiCryptsCreatureAI(boss_shirrak_the_dead_watcher);
    RegisterAuchenaiCryptsCreatureAI(npc_focus_fire);
    RegisterSpellScript(spell_shirrak_ping_shirrak);
}
