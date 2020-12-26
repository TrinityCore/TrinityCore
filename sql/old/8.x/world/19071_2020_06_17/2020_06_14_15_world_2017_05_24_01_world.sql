-- 
UPDATE `gameobject_addon` SET `invisibilityType`=9, `invisibilityValue`=1000 WHERE `guid`=270;
UPDATE `gameobject_addon` SET `invisibilityType`=8, `invisibilityValue`=1000 WHERE `guid`=21077;
UPDATE `gameobject_addon` SET `invisibilityType`=5, `invisibilityValue`=1000 WHERE `guid`=21079;
DELETE FROM `spell_area` WHERE `spell` IN (56773,56772,56774) AND `area`=4438;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(56773, 4438, 12987, 0, 0, 0, 2, 3, 66, 0),
(56772, 4438, 13001, 0, 0, 0, 2, 3, 64, 0),
(56774, 4438, 12976, 0, 0, 0, 2, 3, 64, 0);
