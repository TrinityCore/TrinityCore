-- Add script to Commander Eligor Dawnbringer
UPDATE creature_template SET `AIName`= '',ScriptName = 'npc_commander_eligor_dawnbringer' WHERE entry=27784;

-- NPC talk text insert for Commander Eligor Dawnbringer
DELETE FROM `creature_text` WHERE `entry`=27784;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27784,0,0, 'Next, I shall speak of the most powerful entities within the pinnacle of Naxxramas. Truly, these are two of the greatest threats to all of Northrend.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - Pinnacle of Naxxramas'),
(27784,1,0, 'Next, I shall speak of the death knight wing of Naxxramas. Within its corrupted halls, the echo of battle rings day and night, as our finest warriors are corrupted and twisted into the Scourge''s greatest warriors.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - Death knight wing of Naxxramas'),
(27784,2,0, 'Next, I shall speak of the blighted abomination wing of Naxxramas. There, the Scourge develop the strongest and most hideous aberrations of their armies.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - Blighted abomination wing of Naxxramas'),
(27784,3,0, 'Next, I shall speak of the accursed spider wing of Naxxramas. It is there that the Scourge breed even more poisonous and dangerous versions of their kin.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - Accursed spider wing of Naxxramas'),
(27784,4,0, 'Next, I shall speak of the dread plague wing of Naxxramas, where the scourge seek to improve upon the deadly blight which they spread upon Lordaeron.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - Dread plague wing of Naxxramas'),
(27784,5,0, 'I shall leave this image on display for your perusal. Study your opponents'' strengths, for a creature''s strength can also be its weakness.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer - End of talk'),
(27784,6,0, 'Sapphiron. Once a noble blue dragon within the mountains of Northrend, Sapphiron was slain by Arthas during his campaign through the frozen north. Resurrected to serve him, Sapphiron guards Kel''Thuzad''s lair eternally, awaiting those who would dare tresspass upon his master.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,7,0, 'The Lich, Kel''Thuzad. He serves the Lich King without question, a necromancer of great prowess in life, turned to a master of necromancy after his death. It is said he is the most loyal of the Lich King''s subjects.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,8,0, 'Kel''Thuzad has survived trials that would have long since shattered the souls of even the greatest of the Brotherhood. He readily gave his life at Arthas''s hand, later to be brought back - reborn in the power of the Sunwell.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,9,0, 'In the plaguelands, Kel''Thuzad was again defeated by the agents of the Argent Dawn. However, his phylactery was delivered to a false agent of the brotherhood. We have yet to discover who stole his phylactery or why.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,10,0, 'Pay attention. This is Instructor Razuvious, Kel''Thuzad''s appointed trainer of all death knights. It is said that his own technique is so potent, only a disciple of his could possibly withstand his might.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,11,0, 'Gothik, the Harvester. A master of necromancy and conjuration, Gothik is said to be able to beckon forth legions of the undead at a moment''s notice. It is with his guidance that even the weakest of Death Knights can raise the dead.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,12,0, 'The most powerful Death Knights within Naxxramas are the four horsemen. They represent the pinnacle of Kel''Thuzad''s guard. The first, Thane Korth''azz, holds the power of flame.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,13,0, 'The next, Lady Blaumeux, calls forth the power of shadows, drawing the souls of the living into the voracious embrace.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,14,0, 'Sir Zeliek, a paladin in life, so strong in his faith, that even in undeath, the power of the light still heeds his call, smiting his foes in battle.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,15,0, 'The final Death Knight, Lord Mograine, was the finest warrior that the Death Knights had ever seen. However, after the events in Azeroth, he vanished without a trace. Kel''Thuzad has appointed Baron Rivendare in his place.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,16,0, 'Behold, Patchwerk. When word of his existence first reached the ears of the Brotherhood, none believed the tales of an abomination with such immense speed and strength. Fewer still believed it when he fell the first time...',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,17,0, 'Grobbulus, the first of what was to be an army of flesh giants. It carried the plague slime of Naxxramas within its body, injecting the living ooze into the bodies of its foe. The recipient of this foul injection would usually flee to his allies, bringing them down with him.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,18,0, 'Gluth, the foul plague-dog of Naxxramas, was said to have an appetitie so voracious that even the living were not enough to satisfy his hunger. Feugen was said to feed him an army of Zombies daily, recycling the remains of undead too weak to use in combat.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,19,0, 'Thaddius, built from the flesh of women and children, it is said that their souls are fused together - eternally bound within that foul prison of flesh.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,20,0, 'Anub''Rekhan, one of the finest Spider Lords of Azjol''Nerub, was brought under the control of the Scourge when he and his former commander, Anub''arak, were finally defeated by the Lich King many years ago. It is said that he was the most loyal of Anub''arak''s commanders.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,21,0, 'The Grand Widow Faerlina, a botanist in life, breeder and caretaker of arachnids in death, she oversees the spider wing, developing the most potent of poisons for the Lich King.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,22,0, 'Maexxna, born deep within the mountains of Northrend many ages ago, she was captured within the dread citadel Naxxramas, where she gives birth to her brood, feeding them the corpses of all who dare venture too deeply into Naxxramas.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,23,0, 'Behold, Noth, the Plaguebringer. Responsible for the creation of the process that distills the souls of the living and places them within the cold cage of undeath, Noth was observed to be refining this process even now.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,24,0, 'Observe, Heigan the Unclean. The mastermind behind the plague cauldrons that turned the wilderness of Azeroth into the Plaguelands.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,25,0, 'It is said that Heigan has rigged the very walls and floors of Naxxramas itself with a vast array of traps, which he can trigger at will.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer'),
(27784,26,0, 'Loatheb. The hideous result of fusing the living plague of the plaguelands with the bog beasts of Azeroth, Loatheb is said to control the power of healing itself.',12,7,100,0,0,0, 'Commander Eligor Dawnbringer');

