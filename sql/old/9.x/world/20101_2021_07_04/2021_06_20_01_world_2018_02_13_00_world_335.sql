-- Remove unique items from reference table 24064
DELETE FROM `reference_loot_template` WHERE `Entry`=24064 AND `Item` IN (911, 920, 1076, 1406, 1455, 1459, 1461, 1462, 2034, 2232, 3429);

-- Add former items from reference table 24064 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (911, 920, 1076, 1406, 1455, 2034, 2232, 3429);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(1706, 1076, 1,   0, "Prisoner - Defias Renegade Ring"),
(1711, 1076, 1,   0, "Convict - Defias Renegade Ring"),
(1715, 1076, 1,   0, "Insurgent - Defias Renegade Ring"),
(435,  1455, 0.1, 0, "Blackrock Champion - Blackrock Champion's Axe"),
(74351, 2034, 1,   0, "Twilight Disciple - Scholarly Robes"),
(74353, 2034, 1,   0, "Twilight Aquamancer - Scholarly Robes"),
(74363, 2034, 1,   0, "Twilight Shadow - Scholarly Robes"),
(74380, 2034, 1,   0, "Twilight Storm Mender - Scholarly Robes"),
(74382, 2034, 1,   0, "Twilight Shadowmage - Scholarly Robes"),
(74980, 2034, 1,   0, "Twilight Storm Mender - Scholarly Robes"),
(74983, 2034, 1,   0, "Twilight Disciple - Scholarly Robes"),
(75058, 2034, 1,   0, "Twilight Aquamancer - Scholarly Robes"),
(75135, 2034, 1,   0, "Tormented Sacrifice - Scholarly Robes"),
(75285, 2034, 1,   0, "Twilight Storm Mender - Scholarly Robes"),
(75286, 2034, 1,   0, "Twilight Disciple - Scholarly Robes"),
(76036, 2034, 1,   0, "Twilight Shadow - Scholarly Robes"),
(76037, 2034, 1,   0, "Twilight Storm Mender - Scholarly Robes"),
(76038, 2034, 1,   0, "Twilight Shadowmage - Scholarly Robes"),
(76039, 2034, 1,   0, "Twilight Aquamancer - Scholarly Robes"),
(77232, 2034, 1,   0, "Twilight Disciple - Scholarly Robes");
