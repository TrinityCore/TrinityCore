/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "SpellAuras.h"
#include "ScriptedEscortAI.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "World.h"

/*####
## npc_brewfest_reveler
####*/

class npc_brewfest_reveler : public CreatureScript
{
public:
    npc_brewfest_reveler() : CreatureScript("npc_brewfest_reveler") { }

    struct npc_brewfest_revelerAI : public ScriptedAI
    {
        npc_brewfest_revelerAI(Creature* c) : ScriptedAI(c) {}

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            if (!IsHolidayActive(HOLIDAY_BREWFEST))
                return;

            if (emote == TEXT_EMOTE_DANCE)
                me->CastSpell(player, 41586, false);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brewfest_revelerAI(creature);
    }
};

enum eBrewfestSpells
{
    SPELL_NONE              = 0,
    SPELL_TROT              = 42992,
    SPELL_PETIT_GALOP       = 42993,
    SPELL_GRAND_GALOP       = 42994,

    SPELL_FATIGUE           = 43052,
    SPELL_EPUISE            = 43332,
    SPELL_BASE              = 43310,

    SPELL_MOD_SPEED         = 42924,

    // Quests

    SPELL_BUNNY_VERT        = 43345,
    SPELL_BUNNY_JAUNE       = 43346,
    SPELL_BUNNY_ROUGE       = 43347,

    SPELL_TRIGGER_BELIER    = 42149,
    SPELL_APPLE_VISUAL      = 43450,

    SPELL_THROW_BARREL      = 43660,
    SPELL_RECEIVE_BARREL    = 43662,
};

enum eBrewfestItems
{
    ITEM_BARREL             = 33797,
};

enum eBeliersQuests
{
    QUEST_BARREL_ALLIANCE       = 11122,
    QUEST_BARREL_HORDE          = 11412,
    QUEST_SPEED_ALLIANCE        = 11318,
    QUEST_SPEED_HORDE           = 11320,
    QUEST_SPEED_LOW             = 11409,

    QUEST_ALLIANCE_BARLEYBREWS  = 11293,
    QUEST_ALLIANCE_THUNDERBREWS = 11294,

    QUEST_HORDE_DROHN           = 11407,
    QUEST_HORDE_VAUDOO          = 11408,
};

bool isQuestInBelierQuest(uint32 questId)
{
    if (questId == QUEST_BARREL_ALLIANCE || questId == QUEST_BARREL_HORDE)
        return true;

    if (questId == QUEST_SPEED_ALLIANCE || questId == QUEST_SPEED_HORDE || questId == QUEST_SPEED_LOW)
        return true;

    if (questId == QUEST_ALLIANCE_BARLEYBREWS || questId == QUEST_ALLIANCE_THUNDERBREWS)
        return true;

    if (questId == QUEST_HORDE_DROHN || questId == QUEST_HORDE_VAUDOO)
        return true;

    return false;
}

class npc_brewfest_belier_quests_givers : public CreatureScript
{
public:
    npc_brewfest_belier_quests_givers() : CreatureScript("npc_brewfest_belier_quests_givers") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (isQuestInBelierQuest(quest->GetQuestId()))
            player->CastSpell(player, SPELL_TRIGGER_BELIER, false);

        return true;
    }
};

class npc_brewfest_apple_bunny : public CreatureScript
{
public:
    npc_brewfest_apple_bunny() : CreatureScript("npc_brewfest_apple_bunny") { }

    struct npc_brewfest_apple_bunnyAI : public ScriptedAI
    {
        npc_brewfest_apple_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {}

        void Reset() override
        {
            me->setFaction(35);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetVisible(false);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 15.0f)
                return;

            Player * pPlayer = who->ToPlayer();

            if (!pPlayer)
                return;

            if (pPlayer->HasAura(SPELL_FATIGUE) || pPlayer->HasAura(SPELL_EPUISE))
            {
                pPlayer->CastSpell(pPlayer, SPELL_APPLE_VISUAL, true);
                pPlayer->RemoveAurasDueToSpell(SPELL_EPUISE);
                pPlayer->RemoveAurasDueToSpell(SPELL_FATIGUE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brewfest_apple_bunnyAI(creature);
    }
};

class npc_brewfest_barker_bunny : public CreatureScript
{
public:
    npc_brewfest_barker_bunny() : CreatureScript("npc_brewfest_barker_bunny") { }

