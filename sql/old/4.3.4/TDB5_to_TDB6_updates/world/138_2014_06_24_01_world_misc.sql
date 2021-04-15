-- Q: The Forgotten Tale (12291) & The Truth Shall Set Us Free (12301), & Frostmourne Cavern.
SET @Valonforth     := 27476; -- Captain Luc Valonforth
SET @FPeasant       := 27226; -- Forgotten Peasant -- Ya tiene SAI
SET @FFootman       := 27229; -- Forgotten Footman  -- Ya tiene SAI
SET @FCaptain       := 27220; -- Forgotten Captain -- Ya tiene SAI
SET @FKnight        := 27224; -- Forgotten Knight  -- Ya tiene SAI
SET @FRifleman      := 27225; -- Forgotten Rifleman  -- Ya tiene SAI
SET @Emissary       := 27492; -- Alliance Emissary
SET @PrinceArthas   := 27455; -- Prince Arthas
SET @Muradin        := 27480; -- Muradin
SET @OrbItem        := 37577; -- Orik's Crystalline Orb (Item)
SET @AuraForgotten  := 48864; -- Aura of the Forgotten
SET @OrikSpell      := 48866; -- Orik's Song (Spell)  -- Send Script Event (18014)
SET @ArthasSpell    := 48882; -- Spirit Redeemed (Spell)
SET @ForgottenSoul  := 27465; -- Forgotten Soul (npc)
SET @DespawnSoul    := 48811; -- Despawn Forgotten Soul (Spell) -- Mata soul? 

DELETE FROM creature_summon_groups WHERE `summonerId`=@Valonforth;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(@Valonforth,0,1,@Ffootman,3093.6093,-1248.6965,10.7540,0.6420,3,42300),
(@Valonforth,0,1,@Ffootman,3091.3823,-1245.5709,10.4475,0.0712,3,42300),
(@Valonforth,0,1,@Ffootman,3089.9931,-1248.9025,10.5483,0.0712,3,42300),
(@Valonforth,0,1,@Ffootman,3088.4882,-1245.6225,10.3214,0.5183,3,42300),
(@Valonforth,0,1,@Ffootman,3086.1555,-1242.1805,10.3200,0.3025,3,42300),
(@Valonforth,0,1,@Ffootman,3101.2993,-1231.2617,10.2738,4.8548,3,42300), 
(@Valonforth,0,1,@Ffootman,3096.5869,-1232.9973,9.9625,4.8965,3,42300),
(@Valonforth,0,1,@Ffootman,3092.5539,-1251.9555,11.0228,0.7564,3,42300),
(@Valonforth,0,1,@Ffootman,3089.5644,-1239.8127,10.3610,6.0050,3,42300),
(@Valonforth,0,1,@Ffootman,3095.2739,-1250.8770,10.9930,0.9054,3,42300),
(@Valonforth,0,1,@FRifleman,3089.7722,-1242.4241,10.3311,0.3176,3,110000),
(@Valonforth,0,1,@FRifleman,3099.4746,-1234.2282,10.0952,4.8548,3,110000),
(@Valonforth,0,1,@FKnight,3088.7661,-1237.4055,10.4127,0.1172,3,110000),
(@Valonforth,0,1,@FKnight,3094.5632,-1233.2812,9.9865,5.0920,3,110000),
(@Valonforth,0,1,@FCaptain,3085.7636,-1224.5657,12.4462,5.2552,3,110000),
(@Valonforth,0,1,@FCaptain,3083.3088,-1238.1966,10.9768,6.0426,3,110000),
(@Valonforth,0,1,@Emissary,3087.9968,-1223.3319,11.3495,6.0426,3,40000);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=@THELZAN; 

