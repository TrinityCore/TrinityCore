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

/* ScriptData
SDName: Gilneas
SD%Complete: 0
SDComment: Quest support: 0
SDCategory: Gilneas
EndScriptData */

/* ContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "Pet.h"
#include "Vehicle.h"

enum eGilneas
{
    SPELL_INVISIBILITY_DETECTION_2 = 49417,
    SPELL_GENERIC_QUEST_INVISIBILITY_DERECTION_1 = 49416,
    SPELL_ENRAGE = 56646,
    SPELL_SET_PHASE_02 = 59073, // set phase 2
    SPELL_SET_PHASE_04 = 59074, // set phase 4
    SPELL_SET_PHASE_08 = 59087, // set phase 8

    SPELL_GILNEAS_PRISON_PERIODIC_FORCECAST = 66914,
    NPC_PANICKED_CITIZEN_PHASE1 = 34851,
    NPC_GILNEAS_CITY_GUARD_PHASE1 = 34864,
    NPC_PANICKED_CITIZEN_GATE_PHASE1 = 44086,
    NPC_PRINCE_LIAM_GREYMANE_PHASE1 = 34850,
    NPC_LIEUTNANT_WALDEN_PHASE1 = 34863,

    NPC_RAMPAGING_WORGEN_CW_PHASE2 = 34884,
    NPC_PRINCE_LIAM_GREYMANE_PHASE2 = 34913,
    NPC_GILNEAS_CITY_GUARD_PHASE2 = 34916,
    NPC_FRIGHTENED_CITIZEN_J_PHASE2 = 34981,
    NPC_RAMPAGING_WORGEN_PHASE2 = 35660,
    NPC_GILNEAS_EVACUATION_FACING_MARKER = 35830,
    NPC_FRIGHTENED_CITIZEN_CW_PHASE2 = 35836,

    NPC_GWEN_ARMSTEAD_PHASE4 = 35840,
    NPC_LORD_DARIUS_CROWLEY_PHASE4 = 35077,
    NPC_BLOODFANG_WORGEN_PHASE4 = 35118,
    NPC_TOBIAS_MISTMANTLE_PHASE4 = 35124,
    NPC_WORGEN_RUNT_PHASE4 = 35456,

    NPC_JOSIAH_AVERY_HUMAN_PHASE4 = 35369,
    NPC_JOSIAH_AVERY_WORGEN_PHASE8 = 35370,
    NPC_LORNA_CROWLEY_PHASE8 = 35378,
    NPC_GILNEAS_MASTIFF_PHASE8 = 35631,
    NPC_BLOODFANG_LURKER_PHASE8 = 35463,
    NPC_GILNEAS_CITY_GUARD_PHASE8 = 50474,

    NPC_GENN_GREYMANE_HORSE_PHASE8 = 35905,
    NPC_KRENNAN_ARANAS_PHASE8 = 35753,
    NPC_KRENNAN_ARANAS_SAVE_PHASE8 = 35907,
    NPC_LORD_GOLDFREY_PHASE8 = 35906,
    NPC_GUARD_QSKA_PHASE8 = 35509,
    NPC_WORGEN_QSKA_PHASE8 = 35505,
    NPC_COMMANDEERED_CANNON_PHASE8 = 35914,
    NPC_BLOODFANG_RIPPER_QSKA_PHASE8 = 35916,
    NPC_GILNEAS_CANNON_CAMERA_PHASE8 = 50420,

    NPC_SISTER_ALMYRA_PHASE8 = 44468,
    NPC_CELESTINE_OF_THE_HARVEST_PHASE8 = 44459,
    NPC_PRINCE_LIAM_GREYMANE_PHASE8 = 35551,
    NPC_LORD_DARIUS_CROWLEY_PHASE8 = 35552,
    NPC_KING_GENN_GREYMANE2_PHASE8 = 35911,
    NPC_CROWLEYS_HORSE_PHASE8 = 44427, // standing near darius crowley
    NPC_CROWLEYS_HORSE2_PHASE8 = 44429, // standing near tobias mistmantle
    NPC_CROWLEYS_HORSE1R_PHASE8 = 44428, // spawned by spell
    NPC_CROWLEYS_HORSE2R_PHASE8 = 35231, // spawned by spell
    NPC_LORD_DARIUS_CROWLEY_SUMMON_PHASE8 = 35230, // sitting on horse on seat 1, player on seat 2
    NPC_BLOODFANG_STALKER_PHASE8 = 35229,
    NPC_BLOODFANG_STALKER_CREDIT = 35582,
    NPC_NORTHGATE_REBEL_PHASE8 = 36057,
        
    QUEST_THE_REBEL_LORD_ARSENAL = 14159,
    QUEST_FROM_THE_SHADOWS = 14204,
    QUEST_SAVE_KRENNAN_ARANAS = 14293,
    QUEST_SACRIFICES = 14212,

    QUEST_LOCKDOWN = 14078,
    QUEST_SOMETHINGS_AMISS = 14091,
    QUEST_ALL_HELL_BREAKS_LOOSE = 14093,
    QUEST_EVACUATE_THE_MERCHANT_SQUARE = 14098,
    QUEST_ROYAL_ORDERS = 14099,
    QUEST_BY_THE_SKIN_OF_HIS_TEETH = 14154,


    ITEM_GILNEAN_MASTIFF_COLLAR = 48707,

    SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_1 = 49416,
    SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_2 = 49417,
   
    // SPELL_SET_PHASE_08                           = 67853, // 59087, // set phase 8  // giv all wrong zone

    SPELL_WORGEN_BITE = 72870, // after new loading: stored as gilneas phase 4 aura
    SPELL_INFECTED_BITE = 72872, // after new loading: stored as gilneas phase 8 aura

    SPELL_ATTACK_LURKER = 67805,
    SPELL_SUMMON_MASTIFF = 67807,

    SPELL_SHADOWSTALKER_STEALTH = 5916,
    SPELL_LURKER_ENRAGE = 8599,
    SPELL_UNDYING_FRENZY_INSTANT = 80514,
    SPELL_UNDYING_FRENZY_CHANNELED = 80515,

    SPELL_RESCUE_KRENNAN = 68219,
    SPELL_CANNON_FIRE = 68235,
    SPELL_SHOOT_QSKA = 48424,
    SPELL_CANNON_CAMERA = 93522,
    SPELL_FORECAST_CANNON_CAMERA = 93555,
    SPELL_CROWLEY_SUMMON_INITIALIZE = 67002,

    SPELL_POWER_WORD_FORTITUDE = 74973,
    SPELL_MARK_OF_THE_WILD = 79833,

    SPELL_THROW_TORCH = 67063, // only used by horse 44429 other horses in this quest using 67472 or nothing..
    SPELL_FIRE_BOMB = 67472, // on wowhead is unknown (fire bomb) but uses for horse 44427 and 35231
    SPELL_SUMMON_CROWLEYS_HORSE_1R = 82992, // horse 44428 is summoned and caster enter seat 0, GetAvailableSeatCount returns 1
    SPELL_SUMMON_CROWLEYS_HORSE_2R = 67001, // horse 35231 is summoned and caster enter seat 0, GetAvailableSeatCount returns 0
    SPELL_FORCE_CAST_SUMMON_CROWLEYS_HORSE = 67766, // horse 35231 is summoned and caster enter seat 0, GetAvailableSeatCount returns 0
    SPELL_CROWLEY_FORCE_SUMMON = 67004, // crawley is summoned as guard for player 35230


};

/*######
## npc_panicked_citizen_phase1
######*/

