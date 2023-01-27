/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "throne_of_the_tides.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

#define GOSSIP_READY "We are ready!"
#define SAY_1 "As I purify these waters, the servants of filth will surely be stirred. Beware!"
#define SAY_2 "Patience guests. The waters are nearly cleansed."
#define SAY_3 "The beast has returned! It must not pollute my waters!"
#define SAY_DEATH "Your kind... cannot be... trusted..."
#define SAY_CLEANSED "My waters are cleansed! Drink in their power!"

enum Phases
{
    PHASE_NULL                    = 0, // Used to avoid wrong behaviour
    PHASE_FILTHY_INVADERS_1       = 1, // Starting phase
    PHASE_FILTHY_INVADERS_2       = 2, // Murlocs
    PHASE_FILTHY_INVADERS_3       = 3, // Mindlashers
    PHASE_FILTHY_INVADERS_4       = 4, // Behemont
    PHASE_BEAST_RETURN            = 5, // Real phase 2
    PHASE_TIDAL_SURGE             = 6, // Real phase 3
};

const Position spawns[] =
{
    {-122.412041f, 947.492188f, 231.579025f, 2.279974f},
    {-118.400780f, 1014.799866f, 230.195724f, 4.366778f},
};

enum Spells
{
    SPELL_AURA_PURIFIED                   = 76952,
    SPELL_OZUMAT_SUMMON_LITTLE_CHANCRE    = 83524,
    SPELL_OZUMAT_BIG_CHANCRE              = 83672,
    SPELL_OZUMAT_CHANCRE                  = 83608,

    SPELL_MAREE_POWER                     = 76133,

    SPELL_BEHEMOT_BLIGHT_SPRAY            = 83985,
};

enum OzumatPhase
{
    PHASE_ONE,
    PHASE_TWO,
};

enum actionOzumat
{
    ACTION_CHANGE_PHASE,
};

class npc_neptulon : public CreatureScript
{
public:
    npc_neptulon() : CreatureScript("npc_neptulon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_neptulonAI (creature);
    }

