#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_LIGHTNING_SHIELD_AURA = 263246,
    SPELL_STATIC_SHOCK = 263257,
    SPELL_JOLT = 263318,
    SPELL_CONDUCTION = 263371,
    SPELL_GUST = 263775,
    SPELL_CYCLONE_STRIKE_CAST = 261773,
    SPELL_CYCLONE_STRIKE_DMG = 263573,
    SPELL_CYCLONE_STRIKE_AT = 263325,
    SPELL_ARC_DASH = 263425,
    SPELL_ARCING_BLADE = 263234,
    SPELL_A_PEAR_OF_THUNDER = 263365
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_JOLT,
    EVENT_CONDUCTION,
    EVENT_STATIC_SHOCK,
    EVENT_CYCLONE_STRIKE,
    EVENT_A_PEAL_OF_THUNDER,
    EVENT_ARC_DASH,
    EVENT_GUST,
    EVENT_ARCING_BLADE,
    EVENT_GALE_FORCE,
};

enum Timers
{
    TIMER_CHECK_ENERGY = 3 * IN_MILLISECONDS,
    TIMER_GUST = 10 * IN_MILLISECONDS,
    TIMER_JOLT = 5 * IN_MILLISECONDS,
    TIMER_CONDUCTION = 15 * IN_MILLISECONDS,
    TIMER_CYCLONE_STRIKE = 25 * IN_MILLISECONDS,
    TIMER_A_PEAL_OF_THUNDER = 10 * IN_MILLISECONDS,
    TIMER_ARCING_BLADE = 12 * IN_MILLISECONDS,
    TIMER_GALE_FORCE = 22 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_SHIELDED = 1,
    ACTION_FINISH_OTHER,
};

enum Creatures
{
    BOSS_ADDERIS = 133379,
    BOSS_ASPIX = 133944,
};

const Position centerPos = { 3344.53f, 3148.79f, 88.43f }; //45y

uint8 AdderisAndAspix(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* adderis = instance->GetCreature(BOSS_ADDERIS);
    if (adderis && adderis->IsAlive())
        ++count;

    Creature* aspix = instance->GetCreature(BOSS_ASPIX);
    if (aspix && aspix->IsAlive())
        ++count;

    return count;
}

// gale force forcemovement

#define AGGRO_ASPIX "None can stand against our empire!"
#define SHIELD_ADDERIS "Severed!"
#define SHIELD_ASPIX "Break them, Adderis!"
#define ARCING_SLASH_ADDERIS "Arcing slash!"
#define ASPIX_DEATH "What will become... of the empire..."
#define ADDERIS_DEATH "The sands...take me..."

class bfa_boss_adderis : public CreatureScript
{
public:
    bfa_boss_adderis() : CreatureScript("bfa_boss_adderis") { }

    struct bfa_boss_adderis_AI : public BossAI
    {
        bfa_boss_adderis_AI(Creature* creature) : BossAI(creature, DATA_ADDERIS_AND_ASPIX)  { }

    private:
        bool shielded;
        bool castSpecial;

