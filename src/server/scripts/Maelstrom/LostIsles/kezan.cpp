/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010 - 2012 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "ScriptedEscortAI.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Item.h"
#include "GameObject.h"
#include "Creature.h"
#include "Vehicle.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "WorldSession.h"

enum NPC_DeffiantTroll
{
    SPELL_RAGE                = 45111,
    SPELL_SLEEP                = 62248,
    DEFFIANT_KILL_CREDIT               = 34830,
    SPELL_LIGHTNING_VISUAL             = 45870,
    QUEST_GOOD_HELP_IS_HARD_TO_FIND    = 14069,
    GO_DEPOSIT                         = 202593,
    GO_DEPOSIT_CHUNK = 195492,
};

#define SAY_WORK_1 "Sorry dude. It won't happen again."
#define SAY_WORK_2 "I'm coming, I'm coming!"
#define SAY_WORK_3 "The directress will hear about you!"
#define SAY_WORK_4 "The work was better in Undermine!"
#define SAY_WORK_5 "Outch, it hurts!"
#define SAY_WORK_6 "Oups, end of the work break."
#define SAY_WORK_7 "Not the taser, man!"
#define SAY_WORK_8 "What's wrong? Why I can't take my lunch break and my two breakfast per day. I don't have the right for it?"

class npc_defiant_troll : public CreatureScript
{
public:
    npc_defiant_troll() : CreatureScript("npc_defiant_troll") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defiant_trollAI(creature);
    }

    struct npc_defiant_trollAI : public ScriptedAI
    {
        npc_defiant_trollAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            rebuffTimer = 60000;
            work = false;
            auraTimer = 0;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                work = true;
            //me->LoadEquipment(2901, true);
        }

        void JustReachedHome() { }

        void SpellHits(Unit* caster, const SpellEntry* spell)
        {
            if (!me->HasAura(SPELL_RAGE))
            {
                caster->ToPlayer()->RemoveAura(SPELL_LIGHTNING_VISUAL);
                return ;
            }
            if (spell->ID == SPELL_LIGHTNING_VISUAL && caster->GetTypeId() == TYPEID_PLAYER
                && caster->ToPlayer()->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE && work == false)
            {
                caster->ToPlayer()->KilledMonsterCredit(DEFFIANT_KILL_CREDIT, me->GetGUID());
                me->RemoveAllAuras();
                switch (irand(0, 7))
                {
                case 0:
                    me->Yell(SAY_WORK_1, LANG_UNIVERSAL);
                    break;
                case 1:
                    me->Yell(SAY_WORK_2, LANG_UNIVERSAL);
                    break;
                case 2:
                    me->Yell(SAY_WORK_3, LANG_UNIVERSAL);
                    break;
                case 3:
                    me->Yell(SAY_WORK_4, LANG_UNIVERSAL);
                    break;
                case 4:
                    me->Yell(SAY_WORK_5, LANG_UNIVERSAL);
                    break;
                case 5:
                    me->Yell(SAY_WORK_6, LANG_UNIVERSAL);
                    break;
                case 6:
                    me->Yell(SAY_WORK_7, LANG_UNIVERSAL);
                    break;
                case 7:
                    me->Yell(SAY_WORK_8, LANG_UNIVERSAL);
                    break;
                }
                caster->ToPlayer()->RemoveAura(SPELL_LIGHTNING_VISUAL);
                if (GameObject* Deposit = me->FindNearestGameObject(GO_DEPOSIT, 20))
                    me->GetMotionMaster()->MovePoint(1, Deposit->GetPositionX()-1, Deposit->GetPositionY(), Deposit->GetPositionZ());
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (me->HasAura(SPELL_RAGE))
                return ;

            if (work == true)
                me->HandleEmoteCommand(467);

            if (rebuffTimer <= diff)
            {
                switch (irand(0, 2))
                {
                case 0:
                    me->HandleEmoteCommand(412);
                    break;
                case 1:
                    me->HandleEmoteCommand(10);
                    break;
                case 2:
                    me->HandleEmoteCommand(0);
                    break;
                }
                rebuffTimer = 60000;                 //Rebuff agian in 1 minutes
                float x, y, z, o;
                me->GetHomePosition(x, y, z, o);
                me->NearTeleportTo(x, y, z, o);
                me->AddAura(SPELL_RAGE, me);
                me->AddAura(SPELL_SLEEP, me);

                work = false;
            }
            else
                rebuffTimer -= diff;
        }

    private:
        uint32 rebuffTimer;
        uint32 auraTimer;
        bool work;

    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(creature, SPELL_LIGHTNING_VISUAL, true);
            SpellEntry const* spell = sSpellStore.LookupEntry(SPELL_LIGHTNING_VISUAL);
            CAST_AI(npc_defiant_troll::npc_defiant_trollAI, creature->AI())->SpellHits(player, spell);
            return true;
        }
        return false;
  }

};

enum NPC_BlingBling
{
    SPELL_OUTFIT = 66781,
    SPELL_COOL_SHADE = 66782,
    SPELL_SHINY_BLING = 66780,
    QUEST_BLINGBLING = 14110,
    NPC_SCABO    = 35128,
    NPC_MISSA = 35130,
    NPC_DIASTEME = 35126,
};

