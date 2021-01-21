/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*######
## Quest 12027: Mr. Floppy's Perilous Adventure
######*/

enum Floppy
{
    // Creature
    NPC_MRFLOPPY                = 26589,
    NPC_HUNGRY_WORG             = 26586,
    NPC_RAVENOUS_WORG           = 26590,   // RWORG
    NPC_EMILY                   = 26588,
    // Quest
    QUEST_PERILOUS_ADVENTURE    = 12027,
    // Spell
    SPELL_MRFLOPPY              = 47184,   // vehicle aura
    // Text
    SAY_WORGHAGGRO1             = 0, // Um... I think one of those wolves is back...
    SAY_WORGHAGGRO2             = 1, // He's going for Mr. Floppy!
    SAY_WORGRAGGRO3             = 2, // Oh, no! Look, it's another wolf, and it's a biiiiiig one!
    SAY_WORGRAGGRO4             = 3, // He's gonna eat Mr. Floppy! You gotta help Mr. Floppy! You just gotta!
    SAY_RANDOMAGGRO             = 4, // There's a big meanie attacking Mr. Floppy! Help!
    SAY_VICTORY1                = 5, // Let's get out of here before more wolves find us!
    SAY_VICTORY2                = 6, // Don't go toward the light, Mr. Floppy!
    SAY_VICTORY3                = 7, // Mr. Floppy, you're ok! Thank you so much for saving Mr. Floppy!
    SAY_VICTORY4                = 8, // I think I see the camp! We're almost home, Mr. Floppy! Let's go!
    TEXT_EMOTE_WP1              = 9, // Mr. Floppy revives
    TEXT_EMOTE_AGGRO            = 10, // The Ravenous Worg chomps down on Mr. Floppy
    SAY_QUEST_ACCEPT            = 11, // Are you ready, Mr. Floppy? Stay close to me and watch out for those wolves!
    SAY_QUEST_COMPLETE          = 12  // Thank you for helping me get back to the camp. Go tell Walter that I'm safe now!
};

// emily
class npc_emily : public CreatureScript
{
public:
    npc_emily() : CreatureScript("npc_emily") { }

    struct npc_emilyAI : public EscortAI
    {
        npc_emilyAI(Creature* creature) : EscortAI(creature) { }

