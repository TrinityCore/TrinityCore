-- *** Quest "The Hunt is on" ***
-- Gossip is in place options just need to be enabled and conditions added
UPDATE `gossip_menu_option` SET `OptionType`=1,`OptionNpcFlag`=1 WHERE `MenuID` IN (9217,9218,9219) AND `OptionType`=0;
-- Condition for source Gossip menu option condition type Aura
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9217,9218,9219) AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9217, 0, 0, 0, 1, 0, 46078, 0, 0, 0, 0, 0, '', 'Show gossip menu 9217 option id 0 if target has aura Righteous Vision.'),
(15, 9218, 0, 0, 0, 1, 0, 46078, 0, 0, 0, 0, 0, '', 'Show gossip menu 9218 option id 0 if target has aura Righteous Vision.'),
(15, 9219, 0, 0, 0, 1, 0, 46078, 0, 0, 0, 0, 0, '', 'Show gossip menu 9219 option id 0 if target has aura Righteous Vision.');

-- *** Quest "Aces High!" ***
-- Condition for source Gossip menu condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10204 AND `SourceEntry` IN (14169,14170) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 10204, 14169, 0, 0, 9, 0, 13413, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 text id 14169 if quest Aces High! has been taken.'),
(14, 10204, 14170, 0, 0, 9, 0, 13414, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 text id 14170 if quest Aces High! "Daily" has been taken.');

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10204 AND `SourceEntry` IN (0,1) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10204, 0, 0, 0, 9, 0, 13413, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 option id 0 if quest Aces High! has been taken.'),
(15, 10204, 1, 0, 0, 9, 0, 13414, 0, 0, 0, 0, 0, '', 'Show gossip menu 10204 option id 1 if quest Aces High! "Daily" has been taken.');

-- Corastrasza SAI
SET @ENTRY := 32548;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,62,0,100,0,10204,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select 0 - Close Gossip for player"),
(@ENTRY,0,1,2,62,0,100,0,10204,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select 1 - Close Gossip for player"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,61240,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select - Cast 'Summon Wyrmrest Skytalon' on player"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,61244,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corastrasza - Gossip option select - Cast 'Wyrmrest Skytalon Ride Periodic' on player");

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

-- *** Quest "Not fit for death" ***
UPDATE `gameobject_template` SET `ScriptName` = 'go_caribou_trap' WHERE `entry` IN (187982,187995,187996,187997,187998,187999,188000,188001,188002,188003,188004,188005,188006,188007,188008);
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q11865_place_fake_fur';
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry`=25835;

-- Conditions missing comment
UPDATE `conditions` SET `Comment` = 'Spell Place Fake Fur (effect 0) will hit the potential target of the spell if target is gameobject Caribou Trap.' WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46085;

-- *** Quest "Help those who cannot help themselves" ***
UPDATE `gameobject_template` SET `ScriptName` = 'go_mammoth_trap' WHERE `entry` IN (188022,188024,188025,188026,188027,188028,188029,188030,188031,188032,188033,188034,188035,188036,188037,188038,188039,188040,188041,188042,188043,188044);
UPDATE `item_template` SET `ScriptName` = '' WHERE `entry`=35228;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry`=25850;

-- Conditions missing comment
UPDATE `conditions` SET `Comment` = 'Spell Smash Mammoth Trap (effect 0) will hit the potential target of the spell if target is gameobject Mammoth Trap.' WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46201;

-- Add missing creature text
DELETE FROM `creature_text` WHERE `CreatureID`=25850;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25850, 0, 0, '%s trumpets in approval!', 16, 0, 100, 377, 0, 9914, 25046, 0, 'Trapped Mammoth Calf');

-- *** Quest "Abduction" ***

-- Condition for source Spell condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=45611 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 45611, 0, 0, 31, 1, 3, 25316, 0, 0, 12, 0, '', 'Spell Arcane Chains will hit the explicit target of the spell if target is unit Beryl Sorcerer.'),
(17, 0, 45611, 0, 0, 38, 1, 25, 4, 0, 0, 12, 0, '', 'Spell Arcane Chains will hit the explicit target of the spell if target health percentage must be equal or lower than 25% of max Health.');

DELETE FROM `spell_script_names` WHERE `spell_id`= 45625;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45625, 'spell_arcane_chains_character_force_cast');

-- Update creatures
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=70, `unit_flags`=32768, `unit_class`=8, `ScriptName`='npc_captured_beryl_sorcerer' WHERE `entry`=25474;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=25316;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25316;

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=45735 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 45735, 0, 0, 31, 0, 3, 25474, 0, 0, 0, 0, '', 'Spell Arcane Chains: Chain Channel II (effect 0) will hit the target of the spell if target is unit Captured Beryl Sorcerer.');