class npc_bling_bling : public CreatureScript
{
public:
    npc_bling_bling() : CreatureScript("npc_bling_bling") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bling_blingAI(creature);
    }

    struct npc_bling_blingAI : public ScriptedAI
    {
        npc_bling_blingAI(Creature* creature) : ScriptedAI(creature) {}
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(QUEST_BLINGBLING) == QUEST_STATUS_INCOMPLETE)
        {
            if (creature->GetEntry() == NPC_SCABO)
                player->CastSpell(player, SPELL_OUTFIT, true);
            if (creature->GetEntry() == NPC_MISSA)
                player->CastSpell(player, SPELL_COOL_SHADE, true);
            if (creature->GetEntry() == NPC_DIASTEME)
                player->CastSpell(player, SPELL_SHINY_BLING, true);
            return true;
        }
        return false;
    }
};

enum NPC_Bambo
{
    SPELL_DRINK = 66909,
    SPELL_WATER = 66910,
    SPELL_DANCE = 66911,
    SPELL_FIRE = 66912,
    SPELL_FOOD = 66913,
    BAMBO_KILL_CREDIT = 35186,
    QUEST_T = 14153,
    QUEST_T2 = 14113,
};

#define SAY_D_A "This sparkling white wine is delicious. Where did you find it?"
#define SAY_D_B "I feel much better now. hic !"
#define SAY_D_C "Thanksh !"
#define SAY_D_D "Errrrk. I need a pail!"
#define SAY_D_E "I feel much better now. hic !"
#define SAY_D_F "It's really good, thanks!"
#define SAY_D_G "I am hungry! Where is the food!?"
#define SAY_D_H "Thanks. I had soon finished. Miam Miam !"
#define SAY_D_I "Delicious! And this is only appetizers?"
#define SAY_D_J "If only I had someone to dance with..."
#define SAY_D_K "This party misses bit of shining :( ."
#define SAY_D_L "Oh yeahhhh! Nice a disco ball! Let's go PARTY woohoo!"
#define SAY_D_M "Ah I am loving it! Move your butt Wouhou!"
#define SAY_D_N "I love fireworks! It has to explode in the eardrum and that dazzling sight."
#define SAY_D_O "Wouhou, fireworks! Again, again!"
#define SAY_D_P "Woahhh ! I have never seen something so cool. Again, again!!!"
#define SAY_D_Q "More food would not be useless."

