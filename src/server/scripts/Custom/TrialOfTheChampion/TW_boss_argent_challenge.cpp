/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Argent Challenge Encounter.
SD%Complete: 90 %
SDComment: AI from bosses need more improvements. Need AI for lightwell
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "TW_trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum Spells
{
    //Eadric
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_JUSTICE_STUN   = 66940,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_HAMMER_OVERRIDE_BAR   = 66904, // overrides players cast bar
    SPELL_HAMMER_THROWBACK_DMG  = 66905, // the hammer that is thrown back by the player
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_CONFESSOR_ACHIEVEMENT = 68206,
    SPELL_SMITE                 = 66536,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_RENEW                 = 66537,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,
    
    //Npc_argent_soldier
    SPELL_STRIKE                = 67237,
    SPELL_CLEAVE                = 15284,
    SPELL_PUMMEL                = 67235,
    SPELL_PAIN                  = 34942,
    SPELL_MIND                  = 67229,
    SPELL_SSMITE                = 67289,
    SPELL_LIGHT_H               = 67290,
    SPELL_LIGHT                 = 67247,
    SPELL_FLURRY                = 67233,
    SPELL_FINAL                 = 67255,
    SPELL_DIVINE                = 67251,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677
};
enum Misc
{
    ACHIEV_FACEROLLER           = 3803,
    ACHIEV_CONF                 = 3802
};

enum Talk
{
    SAY_ARGENT_ENTERS           = 19,
    SAY_ARGENT_READY            = 20,
    SAY_MEMORY_NIGHTMARE        = 0,

    // Paletress
    SAY_PALETRESS_AGGRO         = 2,
    SAY_PALETRESS_SUMMON_MEMORY = 3,
    SAY_PALETRESS_MEMORY_DIES   = 4,
    SAY_PALETRESS_PLAYER_DIES   = 5,
    SAY_PALETRESS_DEFEATED      = 6,

    // Eadric
    SAY_EADRIC_AGGRO            = 1,
    SAY_EADRIC_RADIATE_LIGHT    = 2,
    SAY_EADRIC_HAMMER_TARGET    = 3,
    SAY_EADRIC_HAMMER           = 4,
    SAY_EADRIC_PLAYER_DIES      = 5,
    SAY_EADRIC_DEFEATED         = 6
};

enum Events
{
    // Eadric the Pure
    EVENT_VENGEANCE            = 1,
    EVENT_RADIANCE             = 2,
    EVENT_HAMMER_OF_JUSTICE    = 3,

    // Argent Confessor Paletress
    EVENT_HOLY_FIRE            = 4,
    EVENT_SMITE                = 5,
    EVENT_RENEW                = 6
};

enum Data
{
    DATA_THE_FACEROLLER
};

class OrientationCheck
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator() (WorldObject* object)
        {
            return !object->isInFront(caster, 40.0f) || !object->IsWithinDist(caster, 40.0f);
        }

    private:
        Unit* caster;
};

class TW_spell_eadric_hoj : public SpellScriptLoader
{
    public:
        TW_spell_eadric_hoj() : SpellScriptLoader("TW_spell_eadric_hoj") { }

        class TW_spell_eadric_hoj_SpellScript: public SpellScript
        {
            PrepareSpellScript(TW_spell_eadric_hoj_SpellScript);

            void HandleOnHit()
            {
                if (GetHitUnit() && GetHitUnit()->GetTypeId() == TYPEID_PLAYER)
                    if (!GetHitUnit()->HasAura(SPELL_HAMMER_JUSTICE_STUN)) // FIXME: Has Catched Hammer...
                    {
                        SetHitDamage(0);
                        GetHitUnit()->AddAura(SPELL_HAMMER_OVERRIDE_BAR, GetHitUnit());
                    }

            }

            void Register() override
            {
                OnHit += SpellHitFn(TW_spell_eadric_hoj_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_eadric_hoj_SpellScript();
        }
};


class TW_boss_eadric : public CreatureScript
{
    public:
        TW_boss_eadric(): CreatureScript("TW_boss_eadric") {}

