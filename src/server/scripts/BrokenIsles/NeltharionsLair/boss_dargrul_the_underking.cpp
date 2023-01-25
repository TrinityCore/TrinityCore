#include "neltharions_lair.h"
#include "GameObject.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_EMOTE = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_GAIN_ENERGY = 201444,
    SPELL_CONVERSATION_01 = 201665, //SPELL_MAGMA_SCULPTOR
    SPELL_CONVERSATION_02 = 201666, //SPELL_MAGMA_SCULPTOR
    SPELL_MAGMA_SCULPTOR = 200637,
    SPELL_LANDSLIDE = 200700,
    SPELL_LANDSLIDE_MISSILE = 200722,
    SPELL_CRYSTAL_WALL = 200551,
    SPELL_MAGMA_WAVE = 200404,
    SPELL_MAGMA_WAVE_AT = 200418,
    SPELL_MAGMA_WAVE_DMG_AOE = 217090,
    SPELL_MOLTEN_CRASH = 200732,

    //Heroic
    SPELL_MAGMA_BREAKER_DARGRUL = 216368,
    SPELL_LAVA_GEYSER_SUM = 216373,
    SPELL_LAVA_GEYSER_AT = 216385,
    SPELL_FLAME_GOUT = 216374,

    SPELL_CONVERSATION_03 = 201663,
    SPELL_CONVERSATION_04 = 201659,
    SPELL_CONVERSATION_05 = 201661, //SPELL_MAGMA_WAVE

    SPELL_SUM_PILLAR_CREATION = 213589,

    //Trash
    SPELL_FIXATE_PLR = 200154,
    SPELL_COLLISION_AT = 188197,
    SPELL_MAGMA_BREAKER = 209926,
    SPELL_MAGMA_BREAKER_AURA = 209920,
    SPELL_RISING_INFERNO = 216369,

    SPELL_CRYSTAL_BLOCKER_AT = 200367,
    SPELL_CRYSTAL_WALL_SUM_GO = 209964, //GO DOOR
};

enum eEvents
{
    EVENT_MAGMA_SCULPTOR = 1,
    EVENT_LANDSLIDE = 2,
    EVENT_CRYSTAL_WALL = 3,
    EVENT_MOLTEN_CRASH = 4,

    //Heroic
    EVENT_LAVA_GEYSER = 5,

    EVENT_3,
    EVENT_2,
    EVENT_1,
};

//91007
struct boss_dargrul_the_underking : public BossAI
{
    boss_dargrul_the_underking(Creature* creature) : BossAI(creature, DATA_DARGRUL)
    {
        me->SetMaxPower(POWER_MANA, 64);
    }

    std::list<ObjectGuid> listGuid;
    bool introDone = false;
    uint8 rand = 0;
    uint16 magmaTimer = 0;

    void Reset() override
    {
        _Reset();
        me->RemoveAurasDueToSpell(SPELL_GAIN_ENERGY);
        me->SetPower(POWER_MANA, 0);
        magmaTimer = 2000;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO); //Yes. TRY to take the hammer from me!
        _JustEngagedWith();
        DoCast(me, SPELL_GAIN_ENERGY, true);

        if (me->GetMap()->GetDifficultyID() != DIFFICULTY_LFR && me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
            DoCast(me, SPELL_MAGMA_BREAKER_DARGRUL, true);

        events.RescheduleEvent(EVENT_MAGMA_SCULPTOR, 10000);
        events.RescheduleEvent(EVENT_LANDSLIDE, 16000);
        events.RescheduleEvent(EVENT_CRYSTAL_WALL, 6000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!introDone && me->IsWithinDistInMap(who, 115.0f))
        {
            who->CastSpell(who, 209698, true);
            introDone = true;
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_LANDSLIDE)
        {
            Position pos;
            float angle;
            for (uint8 i = 0; i < 100; ++i)
            {
                angle = frand(-0.17f, 0.17f);
                me->GetNearPosition(i, angle);
                me->CastSpell(pos, SPELL_LANDSLIDE_MISSILE, true);
            }
        }
    }