class npc_bambo : public CreatureScript
{
public:
    npc_bambo() : CreatureScript("npc_bambo") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bamboAI(creature);
    }

    struct npc_bamboAI : public ScriptedAI
    {
        npc_bamboAI(Creature* creature) : ScriptedAI(creature)
        {
        }


        void Reset() override
        {
            rebuffTimer = 60000;
            rebuffsTimer = urand(35000, 180000);
            DoBuff();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who->ToPlayer())
                return ;
            if (who->ToPlayer()->GetQuestStatus(QUEST_T) != QUEST_STATUS_INCOMPLETE && who->ToPlayer()->GetQuestStatus(QUEST_T2) != QUEST_STATUS_INCOMPLETE)
            {
                if (who->HasAura(66908))
                    who->RemoveAura(66908);
                who->RemoveAura(66927);
                who->RemoveAura(66928);
                return ;
            }
            if (!who->HasAura(66908))
            {
                who->AddAura(66908, who);
                if (who->getGender() == GENDER_MALE)
                    who->AddAura(66928, who);
                else
                    who->AddAura(66927, who);
            }
        }

        void playtalk(bool eff)
        {
            if (me->HasAura(75042))
            {
                if (eff)
                {
                    switch (urand(0, 2))
                    {
                    case 0:
                        me->Say(SAY_D_A, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(17);
                        break;
                    case 1:
                        me->Say(SAY_D_B, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(17);
                        break;
                    case 2:
                        me->Say(SAY_D_C, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(17);
                        break;
                    }
                }
                else
                {
                    me->Say(SAY_D_Q, LANG_UNIVERSAL, 0);
                    me->HandleEmoteCommand(1);
                }
            }
            if (me->HasAura(75044))
            {
                if (eff)
                {
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->Say(SAY_D_E, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(23);
                        break;
                    case 1:
                        me->Say(SAY_D_F, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(17);
                        break;
                    }
                }
                else
                {
                    me->Say(SAY_D_D, LANG_UNIVERSAL, 0);
                    me->HandleEmoteCommand(1);
                }
            }
            if (me->HasAura(75050))
            {
                if (eff)
                {
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->Say(SAY_D_H, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(7);
                        break;
                    case 1:
                        me->Say(SAY_D_I, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(7);
                        break;
                    }
                }
                else
                {
                    me->Say(SAY_D_G, LANG_UNIVERSAL, 0);
                    me->HandleEmoteCommand(6);
                }
            }
            if (me->HasAura(75048))
            {
                if (eff)
                {
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->Say(SAY_D_P, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(400);
                        break;
                    case 1:
                        me->Say(SAY_D_O, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(401);
                        break;
                    }
                }
                else
                {
                    me->Say(SAY_D_N, LANG_UNIVERSAL, 0);
                    me->HandleEmoteCommand(5);
                }
            }
            if (me->HasAura(75046))
            {
                if (eff)
                {
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->Say(SAY_D_L, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(395);
                        break;
                    case 1:
                        me->Say(SAY_D_M, LANG_UNIVERSAL, 0);
                        me->HandleEmoteCommand(21);
                        break;
                    }
                }
                else
                {
                    me->Say(SAY_D_J, LANG_UNIVERSAL, 0);
                    me->HandleEmoteCommand(18);
                }
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (!caster->ToPlayer())
                return ;

            if ((caster->ToPlayer()->GetQuestStatus(QUEST_T) != QUEST_STATUS_INCOMPLETE && caster->ToPlayer()->GetQuestStatus(QUEST_T2) != QUEST_STATUS_INCOMPLETE)
                || caster->GetTypeId() != TYPEID_PLAYER)
                return ;

            switch (spell->Id)
            {
            case SPELL_DRINK :
                if (!me->HasAura(75042))
                    return;
                playtalk(true);
                me->RemoveAura(75042);
                me->CastSpell(me, 66917 , true);
                me->AddAura(66916, me);
                break;
            case SPELL_WATER :
                if (!me->HasAura(75044))
                    return;
                playtalk(true);
                me->RemoveAura(75044);
                me->RemoveAura(55664);
                me->RemoveAura(46957);
                me->CastSpell(me, 66918 , true);
                me->AddAura(66916, me);
                break;
            case SPELL_DANCE :
                if (!me->HasAura(75046))
                    return;
                playtalk(true);
                me->RemoveAura(75046);
                me->CastSpell(me, 66918 , true);
                me->AddAura(66916, me);
                break;
            case SPELL_FIRE :
                if (!me->HasAura(75048))
                    return;
                playtalk(true);
                me->RemoveAura(75048);
                caster->ToPlayer()->CastSpell(caster, 66917 , true);
                me->CastSpell(me, 66919 , true);
                me->AddAura(66916, me);
                break;
            case SPELL_FOOD :
                if (!me->HasAura(75050))
                    return;
                playtalk(true);
                me->RemoveAura(75050);
                me->CastSpell(me, 66916 , true);
                me->AddAura(66916, me);
                break;
            default:
                break;
            }
            if (!me->HasAura(75048) && !me->HasAura(75050) && !me->HasAura(75046) && !me->HasAura(75044) && !me->HasAura(75042))
                caster->ToPlayer()->KilledMonsterCredit(BAMBO_KILL_CREDIT, me->GetGUID());
        }

        void DoBuff()
        {
            switch (urand(0, 5))
            {
            case 0:
                me->AddAura(75042, me);
                break;
            case 1:
                me->AddAura(75044, me);
                break;
            case 2:
                me->AddAura(75046, me);
                break;
            case 3:
                me->AddAura(75048, me);
                break;
            case 4:
                me->AddAura(75050, me);
                break;
            default:
                me->AddAura(75050, me);
                break;
            }
            me->RemoveAura(66916);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (me->HasAura(75042) || me->HasAura(75044) || me->HasAura(75046) || me->HasAura(75048) || me->HasAura(75050))
            {
                if (rebuffsTimer <= diff)
                {
                    rebuffsTimer = urand(35000, 180000);
                    playtalk(false);
                }
                else
                    rebuffsTimer -= diff;
                return;
            }
            if (rebuffTimer <= diff)
            {
                rebuffTimer = 120000;
                DoBuff();
            }
            else
                rebuffTimer -= diff;
        }

    private:
        uint32 rebuffTimer;
        uint32 rebuffsTimer;
        bool work;
    };
};

class gob_bank_gobelin : public GameObjectScript
{
public:
    gob_bank_gobelin() : GameObjectScript("gob_bank_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(14122) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature *t = player->SummonCreature(35486, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
                t->SetPhaseMask(2048, true);
            if (Creature *t = player->SummonCreature(850000, go->GetPositionX(), go->GetPositionY(),  go->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
                t->SetPhaseMask(2048, true);
            return true;
        }
        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 sender, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(player);
        return true;
    }
};

class spell_kabummbomb : public SpellScriptLoader
{
public:
    spell_kabummbomb() : SpellScriptLoader("spell_kabummbomb") { }

    class spell_kabummbombSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_kabummbombSpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            return true;
        }


        bool Load() override
        {
            return true;
        }


        void HandleActivateGameobject(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCastItem()->GetOwner())
            {
                if (caster->ToPlayer()->GetQuestStatus(14124) != QUEST_STATUS_INCOMPLETE)
                    return;
                if (GameObject* Deposit = caster->FindNearestGameObject(GO_DEPOSIT, 20))
                {
                    caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY(), Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                    caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY()-1, Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                    caster->SummonGameObject(GO_DEPOSIT_CHUNK, Deposit->GetPositionX()-1, Deposit->GetPositionY()+1, Deposit->GetPositionZ()+1, 0, QuaternionData(), 0);
                    Deposit->Delete();
                }
            }
        }


        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_kabummbombSpellScript::HandleActivateGameobject,EFFECT_0,SPELL_EFFECT_ACTIVATE_OBJECT);
        }
    };


    SpellScript *GetSpellScript() const
    {
        return new spell_kabummbombSpellScript();
    }
};


class npc_citoyen_gob : public CreatureScript
{
public:
    npc_citoyen_gob() : CreatureScript("npc_citoyen_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_citoyen_gobAI(creature);
    }

    struct npc_citoyen_gobAI : public ScriptedAI
    {
        npc_citoyen_gobAI(Creature* creature) : ScriptedAI(creature) {}


        void Reset() override
        {
            _s = urand(3000, 7000);
            _t = 2000;
            move = false;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
        }

        void JustReachedHome() override
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->ToPlayer() || move)
                return ;
            if (!me->IsWithinDistInMap(who, 2.0f))
                return ;
            if (who->GetEntry() == 34840)
            {
                switch (urand(0, 16))
                {
                case 0 :
                    me->Yell("Learn how to drive, kind of freak!", LANG_UNIVERSAL, 0);
                    break;
                case 1 :
                    me->Yell("The merchant prince will hear about that, I can tell you!", LANG_UNIVERSAL, 0);
                    break;
                case 2 :
                    me->Say("But check where you are going!", LANG_UNIVERSAL, 0);
                    break;
                case 3 :
                    me->Kill(me);
                    return ;
                case 4 :
                    me->Say("My lawyer will not miss you!", LANG_UNIVERSAL, 0);
                    break;
                case 5 :
                    me->Say("My neck! I will sue you in justice!", LANG_UNIVERSAL, 0);
                    break;
                case 6 :
                    me->Say("We will see you in court!", LANG_UNIVERSAL, 0);
                    break;
                case 7 :
                    me->Say("Outch!", LANG_UNIVERSAL, 0);
                    break;
                case 8 :
                    me->Say("You are a real public danger!", LANG_UNIVERSAL, 0);
                    break;
                case 9 :
                    me->Yell("Doctor !", LANG_UNIVERSAL, 0);
                    break;
                default :
                    break;
                }
                int x, y;
                x = 0;
                y = 0;
                switch (urand(0, 1))
                {
                case 0:
                    x = - irand(5, 10);
                    break;
                case 1:
                    x = irand(5, 10);
                    break;
                }
                switch (irand(0, 1))
                {
                case 0:
                    y = - irand(5, 10);
                    break;
                case 1:
                    y = irand(5, 10);
                    break;
                }
                _t = 6000;
                if (me->GetEntry() == 35234)
                    if (Unit *pl = who->GetVehicleKit()->GetPassenger(0))
                        if (pl->ToPlayer())
                        {
                            if (pl->ToPlayer()->GetQuestStatus(14121) == QUEST_STATUS_INCOMPLETE)
                                pl->ToPlayer()->AddItem(47530, 1);
                            _t = 2000;
                        }
                me->GetMotionMaster()->MoveJump(me->GetPositionX() + x, me->GetPositionY() + y, me->GetPositionZ() + 1, 0.0f, 10.0f, 10.0f);
                move = true;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (_t <= diff)
            {
                if (move)
                {
                    me->GetMotionMaster()->MoveTargetedHome();
                    move = false;
                    if (me->GetEntry() == 35234)
                    {
                        me->Kill(me);
                        return ;
                    }
                }
                _t = 40000000;
            }
            else
                _t -= diff;
            if (_s <= diff)
            {
                _s = urand(5000, 11350);
                if (!UpdateVictim() || me->GetEntry() != 35234)
                    return;
                DoCastVictim(6257);
            }
            else
                _s -= diff;
        }

    private :
        uint32 _t, _s;
        bool move;
    };
};

