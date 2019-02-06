-- 
UPDATE `creature_template_addon` SET `auras`="47395" WHERE `entry` IN (26654,26772,26656,26608);
DELETE FROM `creature_template_addon` WHERE `entry` IN (26319,26606,26777,26676,26778);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(26676,"47396"),(26319,"47396"),(26606,"47396"),(26777,"47395"),(26778,"47395");
UPDATE `creature_addon` SET `auras` ="47396" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (26319, 26606));

DELETE FROM `spell_area` WHERE `area` IN (4163) AND `spell`=47396;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`, `quest_end_status`) VALUES
(47396, 4163, 0, 12069, 0, 0, 2, 1, 0, 11);

DELETE FROM `gameobject_addon` WHERE `guid`=5544;
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES (5544, 5, 1000);

DELETE FROM `creature_template_addon` WHERE `entry` IN (26810);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(26810,"47417");  

DELETE FROM `spell_area` WHERE `area` IN (4165) AND `spell`=47418;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`, `quest_end_status`) VALUES
(47418, 4165, 12069, 0, 0, 0, 2, 1, 64, 0);

UPDATE `creature_addon` SET `auras` ="47418" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (26437));
UPDATE `creature_template_addon` SET `auras`="47786 47418" WHERE `entry`=26379;
