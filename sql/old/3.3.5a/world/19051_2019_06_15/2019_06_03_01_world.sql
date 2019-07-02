-- 
DELETE FROM `creature` WHERE `id`  IN (23153,23154) AND `guid` IN (109148, 109149, 109150, 109151, 109152, 109223, 109498, 109499, 109504, 109626, 109631, 109643);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(109148, 23153, 530, 1, 1, 1, 4117.67, 5379.04, 266.612, 2.49582, 1800, 0, 2),
(109149, 23153, 530, 1, 1, 1, 3971.33, 5668.72, 267.517, 3.35698, 1800, 0, 2),
(109150, 23153, 530, 1, 1, 1, 3914.38, 4913.13, 268.249, 1.44054, 1800, 0, 2),
(109151, 23153, 530, 1, 1, 1, 4078.18, 5123.28, 266.949, 2.26103, 1800, 0, 2),
(109152, 23154, 530, 1, 1, 1, 4110.278 ,5381.844, 266.1487, 5.727434, 1800, 0, 0),
(109223, 23154, 530, 1, 1, 1, 4114.102 ,5368.567, 267.6211, 1.418258, 1800, 0, 0),
(109498, 23154, 530, 1, 1, 1, 3967.494 ,5675.388, 267.7566, 4.963231, 1800, 0, 0),
(109499, 23154, 530, 1, 1, 1, 3967.432 ,5660.811, 268.5316, 1.414797, 1800, 0, 0),
(109504, 23154, 530, 1, 1, 1, 3920.013 ,4910.366, 267.7971, 2.549393, 1800, 0, 0),
(109626, 23154, 530, 1, 1, 1, 3915.637 ,4918.675, 268.0701, 4.993489, 1800, 0, 0),
(109631, 23154, 530, 1, 1, 1, 4070.757 ,5127.342, 267.5959, 5.573686, 1800, 0, 0),
(109643, 23154, 530, 1, 1, 1, 4076.135 ,5114.612, 267.8706, 1.363137, 1800, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (109148, 109149, 109150, 109151);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(109148,1091480,0,1,'40306'),
(109149,1091490,0,1,'40306'),
(109150,1091500,0,1,'40306'),
(109151,1091510,0,1,'40306');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13,17) AND `SourceEntry`=40307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,40307,0,0,31,0,3,22175,0,0,0,'','Stasis Field'),
(13,3,40307,0,0,1,0,40307,0,0,1,0,'','Stasis Field'),
(13,3,40307,0,1,31,0,3,22255,0,0,0,'','Stasis Field'),
(13,3,40307,0,1,1,0,40307,0,0,1,0,'','Stasis Field'),
(13,3,40307,0,2,31,0,3,22181,0,0,0,'','Stasis Field'),
(13,3,40307,0,2,1,0,40307,0,0,1,0,'','Stasis Field'),
(13,3,40307,0,3,31,0,3,22180,0,0,0,'','Stasis Field'),
(13,3,40307,0,3,1,0,40307,0,0,1,0,'','Stasis Field');

DELETE FROM `creature_text` WHERE `CreatureID`=23153;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23153, 0, 0, 'Check those crystals over there!', 12,0,100,1,0,0,21004,0, 'Bash''ir Surveyor (Entry: 23153)'),
(23153, 0, 1, 'Find what I am looking for and you may have a treat.', 12,0,100,1,0,0,21007,0, 'Bash''ir Surveyor (Entry: 23153)'),
(23153, 0, 2, 'That grouping looks promising.', 12,0,100,1,0,0,21006,0, 'Bash''ir Surveyor (Entry: 23153)'),
(23153, 1, 0, 'I am beginning to suspect you are worthless.  Do not disappoint me further.', 12,0,100,1,0,0,21008,0, 'Bash''ir Surveyor (Entry: 23153)'),
(23153, 1, 1, 'Yes, that''s it.  These will do nicely.', 12,0,100,1,0,0,21009,0, 'Bash''ir Surveyor (Entry: 23153)'),
(23153, 1, 2, 'You''ve found nothing?  Very well.  Over there next.', 12,0,100,1,0,0,21005,0, 'Bash''ir Surveyor (Entry: 23153)');

DELETE FROM `pool_template` WHERE `entry` IN (645,646,647,648,649);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(645, 3, 'Bash''ir - Bash''ir Surveyor (23153) and Mana-debt Slave (23154) 1'),
(646, 3, 'Bash''ir - Bash''ir Surveyor (23153) and Mana-debt Slave (23154) 2'),
(647, 3, 'Bash''ir - Bash''ir Surveyor (23153) and Mana-debt Slave (23154) 3'),
(648, 3, 'Bash''ir - Bash''ir Surveyor (23153) and Mana-debt Slave (23154) 4'),
(649, 1, 'Bash''ir - Bash''ir Surveyor (23153) and Mana-debt Slave (23154) Mother Pool');