    struct npc_brewfest_barker_bunnyAI : public ScriptedAI
    {
        npc_brewfest_barker_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {}

        void Reset() override
        {
            me->setFaction(35);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetVisible(false);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 15.0f)
                return;

            Player * pPlayer = who->ToPlayer();

            if (!pPlayer)
                return;

            if (pPlayer->HasAura(SPELL_BASE))
            {
                pPlayer->KilledMonsterCredit(me->GetEntry());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brewfest_barker_bunnyAI(creature);
    }
};

class npc_brewfest_launch_barrel : public CreatureScript
{
public:
    npc_brewfest_launch_barrel() : CreatureScript("npc_brewfest_launch_barrel") { }

    struct npc_brewfest_launch_barrelAI : public ScriptedAI
    {
        npc_brewfest_launch_barrelAI(Creature* creature) : ScriptedAI(creature)
        {}

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 20.0f)
                return;

            Player * pPlayer = who->ToPlayer();

            if (!pPlayer)
                return;

            if (pPlayer->HasAura(SPELL_BASE))
                if (!pPlayer->HasItemCount(ITEM_BARREL, 1))
                    me->CastSpell(pPlayer, SPELL_THROW_BARREL, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brewfest_launch_barrelAI(creature);
    }
};

class npc_brewfest_receive_barrel : public CreatureScript
{
public:
    npc_brewfest_receive_barrel() : CreatureScript("npc_brewfest_receive_barrel") { }

    struct npc_brewfest_receive_barrelAI : public ScriptedAI
    {
        npc_brewfest_receive_barrelAI(Creature* creature) : ScriptedAI(creature)
        {}

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 15.0f)
                return;

            Player * pPlayer = who->ToPlayer();

            if (!pPlayer)
                return;

            if (pPlayer->HasAura(SPELL_BASE))
            {
                if (pPlayer->HasItemCount(ITEM_BARREL, 1))
                {
                    pPlayer->CastSpell(me, SPELL_RECEIVE_BARREL, true);
                    pPlayer->DestroyItemCount(ITEM_BARREL, 1, true);
                    pPlayer->KilledMonsterCredit(24337);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brewfest_receive_barrelAI(creature);
    }
};

// Dark Iron Guzzler in the Brewfest achievement 'Down With The Dark Iron'
enum DarkIronGuzzler
{
    NPC_DARK_IRON_GUZZLER       = 23709,
    NPC_DARK_IRON_HERALD        = 24536,
    NPC_DARK_IRON_SPAWN_BUNNY   = 23894,

    NPC_FESTIVE_KEG_1           = 23702, // Thunderbrew Festive Keg
    NPC_FESTIVE_KEG_2           = 23700, // Barleybrew Festive Keg
    NPC_FESTIVE_KEG_3           = 23706, // Gordok Festive Keg
    NPC_FESTIVE_KEG_4           = 24373, // T'chalis's Festive Keg
    NPC_FESTIVE_KEG_5           = 24372, // Drohn's Festive Keg

    SPELL_GO_TO_NEW_TARGET      = 42498,
    SPELL_ATTACK_KEG            = 42393,
    SPELL_RETREAT               = 42341,
    SPELL_DRINK                 = 42436,

    SAY_RANDOM                  = 0,
};

class npc_dark_iron_guzzler : public CreatureScript
{
public:
    npc_dark_iron_guzzler() : CreatureScript("npc_dark_iron_guzzler") { }

    CreatureAI *GetAI(Creature* creature) const override
    {
        return new npc_dark_iron_guzzlerAI(creature);
    }

    struct npc_dark_iron_guzzlerAI : public ScriptedAI
    {
        npc_dark_iron_guzzlerAI(Creature* creature) : ScriptedAI(creature) { }

        bool atKeg;
        bool playersLost;
        bool barleyAlive;
        bool thunderAlive;
        bool gordokAlive;
        bool drohnAlive;
        bool tchaliAlive;

        uint32 AttackKegTimer;
        uint32 TalkTimer;