    struct npc_neptulonAI : public ScriptedAI
    {
        npc_neptulonAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            InProgress = false;
            sumSapper.clear();
            sumMindlasher.clear();
            sumMurlocs.clear();
            phase = PHASE_FILTHY_INVADERS_1;
            MindlasherTimer     = 20000;
            sumonslasher        = false;
            behemontTimer       = 30000;
            summonbehemont      = false;
            summonMurlocTimer   = 8000;
            phase2_timer        = 60000;
            ozumatGUID          = ObjectGuid::Empty;
            ozumatSummoned      = false;
            flagged             = false;
            deadSappers         = 0;
            slasherphased       = false;
            mui_event = 8000;
            event = 0;
            _ph = 0;
            mui_beast = 20000;
            me->RemoveAura(SPELL_AURA_PURIFIED);
            speakIntro = true;
            _wipeCheckTimer = 5000;
            Summons.DespawnAll();
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->RemoveAura(SPELL_AURA_PURIFIED);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->IsWithinDistInMap(who, 15) && !speakIntro)
                Talk(0);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            switch(summon->GetEntry())
            {
                case NPC_SAPPER:
                    deadSappers += 1;
                    if (deadSappers > 2)
                    {
                        mui_beast = 5000;
                        _ph = 2;
                        Talk(6);
                    }
                    break;
               case NPC_MINDLASHER:
                   if (event == 7)
                       event++;
                   break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_DEEP_MURLOC:
                    sumMurlocs.push_back(summon->GetGUID());
                    summon->GetMotionMaster()->MoveChase(me);
                    break;
                case NPC_MINDLASHER:
                    sumMindlasher.push_back(summon->GetGUID());
                    summon->GetMotionMaster()->MoveChase(me);
                    break;
                case NPC_BEHEMOTH:
                    summon->GetMotionMaster()->MoveChase(me);
                    break;
                case NPC_SAPPER:
                    sumSapper.push_back(summon->GetGUID());
                    summon->CastSpell(me, 83463, true);
                    break;
                case BOSS_OZUMAT:
                   ozumatGUID = summon->GetGUID();
                   summon->SetFaction(14);
                   summon->SetInCombatWithZone();
                   break;
                case NPC_BEAST:
                    summon->GetMotionMaster()->MoveChase(me);
                    summon->CastSpell(summon, 83970,  true);
                    summon->AddAura(83971,  summon);
                    summon->SetInCombatWithZone();
                    break;
                default:
                    summon->SetInCombatWithZone();
                    break;
            }
            Summons.Summon(summon);
        }

        void JustDied(Unit* killer) override
        {
            if (killer)
                me->Say(SAY_DEATH, LANG_UNIVERSAL, killer);
            //            Talk(8);
            Summons.DespawnAll();
        }

        void SummonAdd(uint32 entry, uint32 count)
        {
            if (entry == BOSS_OZUMAT)
            {
                me->SummonCreature(entry, -111.39f, 933.09f, 244.87f, 2.241692f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                return;
            }

            if (entry == NPC_SAPPER)
            {
                me->SummonCreature(entry, -142.599869f, 1001.389221f, 230.390076f, 4.424302f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                me->SummonCreature(entry, -128.356040f, 980.962253f, 230.372058f, 3.170475f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                me->SummonCreature(entry, -154.590064f, 963.942871f, 229.926407f, 1.250507f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                me->AddAura(83463, me);
                return;
            }

            for (uint32 x = 0; x < count; ++x)
               me->SummonCreature(entry, RAND(spawns[0], spawns[1]), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!InProgress)
                return;

            if (_wipeCheckTimer <= diff)
            {
                _wipeCheckTimer = 5000;
                Player* player =  me->SelectNearestPlayer(60.0f);
                if (!player)
                    Reset();
            }
            else
                _wipeCheckTimer -= diff;

            if (phase == PHASE_FILTHY_INVADERS_1)
            {
                me->SetFacingTo(0.166467f);
                phase = PHASE_FILTHY_INVADERS_2;
                Talk(2);
                me->AddAura(SPELL_AURA_PURIFIED, me);
            }

            if (_ph == 0)
            {
                if (mui_event <= diff)
                {
                    switch (event)
                    {
                        case 0:
                           SummonAdd(NPC_DEEP_MURLOC, 6);
                           mui_event = 6000;
                           break;
                        case 1:
                           SummonAdd(NPC_MINDLASHER, 1);
                           mui_event = 15000;
                           break;
                        case 2:
                            SummonAdd(NPC_BEHEMOTH, 1);
                            mui_event = 10000;
                            break;
                        case 3:
                            SummonAdd(NPC_DEEP_MURLOC, 6);
                            mui_event = 9000;
                            break;
                        case 4:
                            SummonAdd(NPC_MINDLASHER, 1);
                            mui_event = 20000;
                            break;
                        case 5:
                            SummonAdd(NPC_DEEP_MURLOC, 6);
                            mui_event = 15000;
                            break;
                        case 6:
                            Talk(3);
                            SummonAdd(NPC_MINDLASHER, 1);
                            mui_event = 1000;
                            break;
                        case 7:
                            mui_event = 1000;
                            break;
                        case 8:
                            mui_event = 5000;
                            break;
                        case 9:
                            SummonAdd(NPC_SAPPER, 3);
                            me->RemoveAura(SPELL_AURA_PURIFIED);
                            mui_event = 9000;
                            Talk(4);
                            break;
                        case 10:
                            SummonAdd(NPC_BEAST, 1);
                            mui_event = 1000;
                            _ph = 1;
                            SummonAdd(BOSS_OZUMAT, 1);
                            Talk(5);
                            break;
                        default :
                            mui_event = 1000;
                            break;
                    }
                    if (event <= 11 && event != 7)
                        event++;
                }
                else
                    mui_event -= diff;
            }
            else if (_ph == 1)
            {
                if (mui_beast <= diff)
                {
                    SummonAdd(NPC_BEAST, 1);
                    mui_beast = 20000;
                }
                else mui_beast -= diff;
            }
            else if (_ph == 2)
            {
                if (mui_beast <= diff)
                {
                    if (Creature *Ozumat = instance->GetCreature(DATA_OZUMAT))
                        Ozumat->AI()->DoAction(ACTION_CHANGE_PHASE);
                    _ph = 3;
                    mui_beast = 6000;
                }
                else mui_beast -= diff;
            }
            else if (_ph == 3)
            {
                if (mui_beast <= diff)
                {
                    Talk(7);
                    if (instance)
                        instance->DoCastSpellOnPlayers(SPELL_MAREE_POWER);
                    me->RemoveAura(83463);
                    _ph = 4;
                    mui_beast = 6000;
                }
                else mui_beast -= diff;
            }
        }


        bool InProgress;
    private :
        bool sumonslasher, summonbehemont, ozumatSummoned, flagged, slasherphased;
        uint32 phase;
        uint32 summonMurlocTimer;
        uint32 MindlasherTimer;
        std::list<ObjectGuid> sumMurlocs;
        std::list<ObjectGuid> sumMindlasher;
        std::list<ObjectGuid>  sumSapper;
        uint32 behemontTimer;
        uint32 phase2_timer;
        InstanceScript* instance;
        ObjectGuid ozumatGUID;
        uint32 deadSappers;
        uint32 event;
        uint32 mui_event;
        uint32 _ph;
        uint32 mui_beast;
        uint32 _wipeCheckTimer;
        bool speakIntro;
        SummonList Summons;
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == 1000)
        {
            CAST_AI(npc_neptulon::npc_neptulonAI, creature->AI())->InProgress = true;
            CAST_AI(npc_neptulon::npc_neptulonAI, creature->AI())->DoZoneInCombat();
            CAST_AI(npc_neptulon::npc_neptulonAI, creature->AI())->Talk(1);
            creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript* instance = creature->GetInstanceScript();
        if (instance)
        {
            if (instance->GetData(DATA_LADY_NAZJAR_EVENT) == DONE && instance->GetData(DATA_COMMANDER_ULTHOK_EVENT) == DONE && instance->GetData(DATA_ERUNAK_STONESPEAKER_EVENT) == DONE)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_READY, GOSSIP_SENDER_MAIN, 1000);
                player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(creature), creature->GetGUID());
            }
        }
        return true;
    }
};

