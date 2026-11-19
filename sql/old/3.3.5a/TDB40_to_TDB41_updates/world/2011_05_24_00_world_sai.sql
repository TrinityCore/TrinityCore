SET @ENTRY := 27853;
SET @GUID := 115101;

-- Remove old EAI and replace with proper SAI
DELETE FROM `creature_ai_scripts` WHERE `id`=2785301;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,-109577,-109576,-109573);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,3000,3000,3000,11,49731,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Projections and Plans Kill Credit Bunny - OOC - Cast Projections and Plans: Kill Credit on self'),
(-109577,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,@GUID,@ENTRY,0,0,0,0,0, 'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-109577,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim'),
(-109576,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,@GUID,@ENTRY,0,0,0,0,0, 'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-109576,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim'),
(-109573,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,@GUID,@ENTRY,0,0,0,0,0, 'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-109573,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim');
