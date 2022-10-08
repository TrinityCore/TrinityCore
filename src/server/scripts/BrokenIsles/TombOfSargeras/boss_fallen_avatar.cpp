/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CHAOS = 1,
    SAY_BLADES = 2,
    SAY_RUPTURE_1 = 3,
    SAY_RUPTURE_2 = 4,
    SAY_ANNIHILANT = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    SPELL_UNBOUND_CHAOS = 234057, //
    SPELL_DESOLATE = 236494, //
    SPELL_SHADOWY_BLADES = 236573, //
    SPELL_RUPTURE_REALISTIC = 239132, //

    SPELL_ACTIVATE_PILONES = 240614, //
    SPELL_RIPPLE_OF_DARKNESS = 236528, //

    // second phase
    SPELL_CONSUME = 240594, //

    SPELL_ANNIHILATION = 235597, //
    SPELL_JUMP = 235613, //

    SPELL_SPARK_SECOND_PHASE = 239309, // ?
    SPELL_SEAR = 234179, // 
    SPELL_DARK_MARK = 239825, //
    SPELL_RUPTURE_REALISTIC_2 = 235572, //

    SPELL_AURA_WITHOUT_BLOCK = 110470,
    SPELL_AURA_PROC = 239830,
    SPELL_VISUAL_SWORD = 235582,


    // heroic
    SPELL_TOUCH_OF_SARGERAS_DMG = 239058,
    SPELL_TOUCH_OF_SARGERAS_NOT_CLOSE = 239287,
    SPELL_TOUCH_OF_SARGERAS_SUM = 239057, // 3 / 5
    SPELL_TOUCH_OF_SARGERAS_AT = 240827,
    SPELL_TOUCH_OF_SARGERAS_VIS = 240834,
    SPELL_TOUCH_OF_SARGERAS_CAST = 239207,

    SPELL_BLACK_WIND_TICKS = 239417,
    SPELL_BLACK_WIND_DMG = 242017,
    SPELL_BLACK_WIND_VIS = 241988,
    SPELL_BLACK_WIND_AT = 239418,

    SPELL_FEL_INFUSION = 236682,
    SPELL_FEL_INFUSION_BUFF = 236684,


    // add
    SPELL_CORRUPTED_BLADE = 236571, //  236604
    SPELL_CORRUPTED_BLADE_1 = 237666,
    SPELL_CORRUPTED_BLADE_REMOVE = 236593, //

    // maiden
    SPELL_CLEANING_PROTOCOL = 233856, //
    SPELL_CLEANING_PROTOCOL_ABSORB = 241008, // 
    SPELL_MALFUNCTION = 233739, //

    // pilones
    SPELL_BEAM_ON_BOSS = 238244, //
    SPELL_BEAM_ON_MAIDEN = 238335, //
    SPELL_BEAM_COND = 233878, //
    SPELL_PILONE_ACTIVATE = 233556, //
    SPELL_SPARK_OF_THE_DARK_TITAN = 234873, //

    SPELL_FEL_PILONE_ACTIVATE = 240623,
    SPELL_BEAM_ON_PLAYER_FEL = 240631, //  (aura)
    SPELL_BEAM_ON_PLAYER = 240746,

    SPELL_BEAM_ON_MAIDEN_FEL = 240758,
    SPELL_BEAM_ON_BOSS_FEL_VIS = 240630,
    SPELL_BEAM_ON_BOSS_FEL = 240675,
    SPELL_TAINTED_ESSENCE = 240728,
    SPELL_TAINTED_ESSENCE_KILL = 242081,

    SPELL_REMOVE_BEAMS = 238407, //

    SPELL_RAIN_OF_THE_DESTROYER_VIS = 241040,
    SPELL_RAIN_OF_THE_DESTROYER_AT = 241039,
    SPELL_RAIN_OF_THE_DESTROYER_SUM = 241036,
    SPELL_RAIN_OF_THE_DESTROYER_AOE = 240396,
    SPELL_RAIN_OF_THE_DESTROYER_CLOSE = 234417,
    // 236674


    // khadhar 241084 + 235582  + dmg (241123, 241122, 241128)
    // velen 241078  + dmg (241470, 241463, heal(241466))
    // illidan 57764 + dmg (241268, 241484)
    SPELL_CONVERS_EVENT_1 = 241103, //++ 4955

    SPELL_BONUS = 240659,
};

enum eEvents
{
    EVENT_SHADOWY_BLADES = 1,
    EVENT_CHECK_ENERGY,
    EVENT_RUPTURE_REALISTIC,
    EVENT_UNBOUND_CHAOS,
    EVENT_DESOLATE,
    EVENT_SELECT_PILONE,
    EVENT_RUPTURE_REALISTIC_AND_ENERGY,
    EVENT_DARK_MARK,

    EVENT_TOUCH_OF_SARGERAS,
    EVENT_SELECT_PILONE_FEL,
    EVENT_RAIN,

    EVENT_FORCE_SECOND_PHASE,
};



Position const pilonesPos[5]
{
    {6547.43f, -760.646f,	1662.98f,	5.75959f },
    {6538.19f, -795.174f,	1662.98f,	0       },
    {6547.38f, -829.529f,	1662.98f,	0.523599f},
    {6572.73f, -854.656f,	1662.98f,	1.0472f  },
    {6572.56f, -735.365f,	1662.98f,	5.23599f }
};

