-- Sovik
DELETE FROM `gossip_menu_option` WHERE `MenuID`=980;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(980,0,1,"Hello Sovik, I wish to browse your goods.",3902,3,128,0,0,0,0,"",0,0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3413;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3413 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3413,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Sovik - On Data Set - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3413;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3413,0,0,"Come and have a talk with me if you're going to go to Gnomeregan, $n!",12,0,100,0,0,0,3903,0,"Sovik");

-- Nogg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3412;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3412 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3412,0,0,0,19,0,100,0,2841,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nogg - On Quest 'Rig Wars' Taken - Store Targetlist"),
(3412,0,1,0,19,0,100,0,2841,0,0,0,100,1,0,0,0,0,0,19,3413,0,0,0,0,0,0,"Nogg - On Quest 'Rig Wars' Taken - Send Target to Sovik"),
(3412,0,2,0,19,0,100,0,2841,0,0,0,45,1,1,0,0,0,0,19,3413,0,0,0,0,0,0,"Nogg - On Quest 'Rig Wars' Taken - Set Data to Sovik");
