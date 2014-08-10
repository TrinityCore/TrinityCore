--
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26048;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2604800;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26048, 0, 0, 1, 64, 0, 100, 0, 0, 0, 0, 0, 12, 26045, 2, 300000, 0, 0, 0, 8, 0, 0, 0, 3403.83, 4133.07, 18.1375, 5.75959, 'Storm Totem - On Gossip Hello - Spawn Storm Tempest'),
(26048, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - Linked with Previous Event - Set NPC Flags'),
(26048, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - Linked with Previous Event - Close Gossip'),
(26048, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2604800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - Linked with Previous Event - Run Script'),
(26048, 0, 4, 0, 11, 0, 100, 0, 0, 0, 0, 0, 81, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - On Spawn - Set NPC Flags'),
(26048, 0, 6, 0, 64, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - On Gossip Hello - Close Gossip'),
(2604800, 9, 0, 0, 0, 0, 100, 0, 300000, 300000, 0, 0, 81, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Storm Totem - Script - Set NPC Flags');

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=26045 AND `source_type`=0 AND `id`=8 AND `link`=9;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =26048;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,26048,0,0,9,0,11895,0,0,0,0,'','Storm Totem - Only Summon Storm Tempest if player is on Master the Storms');
