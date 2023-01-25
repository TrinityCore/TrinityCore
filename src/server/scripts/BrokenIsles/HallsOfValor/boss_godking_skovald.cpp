#include "AreaTriggerAI.h"
#include "halls_of_valor.h"
#include "ScriptedGossip.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_RAGNAROK = 1,
    SAY_RAGNAROK_EMOTE = 2,
    SAY_EGIDA = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_ZERO_REGEN = 78725,
    SPELL_CONVERSATION = 193975, //Skovald Intro 

    SPELL_FELBLAZE_RUSH = 193658,
    SPELL_RAGNAROK = 193826,
    SPELL_RAGNAROK_DMG = 193827,
    SPELL_RAGNAROK_MOD = 202494,
    SPELL_AEGIS_SPAWN = 193940,
    SPELL_CLAIM_THE_AEGIS = 194112,
    SPELL_SAVAGE_BLADE = 193668,
    SPELL_INFERNAL_FLAMES_AURA = 193983,
    SPELL_INFERNAL_FLAMES_FIND_N = 194222, //Filter normal
    SPELL_INFERNAL_FLAMES_FIND_H = 207510, //Filter heroic+
    SPELL_INFERNAL_FLAMES_TRIG_AT = 193705,
    SPELL_INFERNAL_FLAMES_AT = 193704,
    SPELL_INFERNAL_FLAMES_TRIG_SUM = 207509,

    //Aegis
    SPELL_AEGIS_VISUAL_SHIELD = 193769,
    SPELL_AEGIS_OVERRIDE = 193783,

    //Kings
    SPELL_CALL_ANCESTOR = 200969,
    SPELL_WICKED_DAGGER = 199674,
    SPELL_UNRULY_YELL = 199726,
    SPELL_SEVER = 199652,
};

enum eEvents
{
    EVENT_INTRO_COMPLETE = 1,
    EVENT_FELBLAZE_RUSH = 2,
    EVENT_RAGNAROK = 3,
    EVENT_PICK_AEGIS = 4,
    EVENT_SAVAGE_BLADE = 5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
};

Position const kingsPos[4] =
{
    {2387.87f, 506.50f, 749.30f, 0.57f}, //NPC_KING_HALDOR  95843
    {2388.01f, 551.16f, 749.30f, 5.67f}, //NPC_KING_BJORN   97081
    {2409.10f, 490.69f, 749.30f, 1.16f}, //NPC_KING_RANULF  97083
    {2408.56f, 568.34f, 749.30f, 5.11f}, //NPC_KING_TOR     97084
};

uint32 OdynKings[4] =
{
    NPC_KING_HALDOR,
    NPC_KING_BJORN,
    NPC_KING_RANULF,
    NPC_KING_TOR
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
};

//95675
class boss_god_king_skovald : public CreatureScript
{
public:
    boss_god_king_skovald() : CreatureScript("boss_god_king_skovald") {}

    struct boss_god_king_skovaldAI : public BossAI
    {
        boss_god_king_skovaldAI(Creature* creature) : BossAI(creature, DATA_SKOVALD)
        {
            if (me->IsAlive())
            {
                me->SetVisible(false);
                intro = true;
                kingDiedCount = 0;
                SummonOdynKings();
            }
        }

        bool intro;
        bool aegisEvent;
        uint8 kingDiedCount;
        uint8 power, powerCounter;
        uint16 powerTimer;
        std::set<ObjectGuid> KingGUIDs;

