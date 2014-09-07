#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "EmoteAction.h"

using namespace ai;

map<string, uint32> EmoteAction::emotes;

bool EmoteAction::Execute(Event event)
{
    if (emotes.empty())
        InitEmotes();

    uint32 emote = 0;

    string param = event.getParam();
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

	bot->CastStop();
	ai->InterruptSpell();
	bot->SetStandState(UNIT_STAND_STATE_STAND);

    Player* master = GetMaster();
	if (master)
	{
        Unit* masterSelection = master->GetSelectedUnit();
        if (masterSelection)
        {
            Unit* oldSelection = bot->GetSelectedUnit();
            bot->SetSelection(masterSelection->GetGUID());
            bot->HandleEmoteCommand(emote);
            if (oldSelection)
                bot->SetSelection(oldSelection->GetGUID());
            return true;
        }
	}

    bot->HandleEmoteCommand(emote);
    return true;
}

void EmoteAction::InitEmotes()
{
    emotes["cower"] = EMOTE_ONESHOT_COWER;
    emotes["dance"] = EMOTE_ONESHOT_DANCE;
    emotes["drown"] = EMOTE_ONESHOT_DROWN;
    emotes["emerge"] = EMOTE_ONESHOT_EMERGE;
    emotes["land"] = EMOTE_ONESHOT_LAND;
    emotes["laugh_nosheathe"] = EMOTE_ONESHOT_LAUGH_NO_SHEATHE;
    emotes["liftoff"] = EMOTE_ONESHOT_LIFTOFF;
    emotes["loot"] = EMOTE_ONESHOT_LOOT;
    emotes["no"] = EMOTE_ONESHOT_NO;
    emotes["one_shot_stun"] = EMOTE_ONESHOT_STUN;
    emotes["point_nosheathe"] = EMOTE_ONESHOT_POINT_NO_SHEATHE;
    emotes["roar"] = EMOTE_STATE_ROAR;
    emotes["salute"] = EMOTE_ONESHOT_SALUTE;
    emotes["stomp"] = EMOTE_ONESHOT_STOMP;
    emotes["train"] = EMOTE_ONESHOT_TRAIN;
    emotes["yes"] = EMOTE_ONESHOT_YES;
    emotes["applaud"] = EMOTE_ONESHOT_APPLAUD;
    emotes["battleroar"] = EMOTE_ONESHOT_BATTLE_ROAR;
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
    emotes["parryshield"] = EMOTE_ONESHOT_PARRY_SHIELD;
    emotes["parryunarmed"] = EMOTE_ONESHOT_PARRY_UNARMED;
    emotes["point"] = EMOTE_ONESHOT_POINT;
    emotes["question"] = EMOTE_ONESHOT_QUESTION;
    emotes["ready1h"] = EMOTE_ONESHOT_READY1H;
    emotes["readybow"] = EMOTE_ONESHOT_READY_BOW;
    emotes["readyunarmed"] = EMOTE_ONESHOT_READY_UNARMED;
    emotes["roar"] = EMOTE_ONESHOT_ROAR;
    emotes["rude"] = EMOTE_ONESHOT_RUDE;
    emotes["shout"] = EMOTE_ONESHOT_SHOUT;
    emotes["shy"] = EMOTE_ONESHOT_SHY;
    emotes["sleep"] = EMOTE_STATE_SLEEP;
    emotes["talk"] = EMOTE_ONESHOT_TALK;
    emotes["wave"] = EMOTE_ONESHOT_WAVE;
    emotes["woundcritical"] = EMOTE_ONESHOT_WOUND_CRITICAL;
    emotes["wound"] = EMOTE_ONESHOT_WOUND;
}