        void Reset() override
        {
            AttackKegTimer = 5000;
            TalkTimer = (urand(1000, 120000));
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            // Only cast the spell on spawn
            DoCast(me, SPELL_GO_TO_NEW_TARGET);
        }

        // These values are set through SAI - when a Festive Keg dies it will set data to all Dark Iron Guzzlers within 3 yards (the killers)
        void SetData(uint32 type, uint32 data) override
        {
            if (type == 10 && data == 10)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                thunderAlive = false;
            }

            if (type == 11 && data == 11)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                barleyAlive = false;
            }

            if (type == 12 && data == 12)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                gordokAlive = false;
            }

            if (type == 13 && data == 13)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                drohnAlive = false;
            }

            if (type == 14 && data == 14)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                tchaliAlive = false;
            }
        }

        // As you can see here we do not have to use a spellscript for this
        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_DRINK)
            {
                // Fake death - it's only visual!
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                me->StopMoving();

                // Time based on information from videos
                me->DespawnOrUnsummon(7000);
            }

            // Retreat - run back
            if (spell->Id == SPELL_RETREAT)
            {
                // Remove walking flag so we start running
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                if (me->GetAreaId() == 1296)
                {
                    me->GetMotionMaster()->MovePoint(1, 1197.63f, -4293.571f, 21.243f);
                }
                else if (me->GetAreaId() == 1)
                {
                    me->GetMotionMaster()->MovePoint(2, -5152.3f, -603.529f, 398.356f);
                }
            }

            if (spell->Id == SPELL_GO_TO_NEW_TARGET)
            {
                // If we're at Durotar we target different kegs if we are at at Dun Morogh
                if (me->GetAreaId() == 1296)
                {
                    if (drohnAlive && gordokAlive && tchaliAlive)
                    {
                        switch (urand(0, 2))
                        {
                        case 0: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                            break;
                        case 1: // Drohn's Festive Keg
                            me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                            break;
                        case 2: // Ti'chali's Festive Keg
                            me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                            break;
                        }
                    }
                    else if (!drohnAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                            break;
                        case 1: // Ti'chali's Festive Keg
                            me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                            break;
                        }
                    }
                    else if (!gordokAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Drohn's Festive Keg
                            me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                            break;
                        case 1: // Ti'chali's Festive Keg
                            me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                            break;
                        }
                    }
                    else if (!tchaliAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                            break;
                        case 1: // Drohn's Festive Keg
                            me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                            break;
                        }
                    }
                }
                // If we're at Dun Morogh we target different kegs if we are at Durotar
                else if (me->GetAreaId() == 1)
                {
                    if (barleyAlive && gordokAlive && thunderAlive)
                    {
                        switch (urand(0, 2))
                        {
                        case 0: // Barleybrew Festive Keg
                            me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                            break;
                        case 1: // Thunderbrew Festive Keg
                            me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                            break;
                        case 2: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                            break;
                        }
                    }
                    else if (!barleyAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Thunderbrew Festive Keg
                            me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                            break;
                        case 1: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                            break;
                        }
                    }
                    else if (!gordokAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Barleybrew Festive Keg
                            me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                            break;
                        case 1: // Thunderbrew Festive Keg
                            me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                            break;
                        }
                    }
                    else if (!thunderAlive)
                    {
                        switch (urand(0, 1))
                        {
                        case 0: // Barleybrew Festive Keg
                            me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                            break;
                        case 1: // Gordok Festive Keg
                            me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                            break;
                        }
                    }
                }
                atKeg = false;
            }
        }

        void MovementInform(uint32 Type, uint32 PointId) override
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            // Arrived at the retreat spot, we should despawn
            if (PointId == 1 || PointId == 2)
                me->DespawnOrUnsummon(7000);

            // Arrived at the new keg - the spell has conditions in database
            if (PointId == 4 || PointId == 5 || PointId == 6 || PointId == 7 || PointId == 8 || PointId == 9)
            {
                DoCast(SPELL_ATTACK_KEG);
                me->SetStandState(UNIT_STAND_STATE_SIT);
                atKeg = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!IsHolidayActive(HOLIDAY_BREWFEST))
                return;

            // If all kegs are dead we should retreat because we have won
            if ((!gordokAlive && !thunderAlive && !barleyAlive) || (!gordokAlive && !drohnAlive && !tchaliAlive))
            {
                DoCast(me, SPELL_RETREAT);

                // We are doing this because we'll have to reset our scripts when we won
                if (Creature* herald = me->FindNearestCreature(NPC_DARK_IRON_HERALD, 100.0f))
                    herald->AI()->SetData(20, 20);

                // Despawn all summon bunnies so they will stop summoning guzzlers
                if (Creature* spawnbunny = me->FindNearestCreature(NPC_DARK_IRON_SPAWN_BUNNY, 100.0f))
                    spawnbunny->DespawnOrUnsummon();
            }

            if (TalkTimer <= diff)
            {
                me->AI()->Talk(SAY_RANDOM);
                TalkTimer = (urand(44000, 120000));
            } else TalkTimer -= diff;

            // Only happens if we're at keg
            if (atKeg)
            {
                if (AttackKegTimer <= diff)
                {
                    DoCast(SPELL_ATTACK_KEG);
                    AttackKegTimer = 5000;
                } else AttackKegTimer -= diff;
            }
        }
    };
};

