-- Awbee
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10740;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10740 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10740,0,0,0,1,0,100,0,1000,15000,30000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Awbee - Out of Combat - Say Line 0"),
(10740,0,1,0,62,0,100,0,3064,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Awbee - Out of Combat - On Gossip Option Selected - Close Gossip");

DELETE FROM `creature_text` WHERE `CreatureID`=10740;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10740,0,0,"%s whimpers.",16,0,100,0,0,0,6270,0,"Awbee"),
(10740,0,1,"%s breathes erratically.",16,0,100,0,0,0,6271,0,"Awbee"),
(10740,0,2,"%s cries for help.",16,0,100,0,0,0,6272,0,"Awbee");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3063,3066,3065,3064);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3063,0,0,"You will be ok, Awbee. Your assailants have been terminated.",6275,1,1,3066,0,0,0,"",0,0),
(3066,0,0,"Continue please...",6277,1,1,3065,0,0,0,"",0,0),
(3065,0,0,"Horrifying.",6279,1,1,3064,0,0,0,"",0,0),
(3064,0,0,"Absolutely.",6281,1,1,0,0,0,0,"",0,0);
