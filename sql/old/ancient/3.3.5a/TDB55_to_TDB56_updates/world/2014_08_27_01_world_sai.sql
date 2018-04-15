SET @Xarantaur    := 30381;
SET @Stormhoof    := 30388;
SET @Wind         := 30474;
SET @WindImage    := 30550;
SET @Spirit       := 30479;
SET @Ride         := 46598;
SET @DropHorn     := 56892;
SET @Stun         := 46957;

DELETE FROM `creature_text` WHERE `entry` IN (@Xarantaur,@Wind,@Stormhoof,@Spirit,@WindImage);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Xarantaur, 0, 0, 'And it very nearly didn''t remember you. $N fought bravely against the North Wind to protect your story.', 12, 0, 100, 1, 0, 0, 'Xarantaur',32748),
(@Xarantaur, 1, 0, 'Your battle with the wind was hundreds of years ago, Stormhoof. You weakened it so much that it has been silent all these years.', 12, 0, 100, 273, 0, 0, 'Xarantaur',32750),
(@Xarantaur, 2, 0, 'But the North Wind did not silently accept defeat. Instead, it gathered power and bided its time, deciding the best revenge was to destroy your memory, and with it, your village.', 12, 0, 100, 1, 0, 0, 'Xarantaur',32751),
(@Xarantaur, 3, 0, 'The wind used its minions to distort the history of this place, changing the stories your people told, destroying the spirits of the honored dead.', 12, 0, 100, 1, 0, 0, 'Xarantaur',32752),
(@Xarantaur, 4, 0, 'It would''ve succeeded if $N and I hadn''t tracked the North Wind''s historical corruptions to their source: your ancient battle.', 12, 0, 100, 1, 0, 0, 'Xarantaur',32754),
(@Xarantaur, 5, 0, 'With my help, $N travelled back in time to your battle, and ensured that history was set right. The North Wind''s fate was sealed, and your story restored.', 12, 0, 100, 1, 0, 0, 'Xarantaur',32755),
(@Xarantaur, 6, 0, 'Rest well, hero.', 12, 0, 100, 273, 0, 0, 'Xarantaur',32762),
(@Xarantaur, 7, 0, 'This isn''t right at all, $n. In the tale Wind Tamer Barah told me, Stormhoof was a hero, not a villain.', 12, 0, 100, 6, 0, 0, 'Xarantaur',31041),
(@Xarantaur, 8, 0, 'The North Wind is the ancient enemy of the taunka, a ruler among the elements, and the very force which bleeds the life from these ancient people.', 12, 0, 100, 1, 0, 0, 'Xarantaur',31044),
(@Xarantaur, 9, 0, 'They would rather die than bow before the North Wind. Something is amiss here.', 12, 0, 100, 274, 0, 0, 'Xarantaur',31046),
(@Xarantaur, 10, 0, 'The Lorehammer...', 12, 0, 100, 25, 0, 0, 'Xarantaur',31049),
(@Xarantaur, 11, 0, 'It confirms our suspicions. The threads of time have been severed and rewoven in the wrong pattern. But, how?', 12, 0, 100, 1, 0, 0, 'Xarantaur',31050),
(@Xarantaur, 12, 0, 'There''s no doubt that something has distorted the true history of Stormhoof and the warriors of Camp Tunka''lo. But, what?', 12, 0, 100, 1, 0, 0, 'Xarantaur',31259),
(@Xarantaur, 13, 0, 'No! The true voice of history will triumph. We will restore all you have destroyed!', 12, 0, 100, 25, 0, 0, 'Xarantaur',31263),
(@Xarantaur, 14, 0, '$n, we must hurry and discover when the North Wind has started distorting the timeline. Only then can we defeat him and correct it.', 12, 0, 100, 1, 0, 0, 'Xarantaur',31264),
(@Stormhoof, 0, 0, 'The horn! Use the horn on it while it''s weak!', 14, 0, 100, 0, 0, 0, 'Stormhoof',31183),
(@Stormhoof, 1, 0, 'Go to the center of the temple and use the Horn of Elemental Fury!', 41, 0, 100, 0, 0, 0, 'Stormhoof',36207),
(@WindImage, 0, 0, 'Do not trouble yourself, little tauren. Neither Stormhoof, nor you and your ally will stand in my way.', 12, 0, 100, 1, 0, 0, 'Image of the North Wind',31260),
(@WindImage, 1, 0, 'Even now, my power grows. I have long waited for the day when my revenge would be complete.', 12, 0, 100, 1, 0, 0, 'Image of the North Wind',31261),
(@WindImage, 2, 0, 'Stormhoof and his kin will be erased from history and these lands will be restored to their rightful owner!', 12, 0, 100, 1, 0, 0, 'Image of the North Wind',31262),
(@Wind, 0, 0, 'Fool! You will never defeat me!', 14, 0, 100, 0, 0, 0, 'North Wind',31180),
(@Wind, 1, 0, 'I will never allow you to use the Horn of Elemental Fury against us! Die, weakling!', 14, 0, 100, 0, 0, 0, 'North Wind',31181),
(@Spirit, 0, 0, 'This is Camp Tunka''lo, the village ruled by my brother, but I... I don''t remember you.', 12, 0, 100, 6, 0, 0, 'Stormhoof''s Spirit',32747),
(@Spirit, 1, 0, 'The North Wind? It still troubles my people?', 12, 0, 100, 6, 0, 0, 'Stormhoof''s Spirit',32749),
(@Spirit, 2, 0, 'You both have my thanks and that of the village, though many will never know of your deeds.', 12, 0, 100, 2, 0, 0, 'Stormhoof''s Spirit',32756),
(@Spirit, 3, 0, 'I cannot remain here. I must return to my cairn where I belong, but when I see the ancestors again, it is I who will tell your story.', 12, 0, 100, 1, 0, 0, 'Stormhoof''s Spirit',32759);


