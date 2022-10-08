#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "the_underrot.h"

enum Spells
{
    SPELL_FESTERING_HARVEST = 259888,
    SPELL_FESTERING_HARVEST_DAMAGE = 259732,
    SPELL_SPORE_POD_SUMMON_SPELL_DEST = 259621,
    SPELL_BOUNDLESS_ROT_ENTER_COMBAT = 277732,
    SPELL_BOUNDLESS_ROT = 259830,
    SPELL_BOUNDLESS_ROT_AT = 259727, // on npc
    SPELL_SHOCKWAVE = 272457,
    SPELL_UPHEAVAL_TARGET = 259718, // arrow
    SPELL_UPHEAVAL = 274213,
    SPELL_UPHEAVAL_DAMAGE = 259720,
    SPELL_DECAYING_SPORE = 259714,
    SPELL_VOLATILE_POD = 273271,
    SPELL_VOLATILE_POD_EXPLOSION_VISUAL = 273285,
    SPELL_VOLATILE_POD_AT = 273300, // ball
    SPELL_SPORE_HIT_VISUAL = 259862,
    SPELL_SPORE_BEAM = 259968,
    SPELL_SPORE_DETONATION = 259668,
    SPELL_SPORE_BIG_DETONATION = 259958,
};

enum Events
{
    EVENT_SHOCKWAVE = 1,
    EVENT_SPAWN_SPORE,
    EVENT_FESTERING_HARVEST,
    EVENT_UPHEAVAL,
    EVENT_VOLATILE_PODS,
    EVENT_ENERGY_REGEN,
    EVENT_SPAWN_VOLATILE_SPORE,

    EVENT_VOLATILE_PODS_EXPLODE,
};

enum Timers
{
    TIMER_ENERGY_REGEN = 3 * IN_MILLISECONDS,
    TIMER_SPAWN_SPORE = 7 * IN_MILLISECONDS,
    TIMER_SHOCKWAVE = 15 * IN_MILLISECONDS,
    TIMER_UPHEAVAL = 19 * IN_MILLISECONDS,
    TIMER_SPAWN_VOLATILE_SPORE = 30 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_SPORECALLER_ZANCHA = 131383,

    NPC_SPORE_POD_TRIGGER = 131597,
    NPC_VOLATILE_POD_TRIGGER = 139127,
};

Position volatilePodsPositions[6] =
{
    { 1029.872f, 1034.783f, 33.64273f, 1.443645f },
    { 1013.984f, 1074.379f, 33.12016f, 5.567164f },
    { 1007.908f, 1051.262f, 32.98660f, 0.226441f },
    { 1052.523f, 1072.844f, 32.91686f, 3.785604f },
    { 1049.149f, 1043.300f, 33.95835f, 2.441262f },
    { 1035.661f, 1082.078f, 32.73851f, 4.595759f },
};

const Position centerPlatform { 1032.69f, 1058.84f, 33.33f }; // 15 yards min 20 yards max spore spawn, cheaters 30yards

struct checkSpec : public std::unary_function<Unit*, bool>
{
    checkSpec() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
    }
};

class sporeActive
{
public:
    bool operator()(Creature* target) const
    {
        return target && target->HasAura(SPELL_BOUNDLESS_ROT_AT);
    }
};

class frontOfMe
{
public:
    frontOfMe(Unit* caster) : _caster(caster) {}
    bool operator()(WorldObject* target) const
    {
        return target && !target->isInFront(_caster);
    }

private:
    Unit* _caster;
};

enum Sounds
{
    SOUND_DEATH = 109966,
    SOUND_KILL = 109964,
    SOUND_HARVEST = 109965,
    SOUND_VOLATILE = 109960,
    SOUND_INTRO = 109962,
};

#define AGGRO_TEXT "Fester!"
#define DEATH_TEXT "Everything... decays..."
#define VOLATILE_TEXT "Grow!"
#define HARVEST_TEXT "Harvest!"
#define SELECT_SPORE_TEXT "Such fertile soil."
#define KILL_TEXT "Rot must spread!"
#define INTRO_TEXT "Corruption blooms!"

class bfa_boss_sporecaller_zancha : public CreatureScript
{
public:
    bfa_boss_sporecaller_zancha() : CreatureScript("bfa_boss_sporecaller_zancha")
    {}