        void Reset() override
        {
            _Reset();

            DoCast(me, SPELL_ZERO_REGEN, true);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetPower(POWER_ENERGY, 80);
            me->RemoveAurasDueToSpell(SPELL_RAGNAROK_MOD);
            aegisEvent = false;
            powerTimer = 1000;

            if (!intro)
            {
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_DEFENSIVE);

                if (auto odyn = instance->instance->GetCreature(instance->GetGuidData(DATA_ODYN)))
                    odyn->CastSpell(odyn, SPELL_AEGIS_SPAWN, true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO); //Give up the aegis or die!
            _JustEngagedWith();
            events.RescheduleEvent(EVENT_FELBLAZE_RUSH, 7000);
            events.RescheduleEvent(EVENT_SAVAGE_BLADE, 24000);
            DoCast(me, 202366, true); //Remove Odyn's Blessing - Speed buff
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void SummonOdynKings()
        {
            if (instance->GetData(DATA_SKOVALD_EVENT) == DONE)
                KingsEventComplete();
            else
            {
                for (uint8 i = 0; i < 4; i++)
                    me->SummonCreature(OdynKings[i], kingsPos[i]);
            }
        }

        void KingsEventComplete()
        {
            KingGUIDs.clear();
            me->SetVisible(true);
            me->SetPower(POWER_ENERGY, 80);
            me->GetMotionMaster()->MovePoint(1, 2411.03f, 528.72f, 748.99f);
            DoCast(me, SPELL_CONVERSATION, true);

            if (auto odyn = instance->instance->GetCreature(instance->GetGuidData(DATA_ODYN)))
            {
                odyn->AI()->Talk(1); // ??????????? - ????????? ???????
                odyn->CastSpell(odyn, SPELL_AEGIS_SPAWN, true);
            }
            if (instance->GetData(DATA_SKOVALD_EVENT) != DONE)
                instance->SetData(DATA_SKOVALD_EVENT, DONE);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (!intro)
                return;

            switch (summon->GetEntry())
            {
            case NPC_KING_HALDOR:
            case NPC_KING_BJORN:
            case NPC_KING_RANULF:
            case NPC_KING_TOR:
                kingDiedCount++;
                break;
            }

            if (kingDiedCount == 4)
                KingsEventComplete();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                events.RescheduleEvent(EVENT_INTRO_COMPLETE, 24000);
            }
            else if (id == 2)
            {
                events.DelayEvents(3000);
                DoCast(SPELL_CLAIM_THE_AEGIS);
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 193988)
            {
                if (auto target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                    me->SetFacingToObject(target);
                DoCast(me, SPELL_INFERNAL_FLAMES_AURA, true);
                aegisEvent = false;
                Talk(SAY_EGIDA);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_SAVAGE_BLADE:
                if (me->GetGUID() != target->GetGUID())
                    me->CastSpell(target, 193686, true);
                break;
            case SPELL_INFERNAL_FLAMES_FIND_N:
                if (!me->isInBack(target, 3.14f * 0.8f))
                    DoCast(target, SPELL_INFERNAL_FLAMES_TRIG_AT, true);
                break;
            case SPELL_INFERNAL_FLAMES_FIND_H:
                DoCast(target, SPELL_INFERNAL_FLAMES_TRIG_SUM, true);
                break;
            }
        }

        void DoAction(int32 const action) override
        {
            events.RescheduleEvent(EVENT_PICK_AEGIS, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !intro)
                return;

            events.Update(diff);

            if (me->IsInCombat())
            {
                if (powerTimer <= diff)
                {
                    powerTimer = 1000;
                    power = me->GetPower(POWER_ENERGY);

                    if (power < 100)
                    {
                        if (powerCounter < 2)
                        {
                            powerCounter++;
                            me->SetPower(POWER_ENERGY, power + 2);
                        }
                        else
                        {
                            powerCounter = 0;
                            me->SetPower(POWER_ENERGY, power + 1);
                        }
                    }
                    else if (!me->HasUnitState(UNIT_STATE_CASTING))
                    {
                        powerTimer = 4000;
                        events.RescheduleEvent(EVENT_RAGNAROK, 500);
                    }
                }
                else powerTimer -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING) || aegisEvent)
                return;


            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTRO_COMPLETE:
                    intro = false;
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_DEFENSIVE);
                    break;
                case EVENT_FELBLAZE_RUSH:
                    DoCast(SPELL_FELBLAZE_RUSH);
                    events.RescheduleEvent(EVENT_FELBLAZE_RUSH, urand(10, 26) * IN_MILLISECONDS);
                    break;
                case EVENT_RAGNAROK:
                    DoCast(SPELL_RAGNAROK);
                    Talk(SAY_RAGNAROK);
                    Talk(SAY_RAGNAROK_EMOTE);
                    break;
                case EVENT_PICK_AEGIS:
                    aegisEvent = true;
                    me->AttackStop();
                    if (auto aegis = me->FindNearestCreature(NPC_AEGIS_OF_AGGRAMAR, 60.0f))
                        me->GetMotionMaster()->MovePoint(2, aegis->GetPositionX(), aegis->GetPositionY(), aegis->GetPositionZ());
                    else
                    {
                        aegisEvent = false;
                        me->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                case EVENT_SAVAGE_BLADE:
                    me->CastSpell(me->GetVictim(),SPELL_SAVAGE_BLADE);
                    events.RescheduleEvent(EVENT_SAVAGE_BLADE, 24000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_god_king_skovaldAI(creature);
    }
};

//95843, 97081, 97083, 97084
class npc_generic_odyn_kings : public CreatureScript
{
public:
    npc_generic_odyn_kings() : CreatureScript("npc_generic_odyn_kings") {}

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case 1:
            if (Unit* owner = creature->GetOwner())
                owner->GetAI()->DoAction(ACTION_1);
            break;
        }
        return true;
    }