class npc_panicked_citizen_phase1 : public CreatureScript
{
public:
    //npc_panicked_citizen_phase1() : CreatureScript("npc_panicked_citizen_phase1") { }

    struct npc_panicked_citizen_phase1AI : public ScriptedAI
    {
        npc_panicked_citizen_phase1AI(Creature* creature) : ScriptedAI(creature) { }

        void UpdateAI(uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_panicked_citizen_phase1AI(creature);
    }

};

/*######
## npc_gilneas_city_guard_phase1
######*/

class npc_gilneas_city_guard_phase1 : public CreatureScript
{
public:
    npc_gilneas_city_guard_phase1() : CreatureScript("npc_gilneas_city_guard_phase1") { }

    struct npc_gilneas_city_guard_phase1AI : public ScriptedAI
    {
        npc_gilneas_city_guard_phase1AI(Creature* creature) : ScriptedAI(creature) { }

        uint32		_timer;
        uint8		_phase;
        bool		_nearGate;
        uint8		_say;
        Creature* _citizen;

        void Reset()
        {
            _timer = urand(10000, 30000);
            _phase = 0;
            _nearGate = false;

            if (me->GetDistance2d(-1430.47f, 1345.55f) < 10.0f)
                _nearGate = true;
        }

        void UpdateAI(uint32 diff)
        {

            if (_timer <= diff)
            {
                if (_nearGate)
                    DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 0:
            {
                std::list<Creature*> listOfCitizen;
                me->GetCreatureListWithEntryInGrid(listOfCitizen, NPC_PANICKED_CITIZEN_GATE_PHASE1, 35.0f);

                if (!listOfCitizen.empty())
                {
                    uint8 id = urand(0, listOfCitizen.size() - 1);
                    std::list<Creature*>::iterator itr = listOfCitizen.begin();
                    std::advance(itr, id);

                    if (_citizen = *itr)
                    {
                        _timer = urand(1000, 2000);
                        _say = urand(0, 2);
                        switch (urand(0, 4))
                        {
                        case 0:
                            _citizen->HandleEmoteCommand(EMOTE_STATE_COWER);
                            break;
                        case 1:
                            _citizen->HandleEmoteCommand(EMOTE_STATE_TALK);
                            break;
                        case 2:
                            _citizen->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
                            break;
                        case 3:
                            _citizen->HandleEmoteCommand(EMOTE_STATE_SPELL_PRECAST);
                            break;
                        case 4:
                            _citizen->HandleEmoteCommand(EMOTE_STATE_EXCLAIM);
                            break;
                        }
                        _phase = 1;
                        return;
                    }
                }
                break;
            }
            case 1:
            {
                if (_citizen)
                {
                    //_citizen->AI()->Talk(_say, me->GetGUID());
                    _timer = urand(4000, 7000);
                    _phase = 2;
                }
                break;
            }
            case 2:
            {
                if (_citizen)
                {
                    //Talk(_say, me->GetGUID());
                    _timer = 6000;
                    _phase = 3;
                }
                break;
            }
            case 3:
            {
                if (_citizen)
                {
                    _citizen->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                    _timer = urand(10000, 20000);
                    _phase = 0;
                }
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gilneas_city_guard_phase1AI(creature);
    }
};

/*######
## npc_prince_liam_greymane_phase1
######*/

class npc_prince_liam_greymane_phase1 : public CreatureScript
{
public:
    npc_prince_liam_greymane_phase1() : CreatureScript("npc_prince_liam_greymane_phase1") { }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_LOCKDOWN)
            if (Creature* citizen = creature->FindNearestCreature(NPC_PANICKED_CITIZEN_PHASE1, 20.0f))
                citizen->AI()->Talk(0);

        return true;
    }

