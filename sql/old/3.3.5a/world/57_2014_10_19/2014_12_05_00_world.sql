SET @CGUID := 74952;

DELETE FROM `creature` WHERE `id` IN(31314,30698,31306,31428);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31314, 571, 1, 175, 6865.108, 3570.752, 736.0794, 3.01942, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+1, 31314, 571, 1, 175, 6869.777, 3584.097, 735.8923, 2.879793, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+2, 31314, 571, 1, 175, 6866.223, 3574.63, 735.9076, 3.036873, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+3, 31314, 571, 1, 175, 6868.476, 3579.733, 736.1484, 2.949606, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+4, 30698, 571, 1, 175, 6853.651, 3582.979, 738.027, 6.038839, 120, 0, 0), -- 30698 (Area: 4531)
(@CGUID+5, 31306, 571, 1, 175, 6865.82, 3577.979, 736.0449, 2.932153, 120, 0, 0), -- 31306 (Area: 4531)
(@CGUID+6, 31428, 571, 1, 175, 6857.328, 3571.491, 735.8922, 1.151917, 120, 5, 1); -- 31428 (Area: 4531) (possible waypoints or random movement)

DELETE FROM `gossip_menu` WHERE `entry`=10060;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(10060, 13978);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10060;

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(10060, 0, 0, 'Let\'s kill this... thing... and get this over with.', 32118, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN(30698,31314,31306,31428,31301);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(30698, 0, 0x0, 0x1, ''), -- 30698
(31314, 0, 0x0, 0x1, ''), -- 31314
(31306, 0, 0x0, 0x1, '58949'), -- 31306 - 58949
(31428, 28919, 0x0, 0x1, ''), -- 31428
(31301, 0, 0x0, 0x1, '34427'); -- 31301 - 34427

UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=31301;


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(30698,31314,31306,31428,31301);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30698,31314,31306,31428,31301)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3130100)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30698,0,0,1,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Unit Flags'),
(30698,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Hostile'),
(30698,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31306,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Margrave Dhakar'),
(30698,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31428,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Crusader Olakin Sainrith'),
(30698,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,31314,0,200,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Ebon Blade Veteran'),
(30698,0,5,6,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Reset - Set Passive'),
(30698,0,6,0,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Reset - Set Unit Flags'),
(30698,0,7,0,6,0,100,0,0,0,0,0,33,30698,0,0,0,0,0,24,0,0,0,0,0,0,0,'Morbidus - On Death - Kill Credit'),
(31306,0,0,1,62,0,100,0,10060,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Store Targetlist'),
(31306,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Close Gossip'),
(31306,0,2,3,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Set NPC Flags'),
(31306,0,3,4,61,0,100,0,0,0,0,0,12,31301,1,600000,0,0,0,8,0,0,0,6858.596, 3580.5, 736.7512, 5.67232,'Margrave Dhakar - On Gossip Select - Summon The Lich King'),
(31306,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Margrave Dhakar - On Gossip Select - Say Line 0'),
(31306,0,5,6,38,0,100,0,1,1,0,0,8,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Margrave Dhakar - On Data Set 1 1 - Set Hostile'),
(31306,0,6,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Margrave Dhakar - On Data Set 1 1 - Attack Morbidus'),
(31306,0,7,8,7,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Evade - Set Passive'),
(31306,0,8,0,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Evade - Set NPC Flags'),
(31301,0,0,0,11,0,100,0,0,0,0,0,80,3130100,2,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - On Just Summoned - Run Script'),
(31314,0,0,1,38,0,100,0,1,1,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Veteran - On Data Set 1 1 - Set Hostile'),
(31314,0,1,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Ebon Blade Veteran - On Data Set 1 1 - Attack Morbidus'),
(31314,0,2,0,7,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Veteran - On Evade - Set Passive'),
(31428,0,0,1,38,0,100,0,1,1,0,0,2,1770,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Set Faction'),
(31428,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Set Hostile'),
(31428,0,2,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Attack Morbidus'),
(31428,0,3,4,7,0,100,0,1,1,0,0,2,2070,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Evade - Set Faction'),
(31428,0,4,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Evade - Set Passive'),
(3130100,9,0,0,0,0,100,0,100,100,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Cast Ethereal Teleport'),
(3130100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 0'),
(3130100,9,2,0,0,0,100,0,1000,1000,0,0,11,53274,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Cast Icebound Visage'),
(3130100,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 1'),
(3130100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 2'),
(3130100,9,5,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 3'),
(3130100,9,6,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 4'),
(3130100,9,7,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,31428,0,0,0,0,0,0,'The Lich King - Script - Say Line 0 (Crusader Olakin Sainrith)'),
(3130100,9,8,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,30698,0,0,0,0,0,0,'The Lich King - Script - Set Data 1 1 on Morbidus'),
(3130100,9,9,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Despawn');

UPDATE `smart_scripts` SET `event_type`=7 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=28 AND `link`=0;

DELETE FROM `conditions`  WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10060;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10060, 0, 0, 0, 29, 0, 30698, 200, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if Morbidus near'),
(15, 10060, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if Morbidus is alive'),
(15, 10060, 0, 0, 0, 9, 0, 13235, 0, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if player has The Flesh Giant Champion taken');