-- 7th Legion Sentinel SAI
SET @ENTRY := 27162;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY) AND `emote`=376;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,258,376, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - On Spawn - Cast Invisibility and Stealth Detection"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Sentinel - In Combat CMC - Cast Shoot"),
(@ENTRY,0,2,0,0,0,100,0,9000,14000,17000,22000,11,49481,1,0,0,0,0,5,0,0,0,0,0,0,0,"7th Legion Sentinel - In Combat - Cast Glaive Throw");

-- Remove some duplicate spawns
DELETE FROM `creature` WHERE `guid` IN (131126, 131132, 131133, 131251, 131253, 131182, 131183, 107389, 107814, 131184, 131249);
DELETE FROM `creature_addon` WHERE `guid` IN (131126, 131132, 131133, 131251, 131253, 131182, 131183, 107389, 107814, 131184, 131249);

-- remove random movement
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid`=133347;

UPDATE `creature` SET `id`=27776 WHERE `guid`=107609;
UPDATE `creature` SET `modelid`=0, `curhealth`=1 WHERE `id` IN (27766,27768,27773,27776,27779);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (27766,27768,27773,27776,27779);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` BETWEEN 27766 AND 27782;
DELETE FROM `creature_template_addon` WHERE `entry` BETWEEN 27766 AND 27782;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES
(27766,0,1),(27767,0,1),(27768,0,1),(27769,0,1),(27770,0,1),(27771,0,1),
(27772,0,1),(27773,0,1),(27774,0,1),(27775,0,1),(27776,0,1),(27777,0,1),
(27778,0,1),(27779,0,1),(27780,0,1),(27781,0,1),(27782,0,1);

-- Commander Eligor Dawnbringer and gang
UPDATE `creature` SET `position_x`=3798.05,`position_y`=-680.611,`position_z`=222.9825, `orientation`=6.038839 WHERE `guid`=133420;
UPDATE `creature` SET `orientation`=3.384053 WHERE `guid`=131157;
UPDATE `creature` SET `orientation`=3.649463 WHERE `guid`=131171;
UPDATE `creature` SET `orientation`=3.633209 WHERE `guid`=133210;
UPDATE `creature` SET `orientation`=1.793558 WHERE `guid`=131154;
UPDATE `creature` SET `orientation`=1.942263 WHERE `guid`=131155;
UPDATE `creature` SET `orientation`=2.368085 WHERE `guid`=131170;
UPDATE `creature` SET `orientation`=2.026036 WHERE `guid`=133225;
UPDATE `creature` SET `orientation`=3.397538 WHERE `guid`=133227;
UPDATE `creature` SET `orientation`=3.839286 WHERE `guid`=131172;
UPDATE `creature` SET `orientation`=2.225338 WHERE `guid`=131173;

