-- Rogues missing start skill
DELETE FROM `playercreateinfo_skills` WHERE `raceMask`=0 AND `classMask`=8 AND `skill`=54;
INSERT INTO `playercreateinfo_skills` (`raceMask`,`classMask`,`skill`,`comment`) VALUES
(0,8,54, 'Rogue - Mace');
