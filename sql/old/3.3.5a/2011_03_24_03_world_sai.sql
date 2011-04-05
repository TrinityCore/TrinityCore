-- Scourge Deathspeaker SAI 
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=27615;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=27615;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27615;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27615,0,0,1,1,0,100,1,1000,1000,1000,1000,11,49119,2,0,0,0,0,10,101497,27452,0,0,0,0,0,'Scourge Deathspeaker - Spawn & reset - channel Fire Beam'),
(27615,0,1,0,61,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Deathspeaker - Spawn & reset - Prevent Combat Movement'),
(27615,0,2,3,4,0,100,1,0,0,0,0,11,52282,2,0,0,0,0,2,0,0,0,0,0,0,0,'Scourge Deathspeaker - On aggro - Cast Fireball'),
(27615,0,3,0,61,0,100,1,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - On aggro - Set phase 1'),
(27615,0,4,0,9,1,100,0,3000,3000,3400,4800,11,52282,1,0,0,0,0,2,0,0,0,0,0,0,0,'Scourge Deathspeaker - in combat - Cast Fireball (phase 1)'),
(27615,0,5,0,9,1,100,0,35,80,1000,1000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 35 Yards - Start Combat Movement (phase 1)'),
(27615,0,6,0,9,1,100,0,5,15,1000,1000,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 15 Yards - Prevent Combat Movement (phase 1)'),
(27615,0,7,0,9,1,100,0,0,5,1000,1000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Deathspeaker - Below 5 Yards - Start Combat Movement (phase 1)'),
(27615,0,8,0,3,1,100,1,0,7,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - Mana at 7% - Set Phase 2 (phase 1)'),
(27615,0,9,0,0,2,100,1,0,0,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - In combat - Allow Combat Movement (phase 2)'),
(27615,0,10,0,3,2,100,1,15,100,100,100,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - Mana above 15% - Set Phase 1 (phase 2)'),
(27615,0,11,0,2,0,100,1,0,30,120000,130000,11,52281,0,0,0,0,0,2,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 15% HP - Cast Flame of the Seer'),
(27615,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 15% HP - Set Phase 3'),
(27615,0,13,0,2,4,100,1,0,15,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 15% HP - Allow Combat Movement (phase 3)'),
(27615,0,14,15,2,4,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Scourge Deathspeaker - At 15% HP - Flee (phase 3)'),
(27615,0,15,0,61,4,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scourge Deathspeaker - At 15% HP - Say text0 (Phase 3)');

-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry` IN (27615);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27615,0,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'Scourge Deathspeaker');

-- SET InhabitType for Invisible Stalker Grizzly Hills
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=27452;

-- SAI for Dark Conclave Ritualist
SET @ENTRY := 22138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,38469,0,0,0,0,0,19,22139,0,0,0,0,0,0,'Dark Conclave Ritualist - OOC - Dark Conclave Ritualist Channel');

-- Shattered Sun Marksman fixup (tested) 
-- Console no longer spamming waypoint script errors in The Dawning Square
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=24938;
-- Shattered Sun Marksman shoot at Bridge Marksman Target Dummy SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-65694,-65695,-65696,-65697,-65698,-65699,-65700,-65702);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-65694,0,0,0,1,0,100,0,5000,5000,5000,7000,11,45223,0,0,0,0,0,10,62844,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65695,0,0,0,1,0,100,0,2000,2000,5000,7000,11,45223,0,0,0,0,0,10,62844,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65696,0,0,0,1,0,100,0,3000,3000,5000,7000,11,45223,0,0,0,0,0,10,62843,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65697,0,0,0,1,0,100,0,6000,6000,5000,7000,11,45223,0,0,0,0,0,10,62843,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65698,0,0,0,1,0,100,0,2000,2000,5000,7000,11,45223,0,0,0,0,0,10,59515,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65699,0,0,0,1,0,100,0,5000,5000,5000,7000,11,45223,0,0,0,0,0,10,62841,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65700,0,0,0,1,0,100,0,1000,1000,5000,7000,11,45223,0,0,0,0,0,10,62842,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger'),
(-65702,0,0,0,1,0,100,0,5000,5000,5000,7000,11,45223,0,0,0,0,0,10,59473,25192,0,0,0,0,0,'Shattered Sun Marksman - OOC 5-7 sec - Shoot at trigger');
-- Remove path data and scripts from Shattered Sun Marksman
DELETE FROM `waypoint_data` WHERE `id` IN (656940,656950,656960,656970,656980,656990,657000,657020);
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 80 AND 111;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (65694,65695,65696,65697,65698,65699,65700,65702);
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (65694,65695,65696,65697,65698,65699,65700,65702);

-- Fix Spell condition for Spell 45223 to target Bridge Marksman Target Dummy 25192 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45223;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,45223,0,18,1,25192,0,0,'','Spell 45223 targets Bridge Marksman Target Dummy');
