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

#include "Containers.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum ReallyBigProblemData
{
    NPC_SUMMONED_THORNGUARD_IRONCLAW    = 140049,

    CONVO_ACTOR_THORNGUARD_IRONCLAW     = 65120,

    SPELL_DISMISS_TRADEWIND             = 274789
};

// 8790 - Conversation
class conversation_drustvar_really_big_problem_complete : public ConversationAI
{
public:
    conversation_drustvar_really_big_problem_complete(Conversation* conversation) : ConversationAI(conversation) {}

    void OnCreate(Unit* creator) override
    {
        Creature* thornguardIronclaw = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_THORNGUARD_IRONCLAW, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!thornguardIronclaw)
            return;

        thornguardIronclaw->SetReactState(REACT_PASSIVE);
        thornguardIronclaw->SetImmuneToAll(true);

        conversation->AddActor(CONVO_ACTOR_THORNGUARD_IRONCLAW, 0, thornguardIronclaw->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Creature* thornguardIronclaw = conversation->GetActorCreature(0);
            if (!thornguardIronclaw)
                return;

            thornguardIronclaw->GetMotionMaster()->MovePoint(0, thornguardIronclaw->GetFirstCollisionPosition(20.0f, 0));
            thornguardIronclaw->CastSpell(thornguardIronclaw, SPELL_DISMISS_TRADEWIND, TRIGGERED_IGNORE_CAST_TIME);
        }, conversation->GetLastLineEndTime(privateOwnerLocale) + 3s);
    }
};

// 274789 - Dismiss Tradewind
class spell_drustvar_dismiss_tradewind : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* hitUnit = GetHitCreature())
        {
            if (hitUnit->GetEntry() == NPC_SUMMONED_THORNGUARD_IRONCLAW)
                hitUnit->DespawnOrUnsummon(2s);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_dismiss_tradewind::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_zone_drustvar()
{
    // Conversation
    RegisterConversationAI(conversation_drustvar_really_big_problem_complete);

    // Spells
    RegisterSpellScript(spell_drustvar_dismiss_tradewind);
}
