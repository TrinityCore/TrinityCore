/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/


// To not include any random magic numbers; enums are our friends
enum Creationabilities
{
    WARRIOR_CREATION_BATTLE_STANCE       = 2457,  // Battle Stance
    DEATH_KNIGHT_CREATION_BLOOD_PRESENCE = 48266, // Blood Presence
    CREATIONABILITIES_COUNT              = 2
};

// Instead of adding a hacky way into Player::Create, we use existing hooks to cast these spells on first character login
class CharacterCreationProcedures : public PlayerScript
{
public:
    CharacterCreationProcedures() : PlayerScript("CharacterCreationProcedures") { }

    void OnLogin(Player* player, bool firstlogin)
    {
        if (firstlogin)
            switch (player->getClass())
            {
                // Only two classes posses an aura on creation;
                case CLASS_WARRIOR:
                    player->CastSpell(player, WARRIOR_CREATION_BATTLE_STANCE, true);
                    return;
                case CLASS_DEATH_KNIGHT:
                    player->CastSpell(player, DEATH_KNIGHT_CREATION_BLOOD_PRESENCE, true);
                    return;
                // We include, but do not change the other races
                case CLASS_NONE:
                case CLASS_PALADIN:
                case CLASS_HUNTER:
                case CLASS_ROGUE:
                case CLASS_PRIEST:
                case CLASS_SHAMAN:
                case CLASS_MAGE:
                case CLASS_WARLOCK:
                // case CLASS_UNK: // Does not exist!
                case CLASS_DRUID:
                default:
                    // Can be modified based on personal needs;
                    return;
            }
    }
};

void AddSC_character_creation()
{
    new CharacterCreationProcedures();
}