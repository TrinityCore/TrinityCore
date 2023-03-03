/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

UPDATE `quest_template` SET RequiredPOI1 = 265427, RequiredPOI2 = 265428, RequiredPOI3 = 265429, RequiredPOI4 = 265430, RequiredUnkFlag1 = 1, RequiredUnkFlag2 = 1, RequiredUnkFlag3 = 1, RequiredUnkFlag4 = 1 WHERE id = 14070;
UPDATE `quest_template` SET RequiredPOI1 = 264967, RequiredPOI2 = 264968, RequiredPOI3 = 264969, RequiredUnkFlag1 = 0, RequiredUnkFlag2 = 0, RequiredUnkFlag3 = 0, RequiredUnkFlag4 = 0 WHERE id = 14110;
DELETE FROM `creature_questrelation` WHERE `quest` = 14070 AND id != 34668;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 66306;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 34830, 66306, 9, 0, 14069, 0, 0, 'Required quest active for spellclick');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 70015;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, ElseGroup, `SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 1, 48526, 70015, 9, 0, 24502, 0, 0, 'Required quest active for spellclick');

-- 
DELETE FROM `creature_text` WHERE `entry` = 35486 AND groupid = 11;
INSERT INTO `creature_text` (`entry`,`id` , `groupid`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
('35486', '0', '11', 'Победа! Вы получили свои личные сбережения!$B$B|TInterface\\Icons\\INV_Misc_coin_02.blp:64|t', '42', '0', '100', '0', '0', '0', '');