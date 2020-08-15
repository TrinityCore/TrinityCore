-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16204, 1620400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16204, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, 11, 20793, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Magister Idonis - In Combat CMC - Cast 'Fireball'"),
(16204, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Magister Idonis - Between 0-15% Health - Flee For Assist (No Repeat)"),
(16204, 0, 2, 0, 1, 0, 100, 1, 10000, 20000, 280000, 320000, 80, 1620400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magister Idonis - OOC - Run Script"),
(1620400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magister Idonis - On Script - Say Line 0"),
(1620400, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 16240, 0, 0, 0, 0, 0, 0, "Magister Idonis - On Script - Say Line 0 (Arcanist Janeda)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (16204, 16240);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16204, 0, 0, "Why doesn't Kaendris move against Dar'Khan yet?  What is it we're waiting for?", 12, 0, 100, 1, 0, 0, 12594, 0, "Magister Idonis"),
(16240, 0, 0, "Calm yourself, Idonis.  Brash actions will get us nowhere!  Take a break, tap into some mana crystals.  You'll feel better.", 12, 0, 100, 1, 0, 0, 12595, 0, "Arcanist Janeda"),
(16240, 0, 1, "He's got his reasons, Idonis.  He thinks the Farstriders have uncovered something.", 12, 0, 100, 1, 0, 0, 12596, 0, "Arcanist Janeda"),
(16240, 0, 2, "We must remain focused on our work.  Once the sanctum starts producing at full capacity, Silvermoon will be forced to send help.  Functioning arcane sanctums are in short supply.", 12, 0, 100, 1, 0, 0, 12597, 0, "Arcanist Janeda");
