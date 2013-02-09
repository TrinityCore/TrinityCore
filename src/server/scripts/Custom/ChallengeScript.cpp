/*  .Challenge Script for Saqirmdev/TrinityCore -> Thanks L30m4nc3r*/

#include "ScriptPCH.h"
#include "BattlegroundMgr.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "World.h"
#include "Group.h"


class challenge_commands : public CommandScript
{
public:
    challenge_commands() : CommandScript("challenge_commands") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand challengeCreateCommandTable[] =
        {
     		{ "players",        SEC_MODERATOR,      false, &HandleChallengeCreate1x1Command,    "", NULL },
            { "2x2",            SEC_MODERATOR,      false, &HandleChallengeCreate2x2Command,    "", NULL },
            { "3x3",            SEC_MODERATOR,      false, &HandleChallengeCreate3x3Command,    "", NULL },
            { "5x5",            SEC_MODERATOR,      false, &HandleChallengeCreate5x5Command,    "", NULL },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };

        static ChatCommand challengeCommandTable[] =
        {
            { "create",         SEC_MODERATOR,      false, NULL,                                "", challengeCreateCommandTable },
            { "accept",         SEC_PLAYER,         false, &HandleChallengeAcceptCommand,       "", NULL },
            { "mode",           SEC_PLAYER,         false, &HandleChallengeModeCommand,         "", NULL },
            { "1x1",            SEC_PLAYER,         false, &HandleChallenge1x1Command,          "", NULL },
            { "2x2",            SEC_PLAYER,         false, &HandleChallenge2x2Command,          "", NULL },
            { "3x3",            SEC_PLAYER,         false, &HandleChallenge3x3Command,          "", NULL },
            { "5x5",            SEC_PLAYER,         false, &HandleChallenge5x5Command,          "", NULL },
            { "on",             SEC_PLAYER,         false, &HandleChallengeOnCommand,           "", NULL },
            { "off",            SEC_PLAYER,         false, &HandleChallengeOffCommand,          "", NULL },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "challenge",      SEC_PLAYER,         false, NULL,                                "", challengeCommandTable },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };
        return commandTable;
    }

    static bool HandleChallengeModeCommand(ChatHandler* handler, const char* args)
    {
        if (!args)
        {
            handler->PSendSysMessage("Wrong arg!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        ChallengeOption *option = handler->GetSession()->GetPlayer()->challengeData->options;

        switch (args[0])
        {
            case '1':
                if (option->mode != 1)
                {
                    option->mode   = 1;
                    option->changed = true;
                }
                break;
            case '0':
                if (option->mode != 0)
                {
                    option->mode   = 0;
                    option->changed = true;
                }
                break;
            default:
                handler->PSendSysMessage("Wrong arg!");
                handler->SetSentErrorMessage(true);
                return false;
        }

        handler->PSendSysMessage("Mode changed.");
        return true;
    }

    static bool HandleChallengeOnCommand(ChatHandler* handler, const char* /*args*/)
    {
        ChallengeOption *option = handler->GetSession()->GetPlayer()->challengeData->options;
        if (!option->enable)
        {
            option->enable = true;
            option->changed = true;
        }

        handler->PSendSysMessage("Challenge enabled.");
        return true;
    }

    static bool HandleChallengeOffCommand(ChatHandler* handler, const char* /*args*/)
    {
        ChallengeOption *option = handler->GetSession()->GetPlayer()->challengeData->options;
        if (option->enable)
        {
            option->enable = false;
            option->changed = true;
        }

        handler->PSendSysMessage("Challenge disabled.");
        return true;
    }

    static bool HandleChallengeAcceptCommand(ChatHandler* handler, const char* /*args*/)
    {
        uint64 challengerGuid = handler->GetSession()->GetPlayer()->challengeData->challenger;
        if (!challengerGuid)
        {
            handler->PSendSysMessage("You haven`t challenger.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *challenger = ObjectAccessor::FindPlayer(challengerGuid);
        if (!challenger)
        {
            handler->PSendSysMessage("Cant find challenger. Offline?");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sChallengeMgr->InviteGroupsToArena(handler->GetSession()->GetPlayer(), challenger, (ArenaChallengeType)handler->GetSession()->GetPlayer()->challengeData->challengeType))
        {
            handler->PSendSysMessage("Oops! Cant join to queue.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

    static bool HandleChallenge1x1Command(ChatHandler* handler, const char* args)
    {
        return ChallengeForBracket(handler, args, ARENA_CHALLENGE_TYPE_1v1);
    }

    static bool HandleChallenge2x2Command(ChatHandler* handler, const char* args)
    {
        return ChallengeForBracket(handler, args, ARENA_CHALLENGE_TYPE_2v2);
    }

    static bool HandleChallenge3x3Command(ChatHandler* handler, const char* args)
    {
        return ChallengeForBracket(handler, args, ARENA_CHALLENGE_TYPE_3v3);
    }

    static bool HandleChallenge5x5Command(ChatHandler* handler, const char* args)
    {
        return ChallengeForBracket(handler, args, ARENA_CHALLENGE_TYPE_5v5);
    }

    static bool ChallengeForBracket(ChatHandler* handler, const char* args, uint8 type)
    {
        Player *target = NULL;
        Player *player = handler->GetSession()->GetPlayer();

        if (!handler->extractPlayerTarget((char*)args, &target))
        {
            handler->PSendSysMessage("Cant find player.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target->challengeData->options->enable)
        {
			handler->PSendSysMessage("Player turn off this option.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if ((!player->GetGroup() || player->GetGroup()->GetMembersCount() != type ||
            !target->GetGroup() || target->GetGroup()->GetMembersCount() != type) && type != ARENA_CHALLENGE_TYPE_1v1 )
        {
            handler->PSendSysMessage("Problem with players count.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->challengeData->options->mode)
        {
            if (!sChallengeMgr->MakeChallengeOffer(handler->GetSession()->GetPlayer(), target, (ArenaChallengeType)type))
            {
                handler->PSendSysMessage("Oops! Cant join to queue.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("You have challenged %s. Wait for 20s while he make decision.", target->GetName());
        }
        else
        {
            if (!sChallengeMgr->InviteGroupsToArena(handler->GetSession()->GetPlayer(), target, (ArenaChallengeType)type))
            {
                handler->PSendSysMessage("Oops! Cant join to queue.");
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        return true;
    }

    static bool HandleChallengeCreate1x1Command(ChatHandler* handler, const char* args)
    {
        return ChallengeCreateForBracket(handler, args, ARENA_CHALLENGE_TYPE_1v1);
    }

    static bool HandleChallengeCreate2x2Command(ChatHandler* handler, const char* args)
    {
        return ChallengeCreateForBracket(handler, args, ARENA_CHALLENGE_TYPE_2v2);
    }

    static bool HandleChallengeCreate3x3Command(ChatHandler* handler, const char* args)
    {
        return ChallengeCreateForBracket(handler, args, ARENA_CHALLENGE_TYPE_3v3);
    }

    static bool HandleChallengeCreate5x5Command(ChatHandler* handler, const char* args)
    {
        return ChallengeCreateForBracket(handler, args, ARENA_CHALLENGE_TYPE_5v5);
    }

    static bool ChallengeCreateForBracket(ChatHandler* handler, const char* args, uint8 type)
    {
        std::string sargs = strtok((char*)args, " ");
	 char* pTokens = strtok(NULL, " ");
	 Player* player1;
     Player* player2;

        player1 = sObjectMgr->GetPlayerByLowGUID(pTokens[0]);
        player2 = sObjectMgr->GetPlayerByLowGUID(pTokens[1]);

        if (!player1 || !player2)
        {
            handler->PSendSysMessage("Cant find player.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if ((!player1->GetGroup() || player1->GetGroup()->GetMembersCount() != type ||
            !player2->GetGroup() || player2->GetGroup()->GetMembersCount() != type) && type != ARENA_CHALLENGE_TYPE_1v1)
        {
            handler->PSendSysMessage("Problem with players count.");
            handler->SetSentErrorMessage(true);
            return false;
        }

       if (!sChallengeMgr->InviteGroupsToArena(player1, player2, (ArenaChallengeType)type))
        {
            handler->PSendSysMessage("Oops! Cant join to queue.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }
 };


void AddSC_challenge_script()
{
    new challenge_commands();
}