class gob_canon_gobelin : public GameObjectScript
{
public:
    gob_canon_gobelin() : GameObjectScript("gob_canon_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        player->GetMotionMaster()->MoveJump( -7851.79f, 1838.72f, 8.0f, 0.0f, 20.0f, 20.0f);
        return true;
    }

};

class gob_control_gobelin : public GameObjectScript
{
public:
    gob_control_gobelin() : GameObjectScript("gob_control_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(14125) == QUEST_STATUS_COMPLETE)
        {
            if (go->FindNearestCreature(37598, 200) == NULL)
                go->SummonCreature(37598, go->GetPositionX() + 2, go->GetPositionY() + 2, go->GetPositionZ() + 1, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 45000);
            player->KilledMonsterCredit(37598, go->GetGUID());
            return true;
        }
        return true;
    }
};

class npc_robot_gob : public CreatureScript
{
public:
    npc_robot_gob() : CreatureScript("npc_robot_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_robot_gobAI(creature);
    }

    struct npc_robot_gobAI : public ScriptedAI
    {
        npc_robot_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->SetPhaseMask(2048, true);
            const Player *pl  = me->SelectNearestPlayer(50);
            if (pl)
                _playerGUID = pl->GetGUID();
            if (!pl || pl->GetQuestStatus(14125) != QUEST_STATUS_COMPLETE)
                me->Kill(me);
            _t = 200;
            _s = 600000;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            me->CastSpell(me, 70259, true);
            me->CastSpell(me, 70262, true);
            if (id == 1)
                _s = 1200;
        }


        void JustReachedHome() override
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (_t <= diff)
            {
                me->GetMotionMaster()->MovePoint(1, -8423.85f, 1365.88f, 104.7f);
                _t = 300000;
            }
            else _t -= diff;

            if (_s <= diff)
            {
                if (Player *pl = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    if (pl->GetQuestStatus(14125) == QUEST_STATUS_COMPLETE)
                    {
                        pl->SetAuraStack(68481, pl, 1);
                    }
                me->Kill(me);
                _s = 300000;
            }
            else _s -= diff;
        }

    private :
        uint32 _t;
        uint32 _s;
        ObjectGuid _playerGUID;
    };
};

class npc_galaw: public CreatureScript
{
public:
    npc_galaw() : CreatureScript("npc_galaw") {}

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 14120)
        {
            player->RemoveAurasDueToSpell(59074);
            player->SetAuraStack(67789, player, 1);
        }
        return true;
    }
};

class npc_sumkaja_gob : public CreatureScript
{
public:
    npc_sumkaja_gob() : CreatureScript("npc_sumkaja_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sumkaja_gobAI(creature);
    }

    struct npc_sumkaja_gobAI : public ScriptedAI
    {
        npc_sumkaja_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            _t = 1000;
        }

        void JustReachedHome() {}

        void UpdateAI(const uint32 diff) override
        {
            if (_t <= diff)
            {
                if (me->FindNearestGameObject(GO_DEPOSIT, 5) == NULL)
                    me->SummonGameObject(GO_DEPOSIT, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, QuaternionData(), 120000);
                _t = 60000;
            }
            else _t -= diff;
        }

    private :
        uint32 _t;
    };
};

