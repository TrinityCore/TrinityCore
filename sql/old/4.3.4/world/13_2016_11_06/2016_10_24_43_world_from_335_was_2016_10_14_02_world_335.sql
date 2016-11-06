--
/*
DELETE FROM `creature_text` WHERE `entry` IN (10296, 10299);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10296, 0, 0, "At last - one among you is worthy of my knowledge. Worry not - I have probed your thoughts, no harm will come to you.", 12, 0, 100, 1, 0, 0, 5555, 0, "Vaelan"),
(10296, 1, 0, "Listen carefully, for the lord of Blackrock will surely destroy you, should you not be prepared.", 12, 0, 100, 1, 0, 0, 5556, 0, "Vaelan"),
(10296, 2, 0, "%s is surrounded by a barrier of anti-magic.", 16, 0, 100, 0, 0, 0, 5590, 0, "Vaelan"),
(10296, 3, 0, "I have discerned the path that you must take. Are you prepared?", 12, 0, 100, 1, 0, 0, 5591, 0, "Vaelan"),
(10299, 0, 0, "Begone, mortal. You are not worthy of my knowledge.", 15, 0, 100, 0, 0, 0, 5592, 0, "Scarshield Infiltrator");

UPDATE `creature_template` SET `gossip_menu_id`=12039 WHERE `entry`=10296;
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 12039 AND 12048;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12039, 0, 0, "Your kind?", 5569, 1, 1, 12040, 0, 0, 0, "", 0, 0),
(12039, 1, 0, "As you wish, Vaelan.", 5589, 1, 1, 0, 0, 0, 0, "", 0, 0),
(12040, 0, 0, "Please.", 5571, 1, 1, 12041, 0, 0, 0, "", 0, 0),
(12041, 0, 0, "No, Vaelan, I do not.", 5573, 1, 1, 12042, 0, 0, 0, "", 0, 0),
(12042, 0, 0, "Demon Soul?", 5575, 1, 1, 12043, 0, 0, 0, "", 0, 0),
(12043, 0, 0, "Where he left off?", 5577, 1, 1, 12044, 0, 0, 0, "", 0, 0),
(12044, 0, 0, "Why not destroy them with the combined might of the Aspects?", 5579, 1, 1, 12045, 0, 0, 0, "", 0, 0),
(12045, 0, 0, "Unless?", 5581, 1, 1, 12046, 0, 0, 0, "", 0, 0),
(12046, 0, 0, "I am willing to try but I will require instruction.", 5583, 1, 1, 12047, 0, 0, 0, "", 0, 0),
(12047, 0, 0, "I will do my best, Vaelan.", 5585, 1, 1, 12048, 0, 0, 0, "", 0, 0),
(12048, 0, 0, "It will be done.", 5587, 1, 1, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 12039 AND 12048;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(12039, 3301, 0),
(12039, 3311, 0),
(12040, 3302, 0),
(12041, 3303, 0),
(12042, 3304, 0),
(12043, 3305, 0),
(12044, 3306, 0),
(12045, 3307, 0),
(12046, 3308, 0),
(12047, 3309, 0),
(12048, 3310, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=12039;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 12039, 3311, 0, 0, 2, 0, 12219, 1, 0, 0, 0, 0, "", "Show gossip menu 12039 with text 3311 if player has item Unadorned Seal of Ascension in inventory OR"),
(14, 12039, 3311, 0, 1, 2, 0, 12324, 1, 0, 0, 0, 0, "", "Show gossip menu 12039 with text 3311 if player has item Forged Seal of Ascension in inventory"),
(15, 12039, 0, 0, 0, 2, 0, 12219, 1, 0, 1, 0, 0, "", "Show gossip option 0 if player does not have item Unadorned Seal of Ascension in inventory AND"),
(15, 12039, 0, 0, 0, 2, 0, 12324, 1, 0, 1, 0, 0, "", "Show gossip option 0 if player does not have item Forged Seal of Ascension in inventory"),
(15, 12039, 1, 0, 0, 2, 0, 12219, 1, 0, 0, 0, 0, "", "Show gossip option 1 if player has item Unadorned Seal of Ascension in inventory OR"),
(15, 12039, 1, 0, 1, 2, 0, 12324, 1, 0, 0, 0, 0, "", "Show gossip option 1 if player has item Forged Seal of Ascension in inventory");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (10296, 10299);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10296, 10299, 1029900, 1029901);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10299, 0, 0, 0, 62, 0, 100, 0, 12039, 1, 0, 0, 80, 1029901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Gossip Option 1 (menu 12039) selected - Call Actionlist"),
(10299, 0, 1, 0, 62, 0, 100, 0, 12048, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Gossip Option 0 (menu 12048) selected - Close gossip"),
(10299, 0, 2, 0, 38, 0, 100, 1, 1, 1, 1000, 1000, 80, 1029900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Data 1 1 Set - Call Actionlist"),
(1029900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 16037, 2, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Cast"),
(1029900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Remove Flag Standstate Kneel"),
(1029900, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 36, 10296, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Change entry"),
(1029900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Remove Gossip+Questgiver flag"),
(1029900, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Face nearest player"),
(1029900, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Talk 0"),
(1029900, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Talk 1"),
(1029900, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 82, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Add Gossip flag"),
(1029901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Close Gossip"),
(1029901, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Remove Gossip flag"),
(1029901, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Play Emote 1"),
(1029901, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 16051, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Cast Spell"),
(1029901, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Talk 2"),
(1029901, 9, 5, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Talk 3"),
(1029901, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scarshield Infiltrator - On Script - Add Questgiver Flag");

DELETE FROM `areatrigger_scripts` WHERE `entry`=1946;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(1946, "at_nearby_scarshield_infiltrator");

DELETE FROM `creature_template_addon` WHERE `entry`=10299;
INSERT INTO `creature_template_addon` (entry, bytes1) VALUES
(10299, 8);

UPDATE `creature` SET `position_x`=56.9316, `position_y`=-399.4169, `position_z`=64.3478 WHERE `guid`=42798;
DELETE FROM `creature` WHERE `guid`=42797;
*/
