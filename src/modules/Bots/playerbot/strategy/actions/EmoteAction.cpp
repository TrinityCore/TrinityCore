#include "botpch.h"
#include "../../playerbot.h"
#include "EmoteAction.h"

#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
using namespace ai;

map<string, uint32> EmoteActionBase::emotes;
map<string, uint32> EmoteActionBase::textEmotes;

EmoteActionBase::EmoteActionBase(PlayerbotAI* ai, string name) : Action(ai, name)
{
    if (emotes.empty()) InitEmotes();
}

EmoteAction::EmoteAction(PlayerbotAI* ai) : EmoteActionBase(ai, "emote"), Qualified()
{
}

void EmoteActionBase::InitEmotes()
{
    emotes["dance"] = EMOTE_ONESHOT_DANCE;
    emotes["drown"] = EMOTE_ONESHOT_DROWN;
    emotes["land"] = EMOTE_ONESHOT_LAND;
    emotes["liftoff"] = EMOTE_ONESHOT_LIFTOFF;
    emotes["loot"] = EMOTE_ONESHOT_LOOT;
    emotes["no"] = EMOTE_ONESHOT_NO;
    emotes["roar"] = EMOTE_STATE_ROAR;
    emotes["salute"] = EMOTE_ONESHOT_SALUTE;
    emotes["stomp"] = EMOTE_ONESHOT_STOMP;
    emotes["train"] = EMOTE_ONESHOT_TRAIN;
    emotes["yes"] = EMOTE_ONESHOT_YES;
    emotes["applaud"] = EMOTE_ONESHOT_APPLAUD;
    emotes["beg"] = EMOTE_ONESHOT_BEG;
    emotes["bow"] = EMOTE_ONESHOT_BOW;
    emotes["cheer"] = EMOTE_ONESHOT_CHEER;
    emotes["chicken"] = EMOTE_ONESHOT_CHICKEN;
    emotes["cry"] = EMOTE_ONESHOT_CRY;
    emotes["dance"] = EMOTE_STATE_DANCE;
    emotes["eat"] = EMOTE_ONESHOT_EAT;
    emotes["exclamation"] = EMOTE_ONESHOT_EXCLAMATION;
    emotes["flex"] = EMOTE_ONESHOT_FLEX;
    emotes["kick"] = EMOTE_ONESHOT_KICK;
    emotes["kiss"] = EMOTE_ONESHOT_KISS;
    emotes["kneel"] = EMOTE_ONESHOT_KNEEL;
    emotes["laugh"] = EMOTE_ONESHOT_LAUGH;
    emotes["point"] = EMOTE_ONESHOT_POINT;
    emotes["question"] = EMOTE_ONESHOT_QUESTION;
    emotes["ready1h"] = EMOTE_ONESHOT_READY1H;
    emotes["roar"] = EMOTE_ONESHOT_ROAR;
    emotes["rude"] = EMOTE_ONESHOT_RUDE;
    emotes["shout"] = EMOTE_ONESHOT_SHOUT;
    emotes["shy"] = EMOTE_ONESHOT_SHY;
    emotes["sleep"] = EMOTE_STATE_SLEEP;
    emotes["talk"] = EMOTE_ONESHOT_TALK;
    emotes["wave"] = EMOTE_ONESHOT_WAVE;
    emotes["wound"] = EMOTE_ONESHOT_WOUND;

    textEmotes["bored"] = TEXTEMOTE_BORED;
    textEmotes["bye"] = TEXTEMOTE_BYE;
    textEmotes["cheer"] = TEXTEMOTE_CHEER;
    textEmotes["congratulate"] = TEXTEMOTE_CONGRATULATE;
    textEmotes["hello"] = TEXTEMOTE_HELLO;
    textEmotes["no"] = TEXTEMOTE_NO;
    textEmotes["nod"] = TEXTEMOTE_NOD; // yes
    textEmotes["sigh"] = TEXTEMOTE_SIGH;
    textEmotes["thank"] = TEXTEMOTE_THANK;
    textEmotes["welcome"] = TEXTEMOTE_WELCOME; // you are welcome
    textEmotes["whistle"] = TEXTEMOTE_WHISTLE;
    textEmotes["yawn"] = TEXTEMOTE_YAWN;
    textEmotes["oom"] = 323;
    textEmotes["follow"] = 324;
    textEmotes["wait"] = 325;
    textEmotes["healme"] = 326;
    textEmotes["openfire"] = 327;
    textEmotes["helpme"] = 303;
    textEmotes["flee"] = 306;
    textEmotes["danger"] = 304;
    textEmotes["charge"] = 305;
    textEmotes["help"] = 307;
    textEmotes["train"] = 264;
}

