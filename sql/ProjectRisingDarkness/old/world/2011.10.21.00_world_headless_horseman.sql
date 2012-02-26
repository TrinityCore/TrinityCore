DELETE FROM `gameobject` WHERE `id`=186267;
DELETE FROM `game_event_gameobject` WHERE `guid`=54947;
DELETE FROM `gameobject_questrelation` WHERE `id`=186267;

UPDATE `gameobject_template` SET `ScriptName`='go_pumpkin_shrine' WHERE `entry`=186267;
UPDATE `creature_template` SET `ScriptName`='npc_horseman_head' WHERE `entry`=23775;

-- heal body
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43306;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13, 43306, 18, 1, 23682);

-- set lfg flag
UPDATE `quest_template` SET `SpecialFlags`=9 WHERE `entry`=25482;

-- temporary
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (23686, 24034, 23694);

-- immunitys
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (23682,23775);

-- loot
DELETE FROM `creature_loot_template` WHERE `entry`=23682 AND `item` IN (33154,33292,37012,49126,49128,37011);

DELETE FROM `item_loot_template` WHERE `entry`=54516;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(54516,33154, 25,1,0, 1, 1),
(54516,33292, 33,1,0, 1, 1),
(54516,37012,  3,1,0, 1, 1),
(54516,49126,  5,1,0, 1, 1),
(54516,49128,  8,1,0, 1, 1),
(54516,37011, 25,1,0, 1, 1),
(54516,40753,100,1,0, 2, 2),
(54516,34068, 33,1,0, 3, 6),
(54516,33226,100,1,0,20,20);

-- spawn
SET @guid := 303110;

DELETE FROM `creature` WHERE `id`=23682;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid,'23682','189','1','1','0','0','1763.1','1347.73','17.5602','6.20833','10','0','0','126000','3994','0','0','0','0');