    struct TW_boss_eadricAI : public BossAI
    {
        TW_boss_eadricAI(Creature* creature) : BossAI(creature, BOSS_ARGENT_CHALLENGE_E)
        {
            instance = creature->GetInstanceScript();
            hasBeenInCombat = false;
            bCredit = false;
        }

        void Reset()
        {
            uiResetTimer = 5000;
            uiBasePoints = 0;
            me->SetReactState(REACT_PASSIVE);
            _theFaceRoller = false;
            bDone = false;
            Map* pMap = me->GetMap();
            if (hasBeenInCombat && pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                     if (itr->GetSource() && itr->GetSource()->IsAlive() && !itr->GetSource()->IsGameMaster())
                         return;
                }
                
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(), true);

                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, 0);
                me->RemoveFromWorld();
            }
        }

        void DamageTaken(Unit* /*who*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                HandleSpellOnPlayersInInstanceToC5(me, 68575);
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                Talk(SAY_EADRIC_DEFEATED);
                me->setFaction(35);
                bDone = true;
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                    instance->HandleGameObject(gate->GetGUID(),true);
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(),true);
                instance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                HandleInstanceBind(me);
            }
        }

        void MovementInform(uint32 MovementType, uint32 /*Data*/)
        {
            if (MovementType != POINT_MOTION_TYPE)
                return;
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_RADIANCE, 16000);
            events.ScheduleEvent(EVENT_VENGEANCE, 10000);
            events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 25000);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            _EnterCombat();
            me->SetHomePosition(746.843f, 665.000f, 412.339f, 4.670f);
            Talk(SAY_EADRIC_AGGRO);
            hasBeenInCombat = true;
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (IsHeroic() && !bDone && spell->Id == SPELL_HAMMER_THROWBACK_DMG && caster->GetTypeId() == TYPEID_PLAYER)
            {            
                uiBasePoints = spell->Effects[0].BasePoints;
                if (me->GetHealth() <= uiBasePoints)
                {
                    _theFaceRoller = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_EADRIC_ACHIEVEMENT);
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_THE_FACEROLLER)
                return _theFaceRoller;

            return 0;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                bDone = false;
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                    instance->HandleGameObject(gate->GetGUID(),false);
            } else uiResetTimer -= uiDiff;
            
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RADIANCE:
                        DoCastAOE(SPELL_RADIANCE);
                        Talk(SAY_EADRIC_RADIATE_LIGHT);
                        events.ScheduleEvent(EVENT_RADIANCE, 16000);
                        break;
                    case EVENT_VENGEANCE:
                        DoCast(me, SPELL_VENGEANCE);
                        events.ScheduleEvent(EVENT_VENGEANCE, 10000);
                        break;
                    case EVENT_HAMMER_OF_JUSTICE:
                        me->InterruptNonMeleeSpells(true);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                        {
                            Talk(SAY_EADRIC_HAMMER);
                            Talk(SAY_EADRIC_HAMMER_TARGET, target);
                            DoCast(target, SPELL_HAMMER_JUSTICE);
                            DoCast(target, SPELL_HAMMER_RIGHTEOUS);
                        }
                        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 25000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
        InstanceScript* instance;
        uint32 uiResetTimer;
        uint64 uiBasePoints;
        bool bDone;
        bool hasBeenInCombat;
        bool bCredit;
        bool _theFaceRoller;

    };


    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_eadricAI>(creature);
    };
};

class TW_boss_paletress : public CreatureScript
{
    public:
        TW_boss_paletress(): CreatureScript("TW_boss_paletress") {}

    struct TW_boss_paletressAI : public BossAI
    {
        TW_boss_paletressAI(Creature* creature) : BossAI(creature, BOSS_ARGENT_CHALLENGE_P)
        {
            instance = creature->GetInstanceScript();
            hasBeenInCombat = false;
            _hasSummonedMemory = false;
            bCredit = false;
            memoryGUID.Clear();
        }