    struct bfa_boss_sporecaller_zancha_AI : public BossAI
    {
        bfa_boss_sporecaller_zancha_AI(Creature* creature) : BossAI(creature, DATA_SPORECALLER_ZANCHA)
        {
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            introText = false;
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        bool introText;

        void MoveInLineOfSight(Unit* who)
        {
            if (!introText)
            {
                Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    if (Player* pPlayer = itr->GetSource())
                        if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 40.f))
                        {
                            SelectSoundAndText(me, 2);
                            introText = true;
                            return;
                        }
            }
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
                    me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(INTRO_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_INTRO);
                    break;
                case 3:
                    me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_KILL);
                    break;
                case 4:
                    me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_DEATH);
                    break;
                case 5:
                    me->Yell(SELECT_SPORE_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 6:
                    me->Yell(HARVEST_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_HARVEST);
                    break;
                case 7:
                    me->Yell(VOLATILE_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_VOLATILE);
                    break;
                }
            }
        }

        void Reste()
        {
            events.Reset();

            DespawnAurasWipe();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void JustDied(Unit*)
        {
            DespawnAurasWipe();
            SelectSoundAndText(me, 4);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            Reset();
            _DespawnAtEvade(15);
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(centerPlatform.GetPositionX(), centerPlatform.GetPositionY(), centerPlatform.GetPositionZ()) >= 30.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);
            events.ScheduleEvent(EVENT_SHOCKWAVE, TIMER_SHOCKWAVE);
            events.ScheduleEvent(EVENT_UPHEAVAL, TIMER_UPHEAVAL);
            events.ScheduleEvent(EVENT_SPAWN_SPORE, TIMER_SPAWN_SPORE);
            events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_SPAWN_VOLATILE_SPORE, TIMER_SPAWN_VOLATILE_SPORE);
        }

        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_FESTERING_HARVEST_DAMAGE:
                HandleFesteringHarvest();
                break;
            case SPELL_SHOCKWAVE:
            {
                std::list<Creature*> cList;
                me->GetCreatureListWithEntryInGrid(cList, NPC_SPORE_POD_TRIGGER, 5.0f);
                cList.remove_if(frontOfMe(me));
                if (!cList.empty())
                {
                    for (auto allspore : cList)
                    {
                        if(allspore->HasAura(SPELL_BOUNDLESS_ROT_AT) && me->isInFront(allspore, 3.14f / 4.0f))
                            allspore->RemoveAura(SPELL_BOUNDLESS_ROT_AT);
                    }
                    break;
                }
            }
            }
        }

        void DespawnAurasWipe()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_SPORE_POD_TRIGGER, 500.0f);
            if (!cList.empty())
                for (auto allspore : cList)
                {
                    allspore->RemoveAura(SPELL_BOUNDLESS_ROT_AT);
                }
        }

        void HandleFesteringHarvest()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_SPORE_POD_TRIGGER, 500.0f);
            if(!cList.empty())
                for (auto allspore : cList)
                {
                    allspore->CastSpell(allspore, SPELL_VOLATILE_POD_EXPLOSION_VISUAL, true);
                    allspore->RemoveAura(SPELL_BOUNDLESS_ROT_AT);
                }

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        player->CastSpell(player, SPELL_DECAYING_SPORE, true);
                    }
                }
        }

        void HandleSpawnSpore()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_SPORE_POD_TRIGGER, 500.0f);
            cList.remove_if(sporeActive());

            if (!cList.empty())
            {
                if (cList.size() >= 3)
                    cList.resize(3);

                for (auto allspore : cList)
                {
                    allspore->AddAura(SPELL_BOUNDLESS_ROT_AT, allspore);
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->IsInCombat())
                CheckCheaters();

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ENERGY_REGEN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 3);
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        events.ScheduleEvent(EVENT_FESTERING_HARVEST, 1000);
                        me->SetPower(POWER_ENERGY, 0);
                    }
                    events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
                    break;
                case EVENT_FESTERING_HARVEST:
                    SelectSoundAndText(me, 6);
                    me->CastSpell(me, SPELL_FESTERING_HARVEST_DAMAGE);
                    break;
                case EVENT_UPHEAVAL:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);

                    targets.remove_if(checkSpec());

                    if (!targets.empty())
                        if (targets.size() >= 2)
                            targets.resize(2);

                    for (auto target : targets)
                    {
                        me->CastSpell(target, SPELL_UPHEAVAL_TARGET);
                        std::ostringstream str;
                        str << "Sporecaller Zancha begins to cast |cFFF00000|h[Upheaval]|h|r on " << target->GetName();
                        me->TextEmote(str.str().c_str(), 0, true);
                    }

                    events.ScheduleEvent(EVENT_UPHEAVAL, TIMER_UPHEAVAL);
                    break;
                }
                case EVENT_SHOCKWAVE:
                    me->CastSpell(me, SPELL_SHOCKWAVE);
                    events.ScheduleEvent(EVENT_SHOCKWAVE, TIMER_SHOCKWAVE);
                    break;
                case EVENT_SPAWN_SPORE:
                    SelectSoundAndText(me, 5);
                    HandleSpawnSpore();
                    events.ScheduleEvent(EVENT_SPAWN_SPORE, TIMER_SPAWN_SPORE);
                    break;
                case EVENT_SPAWN_VOLATILE_SPORE:
                    SelectSoundAndText(me, 7);
                    for (uint8 i = 0; i < 6; ++i)
                    {
                        me->SummonCreature(NPC_VOLATILE_POD_TRIGGER, volatilePodsPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                    }
                    events.ScheduleEvent(EVENT_SPAWN_VOLATILE_SPORE, TIMER_SPAWN_VOLATILE_SPORE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_sporecaller_zancha_AI(creature);
    }
};