-- Condition for spell targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 49519, 0, 0, 31, 0, 3, 23033, 0, 0, 0, 0, '', 'Heroic Image Channel Targets Invisible Stalker (Floating)');

-- Pathing for Invisible Stalker (Floating) Entry: 23033
SET @NPC := 131250;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3804.403,`position_y`=-695.9564,`position_z`=224.0008 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3804.403,-695.9564,224.0008,0,0,0,0,100,0),
(@PATH,2,3805.12,-693.7753,224.1427,0,0,0,0,100,0),
(@PATH,3,3807.3,-691.3777,224.4204,0,0,0,0,100,0),
(@PATH,4,3811.286,-692.7845,224.0623,0,0,0,0,100,0),
(@PATH,5,3813.058,-695.1207,224.999,0,0,0,0,100,0),
(@PATH,6,3813.632,-697.7827,224.9997,0,0,0,0,100,0),
(@PATH,7,3812.425,-700.1073,224.0008,0,0,0,0,100,0),
(@PATH,8,3809.649,-700.7341,224.0008,0,0,0,0,100,0),
(@PATH,9,3805.123,-698.4109,224.0008,0,0,0,0,100,0);

-- Pathing for Invisible Stalker (Floating) Entry: 23033
SET @NPC := 131252;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3804.225,`position_y`=-669.8109,`position_z`=224.8465 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3804.225,-669.8109,224.8465,0,0,0,0,100,0),
(@PATH,2,3806.744,-669.3193,224.8465,0,0,0,0,100,0),
(@PATH,3,3809.637,-670.4093,224.8465,0,0,0,0,100,0),
(@PATH,4,3810.651,-674.6262,224.8465,0,0,0,0,100,0),
(@PATH,5,3808.057,-677.2673,224.8465,0,0,0,0,100,0),
(@PATH,6,3804.191,-676.4904,224.8465,0,0,0,0,100,0),
(@PATH,7,3802.311,-673.4647,224.8465,0,0,0,0,100,0);

-- Pathing for Invisible Stalker (Floating) Entry: 23033
SET @NPC := 133899;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3816.468,`position_y`=-672.7212,`position_z`=224.0009 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3816.468,-672.7212,224.0009,0,0,0,0,100,0),
(@PATH,2,3819.056,-673.5551,222.9989,0,0,0,0,100,0),
(@PATH,3,3820.681,-676.2151,224.0009,0,0,0,0,100,0),
(@PATH,4,3819.998,-679.0777,224.0009,0,0,0,0,100,0),
(@PATH,5,3815.454,-680.2464,224.0009,0,0,0,0,100,0),
(@PATH,6,3813.004,-677.2374,224.0009,0,0,0,0,100,0),
(@PATH,7,3814.027,-673.7756,224.0009,0,0,0,0,100,0);

-- Pathing for Invisible Stalker (Floating) Entry: 23033
SET @NPC := 133894;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3805.747,`position_y`=-687.1393,`position_z`=224.1568 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3805.747,-687.1393,224.1568,0,0,0,0,100,0),
(@PATH,2,3804.891,-684.0416,224.1568,0,0,0,0,100,0),
(@PATH,3,3807.519,-679.4173,224.1568,0,0,0,0,100,0),
(@PATH,4,3811.978,-681.2499,224.1568,0,0,0,0,100,0),
(@PATH,5,3811.325,-686.3337,224.1568,0,0,0,0,100,0),
(@PATH,6,3808.847,-687.7697,224.1568,0,0,0,0,100,0);

-- Pathing for Invisible Stalker (Floating) Entry: 23033
SET @NPC := 133900;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3794.607,`position_y`=-693.5101,`position_z`=224.7538 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3794.607,-693.5101,224.7538,0,0,0,0,100,0),
(@PATH,2,3794.899,-689.9442,224.7538,0,0,0,0,100,0),
(@PATH,3,3798.899,-687.9035,224.7538,0,0,0,0,100,0),
(@PATH,4,3802.577,-690.2576,224.7538,0,0,0,0,100,0),
(@PATH,5,3801.8,-694.2828,224.7538,0,0,0,0,100,0),
(@PATH,6,3797.656,-695.3698,224.7538,0,0,0,0,100,0);
