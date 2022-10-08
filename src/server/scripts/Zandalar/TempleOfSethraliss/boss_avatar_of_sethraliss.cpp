#include "ScriptMgr.h"
#include "temple_of_sethraliss.h"
#include "ScriptedGossip.h"

enum Misc
{
    ENCOUNTER_ID = 2127,
};

enum Texts
{
    SAY_OBJECTIVE = 0,
    SAY_EFFECTIVE_HEAL = 1,
    SAY_INTRO = 5,
    SAY_RESTORE = 6,
    SAY_THANK_YOU = 4,
    SAY_JOIN_COMBAT = 3,
};

enum Spells
{
    SPELL_EMPOWERMENT = 269670,
    SPELL_LIFE_FORCE = 274149,
    SPELL_LIFE_FORCE_HEAL = 274149,
    SPELL_JOLT = 279000,
    SPELL_TAINT_DEBUFF = 267944,
  
    SPELL_TAINT_CHANNEL = 273677,
    SPELL_TAINT_VISUAL = 267759,
  
    SPELL_PULSE = 268024,
    SPELL_PLAGUE = 269686,
};

enum Events
{
    EVENT_PLAGUE_DOCTOR = 1,
    EVENT_HEART_GUARDIAN,
    EVENT_TOAD,
    EVENT_JOLT,
    EVENT_CHECK_PLAYERS
};

const Position universal_spawn_pos = { 4140.0f, 3659.0f, -43.0f, 0.59f };
const Position middle_of_room_pos = { 4161.0f, 3673.0f, -34.0f, 3.69f };

//133392
struct boss_avatar_of_sethraliss : public BossAI
{
    boss_avatar_of_sethraliss(Creature* creature) : BossAI(creature, DATA_AVATAR_OF_SETHRALISS) { }

    void Reset() override
    {
        BossAI::Reset();
        _JustReachedHome();
        instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, NOT_STARTED);
        this->wavecount = 0;           
        me->RestoreFaction();
        std::list<Creature*> c_li;
        me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
        for (auto & hoodoo : c_li)
        {
            if (hoodoo->IsAlive())
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, hoodoo);
            }
            else
            {
                hoodoo->Respawn(true);
                hoodoo->AI()->Reset();
            }
        }
        me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN);
        me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD);
        me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);       
    }

    void EnterCombat(Unit* who) override
    {
        instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, IN_PROGRESS);
        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1s);
        events.ScheduleEvent(EVENT_HEART_GUARDIAN, 5s);
        events.ScheduleEvent(EVENT_TOAD, 25s);
        if (IsHeroic() || IsMythic()) 
            events.ScheduleEvent(EVENT_PLAGUE_DOCTOR, 10s);
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        me->ForcedDespawn(0, 5s);
        me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN);
        me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD);
        me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR);        
    }

    void DamageTaken(Unit* done_by, uint32& dmg) override
    {
        if (me->HealthAbovePct(99))
        {
            me->CastStop();
            instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, DONE);
            _JustReachedHome();
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            instance->SendBossKillCredit(ENCOUNTER_ID);
            std::list<Player*> p_li;
            me->GetPlayerListInGrid(p_li, 150.0f);
            for (auto & players : p_li)
            {
                players->KilledMonsterCredit(me->GetEntry());
                players->ClearInCombat();
            }
            Talk(SAY_THANK_YOU);
            me->SummonGameObject(GO_SETHRALISS_TREASURE, 4149.73f, 3665.59f, -43.0365f, 3.68391f, QuaternionData(0, 0, -0.963461f, 0.267849f), false);
            if (IsMythic() && instance->IsChallengeModeStarted())
            {
                me->SummonGameObject(GO_CHALLENGERS_CACHE_SETHRALISS, 4185.0f, 3688.0f, -43.0f, 3.84f, QuaternionData(), false);
            }
            me->DespawnCreaturesInArea(NPC_HOODOO_HEXER, 125.0f);
            me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN, 125.0f);
            me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD, 125.0f);
            me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR, 125.0f);
        }

        if (me->HealthBelowPctDamaged(80, dmg) && (this->wavecount = 0))
        {
            wavecount = 1;
            std::list<Creature*> c_li;
            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
            for (auto& hoodoo : c_li)
            {
                if (hoodoo->IsAlive())
                {
                    return;
                }
                else
                {
                    hoodoo->Respawn(true);
                    hoodoo->AI()->Reset();
                }
            }
        }

        if (me->HealthBelowPctDamaged(70, dmg) && (this->wavecount = 1))
        {
            wavecount = 2;
            std::list<Creature*> c_li;
            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
            for (auto& hoodoo : c_li)
            {
                if (hoodoo->IsAlive())
                {
                    return;
                }
                else
                {
                    hoodoo->Respawn(true);
                    hoodoo->AI()->Reset();
                }
            }
        }

        if (me->HealthBelowPctDamaged(40, dmg) && (this->wavecount = 2))
        {
            wavecount = 3;
            std::list<Creature*> c_li;
            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
            for (auto & hoodoo : c_li)
            {
                if (hoodoo->IsAlive())
                {
                    return;
                }
                else
                {
                    hoodoo->Respawn(true);
                    hoodoo->AI()->Reset();
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, hoodoo);
                    std::list<Creature*> c_li;
                    me->GetCreatureListWithEntryInGrid(c_li, NPC_AVATAR_OF_SETHRALISS, 100.0f);
                    for (auto& avatar : c_li)
                    if (avatar->IsAlive())
                    {    
                        me->CastSpell(avatar, SPELL_TAINT_CHANNEL);
                        me->CastSpell(avatar, SPELL_TAINT_VISUAL);
                    }
                }
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_JOLT:
        {
            std::list<Creature*> c_li;
            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
            for (auto& hoodoo : c_li)
            me->AI()->DoCast(hoodoo, SPELL_JOLT);
            events.Repeat(3s);
            break;
        }

        case EVENT_CHECK_PLAYERS:
        {
            std::list<Player*> p_li;
            me->GetPlayerListInGrid(p_li, 150.0f);
            for (auto & players : p_li)
            if (players->IsAlive())
            {
                return;
            }
            else
            {
                BossAI::Reset();
            }
            events.Repeat(3s);
            break;
        }

        case EVENT_HEART_GUARDIAN:
             me->SummonCreature(NPC_HEART_GUARDIAN, universal_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
             events.Repeat(15s);
             break;

        case EVENT_PLAGUE_DOCTOR:
             me->SummonCreature(NPC_PLAGUE_DOCTOR, universal_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
             events.Repeat(20s);
             break;

        case EVENT_TOAD:
            for (uint8 i = 0; i < 6; i++)
            {
                me->SummonCreature(NPC_PLAGUE_TOAD, me->GetRandomPoint(middle_of_room_pos, 30.0f));
            }
            events.Repeat(25s);
            break;
        }        
    }

    void JustSummoned(Creature* summon)
    {
        switch (summon->GetEntry())
        {
        case NPC_PLAGUE_TOAD:
            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                summon->AI()->AttackStart(tar);
            }      
            break;

        case NPC_HEART_GUARDIAN:
            summon->RemoveAura(274609);
            summon->RemoveAura(231201);
            summon->RemoveAura(274603);  
            summon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            summon->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            summon->SetFaction(14);
            summon->AI()->DoZoneInCombat();
            break;

        default:
            break;
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) 
    { 
        if (instance->GetBossState(DATA_AVATAR_OF_SETHRALISS == NOT_STARTED))
        {
            instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, IN_PROGRESS);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->SetHealth(me->GetMaxHealth() * 0.10f);
            me->SetFaction(FACTION_MASK_PLAYER);
            events.ScheduleEvent(EVENT_JOLT, 100ms);

            std::list<Creature*> c_li;
            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
            for (auto & hoodoo : c_li)
            {
                if (hoodoo->IsAlive())
                {
                    hoodoo->SetVisible(true);
                    hoodoo->SetReactState(REACT_DEFENSIVE);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, hoodoo);
                }
            }

            if (Creature* avatar = instance->GetCreature(NPC_AVATAR_OF_SETHRALISS))
            {
                avatar->AI()->Talk(SAY_INTRO);
                _EnterCombat();

                avatar->GetScheduler().Schedule(6s, [this, avatar] (TaskContext context)
                {
                    avatar->AI()->Talk(SAY_OBJECTIVE);
                });

                avatar->GetScheduler().Schedule(8s, [this, avatar] (TaskContext context)
                {
                    avatar->AI()->Talk(SAY_RESTORE);                    
                });
            }          
        }
    }

