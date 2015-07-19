UPDATE `conditions` SET `ConditionValue1`=188679 WHERE `ConditionValue1`=300199;
DELETE FROM `creature_queststarter` WHERE `quest`=14351;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
(2215, 14351);
UPDATE `quest_template` SET `NextQuestIdChain`=14351 WHERE  `Id`=541;
UPDATE `quest_template` SET `PrevQuestId`=541 WHERE  `Id`=14351;
UPDATE `spell_area` SET `quest_start_status`=74 WHERE  `spell`=57745 AND `area`=4591 AND `quest_start`=13068 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
