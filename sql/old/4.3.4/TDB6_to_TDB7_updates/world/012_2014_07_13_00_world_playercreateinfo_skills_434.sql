UPDATE `playercreateinfo_skills` SET `raceMask` = 0 WHERE `skill` IN (45,46,160,173,226);
-- Goblin
UPDATE `playercreateinfo_skills` SET `raceMask` = `raceMask` | 256 WHERE `skill`=109; -- Language: Orcish
-- Worgen
UPDATE `playercreateinfo_skills` SET `raceMask` = `raceMask` | 2097152 WHERE `skill`=98; -- Language: Common

DELETE FROM `playercreateinfo_skills` WHERE `skill` IN (790,792,789,791);
INSERT INTO `playercreateinfo_skills` VALUES
-- Goblin
(256,0,790,0,'Racial - Goblin'),
(256,0,792,0,'Language: Goblin'),
-- Worgen
(2097152,0,789,0,'Racial - Worgen'),
(2097152,0,791,0,'Language: Worgen');