    struct npc_prince_liam_greymane_phase1AI : public ScriptedAI
    {
        npc_prince_liam_greymane_phase1AI(Creature* creature) : ScriptedAI(creature) {}

        uint32  _timer;
        uint8   _phase;

        void Reset()
        {
            _timer = 1000;
            _phase = 0;
        }

        //void UpdateAI(uint32 diff)
        //{
        //    Player* player = me->FindNearestPlayer(30,true);
        //    if (_timer <= diff)
        //        DoWork(player);
        //    else
        //    _timer -= diff;

        //    if (!UpdateVictim())
        //        return;

        //    DoMeleeAttackIfReady();

        //}


        void DoWork(Player* player)
        {
            _timer = 5000;
            switch (_phase)
            {
            case 0:
                if (player)
                {
                    _phase = 1;
                    _timer = 75000;
                }
                break;
            case 1:
                Talk(0);
                _timer = 15000;
                _phase = 2;
                break;
            case 2:
                Talk(1);
                _timer = 18000;
                _phase = 3;
                break;
            case 3:
                Talk(2);
                _timer = 25000;
                _phase = 4;
                break;
            case 4:
                _timer = 30000;
                _phase = 1;
                if (!player)
                    _phase = 0;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_prince_liam_greymane_phase1AI(creature);
    }

};

/*######
## npc_lieutenant_walden_phase1
######*/

class npc_lieutenant_walden_phase1 : public CreatureScript
{
public:
    npc_lieutenant_walden_phase1() : CreatureScript("npc_lieutenant_walden_phase1") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_SOMETHINGS_AMISS)
        {
            player->AddAura(SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_1, player);
            player->CastSpell(player, SPELL_SET_PHASE_02, false);
            player->SaveToDB();
        }
        return true;
    }
};

/*######
## phase 2
######*/

/*######
## npc_rampaging_worgen_phase2
## ToDo: The fight with Prince Liam is not realy finish..
######*/

class npc_rampaging_worgen_phase2 : public CreatureScript
{
public:
    npc_rampaging_worgen_phase2() : CreatureScript("npc_rampaging_worgen_phase2") { }