        void Reset() override
        {
            events.Reset();
            castSpecial = false;
            shielded = false;
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);            
            RespawnAspixAtWipe();
            me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(SHIELD_ADDERIS, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(ADDERIS_DEATH, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(ARCING_SLASH_ADDERIS, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        Creature* GetAspix()
        {
            return me->FindNearestCreature(BOSS_ASPIX, 200.0f, true);
        }

        Creature* GetAdderisDead()
        {
            return me->FindNearestCreature(BOSS_ADDERIS, 200.0f, false);
        }

        Creature* GetAspixDead()
        {
            return me->FindNearestCreature(BOSS_ASPIX, 200.0f, false);
        }

        void RespawnAspixAtWipe()
        {
            if (Creature* aspix = GetAspix())
                aspix->Respawn();
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_FINISH_OTHER:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (GameObject* adderisAspixDoor = me->FindNearestGameObject(GO_ADDERIS_ASPIX_EXIT, 100.0f))
                    adderisAspixDoor->SetGoState(GO_STATE_ACTIVE);
                break;
            case ACTION_SHIELDED:
            {
                SelectSoundAndText(me, 1);
                std::ostringstream str;
                str << "Adderis gains a |cFFF00000|h[Lightning Shield]|h|r !";
                me->TextEmote(str.str().c_str());
                me->AddAura(SPELL_LIGHTNING_SHIELD_AURA, me);
                break;
            }
            }
        }

        void JustDied(Unit*) override
        {
            SelectSoundAndText(me, 2);

            if (instance)
            {
                switch (AdderisAndAspix(instance, me))
                {
                case 1:
                    me->AddLootRecipient(nullptr);
                    break;
                case 0:
                    if (Creature* aspix = GetAspixDead())
                        aspix->AI()->DoAction(ACTION_FINISH_OTHER);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    break;
                }
            }
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            _DespawnAtEvade(15);
        }

        void DamageTaken(Unit* at, uint32& damage) override
        {
            if (me->HasAura(SPELL_LIGHTNING_SHIELD_AURA))
                damage = 0;
        }

        void EnterCombat(Unit*) override
        {
            if (Creature* aspix = GetAspix())
                aspix->SetInCombatWithZone();
            me->SetPower(POWER_ENERGY, 0);
            _EnterCombat();

            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
            events.ScheduleEvent(EVENT_GUST, TIMER_GUST);

            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_ARCING_BLADE, TIMER_ARCING_BLADE);
        }

        void HandleArcDash()
        {
            std::ostringstream str;
            str << "Adderis begins his |cFFF00000|h[Arc Dash]|h|r !";
            me->TextEmote(str.str().c_str());
            SelectSoundAndText(me, 3);

            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            if (playerList.size())
            {
                if (playerList.size() > 1)
                    playerList.resize(1);

                for (auto player : playerList)
                {
                    me->GetMotionMaster()->MoveCharge(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 40.0f);
                    me->CastSpell(player, SPELL_ARC_DASH, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasAura(SPELL_LIGHTNING_SHIELD_AURA))
            {
                shielded = true;
                me->AddUnitState(UNIT_STATE_ROOT);
            }
            else
            {
                shielded = false;
                me->ClearUnitState(UNIT_STATE_ROOT);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ENERGY:
                {
                    if (shielded)
                    {
                        if (me->GetPower(POWER_ENERGY) == 100)
                        {
                            if (Creature* aspix = GetAspix())
                            {
                                aspix->AI()->DoAction(ACTION_SHIELDED);
                                me->RemoveAura(SPELL_LIGHTNING_SHIELD_AURA);
                            }
                            for (uint8 i = 0; i < 3; ++i)
                                HandleArcDash();
                            me->SetPower(POWER_ENERGY, 0);
                            castSpecial = false;
                        }

                        if (me->GetPower(POWER_ENERGY) >= 50 && !castSpecial)
                        {
                            castSpecial = true;
                            events.ScheduleEvent(EVENT_A_PEAL_OF_THUNDER, TIMER_A_PEAL_OF_THUNDER);
                        }

                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 5));
                    }

                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);

                    break;
                }
                case EVENT_A_PEAL_OF_THUNDER:
                {
                    if (shielded)
                    {
                        std::list<Player*> playerList;
                        me->GetPlayerListInGrid(playerList, 100.0f);
                        if (playerList.size())
                        {
                            if (playerList.size() > 1)
                                playerList.resize(1);

                            for (auto player : playerList)
                            {
                                me->NearTeleportTo(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), me->GetOrientation(), false);
                                me->CastSpell(player, SPELL_A_PEAR_OF_THUNDER);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_A_PEAL_OF_THUNDER, TIMER_A_PEAL_OF_THUNDER);
                    break;
                }
                case EVENT_GUST:
                    if (!shielded)
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_GUST);
                    events.ScheduleEvent(EVENT_GUST, TIMER_GUST);
                    break;
                case EVENT_ARCING_BLADE:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_ARCING_BLADE);
                    events.ScheduleEvent(EVENT_ARCING_BLADE, TIMER_ARCING_BLADE);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_adderis_AI(creature);
    }
};

class bfa_boss_aspix : public CreatureScript
{
public:
    bfa_boss_aspix() : CreatureScript("bfa_boss_aspix") { }
    struct bfa_boss_aspix_AI : public BossAI
    {
        bfa_boss_aspix_AI(Creature* creature) : BossAI(creature, DATA_ADDERIS_AND_ASPIX) { }

    private:
        bool shielded;
        bool castSpecial;