        void JustSummoned(Creature* summoned) override
        {
            if (Creature* Mrfloppy = GetClosestCreatureWithEntry(me, NPC_MRFLOPPY, 50.0f))
                summoned->AI()->AttackStart(Mrfloppy);
            else
                summoned->AI()->AttackStart(me->GetVictim());
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 9:
                    if (Creature* Mrfloppy = GetClosestCreatureWithEntry(me, NPC_MRFLOPPY, 100.0f))
                        _mrfloppyGUID = Mrfloppy->GetGUID();
                    break;
                case 10:
                    if (ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                    {
                        Talk(SAY_WORGHAGGRO1);
                        me->SummonCreature(NPC_HUNGRY_WORG, me->GetPositionX()+5, me->GetPositionY()+2, me->GetPositionZ()+1, 3.229f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    }
                    break;
                case 11:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                        Mrfloppy->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                    break;
                case 17:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                        Mrfloppy->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    Talk(SAY_WORGRAGGRO3);
                    if (Creature* RWORG = me->SummonCreature(NPC_RAVENOUS_WORG, me->GetPositionX()+10, me->GetPositionY()+8, me->GetPositionZ()+2, 3.229f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000))
                    {
                        RWORG->SetFaction(FACTION_FRIENDLY);
                        _RavenousworgGUID = RWORG->GetGUID();
                    }
                    break;
                case 18:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                    {
                        if (Creature* RWORG = ObjectAccessor::GetCreature(*me, _RavenousworgGUID))
                            RWORG->GetMotionMaster()->MovePoint(0, Mrfloppy->GetPositionX(), Mrfloppy->GetPositionY(), Mrfloppy->GetPositionZ());
                        DoCast(Mrfloppy, SPELL_MRFLOPPY);
                    }
                    break;
                case 19:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                    {
                        if (Mrfloppy->HasAura(SPELL_MRFLOPPY))
                        {
                            if (Creature* RWORG = ObjectAccessor::GetCreature(*me, _RavenousworgGUID))
                                Mrfloppy->EnterVehicle(RWORG);
                        }
                    }
                    break;
                case 20:
                    if (Creature* RWORG = ObjectAccessor::GetCreature(*me, _RavenousworgGUID))
                        RWORG->HandleEmoteCommand(34);
                    break;
                case 21:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                    {
                        if (Creature* RWORG = ObjectAccessor::GetCreature(*me, _RavenousworgGUID))
                        {
                            RWORG->Kill(Mrfloppy);
                            Mrfloppy->ExitVehicle();
                            RWORG->SetFaction(FACTION_MONSTER);
                            RWORG->GetMotionMaster()->MovePoint(0, RWORG->GetPositionX()+10, RWORG->GetPositionY()+80, RWORG->GetPositionZ());
                            Talk(SAY_VICTORY2);
                        }
                    }
                    break;
                case 22:
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                    {
                        if (Mrfloppy->isDead())
                        {
                            if (Creature* RWORG = ObjectAccessor::GetCreature(*me, _RavenousworgGUID))
                                RWORG->DisappearAndDie();
                            me->GetMotionMaster()->MovePoint(0, Mrfloppy->GetPositionX(), Mrfloppy->GetPositionY(), Mrfloppy->GetPositionZ());
                            Mrfloppy->setDeathState(ALIVE);
                            Mrfloppy->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Talk(SAY_VICTORY3);
                        }
                    }
                    break;
                case 24:
                    player->GroupEventHappens(QUEST_PERILOUS_ADVENTURE, me);
                    Talk(SAY_QUEST_COMPLETE, player);
                    me->SetWalk(false);
                    break;
                case 25:
                    Talk(SAY_VICTORY4);
                    break;
                case 27:
                    me->DisappearAndDie();
                    if (Creature* Mrfloppy = ObjectAccessor::GetCreature(*me, _mrfloppyGUID))
                        Mrfloppy->DisappearAndDie();
                    break;
            }
        }

        void EnterCombat(Unit* /*Who*/) override
        {
            Talk(SAY_RANDOMAGGRO);
        }

        void Reset() override
        {
            _mrfloppyGUID.Clear();
            _RavenousworgGUID.Clear();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_PERILOUS_ADVENTURE)
            {
                Talk(SAY_QUEST_ACCEPT);
                if (Creature* Mrfloppy = GetClosestCreatureWithEntry(me, NPC_MRFLOPPY, 180.0f))
                    Mrfloppy->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

                Start(true, false, player->GetGUID());
            }
        }

        private:
            ObjectGuid   _RavenousworgGUID;
            ObjectGuid   _mrfloppyGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_emilyAI(creature);
    }
};

// mrfloppy
class npc_mrfloppy : public CreatureScript
{
public:
    npc_mrfloppy() : CreatureScript("npc_mrfloppy") { }

    struct npc_mrfloppyAI : public ScriptedAI
    {
        npc_mrfloppyAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* Who) override
        {
            if (Creature* Emily = GetClosestCreatureWithEntry(me, NPC_EMILY, 50.0f))
            {
                switch (Who->GetEntry())
                {
                    case NPC_HUNGRY_WORG:
                        Emily->AI()->Talk(SAY_WORGHAGGRO2);
                        break;
                    case NPC_RAVENOUS_WORG:
                        Emily->AI()->Talk(SAY_WORGRAGGRO4);
                        break;
                    default:
                        Emily->AI()->Talk(SAY_RANDOMAGGRO);
                }
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mrfloppyAI(creature);
    }
};

/*######
## Quest 12227: Doing Your Duty
######*/

enum Outhouse
{
    // Sound
    SOUND_FEMALE                    = 12671,
    SOUND_MALE                      = 12670,
    // Spell
    SPELL_OUTHOUSE_GROANS           = 48382,
    SPELL_CAMERA_SHAKE              = 47533,
    SPELL_DUST_FIELD                = 48329
};

class npc_outhouse_bunny : public CreatureScript
{
public:
    npc_outhouse_bunny() : CreatureScript("npc_outhouse_bunny") { }

