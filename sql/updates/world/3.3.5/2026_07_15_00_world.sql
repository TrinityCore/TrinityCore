--
SET @SPAWN_GROUP_ID := 376; -- 1

-- Jan'alai
DELETE FROM `creature_text` WHERE `CreatureID` = 23578 AND `GroupID` IN (7,8);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23578,7,0,"Come, strangers. The spirit of da dragonhawk be hungry for worthy souls.",14,0,100,0,0,12039,23314,0,"janalai SAY_EVENT_1"),
(23578,7,1,"Come, friends. Your bodies gonna feed ma hatchlings, and your souls gonna fill me with power!",14,0,100,0,0,12040,23313,0,"janalai SAY_EVENT_2"),
(23578,8,0,"%s goes into a frenzy!",41,0,100,0,0,0,10645,0,"janalai EMOTE_FRENZY");

-- Amani Dragonhawk Hatchling
UPDATE `creature_template` SET `speed_walk` = 1, `ScriptName` = 'npc_amani_dragonhawk_hatchling' WHERE `entry` = 23598;

UPDATE `creature_model_info` SET `BoundingRadius` = 0.165, `CombatReach` = 0.82500005 WHERE `DisplayID` = 17546;

-- Dragonhawk Egg
UPDATE `creature_template` SET `ScriptName` = 'npc_dragonhawk_egg' WHERE `entry` = 23817;

DELETE FROM `spawn_group` WHERE `spawnId` IN (89226,89227,89228,89300,89301,89302,89314,89315,89316,89317,89319,89320,89321,89323,89328,89332,89333,89334,89335,89336,89337,89338,89339,89340,89341,89342,89343,89344,89345,89346,89347,89348,89349,89350,89351,89352,89353,89354,89355,89356) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,89226),
(@SPAWN_GROUP_ID+0,0,89227),
(@SPAWN_GROUP_ID+0,0,89228),
(@SPAWN_GROUP_ID+0,0,89300),
(@SPAWN_GROUP_ID+0,0,89301),
(@SPAWN_GROUP_ID+0,0,89302),
(@SPAWN_GROUP_ID+0,0,89314),
(@SPAWN_GROUP_ID+0,0,89315),
(@SPAWN_GROUP_ID+0,0,89316),
(@SPAWN_GROUP_ID+0,0,89317),
(@SPAWN_GROUP_ID+0,0,89319),
(@SPAWN_GROUP_ID+0,0,89320),
(@SPAWN_GROUP_ID+0,0,89321),
(@SPAWN_GROUP_ID+0,0,89323),
(@SPAWN_GROUP_ID+0,0,89328),
(@SPAWN_GROUP_ID+0,0,89332),
(@SPAWN_GROUP_ID+0,0,89333),
(@SPAWN_GROUP_ID+0,0,89334),
(@SPAWN_GROUP_ID+0,0,89335),
(@SPAWN_GROUP_ID+0,0,89336),
(@SPAWN_GROUP_ID+0,0,89337),
(@SPAWN_GROUP_ID+0,0,89338),
(@SPAWN_GROUP_ID+0,0,89339),
(@SPAWN_GROUP_ID+0,0,89340),
(@SPAWN_GROUP_ID+0,0,89341),
(@SPAWN_GROUP_ID+0,0,89342),
(@SPAWN_GROUP_ID+0,0,89343),
(@SPAWN_GROUP_ID+0,0,89344),
(@SPAWN_GROUP_ID+0,0,89345),
(@SPAWN_GROUP_ID+0,0,89346),
(@SPAWN_GROUP_ID+0,0,89347),
(@SPAWN_GROUP_ID+0,0,89348),
(@SPAWN_GROUP_ID+0,0,89349),
(@SPAWN_GROUP_ID+0,0,89350),
(@SPAWN_GROUP_ID+0,0,89351),
(@SPAWN_GROUP_ID+0,0,89352),
(@SPAWN_GROUP_ID+0,0,89353),
(@SPAWN_GROUP_ID+0,0,89354),
(@SPAWN_GROUP_ID+0,0,89355),
(@SPAWN_GROUP_ID+0,0,89356);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Zul'Aman - Dragonhawk Eggs",4);

-- Amani'shi Hatcher
UPDATE `creature_template` SET `speed_walk` = 1, `ScriptName` = 'npc_amanishi_hatcher' WHERE `entry` IN (23818,24504);

UPDATE `creature` SET `StringId` = 'AmanishiHatcherTrigger' WHERE `guid` = 86476 AND `id` = 22515;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (43962,45340);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,43962,0,0,58,0,0,0,0,"AmanishiHatcherTrigger",0,0,0,"","Group 0: Spell 'Summon Amani'shi Hatcher' (Effect 0) targets creature 'World Trigger'"),
(13,1,45340,0,0,58,0,0,0,0,"AmanishiHatcherTrigger",0,0,0,"","Group 0: Spell 'Summon Amani'shi Hatcher' (Effect 0) targets creature 'World Trigger'");

-- Fire Bomb (Zul'Aman)
UPDATE `creature_template` SET `ScriptName` = 'npc_fire_bomb_zulaman' WHERE `entry` = 23920;

-- Misc
UPDATE `spell_target_position` SET `PositionX` = -34.6677, `PositionY` = 1149.56, `PositionZ` = 19.1438, `Orientation` = 3.14159, `VerifiedBuild` = 15595 WHERE `ID` = 43098;

UPDATE `creature` SET `StringId` = 'JanalaiFireWallTrigger' WHERE `guid` IN (86474,86475,86477,86478) AND `id` = 21252;

UPDATE `creature` SET `StringId` = 'JanalaiEggsR' WHERE `guid` IN (89226,89227,89300,89314,89315,89319,89323,89332,89333,89334,89335,89336,89337,89338,89339,89340,89341,89342,89355,89356) AND `id` = 23817;

UPDATE `creature` SET `StringId` = 'JanalaiEggsL' WHERE `guid` IN (89228,89301,89302,89316,89317,89320,89321,89328,89343,89344,89345,89346,89347,89348,89349,89350,89351,89352,89353,89354) AND `id` = 23817;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_janalai_summon_all_players',
'spell_janalai_fire_bomb',
'spell_janalai_hatch_eggs');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43096, 'spell_janalai_summon_all_players'),
(42621, 'spell_janalai_fire_bomb'),
(42471, 'spell_janalai_hatch_eggs');
