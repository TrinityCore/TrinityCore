/* ------------------------------------ */
/* AUTHOR   Azgath                      */
/*    FOR   Az'gath Private Server      */
/* ------------------------------------ */

class azgath_gift_mount : public PlayerScript
{
private:
    bool isEnabled = false;
    uint32 flySpell = 90265; /* Maître cavalier */
    uint32 mountSpell = 307932; /* Wyrm éternel ensorcelé */

public:
    azgath_gift_mount() : PlayerScript("azgath_gift_mount") {}

    void OnLogin(Player* player, bool /*firstLogin*/) {
        if (isEnabled) {
            if (!player->HasSpell(flySpell)) {
                player->LearnSpell(flySpell, false);
            }

            if (!player->HasSpell(mountSpell)) {
                player->LearnSpell(mountSpell, false);
            }
        }
    }
};

void AddSC_azgath_gift_mount()
{
    new azgath_gift_mount();
}