    struct npc_outhouse_bunnyAI : public ScriptedAI
    {
        npc_outhouse_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _counter = 0;
            _gender = 0;
        }

        void Reset() override
        {
            Initialize();
        }

        void SetData(uint32 Type, uint32 Data) override
        {
            if (Type == 1)
                _gender = Data;
        }

        void SpellHit(Unit* Caster, SpellInfo const* Spell) override
        {
             if (Spell->Id == SPELL_OUTHOUSE_GROANS)
             {
                ++_counter;
                if (_counter < 5)
                    DoCast(Caster, SPELL_CAMERA_SHAKE, true);
                else
                    _counter = 0;
                DoCast(me, SPELL_DUST_FIELD, true);
                switch (_gender)
                {
                    case GENDER_FEMALE:
                        DoPlaySoundToSet(me, SOUND_FEMALE);
                        break;

                    case GENDER_MALE:
                        DoPlaySoundToSet(me, SOUND_MALE);
                        break;
                }
            }
        }
        private:
            uint8 _counter;
            uint8 _gender;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_outhouse_bunnyAI(creature);
    }
};

// Tallhorn Stage

enum TallhornStage
{
    //Gameobject
    OBJECT_HAUNCH                   = 188665
};

class npc_tallhorn_stag : public CreatureScript
{
public:
    npc_tallhorn_stag() : CreatureScript("npc_tallhorn_stag") { }

    struct npc_tallhorn_stagAI : public ScriptedAI
    {
        npc_tallhorn_stagAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _phase = 1;
        }

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (_phase == 1)
            {
                if (me->FindNearestGameObject(OBJECT_HAUNCH, 2.0f))
                {
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetImmuneToPC(true);
                    me->AddDynamicFlag(UNIT_DYNFLAG_DEAD);
                }
                _phase = 0;
            }
            DoMeleeAttackIfReady();
        }
        private:
            uint8 _phase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tallhorn_stagAI(creature);
    }
};

// Amberpine Woodsman

enum AmberpineWoodsman
{
    // Creature
    NPC_TALLHORN_STAG                      = 26363
};

enum AmberpineWoodsmanEvents
{
    EVENT_WOODSMAN_1                       = 1,
    EVENT_WOODSMAN_2                       = 2
};

class npc_amberpine_woodsman : public CreatureScript
{
public:
    npc_amberpine_woodsman() : CreatureScript("npc_amberpine_woodsman") { }

    struct npc_amberpine_woodsmanAI : public ScriptedAI
    {
        npc_amberpine_woodsmanAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            if (me->FindNearestCreature(NPC_TALLHORN_STAG, 0.2f))
            {
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
            }
            else
                _events.ScheduleEvent(EVENT_WOODSMAN_1, 0);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WOODSMAN_1:
                        me->SetEmoteState(EMOTE_STATE_LOOT);
                        _events.ScheduleEvent(EVENT_WOODSMAN_2, 3000);
                        break;
                    case EVENT_WOODSMAN_2:
                        me->SetEmoteState(EMOTE_ONESHOT_ATTACK1H);
                        _events.ScheduleEvent(EVENT_WOODSMAN_1, 4000);
                        break;
                    default:
                        break;
                }
            }
            UpdateVictim();
        }
        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_amberpine_woodsmanAI(creature);
    }
};

/*######
## Quest 12288: Overwhelmed!
######*/

enum Skirmisher
{
    // Quest
    QUEST_OVERWHELMED           = 12288,
    // Spell
    SPELL_RENEW_SKIRMISHER      = 48812,
    SPELL_KILL_CREDIT           = 48813,
    // Text
    SAY_RANDOM                  = 0
};

class npc_wounded_skirmisher : public CreatureScript
{
public:
    npc_wounded_skirmisher() : CreatureScript("npc_wounded_skirmisher") { }

    struct npc_wounded_skirmisherAI : public ScriptedAI
    {
        npc_wounded_skirmisherAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _despawnTimer = 5000;
        }

        void Reset() override
        {
            Initialize();
        }

