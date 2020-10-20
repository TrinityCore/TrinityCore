UPDATE `creature_template` SET `unit_flags`=33587264, `InhabitType`=4 WHERE `entry` IN (29310,31465); -- Jedoga
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=131953;
UPDATE `creature_addon` SET `auras`='56075 56327' WHERE `guid`=131953; -- Jedoga
UPDATE `creature_template` SET `ScriptName`='npc_twilight_volunteer' WHERE `entry`=30385;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN(30114,30181);
DELETE FROM `creature` WHERE `id` IN(30114,30181);
DELETE FROM `creature_addon` WHERE `guid` IN (132063,132066,132067,132068,132069,132070,132071,132072,132065);
DELETE FROM `linked_respawn` WHERE `guid` IN (131997,131998,131999,132000,132001,132002,132003,132004,132005,132006,132007,132008,132009,132010,132011);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (56312);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56312,0,0,31,0,3,29310,0,0,0,'','Spell \'Beam Visual\' targets Jedoga Shadowseeker');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_random_lightning_visual_effect';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56328,'spell_random_lightning_visual_effect');

DELETE FROM `creature_text` WHERE `CreatureID`=30385;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(30385,0,0,'I have been chosen!',14,0,100,0,0,0,31179,0,'SAY_CHOSEN'),
(30385,1,0,'I give myself to the master!',14,0,100,0,0,0,30863,0,'SAY_SACRIFICED');

DELETE FROM  `creature_summon_groups` WHERE `summonerId`=29310 AND `groupId`=1;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(29310,0,1,30114, 362.458, -714.166, -16.0964, 0.977384,6,3000),
(29310,0,1,30114, 368.781, -713.932, -16.0964, 1.46608,6,3000),
(29310,0,1,30114, 364.937, -716.11, -16.0964, 1.25664,6,3000),
(29310,0,1,30114, 362.02, -719.828, -16.0964, 1.20428,6,3000),
(29310,0,1,30114, 368.151, -719.763, -16.0964, 1.53589,6,3000),
(29310,0,1,30114, 392.276, -695.895, -16.0964, 3.40339,6,3000),
(29310,0,1,30114, 387.224, -698.006, -16.0964, 3.36848,6,3000),
(29310,0,1,30114, 389.626, -702.3, -16.0964, 3.07178,6,3000),
(29310,0,1,30114, 383.812, -700.41, -16.0964, 3.15905,6,3000),
(29310,0,1,30114, 385.693, -694.376, -16.0964, 3.59538,6,3000),
(29310,0,1,30114, 379.204, -716.697, -16.0964, 2.1293,6,3000),
(29310,0,1,30114, 375.4, -711.434, -16.0964, 2.09439,6,3000),
(29310,0,1,30114, 382.583, -711.713, -16.0964, 2.53073,6,3000),
(29310,0,1,30114, 379.049, -712.899, -16.0964, 2.28638,6,3000),
(29310,0,1,30114, 378.424, -708.388, -16.0964, 2.58309,6,3000);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=29310 AND `groupId`=2;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(29310,0,2,30111,427.3021,-717.3993,-17.95177,2.70526,7,0),
(29310,0,2,30111,429.7342,-712.1823,-17.95688,2.86234,7,0),
(29310,0,2,30111,434.4365,-709.4752,-17.96144,2.949606,7,0),
(29310,0,2,30111,434.0043,-702.8975,-17.95797,3.124139,7,0),
(29310,0,2,30111,439.9826,-699.0701,-17.95278,3.193953,7,0),
(29310,0,2,30111,381.8384,-773.3898,-17.95301,1.762783,7,0),
(29310,0,2,30111,387.0695,-770.9496,-17.95761,1.972222,7,0),
(29310,0,2,30111,392.5775,-765.6364,-17.95891,2.251475,7,0),
(29310,0,2,30111,394.3542,-760.8108,-17.95462,2.443461,7,0),
(29310,0,2,30111,388.3078,-766.784,-17.96076,2.094395,7,0);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=29308 AND `groupId`=1;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(29308,0,1,30181,519.146,-792.274,49.4627,4.15388,8,0),
(29308,0,1,30181,542.994,-762.115,36.0509,1.32645,8,0),
(29308,0,1,30181,599.617,-762.315,35.3111,1.71042,8,0),
(29308,0,1,30181,506.573,-890.563,45.1763,3.35103,8,0),
(29308,0,1,30181,632.232,-774.304,34.0595,0.750492,8,0),
(29308,0,1,30181,489.944,-851.356,52.09,4.95674,8,0),
(29308,0,1,30181,655.409,-814.264,35.2257,0.436332,8,0);
