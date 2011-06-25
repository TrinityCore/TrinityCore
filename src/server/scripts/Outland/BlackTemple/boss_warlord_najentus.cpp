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

/* ScriptData
SDName: Boss_Warlord_Najentus
SD%Complete: 95
SDComment:
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"

#define SAY_AGGRO                       -1564000
#define SAY_NEEDLE1                     -1564001
#define SAY_NEEDLE2                     -1564002
#define SAY_SLAY1                       -1564003
#define SAY_SLAY2                       -1564004
#define SAY_SPECIAL1                    -1564005
#define SAY_SPECIAL2                    -1564006
#define SAY_ENRAGE1                     -1564007            //is this text actually in use?
#define SAY_ENRAGE2                     -1564008
#define SAY_DEATH                       -1564009

//Spells
#define SPELL_NEEDLE_SPINE              39992
#define SPELL_NEEDLE_SPINE_DMG          39835
#define SPELL_NEEDLE_SPINE_AOE          39968
#define SPELL_TIDAL_BURST               39878
#define SPELL_TIDAL_SHIELD              39872
#define SPELL_IMPALING_SPINE            39837
#define SPELL_CREATE_NAJENTUS_SPINE     39956
#define SPELL_HURL_SPINE                39948
#define SPELL_BERSERK                   45078

#define GOBJECT_SPINE                  185584

class boss_najentus : public CreatureScript
{
public:
    boss_najentus() : CreatureScript("boss_najentus") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_najentusAI (_Creature);
    }

    struct boss_najentusAI : public ScriptedAI
    {
        boss_najentusAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 NeedleSpineTimer;
        uint32 EnrageTimer;
        uint32 SpecialYellTimer;
        uint32 TidalShieldTimer;
        uint32 ImpalingSpineTimer;

        uint64 SpineTargetGUID;

        uint32 pulse_Timer;

        void Reset()
        {
            EnrageTimer = 480000;
            SpecialYellTimer = 45000 + (rand()%76)*1000;
            TidalShieldTimer = 60000;

            ResetTimer();
            pulse_Timer = 10000;

            SpineTargetGUID = 0;

            if(pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, NOT_STARTED);

            DeleteSpine();
        }

        void KilledUnit(Unit *victim)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_SLAY1, me); break;
            case 1: DoScriptText(SAY_SLAY2, me); break;
            }
        }

        void JustDied(Unit *victim)
        {
            if(pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, DONE);

            DoScriptText(SAY_DEATH, me);
            DeleteSpine();
        }

        bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
        {
            if(me->IsNonMeleeSpellCasted(false)) return false;

            DoCast(victim,spellId,triggered);
            return true;
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if(spell->Id == SPELL_HURL_SPINE && me->HasAura(SPELL_TIDAL_SHIELD, 0))
            {
                me->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
                me->CastSpell(me, SPELL_TIDAL_BURST, true);
                ResetTimer();
            }
        }

        void SpellHitTarget(Unit *target, const SpellEntry *spell)
        {
            switch(spell->Id)
            {
            case SPELL_NEEDLE_SPINE:
                me->CastSpell(target,SPELL_NEEDLE_SPINE_DMG,true);
                break;
            }
        }

        void EnterCombat(Unit *who)
        {
            if(pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, IN_PROGRESS);

            DoScriptText(SAY_AGGRO, me);
            DoZoneInCombat();
        }

        bool RemoveImpalingSpine()
        {
            if(!SpineTargetGUID) return false;
            Unit* target = Unit::GetUnit(*me, SpineTargetGUID);
            if(target && target->HasAura(SPELL_IMPALING_SPINE, 1))
                target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
            SpineTargetGUID=0;
            return true;
        }

        void ResetTimer(uint32 inc = 0)
        {
            NeedleSpineTimer = 10000 + inc;
            ImpalingSpineTimer = 20000 + inc;
        }

        //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
        //{
        //    if (!attacker)
        //        attacker = me;

        //    if (!pUnit)
        //        pUnit = me;

        //    Map *map = pUnit->GetMap();

        //    if (!map->IsDungeon())
        //        return;

        //    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
        //        return;

        //    Map::PlayerList const &PlayerList = map->GetPlayers();
        //    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        //    {
        //        if (Player* i_pl = i->getSource())
        //            if (i_pl->isAlive() && attacker->GetDistance(i_pl) <= range )
        //            {
        //                pUnit->SetInCombatWith(i_pl);
        //                i_pl->SetInCombatWith(pUnit);
        //                pUnit->AddThreat(i_pl, 0.0f);
        //            }
        //    }
        //}

        void DeleteSpine()
        {
            InstanceMap::PlayerList const &playerliste = ((InstanceMap*)me->GetMap())->GetPlayers();
            InstanceMap::PlayerList::const_iterator it;

            Map::PlayerList const &PlayerList = ((InstanceMap*)me->GetMap())->GetPlayers();
            for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                Player* i_pl = i->getSource();
                if(i_pl)
                    i_pl->DestroyItemCount(32408, i_pl->GetItemCount(32408), true);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if(pulse_Timer < diff)
            {
                DoAttackerAreaInCombat(me->getVictim(),50);
                pulse_Timer = 10000;
            }else pulse_Timer -= diff;

            if(TidalShieldTimer < diff)
            {
                if(TryDoCast(me, SPELL_TIDAL_SHIELD, true))
                {
                    ResetTimer(45000);
                    TidalShieldTimer = 60000;
                }
            }else TidalShieldTimer -= diff;

            if(!me->HasAura(SPELL_BERSERK,0))
            {
                if(EnrageTimer < diff)
                {
                    DoScriptText(SAY_ENRAGE2, me);
                    DoCast(me, SPELL_BERSERK, true);
                }else EnrageTimer -= diff;
            }

            if(SpecialYellTimer < diff)
            {
                switch(rand()%2)
                {
                case 0: DoScriptText(SAY_SPECIAL1, me); break;
                case 1: DoScriptText(SAY_SPECIAL2, me); break;
                }
                SpecialYellTimer = 25000 + (rand()%76)*1000;
            }else SpecialYellTimer -= diff;

            if(ImpalingSpineTimer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 80,true);
                    if(!target) target = me->getVictim();
                    if(target)
                    {
                        DoCast(target, SPELL_IMPALING_SPINE);
                        SpineTargetGUID = target->GetGUID();
                        //must let target summon, otherwise you cannot click the spine
                        target->SummonGameObject(GOBJECT_SPINE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, 0);

                        switch(rand()%2)
                        {
                        case 0: DoScriptText(SAY_NEEDLE1, me); break;
                        case 1: DoScriptText(SAY_NEEDLE2, me); break;
                        }
                        ImpalingSpineTimer = 21000;
                    }
                }
            }else ImpalingSpineTimer -= diff;

            if(NeedleSpineTimer < diff)
            {
                if(TryDoCast(me, SPELL_NEEDLE_SPINE, true))
                {
                    //std::list<Unit*> target;
                    //SelectTargetList(target, 3, SELECT_TARGET_RANDOM, 100, true);
                    //for(std::list<Unit*>::iterator i = target.begin(); i != target.end(); ++i)
                    //    me->CastSpell(*i, 39835, true);
                    NeedleSpineTimer = 3000;
                }
            }else NeedleSpineTimer -= diff;


            DoMeleeAttackIfReady();
        }
    };
};

class go_najentus_spine : public GameObjectScript
{
public:
    go_najentus_spine() : GameObjectScript("go_najentus_spine") { }

    bool OnGossipHello (Player *player, GameObject* _GO)
    {
        if(InstanceScript* pInstance = _GO->GetInstanceScript())
            if(Creature* Najentus = Unit::GetCreature(*_GO, pInstance->GetData64(DATA_HIGHWARLORDNAJENTUS)))
                if(CAST_AI(boss_najentus::boss_najentusAI,Najentus->AI())->RemoveImpalingSpine())
                {
                    player->CastSpell(player, SPELL_CREATE_NAJENTUS_SPINE, true);
                    //_GO->SetLootState(GO_NOT_READY);
                    //_GO->SetRespawnTime(0);
                    _GO->AddObjectToRemoveList();
                }
        return true;
    }
};

void AddSC_boss_najentus()
{
    new boss_najentus();
    new go_najentus_spine();
}

