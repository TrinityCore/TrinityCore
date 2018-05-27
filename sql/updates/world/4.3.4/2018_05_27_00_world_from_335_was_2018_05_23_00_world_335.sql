/*
-- Quest "Get the Scoop"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (21211, 21212,21217);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=231;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,21211,0,0,0,9,0,1950,0,0,0,0,0,"","Show gossip option if quest 'Get the Scoop' is taken"), -- Goblin Pit Crewman
(15,21212,0,0,0,9,0,1950,0,0,0,0,0,"","Show gossip option if quest 'Get the Scoop' is taken"), -- Gnome Pit Crewman
(15,21217,0,0,0,9,0,1950,0,0,0,0,0,"","Show gossip option if quest 'Get the Scoop' is taken"), -- Race Master Kronkrider
(14,231,739,0,0,9,0,1950,0,0,1,0,0,"","Show gossip text 739 if quest 'Get the Scoop' is not taken");  -- "Plucky" Johnson

DELETE FROM `gossip_menu` WHERE `MenuID` IN (281, 283,433);
DELETE FROM `gossip_menu` WHERE `MenuID`=231 AND `TextID`=739;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(281,779,0), -- Goblin Pit Crewman
(283,781,0), -- Gnome Pit Crewman
(433,930,0), -- Race Master Kronkrider
(231,739,0); -- "Plucky" Johnson

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21211, 21212,21217);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(21211,0,0,"Where is Tirth's assistant?",2769,1,1,281,0,0,0,"",0,0), -- Goblin Pit Crewman
(21212,0,0,"Where is Tirth's assistant?",2779,1,1,283,0,0,0,"",0,0), -- Gnome Pit Crewman
(21217,0,0,"Where is Tirth's assistant?",2779,1,1,433,0,0,0,"",0,0); -- Race Master Kronkrider

DELETE FROM `npc_text` WHERE `ID`=739;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(739,"Don't tell Tirth I'm still here.  If he finds out I haven't left the Shimmering Flats, I'll be running his errands and cleaning his dirty laundry forever!","",2722,0,0,0,0,0,0,0,0);

-- "Plucky" Johnson
DELETE FROM `smart_scripts` WHERE `entryorguid`=6626 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=662600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6626,0,0,0,22,0,100,0,22,0,0,0,0,80,662600,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Received Emote 'Chicken' - Run Script"),
(6626,0,1,2,22,0,100,0,7,0,0,0,0,11,9192,2,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Received Emote 'Beckon' - Cast \"Plucky\" Resumes Human Form"),
(6626,0,2,3,61,0,100,0,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Received Emote 'Beckon' - Add NPC Flag Gossip"),
(6626,0,3,0,61,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Received Emote 'Beckon' - Move To Invoker"),
(6626,0,4,0,62,0,100,0,231,0,0,0,0,15,1950,0,0,0,0,0,7,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Gossip Option 0 Selected - Complete Quest 'Get the Scoop'"),
(6626,0,5,0,23,0,100,0,9192,0,1000,1000,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Has No Aura \"Plucky\" Resumes Human Form - Set NPC Flag 0"),
(662600,9,0,0,0,0,100,0,0,0,0,0,0,11,9192,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Script - Cast \"Plucky\" Resumes Human Form"),
(662600,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Script - Set Orientation"),
(662600,9,2,0,0,0,100,0,500,500,0,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Script - Play Emote 'Wave'"),
(662600,9,3,0,0,0,100,0,3500,3500,0,0,0,28,9192,0,0,0,0,0,1,0,0,0,0,0,0,0,"\"Plucky\" Johnson - On Script - Remove Aura \"Plucky\" Resumes Human Form");
*/
