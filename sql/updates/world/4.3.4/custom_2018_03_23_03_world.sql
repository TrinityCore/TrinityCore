INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(94746, 0x00054000, 0x00000001 | 0x00000002, 0x00000002, 0x00000000, 45000), -- Enchant Weapon - Power Torrent
(94747, 0x00054400, 0x00000001 | 0x00000002, 0x00000002, 0x00000000, 45000), -- Enchant Weapon - Hurricane
(95472, 0x00050000, 0x00000001, 0x00000002, 0x00000000, 45000), -- Enchant Weapon - Avalanche
(95709, 0x00050000, 0x00000001, 0x00000002, 0x00000000, 45000); -- Enchant Weapon - Mending

DELETE FROM `spell_enchant_proc_data` WHERE `entry` IN (4098, 4099);
INSERT INTO `spell_enchant_proc_data` (`entry`, `customChance`, `PPMChance`, `procEx`) VALUES
(4098, 0, 1.25, 0), -- Enchant Weapon - Windwalk
(4099, 0, 1.25, 0); -- Enchant Weapon - Landslide
