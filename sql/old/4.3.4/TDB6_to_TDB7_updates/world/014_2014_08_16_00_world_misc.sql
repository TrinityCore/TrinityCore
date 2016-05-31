DELETE FROM `creature_text` WHERE `entry` IN(30243,30632,31258,29880,30725);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(30243, 0, 0, 'I''ll eat your heart!', 12, 0, 100, 0, 0, 14388, 'Njorndar Spear-Sister',30508),
(30243, 0, 1, 'I will feed you to the dogs!', 12, 0, 100, 0, 0, 14389, 'Njorndar Spear-Sister',30499),
(30243, 0, 2, 'I will feed you to the dogs!', 12, 0, 100, 0, 0, 14385, 'Njorndar Spear-Sister',30499),
(30243, 0, 3, 'I will take pleasure in gutting you!', 12, 0, 100, 0, 0, 14384, 'Njorndar Spear-Sister',30498),
(30243, 0, 4, 'Sniveling pig!', 12, 0, 100, 0, 0, 14394, 'Njorndar Spear-Sister',30504),
(30243, 0, 5, 'Ugglin oo bjorr!', 12, 0, 100, 0, 0, 14395, 'Njorndar Spear-Sister',30505),
(30243, 0, 6, 'You come to die!', 12, 0, 100, 0, 0, 14392, 'Njorndar Spear-Sister',30502),
(30243, 0, 7, 'Die, maggot!', 12, 0, 100, 0, 0, 14391, 'Njorndar Spear-Sister',30501),
(30243, 0, 8, 'Haraak foln!', 12, 0, 100, 0, 0, 14396, 'Njorndar Spear-Sister',30506),
(30243, 0, 9, 'Your entrails will make a fine necklace.', 12, 0, 100, 0, 0, 14386, 'Njorndar Spear-Sister',30500),
(30243, 0, 10, 'Die, maggot!', 12, 0, 100, 0, 0, 14387, 'Njorndar Spear-Sister',30501),
(30243, 0, 11, 'Your entrails will make a fine necklace.', 12, 0, 100, 0, 0, 14390, 'Njorndar Spear-Sister',30500),
(30632, 0, 0, 'Your entrails will make a fine necklace.', 12, 0, 100, 0, 0, 13535, 'Mjordin Water Magus',30500),
(30632, 0, 1, 'I''ll eat your heart!', 12, 0, 100, 0, 0, 13695, 'Mjordin Water Magus',30508),
(30632, 0, 2, 'Haraak foln!', 12, 0, 100, 0, 0, 13541, 'Mjordin Water Magus',30506),
(30632, 0, 3, 'I''ll eat your heart!', 12, 0, 100, 0, 0, 13542, 'Mjordin Water Magus',30508),
(30632, 0, 4, 'Sniveling pig!', 12, 0, 100, 0, 0, 13539, 'Mjordin Water Magus',30504),
(30632, 0, 5, 'I spit on you!', 12, 0, 100, 0, 0, 13538, 'Mjordin Water Magus',30503),
(31258, 0, 0, 'I will take pleasure in gutting you!', 12, 0, 100, 0, 0, 13533, 'Ymirheim Chosen Warrior',30498),
(31258, 0, 1, 'I''ll eat your heart!', 12, 0, 100, 1, 0, 13542, 'Ymirheim Chosen Warrior',30508),
(29880, 0, 0, 'You come to die!', 12, 0, 100, 0, 0, 13537, 'Jotunheim Warrior',30502),
(29880, 0, 1, 'Sniveling pig!', 12, 0, 100, 0, 0, 13539, 'Jotunheim Warrior',30504),
(29880, 0, 2, 'I will feed you to the dogs!', 12, 0, 100, 0, 0, 13534, 'Jotunheim Warrior',30499),
(30725, 0, 0, 'You come to die!', 12, 0, 100, 0, 0, 13537, 'Jotunheim Sleep-Watcher',30502),
(30725, 0, 1, 'I spit on you!', 12, 0, 100, 0, 0, 13537, 'Jotunheim Sleep-Watcher',30503),
(30725, 0, 2, 'Your entrails will make a fine necklace.', 12, 0, 100, 0, 0, 13535, 'Jotunheim Sleep-Watcher',30500);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9839;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9839, 0, 0, 'Koltira... this might sound strange, but I keep seeing some kid\'s ghost.  Matthias Lehner... does the name mean anything to you?', 32828, 1, 1, 10195, 0, 0, 0, '', 0);

DELETE FROM `gossip_menu` WHERE `entry`=10195;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10195, 14141); -- 29795

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9839;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9839, 0, 0, 0, 28, 0, 13348, 0, 0, 0, 0, 0, '', 'Only show gossip if player has quest Futility complete'),
(15, 9839, 0, 0, 1, 28, 0, 13348, 0, 0, 0, 0, 0, '', 'Only show gossip if player has quest Futility rewarded'),
(15, 9839, 0, 0, 2, 28, 0, 13348, 0, 0, 0, 0, 0, '', 'Only show gossip if player has quest Futility taken');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30243 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30632 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=31258 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=29880 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30725 AND `id`=3;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30243, 0, 2, 0, 4, 0, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Njorndar Spear-Sister - On Agro - Say'),
(30632, 0, 4, 0, 4, 0, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mjordin Water Magus - On Agro - Say'),
(31258, 0, 4, 0, 4, 0, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Chosen Warrior - On Agro - Say'),
(29880, 0, 4, 0, 4, 0, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jotunheim Warrior - On Agro - Say'),
(30725, 0, 3, 0, 4, 0, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jotunheim Sleep-Watcher - On Agro - Say');
