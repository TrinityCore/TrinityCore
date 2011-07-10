/*######
## npc_frostlord_ahune
######*/

#include "LFGMgr.h"
#define EMOTE_SUBMERGE             "Ahune Retreats. His Defenses Diminish."
#define EMOTE_EMERGE_SOON          "Ahune will soon resurface."

enum Spells
{
    // Ahune
    SPELL_SLIPPERY_FLOOR_AMBIENT  = 46314,
    SPELL_SUMMON_ICE_SPEAR_BUNNY  = 46359,
    SPELL_SUMMON_ICE_SPEAR_OBJECT = 46369,
    SPELL_SELF_STUN               = 46416,
    SPELL_RESURFACE               = 46402,
    SPELL_SHIELD                  = 45954,
    SPELL_BEAM_ATTACK             = 46336,
    SPELL_BEAM_ATTACK_BEAM        = 46363,
    SPELL_SUBMERGE                = 37550,
    SPELL_EMERGE                  = 50142,
    SPELL_SNOWY                   = 46423,
    // Ahunite Hailstone
    SPELL_CHILLING_AURA           = 46542,
    SPELL_PULVERIZE               =  2676,
    // Ahunite Frostwind
    SPELL_WIND_BUFFET             = 46568,
    SPELL_LIGHTNING_SHIELD        = 12550,
    // Ahunite Coldwave
    SPELL_BITTER_BLAST            = 46406,
    // Ice Spear
    SPELL_ICE_SPEAR_KNOCKBACK     = 46360,
    // Slippery Floor
    SPELL_SLIP                    = 45947, // stun
    SPELL_YOU_SLIPPED             = 45946, // decrease speed
    SPELL_SLIPPERY_FLOOR          = 45945  // periodic, channeled
};

enum Npcs
{
    NPC_FROSTLORD_AHUNE           = 25740,
    NPC_FROZEN_CORE               = 25865,
    NPC_AHUNITE_HAILSTONE         = 25755,
    NPC_AHUNITE_COLDWAVE          = 25756,
    NPC_AHUNITE_FROSTWIND         = 25757,
    NPC_SLIPPERY_FLOOR            = 25952,
    NPC_EARTHEN_RING_TOTEM        = 25961,
    NPC_ICE_SPEAR_BUNNY           = 25985
};

enum Objects
{
    GO_ICE_SPEAR                  = 188077,
    GO_ICE_STONE                  = 187882,
    GO_ICE_CHEST                  = 187892
};

enum Actions
{
    ACTION_START_EVENT
};

enum Events
{
    EVENT_EMERGE = 1,
    EVENT_EMERGE_SOON,
    EVENT_SUBMERGED,
    EVENT_EARTHEN_RING_ATTACK,
    EVENT_SUMMON_HAILSTONE,
    EVENT_SUMMON_COLDWAVE,
    EVENT_ICE_SPEAR
};

class npc_frostlord_ahune : public CreatureScript
{
    public:
        npc_frostlord_ahune() : CreatureScript("npc_frostlord_ahune") { }

        struct npc_frostlord_ahuneAI : public Scripted_NoMovementAI
        {
            npc_frostlord_ahuneAI(Creature* c) : Scripted_NoMovementAI(c), _summons(me) { }

            void Reset()
            {
                _summons.DespawnAll();
                _events.Reset();
                _submerged = false;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetCorpseDelay(20);
                me->SetVisible(false);
                DoCast(me, SPELL_SHIELD, true);
                DoCast(me, SPELL_SUBMERGE, true);

                me->SummonGameObject(GO_ICE_STONE, -65.65f, -159.765f, -2.25f, 0, 0, 0, 0, 0, 0);
            }

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_FROZEN_CORE: 
                        summon->SetHealth(me->GetHealth());
                        summon->SetReactState(REACT_PASSIVE);
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        break;
                    case NPC_SLIPPERY_FLOOR:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                        summon->SetDisplayId(11686);
                        summon->setFaction(14);
                        me->AddAura(SPELL_SLIPPERY_FLOOR_AMBIENT, summon);
                        break;
                    case NPC_ICE_SPEAR_BUNNY:
                        summon->SetInCombatWithZone();
                        return;
                }

                _summons.Summon(summon);
                summon->SetInCombatWithZone();
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                if (me->isDead())
                    return;

