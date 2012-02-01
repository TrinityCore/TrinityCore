-- Races:
SET @HUMAN := 1;
SET @ORC := 2;
SET @DWARF := 3;
SET @NIGHT_ELF := 4;
SET @UNDEAD := 5;
SET @TAUREN := 6;
SET @GNOME := 7;
SET @TROLL := 8;
SET @GOBLIN := 9;
SET @BLOOD_ELF := 10;
SET @DRAENEI := 11;
SET @WORGEN := 22;
-- Classes:
SET @WARRIOR := 1;
SET @PALADIN := 2;
SET @HUNTER := 3;
SET @ROGUE := 4;
SET @PRIEST := 5;
SET @DK := 6;
SET @SHAMAN := 7;
SET @MAGE := 8;
SET @WARLOCK := 9;
SET @DRUID := 11;

DELETE FROM `player_levelstats` WHERE
((`class`=@WARRIOR AND `race` IN (@BLOOD_ELF, @GOBLIN, @WORGEN)) OR
(`class`=@PALADIN AND `race` IN (@TAUREN)) OR
(`class`=@HUNTER  AND `race` IN (@HUMAN, @GOBLIN, @WORGEN, @UNDEAD)) OR
(`class`=@ROGUE AND `race` IN (@GOBLIN, @WORGEN)) OR
(`class`=@PRIEST  AND `race` IN (@GNOME, @GOBLIN, @WORGEN, @TAUREN)) OR
(`class`=@SHAMAN  AND `race` IN (@GOBLIN, @DWARF)) OR
(`class`=@MAGE AND `race` IN (@DWARF, @GOBLIN, @WORGEN, @NIGHT_ELF, @ORC)) OR
(`class`=@WARLOCK AND `race` IN (@DWARF, @GOBLIN, @WORGEN, @TROLL)) OR
(`class`=@DRUID AND `race` IN (@WORGEN, @TROLL))) AND `level`=1;
DELETE FROM `player_levelstats` WHERE `class`=@DK AND `race` IN (@GOBLIN, @WORGEN) AND `level`=55;
INSERT INTO `player_levelstats` (`class`, `race`, `level`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES
(@WARRIOR, @BLOOD_ELF, 1, 20, 22, 20, 24, 19),
(@WARRIOR, @GOBLIN, 1, 20, 22, 22, 23, 18),
(@WARRIOR, @WORGEN, 1, 26, 22, 22, 16, 19),
(@PALADIN, @TAUREN, 1, 27, 15, 24, 15, 23),
(@HUNTER, @HUMAN, 1, 20,  23, 21, 20, 21),
(@HUNTER, @WORGEN, 1, 23,  25, 21, 16, 20),
(@HUNTER, @UNDEAD, 1, 19,  21, 22, 18, 26),
(@HUNTER, @GOBLIN, 1, 17,  25, 21, 23, 19),
(@ROGUE, @WORGEN, 1, 23, 25, 21, 16, 19),
(@ROGUE, @GOBLIN, 1, 18, 25, 21, 23, 18),
(@PRIEST, @GNOME, 1, 15 ,23, 19, 25, 23),
(@PRIEST, @WORGEN, 1, 23 ,22, 20, 18, 22),
(@PRIEST, @GOBLIN, 1, 17 ,22, 20, 25, 21),
(@PRIEST, @TAUREN, 1, 25 ,15, 22, 17, 25),
(@DK, @WORGEN, 55, 111, 75, 99, 25, 41),
(@DK, @GOBLIN, 55, 105, 75, 99, 32, 40),
(@SHAMAN, @DWARF, 1, 22, 16, 23, 22, 21),
(@SHAMAN, @GOBLIN, 1, 18, 22, 21, 24, 20),
(@MAGE, @DWARF, 1, 22, 16, 23, 22, 21),
(@MAGE, @NIGHT_ELF, 1, 17, 25, 19, 23, 22),
(@MAGE, @WORGEN, 1, 23, 22, 20, 19, 21),
(@MAGE, @GOBLIN, 1, 17, 22, 20, 26, 20),
(@MAGE, @ORC, 1, 23, 17, 22, 20, 25),
(@WARLOCK, @WORGEN, 1, 23, 22, 21, 18, 21),
(@WARLOCK, @DWARF, 1, 22, 16, 24, 21, 21),
(@WARLOCK, @GOBLIN, 1, 17, 22, 21, 25, 20),
(@WARLOCK, @TROLL, 1, 21, 22, 22, 18, 23),
(@DRUID, @WORGEN, 1, 24, 22, 20, 18, 21),
(@DRUID, @TROLL, 1, 22, 22, 21, 18, 23);