#define NPC_CERVOISE     24108

class spell_hol_launch_beer : public SpellScriptLoader
{
    public:
        spell_hol_launch_beer() : SpellScriptLoader("spell_hol_launch_beer") { }

        class spell_hol_launch_beer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hol_launch_beer_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return true;
            }

            SpellCastResult CheckCast()
            {
                if (!GetExplTargetUnit())
                    return SPELL_FAILED_BAD_TARGETS;

                if (!GetExplTargetUnit()->ToCreature())
                    return SPELL_FAILED_BAD_TARGETS;

                if (GetExplTargetUnit()->ToCreature()->GetEntry() != NPC_CERVOISE)
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* cervoise = GetExplTargetUnit();

                if (!caster || !cervoise)
                    return;

                if (!caster->ToPlayer())
                    return;

                caster->ToPlayer()->KilledMonsterCredit(NPC_CERVOISE, cervoise->GetGUID());
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_hol_launch_beer_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnCheckCast += SpellCheckCastFn(spell_hol_launch_beer_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hol_launch_beer_SpellScript();
        }
};

#define NPC_WOLPERTINGER            23487
#define ITEM_CAPTURED_WOLPERTINGER  32906

class spell_hol_wolpertinger_net : public SpellScriptLoader
{
    public:
        spell_hol_wolpertinger_net() : SpellScriptLoader("spell_hol_wolpertinger_net") { }

        class spell_hol_wolpertinger_net_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hol_wolpertinger_net_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return true;
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();

                if (!caster)
                    return SPELL_FAILED_BAD_TARGETS;

                Creature * wolpertinger = caster->FindNearestCreature(NPC_WOLPERTINGER, 20.0f, true);

                if (!wolpertinger)
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (!caster)
                    return;

                Creature * wolpertinger = caster->FindNearestCreature(NPC_WOLPERTINGER, 20.0f, true);

                if (!wolpertinger)
                    return;

                wolpertinger->AddAura(59260, wolpertinger);
                wolpertinger->ToCreature()->DespawnOrUnsummon(2000);
                caster->ToPlayer()->AddItem(ITEM_CAPTURED_WOLPERTINGER, 1);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_hol_wolpertinger_net_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnCheckCast += SpellCheckCastFn(spell_hol_wolpertinger_net_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hol_wolpertinger_net_SpellScript();
        }
};

#define NEXT    true
#define PREV    false

enum eBeliersFatigue
{
    FATIGUE_NONE        = -7,
    FATIGUE_TROT        = -3,
    FATIGUE_PETIT_GALOP =  3,
    FATIGUE_GRAND_GALOP =  7,
};

enum eBeliersTime
{
    TIME_TROT           = 11, // 20 secs
    TIME_PETIT_GALOP    = 7,  // 12 secs
    TIME_GRAND_GALOP    = 4,  // 6 secs
};

uint32 getSpeedSpellOnTarget(Unit * target)
{
    if (!target)
        return SPELL_NONE;

    if (target->HasAura(SPELL_TROT))
        return SPELL_TROT;

    if (target->HasAura(SPELL_PETIT_GALOP))
        return SPELL_PETIT_GALOP;

    if (target->HasAura(SPELL_GRAND_GALOP))
        return SPELL_GRAND_GALOP;

    return SPELL_NONE;
}

