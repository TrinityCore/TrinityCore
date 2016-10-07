--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (2338, 2339);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2338, 2339);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2338, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - On Aggro - Talk 0"),
(2338, 0, 1, 0, 2, 0, 100, 1, 0, 90, 0, 0, 11, 6074, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - Between 0-90% health - Cast 'Renew'"),
(2338, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 2054, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - Between 0-30% health - Cast 'Heal'"),
(2338, 0, 3, 0, 6, 0, 30, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - On Death - Talk 1"),

(2339, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - On Aggro - Talk 0"),
(2339, 0, 1, 0, 0, 0, 100, 0, 2000, 12000, 35000, 45000, 11, 6713, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - In Combat - Cast 'Disarm'"),
(2339, 0, 2, 0, 6, 0, 30, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - On Death - Talk 1");

DELETE FROM `creature_text` WHERE `entry` IN (2338, 2339);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2338, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=825), 12, 0, 100, 0, 0, 0, 825, 0, "Twilight Disciple"),
(2338, 0, 1, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=833), 12, 0, 100, 0, 0, 0, 833, 0, "Twilight Disciple"),
(2338, 0, 2, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=834), 12, 0, 100, 0, 0, 0, 834, 0, "Twilight Disciple"),
(2338, 0, 3, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=835), 12, 0, 100, 0, 0, 0, 835, 0, "Twilight Disciple"),
(2338, 0, 4, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=836), 12, 0, 100, 0, 0, 0, 836, 0, "Twilight Disciple"),
(2338, 0, 5, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=837), 12, 0, 100, 0, 0, 0, 837, 0, "Twilight Disciple"),
(2338, 0, 6, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=838), 12, 0, 100, 0, 0, 0, 838, 0, "Twilight Disciple"),
(2338, 0, 7, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=839), 12, 0, 100, 0, 0, 0, 839, 0, "Twilight Disciple"),
(2338, 0, 8, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=840), 12, 0, 100, 0, 0, 0, 840, 0, "Twilight Disciple"),
(2338, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=826), 12, 0, 10, 0, 0, 0, 826, 0, "Twilight Disciple"),
(2338, 1, 1, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=827), 12, 0, 10, 0, 0, 0, 827, 0, "Twilight Disciple"),
(2338, 1, 2, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=828), 12, 0, 10, 0, 0, 0, 828, 0, "Twilight Disciple"),
(2338, 1, 3, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=829), 12, 0, 10, 0, 0, 0, 829, 0, "Twilight Disciple"),
(2338, 1, 4, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=830), 12, 0, 10, 0, 0, 0, 830, 0, "Twilight Disciple"),
(2338, 1, 5, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=831), 12, 0, 10, 0, 0, 0, 831, 0, "Twilight Disciple"),
(2338, 1, 6, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=832), 12, 0, 40, 0, 0, 0, 832, 0, "Twilight Disciple"),
(2339, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=825), 12, 0, 100, 0, 0, 0, 825, 0, "Twilight Thug"),
(2339, 0, 1, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=833), 12, 0, 100, 0, 0, 0, 833, 0, "Twilight Thug"),
(2339, 0, 2, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=834), 12, 0, 100, 0, 0, 0, 834, 0, "Twilight Thug"),
(2339, 0, 3, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=835), 12, 0, 100, 0, 0, 0, 835, 0, "Twilight Thug"),
(2339, 0, 4, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=836), 12, 0, 100, 0, 0, 0, 836, 0, "Twilight Thug"),
(2339, 0, 5, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=837), 12, 0, 100, 0, 0, 0, 837, 0, "Twilight Thug"),
(2339, 0, 6, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=838), 12, 0, 100, 0, 0, 0, 838, 0, "Twilight Thug"),
(2339, 0, 7, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=839), 12, 0, 100, 0, 0, 0, 839, 0, "Twilight Thug"),
(2339, 0, 8, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=840), 12, 0, 100, 0, 0, 0, 840, 0, "Twilight Thug"),
(2339, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=826), 12, 0, 10, 0, 0, 0, 826, 0, "Twilight Thug"),
(2339, 1, 1, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=827), 12, 0, 10, 0, 0, 0, 827, 0, "Twilight Thug"),
(2339, 1, 2, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=828), 12, 0, 10, 0, 0, 0, 828, 0, "Twilight Thug"),
(2339, 1, 3, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=829), 12, 0, 10, 0, 0, 0, 829, 0, "Twilight Thug"),
(2339, 1, 4, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=830), 12, 0, 10, 0, 0, 0, 830, 0, "Twilight Thug"),
(2339, 1, 5, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=831), 12, 0, 10, 0, 0, 0, 831, 0, "Twilight Thug"),
(2339, 1, 6, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=832), 12, 0, 40, 0, 0, 0, 832, 0, "Twilight Thug");