    struct npc_rampaging_worgen_phase2AI : public ScriptedAI
    {
        npc_rampaging_worgen_phase2AI(Creature* creature) : ScriptedAI(creature) { _fightWithPrinceLiam = false; _liam = NULL; }

    public:
        bool		_fightWithPrinceLiam;
        bool        _enrage;
        uint32		_timer;
        Creature* _liam;

        void Reset()
        {
            _timer = urand(1800, 2200);
            _enrage = false;
        }

        void StartFightWithPrinceLiam(Creature* liam)
        {
            _liam = liam;
            _fightWithPrinceLiam = true;
            Position pos;
            //liam->GetNearPosition(pos, 1.5f, 0.0f);
            me->GetMotionMaster()->MovePoint(1005, pos);
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (_fightWithPrinceLiam && id == 1005)
            {
                me->SetFaction(2179);
                //me->CombatStart(_liam);
            }
        }

        void DamageTaken(Unit* /*pDone_by*/, uint32& /*uiDamage*/)
        {
            if (me->GetHealthPct() < 30 && !_enrage)
            {
                me->CastSpell(me, SPELL_ENRAGE);
                _enrage = true;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                DoShowFight(diff);
            else
                DoMeleeAttackIfReady();
        }

        void DoShowFight(uint32 diff)
        {

            if (_timer <= diff)
            {
                if (Creature* guard = me->FindNearestCreature(NPC_GILNEAS_CITY_GUARD_PHASE2, 3.0f))
                {
                    me->SetFacingTo(me->GetFollowAngle());//guard
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                }
                _timer = urand(1500, 2500);
            }
            else
                _timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_rampaging_worgen_phase2AI(creature);
    }
};

/*######
## npc_gilneas_city_guard_phase2
######*/

class npc_gilneas_city_guard_phase2 : public CreatureScript
{
public:
    npc_gilneas_city_guard_phase2() : CreatureScript("npc_gilneas_city_guard_phase2") { }

    struct npc_gilneas_city_guard_phase2AI : public ScriptedAI
    {
        npc_gilneas_city_guard_phase2AI(Creature* creature) : ScriptedAI(creature) { }

