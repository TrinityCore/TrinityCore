SET @CGUID :=    29979;

DELETE FROM `creature_text` WHERE `entry` IN(26097,25380,25602,25834,25849,25983,25380,25401);
DELETE FROM `creature_text` WHERE `entry` =23837 AND `groupid`=1;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(26097, 0, 0, 'Thank you for saving us. We accidentally uncovered the pieces of Gearmaster Mechazod and reassembled him.', 12, 0, 100, 0, 0, 0, 'Fizzcrank Gnome Ghost',25205),
(26097, 1, 0, 'In return, he ''de-cursed'' us, saying that we were being ''fixed'' by returning us to the state of being mechanical constructs.', 12, 0, 100, 0, 0, 0, 'Fizzcrank Gnome Ghost',25207),
(26097, 2, 0, 'He claims that all creations of the Titans fall prey to what he calls, ''The Curse of Flesh''. He says that the original gnomes were once mechagnomes.', 12, 0, 100, 0, 0, 0, 'Fizzcrank Gnome Ghost',25208),
(26097, 3, 0, 'He''s quite insane! Someone must put a stop to his madness before it''s too late for everyone!', 12, 0, 100, 0, 0, 0, 'Fizzcrank Gnome Ghost',25209),
(25602, 0, 0, 'Now, $n, let us release their souls and hear what they have to say.', 12, 0, 100, 1, 0, 0, 'Greatmother Taiga',25204),
(25602, 1, 0, 'This is dire news indeed!', 12, 0, 100, 1, 0, 0, 'Greatmother Taiga',25211),
(25380, 0, 0, 'And remember, $n, the bloodspore powder can be used to weaken all magnataur in Gammoth.', 15, 0, 100, 0, 0, 0, 'Primal Mighthorn',24994),
(25834, 0, 0, 'You were looking for me, child? Why do you come to kill me, $n? I only wish to help.', 12, 0, 100, 6, 0, 0, 'Gearmaster Mechazod',25024),
(25834, 1, 0, 'Now that I have been reassembled, we can return to a time of perfection... the time of the Titans!', 12, 0, 100, 1, 0, 0, 'Gearmaster Mechazod',25025),
(25834, 2, 0, 'But, I can see it in your eyes, hear it in your pulse rate. You would destroy me despite my offer of immortality!', 12, 0, 100, 25, 0, 0, 'Gearmaster Mechazod',25026),
(25834, 3, 0, 'Very well. It saddens me that it has come to this. I look upon all of you as if you were my children. I will slay you if I must!', 12, 0, 100, 25, 0, 0, 'Gearmaster Mechazod',25027),
(23837, 1, 0, 'There is a noise from behind you!', 41, 0, 100, 0, 0, 0, 'ELM General Purpose Bunny',25215),
(25849, 0, 0, 'It''s really going to work this time... right?', 12, 0, 100, 6, 0, 0, 'Fezzix Geartwist',25143),
(25849, 1, 0, 'It works, Dorain! Look! It actually works...', 12, 0, 100, 4, 0, 0, 'Fezzix Geartwist',25148),
(25849, 2, 0, 'Here I goooooooooo!', 12, 0, 100, 0, 0, 0, 'Fezzix Geartwist',25150),
(25849, 3, 0, 'OUCH!', 12, 0, 100, 0, 0, 0, 'Fezzix Geartwist',25151),
(25849, 4, 0, 'I give up! So much for goblin ingenuity!', 12, 0, 100, 5, 0, 0, 'Fezzix Geartwist',25152),
(25983, 0, 0, 'Fezzix, I think we''ve solved your little engine problem.', 12, 0, 100, 1, 0, 0, 'Dorain Frosthoof',25132),
(25401, 0, 0, '%s armed.', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24590),
(25401, 1, 0, 'Detonation in 5...', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24591),
(25401, 2, 0, '4...', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24592),
(25401, 3, 0, '3...', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24593),
(25401, 4, 0, '2...', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24594),
(25401, 5, 0, '1...', 16, 0, 100, 0, 0, 0, 'Seaforium Depth Charge',24595);

