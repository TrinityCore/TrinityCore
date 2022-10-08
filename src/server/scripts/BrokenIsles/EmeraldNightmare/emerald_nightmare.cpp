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

#include "emerald_nightmare.h"

enum Says
{
    //SAY_1           = ,
};

enum Spells
{
    //SPELL_    = ,
    //SPELL_    = ,
    //SPELL_    = ,
    //SPELL_    = ,
};

enum eEvents
{
    //EVENT_    = 1,
    //EVENT_    = 2,
    //EVENT_    = 3,
    //EVENT_    = 4,
};

class spell_vantus_rune_the_emerald_nightmare : public SpellScriptLoader
{
public:
    spell_vantus_rune_the_emerald_nightmare() : SpellScriptLoader("spell_vantus_rune_the_emerald_nightmare") {}

    class spell_vantus_rune_the_emerald_nightmare_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vantus_rune_the_emerald_nightmare_AuraScript);

        uint16 checkOnProc;
        uint16 checkOnRemove;

        bool Load()
        {
            checkOnProc = 1000;
            checkOnRemove = 1000;
            return true;
        }

        void OnUpdate(uint32 diff, AuraEffect* aurEff)
        {
            Unit* player = GetCaster();
            if (!player)
                return;

            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return;

            if (checkOnProc <= diff)
            {
                switch (GetSpellInfo()->Id)
                {
                case 192761:
                    if (instance->GetBossState(DATA_NYTHENDRA) == IN_PROGRESS && !player->HasAura(208844))
                        player->CastSpell(player, 208844, false);
                    break;
                case 192765:
                    if (instance->GetBossState(DATA_RENFERAL) == IN_PROGRESS && !player->HasAura(208848))
                        player->CastSpell(player, 208848, false);
                    break;
                case 192762:
                    if (instance->GetBossState(DATA_ILGYNOTH) == IN_PROGRESS && !player->HasAura(208845))
                        player->CastSpell(player, 208852, false);
                    break;
                case 191464:
                    if (instance->GetBossState(DATA_URSOC) == IN_PROGRESS && !player->HasAura(208843))
                        player->CastSpell(player, 208843, false);
                    break;
                case 191463:
                    if (instance->GetBossState(DATA_DRAGON_NIGHTMARE) == IN_PROGRESS && !player->HasAura(208846))
                        player->CastSpell(player, 208846, false);
                    break;
                case 192766:
                    if (instance->GetBossState(DATA_CENARIUS) == IN_PROGRESS && !player->HasAura(208849))
                        player->CastSpell(player, 208849, false);
                    break;
                case 192764:
                    if (instance->GetBossState(DATA_XAVIUS) == IN_PROGRESS && !player->HasAura(208847))
                        player->CastSpell(player, 208847, false);
                    break;
                }
            }
            else
                checkOnProc -= diff;

            if (checkOnRemove <= diff)
            {
                if (player->HasAura(208844))
                {
                    if (instance->GetBossState(DATA_NYTHENDRA) == DONE || instance->GetBossState(DATA_NYTHENDRA) == NOT_STARTED)
                    {
                        player->RemoveAura(208844);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208848))
                {
                    if (instance->GetBossState(DATA_RENFERAL) == DONE || instance->GetBossState(DATA_RENFERAL) == NOT_STARTED)
                    {
                        player->RemoveAura(208848);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208846))
                {
                    if (instance->GetBossState(DATA_ILGYNOTH) == DONE || instance->GetBossState(DATA_ILGYNOTH) == NOT_STARTED)
                    {
                        player->RemoveAura(208846);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208843))
                {
                    if (instance->GetBossState(DATA_URSOC) == DONE || instance->GetBossState(DATA_URSOC) == NOT_STARTED)
                    {
                        player->RemoveAura(208843);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208856))
                {
                    if (instance->GetBossState(DATA_DRAGON_NIGHTMARE) == DONE || instance->GetBossState(DATA_DRAGON_NIGHTMARE) == NOT_STARTED)
                    {
                        player->RemoveAura(208856);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208849))
                {
                    if (instance->GetBossState(DATA_CENARIUS) == DONE || instance->GetBossState(DATA_CENARIUS) == NOT_STARTED)
                    {
                        player->RemoveAura(208849);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }

                if (player->HasAura(208847))
                {
                    if (instance->GetBossState(DATA_XAVIUS) == DONE || instance->GetBossState(DATA_XAVIUS) == NOT_STARTED)
                    {
                        player->RemoveAura(208847);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
            }
            else
                checkOnRemove -= diff;
        }

        void Register() override
        {
         //   OnEffectUpdate += AuraEffectUpdateFn(spell_vantus_rune_the_emerald_nightmare_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vantus_rune_the_emerald_nightmare_AuraScript();
    }

    class spell_vantus_rune_the_emerald_nightmare_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vantus_rune_the_emerald_nightmare_SpellScript);

        SpellCastResult CheckCast()
        {
            if (auto player = GetCaster()->ToPlayer())
                if (!player->GetQuestRewardStatus(39695))
                    return SPELL_CAST_OK;

            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_VANTUS_RUNE);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        void HandleOnHit()
        {
            if (auto player = GetCaster()->ToPlayer())
              //  if (Quest const* quest = sQuestDataStore->GetQuestTemplate(39695))
                   // if (player->CanTakeQuest(quest, false))
                        player->CompleteQuest(39695);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_vantus_rune_the_emerald_nightmare_SpellScript::CheckCast);
            OnHit += SpellHitFn(spell_vantus_rune_the_emerald_nightmare_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vantus_rune_the_emerald_nightmare_SpellScript();
    }
};
/*
//1000
class eventobject_en_into : public EventObjectScript
{
public:
    eventobject_en_into() : EventObjectScript("eventobject_en_into") {}

    bool event_elerethe_Done = false;

    bool OnTrigger(Player* plr, EventObject* eo, bool enter) override
    {
        if (!enter)
            return true;

        InstanceScript* instance = plr->GetInstanceScript();
        if (!instance)
            return false;

        switch (eo->GetEntry())
        {
        case 1000:
        {
            if (!event_elerethe_Done)
            {
                event_elerethe_Done = true;
                plr->CreateConversation(3626);
                plr->AddDelayedEvent(6000, [plr]() -> void
                {
                    plr->CreateConversation(3635);
                });
            }
            break;
        }
        }
        return true;
    }
};
*/
void AddSC_emerald_nightmare()
{
    new spell_vantus_rune_the_emerald_nightmare();
   // new (eventobject_en_into);
}
