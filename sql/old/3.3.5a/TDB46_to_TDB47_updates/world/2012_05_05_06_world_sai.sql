-- Wrathbone Laborer SAI
SET @ENTRY   := 36830; -- NPC entry
SET @SPELL1  := 70302; -- Blinding Dirt
SET @SPELL2  := 70278; -- Puncture Wound
SET @SPELL3  := 69572; -- Shovelled!
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256,`AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,8000,10000,11000,11,@SPELL1,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Blinding Dirt'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,9000,10000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Puncture Wound (Normal)'),
(@ENTRY,0,2,0,0,0,100,6,5000,6000,7000,8000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Shovelled! (Normal)'),
(@ENTRY,0,3,0,1,0,100,6,1000,3000,3000,3000,5,38,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wrathbone Laborer - OOC - emote');
