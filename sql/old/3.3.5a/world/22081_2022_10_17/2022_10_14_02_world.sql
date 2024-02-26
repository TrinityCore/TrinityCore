-- *** Quest "Last rites" ***
DELETE FROM `gossip_menu_option` WHERE `MenuID`=9417;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(9417,0,0,"Let's do this, Thassarian.  It's now or never.",25840,1,1,0,0,0,0,NULL,0,0);

-- Add missing gossip text
DELETE FROM `gossip_menu` WHERE `MenuID`=9417 AND `TextID`=12664;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(9417,12664,0);

-- Condition for source Gossip menu condition type Area id
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9417 AND `SourceEntry` IN (12663,12664) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9417, 12663, 0, 0, 23, 0, 4126, 0, 0, 0, 0, 0, '', 'Show gossip menu 9417 text id 12663 if target area is The Wailing Ziggurat.'),
(14, 9417, 12664, 0, 0, 23, 0, 4128, 0, 0, 0, 0, 0, '', 'Show gossip menu 9417 text id 12664 if target area is Naxxanar.');

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9417 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9417, 0, 0, 0, 9, 0, 12019, 0, 0, 0, 0, 0, '', 'Show gossip menu 9417 option id 0 if quest Last Rites has been taken.'),
(15, 9417, 0, 0, 0, 23, 0, 4128, 0, 0, 0, 0, 0, '', 'Show gossip menu 9417 option id 0 if target area is Naxxanar.');

-- Pathing for Thassarian entry 26170 Quest script for "Last Rites"
SET @PATH := 1013030;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3700.08,3574.54,473.322,0,0,0,100,0),
(@PATH,2,3705.94,3573.63,476.841,0,0,0,100,0),
(@PATH,3,3714.32,3572.3,477.442,0,0,0,100,0);

-- Pathing for Arthas entry 26203 Quest script for "Last Rites"
SET @PATH := 1013031;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3733.2195,3538.1602,477.44214,0,0,0,100,0),
(@PATH,2,3736.5,3556.1494,477.44086,0,0,0,100,0),
(@PATH,3,3737.5398,3565.2202,477.44086,0,0,0,100,0);

-- Pathing for Talbot entry 25301 Quest script for "Last Rites"
SET @PATH := 1013032;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3746.96,3607.5063,473.32144,0,0,0,100,0),
(@PATH,2,3742.525,3586.4636,477.44086,0,0,0,100,0),
(@PATH,3,3738.237,3570.3462,477.44086,0,0,0,100,0);

-- Pathing for Arlos entry 25250 Quest script for "Last Rites"
SET @PATH := 1013033;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3742.4668,3598.8833,477.44287,0,0,0,100,0),
(@PATH,2,3739.2288,3587.0754,477.44086,0,0,0,100,0),
(@PATH,3,3735.5718,3572.422,477.44086,0,0,0,100,0);

-- Pathing for Leryssa entry 25251 Quest script for "Last Rites"
SET @PATH := 1013034;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3750.0989,3603.0605,474.0086,0,0,0,100,0),
(@PATH,2,3747.6187,3591.2925,477.44186,0,0,0,100,0),
(@PATH,3,3741.9653,3571.4446,477.44086,0,0,0,100,0);

-- Two spawns of entry. Script is only used on one.
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=26170;
UPDATE `creature` SET `ScriptName`='npc_thassarian' WHERE `guid`=101303;
-- Image of the Lich King flags were wrong and script is not required
UPDATE `creature_template` SET `unit_flags`=768,`ScriptName`='' WHERE `entry`=26203;

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=3 AND `SourceEntry`=50995 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 50995, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell Empowered Blood Presence (effects 0 & 1) will hit the potential target of the spell if target is player any player.');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=3 AND `SourceEntry`=50995 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 50995, 0, 1, 31, 0, 3, 26170, 0, 0, 0, 0, '', 'Spell Empowered Blood Presence (effects 0 & 1) will hit the potential target of the spell if target is player any player.');

-- Prince Valanar fix class and expansion and add missing loot 
UPDATE `creature_template` SET `exp`=2, `unit_class`=8, `lootid`=28189,`mingold`=3000, `maxgold`=6500 WHERE `entry`=28189;

-- Prince Valanar loot
DELETE FROM `creature_loot_template` WHERE `entry`=28189;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES 
(28189, 33373, 0, 15, 0, 1, 1, 1, 1, 'Fur-lined-belt'),
(28189, 33374, 0, 15, 0, 1, 1, 1, 1, 'Fur-lined-boots'),
(28189, 33375, 0, 15, 0, 1, 1, 1, 1, 'Fur-lined-bracers'),
(28189, 33376, 0, 15, 0, 1, 1, 1, 1, 'Fur-lined-gloves'),
(28189, 33377, 0, 15, 0, 1, 1, 1, 1, 'Fur-lined-pants'),
(28189, 33470, 0, 40, 0, 1, 2, 1, 3, 'Frostweave Cloth');

-- Thassarian add missing aura and remove script waypoints
UPDATE `creature_template_addon` SET `auras`=50995 WHERE `entry`= 26170;
DELETE FROM `script_waypoint` WHERE `entry`=26170;
