#include "ScriptedCreature.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "SceneHelper.h"
#include "MotionMaster.h"

void SceneActionTalk::DoAction()
{
    if (Creature* actor = GetActor())
    {
        actor->AI()->Talk(talkIndex);
    }
}

void SceneActionWhisper::DoAction()
{
    if (Creature* actor = GetActor())
    {
        if (Player* player = ObjectAccessor::GetPlayer(*actor, whisperGuid))
            actor->AI()->Talk(talkIndex, player);
    }
}

void SceneActionSummon::DoAction()
{
    if (!GetActor())
        return;

    if (Map* map = GetActionMap())
    {
        map->SummonCreature(summonEntry, summonPosition);
    }
}

void SceneActionCast::DoAction()
{
    if (Creature* actor = GetActor())
    {
        actor->CastSpell(actor, spellEntry);
    }
}

void SceneActionAI::DoAction()
{
    if (Creature* actor = GetActor())
    {
        actor->AI()->DoAction(actionId);
    }
}

void SceneActionMovePos::DoAction()
{
    if (Creature* actor = GetActor())
    {
        actor->GetMotionMaster()->MovePoint(0, position);
    }
}

void SceneActionMovePath::DoAction()
{
    if (Creature* actor = GetActor())
    {
        actor->GetMotionMaster()->MovePath(pathId, false);
    }
}

void SceneActionCastTarget::DoAction()
{
    if (Creature* actor = GetActor())
    {
        if (target)
            actor->CastSpell(target, spellEntry, triggered);
    }
}

void SceneActionForceCast::DoAction()
{
    if (caster)
    {
        if (target)
            caster->CastSpell(target, spellEntry, triggered);
    }
}

void SceneActionKillCreditMonster::DoAction()
{
    if (Creature* actor = GetActor())
    {
        if (target)
        {
            if (Player* player = target->ToPlayer())
            {
                for (int i = 0; i < int(amount); i++)
                {
                    player->KilledMonsterCredit(creditEntry);
                }
            }
        }
    }
}

void SceneActionEmote::DoAction()
{
    if (Creature* actor = GetActor())
    {
        
    }
}

void SceneActionDespawn::DoAction()
{
    if (Creature* actor = GetActor())
    {
        
    }
}

void SceneActionFace::DoAction()
{
    if (Creature* actor = GetActor())
    {
        if (target)
            actor->SetFacingToObject(target);
    }
}
