-- Remove bad gossip linking (linking to same gossip menu option)
UPDATE `gossip_menu_option` SET `action_menu_id`=0 WHERE  `menu_id`=8036 AND `id`=0;
UPDATE `creature_template` SET `flags_extra`=0 WHERE  `entry`=20218;

DELETE FROM `creature` WHERE  `id`=21267; -- Delete mana beasts as these are duplicated as are summoned by sunfury nethermancer and permament spawn also exists so these are duplicated.

UPDATE `creature_template` SET `gossip_menu_id`=8046 WHERE  `entry`=20397;
UPDATE `creature_template` SET `gossip_menu_id`=8041 WHERE  `entry`=19831;
UPDATE `creature_template` SET `gossip_menu_id`=8040 WHERE  `entry`=19830;


DELETE FROM `gossip_menu` WHERE `entry`IN(8036,8113,8115,8116,8046,8045,8041,8042,8040,8039);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8036, 10045), 
(8036, 9922), 
(8113, 10045), 
(8113, 9922), 
(8115, 10045), 
(8115, 9922), 
(8116, 10045),
(8116, 9922),
(8046, 9931), -- 20397
(8045, 9934), -- 20397
(8041, 9929), -- 19831
(8042, 9930), -- 19831
(8040, 9926), -- 19830
(8039, 9927); -- 19830

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(35016,35176);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 35016, 0, 0, 31, 0, 3, 20226, 0, 0, 0, 0, '', 'Interrupt Shutdown only hits Netherstorm Repair Target'),
(13, 1, 35176, 0, 0, 31, 0, 3, 20226, 0, 0, 0, 0, '', 'Interrupt Shutdown only hits Netherstorm Repair Target');

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(8036, 8113,8115,8116,8046,8041,8040);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 

(8036, 0, 0, '<Begin emergency shutdown.>', 18119, 1, 1, 0, 0, 0, 0, '', 0), 
(8113, 0, 0, '<Begin emergency shutdown.>', 18119, 1, 1, 0, 0, 0, 0, '', 0), 
(8115, 0, 0, '<Begin emergency shutdown.>', 18119, 1, 1, 0, 0, 0, 0, '', 0), 
(8116, 0, 0, '<Begin emergency shutdown.>', 18119, 1, 1, 0, 0, 0, 0, '', 0),
(8046, 0, 0, 'Where did this technology come from?', 17475, 1, 1, 8045, 0, 0, 0, '', 0),
(8041, 0, 0, 'Who attacked Manaforge Duro?', 17464, 1, 1, 8042, 0, 0, 0, '', 0),
(8040, 0, 0, 'Ultris?', 17444, 1, 1, 8039, 0, 0, 0, '', 0);



