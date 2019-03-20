-- A means to an End
DELETE FROM `event_scripts` WHERE `id` = 17868;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(17868, 5, 10, 27238, 120000, 0, 2797.68, -201.873, 139.161, 3.5791);

UPDATE `creature_text` SET `Emote`=15 WHERE `CreatureID`=27238 AND `GroupID`=0; 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432, `AIName`='SmartAI' WHERE `entry`=27352;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (27353,27352);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27353, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 14, 15, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 15, 16, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 16, 17, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 19, 20, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 20, 21, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 21, 22, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 22, 23, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 23, 24, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 24, 25, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 25, 26, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 26, 27, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 27, 28, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 28, 29, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27353, 0, 29, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite Bunny - On Spawn - Summon Levine Family Termite'),
(27352, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Levine Family Termite - On Spawn - Random movments');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =27353;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` =48427;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,48427,0,0,29,0,27238,40,0,1,0,'',' Foreman Kaleiki only spawns if not present'),
(17,0,48427,0,0,29,0,27353,40,0,1,0,'',' Levine Family Termite Bunny only spawns if not present');

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 27352;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Random`) VALUES
(27352, 1, 1, 1, 2);