std::map<uint32, Position> floorBlocks
{
    { 267700, {6600.41f, -794.17f, 1510.0f, 0}},
    { 267701, {6560.08f, -775.08f, 1510.0f, 0}},
    { 267702, {6600.47f, -774.19f, 1510.0f, 0}},
    { 267703, {6635.91f, -761.15f, 1510.0f, 0}},
    { 267704, {6579.87f, -774.42f, 1510.0f, 0}},
    { 267705, {6642.12f, -795.31f, 1510.0f, 0}},
    { 267706, {6642.62f, -777.85f, 1510.0f, 0}},
    { 267707, {6561.22f, -794.48f, 1510.0f, 0}},
    { 267708, {6581.60f, -794.47f, 1510.0f, 0}},
    { 267709, {6560.60f, -757.41f, 1510.0f, 0}},
    { 267710, {6620.75f, -794.93f, 1510.0f, 0}},
    { 267711, {6597.75f, -753.93f, 1510.0f, 0}},
    { 267712, {6578.06f, -754.54f, 1510.0f, 0}},
    { 267713, {6620.22f, -775.04f, 1510.0f, 0}},
    { 267714, {6617.95f, -756.67f, 1510.0f, 0}},
    { 267715, {6600.41f, -836.14f, 1510.0f, 0}},
    { 267716, {6581.68f, -814.19f, 1510.0f, 0}},
    { 267717, {6614.62f, -836.08f, 1510.0f, 0}},
    { 267718, {6619.10f, -814.93f, 1510.0f, 0}},
    { 267719, {6638.89f, -814.43f, 1510.0f, 0}},
    { 267720, {6631.49f, -830.53f, 1510.0f, 0}},
    { 267721, {6600.83f, -814.48f, 1510.0f, 0}},
    { 267722, {6567.33f, -828.77f, 1510.0f, 0}},
    { 267723, {6582.95f, -832.97f, 1510.0f, 0}},
    { 267724, {6563.81f, -814.08f, 1510.0f, 0}}
};

std::map<uint32, std::pair<Position, Position>> perephaseEvent
{
    {121171, {{6515.72f, -809.69f, 1663.67f, 0.0f}, {6712.24f, -770.72f, 1519.62f}}},
    {121170, {{6615.99f, -797.28f, 1663.67f, 0.0f}, {6705.52f, -800.44f, 1513.50f}}},
    {121169, {{6514.16f, -785.14f, 1663.67f, 0.0f}, {6708.47f, -782.25f, 1517.22f}}}
};

Position const bladesPositions[7]
{
    {6594.51f, -806.92f, 1663.58f, 0.0f},
    {6589.36f, -794.80f, 1663.58f, 0.0f},
    {6597.37f, -779.48f, 1663.58f, 0.0f},

    {6551.39f, -737.23f, 1663.58f, 0.0f},
    {6529.41f, -771.28f, 1663.58f, 0.0f},
    {6530.16f, -812.10f, 1663.58f, 0.0f},
    {6541.95f, -839.76f, 1663.58f, 0.0f},
};

std::vector<Position> sargerasPositions
{
    {6551.96f, -805.34f, 1663.58f, 0.0f},
    {6573.08f, -756.50f, 1663.58f, 0.0f},
    {6578.23f, -779.93f, 1663.58f, 0.0f},
    {6578.44f, -832.90f, 1663.58f, 0.0f},
    {6583.62f, -812.65f, 1663.58f, 0.0f},
    {6562.11f, -794.26f, 1663.58f, 0.0f},
    {6554.01f, -767.29f, 1663.58f, 0.0f},
    {6589.62f, -756.13f, 1663.58f, 0.0f},

};

std::vector<Position> windsPos
{
    { 6538.00f, -754.95f, 1509.91f, 0.0f },
    { 6538.00f, -774.61f, 1509.91f, 0.0f },
    { 6538.00f, -795.38f, 1509.91f, 0.0f },
    { 6538.00f, -814.43f, 1509.91f, 0.0f },
    { 6538.00f, -831.60f, 1509.91f, 0.0f }, // + 118 by x

    { 6642.00f, -741.01f, 1509.91f, 0.0f },
    { 6620.33f, -737.82f, 1509.91f, 0.0f },
    { 6596.41f, -737.06f, 1509.91f, 0.0f },
    { 6577.08f, -736.97f, 1509.91f, 0.0f },
    { 6557.97f, -736.97f, 1509.91f, 0.0f } // -118 by y
};

template<typename T>
struct MySpecialList : public std::list<T>
{
    MySpecialList() = default;

    MySpecialList(const std::initializer_list<T>& _list) :
        std::list<T>(_list) {};

    T popAndSafeLast()
    {
        if (this->empty())
            throw "MySpecialList is empty!";

        T val = this->front();
        if (this->size() > 1)
            this->pop_front();

        return val;
    }
};


