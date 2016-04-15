#include "Player.h"
#include "Chat.h"
#include "World.h"
#include "boost/date_time.hpp"

class FindeDobleXP : public PlayerScript
{
public:
    FindeDobleXP() : PlayerScript("FindeDobleXP") { }

    virtual void OnMoneyChanged(Player* player, int64& amount)override
    {
        boost::gregorian::date date(boost::gregorian::day_clock::local_day());
        auto day = date.day_of_week();
        if (day == boost::date_time::Friday || day == boost::date_time::Saturday || day == boost::date_time::Sunday)
            if(amount > 0)
                amount = amount*2;
    }

    virtual void OnGiveXP(Player* player, uint32& amount, Unit* victim)override
    {
        boost::gregorian::date date(boost::gregorian::day_clock::local_day());
        auto day = date.day_of_week();
        if (day == boost::date_time::Friday || day == boost::date_time::Saturday || day == boost::date_time::Sunday)
            amount = amount*2;

    }

    virtual void OnLogin(Player* player, bool firstLogin)override
    {
        boost::gregorian::date date(boost::gregorian::day_clock::local_day());
        auto day = date.day_of_week();
        if (day == boost::date_time::Friday || day == boost::date_time::Saturday || day == boost::date_time::Sunday)
            ChatHandler(player->GetSession()).PSendSysMessage("¡Doble de Experiencia y Oro este Fin de Semana!");
    }
};

void AddSC_FindeDobleXP()
{
    new FindeDobleXP();
}
