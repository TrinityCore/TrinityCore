DELETE FROM `playercreateinfo_cast_spell` WHERE `spell` IN (259086, 259085, 274907, 294662, 312339, 259087, 259084, 294659, 312338, 274905);
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `ClassMask`, `spell`, `note`) VALUES
(0x10000000, 0x4, 259086, 'Void Elf summon Voidstalker Pet'), -- Voidelf
(0x20000000, 0x4, 259085, 'Lightforged Draenei summon Lightforged Talbuk Pet'), -- Lightforged Draenei
(0x800, 0x4, 274907, 'Dark Iron Dwarf summon Blazehound Pet'), -- Dark Iron Dwarf
(0x80000000, 0x4, 294662, 'Kul Tiran summon Alpine Falcon Pet'), -- Kul Tiran Human
(0x4000, 0x4, 312339, 'Mechagnome summon Robowolf Pet'), -- Mechagnome
(0x4000000, 0x4, 259087, 'Nightborne summon Manasaber Pet'), -- Nightborn
(0x8000000, 0x4, 259084, 'Highmountain Tauren summon Great Eagle Pet'), -- Highmountain Tauren
(0x40000000, 0x4, 294659, 'Zandalari Troll summon Slate Direhorn Pet'), -- Zandalari Troll
(0x1000, 0x4, 312338, 'Vulpera summon Crimson Cobra Pet'), -- Vulpera
(0x2000, 0x4, 274905, 'Maghar Orc Summon Shadowmoon Stalker Pet'); -- Maghar Orc