                if (summon->GetEntry() == NPC_FROZEN_CORE)
                    me->SetHealth(summon->GetHealth());
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                if (summon->GetEntry() == NPC_FROZEN_CORE)
                    me->DealDamage(me, me->GetHealth());
            }

            void JustDied(Unit* /*who*/)
            {
                me->SummonGameObject(GO_ICE_CHEST, -97.095f, -203.866f, -1.191f, 1.5f, 0, 0, 0, 0, 0);
                _summons.DespawnAll();

                // lfg reward as there is no ahune entry in dbcs dungeonencounters
                // TODO: unhack
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    Map::PlayerList const& players = map->GetPlayers();
                    if (!players.isEmpty())
                        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                            if (Player* player = i->getSource())
                                if (player->GetDistance(me) < 120.0f)
                                    sLFGMgr->RewardDungeonDoneFor(286, player);
                }
            }

            void DoAction(int32 const action)
            {
                me->SetVisible(true);
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetInCombatWithZone();
                _events.ScheduleEvent(EVENT_EMERGE, 10000);

                if (GameObject* chest = me->FindNearestGameObject(GO_ICE_CHEST, 100.0f))
                    chest->Delete();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EMERGE:
                            me->SummonCreature(NPC_SLIPPERY_FLOOR, *me, TEMPSUMMON_TIMED_DESPAWN, 90000);
                            me->RemoveAurasDueToSpell(SPELL_SELF_STUN);
                            me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_RESURFACE, true);
                            DoCast(SPELL_EMERGE);
                            _attacks = 0;
                            _events.ScheduleEvent(EVENT_EARTHEN_RING_ATTACK, 10000);
                            _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, 2000);
                            _events.ScheduleEvent(EVENT_SUMMON_COLDWAVE, 5000);
                            _events.ScheduleEvent(EVENT_ICE_SPEAR, 10000);
                            break;
                        case EVENT_EMERGE_SOON:
                            me->MonsterTextEmote(EMOTE_EMERGE_SOON, 0, true);
                            break;
                        case EVENT_SUBMERGED:
                            DoCast(me, SPELL_SELF_STUN, true);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->SummonCreature(NPC_FROZEN_CORE, *me, TEMPSUMMON_TIMED_DESPAWN, 30000);
                            _submerged = true;
                            _events.ScheduleEvent(EVENT_EMERGE_SOON, 25000);
                            _events.ScheduleEvent(EVENT_EMERGE, 30000);
                            break;
                        case EVENT_EARTHEN_RING_ATTACK:
                            ++_attacks;
                            if (_attacks >= 9)
                            {
                                me->MonsterTextEmote(EMOTE_SUBMERGE, 0, true);
                                DoCast(SPELL_SUBMERGE);
                                _events.Reset();
                                _events.ScheduleEvent(EVENT_SUBMERGED, 4500);
                            }
                            else
                            {
                                if (Creature* totem = me->FindNearestCreature(NPC_EARTHEN_RING_TOTEM, 150.0f))
                                    totem->CastSpell(me, SPELL_BEAM_ATTACK_BEAM, false);
                                _events.ScheduleEvent(EVENT_EARTHEN_RING_ATTACK, 10000);
                            }
                            break;
                        case EVENT_SUMMON_HAILSTONE:
                            me->SummonCreature(NPC_AHUNITE_HAILSTONE, float(irand(-110, -80)), float(irand(-225, -215)), -1.0f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            break;
                        case EVENT_SUMMON_COLDWAVE:
                            for (uint8 i = 0; i < 2; ++i)
                                me->SummonCreature(NPC_AHUNITE_COLDWAVE, float(irand(-110, -80)), float(irand(-225, -215)), -1.0f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            if (_submerged)
                                me->SummonCreature(NPC_AHUNITE_FROSTWIND, float(irand(-110, -80)), float(irand(-225, -215)), -1.0f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            _events.ScheduleEvent(EVENT_SUMMON_COLDWAVE, 7000);
                            break;
                        case EVENT_ICE_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                                DoCast(target, SPELL_SUMMON_ICE_SPEAR_BUNNY);
                            _events.ScheduleEvent(EVENT_ICE_SPEAR, 7000);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            SummonList _summons;
            EventMap _events;
            bool _submerged;
            uint8 _attacks;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frostlord_ahuneAI(creature);
        }
};

class npc_ahune_ice_spear : public CreatureScript
{
    public:
        npc_ahune_ice_spear() : CreatureScript("npc_ahune_ice_spear") { }

        struct npc_ahune_ice_spearAI : public Scripted_NoMovementAI
        {
            npc_ahune_ice_spearAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                _spikeTimer = 2000;
                _spiked = false;
                DoCast(me, SPELL_SUMMON_ICE_SPEAR_OBJECT, true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (_spikeTimer <= diff)
                {
                    GameObject* spike = me->FindNearestGameObject(GO_ICE_SPEAR, 10.0f);
                    if (spike && !_spiked)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 3.0f, true))
                            target->CastSpell(target, SPELL_ICE_SPEAR_KNOCKBACK, true);
                        spike->UseDoorOrButton();
                        _spiked = true;
                        _spikeTimer = 4000;
                    }
                    else if (spike)
                    {
                        spike->Delete();
                        me->DespawnOrUnsummon();
                    }
                }
                else
                    _spikeTimer -= diff;
            }

        private:
            uint32 _spikeTimer;
            bool _spiked;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ahune_ice_spearAI(creature);
        }
};

class go_ahune_ice_stone : public GameObjectScript
{
    public:
        go_ahune_ice_stone() : GameObjectScript("go_ahune_ice_stone") { }

        bool OnQuestReward(Player* /*player*/, GameObject* go, Quest const* /*quest*/, uint32 /*opt*/)
        {
            if (Creature* ahune = go->FindNearestCreature(NPC_FROSTLORD_AHUNE, 100.0f, true))
            {
                ahune->AI()->DoAction(ACTION_START_EVENT);
                go->Delete();
            }
            return true;
        }
};

void AddSC_boss_frostlord_ahune()
{
    new npc_frostlord_ahune();
    new npc_ahune_ice_spear();
    new go_ahune_ice_stone();
}
