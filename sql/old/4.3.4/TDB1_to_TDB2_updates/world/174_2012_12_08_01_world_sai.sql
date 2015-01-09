-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Move Texts to correct table
DELETE FROM `db_script_string` WHERE `entry` IN (2000000090,2000000091,2000000092,2000000097,2000000098,2000000099,2000000100,2000000090,2000000091,2000000092,2000000095,2000000096);
DELETE FROM `creature_text` WHERE `entry` IN (1443,3054,3616,3448,4049);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- 1443: Ferzerul Texts
(1443,0,0, 'I hereby destroy these instruments of evil! For the Horde!',14,1,100,0,0,0, 'Felzerul on Quest 1445 finished'),
-- 3054: Zarlman Two-Moons Texts
(3054,0,0, 'Zarlman Two-Moons begins chanting as he mixes the well stones and ambercom before the Tribal Fire.',16,1,100,0,0,0, 'Zarlman Two-Moons on Quest 771 finished 1'),
(3054,1,0, 'The Water of the Seers is ready for your consumption, $N.',12,1,100,0,0,0, 'Zarlman Two-Moons on Quest 771 finished 2'),
-- 3448: Tonga Runetotem Texts
(3448,0,0, 'Tonga Runetotem inspects the snapjaw shells...',16,1,100,0,0,0, 'Tonga Runetotem on Quest 880 finished'),
(3448,1,0, 'Hm...',12,1,100,0,0,0, 'Tonga Runetotem on Quest 880 finished'),
(3448,2,0, 'Strange. Very strange...',12,1,100,0,0,0, 'Tonga Runetotem on Quest 880 finished'),
(3448,3,0, '$N. These shells tell me much, but I fear many more questions are now raised...',12,1,100,1,0,0, 'Tonga Runetotem on Quest 880 finished'),
-- 3616: Onu Texts
(3616,0,0, 'Onu studies the parchment from the Twilight Tome...',16,7,100,0,0,0, 'Onu on Quest 950 finished'),
(3616,1,0, 'Onu is struck by unleashed magic!',16,7,100,0,0,0, 'Onu on Quest 950 finished'),
(3616,2,0, 'Hmm...',12,7,100,0,0,0, 'Onu on Quest 950 finished'),
-- 4049: Seereth Stonebreak Texts
(4049,0,0, 'The spirits of Stonetalon still rage, $N.',16,7,100,0,0,0,'Seereth Stonebreak on Quest 1062 finished'),
(4049,1,0, 'I fear we may never soothe them...',16,7,100,0,0,0,'Seereth Stonebreak on Quest 1062 finished');
-- SAI 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (1443,3054,3448,3616,4049,21311);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1443,3054,3448,3616,4049,21311) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=305400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Ferzerul Converted Quest_end_scripts id 1445
(1443,0,0,1,20,0,100,0,1062,0,0,0,1 ,   0,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Seereth Stonebreak - On quest " The Temple of AtalHakkar" rewarded - Say line 1'),
(1443,0,1,0,20,0,100,0,1062,0,0,0,11,7437,   0,0,0,0,0,1,0,0,0,0,0,0,0,'Seereth Stonebreak - On quest " The Temple of AtalHakkar" rewarded - Cast Spell'),
-- Tonga Runetotem Converted Quest_end_scripts id 880
(3448,0,0,1,20,0,100,0,880,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Tonga Runetotem - On quest "Altered Beings" rewarded - Say line 1'),
(3448,0,1,2,20,0,100,0,880,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0, 'Tonga Runetotem - On quest "Altered Beings" rewarded - Say line 2'),
(3448,0,2,3,20,0,100,0,880,0,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0, 'Tonga Runetotem - On quest "Altered Beings" rewarded - Say line 3'),
(3448,0,3,4,20,0,100,0,880,0,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0, 'Tonga Runetotem - On quest "Altered Beings" rewarded - Say line 4'),
-- Onu Converted Quest_end_scripts id 950
(3616,0,0,1,20,0,100,0,950,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0, 'Onu - On quest "Return to Onu" rewarded - Say line 1'),
(3616,0,1,2,20,0,100,0,950,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0, 'Onu - On quest "Return to Onu" rewarded - Say line 2'),
(3616,0,2,0,20,0,100,0,950,0,0,0,1,2,   0,0,0,0,0,1,0,0,0,0,0,0,0, 'Onu - On quest "Return to Onu" rewarded - Say line 3'),
-- Seereth Stonebeak Converted Quest_end_scripts id 1062
(4049,0,0,1,20,0,100,0,1062,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Seereth Stonebreak - On quest "Goblin Invaders" rewarded - Say line 1'),
(4049,0,1,0,20,0,100,0,1062,0,0,0,1,1,   0,0,0,0,0,1,0,0,0,0,0,0,0,'Seereth Stonebreak - On quest "Goblin Invaders" rewarded - Say line 2'),
-- Rokgar Bloodgrip Converted Quest_end_scripts id 10526
(21311,0,0,0,20,0,100,0,10526,0,0,0,12,21950,1,900000,0,0,0,8,0,0,0,2272.95,5984.40,142.79,6.23, 'Rokgah Bloodgrip - On Quest "The Thunderspike" Complete - Summon Garm Wolfbrother'),
(21311,0,1,0,20,0,100,0,10526,0,0,0,12,21952,1,900000,0,0,0,8,0,0,0,2273.26,5986.73,142.75,5.14, 'Rokgah Bloodgrip - On Quest "The Thunderspike" Complete - Summon Lobo'),
(21311,0,2,0,20,0,100,0,10526,0,0,0,12,21951,1,900000,0,0,0,8,0,0,0,2270.95,5982.93,142.83,0.31, 'Rokgah Bloodgrip - On Quest "The Thunderspike" Complete - Summon Thunderlord Clan Sub-Chief'),
(21311,0,3,0,20,0,100,0,10526,0,0,0,12,21951,1,900000,0,0,0,8,0,0,0,2271.17,5986.07,142.81,5.86, 'Rokgah Bloodgrip - On Quest "The Thunderspike" Complete - Summon Thunderlord Clan Sub-Chief'),
-- Zarlman Two-Moons Converted Quest_end_scripts id 771
(3054  ,0,1,0,20,0,100,0, 771,   0,0,0,80,305400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zarlman Two-Moons: On quest "" Rewarded - call script'),
(305400,9,0,1,1 ,0,100,0,   0,   0,0,0, 1,     0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zarlman Two-Moons - TimedScript - Say line 1'),
(305400,9,1,2,1 ,0,100,0,1000,1000,0,0,11,  5026,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zarlman Two-Moons - TimedScript - Cast Spell'),
(305400,9,2,0,1 ,0,100,0,7000,7000,0,0, 1,     1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zarlman Two-Moons - TimedScript - Say line 2');
-- Quest_end_script removal
DELETE FROM `quest_end_scripts` WHERE `id` IN (10526,1445,1062,950,880);
UPDATE `quest_template` SET `CompleteScript`=0 WHERE `Id`IN (10526,1445,1062,950,880);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
