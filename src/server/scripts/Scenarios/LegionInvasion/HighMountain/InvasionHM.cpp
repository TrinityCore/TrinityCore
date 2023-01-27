/*
    http://uwow.biz
    Invasion HM
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"

// 119850
class npc_invasion_hm_mayla : public CreatureScript
{
public:
    npc_invasion_hm_mayla() : CreatureScript("npc_invasion_hm_mayla") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_hm_maylaAI(creature);
    }

      struct npc_invasion_hm_maylaAI : ScriptedAI
      {
         npc_invasion_hm_maylaAI(Creature* creature) : ScriptedAI(creature) 
         {
            me->Respawn(true); // avoid bugs
         }
        
         bool _introDone = false;

         void DoAction(int32 const action) override
         {
            me->AddDelayedEvent(3000, [this]() -> void
            {
                me->CreateConversation(4684);
            });
            me->RemoveAura(68442);
            me->GetMotionMaster()->MovePath(10993802, false); // 12
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
         }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 20.0f))
            {
                _introDone = true;
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT, 57177);
                Talk(0);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 10)
                {
                    if (Creature* infernal = me->SummonCreature(119986, 4127.87f, 4476.00f, 660.0f))
                    {
                        infernal->CastSpell(infernal, 205266);
                        infernal->CastSpell(infernal, 233004);
                    }
                    Talk(4);
                }
                if (id == 13)
                    Talk(5);
                if (id == 26)
                    me->CreateConversation(4962);
            }
        }

    };
};

// 119857
class npc_invasion_hm_eagles : public CreatureScript
{
public:
    npc_invasion_hm_eagles() : CreatureScript("npc_invasion_hm_eagles") {}

    struct npc_invasion_hm_eaglesAI : ScriptedAI
    {
        npc_invasion_hm_eaglesAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            SetFlyMode(true);
            if (who->IsPlayer())
            {
                me->GetMotionMaster()->MovePath(10993801, false);
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 57189);
            }
        }

        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;

            if (me->GetVehicleKit() && pointId == 17)
            {
                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                    if (passenger->IsPlayer())
                        passenger->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 57209);
                    passenger->AddAura(55001, passenger);
                    me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_hm_eaglesAI(creature);
    }
};

// 119994 119981 120048
class npc_invasion_hm_misc : public CreatureScript
{
public:
    npc_invasion_hm_misc() : CreatureScript("npc_invasion_hm_misc") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_hm_miscAI(creature);
    }

    struct npc_invasion_hm_miscAI : ScriptedAI
    {
        npc_invasion_hm_miscAI(Creature* creature) : ScriptedAI(creature) {}

        void OnSpellClick(Unit* clicker) override
        {
            if (!clicker->IsPlayer())
                return;

            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

            if (me->GetEntry() == 119994)
            {
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 57210);
                if (Creature* tauren = me->FindNearestCreature(119993, 10.0f, true))
                {
                    tauren->SetWalk(false);
                    tauren->GetMotionMaster()->MoveRandom(5.0f);
                    tauren->DespawnOrUnsummon(1000);
                }
                me->DespawnOrUnsummon(10);
            }
            else if (me->GetEntry() == 119981)
            {
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 57211);
                me->RemoveAura(164141);
            }
        }
    };
};

void AddSC_InvasionHM()
{
    new npc_invasion_hm_mayla();
    new npc_invasion_hm_eagles();
    new npc_invasion_hm_misc();
};