        void Reset()
        {
            me->RemoveAllAuras();
            uiResetTimer        = 7000;
            _hasSummonedMemory = false;
            bDone = false;
            me->SetReactState(REACT_PASSIVE);

            if (Creature* pMemory = ObjectAccessor::GetCreature(*me, memoryGUID))
                if (pMemory->IsAlive())
                    pMemory->RemoveFromWorld();

            Map* pMap = me->GetMap();
            if (hasBeenInCombat && pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (itr->GetSource() && itr->GetSource()->IsAlive() && !itr->GetSource()->IsGameMaster())
                        return;
                }

                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(), true);

                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, 0);
                me->RemoveFromWorld();
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
            events.ScheduleEvent(EVENT_SMITE, urand(5000, 7000));
            events.ScheduleEvent(EVENT_RENEW, urand(2000, 5000));

            me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            _EnterCombat();
            me->SetHomePosition(746.843f, 665.000f, 412.339f, 4.670f);
            hasBeenInCombat = true;
            Talk(SAY_PALETRESS_AGGRO);
        }

        void SetData(uint32 uiId, uint32 /*uiValue*/)
        {
            if (uiId == 1)
                me->RemoveAura(SPELL_SHIELD);
                Talk(SAY_PALETRESS_MEMORY_DIES);
        }

        void DamageTaken(Unit* /*who*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                HandleSpellOnPlayersInInstanceToC5(me, 68574);
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                Talk(SAY_PALETRESS_DEFEATED);
                me->setFaction(35);
                bDone = true;
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                    instance->HandleGameObject(gate->GetGUID(),true);
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(),true);
                instance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);
                HandleInstanceBind(me);

                if (Creature* memory = ObjectAccessor::GetCreature(*me, memoryGUID))
                    HandleSpellOnPlayersInInstanceToC5(memory, SPELL_CONFESSOR_ACHIEVEMENT);
            }
        }

        void MovementInform(uint32 MovementType, uint32 /*Data*/)
        {
            if (MovementType != POINT_MOTION_TYPE)
                return;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0, 746.843f, 695.68f, 412.339f);
                bDone = false;
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                    instance->HandleGameObject(gate->GetGUID(),false);
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HOLY_FIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                            DoCast(target, SPELL_HOLY_FIRE);
                        if (me->HasAura(SPELL_SHIELD))
                            events.ScheduleEvent(EVENT_HOLY_FIRE, 13000);
                        else
                            events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
                        break;
                    case EVENT_SMITE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                            DoCast(target, SPELL_SMITE);
                        if (me->HasAura(SPELL_SHIELD))
                            events.ScheduleEvent(EVENT_SMITE, 9000);
                        else
                            events.ScheduleEvent(EVENT_SMITE, urand(5000, 7000));
                        break;
                    case EVENT_RENEW:
                        if (me->HasAura(SPELL_SHIELD))
                        {
                            me->InterruptNonMeleeSpells(true);
                            uint8 uiTarget = urand(0, 1);
                            switch (uiTarget)
                            {
                                case 0:
                                    DoCast(me, SPELL_RENEW);
                                    break;
                                case 1:
                                    if (Creature* memory = ObjectAccessor::GetCreature(*me, memoryGUID))
                                        if (memory->IsAlive())
                                            DoCast(memory, SPELL_RENEW);
                                    break;
                            }
                        }
                        events.ScheduleEvent(EVENT_RENEW, 15000, 17000);
                        break;
                    default:
                        break;

                }
            }

            DoMeleeAttackIfReady();

            if (!_hasSummonedMemory && me->HealthBelowPct(25))
            {
                Talk(SAY_PALETRESS_SUMMON_MEMORY);
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA, false);
                DoCast(me, SPELL_SHIELD);
                DoCastAOE(SPELL_CONFESS, false);
                DoCast(SPELL_SUMMON_MEMORY);
                _hasSummonedMemory = true;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            memoryGUID = summon->GetGUID();
        }
    private:
        InstanceScript* instance;
        ObjectGuid memoryGUID;
        bool _hasSummonedMemory;
        bool bDone;
        bool hasBeenInCombat;
        bool bCredit;
        uint32 uiResetTimer;

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_paletressAI>(creature);
    };
};