MySpecialList<uint32> unboundChaosTimers{ 41000, 44000, 36000, 47000, 44000, 35000, 47000 };
MySpecialList<uint32> unboundChaosHeroicTimers{ 46000, 35000, 42000, 62000, 35000, 50000 };
MySpecialList<uint32> shadowBladesTimers{ 34000, 48000, 43000, 36000, 49000, 43000 };
MySpecialList<uint32> shadowBladesHeroicTimers{ 45000, 61000, 37000, 42000, 38000 };
MySpecialList<uint32> ruptureRealisticTimersHeroic{ 60000, 80000, 60000 };
/*
// 116939
struct boss_fallen_avatar : BossAI
{
    boss_fallen_avatar(Creature* creature) : BossAI(creature, DATA_FALLEN_AVATAR)
    {
        IntroDone = false;
        me->m_SightDistance = 100.0f;
    }

    bool IntroDone;
    std::vector<std::pair<ObjectGuid, uint8>> pilones; // 0 - free, 1 - usual, 2 -fel
    bool isSecondPhase;
    std::map<uint32, Position> localFloorBlocks;
    MySpecialList<uint32> m_unboundChaosTimers;
    MySpecialList<uint32> m_shadowBladesTimers;
    MySpecialList<uint32> m_darkMarkTimers;
    MySpecialList<uint32> m_ruptureRealisticTimers;


    void Reset() override
    {
        localFloorBlocks = floorBlocks;

        isSecondPhase = false;
        _Reset();

        pilones.clear(); // just despawned, i think

      //  if (me->IsAlive())
          //  if (Creature* maiden = me->SummonCreature(NPC_AVATARA_MAIDEN, 6583.50f, -771.65f, 1663.67f, 3.04f, TEMPSUMMON_MANUAL_DESPAWN))
          //      for (const auto pos : pilonesPos)
                   // me->SummonCreature(NPC_PILONES, pos, maiden->GetGUID(), TEMPSUMMON_MANUAL_DESPAWN, 0);

        SetCombatMovement(false);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TAINTED_ESSENCE);

        me->SetPower(me->GetPowerType(), 0);

        if (IntroDone)
            DoCast(SPELL_VISUAL_SWORD);

        me->SetDisplayId(me->GetNativeDisplayId());
        me->SetCanFly(true);

        if (IsHeroic())
            me->CastSpell(me, SPELL_FEL_INFUSION);

        m_unboundChaosTimers = (IsMythic() ? unboundChaosTimers : unboundChaosHeroicTimers);
        m_shadowBladesTimers = (IsMythic() ? shadowBladesTimers : shadowBladesHeroicTimers);
        m_ruptureRealisticTimers = (IsHeroic() ? ruptureRealisticTimersHeroic : MySpecialList<uint32>({ 60000 }));
    }

    void EnterCombat(Unit* who) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();

        me->SetPower(me->GetPowerType(), 0);

        DoCast(74426); // hack

        events.RescheduleEvent(EVENT_CHECK_ENERGY, urand(4000, 5000));
        events.RescheduleEvent(EVENT_RUPTURE_REALISTIC, 38000);
        events.RescheduleEvent(EVENT_UNBOUND_CHAOS, 7000);
        events.RescheduleEvent(EVENT_SHADOWY_BLADES, 30000);
        events.RescheduleEvent(EVENT_DESOLATE, 13000);
        events.RescheduleEvent(EVENT_SELECT_PILONE, 1000);
        if (IsHeroic())
            events.RescheduleEvent(EVENT_TOUCH_OF_SARGERAS, 15000);
        if (IsMythic())
            events.RescheduleEvent(EVENT_SELECT_PILONE_FEL, 1100);

       // if (who)
          //  me->AddDelayedCombat(500, [&]() -> void
        {
         //   if (Creature* maiden = summons.GetCreature(NPC_AVATARA_MAIDEN))
         //   {
               // if (!maiden->isInCombat())
               //     DoZoneInCombat(maiden);
         //       instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, maiden);
            }
      //  });
    }

    void SummonedCreatureDies(Creature* creature, Unit* killer) override
    {
        if (killer->GetGUID() == me->GetGUID())
            return;

        if (creature->GetEntry() != NPC_AVATARA_MAIDEN)
            return;

        events.Reset();
        events.RescheduleEvent(EVENT_FORCE_SECOND_PHASE, 1);
    }*/

   // void JustDied(Unit* /*killer*/) override
  /*  {
        Talk(SAY_DEATH);
        // _JustDied(); // without summons
       // me->RemoveAllAreaObjects();
        me->m_Events.KillAllEvents(true);

        events.Reset();
        if (instance)
        {
            instance->SetBossState(DATA_FALLEN_AVATAR, DONE);
            instance->SaveToDB();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
           // instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me);
        }

      //  me->CreateConversation(4955);// 14^09
      //  me->AddDelayedEvent(30000, [this]() -> void
        {
            if (Creature* kiljedan = instance->instance->GetCreature(instance->GetGuidData(NPC_KILDJEDAN_AVATARA)))
            {
                kiljedan->GetMotionMaster()->MovePoint(0, 6748.58f, -795.00f, 1527.00f);
               // kiljedan->AddDelayedEvent(4000, [kiljedan]() -> void
                {
                    kiljedan->SetVisible(false);
              //  });
            }
       // });

        //me->AddDelayedEvent(58000, [this]() -> void
        {
          //  if (Creature* velen = summons.GetCreature(121170))
            {
               // velen->SetCanFly(false);
              //  velen->GetMotionMaster()->MovePoint(0, 6748.58f, -795.00f, 1527.00f);
              //  velen->AddDelayedEvent(4000, [velen]() -> void
                {
                  //  velen->SetVisible(false);
               // });
            }
      //  });

       // me->AddDelayedEvent(115000, [this]() -> void
       // {
        //    for (auto id : { 121171, 121169 })
              //  if (Creature* add = summons.GetCreature(id))
                {
                    //add->SetCanFly(false);
                   // add->GetMotionMaster()->MovePoint(0, 6748.58f, -795.00f, 1527.00f);
                    //add->AddDelayedEvent(3000, [add]() -> void
                  //  {
                     //   add->SetVisible(false);
                  //  });
                }
        //});

        /*  instance->instance->ApplyOnEveryPlayer([&](Player* player)
          {
              if (me->GetThreatTarget(player->GetGUID()))
                  me->CastSpell(player, SPELL_BONUS, true);
           });*/
  //  }

   /* void SetGUID(const ObjectGuid& guid, int32 id) override
    {
        if (Creature* add = instance->instance->GetCreature(guid))
        {
            std::pair<const uint32, Position>* selected = nullptr;
            for (auto& pair : localFloorBlocks)
            {
                float dist = add->GetDistance(pair.second);
                if (!selected || dist > add->GetDistance(selected->second))
                {
                    if (add->GetPositionZ() <= 1509.4f && dist > 12.0f)
                        continue;

                    selected = &pair;
                }
            }

            if (selected)
            {
                if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(selected->first)))
                    go->AddDelayedEvent(6000, [go]() -> void
                {
                    go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED, nullptr, false);
                });

                localFloorBlocks.erase(selected->first);
            }
        }
    }
    */
  /*  void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode();
        me->NearTeleportTo(me->GetHomePosition());

        //instance->instance->ApplyOnEveryPlayer([](Player* player) -> void
        {
           // if (player->GetPositionZ() < 1660.0f)
           //     player->NearTeleportTo(6502.62f, -795.02f, 1663.58f, 0.0f);
       // });
    }
        */
   /* void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_CORRUPTED_BLADE:
            summon->SetReactState(REACT_PASSIVE);
          //  if (Unit* target = summon->GetTargetUnit())
            {
               // summon->CastSpell(target, SPELL_CORRUPTED_BLADE);
               // summon->CastSpell(target, SPELL_CORRUPTED_BLADE_1); // 236604
                //summon->AddDelayedEvent(7000, [summon]() -> void
                {
                    summon->CastSpell(summon, SPELL_CORRUPTED_BLADE_REMOVE);
                    summon->DespawnOrUnsummon(2000);
               // });
            }
            break;
        case NPC_PILONES:
            pilones.push_back({ summon->GetGUID(), 0 });
            break;
        }

        BossAI::JustSummoned(summon);
    }
        */
  //  void DamageTaken(Unit* attacker, uint32& damage) override
 /*   {
        if (!isSecondPhase)
            if (me->HealthBelowPct(20))
   *///         {

   //             events.Reset();
   //             events.RescheduleEvent(EVENT_FORCE_SECOND_PHASE, 1);
   //         }
 //   }
