--
UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `action_type` IN (18,19) AND `entryorguid` IN (16844,16857,23285,18678,28083,21380,30340,34920) AND `source_type` = 0;

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `action_type` IN (18,19) AND `entryorguid` IN (2840500) AND `source_type` = 9;

UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 22258 AND `source_type` = 0 AND `id` = 3;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22258 AND `source_type` = 0 AND `id` BETWEEN 7 AND 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22258,0,7,0,11,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Demoniac Scryer - On Spawn - Set Reactstate Passive");

UPDATE `smart_scripts` SET `action_param1` = 256 WHERE `action_type` IN (18,19) AND `entryorguid` IN (28213) AND `source_type` = 0;

UPDATE `smart_scripts` SET `action_param1` = 256 WHERE `action_type` IN (18,19) AND `entryorguid` IN (28105) AND `source_type` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 14688 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14688,0,0,0,0,0,80,0,0,0,10000,20000,0,11,61162,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Cast 'Engulfing Strike'"),
(14688,0,1,0,0,0,80,0,15000,20000,30000,30000,0,11,61163,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Cast 'Fire Nova'"),
(14688,0,2,0,0,0,100,0,30000,30000,30000,30000,0,11,61144,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Cast 'Fire Shield'"),
(14688,0,3,4,0,0,100,0,31100,31100,30000,30000,0,11,61145,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Cast 'Ember Shower'"),
(14688,0,4,0,61,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Set Reactstate Passive"),
(14688,0,5,6,0,0,100,0,45100,45100,30000,30000,0,28,61144,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Remove Aura 'Fire Shield'"),
(14688,0,6,7,61,0,100,0,0,0,0,0,0,28,61145,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Remove Aura 'Ember Shower'"),
(14688,0,7,0,61,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - In Combat - Set Reactstate Aggressive"),
(14688,0,12,0,54,0,100,0,0,0,0,0,0,80,1468800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - On Just Summoned - Run Script"),
(14688,0,13,0,54,0,100,0,0,0,0,0,0,11,4335,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - On Just Summoned - Cast 'Spawn Smoke (scale x2.00)'"),
(14688,0,14,0,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - On Just Summoned - Say Line 0"),
(14688,0,15,0,1,0,100,1,14000,14000,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,0,"Prince Sandoval - Out of Combat - Start Attacking"),
(14688,0,16,0,5,0,100,0,0,0,0,0,0,45,20,20,0,0,0,0,11,31135,100,0,0,0,0,0,0,"Prince Sandoval - On Killed Unit - Set Data 20 20"),
(14688,0,17,0,6,0,100,0,0,0,0,0,0,45,6,6,0,0,0,0,11,31135,100,0,0,0,0,0,0,"Prince Sandoval - On Just Died - Set Data 6 6"),
(14688,0,18,0,1,0,100,1,30000,30000,0,0,0,45,19,19,0,0,0,0,11,31135,100,0,0,0,0,0,0,"Prince Sandoval - Out of Combat - Set Data 19 19"),
(14688,0,19,20,1,0,100,1,0,0,0,0,0,28,61144,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - Out of Combat - Remove Aura 'Fire Shield'"),
(14688,0,20,21,61,0,100,0,0,0,0,0,0,28,61145,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - Out of Combat - Remove Aura 'Ember Shower'"),
(14688,0,21,0,61,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Sandoval - Out of Combat - Set Reactstate Aggressive");

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 0x00000040 WHERE `action_type` IN (18,19);

UPDATE `smart_scripts` SET `action_param1` = 512 WHERE `action_type` IN (18,19) AND `entryorguid` IN (27482) AND `source_type` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30468 AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30468,0,1,0,11,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Harnessed Icemaw Matriarch - On Spawn - Set Reactstate Passive");

UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = -118282 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -118282 AND `source_type` = 0 AND `id` = 1;

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `action_type` IN (18,19) AND `entryorguid` IN (330100) AND `source_type` = 9;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24640 AND `source_type` = 0 AND `id` IN (1,2);

UPDATE `creature_template` SET `unit_flags` = 33536, `AIName` = '' WHERE `entry` = 10939;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10939 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1093900 AND `source_type` = 9;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 2390000 AND `source_type` = 9 AND `id` IN (1,2);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3013400 AND `source_type` = 9 AND `id` IN (3);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3222500 AND `source_type` = 9 AND `id` IN (2);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3188100 AND `source_type` = 9 AND `id` IN (2);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29919 AND `source_type` = 0 AND `id` BETWEEN 0 AND 5;

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `action_type` IN (18,19) AND `entryorguid` IN (2378900,2378901) AND `source_type` = 9;

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 32768 WHERE `action_type` IN (18,19) AND `entryorguid` IN (2784300,2784301) AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2784301 AND `source_type` = 9 AND `id` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25800 AND `source_type` = 0 AND `id` IN (1,2);

UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 32768 WHERE `action_type` IN (18,19);

DELETE FROM `smart_scripts` WHERE `action_type` IN (18,19) AND `entryorguid` IN (2541600,2541800) AND `source_type` = 9;

UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 0 WHERE `action_type` IN (18,19) AND `entryorguid` IN (2700300) AND `source_type` = 9;

UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 0 WHERE `action_type` IN (18,19) AND `entryorguid` IN (2962100) AND `source_type` = 9;
UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 2 WHERE `action_type` IN (18,19) AND `entryorguid` IN (29621) AND `source_type` = 0;

UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 0 WHERE `action_type` IN (18) AND `entryorguid` IN (24238) AND `source_type` = 0;
UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 2 WHERE `action_type` IN (19) AND `entryorguid` IN (24238) AND `source_type` = 0;
