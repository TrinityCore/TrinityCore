SET @GUID := -317632;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`= 42098;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
