/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

//@author: Lothloryen.

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "gnomeregan.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Creature.h"
#include "TemporarySummon.h"
#include "MotionMaster.h"

enum Yells
{
    SAY_AGGRO = 0,
    SAY_MACHINES = 1,
    SAY_EXPLOSIONS = 2,
    SAY_DEAD = 3,
};

enum Events
{
    EVENT_POUND = 1,
    EVENT_STEAM_BLAST = 2,
    EVENT_KNOCK_AWAY = 3,
    EVENT_ACTIVATE_BOMBS = 4,
    EVENT_WELDING_BEAM = 5,

    EVENT_SUMMON_BOMB = 6,
    EVENT_ATTACK_START = 7,
};

enum Spells
{
    SPELL_POUND = 35049,
    SPELL_STEAM_BLAST = 50375,
    SPELL_KNOCK_AWAY = 10101,
    SPELL_ACTIVATE_BOMB_VISUAL = 11511,
    SPELL_ACTIVATE_BOMB = 11518,
    SPELL_WELDING_BEAM = 35919,

    SPELL_BOMB_EFFECT = 11504,
};

enum Actions
{
    ACTION_ACTIVATE = 0,
};

uint32 const GnomeFaces[MAX_GNOME_FACES] =
{
    142211,
    142210,
    142209,
    142208,
    142213,
    142212
};

Position BombPositions[MAX_GNOME_FACES] =
{
    { -550.36f, 695.84f, -316.64f, 5.29f }, // Gnome Face 01
    { -522.94f, 701.96f, -315.95f, 4.48f }, // Gnome Face 02
    { -501.40f, 683.53f, -315.77f, 3.55f }, // Gnome Face 03
    { -501.87f, 655.21f, -315.75f, 2.62f }, // Gnome Face 04
    { -524.90f, 638.13f, -315.07f, 1.79f }, // Gnome Face 05
    { -552.53f, 645.29f, -314.61f, 1.00f }, // Gnome Face 06
};

class boss_mekgineer_thermaplugg : public CreatureScript
{
public:
    boss_mekgineer_thermaplugg() : CreatureScript("boss_mekgineer_thermaplugg") { }

    struct boss_mekgineer_thermapluggAI : public BossAI
    {
        boss_mekgineer_thermapluggAI(Creature* creature) : BossAI(creature, DATA_MEKGINEER_THERMAPLUGG)
        {
        }

        void AddFaceAvailable(uint32 entry)
        {
            _availableFacesList.insert(entry);
        }

        void RemoveFaceAvailable(uint32 entry)
        {
            _availableFacesList.erase(entry);
        }

        void DespawnBombs()
        {
            std::list<Creature*> pCreatureList;
            me->GetCreatureListWithEntryInGrid(pCreatureList, NPC_WALKING_BOMB);
            for (Creature* bomb: pCreatureList)
                bomb->DespawnOrUnsummon();
        }

        void Initialize()
        {
            _availableFacesList.clear();

            for (uint8 i = 0; i < MAX_GNOME_FACES; i++)
                if (GameObject* face = me->FindNearestGameObject(GnomeFaces[i], 130.0f))
                    face->AI()->Reset();
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
            DespawnBombs();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_DEAD);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            DespawnBombs();
            for (uint8 i = 0; i < MAX_GNOME_FACES; i++)
                if (GameObject* face = me->FindNearestGameObject(GnomeFaces[i], 130.0f))
                    face->AI()->Reset();
        }

        void JustEnteredCombat(Unit* /*who*/) override
        {
            for (uint8 i = 0; i < MAX_GNOME_FACES; i++)
                if (GameObject* face = me->FindNearestGameObject(GnomeFaces[i], 130.0f))
                    AddFaceAvailable(GnomeFaces[i]);

            Talk(SAY_AGGRO);
            _events.ScheduleEvent(EVENT_POUND, 6s);
            _events.ScheduleEvent(EVENT_STEAM_BLAST, 10s);
            _events.ScheduleEvent(EVENT_ACTIVATE_BOMBS, 8s);
            _events.ScheduleEvent(EVENT_WELDING_BEAM, 14s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_POUND:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f))
                            DoCast(target, SPELL_POUND);
                        else
                            DoCastVictim(SPELL_POUND);

                        _events.RescheduleEvent(EVENT_POUND, 10s);
                        _events.RescheduleEvent(EVENT_STEAM_BLAST, 4s);
                        break;
                    case EVENT_STEAM_BLAST:
                        Talk(SAY_MACHINES);
                        DoCastVictim(SPELL_STEAM_BLAST);
                        if (GetThreat(me->GetVictim()))
                            ModifyThreatByPercent(me->GetVictim(), -50);
                    break;
                    case EVENT_ACTIVATE_BOMBS:
                        if (!_availableFacesList.empty())
                        {
                            uint32 faceEntry = Trinity::Containers::SelectRandomContainerElement(_availableFacesList);
                            if (GameObject* face = me->FindNearestGameObject(faceEntry, 125.0f))
                            {
                                Talk(SAY_EXPLOSIONS);
                                face->AI()->DoAction(ACTION_ACTIVATE);
                                face->SetGoState(GO_STATE_ACTIVE);
                                DoCast(SPELL_ACTIVATE_BOMB_VISUAL);
                            }
                        }
                        _events.Repeat(10s, 18s);
                    break;
                    case EVENT_WELDING_BEAM:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, true))
                            DoCast(target, SPELL_WELDING_BEAM, true);

                        _events.Repeat(10s, 15s);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        EventMap _events;
        std::set<uint32> _availableFacesList;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGnomereganAI<boss_mekgineer_thermapluggAI>(creature);
    }

};