    struct npc_generic_odyn_kingsAI : public ScriptedAI
    {
        npc_generic_odyn_kingsAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        EventMap events;
        SummonList summons;
        std::set<uint32> spellIDs;
        uint8 splashed = 0;
        bool gotaura = false;
        InstanceScript* instance;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
            me->SetFaction(35);

            if (Unit* owner = me->GetOwner())
                owner->GetAI()->DoAction(ACTION_2);

            for (auto spellId : spellIDs)
                if (!me->HasAura(spellId))
                    DoCast(me, spellId, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.RescheduleEvent(EVENT_1, urand(24000, 27000)); // Call
            events.RescheduleEvent(EVENT_2, urand(16000, 18000)); // Dagger
            events.RescheduleEvent(EVENT_3, urand(3000, 5000));   // Yell
            events.RescheduleEvent(EVENT_4, urand(11000, 15000)); // Sever

            if (me->GetEntry() != NPC_KING_RANULF)
                Talk(0);

            DoCast(me, 202366, true); //Remove Odyn's Blessing - Speed buff
        }

        void JustDied(Unit* /*killer*/) override
        {
            summons.DespawnAll();

            Talk(1);

            if (me->GetEntry() == NPC_KING_TOR)
                me->CastSpell(me, 199614, true); // Bond of Kings
            if (me->GetEntry() == NPC_KING_RANULF)
                me->CastSpell(me, 199622, true); // Bond of Kings 
            if (me->GetEntry() == NPC_KING_BJORN)
                me->CastSpell(me, 199621, true); // Bond of Kings
            if (me->GetEntry() == NPC_KING_HALDOR)
                me->CastSpell(me, 199620, true); // Bond of Kings
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case 199614:
                spellIDs.insert(199590);
                break;
            case 199620:
                spellIDs.insert(199591);
                break;
            case 199621:
                spellIDs.insert(199592);
                break;
            case 199622:
                spellIDs.insert(199593);
                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case ACTION_1:
                ++splashed;
                if (splashed == 4)
                    if (instance && (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE))
                        instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 207733);
                break;
            case ACTION_2:
                splashed = splashed - 1;
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1: // Call
                    DoCast(SPELL_CALL_ANCESTOR);
                    events.RescheduleEvent(EVENT_1, urand(22000, 26000));
                    break;
                case EVENT_2: // Dagger
                    DoCast(SPELL_WICKED_DAGGER);
                    events.RescheduleEvent(EVENT_2, urand(16000, 18000));
                    break;
                case EVENT_3: // Yell
                    DoCast(SPELL_UNRULY_YELL);
                    break;
                case EVENT_4: // Sever
                    DoCast(SPELL_SEVER);
                    events.RescheduleEvent(EVENT_4, urand(11000, 15000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_generic_odyn_kingsAI(creature);
    }
};

//98364
class npc_skovald_aegis_of_aggramar : public CreatureScript
{
public:
    npc_skovald_aegis_of_aggramar() : CreatureScript("npc_skovald_aegis_of_aggramar") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->CastSpell(player, SPELL_AEGIS_OVERRIDE, true);
        creature->DespawnOrUnsummon();
        return true;
    }

