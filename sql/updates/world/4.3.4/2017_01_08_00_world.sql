-- Hunters start with a pet depending on raceMask
DELETE FROM playercreateinfo_cast_spell WHERE classMask=4;
INSERT INTO playercreateinfo_cast_spell VALUES
(1,4,79597,"Human - Hunter - Young Wolf"),
(2,4,79598,"Orc - Hunter - Young Boar"),
(4,4,79593,"Dwarf - Hunter - Young Boar"),
(8,4,79602,"Night Elf - Hunter - Young Boar"),
(16,4,79600,"Undead - Hunter - Young Widow"),
(32,4,79603,"Tauren - Hunter - Young Tallstrider"),
(128,4,79599,"Troll - Hunter - Young Raptor"),
(256,4,79595,"Goblin - Hunter - Young Crab"),
(512,4,79594,"Blood Elf - Hunter - Young Dragonhawk"),
(1024,4,79601,"Draenei - Hunter - Young Moth"),
(2097152,4,79596,"Worgen - Hunter - Young Mastiff");
--