class TW_npc_memory : public CreatureScript
{
    public:
        TW_npc_memory(): CreatureScript("TW_npc_memory") {}

    struct TW_npc_memoryAI : public ScriptedAI
    {
        TW_npc_memoryAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiOldWoundsTimer;
        uint32 uiShadowPastTimer;
        uint32 uiWakingNightmare;

        void Reset()
        {
            uiOldWoundsTimer = 12000;
            uiShadowPastTimer = 5000;
            uiWakingNightmare = 7000;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (uiOldWoundsTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                {
                    if (target && target->IsAlive())
                        DoCast(target, DUNGEON_MODE(SPELL_OLD_WOUNDS,SPELL_OLD_WOUNDS_H));
                }
                uiOldWoundsTimer = 23000;
            } else uiOldWoundsTimer -= uiDiff;

            if (uiWakingNightmare <= uiDiff)
            {
                Talk(SAY_MEMORY_NIGHTMARE);
                DoCast(me, DUNGEON_MODE(SPELL_WAKING_NIGHTMARE,SPELL_WAKING_NIGHTMARE_H));
                uiWakingNightmare = 15000;
            } else uiWakingNightmare -= uiDiff;

            if (uiShadowPastTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,1))
                {
                    if (target && target->IsAlive())
                        DoCast(target,DUNGEON_MODE(SPELL_SHADOWS_PAST,SPELL_SHADOWS_PAST_H));
                }
                uiShadowPastTimer = 20000;
            } else uiShadowPastTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (me->IsSummon())
            {
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                {
                    if (summoner && summoner->IsAlive() && summoner->GetTypeId() == TYPEID_UNIT)
                        summoner->ToCreature()->AI()->SetData(1,0);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_npc_memoryAI>(creature);
    };
};

// THIS AI NEEDS MORE IMPROVEMENTS
class TW_npc_argent_soldier : public CreatureScript
{
    public:
        TW_npc_argent_soldier(): CreatureScript("TW_npc_argent_soldier") {}

    struct TW_npc_argent_soldierAI : public npc_escortAI
    {
        TW_npc_argent_soldierAI(Creature* creature) : npc_escortAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
            if (GameObject* gate = ObjectAccessor::GetGameObject(*me, pInstance->GetGuidData(DATA_MAIN_GATE)))
                pInstance->HandleGameObject(gate->GetGUID(),true);
            SetDespawnAtEnd(false);
            uiWaypoint = 0;
            bStarted = false;
        }

        InstanceScript* pInstance;

        uint8 uiWaypoint;

        uint32 uiStrikeTimer;
        uint32 uiCleaveTimer;
        uint32 uiPummelTimer;
        uint32 uiPainTimer;
        uint32 uiMindTimer;
        uint32 uiSsmiteTimer;
        uint32 uiLightTimer;
        uint32 uiFlurryTimer;
        uint32 uiFinalTimer;
        uint32 uiDivineTimer;

        bool bStarted;

        void Reset() override
        {
            uiStrikeTimer = 5000;
            uiCleaveTimer = 6000;
            uiPummelTimer = 10000;
            uiPainTimer = 60000;
            uiMindTimer = 70000;
            uiSsmiteTimer = 6000;
            uiLightTimer = 3000;
   	        uiFlurryTimer = 6000;
            uiFinalTimer = 30000;
            uiDivineTimer = 70000;
            
            if (bStarted)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            }
        }

