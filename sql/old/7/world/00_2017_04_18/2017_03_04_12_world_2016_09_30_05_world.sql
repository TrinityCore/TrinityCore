--
DELETE FROM `smart_scripts` WHERE `entryorguid`=1724100 AND `source_type`=9 AND `id` BETWEEN 10 AND 14;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1724100, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 17242, 0, 0, 0, 0, 0, 0, "Priestess Kyleen Il'dinare - Script - Say Line 7 (Archaeologist Adamant Ironheart)"),
(1724100, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Priestess Kyleen Il'dinare - Script - Say Line 2"),
(1724100, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17242, 0, 0, 0, 0, 0, 0, "Priestess Kyleen Il'dinare - Script - Set Data 2 2 on Archaeologist Adamant Ironheart"),
(1724100, 9, 13, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.994838, "Priestess Kyleen Il'dinare - Script - Set Orientation"),
(1724100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Priestess Kyleen Il'dinare - Script - Set NPC Flags");

UPDATE `quest_offer_reward` SET `RewardText`="With Warlord Sriss'tiz dead, the possibility of a naga invasion is now only a distant memory. We are safe, for the time being...$B$BI must admit, I was wrong to think badly of you, $N. You have shown that you are nothing like the filth that was Archimonde. Accept this as a gift from the night elves." WHERE `ID`=9515;

DELETE FROM `gossip_menu` WHERE `entry`=7983 AND `text_id` IN (8994, 9039); -- Remove High Chief Stillpine texts from Field Commander Mahfuun (a totally unrelated NPC).
DELETE FROM `gossip_menu` WHERE `entry`=7434 AND `text_id`=9039;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(7434, 9039, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND SourceGroup IN (7434, 7983);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 7434, 9039, 0, 0, 9, 0, 9663, 0, 0, 0, 0, 0, "", "Show gossip text 9039 if player has quest 9663"),
(14, 7434, 8997, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8997 if player has quest 9544 rewarded");

DELETE FROM `gossip_menu` WHERE `entry`=7428 AND `text_id`=8983;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(7428, 8983, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` BETWEEN 7428 AND 7433;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 7428, 8990, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8990 if player has quest 9544 rewarded"),
(14, 7429, 8991, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8991 if player has quest 9544 rewarded"),
(14, 7430, 8992, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8992 if player has quest 9544 rewarded"),
(14, 7431, 8993, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8993 if player has quest 9544 rewarded"),
(14, 7432, 8994, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8994 if player has quest 9544 rewarded"),
(14, 7433, 8996, 0, 0, 8, 0, 9544, 0, 0, 0, 0, 0, "", "Show gossip text 8996 if player has quest 9544 rewarded");