bool EmoteActionBase::Emote(Unit* target, uint32 type)
{
    if (sServerFacade.isMoving(bot)) return false;

    if (target && !sServerFacade.IsInFront(bot, target, sPlayerbotAIConfig.sightDistance, EMOTE_ANGLE_IN_FRONT))
        sServerFacade.SetFacingTo(bot, target);

    ObjectGuid oldSelection = bot->GetSelectionGuid();
    if (target)
    {
        bot->SetSelectionGuid(target->GetObjectGuid());
        Player* player = dynamic_cast<Player*>(target);
        if (player && player->GetPlayerbotAI() && !sServerFacade.IsInFront(player, bot, sPlayerbotAIConfig.sightDistance, EMOTE_ANGLE_IN_FRONT))
            sServerFacade.SetFacingTo(player, bot);
    }

    bot->HandleEmoteCommand(type);

    if (oldSelection)
        bot->SetSelectionGuid(oldSelection);

    return true;
}

Unit* EmoteActionBase::GetTarget()
{
    Unit* target = NULL;

    list<ObjectGuid> nfp = *context->GetValue<list<ObjectGuid> >("nearest friendly players");
    vector<Unit*> targets;
    for (list<ObjectGuid>::iterator i = nfp.begin(); i != nfp.end(); ++i)
    {
        Unit* unit = ai->GetUnit(*i);
        if (unit && sServerFacade.GetDistance2d(bot, unit) < sPlayerbotAIConfig.tooCloseDistance) targets.push_back(unit);
    }

    if (!targets.empty())
        target = targets[urand(0, targets.size() - 1)];

    return target;
}


bool EmoteAction::Execute(Event event)
{
    uint32 emote = 0;

    string param = event.getParam();
    if (param.empty())
    {
        time_t lastEmote = AI_VALUE2(time_t, "last emote", qualifier);
        ai->GetAiObjectContext()->GetValue<time_t>("last emote", qualifier)->Set(time(0) + urand(1000, sPlayerbotAIConfig.repeatDelay) / 1000);
        param = qualifier;
    }

    if (param.find("sound") == 0)
    {
        return ai->PlaySound(atoi(param.substr(5).c_str()));
    }

    if (!param.empty() && textEmotes.find(param) != textEmotes.end())
    {
        return ai->PlaySound(textEmotes[param]);
    }

    if (param.empty() || emotes.find(param) == emotes.end())
    {
        int index = rand() % emotes.size();
        for (map<string, uint32>::iterator i = emotes.begin(); i != emotes.end() && index; ++i, --index)
            emote = i->second;
    }
    else
    {
        emote = emotes[param];
    }

    if (param.find("text") == 0)
    {
        emote = atoi(param.substr(4).c_str());
    }

    return Emote(GetTarget(), emote);
}

bool EmoteAction::isUseful()
{
    time_t lastEmote = AI_VALUE2(time_t, "last emote", qualifier);
    return (time(0) - lastEmote) >= sPlayerbotAIConfig.repeatDelay / 1000;
}


bool TalkAction::Execute(Event event)
{
    Unit* target = ai->GetUnit(AI_VALUE(ObjectGuid, "talk target"));
    if (!target)
        target = GetTarget();

    if (!urand(0, 100))
    {
        target = NULL;
        context->GetValue<ObjectGuid>("talk target")->Set(ObjectGuid());
        return true;
    }

    if (target)
    {
        Player* player = dynamic_cast<Player*>(target);
        if (player && player->GetPlayerbotAI())
            player->GetPlayerbotAI()->GetAiObjectContext()->GetValue<ObjectGuid>("talk target")->Set(bot->GetObjectGuid());

        context->GetValue<ObjectGuid>("talk target")->Set(target->GetObjectGuid());
        return Emote(target, GetRandomEmote(target));
    }

    return false;
}

uint32 TalkAction::GetRandomEmote(Unit* unit)
{
    vector<uint32> types;
    if (!urand(0, 20))
    {
        // expressions
        types.push_back(EMOTE_ONESHOT_BOW);
        types.push_back(EMOTE_ONESHOT_RUDE);
        types.push_back(EMOTE_ONESHOT_CRY);
        types.push_back(EMOTE_ONESHOT_LAUGH);
        types.push_back(EMOTE_ONESHOT_POINT);
        types.push_back(EMOTE_ONESHOT_CHEER);
        types.push_back(EMOTE_ONESHOT_SHY);
    }
    else
    {
        // talk
        types.push_back(EMOTE_ONESHOT_TALK);
        types.push_back(EMOTE_ONESHOT_EXCLAMATION);
        types.push_back(EMOTE_ONESHOT_QUESTION);
        if (unit && (unit->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TRAINER) || unit->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER)))
        {
            types.push_back(EMOTE_ONESHOT_SALUTE);
        }
    }
    return types[urand(0, types.size() - 1)];
}
