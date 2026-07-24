-- Ironaya
SET @SPAWN_GROUP_ID := 334; -- 1

DELETE FROM `spawn_group` WHERE `spawnId` = 54080 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,54080);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Uldaman - Ironaya",4);

UPDATE `creature` SET `position_x` = -234.73112, `position_y` = 312.00705, `position_z` = -47.514233, `orientation` = 4.799655437469482421 WHERE `guid` = 54080 AND `id` = 7228;

DELETE FROM `waypoint_data` WHERE `id` = 6;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(6,1,-234.83836,304.74194,-47.59481,NULL,0,0,0,100,0),
(6,2,-234.52731,289.1205,-48.02008,NULL,0,0,0,100,0),
(6,3,-233.9544,270.41608,-50.40104,NULL,0,0,0,100,0),
(6,4,-233.42236,252.05559,-49.447884,NULL,0,0,0,100,0);

-- Stone Keepers
UPDATE `creature_template` SET `ScriptName` = 'npc_stone_keeper' WHERE `entry` = 4857;

UPDATE `creature` SET `StringId` = 'StoneKeeper1' WHERE `guid` = 27555 AND `id` = 4857;
UPDATE `creature` SET `StringId` = 'StoneKeeper2' WHERE `guid` = 28368 AND `id` = 4857;
UPDATE `creature` SET `StringId` = 'StoneKeeper3' WHERE `guid` = 27554 AND `id` = 4857;
UPDATE `creature` SET `StringId` = 'StoneKeeper4' WHERE `guid` = 27794 AND `id` = 4857;

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 4857;

-- Archaedas
UPDATE `gameobject_template` SET `ScriptName` = '' WHERE `entry` = 133234;

DELETE FROM `creature_text` WHERE `CreatureID` = 2748 AND `GroupID` = 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2748,4,0,"%s breaks free from his stone slumber!",16,0,100,0,0,0,3399,0,"Archaedas EMOTE_AWAKEN");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (10604,10259,10252,10258,10260);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,10604,0,0,31,0,3,7076,0,0,0,0,"","Group 0: Spell 'Destroy Earthen Guards' (Effect 0) targets creature 'Earthen Guardian'"),
(13,1,10604,0,1,31,0,3,7077,0,0,0,0,"","Group 1: Spell 'Destroy Earthen Guards' (Effect 0) targets creature 'Earthen Hallshaper'"),
(13,1,10604,0,2,31,0,3,7309,0,0,0,0,"","Group 2: Spell 'Destroy Earthen Guards' (Effect 0) targets creature 'Earthen Custodian'"),
(13,1,10604,0,3,31,0,3,10120,0,0,0,0,"","Group 3: Spell 'Destroy Earthen Guards' (Effect 0) targets creature 'Vault Warder'"),
(13,1,10604,0,0,36,0,0,0,0,0,0,0,"","Group 0: Spell 'Destroy Earthen Guards' (Effect 0) targets only alive creature"),
(13,1,10604,0,1,36,0,0,0,0,0,0,0,"","Group 1: Spell 'Destroy Earthen Guards' (Effect 0) targets only alive creature"),
(13,1,10604,0,2,36,0,0,0,0,0,0,0,"","Group 2: Spell 'Destroy Earthen Guards' (Effect 0) targets only alive creature"),
(13,1,10604,0,3,36,0,0,0,0,0,0,0,"","Group 3: Spell 'Destroy Earthen Guards' (Effect 0) targets only alive creature"),

(13,1,10259,0,0,31,0,3,7077,0,0,0,0,"","Group 0: Spell 'Awaken Earthen Dwarf' (Effect 0) targets creature 'Earthen Hallshaper'"),
(13,1,10259,0,1,31,0,3,7309,0,0,0,0,"","Group 1: Spell 'Awaken Earthen Dwarf' (Effect 0) targets creature 'Earthen Custodian'"),
(13,1,10259,0,0,1,0,10255,0,0,0,0,0,"","Group 0: Spell 'Awaken Earthen Dwarf' (Effect 0) targets creature with aura 'Stoned'"),
(13,1,10259,0,1,1,0,10255,0,0,0,0,0,"","Group 1: Spell 'Awaken Earthen Dwarf' (Effect 0) targets creature with aura 'Stoned'"),

(13,1,10252,0,0,31,0,3,7076,0,0,0,0,"","Group 0: Spell 'Awaken Earthen Guardians' (Effect 0) targets creature 'Earthen Guardian'"),

(13,1,10258,0,0,31,0,3,10120,0,0,0,0,"","Group 0: Spell 'Awaken Vault Warder' (Effect 0) targets creature 'Vault Warder'"),

(13,1,10260,0,0,31,0,3,2748,0,0,0,0,"","Group 0: Spell 'Reconstruct' (Effect 0) targets creature 'Archaedas'");

UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` IN (7076,7077,7309);
UPDATE `creature_template` SET `unit_flags` = 33555264 WHERE `entry` = 10120;
UPDATE `creature_template` SET `ScriptName` = 'npc_earthen_hallshaper_custodian' WHERE `entry` IN (7077,7309);
UPDATE `creature_template` SET `ScriptName` = 'npc_earthen_guardian' WHERE `entry` = 7076;
UPDATE `creature_template` SET `ScriptName` = 'npc_vault_warder' WHERE `entry` = 10120;

UPDATE `creature` SET `StringId` = 'VaultWarderOutside' WHERE `guid` IN (33535,33504) AND `id` = 10120;
