/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "LFGMgr.h"

enum Yells
{
    SAY_ENTRANCE                = -1189100,
    SAY_REJOINED                = -1189101,
    SAY_LOST_HEAD               = -1189102,
    SAY_LOST_HEAD2              = -1189103,
    SAY_CONFLAGRATION           = -1189104,
    SAY_SPROUTING_PUMPKINS      = -1189105,
    SAY_PLAYER_DEATH            = -1189106,
    SAY_DEATH                   = -1189107
};

enum Actions
{
    ACTION_SWITCH_PHASE         = 1
};

enum Entries
{
    NPC_HEAD                    = 23775,
    NPC_PULSING_PUMPKIN         = 23694,
    NPC_PUMPKIN_FIEND           = 23545,
    NPC_SIR_THOMAS              = 23904,
    HELPER                      = 23686,
    GO_PUMPKIN_SHRINE           = 186267
};

enum Spells
{
    SPELL_SUMMON_PUMPKIN        = 52236, // 8s trigger 42394

    SPELL_IMMUNED               = 42556,
    SPELL_BODY_REGEN            = 42403, // regenerate health plus model change to unhorsed
    SPELL_CONFUSED              = 43105,
    SPELL_HEAL_BODY             = 43306, // heal to 100%
    SPELL_CLEAVE                = 42587,
    SPELL_WHIRLWIND             = 43116,
    SPELL_CONFLAGRATION         = 42380,
    SPELL_BURNING               = 42971,

    SPELL_FLYING_HEAD           = 42399, // flying head visual
    SPELL_HEAD                  = 42413, // horseman head visual
    SPELL_HEAD_LANDS            = 42400,
    SPELL_CREATE_PUMPKIN_TREATS = 42754,
    SPELL_RHYME_BIG             = 42909,
	
    SPELL_SPROUTING             = 42281,
    SPELL_SPROUT_BODY           = 42285,
    SPELL_PUMPKIN_AURA_GREEN    = 42294,
    SPELL_PUMPKIN_AURA          = 42280,
    SPELL_WISP_BLUE             = 42821,
    SPELL_WISP_FLIGHT_PORT      = 42818,
    SPELL_DEATH                 = 42566,
    SPELL_BODY_FLAME            = 42074,
    SPELL_SMOKE                 = 42355,
    SPELL_SQUASH_SOUL           = 42514
};

uint32 randomLaugh[]            = {11965, 11975, 11976};

static Position flightPos[]=
{
    {1764.957f, 1347.432f, 18.7f, 6.029f},
    {1774.625f, 1345.035f, 20.8f, 6.081f},
    {1789.114f, 1341.439f, 26.8f, 0.198f},
    {1798.446f, 1345.865f, 30.8f, 1.781f},
    {1791.671f, 1360.825f, 30.1f, 2.766f},
    {1777.449f, 1364.652f, 25.1f, 2.911f},
    {1770.126f, 1361.402f, 20.7f, 4.093f},
    {1755.552f, 1366.757f, 19.5f, 6.212f}
};

static char const* Text[]=
{
    "Horseman rise...",
    "Your time is nigh...",
    "You felt death once...",
    "Now, know demise!"
};

//#define EMOTE_LAUGH   "Headless Horseman laughs."
#define GOSSIP_OPTION "Call the Headless Horseman."

class boss_headless_horseman : public CreatureScript
{
    public:
        boss_headless_horseman() : CreatureScript("boss_headless_horseman") { }

        struct boss_headless_horsemanAI : public ScriptedAI
        {
            boss_headless_horsemanAI(Creature* c) : ScriptedAI(c), _summons(me)
            {
            }

            void Reset()
            {
                _summons.DespawnAll();

                me->SetVisible(false);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);


                me->SetUnitMovementFlags(MOVEMENTFLAG_NONE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SetSpeed(MOVE_RUN, 2.0f, true);
                me->SetSpeed(MOVE_FLIGHT, 3.2f, true);
                me->SetCorpseDelay(75);

                _wpCount = 0;
                _introCount = 0;
                _wpReached = false;
                _phase = 0;


                _introTimer = 1*IN_MILLISECONDS;
                _laughTimer = 5*IN_MILLISECONDS;
                _cleaveTimer = 3*IN_MILLISECONDS;
                _summonTimer = 1*IN_MILLISECONDS;
                _conflagTimer = 4*IN_MILLISECONDS;

                me->SummonGameObject(GO_PUMPKIN_SHRINE, 1776.27f, 1348.74f, 20.4116f, 0, 0, 0, 0.00518764f, -0.999987f, 0);
                DoCast(me, SPELL_HEAD, true);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != _wpCount)
                    return;
					
