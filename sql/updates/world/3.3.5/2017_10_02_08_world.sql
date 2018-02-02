-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4286, 4301) AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4295, 4540) AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4298, 4300, 10424) AND `id`=3 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4540, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarlet Monk - Between 0-15% Health - Flee For Assist (No Repeat)"),
(4301, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarlet Centurion - Between 0-15% Health - Flee For Assist (No Repeat)"),
(4300, 0, 3, 0, 4, 0, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Scarlet Wizard - On Aggro - Say Line 0"),
(4286, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarlet Soldier - Between 0-15% Health - Flee For Assist (No Repeat)"),
(4295, 0, 2, 0, 4, 0, 20, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Scarlet Myrmidon - On Aggro - Say Line 1"),
(4298, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarlet Defender - Between 0-15% Health - Flee For Assist (No Repeat)"),
(10424, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crimson Gallant - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (4295, 4300);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4300, 0, 0, "You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.", 12, 7, 25, 0, 0, 0, 2625, 0, "Scarlet Wizard"),
(4300, 0, 1, "There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.", 12, 7, 25, 0, 0, 0, 2626, 0, "Scarlet Wizard"),
(4300, 0, 2, "The Light condemns all who harbor evil.  Now you will die!", 12, 7, 25, 0, 0, 0, 2627, 0, "Scarlet Wizard"),
(4300, 0, 3, "The Scarlet Crusade shall smite the wicked and drive evil from these lands!", 12, 7, 25, 0, 0, 0, 2628, 0, "Scarlet Wizard"),
(4295, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Scarlet Myrmidon"),
(4295, 1, 0, "You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.", 12, 7, 25, 0, 0, 0, 2625, 0, "Scarlet Myrmidon"),
(4295, 1, 1, "There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.", 12, 7, 25, 0, 0, 0, 2626, 0, "Scarlet Myrmidon"),
(4295, 1, 2, "The Light condemns all who harbor evil.  Now you will die!", 12, 7, 25, 0, 0, 0, 2627, 0, "Scarlet Myrmidon"),
(4295, 1, 3, "The Scarlet Crusade shall smite the wicked and drive evil from these lands!", 12, 7, 25, 0, 0, 0, 2628, 0, "Scarlet Myrmidon");
