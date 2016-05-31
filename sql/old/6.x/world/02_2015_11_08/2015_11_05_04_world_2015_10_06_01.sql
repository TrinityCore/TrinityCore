-- Sheddle Glossgleam
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=194115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29703;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (194115) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29703) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2970300, 19411500) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(194115, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 80, 19411500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shoeshine Seat - On Gossip hello - Action list'),
(19411500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shoeshine Seat - Action list - Store target'),
(19411500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 29703, 20, 0, 0, 0, 0, 0, 'Shoeshine Seat - Action list - Send Target'),
(19411500, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29703, 20, 0, 0, 0, 0, 0, 'Shoeshine Seat - Action list - Set Data'),
(29703, 0, 0, 0, 38, 0, 100, 0, 1, 1, 13000, 13000, 80, 2970300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - On Data set - Action list'),
(2970300, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Say text'),
(2970300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Set run off'),
(2970300, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5810.110, 676.122, 658.0285, 5.002982, 'Sheddle Glossgleam- Action list - Move to pos'),
(2970300, 9, 3, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5810.110, 676.122, 658.0285, 5.002982, 'Sheddle Glossgleam - Action list - Set Orientation'),
(2970300, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Cast Kneel'),
(2970300, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 28, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Remove Kneel aura'),
(2970300, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 62089, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Cast Shiny Shoes'),
(2970300, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Sheddle Glossgleam - Action list - Say text'),
(2970300, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5812.08, 676.872, 658.112, 3.071780, 'Sheddle Glossgleam - Action list - Move to pos'),
(2970300, 9, 9, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5812.08, 676.872, 658.112, 3.071780, 'Sheddle Glossgleam - Action list - Set Orientation');

DELETE FROM `creature_text` WHERE `entry` IN (29703);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(29703,0,0,'Need a shoeshine, $c?',12,0,100,0,0,0, 'Sheddle Glossgleam',33178),
(29703,0,1,'One shoeshine coming up!',12,0,100,0,0,0, 'Sheddle Glossgleam',33180),
(29703,0,2,'Let me shine your shoes, $c.',12,0,100,0,0,0, 'Sheddle Glossgleam',33181),
(29703,1,0,'Take care of that shine, $c.',12,0,100,0,0,0, 'Sheddle Glossgleam',33179),
(29703,1,1,'Shiny!',12,0,100,0,0,0, 'Sheddle Glossgleam',33182),
(29703,1,2,'Another shiny, happy person.  Take care, $c!',12,0,100,0,0,0, 'Sheddle Glossgleam',33183);
