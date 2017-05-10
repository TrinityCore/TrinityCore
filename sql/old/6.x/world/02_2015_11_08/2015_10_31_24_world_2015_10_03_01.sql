-- 
DELETE FROM `creature` WHERE `guid`=71981 AND `id`=20251;

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (15241, 21719, 24933, 21497, 20127);
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (20611);

UPDATE `creature_template_addon` SET `bytes1`=33554432 WHERE `entry`=21497;
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry` IN (21497);
UPDATE `smart_scripts` SET `action_param1`=15847, `comment`="Blackscale - In Combat - Cast 'Tail Sweep'" WHERE `entryorguid`=21497 AND `source_Type`=0 AND `id`=2;
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `id` IN (21497, 20611, 20127);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id` IN (21639, 20251, 22320);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (20238);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (20238) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20238,0,0,0,1,0,100,0,1000,3000,3000,7000,11,35063,0,0,0,0,0,19,20251,20,0,0,0,0,0,"Honor Hold Scout - OOC - Cast Shoot Honor Hold Scout Archery Target");
