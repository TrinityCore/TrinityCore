/*
-- 
SET @BETHOR := 1498;
SET @GUNTHER := 5666;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@BETHOR, @GUNTHER);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BETHOR, @BETHOR*100, @GUNTHER, @GUNTHER*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BETHOR, 0, 0, 0, 20, 0, 100, 0, 411, 0, 0, 0, 80, @BETHOR*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bethor Iceshard - On Quest 'The Prodigal Lich Returns' Rewarded - Run Script"),
(@BETHOR*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 7762, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bethor Iceshard - On Script - Cast Summon Gunther's Visage"),
(@BETHOR*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 12, @GUNTHER, 1, 22000, 0, 0, 0, 8, 0, 0, 0, 1766.0415, 62.8454, -46.3213, 1.5910, "Bethor Iceshard - On Script - Summon Gunther's Visage"),
(@BETHOR*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bethor Iceshard - On Script - Store Targetlist"),
(@BETHOR*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, @GUNTHER, 0, 0, 0, 0, 0, 0, "Bethor Iceshard - On Script - Send Targetlist to Guther's Visage"),
(@GUNTHER, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @GUNTHER*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gunther's Visage - On Just Summoned - Run Script"),
(@GUNTHER*100, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gunther's Visage - On Script - Talk 0"),
(@GUNTHER*100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gunther's Visage - On Script - Talk 1"),
(@GUNTHER*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Gunther's Visage - On Script - Talk 2"),
(@GUNTHER*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 1498, 0, 0, 0, 0, 0, 0, "Gunther's Visage - On Script - Talk 0 (Bethor Iceshard)");

DELETE FROM `creature_text` WHERE `entry` IN (1498, 5666);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@GUNTHER, 0, 0, "It has been a long time, Bethor, my friend.", 12, 0, 100, 1, 0, 0, 1973, 0, "Gunther's Visage"),
(@GUNTHER, 1, 0, "When time permits, we must speak at length.  For we have much to discuss.", 12, 0, 100, 1, 0, 0, 1974, 0, "Gunther's Visage"),
(@GUNTHER, 2, 0, "And thank you, $n.  Without your aid I may never have found my way to the Forsaken.", 12, 0, 100, 1, 0, 0, 1975, 0, "Gunther's Visage"),
(@BETHOR, 0, 0, "Farewell, my friend.", 12, 0, 100, 1, 0, 0, 1976, 0, "Bethor Iceshard");
*/
