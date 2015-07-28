INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT `modelid1` FROM `creature_template` WHERE `modelid1` NOT IN (SELECT `modelid` FROM `creature_model_info`);
INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT `modelid2` FROM `creature_template` WHERE `modelid2` NOT IN (SELECT `modelid` FROM `creature_model_info`);
INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT `modelid3` FROM `creature_template` WHERE `modelid3` NOT IN (SELECT `modelid` FROM `creature_model_info`);
INSERT IGNORE INTO `creature_model_info` (`modelid`) SELECT `modelid4` FROM `creature_template` WHERE `modelid4` NOT IN (SELECT `modelid` FROM `creature_model_info`);
DELETE FROM `creature_model_info` WHERE `modelid` = 0;
