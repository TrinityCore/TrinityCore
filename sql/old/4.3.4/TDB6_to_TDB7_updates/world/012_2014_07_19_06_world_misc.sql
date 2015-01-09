--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (34127,33550,33429);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34127,33550,33429);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34127,0,0,0,4,0,100,0,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Commander - On Aggro - Cast Charge'),
(34127,0,1,0,9,0,100,0,5,5,4000,7000,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Commander - On more than 5 yard range - Cast Shield-Breaker'),
(34127,0,2,3,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Commander - On 10-12 yard range - Cast Charge'),
(34127,0,3,0,61,0,100,0,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Commander - Linked with previous event - Cast Shield-Breaker'),
(34127,0,5,0,11,0,100,0,0,0,0,0,11,60023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Commander - On Spawn - Cast Scourge Banner Aura'),
(34127,0,6,7,9,0,100,0,0,6000,10000,15000,46,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Commander - On Range - Move forward 15 yards'),
(34127,0,7,0,61,0,100,0,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Commander - Linked with Previous Event - Cast Charge'),
(34127,0,8,9,11,0,100,0,0,0,0,0,11,59942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Commander - On Spawn - Cast Scourge Banner-Bearer'),
(34127,0,9,0,61,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Commander - Linked with Previous Event - Defend Aura'),
(33550,0,0,0,0,0,100,0,0,3000,3000,3000,11,63233,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Scout - IC - Cast Necrocution'),
(33429,0,0,1,4,0,100,0,0,0,0,0,11,62710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Lieutenant - On Agro - Cast Strong Guy Sundering Thrust Aura'),
(33429,0,1,0,61,0,100,0,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Lieutenant - Linked with Previous Event - Cast Strong Guy Sundering Thrust Aura'),
(33429,0,2,0,25,0,100,0,0,0,0,0,28,62710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Lieutenant - On Reset - Remove Strong Guy Sundering Thrust Aura'),
(33429,0,3,4,9,0,100,0,0,6000,10000,15000,46,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Lieutenant - On Range - Move forward 15 yards'),
(33429,0,4,0,61,0,100,0,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Lieutenant - Linked with Previous Event - Cast Charge'),
(33429,0,5,0,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Boneguard Lieutenant - On 10-12 yard range - Cast Charge'),
(33429,0,6,0,11,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Boneguard Lieutenant - On Spawn - Defend Aura');