DELETE FROM event_scripts WHERE id IN (18014); -- Evento 'The Truth...'
INSERT INTO event_scripts VALUES
(18014,0,10,@Valonforth,90000,0,3100.3500,-1252.466,11.6589,2.165); -- Event The Truth...

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Valonforth,@Emissary);
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry` IN (@MURADIN,@PrinceArthas);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @MURADIN AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @PrinceArthas AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @FCaptain AND `id`>2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @FKnight AND `id`>14;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @FRifleman AND `id`>21;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Valonforth,@Emissary,@FFootman);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@PrinceArthas*100+1,@MURADIN*100+2,@Emissary*100,@Valonforth*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@PrinceArthas,0,1,0,38,0,100,0,1,1,0,0,80,@PrinceArthas*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - On dataset - Run script The Truth Shall Set...'),
(@MURADIN,0,2,0,38,0,100,0,2,1,0,0,80,@MURADIN*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - On dataset - Run script The Truth Shall Set...'),
(@Valonforth,0,0,1,54,0,100,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Just Spawned - Summon Group"),
(@Valonforth,0,1,0,61,0,100,0,0,0,0,0,80,@Valonforth*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Link - Run Script"),
(@Emissary,0,0,0,54,0,100,0,0,0,0,0,53,0,@Emissary,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Emissary - Just Spawned - Start Waypoint"),
(@Emissary,0,1,2,40,0,100,0,2,@Emissary,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Emissary - On reached WP2 - Pause Event'),
(@Emissary,0,2,0,61,0,100,0,0,0,0,0,80,@Emissary*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Emissary - Link - Run script'),
-- The Truth Shall Set Us Free - scripts
(@Valonforth*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Script - Say 0"),
(@Valonforth*100,9,1,0,0,0,100,0,15500,15500,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Script - Say 1"),
(@Valonforth*100,9,2,0,0,0,100,0,13000,13000,0,0,1,2,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Script - Say 2"),
(@Valonforth*100,9,3,0,0,0,100,0,12000,12000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Valonforth - Script - Say 3"),
(@Emissary*100,9,0,0,0,0,100,0,3500,3500,0,0,1,0,8500,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Emissary - Script - Says 0'),
(@Emissary*100,9,1,0,0,0,100,0,13000,13000,0,0,1,1,9000,0,0,0,0,1,0,0,0,0,0,0,0,'Alliance Emissary - Script - Says 1'),
(@Emissary*100,9,2,0,0,0,100,0,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,3087.9968,-1223.3319,11.3495,0,'Alliance Emissary - Script - moveto'),
(@Emissary*100,9,3,0,0,0,100,0,6000,6000,0,0,45,3,1,0,0,0,0,11,@FFootman,30,0,0,0,0,0,"Alliance Emissary - Script - Set Data 3 1 Forgotten Footman"),
(@Emissary*100,9,4,0,0,0,100,0,0,0,0,0,12,@PrinceArthas,3,63000,0,0,0,8,0,0,0,3104.5910,-1226.6417,12.0252,4.4519,"Alliance Emissary - Script - Summon Prince Arthas"),
(@Emissary*100,9,5,0,0,0,100,0,0,0,0,0,12,@Muradin,3,63000,0,0,0,8,0,0,0,3105.9204,-1228.2515,11.6541,11.6541,"Alliance Emissary - Script - Summon Muradin"),
(@Emissary*100,9,6,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@PrinceArthas,20,0,0,0,0,0,"Alliance Emissary - Script - Set Data 1 1 Prince Arthas"),
(@Emissary*100,9,7,0,0,0,100,0,0,0,0,0,45,2,1,0,0,0,0,11,@Muradin,20,0,0,0,0,0,"Alliance Emissary - Script - Set Data 2 1 Muradin"),
(@Emissary*100,9,8,0,0,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Emissary - Script - Despawn"),
(@PrinceArthas*100+1,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3101.1733,-1238.0469,10.3770,0,'Prince Arthas - Script - moveto'),
(@PrinceArthas*100+1,9,1,0,0,0,100,0,2000,2000,0,0,1,0,9000,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Says 0'),
(@PrinceArthas*100+1,9,2,0,0,0,100,0,14000,14000,0,0,1,1,11000,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Says 1'),
(@PrinceArthas*100+1,9,3,0,0,0,100,0,15000,15000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Says 2'),
(@PrinceArthas*100+1,9,4,0,0,0,100,0,18000,18000,0,0,1,3,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Says 3'),
(@PrinceArthas*100+1,9,5,0,0,0,100,0,11000,11000,0,0,11,@ArthasSpell,0,0,0,0,0,11,0,35,0,0,0,0,0,'Prince Arthas - Script - Cast Spirit Redeemed'),
(@Muradin*100+2,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3103.4113,-1238.8131,10.6220,0,"Muradin - Script - Moveto"),
(@Muradin*100+2,9,1,0,0,0,100,0,28000,28000,0,0,1,0,2500,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Says 0'),
(@Muradin*100+2,9,2,0,0,0,100,0,10000,10000,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Says 1'),

-- The Forgotten Tale & normal SAI
-- Forgottens: Captain
(@FCaptain,0,3,4,8,0,100,0,@ArthasSpell,0,0,0,3,27465,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Captain  - Spell Hit - Morph to Forgotten Soul'),
(@FCaptain,0,4,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Captain - Link - Die'),
-- Knight
(@FKnight,0,15,16,8,0,100,0,@ArthasSpell,0,0,0,3,27465,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Knight - Spell Hit - Morph to Forgotten Soul'),
(@FKnight,0,16,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Knight - Link - Die'),
-- Rifleman
(@FRifleman,0,22,23,8,0,100,0,@ArthasSpell,0,0,0,3,27465,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Rifleman  - Morph to Forgotten Soul'),
(@FRifleman,0,23,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Rifleman - Link - Die'),
-- Footman
(@FFootman,0,0,1,62,0,100,0,9545,0,0,0,33,27474,0,0,0,0,0,21,10,0,0,0,0,0,0,'Forgotten Footman - On gossip option select quest credit'), -- deberia Cast 48832
(@FFootman,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Forgotten Footman - Close Gossip'),
(@FFootman,0,2,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forgotten Footman - Add Forgotten Aura if missing'),
(@FFootman,0,3,0,0,0,100,0,3000,7000,9000,12000,11,32587,0,0,0,0,0,2,0,0,0,0,0,0,0,'Forgotten Footman - Cast Shield Block'),
(@FFootman,0,4,0,38,0,100,0,3,1,0,0,53,1,@FFootman,0,0,0,0,1,0,0,0,0,0,0,0,"Forgotten Footman - On Data set 3 1 - Start Waypoint");

DELETE FROM `creature_text` WHERE `entry` IN (@Valonforth,@Emissary);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(27492, 1, 0, 'That\'s correct. My men report that the roads from here to the shore are held by the undead. You\'ll need to find an alternate route back to your ships.', 12, 0, 100, 378, 4000, 12724, 'Alliance Emissary 1 - Q: The Truth Shall Set Us Free', 26712),
(27492, 0, 0, 'By royal edict, you men are to return to Lordaeron immediately. Lord Uther has convinced the king to recall this expedition.', 12, 0, 100, 25, 3500, 12723, 'Alliance Emissary 0 - Q: The Truth Shall Set Us Free', 26710),
(27476, 2, 0, 'To hell with the undead! We\'ll cut our way through the woods, men!', 12, 0, 100, 22, 3000, 12721, 'Valonforth 2  - Q: The Truth Shall Set Us Free', 26713),
(27476, 3, 0, 'Well, milord, your father had our troops recalled at Lord Uther\'s request.', 12, 0, 100, 1, 3000, 12722, 'Valonforth 3 - Q: The Truth Shall Set Us Free', 26715),
(27476, 0, 0, 'I apologize, emissary, but the prince is away on an errand. Wha brings you to this desolate place?', 12, 0, 100, 1, 3000, 12719, 'Valonforth 0  - Q: The Truth Shall Set Us Free', 26709),
(27476, 1, 0, 'We\'re to just pick up and leave?', 12, 0, 100, 6, 1500, 12720, 'Valonforth 1  - Q: The Truth Shall Set Us Free', 26711);

DELETE FROM `waypoints` WHERE entry IN (@Emissary,@FFootman);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Emissary,1,3087.9968,-1223.3319,11.3495,'Emissary Spawn - Q: The Truth Shall Set Us Free'),
(@Emissary,2,3094.6638,-1241.1671,10.3504,'Emissary Talk - Q: The Truth Shall Set Us Free'),
(@Emissary,3,3087.9968,-1223.3319,11.3495,'Emissary Despawn - Q: The Truth Shall Set Us Free'),
(@FFootman,1,3061.2832,-1241.4072,11.5542,'Forgotten Footman Runaway - Q: The Truth Shall Set Us Free');

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid` IN (5082,5083,5084) AND `source_type`=2 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=-126866 AND `source_type`=0 AND `id`=15 AND `link`=29;
