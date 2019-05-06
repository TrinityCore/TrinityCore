UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25522;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25522, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Skadir Raider - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=25522;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25522, 0, 0, "I shall draw your soul into the mist!", 12, 0, 100, 0, 0, 0, 24846, 0, "Skadir Raider"),
(25522, 0, 1, "YAAARRRGH!", 12, 0, 100, 0, 0, 0, 24847, 0, "Skadir Raider"),
(25522, 0, 2, "Be consumed by the mist!", 12, 0, 100, 0, 0, 0, 24848, 0, "Skadir Raider"),
(25522, 0, 3, "Look what's lost its way...", 12, 0, 100, 0, 0, 0, 24849, 0, "Skadir Raider"),
(25522, 0, 4, "I will heave your carcass into the ocean myself!", 12, 0, 100, 0, 0, 0, 24850, 0, "Skadir Raider"),
(25522, 0, 5, "You're not even fit to be fed to Leviroth.", 12, 0, 100, 0, 0, 0, 24851, 0, "Skadir Raider"),
(25522, 0, 6, "You've strayed too far from your comfortable soil, $r.", 12, 0, 100, 0, 0, 0, 24852, 0, "Skadir Raider");
