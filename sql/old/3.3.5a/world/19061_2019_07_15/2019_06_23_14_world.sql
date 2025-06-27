-- 
UPDATE `creature_template_addon` SET `auras`="45842" WHERE `entry`=25478;
DELETE FROM `creature_addon` WHERE `guid`=113408;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(113408, "46076");

DELETE FROM `spell_area` WHERE `spell` IN (45844, 46079);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(45844, 4023, 11590, 0, 0, 0, 2, 1, 64, 11),
(46079, 4023, 11681, 0, 0, 0, 2, 1, 66, 11);
