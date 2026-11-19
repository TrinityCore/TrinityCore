-- SAI for Erich Lohan
SET @ENTRY=3627;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Erich Lohan - OOC - Say random text');
-- Talk text from sniff
DELETE FROM `creature_text` WHERE `entry`=3627;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(3627,0,0, 'Magical studies stressing your brain? Relax at the Blue Recluse!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,1, 'Best drinks in Stormwind!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,2, 'Come for the beer, stay for the atmosphere!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,3, 'The only place in Stormwind where magic and spirits mix, come to the Blue Recluse!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,4, 'Free drinks at the Blue Recluse!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,5, 'Feeling blue? Come on down to the Blue Recluse for a good time!',12,7,100,0,0,0, 'Erich Lohan'),
(3627,0,6, 'Head on over to the Blue Recluse. Where everybody knows your name!',12,7,100,0,0,0, 'Erich Lohan');
-- Remove old waypoint text
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=904450;
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 432 AND 446;
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000005185 AND 2000005199;