/*
    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (me->IsAlive() && !me->IsInCombat() && who->GetDistance(me) <= 19.0f)
            AttackStart(who);

        if (me->GetDistance(who) < 100.0f && !IntroDone)
        {
            IntroDone = true;
            if (Creature* kiljedan = instance->instance->GetCreature(instance->GetGuidData(NPC_KILDJEDAN_AVATARA)))
            {
                kiljedan->CastSpell(kiljedan, 242902);
              //  kiljedan->AddDelayedEvent(27000, [kiljedan, this]() -> void
                {
                    kiljedan->CastSpell(me, 240897);
                  //  me->AddDelayedEvent(3000, [this]() -> void
                    {
                    //    me->SetAnimKitId(12758);
                    //    me->AddDelayedEvent(10000, [this]() -> void
                        {
                            DoCast(SPELL_VISUAL_SWORD);
                      //  });
                  //  });

                 //   kiljedan->AddDelayedEvent(13000, [kiljedan]() -> void
                    {
                        kiljedan->CastSpell(kiljedan, 240923);
                   // });
               // });
            }
        }
    }
    */
   /* void SpellFinishCast(const SpellInfo* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_CONSUME:
            if (Creature* maiden = summons.GetCreature(NPC_AVATARA_MAIDEN))
            {
                if (maiden->GetHealth() + me->GetHealth() >= me->GetMaxHealth())
                    me->SetHealth(me->GetMaxHealth());
                else
                    me->SetHealth(maiden->GetHealth() + me->GetHealth());

                maiden->CastSpell(maiden, SPELL_REMOVE_BEAMS);
                me->Kill(maiden);

                summons.DespawnAll();
            }
            break;
        case SPELL_ANNIHILATION:
            Talk(SAY_ANNIHILANT);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // sometimes it's broke after maiden dead
            instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, me);

            if (GameObject* go = me->GetMap()->GetGameObject(instance->GetGuidData(GO_AVATARA_FLOOR)))  // destroy room
                go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED, nullptr, false);

            me->RemoveAurasDueToSpell(74426); // hack

            me->AddDelayedCombat(500, [this]() -> void
            {
                SetCombatMovement(true);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveJump({ me->GetPositionX(), me->GetPositionY(), 1509.9f }, 40, 40);
                me->SetCanFly(false);

                // second phase
                events.RescheduleEvent(EVENT_DESOLATE, 19000);
                events.RescheduleEvent(EVENT_RUPTURE_REALISTIC_AND_ENERGY, 6000);
                events.RescheduleEvent(EVENT_DARK_MARK, (IsMythicRaid() ? 31000 : 21000));
                if (IsHeroicPlusRaid())
                    me->CastSpell(me, SPELL_BLACK_WIND_TICKS, true);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_RAIN, 16000);

                me->AddDelayedCombat(2000, [this]() -> void
                {
                    DoCast(me, SPELL_SEAR, true);
                });
                me->SetDisplayId(74497);

                me->AddDelayedCombat(5000, [this]() -> void
                {
                    //  me->GetMotionMaster()->MovementExpired();
                    for (auto pair : perephaseEvent)
                        if (Creature* cre = me->SummonCreature(pair.first, pair.second.first))
                        {
                            cre->SetWalk(false);
                            cre->GetMotionMaster()->MoveSmoothFlyPath(0, pair.second.second);
                            cre->SetCanFly(true);
                        }
                    me->CastSpellDelay(me, SPELL_CONVERS_EVENT_1, false, 3000);
                });

                me->AddDelayedCombat(7000, [this]() -> void
                {
                    instance->instance->ApplyOnEveryPlayer([](Player* player) -> void
                    {
                        if (player->GetPositionZ() >= 1643.75f)
                            player->NearTeleportTo(6557.89f, -872.24f, 1508.68f, 0.92f);
                    });
                });
            });
            break;
        case SPELL_RUPTURE_REALISTIC_2:
            for (auto pair : localFloorBlocks)
                if (me->GetDistance(pair.second) <= 30.0f)
                {
                    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(pair.first)))
                        go->AddDelayedEvent(me->GetDistance(pair.second) * 3 + 1, [go]() -> void
                    {
                        go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED, nullptr, false);
                    });

                    localFloorBlocks.erase(pair.first);
                }
            break;
        }
    }

    uint32 GetModifyedData(uint32) override
    {
        return m_darkMarkTimers.popAndSafeLast();
    }
    */
  /*  void UpdateAI(uint32 diff) override
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
            case EVENT_FORCE_SECOND_PHASE:
                isSecondPhase = true;
                DoCast(SPELL_REMOVE_BEAMS);
                DoCast(SPELL_CONSUME);
             //   me->AddDelayedEvent(500, [this]() -> void
                {
                    DoCast(SPELL_ANNIHILATION);
              //  });

                me->SetPower(me->GetPowerType(), 0);
                break;
            case EVENT_SHADOWY_BLADES:
            {
                Talk(SAY_BLADES);
                DoCast(SPELL_SHADOWY_BLADES);

                auto threatlist = me->getThreatManager().getThreatList();
                threatlist.remove_if([](HostileReference* ref)
                {
                    return !ref->getTarget()->IsPlayer();
                });

                for (uint8 i = 0; i < (IsMythic() ? 5 : 3); ++i)
                {
                    if (threatlist.empty())
                        break;

                    auto itr = threatlist.begin();
                    std::advance(itr, urand(0, threatlist.size() - 1));

                  //  if (Unit* target = (*itr)->getTarget())
                       // me->SummonCreature(NPC_CORRUPTED_BLADE, bladesPositions[i], target->GetGUID(), TEMPSUMMON_TIMED_DESPAWN, 11000);

                //    threatlist.remove(*itr);
                }

                events.RescheduleEvent(EVENT_SHADOWY_BLADES, m_shadowBladesTimers.popAndSafeLast());
                break;
            }
            case EVENT_RUPTURE_REALISTIC:
                Talk(SAY_RUPTURE_1);
                Talk(SAY_RUPTURE_2);
                DoCast(SPELL_RUPTURE_REALISTIC);
                events.RescheduleEvent(EVENT_RUPTURE_REALISTIC, m_ruptureRealisticTimers.popAndSafeLast());
                break;
            case EVENT_UNBOUND_CHAOS:
                DoCast(SPELL_UNBOUND_CHAOS);
                Talk(SAY_CHAOS);
                events.RescheduleEvent(EVENT_UNBOUND_CHAOS, m_unboundChaosTimers.popAndSafeLast());
                break;
            case EVENT_DESOLATE:
               // DoCastTopAggro(SPELL_DESOLATE, false, true);
                events.RescheduleEvent(EVENT_DESOLATE, 13000);
                break;
            case EVENT_SELECT_PILONE:
                DoCast(SPELL_ACTIVATE_PILONES);
                if (!pilones.empty())
                {
                    std::vector<std::pair<ObjectGuid, uint8>*> freePilones{};
                    for (auto& pair : pilones)
                    {
                        if (pair.second == 1)
                            pair.second = 0;

                        if (pair.second == 0)
                            freePilones.push_back(&pair);
                    }

                   // if (!freePilones.empty())
                    {
                   //     uint8 i = urand(0, freePilones.size() - 1);
                      //  if (Creature* summon = Unit::GetCreature(*me, freePilones[i]->first))
                         //   summon->CastSpell(summon, SPELL_PILONE_ACTIVATE);

                      //  freePilones[i]->second = 1;
                    }
                }

                events.RescheduleEvent(EVENT_SELECT_PILONE, (IsMythic() ? 12000 : 40000) + 10000);
                break;
            case EVENT_SELECT_PILONE_FEL:
            {
                if (!pilones.empty())
                {
                    std::vector<std::pair<ObjectGuid, uint8>*> freePilones{};
                    for (auto& pair : pilones)
                    {
                        if (pair.second == 2)
                            pair.second = 0;

                        if (pair.second == 0)
                            freePilones.push_back(&pair);
                    }

                    if (!freePilones.empty())
                    {
                        Trinity::Containers::RandomResize(freePilones, 2);

                      //  for (auto& pair : freePilones)
                        {
                           // if (Creature* summon = Unit::GetCreature(*me, pair->first))
                           //     summon->CastSpell(summon, SPELL_FEL_PILONE_ACTIVATE);

                          //  pair->second = 2;
                        }
                    }
                }

                events.RescheduleEvent(EVENT_SELECT_PILONE_FEL, 49000 + 10000);
                break;
            }
            case EVENT_CHECK_ENERGY:
                if (isSecondPhase)
                    break;

                me->SetPower(me->GetPowerType(), me->GetPower(me->GetPowerType()) + 1);

               // if ((me->GetPower(me->GetPowerType()) >= 100 && summons.GetCreature(NPC_AVATARA_MAIDEN) && summons.GetCreature(NPC_AVATARA_MAIDEN)->isAlive())
                //    || (summons.GetCreature(NPC_AVATARA_MAIDEN) && !summons.GetCreature(NPC_AVATARA_MAIDEN)->isAlive()))
                {
                    isSecondPhase = true;
                    events.Reset();
                    DoCast(SPELL_REMOVE_BEAMS);
                    DoCast(SPELL_CONSUME);
                 //   me->AddDelayedEvent(500, [this]() -> void
                    {
                        DoCast(SPELL_ANNIHILATION);
                   // });

                    me->SetPower(me->GetPowerType(), 0);
                    break;
                }

                if (me->GetVictim() && !me->IsWithinMeleeRange(me->GetVictim()))
                    DoCast(236528);

                if (!isSecondPhase)
                    events.RescheduleEvent(EVENT_CHECK_ENERGY, urand(4000, 5000));
                break;
            case EVENT_RUPTURE_REALISTIC_AND_ENERGY:

                if (isSecondPhase)
                    if (!me->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
                    {
                        //float tz = me->GetHeight(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), false, MAX_FALL_DISTANCE);
                       // if (tz <= 1509.7f) // fall under water
                            me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), 1508.80f, me->GetOrientation());
                      //  else
                            me->GetMotionMaster()->MoveFall(0);
                    }


                if (me->GetPower(me->GetPowerType()) >= 100)
                {
                    DoCast(SPELL_RUPTURE_REALISTIC_2);
                    Talk(SAY_RUPTURE_1);
                    Talk(SAY_RUPTURE_2);
                }
                else
                    me->SetPower(me->GetPowerType(), me->GetPower(me->GetPowerType()) + 3);

                events.RescheduleEvent(EVENT_RUPTURE_REALISTIC_AND_ENERGY, 1000);
                break;
            case EVENT_DARK_MARK:
                m_darkMarkTimers = MySpecialList<uint32>({ 6000, 8000, 10000 });
                DoCast(SPELL_DARK_MARK);
                events.RescheduleEvent(EVENT_DARK_MARK, IsMythic() ? 25000 : 34000);
                break;
            case EVENT_TOUCH_OF_SARGERAS:
            {
                DoCast(SPELL_TOUCH_OF_SARGERAS_CAST);
              //  me->AddDelayedCombat(2500, [this]() -> void
                {
                    std::vector<Position> positions = sargerasPositions;

                    Trinity::Containers::RandomResize(positions, IsMythic() ? 4 : 3);
                    for (const auto& pos : positions)
                        me->CastSpell(pos.GetPositionX() + frand(-5, 5), pos.GetPositionY() + frand(-5, 5), pos.GetPositionZ(), SPELL_TOUCH_OF_SARGERAS_SUM, true);
               // });
                events.RescheduleEvent(EVENT_TOUCH_OF_SARGERAS, IsMythic() ? 63000 : 45000);
                break;
            }
            case EVENT_RAIN:
            {
              //  auto blocks = localFloorBlocks;

               // Trinity::Containers::RandomResize(blocks, 7);
               // uint8 i = 1;
                //for (const auto& pair : blocks)
              //  {
                  //  me->AddDelayedCombat(i++ * 50 + 10, [this, pair]() -> void
                   // {
                        me->CastSpell(pair.second.GetPositionX() + frand(-3, 3), pair.second.GetPositionY() + frand(-3, 3), pair.second.GetPositionZ(), SPELL_RAIN_OF_THE_DESTROYER_SUM, true);
                  //  });
                }

                events.RescheduleEvent(EVENT_RAIN, 35000);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};*/
