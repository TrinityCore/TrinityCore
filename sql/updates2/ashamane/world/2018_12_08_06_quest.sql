-- Fix quest Gryphon' Napper (51358)

-- Allow gobject to start quest 51358
DELETE FROM `gameobject_queststarter` WHERE (quest = 51358);
INSERT INTO `gameobject_queststarter` (`id`, `quest`) VALUES
(288641, 51358);
-- Update LockId so it's clickable
UPDATE `gameobject_template` SET `Data0` = 5 WHERE (entry = 288641);
-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceGroup` = '1' AND `SourceEntry` = '279049' AND `SourceId` = '0' AND `ElseGroup` = '0' AND `ConditionTypeOrReference` = '31' AND `ConditionTarget` = '0' AND `ConditionValue1` = '4' AND `ConditionValue2` = '0' AND `ConditionValue3` = '0'; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('13', '1', '279049', '31', '4'); 
