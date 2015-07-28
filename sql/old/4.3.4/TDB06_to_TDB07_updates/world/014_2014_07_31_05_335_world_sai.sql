/*UPDATE `creature_text` SET `type`=14 WHERE  `entry`=8391 AND `groupid`=1 AND `id`=0;

DELETE FROM `creature_text` WHERE `entry`IN(8421, 8391);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(8421, 0, 0, 'Fools. I knew that if I played upon my brother''s feeble emotions, he would send ''rescuers.''', 12, 0, 100, 0, 0, 0, 'Dorius', 4394),
(8421, 1, 0, 'How easy it was to manipulate you into recovering the last Suntara stone from those imbeciles of the Twilight\'s Hammer.', 12, 0, 100, 0, 0, 0, 'Dorius', 4395),
(8421, 2, 0, 'When I stumbled upon the Suntara stones at the Grimesilt Digsite, the power of Ragnaros surged through my being. It was Ragnaros that gave me a purpose.', 12, 0, 100, 0, 0, 0, 'Dorius', 4396),
(8421, 3, 0, 'It was the will of Ragnaros that Obsidion be built. Obsidion will destroy the Blackrock orcs of Blackrock Spire, uniting us with our bretheren in the fiery depths.', 12, 0, 100, 0, 0, 0, 'Dorius', 4397),
(8421, 4, 0, 'And ultimately, it was Ragnaros that named me when I was reborn as an acolyte of fire: Lathoric... Lathoric the Black.', 12, 0, 100, 0, 0, 0, 'Dorius', 4398),
(8421, 5, 0, '%s''s laughter trails off...', 16, 0, 100, 0, 0, 0, 'Dorius', 4399),
(8421, 6, 0, 'Bravo! Bravo! Good show. What? You thought I was dead?', 12, 0, 100, 0, 0, 0, 'Dorius', 4393),
(8391, 0, 0, 'Your task is complete. Prepare to meet your doom.', 12, 0, 100, 0, 0, 0, 'Lathoric the Black', 4391),
(8391, 1, 0, 'Obsidion, Rise and Serve your Master!', 14, 0, 100, 0, 0, 0, 'Lathoric the Black', 4392);

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry`=148498;

DELETE FROM `smart_scripts` WHERE `entryorguid` =148498;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(148498,1,0,1,62,0,100,0,1282,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Altar of Suntara - On Gossip Select - Close gossip'),
(148498,1,1,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,8400,0,0,0,0,0,0,'Altar of Suntara - Linked with previous event - Set Data 3 3 on Obsidion');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=8391;

DELETE FROM `smart_scripts` WHERE `entryorguid` =8391;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8391, 0,0,0,11,0,100,0,0,0,0,0,69,0,0,0,0,0,0,19,8400,0,0,0,0,0,0,'Lathoric the Black - On Spawn - Move to Altar of Suntara'),
(8391, 0,1,2,1,0,100,1,8000,8000,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - OOC (No Repeat) - Set Home Position'),
(8391, 0,2,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,'Lathoric the Black - Linked with Previous Event - Attack'),
(8391, 0,3,0,7,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - On Evade - Despawn'),
(8391, 0,4,0,11,0,100,1,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - On Spawn - Set React State Defensive');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=8400;

DELETE FROM `smart_scripts` WHERE `entryorguid` =8400;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8400, 0,0,1,38,0,100,0,1,1,0,0,19,256,0,0,0,0,0,8,0,0,0,0,0,0,0,'Obsidion - On Data Set - Remove Unattackable Flags'),
(8400, 0,1,2,61,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Obsidion - Linked with Previous Event - Set Bytes_1'),
(8400, 0,2,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,'Obsidion - Linked with Previous Event - Attack'),
(8400, 0,3,4,7,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Obsidion - On Evade - Set Bytes_1'),
(8400, 0,4,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Obsidion - On Evade - Set Unit Flags'),
(8400, 0,5,0,9,0,100,0,0,10,20000,30000,11,12734,2,0,0,0,0,1,0,0,0,0,0,0,0,'Obsidion - On Range - Cast Floor Smash'),
(8400, 0,6,0,9,0,100,0,0,5,15000,30000,11,10101,2,0,0,0,0,7,0,0,0,0,0,0,0,'Obsidion - On Range - Cast Knock Away'),
(8400, 0,7,8,38,0,100,0,2,2,60000,60000,12,8421,3,31000,0,0,0,8,0,0,0,-6481.127441,-1237.451538,180.067535,5.104429,'Obsidion - On Data Set 2 2 - Spawn Dorius'),
(8400, 0,8,0,61 ,0,100,1,8000,8000,0,0,1,6,5000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - OOC - Say (Dorius)'),
(8400, 0,9,0,52,0,100,0,0,8421,0,0,1,1,5000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,10,0,52,0,100,0,1,8421,0,0,1,2,5000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,11,0,52,0,100,0,2,8421,0,0,1,3,5000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,12,0,52,0,100,0,3,8421,0,0,1,4,3000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,13,14,52,0,100,0,4,8421,0,0,1,5,3000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,14,0,61,0,100,0,0,0,0,0,12,8391,3,300000,0,0,0,8,0,0,0,-6528.036621,  -1233.628296, 182.052963, 5.990324,'Obsidion - On Text Over - Spawn Lathoric The Black'),
(8400, 0,16,0,52,0,100,0,5,8421,0,0,1,0,5000,0,0,0,0,19,8391,0,0,0,0,0,0,'Obsidion - On Text Over - Say (Lathoric the Black)'),
(8400, 0,17,0,52,0,100,0,6,8421,0,0,1,0,5000,0,0,0,0,9,8421,0,100,0,0,0,0,'Obsidion - On Text Over - Say (Dorius)'),
(8400, 0,18,0,52,0,100,0,0,8391,0,0,1,1,2000,0,0,0,0,19,8391,0,0,0,0,0,0,'Obsidion - On Text Over - Say (Lathoric the Black)'),
(8400, 0,19,20,52,0,100,0,1,8391,0,0,45,2,2,0,0,0,0,19,8391,0,0,0,0,0,0,'Obsidion - On Text Over- Send Data to Lathoric the Black'),
(8400, 0,20,0,61,0,100,0,1,0,0,0,45,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - OOC - Send Data to Obsidion');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=8417;

DELETE FROM `smart_scripts` WHERE `entryorguid` =8417;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8417,0,0,0,19,0,100,0,3566,0,0,0,45,2,2,0,0,0,0,19,8400,0,0,0,0,0,0,' Dying Archaeologist - On Quest Accept - Set Data 2 2 on Obsidion');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=8421;

DELETE FROM `smart_scripts` WHERE `entryorguid` =8421;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8421, 0,0,1,11,0,100,1,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dorius - On Spawn - Set React State Defensive'),
(8421, 0,1,0,61,0,100,1,0,0,0,0,2,120,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dorius - On Spawn - Set Faction');
*/
