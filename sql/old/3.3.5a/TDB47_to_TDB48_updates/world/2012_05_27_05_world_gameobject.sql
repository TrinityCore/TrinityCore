-- [QUEST] Attunement to Dalaran
SET @GUID := 320;
-- Adds the gameobject to recognize the zone
DELETE FROM `gameobject` WHERE `id`=300193;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES
(@GUID,300193,571,1,1,3343.8,2502.85,-15.1381,5.74342,0,0,0.266617,-0.963802,300,0,1);
-- [SAI] NPC Attunement To Dalaran Kill Credit Bunny 27135
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27135;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27135 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
(27135,0,0,0,8,0,100,1,48021,1,0,0,33,27135,0,0,0,0,0,7,0,0,0,0,0,0,0, 'On spellhit - give kill credit - Attunement to Dalaran Kill Credit Bunny');
