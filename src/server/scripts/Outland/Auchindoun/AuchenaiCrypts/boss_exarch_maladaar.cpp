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
#include "auchenai_crypts.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    SAY_ROAR                    = 0,
    SAY_SOUL_CLEAVE             = 1,
    SAY_SUMMON                  = 2,
    SAY_AGGRO                   = 3,
    SAY_SLAY                    = 4,
    SAY_DEATH                   = 5
};

enum Spells
{
    SPELL_SOUL_SCREAM           = 32421,
    SPELL_RIBBON_OF_SOULS       = 32422,
    SPELL_STOLEN_SOUL           = 32346,
    SPELL_SUMMON_STOLEN_SOUL    = 32360,
    SPELL_SUMMON_AVATAR         = 32424,

    // Stolen Soul
    SPELL_STOLEN_SOUL_VISUAL    = 32395,
    SPELL_STOLEN_SOUL_DISPEL    = 33326,

    SPELL_MOONFIRE              = 37328,
    SPELL_FIREBALL              = 37329,
    SPELL_MIND_FLAY             = 37330,
    SPELL_HEMORRHAGE            = 37331,
    SPELL_FROST_SHOCK           = 37332,
    SPELL_CURSE_OF_AGONY        = 37334,
    SPELL_MORTAL_STRIKE         = 37335,
    SPELL_FREEZING_TRAP         = 37368,
    SPELL_HAMMER_OF_JUSTICE     = 37369,
    SPELL_PLAGUE_STRIKE         = 58839
};

enum Events
{
    EVENT_SOUL_SCREAM           = 1,
    EVENT_RIBBON_OF_SOULS,
    EVENT_STOLEN_SOUL,
    EVENT_SUMMON_AVATAR
};

enum Misc
{
    NPC_DORE                    = 19412,

    MODEL_UNDEAD_MALE           = 1027,    // guessed
    MODEL_UNDEAD_FEMALE         = 1029,    // guessed
    MODEL_NIGHTELF_MALE         = 2572,    // guessed
    MODEL_NIGHTELF_FEMALE       = 2575,    // guessed
    MODEL_ORC_MALE              = 2576,    // guessed
    MODEL_ORC_FEMALE            = 2577,    // guessed
    MODEL_TAUREN_MALE           = 2578,    // sniff
    MODEL_TAUREN_FEMALE         = 2579,    // guessed
    MODEL_GNOME_MALE            = 2581,    // guessed
    MODEL_GNOME_FEMALE          = 2590,    // guessed
    MODEL_HUMAN_MALE            = 2582,    // sniff
    MODEL_HUMAN_FEMALE          = 2583,    // sniff
    MODEL_DWARF_MALE            = 2584,    // sniff
    MODEL_DWARF_FEMALE          = 2585,    // guessed
    MODEL_TROLL_MALE            = 2588,    // guessed
    MODEL_TROLL_FEMALE          = 2589,    // guessed
    MODEL_BLOODELF_MALE         = 17267,   // completely guessed
    MODEL_BLOODELF_FEMALE       = 17268,   // completely guessed
    MODEL_DRAENEI_MALE          = 16721,   // completely guessed
    MODEL_DRAENEI_FEMALE        = 17004    // completely guessed
};

Position const DoreSpawnPos = { -4.40722f, -387.277f, 40.6294f, 6.26573f };

struct boss_exarch_maladaar : public BossAI
{
    boss_exarch_maladaar(Creature* creature) : BossAI(creature, DATA_EXARCH_MALADAAR), _avatarSummoned(false) { }

    void Reset() override
    {
        _Reset();
        _avatarSummoned = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SOUL_SCREAM, RAND(10s, 15s, 20s, 25s));
        events.ScheduleEvent(EVENT_RIBBON_OF_SOULS, 1s, 4s);
        events.ScheduleEvent(EVENT_STOLEN_SOUL, RAND(10s, 15s, 20s, 25s));
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_avatarSummoned && me->HealthBelowPctDamaged(25, damage))
        {
            _avatarSummoned = true;
            events.ScheduleEvent(EVENT_SUMMON_AVATAR, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_STOLEN_SOUL)
            if (roll_chance_i(25))
                Talk(SAY_SOUL_CLEAVE);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_STOLEN_SOUL)
            target->CastSpell(target, SPELL_SUMMON_STOLEN_SOUL, true);
    }

    // Do not despawn avatar
    void JustSummoned(Creature* /*summon*/) override { }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        me->SummonCreature(NPC_DORE, DoreSpawnPos, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SOUL_SCREAM:
                    if (roll_chance_i(25))
                        Talk(SAY_ROAR);
                    DoCastSelf(SPELL_SOUL_SCREAM);
                    events.Repeat(RAND(15s, 20s));
                    break;
                case EVENT_RIBBON_OF_SOULS:
                    DoCastVictim(SPELL_RIBBON_OF_SOULS);
                    events.Repeat(4s, 20s);    // Usually just 4
                    break;
                case EVENT_STOLEN_SOUL:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true, true, -SPELL_STOLEN_SOUL))
                        DoCast(target, SPELL_STOLEN_SOUL);
                    events.Repeat(RAND(20s, 25s));
                    break;
                case EVENT_SUMMON_AVATAR:
                    Talk(SAY_SUMMON);
                    DoCastSelf(SPELL_SUMMON_AVATAR);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _avatarSummoned;
};