    struct npc_skovald_aegis_of_aggramarAI : public ScriptedAI
    {
        npc_skovald_aegis_of_aggramarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* instance;

        bool click;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetTypeId() == TYPEID_PLAYER)
            {
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);

                if (Creature* skovald = instance->instance->GetCreature(instance->GetGuidData(DATA_SKOVALD)))
                {
                    if (instance->GetBossState(DATA_SKOVALD) == IN_PROGRESS && skovald->IsInCombat())
                        skovald->AI()->DoAction(true);
                    else
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }
                }
            }

            click = false;
            DoCast(me, SPELL_AEGIS_VISUAL_SHIELD, true);
            Talk(0); // ????? ???????????
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_CLAIM_THE_AEGIS)
            {
                DoCast(caster, 193988, true);
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skovald_aegis_of_aggramarAI(creature);
    }
};

//101326
class npc_skovald_honored_ancestor : public CreatureScript
{
public:
    npc_skovald_honored_ancestor() : CreatureScript("npc_skovald_honored_ancestor") {}

    struct npc_skovald_honored_ancestorAI : public ScriptedAI
    {
        npc_skovald_honored_ancestorAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetWalk(true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        }

        Unit* owner = nullptr;
        bool moveComplete;
        uint16 moveTimer;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            owner = summoner;
            DoCast(me, 199745, true); //Visual
            DoCast(me, 199738, true); //Visual
            moveTimer = 1000;
            moveComplete = false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!moveComplete)
            {
                if (moveTimer <= diff)
                {
                    if (!owner || !owner->IsInWorld() || !owner->IsAlive())
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }

                    if (me->GetDistance(owner) < 3.0f)
                    {
                        moveComplete = true;
                        me->DespawnOrUnsummon(3000);
                        DoCast(owner, 199747, true);
                        me->SetVisible(false);
                    }
                    else
                    {
                        if (!me->HasUnitState(UNIT_STATE_STUNNED))
                            me->GetMotionMaster()->MovePoint(1, owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ());
                    }
                    moveTimer = 1000;
                }
                else
                    moveTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skovald_honored_ancestorAI(creature);
    }
};

//104822
class npc_skovald_flame_of_woe : public CreatureScript
{
public:
    npc_skovald_flame_of_woe() : CreatureScript("npc_skovald_flame_of_woe") {}

    struct npc_skovald_flame_of_woeAI : public ScriptedAI
    {
        npc_skovald_flame_of_woeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 0.7f);
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            DoZoneInCombat(me, 100.0f);
            DoCast(me, 221093, true); //Consuming Flame - self dmg
            DoCast(me, 221094, true);
            events.RescheduleEvent(EVENT_1, 1000);
            events.RescheduleEvent(EVENT_2, 2000);
        }

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
                    events.RescheduleEvent(EVENT_1, 2000);
                    if (me->GetVictim() && me->GetVictim()->HasAura(193708))
                        break;
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                   //     DoResetThreat();
                        AttackStart(target);
                    //    me->AddThreat(target, 100000.0f);
                        DoCast(target, 193708, true);
                    }
                    break;
                case EVENT_2:
                    DoCast(me, SPELL_INFERNAL_FLAMES_AT, true);
                    events.RescheduleEvent(EVENT_2, 4000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skovald_flame_of_woeAI(creature);
    }
};