        void WaypointReached(uint32 uiPoint) override
        {
            if (uiPoint == 0)
            {
                switch(uiWaypoint)
                {
                    case 1:
                        me->SetOrientation(4.60f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        bStarted = true;
                        break;
                }
            }

            if (uiPoint == 1)
            {
                switch(uiWaypoint)
                {
                    case 0:
                        me->SetOrientation(5.81f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        bStarted = true;
                        break;
                    case 2:
                        me->SetOrientation(3.39f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        bStarted = true;
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, pInstance->GetGuidData(DATA_MAIN_GATE)))
                            pInstance->HandleGameObject(gate->GetGUID(),false);
                        break;
                }

                me->SendMovementFlagUpdate();
            }  
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) override
        {
            switch(me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0, 737.14f,655.42f,412.88f);
                            AddWaypoint(1, 712.14f,628.42f,411.88f);
                            break;
                        case 1:
                            AddWaypoint(0, 742.44f, 650.29f, 411.79f);
                            break;
                        case 2:
                            AddWaypoint(0, 756.14f, 655.42f, 411.88f);
                            AddWaypoint(1, 775.912f, 639.033f, 411.907f);
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0, 737.14f, 655.42f, 412.88f);
                            AddWaypoint(1, 713.12f, 632.97f, 411.90f);
                            break;
                        case 1:
                            AddWaypoint(0, 746.73f, 650.24f, 411.56f);
                            break;
                        case 2:
                            AddWaypoint(0, 756.14f, 655.42f, 411.88f);
                            AddWaypoint(1, 784.817f, 629.883f, 411.908f);
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0, 737.14f, 655.42f, 412.88f);
                            AddWaypoint(1, 715.06f, 637.07f, 411.91f);
                            break;
                        case 1:
                            AddWaypoint(0, 750.72f, 650.20f, 411.77f);
                            break;
                        case 2:
                            AddWaypoint(0, 756.14f, 655.42f, 411.88f);
                            AddWaypoint(1, 779.942f, 634.061f, 411.905f);
                            break;
                    }
                    break;
            }

            Start(false,true);
            uiWaypoint = uiType;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            if (uiCleaveTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_STRIKE);
                uiCleaveTimer = 20000;
            } else uiCleaveTimer -= uiDiff;

            if (uiStrikeTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_CLEAVE);
                uiStrikeTimer = 25000;
            } else uiStrikeTimer -= uiDiff;	

            if (uiPummelTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_PUMMEL);
                uiPummelTimer = 35000;
            } else uiPummelTimer -= uiDiff;	

            if (uiPainTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_PAIN);
                uiPainTimer = 30000;
            } else uiPainTimer -= uiDiff;

            if (uiMindTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_MIND);
                uiMindTimer = 90000;
            } else uiMindTimer -= uiDiff;

            if (uiSsmiteTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_SSMITE);
                uiSsmiteTimer = 25000;
            } else uiSsmiteTimer -= uiDiff;

            if (uiLightTimer <= uiDiff)
            {
                DoCast(me,DUNGEON_MODE(SPELL_LIGHT,SPELL_LIGHT_H));
                uiLightTimer = urand (15000, 17000);
            } else uiLightTimer -= uiDiff;

            if (uiFlurryTimer <= uiDiff)
            {
                DoCast(me,SPELL_FLURRY);
                uiFlurryTimer = 22000;
            } else uiFlurryTimer -= uiDiff;

            if (uiFinalTimer <= uiDiff)
            {
                DoCast(me,SPELL_FINAL);
                uiFinalTimer = 70000;
            } else uiFinalTimer -= uiDiff;

            if (uiDivineTimer <= uiDiff)
            {
                DoCast(me,SPELL_DIVINE);
                uiDivineTimer = 85000;
            } else uiDivineTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            pInstance->SetData(DATA_ARGENT_SOLDIER_DEFEATED,pInstance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_npc_argent_soldierAI>(creature);
    };
};

enum ReflectiveShield
{
    SPELL_REFLECTIVE_SHIELD_TRIGGERED = 33619,
};

// Reflective Shield 66515
class TW_spell_gen_reflective_shield : public SpellScriptLoader
{
    public:
        TW_spell_gen_reflective_shield() : SpellScriptLoader("TW_spell_gen_reflective_shield") { }

