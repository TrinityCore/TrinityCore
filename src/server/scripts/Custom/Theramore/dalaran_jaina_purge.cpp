#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "CreatureGroups.h"

#include <iostream>

//npc_displaced_sunreaver

enum NPCs
{
    NPC_JAINA_PROUDMOORE        = 100045,
    NPC_DISPLACED_SUNREAVER     = 100048
};

enum Spells
{
    SPELL_FIREBALL              = 100002,
    SPELL_BLIZZARD              = 100001,
    SPELL_TELEPORT              = 51347,
    SPELL_DIRECT_TELEPORT       = 100045,
    SPELL_AURA_OF_BRILLANCE     = 31260
};

enum Misc
{
    // Jaina's casting
    CASTING_BLIZZARD            = 1,

    SAY_JAINA_TELEPORT          = 0,
    SAY_JAINA_SLAIN             = 1
};

class npc_displaced_sunreaver : public CreatureScript
{
    public:
    npc_displaced_sunreaver() : CreatureScript("npc_displaced_sunreaver") {}

    struct npc_displaced_sunreaverAI : public ScriptedAI
    {
        npc_displaced_sunreaverAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize() { }

        void Teleport()
        {
            DoCastSelf(SPELL_TELEPORT);

            me->SetFaction(35);
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            me->GetMotionMaster()->Clear();
            me->DespawnOrUnsummon(1s);
        }

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            me->GetMotionMaster()->Clear();

            me->SetReactState(REACT_AGGRESSIVE);
            me->Attack(attacker, true);
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
            me->SetReactState(REACT_DEFENSIVE);
            me->SetRespawnDelay(30);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                Creature* jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 30.f);
                if (jaina)
                {
                    if (!IsFleeing)
                    {
                        me->GetMotionMaster()->MoveFleeing(jaina);
                        IsFleeing = true;
                    }
                }
                else
                {
                    if (IsFleeing)
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
                        IsFleeing = false;
                    }
                }
            }
            else
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_displaced_sunreaverAI(creature);
    }
};

class dalaran_jaina_purge : public CreatureScript
{
    public:
    dalaran_jaina_purge() : CreatureScript("dalaran_jaina_purge") {}

    struct dalaran_jaina_purgeAI : public ScriptedAI
    {
        dalaran_jaina_purgeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            teleport = false;
            teleportTimer = 10 * IN_MILLISECONDS;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->AddAura(SPELL_AURA_OF_BRILLANCE, me);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetEntry() == NPC_DISPLACED_SUNREAVER)
            {
                Talk(SAY_JAINA_SLAIN);

                teleportTimer = 15 * IN_MILLISECONDS;
            }
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                SetCombatMovement(false);
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(CASTING_BLIZZARD, 2s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                if (teleportTimer <= diff)
                {
                    if (Creature* sunreaver = GetClosestCreatureWithEntry(me, NPC_DISPLACED_SUNREAVER, 30.f))
                    {
                        Talk(SAY_JAINA_TELEPORT);

                        DoCast(sunreaver, SPELL_DIRECT_TELEPORT);
                        ENSURE_AI(npc_displaced_sunreaver::npc_displaced_sunreaverAI, sunreaver->AI())->Teleport();
                        teleportTimer = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
                    }
                }
                else teleportTimer -= diff;
            }
            else
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_BLIZZARD:
                            if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_BLIZZARD);
                            events.RescheduleEvent(CASTING_BLIZZARD, 14s, 25s);
                            break;

                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_FIREBALL);
            }
        }

        private:
        EventMap events;
        bool teleport;
        uint32 teleportTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new dalaran_jaina_purgeAI(creature);
    }
};

void AddSC_dalaran_jaina_purge()
{
    new dalaran_jaina_purge();
    new npc_displaced_sunreaver();
}
