#include "Player.h"
#include "Chat.h"
#include "World.h"

class anuncio_gm_login : public PlayerScript
{
public:
    anuncio_gm_login() : PlayerScript("anuncio_gm_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)override
    {
        if (player->IsGameMaster() == true)
        {
            std::ostringstream ss;
            ss << "|cff4CFF00[MJ ONLINE]: " << player->GetName() << " se ha conectado.";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }
    }
};

void AddSC_anuncio_gm_login()
{
    new anuncio_gm_login;
}
