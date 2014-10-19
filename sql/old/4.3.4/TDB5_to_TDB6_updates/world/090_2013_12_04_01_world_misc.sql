-- Quest 10594 "Gauging the Resonant Frequency"

-- Add creature script
UPDATE creature_template SET ScriptName = 'npc_oscillating_frequency_scanner_master_bunny' WHERE entry=21760;

-- Update triggers
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (21759,21760);

-- Add spell script
DELETE FROM `spell_script_names` WHERE `spell_id`=37408;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(37408, 'spell_oscillating_field');

-- Oscillating Frequency Scanner Top Bunny (Caster) SAI
SET @ENTRY := 21759;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,37418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oscillating Frequency Scanner Top Bunny (Caster) - On Spawn - Cast Top Bunny Beam Test Visual");

-- Condition for spell Top Bunny Beam Test Visual
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=37697;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 37697, 0, 0, 31, 0, 3, 21759, 0, 0, 0, 0, '', 'Top Bunny Beam Test Visual targets Oscillating Frequency Scanner Top Bunny');