struct npc_stolen_soul : public ScriptedAI
{
    npc_stolen_soul(Creature* creature) : ScriptedAI(creature), _summonerClass(CLASS_NONE) { }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Player* summoner = summonerWO->ToPlayer();
        if (!summoner)
            return;

        _summonerGUID = summoner->GetGUID();
        _summonerClass = summoner->GetClass();

        // Apparently this is the first time they tried to "clone" player
        uint32 model = 0;
        uint8 gender = summoner->GetNativeGender();

        switch (summoner->GetRace())
        {
            case RACE_UNDEAD_PLAYER: model = gender ? MODEL_UNDEAD_FEMALE : MODEL_UNDEAD_MALE; break;
            case RACE_NIGHTELF:      model = gender ? MODEL_NIGHTELF_FEMALE : MODEL_NIGHTELF_MALE; break;
            case RACE_ORC:           model = gender ? MODEL_ORC_FEMALE : MODEL_ORC_MALE; break;
            case RACE_TAUREN:        model = gender ? MODEL_TAUREN_FEMALE : MODEL_TAUREN_MALE; break;
            case RACE_GNOME:         model = gender ? MODEL_GNOME_FEMALE : MODEL_GNOME_MALE; break;
            case RACE_HUMAN:         model = gender ? MODEL_HUMAN_FEMALE : MODEL_HUMAN_MALE; break;
            case RACE_DWARF:         model = gender ? MODEL_DWARF_FEMALE : MODEL_DWARF_MALE; break;
            case RACE_TROLL:         model = gender ? MODEL_TROLL_FEMALE : MODEL_TROLL_MALE; break;
            case RACE_BLOODELF:      model = gender ? MODEL_BLOODELF_FEMALE : MODEL_BLOODELF_MALE; break;
            case RACE_DRAENEI:       model = gender ? MODEL_DRAENEI_FEMALE : MODEL_DRAENEI_MALE; break;
            default: break;
        }

        if (model)
            me->SetDisplayId(model);

        me->SetCorpseDelay(3, true);
        DoCastSelf(SPELL_STOLEN_SOUL_VISUAL);

        DoZoneInCombat();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        switch (_summonerClass)
        {
            case CLASS_WARRIOR:            //
                _scheduler.Schedule(5s, 10s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    task.Repeat(5s, 10s);
                });
                break;
            case CLASS_PALADIN:            // video & sniff
                _scheduler.Schedule(2s, 7s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                    task.Repeat(8s, 15s);
                });
                break;
            case CLASS_HUNTER:             // video
                _scheduler.Schedule(5s, [this](TaskContext task)
                {
                    DoCastSelf(SPELL_FREEZING_TRAP);
                    task.Repeat(20s);
                });
                break;
            case CLASS_ROGUE:              //
                _scheduler.Schedule(5s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_HEMORRHAGE);
                    task.Repeat(10s);
                });
                break;
            case CLASS_PRIEST:             //
                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_MIND_FLAY);
                    task.Repeat(3s, 5s);
                });
                break;
            case CLASS_SHAMAN:             // video
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f, true, true, -SPELL_FROST_SHOCK))
                        DoCast(target, SPELL_FROST_SHOCK);
                    task.Repeat(3s, 8s);
                });
                break;
            case CLASS_MAGE:               // video
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_FIREBALL);
                    task.Repeat(3s);
                });
                break;
            case CLASS_WARLOCK:            // video
                _scheduler.Schedule(10s, [this](TaskContext task)
                {
                    if (Unit* victim = me->GetVictim())
                        if (!victim->HasAura(SPELL_CURSE_OF_AGONY))
                            DoCast(victim, SPELL_CURSE_OF_AGONY);

                    task.Repeat(7s);
                });
                break;
            case CLASS_DRUID:              //
                _scheduler.Schedule(5s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_MOONFIRE);
                    task.Repeat(10s);
                });
                break;
            case CLASS_DEATH_KNIGHT:       //
                _scheduler.Schedule(3s, 6s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_PLAGUE_STRIKE);
                    task.Repeat(6s, 12s);
                });
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Unit* target = ObjectAccessor::GetUnit(*me, _summonerGUID))
            DoCast(target, SPELL_STOLEN_SOUL_DISPEL, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _summonerGUID;
    uint8 _summonerClass;
};

// 33326 - Stolen Soul Dispel
class spell_exarch_maladaar_stolen_soul_dispel : public AuraScript
{
    PrepareAuraScript(spell_exarch_maladaar_stolen_soul_dispel);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_STOLEN_SOUL });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_STOLEN_SOUL);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_exarch_maladaar_stolen_soul_dispel::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_exarch_maladaar()
{
    RegisterAuchenaiCryptsCreatureAI(boss_exarch_maladaar);
    RegisterAuchenaiCryptsCreatureAI(npc_stolen_soul);
    RegisterSpellScript(spell_exarch_maladaar_stolen_soul_dispel);
}
