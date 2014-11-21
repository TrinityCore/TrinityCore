DELETE FROM `creature_text` WHERE `entry` = 36497;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (36497, 0, 0, 'Finally, a captive audience!', 14, 0, 100, 0, 0, 16595, 38486, 0, 'bronjham SAY_AGGRO');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (36497, 1, 0, 'Fodder for the engine.', 14, 0, 100, 0, 0, 16596, 38490, 0, 'bronjham SAY_SLAY_1');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (36497, 1, 1, 'Another soul to strengthen the host!', 14, 0, 100, 0, 0, 16597, 38491, 0, 'bronjham SAY_SLAY_2');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (36497, 2, 0, 'The vortex of the harvested calls to you!', 14, 0, 100, 0, 0, 16599, 38488, 0, 'bronjham SAY_SOUL_STORM');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (36497, 3, 0, 'I will sever your soul from your body!', 14, 0, 100, 0, 0, 16600, 38489, 0, 'bronjham SAY_CORRUPT_SOUL');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12752 AND `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES (12752, 11, 0, 0, 'achievement_bronjahm_soul_power');
