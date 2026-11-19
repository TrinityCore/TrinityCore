-- 
UPDATE `creature_addon` SET `auras`="55474" WHERE `guid` IN (125388, 125390, 125385);
DELETE FROM `creature` WHERE `guid`=125391;
DELETE FROM `creature_addon` WHERE `guid`=125391;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=27432;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-125386, 2743200) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-125386, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 150000, 210000, 0, 80, 2743200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Warsong Peon - Out Of Combat - Run Script"),
(2743200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, 125389, 27432, 0, 0, 0, 0, 0, "Warsong Peon - On Script - Say Line 0 (Warsong Peon)"),
(2743200, 9, 1, 0, 0, 0, 50, 0, 60000, 120000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Warsong Peon - On Script - Say Line 1"),
(2743200, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Warsong Peon - On Script - Play Emote 'Attack 1H'"),
(2743200, 9, 3, 0, 0, 0, 50, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 10, 125387, 27432, 0, 0, 0, 0, 0, "Warsong Peon - On Script - Say Line 2 (Warsong Peon)");

DELETE FROM `creature_text` WHERE `CreatureID`=27432;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(27432, 0, 0, "Me hungry.", 12, 1, 100, 1, 0, 0, 26572, 0, "Warsong Peon"),
(27432, 0, 1, "Me sleepy.", 12, 1, 100, 1, 0, 0, 26573, 0, "Warsong Peon"),
(27432, 0, 2, "Me cold.", 12, 1, 100, 1, 0, 0, 26574, 0, "Warsong Peon"),
(27432, 0, 3, "Me scared of bug things.", 12, 1, 100, 1, 0, 0, 26575, 0, "Warsong Peon"),
(27432, 0, 4, "Me got stuck in sticky bug rope.", 12, 1, 100, 1, 0, 0, 26576, 0, "Warsong Peon"),
(27432, 0, 5, "Me no like rock place full of bugs.", 12, 1, 100, 1, 0, 0, 26577, 0, "Warsong Peon"),
(27432, 0, 6, "Me no like new cold place.", 12, 1, 100, 1, 0, 0, 26578, 0, "Warsong Peon"),
(27432, 0, 7, "It time for work! Zug zug!", 12, 1, 100, 1, 0, 0, 26589, 0, "Warsong Peon"),
(27432, 1, 0, "Ha ha.", 12, 1, 100, 1, 0, 0, 26582, 0, "Warsong Peon"),
(27432, 1, 1, "That funny.", 12, 1, 100, 1, 0, 0, 26583, 0, "Warsong Peon"),
(27432, 1, 2, "Your head like rock.", 12, 1, 100, 1, 0, 0, 26588, 0, "Warsong Peon"),
(27432, 2, 0, "Ow.", 12, 1, 100, 1, 0, 0, 26584, 0, "Warsong Peon"),
(27432, 2, 1, "Stop it!", 12, 1, 100, 1, 0, 0, 26585, 0, "Warsong Peon"),
(27432, 2, 2, "That hurt.", 12, 1, 100, 1, 0, 0, 26586, 0, "Warsong Peon"),
(27432, 2, 3, "What that sound?", 12, 1, 100, 1, 0, 0, 26587, 0, "Warsong Peon");
