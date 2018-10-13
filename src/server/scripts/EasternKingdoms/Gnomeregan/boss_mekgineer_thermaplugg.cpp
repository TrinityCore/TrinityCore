/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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
    SAY_AGGRO         = 0,
    SAY_MACHINES      = 1,
    SAY_EXPLOSIONS    = 2,
    SAY_DEAD          = 3,
};

enum Events
{
    EVENT_KNOCK_AWAY = 1,
    EVENT_ACTIVATE_BOMBS,

    EVENT_SUMMON_BOMB,
    EVENT_ATTACK_START
};

enum Spells
{
    SPELL_KNOCK_AWAY       = 10101,
    SPELL_KNOCK_AWAY_AOE   = 11130,
    SPELL_ACTIVATE_BOMB_A  = 11511,
    SPELL_ACTIVATE_BOMB_B  = 11795,
    SPELL_BOMB_EFFECT      = 11504
};

uint32 const GnomeFaces[MAX_GNOME_FACES] =
{
    DATA_FACE_01,
    DATA_FACE_02,
    DATA_FACE_03,
    DATA_FACE_04,
    DATA_FACE_05,
    DATA_FACE_06
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
        boss_mekgineer_thermapluggAI(Creature* creature) : BossAI(creature, DATA_THERMAPLUGG), phase_two(false) { }

        void AddFaceAvailable(uint32 entry)
        {
            _availableFaces.insert(entry);
        }

        void RemoveFaceAvailable(uint32 entry)
        {
            _availableFaces.erase(entry);
        }

        void DespawnBombs()
        {
            std::list<Creature*> pCreatureList;
            me->GetCreatureListWithEntryInGrid(pCreatureList, NPC_WALKING_BOMB);
            for (Creature* bomb: pCreatureList)
                bomb->DespawnOrUnsummon();
        }

        void UnlockDoor()
        {
            if (GameObject* door = instance->GetGameObject(DATA_THE_FINAL_CHAMBER))
                if(door->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE))
                {
                    door->SetGoState(GO_STATE_ACTIVE);
                    door->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }
        }
        void LockDoor()
        {
            if (GameObject* door = instance->GetGameObject(DATA_THE_FINAL_CHAMBER))
            {
                door->SetGoState(GO_STATE_READY);
                door->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }
        }

        void ResetFaces()
        {
            for (uint32 face_id : GnomeFaces)
                if (GameObject* face = instance->GetGameObject(face_id))
                    face->AI()->Reset();
        }

        void Reset() override
        {
            events.Reset();
            ResetFaces();
            DespawnBombs();
            UnlockDoor();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_DEAD);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            events.Reset();
            ResetFaces();
            UnlockDoor();
        }

        void JustEnteredCombat(Unit* /*who*/) override
        {
            for (uint32 face_id : GnomeFaces)
                if (GameObject* face = instance->GetGameObject(face_id))
                    AddFaceAvailable(face_id);

            uint32 face_id = Trinity::Containers::SelectRandomContainerElement(_availableFaces);
            if (GameObject* face = instance->GetGameObject(face_id))
                face->SetGoState(GO_STATE_ACTIVE);

            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_KNOCK_AWAY, 17s, 20s);
            events.ScheduleEvent(EVENT_ACTIVATE_BOMBS, 10s, 15s);
            phase_two = false;

            LockDoor();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!phase_two && me->HealthBelowPct(50))
            {
                phase_two = true;
                Talk(SAY_MACHINES);
            }

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_BOMBS:
                        if (!_availableFaces.empty())
                        {
                            uint32 face_id = Trinity::Containers::SelectRandomContainerElement(_availableFaces);
                            if (GameObject* face = instance->GetGameObject(face_id))
                            {
                                Talk(SAY_EXPLOSIONS);
                                face->SetGoState(GO_STATE_ACTIVE);
                                DoCast(phase_two ? SPELL_ACTIVATE_BOMB_B : SPELL_ACTIVATE_BOMB_A);
                            }
                        }

                        if (phase_two)
                            events.Repeat(10s, 18s);
                        else
                            events.Repeat(6s, 12s);

                        break;
                    case EVENT_KNOCK_AWAY:
                        if (phase_two)
                        {
                            DoCastVictim(SPELL_KNOCK_AWAY_AOE, true);
                            events.Repeat(12s);
                        }
                        else
                        {
                            DoCastVictim(SPELL_KNOCK_AWAY, true);
                            events.Repeat(17s, 20s);
                        }
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
        std::set<uint32> _availableFaces;
        bool phase_two;
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
        npc_walking_bombAI(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
        {
        }

        void InitializeAI() override
        {
            ScriptedAI::InitializeAI();

            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.ScheduleEvent(EVENT_ATTACK_START, 2s);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (Creature* boss = _instance->GetCreature(DATA_THERMAPLUGG))
                    if(boss->IsAlive())
                       boss->AI()->Talk(SAY_DEAD);
        }

        void UpdateAI(uint32 diff) override
        {
            if (Player* player = me->SelectNearestPlayer(3.0f))
                me->CastSpell(me, SPELL_BOMB_EFFECT, true);

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
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
                        else
                            me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
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
        go_buttonAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()), _face_id(GetFace()) {};

        bool GossipHello(Player* /*player*/) override
        {
            if (GameObject* gnomeFace = _instance->GetGameObject(_face_id))
            {
                gnomeFace->SetGoState(GO_STATE_READY);
            }
            return false;
        }

    private:
        InstanceScript* _instance;
        uint32 _face_id;

        uint32 GetFace()
        {
            switch (me->GetEntry())
            {
                case GO_BUTTON_01:
                    return DATA_FACE_01;
                case GO_BUTTON_02:
                    return DATA_FACE_02;
                case GO_BUTTON_03:
                    return DATA_FACE_03;
                case GO_BUTTON_04:
                    return DATA_FACE_04;
                case GO_BUTTON_05:
                    return DATA_FACE_05;
                case GO_BUTTON_06:
                    return DATA_FACE_06;
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
        go_gnome_faceAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()), _isActive(false), _face_id(GetFace()), _bomb_position(GetBombPosition()) { }

        void OnStateChanged(uint32 state) override
        {
            switch (state)
            {
                case GO_STATE_ACTIVE:
                    if (Creature* boss = _instance->GetCreature(DATA_THERMAPLUGG))
                        CAST_AI(boss_mekgineer_thermaplugg::boss_mekgineer_thermapluggAI, boss->AI())->RemoveFaceAvailable(_face_id);

                    _isActive = true;
                    events.RescheduleEvent(EVENT_SUMMON_BOMB, 2s);
                    break;
                case GO_STATE_READY:
                    if (_isActive)
                        if (Creature* boss = _instance->GetCreature(DATA_THERMAPLUGG))
                            CAST_AI(boss_mekgineer_thermaplugg::boss_mekgineer_thermapluggAI, boss->AI())->AddFaceAvailable(_face_id);

                    _isActive = false;
                    events.CancelEvent(EVENT_SUMMON_BOMB);
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            me->SetGoState(GO_STATE_READY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_isActive)
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUMMON_BOMB:
                        if (Creature* bomb = me->SummonCreature(NPC_WALKING_BOMB, _bomb_position))
                        {
                            bomb->SetCorpseDelay(5);
                            bomb->GetMotionMaster()->MoveFall();
                        }

                        events.Repeat(10s);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        InstanceScript* _instance;
        EventMap events;
        bool _isActive;
        uint32 _face_id;
        Position _bomb_position;

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

        uint32 GetFace()
        {
            switch (me->GetEntry())
            {
                case GO_GNOME_FACE_01:
                    return DATA_FACE_01;
                case GO_GNOME_FACE_02:
                    return DATA_FACE_02;
                case GO_GNOME_FACE_03:
                    return DATA_FACE_03;
                case GO_GNOME_FACE_04:
                    return DATA_FACE_04;
                case GO_GNOME_FACE_05:
                    return DATA_FACE_05;
                case GO_GNOME_FACE_06:
                    return DATA_FACE_06;
                default:
                    break;
            }
            return 0;
        }

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
