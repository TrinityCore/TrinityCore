#include "ScriptMgr.h"
#include "halls_of_origination.h"

// Different ids for 3 stages
static const uint32 SPELL_CELESTIAL_CALL[3] = {74362, 74355, 74364};
static const uint32 SPELL_ASTRAL_RAIN[3] = {74134, 74365, 74371};
static const uint32 SPELL_VEIL_OF_SKY[3] = {74133, 74372, 74373};
static const uint32 NPC_AVATAR[3] = {39720, 39721, 39722};

enum Events
{
    EVENT_CELESTIAL_CALL                = 1,
    EVENT_ASTRAL_RAIN,
    EVENT_VEIL_OF_SKY,
    EVENT_SUPERNOVA
};

enum Entities
{
    NPC_ASTRAL_RAIN                 = 39720,
    NPC_CELESTIAL_CALL              = 39721,
    NPC_VEIL_OF_SKY                 = 39722,
    NPC_SPATIAL_FLUX                = 39612
};

enum Misc
{
    DATA_RAIN,
    DATA_CALL,
    DATA_VEIL,

    // Isiset
    SPELL_SUPERNOVA                     = 74136,
    DISPLAYID_INVISIBLE                 = 11686,

    // Trash
    SPELL_ENERGY_FLUX_SUMMON            = 74041,
    SPELL_ENERGY_FLUX_BEAM              = 74043,
    SPELL_ENERGY_FLUX_SUMMON_2          = 74042
};

enum Quotes
{
    SAY_AGGRO,
    SAY_DEATH,
    SAY_SLAY,
    SAY_SUPERNOVA,
    EMOTE_SUPERNOVA
};

class boss_isiset : public CreatureScript
{
    struct boss_isisetAI : public BossAI
    {
        boss_isisetAI(Creature * creature) : BossAI(creature, DATA_ISISET) {}

        void Reset() override
        {
            stage = 0;
            split = false;
            memset(&abilities, true, sizeof(abilities));
            me->RestoreDisplayId();
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            _Reset();
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if(split)
                damage = 0;
            else if(stage < 2)
            {
                if(me->HealthBelowPctDamaged(stage ? 33 : 66, damage))
                {
                    ++stage;
                    split = true;
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAuras();
                    me->StopMoving();
                    me->SetDisplayId(DISPLAYID_INVISIBLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                    // summon avatars
                    Position pos;
                    for (int i=0; i<3; ++i)
                    {
                        if(abilities[i])
                        {
                            pos = me->GetNearPosition(10.0f, float((2*M_PI)/3)*i);
                            me->SummonCreature(NPC_AVATAR[i], pos, TEMPSUMMON_DEAD_DESPAWN);
                        }
                    }

                }
            }
        }

        void JustDied(Unit* ) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void KillerUnit(Unit * )
        {
            Talk(SAY_SLAY);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_CELESTIAL_CALL, urand(5000, 8000));
            events.ScheduleEvent(EVENT_ASTRAL_RAIN, urand(10000, 12000));
            events.ScheduleEvent(EVENT_VEIL_OF_SKY, urand(8000, 10000));
            events.ScheduleEvent(EVENT_SUPERNOVA, urand(15000, 20000));
            me->SummonCreature(NPC_SPATIAL_FLUX, -482.35f, 414.21f, 343.94f, 4.27f);
        }

        void SummonedCreatureDies(Creature* creature, Unit* /*killer*/) override
        {
            if(split)
            {
                switch(creature->GetEntry())
                {
                case NPC_ASTRAL_RAIN:
                    abilities[DATA_RAIN] = false;
                    events.CancelEvent(EVENT_ASTRAL_RAIN);
                    break;
                case NPC_CELESTIAL_CALL:
                    abilities[DATA_CALL] = false;
                    events.CancelEvent(EVENT_CELESTIAL_CALL);
                    break;
                case NPC_VEIL_OF_SKY:
                    abilities[DATA_VEIL] = false;
                    events.CancelEvent(EVENT_VEIL_OF_SKY);
                    break;
                default:
                    return;
                }

                for(int i=0; i<3; ++i)
                    if(Creature * avatar = me->FindNearestCreature(NPC_AVATAR[i], 200.0f))
                        avatar->DespawnOrUnsummon();

                split = false;
                creature->DespawnOrUnsummon();
                me->RestoreDisplayId();
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                if(Unit * victim = me->GetVictim())
                    DoStartMovement(victim);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim() || split)
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_CELESTIAL_CALL:
                    DoCast(SPELL_CELESTIAL_CALL[stage]);
                    events.ScheduleEvent(EVENT_CELESTIAL_CALL, urand(10000, 20000));
                    break;
                case EVENT_VEIL_OF_SKY:
                    DoCast(me, SPELL_VEIL_OF_SKY[stage], true);
                    events.ScheduleEvent(EVENT_VEIL_OF_SKY, urand(50000, 65000));
                    break;
                case EVENT_ASTRAL_RAIN:
                    DoCast(SPELL_ASTRAL_RAIN[stage]);
                    events.ScheduleEvent(EVENT_ASTRAL_RAIN, stage == 2 ? 50000 : urand(15000, 20000));
                    break;
                case EVENT_SUPERNOVA:
                    Talk(SAY_SUPERNOVA);
                    Talk(EMOTE_SUPERNOVA);
                    DoCast(SPELL_SUPERNOVA);
                    events.ScheduleEvent(EVENT_SUPERNOVA, urand(20000, 25000));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        uint8 stage;
        bool split;
        bool abilities[3];
    };

public:
    boss_isiset() : CreatureScript("boss_isiset") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_isisetAI(creature);
    }
};

class FacingCheck
{
public:
    FacingCheck(WorldObject* caster) : _caster(caster) { }

    bool operator() (WorldObject* unit)
    {
        Position pos = _caster->GetPosition();
        return !unit->HasInArc(static_cast<float>(M_PI), &pos);
    }

private:
    WorldObject* _caster;
};

class spell_isiset_supernova : public SpellScriptLoader
{
public:
    spell_isiset_supernova() : SpellScriptLoader("spell_isiset_supernova") { }

    class spell_isiset_supernova_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_supernova_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(FacingCheck(GetCaster()));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_isiset_supernova_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_isiset_supernova_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_supernova_SpellScript();
    }
};

class npc_spatial_flux : public CreatureScript
{
    struct npc_spatial_fluxAI : public ScriptedAI
    {
        npc_spatial_fluxAI(Creature * creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            summonTimer = 10000;
        }

        void JustSummoned(Creature* summon) override
        {
            //if(Unit * victim = ObjectAccessor::GetUnit(*me, targetGUID))
            if(Unit * victim = summon->SelectNearestPlayer(20.0f))
            {
                summon->GetMotionMaster()->Clear();
                summon->GetMotionMaster()->MoveFollow(victim, 0.0f, 0.0f);
                summon->SetReactState(REACT_PASSIVE);
            }
            DoCast(SPELL_ENERGY_FLUX_BEAM);
        }

        void UpdateAI(uint32 diff) override
        {
            if(summonTimer <= diff)
            {
                DoCast(SPELL_ENERGY_FLUX_SUMMON);
                summonTimer = 10000;
            }else summonTimer -= diff;
        }

    private:
        uint32 summonTimer;
    };

public:
    npc_spatial_flux() : CreatureScript("npc_spatial_flux") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spatial_fluxAI(creature);
    }
};

void AddSC_boss_isiset()
{
    new boss_isiset();
    new spell_isiset_supernova();
    new npc_spatial_flux();
}
