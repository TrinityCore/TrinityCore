-- Gossip Menu Option for Squire David (33447)
SET @SourceGroup = 10340;
SET @SourceEntry = 0; 
SET @ConditionTypeOrReference = 9;

DELETE FROM conditions where SourceGroup=@SourceGroup and SourceEntry=@SourceEntry;
INSERT INTO conditions(SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES 
(15, @SourceGroup, @SourceEntry, 0, 0, @ConditionTypeOrReference, 0, 13679, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest 13679'),
(15, @SourceGroup, @SourceEntry, 0, 1, @ConditionTypeOrReference, 0, 13680, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest 13680');

-- Squire David SAI
SET @ENTRY := 33447;
UPDATE creature_template SET ScriptName="" WHERE entry=33447;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,10340,0,0,0,11,63028,0,0,0,0,0,7,0,0,0,0,0,0,0,"Squire David - On Gossip Option 0 Selected - Cast 'Force Cast'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Squire David - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM `spell_target_position` WHERE `id`=63026;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(63026, 0, 571, 8575.38, 921.85, 547.554, 0.2718);