uint32 getNextOrPrevSpeedSpell(bool next, uint32 currentId)
{
    uint32 returnSpell = 0;

    switch (currentId)
    {
        case SPELL_NONE:
            returnSpell = !next ? currentId:            SPELL_TROT;
            break;
        case SPELL_TROT:
            returnSpell = !next ? SPELL_NONE:           SPELL_PETIT_GALOP;
            break;
        case SPELL_PETIT_GALOP:
            returnSpell = !next ? SPELL_TROT:           SPELL_GRAND_GALOP;
            break;
        case SPELL_GRAND_GALOP:
            returnSpell = !next ? SPELL_PETIT_GALOP:    currentId;
            break;
    }

    return returnSpell;
}

int32 getFatigueModForSpell(uint32 spellId)
{
    switch (spellId)
    {
        case SPELL_NONE:        return FATIGUE_NONE;
        case SPELL_TROT:        return FATIGUE_TROT;
        case SPELL_PETIT_GALOP: return FATIGUE_PETIT_GALOP;
        case SPELL_GRAND_GALOP: return FATIGUE_GRAND_GALOP;
    }

    return 0;
}

uint8 getTimeForSpell(uint32 spellId)
{
    switch (spellId)
    {
        case SPELL_TROT:        return TIME_TROT;
        case SPELL_PETIT_GALOP: return TIME_PETIT_GALOP;
        case SPELL_GRAND_GALOP: return TIME_GRAND_GALOP;
    }

    return 0;
}

class spell_hol_belier_base : public SpellScriptLoader
{
    public:
        spell_hol_belier_base() : SpellScriptLoader("spell_hol_belier_base") { }

        class spell_hol_belier_base_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hol_belier_base_AuraScript);

            bool Load() override
            {
                return true;
            }

            // Toutes les 2 secondes
            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit * target = GetTarget();

                if (!target)
                    return;

                uint32 currentSpell = getSpeedSpellOnTarget(GetTarget());
                int32 currentFatigueMod = getFatigueModForSpell(currentSpell);

                if (Aura* fatigueAura = target->GetAura(SPELL_FATIGUE))
                {
                    int8 currentStack = fatigueAura->GetStackAmount();
                    int8 newStack = currentStack + currentFatigueMod;

                    if (newStack < 0)
                        newStack = 0;

                    if (newStack >= 100)
                    {
                        target->RemoveAurasDueToSpell(currentSpell);
                        target->RemoveAurasDueToSpell(SPELL_FATIGUE);
                        target->AddAura(SPELL_EPUISE, target);
                    }
                    else
                        fatigueAura->SetStackAmount(uint8(newStack));
                }
                else
                    if (currentFatigueMod > 0)
                        if (Aura* aura = target->AddAura(SPELL_FATIGUE, target))
                            aura->SetStackAmount(currentFatigueMod);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hol_belier_base_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hol_belier_base_AuraScript();
        }
};

class spell_hol_belier_renes : public SpellScriptLoader
{
    public:
        spell_hol_belier_renes() : SpellScriptLoader("spell_hol_belier_renes") { }

