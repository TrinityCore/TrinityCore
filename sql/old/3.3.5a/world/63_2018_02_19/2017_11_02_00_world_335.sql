-- Aquementas (9453)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`=9453;

DELETE FROM `creature_text` WHERE `CreatureID`=9453;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(9453, 0, 0, 'Who dares awaken Aquementas?', 14, 0, 100, 0, 0, 0, 5465, 0, 'Aquementas'),
(9453, 1, 0, '$n, you have disturbed me from my rest!', 12, 0, 100, 0, 0, 0, 5463, 0, 'Aquementas'),
(9453, 2, 0, '%s begins to cast a powerful spell.', 16, 0, 100, 0, 0, 0, 5427, 0, 'Aquementas'),
(9453, 3, 0, '%s transforms the items into a totem.', 16, 0, 100, 0, 0, 0, 5428, 0, 'Aquementas');

DELETE FROM `smart_scripts` WHERE `entryorguid`=9453 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(9453, 0,  0,  0,  0, 0, 100, 0, 1000, 1000, 15000, 18000, 11, 15089, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Aquementas - IC - Cast 'Frost Shock'"),
(9453, 0,  1,  0,  0, 0, 100, 0, 5000, 5000, 15000, 18000, 11, 13586, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Aquementas - IC - Cast 'Aqua Jet'"),
(9453, 0,  2,  3, 11, 0, 100, 0, 0, 0, 0, 0,   2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Spawn - Set Faction 35"),
(9453, 0,  3,  4, 61, 0, 100, 0, 0, 0, 0, 0,   1,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Spawn - Say Line 0"),
(9453, 0,  4,  0, 61, 0, 100, 0, 0, 0, 0, 0,  53,1,9453, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Spawn - Start WP"),
(9453, 0,  5,  6, 40, 0, 100, 0, 5, 0, 0, 0, 101,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Reached WP5 - Set Home Position"),
(9453, 0,  6,  7, 61, 0, 100, 0, 0, 0, 0, 0,   2, 91, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Reached WP5 - Set Faction 91"),
(9453, 0,  7,  0, 61, 0, 100, 0, 0, 0, 0, 0,   8,  2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Reached WP5 - Set Aggresive"),
(9453, 0,  8,  9,  4, 0, 100, 0, 0, 0, 0, 0,   1,  1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Aggro - Say Line 1"),
(9453, 0,  9, 10, 61, 0, 100, 0, 0, 0, 0, 0,   1,  2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Aggro - Say Line 2 (targets self)"),
(9453, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0,   1,  3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Aggro - Say Line 3 (targets self)"),
(9453, 0, 11,  0, 61, 0, 100, 0, 0, 0, 0, 0, 85,13909,2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Aquementas - On Aggro - Invoker Cast Create Elemental Totem");

DELETE FROM `waypoints` WHERE `entry`= 9453;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
(9453, 1, -8183.86, -5113.11,  7.3958, 'Aquementas'),
(9453, 2, -8183.93, -5106.03,  8.5556, 'Aquementas'),
(9453, 3, -8180.63, -5088.66, 12.3430, 'Aquementas'),
(9453, 4, -8177.40, -5083.53, 14.0073, 'Aquementas'),
(9453, 5, -8172.82, -5075.97, 15.8171, 'Aquementas');

DELETE FROM `event_scripts` WHERE `id`=3708;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES 
(3708, 0, 10, 9453, 300000, 0, -8176.68, -5155.78, 4.55307, 1.42);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=13909;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17, 0, 13909, 0, 0, 2, 0, 11172, 11, 0, 0, 0, 0, "", "Allow to cast spell 'Create Elemental Totem' if caster has item 'Silvery Claws' x11 in inventory"),
(17, 0, 13909, 0, 0, 2, 0, 11173,  1, 0, 0, 0, 0, "", "Allow to cast spell 'Create Elemental Totem' if caster has item 'Irontree Heart' in inventory"),
(17, 0, 13909, 0, 0, 2, 0, 11169,  1, 0, 0, 0, 0, "", "Allow to cast spell 'Create Elemental Totem' if caster has item 'Book of Aquor' in inventory");
