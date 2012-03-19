DELETE FROM `creature` WHERE `id` IN (28538,29056,28563);
DELETE FROM `creature` WHERE `id`=28320 AND `guid` BETWEEN 40451 AND 40462 OR `guid` IN (40466,40467);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Cultist Saboteur
(40271,28538,571,1,1,0,0,6197.03,4772.67,221.593,4.62512,120,0,0,1,0,0,0,0,0),
(40272,28538,571,1,1,0,0,6207.94,4791.03,224.951,0.504098,120,0,0,1,0,0,0,0,0),
(40273,28538,571,1,1,0,0,6209.31,4766.71,224.144,3.22886,120,0,0,1,0,0,0,0,0),
(40274,28538,571,1,1,0,0,6177.88,4737.93,224.747,2.24767,120,0,0,1,0,0,0,0,0),
(40275,28538,571,1,1,0,0,6185.42,4760.61,224.796,1.62316,120,0,0,1,0,0,0,0,0),
(40276,28538,571,1,1,0,0,6195.94,4761.25,220.873,1.53589,120,0,0,1,0,0,0,0,0),
(40277,28538,571,1,1,0,0,6231.93,4739.39,224.738,5.95606,120,0,0,1,0,0,0,0,0),
(40278,28538,571,1,1,0,0,6208.1,4762.39,222.758,2.87979,120,0,0,1,0,0,0,0,0),
-- Servant of Freya
(40451,28320,571,1,1,0,0,6177.58,4762.69,225.418,1.78024,120,0,0,1,0,0,0,0,0),
(40452,28320,571,1,1,0,0,6236,4785.33,224.865,1.90241,120,0,0,1,0,0,0,0,0),
(40453,28320,571,1,1,0,0,6218.78,4772.22,224.84,5.41052,120,0,0,1,0,0,0,0,0),
(40454,28320,571,1,1,0,0,6191.46,4728.85,224.807,5.86431,120,0,0,1,0,0,0,0,0),
(40455,28320,571,1,1,0,0,6206.62,4787.49,224.797,4.64258,120,0,0,1,0,0,0,0,0),
(40456,28320,571,1,1,0,0,6185.58,4761.77,224.796,4.39823,120,0,0,1,0,0,0,0,0),
(40457,28320,571,1,1,0,0,6226.41,4738,224.796,5.61996,120,0,0,1,0,0,0,0,0),
(40458,28320,571,1,1,0,0,6206.94,4750.79,224.796,3.78736,120,0,0,1,0,0,0,0,0),
(40459,28320,571,1,1,0,0,6238.17,4731.89,224.783,3.92699,120,0,0,1,0,0,0,0,0),
(40460,28320,571,1,1,0,0,6177.83,4730.03,224.693,0.244346,120,0,0,1,0,0,0,0,0),
(40461,28320,571,1,1,0,0,6168.2,4749.64,224.577,5.0091,120,0,0,1,0,0,0,0,0),
(40462,28320,571,1,1,0,0,6242.58,4769.51,224.443,2.98451,120,0,0,1,0,0,0,0,0),
(40466,28320,571,1,1,0,0,6217.79,4796.46,224.431,1.39626,120,0,0,1,0,0,0,0,0),
(40467,28320,571,1,1,0,0,6254.19,4757.5,217.856,0.837758,120,0,0,1,0,0,0,0,0),
-- Glimmering Pillar Credit
(40468,29056,571,1,1,0,0,6201.76,4764.45,225.84,3.19395,120,0,0,1,0,0,0,0,0),
-- Freya's Presence
(40469,28563,571,1,1,0,0,6203.26,4765.47,248.057,1.95477,120,0,0,1,0,0,0,0,0);

-- by Valcorb
DELETE FROM `gameobject` WHERE `id`=300223;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(227,300223,571,1,1,6204.758301,4766.002930,221.531799,0,0,0,0,0,300,0,1);

UPDATE `creature_template` SET `unit_flags`=0,`MovementType`=1 WHERE `entry`=28320; -- Servant of Freya
UPDATE `creature_template` SET `MovementType`=1 WHERE `entry`=28538; -- Cultist Saboteur
UPDATE `creature_template` SET `exp`=0,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=28563; -- Freya's Presence

DELETE FROM `creature_template_addon` WHERE `entry` IN (28538,29036,28320,28563);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28538,0,0,1,69, NULL), -- Cultist Saboteur (EMOTE_STATE_USE_STANDING)
(29036,0,0,1,0, '52948 61750 61751'), -- Servant of Freya (All Wild Growth, visual effects)
(28320,0,0,1,429, NULL), -- Servant of Freya
(28563,0,0,1,0, NULL); -- Freya's Presence

DELETE FROM `creature_text` WHERE `entry`=28563;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28563,0,0, 'The structure above begins to hum with energy.',42,0,0,0,0,0, 'Freya''s Presence - On Call of the Lifewarden cast');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (51318,51395);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,51318,0,0,18,1,28320,0,0, '', 'Freya Dummy - Target Servant of Freya'),
(13,0,51395,0,0,18,1,28538,0,0, '', 'Lifeforce - Target Cultist Saboteur');

DELETE FROM `spell_script_names` WHERE `spell_id`=51957;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51957,'spell_q12620_the_lifewarden_wrath');