UPDATE `creature_template` SET `unit_flags`=33024 WHERE  `entry`=25834;
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(26097,35426,25602,25983,25849,25834,25380,25401);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26097,35426,25602,25983,25849,25834,25380,25401) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2560200,2598300,2584900,2584901,2583400,2540100) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25401, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - On Just Summoned - Store Targetlist'),
(25401, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2540100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - On Just Summoned - Run Script'),
(25401, 0, 2, 0, 1, 2, 100, 1, 100, 100, 0, 0, 11, 45506, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - OOC (Phase 2/No repeat) - Cast Nerub ar Sinkhole Credit (SW) '),
(25401, 0, 3, 0, 1, 2, 100, 1, 100, 100, 0, 0, 11, 45508, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - OOC (Phase 2/No repeat) - Cast Nerub ar Sinkhole Credit (SE)'),
(25401, 0, 4, 0, 1, 2, 100, 1, 100, 100, 0, 0, 11, 45510, 2, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - OOC (Phase 2/No repeat) - Cast Nerub ar Sinkhole Credit (NW)'),
(25401, 0, 5, 0, 1, 2, 100, 1, 100, 100, 0, 0, 11, 45512, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - OOC (Phase 2/No repeat) - Cast Nerub ar Sinkhole Credit (NE)'),
(25834, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - On Just Summoned - Store Targetlist'),
(25834, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2583400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - On Just Summoned - Run Script'),
(25834, 0, 2, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - On Evade Despawn'),
(25380, 0, 0, 0, 19, 0, 100, 0, 11721, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Primal Mighthorn - On Quest Accept (Gammothra the Tormentor) - Say Line 1'),
(26097, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fizzcrank Gnome Ghost - OOC (No Repeat) - Cast Arcane Explosion Visual'),
(26097, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 32423, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fizzcrank Gnome Ghost - On Just Summoned - Cast Blue Radiation'),
(25602, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - On Reset Set Phase 1'),
(25602, 0, 1, 2, 20, 1, 100, 0, 11899, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - On Quest Reward (Souls of the Decursed) - Say Line 1 (Phase 1)'),
(25602, 0, 2, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, 2560200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - On Quest Reward (Souls of the Decursed) - Run Script (Phase 1)'),
(25983, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorain Frosthoof - On Reset Set Phase 1'),
(25983, 0, 1, 2, 20, 1, 100, 0, 11893, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dorain Frosthoof -  - On Quest Reward (The Power of the Elements) - Say Line 1'),
(25983, 0, 2, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, 2598300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorain Frosthoof -  - On Quest Reward (The Power of the Elements) - Run Script'),
(25849, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - On Reset Set Phase 1'),
(25849, 0, 1, 2, 20, 1, 100, 0, 11894, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist -  - On Quest Reward (Patching Up) - Say Line 1'),
(25849, 0, 2, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, 2584900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist -  - On Quest Reward (Patching Up) - Run Script'),
(25849, 0, 3, 0, 40, 2, 100, 0, 11, 25849, 0, 0, 80, 2584901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist -  - On Reached WP11 - Run Script (Phase 2)'),
(25849, 0, 4, 5, 40, 2, 100, 0, 12, 25849, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist -  - On Reached WP12 - Set Phase 1'),
(25849, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.06662, 'Fezzix Geartwist -  - On Reached WP12 - Set Orientation'),
(2540100, 9, 0, 0, 0, 0, 100, 0, 0, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 0'),
(2540100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 1'),
(2540100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 2'),
(2540100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 2'),
(2540100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 2'),
(2540100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Say Line 2'),
(2540100, 9, 6, 0, 0, 0, 100, 0, 900, 900, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Set Phase 2'),
(2540100, 9, 7, 0, 0, 0, 100, 0, 100, 100, 0, 0, 11, 45502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Cast Seaforium Depth Charge Explosion'),
(2540100, 9, 8, 0, 0, 0, 100, 0, 500, 500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seaforium Depth Charge - Script - Cast Seaforium Depth Charge Explosion'),
(2584900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Set Phase 2'),
(2584900, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 12, 26040, 1, 13000, 0, 0, 0, 8, 0, 0, 0, 3481.329, 4099.854, 17.83902, 3.351032, 'Fezzix Geartwist - Script - Spawn Fezzixs Flying Machine'),
(2584900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 60069, 188087, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Despawn Wreckage A'),
(2584900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 60080, 188088, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Despawn Wreckage B'),
(2584900, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 14, 60095, 188089, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Despawn Wreckage C'),
(2584900, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Say Line 2'),
(2584900, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 43, 0, 22719, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Mount Display ID 22719'),
(2584900, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Say Line 3'),
(2584900, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Set Fly On'),
(2584900, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 25849, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script - Start WP'),
(2583400, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Cast Ethereal Teleport'),
(2583400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 10, @CGUID+0, 23837, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Say Line on Bunny'),
(2583400, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Say Line 1'),
(2583400, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Set Orientation'),
(2583400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Say Line 2'),
(2583400, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Say Line 3'),
(2583400, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Say Line 4'),
(2583400, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Remove Unit Flag (Immune to PC)'),
(2583400, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gearmaster Mechazod - Script - Start Attack'),
(2584901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46419, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Cast Cosmetic - Explosion'),
(2584901, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Dismount'),
(2584901, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Turn Fly Off'),
(2584901, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 42963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Cast Cosmetic - Combat Knockdown Self'),
(2584901, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Say Line 4'),
(2584901, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fezzix Geartwist - Script 2 - Say Line 5'),
(2598300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dorain Frosthoof - Script - Set Phase 2'),
(2598300, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 46399, 0, 0, 0, 0, 0, 14, 113431, 26041, 0, 0, 0, 0, 0, 'Dorain Frosthoof - Script - Cast Energy Transfer'),
(2598300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dorain Frosthoof - Script - Set Phase 1'),
(2560200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Set Phase 2'),
(2560200, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Cast Nature Channeling'),
(2560200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 28, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Remove Aura Nature Channeling'),
(2560200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Summon Group 0'),
(2560200, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26097, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Say Line 1 on Closest Fizzcrank Gnome Ghost'),
(2560200, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26097, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Say Line 2 on Closest Fizzcrank Gnome Ghost'),
(2560200, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26097, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Say Line 3 on Closest Fizzcrank Gnome Ghost'),
(2560200, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 26097, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Say Line 4 on Closest Fizzcrank Gnome Ghost'),
(2560200, 9, 8, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 5, 3, 0, 0, 0, 0, 0, 9, 26097, 0, 200, 0, 0, 0, 0, 'Greatmother Taiga - Script - Play emote OneShotWave on all Fizzcrank Gnome Ghost'),
(2560200, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Say Line 2'),
(2560200, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Taiga - Script - Set Phase 1');


DELETE FROM `creature_summon_groups` WHERE `summonerId`=25602;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(25602, 0, 0, 26097, 3483.047, 4114.145, 18.48475, 3.193953, 1, 40000),
(25602, 0, 0, 26097, 3486.638, 4116.401, 18.48475, 3.403392, 1, 40000),
(25602, 0, 0, 26097, 3483.65, 4112.257, 18.48475, 2.9147, 1, 40000),
(25602, 0, 0, 26097, 3481.733, 4118.205, 18.48475, 3.926991, 1, 40000),
(25602, 0, 0, 26097, 3485.337, 4117.493, 18.48475, 3.543018, 1, 40000),
(25602, 0, 0, 26097, 3482.166, 4116.395, 18.48475, 3.612832, 1, 40000),
(25602, 0, 0, 26097, 3485.657, 4113.342, 18.48475, 3.124139, 1, 40000),
(25602, 0, 0, 26097, 3483.949, 4118.282, 18.48475, 3.682645, 1, 40000),
(25602, 0, 0, 26097, 3484.028, 4115.051, 18.48475, 3.316126, 1, 40000),
(25602, 0, 0, 26097, 3484.057, 4116.235, 18.48474, 3.560472, 1, 40000);


DELETE FROM `waypoints` WHERE `entry` =25849;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(25849, 1,3476.835, 4099.595, 20.46597, 'Fezzix Geartwist'),
(25849, 2,3469.259, 4098.425, 23.37573, 'Fezzix Geartwist'),
(25849, 3,3464.057, 4092.921, 28.09206, 'Fezzix Geartwist'),
(25849, 4,3468.28, 4083.907, 34.53652, 'Fezzix Geartwist'),
(25849, 5,3471.045, 4079.119, 38.06437, 'Fezzix Geartwist'),
(25849, 6,3476.159, 4076.131, 41.48104, 'Fezzix Geartwist'),
(25849, 7,3483.686, 4077.679, 42.78663, 'Fezzix Geartwist'),
(25849, 8,3487.812, 4082.535, 42.78663, 'Fezzix Geartwist'),
(25849, 9,3488.05, 4090.021, 42.78663, 'Fezzix Geartwist'),
(25849, 10,3486.571, 4098.099, 42.78663, 'Fezzix Geartwist'),
(25849, 11,3479.899, 4100.219, 42.78663, 'Fezzix Geartwist'),
(25849, 12,3477.16, 4103.97, 17.9091, 'Fezzix Geartwist');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 23837, 571, 1, 1, 4000.194, 4853.576, 26.05447, 5.585053, 120, 0, 0); -- 23837 (Area: 3537)

DELETE FROM `event_scripts` WHERE `id`=17209;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(17209, 3, 10, 25834, 3000000, 0, 4004.175, 4850.362, 26.05081,2.391101);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45502;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 45502, 0, 0, 31, 0, 3, 25402, 0, 1, 0, 0, '', 'Seaforium Depth Charge Explosion does not knock back Nerub ar Sinkhole (South)'),
(13, 2, 45502, 0, 0, 31, 0, 3, 25403, 0, 1, 0, 0, '', 'Seaforium Depth Charge Explosion does not knock back Nerub ar Sinkhole (East)'),
(13, 2, 45502, 0, 0, 31, 0, 3, 25404, 0, 1, 0, 0, '', 'Seaforium Depth Charge Explosion does not knock back Nerub ar Sinkhole (West)'),
(13, 2, 45502, 0, 0, 31, 0, 3, 25405, 0, 1, 0, 0, '', 'Seaforium Depth Charge Explosion does not knock back Nerub ar Sinkhole (North)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25401;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 3, 25401, 0, 0, 29, 1, 25402, 20, 0, 0, 0, 0, '', 'Seaforium Depth Charge - Only run SAI if Nerub ar Sinkhole (South) within 20 yards'),
(22, 4, 25401, 0, 0, 29, 1, 25403, 20, 0, 0, 0, 0, '', 'Seaforium Depth Charge - Only run SAI if Nerub ar Sinkhole (East) within 20 yards'),
(22, 5, 25401, 0, 0, 29, 1, 25404, 20, 0, 0, 0, 0, '', 'Seaforium Depth Charge - Only run SAI if Nerub ar Sinkhole (West) within 20 yards'),
(22, 6, 25401, 0, 0, 29, 1, 25405, 20, 0, 0, 0, 0, '', 'Seaforium Depth Charge - Only run SAI if Nerub ar Sinkhole (North) within 20 yards');
