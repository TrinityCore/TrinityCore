-- Celebras the Redeemed
DELETE FROM `gossip_menu` WHERE `MenuID`=5349 AND `TextID` IN (6373, 6375);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (5350, 5351, 5352, 5353, 5354, 5355, 5358);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5349,6375,0),
(5349,6373,0),
(5350,6374,0),
(5351,6377,0),
(5352,6378,0),
(5353,6379,0),
(5354,6384,0),
(5355,6385,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5349, 5351, 5352, 5347, 5346, 5354);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5349,0,0,"Celebras, I lost my Scepter...",8928,1,1,5350,0,0,0,"",0,0),
(5349,1,0,"Please show me the Stone of Maraudon.",8931,1,1,0,0,0,0,"",0,0),
(5349,2,0,"Please explain how the scepter works.",8932,1,1,5351,0,0,0,"",0,0),
(5349,3,0,"Please tell me more about Maraudon.",8938,1,1,5347,0,0,0,"",0,0),
(5349,4,0,"How can I find the two parts of your scepter?",8957,1,1,5354,0,0,0,"",0,0),
(5351,0,0,"I don't quite understand...",8934,1,1,5352,0,0,0,"",0,0),
(5352,0,0,"No, really, I still don't understand...",8936,1,1,5353,0,0,0,"",0,0),
(5347,0,0,"Please tell me more about Zaetar.",8940,1,1,5346,0,0,0,"",0,0),
(5346,0,0,"Tell me more about the history of Remulos and Zaetar.",8961,1,1,5361,0,0,0,"",0,0),
(5354,0,0,"Why didn't Lord Vyletongue unite both parts of the scepter into one?",8959,1,1,5355,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID`=6374;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`) VALUES
(6374,"How has this come to be, $n? Do you think that an item such as the Scepter of Celebras is trivial?$B$BI can help you this time, but do not be careless with this valuable item again...","",8927,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5349;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5349;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,5349,6375,0,0,9,0,7046,0,0,0,0,0,"","Show gossip text 6375 if quest 'The Scepter of Celebras' is taken"),
(14,5349,6373,0,0,8,0,7046,0,0,0,0,0,"","Show gossip text 6373 if quest 'The Scepter of Celebras' is rewarded"),
(15,5349,0,0,0,2,0,17191,1,1,1,0,0,"","Show gossip option 0 if player does not have item Scepter of Celebras"),
(15,5349,0,0,0,8,0,7046,0,0,0,0,0,"","Show gossip option 0 if quest 'The Scepter of Celebras' is rewarded"),
(15,5349,2,0,0,8,0,7046,0,0,0,0,0,"","Show gossip option 2 if quest 'The Scepter of Celebras' is rewarded"),
(15,5349,3,0,0,8,0,7046,0,0,0,0,0,"","Show gossip option 3 if quest 'The Scepter of Celebras' is rewarded"),
(15,5349,1,0,0,9,0,7046,0,0,0,0,0,"","Show gossip option 1 if quest 'The Scepter of Celebras' is taken"),
(15,5349,4,0,0,9,0,7044,0,0,0,0,0,"","Show gossip option 4 if quest 'Legends of Maraudon' is taken");

UPDATE `smart_scripts` SET `event_type`=62, `event_param1`=5349, `event_param2`=1 WHERE `entryorguid`=13716 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13716 AND `source_type`=0 AND `id` IN (20, 21, 22);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13716,0,20,0,38,0,100,512,0,1,0,0,28,21916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Celebras the Redeemed - On Data Set 0 1 - Remove Aura 'Celebras Waiting'"),
(13716,0,21,0,19,0,100,512,7046,0,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,"Celebras the Redeemed - On Quest 'The Scepter of Celebras' Taken - Say Line 8"),
(13716,0,22,0,62,0,100,512,5349,0,0,0,85,56211,0,0,0,0,0,7,0,0,0,0,0,0,0,"Celebras the Redeemed - On Gossip Option 0 Selected - Invoker Cast 'Create Scepter of Celebras'");

DELETE FROM `creature_text` WHERE `CreatureID`=13716 AND `GroupID`=8;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(13716,8,0,"Perhaps we can attempt this later. Please speak to me again if you wish to do so.",12,0,100,0,0,0,8947,0,"Celebras the Redeemed");
