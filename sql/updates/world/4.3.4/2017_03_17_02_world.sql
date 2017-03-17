--
DELETE FROM `playercreateinfo_cast_spell` WHERE `spell` IN (688, 73523);
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `spell`, `note`) VALUES
(0, 256, 688, 'Warlock - Summon Imp'),
(16, 925, 73523, 'Undead - Rigor Mortis');
--
