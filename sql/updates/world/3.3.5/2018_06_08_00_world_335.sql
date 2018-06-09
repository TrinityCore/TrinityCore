-- Larion --> Add gossip option
DELETE FROM `gossip_menu` WHERE `MenuID`=5631;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5631,6742,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=5630;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5630,0,0,"Larion, I want to help you fight these pests!",9138,1,1,5631,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID`=6742;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(6742,"This is some specialized equipment! Don't be handling it carelessly, and of course don't try and operate the thing if you've had too much of that volatile rum I hear you like so much...$B$BSpeaking of which... you don't happen to have any of that nasty stuff, do you?","",9139,0,1,0,0,0,0,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5630;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,5630,0,0,0,8,0,4148,0,0,0,0,0,"","Show gossip option if quest 'Bloodpetal Zapper' is rewarded"),
(15,5630,0,0,0,2,0,11320,1,1,1,0,0,"","Show gossip option if player does not have item 'Bloodpetal Zapper'");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9118;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9118 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9118,0,0,0,62,0,100,0,5630,0,0,0,85,22565,0,0,0,0,0,7,0,0,0,0,0,0,0,"Larion - On Gossip Option 0 Selected - Invoker Cast 'Create Bloodpetal Zapper'");