/*
// 117264
struct npc_avatara_maiden : public ScriptedAI
{
    npc_avatara_maiden(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->SetPower(me->GetPowerType(), 0);
    }
/*
    void EnterCombat(Unit* who) override
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->SetPower(me->GetPowerType(), 0);

        events.RescheduleEvent(1, 1000);

       // if (who)
            //me->AddDelayedCombat(500, [&]() -> void
        {
         //   if (Unit* owner = me->GetOwner())
          //      if (!owner->IsInCombat())
          //          DoZoneInCombat(owner->ToCreature());
      //  });

      //  me->AddUnitState(UNIT_STATE_MOVE_IN_CASTING);
    }
    */
   // void IsSummonedBy(Unit*) override
//   {
 //       me->SetReactState(REACT_PASSIVE);
 //   }

   // void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode /*mode*/, bool apply) override
  /*  {
        if (spellId == SPELL_CLEANING_PROTOCOL_ABSORB && !apply)
        {
            me->SetPower(me->getPowerType(), 0);
            DoCast(me, SPELL_MALFUNCTION, true);
            me->DealDamage(me, me->GetMaxHealth()*0.25);
        }
    }
    */
 /*   void UpdateAI(uint32 diff) override
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
            case 1:
                if (me->GetPower(me->GetPowerType()) >= 100 && !me->HasAura(SPELL_CLEANING_PROTOCOL_ABSORB))
                {
                    me->CastCustomSpell(SPELL_CLEANING_PROTOCOL_ABSORB, SPELLVALUE_BASE_POINT0, me->GetMaxHealth() * 0.05, me);
                    DoCast(SPELL_CLEANING_PROTOCOL);
                    Talk(0);
                    Talk(1);
                }
                events.RescheduleEvent(1, 1000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};
*/
/*
// 117279
struct npc_avatara_pilones : public ScriptedAI
{
    npc_avatara_pilones(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;
    ObjectGuid selectedGuid{};

    void Reset() override
    {
        events.Reset();
    }

 //   void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode //*mode*///, bool apply) override
