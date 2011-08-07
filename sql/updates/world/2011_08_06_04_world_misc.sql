-- honor challenge
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30037;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30037 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(30037,0,0,0,8,0,100,0,21855,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mjordin Combatant - set to phase 1 when aggroed by spell'),
(30037,0,1,0,6,1,100,0,0,0,0,0,33,30038,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mjordin Combatant - give credit only when it has buff');

-- forgotten depths ambusher
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30204 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(30204,0,0,0,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Depths Ambusher - change flags when aggroed'),
(30204,0,1,0,4,0,100,0,0,0,0,0,28,56422,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Depths Ambusher - remove submerge');

-- ocular
DELETE FROM `creature` WHERE `id`=29747;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) values
(29747,571,1,2,0,0,8526.228,2665.085,1045.04,2.670354,120,0,0,126000,0,0);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33555200 WHERE `entry`=29790;
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|8, `unit_flags`=`unit_flags`|4, `InhabitType`=7 WHERE `entry` IN (29747,29790);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29747;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29747 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(29747,0,0,0,0,0,100,0,1500,1500,4000,4000,11,55269,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ocular - cast Deathly Stare every 3 secs'),
 -- (29747,0,1,0,6,0,100,0,0,0,0,0,11,55288,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ocular - cast It''s All Fun and Games: The Ocular On Death'),
(29747,0,1,0,6,0,100,0,0,0,0,0,33,29803,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ocular - cast It''s All Fun and Games: The Ocular On Death'), -- temporary hack
(29747,0,2,0,25,0,100,0,0,0,0,0,75,55162,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Ocular - cast Transform on Spawn');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=55288;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(55288,55289,0, 'Ocular on script cast killcredit');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=55288;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, Comment) VALUES 
(17,0,55288,0,18,1,0,0,0, 'It''s All Fun and Games: The Ocular On Death');

-- shadow vault auras
DELETE FROM `spell_area` WHERE `spell`=30181 AND `area`=4477;
INSERT INTO `spell_area` VALUES 
(30181,4477,0,0,12896,0,1101,2,1),
(30181,4477,0,0,12897,0,690,2,1);

-- quests
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (12897,12896);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ScriptName`, `Comment`) VALUES 
(19,0,12897,0,8,12893,0,0,'', 'If he cannot be turned - horde'),
(19,0,12896,0,8,12893,0,0,'', 'If he cannot be turned - alliance');

-- temp fix
SET @VILE := 29769;
SET @LADY := 29770;
SET @LEAPER := 29840;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VILE,@LADY,@LEAPER) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@VILE,0,0,0,6,0,100,0,0,0,0,0,33,29845,0,0,0,0,0,7,0,0,0,0,0,0,0,'The Vile - On spell hit - Give kill credit'),
(@LADY,0,0,0,6,0,100,0,0,0,0,0,33,29846,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lady Nightswood - On spell hit - Give kill credit'),
(@LEAPER,0,0,0,6,0,100,0,0,0,0,0,33,29847,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Leaper - On spell hit - Give kill credit');

-- vereth quests
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (13146,13147,13160,13161,13162,13163,13164);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ScriptName`, `Comment`) VALUES 
(19,0,13146,0,8,13145,0,0,'', 'Generosity Abounds'),
(19,0,13160,0,8,13145,0,0,'', 'Stunning View'),
(19,0,13147,0,8,13145,0,0,'', 'Matchmaker'),
(19,0,13161,0,8,13146,0,0,'', 'The Rider of the Unholy'),
(19,0,13161,0,8,13147,0,0,'', 'The Rider of the Unholy'),
(19,0,13161,0,8,13160,0,0,'', 'The Rider of the Unholy'),
(19,0,13162,0,8,13146,0,0,'', 'The Rider of Frost'),
(19,0,13162,0,8,13147,0,0,'', 'The Rider of Frost'),
(19,0,13162,0,8,13160,0,0,'', 'The Rider of Frost'),
(19,0,13163,0,8,13146,0,0,'', 'The Rider of Blood'),
(19,0,13163,0,8,13147,0,0,'', 'The Rider of Blood'),
(19,0,13163,0,8,13160,0,0,'', 'The Rider of Blood'),
(19,0,13164,0,8,13161,0,0,'', 'The Fate of Bloodbane'),
(19,0,13164,0,8,13162,0,0,'', 'The Fate of Bloodbane'),
(19,0,13164,0,8,13163,0,0,'', 'The Fate of Bloodbane');

-- spawns
DELETE FROM `creature` WHERE `id` IN (29717,29719,29720,29722,29738,29740,29770,29769,29804);
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(29717,571,1,2,0,0,8335.01,2815.44,655.279,1.91986,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8416.89,2698.95,655.278,5.4655,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8337.6,2803.88,655.317,4.75039,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8313.91,2802.63,655.294,3.49066,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8375.95,2711.55,655.283,4.58118,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8353.96,2806.34,655.317,0.488692,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8379.28,2778.25,655.28,0.471239,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8364.14,2701.92,656.568,0.0349066,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8477.41,2632.19,653.252,4.90438,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8481.43,2626.01,652.453,2.44346,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8487.49,2597.66,652.453,3.735,300,0,0,12175,3893,0),
(29717,571,1,2,0,0,8482,2594.25,653.308,5.72468,300,0,0,12175,3893,0),
(29719,571,1,2,0,0,8251.46,2788.82,642.024,3.15905,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8441.54,2736.37,760.141,5.28835,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8346.44,2669.66,689.96,5.49779,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8481.1,2684.45,652.537,2.75762,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8419.11,2731.21,656.928,3.83972,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8442.5,2591.95,760.057,2.81745,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8333.68,2713.6,658.645,1.27409,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8353.3,2769.46,656.19,4.17134,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8249.88,2766.01,642.024,2.84489,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8249.3,2792.87,641.876,4.50706,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8407.3,2792.75,717.842,3.32933,300,0,0,12175,0,0),
(29719,571,1,2,0,0,8441.07,2731.16,760.057,3.90197,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8253.07,2778.52,641.94,5.84327,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8375.25,2827.48,717.925,1.25664,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8384.67,2727.19,655.276,0.523599,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8262.02,2742.37,643.984,2.56197,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8505.87,2684.41,654.01,4.31096,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8493.93,2656.29,653.637,4.39823,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8249.41,2794.36,642.251,3.02912,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8238,2798.22,638.909,2.10867,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8312.52,2676.2,689.168,3.89319,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8357.75,2724,662.616,1.15192,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8417.85,2644.77,760.057,0.294484,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8323.99,2775.64,655.539,0.820305,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8313.71,2730.07,666.374,1.41372,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8404.08,2751.16,666.536,3.59538,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8526.63,2647.68,654.274,5.81195,300,0,0,12175,0,0),
(29720,571,1,2,0,0,8510.63,2619.33,652.453,1.21255,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8419.52,2697.4,760.141,4.81711,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8413.14,2643.3,760.141,3.28122,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8313.09,2684.89,689.96,5.93412,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8407.96,2796.92,717.907,5.70723,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8382.41,2828.45,717.247,5.77289,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8418.25,2696.34,760.057,3.28026,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8338.52,2740.88,655.542,6.19592,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8284.4,2669.41,689.419,4.65308,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8348.2,2813.92,655.394,2.53073,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8320.35,2814.49,656.567,5.58505,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8349.74,2669.86,689.877,0.32094,300,0,0,12175,0,0),
(29722,571,1,2,0,0,8367.34,2745.54,655.24,0.160263,300,0,0,12175,0,0),
(29738,571,1,2,0,0,8407.75,2712.33,655.278,0.593412,300,0,0,12175,3893,0),
(29738,571,1,2,0,0,8380.24,2751.93,655.466,2.37967,300,0,0,12175,3893,0),
(29738,571,1,2,0,0,8289.62,2759.84,656.208,2.9147,300,0,0,12175,3893,0),
(29738,571,1,2,0,0,8292.34,2783.9,656.208,3.15905,300,0,0,12175,3893,0),
(29738,571,1,2,0,0,8520.61,2728.09,652.537,4.99164,300,0,0,12175,3893,0),
(29738,571,1,2,0,0,8309.55,2775.3,655.197,4.70894,300,0,0,12175,3893,2),
(29840,571,1,2,0,0,8418.5,2620.67,759.958,4.90178,300,0,0,12600,0,2),
(29770,571,1,2,0,0,8402.52,2824.4,716.659,0.954007,300,0,0,10080,8814,0),
(29769,571,1,2,0,0,8298.21,2657.99,688.695,5.5676,300,0,0,12600,0,0),
(29804,571,1,2,0,0,8395.01,2675.19,657.913,1.32645,300,0,0,63000,19970,0);


UPDATE `gameobject` SET `phasemask`=3 WHERE `guid`=62035;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29769;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29717;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29738;
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=29722;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29840;
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry`=29770;

DELETE FROM `gameobject` WHERE `id` IN (191778,191779);
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(191778,571,1,2,8600.93,2639.53,652.353,-3.12412,0,0,-0.999962,0.00873622,300,100,1),
(191779,571,1,2,8594.72,2627.14,652.353,1.15192,0,0,0.54464,0.83867,300,100,1);

-- lightbane from sniffs
DELETE FROM `event_scripts` WHERE `id`=19423;
INSERT INTO `event_scripts` VALUES
(19423,3,10,29851,300000,0,8593.944,2618.039,652.3534,3.174454);