class npc_walking_bomb : public CreatureScript
{
public:
    npc_walking_bomb() : CreatureScript("npc_walking_bomb") { }

    struct npc_walking_bombAI : public ScriptedAI
    {
        npc_walking_bombAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        void InitializeAI() override
        {
            ScriptedAI::InitializeAI();

            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            _events.ScheduleEvent(EVENT_ATTACK_START, 2s);
            despawn = false;
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (Creature* boss = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MEKGINEER_THERMAPLUGG)))
                    boss->AI()->Talk(SAY_DEAD);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!despawn)
                if (Player* player = me->SelectNearestPlayer(3.0f))
                {
                    despawn = true;
                    me->CastSpell(me, SPELL_BOMB_EFFECT, true);
                    me->StopMoving();
                }

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ATTACK_START:
                    DoZoneInCombat();
                    if (Player* player = me->SelectNearestPlayer(125.0f))
                    {
                        AttackStart(player);
                        AddThreat(player, 10000);
                    }
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool despawn;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGnomereganAI<npc_walking_bombAI>(creature);
    }
};

class go_button : public GameObjectScript
{
public:
    go_button() : GameObjectScript("go_button") { }

    struct go_buttonAI : public GameObjectAI
    {
        go_buttonAI(GameObject* go) : GameObjectAI(go) {};

        bool GossipHello(Player* /*player*/) override
        {
            if (GameObject* gnomeFace = me->FindNearestGameObject(GetFace(me->GetEntry()), 20.0f))
            {
                gnomeFace->SetLootState(GO_READY);
                gnomeFace->SetGoState(GO_STATE_READY);
            }
            return false;
        }

    private:
        uint32 GetFace(uint32 uiType)
        {
            switch (uiType)
            {
            case GO_BUTTON_01:
                return GO_GNOME_FACE_01;
            case GO_BUTTON_02:
                return GO_GNOME_FACE_02;
            case GO_BUTTON_03:
                return GO_GNOME_FACE_03;
            case GO_BUTTON_04:
                return GO_GNOME_FACE_04;
            case GO_BUTTON_05:
                return GO_GNOME_FACE_05;
            case GO_BUTTON_06:
                return GO_GNOME_FACE_06;
            default:
                break;
            }
            return 0;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetGnomereganAI<go_buttonAI>(go);
    }
};

class go_gnome_face : public GameObjectScript
{
public:
    go_gnome_face() : GameObjectScript("go_gnome_face") { }

    struct go_gnome_faceAI : public GameObjectAI
    {
        go_gnome_faceAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()), _isActive(false) { }

        void OnStateChanged(uint32 state) override
        {
            switch (state)
            {
            case GO_STATE_ACTIVE:
                if (Creature* boss = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MEKGINEER_THERMAPLUGG)))
                    CAST_AI(boss_mekgineer_thermaplugg::boss_mekgineer_thermapluggAI, boss->AI())->RemoveFaceAvailable(me->GetEntry());

                _isActive = true;
                _events.RescheduleEvent(EVENT_SUMMON_BOMB, 2s);
                break;
            case GO_STATE_READY:
                if (_isActive)
                    if (Creature* boss = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MEKGINEER_THERMAPLUGG)))
                        CAST_AI(boss_mekgineer_thermaplugg::boss_mekgineer_thermapluggAI, boss->AI())->AddFaceAvailable(me->GetEntry());

                _isActive = false;
                _events.CancelEvent(EVENT_SUMMON_BOMB);
                break;
            default:
                break;
            }
        }

        void Reset() override
        {
            me->SetLootState(GO_READY);
            me->SetGoState(GO_STATE_READY);
        }

        void DoAction(int32 param) override
        {
            if (param == ACTION_ACTIVATE)
                me->CastSpell(me, SPELL_ACTIVATE_BOMB, true);
        }

        Position GetBombPosition()
        {
            switch (me->GetEntry())
            {
            case GO_GNOME_FACE_01:
                return BombPositions[0];
            case GO_GNOME_FACE_02:
                return BombPositions[1];
            case GO_GNOME_FACE_03:
                return BombPositions[2];
            case GO_GNOME_FACE_04:
                return BombPositions[3];
            case GO_GNOME_FACE_05:
                return BombPositions[4];
            case GO_GNOME_FACE_06:
                return BombPositions[5];
            default:
                return BombPositions[0];
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_isActive)
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_BOMB:
                    if (Creature* bomb = me->SummonCreature(NPC_WALKING_BOMB, GetBombPosition()))
                    {
                        bomb->SetCorpseDelay(5);
                        bomb->GetMotionMaster()->MoveFall();
                    }

                    _events.Repeat(10s);
                    break;
                default:
                    break;
                }
            }
        }

        InstanceScript* _instance;
        EventMap _events;
        bool _isActive;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetGnomereganAI<go_gnome_faceAI>(go);
    }

};

void AddSC_boss_mekgineer_thermaplugg()
{
    new boss_mekgineer_thermaplugg();
    new npc_walking_bomb();
    new go_button();
    new go_gnome_face();
}