/*    {
        if (spellId == SPELL_PILONE_ACTIVATE)
        {
            if (apply)
            {
                events.RescheduleEvent(EVENT_1, 100);
                if (!me->GetMap()->IsMythicRaid())
                    if (Aura* aura = me->GetAura(SPELL_PILONE_ACTIVATE))
                        aura->SetDuration(39500);
            }
            else
            {
                events.Reset();
                if (!selectedGuid.IsEmpty())
                    if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                        if (selected->IsInWorld())
                            selected->CastSpell(selected, SPELL_REMOVE_BEAMS, true);
            }
        }
        else if (spellId == SPELL_FEL_PILONE_ACTIVATE)
        {
            if (apply)
                events.RescheduleEvent(EVENT_2, 100);
            else
            {
                events.Reset();
                if (!selectedGuid.IsEmpty())
                    if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                        if (selected->IsInWorld())
                            selected->CastSpell(selected, SPELL_REMOVE_BEAMS, true);
            }
        }
    }
    */
  /*  void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
            {
                if (Unit* owner = me->GetOwner())
                {
                    //if (Unit* target = me->GetTargetUnit())
                    {
                        ObjectGuid tempSelectedGuid{};
                        //if (target->IsInBetween(owner, me, 3.0f))
                          //  tempSelectedGuid = target->GetGUID();
                      //  else
                            tempSelectedGuid = owner->GetGUID();

                        if (!selectedGuid.IsEmpty() && tempSelectedGuid != selectedGuid)
                            if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                                selected->CastSpell(selected, SPELL_REMOVE_BEAMS, true);

                        selectedGuid = tempSelectedGuid;

                        if (!selectedGuid.IsEmpty())
                            if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                            {
                                if (!selected->HasAura((selected == owner ? SPELL_BEAM_ON_BOSS : SPELL_BEAM_ON_MAIDEN)))
                                    me->CastSpell(selected, (selected == owner ? SPELL_BEAM_ON_BOSS : SPELL_BEAM_ON_MAIDEN));
                                if (selected != owner && urand(1, 4) == 1)
                                    selected->CastSpell(selected, 233961);

                                for (uint32 spell : {SPELL_BEAM_COND, SPELL_SPARK_OF_THE_DARK_TITAN})
                                    if (!selected->HasAura(spell))
                                        selected->CastSpell(selected, spell);
                            }
                    }
                }
                events.RescheduleEvent(1, 1000);
                break;
            }
            case 2:
            {
               // auto* owner = me->GetAnyOwner();
               // if (!owner)
                //    break;
              //  ObjectGuid tempSelectedGuid = owner->GetGUID();
                if (!selectedGuid.IsEmpty())
                    if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                        //if (selected->IsInBetween(owner, me, 3.0f))
                         //   tempSelectedGuid = selectedGuid;

                const auto& players = me->GetMap()->GetPlayers();
                //for (auto& itr : players)
                {
                  //  Unit* player = itr.GetSource();
                  //  if (player->IsInBetween(owner, me, 3.0f))
                        //if (Unit* tempSelected = ObjectAccessor::GetUnit(*me, tempSelectedGuid))
                          //  if (me->GetDistance(tempSelected) > me->GetDistance(player))
                             //   tempSelectedGuid = player->GetGUID();
                }

                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* maiden = instance->instance->GetCreature(instance->GetGuidData(NPC_AVATARA_MAIDEN)))
                        //if (Unit* tempSelected = ObjectAccessor::GetUnit(*me, tempSelectedGuid))
                       //     if (maiden->IsInBetween(owner, me, 3.0f))
                             //   if (me->GetDistance(tempSelected) > me->GetDistance(maiden))
                             //       tempSelectedGuid = maiden->GetGUID();


              //  if (!selectedGuid.IsEmpty() && tempSelectedGuid != selectedGuid)
                    if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                    {
                        selected->CastSpell(selected, SPELL_REMOVE_BEAMS, true);
                        if (selected->IsPlayer())
                            if (selected->GetAuraCount(SPELL_TAINTED_ESSENCE) >= 10)
                                selected->CastSpell(selected, SPELL_TAINTED_ESSENCE_KILL);
                    }

             //   selectedGuid = tempSelectedGuid;

                if (!selectedGuid.IsEmpty())
                    if (Unit* selected = ObjectAccessor::GetUnit(*me, selectedGuid))
                    {
                        if (selected->IsPlayer())
                        {
                            if (!selected->HasAura(SPELL_BEAM_ON_PLAYER_FEL))
                                me->CastSpell(selected, SPELL_BEAM_ON_PLAYER_FEL);

                            if (!selected->HasAura(SPELL_BEAM_ON_PLAYER))
                                selected->AddAura(SPELL_BEAM_ON_PLAYER, selected);
                        }
                        else if (selected->GetEntry() == NPC_AVATARA_MAIDEN)
                            selected->CastSpell(selected, SPELL_BEAM_ON_MAIDEN_FEL);
                        else if (selected->GetEntry() == NPC_FALLEN_AVATAR)
                        {
                            selected->CastSpell(selected, SPELL_BEAM_ON_BOSS_FEL);
                            me->CastSpell(me, SPELL_BEAM_ON_BOSS_FEL_VIS);
                        }
                    }
                events.RescheduleEvent(2, 1000);
                break;
            }
            }
        }

    }
};*/

