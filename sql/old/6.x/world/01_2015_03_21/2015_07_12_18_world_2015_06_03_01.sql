UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`in(20875);

DELETE FROM `smart_scripts` WHERE `entryorguid`in(20875)  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20875,0,0,0,4,0,100,0,0,0,0,0,11,36733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Agro - Cast Elemental Response'),
(20875,0,1,0,9,0,100,0,0,8,12000,20000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Range  - Cast Psychic Scream'),
(20875,0,2,0,0,2,100,0,15000,25000,15000,25000,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2) - Set Phase 1'),
(20875,0,3,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Agro - Set Phase 1'),
(20875,0,4,17,8,1,100,0,0,2,0,0,11,34336,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Holy) (Phase 1) - Cast Damage Reduction: Holy'),
(20875,0,5,18,8,1,100,0,0,4,0,0,11,34333,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Fire) (Phase 1) - Cast Damage Reduction: Fire'),
(20875,0,6,19,8,1,100,0,0,8,0,0,11,34335,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Nature)(Phase 1) - Cast Damage Reduction: Nature'),
(20875,0,7,20,8,1,100,0,0,16,0,0,11,34334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Frost) (Phase 1) - Cast Damage Reduction: Frost'),
(20875,0,8,21,8,1,100,0,0,32,0,0,11,34338,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Shadow) (Phase 1)  - Cast Damage Reduction: Shadow'),
(20875,0,9,22,8,1,100,0,0,64,0,0,11,34331,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Arcane) (Phase 1)  - Cast Damage Reduction: Arcane'),
(20875,0,10,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - Link - Set Phase 2'),
(20875,0,11,0,0,2,100,2,0,0,3000,3500,11,36742,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Fireball Volley (Normal Dungeon)'),
(20875,0,12,0,0,2,100,2,0,0,3000,3500,11,36738,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Arcane Volley (Normal Dungeon)'),
(20875,0,13,0,0,2,100,2,0,0,3000,3500,11,36741,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Frostbolt Volley (Normal Dungeon)'),
(20875,0,14,0,0,2,100,2,0,0,3000,3500,11,36743,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Holy Bolt Volley (Normal Dungeon)'),
(20875,0,15,0,0,2,100,2,0,0,3000,3500,11,36740,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Lightning Bolt Volley (Normal Dungeon)'),
(20875,0,16,0,0,2,100,2,0,0,3000,3500,11,36736,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Shadow Bolt Volley (Normal Dungeon)'),
(20875,0,17,10,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Holy) (Phase 1) - Say'),
(20875,0,18,10,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Fire) (Phase 1) - Say'),
(20875,0,19,10,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Nature)(Phase 1) - Say'),
(20875,0,20,10,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Frost) (Phase 1) - Say'),
(20875,0,21,10,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Shadow) (Phase 1)  - Say'),
(20875,0,22,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Arcane) (Phase 1)  - Say'),
(20875,0,23,0,0,2,100,4,0,0,3000,3500,11,38836,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Fireball Volley (Heroic Dungeon)'),
(20875,0,24,0,0,2,100,4,0,0,3000,3500,11,38835,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Arcane Volley (Heroic Dungeon)'),
(20875,0,25,0,0,2,100,4,0,0,3000,3500,11,38837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Frostbolt Volley (Heroic Dungeon)'),
(20875,0,26,0,0,2,100,4,0,0,3000,3500,11,38838,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Holy Bolt Volley (Heroic Dungeon)'),
(20875,0,27,0,0,2,100,4,0,0,3000,3500,11,38839,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Lightning Bolt Volley (Heroic Dungeon)'),
(20875,0,28,0,0,2,100,4,0,0,3000,3500,11,38840,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Shadow Bolt Volley (Heroic Dungeon)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=20875;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 12, 20875, 0, 0, 1, 1, 34333, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Fire to cast Fireball Volley (Normal)'),
(22, 13, 20875, 0, 0, 1, 1, 34331, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Arcane to cast Arcane Volley (Normal)'),
(22, 14, 20875, 0, 0, 1, 1, 34334, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Frost to cast Frostbolt Volley (Normal)'),
(22, 15, 20875, 0, 0, 1, 1, 34336, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Holy to cast Holy Bolt Volley (Normal)'),
(22, 16, 20875, 0, 0, 1, 1, 34335, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Nature to cast Lightning Bolt Volley (Normal)'),
(22, 17, 20875, 0, 0, 1, 1, 34338, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Shadow to cast Shadow Bolt Volley (Normal)'),
(22, 24, 20875, 0, 0, 1, 1, 34333, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Fire to cast Fireball Volley (Heroic)'),
(22, 25, 20875, 0, 0, 1, 1, 34331, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Arcane to cast Arcane Volley (Heroic)'),
(22, 26, 20875, 0, 0, 1, 1, 34334, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Frost to cast Frostbolt Volley (Heroic)'),
(22, 27, 20875, 0, 0, 1, 1, 34336, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Holy to cast Holy Bolt Volley (Heroic)'),
(22, 28, 20875, 0, 0, 1, 1, 34335, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Nature to cast Lightning Bolt Volley (Heroic)'),
(22, 29, 20875, 0, 0, 1, 1, 34338, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Shadow to cast Shadow Bolt Volley (Heroic)');

DELETE FROM `creature_text` WHERE `entry`=20875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(20875, 0, 0, '%s absorbs the fire energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17105),
(20875, 1, 0, '%s absorbs the arcane energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17109),
(20875, 2, 0, '%s absorbs the frost energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17106),
(20875, 3, 0, '%s absorbs the holy energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17110),
(20875, 4, 0, '%s absorbs the nature energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17107),
(20875, 5, 0, '%s absorbs the shadow energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17108);

DELETE FROM `waypoints` where `entry`IN(14323,14321);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14323, 1, 558.6339, 549.9158, -25.39908, 'Guard Slip kik'),
(14323, 2, 550.9423, 528.1198, -25.40169, 'Guard Slip kik'),
(14323, 3, 558.6339, 549.9158, -25.39908, 'Guard Slip kik'),
(14323, 4, 573.5057, 563.2197, -25.40176, 'Guard Slip kik'),
(14323, 5, 573.2263, 586.457, -25.40273, 'Guard Slip kik'),
(14323, 6, 524.0547, 587.0665, -25.40254, 'Guard Slip kik'),
(14323, 7, 510.3508, 606.5667, -25.40364, 'Guard Slip kik'),
(14323, 8, 486.8481, 606.4826, -25.40477, 'Guard Slip kik'),
(14323, 9, 478.1636, 594.9525, -25.40531, 'Guard Slip kik'),
(14323, 10, 477.4341, 579.6123, -25.4021, 'Guard Slip kik'),
(14323, 11, 504.7797, 574.7651, -25.40086, 'Guard Slip kik'),
(14323, 12, 477.4341, 579.6123, -25.4021, 'Guard Slip kik'),
(14323, 13, 486.8481, 606.4826, -25.40477, 'Guard Slip kik'),
(14323, 14, 510.3508, 606.5667, -25.40364, 'Guard Slip kik'),
(14323, 15, 524.0547, 587.0665, -25.40254, 'Guard Slip kik'),
(14323, 16, 573.2263, 586.457, -25.40273, 'Guard Slip kik'),
(14323, 17, 573.5057, 563.2197, -25.40176, 'Guard Slip kik'),
(14321, 1, 390.7901, 340.0213, 2.865798, 'Guard Fengus'),
(14321, 2, 386.5863, 316.9394, 10.87668, 'Guard Fengus'),
(14321, 3, 385.826, 281.0563, 12.23588, 'Guard Fengus'),
(14321, 4, 385.6659, 260.2018, 11.43955, 'Guard Fengus'),
(14321, 5, 407.447, 256.0239, 12.23423, 'Guard Fengus'),
(14321, 6, 444.0919, 255.3879, 11.20982, 'Guard Fengus'),
(14321, 7, 407.4797, 258.508, 12.23421, 'Guard Fengus'),
(14321, 8, 384.6136, 256.412, 11.43955, 'Guard Fengus'),
(14321, 9, 358.8656, 258.3085, 12.23409, 'Guard Fengus'),
(14321, 10, 316.5439, 258.2672, 11.22405, 'Guard Fengus'),
(14321, 11, 287.7441, 260.7287, 2.869437, 'Guard Fengus'),
(14321, 12, 290.6053, 280.1005, 2.848812, 'Guard Fengus'),
(14321, 13, 289.7671, 310.0473, 2.853041, 'Guard Fengus'),
(14321, 14, 300.0063, 328.7043, 2.852961, 'Guard Fengus'),
(14321, 15, 294.1508, 290.1005, 2.849759, 'Guard Fengus'),
(14321, 16, 288.6681, 260.1472, 2.870163, 'Guard Fengus'),
(14321, 17, 318.0658, 258.1307, 11.22347, 'Guard Fengus'),
(14321, 18, 352.2249, 259.8816, 11.20577, 'Guard Fengus'),
(14321, 19, 379.2898, 259.8564, 11.43955, 'Guard Fengus'),
(14321, 20, 383.1255, 280.3708, 12.23591, 'Guard Fengus'),
(14321, 21, 384.3981, 315.2444, 11.21198, 'Guard Fengus'),
(14321, 22, 385.5048, 342.4915, 2.862235, 'Guard Fengus'),
(14321, 23, 350.4333, 341.1977, 2.853369, 'Guard Fengus'),
(14321, 24, 313.9085, 338.8922, 2.852938, 'Guard Fengus'),
(14321, 25, 356.01, 342.2071, 2.853216, 'Guard Fengus'),
(14321, 26, 388.9794, 340.4667, 2.864845, 'Guard Fengus'),
(14321, 27, 423.3712, 340.0448, 2.853797, 'Guard Fengus'),
(14321, 28, 454.4482, 336.7815, 2.855228, 'Guard Fengus'),
(14321, 29, 417.1513, 339.7217, 2.853512, 'Guard Fengus');

UPDATE `smart_scripts` SET `event_param1`=3, `comment`='Guard Slip\'kik - On Reached WP3 (Phase 2) - Stop WP' WHERE  `entryorguid`=14323 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `link`=14 WHERE  `entryorguid`=14325 AND `source_type`=0 AND `id`=11 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14321 AND `source_type`=0 AND `id`=6 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14323 AND `source_type`=0 AND `id`=6 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14323 AND `source_type`=0 AND `id`=6 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14324 AND `source_type`=0 AND `id`=28 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14321 AND `source_type`=0 AND `id` in(8,9);
DELETE FROM `smart_scripts` WHERE  `entryorguid`=14323 AND `source_type`=0 AND `id`=14;
UPDATE `smart_scripts` SET `link`=15 WHERE  `entryorguid`=14325 AND `source_type`=0 AND `id`=13 AND `link`=0;

DELETE FROM `smart_scripts` WHERE  `entryorguid`=14325 AND `source_type`=0 AND `id`>13;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14325 AND `source_type`=0 AND `id`=14;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14325, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Gossip Option Selected - Set Faction'),
(14325, 0, 15, 0, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Reached WP2 - Set Npc Flags'),
(14321, 0, 8, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14321, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Fengus - On Spawn - Start WP'),
(14321, 0, 9, 0, 64, 0, 100, 0, 0, 0, 0, 0, 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Fengus - On Gossip Hello - Pause WP'),
(14323, 0, 14, 0, 64, 0, 100, 0, 0, 0, 0, 0, 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip Kik - On Gossip Hello - Pause WP');