                if (id < 7)
                {
                    ++_wpCount;
                    _wpReached = true;
                }
                else // start fighting
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    DoZoneInCombat(me, 100.0f);

                    if (me->getVictim())
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat(me, 100.0f);
            }

            void KilledUnit(Unit* victim)
            {
                if (!victim->ToPlayer())
                    return;

                DoScriptText(SAY_PLAYER_DEATH, me);
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                _summons.DespawnAll();

                // TODO: unhack
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    Map::PlayerList const& players = map->GetPlayers();
                    if (!players.isEmpty())
                        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                            if (Player* player = i->getSource())
                                if (player->GetDistance(me) < 120.0f)
                                    sLFGMgr->RewardDungeonDoneFor(285, player);
                }

                DoCast(me, SPELL_BURNING, true);
                me->SummonCreature(NPC_SIR_THOMAS, 1762.863f, 1345.217f, 17.9f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 60*IN_MILLISECONDS);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (_phase > 3)
                {
                    me->RemoveAllAuras();
                    return;
                }

                if (me->HasAura(SPELL_BODY_REGEN))
                {
                    damage = 0;
                    return;
                }

                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1;

                    DoCast(me, SPELL_IMMUNED, true);
                    DoCast(me, SPELL_BODY_REGEN, true);
                    DoCast(me, SPELL_CONFUSED, true);

                    Position randomPos;
                    me->GetRandomNearPosition(randomPos, 20.0f);

                    if (Creature* head = me->SummonCreature(NPC_HEAD, randomPos))
                    {
                        head->AI()->SetData(0, _phase);

                        switch (_phase)
                        {
                            case 2: head->SetHealth(uint32(head->GetMaxHealth() * 2 / 3)); break;
                            case 3: head->SetHealth(uint32(head->GetMaxHealth() / 3)); break;
                        }
                    }

                    me->RemoveAurasDueToSpell(SPELL_HEAD);
                }
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_SWITCH_PHASE:
                        me->RemoveAllAuras();
                        DoCast(me, SPELL_HEAL_BODY, true);
                        DoCast(me, SPELL_HEAD, true);

                        ++_phase;
                        if (_phase > 3)
                            me->DealDamage(me, me->GetHealth());
                        else
                            DoScriptText(SAY_REJOINED, me);

                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_phase == 0)
                {
                    if (_introTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            if (_introCount < 3)
                                target->ToPlayer()->Say(Text[_introCount], 0);
                            else
                            {
                                DoCast(me, SPELL_RHYME_BIG, true);
                                target->ToPlayer()->Say(Text[_introCount], 0);
                                target->HandleEmoteCommand(ANIM_EMOTE_SHOUT);
                                _phase = 1;
                                _wpReached = true;
                                me->SetVisible(true);
                                DoScriptText(SAY_ENTRANCE, me);
                            }
                        }
                        _introTimer = 3*IN_MILLISECONDS;
                        ++_introCount;
                    }
                    else
                        _introTimer -= diff;

                    return;
                }

                if (_wpReached)
                {
                    _wpReached = false;
                    me->GetMotionMaster()->MovePoint(_wpCount, flightPos[_wpCount]);
                }

                if (me->HasAura(SPELL_BODY_REGEN))
                {
                    if (me->IsFullHealth())
                    {
                        me->RemoveAllAuras();
                        DoCast(me, SPELL_HEAD, true);

                        if (Creature* head = me->FindNearestCreature(NPC_HEAD, 250.0f, true))
                        {
                            head->SetFullHealth();
                            head->RemoveAllAuras();
                            head->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            head->DespawnOrUnsummon(3*IN_MILLISECONDS);
                            head->CastSpell(me, SPELL_FLYING_HEAD, true);
                        }
                    }
                    else if (!me->HasAura(SPELL_WHIRLWIND) && me->GetHealthPct() > 10.0f)
                        DoCast(me, SPELL_WHIRLWIND, true);

                    return;
                }

                if (_laughTimer <= diff)
                {
                    DoPlaySoundToSet(me, randomLaugh[rand()%3]);
                    _laughTimer = urand(11, 22) *IN_MILLISECONDS;
                }
                else
                    _laughTimer -= diff;

                if (me->HasReactState(REACT_PASSIVE))
                    return;

                if (_cleaveTimer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE);
                    _cleaveTimer = urand(2, 6) *IN_MILLISECONDS;
                }
                else
                    _cleaveTimer -= diff;

                switch (_phase)
                {
                    case 2:
                        if (_conflagTimer <= diff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
                            {
                                DoScriptText(SAY_CONFLAGRATION, me);
                                DoCast(target, SPELL_CONFLAGRATION);
                            }
                            _conflagTimer = urand(20, 25) *IN_MILLISECONDS;
                        }
                        else
                            _conflagTimer -= diff;
                        break;
                    case 3:
                        if (_summonTimer <= diff)
                        {
                            DoScriptText(SAY_SPROUTING_PUMPKINS, me);
                            DoCast(me, SPELL_SUMMON_PUMPKIN, true);
                            _summonTimer = 45*IN_MILLISECONDS;
                        }
                        else
                            _summonTimer -= diff;
                        break;
                }

                DoMeleeAttackIfReady();
            }
			
        private:
            SummonList _summons;
            uint8 _phase;
            uint8 _wpCount;
            uint8 _introCount;
            uint32 _introTimer;
            uint32 _laughTimer;
            uint32 _cleaveTimer;
            uint32 _summonTimer;
            uint32 _conflagTimer;
            bool _wpReached;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_headless_horsemanAI(creature);
        }
};


