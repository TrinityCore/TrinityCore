--
DELETE FROM `conditions` WHERE `SourceGroup`=5502 AND `SourceTypeOrReferenceId` IN (14, 15);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 5502, 6555, 0, 0, 8, 0, 1046, 0, 0, 0, 0, 0, "", "Gossip text requires quest Raene's Cleansing (Part 11) rewarded"),
(15, 5502, 0, 0, 0, 8, 0, 1029, 0, 0, 0, 0, 0, "", "Gossip option 0 requires quest Return to Raene rewarded AND"),
(15, 5502, 0, 0, 0, 2, 0, 5462, 1, 1, 1, 0, 0, "", "Gossip option 0 requires item Dartol's Rod of Transformation not in bags or bank");

DELETE FROM `npc_text` WHERE `ID`=50001;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50001, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=9026), 9026);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=5502;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5502, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=9025), 9025, 1, 1, 50001, 0, 0, 0, "", 0, 0);

DELETE FROM `gossip_menu` WHERE `entry`=50001;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(50001, 50001, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=3691 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3691, 0, 6, 0, 62, 0, 100, 0, 5502, 0, 0, 0, 56, 5462, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Raene Wolfrunner - On Gossip Select - Add Item 'Dartol's Rod of Transformation'");
