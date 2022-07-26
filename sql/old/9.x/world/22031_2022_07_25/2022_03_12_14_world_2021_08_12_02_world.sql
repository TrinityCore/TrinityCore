--
DELETE FROM `spell_script_names` WHERE `spell_id` = 55804 AND `ScriptName` = 'spell_q12937_relief_for_the_fallen';

UPDATE `creature_template` SET `unit_flags2` = 0, `AIName` = "SmartAI", `RegenHealth` = 0 WHERE `entry` = 30035;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30035 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3003500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Managed to catch this in sniff, always changes HP to 30%
(30035,0,0,0,11,0,100,0,0,0,0,0,0,11,22269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Spawn - Cast 'Injured'"),
(30035,0,1,0,8,0,100,1,55804,0,0,0,0,80,3003500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Spellhit 'Healing Finished' - Run Script (No Repeat)"),

(3003500,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Set Orientation Invoker"),
(3003500,9,1,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Remove Flag Standstate Dead"),
(3003500,9,2,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Remove Flag Standstate Kneel"),
(3003500,9,3,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Set Emote State 0"),
(3003500,9,4,0,0,0,100,0,2000,2000,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Say Line 0"),
(3003500,9,5,0,0,0,100,0,3000,3000,0,0,0,11,55809,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Cast 'Trigger Aid of the Earthen'"),
(3003500,9,6,0,0,0,100,0,0,0,0,0,0,33,30035,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Quest Credit 'Relief for the Fallen'"),
(3003500,9,7,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fallen Earthen Defender - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 30035;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(30035,0,0,"Thank you. I thought I was doomed.",12,0,100,2,0,0,30720,0,"Fallen Earthen Defender"),
(30035,0,1,"I was certain I was going to die out here.",12,0,100,2,0,0,30721,0,"Fallen Earthen Defender"),
(30035,0,2,"Let me fight by your side.",12,0,100,2,0,0,30722,0,"Fallen Earthen Defender"),
(30035,0,3,"Let us fight the irons together!",12,0,100,2,0,0,30723,0,"Fallen Earthen Defender");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 30036;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30036 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Always after 30 sec
(30036,0,0,0,63,0,100,0,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rejuvenated Defender - On Just Created - Delayed Despawn"),
-- Not sure if should be repeatable or be used on range
(30036,0,1,0,4,0,100,0,0,0,0,0,0,11,55770,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Rejuvenated Defender - On Aggro - Cast 'Earthen - Boulder Rush'");

DELETE FROM `spell_scripts` WHERE `id` = 55770;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(55770,0,0,15,55771,0,0,0,0,0,0,"Earthen - Boulder Rush - On Effect Hit (Script Effect) - Cast 'Earthen - Boulder Rush (Charge)'");

-- Sniffed time
-- Like before, we don't want any system to affect static timer
DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` IN (SELECT `guid` FROM `creature` WHERE `id` = 30035);
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 30035;