// 120838
struct npc_tos_touch_of_sargeras : public ScriptedAI
{
    npc_tos_touch_of_sargeras(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void IsSummonedBy(Unit* owner) override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_TOUCH_OF_SARGERAS_AT);
        DoCast(SPELL_TOUCH_OF_SARGERAS_VIS);
        events.RescheduleEvent(1, 8000 + 3000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
            {
                bool hasPlayer = false;
                const auto& players = me->GetMap()->GetPlayers();
                for (const auto& player : players)
                    if (me->GetDistance(player.GetSource()) <= 6)
                    {
                        hasPlayer = true;
                        break;
                    }


                DoCast(me, hasPlayer ? SPELL_TOUCH_OF_SARGERAS_DMG : SPELL_TOUCH_OF_SARGERAS_NOT_CLOSE);
                me->RemoveAllAuras();
                //me->RemoveAllAreaObjects();

                me->DespawnOrUnsummon(100);
                break;
            }
            }
        }

    }
};

// 120961
struct npc_tos_rain_of_destroyer : public ScriptedAI
{
    npc_tos_rain_of_destroyer(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void IsSummonedBy(Unit* owner) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(me, SPELL_RAIN_OF_THE_DESTROYER_AT);
        me->CastSpell(me, SPELL_RAIN_OF_THE_DESTROYER_VIS);
        events.RescheduleEvent(1, 6000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
            {
                bool hasPlayer = false;
                const auto& players = me->GetMap()->GetPlayers();
                for (const auto& player : players)
                    if (me->GetDistance(player.GetSource()) <= 4)
                    {
                        hasPlayer = true;
                        break;
                    }


                DoCast(me, hasPlayer ? SPELL_RAIN_OF_THE_DESTROYER_CLOSE : SPELL_RAIN_OF_THE_DESTROYER_AOE);
                if (!hasPlayer)
                    if (Unit* owner = me->GetOwner())
                        owner->ToCreature()->AI()->SetGUID(me->GetGUID());

                me->DespawnOrUnsummon(6200);
                break;
            }
            }
        }

    }
};


