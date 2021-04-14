UPDATE `creature_template` SET `gossip_menu_id`=3310 WHERE  `entry`=11216;

DELETE FROM `gossip_menu_option` WHERE `menu_id` in(3310,3309,3308,3307,3306,3305,3304,3303,3302,3301);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(3310, 0, 0, 'The pleasure is mine, madam. Might I ask what it is that you are doing here?', 6645, 1, 1, 3309, 0, 0, 0, '', 0),
(3310, 1, 0, 'Eva, I have lost the Spectral Essence. I need another.', 6799, 1, 1, 0, 0, 0, 0, '', 0),
(3309, 0, 0, 'Until what, Eva? I must know.', 6647, 1, 1, 3308, 0, 0, 0, '', 0),
(3308, 0, 0, 'What do you mean?', 6649, 1, 1, 3307, 0, 0, 0, '', 0),
(3307, 0, 0, 'Why didn''t you just leave?', 6651, 1, 1, 3306, 0, 0, 0, '', 0),
(3306, 0, 0, 'So what happened?', 6653, 1, 1, 3305, 0, 0, 0, '', 0),
(3305, 0, 0, 'No restraints? Just a circle?', 6655, 1, 1, 3304, 0, 0, 0, '', 0),
(3304, 0, 0, 'Tell me more', 6657, 1, 1, 3303, 0, 0, 0, '', 0),
(3303, 0, 0, 'This is an atrocity.', 6659, 1, 1, 3302, 0, 0, 0, '', 0),
(3302, 0, 0, 'I feel sick', 6661, 1, 1, 3301, 0, 0, 0, '', 0),
(3301, 0, 0, 'What can I do to help?', 45678, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (3310);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 3310, 0, 0, 0, 8, 0, 5382, 0, 0, 1, 0, 0, '', 'Gossip Option requires Doctor Theolen Krastinov, the Butcher not rewarded'),
(15, 3310, 0, 0, 0, 9, 0, 5382, 0, 0, 1, 0, 0, '', 'Gossip Option requires Doctor Theolen Krastinov, the Butcher not taken'),
(15, 3310, 0, 0, 0, 28, 0, 5382, 0, 0, 1, 0, 0, '', 'Gossip Option requires Doctor Theolen Krastinov, the Butcher not complete'),
(15, 3310, 1, 0, 0, 8, 0, 5384, 0, 0, 0, 0, 0, '', 'Gossip Option requires Kirtonos the Herald Rewarded'),
(15, 3310, 1, 0, 0, 2, 0, 13544, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectral Essence');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (11216);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(11216) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11216,0,0,1,62,0,100,0,3310,1,0,0,85,17672,2,0,0,0,0,7,0,0,0,0,0,0,0,'Eva Sarkhoff - On Gossip Option 1 Selected - Cast Summon Spectral Essence'),
(11216,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Eva Sarkhoff - Link - Close Gossip'),
(11216,0,3,4,62,0,100,0,3301,0,0,0,7,5382,0,0,0,0,0,7,0,0,0,0,0,0,0,'Eva Sarkhoff - On Gossip Option 0 Selected - Add Quest Doctor Theolen Krastinov, the Butcher'),
(11216,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Eva Sarkhoff - Link - Close Gossip');