    void DoAction(int32 const action) override
    {
        if (me->GetMap()->GetDifficultyID() != DIFFICULTY_LFR && me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
            events.RescheduleEvent(EVENT_LAVA_GEYSER, 1000);
    }

    bool GetObjectData(ObjectGuid const& guid)
    {
        bool find = false;

        for (auto targetGuid : listGuid)
            if (targetGuid == guid)
                find = true;

        if (!find)
            listGuid.push_back(guid);

        return find;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
        {
            if (magmaTimer <= diff)
            {
                magmaTimer = 2000;

                    if (me->HasAura(SPELL_MAGMA_WAVE))
                        DoCast(me, SPELL_MAGMA_WAVE_DMG_AOE, true);
            }
            else
                magmaTimer -= diff;
            return;
        }

        if (me->GetPositionZ() > -205.0f)
        {
            EnterEvadeMode();
            return;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MAGMA_SCULPTOR:
                rand = urand(0, 1);
                DoCast(me, rand ? SPELL_CONVERSATION_01 : SPELL_CONVERSATION_02, true);
                DoCast(SPELL_MAGMA_SCULPTOR);
                events.RescheduleEvent(EVENT_MAGMA_SCULPTOR, 70000);
                break;
            case EVENT_LANDSLIDE:
                listGuid.clear();
                DoCast(SPELL_LANDSLIDE);
                events.RescheduleEvent(EVENT_LANDSLIDE, 16000);
                events.RescheduleEvent(EVENT_MOLTEN_CRASH, 3000);
                break;
            case EVENT_CRYSTAL_WALL:
                DoCast(SPELL_CRYSTAL_WALL);
                events.RescheduleEvent(EVENT_CRYSTAL_WALL, 22000);
                break;
            case EVENT_MOLTEN_CRASH:
                DoCastVictim(SPELL_MOLTEN_CRASH);
                break;
            case EVENT_LAVA_GEYSER:
                DoCast(SPELL_LAVA_GEYSER_SUM);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//101476
struct npc_dargrul_molten_charskin : public ScriptedAI
{
    npc_dargrul_molten_charskin(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    EventMap events;
    ObjectGuid playerGuid;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 100.0f);

        if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
            DoCast(me, SPELL_RISING_INFERNO, true);
        else
            DoCast(me, SPELL_MAGMA_BREAKER_AURA, true);

        events.RescheduleEvent(EVENT_1, 2000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->RemoveAurasDueToSpell(SPELL_MAGMA_BREAKER_AURA);
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_FIXATE_PLR)
        {
            playerGuid = target->GetGUID();
            AttackStart(target);
            me->ClearUnitState(UNIT_STATE_CASTING);
        }
    }

    //bool checkPlayers()
    //{
    //    std::list<ThreatReference*> threatList = me->GetThreatManager().GetUnsortedThreatList();
    //    if (threatList.size() > 1)
    //        return true;

    //    return false;
    //}

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                Unit* player = me->GetVictim();
                if (!player || !player->IsAlive() || !player->HasAura(SPELL_FIXATE_PLR))
                {
                    if (me->GetOwner())
                        if (Creature* summoner = me->GetOwner()->ToCreature())
                                me->AttackStop();
                                me->CastSpell(SPELL_FIXATE_PLR, TriggerCastFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS));
                            
                }
                else
                    AttackStart(player);
                events.RescheduleEvent(EVENT_1, 2000);
                break;
            }
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//101593
struct npc_dargrul_crystal_wall : public ScriptedAI
{
    npc_dargrul_crystal_wall(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
    }

    bool despawn = false;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        if (!summoner->IsInCombat())
        {
            me->DespawnOrUnsummon();
            return;
        }

        DoCast(me, SPELL_CRYSTAL_BLOCKER_AT, true);
        DoCast(me, SPELL_CRYSTAL_WALL_SUM_GO, true);
    }
    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == 200721 || spell->Id == 209947)
            Despawn();
    }

    void Despawn()
    {
        if (despawn)
            return;

        despawn = true;

        me->DespawnOrUnsummon(200);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        damage = 0;
    }

    void UpdateAI(uint32 diff) override {}
};

//108926
struct npc_dargrul_lava_geyser : public ScriptedAI
{
    npc_dargrul_lava_geyser(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_LAVA_GEYSER_AT, true);
        DoCast(me, SPELL_FLAME_GOUT, true);
    }

    void UpdateAI(uint32 diff) override {}
};

//102253
struct npc_nl_understone_demolisher : public ScriptedAI
{
    npc_nl_understone_demolisher(Creature* creature) : ScriptedAI(creature) {}

    ObjectGuid playerGuid;
    EventMap events;
    uint32 healthPct = 70;

    void Reset() override
    {
        events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (HealthBelowPct(healthPct))
        {
            healthPct = 0;
            me->AttackStop();
            me->CastSpell(me, 188587);
            events.RescheduleEvent(EVENT_1, 2500);
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_FIXATE_PLR)
        {
            playerGuid = target->GetGUID();
            AttackStart(target);
            me->ClearUnitState(UNIT_STATE_CASTING);
        }
    }

    //bool checkPlayers()
    //{
    //    std::list<ThreatReference*> threatList = me->GetThreatManager().GetUnsortedThreatList();
    //    if (threatList.size() > 1)
    //        return true;

