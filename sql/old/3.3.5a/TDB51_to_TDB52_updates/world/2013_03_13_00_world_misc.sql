SET @CGUID := 49815;
SET @OGUID := 14972;
SET @SERINAR := 26593;
SET @NECROLYTE := 27356;
SET @BUNNY := 27369;
SET @RUNE := 188695;

UPDATE `creature` SET `MovementType`=0, `spawndist`=0, `unit_flags`=33024 WHERE `guid`=116960;
DELETE FROM `creature` WHERE `guid` IN (117061,117371,117372,117421,117422,117423,117633,117634,117646,117648,117649);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(117061, @BUNNY, 571, 1, 1, 13069, 4495.499, 1747.361, 175.1579, 0.6806784, 300, 0, 0),
(117371, @BUNNY, 571, 1, 1, 13069, 4544.45, 1739.195, 167.6779, 0.9075712, 300, 0, 0),
(117372, @BUNNY, 571, 1, 1, 13069, 4573.836, 1708.501, 171.742, 1.466077, 300, 0, 0),
(117421, @BUNNY, 571, 1, 1, 13069, 4604.599, 1727.422, 170.6874, 4.921828, 300, 0, 0),
(117422, @BUNNY, 571, 1, 1, 13069, 4601.996, 1700.385, 171.9938, 1.37881, 300, 0, 0),
(117423, @BUNNY, 571, 1, 1, 13069, 4576.454, 1755.058, 167.8554, 2.164208, 300, 0, 0),
(117633, @BUNNY, 571, 1, 1, 13069, 4625.904, 1754.476, 182.3284, 6.038839, 300, 0, 0),
(117634, @BUNNY, 571, 1, 1, 13069, 4561.219, 1731.186, 166.7194, 3.926991, 300, 0, 0),
(117646, @BUNNY, 571, 1, 1, 13069, 4497.56, 1880.672, 164.3632, 5.61996, 300, 0, 0),
(117648, 27362, 571, 1, 1, 0, 4567.375, 1724.495, 168.1724, 0.6806784, 300, 5, 1),
(117649, 27362, 571, 1, 1, 0, 4608.474, 1721.618, 170.9504, 3.124139, 300, 5, 1),
(@CGUID+0, 27358, 571, 1, 1, 0, 4576.38, 1711.559, 171.3237, 4.018391, 300, 5, 1),
(@CGUID+1, 27358, 571, 1, 1, 0, 4574.408, 1751.613, 167.8838, 1.03504, 300, 5, 1),
(@CGUID+2, 27363, 571, 1, 1, 0, 4570.443, 1678.617, 170.5762, 0.002298846, 300, 5, 1);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`, `orientation`, `rotation0`, `rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,@RUNE,571,1,1,4495.527,1747.337,175.0751,0.7330382,0,0,0.3583679,0.9335805,300,100,1),
(@OGUID+1,@RUNE,571,1,1,4544.453,1739.186,167.594,-1.151916,0,0,-0.5446386,0.8386708,300,100,1),
(@OGUID+2,@RUNE,571,1,1,4573.879,1708.473,171.6586,-2.268925,0,0,-0.9063072,0.4226195,300,100,1),
(@OGUID+3,@RUNE,571,1,1,4604.577,1727.41,170.6038,-0.1919852,0,0,-0.09584522,0.9953963,300,100,1),
(@OGUID+4,@RUNE,571,1,1,4601.975,1700.365,171.9105,-0.4014249,0,0,-0.1993675,0.9799248,300,100,1),
(@OGUID+5,@RUNE,571,1,1,4576.479,1755.036,167.7747,-0.2792516,0,0,-0.1391726,0.9902682,300,100,1),
(@OGUID+6,@RUNE,571,1,1,4625.864,1754.506,182.2451,-0.7330382,0,0,-0.3583679,0.9335805,300,100,1),
(@OGUID+7,@RUNE,571,1,1,4561.233,1731.201,166.6359,-0.6108635,0,0,-0.300705,0.9537172,300,100,1),
(@OGUID+8,@RUNE,571,1,1,4497.559,1880.615,164.2788,0.8377574,0,0,0.4067364,0.9135455,300,100,1);

DELETE FROM `creature_addon` WHERE `guid`=116960;
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(116960,'29266');

DELETE FROM `creature_text` WHERE `entry`=@SERINAR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SERINAR,0,0, 'Perfect.  As long as you don''t go hacking and slashing your way through, they''ll never know the difference.',12,0,100,0,0,0, 'Serinar');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48750;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(48750,48770,2,'Serinar''s Vision is applied while aura Burning Depths Necrolyte Image is active');

UPDATE `quest_template` SET `PrevQuestId`=12447 WHERE `Id` IN (12261,12262);
UPDATE `quest_template` SET `PrevQuestId`=12263 WHERE `Id` IN (12264,12265);

UPDATE `gameobject_template` SET `flags`=4 WHERE `entry`=188695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SERINAR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SERINAR AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SERINAR*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SERINAR, 0, 0, 1, 19, 0, 100, 0, 12263, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @NECROLYTE, 20, 0, 0, 0, 0, 0, 'Serinar - On quest accept - Turn to'),
(@SERINAR, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48748, 0, 0, 0, 0, 0, 19, @NECROLYTE, 20, 0, 0, 0, 0, 0, 'Serinar - On quest accept - Spellcast Absorb Image'),
(@SERINAR, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @SERINAR*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Serinar - On quest accept - Run script'),
(@SERINAR, 0, 3, 4, 62, 0, 100, 0, 9537, 0, 0, 0, 11, 48750, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serinar - On gossip select - Spellcast Burning Depths Necrolyte Image'),
(@SERINAR, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Serinar - On gossip select - Say line'),
(@SERINAR, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serinar - On gossip select - Close gossip'),

(@SERINAR*100, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serinar script - Turn to'),
(@SERINAR*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 48750, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serinar script - Spellcast Burning Depths Necrolyte Image'),
(@SERINAR*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Serinar script - Say line'),
(@SERINAR*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Serinar script - Turn to');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (48738,48748);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9537 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 48738, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', 'Spell Stamp Out Necromantic Rune effect0 targets player'),
(13, 2, 48738, 0, 0, 31, 0, 3, @BUNNY, 0, 0, 0, '', 'Spell Stamp Out Necromantic Rune effect1 targets Necromantic Rune Bunny'),
(13, 1, 48748, 0, 0, 31, 0, 3, @NECROLYTE, 0, 0, 0, '', 'Spell Absorb Image targets Burning Depths Necrolyte'),
(15, 9537, 0, 0, 0, 9, 0, 12263, 0, 0, 0, 0, '', 'Show gossip option only if player has taken quest The Best of Intentions'),
(15, 9537, 0, 0, 0, 1, 0, 48750, 0, 0, 1, 0, '', 'Show gossip option only if player doesn''t have aura Burning Depths Necrolyte Image');
