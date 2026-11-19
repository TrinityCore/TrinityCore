-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23832,-18587) AND source_type=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2383200 AND source_type=9;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=23832;
UPDATE `creature_template_addon` SET `auras`="42491" WHERE `entry`=23832;