    //    return false;
    //}

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                me->SetReactState(REACT_AGGRESSIVE);
                Unit* player = me->GetVictim();
                if (!player || !player->IsAlive() || !player->HasAura(SPELL_FIXATE_PLR))
                {
                    if (Unit* plrTarget = SelectTarget(SELECT_TARGET_RANDOM, 80.0f, true, false))
                    {
                        playerGuid.Clear();
                        me->AttackStop();
                        me->CastSpell(plrTarget, SPELL_FIXATE_PLR, TriggerCastFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS));
                    }
                }
                else
                    AttackStart(player);
                events.RescheduleEvent(EVENT_1, 2000);
                break;
            }
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102295 trash
struct npc_emberhusk_dominator : public ScriptedAI
{
    npc_emberhusk_dominator(Creature* creature) : ScriptedAI(creature)
    {
        if (me->GetEntry() == 102295)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AttackStop();
        }
        me->SetReactState(REACT_AGGRESSIVE);
    }

    EventMap events;


    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, 500);
        events.RescheduleEvent(EVENT_2, urandms(10, 11));
        events.RescheduleEvent(EVENT_3, 3000);
    }

    void Reset() override
    {
        events.Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                if (me->GetEntry() == 102295)
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, 201953, true);
                events.RescheduleEvent(EVENT_1, 3000);
                break;
            }
            case EVENT_2:
            {
                if (me->GetEntry() == 102295)
                    Talk(0);
                if (me->GetEntry() == 102287)
                    DoCast(201983);
                events.RescheduleEvent(EVENT_2, urandms(20, 21));
                break;
            }
            case EVENT_3:
            {
                if (me->GetEntry() == 102287)
                    DoCast(226406);
                events.RescheduleEvent(EVENT_3, urandms(10, 13));
                break;
            }
            }
        }
        if (me->GetEntry() == 102287)
            DoMeleeAttackIfReady();
    }
};

//201444
class spell_dargrul_gain_energy : public AuraScript
{
    PrepareAuraScript(spell_dargrul_gain_energy);

    void OnTick(AuraEffect const* aurEff)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        if (caster->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (caster->GetPower(POWER_MANA) >= 64)
        {
            caster->CastSpell(caster, SPELL_CONVERSATION_05, true);
            caster->CastSpell(caster, SPELL_MAGMA_WAVE_AT);
            //caster->m_Events.AddEvent(new DelayCastEvent(*caster, caster->GetGUID(), SPELL_MAGMA_WAVE, false), caster->m_Events.CalculateTime(500));
            caster->AI()->DoAction(true);
            if (Creature* target = caster->FindNearestCreature(91007, 50, true))
                target->AI()->Talk(SAY_EMOTE);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dargrul_gain_energy::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

//209920, 216368
class spell_dargrul_magma_breaker : public AuraScript
{
    PrepareAuraScript(spell_dargrul_magma_breaker);

    void OnTick(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        if (GetCaster()->isMoving())
            GetCaster()->CastSpell(GetCaster(), SPELL_MAGMA_BREAKER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dargrul_magma_breaker::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//200404, 217090
class spell_dargrul_magma_wave_filter : public SpellScript
{
    PrepareSpellScript(spell_dargrul_magma_wave_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        if (targets.empty())
            return;

        std::list<GameObject*> goList;
        GetCaster()->GetGameObjectListWithEntryInGrid(goList, GO_CRYSTAL_WALL_COLLISION, 100.0f);
        if (!goList.empty())
            for (std::list<GameObject*>::const_iterator itr = goList.begin(); itr != goList.end(); ++itr)
                targets.remove_if(WallCheck(GetCaster(), (*itr)));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dargrul_magma_wave_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

private:
    class WallCheck
    {
    public:
        WallCheck(Unit* searcher, GameObject* go) : _searcher(searcher), _go(go) {}

        bool operator()(WorldObject* unit)
        {
            return (_go->IsInBetween(_searcher, unit, 4.0f));
        }

    private:
        Unit* _searcher;
        GameObject* _go;
    };
};

//200721
class spell_dargrul_landslide_filter : public SpellScript
{
    PrepareSpellScript(spell_dargrul_landslide_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (auto caster = GetCaster()->ToCreature())
        {
            for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                targets.remove(*itr++);
        }
    }

    void FilterTargetsEntry(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || object->GetEntry() != NPC_CRYSTAL_WALL_STALKER || object->GetDistance(*GetExplTargetDest()) >= 3.0f)
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dargrul_landslide_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dargrul_landslide_filter::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dargrul_landslide_filter::FilterTargetsEntry, EFFECT_2, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

void AddSC_boss_dargrul_the_underking()
{
    RegisterCreatureAI(boss_dargrul_the_underking);
    RegisterCreatureAI(npc_dargrul_molten_charskin);
    RegisterCreatureAI(npc_dargrul_crystal_wall);
    RegisterCreatureAI(npc_dargrul_lava_geyser);
    RegisterCreatureAI(npc_emberhusk_dominator);
    RegisterCreatureAI(npc_nl_understone_demolisher);
    RegisterAuraScript(spell_dargrul_gain_energy);
    RegisterAuraScript(spell_dargrul_magma_breaker);
    RegisterSpellScript(spell_dargrul_magma_wave_filter);
    RegisterSpellScript(spell_dargrul_landslide_filter);
}
