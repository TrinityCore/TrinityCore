/*
-- Highland Thrasher
DELETE FROM `smart_scripts` WHERE `entryorguid`=2560 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2560,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Thrasher - On Reset - Cast Thrash");

-- Mesa Buzzard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2579 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2579,0,0,0,0,0,100,0,4000,12000,10000,18000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mesa Buzzard - In Combat - Cast Fevered Fatigue");

-- Elder Mesa Buzzard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2580 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2580,0,0,0,0,0,100,0,4000,12000,10000,18000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Mesa Buzzard - In Combat - Cast Fevered Fatigue");

-- Plains Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2563 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2563,0,0,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Creeper - On Reset - Cast Poison Proc"),
(2563,0,1,0,0,0,100,0,5000,14000,16000,23000,11,4962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plains Creeper - In Combat - Cast Encasing Webs");

-- Giant Plains Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2565 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2565,0,0,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Giant Plains Creeper - On Reset - Cast Poison Proc"),
(2565,0,1,0,0,0,100,0,5000,14000,16000,23000,11,4962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Plains Creeper - In Combat - Cast Encasing Webs");

-- Boulderfist Ogre
DELETE FROM `smart_scripts` WHERE `entryorguid`=2562 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2562,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Ogre - On Aggro - Say Line 0"),
(2562,0,1,0,2,0,100,0,0,30,16000,22000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Ogre - Between 0-30% Health - Cast Fist of Stone");

-- Boulderfist Enforcer
DELETE FROM `smart_scripts` WHERE `entryorguid`=2564 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2564,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Enforcer - On Aggro - Say Line 0"),
(2564,0,1,0,2,0,100,0,0,30,16000,22000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Enforcer - Between 0-30% Health - Cast Fist of Stone"),
(2564,0,2,0,0,0,100,0,5000,11000,30000,35000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Enforcer - In Combat - Cast Demoralizing Shout");

-- Boulderfist Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=2566 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2566,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Brute - On Aggro - Say Line 0"),
(2566,0,2,0,2,0,100,0,0,30,16000,22000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Brute - Between 0-30% Health - Cast Fist of Stone");

-- Boulderfist Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2569 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2569,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Mauler - On Aggro - Say Line 0"),
(2569,0,1,0,0,0,100,0,6000,14000,16000,24000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Mauler - In Combat - Cast Fist of Stone");

-- Boulderfist Magus
DELETE FROM `smart_scripts` WHERE `entryorguid`=2567 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2567,0,3,0,9,0,100,0,0,8,15000,23000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - Within 0-8 Range - Cast Frost Nova");

-- Boulderfist Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=2570 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2570,0,2,0,0,0,100,0,8000,12000,41000,45000,11,6364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - In Combat - Cast Searing Totem");

-- Boulderfist Lord
DELETE FROM `smart_scripts` WHERE `entryorguid`=2571 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2571,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Lord - On Aggro - Say Line 0"),
(2571,0,1,0,4,0,100,0,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Lord - On Aggro - Cast Devotion Aura"),
(2571,0,2,0,0,0,100,0,6000,14000,16000,24000,11,4955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Lord - In Combat - Cast Fist of Stone");

DELETE FROM `creature_text` WHERE `CreatureID`=2571;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2571,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Boulderfist Lord"),
(2571,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Boulderfist Lord"),
(2571,0,2,"Ill crush you!",12,0,100,0,0,0,1927,0,"Boulderfist Lord");

-- Witherbark Troll
DELETE FROM `smart_scripts` WHERE `entryorguid`=2552 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2552,0,0,0,0,0,100,0,4000,12000,8000,16000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Troll - In Combat - Cast Wither Touch");

-- Witherbark Shadowcaster
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=2553 AND `source_type`=0 AND `id`=0;

-- Witherbark Axe Thrower
DELETE FROM `smart_scripts` WHERE `entryorguid`=2554 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2554,0,1,0,0,0,100,0,4000,12000,8000,16000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - In Combat - Cast Wither Touch");

-- Witherbark Headhunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=2556 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2556,0,0,0,0,0,100,0,6000,10000,18000,24000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Headhunter - In Combat - Cast Net"),
(2556,0,1,0,0,0,100,0,4000,12000,8000,16000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Headhunter - In Combat - Cast Wither Touch");

-- Witherbark Witch Doctor
DELETE FROM `smart_scripts` WHERE `entryorguid`=2555 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2555,0,0,0,0,0,100,0,5000,7000,19000,22000,11,8190,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Witch Doctor - In Combat - Cast Magma Totem"),
(2555,0,1,0,0,0,100,0,12000,14000,32000,35000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Witch Doctor - In Combat - Cast Healing Ward");

-- Witherbark Shadow Hunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=2557 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2557,0,0,0,0,0,100,0,2000,6000,19000,23000,11,992,0,0,0,0,0,5,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Shadow Word: Pain"),
(2557,0,1,0,0,0,100,0,4000,8000,28000,35000,11,7646,32,0,0,0,0,5,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Curse of Weakness"),
(2557,0,2,0,0,0,100,0,9000,14000,31000,36000,11,6726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Silence");

-- Witherbark Berserker
DELETE FROM `smart_scripts` WHERE `entryorguid`=2558 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2558,0,0,0,0,0,100,0,4000,12000,8000,16000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Berserker - In Combat - Cast Wither Touch");

-- Dabyrie Laborer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2582;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2582 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2582,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dabyrie Laborer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Fardel Dabyrie
DELETE FROM `smart_scripts` WHERE `entryorguid`=4479 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4479,0,0,0,25,0,100,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fardel Dabyrie - On Reset - Cast Thrash");

-- Drywhisker Digger
DELETE FROM `smart_scripts` WHERE `entryorguid`=2574 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2574,0,0,0,0,0,100,0,1000,3000,180000,180000,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Digger - In Combat - Cast Defensive Stance");

-- Drywhisker Surveyor
DELETE FROM `smart_scripts` WHERE `entryorguid`=2573 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2573,0,2,0,9,0,100,0,0,8,15000,22000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - Within 0-8 Range - Cast Frost Nova");

-- Thundering Exile
DELETE FROM `smart_scripts` WHERE `entryorguid`=2762 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2762,0,0,0,0,0,100,0,0,0,3300,6600,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thundering Exile - In Combat - Cast Lightning Bolt"),
(2762,0,1,0,0,0,100,0,4000,8000,16000,24000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thundering Exile - In Combat - Cast Shock"),
(2762,0,2,0,8,0,100,512,4132,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - On Spellhit - Despawn");

-- Rumbling Exile
DELETE FROM `smart_scripts` WHERE `entryorguid`=2592 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2592,0,0,0,0,0,100,0,3000,12000,12000,21000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbling Exile - In Combat - Cast Ground Tremor");

-- Cresting Exile
DELETE FROM `smart_scripts` WHERE `entryorguid`=2761 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2761,0,1,0,0,0,100,0,4000,9000,16000,22000,11,865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cresting Exile - In Combat - Cast Frost Nova");

-- Syndicate Thief
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24477;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24477 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24477,0,0,0,67,0,100,0,4000,6000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - On Behind Target - Cast Backstab"),
(24477,0,1,0,0,0,100,0,5000,9000,18000,24000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - In Combat - Cast Disarm"),
(24477,0,2,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Thief - On Reset - Cast Poison Proc"),
(24477,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Thief - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Prowler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2588 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2588,0,2,0,0,0,100,0,4000,10000,16000,22000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Prowler - In Combat - Cast Sinister Strike"),
(2588,0,3,0,0,0,100,0,8000,14000,22000,28000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Prowler - In Combat - Cast Disarm");

-- Otto
DELETE FROM `smart_scripts` WHERE `entryorguid`=2599 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2599,0,0,0,0,0,100,0,9000,15000,12000,20000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Otto - In Combat - Cast Backhand"),
(2599,0,1,0,0,0,100,0,6000,11000,14000,19000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Otto - In Combat - Cast Pummel"),
(2599,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Otto - Between 0-15% Health - Flee For Assist");

-- Lord Falconcrest
DELETE FROM `smart_scripts` WHERE `entryorguid`=2597 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=259700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2597,0,0,0,1,0,100,0,5000,15000,150000,180000,80,259700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Falconcrest - Out of Combat - Run Script"),
(2597,0,1,0,0,0,100,0,2000,5000,6000,9000,11,32064,32,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Falconcrest - In Combat - Cast Battle Shout"),
(2597,0,2,0,0,0,100,0,5000,10000,16000,26000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Falconcrest - In Combat - Cast Disarm"),
(259700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Falconcrest - On Script - Say Line 0"),
(259700,9,1,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,19,2599,0,0,0,0,0,0,"Lord Falconcrest - On Script - Say Line 0 (Otto)");

-- Stromgarde Troll Hunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=2583 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2583,0,0,0,0,0,100,0,2000,5000,19000,23000,11,2767,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stromgarde Troll Hunter - In Combat - Cast Shadow Word: Pain");

-- Feeboz
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=4063 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4063 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4063,0,3,0,1,0,100,0,5000,15000,65000,75000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - Out of Combat - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=4063 AND `GroupID`=0 AND `ID`>2;
DELETE FROM `creature_text` WHERE `CreatureID`=4063 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4063,0,3,"Arent you a little short for your kind?",12,0,100,0,0,0,809,0,"Feeboz"),
(4063,0,4,"My life means nothing!  Our sacred task is all!",12,0,100,0,0,0,810,0,"Feeboz"),
(4063,0,5,"If you mean to free Myzrael, you will be sorry!",12,0,100,0,0,0,811,0,"Feeboz"),
(4063,0,6,"Stand firm, brothers.  And dont worry!  Size is on our side!",12,0,100,0,0,0,812,0,"Feeboz"),
(4063,0,7,"Take that!  The Drywhiskers will prevail!",12,0,100,0,0,0,814,0,"Feeboz"),
(4063,1,0,"May I bask in your shadow forever!",12,0,100,0,0,0,799,0,"Feeboz"),
(4063,1,1,"Master, your wisdom is matched only by your hugeness!",12,0,100,0,0,0,800,0,"Feeboz"),
(4063,1,2,"If I had a copper for each of your great deeds, Id be a rich kobold!",12,0,100,0,0,0,801,0,"Feeboz"),
(4063,1,3,"You will keep us safe from the evil mistress, yes!",12,0,100,0,0,0,802,0,"Feeboz"),
(4063,1,4,"Oh, praise!  Your vigilance keeps Myzrael deep in the earth!",12,0,100,0,0,0,803,0,"Feeboz"),
(4063,1,5,"My only wish is to serve you, great one, until I die by your foot!",12,0,100,0,0,0,804,0,"Feeboz"),
(4063,1,6,"Your strength is of the mountain.  Your grace is of the winds!",12,0,100,0,0,0,805,0,"Feeboz"),
(4063,1,7,"My feet hurt...",12,0,100,0,0,0,806,0,"Feeboz");

-- Znort
DELETE FROM `smart_scripts` WHERE `entryorguid`=2765 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2765,0,1,0,0,0,100,0,5000,7000,7000,10000,11,845,0,0,0,0,0,2,0,0,0,0,0,0,0,"Znort - In Combat - Cast Cleave"),
(2765,0,3,0,1,0,100,0,25000,35000,65000,75000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Znort - Out of Combat - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2765 AND `GroupID`=0 AND `ID`>2;
DELETE FROM `creature_text` WHERE `CreatureID`=2765 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2765,0,3,"Arent you a little short for your kind?",12,0,100,0,0,0,809,0,"Znort"),
(2765,0,4,"My life means nothing!  Our sacred task is all!",12,0,100,0,0,0,810,0,"Znort"),
(2765,0,5,"If you mean to free Myzrael, you will be sorry!",12,0,100,0,0,0,811,0,"Znort"),
(2765,0,6,"Die!  You will not free Myzrael!",12,0,100,0,0,0,807,0,"Znort"),
(2765,0,7,"Take that!  The Drywhiskers will prevail!",12,0,100,0,0,0,814,0,"Znort"),
(2765,1,0,"May I bask in your shadow forever!",12,0,100,0,0,0,799,0,"Znort"),
(2765,1,1,"Master, your wisdom is matched only by your hugeness!",12,0,100,0,0,0,800,0,"Znort"),
(2765,1,2,"If I had a copper for each of your great deeds, Id be a rich kobold!",12,0,100,0,0,0,801,0,"Znort"),
(2765,1,3,"You will keep us safe from the evil mistress, yes!",12,0,100,0,0,0,802,0,"Znort"),
(2765,1,4,"Oh, praise!  Your vigilance keeps Myzrael deep in the earth!",12,0,100,0,0,0,803,0,"Znort"),
(2765,1,5,"My only wish is to serve you, great one, until I die by your foot!",12,0,100,0,0,0,804,0,"Znort"),
(2765,1,6,"Your strength is of the mountain.  Your grace is of the winds!",12,0,100,0,0,0,805,0,"Znort"),
(2765,1,7,"My feet hurt...",12,0,100,0,0,0,806,0,"Znort");

-- Sleeby
DELETE FROM `smart_scripts` WHERE `entryorguid`=2764 AND `source_type`=0 AND `id` IN (4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2764,0,4,0,1,0,100,0,45000,55000,65000,75000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sleeby - Out of Combat - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2764 AND `GroupID`=0 AND `ID`>1;
DELETE FROM `creature_text` WHERE `CreatureID`=2764 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2764,0,2,"The Great One will smash you!",12,0,100,0,0,0,808,0,"Sleeby"),
(2764,0,3,"Arent you a little short for your kind?",12,0,100,0,0,0,809,0,"Sleeby"),
(2764,0,4,"My life means nothing!  Our sacred task is all!",12,0,100,0,0,0,810,0,"Sleeby"),
(2764,0,5,"If you mean to free Myzrael, you will be sorry!",12,0,100,0,0,0,811,0,"Sleeby"),
(2764,0,6,"Die!  You will not free Myzrael!",12,0,100,0,0,0,807,0,"Sleeby"),
(2764,0,7,"No!  Leave us!  We must not fail our task!",12,0,100,0,0,0,815,0,"Sleeby"),
(2764,1,0,"May I bask in your shadow forever!",12,0,100,0,0,0,799,0,"Sleeby"),
(2764,1,1,"Master, your wisdom is matched only by your hugeness!",12,0,100,0,0,0,800,0,"Sleeby"),
(2764,1,2,"If I had a copper for each of your great deeds, Id be a rich kobold!",12,0,100,0,0,0,801,0,"Sleeby"),
(2764,1,3,"You will keep us safe from the evil mistress, yes!",12,0,100,0,0,0,802,0,"Sleeby"),
(2764,1,4,"Oh, praise!  Your vigilance keeps Myzrael deep in the earth!",12,0,100,0,0,0,803,0,"Sleeby"),
(2764,1,5,"My only wish is to serve you, great one, until I die by your foot!",12,0,100,0,0,0,804,0,"Sleeby"),
(2764,1,6,"Your strength is of the mountain.  Your grace is of the winds!",12,0,100,0,0,0,805,0,"Sleeby"),
(2764,1,7,"My feet hurt...",12,0,100,0,0,0,806,0,"Sleeby");

-- Thenan
DELETE FROM `smart_scripts` WHERE `entryorguid`=2763 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2763,0,1,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Thenan - On Respawn - Start Attacking");

-- Darbel Montrose
DELETE FROM `smart_scripts` WHERE `entryorguid`=2598 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2598,0,2,0,0,0,100,0,4000,7000,18000,21000,11,12741,32,0,0,0,0,2,0,0,0,0,0,0,0,"Darbel Montrose - In Combat - Cast Curse of Weakness");

-- Molok the Crusher
DELETE FROM `smart_scripts` WHERE `entryorguid`=2604 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2604,0,0,0,0,0,100,0,7000,11000,9000,13000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Molok the Crusher - In Combat - Cast Backhand");

-- Zalas Witherbark
DELETE FROM `smart_scripts` WHERE `entryorguid`=2605 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2605,0,0,0,0,0,100,0,3000,5000,23000,27000,11,512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Chains of Ice"),
(2605,0,1,0,0,0,100,0,3000,5000,15000,18000,11,851,2,0,0,0,0,6,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Polymorph: Sheep"),
(2605,0,2,0,0,0,100,0,5000,8000,8000,15000,11,9081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Shadowbolt Volley"),
(2605,0,3,0,0,0,100,0,2000,3000,13000,15000,11,4974,32,0,0,0,0,5,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Wither Touch");

-- Ruul Onestone
DELETE FROM `smart_scripts` WHERE `entryorguid`=2602 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2602,0,0,0,0,0,100,0,4000,6000,12000,14000,11,6219,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruul Onestone - In Combat - Cast Rain of Fire"),
(2602,0,1,0,0,0,100,0,1000,1000,31000,33000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ruul Onestone - In Combat - Cast Bloodlust"),
(2602,0,2,0,0,0,100,0,2000,3000,3000,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ruul Onestone - In Combat - Cast Lightning Bolt");

-- Fix movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid`=12046;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid`=14538;
*/