// 239132 235572
class spell_tos_rupture_realistic : public SpellScript
{
    PrepareSpellScript(spell_tos_rupture_realistic);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();

        if (!caster || !target)
            return;

        float dist = caster->GetDistance(target);
        if (dist < 40.0f)
            SetHitDamage(GetHitDamage() * (0.1f + 0.9f*(40.0f - dist) / 40.0f));
        else
            SetHitDamage(GetHitDamage() * 0.1f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_rupture_realistic::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 239742
class spell_tos_dark_mark : public SpellScript
{
    PrepareSpellScript(spell_tos_dark_mark);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();

        if (!caster || !target || target == caster)
            return;

        caster->CastSpell(target, 239819);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_dark_mark::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};
/*
// 234873
class spell_tos_avatara_energy : public AuraScript
{
    PrepareAuraScript(spell_tos_avatara_energy);

    bool isFirstTick = true;

   // void OnTick(AuraEffect const* /*aurEff*///)
/*    {
        Unit* target = GetTarget();
        if (!target)
            return;

        target->SetPower(target->GetPowerType(), target->GetPower(target->GetPowerType()) + ((isFirstTick || urand(1, 100) == 90) ? 3 : 2));
        isFirstTick = false;
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_avatara_energy::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};*/
/*
// 238460
class spell_tos_shadow_blades : public SpellScript
{
    PrepareSpellScript(spell_tos_shadow_blades);

//  */ //void HandleDummy(SpellEffIndex /*effectIndex*/)
 /*   {
        auto* caster = GetCaster();
        auto* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, (caster->GetMap()->IsHeroic() ? 236604 : 240970));
    }

    void Register() override
    {
   //     OnEffectHitTarget += SpellEffectFn(spell_tos_shadow_blades::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
    }
};


// 239417
class spell_tos_black_winds : public AuraScript
{
    PrepareAuraScript(spell_tos_black_winds);

  *///  void OnTick(AuraEffect const* /*aurEff*/)
  /*  {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint8 i = urand(0, 9);
        Position start = windsPos[i];
        Position end = windsPos[i];

        if (i <= 4)
            end.m_positionX += 118.0f;
        else
            end.m_positionY -= 118.0f;

        if (urand(1, 2) == 2)
            std::swap(start, end);


        if (Creature* add = caster->SummonCreature(NPC_BLACK_WINDS, start, TEMPSUMMON_TIMED_DESPAWN, 10000))
        {
            add->SetReactState(REACT_PASSIVE);
            add->CastSpell(add, SPELL_BLACK_WIND_VIS);
            add->CastSpell(add, SPELL_BLACK_WIND_AT);
           // add->AddDelayedEvent(1000, [add, end]() -> void
           // {
                add->GetMotionMaster()->MovePoint(0, end);
          //  });
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_black_winds::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 236682
class spell_tos_fel_infusion : public AuraScript
{
    PrepareAuraScript(spell_tos_fel_infusion);

   */// void OnTick(AuraEffect const* /*aurEff*/)
  /*  {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetPositionZ() <= 1508.9f || (caster->GetPositionX() >= 6667.59f && caster->GetPositionZ() <= 1540.68f))
            caster->CastSpell(caster, SPELL_FEL_INFUSION_BUFF);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_fel_infusion::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 239739
class spell_tos_black_mark_aura : public AuraScript
{
    PrepareAuraScript(spell_tos_black_mark_aura);

   */// void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
 /*   {
        if (!GetCaster() || !GetTarget())
            return;

        Creature* cre = GetCaster()->ToCreature();
        Unit* target = GetTarget();
        if (!cre || !target)
            return;

     //   uint32 timer = cre->AI()->GetModifyedData(1);

      //  GetAura()->SetDuration(timer);
    }

    void Register()
    {
        OnEffectApply += AuraEffectApplyFn(spell_tos_black_mark_aura::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};
*/
void AddSC_boss_fallen_avatar()
{
   // RegisterCreatureAI(boss_fallen_avatar);
   // RegisterCreatureAI(npc_avatara_maiden);
   // RegisterCreatureAI(npc_avatara_pilones);
    RegisterCreatureAI(npc_tos_touch_of_sargeras);
    RegisterCreatureAI(npc_tos_rain_of_destroyer);
    RegisterSpellScript(spell_tos_rupture_realistic);
    RegisterSpellScript(spell_tos_dark_mark);
  //  RegisterAuraScript(spell_tos_avatara_energy);
  //  RegisterSpellScript(spell_tos_shadow_blades);
  //  RegisterAuraScript(spell_tos_black_winds);
  //  RegisterAuraScript(spell_tos_fel_infusion);
  //  RegisterAuraScript(spell_tos_black_mark_aura);
}
