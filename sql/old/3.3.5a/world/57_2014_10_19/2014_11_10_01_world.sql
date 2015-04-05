DELETE FROM `creature_text` WHERE `entry`IN(26810,26379,26437);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(26810, 0, 0, 'Gather, brothers and sisters.', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26136),
(26810, 1, 0, '%s reads from the scroll as the other Taunka gather around him.', 16, 1, 100, 0, 0, 0, 'Roanauk Icemist',26130),
(26810, 2, 0, 'Lok''tar ogar! Victory or death - it is these words that bind me to the Horde! For they are the most sacred and fundamental of truths to any warrior of the Horde.', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26137),
(26810, 3, 0, 'I give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command!', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26138),
(26810, 4, 0, 'From this moment until the end of days I live and die - For the Horde!', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26139),
(26810, 5, 0, 'For my Taunka brothers and sisters! FOR THE HORDE!', 14, 1, 100, 388, 0, 0, 'Roanauk Icemist',26140),
(26379, 0, 0, 'We will walk together, $n.', 12, 1, 100, 1, 0, 0, 'Overlord Agmar',26131),
(26379, 1, 0, 'Welcome to the Horde, High Chief. Lok''tar ogar!', 12, 1, 100, 2, 0, 0, 'Overlord Agmar',26141),
(26379, 2, 0, 'FOR THE HORDE!', 14, 1, 100, 15, 0, 0, 'Overlord Agmar',26142),
(26437, 0, 0, 'Amidst the tragedy and chaos, this place stands defiantly against the Scourge! It is good to be Horde.', 12, 1, 100, 113, 0, 0, 'Taunka Soldier',25727);

UPDATE`creature` SET `position_x`=3842.386, `position_y`=1486.616, `position_z`=92.06059, `orientation`=1.570796 WHERE  `guid`=97430;

DELETE FROM `creature_addon` WHERE  `guid`=97430;

DELETE FROM `creature_template_addon` WHERE `entry`IN(26379);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(26379, 0, 0x6, 0x101, '47786'); -- 26379 - 47786


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(26379,26437,26810);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26379,26437,26810,-102329,-102341,-102330,-102328,-102326,-102333,-102327,-102326) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2681000) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26379, 0, 0, 1, 19, 0, 100, 0, 12140, 0, 0, 0, 81, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Npc Flags'),
(26379, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 91, 257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Bytes 1'),
(26379, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Say Line 1'),
(26379, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 26379, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Start WP'),
(26379, 0, 4, 0, 40, 0, 100, 0, 10, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On reached WP10 - Set Orientation'),
(26379, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Data Set - Evade'),
(26379, 0, 6, 0, 21, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Reached Home - Set Unit Flags'),
(26810, 0, 0, 1, 62, 0, 100, 0, 9462, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Store Targetlist'),
(26810, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Close Gossip'),
(26810, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Set NPC Flags'),
(26810, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 26437, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Set Data Taunka Soldier'),
(26810, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2681000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Run Script'),
(-102329, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65539, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102329, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643700, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102329, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102329, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102341, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65539, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102341, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643701, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102341, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102341, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102330, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102330, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643702, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102330, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102330, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102328, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102328, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643703, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102328, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102328, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102326, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65537, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102326, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643704, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102326, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102326, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102333, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65537, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102333, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643705, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102333, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102333, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102327, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102327, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643706, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102327, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102327, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(2681000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1'),
(2681000, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 2'),
(2681000, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 3'),
(2681000, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 4'),
(2681000, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 5'),
(2681000, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1 on Overlord Agmar'),
(2681000, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 15, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Play emote OneShotRoar'),
(2681000, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 33, 26810, 0, 0,  0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Give Kill Credit'),
(2681000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 388, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Play emote OneShotStomp'),
(2681000, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 6'),
(2681000, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 2 on Overlord Agmar'),
(2681000, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0,  0, 0, 0, 19, 26437, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 0 on Taunka Soldier'),
(2681000, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 2, 0,  0, 0, 0, 9, 26437, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data Taunka Soldier'),
(2681000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data Overlord Agmar'),
(2681000, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry`=26379;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2643700 AND 2643707;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(26379, 1, 3842.118, 1492.083, 91.71697, 'Overlord Agmar'),
(26379, 2, 3842.422, 1498.366, 91.98796, 'Overlord Agmar'),
(26379, 3, 3842.672, 1511.366, 91.98796, 'Overlord Agmar'),
(26379, 4, 3842.172, 1520.616, 91.73796, 'Overlord Agmar'),
(26379, 5, 3842.672, 1535.866, 90.23796, 'Overlord Agmar'),
(26379, 6, 3850.172, 1547.616, 90.23796, 'Overlord Agmar'),
(26379, 7, 3859.422, 1559.866, 90.23796, 'Overlord Agmar'),
(26379, 8, 3865.922, 1568.366, 90.23796, 'Overlord Agmar'),
(26379, 9, 3868.922, 1577.616, 90.23796, 'Overlord Agmar'),
(26379, 10, 3870.227, 1589.648, 89.75896, 'Overlord Agmar'),
(2643700, 1, 3872.902, 1594.418, 90.0797, 'Taunka Soldier'), -- 102329 
(2643701, 1, 3880.851, 1591.76, 90.98628, 'Taunka Soldier'), -- 102341 
(2643702, 1, 3874.775, 1589.399, 90.39027, 'Taunka Soldier'), -- 102330 
(2643703, 1, 3877.774, 1588.824, 90.92334, 'Taunka Soldier'), -- 102328 
(2643704, 1, 3876.746, 1597.52, 90.69058, 'Taunka Soldier'), -- 102326 
(2643705, 1, 3879.273, 1595.718, 90.78122, 'Taunka Soldier'), -- 102333 
(2643706, 1, 3873.469, 1597.843, 90.18542, 'Taunka Soldier'); -- 102327 

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(9461,9462);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9461, 0, 0, 'Greetings High Chief. Would you do me the honor of accepting my invitation to join the Horde as an official member and leader of the Taunka?', 26127, 1, 1, 9462, 0, 0, 0, '', 0),
(9462, 0, 0, 'It is you who honor me, High Chief. Please read from this scroll. It is the oath of allegiance.', 26129, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9461;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9461, 0, 0, 0, 9, 0, 12140, 0, 0, 0, 0, 0, '', 'Show gossip option only if player is on quest All Hail Roanak'),
(15, 9461, 0, 0, 0, 29, 0, 26379, 30, 0, 0, 0, 0, '', 'Show gossip option only if Overlord Agmar is within 30 yards');