UPDATE `creature_model_info` SET `bounding_radius`=0.6249996, `combat_reach`=2.7 WHERE `modelid`=26979;
UPDATE `creature_model_info` SET `bounding_radius`=0.6597218, `combat_reach`=2.85 WHERE `modelid`=26980;

DELETE FROM `creature_equip_template` WHERE `entry`=@Spirit;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@Spirit,1,42873,0,0);

UPDATE `creature_template` SET `spell1`=56897,`spell2`=61668,`spell3`=56896,`AIName`='' WHERE `entry`=@Stormhoof;
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=@Wind;
UPDATE `creature_template` SET `faction`=775,`unit_flags`=768 WHERE `entry`=@Spirit;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Xarantaur,@Wind,@Spirit,@WindImage);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Xarantaur,@Stormhoof,@Wind,@Spirit,@WindImage) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Xarantaur*100,(@Xarantaur*100)+1) AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Spirit*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Wind,0,0,0,0,0,100,0,1000,3000,8000,11000,11,61662,0,0,0,0,0,2,0,0,0,0,0,0,0,'North Wind - IC - Cast Cyclone'),
(@Wind,0,1,0,0,0,100,0,1000,8000,12000,16000,11,61663,0,0,0,0,0,2,0,0,0,0,0,0,0,'North Wind - IC - Gust of Wind'),
(@Wind,0,2,3,2,0,100,1,10,20,20000,20000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Set faction'),
(@Wind,0,3,4,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Say line 0'),
(@Wind,0,4,5,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Stop autoattack'),
(@Wind,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Stop combat movement'),
(@Wind,0,6,7,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Set homeposition'),
(@Wind,0,7,0,61,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Stop health regen'),
(@Wind,0,8,9,52,0,100,0,0,@Wind,0,0,1,0,0,0,0,0,0,19,@Stormhoof,20,0,0,0,0,0,'North Wind - Text over - Stormhoof say line 0'),
(@Wind,0,9,10,61,0,100,0,0,0,0,0,1,1,1000,0,0,0,0,19,@Stormhoof,20,0,0,0,0,0,'North Wind - Text over - Spellcast Drop Horn of Elemental Fury'),
(@Wind,0,10,0,61,0,100,0,0,0,0,0,11,@DropHorn,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Spellcast Drop Horn of Elemental Fury'),
(@Wind,0,11,12,52,0,100,0,1,@Stormhoof,0,0,28,@Ride,0,0,0,0,0,19,@Stormhoof,20,0,0,0,0,0,'North Wind - Text over - Remove aura Ride Vehicle Hardcoded'),
(@Wind,0,12,13,61,0,100,0,0,0,0,0,11,@Stun,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text Over - Spellcast Cosmetic - Stun (Permanent)'),
(@Wind,0,13,0,61,0,100,0,0,0,0,0,1,1,60000,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text Over - Say line 1'),
(@Wind,0,14,15,52,0,100,0,1,@Wind,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Restore faction'),
(@Wind,0,15,16,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Enable autocombat'),
(@Wind,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Enable combat movement'),
(@Wind,0,17,18,61,0,100,0,0,0,0,0,28,@Stun,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Remove aura Cosmetic - Stun (Permanent)'),
(@Wind,0,18,19,61,0,100,0,0,0,0,0,102,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Start health regen'),
(@Wind,0,19,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Text over - Despawn'),
(@Xarantaur,0,0,1,20,1,100,0,13058,0,0,0,12,@Spirit,8,0,0,0,0,8,0,0,0,7765.307,-2831.78,1216.812,3.577925,'Xarantaur - Quest rewarded (phase 1)- Summon Stormhoof''s Spirit'),
(@Xarantaur,0,1,2,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (phase 1) - Set event phase 0'),
(@Xarantaur,0,2,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (phase 1) - Store targetlist'),
(@Xarantaur,0,3,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Xarantaur - Respawn - Set event phase 1'),
(@Xarantaur,0,4,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Data 0 1 set - Say line 0'),
(@Xarantaur,0,5,0,38,0,100,0,0,2,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Data 0 2 set - Say line 4'),
(@Xarantaur,0,6,0,38,0,100,0,0,3,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Data 0 2 set - Say line 5'),
(@Xarantaur,0,7,8,20,1,100,0,13034,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (The Witness and the Hero)- Store Targetlist'),
(@Xarantaur,0,8,0,61,1,100,0,0,0,0,0,80,@Xarantaur*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (The Witness and the Hero)- Run Script 1'),
(@Xarantaur,0,9,10,20,1,100,0,13038,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (Distortions in Time)- Store Targetlist'),
(@Xarantaur,0,10,0,61,1,100,0,0,0,0,0,80,(@Xarantaur*100)+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Xarantaur - Quest rewarded (Distortions in Time)- Run Script 2'),
(@Xarantaur*100,9,0,0,0,0,100,0,1000,1000,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script - Say Line 7'),
(@Xarantaur*100,9,1,0,0,0,100,0,6000,6000,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script - Say Line 8'),
(@Xarantaur*100,9,2,0,0,0,100,0,6000,6000,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script - Say Line 9'),
(@Xarantaur*100,9,3,0,0,0,100,0,6000,6000,0,0,1,10,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script - Say Line 10'),
(@Xarantaur*100,9,4,0,0,0,100,0,6000,6000,0,0,1,11,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script - Say Line 11'),
(@WindImage, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 16000, 11, 57322, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of the North Wind - On Data Set - Cast Lightning Nova'),
((@Xarantaur*100)+1,9,0,0,0,0,100,0,1000,1000,0,0,1,12,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script 2 - Say Line 12'),
((@Xarantaur*100)+1,9,1,0,0,0,100,0,4000,4000,0,0,12,@WindImage,1,18000,0,0,0,8,0,0,0,7761.913, -2830.313, 1216.813, 4.310963,'Xarantaur - Script - Summon Image of the Northwind'),
((@Xarantaur*100)+1,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,@WindImage,0,0,0,0,0,0,'Xarantaur - Script 2- Set Data 1 1 to Image of the Northwind'),
((@Xarantaur*100)+1,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,@WindImage,0,0,0,0,0,0,'Xarantaur - Script 2- Say Line 1 (Image of the North Wind)'),
((@Xarantaur*100)+1,9,4,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,19,@WindImage,0,0,0,0,0,0,'Xarantaur - Script 2- Say Line 2 (Image of the North Wind)'),
((@Xarantaur*100)+1,9,5,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,19,@WindImage,0,0,0,0,0,0,'Xarantaur - Script 2- Say Line 3 (Image of the North Wind)'),
((@Xarantaur*100)+1,9,6,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,@WindImage,0,0,0,0,0,0,'Xarantaur - Script 2- Set Data 1 1 to Image of the Northwind'),
((@Xarantaur*100)+1,9,7,0,0,0,100,0,3000,3000,0,0,1,13,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script2 - Say Line 13'),
((@Xarantaur*100)+1,9,8,0,0,0,100,0,6000,6000,0,0,1,14,0,0,0,0,0,12,1,0,0,0,0,0,0,'Xarantaur - Script 2- Say Line 14'),
(@Spirit,0,0,0,54,0,100,0,0,0,0,0,80,@Spirit*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit - Just summoned - Run script'),
(@Spirit*100,9,0,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,7762.596,-2834.026,1216.85,0,'Stormhoof''s Spirit script - Move to position'),
(@Spirit*100,9,1,0,0,0,100,0,2500,2500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Say line 0'),
(@Spirit*100,9,2,0,0,0,100,0,6000,6000,0,0,45,0,1,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Set data 0 1 Xarantaur'),
(@Spirit*100,9,3,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Say line 1'),
(@Spirit*100,9,4,0,0,0,100,0,4500,4500,0,0,1,1,0,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Xarantaur say line 1'),
(@Spirit*100,9,5,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Xarantaur say line 2'),
(@Spirit*100,9,6,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Xarantaur say line 3'),
(@Spirit*100,9,7,0,0,0,100,0,6000,6000,0,0,45,0,2,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Set data 0 2 Xarantaur'),
(@Spirit*100,9,8,0,0,0,100,0,6000,6000,0,0,45,0,3,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Set data 0 3 Xarantaur'),
(@Spirit*100,9,9,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Say line 2'),
(@Spirit*100,9,10,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Say line 3'),
(@Spirit*100,9,11,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,19,@Xarantaur,20,0,0,0,0,0,'Stormhoof''s Spirit script - Xarantaur say line 6'),
(@Spirit*100,9,12,0,0,0,100,0,3000,3000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Play emote'),
(@Spirit*100,9,13,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,7765.107,-2832.312,1216.809,0,'Stormhoof''s Spirit script - Move to position'),
(@Spirit*100,9,14,0,0,0,100,0,2500,2500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof''s Spirit script - Set orientation');

UPDATE `creature_template` SET `faction`=14, `unit_flags`=768 WHERE  `entry`=@WindImage;

DELETE FROM `creature_template_addon` WHERE `entry`=@WindImage;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@WindImage, 0, 0x2000000, 0x1, ''); -- 30550
