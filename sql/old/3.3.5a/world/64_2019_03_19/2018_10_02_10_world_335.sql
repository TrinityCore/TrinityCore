-- Warlord Goretooth
UPDATE `creature_template` SET `gossip_menu_id`=2884, `AIName`="SmartAI" WHERE `entry`=9077;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (2884,2885,2886,2887,2888,2889);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2884,3560,0),
(2885,3561,0),
(2886,3562,0),
(2887,3563,0),
(2888,3564,0),
(2889,3565,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2884,2885,2886,2887,2888,2889);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2884,0,0,"What roles?",5971,1,1,2885,0,0,0,"",0,0),
(2885,0,0,"Dreams?",5973,1,1,2886,0,0,0,"",0,0),
(2886,0,0,"I pray for such things.",5975,1,1,2887,0,0,0,"",0,0),
(2887,0,0,"I do not deserve such praise, Warlord Goretooth.",5977,1,1,2888,0,0,0,"",0,0),
(2888,0,0,"Sir! Until my body ceases to function!",5979,1,1,2889,0,0,0,"",0,0),
(2889,0,0,"Yes, sir. Thank you, sir!",5981,1,1,0,0,0,0,"",0,0);

UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3561;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=5 WHERE `ID`=3562;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=66 WHERE `ID`=3563;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=25, `em0_2`=0, `em0_3`=6, `em0_4`=0, `em0_5`=6 WHERE `ID`=3564;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1 WHERE `ID`=3565;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2884;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2884,0,0,0,14,0,4903,0,0,0,0,0,"","Show gossip option if quest 'Warlord's Command' is not taken");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9077 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9077,0,0,0,62,0,100,0,2889,0,0,0,85,16548,2,0,0,0,0,7,0,0,0,0,0,0,0,"Warlord Goretooth - On Gossip Option Selected - Invoker Cast 'Goretooth's Orders'"),
(9077,0,1,0,62,0,100,0,2889,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warlord Goretooth - On Gossip Option Selected - Close Gossip");

DELETE FROM `creature_queststarter` WHERE `quest`=4903;