        void MovementInform(uint32, uint32 id) override
        {
            if (id == 1)
                me->DespawnOrUnsummon(_despawnTimer);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_RENEW_SKIRMISHER && caster->GetTypeId() == TYPEID_PLAYER
                && caster->ToPlayer()->GetQuestStatus(QUEST_OVERWHELMED) == QUEST_STATUS_INCOMPLETE)
            {
                DoCast(caster, SPELL_KILL_CREDIT);
                Talk(SAY_RANDOM);
                if (me->IsStandState())
                    me->GetMotionMaster()->MovePoint(1, me->GetPositionX()+7, me->GetPositionY()+7, me->GetPositionZ());
                else
                {
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->DespawnOrUnsummon(_despawnTimer);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
        private:
            uint32 _despawnTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wounded_skirmisherAI(creature);
    }
};

/*Venture co. Straggler - when you cast Smoke Bomb, he will yell and run away*/
enum SmokeEmOut
{
    // Quest
    QUEST_SMOKE_EM_OUT_A                        = 12323,
    QUEST_SMOKE_EM_OUT_H                        = 12324,
    // Spell
    SPELL_SMOKE_BOMB                            = 49075,
    SPELL_CHOP                                  = 43410,
    SPELL_VENTURE_STRAGGLER_CREDIT              = 49093,
    // Text
    SAY_SEO                                     = 0
};

enum StragglerEvents
{
    EVENT_STRAGGLER_1                           = 1,
    EVENT_STRAGGLER_2                           = 2,
    EVENT_STRAGGLER_3                           = 3,
    EVENT_STRAGGLER_4                           = 4,
    EVENT_CHOP                                  = 5
};

class npc_venture_co_straggler : public CreatureScript
{
public:
    npc_venture_co_straggler() : CreatureScript("npc_venture_co_straggler") { }

    struct npc_venture_co_stragglerAI : public ScriptedAI
    {
        npc_venture_co_stragglerAI(Creature* creature) : ScriptedAI(creature) { }

	void EnterCombat(Unit* /*who*/) override
	{
	    _events.ScheduleEvent(EVENT_CHOP, Seconds(3), Seconds(6));
	}

        void Reset() override
        {
            _playerGUID.Clear();

            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetImmuneToPC(false);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STRAGGLER_1:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                             DoCast(player, SPELL_VENTURE_STRAGGLER_CREDIT);
                         me->GetMotionMaster()->MovePoint(0, me->GetPositionX()-7, me->GetPositionY()+7, me->GetPositionZ());
                         _events.ScheduleEvent(EVENT_STRAGGLER_2, 2500);
                         break;
                    case EVENT_STRAGGLER_2:
                         Talk(SAY_SEO);
                         me->GetMotionMaster()->MovePoint(0, me->GetPositionX()-7, me->GetPositionY()-5, me->GetPositionZ());
                         _events.ScheduleEvent(EVENT_STRAGGLER_3, 2500);
                         break;
                    case EVENT_STRAGGLER_3:
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX()-5, me->GetPositionY()-5, me->GetPositionZ());
                        _events.ScheduleEvent(EVENT_STRAGGLER_4, 2500);
                        break;
                    case EVENT_STRAGGLER_4:
                        me->DisappearAndDie();
                        break;
                    case EVENT_CHOP:
                        if (UpdateVictim())
                            DoCastVictim(SPELL_CHOP);
                        _events.Repeat(Seconds(10), Seconds(12));
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SMOKE_BOMB && caster->GetTypeId() == TYPEID_PLAYER)
            {
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetImmuneToPC(true);
                me->SetReactState(REACT_PASSIVE);
                me->CombatStop(false);
                _playerGUID = caster->GetGUID();
                _events.ScheduleEvent(EVENT_STRAGGLER_1, 3500);
            }
        }

        private:
            EventMap _events;
            ObjectGuid _playerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_venture_co_stragglerAI(creature);
        }
};

/*######
## Quest: A Blade Fit For A Champion
######*/