class npc_horseman_head : public CreatureScript
{
    public:
        npc_horseman_head() : CreatureScript("npc_horseman_head") { }

        struct npc_horseman_headAI : public ScriptedAI
        {
            npc_horseman_headAI(Creature* c) : ScriptedAI(c)
            {
                me->SetDisplayId(21908);
                me->SetReactState(REACT_PASSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->MoveRandom(30.0f);
                DoCast(me, SPELL_HEAD, true);
                DoCast(me, SPELL_HEAD_LANDS, true);
                DoScriptText(RAND(SAY_LOST_HEAD, SAY_LOST_HEAD2), me);
                _despawn = false;
            }

            void SetData(uint32 /*type*/, uint32 data)
            {
                _phase = data;
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {

                if (_despawn)
                {
                    damage = 0;
                    return;
                }
                int32 healthPct;

                switch (_phase)
                {
                    case 1: healthPct = 66; break;
                    case 2: healthPct = 33; break;
                    default: healthPct = 1; break;
                }

                if (me->HealthBelowPctDamaged(healthPct, damage) || damage >= me->GetHealth())
                {
                    damage = 0;
                    me->RemoveAllAuras();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->DespawnOrUnsummon(3*IN_MILLISECONDS);
                    _despawn = true;

                    if (me->ToTempSummon())
                        if (Unit* horseman = me->ToTempSummon()->GetSummoner())
                        {
                            if (_phase < 3)
                                DoCast(horseman, SPELL_FLYING_HEAD, true);
                            horseman->ToCreature()->AI()->DoAction(ACTION_SWITCH_PHASE);
                        }
                }
            }

        private:
            uint8 _phase;
            bool _despawn;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_horseman_headAI(creature);
        }
};

class mob_wisp_invis : public CreatureScript
{
public:
    mob_wisp_invis() : CreatureScript("mob_wisp_invis") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wisp_invisAI (creature);
    }

    struct mob_wisp_invisAI : public ScriptedAI
    {
        mob_wisp_invisAI(Creature* c) : ScriptedAI(c)
        {
            Creaturetype = delay = spell = spell2 = 0;
            //that's hack but there are no info about range of this spells in dbc
            /*SpellEntry *wisp = GET_SPELL(SPELL_WISP_BLUE);
            if (wisp)
                wisp->rangeIndex = 6; //100 yards
            SpellEntry *port = GET_SPELL(SPELL_WISP_FLIGHT_PORT);
            if (port)
                port->rangeIndex = 6;*/
        }