        class TW_spell_gen_reflective_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_gen_reflective_shield_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_REFLECTIVE_SHIELD_TRIGGERED)) // Is this correct?  I honestly don't know anything about AuraScript, so I took this from class spell_blood_queen_pact_of_the_darkfallen_dmg 
                    return false;

                return true;
            }

            void Trigger(AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit * target = dmgInfo.GetAttacker();
                if (!target)
                    return;
                Unit * caster = GetCaster();
                if (!caster)
                    return;
                int32 bp = CalculatePct(absorbAmount, 25);
                target->CastCustomSpell(target, SPELL_REFLECTIVE_SHIELD_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
            }

            void Register()
            {
                 AfterEffectAbsorb += AuraEffectAbsorbFn(TW_spell_gen_reflective_shield_AuraScript::Trigger, EFFECT_0);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new TW_spell_gen_reflective_shield_AuraScript();
        }
};

class TW_achievement_toc5_argent_challenge : public AchievementCriteriaScript
{
    public:
        uint32 creature_entry;

        TW_achievement_toc5_argent_challenge(const char* name, uint32 original_entry) : AchievementCriteriaScript(name) {
            creature_entry = original_entry;
        }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* creature = target->ToCreature())
                if (creature->GetOriginalEntry() == creature_entry)
                    return true;

            return false;
        }
};

class TW_achievement_toc5_argent_confessor : public AchievementCriteriaScript
{
    public:
        uint32 creature_entry;

        TW_achievement_toc5_argent_confessor(const char* name, uint32 original_entry) : AchievementCriteriaScript(name) 
        {
            creature_entry = original_entry;
        }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* creature = target->ToCreature())
                if (creature->GetEntry() == creature_entry && creature->GetMap()->ToInstanceMap()->IsHeroic())
                    return true;

            return false;
        }
};

class TW_achievement_toc5_the_faceroller : public AchievementCriteriaScript
{
    public:
        TW_achievement_toc5_the_faceroller(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->GetMap()->ToInstanceMap()->IsHeroic())
                return target->GetAI()->GetData(DATA_THE_FACEROLLER) == 1;

            return false;
        }
};

void AddSC_TW_boss_argent_challenge()
{
    new TW_boss_eadric();
    new TW_spell_eadric_hoj();
    new TW_boss_paletress();
    new TW_npc_memory();
    new TW_npc_argent_soldier();
    new TW_spell_gen_reflective_shield();
    new TW_achievement_toc5_argent_challenge("TW_achievement_toc5_paletress", NPC_PALETRESS);
    new TW_achievement_toc5_argent_challenge("TW_achievement_toc5_eadric", NPC_EADRIC);
    
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_hogger", MEMORY_HOGGER);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_vancleef", MEMORY_VANCLEEF);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_mutanus", MEMORY_MUTANUS);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_herod", MEMORY_HEROD);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_lucifron", MEMORY_LUCIFRON);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_thunderaan", MEMORY_THUNDERAAN);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_chromaggus", MEMORY_CHROMAGGUS);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_hakkar", MEMORY_HAKKAR);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_veknilash", MEMORY_VEKNILASH);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_kalithresh", MEMORY_KALITHRESH);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_malchezar", MEMORY_MALCHEZAAR);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_gruul", MEMORY_GRUUL);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_vashj", MEMORY_VASHJ);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_archimonde", MEMORY_ARCHIMONDE);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_illidan", MEMORY_ILLIDAN);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_delrissa", MEMORY_DELRISSA);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_muru", MEMORY_ENTROPIUS);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_ingvar", MEMORY_INGVAR);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_cyanigosa", MEMORY_CYANIGOSA);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_eck", MEMORY_ECK);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_onyxia", MEMORY_ONYXIA);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_heigan", MEMORY_HEIGAN);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_ignis", MEMORY_IGNIS);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_vezax", MEMORY_VEZAX);
    new TW_achievement_toc5_argent_confessor("TW_achivement_toc5_argent_confessor_algalon", MEMORY_ALGALON);

    new TW_achievement_toc5_the_faceroller("TW_achievement_toc5_the_faceroller");
}
