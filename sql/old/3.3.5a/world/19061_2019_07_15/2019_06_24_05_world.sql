UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (29437, 29439);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29437, 29439) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29437, 0, 0, 0, 0, 0, 100, 0, 200, 900, 120000, 240000, 0, 11, 50420, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rageclaw Berserker - In Combat - Cast 'Enrage'"),
(29437, 0, 1, 0, 0, 0, 30, 0, 10000, 60000, 120000, 240000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rageclaw Berserker - In Combat - Talk 0"),
(29439, 0, 0, 0, 0, 0, 30, 0, 10000, 60000, 120000, 240000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rageclaw Hunter - In Combat - Talk 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (29437, 29439);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29437, 0, 0, "You go now, bad troll!", 12, 0, 100, 0, 0, 0, 30336, 0, "Rageclaw Berserker"),
(29437, 0, 1, "Why you hurt Rageclaw? You crazy?", 12, 0, 100, 0, 0, 0, 30337, 0, "Rageclaw Berserker"),
(29437, 0, 2, "Rageclaw and troll friends no more!", 12, 0, 100, 0, 0, 0, 30338, 0, "Rageclaw Berserker"),
(29437, 0, 3, "You kill our pups! We kill you back!", 12, 0, 100, 0, 0, 0, 30339, 0, "Rageclaw Berserker"),
(29437, 0, 4, "You leave den the hard way!", 12, 0, 100, 0, 0, 0, 30340, 0, "Rageclaw Berserker"),
(29437, 0, 5, "You hurted the chief's lion seal! WHY YOU HURT LION SEAL??!", 12, 0, 100, 0, 0, 0, 30341, 0, "Rageclaw Berserker"),
(29437, 0, 6, "Why you smell so bad now? You smelled much less bad before!", 12, 0, 100, 0, 0, 0, 30342, 0, "Rageclaw Berserker"),
(29437, 0, 7, "Trolls is shameful. Trolls is killers!", 12, 0, 100, 0, 0, 0, 30343, 0, "Rageclaw Berserker"),
(29439, 0, 0, "You go now, bad troll!", 12, 0, 100, 0, 0, 0, 30336, 0, "Rageclaw Hunter"),
(29439, 0, 1, "Why you hurt Rageclaw? You crazy?", 12, 0, 100, 0, 0, 0, 30337, 0, "Rageclaw Hunter"),
(29439, 0, 2, "Rageclaw and troll friends no more!", 12, 0, 100, 0, 0, 0, 30338, 0, "Rageclaw Hunter"),
(29439, 0, 3, "You kill our pups! We kill you back!", 12, 0, 100, 0, 0, 0, 30339, 0, "Rageclaw Hunter"),
(29439, 0, 4, "You leave den the hard way!", 12, 0, 100, 0, 0, 0, 30340, 0, "Rageclaw Hunter"),
(29439, 0, 5, "You hurted the chief's lion seal! WHY YOU HURT LION SEAL??!", 12, 0, 100, 0, 0, 0, 30341, 0, "Rageclaw Hunter"),
(29439, 0, 6, "Why you smell so bad now? You smelled much less bad before!", 12, 0, 100, 0, 0, 0, 30342, 0, "Rageclaw Hunter"),
(29439, 0, 7, "Trolls is shameful. Trolls is killers!", 12, 0, 100, 0, 0, 0, 30343, 0, "Rageclaw Hunter");