enum LakeFrog
{
    // Creature
    NPC_LAKE_FROG                          = 33211,
    NPC_LAKE_FROG_QUEST                    = 33224,
    NPC_MAIDEN_OF_ASHWOOD_LAKE             = 33220,
    // Items
    ITEM_WARTS_B_GONE_LIP_BALM             = 44986,
    // Spells
    SPELL_WARTSBGONE_LIP_BALM              = 62574,
    SPELL_FROG_LOVE                        = 62537, // for 1 minute !
    SPELL_WARTS                            = 62581,
    SPELL_MAIDEN_OF_ASHWOOD_LAKE_TRANSFORM = 62550,
    SPELL_SUMMON_ASHWOOD_BRAND             = 62554,
    SPELL_FROG_KISS                        = 62536,
    // Text
    SAY_MAIDEN_0                           = 0,
    SAY_MAIDEN_1                           = 1
};

enum LakeFrogEvents
{
    EVENT_LAKEFROG_1                       = 1,
    EVENT_LAKEFROG_2                       = 2,
    EVENT_LAKEFROG_3                       = 3,
    EVENT_LAKEFROG_4                       = 4,
    EVENT_LAKEFROG_5                       = 5
};

class npc_lake_frog : public CreatureScript
{
public:
    npc_lake_frog() : CreatureScript("npc_lake_frog") { }

        struct npc_lake_frogAI : public ScriptedAI
        {
            npc_lake_frogAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _following = false;
                _runningScript = false;
            }

            void Reset() override
            {
                Initialize();
                if (me->GetEntry() == NPC_LAKE_FROG_QUEST)
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_following)
                    if (!me->HasAura(SPELL_FROG_LOVE))
                        me->DespawnOrUnsummon(1000);

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_LAKEFROG_1:
                            DoCast(me, SPELL_MAIDEN_OF_ASHWOOD_LAKE_TRANSFORM);
                            me->SetEntry(NPC_MAIDEN_OF_ASHWOOD_LAKE);
                            _events.ScheduleEvent(EVENT_LAKEFROG_2, 2000);
                            break;
                        case EVENT_LAKEFROG_2:
                            Talk(SAY_MAIDEN_0);
                            _events.ScheduleEvent(EVENT_LAKEFROG_3, 3000);
                            break;
                        case EVENT_LAKEFROG_3:
                            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            _events.ScheduleEvent(EVENT_LAKEFROG_4, 25000);
                            break;
                        case EVENT_LAKEFROG_4:
                            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            _events.ScheduleEvent(EVENT_LAKEFROG_5, 2000);
                            break;
                        case EVENT_LAKEFROG_5:
                            Talk(SAY_MAIDEN_1);
                            me->DespawnOrUnsummon(4000);
                            break;
                        default:
                            break;
                    }
                }
            }

            void ReceiveEmote(Player* player, uint32 emote) override
            {
                if (_following || _runningScript)
                    return;

                if (emote == TEXT_EMOTE_KISS && me->IsWithinDistInMap(player, 30.0f) && player->HasItemCount(ITEM_WARTS_B_GONE_LIP_BALM, 1, false))
                {
                    if (!player->HasAura(SPELL_WARTSBGONE_LIP_BALM))
                        player->AddAura(SPELL_WARTS, player);
                    else
                    {
                        DoCast(player, SPELL_FROG_KISS); // Removes SPELL_WARTSBGONE_LIP_BALM

                        if (me->GetEntry() == NPC_LAKE_FROG)
                        {
                            me->AddAura(SPELL_FROG_LOVE, me);
                            me->GetMotionMaster()->MoveFollow(player, 0.3f, frand(float(M_PI) / 2, float(M_PI) + (float(M_PI) / 2)));
                            _following = true;
                        }
                        else if (me->GetEntry() == NPC_LAKE_FROG_QUEST)
                        {
                            me->GetMotionMaster()->MoveIdle();
                            me->SetFacingToObject(player);
                            _runningScript = true;
                            _events.ScheduleEvent(EVENT_LAKEFROG_1, 2000);
                        }
                    }
                }
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                DoCast(player, SPELL_SUMMON_ASHWOOD_BRAND);
                return false;
            }

        private:
            EventMap _events;
            bool   _following;
            bool   _runningScript;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_lake_frogAI(creature);
        }
};

