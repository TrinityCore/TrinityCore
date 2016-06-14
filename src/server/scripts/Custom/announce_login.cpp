class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
        if (player->GetTeam() == ALLIANCE)
                {
            std::ostringstream ss;
                        ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cff0026FF Alliance";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                }
                else
                {
            std::ostringstream ss;
                        ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cffFF0000 Horde" ;
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                }
        }
};

void AddSC_announce_login()
{
    new announce_login;
}