        uint32 _timer;
        uint32 _health;

        void Reset()
        {
            _timer = urand(1800, 2200);
            _health = urand(65, 95);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (attacker->GetEntry() == NPC_BLOODFANG_WORGEN_PHASE4)
                if (me->HealthBelowPct(_health))
                    damage = 0;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                DoShowFight(diff);
            else
                DoMeleeAttackIfReady();
        }

        void DoShowFight(uint32 diff)
        {
            if (Creature* worgen = me->FindNearestCreature(NPC_RAMPAGING_WORGEN_PHASE2, 3.0f))
            {
                if (_timer <= diff)
                {
                    me->SetFacingTo(me->GetFollowAngle());//worgen
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                    _timer = urand(1800, 2200);
                }
                else
                    _timer -= diff;
            }
            if (Creature* worgen = me->FindNearestCreature(NPC_BLOODFANG_WORGEN_PHASE4, 3.0f))
            {
                if (_timer <= diff)
                {
                    //me->SetFacingTo(me->GetFollowAngle(worgen));
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                    _timer = urand(1800, 2200);
                }
                else
                    _timer -= diff;
            }

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gilneas_city_guard_phase2AI(creature);
    }
};

/*######
## npc_prince_liam_greymane_phase2
######*/

class npc_prince_liam_greymane_phase2 : public CreatureScript
{
public:
    npc_prince_liam_greymane_phase2() : CreatureScript("npc_prince_liam_greymane_phase2") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (npc_prince_liam_greymane_phase2AI* prince = CAST_AI(npc_prince_liam_greymane_phase2AI, creature->AI()))
            prince->StartEvent(player);

        return false;
    }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_ROYAL_ORDERS)
        {
            player->RemoveAura(SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_1);
            player->AddAura(SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_2, player);
            player->CastSpell(player, SPELL_SET_PHASE_04, false);
            player->SaveToDB();
        }

        return true;
    }

    struct npc_prince_liam_greymane_phase2AI : public ScriptedAI // ScriptedAI
    {
        npc_prince_liam_greymane_phase2AI(Creature* creature) : ScriptedAI(creature) { }

        uint32 _timer;
        uint32 _phase;
        Player* _player;
        Creature* _worgen;

        void Reset()
        {
            _timer = 0; _phase = 0; _player = NULL; _worgen = NULL;
        }

        void StartEvent(Player* player)
        {
            _player = player;
            if (_phase == 0)
            {
                _timer = 1000; _phase = 1;
            }
        }