enum ShredderDelivery
{
    NPC_BROKEN_DOWN_SHREDDER               = 27354
};

class spell_shredder_delivery : public SpellScriptLoader
{
    public:
        spell_shredder_delivery() : SpellScriptLoader("spell_shredder_delivery") { }

        class spell_shredder_delivery_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shredder_delivery_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->ToCreature()->GetEntry() == NPC_BROKEN_DOWN_SHREDDER)
                    GetCaster()->ToCreature()->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_shredder_delivery_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shredder_delivery_SpellScript();
        }
};

enum InfectedWorgenBite
{
    SPELL_INFECTED_WORGEN_BITE = 53094,
    SPELL_WORGENS_CALL         = 53095
};

class spell_infected_worgen_bite : public SpellScriptLoader
{
    public:
        spell_infected_worgen_bite() : SpellScriptLoader("spell_infected_worgen_bite") { }

        class spell_infected_worgen_bite_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_infected_worgen_bite_AuraScript);

            void HandleAfterEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target->GetTypeId() == TYPEID_PLAYER)
                    if (GetStackAmount() == GetSpellInfo()->StackAmount)
                    {
                        Remove();
                        target->CastSpell(target, SPELL_WORGENS_CALL, true);
                    }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_infected_worgen_bite_AuraScript::HandleAfterEffectApply, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAPPLY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_infected_worgen_bite_AuraScript();
        }
};

/*######
## Quest: Riding the Red Rocket
######*/

enum RedRocket
{
    SPELL_VEHICLE_WARHEAD_FUSE            = 49107,
    SPELL_ALLIANCE_KILL_CREDIT_TORPEDO    = 49510,
    SPELL_HORDE_KILL_CREDIT_TORPEDO       = 49340,
    NPC_HORDE_LUMBERBOAT                  = 27702,
    NPC_ALLIANCE_LUMBERBOAT               = 27688,
    SPELL_DETONATE                        = 49250
};

class npc_rocket_propelled_warhead : public CreatureScript
{
public:
    npc_rocket_propelled_warhead() : CreatureScript("npc_rocket_propelled_warhead") { }

    struct npc_rocket_propelled_warheadAI : public VehicleAI
    {
        npc_rocket_propelled_warheadAI(Creature* creature) : VehicleAI(creature)
        {
            _finished = false;
            _faction = ALLIANCE;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply && who->ToPlayer())
            {
                DoCast(me, SPELL_VEHICLE_WARHEAD_FUSE);
                _faction = who->ToPlayer()->GetTeam();
            }
        }

        void JustReachedHome() override
        {
            _finished = false;
            me->SetVisible(true);
            me->GetMotionMaster()->Clear(true);
        }

        void DoAction(int32 /*action*/) override
        {
            FinishQuest(false, _faction);
        }

        void SpellHit(Unit* caster, SpellInfo const* /*spellInfo*/) override
        {
            if (caster->GetEntry() == NPC_HORDE_LUMBERBOAT || caster->GetEntry() == NPC_ALLIANCE_LUMBERBOAT)
                FinishQuest(true, _faction);
        }

        void FinishQuest(bool success, uint32 faction)
        {
            if (_finished)
                return;

            _finished = true;

            if (success)
                DoCast(me, faction == ALLIANCE ? SPELL_ALLIANCE_KILL_CREDIT_TORPEDO : SPELL_HORDE_KILL_CREDIT_TORPEDO);

            DoCast(me, SPELL_DETONATE);
            me->RemoveAllAuras();
            me->SetVisible(false);
            me->GetMotionMaster()->MoveTargetedHome();
        }

    private:
        uint32 _faction;
        bool _finished;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rocket_propelled_warheadAI(creature);
    }
};

enum WarheadSpells
{
    SPELL_WARHEAD_Z_CHECK               = 61678,
    SPELL_WARHEAD_SEEKING_LUMBERSHIP    = 49331,
    SPELL_WARHEAD_FUSE                  = 49181
};
// 49107 - Vehicle: Warhead Fuse
class spell_vehicle_warhead_fuse : public SpellScriptLoader
{
public:
    spell_vehicle_warhead_fuse() : SpellScriptLoader("spell_vehicle_warhead_fuse") { }