        uint32 Creaturetype;
        uint32 delay;
        uint32 spell;
        uint32 spell2;
        void Reset(){}
        void EnterCombat(Unit* /*who*/){}
        void SetType(uint32 _type)
        {
            switch(Creaturetype = _type)
            {
                case 1:
                    spell = SPELL_PUMPKIN_AURA_GREEN;
                    break;
                case 2:
                    delay = 15000;
                    spell = SPELL_BODY_FLAME;
                    spell2 = SPELL_DEATH;
                    break;
                case 3:
                    delay = 15000;
                    spell = SPELL_SMOKE;
                    break;
                case 4:
                    delay = 7000;
                    spell2 = SPELL_WISP_BLUE;
                    break;
            }
            if (spell)
                DoCast(me, spell);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_WISP_FLIGHT_PORT && Creaturetype == 4)
                me->SetDisplayId(2027);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || Creaturetype != 1 || !who->isTargetableForAttack())
                return;

            if (me->IsWithinDist(who, 0.1f, false) && !who->HasAura(SPELL_SQUASH_SOUL))
                DoCast(who, SPELL_SQUASH_SOUL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (delay)
            {
                if (delay <= diff)
                {
                    me->RemoveAurasDueToSpell(SPELL_SMOKE);
                    if (spell2)
                        DoCast(me, spell2);
                    delay = 0;
                } else delay -= diff;
            }
        }
    };

};


class mob_pulsing_pumpkin : public CreatureScript
{
public:
    mob_pulsing_pumpkin() : CreatureScript("mob_pulsing_pumpkin") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pulsing_pumpkinAI (creature);
    }

    struct mob_pulsing_pumpkinAI : public ScriptedAI
    {
        mob_pulsing_pumpkinAI(Creature* c) : ScriptedAI(c) {}

        bool sprouted;
        uint64 debuffGUID;

        void Reset()
        {
            float x, y, z;
            me->GetPosition(x, y, z);   //this visual aura some under ground
            me->GetMap()->CreatureRelocation(me, x, y, z + 0.35f, 0.0f);
            Despawn();
            Creature* debuff = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 14500);
            if (debuff)
            {
                debuff->SetDisplayId(me->GetDisplayId());
                debuff->CastSpell(debuff, SPELL_PUMPKIN_AURA_GREEN, false);
                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, debuff->AI())->SetType(1);
                debuffGUID = debuff->GetGUID();
            }
            sprouted = false;
            DoCast(me, SPELL_PUMPKIN_AURA, true);
            DoCast(me, SPELL_SPROUTING);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }

        void EnterCombat(Unit* /*who*/){}

        void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_SPROUTING)
            {
                sprouted = true;
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                DoCast(me, SPELL_SPROUT_BODY, true);
                me->UpdateEntry(NPC_PUMPKIN_FIEND);
                DoStartMovement(me->getVictim());
            }
        }

        void Despawn()
        {
            if (!debuffGUID) return;
            Unit* debuff = Unit::GetUnit((*me), debuffGUID);
            if (debuff)
                debuff->SetVisible(false);
                debuffGUID = 0;
        }

        void JustDied(Unit* /*killer*/) { if (!sprouted) Despawn(); }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || !who->isTargetableForAttack() || !me->IsHostileTo(who) || me->getVictim())
                return;

            me->AddThreat(who, 0.0f);
            if (sprouted)
                DoStartMovement(who);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (sprouted && UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };

};


class go_pumpkin_shrine : public GameObjectScript
{
    public:
        go_pumpkin_shrine() : GameObjectScript("go_pumpkin_shrine") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {

            if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
                player->PrepareQuestMenu(go->GetGUID());
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(go), go->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF)
            {
                if (Unit* horseman = go->GetOwner())
                {
                    horseman->ToCreature()->AI()->AttackStart(player);
                    horseman->AddThreat(player, 1000.0f);
                    go->Delete();
                }
            }
            return true;
        }
};

void AddSC_boss_headless_horseman()
{
    new boss_headless_horseman();
    new npc_horseman_head();
    new mob_pulsing_pumpkin();
    new mob_wisp_invis();
    new go_pumpkin_shrine();
}
