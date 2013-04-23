DELETE FROM `gameobject` WHERE `id`=186267;
DELETE FROM `game_event_gameobject` WHERE `guid`=54947;
DELETE FROM `gameobject_questrelation` WHERE `id`=186267;

-- Scriptnames
UPDATE `gameobject_template` SET `ScriptName`='go_pumpkin_shrine' WHERE `entry`=186267;
UPDATE `creature_template` SET `ScriptName`='npc_horseman_head' WHERE `entry`=23775;

-- Headless Horseman Climax - Heal Body conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43306;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13, 43306, 18, 1, 23682);

-- creature mechanic_immune_mask
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (23682,23775);

-- The Headless horseman is only supposed to drop rings, the mounts etc drop from the Loot-Filled Pumpkin.
DELETE FROM `creature_loot_template` WHERE `entry`=23682 AND `item` IN (33154,33292,37012,49126,49128,37011);

-- Loot-Filled Pumpkin
DELETE FROM `item_loot_template` WHERE `entry`=54516;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(54516,49426,100,1,0,2,2),
(54516,33226,93,1,0,4,6),
(54516,33154,17,1,0,1,1),
(54516,33176,17,1,0,1,1),
(54516,33292,17,1,0,1,1),
(54516,49126,17,1,0,1,1),
(54516,49128,17,1,0,1,1),
(54516,20391,5,1,0,1,1),
(54516,20392,5,1,0,1,1),
(54516,20561,5,1,0,1,1),
(54516,20562,5,1,0,1,1),
(54516,20563,5,1,0,1,1),
(54516,20564,5,1,0,1,1),
(54516,20565,5,1,0,1,1),
(54516,20566,5,1,0,1,1),
(54516,20567,5,1,0,1,1),
(54516,20568,5,1,0,1,1),
(54516,20569,5,1,0,1,1),
(54516,20570,5,1,0,1,1),
(54516,20571,5,1,0,1,1),
(54516,20572,5,1,0,1,1),
(54516,20573,5,1,0,1,1),
(54516,20574,5,1,0,1,1),
(54516,34000,5,1,0,1,1),
(54516,34001,5,1,0,1,1),
(54516,34002,5,1,0,1,1),
(54516,34003,5,1,0,1,1),
(54516,37012,1,1,0,1,1);

-- The Headless Horseman
SET @GUID := 42662;

DELETE FROM `creature` WHERE `id`=23682;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,'23682','189','1','1','0','0','1763.1','1347.73','17.5602','6.20833','86400','0','0','126000','3994','0','0','0','0');

-- Creature_text
DELETE FROM `creature_text` WHERE `entry` IN (23682,23775);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23682,0,0, 'It is over, your search is done. Let fate choose now, the righteous one.',12,0,100,0,0,11961, 'Headless Horseman'),
(23682,1,0, 'Here''s my body, fit and pure! Now, your blackened souls I''ll cure!',14,0,100,0,0,12567, 'Headless Horseman'),
(23682,2,0, 'Harken, cur! Tis you I spurn! Now feel... the burn!',12,0,100,0,0,12574, 'Headless Horseman'),
(23682,3,0, 'Soldiers arise, stand and fight! Bring victory at last to this fallen knight!',12,0,100,0,0,11963, 'Headless Horseman'),
(23682,4,0, 'Your body lies beaten, battered and broken. Let my curse be your own, fate has spoken.',14,0,100,0,0,11962, 'Headless Horseman'),
(23682,5,0, 'This end have I reached before. What new adventure lies in store?',12,0,100,0,0,11964, 'Headless Horseman'),
(23775,0,0, 'Get over here, you idiot!',12,0,100,0,0,12569, 'Head of the Horseman');
