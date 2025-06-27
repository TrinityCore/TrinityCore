-- Finkle Einhorn
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2994,2995,2996,2997,2998,2999);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2994,3660,0),
(2995,3661,0),
(2996,3662,0),
(2997,3663,0),
(2998,3664,0),
(2999,3665,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2951,2994,2995,2996,2997,2998,2999);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2951,0,0,"How the hell did you get in there to begin with?",6079,1,1,2994,0,0,0,"",0,0),
(2994,0,0,"I'm all ears.",6081,1,1,2995,0,0,0,"",0,0),
(2995,0,0,"So let me get this straight. You were swimming, nay, doing backstrokes in molten lava with this... this lava suit of yours? Yes? And out of nowhere, this here beast swallowed you whole?",6083,1,1,2996,0,0,0,"",0,0),
(2996,0,0,"I must know something: How did you go to the bathroom with that thing on?",6085,1,1,2997,0,0,0,"",0,0),
(2997,0,0,"Oh?",6087,1,1,2998,0,0,0,"",0,0),
(2998,0,0,"I'll consider that the next time I run into one of these things.",6089,1,1,2999,0,0,0,"",0,0),
(2999,0,0,"To Malyfous, I assume.",6092,1,1,0,0,0,0,"",0,0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10776;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10776 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10776,0,0,0,11,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Finkle Einhorn - On Respawn - Remove Npc Flag Questgiver"),
(10776,0,1,0,62,0,100,0,2999,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Finkle Einhorn - On Gossip Option Selected - Add Npc Flag Questgiver"),
(10776,0,2,0,62,0,100,0,2999,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Finkle Einhorn - On Gossip Option Selected - Close Gossip");

-- Fix gossip text emotes
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=5, `em0_4`=0,`em0_5`=4 WHERE `ID`=3659;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1 WHERE `ID`=3660;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0,`em0_5`=5 WHERE `ID`=3661;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=25 WHERE `ID`=3662;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=6, `em0_2`=0, `em0_3`=1, `em0_4`=0,`em0_5`=6 WHERE `ID`=3663;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0,`em0_5`=1 WHERE `ID`=3664;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=6 WHERE `ID`=3665;