//193826
class spell_skovald_ragnarok : public SpellScriptLoader
{
public:
    spell_skovald_ragnarok() : SpellScriptLoader("spell_skovald_ragnarok") { }

    class spell_skovald_ragnarok_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skovald_ragnarok_AuraScript);

        uint16 m_checkTimer = 1500;

        void OnUpdate(AuraEffect const* aurEff)
        {

            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_RAGNAROK_DMG, true);
                caster->CastSpell(caster, SPELL_RAGNAROK_MOD, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skovald_ragnarok_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skovald_ragnarok_AuraScript();
    }
};

//193991
class spell_skovald_drop_aegis : public SpellScriptLoader
{
public:
    spell_skovald_drop_aegis() : SpellScriptLoader("spell_skovald_drop_aegis") { }

    class spell_skovald_drop_aegis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skovald_drop_aegis_SpellScript);

        void HandleScript(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            PreventHitEffect(EFFECT_0);
            WorldLocation* loc = GetHitDest();
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (instance->GetBossState(DATA_SKOVALD) == IN_PROGRESS)
                    caster->CastSpell(loc->GetPositionX(), loc->GetPositionY(), loc->GetPositionZ(), 193781, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_skovald_drop_aegis_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skovald_drop_aegis_SpellScript();
    }
};

//193983, 193783
class spell_skovald_aegis_remove : public SpellScriptLoader
{
public:
    spell_skovald_aegis_remove() : SpellScriptLoader("spell_skovald_aegis_remove") { }

    class spell_skovald_aegis_remove_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skovald_aegis_remove_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTarget())
                return;

            GetTarget()->CastSpell(GetTarget(), 193991, true);
        }

        void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (!GetCaster())
                return;

            if (Unit* attacker = dmgInfo.GetAttacker())
                if (attacker->GetDistance(GetCaster()->GetPosition()) < 5.0f && GetCaster()->isInBack(attacker, 3.14f * 0.8f))
                    absorbAmount = 0;
                else
                    absorbAmount = dmgInfo.GetDamage();
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_skovald_aegis_remove_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_skovald_aegis_remove_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_skovald_aegis_remove_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_skovald_aegis_remove_AuraScript::OnAbsorb, EFFECT_1);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skovald_aegis_remove_AuraScript();
    }
};

//193743
class spell_skovald_aegis_absorb : public SpellScriptLoader
{
public:
    spell_skovald_aegis_absorb() : SpellScriptLoader("spell_skovald_aegis_absorb") {}

    class spell_skovald_aegis_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skovald_aegis_absorb_AuraScript);

        void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (!GetCaster())
                return;

            if (auto attacker = dmgInfo.GetAttacker())
            {
                Position pos;
                if (pos.HasInArc(3.14f * 1.4f, attacker))
                    absorbAmount = dmgInfo.GetDamage();
                else
                    absorbAmount = 0;
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_skovald_aegis_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_skovald_aegis_absorb_AuraScript::OnAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skovald_aegis_absorb_AuraScript();
    }
};

//202711
class spell_skovald_aegis_check_cast : public SpellScriptLoader
{
public:
    spell_skovald_aegis_check_cast() : SpellScriptLoader("spell_skovald_aegis_check_cast") {}

    class spell_skovald_aegis_check_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skovald_aegis_check_cast_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (instance->GetBossState(DATA_SKOVALD) != IN_PROGRESS)
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_skovald_aegis_check_cast_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skovald_aegis_check_cast_SpellScript();
    }
};

void AddSC_boss_godking_skovald()
{
    new boss_god_king_skovald();
    new npc_generic_odyn_kings();
    new npc_skovald_aegis_of_aggramar();
    new npc_skovald_honored_ancestor();
    new npc_skovald_flame_of_woe();
    new spell_skovald_ragnarok();
    new spell_skovald_drop_aegis();
    new spell_skovald_aegis_remove();
    new spell_skovald_aegis_absorb();
    new spell_skovald_aegis_check_cast();
}
