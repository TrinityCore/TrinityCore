--
DELETE FROM `creature_text` WHERE `entry` IN (6929, 11814, 6746, 6741, 6740, 5111, 6826, 6735);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6929, 0, 0, "Ooo, so strong!  Happy Hallow's End, $n!", 12, 0, 100, 23, 0, 0, 10789, 0, "Innkeeper Gryshka"),
(11814, 0, 0, "Chugga-chugga, woo-woo!  Happy Hallow's End, $n!", 12, 0, 100, 275, 0, 0, 10788, 0, "Kali Remik"),
(6746, 0, 0, "I may have ninety-nine problems, but dancin' ain't one of them!  Happy Hallow's End, $n!", 12, 0, 100, 94, 0, 0, 10787, 0, "Innkeeper Pala"),
(6741, 0, 0, "Bawk, bawk, bawk!  Happy Hallow's End, $n!", 12, 0, 100, 19, 0, 0, 10786, 0, "Innkeeper Norman"),
(6740, 0, 0, "Ooo, so strong!  Happy Hallow's End, $n!", 12, 0, 100, 23, 0, 0, 10797, 0, "Innkeeper Allison"),
(5111, 0, 0, "Bawk, bawk, bawk!  Happy Hallow's End, $n!", 12, 0, 100, 19, 0, 0, 10798, 0, "Innkeeper Firebrew"),
(6826, 0, 0, "Chugga-chugga, woo-woo!  Happy Hallow's End, $n!", 12, 0, 100, 275, 0, 0, 10799, 0, "Talvash del Kissel"),
(6735, 0, 0, "I may have ninety-nine problems, but dancin' ain't one of them!  Happy Hallow's End, $n!", 12, 0, 100, 94, 0, 0, 10800, 0, "Innkeeper Saelienne");

UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid` IN (6746, 6929, 6740, 5111, 6735) AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6746, 6929, 6740, 5111, 6735) AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6929, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Gryshka - Received Emote 41 - Talk 0"),
(6746, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Pala - Received Emote 34 - Talk 0"),
(6740, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Allison - Received Emote 41 - Talk 0"),
(5111, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Firebrew - Received Emote 22 - Talk 0"),
(6735, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Saelienne - Received Emote 34 - Talk 0");

UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid` IN (11814, 6826) AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11814, 6826) AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11814, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Kali Remik - Received Emote 264 - Talk 0"),
(6826, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Talvash del Kissel - Received Emote 264 - Talk 0");

UPDATE `smart_scripts` SET `link`=4 WHERE `entryorguid`=6741 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6741 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6741, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Innkeeper Norman - Received Emote 22 - Talk 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (6929, 11814, 6746, 6741, 6740, 5111, 6826, 6735);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 6929, 0, 0, 9, 0, 8359, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Gryshka can only run if player has quest Flexing for Nougat"),
(22, 1, 11814, 0, 0, 9, 0, 8358, 0, 0, 0, 0, 0, "", "SAI id 0 for NPC Kali Remik can only run if player has quest Incoming Gumdrop"),
(22, 3, 6746, 0, 0, 9, 0, 8360, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Pala can only run if player has quest Dancing for Marzipan"),
(22, 3, 6741, 0, 0, 9, 0, 8354, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Norman can only run if player has quest Chicken Clucking for a Mint"),
(22, 3, 6740, 0, 0, 9, 0, 8356, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Allison can only run if player has quest Flexing for Nougat"),
(22, 3, 5111, 0, 0, 9, 0, 8353, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Firebrew can only run if player has quest Chicken Clucking for a Mint"),
(22, 1, 6826, 0, 0, 9, 0, 8355, 0, 0, 0, 0, 0, "", "SAI id 0 for NPC Talvash del Kissel can only run if player has quest Incoming Gumdrop"),
(22, 3, 6735, 0, 0, 9, 0, 8357, 0, 0, 0, 0, 0, "", "SAI id 2 for NPC Innkeeper Saelienne can only run if player has quest Dancing for Marzipan");

UPDATE `quest_template_addon` SET `SpecialFlags`=`SpecialFlags`|1 WHERE `ID` IN (8359, 8358, 8360, 8354, 8356, 8353, 8355, 8357);
