
-- Add Shango Spawn for the quest
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES ('20555656', '28297', '571', '0', '0', '1', '0', '0', '0', '0', '6370.99', '5438.1', '-39.441', '2.48491', '300', '0', '0', '5239', '0', '0', '0', '0', '0', '0', '0', '', '0');

/* QUEST [Ecouter aux portes des trolls] (ID = 24489)
  Les creatures ne parlent pas, donc la quête ne se valide pas.
  Issue ID = 50
*/
-- Soothsayer Shi'kala SAI
SET @ENTRY := 37108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37108,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37108,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,2,37108,0,0,33,37109,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 2 Over - Quest Credit 'Trolling for Information'");


-- Soothsayer Rikkari SAI
SET @ENTRY := 37173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37173,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37173,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,2,37173,0,0,33,37110,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 2 Over - Quest Credit 'Trolling for Information'");

-- Soothsayer Mirim'koa SAI
SET @ENTRY := 37174;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37174,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37174,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,2,37174,0,0,33,37111,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 2 Over - Quest Credit 'Trolling for Information'");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (37108, 37173, 37174);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(37108, 0, 0, 'Da spirits be angry with us.', 12, 0, 100, 0, 0, 0, 36962, 0, 'Soothsayer Shi\'kala'),
(37108, 1, 0, 'I don'' know why the spirits be rejectin'' us so.', 12, 0, 100, 0, 0, 0, 36958, 0, 'Soothsayer Shi\'kala'),
(37108, 2, 0, 'Don'' worry, child.  Grik''nir gonna help us get through this.', 12, 0, 100, 0, 0, 0, 36959, 0, 'Soothsayer Shi\'kala'),
--
(37173, 0, 0, 'What we gon'' do now, you ask?  We wait.', 12, 0, 100, 0, 0, 0, 36957, 0, 'Soothsayer Rikkari'),
(37173, 1, 0, 'Grik''nir says he gon'' talk to the elemental, get it to fight on our side.', 12, 0, 100, 0, 0, 0, 36960, 0, 'Soothsayer Rikkari'),
(37173, 2, 0, 'Soon enough we take over dis valley. Soon enough.', 12, 0, 100, 0, 0, 0, 36961, 0, 'Soothsayer Rikkari'),
--
(37174, 0, 0, 'Our land be a land of ice an'' snow.', 12, 0, 100, 0, 0, 0, 36963, 0, 'Soothsayer Mirim\'koa'),
(37174, 1, 0, 'But beneath the earth, child, there always be fire.', 12, 0, 100, 0, 0, 0, 36964, 0, 'Soothsayer Mirim\'koa'),
(37174, 2, 0, 'De spirit come from deep down to talk with Grik''nir.', 12, 0, 100, 0, 0, 0, 36965, 0, 'Soothsayer Mirim\'koa');