DELETE FROM `creature_text` WHERE  `entry`IN(20209,20417,20418,20440) AND `groupid`=5;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(20209, 5, 0, 'Manaforge shutdown aborted.  Resuming manaforge activity.', 16, 0, 100, 0, 0, 0, 'manaforge_control fail', 17886),
(20417, 5, 0, 'Manaforge shutdown aborted.  Resuming manaforge activity.', 16, 0, 100, 0, 0, 0, 'manaforge_control fail', 17886),
(20418, 5, 0, 'Manaforge shutdown aborted.  Resuming manaforge activity.', 16, 0, 100, 0, 0, 0, 'manaforge_control fail', 17886),
(20440, 5, 0, 'Manaforge shutdown aborted.  Resuming manaforge activity.', 16, 0, 100, 0, 0, 0, 'manaforge_control fail', 17886);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup` IN(8036,8113,8115,8116);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8036, 0, 0, 0, 9, 0, 10299, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8036, 0, 0, 0, 2, 0, 29366, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got B''naar Access Crystal'),
(15, 8036, 0, 0, 1, 9, 0, 10329, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8036, 0, 0, 1, 2, 0, 29366, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got B''naar Access Crystal'),
(15, 8113, 0, 0, 0, 9, 0, 10330, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8113, 0, 0, 0, 2, 0, 29396, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Coruu Access Crystal'),
(15, 8113, 0, 0, 1, 9, 0, 10321, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8113, 0, 0, 1, 2, 0, 29396, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Coruu Access Crystal'),
(15, 8115, 0, 0, 0, 9, 0, 10338, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8115, 0, 0, 0, 2, 0, 29397, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Duru Access Crystal'),
(15, 8115, 0, 0, 1, 9, 0, 10322, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8115, 0, 0, 1, 2, 0, 29397, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Duru Access Crystal'),
(15, 8116, 0, 0, 0, 9, 0, 10365, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8116, 0, 0, 0, 2, 0, 29411, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Ara Access Crystal'),
(15, 8116, 0, 0, 1, 9, 0, 10323, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest marked as taken'),
(15, 8116, 0, 0, 1, 2, 0, 29411, 1, 0, 0, 0, 0, '', 'Only show gossip option if Player Has got Ara Access Crystal'),

(14, 8036, 9922, 0, 0, 2, 0, 29366, 1, 0, 1, 0, 0, '', 'Only show npc text if Player does not have B''naar Access Crystal'),
(14, 8113, 9922, 0, 0, 2, 0, 29396, 1, 0, 1, 0, 0, '', 'Only show npc text if Player does not have Coruu Access Crystal'),
(14, 8115, 9922, 0, 0, 2, 0, 29397, 1, 0, 1, 0, 0, '', 'Only show npc text if Player does not have Duru Access Crystal'),
(14, 8116, 9922, 0, 0, 2, 0, 29411, 1, 0, 1, 0, 0, '', 'Onlyshow npc text if Player does not have Ara Access Crystal'),
(14, 8036, 10045, 0, 0, 2, 0, 29366, 1, 0, 0, 0, 0, '', 'Only show npc text if Player has B''naar Access Crystal'),
(14, 8113, 10045, 0, 0, 2, 0, 29396, 1, 0, 0, 0, 0, '', 'Only show npc text if Player has Coruu Access Crystal'),
(14, 8115, 10045, 0, 0, 2, 0, 29397, 1, 0, 0, 0, 0, '', 'Only show npc text if Player has Duru Access Crystal'),
(14, 8116, 10045, 0, 0, 2, 0, 29411, 1, 0, 0, 0, 0, '', 'Onlyshow npc text if Player has Ara Access Crystal');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI',`ScriptName`= '' WHERE  `entry`IN(183770,183956,184311,184312);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(183770,183956,184311,184312) and `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(18377000,18395600,18431100,18431200) and `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(183770,1,0,1,62,0,100,0,8036,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'B''naar Control Console - On Gossip Option Select - Store Target List'),
(183770,1,1,2,61,0,100,0,0,0,0,0,12,20209,1,120000,0,0,0,8,0,0,0,2918.95, 4189.98, 161.88, 0.34,'B''naar Control Console - Linked with previous event - Summon B''naar Control Console'),
(183770,1,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console - Linked with previous event - Send Targetlist to B''naar Control Console'),
(183770,1,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'B''naar Control Console - Linked with previous event - Close Gossip'),
(183770,1,4,0,61,0,100,0,0,0,0,0,80,18377000,2,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console - Linked with previous event - Run Script'),
(183770,1,5,6,38,0,100,0,1,1,2000,2000,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console - On Data Set - Fail Quest'),
(183770,1,6,7,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console - On Data Set - Say'),
(183770,1,7,8,61,0,100,0,0,0,0,0,45,7,7,0,0,0,0,19,20209,0,0,0,0,0,0,'Ara Control Console - On Data Set - Set Data'),
(183770,1,8,0,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console - On Data Set - Reset Scripts'),
(18377000,9,0,0,0,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console - Linked with previous event - Run Script'),
(18377000,9,1,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console - Script - Set Data B''naar Control Console'),
(18377000,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,3,0,0,0,100,0,29000,29000,0,0,45,2,2,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,4,0,0,0,100,0,30000,30000,0,0,45,3,3,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,5,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,6,0,0,0,100,0,30000,30000,0,0,45,4,4,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,7,0,0,0,100,0,20000,20000,0,0,45,5,5,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,8,0,0,0,100,0,10000,10000,0,0,45,6,6,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,9,0,0,0,100,0,0,0,0,0,45,8,8,0,0,0,0,19,20209,0,0,0,0,0,0,'B''naar Control Console Script - Set Data B''naar Control Console'),
(18377000,9,10,0,0,0,100,0,0,0,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console Script - Set Flags'),
(183956,1,0,1,62,0,100,0,8113,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Coruu Control Console - On Gossip Option Select - Store Target List'),
(183956,1,1,2,61,0,100,0,0,0,0,0,12,20417,1,120000,0,0,0,8,0,0,0,2426.77, 2750.38, 133.24, 2.14,'Coruu Control Console - Linked with previous event - Summon Coruu Control Console'),
(183956,1,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console - Linked with previous event - Send Targetlist to Coruu Control Console'),
(183956,1,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Coruu Control Console - Linked with previous event - Close Gossip'),
(183956,1,4,0,61,0,100,0,0,0,0,0,80,18395600,2,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console - Linked with previous event - Run Script'),
(183956,1,5,6,38,0,100,0,1,1,2000,2000,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console - On Data Set - Fail Quest'),
(183956,1,6,7,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console - On Data Set - Say'),
(183956,1,7,8,61,0,100,0,0,0,0,0,45,7,7,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console - On Data Set - Set Data'),
(183956,1,8,0,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console - On Data Set - Reset Scripts'),
(18395600,9,0,0,0,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console - Linked with previous event - Run Script'),
(18395600,9,1,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console - Script - Set Data Coruu Control Console'),
(18395600,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,3,0,0,0,100,0,19000,19000,0,0,45,2,2,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,4,0,0,0,100,0,20000,20000,0,0,45,2,2,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,5,0,0,0,100,0,20000,20000,0,0,45,2,2,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,6,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,8,0,0,0,100,0,20000,20000,0,0,45,2,2,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,9,0,0,0,100,0,10000,10000,0,0,45,4,4,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,10,0,0,0,100,0,10000,10000,0,0,45,8,8,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,11,0,0,0,100,0,10000,10000,0,0,45,5,5,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,12,0,0,0,100,0,10000,10000,0,0,45,6,6,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,13,0,0,0,100,0,0,0,0,0,45,8,8,0,0,0,0,19,20417,0,0,0,0,0,0,'Coruu Control Console Script - Set Data Coruu Control Console'),
(18395600,9,14,0,0,0,100,0,0,0,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console Script - Set Flags'),
(184311,1,0,1,62,0,100,0,8115,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Duru Control Console - On Gossip Option Select - Store Target List'),
(184311,1,1,2,61,0,100,0,0,0,0,0,12,20418,1,120000,0,0,0,8,0,0,0,2976.48, 2183.29, 163.20, 1.85,'Duru Control Console - Linked with previous event - Summon Duru Control Console'),
(184311,1,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console - Linked with previous event - Send Targetlist to Duru Control Console'),
(184311,1,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Duru Control Console - Linked with previous event - Close Gossip'),
(184311,1,4,0,61,0,100,0,0,0,0,0,80,18431100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - Linked with previous event - Run Script'),
(184311,1,5,6,38,0,100,0,1,1,2000,2000,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - On Data Set - Fail Quest'),
(184311,1,6,7,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console - On Data Set - Say'),
(184311,1,7,8,61,0,100,0,0,0,0,0,45,7,7,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console - On Data Set - Set Data'),
(184311,1,8,9,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - On Data Set - Reset Scripts'),
(18431100,9,0,0,0,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - Linked with previous event - Run Script'),
(18431100,9,1,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console - Script - Set Data Duru Control Console'),
(18431100,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,3,0,0,0,100,0,14000,14000,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,4,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,5,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,6,0,0,0,100,0,15000,15000,0,0,45,3,3,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,7,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,8,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,9,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,10,0,0,0,100,0,15000,15000,0,0,45,4,4,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,11,0,0,0,100,0,5000,5000,0,0,45,5,5,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,12,0,0,0,100,0,10000,10000,0,0,45,6,6,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,13,0,0,0,100,0,0,0,0,0,45,8,8,0,0,0,0,19,20418,0,0,0,0,0,0,'Duru Control Console Script - Set Data Duru Control Console'),
(18431100,9,14,0,0,0,100,0,0,0,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console Script - Set Flags'),
(184312,1,0,1,62,0,100,0,8116,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ara Control Console - On Gossip Option Select - Store Target List'),
(184312,1,1,2,61,0,100,0,0,0,0,0,12,20440,1,120000,0,0,0,8,0,0,0,4013.71, 4028.76, 192.10, 1.25,'Ara Control Console - Linked with previous event - Summon Ara Control Console'),
(184312,1,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console - Linked with previous event - Send Targetlist to Ara Control Console'),
(184312,1,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ara Control Console - Linked with previous event - Close Gossip'),
(184312,1,4,0,61,0,100,0,0,0,0,0,80,18431200,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - Linked with previous event - Run Script'),
(184312,1,5,6,38,0,100,0,1,1,2000,2000,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - On Data Set - Fail Quest'),
(184312,1,6,7,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console - On Data Set - Say'),
(184312,1,7,8,61,0,100,0,0,0,0,0,45,7,7,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console - On Data Set - Set Data'),
(184312,1,0,0,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - On Data Set - Reset Scripts'),
(18431200,9,0,0,0,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - Linked with previous event - Run Script'),
(18431200,9,1,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console - Script - Set Data Ara Control Console'),
(18431200,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,3,0,0,0,100,0,14000,14000,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,4,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,5,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,6,0,0,0,100,0,15000,15000,0,0,45,3,3,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,7,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,8,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,9,0,0,0,100,0,15000,15000,0,0,45,2,2,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,10,0,0,0,100,0,15000,15000,0,0,45,4,4,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,11,0,0,0,100,0,5000,5000,0,0,45,5,5,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,12,0,0,0,100,0,10000,10000,0,0,45,6,6,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,13,0,0,0,100,0,0,0,0,0,45,8,8,0,0,0,0,19,20440,0,0,0,0,0,0,'Ara Control Console Script - Set Data Ara Control Console'),
(18431200,9,14,0,0,0,100,0,0,0,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console Script - Set Flags');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN(183770,183956,184311,184312);

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE  `entry` IN(20209,20218, 20226, 20417,20418, 20436, 20440, 20438, 20439, 20460);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(20209,20218,20226,20417, 20418, 20436, 20440, 20438, 20439, 20460) and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2020900, 2020901,2041700,2041800,2044000,2044001,2022600,2022601,2022602,2022603,2021800,2021801,2021802,2021803,2021804,2021804,2021805,2043900,2043901,2021806) and `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20209, 0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console - On Data Set 1 1 - Say'),
(20209, 0,1,0,38,0,100,0,2,2,0,0,87,2020900,2020901,0,0,0,0,1,0,0,0,0, 0, 0, 0,'B''naar Control Console - On Data Set 2 2 - Run Randomscript'),
(20209, 0,2,0,38,0,100,0,3,3,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console - On Data Set 3 3 - Say'),
(20209, 0,3,4,38,0,100,0,4,4,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console - On Data Set 4 4 - Say'),
(20209, 0,4,5,61,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2946.52, 4201.42, 163.47, 3.54,'B''naar Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20209, 0,5,6,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Linked with Previous Event - Send Target list to Sunfury Technician'),
(20209, 0,6,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Linked with Previous Event - Set Data to to Sunfury Technician'),
(20209, 0,7,0,38,0,100,0,5,5,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console - On Data Set 5 5 - Say'),
(20209, 0,8,10,38,0,100,0,6,6,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console - On Data Set 6 6 - Say'),
(20209, 0,9,0,38,0,100,0,7,7,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'B''naar Control Console - On Data Set 7 7 - Despawn'),
(20209, 0,10,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,20226,0,0,0,0,0,0,'B''naar Control Console - On Data Set 6 6 - Set Data Manaforge Visual Trigger'),
(20209 ,0,11,12,38,0,100,0,8,8,0,0,33,20209,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console Script - Give Kill Credit'),
(20209 ,0,12,13,61,0,100,0,0,0,0,0,15,10299,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console Script - Give Kill Credit'),
(20209 ,0,13,0,61,0,100,0,0,0,0,0,15,10329,0,0,0,0,0,12,1,0,0,0,0,0,0,'B''naar Control Console Script - Give Kill Credit'),
(2020900, 9,0,0,0,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2927.36, 4212.97, 164.00, 4.94,'B''naar Control Console - Script 1 - Summon Sunfury Technician'),
(2020900, 9,1,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Script 1 - Send Target list to Sunfury Technician'),
(2020900, 9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Script 1 - Set Data to to Sunfury Technician'),
(2020901, 9,0,0,0,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2933.68, 4162.55, 164.00, 1.60,'B''naar Control Console - Script 2 - Summon Sunfury Technician'),
(2020901, 9,1,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Script 2 - Send Target list to Sunfury Technician'),
(2020901, 9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'B''naar Control Console - Script 2 - Set Data to to Sunfury Technician'),
(20417, 0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console - On Data Set 1 1 - Say'),
(20417, 0,1,0,38,0,100,0,2,2,0,0,80,2041700,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Coruu Control Console - On Data Set 2 2 - Run Script'),
(20417, 0,2,0,38,0,100,0,3,3,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console - On Data Set 3 3 - Say'),
(20417, 0,3,0,38,0,100,0,4,4,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console - On Data Set 4 4 - Say'),
(20417, 0,4,5,38,0,100,0,8,8,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2453.88, 2737.85, 133.27, 2.59,'Coruu Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20417, 0,5,6,61,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2441.62, 2735.32, 134.49, 1.97,'Coruu Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20417, 0,6,7,61,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2450.73, 2754.50, 134.49, 3.29,'Coruu Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20417, 0,7,8,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Coruu Control Console - Linked with Previous Event - Send Target list to Sunfury Technician'),
(20417, 0,8,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Coruu Control Console - Linked with Previous Event - Set Data to to Sunfury Technician'),
(20417, 0,9,0,38,0,100,0,5,5,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console - On Data Set 5 5 - Say'),
(20417, 0,10,12,38,0,100,0,6,6,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console - On Data Set 6 6 - Say'),
(20417, 0,11,0,38,0,100,0,7,7,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Coruu Control Console - On Data Set 7 7 - Despawn'),
(20417, 0,12,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,20226,0,0,0,0,0,0,'Coruu Control Console - On Data Set 6 6 - Set Data Manaforge Visual Trigger'),
(20417 ,0,13,14,38,0,100,0,8,8,0,0,33,20417,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coruu Control Console Script - Give Kill Credit'),
(20417 ,0,14,15,61,0,100,0,0,0,0,0,15,10330,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coru Control Console Script - Give Kill Credit'),
(20417 ,0,13,0,61,0,100,0,0,0,0,0,15,10321,0,0,0,0,0,12,1,0,0,0,0,0,0,'Coru Control Console Script - Give Kill Credit'),
(2041700, 9,0,0,0,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2445.21, 2765.26, 134.49, 3.93,'Coruu Control Console - Script - Summon Sunfury Technician'),
(2041700, 9,1,0,0,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2429.86, 2731.85, 134.53, 1.31,'Coruu Control Console - Script - Summon Sunfury Technician'),
(2041700, 9,2,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Coruu Control Console - Script - Send Target list to Sunfury Technician'),
(2041700, 9,3,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Coruu Control Console - Script - Set Data to to Sunfury Technician'),
(20418, 0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console - On Data Set 1 1 - Say'),
(20418, 0,1,0,38,0,100,0,2,2,0,0,80,2041800,2,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - On Data Set 2 2 - Run Script'),
(20418, 0,2,0,38,0,100,0,3,3,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console - On Data Set 3 3 - Say'),
(20418, 0,3,4,38,0,100,0,4,4,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console - On Data Set 4 4 - Say'),
(20418, 0,4,5,61,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2956.18, 2202.85, 165.32, 5.45,'Duru Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20418, 0,5,6,61,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2975.30, 2211.50, 165.32, 4.55,'Duru Control Console - Linked with Previous Event - Summon Sunfury Technician'),
(20418, 0,6,7,61,0,100,0,0,0,0,0,12,20436,1,120000,1,0,0,8,0,0,0,2965.02, 2217.45, 164.16, 4.96,'Duru Control Console - Linked with Previous Event - Summon Sunfury Protector'),
(20418, 0,7,8,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Duru Control Console - Linked with Previous Event - Send Target list to Sunfury Technician'),
(20418, 0,8,9,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20436,0,200,0, 0, 0, 0,'Duru Control Console - Linked with Previous Event - Send Target list to Sunfury Protector'),
(20418, 0,9,10,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Duru Control Console - Linked with Previous Event - Set Data to to Sunfury Technician'),
(20418, 0,10,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,20436,0,200,0, 0, 0, 0,'Duru Control Console - Linked with Previous Event - Set Data to to Sunfury Protector'),
(20418, 0,11,0,38,0,100,0,5,5,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console - On Data Set 5 5 - Say'),
(20418, 0,12,14,38,0,100,0,6,6,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console - On Data Set 6 6 - Say'),
(20418, 0,13,0,38,0,100,0,7,7,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Duru Control Console - On Data Set 7 7 - Despawn'),
(20418, 0,14,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,20226,0,0,0,0,0,0,'Duru Control Console - On Data Set 6 6 - Set Data Manaforge Visual Trigger'),
(20418 ,0,15,16,38,0,100,0,8,8,0,0,33,20418,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console Script - Give Kill Credit'),
(20418 ,0,16,17,61,0,100,0,0,0,0,0,15,10338,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console Script - Give Kill Credit'),
(20418 ,0,17,0,61,0,100,0,0,0,0,0,15,10322,0,0,0,0,0,12,1,0,0,0,0,0,0,'Duru Control Console Script - Give Kill Credit'),
(2041800, 9,0,0,0,0,100,0,2,2,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2986.80, 2205.36, 165.37, 3.74,'Duru Control Console - Script - Summon Sunfury Technician'),
(2041800, 9,1,0,0,0,100,0,0,0,0,0,12,20218,1,120000,1,0,0,8,0,0,0,2952.91, 2191.20, 165.32, 0.22,'Duru Control Console - Script - Summon Sunfury Technician'),
(2041800, 9,2,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Duru Control Console - Script - Send Target list to Sunfury Technician'),
(2041800, 9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,20218,0,200,0, 0, 0, 0,'Duru Control Console - Script - Set Data to to Sunfury Technician'),
(20440, 0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console - On Data Set 1 1 - Say'),
(20440, 0,1,0,38,0,100,0,2,2,0,0,87,2044000,2044001,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - On Data Set 2 2 - Run Random Script'),
(20440, 0,2,0,38,0,100,0,3,3,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console - On Data Set 3 3 - Say'),
(20440, 0,3,4,38,0,100,0,4,4,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console - On Data Set 4 4 - Say'),
(20440, 0,4,5,61,0,100,0,0,0,0,0,12,20439,1,120000,1,0,0,8,0,0,0,3994.51, 4020.46, 192.18, 0.91,'Ara Control Console - Linked with Previous Event - Summon Ara Engineer'),
(20440, 0,5,6,61,0,100,0,0,0,0,0,12,20460,1,120000,1,0,0,8,0,0,0,4021.56, 4059.35, 193.59, 4.44,'Ara Control Console - Linked with Previous Event - Summon Chief Engineer Gork lonn'),
(20440, 0,6,7,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20239,0,200,0, 0, 0, 0,'Ara Control Console - Linked with Previous Event - Send Target list to Ara Engineer'),
(20440, 0,7,8,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20460,0,200,0, 0, 0, 0,'Ara Control Console - Linked with Previous Event - Send Target list to Chief Engineer Gork lonn'),
(20440, 0,8,9,61,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,20239,0,200,0, 0, 0, 0,'Ara Control Console - Linked with Previous Event - Set Data to to Ara Engineer'),
(20440, 0,9,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,20460,0,200,0, 0, 0, 0,'Ara Control Console - Linked with Previous Event - Set Data to to Chief Engineer Gork lonn'),
(20440, 0,10,0,38,0,100,0,5,5,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console - On Data Set 5 5 - Say'),
(20440, 0,11,13,38,0,100,0,6,6,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console - On Data Set 6 6 - Say'),
(20440, 0,12,0,38,0,100,0,7,7,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ara Control Console - On Data Set 7 7 - Despawn'),
(20440, 0,13,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,20226,0,0,0,0,0,0,'Ara Control Console - On Data Set 6 6 - Set Data Manaforge Visual Trigger'),
(20440 ,0,14,15,38,0,100,0,8,8,0,0,33,20440,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console Script - Give Kill Credit'),
(20440 ,0,15,16,61,0,100,0,0,0,0,0,15,10365,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console Script - Give Kill Credit'),
(20440 ,0,16,0,61,0,100,0,0,0,0,0,15,10323,0,0,0,0,0,12,1,0,0,0,0,0,0,'Ara Control Console Script - Give Kill Credit'),
(2044000, 9,0,0,0,0,100,0,2,2,0,0,12,20438,1,120000,1,0,0,8,0,0,0,4035.11, 4038.97, 194.27, 2.57,'Ara Control Console - Script 1 - Summon Ara Technician'),
(2044000, 9,1,0,0,0,100,0,0,0,0,0,12,20438,1,120000,1,0,0,8,0,0,0,4033.66, 4036.79, 194.28, 2.57,'Ara Control Console - Script 1 - Summon Ara Technician'),
(2044000, 9,2,0,0,0,100,0,0,0,0,0,12,20438,1,120000,1,0,0,8,0,0,0,4037.13, 4037.30, 194.23, 2.57,'Ara Control Console - Script 1 - Summon Ara Technician'),
(2044000, 9,3,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20438,0,200,0, 0, 0, 0,'Ara Control Console - Script 1 - Send Target list to Ara Technician'),
(2044000, 9,4,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,20438,0,200,0, 0, 0, 0,'Ara Control Console - Script 1 - Set Data to to Ara Technician'),
(2044001, 9,0,0,0,0,100,0,2,2,0,0,12,20438,1,120000,1,0,0,8,0,0,0,3099.59, 4049.30, 194.22, 0.05,'Ara Control Console - Script 2 - Summon Ara Technician'),
(2044001, 9,1,0,0,0,100,0,0,0,0,0,12,20438,1,120000,1,0,0,8,0,0,0,3999.72, 4046.75, 194.22, 0.05,'Ara Control Console - Script 2 - Summon Ara Technician'),
(2044001, 9,2,0,0,0,100,0,0,0,0,0,12,20438,1,120000,1,0,0,8,0,0,0,3996.81, 4048.26, 194.22, 0.05,'Ara Control Console - Script 2 - Summon Ara Technician'),
(2044001, 9,3,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,20438,0,200,0, 0, 0, 0,'Ara Control Console - Script 1 - Send Target list to Ara Technician'),
(2044001, 9,4,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,20438,0,200,0, 0, 0, 0,'Ara Control Console - Script 1 - Set Data to to Ara Technician'),
(20218, 0,0,0,54,0,40,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Just Summoned - Say'),
(20218, 0,1,2,38,0,100,1,1,1,0,0,8,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,2,0,61,0,100,0,0,0,0,0,87,2021800,2021801,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,3,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,183770,0,0,0, 0, 0, 0,'Sunfury Technician - OOC (Phase 1) - Set Data'),
(20218, 0,4,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,183956,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(20218, 0,5,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,184311,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(20218, 0,6,0,40,0,100,0,1,0,0,0,80,2021806,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Reached WP1 - Cast Interrupt Shutdown'),
(20218, 0,7,8,4,0,100,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Agro - Set Phase 0'),
(20218, 0,8,9,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20218, 0,9,10,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20218, 0,10,0,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20218, 0,11,12,38,0,100,1,2,2,0,0,8,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,12,0,61,0,100,0,0,0,0,0,87,2021801,2021802,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,13,14,38,0,100,1,3,3,0,0,8,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,14,0,61,0,100,0,0,0,0,0,87,2021803,2021804,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Data Set - Set Defensive'),
(20218, 0,15,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,183770,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(20218, 0,16,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,183956,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(20218, 0,17,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184311,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(2021806, 9,0,0,0,0,100,0,1,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0, 0, 0, 3.6,'Sunfury Technician - On Reached WP1 - Cast Interrupt Shutdown'),
(2021806, 9,1,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),
(2021806, 9,2,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Agro - Set Phase 0'),
(2021806, 9,3,0,0,0,100,0,1000,1000,0,0,11,35016,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Reached WP1 Set Phase 1'),



(2021800, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021800,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(2021801, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021801,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(2021802, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021802,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(2021803, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021803,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(2021804, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021804,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(2021805, 9,0,0,0,0,100,0,0,0,0,0,53,1,2021805,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - Script - Start wp'),
(20436, 0,0,0,38,2,100,0,1,1,0,0,49,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,'Sunfury Protector - On Data Set - Attack Stored Target'),
(20436, 0,1,0,54,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Protector - On Just Summoned - Set Phase 2'),
(20436, 0,2,0,1,2,100,0,1000,1000,1000,1000,49,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,'Sunfury Protector - OOC - Attack'),
(20438, 0,0,1,38,0,100,0,4,4,0,0,8,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - On Data Set - Set Defensive'),
(20438, 0,1,0,61,0,100,0,0,0,0,0,87,2043900,2043901,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - On Data Set - Set Defensive'),
(20438, 0,2,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,184312,0,0,0, 0, 0, 0,'Ara Engineer - OOC (Phase 1) - Set Data'),
(20438, 0,3,4,40,0,100,0,1,0,0,0,11,35176,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - On Reached WP1 - Cast Interrupt Shutdown'),
(20438, 0,4,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - On Reached WP1 Set Phase 1'),
(20438, 0,5,6,4,0,100,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - On Agro - Set Phase 0'),
(20438, 0,6,7,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20438, 0,7,8,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20438, 0,8,0,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On agro - Set agressive'),
(20438, 0,9,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184312,0,0,0, 0, 0, 0,'Ara Techician - On Evade - Set Data'),
(20439, 0,3,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,'Ara Technician - On Data Set - Attack Stored Target'),
(20439, 0,6,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184312,0,0,0, 0, 0, 0,'Ara Techician - On Evade - Set Data'),
(20438, 0,13,0,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Sunfury Technician - On Evade - Set Data'),

(2043900, 9,0,0,0,0,100,0,0,0,0,0,53,1,2043900,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - Script - Start wp'),
(2043901, 9,0,0,0,0,100,0,0,0,0,0,53,1,2043901,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Ara Engineer - Script - Start wp'),
(20460, 0,0,0,38,2,100,0,1,1,0,0,49,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,'Chief Engineer Gork lonn - On Data Set - Attack Stored Target'),
(20460, 0,1,2,7,2,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184312,0,0,0, 0, 0, 0,'Chief Engineer Gork lonn - On Evade - Set Data'),
(20460, 0,2,0,61,2,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Chief Engineer Gork lonn - On Evade - Despawn'),
(20460, 0,3,0,54,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Chief Engineer Gork lonn - On Just Summoned - Set Phase 2'),
(20460, 0,4,0,1,2,100,0,1000,1000,1000,1000,49,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,'Chief Engineer Gork lonn - OOC - Attack'),
(20226, 0,0,1,38,0,100,0,1,1,0,0,11,35031,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Manaforge Visual Trigger - On Data Set - Cast Manaforge Disable Visual'),
(20226, 0,1,0,61,0,100,0,0,0,0,0,50,184954,60000,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Manaforge Visual Trigger - On Data Set - Summon Manaforge Smoke');

DELETE FROM `creature_text` WHERE `entry`=20218;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(20218, 0, 0, 'Stop the emergency shutdown! Kael will have our heads if he hears about this!', 12, 0, 100, 0, 0, 0, 'Sunfury Technician', 17931),
(20218, 0, 1, 'Stop this immediately!', 12, 0, 100, 0, 0, 0, 'Sunfury Technician', 18131),
(20218, 0, 2, 'The naaru''s emergency shutdown will disable the manaforge permanently! It must be aborted!', 12, 0, 100, 0, 0, 0, 'Sunfury Technician', 17932);


DELETE FROM `waypoints` WHERE `entry` IN(2021800,2021801,2021802,2021803,2021804,2021805,2043900,2043901);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2021800,1, 2918.929199, 4180.713379, 161.866867,'Manforge B''naar cast point 1'),
(2021801,1, 2911.797852, 4196.943848, 161.883194,'Manforge B''naar cast point 2'),
(2021802,1, 2417.708252, 2748.968018, 132.415741,'Manforge Coruu cast point 1'),
(2021803,1, 2424.118652, 2765.202637, 132.368378,'Manforge Coruu cast point 2'),
(2021804,1, 2969.341797, 2175.692383, 163.197601,'Manforge Duru cast point 1'),
(2021805,1, 2986.231201, 2184.670166, 163.204178,'Manforge Duru cast point 2'),
(2043900,1, 4004.417969, 4033.558105, 192.624023,'Manforge Ara cast point 1'),
(2043901,1, 4024.727295, 4027.472656, 192.559723,'Manforge Ara cast point 2');

