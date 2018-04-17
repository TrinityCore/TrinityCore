UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`= 46363;
UPDATE `creature_template` SET `ScriptName`='npc_sanitron_5000', `InhabitType` = 4, `HoverHeight` = 0 WHERE `entry`= 46185;
DELETE FROM `creature_text` WHERE `CreatureID` IN (46185, 46230);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextID`) VALUES
(46185, 0, 0, 'Commencing decontamination sequence...', 12, 0, 100, 0, 0, 0, NULL, 46323),
(46185, 1, 0, 'Decontamination complete. Standby for delivery.', 12, 0, 100, 0, 0, 0, NULL, 46324),
(46185, 2, 0, 'Warning, system overload. Malfunction imminent!', 12, 0, 100, 0, 0, 0, NULL, 46325),
(46230, 0, 0, 'Ugh! Not this again! I''m asking for a new station next expedition...', 12, 0, 100, 0, 0, 0, NULL, 46342);
