-- Sabotage (12676)
SET @ENTRY      := 28780; -- Explosive Charges Bunny
SET @GOB        := 190731; -- Scourgewagon
SET @DETONATE   := 52322; -- Detonate Charges
SET @EX1        := 52325; -- Explode Scourgewagon:Roller
SET @EX2        := 52329; -- Explode Scourgewagon:Frame
SET @EX3        := 52330; -- Explode Scourgewagon:Grill
SET @EX4        := 52332; -- Explode Scourgewagon:Wheel
SET @CREDIT     := 52346; -- Credit

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@DETONATE;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@DETONATE,@EX1,1,'Explode Scourgewagon'),
(@DETONATE,@EX2,1,'Explode Scourgewagon'),
(@DETONATE,@EX3,1,'Explode Scourgewagon'),
(@DETONATE,@EX4,1,'Explode Scourgewagon');

-- Explosive Charges Bunny
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Explosive Charges Bunny - On just summoned - Run script'),
--
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,2000,2000,11,@DETONATE,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Explosive Charges Bunny - On Timed Script - Cast detonate'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,11,@CREDIT,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Explosive Charges Bunny - On Timed Script - Cast credit ');
