--
DELETE FROM `playercreateinfo_skills` WHERE `skill` IN (795, 796, 797, 798, 799, 800, 801, 802, 803, 804);
INSERT INTO `playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `comment`) VALUES
(0, 4, 795, 'Hunter - General'),
(0, 32, 796, 'Death Knight - General'),
(0, 8, 797, 'Rogue - General'),
(0, 1024, 798, 'Druid - General'),
(0, 128, 799, 'Mage - General'),
(0, 2, 800, 'Paladin - General'),
(0, 64, 801, 'Shaman - General'),
(0, 256, 802, 'Warlock - General'),
(0, 1, 803, 'Warrior - General'),
(0, 16, 804, 'Priest - General');

