-- Creature Magma Orb 54299
SET @ENTRY := 54299;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