        void UpdateAI(uint32 diff)
        {

            if (_timer <= diff)
            {
                DoWork();
                _timer = 1000;
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            if (!_player) return;
            if (me->GetDistance(_player) > 35.0f)
                return;

            if (_player->GetQuestStatus(QUEST_ALL_HELL_BREAKS_LOOSE) != QUEST_STATUS_INCOMPLETE)
                return;

            if (_worgen)
            {
                if (_worgen->IsAlive()) return;
                if (_worgen->isDead())//IsDead
                {
                    _worgen->DespawnOrUnsummon();
                    _worgen = NULL;
                    return;
                }
            }
            if (_worgen = me->SummonCreature(NPC_RAMPAGING_WORGEN_PHASE2, -1474.3f, 1396.6f, 35.556f, 0.27f, TEMPSUMMON_TIMED_DESPAWN, Milliseconds(20000)))
            {
                CAST_AI(npc_rampaging_worgen_phase2::npc_rampaging_worgen_phase2AI, _worgen->AI())->StartFightWithPrinceLiam(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_prince_liam_greymane_phase2AI(creature);
    }

};

/*######
## npc_frightened_citizen_j_phase2
######*/

class npc_frightened_citizen_j_phase2 : public CreatureScript
{
public:
    npc_frightened_citizen_j_phase2() : CreatureScript("npc_frightened_citizen_j_phase2") {}

    struct npc_frightened_citizen_j_phase2AI : public EscortAI
    {
        npc_frightened_citizen_j_phase2AI(Creature* c) : EscortAI(c) { }

        uint32  _timer;
        bool	_pause;

        //void WaypointReached(uint32 point)
        //{
        //    if (point == 2)
        //    {
        //        if (me->IsSummon())
        //            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
        //                if (Player* player = summoner->ToPlayer())
        //                {
        //                    player->KilledMonsterCredit(NPC_GILNEAS_EVACUATION_FACING_MARKER, 0);
        //                    SetEscortPaused(true);
        //                    _pause = true;
        //                    _timer = 4000;
        //                    me->SetFacingTo(me->GetFollowAngle());//player
        //                    Talk(0);
        //                }
        //    }
        //}

        void UpdateAI(uint32 diff)
        {
            EscortAI::UpdateAI(diff);

            if (_pause)
                if (_timer <= diff)
                {
                    _pause = false;
                    SetEscortPaused(false);
                }
                else
                    _timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_frightened_citizen_j_phase2AI(creature);
    }
};

/*######
## npc_frightened_citizen_cw_phase2
######*/

class npc_frightened_citizen_cw_phase2 : public CreatureScript
{
public:
    npc_frightened_citizen_cw_phase2() : CreatureScript("npc_frightened_citizen_cw_phase2") {}

    struct npc_frightened_citizen_cw_phase2AI : public EscortAI
    {
        npc_frightened_citizen_cw_phase2AI(Creature* c) : EscortAI(c) { }

        uint32  _timer;
        bool	_pause;

        //void WaypointReached(uint32 point)
        //{
        //    if (point == 2)
        //    {
        //        if (me->IsSummon())
        //            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
        //                if (Player* player = summoner->ToPlayer())
        //                {
        //                    player->KilledMonsterCredit(NPC_GILNEAS_EVACUATION_FACING_MARKER);//, 0
        //                    //SetEscortPaused(true);
        //                    _pause = true;
        //                    _timer = 1000;
        //                    me->SetFacingTo(me->GetFollowAngle());//player
        //                    Talk(0);
        //                }
        //    }
        //}

        void UpdateAI(uint32 diff)
        {
            EscortAI::UpdateAI(diff);

            if (_pause)
                if (_timer <= diff)
                {
                    _pause = false;
                    SetEscortPaused(false);
                }
                else
                    _timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_frightened_citizen_cw_phase2AI(creature);
    }
};

/*######
## npc_rampaging_worgen_cw_phase2
######*/


class npc_rampaging_worgen_cw_phase2 : public CreatureScript
{
public:
    npc_rampaging_worgen_cw_phase2() : CreatureScript("npc_rampaging_worgen_cw_phase2") {}

    struct npc_rampaging_worgen_cw_phase2AI : public EscortAI
    {
        npc_rampaging_worgen_cw_phase2AI(Creature* creature) : EscortAI(creature)
        {
            creature->SetReactState(REACT_PASSIVE);
            uiPauseTimer = 4000;
            enrage = false;
            pause = true;
        }

        uint32  uiPauseTimer;
        bool    pause;
        bool    enrage;

        //void WaypointReached(uint32 point)
        //{
        //    if (point == 1)
        //    {
        //        me->SetReactState(REACT_AGGRESSIVE);
        //        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);//UNIT_FIELD_FLAGS,
        //        /*if (me->IsSummon())
        //            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
        //                AttackStart(summoner);
        //            else
        //                me->DespawnOrUnsummon();*/
        //    }
        //}
    };
};



const uint16 PanickedCitizenRandomEmote[5] =
{
    EMOTE_STATE_COWER,
    EMOTE_STATE_TALK,
    EMOTE_ONESHOT_CRY,
    EMOTE_STATE_SPELL_PRECAST,
    EMOTE_STATE_EXCLAIM,
};
