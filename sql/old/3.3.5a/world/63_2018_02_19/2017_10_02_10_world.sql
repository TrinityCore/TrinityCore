-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8899, 8886);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8899, 0, 0, "Please loan me that spyglass.", 22806, 1, 1, 8928, 0, 0, 0, "", 0, 0),
(8886, 0, 0, "Sergeant, loan me your spyglass.", 22774, 1, 1, 8928, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8899, 8886);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8899, 0, 0, 0, 8, 0, 11256, 0, 0, 0, 0, 0, "", "Gossip option requires quest 'Skorn Must Fall!' rewarded AND"),
(15, 8899, 0, 0, 0, 2, 0, 33341, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Brave's Spyglass' NOT in inventory or bank"),
(15, 8886, 0, 0, 0, 8, 0, 11248, 0, 0, 0, 0, 0, "", "Gossip option requires quest 'Operation: Skornful Wrath' rewarded AND"),
(15, 8886, 0, 0, 0, 2, 0, 33336, 1, 1, 1, 0, 0, "", "Gossip option requires item 'Sergeant's Spyglass' NOT in inventory or bank");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (24130, 24060);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24130, 24060) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24130, 0, 0, 0, 62, 0, 100, 512, 8899, 0, 0, 0, 85, 43103, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Winterhoof Brave - On Gossip Option Selected - Invoker Cast 'Loan Spyglass'"),
(24060, 0, 0, 0, 62, 0, 100, 512, 8886, 0, 0, 0, 85, 43084, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Westguard Sergeant - On Gossip Option Selected - Invoker Cast 'Loan Spyglass'");
