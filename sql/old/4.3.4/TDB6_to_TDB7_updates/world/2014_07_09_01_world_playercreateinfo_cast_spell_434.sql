DELETE FROM `playercreateinfo_cast_spell` WHERE `spell` IN (48266, 79597, 79598, 79593, 79602, 79600, 79603, 79599, 79595, 79594, 79601, 79596, 2457, 688, 73523);
INSERT INTO `playercreateinfo_cast_spell` (`racemask`, `classmask`, `spell`, `note`) VALUES
-- Death Knight
(0, 32, 48266, 'Death Knight - Blood Presence'),
-- Hunter
(1, 4, 79597, 'Human - Hunter - Young Wolf'),
(2, 4, 79598, 'Orc - Hunter - Young Boar'),
(4, 4, 79593, 'Dwarf - Hunter - Young Bear'),
(8, 4, 79602, 'Night Elf - Hunter - Young Cat'),
(16, 4, 79600, 'Undead - Hunter - Young Widow'),
(32, 4, 79603, 'Tauren - Hunter - Young Tallstrider'),
(128, 4, 79599, 'Troll - Hunter - Young Raptor'),
(256, 4, 79595, 'Goblin - Hunter - Young Crab'),
(512, 4, 79594, 'Blood Elf - Hunter - Young Dragonhawk'),
(1024, 4, 79601, 'Draenei - Hunter - Young Moth'),
(2097152, 4, 79596, 'Worgen - Hunter - Young Mastiff'),
-- Warrior
(0, 1, 2457, 'Warrior - Battle Stance'),
-- Warlock
(0, 256, 688, 'Warlock - Summon Imp'),
-- Quest
(16, 0, 73523, 'Undead - Rigor Mortis');
