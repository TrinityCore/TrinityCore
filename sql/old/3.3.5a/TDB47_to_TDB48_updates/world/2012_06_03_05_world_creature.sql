-- Fix up Shadowmoon Harbinger
SET @ENTRY := 21795;
UPDATE `creature` SET `spawndist`=5,`MovementType`=1,`curhealth`=1,`curmana`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'37467 37509');
