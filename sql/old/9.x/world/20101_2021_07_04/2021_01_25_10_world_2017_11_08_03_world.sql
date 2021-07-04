-- 
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=17046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17046;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17015 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1701500, 17046) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17015, 0, 2, 0, 40, 0, 100, 0, 11, 0, 0, 0, 54, 300000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Waypoint 11 Reached - Pause Waypoint"),
(1701500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 49000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Pause Waypoint"),
(1701500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Remove NPC Flag Gossip+Questgiver"),
(1701500, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 0"),
(1701500, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 17046, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 0 (Pilgrim Gal'ressa)"),
(1701500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 17046, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Set Data 1 1 (Pilgrim Gal'ressa)"),
(1701500, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 17046, 20, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 1 (Pilgrim Gal'ressa)"),
(1701500, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 1"),
(1701500, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 17046, 20, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 2 (Pilgrim Gal'ressa)"),
(1701500, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 2"),
(1701500, 9, 9, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 17046, 20, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 3 (Pilgrim Gal'ressa)"),
(1701500, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Talk 3"),
(1701500, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17046, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Set Data 2 2 (Pilgrim Gal'ressa)"),
(1701500, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Taleris Dawngazer - On Script - Add NPC Flag Gossip+Questgiver"),
(17046, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Pilgrim Gal'ressa - On Data Set 1 1 - Stand Up"),
(17046, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Pilgrim Gal'ressa - On Data Set 2 2 - Sleep");

DELETE FROM `creature_text` WHERE `CreatureID` IN (17015, 17046);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17015, 0, 0, "Wake up, Gal'ressa.", 12, 1, 100, 1, 0, 0, 13325, 0, "Taleris Dawngazer"),
(17015, 1, 0, "You've had enough time to recover from your wounds, Gal'ressa. The time has come for you to return to the road.", 12, 1, 100, 1, 0, 0, 13328, 0, "Taleris Dawngazer"),
(17015, 2, 0, "You'll do no such thing. We simply haven't the room to keep you here. Now, kindly be on your way.", 12, 1, 100, 1, 0, 0, 13330, 0, "Taleris Dawngazer"),
(17015, 3, 0, "Very well then, have it your way. When we turn others away, you will be responsible for their suffering. Think about that.", 12, 1, 100, 1, 0, 0, 13332, 0, "Taleris Dawngazer"),
(17046, 0, 0, "%s rubs the sleep from her eyes.", 16, 0, 100, 0, 0, 0, 13326, 0, "Pilgrim Gal'ressa"),
(17046, 1, 0, "What do you want, Taleris?", 12, 1, 100, 1, 0, 0, 13327, 0, "Pilgrim Gal'ressa"),
(17046, 2, 0, "I'm not going on alone, Taleris, and that's final. I'm going to wait here for the next group of pilgrims and set out with them when they depart.", 12, 1, 100, 1, 0, 0, 13329, 0, "Pilgrim Gal'ressa"),
(17046, 3, 0, "By the Sunwell, you've a thick skull! You'll not bully me into leaving, Taleris. Now, begone from my sight!", 12, 1, 100, 1, 0, 0, 13331, 0, "Pilgrim Gal'ressa");
