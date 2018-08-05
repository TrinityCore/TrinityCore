SET @QUEST_FROSTMANE_AGGRESSION          := 25724;
SET @NPC_MOUNTAINEER_DUNSTAN             := 40991;
SET @NPC_MOUNTAINEER_LEWAN               := 40994;
SET @NPC_MOUNTAINEER_VALGRUM             := 41056;

-- fix up quest pushing forward (25792)
SET @SPELL_BURN_CONSTRICTION_TOTEM          := 77314;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (@SPELL_BURN_CONSTRICTION_TOTEM);
INSERT INTO `spell_script_names` 
    (`spell_id`, `ScriptName`)
 VALUES
 (77314,'spell_burn_constriction_totem');

-- hostile creatures
UPDATE `creature_template`
SET `faction` = 7
WHERE `entry` IN (@NPC_MOUNTAINEER_DUNSTAN,@NPC_MOUNTAINEER_LEWAN,@NPC_MOUNTAINEER_VALGRUM); 

-- update conditions for text 
DELETE FROM `conditions`
WHERE `SourceGroup` IN (11455,11456,11457);

INSERT INTO `conditions`
(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,
`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(15,11455,0,0,0,9,0,313,0,0,0,0,0,'','Only show if on quest forced to watch from afar'),
(15,11456,0,0,0,9,0,313,0,0,0,0,0,'','Only show if on quest forced to watch from afar'),
(15,11457,0,0,0,9,0,313,0,0,0,0,0,'','Only show if on quest forced to watch from afar');


DELETE FROM `conditions`
WHERE (`SourceEntry` = 24493 AND `ConditionValue1` = 24492);

INSERT INTO `conditions`
(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,
`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(19,0,24493,0,0,8,0,24492,0,0,0,0,0,'','Needed to allow quest to complete');

 
-- stop personell mover from moving
 UPDATE creature
 SET spawndist = 0,
 MovementType = 0
 WHERE id = 41398;
 

 -- fix flying machines, repaired bomber and chicken, and launcher
DELETE FROM `npc_spellclick_spells`
WHERE `npc_entry` IN (53568,41848,42175,42092,41398);

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(53568, 99486, 3, 0), 
(41848, 78025, 3, 0),
(42175, 78680, 3, 0),
(41398, 77393, 3, 0),
(42092, 78510, 3, 0);



UPDATE `creature_template` SET `npcflag` = `npcflag` | 16777216,
AIName = ''
WHERE `entry` IN (42175,41848,42092,41398);

 
UPDATE `creature_template`
SET `ScriptName` = 'npc_frostmane_builder'
WHERE `entry` = 41251;

UPDATE `creature_template` SET `InhabitType` = 4, `ScriptName` = 'npc_flying_machine' WHERE `entry` = 41382;


DELETE FROM `creature_template_addon` WHERE `entry` = 41382;
INSERT INTO `creature_template_addon`
    (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`)
VALUES
    (41382, 0, 22719, 50331648, 1, 0, 0, 0, 0, '');

DELETE FROM `spell_script_names` WHERE `spell_id` = 77477;
INSERT INTO `spell_script_names` 
    (`spell_id`, `ScriptName`)
 VALUES
    (77477, 'spell_missile_barrage');

SET @SPELL_SIGNAL_FLARE            := 77488;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (@SPELL_SIGNAL_FLARE);
INSERT INTO `spell_script_names` 
    (`spell_id`, `ScriptName`)
 VALUES
    (@SPELL_SIGNAL_FLARE, 'spell_signal_flare');


UPDATE `creature`
SET `zoneId` = 1
WHERE `id` IN (41372,41373);

DELETE FROM `spell_script_names` WHERE `spell_id` = 80464;
INSERT INTO `spell_script_names` 
    (`spell_id`, `ScriptName`)
 VALUES
    (80464, 'spell_emote_stolen_ram');

UPDATE `creature_template` SET `ScriptName` = 'npc_stolen_ram' WHERE `entry` = 41539;

SET @SPELL_EXTINGUISH_FIRE          := 78369;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (@SPELL_EXTINGUISH_FIRE);
INSERT INTO `spell_script_names` 
    (`spell_id`, `ScriptName`)
 VALUES
 (78369,'spell_extinguish_fire');

-- burning bomber credit fixes
 UPDATE `creature_template`
 SET `unit_flags3`=0,
 unit_flags = 33555200,
 unit_flags2 = 2048,
 modelid1 =11686,
 modelid2 = 0,
 flags_extra = 130
 WHERE `entry`= 42046;
 
 UPDATE creature
 SET spawndist = 0,
 modelid = 0,
 MovementType = 0,
  unit_flags = 33555200,
 unit_flags2 = 2048 
 WHERE id = 42046;

 
-- only cast spell when the loose snow is nearby 
DELETE FROM `conditions` WHERE `SourceEntry` = 78395;
INSERT INTO `conditions`
    (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
    (13, 3, 78395, 0, 0, 31, 0, 5, 203452, 0, 0, 0, 0, '', 'Plant Ironforge Banner Target');

	
-- update model for Forgotton dwarven artifact
UPDATE gameobject_template
SET displayId = 6420
WHERE entry = 201608;	
	
-- delete deprecated quests
DELETE FROM `creature_queststarter`
WHERE `quest` IN (24531,3108,3109,24532,24528);

DELETE FROM `creature_questender`
WHERE `quest` IN (24531,3108,3109,24532,24528);	
	
-- fix up vendor duncan farcutter
UPDATE `gossip_menu_option`
SET `OptionType` = 3,
`OptionNpcFlag` = 128
WHERE `MenuId` = 1262
AND `OptionIndex` = 0;

-- fix up Grundel Harkin vendor
UPDATE creature_template
SET gossip_menu_id = 1262
WHERE entry = 1104;

-- fix up vendor loslor rudge
UPDATE `gossip_menu_option`
SET `OptionType` = 3,
`OptionNpcFlag` = 128
WHERE `MenuId` = 3501
AND `OptionIndex` = 0;

-- sniffs for general grimaxe
UPDATE creature_template_addon
SET `auras` = 46598
WHERE entry = 42010;

-- double spawn general grimaxe
DELETE FROM `creature`
WHERE `guid` = 181733;

-- general grimaxe not attackable
UPDATE `creature_template`
SET `unit_flags` = 0
WHERE `entry` = 42010;
	
-- remove 41603 frostmane raider incorrect spawn
DELETE FROM `creature`
WHERE `guid` = 170355;

-- rams on the lamb
UPDATE `creature_template`
SET `ScriptName` = 'npc_sergeant_flinthammer'
WHERE `entry` = 41578;


UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Ah, $n.  Have you returned from Ironforge?', `VerifiedBuild`=24742 WHERE `ID`=6392; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=24742 WHERE `ID`=6388; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `VerifiedBuild`=24742 WHERE `ID`=6391; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=24742 WHERE `ID`=25997; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=24742 WHERE `ID`=25937; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=20, `VerifiedBuild`=24742 WHERE `ID`=314; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `VerifiedBuild`=24742 WHERE `ID`=412; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=24742 WHERE `ID`=25668; -- -Unknown-
UPDATE `quest_request_items` SET `CompletionText`='I''m going to need those crag boar ribs and a mug of Rhapsody Malt, $n.', `VerifiedBuild`=24742 WHERE `ID`=384; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=24742 WHERE `ID`=26380; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=24742 WHERE `ID`=315; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=24742 WHERE `ID`=6387; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=24742 WHERE `ID`=24492; -- -Unknown-
UPDATE `quest_request_items` SET `CompletionText`='$n! Any luck?', `VerifiedBuild`=24742 WHERE `ID`=218; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=24742 WHERE `ID`=3361; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=24742 WHERE `ID`=24486; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=24742 WHERE `ID`=24486; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=24742 WHERE `ID`=24475; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=24742 WHERE `ID`=24477; -- -Unknown-
UPDATE `quest_request_items` SET `EmoteOnComplete`=22, `VerifiedBuild`=24742 WHERE `ID`=24474; -- -Unknown-


DELETE FROM `creature_template_addon` WHERE `entry` IN (96490 /*96490 (Krimple Proxmeasure)*/, 118889 /*118889 (Corin Twinbellows) - -Unknown-*/, 62425 /*62425 (Liu of the Bottomless Tankard)*/, 61317 /*61317 (Long-tailed Mole)*/, 1130 /*1130 (Bjarn)*/, 41603 /*41603 (Frostmane Raider)*/, 51912 /*51912 (Dun Morogh Mountaineer)*/, 63285 /*63285 (Lo) - -Unknown-*/, 63075 /*63075 (Grady Bannson)*/, 63074 /*63074 (Fluffy)*/, 61690 /*61690 (Alpine Hare)*/, 61689 /*61689 (Snow Cub)*/, 122323 /*122323 (VFX Bunny)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(96490, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 96490 (Krimple Proxmeasure)
(118889, 0, 0, 0, 1, 0, 0, 0, 0, '235614'), -- 118889 (Corin Twinbellows) - -Unknown-
(62425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 62425 (Liu of the Bottomless Tankard)
(61317, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61317 (Long-tailed Mole)
(1130, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 1130 (Bjarn)
(41603, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 41603 (Frostmane Raider)
(51912, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 51912 (Dun Morogh Mountaineer)
(63285, 0, 0, 0, 1, 0, 0, 0, 0, '118348'), -- 63285 (Lo) - -Unknown-
(63075, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63075 (Grady Bannson)
(63074, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63074 (Fluffy)
(61690, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61690 (Alpine Hare)
(61689, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61689 (Snow Cub)
(122323, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- 122323 (VFX Bunny)

UPDATE `creature_template_addon` SET `auras`='98892 61574' WHERE `entry`=31144; -- 31144 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='61574 98892' WHERE `entry`=32666; -- 32666 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 61574' WHERE `entry`=31146; -- 31146 (Raider's Training Dummy)
UPDATE `creature_template_addon` SET `auras`='61574 98892' WHERE `entry`=32667; -- 32667 (Training Dummy)
UPDATE `creature_template_addon` SET `mount`=29258 WHERE `entry`=50309; -- 50309 (Captain Stonehelm)
UPDATE `creature_template_addon` SET `mount`=28571 WHERE `entry`=50308; -- 50308 (Master Tinker Trini)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=42010; -- 42010 (General Grimaxe)
UPDATE `creature_template_addon` SET `auras`='8258' WHERE `entry`=41897; -- 41897 (Dun Morogh Mountaineer)
UPDATE `creature_template_addon` SET `auras`='8258' WHERE `entry`=41909; -- 41909 (Airfield Guard)
UPDATE `creature_template_addon` SET `auras`='9036 10848' WHERE `entry`=6491; -- 6491 (Spirit Healer)
UPDATE `creature_template_addon` SET `auras`='77910' WHERE `entry`=41763; -- 41763 (Frozen Mountaineer)
UPDATE `creature_template_addon` SET `auras`='16245 77885' WHERE `entry`=41761; -- 41761 (Water Spout)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=47395; -- 47395 (Injured Miner)
UPDATE `creature_template_addon` SET `mount`=10003 WHERE `entry`=41544; -- 41544 (Frostmane Raider)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=41366; -- 41366 (Warstrider Cannon)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=41122; -- 41122 (Frostmane Snowstrider)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=43273; -- 43273 (Ammo Cart)
UPDATE `creature_template_addon` SET `auras`='46598 80855 16245' WHERE `entry`=43279; -- 43279 (Ammo Cart Bunny)
UPDATE `creature_template_addon` SET `auras`='56384' WHERE `entry`=1228; -- 1228 (Magis Sparkmantle)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=1226; -- 1226 (Maxan Anvol)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=41335; -- 41335 (Covert Operative)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=10804; -- 10804 (Rifleman Middlecamp)
UPDATE `creature_template_addon` SET `bytes1`=65536, `auras`='70045' WHERE `entry`=37169; -- 37169 (Milo's Gyro)
UPDATE `creature_template_addon` SET `bytes1`=65536 WHERE `entry`=37113; -- 37113 (Milo Geartwinge)
UPDATE `creature_template_addon` SET `auras`='56384' WHERE `entry`=37121; -- 37121 (Teegli Merrowith)
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=37177; -- 37177 (Coldridge Defender)
UPDATE `creature_template_addon` SET `auras`='76143' WHERE `entry`=37080; -- 37080 (Wounded Coldridge Mountaineer)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=43224; -- 43224 (Wounded Mountaineer)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=41181; -- 41181 (Kharanos Mountaineer)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=727; -- 727 (Ironforge Mountaineer)


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=96490 AND `ID`=1) OR (`CreatureID`=41251 AND `ID`=2) OR (`CreatureID`=41122 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(96490, 1, 3699, 0, 0, 0, 0, 0, 0, 0, 0), -- Krimple Proxmeasure
(41251, 2, 1938, 0, 0, 0, 0, 0, 0, 0, 0), -- Frostmane Builder
(41122, 2, 3350, 0, 0, 0, 0, 0, 0, 0, 0); -- Frostmane Snowstrider

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=5166 AND `ID`=1); -- Ormyr Flinteye
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=1701 AND `ID`=1); -- Dank Drizzlecut
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=41258 AND `ID`=1); -- Frostmane Warrior
UPDATE `creature_equip_template` SET `ItemID1`=55990 WHERE (`CreatureID`=41251 AND `ID`=1); -- Frostmane Builder
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=1228 AND `ID`=1); -- Magis Sparkmantle
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=1234 AND `ID`=1); -- Hogral Bakkan
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=1226 AND `ID`=1); -- Maxan Anvol
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=49748 AND `ID`=1); -- Hero's Herald


UPDATE `points_of_interest` SET `PositionX`=-4719.61, `PositionY`=-1056.97, `Name`='Stonebrow''s Clothier', `VerifiedBuild`=24742 WHERE `ID`=48;
UPDATE `points_of_interest` SET `PositionX`=-4745.01, `PositionY`=-1027.58, `Name`='Finespindle''s Leather Goods', `VerifiedBuild`=24742 WHERE `ID`=47;
UPDATE `points_of_interest` SET `PositionX`=-4705.06, `PositionY`=-1116.43, `Name`='Deepmountain Mining & Jewelcrafting', `VerifiedBuild`=24742 WHERE `ID`=46;
UPDATE `points_of_interest` SET `PositionX`=-4745.01, `PositionY`=-1027.58, `Name`='Finespindle''s Leather Goods', `VerifiedBuild`=24742 WHERE `ID`=45;
UPDATE `points_of_interest` SET `PositionX`=-4745.01, `PositionY`=-1027.58, `Name`='Finespindle''s Leather Goods', `VerifiedBuild`=24742 WHERE `ID`=44;
UPDATE `points_of_interest` SET `PositionX`=-4705.06, `PositionY`=-1116.43, `Name`='Deepmountain Mining & Jewelcrafting', `VerifiedBuild`=24742 WHERE `ID`=43;
UPDATE `points_of_interest` SET `PositionX`=-4801.79, `PositionY`=-1189.09, `Name`='Ironforge Inscription', `VerifiedBuild`=24742 WHERE `ID`=42;
UPDATE `points_of_interest` SET `PositionX`=-4881.6, `PositionY`=-1153.13, `Name`='Ironforge Physician', `VerifiedBuild`=24742 WHERE `ID`=41;
UPDATE `points_of_interest` SET `PositionX`=-4597.91, `PositionY`=-1091.93, `Name`='Traveling Fisherman', `VerifiedBuild`=24742 WHERE `ID`=40;
UPDATE `points_of_interest` SET `PositionX`=-4881.6, `PositionY`=-1153.13, `Name`='Ironforge Physician', `VerifiedBuild`=24742 WHERE `ID`=39;
UPDATE `points_of_interest` SET `PositionX`=-4799.56, `PositionY`=-1250.24, `Name`='Springspindle''s Gadgets', `VerifiedBuild`=24742 WHERE `ID`=38;
UPDATE `points_of_interest` SET `PositionX`=-4803.72, `PositionY`=-1196.53, `Name`='Thistlefuzz Arcanery', `VerifiedBuild`=24742 WHERE `ID`=37;
UPDATE `points_of_interest` SET `PositionX`=-4803.72, `PositionY`=-1196.53, `Name`='Thistlefuzz Arcanery', `VerifiedBuild`=24742 WHERE `ID`=36;
UPDATE `points_of_interest` SET `PositionX`=-4767.83, `PositionY`=-1184.6, `Name`='The Bronze Kettle', `VerifiedBuild`=24742 WHERE `ID`=35;
UPDATE `points_of_interest` SET `PositionX`=-4796.98, `PositionY`=-1110.17, `Name`='The Great Forge', `VerifiedBuild`=24742 WHERE `ID`=34;
UPDATE `points_of_interest` SET `PositionX`=-4627.94, `PositionY`=-1311.17, `Name`='Ironforge Archaeology', `VerifiedBuild`=24742 WHERE `ID`=33;
UPDATE `points_of_interest` SET `PositionX`=-4858.5, `PositionY`=-1241.84, `Name`='Berryfizz''s Potions and Mixed Drinks', `VerifiedBuild`=24742 WHERE `ID`=32;
UPDATE `points_of_interest` SET `PositionX`=-4849.077, `PositionY`=-867.3924, `Name`='Ironforge Monk Trainer', `VerifiedBuild`=24742 WHERE `ID`=31;
UPDATE `points_of_interest` SET `PositionX`=-4722.59, `PositionY`=-1151.39, `Name`='Ironforge Shaman Trainer', `VerifiedBuild`=24742 WHERE `ID`=30;
UPDATE `points_of_interest` SET `PositionX`=-5023.08, `PositionY`=-1253.68, `Name`='Hall of Arms', `VerifiedBuild`=24742 WHERE `ID`=29;
UPDATE `points_of_interest` SET `PositionX`=-4605.03, `PositionY`=-1110.46, `Name`='Ironforge Warlock Trainer', `VerifiedBuild`=24742 WHERE `ID`=28;
UPDATE `points_of_interest` SET `PositionX`=-4647.83, `PositionY`=-1124, `Name`='Ironforge Rogue Trainer', `VerifiedBuild`=24742 WHERE `ID`=27;
UPDATE `points_of_interest` SET `PositionX`=-4627.02, `PositionY`=-926.459, `Name`='Hall of Mysteries', `VerifiedBuild`=24742 WHERE `ID`=26;
UPDATE `points_of_interest` SET `PositionX`=-4627.02, `PositionY`=-926.459, `Flags`=99, `Name`='Hall of Mysteries', `VerifiedBuild`=24742 WHERE `ID`=25;
UPDATE `points_of_interest` SET `PositionX`=-4627.02, `PositionY`=-926.459, `Name`='Hall of Mysteries', `VerifiedBuild`=24742 WHERE `ID`=24;
UPDATE `points_of_interest` SET `PositionX`=-5023.08, `PositionY`=-1253.68, `Name`='Hall of Arms', `VerifiedBuild`=24742 WHERE `ID`=23;
UPDATE `points_of_interest` SET `PositionX`=-5081.342, `PositionY`=-780.4653, `Name`='Ironforge Druid Trainer', `VerifiedBuild`=24742 WHERE `ID`=22;
UPDATE `points_of_interest` SET `PositionX`=-4839.48, `PositionY`=-917.295, `Name`='Ironforge Barber', `VerifiedBuild`=24742 WHERE `ID`=21;
UPDATE `points_of_interest` SET `PositionX`=-5042.66, `PositionY`=-1269.78, `Flags`=99, `Name`='Battlemasters Ironforge', `VerifiedBuild`=24742 WHERE `ID`=20;
UPDATE `points_of_interest` SET `PositionX`=-5010.21, `PositionY`=-1262.03, `Name`='Ulbrek Firehand', `VerifiedBuild`=24742 WHERE `ID`=19;
UPDATE `points_of_interest` SET `PositionX`=-4845.7, `PositionY`=-880.552, `Name`='Ironforge Mailbox', `VerifiedBuild`=24742 WHERE `ID`=18;
UPDATE `points_of_interest` SET `PositionX`=-4850.48, `PositionY`=-872.571, `Name`='Stonefire Tavern', `VerifiedBuild`=24742 WHERE `ID`=17;
UPDATE `points_of_interest` SET `PositionX`=-5021.06, `PositionY`=-996.453, `Name`='Ironforge Visitor''s Center', `VerifiedBuild`=24742 WHERE `ID`=16;
UPDATE `points_of_interest` SET `PositionX`=-4821.52, `PositionY`=-1152.3, `Name`='Ironforge Gryphon Master', `VerifiedBuild`=24742 WHERE `ID`=15;
UPDATE `points_of_interest` SET `PositionX`=-4836.15, `PositionY`=-1301.33, `Name`='Ironforge Tram Entrance', `VerifiedBuild`=24742 WHERE `ID`=14;
UPDATE `points_of_interest` SET `PositionX`=-4891.91, `PositionY`=-991.48, `Name`='The Vault', `VerifiedBuild`=24742 WHERE `ID`=13;
UPDATE `points_of_interest` SET `PositionX`=-4957.39, `PositionY`=-911.604, `Name`='Ironforge Auction House', `VerifiedBuild`=24742 WHERE `ID`=12;
UPDATE `points_of_interest` SET `PositionX`=-5605.01, `PositionY`=-530.145, `Name`='Granis Swiftaxe', `VerifiedBuild`=24742 WHERE `ID`=11;
UPDATE `points_of_interest` SET `PositionX`=-5639.5, `PositionY`=-528.501, `Name`='Gimrizz Shadowcog', `VerifiedBuild`=24742 WHERE `ID`=10;
UPDATE `points_of_interest` SET `PositionX`=-5581.787, `PositionY`=-535.559, `Name`='Halbin Frosthammer', `VerifiedBuild`=24742 WHERE `ID`=9;
UPDATE `points_of_interest` SET `PositionX`=-5604.48, `PositionY`=-540.089, `Name`='Hogral Bakkan', `VerifiedBuild`=24742 WHERE `ID`=8;
UPDATE `points_of_interest` SET `PositionX`=-5589.19, `PositionY`=-530.288, `Name`='Maxan Anvol', `VerifiedBuild`=24742 WHERE `ID`=7;
UPDATE `points_of_interest` SET `PositionX`=-5584.69, `PositionY`=-542.492, `Name`='Azar Stronghammer', `VerifiedBuild`=24742 WHERE `ID`=6;
UPDATE `points_of_interest` SET `PositionX`=-5587.37, `PositionY`=-539.037, `Name`='Magis Sparkmantle', `VerifiedBuild`=24742 WHERE `ID`=5;
UPDATE `points_of_interest` SET `PositionX`=-5618.73, `PositionY`=-453.72, `Name`='Grif Wildheart', `VerifiedBuild`=24742 WHERE `ID`=4;
UPDATE `points_of_interest` SET `PositionX`=-5637.168, `PositionY`=-497.8038, `Name`='Wembil Taskwidget', `VerifiedBuild`=24742 WHERE `ID`=3;
UPDATE `points_of_interest` SET `PositionX`=-5606.17, `PositionY`=-513.008, `Name`='Shelby Stoneflint', `VerifiedBuild`=24742 WHERE `ID`=2;
UPDATE `points_of_interest` SET `PositionX`=-5584.11, `PositionY`=-510.862, `Name`='Thunderbrew Distillery', `VerifiedBuild`=24742 WHERE `ID`=1;

DELETE FROM `creature_text` WHERE `CreatureID` IN
(706,808,1115,1119,1263,1360,1378,5595,6123,6782,37073,37080,37081,37108,37112,37173,37174,37507,37518,40950,40951,
40991,40994,41056,41121,41237,41251,41335,41578,41603,41611,41671,41763,42010,42129,42131,42153,42928);

INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(706, 0, 0, 'Killing you be easy.', 12, 0, 100, 0, 0, 0, 1909, 'Frostmane Troll Whelp to Player'),
(706, 1, 0, 'My weapon be thirsty!', 12, 0, 100, 0, 0, 0, 1908, 'Frostmane Troll Whelp to Player'),
(808, 0, 0, 'First da fire, and now da $r!  You gonna die!', 12, 0, 100, 0, 0, 0, 36953, 'Grik''nir the Cold to Player'),
(1115, 0, 0, 'Crush!', 12, 7, 100, 0, 0, 0, 1913, 'Rockjaw Skullthumper to Player'), -- BroadcastTextID: 1913 - 40182
(1115, 1, 0, 'Kill!', 12, 7, 100, 0, 0, 0, 1914, 'Rockjaw Skullthumper to Player'), -- BroadcastTextID: 1914 - 29607 - 30905 - 76121 - 87849 - 95337
(1119, 0, 0, 'I smell a $R', 12, 0, 100, 0, 0, 0, 1916, 'Hammerspine to Player'),
(1119, 1, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 1191, 'Hammerspine'), -- BroadcastTextID: 1191 - 2384 - 10645 - 36719 - 38630
(1263, 0, 0, 'Why do you run from me, Fluffy?!', 12, 6, 100, 0, 0, 0, 160, 'Yarlyn Amberstill'),
(1263, 1, 0, 'Come back, Fluffy!', 12, 6, 100, 0, 0, 0, 159, 'Yarlyn Amberstill'),
(1263, 2, 0, 'Carrots every day for a year if you stop!', 12, 6, 100, 0, 0, 0, 164, 'Yarlyn Amberstill'),
(1263, 3, 0, 'C''mon, Fluffy! I just want to give you a bath!', 12, 6, 100, 0, 0, 0, 161, 'Yarlyn Amberstill'),
(1360, 0, 0, 'I''ll take whatever ya got cookin''! And throw in a bottle to wash it down!', 12, 6, 100, 0, 0, 0, 124, 'Miner Grumnal'),
(1378, 0, 0, 'C''mon, let''s get you another ale.', 12, 0, 100, 5, 0, 0, 43204, 'Pilot Bellowfiz'),
(5595, 0, 0, 'Glad to see that Dark Iron scum is finally getting what he deserves!', 12, 0, 100, 25, 0, 0, 42039, 'Ironforge Guard to Ambassador Slaghammer'),
(5595, 1, 0, 'Quiet! Moira''s in a foul mood and if she hears you, she''ll have your head...', 12, 0, 100, 5, 0, 0, 42040, 'Ironforge Guard to Ambassador Slaghammer'),
(5595, 2, 0, 'I''ll escort you to your new ''accommodations'', Your Excellency.', 12, 0, 100, 1, 0, 0, 42048, 'Ironforge Guard to Arrest the Ambassador Credit'),
(6123, 0, 0, 'Time to die, $C.', 12, 0, 100, 0, 0, 0, 1935, 'Dark Iron Spy to Player'),
(6123, 1, 0, 'Never cross a Dark Iron, $C.', 12, 0, 100, 0, 0, 0, 1934, 'Dark Iron Spy to Player'),
(6782, 0, 0, 'Alright, so you''re just going to head through this tunnel and whaaaaa....?', 12, 0, 100, 0, 0, 12549, 37003, 'Hands Springsprocket to Player'),
(37073, 0, 0, 'You break our cave, I break your skull!', 12, 0, 100, 0, 0, 0, 36904, 'Rockjaw Goon to Player'),
(37073, 1, 0, 'Trogg cave all gone!  You pay for this!!', 12, 0, 100, 36, 0, 0, 36905, 'Rockjaw Goon to Player'),
(37080, 0, 0, 'Ahh, much better.  I owe ya one.', 12, 7, 100, 0, 0, 0, 36984, 'Wounded Coldridge Mountaineer to Player'),
(37080, 1, 0, 'Thanks!  I can make it from here.', 12, 7, 100, 0, 0, 0, 36982, 'Wounded Coldridge Mountaineer to Player'),
(37080, 2, 0, 'Yer a lifesaver!  For Ironforge!', 12, 7, 100, 0, 0, 0, 36983, 'Wounded Coldridge Mountaineer to Player'),
(37081, 0, 0, 'Eat dwarven lead!', 12, 0, 100, 0, 0, 0, 37008, 'Joren Ironstock to Rockjaw Invader'),
(37081, 1, 0, 'Get back, ye filthy beast!', 12, 0, 100, 0, 0, 0, 37007, 'Joren Ironstock to Rockjaw Invader'),
(37081, 2, 0, 'For Ironforge!', 12, 0, 100, 0, 0, 0, 37009, 'Joren Ironstock to Rockjaw Invader'),
(37108, 0, 0, 'Da spirits be angry with us.', 12, 0, 100, 0, 0, 0, 36962, 'Soothsayer Shi''kala to Player'),
(37108, 1, 0, 'I don'' know why the spirits be rejectin'' us so.', 12, 0, 100, 0, 0, 0, 36958, 'Soothsayer Shi''kala to Player'),
(37108, 2, 0, 'Don'' worry, child.  Grik''nir gonna help us get through this.', 12, 0, 100, 0, 0, 0, 36959, 'Soothsayer Shi''kala to Player'),
(37112, 0, 0, 'T ma toro nuk krast''ven fmerk ', 14, 12, 100, 0, 0, 0, 0, 'Wayward Fire Elemental'),
(37112, 1, 0, 'T MA TORO NUK KRAST''VEN FMERK ', 12, 12, 100, 0, 0, 0, 0, 'Wayward Fire Elemental to Player'),
(37173, 0, 0, 'What we gon'' do now, you ask?  We wait.', 12, 0, 100, 0, 0, 0, 36957, 'Soothsayer Rikkari to Player'),
(37173, 1, 0, 'Grik''nir says he gon'' talk to the elemental, get it to fight on our side.', 12, 0, 100, 0, 0, 0, 36960, 'Soothsayer Rikkari to Player'),
(37173, 2, 0, 'Soon enough we take over dis valley.  Soon enough.', 12, 0, 100, 0, 0, 0, 36961, 'Soothsayer Rikkari to Player'),
(37174, 0, 0, 'Our land be a land of ice an'' snow.', 12, 0, 100, 0, 0, 0, 36963, 'Soothsayer Mirim''koa to Player'),
(37174, 1, 0, 'But beneath the earth, child, there always be fire.', 12, 0, 100, 0, 0, 0, 36964, 'Soothsayer Mirim''koa to Player'),
(37174, 2, 0, 'De spirit come from deep down to talk with Grik''nir.', 12, 0, 100, 0, 0, 0, 36965, 'Soothsayer Mirim''koa to Player'),
(37507, 0, 0, 'I gonna make you into mojo!', 12, 0, 100, 0, 0, 0, 10435, 'Frostmane Blade to Player'),
(37518, 0, 0, '<Static>$bIs this thing on?  Hello?', 12, 7, 100, 0, 0, 0, 37115, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 1, 0, 'Ahh, there you are.  Hello!  I figured that, while you''re flying to Kharanos, I''d give you some data about what''s going on outside of Coldridge Valley.', 12, 7, 100, 0, 0, 0, 37117, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 2, 0, 'It seems you Coldridge folks are dreadfully under-informed about the events of the last few days.', 12, 7, 100, 0, 0, 0, 37118, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 3, 0, 'If you thought you had problems with trolls in Coldridge, wait ''til you get to Kharanos!  That big cataclysm got the trolls all stirred up out here.', 12, 7, 100, 0, 0, 0, 37119, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 4, 0, 'And if you''ll look to your left, you''ll see that the gnomes have retaken Gnomeregan.  Hooray for us!', 12, 7, 100, 0, 0, 0, 43112, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 5, 0, 'There''s plenty else going on out here, too.  We''ve opened up the path to the airport, there''s rumors of Dark Irons in the east... oh, and I think something weird is going on with that dwarf king, Magni.  Might want to check it out.', 12, 7, 100, 0, 0, 0, 43113, 'Milo Geartwinge to Milo''s Gyro'),
(37518, 6, 0, 'And here we are!  Welcome to Kharanos!  Watch your step on the way out.', 12, 7, 100, 0, 0, 0, 43115, 'Milo Geartwinge to Milo''s Gyro'),
(40950, 0, 0, 'We''re getting bogged down in the fight against the Frostmane trolls.', 12, 0, 100, 5, 0, 0, 43235, 'Captain Tharran'),
(40950, 1, 0, 'Most of our steam tanks are out of commission and we''re losing mountaineers quickly.', 12, 0, 100, 5, 0, 0, 43236, 'Captain Tharran'),
(40950, 2, 0, 'We can''t keep up the operation much longer. Delber and his team must launch their attack from Steelgrill''s Depot as soon as possible!', 12, 0, 100, 6, 0, 0, 43243, 'Captain Tharran'),
(40950, 3, 0, 'Glad to hear it. I''ll send Delber any forces I can spare.', 12, 0, 100, 273, 0, 0, 43253, 'Captain Tharran'),
(40950, 4, 0, 'There''s no substitute for live observers, but I need those mountaineers here. We''ll have to rely on those little gnomish observer bots for now...', 12, 0, 100, 6, 0, 0, 43522, 'Captain Tharran to Player'),
(40951, 0, 0, 'It won''t be long before we''re out of supplies too, Captain. Between the trolls and the yeti raids, we''ll be down to half rations within a week.', 12, 0, 100, 1, 0, 0, 43242, 'Quartermaster Glynna to Captain Tharran'),
(40991, 0, 0, 'Tell Captain Tharran that I''ll be back in Kharanos as soon as I''ve verified that the bot is working correctly.', 12, 0, 100, 66, 0, 0, 41005, 'Mountaineer Dunstan to Player'),
(40994, 0, 0, 'I can''t wait to get out there and help in the fight against those trolls.', 12, 0, 100, 66, 0, 0, 41006, 'Mountaineer Lewin to Player'),
(41056, 0, 0, 'We''ve been fighting nonstop since the cataclysm. It''ll be nice to get a rest, if a brief one.', 12, 0, 100, 66, 0, 0, 41008, 'Mountaineer Valgrum to Player'),
(41121, 0, 0, 'Iman m t''ief fu Fus''obeah italaf ', 12, 14, 100, 0, 0, 0, 0, 'Frostmane Seer to Player'),
(41237, 0, 0, '%s gasps for air.', 16, 0, 100, 0, 0, 0, 29786, 'Kharanos Mountaineer to Constriction Totem'), -- BroadcastTextID: 29786 - 37502 - 41180
(41237, 1, 0, 'Thank you for freeing me!', 12, 0, 100, 5, 0, 0, 41181, 'Kharanos Mountaineer to Constriction Totem'),
(41251, 0, 0, 'Can''t... lift... tools...', 12, 0, 100, 15, 0, 0, 50318, 'Frostmane Builder to Player'),
(41251, 1, 0, 'Take curse away!', 12, 0, 100, 5, 0, 0, 50649, 'Frostmane Builder to Player'),
(41251, 2, 0, 'Why everyone else get so big?', 12, 0, 100, 6, 0, 0, 50322, 'Frostmane Builder to Player'),
(41251, 3, 0, 'No make me small!', 12, 0, 100, 15, 0, 0, 50321, 'Frostmane Builder to Player'),
(41335, 0, 0, 'Delber and his men are working overtime, captain. He has devised a means of delivering an assault team to the rear flank of the battle.', 12, 0, 100, 1, 0, 0, 43245, 'Covert Operative to Captain Tharran'),
(41335, 1, 0, 'We''ve also secured air support for the operation and will be ready to deploy soon. If any of your men want to join the assault team, just send them to Delber.', 12, 0, 100, 1, 0, 0, 43248, 'Covert Operative to Captain Tharran'),
(41578, 0, 0, 'The Frostmane trolls have been raiding the ranch continuously.', 12, 0, 100, 6, 0, 0, 41525, 'Sergeant Flinthammer to Player'),
(41578, 1, 0, 'As it is, there are barely enough of us to keep them from taking everything.', 12, 0, 100, 5, 0, 0, 41526, 'Sergeant Flinthammer to Player'),
(41578, 2, 0, 'They just take the rams and go. The herd can''t take any more.', 12, 0, 100, 1, 0, 0, 41527, 'Sergeant Flinthammer to Player'),
(41578, 3, 0, 'One of the mountaineers has seen something. Keep your eyes open!', 14, 0, 100, 25, 0, 0, 41528, 'Sergeant Flinthammer to Player'),
(41603, 0, 0, 'If you want your rams back, come get them, cowards!', 14, 0, 100, 15, 0, 0, 41519, 'Frostmane Raider to Player'),
(41611, 0, 0, 'Does anyone hear something strange?', 12, 0, 100, 6, 0, 0, 41521, 'Amberstill Mountaineer to Player'),
(41611, 1, 0, 'There it is again! I know I heard something!', 12, 0, 100, 5, 0, 0, 41522, 'Amberstill Mountaineer to Player'),
(41611, 2, 0, 'Frostmane raiders! Sound the alarm!', 14, 0, 100, 5, 0, 7234, 41523, 'Amberstill Mountaineer to Player'),
(41611, 3, 0, 'To arms, mountaineers! Take back those rams!', 14, 0, 100, 25, 0, 0, 41524, 'Amberstill Mountaineer to Player'),
(41671, 0, 0, 'Thank you!', 12, 0, 100, 2, 0, 0, 18708, 'Trapped Miner to Player'), -- BroadcastTextID: 18708 - 18709 - 27898 - 35230 - 37121 - 37237 - 41471 - 41477 - 41537 - 58873 - 75228 - 81301 - 84724 - 84764 - 96436 - 101019 - 122116 - 131553
(41671, 1, 0, 'I can''t wait to get home to my family. Thank you, stranger.', 12, 0, 100, 2, 0, 0, 41542, 'Trapped Miner to Player'),
(41671, 2, 0, 'Light bless you, stranger. You''ve saved me!', 12, 0, 100, 2, 0, 0, 41540, 'Trapped Miner to Player'),
(41671, 3, 0, 'You''re the best thing I''ve seen since the troggs showed up!', 12, 0, 100, 2, 0, 0, 41541, 'Trapped Miner to Player'),
(41763, 0, 0, '%s gasps for air and shivers in the cold.', 16, 0, 100, 20, 0, 0, 41593, 'Frozen Mountaineer to Icy Tomb'),
(42010, 0, 0, 'Long live the Dark Iron!', 12, 0, 100, 15, 0, 0, 41821, 'General Grimaxe to Dark Iron Golem'),
(42129, 0, 0, 'How dare you storm into my throne room and attempt to spread this conspiratorial nonsense!', 12, 7, 100, 5, 0, 0, 42005, 'Moira Thaurissan to Player'),
(42129, 1, 0, 'I will not let you and this treasonous Commander Stonebreaker steal my son''s birthright!', 12, 0, 100, 274, 0, 0, 42006, 'Moira Thaurissan to Player'),
(42129, 2, 0, 'Both of you know I would never order such a thing! Why would I set one half my son''s inheritance against the other?', 12, 7, 100, 5, 0, 0, 42022, 'Moira Thaurissan to Player'),
(42129, 3, 0, 'No, this is the work of a traitor to both our peoples. Despite my best efforts, some Dark Irons remain in the grip of Twilight''s Hammer.', 12, 0, 100, 1, 0, 0, 42026, 'Moira Thaurissan to Player'),
(42129, 4, 0, 'The cult must have someone in the city to coordinate this kind of attack. That only leaves one suspect, Ambassador Slaghammer!', 12, 0, 100, 1, 0, 0, 42028, 'Moira Thaurissan to Player'),
(42129, 5, 0, 'If we were in Shadowforge City, I would have you tossed into the Ring of Law for your transgressions, Ambassador. The darkest dungeons of Ironforge will have to do for now.', 12, 0, 100, 274, 0, 0, 42044, 'Moira Thaurissan to Arrest the Ambassador Credit'),
(42131, 0, 0, 'Muradin has a point. If you cannot govern your own people, you have no place at this table.', 12, 7, 100, 273, 0, 0, 42017, 'Falstad Wildhammer to Player'),
(42153, 0, 0, 'I go willingly, $c. My purpose in my master''s plan is fulfilled.', 12, 0, 100, 1, 0, 0, 42046, 'Ambassador Slaghammer to Player'),
(42153, 1, 0, 'Do as you will with me. I am not afraid. That halfbreed runt will never be my emperor! Long live Twilight''s Hammer!', 12, 0, 100, 5, 0, 0, 42043, 'Ambassador Slaghammer to Arrest the Ambassador Credit'),
(42928, 0, 0, 'That is quite an accusation, Moira. It''s hardly your throne room in the first place.', 12, 0, 100, 6, 0, 0, 42007, 'Muradin Bronzebeard to Player'),
(42928, 1, 0, 'I know Commander Stonebreaker and I will vouch for his loyalty and his honesty. We must take his word.', 12, 0, 100, 1, 0, 0, 42008, 'Muradin Bronzebeard to Player'),
(42928, 2, 0, 'What cause do the Dark Irons have for taking up arms against Ironforge? Are you unable to control your own people, Moira?', 12, 0, 100, 6, 0, 0, 42012, 'Muradin Bronzebeard to Player');


-- allow Amberstill Mountaineer to assist in combat
UPDATE `creature_template`
SET `type_flags` = 4096
WHERE `entry` = 41611;

-- remove forsaken catapult
DELETE FROM `creature`
WHERE `guid` = 306802;

DELETE FROM `creature_addon`
WHERE `guid` = 307073;

-- remove forsaken trooper
DELETE FROM `creature`
WHERE `guid` = 307073;

DELETE FROM `creature_addon`
WHERE `guid` = 307073;

-- hack quest, could not get chains or item to work
UPDATE `quest_template`
SET `QuestType` = 0,
`Flags` = 65536
WHERE `ID` = 26118;

DELETE FROM `quest_poi`
WHERE `QuestID` = 26118;

DELETE FROM `quest_poi_points`
WHERE `QuestID` = 26118;

UPDATE creature_template
SET ScriptName = 'npc_moira_thaurissan'
WHERE entry = 42129;
