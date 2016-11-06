-- 
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=287136;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4484, 2338) AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=2338 ;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `faction`=2372, `speed_run`=1.14286, `unit_class`=4, `unit_flags`=64 WHERE `entry`=54016;
DELETE FROM `gameobject_addon` WHERE `guid` IN (73588,73589,73590,73591,73592,73593,73594,73595,73596,73597, 222389, 200067);
DELETE FROM `spell_bonus_data` WHERE `entry`=54203;
