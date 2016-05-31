-- Assign queststarter
DELETE FROM `creature_queststarter` WHERE `id`=39675 AND `quest`=25199;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(39675,25199);

-- Assign questender 
DELETE FROM `creature_questender` WHERE `id`=39675 AND `quest`=25199;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(39675,25199);

-- Update creatures to use SAI
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (39349,39368);

-- Gnomeregan Trainee SAI 
DELETE FROM `smart_scripts` WHERE `entryorguid`=39349 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39349,0,0,0,38,0,100,0,0,1,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnomeregan Trainee - On Data 0 1 Set - Emote Salute'),
(39349,0,1,0,38,0,100,0,0,2,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnomeregan Trainee - On Data 0 2 Set - Emote Roar'),
(39349,0,2,0,38,0,100,0,0,3,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnomeregan Trainee - On Data 0 3 Set - Emote Cheer'),
(39349,0,3,0,38,0,100,0,0,4,0,0,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnomeregan Trainee - On Data 0 4 Set - Emote Dance'),
(39349,0,4,0,38,0,100,0,0,5,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnomeregan Trainee - On Data 0 5 Set - Emote None');

-- Drill Sergeant Steamcrank SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=39368 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39368,0,0,0,11,0,100,0,0,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Respawn - Say Line 0'),
(39368,0,1,0,52,0,100,0,0,39368,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 1'),
(39368,0,2,0,52,0,100,0,1,39368,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 2'),
(39368,0,3,0,52,0,100,0,2,39368,0,0,1,3,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 3'),
(39368,0,4,5,52,0,100,0,3,39368,0,0,1,4,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 4'),
(39368,0,5,6,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,39349,30,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set data 0 1'),
(39368,0,6,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 1'),
(39368,0,7,0,22,1,100,0,78,0,0,0,11,73771,2,0,0,0,0,7,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Emote Received ''Salute'' - Cast ''[DND] Salute Quest Credit'' (phase 1)'),
(39368,0,8,9,52,0,100,0,4,39368,0,0,1,5,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 5'),
(39368,0,9,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 5'),
(39368,0,10,0,52,0,100,0,5,39368,0,0,1,6,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 6'),
(39368,0,11,0,52,0,100,0,6,39368,0,0,1,7,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 7'),
(39368,0,12,13,52,0,100,0,7,39368,0,0,1,8,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 8'),
(39368,0,13,14,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,11,39349,30,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set data 0 2'),
(39368,0,14,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 2'),
(39368,0,15,0,22,2,100,0,75,0,0,0,11,73832,2,0,0,0,0,7,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Emote Received ''Roar'' - Cast ''[DND] Cheer Quest Credit'' (phase 2)'),
(39368,0,16,17,52,0,100,0,8,39368,0,0,1,9,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line - Say Line 9'),
(39368,0,17,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 5'),
(39368,0,18,0,52,0,100,0,9,39368,0,0,1,10,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 10'),
(39368,0,19,0,52,0,100,0,10,39368,0,0,1,11,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 11'),
(39368,0,20,21,52,0,100,0,11,39368,0,0,1,12,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 12'),
(39368,0,21,22,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 3'),
(39368,0,22,0,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,11,39349,30,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set data 0 3'),
(39368,0,23,0,22,4,100,0,21,0,0,0,11,73833,2,0,0,0,0,7,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Emote Received ''Cheer'' - Cast ''[DND] Cheer Quest Credit'' (phase 3)'),
(39368,0,24,25,52,0,100,0,12,39368,0,0,1,13,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 13'),
(39368,0,25,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 5'),
(39368,0,26,0,52,0,100,0,13,39368,0,0,1,14,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 14'),
(39368,0,27,0,52,0,100,0,14,39368,0,0,1,15,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 15'),
(39368,0,28,29,52,0,100,0,15,39368,0,0,1,16,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 16'),
(39368,0,29,30,61,0,100,0,0,0,0,0,45,0,4,0,0,0,0,11,39349,30,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set data 0 4'),
(39368,0,30,0,61,0,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 4'),
(39368,0,31,32,52,0,100,0,16,39368,0,0,1,17,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 17'),
(39368,0,32,33,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set Phase 5'),
(39368,0,33,0,61,0,100,0,0,0,0,0,45,0,5,0,0,0,0,11,39349,30,0,0,0,0,0,'Drill Sergeant Steamcrank - Link With Previous - Set data 0 5'),
(39368,0,34,0,22,8,100,0,34,0,0,0,11,73830,2,0,0,0,0,7,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - Emote Received ''Dance'' - Cast ''[DND] Dance Quest Credit'' (phase 4)'),
(39368,0,35,0,52,0,100,0,17,39368,0,0,1,18,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 18'),
(39368,0,36,0,52,0,100,0,18,39368,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Drill Sergeant Steamcrank - On Text Over - Say Line 0');