class npc_meteor_gob : public CreatureScript
{
public:
    npc_meteor_gob() : CreatureScript("npc_meteor_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_meteor_gobAI(creature);
    }

    struct npc_meteor_gobAI : public ScriptedAI
    {
        npc_meteor_gobAI(Creature* creature) : ScriptedAI(creature) {}


        void Reset() override
        {
            _a = urand(66000, 200200);
            _b = 600000;
            _c = 600000;
        }

        void JustReachedHome() {}

        void UpdateAI(const uint32 diff) override
        {
            if (_a <= diff)
            {
                me->CastSpell(me, 93668, true);
                _a = urand(66000, 200200);
                _b = 800;
            }
            else _a -= diff;
            if (_b <= diff)
            {
                me->CastSpell(me, 87701, true);
                _b = 600000;
                _c = 500;
            }
            else _b -= diff;
            if (_c <= diff)
            {
                me->CastSpell(me, 69235, true);
                _c = 600000;
            }
            else _c -= diff;
        }

    private :
        uint32 _a, _b, _c;
    };
};


#define TREMBLEMENT_PERSO 78607
#define QUEST_BRUTALITY_NECESSARY 24502
#define QUEST_BRUTALITY_NECESSARY_ROUND_2 28414
#define NPC_SHARK 37179
#define NPC_SHARK_2 37213
#define ACCEPT_EVENT 42

class npc_gw: public CreatureScript
{
public:
    npc_gw() : CreatureScript("npc_gw") {}

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 ) override
    {
        if (_Quest->GetQuestId() == QUEST_BRUTALITY_NECESSARY_ROUND_2)
            player->CastSpell(player, 78607, true);
        return false;
    }

    bool OnQuestComplete (Player* player, Creature* creature, Quest const* quest)
    {
        return false;
    }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* _Quest) override
    {
        if (_Quest->GetQuestId() == QUEST_BRUTALITY_NECESSARY || _Quest->GetQuestId() == QUEST_BRUTALITY_NECESSARY_ROUND_2)
        {
            Creature *c = NULL;
            if (_Quest->GetQuestId() == QUEST_BRUTALITY_NECESSARY)
                c = player->SummonCreature(NPC_SHARK, -8249.41f, 1485.15f, 41.34f, 3.06f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 750000);
            else if (_Quest->GetQuestId() == QUEST_BRUTALITY_NECESSARY_ROUND_2)
                c = player->SummonCreature(NPC_SHARK_2, -8249.41f, 1485.15f, 41.34f, 3.06f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 750000);
            if (c != NULL)
            {
                uint32 questId = _Quest->GetQuestId();
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, c, false);
                c->AI()->SetData(questId, ACCEPT_EVENT);
            }
        }
        return false;
    }
};

const Position SharkPos[8] =
{
    { -8278.0f, 1485.0f, 43.14f, 6.28f},
    { -8285.0f, 1485.0f, 43.9f, 6.28f},
    { -8285.61f, 1489.94f, 43.9f, 6.28f},
    { -8285.76f, 1480.03f, 43.9f, 6.28f},
    { -8290.68f, 1475.38f, 43.95f, 6.28f},
    { -8291.06f, 1480.00f, 43.98f, 6.28f},
    { -8290.98f, 1487.85f ,43.99f, 6.28f},
    { -8290.90f, 1492.98f, 43.9f, 6.28f},
};

class npc_boucanier_gob : public CreatureScript
{
public:
    npc_boucanier_gob() : CreatureScript("npc_boucanier_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_boucanier_gobAI(creature);
    }

    struct npc_boucanier_gobAI : public ScriptedAI
    {
        npc_boucanier_gobAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() override
        {
            _t = 1000;
            activate = true;
        }

        void SetData(uint32 type, uint32 value) override
        {
            if (value != ACCEPT_EVENT)
                return;
            Player *player = NULL;
            if (me->ToTempSummon())
                if (Unit *u = me->ToTempSummon()->GetSummoner())
                    if (u->GetTypeId() == TYPEID_PLAYER)
                        player = u->ToPlayer();
            if (player == NULL)
                return;
            if (player->GetQuestStatus(type) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(37179, me->GetGUID());
                me->AddAura(70016, me);
                if (type == QUEST_BRUTALITY_NECESSARY)
                    for (unsigned int cnt = 0; cnt < 8; cnt++)
                        DoSpawnShark(cnt);
            }
            me->SetSpeed(MOVE_RUN, 0.001f);
            _t = 1000;
            activate = true;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
        }

        void JustReachedHome() override
        {
        }

        void DoSpawnShark(int i)
        {
            me->SummonCreature(37114, SharkPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60*IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (_t <= diff)
            {
                _t = 1000;
                if (activate)
                    me->DespawnOrUnsummon(); // prevent possible usebug for mass poping creatures
                activate = false;
            }
            else _t -= diff;
        }

    private :
        bool activate;
        uint32 _t;
    };
};

#define YENDPOINT 8250

class npc_shark_gob : public CreatureScript
{
public:
    npc_shark_gob() : CreatureScript("npc_shark_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shark_gobAI(creature);
    }

    struct npc_shark_gobAI : public ScriptedAI
    {
        npc_shark_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            _t = 3000;
            start = false;
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                me->DespawnOrUnsummon();
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 69993)
            {
                if (caster->GetVehicleKit())
                    if (Unit *un = caster->GetVehicleKit()->GetPassenger(0))
                        if (un->GetTypeId() == TYPEID_PLAYER)
                            un->ToPlayer()->KilledMonsterCredit(37114, me->GetGUID());
                caster->Kill(me);
            }
        }

