--
SET @GUID       := 143596;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN -@GUID-89 AND -@GUID-0 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=36421 WHERE `entryorguid`= 1999500 AND `Source_type`= 9 AND `id`= 17;
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=120692;
