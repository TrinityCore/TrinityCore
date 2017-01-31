SET @ADARRAH := 24405;
SET @WARMONGER := 26811;
SET @SOOTHSAYER := 26812;
SET @HARRISON := 26814;
SET @TECAHUNA := 26865;
SET @MUMMY_BUNNY := 26867;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@TECAHUNA;
DELETE FROM `creature_equip_template` WHERE `entry`=@HARRISON;

UPDATE `gameobject` SET `state`=1 WHERE `id`=188465;
UPDATE `gameobject` SET `state`=0 WHERE `id`=188480;

UPDATE `creature` SET `equipment_id`=0 WHERE `id`=@HARRISON;
DELETE FROM `creature` WHERE `guid`=86444;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(86444, @ADARRAH, 571, 1, 1, 4912.768, -4797.917, 32.68771, 3.595378, 300, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (@WARMONGER,@SOOTHSAYER,@MUMMY_BUNNY);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(@WARMONGER,'17327'),
(@SOOTHSAYER,'17327'),
(@MUMMY_BUNNY,'48150');

UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=@ADARRAH;
UPDATE `creature_template` SET `dmg_multiplier`=5 WHERE `entry`=@HARRISON;
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `unit_flags`=768, `dmg_multiplier`=6, `AIName`='SmartAI' WHERE `entry`=@TECAHUNA;
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry`=26871;
UPDATE `creature_template` SET `unit_flags`=33554688, `flags_extra`=128 WHERE `entry`=@MUMMY_BUNNY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ADARRAH,@HARRISON,@MUMMY_BUNNY);
UPDATE `gameobject_template` SET `flags`=2 WHERE `entry` IN (188472,188487);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ADARRAH,@HARRISON,@TECAHUNA,@MUMMY_BUNNY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WARMONGER AND `source_type`=0 AND `id`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SOOTHSAYER AND `source_type`=0 AND `id` BETWEEN 9 AND 18;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ADARRAH*100,@HARRISON*100,@HARRISON*100+1,@HARRISON*100+2,@HARRISON*100+3,@HARRISON*100+4,@TECAHUNA*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ADARRAH,0,0,0,38,0,100,0,0,1,0,0,80,@ADARRAH*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Adarrah - On data set 0 1 - Run script'),
(@ADARRAH,0,1,0,40,0,100,0,6,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Adarrah - On WP reached - Despawn'),

(@WARMONGER,0,9,0,0,0,100,0,5000,7000,8000,12000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On update IC - Spellcast Sunder Armor'),
(@SOOTHSAYER,0,9,10,4,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On aggro - Set event phase 2'),
(@SOOTHSAYER,0,10,0,61,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On aggro - Stop combat movement'),
(@SOOTHSAYER,0,11,0,0,2,100,0,0,0,3400,4800,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On update IC (phase 2) - Spellcast Holy Smite'),
(@SOOTHSAYER,0,12,13,9,2,100,0,35,80,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On target range 35y and more - Set event phase 3'),
(@SOOTHSAYER,0,13,0,61,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On target range 40y and more - Start combat movement'),
(@SOOTHSAYER,0,14,10,9,0,100,0,5,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On target range below 15y - Set event phase 2'),
(@SOOTHSAYER,0,15,13,9,0,100,0,0,5,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On target range below 15y - Set event phase 2'),
(@SOOTHSAYER,0,16,13,3,0,100,0,0,7,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On mana below 7% - Set event phase 4'),
(@SOOTHSAYER,0,17,13,3,8,100,0,15,100,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On mana over 15% (phase 4) - Set event phase 2'),
(@SOOTHSAYER,0,18,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On evade - Set event phase 0'),

(@HARRISON,0,0,1,11,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On spawn - Reset faction'),
(@HARRISON,0,1,2,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On spawn - Set invincibility 1HP'),
(@HARRISON,0,2,0,61,0,100,0,0,0,0,0,71,0,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On spawn - Remove equip'),
(@HARRISON,0,3,4,19,0,100,0,12082,0,0,0,80,@HARRISON*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On quest accept - Run script 0'),
(@HARRISON,0,4,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Harrison Jones - On quest accept - Store target list'),
(@HARRISON,0,5,6,40,0,100,0,7,@HARRISON,0,0,54,8500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 7 reached - Pause WP movement 8.5 seconds'),
(@HARRISON,0,6,0,61,0,100,0,0,0,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 7 reached - Say line'),
(@HARRISON,0,7,0,52,0,100,0,1,@HARRISON,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On text over - Say line'),
(@HARRISON,0,8,9,40,0,100,0,9,@HARRISON,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 9 reached - Pause WP movement 12 seconds'),
(@HARRISON,0,9,0,61,0,100,0,0,0,0,0,80,@HARRISON*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 9 reached - Run script 1'),
(@HARRISON,0,10,11,40,0,100,0,11,@HARRISON,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 11 reached - Pause WP movement 18 seconds'),
(@HARRISON,0,11,0,61,0,100,0,0,0,0,0,80,@HARRISON*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 11 reached - Run script 2'),
(@HARRISON,0,12,13,40,0,100,0,13,@HARRISON,0,0,54,4600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 13 reached - Pause WP movement 4.5 seconds'),
(@HARRISON,0,13,0,61,0,100,0,0,0,0,0,1,4,4600,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 13 reached - Say line'),
(@HARRISON,0,14,0,52,0,100,0,4,@HARRISON,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On text over - Say line'),
(@HARRISON,0,15,0,40,0,100,0,16,@HARRISON,0,0,9,0,0,0,0,0,0,20,188480,50,0,0,0,0,0, 'Harrison Jones - On WP 16 reached - Activate Grizzly Hills - FireDoor01'),
(@HARRISON,0,16,17,40,0,100,0,17,@HARRISON,0,0,54,500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 17 reached - Say line'),
(@HARRISON,0,17,0,61,0,100,0,0,0,0,0,12,@TECAHUNA,2,300000,0,0,0,8,0,0,0,4906.587,-4818.92,32.63929,2.530727, 'Harrison Jones - On WP 17 reached - Summon Tecahuna'),
(@HARRISON,0,18,0,40,0,100,0,18,@HARRISON,0,0,80,@HARRISON*100+3,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 18 reached - Run script'),
(@HARRISON,0,19,20,2,0,100,1,0,0.0014,0,0,32,0,0,0,0,0,0,20,188480,50,0,0,0,0,0, 'Harrison Jones - On health below 0.0014% - Activate Grizzly Hills - FireDoor01'),
(@HARRISON,0,20,21,61,0,100,0,0,0,0,0,6,12082,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Harrison Jones - On health below 0.0014% - Fail quest'),
(@HARRISON,0,21,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On health below 0.0014% - Die'),
(@HARRISON,0,22,23,56,0,100,0,17,@HARRISON,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 17 resumed - Say line'),
(@HARRISON,0,23,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 17 resumed - Set run'),
(@HARRISON,0,24,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On data set 0 1 - Set event phase 1'),
(@HARRISON,0,25,0,7,1,100,0,0,0,0,0,80,@HARRISON*100+4,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On homeposition (phase 1) - Run script'),
(@HARRISON,0,26,27,40,0,100,0,21,@HARRISON*10,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 21 reached - Pause WP movement 6 seconds'),
(@HARRISON,0,27,0,61,0,100,0,0,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 21 reached - Say line'),
(@HARRISON,0,28,29,56,0,100,0,21,@HARRISON*10,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 21 resumed - Set run'),
(@HARRISON,0,29,0,61,0,100,0,0,0,0,0,15,12082,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Harrison Jones - On WP 21 resumed - Quest credit'),
(@HARRISON,0,30,0,40,0,100,0,25,@HARRISON*10,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On WP 25 reached - Despawn'),
(@HARRISON,0,31,0,4,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones - On aggro - Set reaction hostile'),

(@TECAHUNA,0,0,1,54,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Just summoned - Set invincibility 1HP'),
(@TECAHUNA,0,1,2,61,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Just summoned - Root'),
(@TECAHUNA,0,2,3,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Just summoned - Set event phase 1'),
(@TECAHUNA,0,3,0,61,0,100,0,0,0,0,0,80,@TECAHUNA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Just summoned - Run script'),
(@TECAHUNA,0,4,5,0,0,100,0,20000,25000,20000,30000,11,47601,0,0,0,0,0,19,@MUMMY_BUNNY,60,0,0,0,0,0, 'Tecahuna - On update IC - Spellcast Cosmetic - Tecahuna Spirit Beam'),
(@TECAHUNA,0,5,0,61,0,100,0,0,0,0,0,11,47601,0,0,0,0,0,19,@MUMMY_BUNNY,60,0,0,0,0,0, 'Tecahuna - On update IC - Spellcast Cosmetic - Tecahuna Spirit Beam'),
(@TECAHUNA,0,6,7,2,0,100,1,0,0.002,0,0,9,0,0,0,0,0,0,20,188480,50,0,0,0,0,0, 'Tecahuna - On health below 0.002% - Activate Grizzly Hills - FireDoor01'),
(@TECAHUNA,0,7,8,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@HARRISON,50,0,0,0,0,0, 'Tecahuna - On health below 0.002% - Set data 0 1 Harrison Jones'),
(@TECAHUNA,0,8,9,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,@MUMMY_BUNNY,50,0,0,0,0,0, 'Tecahuna - On health below 0.002% - Set data 0 1 Mummy Effect Bunny'),
(@TECAHUNA,0,9,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On health below 0.002% - Die'),
(@TECAHUNA,0,10,0,7,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On evade - Set event phase 1'),
(@TECAHUNA,0,11,0,0,3,100,0,0,0,8000,9000,11,47629,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Tecahuna - On update IC (phase 1+2) - Spellcast Tecahuna Venom Spit'),
(@TECAHUNA,0,12,14,9,1,100,0,40,80,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On target range more than 40y (phase 1) - Unroot'),
(@TECAHUNA,0,13,14,9,0,100,0,0,5,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On target range below 5y - Unroot'),
(@TECAHUNA,0,14,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Linked - Set event phase 2'),
(@TECAHUNA,0,15,16,3,0,100,0,0,7,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On mana below 7% (phase 1) - Unroot'),
(@TECAHUNA,0,16,0,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Linked - Set event phase 3'),
(@TECAHUNA,0,17,19,9,0,100,0,5,15,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On target range below 15y - Root'),
(@TECAHUNA,0,18,19,3,4,100,0,15,100,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - On mana 15% (phase 3) - Unroot'),
(@TECAHUNA,0,19,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna - Linked - Set event phase 1'),

(@MUMMY_BUNNY,0,0,0,8,0,100,0,47601,0,0,0,11,47602,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mummy Effect Bunny - On spellhit Cosmetic - Tecahuna Spirit Beam - Spellcast Summon Ancient Drakkari King'),
(@MUMMY_BUNNY,0,1,0,38,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mummy Effect Bunny - On spellhit Cosmetic - On data set 0 1 - Despawn'),

(@ADARRAH*100,9,0,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Adarrah script - Play emote'),
(@ADARRAH*100,9,1,0,0,0,100,0,1900,1900,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Adarrah script - Say line'),
(@ADARRAH*100,9,2,0,0,0,100,0,1000,1000,0,0,53,1,@ADARRAH,0,0,0,0,1,0,0,0,0,0,0,0, 'Adarrah script - Start WP movement'),

(@HARRISON*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 0 - Say line'),
(@HARRISON*100,9,1,0,0,0,100,0,500,500,0,0,9,0,0,0,0,0,0,20,188465,5,0,0,0,0,0, 'Harrison Jones script 0 - Activate Harrison''s Cage'),
(@HARRISON*100,9,2,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 0 - Set faction'),
(@HARRISON*100,9,3,0,0,0,100,0,0,0,0,0,71,0,2,0,2081,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 0 - Equip'),
(@HARRISON*100,9,4,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 0 - Remove npcflag gossip'),
(@HARRISON*100,9,5,0,0,0,100,0,2500,2500,0,0,53,0,@HARRISON,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 0 - Start WP movement'),
(@HARRISON*100,9,6,0,0,0,100,0,7000,7000,0,0,9,0,0,0,0,0,0,20,188465,50,0,0,0,0,0, 'Harrison Jones script 0 - Activate Harrison''s Cage'),

(@HARRISON*100+1,9,0,0,0,0,100,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 1 - Play emote'),
(@HARRISON*100+1,9,1,0,0,0,100,0,2500,2500,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 1 - Stop emote'),
(@HARRISON*100+1,9,2,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 1 - Say line'),
(@HARRISON*100+1,9,3,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,188487,5,0,0,0,0,0, 'Harrison Jones script 1 - Activate Adarra''s Cage'),
(@HARRISON*100+1,9,4,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@ADARRAH,5,0,0,0,0,0, 'Harrison Jones script 1 - Set data 0 1 Adarra''s Cage'),
(@HARRISON*100+1,9,5,0,0,0,100,0,10000,10000,0,0,9,0,0,0,0,0,0,20,188487,5,0,0,0,0,0, 'Harrison Jones script 1 - Activate Adarra''s Cage'),

(@HARRISON*100+2,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.143559, 'Harrison Jones script 2 - Set orientation'),
(@HARRISON*100+2,9,1,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Set unit_field_bytes1 (kneel)'),
(@HARRISON*100+2,9,2,0,0,0,100,0,2400,2400,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.677482, 'Harrison Jones script 2 - Set orientation'),
(@HARRISON*100+2,9,3,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Remove unit_field_bytes1 (kneel)'),
(@HARRISON*100+2,9,4,0,0,0,100,0,0,0,0,0,71,0,1,32246,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Equip'),
(@HARRISON*100+2,9,5,0,0,0,100,0,2500,2500,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play emote'),
(@HARRISON*100+2,9,6,0,0,0,100,0,0,0,0,0,4,12827,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play sound'),
(@HARRISON*100+2,9,7,0,0,0,100,0,0,0,0,0,11,47533,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Spellcast Camera Shake'),
(@HARRISON*100+2,9,8,0,0,0,100,0,2500,2500,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play emote'),
(@HARRISON*100+2,9,9,0,0,0,100,0,0,0,0,0,4,12827,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play sound'),
(@HARRISON*100+2,9,10,0,0,0,100,0,0,0,0,0,11,47533,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Spellcast Camera Shake'),
(@HARRISON*100+2,9,11,0,0,0,100,0,2500,2500,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play emote'),
(@HARRISON*100+2,9,12,0,0,0,100,0,0,0,0,0,4,12827,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Play sound'),
(@HARRISON*100+2,9,13,0,0,0,100,0,0,0,0,0,11,47533,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 2 - Spellcast Camera Shake'),
(@HARRISON*100+2,9,14,0,0,0,100,0,2000,2000,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4902.228,-4827.556,32.61251,2.443461, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,15,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4876.608,-4805.581,32.58254,6.178465, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,16,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4877.39,-4815.752,32.58345,0.1570796, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,17,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4883.104,-4823.975,32.58836,0.8726646, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,18,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4892.313,-4828.58,32.59582,1.570796, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,19,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4908.681,-4794.352,32.67061,3.979351, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,20,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4899.539,-4789.862,32.59812,4.764749, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,21,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4889.959,-4790.646,32.59848,5.201081, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,22,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4914.76,-4813.242,32.58661,3.01942, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),
(@HARRISON*100+2,9,23,0,0,0,100,0,0,0,0,0,12,@MUMMY_BUNNY,2,300000,0,0,0,8,0,0,0,4914.13,-4802.799,32.66964,3.420845, 'Harrison Jones script 2 - Summon Mummy Effect Bunny'),

(@HARRISON*100+3,9,0,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 3 - Say line'),
(@HARRISON*100+3,9,1,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 3 - Set homeposition'),
(@HARRISON*100+3,9,2,0,0,0,100,0,7200,7200,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 3 - Say line'),
(@HARRISON*100+3,9,3,0,0,0,100,0,6000,6000,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 3 - Start attack'),

(@HARRISON*100+4,9,0,0,0,0,100,0,1000,1000,0,0,53,1,@HARRISON*10,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 4 - Start WP movement'),
(@HARRISON*100+4,9,1,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harrison Jones script 4 - Set event phase 0'),

(@TECAHUNA*100,9,0,0,0,0,100,0,15300,15300,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tecahuna script - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@TECAHUNA*100,9,1,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@HARRISON,30,0,0,0,0,0, 'Tecahuna script - Start attack');

DELETE FROM `creature_text` WHERE `entry` IN (@ADARRAH,@HARRISON);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ADARRAH,0,0,'Thank you!',12,0,100,17,0,0,'Adarrah'),
(@HARRISON,0,0,'Alright, kid. Stay behind me and you''ll be fine.',12,0,100,60,0,0,'Harrison Jones'),
(@HARRISON,1,0,'Their ceremonial chamber, where I was to be sacrificed...',12,0,100,396,0,0,'Harrison Jones'),
(@HARRISON,2,0,'Time to put an end to all this!',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,3,0,'You''re free to go, miss.',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,4,0,'Odd. That usually does it.',12,0,100,396,0,0,'Harrison Jones'),
(@HARRISON,5,0,'Just as well, I''ve had enough of this place.',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,6,0,'What''s this?',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,7,0,'Aww, not a snake!',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,8,0,'Listen, kid. I can handle this thing. You just watch my back!',12,0,100,0,0,0,'Harrison Jones'),
(@HARRISON,9,0,'See ya ''round, kid!',12,0,100,0,0,0,'Harrison Jones');

DELETE FROM `waypoints` WHERE `entry` IN (@ADARRAH,@HARRISON,@HARRISON*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ADARRAH, 1,4902.543, -4798.52, 31.8586,'Adarrah'),
(@ADARRAH, 2,4893.144, -4795.715, 32.28691,'Adarrah'),
(@ADARRAH, 3,4887.894, -4793.465, 32.53691,'Adarrah'),
(@ADARRAH, 4,4878.785, -4793.664, 32.5359,'Adarrah'),
(@ADARRAH, 5,4863.294, -4785.226, 32.60138,'Adarrah'),
(@ADARRAH, 6,4839.031, -4774.794, 32.58206,'Adarrah'),

(@HARRISON, 1,4904.213, -4758.285, 27.27473,'Harrison Jones'),
(@HARRISON, 2,4896.463, -4755.535, 27.27473,'Harrison Jones'),
(@HARRISON, 3,4893.663, -4754.357, 27.23306,'Harrison Jones'),
(@HARRISON, 4,4886.543, -4762.921, 27.57825,'Harrison Jones'),
(@HARRISON, 5,4880.44, -4770.725, 30.70074,'Harrison Jones'),
(@HARRISON, 6,4876.696, -4790.863, 32.32729,'Harrison Jones'),
(@HARRISON, 7,4878.253, -4793.774, 32.53423,'Harrison Jones'),
(@HARRISON, 8,4882.602, -4795.872, 32.30199,'Harrison Jones'),
(@HARRISON, 9,4909.493, -4798.01, 32.54974,'Harrison Jones'),
(@HARRISON,10,4907.815, -4804.193, 31.78963,'Harrison Jones'),
(@HARRISON,11,4914.756, -4823.07, 32.66446,'Harrison Jones'),
(@HARRISON,12,4913.032, -4822.288, 32.63041,'Harrison Jones'),
(@HARRISON,13,4909.308, -4821.506, 32.59636,'Harrison Jones'),
(@HARRISON,14,4893.949, -4813.76, 31.7795,'Harrison Jones'),
(@HARRISON,15,4887.193, -4808.022, 32.0295,'Harrison Jones'),
(@HARRISON,16,4886.381, -4806.938, 32.29276,'Harrison Jones'),
(@HARRISON,17,4883.646, -4798.885, 32.57867,'Harrison Jones'),
(@HARRISON,18,4899.398, -4806.076, 32.02951,'Harrison Jones'),

(@HARRISON*10, 1,4893.088, -4802.876, 32.0295,'Harrison Jones'),
(@HARRISON*10, 2,4881.008, -4795.617, 32.50804,'Harrison Jones'),
(@HARRISON*10, 3,4857.754, -4778.792, 32.6265,'Harrison Jones'),
(@HARRISON*10, 4,4837.625, -4774.61, 32.5914,'Harrison Jones'),
(@HARRISON*10, 5,4817.824, -4790.486, 25.46436,'Harrison Jones'),
(@HARRISON*10, 6,4826.314, -4827.564, 25.48946,'Harrison Jones'),
(@HARRISON*10, 7,4826.336, -4841.321, 25.48413,'Harrison Jones'),
(@HARRISON*10, 8,4809.195, -4851.308, 25.52775,'Harrison Jones'),
(@HARRISON*10, 9,4781.125, -4849.693, 25.44121,'Harrison Jones'),
(@HARRISON*10,10,4761.496, -4853.984, 25.00991,'Harrison Jones'),
(@HARRISON*10,11,4719.89, -4857.747, 26.13666,'Harrison Jones'),
(@HARRISON*10,12,4693.853, -4858.84, 32.49986,'Harrison Jones'),
(@HARRISON*10,13,4680.416, -4861.247, 35.56741,'Harrison Jones'),
(@HARRISON*10,14,4673.966, -4864.334, 35.56741,'Harrison Jones'),
(@HARRISON*10,15,4662.382, -4882.535, 35.58759,'Harrison Jones'),
(@HARRISON*10,16,4658.195, -4895.924, 36.19548,'Harrison Jones'),
(@HARRISON*10,17,4656.812, -4915.515, 43.78271,'Harrison Jones'),
(@HARRISON*10,18,4659.832, -4928.781, 47.82988,'Harrison Jones'),
(@HARRISON*10,19,4664.121, -4942.443, 48.00279,'Harrison Jones'),
(@HARRISON*10,20,4666.967, -4951.508, 48.10587,'Harrison Jones'),
(@HARRISON*10,21,4675.692, -4970.227, 47.64427,'Harrison Jones'),
(@HARRISON*10,22,4681.637, -4973.975, 46.74993,'Harrison Jones'),
(@HARRISON*10,23,4707.978, -4997.285, 40.70398,'Harrison Jones'),
(@HARRISON*10,24,4712.889, -5002.176, 39.12014,'Harrison Jones'),
(@HARRISON*10,25,4739.859, -5031.481, 31.18226,'Harrison Jones');
