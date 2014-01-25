--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=16847;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16847 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16847,0,0,1,8,0,100,0,29314,0,60000,60000,33,16847,0,0,0,0,0,7,0,0,0,0,0,0,0,'Debilitated Maghar Grunt - On Spellhit (Quest - Healing Salve) - Give Kill Credit'),
(16847,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Debilitated Maghar Grunt - Linked with Previous Event - Say'),
(16847,0,2,3,61,0,100,0,0,0,0,0,3,16846,0,0,0,0,0,1,0,0,0,0,0,0,0,'Debilitated Maghar Grunt - Linked with Previous Event - Change Entry'),
(16847,0,3,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Debilitated Maghar Grunt - Linked with Previous Event - Despawn'),
(16847,0,4,0,25,0,100,0,0,0,0,0,3,16847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Debilitated Maghar Grunt - On Spawn - Change Entry');


DELETE FROM `creature_text` WHERE `entry` =16847;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16847,0,0,'My strength.... is... returning!',12,0,100,0,0,0,'Debilitated Maghar Grunt'),
(16847,0,1,'You''ve found a cure! We will crush our enemies!',12,0,100,0,0,0,'Debilitated Maghar Grunt'),
(16847,0,2,'You''ve restored my health! I''m in your debt, $N.',12,0,100,0,0,0,'Debilitated Maghar Grunt');
