-- 
DELETE FROM `creature_text` WHERE `CreatureID`=17841;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17841, 0, 0, "It's just like the structure you described at Umbrafen Lake.  Does this mean the naga are pumping water out of all the lakes in Zangarmarsh?", 15, 0, 100, 0, 0, 0, 14706, 0, "Ysiel Windsinger"),
(17841, 1, 0, "The naga are even pumping the water out of their own lake!  What purpose could that possibly serve?", 15, 0, 100, 0, 0, 0, 14712, 0, "Ysiel Windsinger"),
(17841, 2, 0, "There!  Those pipes all appear to be connected to that structure.  It can't possibly fit all the water they've been stealing.  Where are they keeping it?", 15, 0, 100, 0, 0, 0, 14713, 0, "Ysiel Windsinger"),
(17841, 3, 0, "What we saw explains what happened in the Dead Mire.  There was a lake here once.  If we don't stop the naga, all of the marsh will soon look like this!", 15, 0, 100, 0, 0, 0, 14714, 0, "Ysiel Windsinger");
DELETE FROM `event_scripts` WHERE `id` IN (11286,11289,11290,11291);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(11286, 0, 10, 17841, 100, 0, 0,0,0, 0),
(11289, 0, 10, 17841, 100, 0, 0,0,0, 0),
(11290, 0, 10, 17841, 100, 0, 0,0,0, 0),
(11291, 0, 10, 17841, 100, 0, 263.479, 5527.215, 65.718498, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17841 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17841, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  "Ysiel Windsinger - Just summoned - Say text"),
(17841, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Ysiel Windsinger - Just summoned - Say tex"),
(17841, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Ysiel Windsinger - Just summoned - Say tex"),
(17841, 0, 4, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Ysiel Windsinger - Just summoned - Say tex"),
(17841, 0, 5, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Ysiel Windsinger - Just summoned - Say tex");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=17841;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 17841, 0, 0, 23, 1, 3819, 0, 0, 0, 0, 0, '', 'Ysiel Windsinger Requires Area'),
(22, 4, 17841, 0, 0, 23, 1, 3653, 0, 0, 1, 0, 0, '', 'Ysiel Windsinger Requires Area'),
(22, 4, 17841, 0, 0, 23, 1, 3819, 0, 0, 1, 0, 0, '', 'Ysiel Windsinger Requires Area'),
(22, 4, 17841, 0, 0, 23, 1, 3648, 0, 0, 1, 0, 0, '', 'Ysiel Windsinger Requires Area'),
(22, 5, 17841, 0, 0, 23, 1, 3653, 0, 0, 0, 0, 0, '', 'Ysiel Windsinger Requires Area'),
(22, 6, 17841, 0, 0, 23, 1, 3648, 0, 0, 0, 0, 0, '', 'Ysiel Windsinger Requires Area');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (31746) AND `spell_effect`=31773;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-31773, -31774, -31775, -31776);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(31746, 31773, 0, "Whisper Aura 0"),
(-31773, 31774, 0, "Whisper Aura 1"),
(-31774, 31775, 0, "Whisper Aura 2"),
(-31775, 31776, 0, "Whisper Aura 3"),
(-31776, 31777, 0, "Whisper Aura 4");