class boss_ozumat : public CreatureScript
{
public:
    boss_ozumat() : CreatureScript("boss_ozumat") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ozumatAI (creature);
    }

    struct boss_ozumatAI : public ScriptedAI
    {
        boss_ozumatAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            Finished = false;
            _phase = 0;
            mui_timer_little_chancre = 10000;
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_CHANGE_PHASE)
            {
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                _phase = PHASE_TWO;
                me->CastSpell(me, SPELL_OZUMAT_BIG_CHANCRE, false);
            }
        }


        void UpdateAI(uint32 diff) override
        {
            switch (_phase)
            {
                case PHASE_ONE:
                    if (mui_timer_little_chancre <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            me->CastSpell(target, 83524, true);
                        mui_timer_little_chancre = 10000;
                    }
                    else
                        mui_timer_little_chancre -= diff;
                    break;
                case PHASE_TWO:
                    if (me->HealthBelowPct(5) && Finished == false)
                    {
                        me->SetFaction(35);

                        if (Creature *Neptulon = instance->GetCreature(DATA_NEPTULON))
                            Neptulon->DespawnOrUnsummon(35000);
                        me->CombatStop();
                        if (instance)
                        {
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAREE_POWER);
                            instance->SetData(DATA_OZUMAT, DONE);
                            instance->DoCompleteAchievement(DUNGEON_MODE(NORMAL_OZUMAT_DEFEAT, HEROIC_OZUMAT_DEFEAT));
                            /*if (instance->IsInGuildGroup() && IsHeroic())
                                instance->DoCompleteAchievement(HEROIC_OZUMAT_DEFEAT_WHILE_IN_GUILD_GROUP);*/
                        }

                        me->DespawnOrUnsummon();
                        Finished = true;
                    }
                    break;
                default :
                    break;
            }
        }

    private:
        InstanceScript* instance;
        bool Finished;
        uint8 _phase;
        uint32 mui_timer_little_chancre;
    };
};

class npc_behemot : public CreatureScript
{
public:
    npc_behemot() : CreatureScript("npc_behemot") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_behemotAI (creature);
    }

    struct npc_behemotAI : public ScriptedAI
    {
        npc_behemotAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            mui_blight_spray_timer = 3000;
        }

        void JustDied(Unit* killer) override
        {
            if (killer->HasAura(HEROIC_DEFEAT_BEHEMOT_WITH_SURGE_EFFECT) && IsHeroic())
                instance->DoCompleteAchievement(SPELL_MAREE_POWER);
        }

        void UpdateAI(uint32 diff) override
        {
            if (mui_blight_spray_timer <= diff)
            {
                DoCastAOE(SPELL_BEHEMOT_BLIGHT_SPRAY);
                mui_blight_spray_timer = urand(5000, 7000);
            }
            else mui_blight_spray_timer -= diff;
        }

    private :
        InstanceScript* instance;
        uint32 mui_blight_spray_timer;
    };
};

void AddSC_boss_ozumat()
{
    new npc_neptulon();
    new boss_ozumat();
    new npc_behemot();
}
