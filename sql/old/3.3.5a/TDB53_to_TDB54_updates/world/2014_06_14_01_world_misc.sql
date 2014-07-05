DELETE FROM `gossip_menu_option` WHERE `menu_id`=10389;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10389, 0, 0, 'Teleport to the Expedition Base Camp.', 33919, 1, 0, 0, ''), -- 194569
(10389, 1, 0, 'Teleport to the Formation Grounds.', 33920, 1, 0, 0, ''), -- 194569
(10389, 3, 0, 'Teleport to the Colossal Forge.', 33921, 1, 0, 0, ''), -- 194569
(10389, 4, 0, 'Teleport to the Scrapyard.', 33922, 1, 0, 0, ''), -- 194569
(10389, 5, 0, 'Teleport to the Antechamber of Ulduar.', 33923, 1, 0, 0, ''), -- 194569
(10389, 6, 0, 'Teleport to the Shattered Walkway.', 33924, 1, 0, 0, ''), -- 194569
(10389, 10, 0, 'Teleport to the Conservatory of Life.', 33926, 1, 0, 0, ''), -- 194569
(10389, 12, 0, 'Teleport to the Spark of Imagination.', 33927, 1, 0, 0, ''), -- 194569
(10389, 15, 0, 'Teleport to the Prison of Yogg-Saron.', 33928, 1, 0, 0, ''); -- 194569

UPDATE `gameobject_template` SET AIName = 'SmartGameObjectAI', `ScriptName` = '' WHERE `entry`=194569;

SET @Entry := 194569;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Entry;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` VALUES
-- Expedition Base Camp Teleport
(@ENTRY,1,0,9,62,0,100,0,10389,0,0,0,11,64014,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 0 - Cast "Expedition Base Camp Teleport"'),
-- Formation Grounds Teleport
(@ENTRY,1,1,9,62,0,100,0,10389,1,0,0,11,64032,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 1 - Cast "Formation Grounds Teleport"'),
-- Colossal Forge Teleport
(@ENTRY,1,2,9,62,0,100,0,10389,3,0,0,11,64028,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 3 - Cast "Colossal Forge Teleport"'),
-- Scrapyard Teleport
(@ENTRY,1,3,9,62,0,100,0,10389,4,0,0,11,64031,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 4 - Cast "Scrapyard Teleport"'),
-- Antechamber Teleport
(@ENTRY,1,4,9,62,0,100,0,10389,5,0,0,11,64030,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 5 - Cast "Antechamber Teleport"'),
-- Shattered Walkway Teleport
(@ENTRY,1,5,9,62,0,100,0,10389,6,0,0,11,64029,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 6 - Cast "Shattered Walkway Teleport"'),
-- Conservatory Teleport
(@ENTRY,1,6,9,62,0,100,0,10389,10,0,0,11,64024,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 10 - Cast "Conservatory Teleport"'),
-- Halls of Invention Teleport
(@ENTRY,1,7,9,62,0,100,0,10389,12,0,0,11,64025,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 12 - Cast "Halls of Invention Teleport"'),
-- Prison of Yogg-Saron Teleport
(@ENTRY,1,8,9,62,0,100,0,10389,15,0,0,11,65042,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - On gossip select 15 - Cast "Prison of Yogg-Saron Teleport"'),
-- Close gossip
(@ENTRY,1,9,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ulduar Teleporter - Linked with Previous Event - Close gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10389;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10389, 1, 0, 0, 13, 1, 20, 2, 0, 0, 0, 0, '', 'Show options for gossip only if 2 Collossus death'),
(15, 10389, 3, 0, 0, 13, 1, 0, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_LEVIATHAN done'),
(15, 10389, 4, 0, 0, 13, 1, 3, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_XT002 done'),
(15, 10389, 5, 0, 0, 13, 1, 3, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_XT002 done'),
(15, 10389, 6, 0, 0, 13, 1, 5, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_KOLOGARN done'),
(15, 10389, 12, 0, 0, 13, 1, 5, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_KOLOGARN done'),
(15, 10389, 10, 0, 0, 13, 1, 6, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_AURIAYA done'),
(15, 10389, 15, 0, 0, 13, 1, 14, 3, 2, 0, 0, 0, '', 'Show options for gossip only if BOSS_VEZAX done');