class bfa_npc_spore_pod : public CreatureScript
{
public:
    bfa_npc_spore_pod() : CreatureScript("bfa_npc_spore_pod")
    {}

    struct bfa_npc_spore_pod_AI : public ScriptedAI
    {
        bfa_npc_spore_pod_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;
        bool triggered;

        void Reset()
        {
            events.Reset();
            triggered = false;
        }

        void CheckPlayers()
        {
            if (me->HasAura(SPELL_BOUNDLESS_ROT_AT))
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster()) //gm check
                        {
                            if (player->GetDistance(me) <= 0.5f)
                            {
                                if (!triggered)
                                {
                                    triggered = true;
                                    player->CastSpell(player, SPELL_DECAYING_SPORE, true);
                                    me->CastSpell(me, SPELL_VOLATILE_POD_EXPLOSION_VISUAL, true);
                                    me->RemoveAura(SPELL_BOUNDLESS_ROT_AT);
                                }
                            }
                        }
                    }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            CheckPlayers();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_spore_pod_AI(creature);
    }
};

class bfa_npc_volatile_pod : public CreatureScript
{
public:
    bfa_npc_volatile_pod() : CreatureScript("bfa_npc_volatile_pod")
    {}

    struct bfa_npc_volatile_pod_AI : public ScriptedAI
    {
        bfa_npc_volatile_pod_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_VOLATILE_PODS_EXPLODE, 10 * IN_MILLISECONDS);
            me->DespawnOrUnsummon(12 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOLATILE_PODS_EXPLODE:
                {
                    float initialOrientation = frand(0.f, 2.f * float(M_PI));

                    for (uint8 i = 0; i < 6; ++i)
                    {
                        me->SetOrientation(initialOrientation);
                        me->CastSpell(nullptr, SPELL_VOLATILE_POD_AT, true);
                        initialOrientation += float(M_PI) / 3;
                    }

                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_volatile_pod_AI(creature);
    }
};

// 259718
class bfa_spell_upheaval : public SpellScriptLoader
{
public:
    bfa_spell_upheaval() : SpellScriptLoader("bfa_spell_upheaval") { }

    class bfa_spell_upheaval_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_upheaval_AuraScript);

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_UPHEAVAL);
            std::list<Creature*> cList;
            target->GetCreatureListWithEntryInGrid(cList, NPC_SPORE_POD_TRIGGER, 8.0f);
            if (!cList.empty())
                for (auto allspore : cList)
                {
                    allspore->RemoveAura(SPELL_BOUNDLESS_ROT_AT);
                }

        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_upheaval_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_upheaval_AuraScript();
    }
};

// 18227
class bfa_at_volatile_pod_explosion : public AreaTriggerEntityScript
{
public:
    bfa_at_volatile_pod_explosion() : AreaTriggerEntityScript("bfa_at_volatile_pod_explosion")
    {}

    struct bfa_at_volatile_pod_explosion_AI : public AreaTriggerAI
    {
        bfa_at_volatile_pod_explosion_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}

        void OnUnitEnter(Unit* unit) override
        {
            if(unit->IsPlayer())
                unit->CastSpell(unit, SPELL_DECAYING_SPORE, true);

        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new bfa_at_volatile_pod_explosion_AI(at);
    }
};

void AddSC_boss_sporecaller_zancha()
{
    new bfa_boss_sporecaller_zancha();
    new bfa_npc_spore_pod();
    new bfa_npc_volatile_pod();

    new bfa_at_volatile_pod_explosion();

    new bfa_spell_upheaval();
}