private:
    uint8 wavecount;
    uint8 encouter_done;
};

enum HoodooHexerSpells
{
    SPELL_LAVA_BURST = 274642,
    SPELL_FLAME_SHOCK = 268013
};

enum HoodooHexerEvents
{
    EVENT_LAVA_BURST = 1,
    EVENT_FLAME_SHOCK
};

//135552
struct npc_hoodoo_hexer : public ScriptedAI
{
    npc_hoodoo_hexer(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        std::list<Creature*> c_li;
        me->GetCreatureListWithEntryInGrid(c_li, NPC_AVATAR_OF_SETHRALISS, 100.0f);
        for (auto & avatar : c_li)
        if (avatar->IsAlive())
        {            
            me->CastSpell(avatar, SPELL_TAINT_CHANNEL);
            me->CastSpell(avatar, SPELL_TAINT_VISUAL);
        }
        me->SetVisible(false);
    }

    void EnterCombat(Unit* u) override
    {        
        if (IsHeroic() || IsMythic())
        {
            events.ScheduleEvent(EVENT_FLAME_SHOCK, 1s);
        }
        events.ScheduleEvent(EVENT_LAVA_BURST, 3s);
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_FLAME_SHOCK:
            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                DoCast(tar, SPELL_FLAME_SHOCK);
            }
            events.Repeat(15s);
            break;

        case EVENT_LAVA_BURST:
            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
            {
                DoCast(tar, SPELL_LAVA_BURST);
            }
            events.Repeat(3s);
            break;

        default:
            break;
        }
    }
};

//137233
struct npc_plague_toad_137233 : public ScriptedAI
{
    npc_plague_toad_137233(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* u) override
    {
       DoCastVictim(SPELL_PLAGUE);
    }
};

//142929
struct npc_energy_fragment : public ScriptedAI
{
    npc_energy_fragment(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void sGossipHello(Player* player) 
    { 
        CloseGossipMenuFor(player);
        if (Creature* avatar = instance->GetCreature(NPC_AVATAR_OF_SETHRALISS))
        {
            avatar->RemoveAura(SPELL_TAINT_DEBUFF);
            avatar->AddAura(SPELL_LIFE_FORCE);
            me->CastSpell(avatar, SPELL_LIFE_FORCE_HEAL);
            avatar->AI()->Talk(SAY_EFFECTIVE_HEAL);            
            me->DespawnOrUnsummon();
        }
    }
};

void AddSC_boss_avatar_of_sethraliss()
{
    RegisterCreatureAI(boss_avatar_of_sethraliss);
    RegisterCreatureAI(npc_hoodoo_hexer);
    RegisterCreatureAI(npc_plague_toad_137233);
    RegisterCreatureAI(npc_energy_fragment);
}