        void JustReachedHome() override
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (start)
                return;
            if (_t <= diff)
            {
                me->GetMotionMaster()->MovePoint(1, -8250.0f, me->GetPositionY(), me->GetPositionZ());
                start = true;
            }
            else _t -= diff;
        }

    private :
        bool start, goal;
        uint32 _t;
    };
};

class npc_chipie_quest_giver_end_event : public CreatureScript
{
public:
    npc_chipie_quest_giver_end_event() : CreatureScript("npc_chipie_quest_giver_end_event") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (Creature *t = player->SummonCreature(900000, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),
                                                     creature->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
            {
                if (Creature *c = player->SummonCreature(creature->GetEntry(), creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),
                                                         creature->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
                {
                    c->Say("Gimme keys chief, I drive!", LANG_UNIVERSAL, 0);
                    player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 2, t, false);
                    c->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
                    CAST_AI(npc_escortAI, (t->AI()))->Start(false, true, player->GetGUID());
                }
            }
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14126) != QUEST_STATUS_NONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Yes, I want to go there!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

};

class npc_hot_rod : public CreatureScript
{
public:
    npc_hot_rod() : CreatureScript("npc_hot_rod") { }

    struct npc_hot_rodAI : public npc_escortAI
    {
        npc_hot_rodAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}


        void Reset() override
        {
            me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
        }

        void WaypointReached(uint32 i) override
        {
            Creature *chipie = me->FindNearestCreature(34668, 5, true);
            if (!chipie)
                return;
            switch(i)
            {
            case 4:
                chipie->Say("Hold on! I'm going to drive fast!", LANG_UNIVERSAL, 0);
                break;
            case 16:
                chipie->Say("We must do the trick!", LANG_UNIVERSAL, 0);
                chipie->Say("Hold on! I'm going to drive fast!", LANG_UNIVERSAL, 0);
                break;
            case 17:
                chipie->Yell("Clear the way!", LANG_UNIVERSAL, 0);
                break;
            case 26:
                me->SetCanFly(true);
                me->SetSpeed(MOVE_FLIGHT, 3.0f);
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hot_rodAI (creature);
    }
};

#define NPC_HOT_ROD 900000
#define ACTION_A 1
#define ACTION_B 2
#define ACTION_C 3
#define ACTION_D 4
#define ACTION_E 5
#define ACTION_START 6
#define ACTION_FAIL 7
#define ACTION_SUCCESS 8

class npc_gl_gob : public CreatureScript
{
public:
    npc_gl_gob() : CreatureScript("npc_gl_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gl_gobAI(creature);
    }

    struct npc_gl_gobAI : public npc_escortAI
    {
        npc_gl_gobAI(Creature* creature) : npc_escortAI(creature), vehicle(creature->GetVehicleKit()) {}

        void Reset() override
        {
            m_ty = 100;
            st = false;
            me->SetSpeed(MOVE_WALK, 0.001f);
            me->SetSpeed(MOVE_RUN, 0.001f);
        }

        void JustReachedHome() override
        {

        }

        void WaypointReached(uint32) override
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (m_ty <= diff)
            {
                if (!st)
                {
                    if (me->ToTempSummon())
                        if (Unit *p = me->ToTempSummon()->GetSummoner())
                            if (p->ToPlayer())
                                p->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, me, false);
                    st = true;
                }
                else
                    me->DespawnOrUnsummon();
                m_ty = 3000;
            }
            else m_ty -= diff;
            npc_escortAI::UpdateAI(diff);
        }

    private :
        uint32 m_ty;
        Vehicle* vehicle;
        uint64 _prev_aura;
        uint64 _will_aura;
        bool st;
    };
};

class npc_gls_gob : public CreatureScript
{
public:
    npc_gls_gob() : CreatureScript("npc_gls_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gls_gobAI(creature);
    }

    struct npc_gls_gobAI : public ScriptedAI
    {
        npc_gls_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            _start_event = true;
            _diag = 0;
            mui_diag = 5000;
            _count = 0;
            _will_aura = ACTION_START;
            _scriptetre = true;
            if (me->ToTempSummon())
            {
                if (Unit *p = me->ToTempSummon()->GetSummoner())
                {
                    if (p->GetTypeId() != TYPEID_PLAYER)
                        _scriptetre = false;
                }
                else
                    _scriptetre = false;
            }
            else
                _scriptetre = false;
            if (!_scriptetre)
                return;
            m_ty = 600000;
            me->SetPhaseMask(2048, true);
        }

        void DoAction(const int32 param) override
        {
            if (!_scriptetre || _start_event)
                return;
            m_ty = 2000;
            _prev_aura = param;
            Player *player = NULL;
            if (Unit *p = me->ToTempSummon()->GetSummoner())
                if (player = p->ToPlayer())
                    if (param != ACTION_FAIL)
                        player->PlayDirectSound(11595, player);
            if (_prev_aura != _will_aura)
            {
                if (player)
                    Talk(11, player);
                _count -= 1;
            }
            else
            {
                int res = (_count * 100) / 30 + 4;
                if (res < 0)
                {
                    _count = 0;
                    res = 0;
                }
                if (player)
                    if (player->GetVehicle())
                        if (player->GetVehicle()->GetBase())
                            player->GetVehicle()->GetBase()->SetPower(POWER_ENERGY, res); //DON'T WORK !
                std::ostringstream oss;
                oss << res;
                std::string result = oss.str();
                std::string _mess = "Bravo !\n Progress : ";
                _mess += result;
                _mess += "/100";
                if (player)
                {
                    Talk(10, player);
                    me->Whisper(_mess.c_str(), LANG_UNIVERSAL, player, true);
                }
                _count++;
            }
            if (param == ACTION_B)
                me->CastSpell(me, 90709, true);
            if (_count == 30)
            {
                if (player)
                {
                    Talk(12, player);
                    player->AddItem(46858, 1);
                }
                me->DespawnOrUnsummon();
                return ;
            }
            _will_aura = urand(1, 5);
            int sc_text = _will_aura;
            if (player)
                Talk(sc_text, player);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
        }

