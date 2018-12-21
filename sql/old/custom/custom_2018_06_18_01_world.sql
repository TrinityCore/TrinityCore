DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (36037, 28434, 36055, 35827, 36019, 36056, 35546, 36054, 35733);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Chance`, `MinCount`, `MaxCount`, `IsCurrency`) VALUES
(36037, 64394, 4, 1, 3, 0), -- Draenei Tomes
(36037, 398, 100, 4, 9, 1), -- Draenei Archaeology Fragment
(28434, 52843, 4, 1, 3, 0), -- Dwarf Rune Stone
(28434, 384, 100, 4, 9, 1), -- Dwarf Archaeology Fragment
(36055, 64396, 4, 1, 3, 0), -- Nerubian Obelisk
(36055, 400, 100, 4, 9, 1), -- Nerubian Archaeology Fragment
(35827, 63127, 4, 1, 3, 0), -- Highborne Scroll
(35827, 394, 100, 4, 9, 1), -- Night Elf Archaeology Fragment
(36019, 64392, 4, 1, 3, 0), -- Orc Blood Text
(36019, 397, 100, 4, 9, 1), -- Orc Archaeology Fragment
(36056, 64397, 4, 1, 3, 0), -- Tolvir Hieroglyphic
(36056, 401, 100, 4, 9, 1), -- Tolvir Archaeology Fragment
(35546, 63128, 4, 1, 3, 0), -- Troll Tablet
(35546, 385, 100, 4, 9, 1), -- Troll Archaeology Fragment
(36054, 36054, 4, 1, 3, 0), -- Vrykul Rune Stick
(36054, 399, 100, 4, 9, 1), -- Vrykul Archaeology Fragment
(35733, 393, 100, 4, 9, 1); -- Fossil Archaeology Fragment
