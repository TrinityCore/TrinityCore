SET @OGUID :=    59568;
SET @CGUID :=    74509;

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=21210;
UPDATE `creature_template_addon` SET `auras`='' WHERE  `entry`=21210;


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21210,21207,21735);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21210,-84857,-84854,-84855,-84856,-84858,21207,21735) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-84857, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36393, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster (Guid 84857) - On Spawn - Cast Deathforge Summon Visual'),
(-84857, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster  - On Data Set 1 1 - Despawn'),
(-84854, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36384, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster (Guid 84854) - On Spawn - Cast Skartax Purple Beam'),
(-84854, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster  - On Data Set 1 1 - Despawn'),
(-84855, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36384, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster (Guid 84854) - On Spawn - Cast Skartax Purple Beam'),
(-84855, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster  - On Data Set 1 1 - Despawn'),
(-84856, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36384, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster (Guid 84854) - On Spawn - Cast Skartax Purple Beam'),
(-84856, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster  - On Data Set 1 1 - Despawn'),
(-84858, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36384, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster (Guid 84854) - On Spawn - Cast Skartax Purple Beam'),
(-84858, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis Deathforge Caster  - On Data Set 1 1 - Despawn'),
(21207, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 36382, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summoner Skartax - On Spawn - Cast Skartax Self Aura I'),
(21207, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summoner Skartax - On Spawn - Cast Test Channel'),
(21207, 0, 2, 0, 0, 0, 100, 0, 0, 0, 3000, 5000, 11, 12471, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Summoner Skartax - IC - Cast Shadowbolt'),
(21207, 0, 3, 0, 0, 0, 100, 0, 0, 0, 2500, 4500, 11, 38401, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Summoner Skartax - IC - Cast Incinerate'),
(21735, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 11, 37281, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infernal Oversoul - On Spawn - Cast Infernal Oversouls Wrath'),
(21735, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 21210, 0, 200, 0, 0, 0, 0, 'Infernal Oversoul - On Spawn - Set Data on Invis Deathforge Caster'),
(21735, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Infernal Oversoul - On Spawn - Start Attack');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(36384,36431,37281);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 36384, 0, 0, 31, 0, 3, 21210, 0, 0, 0, 0, '', 'Skartax Purple Beam targets Invis Deathforge Caster'),
(13, 1, 36384, 0, 0, 1, 0, 36393, 0, 0, 1, 0, 0, '', 'Skartax Purple Beam targets Invis Deathforge Caster only if does not have aura Deathforge Summon Visual'),
(13, 1, 36384, 0, 1, 31, 0, 3, 21211, 0, 0, 0, 0, '', 'Skartax Purple Beam targets Invis Deathforge Target'),
(13, 1, 36431, 0, 0, 31, 0, 3, 21210, 0, 0, 0, 0, '', 'Test Channel targets Invis Deathforge Caster'),
(13, 1, 36431, 0, 0, 1, 0, 36393, 0, 0, 0, 0, 0, '', 'Test Channel targets Invis Deathforge Caster only if has aura Deathforge Summon Visual'),
(13, 1, 37281, 0, 0, 31, 0, 3, 21207, 0, 0, 0, 0, '', 'Infernal Oversouls Wrath targets Summoner Skartax'),
(13, 1, 37281, 0, 1, 31, 0, 3, 20872, 0, 0, 0, 0, '', 'Infernal Oversouls Wrath targets Deathforge Summoner');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+2 AND `id`=20872;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 20872, 530, 1, 1,  -3335.892, 2133.704, -2.183001, 2.513274, 120, 0, 0), -- 20872 (Area: 3520)
(@CGUID+1, 20872, 530, 1, 1,  -3335.601, 2151.807, -1.211325, 3.001966, 120, 0, 0), -- 20872 (Area: 3520)
(@CGUID+2, 20872, 530, 1, 1,  -3341.744, 2168.385, 2.227986, 3.996804, 120, 0, 0); -- 20872 (Area: 3520)

DELETE FROM `gameobject` WHERE `id`=184820;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 184820, 530, 1, 1, 1506.37, 6367.81, 0.62336, 4.5204, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+1, 184820, 530, 1, 1, 1544.21, 6321.05, 2.36069, 0.593412, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+2, 184820, 530, 1, 1, 1589.61, 6294.26, 2.97764, 1.27409, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+3, 184820, 530, 1, 1, 1718.04, 6303.09, -0.245553, 4.24115, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+4, 184820, 530, 1, 1, 2165.13, 6485.68, 6.32237, 1.39626, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+5, 184820, 530, 1, 1, 2318.35, 6650.72, 16.8051, 5.74213, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+6, 184820, 530, 1, 1, 2330.77, 6719.11, 16.5635, 5.63741, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+7, 184820, 530, 1, 1, 2381.57, 6742.27, 16.7087, 4.90438, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+8, 184820, 530, 1, 1, 2494.49, 6713.98, 4.47157, 4.29351, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+9, 184820, 530, 1, 1, 2700.36, 6601.66, 22.8472, 3.40339, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+10, 184820, 530, 1, 1, 2706.19, 6673.73, 21.6303, 2.47837, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+11, 184820, 530, 1, 1, 2700.19, 6514.47, 2.13838, 2.11185, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+12, 184820, 530, 1, 1, 2597.69, 6505.88, 1.66538, 1.09956, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+13, 184820, 530, 1, 1, 2635.83, 6463.89, 1.86259, 1.85005, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+14, 184820, 530, 1, 1, 2462.47, 6544.21, 1.93072, 0.541052, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+15, 184820, 530, 1, 1, 2382.94, 6498.44, 3.00535, 1.98968, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+16, 184820, 530, 1, 1, 2332.92, 6567.22, 3.77855, 0.453786, 0, 0, 0, 1, 120, 255, 1);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21352,21498,21456,21351);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21352,21498,21456,21351) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21352, 0, 0, 1,38, 0, 100, 0, 1, 1, 180000, 180000, 12, 21456, 2, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Building Bunny Summoner - On Data Set 1 1 - Summon Ogre Building Bunny Small'),
(21352, 0, 1, 2,61, 0, 100, 0, 0, 0, 0, 0, 11, 32582, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summon Ogre Building Bunny Small - On Just Summoned - Cast Ogre Building Bunny Curse Visual'),
(21352, 0, 2, 0,61, 0, 100, 0, 0, 0, 0, 0, 12, 21498, 2, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Building Cursed Spirit Bunny - On Just Summoned - Summon Bladespire Evil Spirit'),
(21498, 0, 0, 0,54, 0, 100, 0, 0, 0, 0, 0, 12, 21446, 2, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Building Cursed Spirit Bunny - On Just Summoned - Summon Bladespire Evil Spirit'),
(21498, 0, 1, 0,54, 0, 100, 0, 0, 0, 0, 0, 12, 21452, 2, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Building Cursed Spirit Bunny - On Just Summoned - Summon Bloodmaul Evil Spirit'),
(21351, 0, 0, 0,54, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21352, 0, 0, 0, 0, 0, 0, 'Ogre Building Bunny Large - On Just Summoned - Set Data 1 1 Ogre Building Bunny Summoner');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=21498;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 21498, 0, 0, 23, 1, 3773, 0, 0, 0, 0, 0, '', 'Only Run AI in Bladespire Hold'),
(22, 2, 21498, 0, 0, 23, 1, 3776, 0, 0, 0, 0, 0, '', 'Only Run AI in  Bloodmaul Outpost');

DELETE FROM `spell_scripts` WHERE `id`=32580;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(32580, 0, 0, 10, 21351, 30000, 0, 0, 0, 0, 0);
