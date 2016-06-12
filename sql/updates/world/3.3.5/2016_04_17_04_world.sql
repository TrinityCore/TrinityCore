--
-- Quest Bring 'Em Back Alive
UPDATE `creature_template_addon` SET `auras`=45771 WHERE  `entry`=25596;
UPDATE `creature_template` SET `spell1`=45876, `spell2`=45877 WHERE  `entry`=25596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=25607; 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25596, 25607) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2560700) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25596, 0, 0, 0, 0, 0, 100, 0, 10000, 12000, 20000, 22000, 11, 45876, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - In Combat - Cast \'Stampede\''),
(25596, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Aggro - Remove Flag Standstate Dead'),
(25596, 0, 2, 3, 27, 0, 100, 0, 0, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Passenger Boarded - Remove Flag Standstate Dead'),
(25596, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 28, 45771, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Link - Remove Aura \'Scourge Infection\' (No Repeat)'),
(25596, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Link - Remove Aura \'Scourge Infection\' (No Repeat)'),
(25596, 0, 5, 6, 31, 0, 100, 0, 45877, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Target Spell Hit \'Deliver Kodo\' - Eject passenger'),
(25596, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 25607, 20, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Target Spell Hit \'Deliver Kodo\' - Set data'),
(25596, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infected Kodo Beast - On Target Spell Hit \'Deliver Kodo\' - Despawn Instant'),
(25607, 0, 0, 0, 38, 0, 100, 0, 0, 1, 3000, 3000, 80, 2560700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Farmer Torp - In Data set - Action list'),
(2560700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 84, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Farmer Torp - Action list - Player talk'),
(2560700, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Farmer Torp - Action list - Say text');

DELETE FROM `creature_text` WHERE `entry` IN (25607, 25596);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25607,0,0,"Here's your kodo, Torp!",12,100,24881,0,"Farmer Torp"),
(25607,0,1,"Door-to-door kodo delivery!",12,100,24882,0,"Farmer Torp"),
(25607,1,0,"YES! It worked!",12,100,24883,0,"Farmer Torp"),
(25607,1,1,"Great job!",12,100,24884,0,"Farmer Torp"),
(25596,0,0,"%s is cured!",16,100,24885,0,"Infected Kodo Beast");