        void JustReachedHome() override
        {

        }

        void WaypointReached(uint32)
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (!_scriptetre)
                return;
            if (_start_event)
            {
                if (mui_diag <= diff)
                {
                    Player *player = NULL;
                    if (Unit *p = me->ToTempSummon()->GetSummoner())
                        player = p->ToPlayer();
                    if (!player || player->GetVehicle() == NULL)
                        me->DespawnOrUnsummon();
                    switch (_diag)
                    {
                    case 0 :
                        if (player)
                            Talk(6, player);
                        ++_diag;
                        break;
                    case 1 :
                        if (player)
                            Talk(7, player);
                        ++_diag;
                        break;
                    case 2 :
                        if (player)
                            Talk(8, player);
                        ++_diag;
                        break;
                    case 3 :
                        if (player)
                            Talk(9, player);
                        ++_diag;
                        break;
                    default :
                        _start_event = false;
                        DoAction(ACTION_START);
                        break;
                    }
                    mui_diag = 10000;
                }
                else  mui_diag -= diff;
            }
            else
            {
                if (m_ty <= diff)
                {
                    m_ty = 600000;
                    DoAction(ACTION_FAIL);
                    if (_count < -4)
                        me->DespawnOrUnsummon();
                }
                else m_ty -= diff;
            }
        }

    private :
        uint32 m_ty;
        uint64 _prev_aura;
        uint64 _will_aura;
        int _count;
        bool _scriptetre;
        bool _start_event;
        uint32 mui_diag;
        int _diag;
    };
};

class spell_klaxon : public SpellScriptLoader
{
public:
    spell_klaxon() : SpellScriptLoader("spell_klaxon") { }


    class spell_klaxonSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_klaxonSpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }


        bool Load() override
        {
            return true;
        }

        void SummonPetAndValidQuest(uint32 spellEntry, Player *player, uint32 npcEntry, uint32 petEntry)
        {
            if (Creature *c = player->FindNearestCreature(npcEntry, 10))
            {
                c->DespawnOrUnsummon();
                player->CastSpell(player, spellEntry, true);
                player->KilledMonsterCredit(npcEntry);
            }
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Unit* owner = GetCaster()->GetOwner())
                if (Player* player = owner->ToPlayer())
                {
                    GetCaster()->PlayDirectSound(22491, player);
                    st = true;
                    SummonPetAndValidQuest(66597, player, 934957, 34957);
                    SummonPetAndValidQuest(66599, player, 934958, 34958);
                    SummonPetAndValidQuest(66600, player, 934959, 34959);
                }
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_klaxonSpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_klaxonSpellScript();
    }
};

#define RADIO 23406

class spell_radio : public SpellScriptLoader
{
public:
    spell_radio() : SpellScriptLoader("spell_radio") { }

    class  spell_radioSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_radioSpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void SendPacketToPlayers(WorldPacket const* data, Player *player) const
        {
            player->GetSession()->SendPacket(data);
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Unit* caster = GetCaster()->GetOwner())
            {
                if (caster->GetTypeId() == TYPEID_PLAYER)
                    GetCaster()->PlayDistanceSound(RADIO, caster->ToPlayer());
                st = true;
            }
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_radioSpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_radioSpellScript();
    }
};

class spell_bank_67495 : public SpellScriptLoader
{
public:
    spell_bank_67495() : SpellScriptLoader("spell_bank_67495") { }


    class  spell_bank_67495SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bank_67495SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Creature *t = GetCaster()->FindNearestCreature(850000, 5))
                t->GetAI()->DoAction(ACTION_A);
            st = true;
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_bank_67495SpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_bank_67495SpellScript();
    }
};

class spell_bank_67496 : public SpellScriptLoader
{
public:
    spell_bank_67496() : SpellScriptLoader("spell_bank_67496") { }


    class  spell_bank_67496SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bank_67496SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Creature *t = GetCaster()->FindNearestCreature(850000, 5))
                t->GetAI()->DoAction(ACTION_B);

            st = true;
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_bank_67496SpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_bank_67496SpellScript();
    }
};

class spell_bank_67497 : public SpellScriptLoader
{
public:
    spell_bank_67497() : SpellScriptLoader("spell_bank_67497") { }


    class  spell_bank_67497SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bank_67497SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Creature *t = GetCaster()->FindNearestCreature(850000, 5))
                t->GetAI()->DoAction(ACTION_C);
            st = true;
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_bank_67497SpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_bank_67497SpellScript();
    }
};

class spell_bank_67498 : public SpellScriptLoader
{
public:
    spell_bank_67498() : SpellScriptLoader("spell_bank_67498") { }

    class  spell_bank_67498SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bank_67498SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Creature *t = GetCaster()->FindNearestCreature(850000, 5))
                t->GetAI()->DoAction(ACTION_D);
            st = true;
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_bank_67498SpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_bank_67498SpellScript();
    }
};

class spell_bank_67499 : public SpellScriptLoader
{
public:
    spell_bank_67499() : SpellScriptLoader("spell_bank_67499") { }