        void Reset() override
        {
            shielded = false;
            castSpecial = false;
            events.Reset();
            me->SetPowerType(POWER_ENERGY);
            RespawnAdderisAtWipe();
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(SHIELD_ASPIX, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(ASPIX_DEATH, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(AGGRO_ASPIX, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        Creature* GetAdderis()
        {
            return me->FindNearestCreature(BOSS_ADDERIS, 200.0f, true);
        }

        Creature* GetAdderisDead()
        {
            return me->FindNearestCreature(BOSS_ADDERIS, 200.0f, false);
        }

        Creature* GetAspixDead()
        {
            return me->FindNearestCreature(BOSS_ASPIX, 200.0f, false);
        }

        void RespawnAdderisAtWipe()
        {
            if (Creature* adderis = GetAdderisDead())
                adderis->Respawn();
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_FINISH_OTHER:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (GameObject* adderisAspixDoor = me->FindNearestGameObject(GO_ADDERIS_ASPIX_EXIT, 100.0f))
                    adderisAspixDoor->SetGoState(GO_STATE_ACTIVE);
                break;
            case ACTION_SHIELDED:
            {
                std::ostringstream str;
                str << "Aspix gains a |cFFF00000|h[Lightning Shield]|h|r !";
                me->TextEmote(str.str().c_str());
                SelectSoundAndText(me, 1);

                me->AddAura(SPELL_LIGHTNING_SHIELD_AURA, me);
                break;
            }
            }
        }

        void JustDied(Unit*) override
        {
            SelectSoundAndText(me, 2);

            if (instance)
            {
                switch (AdderisAndAspix(instance, me))
                {
                case 1:
                    me->AddLootRecipient(nullptr);
                    break;
                case 0:
                    if (Creature* adderis = GetAdderisDead())
                        adderis->AI()->DoAction(ACTION_FINISH_OTHER);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    break;
                }
            }
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            _DespawnAtEvade(15);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->HasAura(SPELL_LIGHTNING_SHIELD_AURA))
                damage = 0;
        }

        void EnterCombat(Unit*) override
        {
            SelectSoundAndText(me, 3);
            if (Creature* adderis = GetAdderis())
                adderis->SetInCombatWithZone();

            me->CastSpell(me, SPELL_LIGHTNING_SHIELD_AURA, true);
            me->SetPower(POWER_ENERGY, 0);
            _EnterCombat();

            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
            events.ScheduleEvent(EVENT_CYCLONE_STRIKE, TIMER_CYCLONE_STRIKE);
            events.ScheduleEvent(EVENT_JOLT, TIMER_JOLT);

            if (IsHeroic() || IsMythic())
                events.ScheduleEvent(EVENT_GALE_FORCE, TIMER_GALE_FORCE);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasAura(SPELL_LIGHTNING_SHIELD_AURA))
            {
                shielded = true;
                me->AddUnitState(UNIT_STATE_ROOT);
            }
            else
            {
                shielded = false;
                me->ClearUnitState(UNIT_STATE_ROOT);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_GALE_FORCE:
                    events.ScheduleEvent(EVENT_GALE_FORCE, TIMER_GALE_FORCE);
                    break;
                case EVENT_CHECK_ENERGY:
                {
                    if (shielded)
                    {
                        if (me->GetPower(POWER_ENERGY) == 100)
                        {
                            if (Creature* adderis = GetAdderis())
                            {
                                adderis->AI()->DoAction(ACTION_SHIELDED);
                                me->RemoveAura(SPELL_LIGHTNING_SHIELD_AURA);
                            }
                            me->CastSpell(me, SPELL_STATIC_SHOCK);
                            me->SetPower(POWER_ENERGY, 0);
                            castSpecial = false;
                        }

                        if (me->GetPower(POWER_ENERGY) >= 50 && !castSpecial)
                        {
                            castSpecial = true;
                            events.ScheduleEvent(EVENT_CONDUCTION, TIMER_CONDUCTION);
                        }

                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 5));
                    }

                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);

                    break;
                }
                case EVENT_CONDUCTION:
                    if (shielded)
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            me->CastSpell(target, SPELL_CONDUCTION);
                    events.ScheduleEvent(EVENT_CONDUCTION, TIMER_CONDUCTION);
                    break;
                case EVENT_CYCLONE_STRIKE:
                    if (!shielded)
                        me->CastSpell(me, SPELL_CYCLONE_STRIKE_CAST);
                    events.ScheduleEvent(EVENT_CYCLONE_STRIKE, TIMER_CYCLONE_STRIKE);
                    break;
                case EVENT_JOLT:
                    if (shielded)
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            me->CastSpell(target, SPELL_JOLT);
                    events.ScheduleEvent(EVENT_JOLT, TIMER_JOLT);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_aspix_AI(creature);
    }
};

// 263234
class bfa_spell_arcing_blade : public SpellScriptLoader
{
public:
    bfa_spell_arcing_blade() : SpellScriptLoader("bfa_spell_arcing_blade") { }

    class bfa_spell_arcing_blade_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_arcing_blade_SpellScript);

        uint8 targetsPlayers;

        bool Load()
        {
            targetsPlayers = 1;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetsPlayers = targets.size();
        }

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(GetHitDamage() / targetsPlayers);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_arcing_blade_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_arcing_blade_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcing_blade_SpellScript();
    }
};

void AddSC_boss_adderis_and_aspix()
{
    new bfa_boss_adderis();
    new bfa_boss_aspix();
    new bfa_spell_arcing_blade();
}
