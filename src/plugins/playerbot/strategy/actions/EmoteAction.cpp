#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "EmoteAction.h"

using namespace ai;

map<string, uint32> EmoteAction::emotes;
map<string, uint32> EmoteAction::textEmotes;

bool EmoteAction::Execute(Event event)
{
    if (emotes.empty())
        InitEmotes();

    uint32 emote = 0;

    time_t lastEmote = AI_VALUE2(time_t, "last emote", qualifier);
    ai->GetAiObjectContext()->GetValue<time_t>("last emote", qualifier)->Set(time(0) + urand(1, 60));

    string param = event.getParam();
    if (param.empty()) param = qualifier;

    if (!param.empty() && textEmotes.find(param) != emotes.end())
    {
        return ai->PlaySound(textEmotes[param]);
    }
    else if (param.empty() || emotes.find(param) == emotes.end())
    {
        int index = rand() % emotes.size();
		for (map<string, uint32>::iterator i = emotes.begin(); i != emotes.end() && index; ++i, --index)
			emote = i->second;
    }
    else
    {
        emote = emotes[param];
    }

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

    textEmotes["agree"] = TEXT_EMOTE_AGREE;
    textEmotes["amaze"] = TEXT_EMOTE_AMAZE;
    textEmotes["angry"] = TEXT_EMOTE_ANGRY;
    textEmotes["apologize"] = TEXT_EMOTE_APOLOGIZE;
    textEmotes["applaud"] = TEXT_EMOTE_APPLAUD;
    textEmotes["bashful"] = TEXT_EMOTE_BASHFUL;
    textEmotes["beckon"] = TEXT_EMOTE_BECKON;
    textEmotes["beg"] = TEXT_EMOTE_BEG;
    textEmotes["bite"] = TEXT_EMOTE_BITE;
    textEmotes["bleed"] = TEXT_EMOTE_BLEED;
    textEmotes["blink"] = TEXT_EMOTE_BLINK;
    textEmotes["blush"] = TEXT_EMOTE_BLUSH;
    textEmotes["bonk"] = TEXT_EMOTE_BONK;
    textEmotes["bored"] = TEXT_EMOTE_BORED;
    textEmotes["bounce"] = TEXT_EMOTE_BOUNCE;
    textEmotes["brb"] = TEXT_EMOTE_BRB;
    textEmotes["bow"] = TEXT_EMOTE_BOW;
    textEmotes["burp"] = TEXT_EMOTE_BURP;
    textEmotes["bye"] = TEXT_EMOTE_BYE;
    textEmotes["cackle"] = TEXT_EMOTE_CACKLE;
    textEmotes["cheer"] = TEXT_EMOTE_CHEER;
    textEmotes["chicken"] = TEXT_EMOTE_CHICKEN;
    textEmotes["chuckle"] = TEXT_EMOTE_CHUCKLE;
    textEmotes["clap"] = TEXT_EMOTE_CLAP;
    textEmotes["confused"] = TEXT_EMOTE_CONFUSED;
    textEmotes["congratulate"] = TEXT_EMOTE_CONGRATULATE;
    textEmotes["cough"] = TEXT_EMOTE_COUGH;
    textEmotes["cower"] = TEXT_EMOTE_COWER;
    textEmotes["crack"] = TEXT_EMOTE_CRACK;
    textEmotes["cringe"] = TEXT_EMOTE_CRINGE;
    textEmotes["cry"] = TEXT_EMOTE_CRY;
    textEmotes["curious"] = TEXT_EMOTE_CURIOUS;
    textEmotes["curtsey"] = TEXT_EMOTE_CURTSEY;
    textEmotes["dance"] = TEXT_EMOTE_DANCE;
    textEmotes["drink"] = TEXT_EMOTE_DRINK;
    textEmotes["drool"] = TEXT_EMOTE_DROOL;
    textEmotes["eat"] = TEXT_EMOTE_EAT;
    textEmotes["eye"] = TEXT_EMOTE_EYE;
    textEmotes["fart"] = TEXT_EMOTE_FART;
    textEmotes["fidget"] = TEXT_EMOTE_FIDGET;
    textEmotes["flex"] = TEXT_EMOTE_FLEX;
    textEmotes["frown"] = TEXT_EMOTE_FROWN;
    textEmotes["gasp"] = TEXT_EMOTE_GASP;
    textEmotes["gaze"] = TEXT_EMOTE_GAZE;
    textEmotes["giggle"] = TEXT_EMOTE_GIGGLE;
    textEmotes["glare"] = TEXT_EMOTE_GLARE;
    textEmotes["gloat"] = TEXT_EMOTE_GLOAT;
    textEmotes["greet"] = TEXT_EMOTE_GREET;
    textEmotes["grin"] = TEXT_EMOTE_GRIN;
    textEmotes["groan"] = TEXT_EMOTE_GROAN;
    textEmotes["grovel"] = TEXT_EMOTE_GROVEL;
    textEmotes["guffaw"] = TEXT_EMOTE_GUFFAW;
    textEmotes["hail"] = TEXT_EMOTE_HAIL;
    textEmotes["happy"] = TEXT_EMOTE_HAPPY;
    textEmotes["hello"] = TEXT_EMOTE_HELLO;
    textEmotes["hug"] = TEXT_EMOTE_HUG;
    textEmotes["hungry"] = TEXT_EMOTE_HUNGRY;
    textEmotes["kiss"] = TEXT_EMOTE_KISS;
    textEmotes["kneel"] = TEXT_EMOTE_KNEEL;
    textEmotes["laugh"] = TEXT_EMOTE_LAUGH;
    textEmotes["laydown"] = TEXT_EMOTE_LAYDOWN;
    textEmotes["message"] = TEXT_EMOTE_MESSAGE;
    textEmotes["moan"] = TEXT_EMOTE_MOAN;
    textEmotes["moon"] = TEXT_EMOTE_MOON;
    textEmotes["mourn"] = TEXT_EMOTE_MOURN;
    textEmotes["no"] = TEXT_EMOTE_NO;
    textEmotes["nod"] = TEXT_EMOTE_NOD;
    textEmotes["nosepick"] = TEXT_EMOTE_NOSEPICK;
    textEmotes["panic"] = TEXT_EMOTE_PANIC;
    textEmotes["peer"] = TEXT_EMOTE_PEER;
    textEmotes["plead"] = TEXT_EMOTE_PLEAD;
    textEmotes["point"] = TEXT_EMOTE_POINT;
    textEmotes["poke"] = TEXT_EMOTE_POKE;
    textEmotes["pray"] = TEXT_EMOTE_PRAY;
    textEmotes["roar"] = TEXT_EMOTE_ROAR;
    textEmotes["rofl"] = TEXT_EMOTE_ROFL;
    textEmotes["rude"] = TEXT_EMOTE_RUDE;
    textEmotes["salute"] = TEXT_EMOTE_SALUTE;
    textEmotes["scratch"] = TEXT_EMOTE_SCRATCH;
    textEmotes["sexy"] = TEXT_EMOTE_SEXY;
    textEmotes["shake"] = TEXT_EMOTE_SHAKE;
    textEmotes["shout"] = TEXT_EMOTE_SHOUT;
    textEmotes["shrug"] = TEXT_EMOTE_SHRUG;
    textEmotes["shy"] = TEXT_EMOTE_SHY;
    textEmotes["sigh"] = TEXT_EMOTE_SIGH;
    textEmotes["sit"] = TEXT_EMOTE_SIT;
    textEmotes["sleep"] = TEXT_EMOTE_SLEEP;
    textEmotes["snarl"] = TEXT_EMOTE_SNARL;
    textEmotes["spit"] = TEXT_EMOTE_SPIT;
    textEmotes["stare"] = TEXT_EMOTE_STARE;
    textEmotes["surprised"] = TEXT_EMOTE_SURPRISED;
    textEmotes["surrender"] = TEXT_EMOTE_SURRENDER;
    textEmotes["talk"] = TEXT_EMOTE_TALK;
    textEmotes["talkex"] = TEXT_EMOTE_TALKEX;
    textEmotes["talkq"] = TEXT_EMOTE_TALKQ;
    textEmotes["tap"] = TEXT_EMOTE_TAP;
    textEmotes["thank"] = TEXT_EMOTE_THANK;
    textEmotes["threaten"] = TEXT_EMOTE_THREATEN;
    textEmotes["tired"] = TEXT_EMOTE_TIRED;
    textEmotes["victory"] = TEXT_EMOTE_VICTORY;
    textEmotes["wave"] = TEXT_EMOTE_WAVE;
    textEmotes["welcome"] = TEXT_EMOTE_WELCOME;
    textEmotes["whine"] = TEXT_EMOTE_WHINE;
    textEmotes["whistle"] = TEXT_EMOTE_WHISTLE;
    textEmotes["work"] = TEXT_EMOTE_WORK;
    textEmotes["yawn"] = TEXT_EMOTE_YAWN;
    textEmotes["boggle"] = TEXT_EMOTE_BOGGLE;
    textEmotes["calm"] = TEXT_EMOTE_CALM;
    textEmotes["cold"] = TEXT_EMOTE_COLD;
    textEmotes["comfort"] = TEXT_EMOTE_COMFORT;
    textEmotes["cuddle"] = TEXT_EMOTE_CUDDLE;
    textEmotes["duck"] = TEXT_EMOTE_DUCK;
    textEmotes["insult"] = TEXT_EMOTE_INSULT;
    textEmotes["introduce"] = TEXT_EMOTE_INTRODUCE;
    textEmotes["jk"] = TEXT_EMOTE_JK;
    textEmotes["lick"] = TEXT_EMOTE_LICK;
    textEmotes["listen"] = TEXT_EMOTE_LISTEN;
    textEmotes["lost"] = TEXT_EMOTE_LOST;
    textEmotes["mock"] = TEXT_EMOTE_MOCK;
    textEmotes["ponder"] = TEXT_EMOTE_PONDER;
    textEmotes["pounce"] = TEXT_EMOTE_POUNCE;
    textEmotes["praise"] = TEXT_EMOTE_PRAISE;
    textEmotes["purr"] = TEXT_EMOTE_PURR;
    textEmotes["puzzle"] = TEXT_EMOTE_PUZZLE;
    textEmotes["raise"] = TEXT_EMOTE_RAISE;
    textEmotes["ready"] = TEXT_EMOTE_READY;
    textEmotes["shimmy"] = TEXT_EMOTE_SHIMMY;
    textEmotes["shiver"] = TEXT_EMOTE_SHIVER;
    textEmotes["shoo"] = TEXT_EMOTE_SHOO;
    textEmotes["slap"] = TEXT_EMOTE_SLAP;
    textEmotes["smirk"] = TEXT_EMOTE_SMIRK;
    textEmotes["sniff"] = TEXT_EMOTE_SNIFF;
    textEmotes["snub"] = TEXT_EMOTE_SNUB;
    textEmotes["soothe"] = TEXT_EMOTE_SOOTHE;
    textEmotes["stink"] = TEXT_EMOTE_STINK;
    textEmotes["taunt"] = TEXT_EMOTE_TAUNT;
    textEmotes["tease"] = TEXT_EMOTE_TEASE;
    textEmotes["thirsty"] = TEXT_EMOTE_THIRSTY;
    textEmotes["veto"] = TEXT_EMOTE_VETO;
    textEmotes["snicker"] = TEXT_EMOTE_SNICKER;
    textEmotes["stand"] = TEXT_EMOTE_STAND;
    textEmotes["tickle"] = TEXT_EMOTE_TICKLE;
    textEmotes["violin"] = TEXT_EMOTE_VIOLIN;
    textEmotes["smile"] = TEXT_EMOTE_SMILE;
    textEmotes["rasp"] = TEXT_EMOTE_RASP;
    textEmotes["pity"] = TEXT_EMOTE_PITY;
    textEmotes["growl"] = TEXT_EMOTE_GROWL;
    textEmotes["bark"] = TEXT_EMOTE_BARK;
    textEmotes["scared"] = TEXT_EMOTE_SCARED;
    textEmotes["flop"] = TEXT_EMOTE_FLOP;
    textEmotes["love"] = TEXT_EMOTE_LOVE;
    textEmotes["moo"] = TEXT_EMOTE_MOO;
    textEmotes["commend"] = TEXT_EMOTE_COMMEND;
    textEmotes["train"] = TEXT_EMOTE_TRAIN;
    textEmotes["helpme"] = TEXT_EMOTE_HELPME;
    textEmotes["incoming"] = TEXT_EMOTE_INCOMING;
    textEmotes["charge"] = TEXT_EMOTE_CHARGE;
    textEmotes["flee"] = TEXT_EMOTE_FLEE;
    textEmotes["attackmytarget"] = TEXT_EMOTE_ATTACKMYTARGET;
    textEmotes["oom"] = TEXT_EMOTE_OOM;
    textEmotes["follow"] = TEXT_EMOTE_FOLLOW;
    textEmotes["wait"] = TEXT_EMOTE_WAIT;
    textEmotes["healme"] = TEXT_EMOTE_HEALME;
    textEmotes["openfire"] = TEXT_EMOTE_OPENFIRE;
    textEmotes["flirt"] = TEXT_EMOTE_FLIRT;
    textEmotes["joke"] = TEXT_EMOTE_JOKE;
    textEmotes["golfclap"] = TEXT_EMOTE_GOLFCLAP;
    textEmotes["wink"] = TEXT_EMOTE_WINK;
    textEmotes["pat"] = TEXT_EMOTE_PAT;
    textEmotes["serious"] = TEXT_EMOTE_SERIOUS;
    textEmotes["mount_special"] = TEXT_EMOTE_MOUNT_SPECIAL;
    textEmotes["goodluck"] = TEXT_EMOTE_GOODLUCK;
    textEmotes["blame"] = TEXT_EMOTE_BLAME;
    textEmotes["blank"] = TEXT_EMOTE_BLANK;
    textEmotes["brandish"] = TEXT_EMOTE_BRANDISH;
    textEmotes["breath"] = TEXT_EMOTE_BREATH;
    textEmotes["disagree"] = TEXT_EMOTE_DISAGREE;
    textEmotes["doubt"] = TEXT_EMOTE_DOUBT;
    textEmotes["embarrass"] = TEXT_EMOTE_EMBARRASS;
    textEmotes["encourage"] = TEXT_EMOTE_ENCOURAGE;
    textEmotes["enemy"] = TEXT_EMOTE_ENEMY;
    textEmotes["eyebrow"] = TEXT_EMOTE_EYEBROW;
    textEmotes["toast"] = TEXT_EMOTE_TOAST;
    textEmotes["fail"] = TEXT_EMOTE_FAIL;
    textEmotes["highfive"] = TEXT_EMOTE_HIGHFIVE;
    textEmotes["absent"] = TEXT_EMOTE_ABSENT;
    textEmotes["arm"] = TEXT_EMOTE_ARM;
    textEmotes["awe"] = TEXT_EMOTE_AWE;
    textEmotes["backpack"] = TEXT_EMOTE_BACKPACK;
    textEmotes["badfeeling"] = TEXT_EMOTE_BADFEELING;
    textEmotes["challenge"] = TEXT_EMOTE_CHALLENGE;
    textEmotes["chug"] = TEXT_EMOTE_CHUG;
    textEmotes["ding"] = TEXT_EMOTE_DING;
    textEmotes["facepalm"] = TEXT_EMOTE_FACEPALM;
    textEmotes["faint"] = TEXT_EMOTE_FAINT;
    textEmotes["go"] = TEXT_EMOTE_GO;
    textEmotes["going"] = TEXT_EMOTE_GOING;
    textEmotes["glower"] = TEXT_EMOTE_GLOWER;
    textEmotes["headache"] = TEXT_EMOTE_HEADACHE;
    textEmotes["hiccup"] = TEXT_EMOTE_HICCUP;
    textEmotes["hiss"] = TEXT_EMOTE_HISS;
    textEmotes["holdhand"] = TEXT_EMOTE_HOLDHAND;
    textEmotes["hurry"] = TEXT_EMOTE_HURRY;
    textEmotes["idea"] = TEXT_EMOTE_IDEA;
    textEmotes["jealous"] = TEXT_EMOTE_JEALOUS;
    textEmotes["luck"] = TEXT_EMOTE_LUCK;
    textEmotes["map"] = TEXT_EMOTE_MAP;
    textEmotes["mercy"] = TEXT_EMOTE_MERCY;
    textEmotes["mutter"] = TEXT_EMOTE_MUTTER;
    textEmotes["nervous"] = TEXT_EMOTE_NERVOUS;
    textEmotes["offer"] = TEXT_EMOTE_OFFER;
    textEmotes["pet"] = TEXT_EMOTE_PET;
    textEmotes["pinch"] = TEXT_EMOTE_PINCH;
    textEmotes["proud"] = TEXT_EMOTE_PROUD;
    textEmotes["promise"] = TEXT_EMOTE_PROMISE;
    textEmotes["pulse"] = TEXT_EMOTE_PULSE;
    textEmotes["punch"] = TEXT_EMOTE_PUNCH;
    textEmotes["pout"] = TEXT_EMOTE_POUT;
    textEmotes["regret"] = TEXT_EMOTE_REGRET;
    textEmotes["revenge"] = TEXT_EMOTE_REVENGE;
    textEmotes["rolleyes"] = TEXT_EMOTE_ROLLEYES;
    textEmotes["ruffle"] = TEXT_EMOTE_RUFFLE;
    textEmotes["sad"] = TEXT_EMOTE_SAD;
    textEmotes["scoff"] = TEXT_EMOTE_SCOFF;
    textEmotes["scold"] = TEXT_EMOTE_SCOLD;
    textEmotes["scowl"] = TEXT_EMOTE_SCOWL;
    textEmotes["search"] = TEXT_EMOTE_SEARCH;
    textEmotes["shakefist"] = TEXT_EMOTE_SHAKEFIST;
    textEmotes["shifty"] = TEXT_EMOTE_SHIFTY;
    textEmotes["shudder"] = TEXT_EMOTE_SHUDDER;
    textEmotes["signal"] = TEXT_EMOTE_SIGNAL;
    textEmotes["silence"] = TEXT_EMOTE_SILENCE;
    textEmotes["sing"] = TEXT_EMOTE_SING;
    textEmotes["smack"] = TEXT_EMOTE_SMACK;
    textEmotes["sneak"] = TEXT_EMOTE_SNEAK;
    textEmotes["sneeze"] = TEXT_EMOTE_SNEEZE;
    textEmotes["snort"] = TEXT_EMOTE_SNORT;
    textEmotes["squeal"] = TEXT_EMOTE_SQUEAL;
    textEmotes["stopattack"] = TEXT_EMOTE_STOPATTACK;
    textEmotes["suspicious"] = TEXT_EMOTE_SUSPICIOUS;
    textEmotes["think"] = TEXT_EMOTE_THINK;
    textEmotes["truce"] = TEXT_EMOTE_TRUCE;
    textEmotes["twiddle"] = TEXT_EMOTE_TWIDDLE;
    textEmotes["warn"] = TEXT_EMOTE_WARN;
    textEmotes["snap"] = TEXT_EMOTE_SNAP;
    textEmotes["charm"] = TEXT_EMOTE_CHARM;
    textEmotes["coverears"] = TEXT_EMOTE_COVEREARS;
    textEmotes["crossarms"] = TEXT_EMOTE_CROSSARMS;
    textEmotes["look"] = TEXT_EMOTE_LOOK;
    textEmotes["object"] = TEXT_EMOTE_OBJECT;
    textEmotes["sweat"] = TEXT_EMOTE_SWEAT;
    textEmotes["yw"] = TEXT_EMOTE_YW;
}


bool EmoteAction::isUseful()
{
    time_t lastEmote = AI_VALUE2(time_t, "last emote", qualifier);
    return (time(0) - lastEmote) > 30;
}
