-- 
DELETE FROM `creature_text` WHERE `CreatureID` IN (31261, 31259);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(31261, 0, 0, "This is madness! Cease this foolish battle!", 12, 1, 100, 0, 0, 0, 31915, 0, "Brother Keltan"),
(31261, 0, 1, "Brothers and sisters, we must remain united! The Lich King will never fall to a world divided!", 12, 1, 100, 0, 0, 0, 31916, 0, "Brother Keltan"),
(31261, 0, 2, "Can you not see that you play right into the Lich King's hands? He wants you to kill each other!", 12, 1, 100, 0, 0, 0, 31917, 0, "Brother Keltan"),
(31261, 0, 3, "Join the Argent Crusade! United, we shall destroy the Lich King!", 12, 1, 100, 0, 0, 0, 31918, 0, "Brother Keltan"),
(31261, 0, 4, "Judgment day comes, brothers and sisters! Will you be prepared?", 12, 1, 100, 0, 0, 0, 31919, 0, "Brother Keltan"),
(31261, 0, 5, "How much of our efforts are being wasted by attacking the Alliance?", 12, 1, 100, 0, 0, 0, 31920, 0, "Brother Keltan"),
(31261, 0, 6, "We must unite and focus our attention upon the true threat: THE LICH KING!", 12, 1, 100, 0, 0, 0, 31922, 0, "Brother Keltan"),
(31259, 0, 0, "This is madness! Cease this foolish battle!", 12, 7, 100, 0, 0, 0, 31923, 0, "Absalan the Pious"),
(31259, 0, 1, "Brothers and sisters, we must remain united! The Lich King will never fall to a world divided!", 12, 7, 100, 0, 0, 0, 31924, 0, "Absalan the Pious"),
(31259, 0, 2, "Can you not see that you play right into the Lich King's hands? He wants you to kill each other!", 12, 7, 100, 0, 0, 0, 31925, 0, "Absalan the Pious"),
(31259, 0, 3, "Join the Argent Crusade! United, we shall destroy the Lich King!", 12, 7, 100, 0, 0, 0, 31926, 0, "Absalan the Pious"),
(31259, 0, 4, "Judgment day comes, brothers and sisters! Will you be prepared?", 12, 7, 100, 0, 0, 0, 31927, 0, "Absalan the Pious"),
(31259, 0, 5, "How much of our efforts are being wasted by attacking the Horde?", 12, 7, 100, 0, 0, 0, 31928, 0, "Absalan the Pious"),
(31259, 0, 6, "We must unite and focus our attention upon the true threat: THE LICH KING!", 12, 7, 100, 0, 0, 0, 31929, 0, "Absalan the Pious");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (31261, 31259);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31261, 31259) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31261, 0, 0, 0, 1, 0, 100, 0, 15000, 30000, 100000, 140000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Keltan - Out Of Combat - Say Line 0"),
(31259, 0, 0, 0, 1, 0, 100, 0, 15000, 30000, 100000, 140000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Absalan the Pious - Out Of Combat - Say Line 0");
