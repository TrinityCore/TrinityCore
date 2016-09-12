class AccountMounts : public PlayerScript
{
    static const bool limitrace = true; // This set to true will only learn mounts from chars on the same team, do what you want.
public:
    AccountMounts() : PlayerScript("AccountMounts") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        std::vector<uint32> Guids;
        uint32 playerGUID = player->GetGUID();
        QueryResult result1 = CharacterDatabase.PQuery("SELECT guid, race FROM characters WHERE account = %u", playerGUID);
        if (!result1)
            return;

        do
        {
            Field* fields = result1->Fetch();

            uint32 guid = fields[0].GetUInt32();
            uint32 race = fields[1].GetUInt8();

            if ((Player::TeamForRace(race) == Player::TeamForRace(player->getRace())) || !limitrace)
                Guids.push_back(result1->Fetch()[0].GetUInt32());

        } while (result1->NextRow());

        std::vector<uint32> Spells;

        for (auto& i : Guids)
        {
            QueryResult result2 = CharacterDatabase.PQuery("SELECT spell FROM character_spell WHERE guid = %u", i);
            if (!result2)
                continue;

            do
            {
                Spells.push_back(result2->Fetch()[0].GetUInt32());
            } while (result2->NextRow());
        }

        for (auto& i : Spells)
        {
            auto sSpell = sSpellStore.LookupEntry(i);
            if (sSpell->Effect[0] == SPELL_EFFECT_APPLY_AURA && sSpell->EffectApplyAuraName[0] == SPELL_AURA_MOUNTED)
                player->LearnSpell(sSpell->Id, false);
        }
    }
};

void AddSC_accontmounts()
{
    new AccountMounts;
}