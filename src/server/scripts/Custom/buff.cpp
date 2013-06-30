	

    /***************************************
    *Made by ???                           *
    *Edit & Release by Ghostcrawler336     *
    ****************************************/
    #include "ScriptPCH.h"
    #include "Chat.h"
     
     
    uint32 auras[] = { 48162, 48074, 48170, 43223, 36880, 467, 48469 };
     
    class buffcommand : public CommandScript
    {
    public:
        buffcommand() : CommandScript("buffcommand") { }
     
            ChatCommand* GetCommands() const
        {
            static ChatCommand IngameCommandTable[] =
            {
            { "buff",           SEC_PLAYER,         true,  &HandleBuffCommand,                "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
            };
                     return IngameCommandTable;
        }
     
            static bool HandleBuffCommand(ChatHandler * handler, const char * args)
        {
            Player * pl = handler->GetSession()->GetPlayer();
                    if(pl->InArena())
                    {
                            pl->GetSession()->SendNotification("You can't use that item in an arena match!");
                            return false;
                    }
           
                    pl->RemoveAurasByType(SPELL_AURA_MOUNTED);
                    for(int i = 0; i < 7; i++)
                        pl->AddAura(auras[i], pl);
                    handler->PSendSysMessage("|cffB400B4You have been buffed, enjoy!");
                    return true;
     
        }
    };
     
    void AddSC_buffcommand()
    {
        new buffcommand();
    }