    class  spell_bank_67499SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bank_67499SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (st)
                return;
            if (Creature *t = GetCaster()->FindNearestCreature(850000, 5))
                t->GetAI()->DoAction(ACTION_E);
            st = true;
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_bank_67499SpellScript::HandleOnHit);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_bank_67499SpellScript();
    }
};

#define SHARK_VEHICLE_ROUND_2 37213

class GobelinQuestEvent : public PlayerScript
{
public:
    GobelinQuestEvent() : PlayerScript("GobelinQuestEvent") { }

    void OnQuestComplete(Player* player, Quest const* quest)
    {
        switch (quest->GetQuestId())
        {
        case QUEST_BRUTALITY_NECESSARY:
        {
            if (Vehicle* veh = player->GetVehicle())
                if (Unit *unit = veh->GetBase())
                {
                    unit->ToCreature()->UpdateEntry(37213);
                    player->KilledMonsterCredit(37203, unit->GetGUID());
                    player->ExitVehicle();
                    player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, unit, false);
                    unit->ToCreature()->SetSpeed(MOVE_RUN, 0.001f);
                }
            break;
        }
        }
    }
};

class npc_fourth_and_goal_target : public CreatureScript
{
public:
    npc_fourth_and_goal_target() : CreatureScript("npc_fourth_and_goal_target") { }

    struct npc_fourth_and_goal_targetAI : public ScriptedAI
    {
        npc_fourth_and_goal_targetAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            activate = false;
            m_timerValidGoalEvent = 100;
        }

        void SetData(uint32 type, uint32 value) override
        {
            activate = true;
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!activate)
                return ;
            if (m_timerValidGoalEvent <= diff)
            {
                if (me->ToTempSummon())
                    if (Unit *owner = me->ToTempSummon()->GetSummoner())
                        if (Player *player = owner->ToPlayer())
                        {
                            if (Vehicle* veh = player->GetVehicle())
                                if (Unit *unit = veh->GetBase())
                                {
                                    player->SummonCreature(48572, -8178.59f, 1482.14f, 83.99894f, 3.106686f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS);
                                    unit->ToCreature()->DespawnOrUnsummon();
                                }
                            me->DespawnOrUnsummon(3000);
                            player->CastSpell(player, TREMBLEMENT_PERSO, true);
                        }
                m_timerValidGoalEvent = 3600;
            }
            else
                m_timerValidGoalEvent -= diff;
        }

    private:
        bool activate;
        uint32 m_timerValidGoalEvent;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fourth_and_goal_targetAI(creature);
    }
};

class npc_original_hot_rod : public CreatureScript
{
public:
    npc_original_hot_rod() : CreatureScript("npc_original_hot_rod") { }

    struct npc_original_hot_rodAI : public ScriptedAI
    {
        npc_original_hot_rodAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}


        void Reset() override
        {
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (apply)
                {
                    int cnt = 1;
                    Player *player = who->ToPlayer();
                    for (Unit::ControlList::iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                        if ((*itr)->GetTypeId() == TYPEID_UNIT && ((*itr)->GetEntry() == 34959 || (*itr)->GetEntry() == 34958 || (*itr)->GetEntry() == 34957))
                        {
                            cnt++;
                            (*itr)->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, cnt, me, false);
                        }
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_original_hot_rodAI (creature);
    }
};

class npc_friend_gob : public CreatureScript
{
public:
    npc_friend_gob() : CreatureScript("npc_friend_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_friend_gobAI(creature);
    }

    struct npc_friend_gobAI : public ScriptedAI
    {
        npc_friend_gobAI(Creature* creature) : ScriptedAI(creature) {}


        void Reset() override
        {
            entervh = true;
            delayedEnterVehicle = 1000;
        }

        void DoAction(int32 const /*param*/) override
        {
        }

        void JustReachedHome() override
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (!entervh)
                return;
            if (delayedEnterVehicle <= diff)
            {
                if (me->ToTempSummon())
                    if (me->ToTempSummon()->GetSummoner())
                        if (me->ToTempSummon()->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
                            if (Vehicle *veh = me->ToTempSummon()->GetSummoner()->GetVehicle())
                                if (Unit *unit = me->ToTempSummon()->GetSummoner()->GetVehicle()->GetBase())
                                {
                                    SeatMap::const_iterator seat = veh->GetNextEmptySeat(0, true);
                                    if (seat != veh->Seats.end())
                                        me->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, seat->first + 1, unit, false);
                                }
                delayedEnterVehicle = 3600000;
                entervh = false;
            }
            else
                delayedEnterVehicle -= diff;
        }

    private :
        bool entervh;
        uint32 delayedEnterVehicle;
    };
};

void AddSC_kezan()
{
    new npc_fourth_and_goal_target();
    new npc_defiant_troll();
    new npc_bling_bling();
    new npc_bambo();
    new gob_bank_gobelin();
    new spell_kabummbomb();
    new npc_shark_gob();
    new npc_boucanier_gob();
    new npc_citoyen_gob();
    new gob_canon_gobelin();
    new npc_robot_gob();
    new gob_control_gobelin();
    new npc_galaw();
    new npc_sumkaja_gob();
    new npc_meteor_gob();
    new npc_gw();
    new npc_hot_rod();
    new npc_gl_gob();
    new spell_klaxon();
    new spell_radio();
    new spell_bank_67495();
    new spell_bank_67496();
    new spell_bank_67497();
    new spell_bank_67498();
    new spell_bank_67499();
    new npc_gls_gob();
    new GobelinQuestEvent();
    new npc_original_hot_rod();
    new npc_friend_gob();
    new npc_chipie_quest_giver_end_event();
}
