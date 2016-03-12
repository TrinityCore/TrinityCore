SET @GUID   := 143894; 

DELETE FROM `disables` WHERE `entry` = 7180 AND `sourceType` = 4;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(27737);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(27737) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN -@GUID-89 AND -@GUID-0 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-@GUID-0, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-0, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-0, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-0, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-1, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-1, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-1, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-1, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-2, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-2, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-2, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-2, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-3, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-3, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-3, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-3, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-4, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-4, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-4, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-4, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-5, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-5, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-5, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-5, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-6, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-6, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-6, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-6, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-7, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-7, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-7, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-7, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-8, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-8, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-8, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-8, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-9, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-9, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-9, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-9, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-10, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-10, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-10, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-10, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-11, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-11, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-11, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-11, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-12, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-12, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-12, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-12, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-13, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-13, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-13, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-13, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-14, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-14, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-14, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-14, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-15, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-15, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-15, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-15, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-16, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-16, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-16, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-16, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-17, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-17, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-17, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-17, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-18, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-18, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-18, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-18, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-19, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-19, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-19, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-19, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-20, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-20, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-20, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-20, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-21, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-21, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-21, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-21, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-22, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-22, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-22, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-22, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-23, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-23, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-23, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-23, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-24, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-24, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-24, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-24, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-25, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-25, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-25, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-25, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-26, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-26, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-26, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-26, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-27, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-27, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-27, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-27, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-28, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-28, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-28, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-28, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-29, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-29, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-29, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-29, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-30, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-30, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-30, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-30, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-31, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-31, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-31, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-31, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-32, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-32, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-32, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-32, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-33, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-33, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-33, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-33, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-34, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-34, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-34, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-34, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-35, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-35, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-35, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-35, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-36, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-36, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-36, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-36, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-37, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-37, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-37, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-37, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-38, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-38, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-38, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-38, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-39, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-39, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-39, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-39, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-40, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-40, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-40, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-40, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-41, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-41, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-41, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-41, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-42, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-42, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-42, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-42, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-43, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-43, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-43, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-43, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-44, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-44, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-44, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-44, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-45, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-45, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-45, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-45, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-46, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-46, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-46, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-46, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-47, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-47, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-47, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-47, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-48, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-48, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-48, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-48, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-49, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-49, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-49, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-49, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-50, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-50, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-50, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-50, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-51, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-51, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-51, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-51, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-52, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-52, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-52, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-52, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-53, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-53, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-53, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-53, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-54, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-54, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-54, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-54, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-59, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-59, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-59, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-59, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-60, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-60, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-60, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-60, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-61, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-61, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-61, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-61, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-62, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-62, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-62, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-62, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-63, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-63, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-63, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-63, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-64, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-64, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-64, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-64, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-65, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-65, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-65, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-65, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-66, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-66, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-66, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-66, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-67, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-67, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-67, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-67, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-68, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-68, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-68, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-68, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-69, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-69, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-69, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-69, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-70, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-70, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-70, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-70, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-71, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-71, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-71, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-71, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-72, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-72, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-72, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-72, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-73, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-73, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-73, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-73, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-74, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-74, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-74, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-74, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-75, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-75, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-75, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-75, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-76, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-76, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-76, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-76, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-77, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-77, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-77, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-77, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-78, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-78, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-78, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-78, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-79, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-79, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-79, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-79, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-80, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-80, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-80, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-80, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-81, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-81, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-81, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-81, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-82, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-82, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-82, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-82, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-83, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-83, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-83, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-83, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-84, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-84, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-84, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-84, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-85, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-85, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-85, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-85, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-86, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-86, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-86, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-86, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-87, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-87, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-87, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-87, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-88, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-88, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-88, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-88, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-89, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Remove Unit Flags (No repeat)'),
(-@GUID-89, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)'),
(-@GUID-89, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - On Spawn - Set Unit Flags (No repeat)'),
(-@GUID-89, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Zombie - OOC - Set Visible (No repeat)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` BETWEEN -@GUID-89 AND -@GUID-0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, -@GUID-0, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-0, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-1, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-1, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-2, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-2, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-3, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-3, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-4, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-4, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-5, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-5, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-6, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-6, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-7, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-7, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-8, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-8, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-9, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-9, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-10, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-10, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-11, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-11, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-12, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-12, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-13, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-13, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-14, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-14, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-15, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-15, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-16, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-16, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-17, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-17, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-18, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-18, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-19, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-19, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-20, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-20, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-21, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-21, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-22, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-22, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-23, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-23, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-24, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-24, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-25, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-25, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-26, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-26, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-27, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-27, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-28, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-28, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-29, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-29, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-30, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-30, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-31, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-31, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-32, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-32, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-33, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-33, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-34, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-34, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-35, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-35, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-36, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-36, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-37, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-37, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-38, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-38, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-39, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-39, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-40, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-40, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-41, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-41, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-42, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-42, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-43, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-43, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-44, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-44, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-45, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-45, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-46, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-46, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-47, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-47, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-48, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-48, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-49, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-49, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-50, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-50, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-51, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-51, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-52, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-52, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-53, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-53, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-54, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-54, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-59, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-59, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-60, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-60, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-61, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-61, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-62, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-62, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-63, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-63, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-64, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-64, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-65, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-65, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-66, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-66, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-67, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-67, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-68, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-68, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-69, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-69, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-70, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-70, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-71, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-71, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-72, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-72, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-73, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-73, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-74, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-74, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-75, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-75, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-76, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-76, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-77, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-77, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-78, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-78, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-79, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-79, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-80, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-80, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-81, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-81, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-82, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-82, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-83, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-83, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-84, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-84, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-85, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-85, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-86, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-86, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-87, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-87, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-88, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-88, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done'),
(22, 1, -@GUID-89, 0, 0, 13, 1, 0, 1, 2, 0, 0, 0, '', 'Execute SAI only if Arthas Started'),
(22, 1, -@GUID-89, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Execute SAI only if Salramm not done');


DELETE FROM `creature` WHERE `id` IN(27737,27731);-- 55 - 58
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- 1st Half
(@GUID+0, 27737, 595, 3, 1, 2161.82, 1354.491, 131.1483, 2.331408, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+1, 27737, 595, 3, 1, 2236.563, 1186.729, 136.1916, 4.947702, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+2, 27737, 595, 3, 1, 2182.118, 1267.972, 133.9415, 2.251475, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+3, 27737, 595, 3, 1, 2180.779, 1249.29, 136.1283, 2.05123, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+4, 27737, 595, 3, 1, 2256.721, 1159.953, 138.1671, 0.2378878, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+5, 27737, 595, 3, 1, 2178.129, 1342.832, 130.0959, 2.633242, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+6, 27737, 595, 3, 1, 2184.672, 1283.357, 134.2776, 5.951573, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+7, 27737, 595, 3, 1, 2182.101, 1349.334, 130.5124, 0.9876914, 240, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+8, 27737, 595, 3, 1, 2346.691, 1176.774, 130.5827, 2.633849, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+9, 27737, 595, 3, 1, 2317.5, 1182.395, 134.5855, 0.2704094, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+10, 27737, 595, 3, 1, 2342.65, 1201.867, 130.8089, 5.009095, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+11, 27737, 595, 3, 1, 2204.984, 1335.487, 129.7152, 5.232573, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+12, 27737, 595, 3, 1, 2235.223, 1169.072, 137.4158, 1.448623, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+13, 27737, 595, 3, 1, 2159.948, 1260.771, 134.5026, 0.2792527, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+14, 27737, 595, 3, 1, 2290.749, 1180.91, 137.9212, 3.518519, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+15, 27737, 595, 3, 1, 2140.347, 1343.273, 132.1016, 1.710423, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+16, 27737, 595, 3, 1, 2308.356, 1170.963, 136.3496, 6.255137, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+17, 27737, 595, 3, 1, 2186.262, 1322.747, 129.9056, 3.620198, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+18, 27737, 595, 3, 1, 2147.991, 1358.539, 132.3033, 3.856933, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+19, 27737, 595, 3, 1, 2182.792, 1293.969, 133.0651, 0.05565223, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+20, 27737, 595, 3, 1, 2216.737, 1197.397, 136.0267, 1.573244, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+21, 27737, 595, 3, 1, 2267.147, 1175.45, 137.9304, 5.129838, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+22, 27737, 595, 3, 1, 2170.33, 1308.926, 132.1849, 3.249883, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+23, 27737, 595, 3, 1, 2166.907, 1260.357, 133.9678, 1.839856, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+24, 27737, 595, 3, 1, 2162.47, 1298.826, 133.6364, 4.921828, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+25, 27737, 595, 3, 1, 2250.398, 1178.572, 137.4704, 6.230714, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+26, 27737, 595, 3, 1, 2168.266, 1285.917, 133.0716, 0.3473166, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+27, 27737, 595, 3, 1, 2162.47, 1298.826, 133.6364, 4.921828, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+28, 27737, 595, 3, 1, 2156.109, 1350.486, 131.7296, 3.737586, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+29, 27737, 595, 3, 1, 2177.279, 1286.727, 133.2539, 1.043647, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+30, 27737, 595, 3, 1, 2163.427, 1275.624, 133.6055, 2.009026, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+31, 27737, 595, 3, 1, 2207.282, 1326.216, 129.5644, 1.15092, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+32, 27737, 595, 3, 1, 2197.55, 1343.202, 130.5129, 3.780437, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+33, 27737, 595, 3, 1, 2187.311, 1333.527, 130.1098, 5.819355, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+34, 27737, 595, 3, 1, 2198.283, 1323.173, 130.42, 3.730995, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+35, 27737, 595, 3, 1, 2166.612, 1293.848, 133.2112, 3.054326, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+36, 27737, 595, 3, 1, 2180.712, 1305.788, 131.7394, 3.38325, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+37, 27737, 595, 3, 1, 2134.044, 1359.902, 132.1847, 1.668735, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+38, 27737, 595, 3, 1, 2177.545, 1257.854, 135.0027, 0.02948252, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+39, 27737, 595, 3, 1, 2172.916, 1345.946, 130.3247, 0.3643927, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+40, 27737, 595, 3, 1, 2170.042, 1244.831, 136.1126, 4.301986, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+41, 27737, 595, 3, 1, 2144.03, 1282.192, 134.9001, 6.184534, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+42, 27737, 595, 3, 1, 2127.322, 1343.184, 131.1696, 0.8850852, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+43, 27737, 595, 3, 1, 2173.298, 1327.852, 130.4678, 4.017004, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+44, 27737, 595, 3, 1, 2345.861, 1199.473, 130.6499, 1.27409, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+45, 27737, 595, 3, 1, 2221.904, 1186.763, 135.7659, 2.080931, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+46, 27737, 595, 3, 1, 2324.541, 1174.526, 133.7252, 5.438884, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+47, 27737, 595, 3, 1, 2352.759, 1187.038, 130.4972, 2.111265, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+48, 27737, 595, 3, 1, 2241.31, 1168.949, 137.4646, 2.288553, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+49, 27737, 595, 3, 1, 2277.496, 1175.328, 137.7658, 4.471868, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+50, 27737, 595, 3, 1, 2240.862, 1183.754, 136.7626, 1.269583, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+51, 27737, 595, 3, 1, 2215.602, 1198.933, 136.0747, 3.191143, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+52, 27737, 595, 3, 1, 2253.736, 1173.219, 138.1033, 3.833174, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+53, 27737, 595, 3, 1, 2301.188, 1177.337, 136.9212, 0.4530731, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+54, 27737, 595, 3, 1, 2256.917, 1158.745, 138.2293, 3.033373, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+55, 27731, 595, 3, 1, 2256.084, 1157.831, 138.2716, 1.364949, 240, 5, 1), -- 27731 (Area: 4100) 1
(@GUID+56, 27731, 595, 3, 1, 2253.797, 1169.233, 138.2792, 1.436542, 240, 5, 1), -- 27731 (Area: 4100) 1
(@GUID+57, 27731, 595, 3, 1, 2257.816, 1162.377, 138.0986, 0.9713849, 240, 5, 1), -- 27731 (Area: 4100) 1
(@GUID+58, 27731, 595, 3, 1, 2262.165, 1166.002, 138.1224, 1.240342, 240, 5, 1), -- 27731 (Area: 4100) 1
(@GUID+59, 27737, 595, 3, 1, 2281.302, 1141.813, 137.9214, 5.003052, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+60, 27737, 595, 3, 1, 2250.17, 1166.411, 138.147, 0.3446127, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+61, 27737, 595, 3, 1, 2228.241, 1176.167, 136.5662, 5.933817, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+62, 27737, 595, 3, 1, 2300.582, 1183.189, 137.4008, 0.9829545, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+63, 27737, 595, 3, 1, 2260.475, 1178.165, 138.4617, 1.953951, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+64, 27737, 595, 3, 1, 2314.233, 1173.99, 135.4144, 3.033998, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+65, 27737, 595, 3, 1, 2330.992, 1179.689, 131.6598, 0.2531269, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+66, 27737, 595, 3, 1, 2285.286, 1176.464, 137.7416, 4.279643, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+67, 27737, 595, 3, 1, 2226.437, 1192.199, 135.8167, 1.753368, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+68, 27737, 595, 3, 1, 2354.042, 1179.965, 130.7275, 1.108088, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+69, 27737, 595, 3, 1, 2242.06, 1175.723, 137.1995, 6.210336, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+70, 27737, 595, 3, 1, 2346.105, 1194.632, 130.6152, 1.745329, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+71, 27737, 595, 3, 1, 2186.328, 1311.786, 130.9303, 4.978087, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+72, 27737, 595, 3, 1, 2115.17, 1363.209, 131.0886, 3.417473, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+73, 27737, 595, 3, 1, 2171.35, 1317.278, 131.321, 2.759058, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+74, 27737, 595, 3, 1, 2159.191, 1349.993, 131.5126, 3.911789, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+75, 27737, 595, 3, 1, 2141.456, 1363.355, 132.3215, 1.991677, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+76, 27737, 595, 3, 1, 2183.169, 1328.252, 129.9512, 5.934655, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+77, 27737, 595, 3, 1, 2183.9, 1300.783, 132.3583, 2.234651, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+78, 27737, 595, 3, 1, 2194.571, 1332.426, 129.9806, 2.67068, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+79, 27737, 595, 3, 1, 2169.268, 1278.101, 133.2, 4.272601, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+80, 27737, 595, 3, 1, 2163.175, 1357.961, 131.71, 3.281193, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+81, 27737, 595, 3, 1, 2115.964, 1345.561, 131.5159, 5.410521, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+82, 27737, 595, 3, 1, 2171.605, 1335.377, 130.2321, 3.992525, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+83, 27737, 595, 3, 1, 2126.402, 1362.936, 131.2733, 3.310562, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+84, 27737, 595, 3, 1, 2173.577, 1264.115, 133.8741, 1.023024, 240, 5, 1), -- 27737 (Area: 4100) 1
(@GUID+85, 27737, 595, 3, 1, 2208.027, 1335.281, 129.5424, 1.518706, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+86, 27737, 595, 3, 1, 2171.453, 1301.018, 132.7366, 0.2901765, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+87, 27737, 595, 3, 1, 2169.414, 1250.857, 135.2106, 2.8393, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+88, 27737, 595, 3, 1, 2132.141, 1346.274, 131.2455, 2.690396, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
(@GUID+89, 27737, 595, 3, 1, 2158.416, 1280.064, 133.8115, 5.935702, 240, 5, 1), -- 27737 (Area: 4100) (Auras: ) 1
-- Second Half
(@GUID+90, 27731, 595, 3, 1, 2500.738, 1360.329, 131.1847, 1.937315, 120, 5, 1), -- 27731 (Area: 4100)
(@GUID+91, 27737, 595, 3, 1, 2564.911, 1178.225, 126.5099, 0.715585, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+92, 27731, 595, 3, 1, 2572.829, 1156.034, 126.4628, 2.289771, 120, 5, 1), -- 27731 (Area: 4100) (Auras: )
(@GUID+93, 27737, 595, 3, 1, 2546.042, 1227.147, 127.048, 2.86234, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+94, 27737, 595, 3, 1, 2549.196, 1213.742, 127.6477, 5.201081, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+95, 27737, 595, 3, 1, 2574.684, 1153.874, 126.5534, 5.009095, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+96, 27737, 595, 3, 1, 2565.958, 1167.619, 127.0209, 2.356194, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+97, 27737, 595, 3, 1, 2558.278, 1169.111, 128.0473, 4.29351, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+98, 27737, 595, 3, 1, 2534.67, 1255.3, 127.0307, 3.926991, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+99, 27737, 595, 3, 1, 2551.866, 1232.249, 125.6097, 2.635447, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+100, 27737, 595, 3, 1, 2559.216, 1178.839, 127.2618, 3.089233, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+101, 27737, 595, 3, 1, 2533.401, 1263.405, 127.5351, 3.926991, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+102, 27731, 595, 3, 1, 2574.436, 1155.751, 126.4111, 3.559219, 120, 5, 1), -- 27731 (Area: 4100) (Auras: )
(@GUID+103, 27737, 595, 3, 1, 2564.436, 1152.985, 127.6109, 4.642576, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+104, 27737, 595, 3, 1, 2510.611, 1279.379, 129.8318, 1.570796, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+105, 27737, 595, 3, 1, 2558.396, 1221.108, 125.4641, 3.438299, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+106, 27737, 595, 3, 1, 2547.228, 1241.545, 125.8737, 4.415683, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+107, 27737, 595, 3, 1, 2556.666, 1234.75, 125.8504, 0.4363323, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+108, 27737, 595, 3, 1, 2558.199, 1195.568, 126.8055, 4.380776, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+109, 27737, 595, 3, 1, 2561.93, 1157.015, 127.7777, 1.832596, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+110, 27731, 595, 3, 1, 2573.595, 1157.235, 126.3465, 1.509647, 120, 5, 1), -- 27731 (Area: 4100) (Auras: )
(@GUID+111, 27737, 595, 3, 1, 2556.297, 1145.754, 129.0501, 3.106686, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+112, 27737, 595, 3, 1, 2569.254, 1205.719, 125.4004, 5.002082, 120, 5, 1), -- 27737 (Area: 4100) (Auras: 42726 - 42726)
(@GUID+113, 27737, 595, 3, 1, 2572.153, 1146.823, 126.8599, 2.70526, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+114, 27737, 595, 3, 1, 2538.41, 1241.072, 126.9086, 4.886922, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+115, 27731, 595, 3, 1, 2500.738, 1360.329, 131.1847, 2.409203, 120, 5, 1), -- 27731 (Area: 4100) (Auras: ) (possible waypoints or random movement)
(@GUID+116, 27737, 595, 3, 1, 2469.409, 1391.765, 129.9645, 0.01745329, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+117, 27737, 595, 3, 1, 2480.067, 1378.496, 129.6512, 5.951573, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+118, 27737, 595, 3, 1, 2496.575, 1365.8, 130.7648, 3.263766, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+119, 27737, 595, 3, 1, 2507.699, 1291.871, 131.0477, 4.13643, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+120, 27737, 595, 3, 1, 2520.572, 1286.806, 129.7177, 2.146755, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+121, 27737, 595, 3, 1, 2478.782, 1393.61, 130.0417, 5.253441, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+122, 27737, 595, 3, 1, 2502.809, 1348.058, 133.0128, 2.844887, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+123, 27737, 595, 3, 1, 2492.209, 1383.335, 130.4428, 5.969026, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+124, 27731, 595, 3, 1, 2498.377, 1361.939, 131.0246, 2.017789, 120, 5, 1), -- 27731 (Area: 4100) (Auras: ) (possible waypoints or random movement)
(@GUID+125, 27737, 595, 3, 1, 2465.855, 1409.319, 130.7084, 1.658063, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+126, 27731, 595, 3, 1, 2497.87, 1359.616, 131.4152, 2.273972, 120, 5, 1), -- 27731 (Area: 4100) (Auras: ) (possible waypoints or random movement)
(@GUID+127, 27737, 595, 3, 1, 2567.898, 1195.905, 125.7625, 4.764749, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+128, 27737, 595, 3, 1, 2539.281, 1259.073, 126.4106, 0.8726646, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+129, 27737, 595, 3, 1, 2550.405, 1221.265, 126.6349, 5.502605, 120, 5, 1), -- 27737 (Area: 4100) (Auras: 42726 - 42726)
(@GUID+130, 27737, 595, 3, 1, 2561.143, 1165.518, 127.7086, 4.921828, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+131, 27737, 595, 3, 1, 2570.456, 1166.24, 126.5573, 3.787364, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+132, 27737, 595, 3, 1, 2523.198, 1270.922, 128.7036, 2.007129, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+133, 27737, 595, 3, 1, 2565.553, 1148.601, 127.6903, 2.670354, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+134, 27737, 595, 3, 1, 2569.308, 1188.428, 125.8085, 4.485496, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+135, 27737, 595, 3, 1, 2571.416, 1161.062, 126.5842, 2.949606, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+136, 27737, 595, 3, 1, 2561.565, 1211.34, 125.4866, 0.1047198, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+137, 27737, 595, 3, 1, 2540.505, 1247.505, 126.4913, 0.9250245, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+138, 27737, 595, 3, 1, 2545.149, 1252.06, 126.2658, 0.2443461, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+139, 27737, 595, 3, 1, 2551.554, 1239.584, 125.4468, 4.590216, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+140, 27737, 595, 3, 1, 2550.498, 1247.44, 125.5242, 4.24115, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+141, 27737, 595, 3, 1, 2555.76, 1206.637, 126.8258, 1.762783, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+142, 27737, 595, 3, 1, 2570.634, 1178.631, 125.9873, 2.670354, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+143, 27737, 595, 3, 1, 2544.546, 1233.477, 126.8366, 0.2617994, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+144, 27737, 595, 3, 1, 2561.324, 1186.026, 126.4857, 3.996804, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+145, 27737, 595, 3, 1, 2571.687, 1164.973, 126.3542, 2.063297, 120, 5, 1), -- 27737 (Area: 4100) (Auras: 42726 - 42726)
(@GUID+146, 27737, 595, 3, 1, 2563.486, 1192.775, 126.1027, 2.111848, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+147, 27737, 595, 3, 1, 2563.203, 1203.705, 125.7591, 6.265732, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+148, 27737, 595, 3, 1, 2574.435, 1170.58, 126.0365, 4.13643, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+149, 27737, 595, 3, 1, 2519.148, 1282.076, 129.3335, 1.675516, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+150, 27737, 595, 3, 1, 2487.284, 1355.895, 132.0378, 5.166174, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+151, 27737, 595, 3, 1, 2486.355, 1381.331, 130.2177, 0.8377581, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+152, 27737, 595, 3, 1, 2537.23, 1274.154, 127.247, 5.201081, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+153, 27737, 595, 3, 1, 2482.333, 1378.755, 129.8668, 4.445682, 120, 5, 1), -- 27737 (Area: 4100) (Auras: 42726 - 42726)
(@GUID+154, 27737, 595, 3, 1, 2514.438, 1294.972, 130.8045, 4.537856, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+155, 27737, 595, 3, 1, 2495.49, 1351.598, 132.5921, 5.899213, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+156, 27737, 595, 3, 1, 2527.383, 1289.23, 129.802, 0.6457718, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+157, 27737, 595, 3, 1, 2488.743, 1364.121, 130.6187, 0.9599311, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+158, 27737, 595, 3, 1, 2492.943, 1370.252, 130.7567, 4.747295, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+159, 27737, 595, 3, 1, 2527.926, 1279.266, 128.2349, 2.111848, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+160, 27737, 595, 3, 1, 2512.307, 1285.777, 130.3244, 1.361357, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+161, 27737, 595, 3, 1, 2501.182, 1354.545, 132.4567, 2.635447, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+162, 27737, 595, 3, 1, 2528.756, 1270.082, 128.0023, 2.722714, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+163, 27737, 595, 3, 1, 2534.166, 1281.988, 128.3769, 1.22173, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+164, 27737, 595, 3, 1, 2478.309, 1366.715, 130.1298, 3.036873, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+165, 27737, 595, 3, 1, 2518.97, 1276.149, 128.4369, 0.6981317, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+166, 27737, 595, 3, 1, 2539.054, 1267.989, 126.5578, 5.026548, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+167, 27737, 595, 3, 1, 2546.093, 1260.12, 126.4856, 5.113815, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+168, 27737, 595, 3, 1, 2494.707, 1357.887, 131.7789, 5.410521, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+169, 27737, 595, 3, 1, 2520.985, 1296.503, 130.6993, 1.134464, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+170, 27737, 595, 3, 1, 2483.547, 1369.328, 129.7479, 0.3141593, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+171, 27737, 595, 3, 1, 2461.695, 1405.834, 130.6046, 2.321288, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+172, 27737, 595, 3, 1, 2485.281, 1401.199, 130.993, 0.926355, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+173, 27737, 595, 3, 1, 2480.869, 1387.697, 129.9826, 1.989675, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+174, 27737, 595, 3, 1, 2484.152, 1391.818, 130.3346, 1.832596, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+175, 27737, 595, 3, 1, 2474.796, 1386.799, 129.2887, 4.18879, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+176, 27737, 595, 3, 1, 2474.894, 1398.443, 130.355, 1.780236, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+177, 27737, 595, 3, 1, 2470.626, 1403.028, 130.578, 4.223697, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+178, 27737, 595, 3, 1, 2469.058, 1411.237, 131.0699, 4.782202, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+179, 27737, 595, 3, 1, 2496.014, 1388.685, 131.2523, 3.263766, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+180, 27737, 595, 3, 1, 2463.726, 1416.033, 130.9224, 4.502949, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+181, 27737, 595, 3, 1, 2457.688, 1415.661, 130.2885, 1.343904, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+182, 27737, 595, 3, 1, 2445.796, 1420.992, 130.3097, 1.780236, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+183, 27737, 595, 3, 1, 2461.943, 1422.238, 130.9959, 5.480334, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+184, 27737, 595, 3, 1, 2437.17, 1420.377, 130.4104, 3.874631, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+185, 27737, 595, 3, 1, 2467.397, 1419.898, 131.3669, 6.178465, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+186, 27737, 595, 3, 1, 2427.73, 1416.372, 130.616, 1.343904, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+187, 27737, 595, 3, 1, 2453.945, 1422.732, 130.7179, 2.548181, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+188, 27737, 595, 3, 1, 2433.062, 1428.894, 131.3722, 4.118977, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+189, 27737, 595, 3, 1, 2446.571, 1428.854, 131.1397, 4.625123, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+190, 27737, 595, 3, 1, 2454.021, 1429.103, 131.2739, 0.2792527, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+191, 27737, 595, 3, 1, 2455.682, 1435.659, 131.8695, 4.066617, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+192, 27737, 595, 3, 1, 2427.347, 1424.508, 131.1206, 3.700098, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+193, 27737, 595, 3, 1, 2461.234, 1428.908, 131.2317, 0.418879, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+194, 27737, 595, 3, 1, 2464.28, 1425.138, 131.1465, 4.939282, 120, 5, 1), -- 27737 (Area: 4100)
(@GUID+195, 27737, 595, 3, 1, 2439.296, 1427.013, 130.9965, 0.2268928, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+196, 27737, 595, 3, 1, 2442.111, 1435.992, 131.7104, 4.13643, 120, 5, 1), -- 27737 (Area: 4100) (Auras: )
(@GUID+197, 27731, 595, 3, 1, 2577.112, 1156.938, 126.5042, 1.466077, 120, 5, 1), -- 27731 (Area: 4100)
(@GUID+198, 27731, 595, 3, 1, 2573.414, 1154.276, 126.5274, 0.4363323, 120, 5, 1), -- 27731 (Area: 4100)
(@GUID+199, 27731, 595, 3, 1, 2575.825, 1152.61, 126.6092, 0.3490658, 120, 5, 1), -- 27731 (Area: 4100)
(@GUID+200, 27731, 595, 3, 1, 2497.87, 1359.616, 131.4152, 1.396263, 120, 5, 1), -- 27731 (Area: 4100)
(@GUID+201, 27731, 595, 3, 1, 2498.424, 1361.842, 131.0335, 1.082104, 120, 5, 1); -- 27731 (Area: 4100)