DELETE FROM `pool_creature` WHERE `pool_entry` IN (645,646,647,648);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(109148,645, 0, 'Bash''ir Surveyor (23153)'),
(109152,645, 0, 'Mana-debt Slave (23154)'),
(109223,645, 0, 'Mana-debt Slave (23154)'),
(109149,646, 0, 'Bash''ir Surveyor (23153)'),
(109498,646, 0, 'Mana-debt Slave (23154)'),
(109499,646, 0, 'Mana-debt Slave (23154)'),
(109150,647, 0, 'Bash''ir Surveyor (23153)'),
(109504,647, 0, 'Mana-debt Slave (23154)'),
(109626,647, 0, 'Mana-debt Slave (23154)'),
(109151,648, 0, 'Bash''ir Surveyor (23153)'),
(109631,648, 0, 'Mana-debt Slave (23154)'),
(109643,648, 0, 'Mana-debt Slave (23154)');

DELETE FROM `pool_pool` WHERE `mother_pool`=649;
INSERT INTO `pool_pool` (`pool_id`, `mother_pool`, `chance`, `description`) VALUES 
(645, 649, 0, 'Bash''ir Surveyor (23153) and Mana-debt Slave (23154)'),
(646, 649, 0, 'Bash''ir Surveyor (23153) and Mana-debt Slave (23154)'),
(647, 649, 0, 'Bash''ir Surveyor (23153) and Mana-debt Slave (23154)'),
(648, 649, 0, 'Bash''ir Surveyor (23153) and Mana-debt Slave (23154)');

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (109148,109149,109150,109151);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(109148, 109148, 0, 0, 515, 0, 0),
(109148, 109152, 5, 70, 515, 0, 0),
(109148, 109223, 5, 290, 515, 0, 0),
(109149, 109149, 0, 0, 515, 0, 0),
(109149, 109498, 5, 70, 515, 0, 0),
(109149, 109499, 5, 290, 515, 0, 0),
(109150, 109150, 0, 0, 515, 0, 0),
(109150, 109504, 5, 70, 515, 0, 0),
(109150, 109626, 5, 290, 515, 0, 0),
(109151, 109151, 0, 0, 515, 0, 0),
(109151, 109631, 5, 70, 515, 0, 0),
(109151, 109643, 5, 290, 515, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` IN (1091480, 1091490, 1091500, 1091510);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`,`action`, `orientation`, `action_chance`, `move_type`, `wpguid`) VALUES
(1091480,1,4088.924,5360.324,266.8262,0,0,100, 100, 0, 0),
(1091480,2,4086.19,5334.616,272.1114,30000,0,100, 100, 0, 0),
(1091480,3,4055.083,5388.747,268.2536,0,0,100, 100, 0, 0),
(1091480,4,4018.438,5403.46,266.9296,30000,0,100, 100, 0, 0),
(1091480,5,4041.49,5440.908,266.7763,0,0,100, 100, 0, 0),
(1091480,6,4061.738,5470.963,267.3727,30000,0,100, 100, 0, 0),
(1091480,7,4081.422,5433.799,266.9398,0,0,100, 100, 0, 0),
(1091480,8,4088.155,5399.219,264.8799,0,0,100, 100, 0, 0),
(1091480,9,4099.717,5375.085,265.682,0,2315301,100, 100, 0, 0),
(1091490,1,3950.579,5664.166,267.8868,0,0,100, 100, 0, 0),
(1091490,2,3949.695,5648.014,267.833,30000,0,100, 100, 0, 0),
(1091490,3,3939.836,5699.776,267.8054,0,0,100, 100, 0, 0),
(1091490,4,3917.208,5714.594,267.5573,30000,0,100, 100, 0, 0),
(1091490,5,3953.256,5680.032,268.8732,0,0,100, 100, 0, 0),
(1091490,6,3983.988,5671.252,266.8484,0,0,100, 100, 0, 0),
(1091490,7,4018.189,5675.339,266.136,0,0,100, 100, 0, 0),
(1091490,8,4045.02,5677.407,267.089,30000,0,100, 100, 0, 0),
(1091490,9,4001.402,5668.4,267.5134,0,0,100, 100, 0, 0),
(1091490,10,3974.07,5668.724,267.664,0,2315301,100, 100, 0, 0),
(1091500,1,3921.228,4965.274,266.4946,0,0,100, 100, 0, 0),
(1091500,2,3910.742,4992.671,267.6488,30000,0,100, 100, 0, 0),
(1091500,3,3954.662,4958.776,266.2497,0,0,100, 100, 0, 0),
(1091500,4,3990.942,4941.342,268.8905,0,0,100, 100, 0, 0),
(1091500,5,4003.885,4918.704,266.4579,0,0,100, 100, 0, 0),
(1091500,6,4019.997,4916.955,265.7477,30000,0,100, 100, 0, 0),
(1091500,7,4001.091,4867.379,267.7419,0,0,100, 100, 0, 0),
(1091500,8,3966.167,4855.453,267.1823,0,0,100, 100, 0, 0),
(1091500,9,3938.668,4864.629,266.8073,0,0,100, 100, 0, 0),
(1091500,10,3917.792,4875.084,266.7963,30000,0,100, 100, 0, 0),
(1091500,11,3930.731,4901.205,267.671,0,0,100, 100, 0, 0),
(1091500,12,3917.535,4918.631,267.874,0,2315301,100, 100, 0, 0),
(1091510,1,4049.228,5158.38,265.8159,0,0,100, 100, 0, 0),
(1091510,2,4049.228,5158.38,265.8159,30000,0,100, 100, 0, 0),
(1091510,3,4013.033,5126.243,267.2072,0,0,100, 100, 0, 0),
(1091510,4,3994.749,5096.724,266.9342,0,0,100, 100, 0, 0),
(1091510,5,3972.481,5072.851,268.5905,30000,0,100, 100, 0, 0),
(1091510,6,4017.094,5033.253,268.2528,0,0,100, 100, 0, 0),
(1091510,7,4029.895,5002.403,267.9489,0,0,100, 100, 0, 0),
(1091510,8,4054.003,4995.914,267.5135,30000,0,100, 100, 0, 0),
(1091510,9,4058.921,5066.56,268.2322,0,0,100, 100, 0, 0),
(1091510,10,4066.631,5099.14,267.5258,0,0,100, 100, 0, 0),
(1091510,11,4069.543,5118.533,267.2003,0,0,100, 100, 0, 0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (23153,23154);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-109148,-109149,-109150,-109151,23153,23154) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2315300,2315301) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-109148,0,0,0,34,0,100,0,2,1,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109148,0,1,0,34,0,100,0,2,3,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109148,0,2,0,34,0,100,0,2,5,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109148,0,3,0,34,0,100,0,2,8,0,0,80,2315301,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109149,0,0,0,34,0,100,0,2,1,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109149,0,1,0,34,0,100,0,2,3,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109149,0,2,0,34,0,100,0,2,7,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109149,0,3,0,34,0,100,0,2,9,0,0,80,2315301,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109150,0,0,0,34,0,100,0,2,1,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109150,0,1,0,34,0,100,0,2,5,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109150,0,2,0,34,0,100,0,2,9,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109150,0,3,0,34,0,100,0,2,11,0,0,80,2315301,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109151,0,0,0,34,0,100,0,2,1,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109151,0,1,0,34,0,100,0,2,4,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109151,0,2,0,34,0,100,0,2,7,0,0,80,2315300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(-109151,0,3,0,34,0,100,0,2,10,0,0,80,2315301,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On movement informer - Run Script"),
(2315300,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,1,0,0,0,19,23154,20,0,0,0,0,0,"Bash'ir Surveyor - On Script - Run Script"),
(2315300,9,1,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,11,23154,20,0,0,0,0,0,"Bash'ir Surveyor - On Script - Despawn"),
(2315300,9,2,0,0,0,100,0,24000,24000,0,0,1,1,0,1,0,0,0,19,23154,20,0,0,0,0,0,"Bash'ir Surveyor - On Script - Despawn"),
(2315300,9,3,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,11,23154,20,0,0,0,0,0,"Bash'ir Surveyor - On Script - Despawn"),
(2315301,9,0,0,0,0,100,0,0,0,0,0,1,0,0,1,0,0,0,19,23154,20,0,0,0,0,0,"Bash'ir Surveyor - On Script - Run Script"),
(2315301,9,1,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,11,23154,40,0,0,0,0,0,"Bash'ir Surveyor - On Script - Despawn"),
(2315301,9,2,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Surveyor - On Script - Despawn"),
(23154,0,0,0,38,0,100,0,1,1,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana-debt Slave - On data set - Emote state work"), 
(23154,0,1,0,38,0,100,0,2,2,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana-debt Slave - On data set - Emote state none");