        class spell_hol_belier_renes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hol_belier_renes_AuraScript);

            bool Load() override
            {
                return true;
            }

            // Toutes les 2 secondes
            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit * target = GetTarget();

                if (!target)
                    return;

                if (Aura* reneAura = target->GetAura(SPELL_MOD_SPEED))
                {
                    uint32 currentSpell = getSpeedSpellOnTarget(target);

                    if (currentSpell == SPELL_NONE)
                    {
                        target->RemoveAura(reneAura);
                        return;
                    }

                    int8 currentStack = reneAura->GetStackAmount();
                    int8 nextStack = ++currentStack;

                    // x temps on passe depuis qu'il a le spell
                    if (nextStack == getTimeForSpell(currentSpell))
                    {
                        uint32 prevSpell = getNextOrPrevSpeedSpell(PREV, currentSpell);
                        target->RemoveAurasDueToSpell(currentSpell);
                        target->AddAura(prevSpell, target);
                        reneAura->SetStackAmount(1);
                    }
                    else
                        reneAura->SetStackAmount(nextStack);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hol_belier_renes_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        class spell_hol_belier_renes_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hol_belier_renes_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return true;
            }

            SpellCastResult CheckCast()
            {
                if (!GetCaster())
                    return SPELL_FAILED_BAD_TARGETS;

                if (GetCaster()->HasAura(SPELL_EPUISE))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                if (!GetCaster()->HasAura(SPELL_BASE))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (!caster)
                    return;

                uint32 currentSpell = getSpeedSpellOnTarget(caster);
                uint32 nextSpell = getNextOrPrevSpeedSpell(NEXT, currentSpell);

                if (currentSpell != nextSpell)
                {
                    if (currentSpell)
                        caster->RemoveAurasDueToSpell(currentSpell);

                    if (nextSpell)
                        caster->AddAura(nextSpell, caster);
                }

                if (Aura* reneAura = caster->GetAura(SPELL_MOD_SPEED))
                    reneAura->SetStackAmount(1);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_hol_belier_renes_SpellScript::CheckCast);
                OnEffectHit += SpellEffectFn(spell_hol_belier_renes_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hol_belier_renes_AuraScript();
        }

        SpellScript* GetSpellScript() const override
        {
            return new spell_hol_belier_renes_SpellScript();
        }
};

class spell_hol_belier_all_speeds : public SpellScriptLoader
{
    public:
        spell_hol_belier_all_speeds() : SpellScriptLoader("spell_hol_belier_all_speeds") { }

        class spell_hol_belier_all_speeds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hol_belier_all_speeds_AuraScript);

            bool Load() override
            {
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                timeCounter = 0;
            }

            // Toutes les 2 secondes
            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                timeCounter++;

                Unit * caster = GetCaster();

                if (!caster)
                    return;

                if (!caster->HasAura(SPELL_BASE))
                    caster->RemoveAurasDueToSpell(GetId());

                if (timeCounter >= 4)
                {
                    uint32 bunnySpell = 0;

                    switch (GetId())
                    {
                        case SPELL_TROT:        bunnySpell = SPELL_BUNNY_VERT; break;
                        case SPELL_PETIT_GALOP: bunnySpell = SPELL_BUNNY_JAUNE; break;
                        case SPELL_GRAND_GALOP: bunnySpell = SPELL_BUNNY_ROUGE; break;
                    }

                    if (bunnySpell)
                        caster->CastSpell(GetCaster(), bunnySpell, true);
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_hol_belier_all_speeds_AuraScript::HandleEffectApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hol_belier_all_speeds_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }

            uint32 timeCounter;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hol_belier_all_speeds_AuraScript();
        }
};

class spell_hol_beliers : public SpellScriptLoader
{
    public:
        spell_hol_beliers() : SpellScriptLoader("spell_hol_beliers") { }

        class spell_hol_beliers_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hol_beliers_AuraScript);

            bool Load() override
            {
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->RemoveAurasDueToSpell(SPELL_FATIGUE);
                GetTarget()->RemoveAurasDueToSpell(SPELL_TROT);
                GetTarget()->RemoveAurasDueToSpell(SPELL_PETIT_GALOP);
                GetTarget()->RemoveAurasDueToSpell(SPELL_GRAND_GALOP);
                GetTarget()->RemoveAurasDueToSpell(SPELL_EPUISE);
                GetTarget()->RemoveAurasDueToSpell(SPELL_FATIGUE);

                if (Player * pPlayer = GetTarget()->ToPlayer())
                    if (pPlayer->HasItemCount(33797, 1))
                        pPlayer->DestroyItemCount(33797, 1, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hol_beliers_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOUNTED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hol_beliers_AuraScript();
        }
};

void AddSC_event_brewfest()
{
    new npc_brewfest_reveler();
    new npc_brewfest_belier_quests_givers();
    new npc_brewfest_apple_bunny();
    new npc_brewfest_barker_bunny();
    new npc_brewfest_launch_barrel();
    new npc_brewfest_receive_barrel();
    new npc_dark_iron_guzzler();
    new spell_hol_launch_beer();
    new spell_hol_wolpertinger_net();
    new spell_hol_belier_base();
    new spell_hol_belier_renes();
    new spell_hol_belier_all_speeds();
    new spell_hol_beliers();
}
