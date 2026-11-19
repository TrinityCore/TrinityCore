-- 
DELETE FROM `creature` WHERE `guid`=126052;
DELETE FROM `creature_addon` WHERE `guid`=126052;
DELETE FROM `linked_respawn` WHERE `guid`=126052 AND `linkedGuid`=126103;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (26668, 30810);
UPDATE `smart_scripts` SET `action_param6`=2 WHERE `entryorguid`=-126160 AND `id`=0;

UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry`=12423;

-- Set all of these creatures to roam 5 yards, and random movement type
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE id IN (16349,16352);

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `id`=9369;

UPDATE `creature_template` SET `unit_flags`=537166656, `unit_flags2`=2048 WHERE `entry` IN (26737);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26737) AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26737,0,6,0,6,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Mana-Surge - On Just Died - Remove unit flag immune to pc");

UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=10161;