    class spell_vehicle_warhead_fuse_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vehicle_warhead_fuse_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WARHEAD_Z_CHECK, SPELL_WARHEAD_SEEKING_LUMBERSHIP, SPELL_WARHEAD_FUSE });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            caster->CastSpell(caster, SPELL_WARHEAD_Z_CHECK, true);
            caster->CastSpell(caster, SPELL_WARHEAD_SEEKING_LUMBERSHIP, true);
            caster->CastSpell(caster, SPELL_WARHEAD_FUSE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_vehicle_warhead_fuse_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vehicle_warhead_fuse_SpellScript();
    }
};

enum WarheadDenonate
{
    SPELL_PARACHUTE                     = 66154,
    SPELL_TORPEDO_EXPLOSION             = 49290,
    NPC_ALLIANCE_LUMBERBOAT_EXPLOSIONS  = 27689
};
// 49250 - Detonate
class spell_warhead_detonate : public SpellScriptLoader
{
public:
    spell_warhead_detonate() : SpellScriptLoader("spell_warhead_detonate") { }

    class spell_warhead_detonate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warhead_detonate_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PARACHUTE, SPELL_TORPEDO_EXPLOSION });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Player* player = GetHitPlayer();
            if (!player)
                return;

            player->ExitVehicle();
            float horizontalSpeed = 3.0f;
            float verticalSpeed = 40.0f;
            player->KnockbackFrom(caster->GetPositionX(), caster->GetPositionY(), horizontalSpeed, verticalSpeed);
            caster->CastSpell(player, SPELL_PARACHUTE, true);

            std::list<Creature*> explosionBunnys;
            caster->GetCreatureListWithEntryInGrid(explosionBunnys, NPC_ALLIANCE_LUMBERBOAT_EXPLOSIONS, 90.0f);
            for (std::list<Creature*>::const_iterator itr = explosionBunnys.begin(); itr != explosionBunnys.end(); ++itr)
                (*itr)->CastSpell((*itr), SPELL_TORPEDO_EXPLOSION, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warhead_detonate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warhead_detonate_SpellScript();
    }
};

// 61678 - Z Check
class spell_z_check : public SpellScriptLoader
{
public:
    spell_z_check() : SpellScriptLoader("spell_z_check") { }

    class spell_z_check_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_z_check_AuraScript);

    public:
        spell_z_check_AuraScript()
        {
            _posZ = 0.0f;
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            _posZ = GetTarget()->GetPositionZ();
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();

            if (_posZ != GetTarget()->GetPositionZ())
                if (Creature* target = GetTarget()->ToCreature())
                    target->AI()->DoAction(0);
        }

    private:
        float _posZ;

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_z_check_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_z_check_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_z_check_AuraScript();
    }
};

// 49181 - Warhead Fuse
class spell_warhead_fuse : public SpellScriptLoader
{
public:
    spell_warhead_fuse() : SpellScriptLoader("spell_warhead_fuse") { }

    class spell_warhead_fuse_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warhead_fuse_AuraScript);

        void HandleOnEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* rocketUnit = GetTarget()->GetVehicleBase())
                if (Creature* rocketCrea = rocketUnit->ToCreature())
                    rocketCrea->AI()->DoAction(0);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_warhead_fuse_AuraScript::HandleOnEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warhead_fuse_AuraScript();
    }
};

void AddSC_grizzly_hills()
{
    new npc_emily();
    new npc_mrfloppy();
    new npc_outhouse_bunny();
    new npc_tallhorn_stag();
    new npc_amberpine_woodsman();
    new npc_wounded_skirmisher();
    new npc_venture_co_straggler();
    new npc_lake_frog();
    new spell_shredder_delivery();
    new spell_infected_worgen_bite();
    new npc_rocket_propelled_warhead();
    new spell_z_check();
    new spell_warhead_detonate();
    new spell_vehicle_warhead_fuse();
    new spell_warhead_fuse();
}
