DELETE FROM `creature` WHERE `id`=27715;
UPDATE `creature_template` SET `faction_a`=14, `faction_h`=14, `AIName`='SmartAI' WHERE `entry` IN (27715, 27716, 27717, 27718);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27727, 27726);

DELETE FROM `creature_text` WHERE `entry` IN (27719, 27727, 27726);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(27719,0,0,"Ladies and gentlemen! Well... let's just say you don't want to miss this one!",14,0,100,0,0,0,'Grennix Shivwiggle - Quest Accepted'),
(27727,0,0,"You went behind my back. You neglected my orders. You will pay the price.",12,0,100,0,0,0,'Conqueror Krenna - Say 0'),
(27727,1,1,"Enough talk. By the time I'm though with you, not even the worgs will go near your corpse.",12,0,100,0,0,0,'Conqueror Krenna - Say 1'),
(27726,0,0,"I used good judgment when you showed non. I don't want to see you lead us into ruin, Krenna!",12,0,100,0,0,0,'Gorgonna - Say 0'),
(27726,1,1,"It doesn't have to end this way, you know?",12,0,100,0,0,0,'Gorgonna - Say 1'),
(27726,2,2,"We'll see about that",12,0,100,0,0,0,'Gorgonna - Say 2'),
(27726,3,3,"Why... why sister? Why did it have to come to this?",12,0,100,0,0,0,'Gorgonna - Say 3');

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27715,27716,27717,27718,27727,27719,27726);
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (27715,27716,27717,27718,27727,27719,27726); 4.x removed
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27715,27716,27717,27718,27727,27719,27726);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27715,0,0,0,9,0,100,0,8,25,17000,24000,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ironhide - Cast Charge'),
(27715,0,1,0,0,0,100,0,5000,7000,7000,9000,11,34298,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ironhide - Cast Maul'),
(27715,0,2,0,9,0,100,0,0,5,7000,11000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ironhide - Cast Swipe'),
(27715,0,3,0,7,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ironhide - Evade - Unseen'),
(27715,0,4,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ironhide - Evade - Despawn'),
(27715,0,5,0,6,0,100,0,0,0,0,0,15,12427,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ironhide - Death - Credit'),
(27715,0,6,0,6,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ironhide - Death - Unseen'),
(27715,0,7,0,7,0,100,0,0,0,0,0,6,12427,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ironhide - Evade - Quest Fail'),

-- Torgg Thundertotem 27716
(27716,0,0,0,0,0,100,0,1000,3000,6000,8000,11,16033,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Torgg Thundertotem - Cast Chain Lightning'),
(27716,0,1,0,0,0,100,0,10000,20000,5000,15000,11,15982,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Cast Healing Wave'),
(27716,0,2,0,0,0,100,0,0,0,21000,21000,11,31991,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Cast Corrupted Nova Totem'),
(27716,0,3,0,0,0,100,0,4000,4000,12000,12000,11,15501,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Cast Earth Shock'),
(27716,0,4,0,7,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Evade - Unseen'),
(27716,0,5,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Evade - Despawn'),
(27716,0,6,0,6,0,100,0,0,0,0,0,15,12428,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Torgg Thundertotem - Credit'),
(27716,0,7,0,6,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Torgg Thundertotem - Death - Unseen'),
(27716,0,8,0,7,0,100,0,0,0,0,0,6,12428,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Torgg Thundertotem - Evade - Quest Fail'),

-- Rustblood 27717
(27717,0,0,0,0,0,100,0,5000,7000,5000,7000,11,42746,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rustblood - Cast Cleave'),
(27717,0,1,0,9,0,100,0,0,5,22000,30000,11,49398,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rustblood - Cast Knockback'),
(27717,0,2,0,0,0,100,0,12000,15000,18000,21000,11,14102,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rustblood - Cast Head Smash'),
(27717,0,3,0,0,0,100,0,0,3000,12000,12000,11,61893,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rustblood - Cast Lightning Bolt'),
(27717,0,4,0,7,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rustblood - Evade - Unseen'),
(27717,0,5,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rustblood - Evade - Despawn'),
(27717,0,6,0,6,0,100,0,0,0,0,0,15,12429,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rustblood - Death - Credit'),
(27717,0,7,0,6,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rustblood  - Death - Unseen'),
(27717,0,8,0,7,0,100,0,0,0,0,0,6,12429,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rustblood - Evade - Quest Fail'),

-- Horgrenn Hellcleave 27718
(27718,0,0,0,9,0,100,0,0,10,21000,29000,11,16508,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Cast Intimidating Roar'),
(27718,0,1,0,0,0,100,0,3000,6000,8000,12000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Cast Sunder Armor'),
(27718,0,2,0,0,0,100,0,9000,12000,12000,16000,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Cast Mortal Strike'),
(27718,0,3,0,0,0,100,0,13000,15000,13000,18000,11,38618,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Cast Whirlwind'),
(27718,0,4,0,7,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Evade - Unseen'),
(27718,0,5,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Evade - Despawn'),
(27718,0,6,0,6,0,100,0,0,0,0,0,15,12430,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Death - Credit'),
(27718,0,7,0,6,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Death - Unseen'),
(27718,0,8,0,7,0,100,0,0,0,0,0,6,12430,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Horgrenn Hellcleave - Evade - Quest Fail'),

-- Conqueror Krenna 27727
(27727,0,0,0,9,0,100,0,0,5,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Conqueror Krenna - Cast Cleave'),
(27727,0,1,0,0,0,100,0,9000,12000,12000,17000,11,11430,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Conqueror Krenna - Cast Slam'),
(27727,0,2,0,13,0,100,0,14000,17000,14000,17000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Conqueror Krenna - Cast Pummel'),
(27727,0,3,0,13,0,100,0,3000,6000,6000,11000,11,34719,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Conqueror Krenna - Cast Fixate'),
(27727,0,4,0,54,0,100,0,0,0,0,0,12,27726,3,75000,0,0,0,8,0,0,0,3244.50,-2340.56,92.14,6.27, 'Conqueror Krenna - Summon Gorgonna'),
(27727,0,5,0,54,0,100,0,0,0,0,0,1,0,18000,0,0,0,0,1,0,0,0,0,0,0,0, 'Conqueror Krenna - Summoned - Say 0'),
(27727,0,6,0,52,0,100,0,0,27727,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0, 'Conqueror Krenna - Say 0 - Say 1'),
(27727,0,7,0,1,0,100,1,35000,35000,1,1,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Conqueror Krenna - OOC 35 Sec - Enemy'),
(27727,0,8,0,6,0,100,0,0,0,0,0,15,12431,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Conqueror Krenna - Death - Credit'),
(27727,0,9,0,6,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Conqueror Krenna - Death - Unseen'),
(27727,0,10,0,7,0,100,0,0,0,0,0,6,12431,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Conqueror Krenna - Evade - Quest Fail'),

-- Gorgonna 27726
(27726,0,0,0,1,0,100,1,6000,6000,1,1,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Gorgonna - OOC 6 Sec - Say 0'),
(27726,0,1,0,52,0,100,0,0,27726,0,0,1,1,18000,0,0,0,0,1,0,0,0,0,0,0,0,'Gorgonna - Say 0 - Say 1'),
(27726,0,2,0,52,0,100,0,1,27726,0,0,1,2,15000,0,0,0,0,1,0,0,0,0,0,0,0,'Gorgonna - Say 1 - Say 2'),
(27726,0,3,0,52,0,100,0,2,27726,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gorgonna - Say 2 - Say 3'),

-- Grennix Shivwiggle 27719
(27719, 0, 0, 0, 19, 0, 100, 0, 12427, 0, 0, 0, 12, 27715, 7, 0, 0, 0, 0, 8, 0, 0, 0, 3242.77, -2340.98, 92.34, 0.98, 'Grennix Shivwiggle - Accepted Quest - Summon 27715'),
(27719, 0, 1, 0, 19, 0, 100, 0, 12428, 0, 0, 0, 12, 27716, 7, 0, 0, 0, 0, 8, 0, 0, 0, 3242.77, -2340.98, 92.34, 0.98, 'Grennix Shivwiggle - Accepted Quest - Summon 27716'),
(27719, 0, 2, 0, 19, 0, 100, 0, 12429, 0, 0, 0, 12, 27717, 7, 0, 0, 0, 0, 8, 0, 0, 0, 3242.77, -2340.98, 92.34, 0.98, 'Grennix Shivwiggle - Accepted Quest - Summon 27717'),
(27719, 0, 3, 0, 19, 0, 100, 0, 12430, 0, 0, 0, 12, 27718, 7, 0, 0, 0, 0, 8, 0, 0, 0, 3242.77, -2340.98, 92.34, 0.98, 'Grennix Shivwiggle - Accepted Quest - Summon 27718'),
(27719, 0, 4, 0, 19, 0, 100, 0, 12431, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grennix Shivwiggle - Accepted Quest - Say 0'),
(27719, 0, 5, 0, 19, 0, 100, 0, 12431, 0, 0, 0, 12, 27727, 7, 0, 0, 0, 0, 8, 0, 0, 0, 3251.91, -2340.61, 91.86, 3.1, 'Grennix Shivwiggle - Accepted Quest - Summon 27727');
