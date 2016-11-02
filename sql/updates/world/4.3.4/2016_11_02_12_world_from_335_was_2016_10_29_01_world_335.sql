-- 
/*
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (2181, 2182,12347, 2236, 2235, 15184);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2181, 2182, 12347, 2236, 2235, 15184) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2181, 0, 0, 0, 0, 0, 100, 0, 4000, 7000, 8000, 13000, 11, 5164, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormscale Myrmidon - Update In Combat - Cast \'Knockdown\''),
(2182,0,0,0,0,0,100,0,1000,2000,3000,3400,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,'Stormscale Sorceress - ic -Cast bolt'),
(2182,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormscale Sorceress - Flee at 15% HP'),
(2182,0,2,0,23,0,100,0,12544,0,1000,1000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,'Stormscale Sorceress - Cast Frost Armor on Spawn'),
(12347, 0, 0, 0, 2, 0, 100, 1, 0, 20, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Reef Crawler - On Low (20%) Health - Cast \'Enraged\''),
(2236,0,0,0,4,0,100,1,0,0,0,0,75,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raging Reef Crawler - Cast Thrash - on Aggro'),
(2235,0,0,0,0,0,100,0,3000,5000,5000,8000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,'Reef Crawler- Update In Combat - Cast \'Muscle Tear\''),
(15184, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 18950, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Hold Infantry - On Reset - Cast Invisibility and Stealth Detection'),
(15184, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Hold Infantry - On Aggro - Say Line 0'),
(15184, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 6000, 12000, 11, 30223, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Hold Infantry - In Combat - Cast Cleave'),
(15184, 0, 3, 0, 13, 0, 100, 0, 10000, 10000, 0, 0, 11, 27620, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Hold Infantry - Victim Casting - Cast Snap Kick');

DELETE FROM `creature_text` WHERE `entry`=15184;
INSERT INTO `creature_text` VALUES (15184, 0, 0, 'Taste blade, mongrel!', 12, 0, 100, 0, 0, 0, 10950, 0, 'SAY_GUARD_SIL_AGGRO1'),
(15184, 0, 1, 'Please tell me that you didn''t just do what I think you just did. Please tell me that I''m not going to have to hurt you...', 12, 0, 100, 0, 0, 0, 10951, 0, 'SAY_GUARD_SIL_AGGRO2'),
(15184, 0, 2, 'As if we don''t have enough problems, you go and create more!', 12, 0, 100, 0, 0, 0, 10953, 0, 'SAY_GUARD_SIL_AGGRO3'),
(15184, 0, 3, 'You dare spill blood on neutral ground? OUT! OUT, I SAY!', 12, 0, 100, 0, 0, 0, 10948, 0, 'Cenarion Hold Infantry - On Aggro'),
(15184, 0, 4, 'We don''t take kindly to miscreants, $r.', 12, 0, 100, 0, 0, 0, 10949, 0, 'Cenarion Hold Infantry - On Aggro'),
(15184, 0, 5, 'Get a rope!', 12, 0, 100, 0, 0, 0, 10952, 0, 'Cenarion Hold Infantry - On Aggro'),
(15184, 0, 6, 'Believe me when I tell you this: You''re gonna wish you weren''t born, sissy!', 12, 0, 100, 0, 0, 0, 10954, 0, 'Cenarion Hold Infantry - On Aggro'),
(15184, 0, 7, 'Your actions shame us all, $c. I hurt inside as I beat you senseless.', 12, 0, 100, 0, 0, 0, 10955, 0, 'Cenarion Hold Infantry - On Aggro');
*/
