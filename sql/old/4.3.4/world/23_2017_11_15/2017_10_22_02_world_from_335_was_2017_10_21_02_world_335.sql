/*
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry` IN (11056, 11057);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (3223, 3224, 3225, 3226, 3227, 3228);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 3223, 0, 0, 0, 8, 0, 5230, 0, 0, 0, 0, 0, "", "Gossip option 0 requires quest 'Return to the Bulwark' rewarded"),
(15, 3223, 1, 0, 0, 8, 0, 5230, 0, 0, 0, 0, 0, "", "Gossip option 1 requires quest 'Return to the Bulwark' rewarded"),
(15, 3223, 2, 0, 0, 8, 0, 5232, 0, 0, 0, 0, 0, "", "Gossip option 2 requires quest 'Return to the Bulwark' rewarded"),
(15, 3223, 3, 0, 0, 8, 0, 5234, 0, 0, 0, 0, 0, "", "Gossip option 3 requires quest 'Return to the Bulwark' rewarded"),
(15, 3223, 4, 0, 0, 8, 0, 5236, 0, 0, 0, 0, 0, "", "Gossip option 4 requires quest 'Return to the Bulwark' rewarded"),
(15, 3228, 0, 0, 0, 8, 0, 5217, 0, 0, 0, 0, 0, "", "Gossip option 0 requires quest 'Return to Chillwind Camp' rewarded"),
(15, 3228, 1, 0, 0, 8, 0, 5217, 0, 0, 0, 0, 0, "", "Gossip option 1 requires quest 'Return to Chillwind Camp' rewarded"),
(15, 3228, 2, 0, 0, 8, 0, 5220, 0, 0, 0, 0, 0, "", "Gossip option 2 requires quest 'Return to Chillwind Camp' rewarded"),
(15, 3228, 3, 0, 0, 8, 0, 5223, 0, 0, 0, 0, 0, "", "Gossip option 3 requires quest 'Return to Chillwind Camp' rewarded"),
(15, 3228, 4, 0, 0, 8, 0, 5226, 0, 0, 0, 0, 0, "", "Gossip option 4 requires quest 'Return to Chillwind Camp' rewarded"),
(15, 3224, 0, 0, 0, 2, 0, 13370, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Vitreous Focuser' not in inventory or bank"),
(15, 3225, 0, 0, 0, 2, 0, 13370, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Vitreous Focuser' not in inventory or bank"),
(15, 3226, 0, 0, 0, 2, 0, 13370, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Vitreous Focuser' not in inventory or bank"),
(15, 3227, 0, 0, 0, 2, 0, 13370, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Vitreous Focuser' not in inventory or bank");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3223, 3224, 3225, 3226, 3227, 3228, 3229);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3223, 0, 1, "I wish to purchase arcane quickener from you.", 6513, 3, 1, 0, 0, 0, 0, "", 0, 0),
(3223, 1, 0, "What's needed for the cauldron at Felstone Field?", 6516, 1, 1, 3224, 0, 0, 0, "", 0, 0),
(3223, 2, 0, "What's needed for the cauldron at Dalson's Tears?", 6517, 1, 1, 3225, 0, 0, 0, "", 0, 0),
(3223, 3, 0, "What's needed for the cauldron at the Writhing Haunt?", 6518, 1, 1, 3226, 0, 0, 0, "", 0, 0),
(3223, 4, 0, "What's needed for the cauldron at Gahrron's Withering?", 6519, 1, 1, 3227, 0, 0, 0, "", 0, 0),
(3228, 0, 1, "I wish to purchase arcane quickener from you.", 6513, 3, 1, 0, 0, 0, 0, "", 0, 0),
(3228, 1, 0, "What's needed for the cauldron at Felstone Field?", 6516, 1, 1, 3224, 0, 0, 0, "", 0, 0),
(3228, 2, 0, "What's needed for the cauldron at Dalson's Tears?", 6517, 1, 1, 3225, 0, 0, 0, "", 0, 0),
(3228, 3, 0, "What's needed for the cauldron at the Writhing Haunt?", 6518, 1, 1, 3226, 0, 0, 0, "", 0, 0),
(3228, 4, 0, "What's needed for the cauldron at Gahrron's Withering?", 6519, 1, 1, 3227, 0, 0, 0, "", 0, 0),
(3224, 0, 0, "I need a Vitreous Focuser.", 6531, 1, 1, 0, 0, 0, 0, "", 0, 0),
(3225, 0, 0, "I need a Vitreous Focuser.", 6531, 1, 1, 0, 0, 0, 0, "", 0, 0),
(3226, 0, 0, "I need a Vitreous Focuser.", 6531, 1, 1, 0, 0, 0, 0, "", 0, 0),
(3227, 0, 0, "I need a Vitreous Focuser.", 6531, 1, 1, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11056, 11057) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11056, 0, 0, 1, 62, 0, 100, 0, 3224, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Close Gossip"),
(11056, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11056, 0, 2, 3, 62, 0, 100, 0, 3225, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Close Gossip"),
(11056, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11056, 0, 4, 5, 62, 0, 100, 0, 3226, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Close Gossip"),
(11056, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11056, 0, 6, 7, 62, 0, 100, 0, 3227, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Close Gossip"),
(11056, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Alchemist Arbington - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11057, 0, 0, 1, 62, 0, 100, 0, 3224, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Close Gossip"),
(11057, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11057, 0, 2, 3, 62, 0, 100, 0, 3225, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Close Gossip"),
(11057, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11057, 0, 4, 5, 62, 0, 100, 0, 3226, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Close Gossip"),
(11057, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Cast 'Vitreous Focuser'"),
(11057, 0, 6, 7, 62, 0, 100, 0, 3227, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Close Gossip"),
(11057, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Apothecary Dithers - On Gossip Option Selected - Cast 'Vitreous Focuser'");
*/
