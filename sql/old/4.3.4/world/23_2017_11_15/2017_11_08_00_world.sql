-- Set Scriptnames of Stormwind Infantry, Blackrock Battle Worg and Brother Paxton
UPDATE `creature_template` SET `scriptname`= 'npc_stormwind_infantry' WHERE `entry`= 49869;
UPDATE `creature_template` SET `scriptname`= 'npc_blackrock_battle_worg' WHERE `entry`= 49871;
UPDATE `creature_template_addon` SET `bytes1`= 0 WHERE `entry`= 49871;

DELETE FROM `creature_template_addon` WHERE `entry`= 951;
DELETE FROM `creature_addon` WHERE `guid`= 279895;

DELETE FROM `waypoints` WHERE `entry`= 279895;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(279895, 1, -8819.92, -149.533, 81.16428),
(279895, 2, -8825.132, -146.5087, 80.57005),
(279895, 3, -8819.92, -149.533, 81.16428),
(279895, 4, -8816.466, -153.0781, 81.6179);

-- Creature Brother Paxton 951 SAI
SET @ENTRY := 951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 279895, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On Respawn - Self: Start path #279895, walk, repeat, Passive // ");

UPDATE `creature_template` SET `scriptname`= 'npc_injured_stormwind_infantry_dummy', `flags_extra`= 128 WHERE `entry`= 50378; 
DELETE FROM `creature_text` WHERE `CreatureID`= 50378;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(50378, 0, 0, '|cFFFFFF00[Right-Click]|r on Injured Stormwind Infantry that you find in the north field.', 41, 0, 100, 0, 0, 0, 'Dummy - Fear No Evil quest hint', 50117);
