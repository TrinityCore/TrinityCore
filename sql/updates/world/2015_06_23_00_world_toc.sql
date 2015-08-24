-- Trial of the Champion
-- by Appled
-- Thanks to Aokromes for providing sniffs

--
-- General
--

-- Disabling mmap for Trial of the Champion instance
-- creatures are spawned according to sniffs behind an invisible wall and they don't know how to go through it
-- Edit: Aokromes has pushed this already but disabled whole instance in the same commit
DELETE FROM `disables` WHERE `entry`=650 AND `sourceType`=2;
-- DELETE FROM `disables` WHERE `sourceType`='7' AND `entry`='650';
-- INSERT INTO `disables` (`sourceType`,`entry`) VALUES ('7','650');

-- Spellscript for vehicles' Trample aura
DELETE FROM `spell_script_names` WHERE `spell_id`=67868 AND `ScriptName`='spell_toc5_trample_aura';
INSERT INTO `spell_script_names` VALUES (67868,'spell_toc5_trample_aura');

-- Spellscript for Hunter Grand Champion's Lightning Arrows
DELETE FROM `spell_script_names` WHERE `spell_id`=66083 AND `ScriptName`='spell_toc5_lightning_arrows';
INSERT INTO `spell_script_names` VALUES (66083,'spell_toc5_lightning_arrows');

--
-- Vehicles
--

-- Variables
SET @ARGENT_BATTLEWORG_GC := 36559; -- used by Grand Champions in looking for mount phase, cannot be used by players
SET @ARGENT_BATTLEWORG_H := 36558;
SET @ARGENT_WARHORSE_A := 36557;
SET @ARGENT_WARHORSE_GC := 35644; -- used by Grand Champions in looking for mount phase, cannot be used by players

-- Argent Battleworg should not be attackable by players
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry`=@ARGENT_BATTLEWORG_GC;

-- Scriptname for cosmetic vehicles
UPDATE `creature_template` SET `ScriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (@ARGENT_BATTLEWORG_GC,@ARGENT_WARHORSE_GC);

-- Argent Battleworg is missing its Trample aura
UPDATE `creature_template_addon` SET `auras`=67870 WHERE `entry`=@ARGENT_BATTLEWORG_H;

-- Argent Warhorse is missing its vehicle data
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@ARGENT_BATTLEWORG_H,@ARGENT_WARHORSE_A) AND `spell_id`=67830;
UPDATE `creature_template` SET `npcflag`=16777216,`spell1`=68505,`spell2`=62575,`spell3`=68282,`spell4`=62552,`VehicleId`=486 WHERE `entry`=@ARGENT_WARHORSE_A;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`) VALUES
(@ARGENT_BATTLEWORG_H,67830,1),
(@ARGENT_WARHORSE_A,67830,1);

-- You should not be able to mount a vehicle if you don't have Argent Lance equipped
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceGroup`=0 AND `SourceEntry` IN (@ARGENT_BATTLEWORG_H,@ARGENT_WARHORSE_A);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(16,0,@ARGENT_BATTLEWORG_H,0,0,3,0,46106,0,0,'Argent Lance must be equipped in order to mount a vehicle'),
(16,0,@ARGENT_WARHORSE_A,0,0,3,0,46106,0,0,'Argent Lance must be equipped in order to mount a vehicle');

--
-- Heralds
--

-- Variables
SET @HERALD_H := 35004; -- Jaeren Sunsworn
SET @HERALD_A := 35005; -- Arelas Brightstar
SET @GOSSIP_MENU := 10614; -- same gossip menu used by both heralds

-- Arelas Brightstar had no gossip menu set in database
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP_MENU WHERE `entry`=@HERALD_A;

--
-- Text updates
--

-- Roleplaying event is missing creature_text data
DELETE FROM `creature_text` WHERE `entry` IN (@HERALD_H,@HERALD_A) AND `groupid` BETWEEN 9 AND 13;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@HERALD_H,9,0,'$n has risen to the ranks of champion in our tournament.  We are proud to present $ghim:her; to you today.',14,100,8574,35304,2,'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_0'),
(@HERALD_H,10,0,'Champions on the tournament grounds speak highly of this $c.  Today we present, $n.',14,100,8574,35305,2,'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_1'),
(@HERALD_H,11,0,'One would be hard pressed to find a more steadfast champion than this $c.  Today we present, $n. ',14,100,8574,35306,2,'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_2'),
(@HERALD_H,12,0,'We offer a mighty champion, a capable $c, an honorable $r.  We present, $n.',14,100,8574,35307,2,'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_3'),
(@HERALD_H,13,0,'Many champions have fallen to the skills displayed by $n.  We are proud to present this formidable $c.',14,100,8574,35308,2,'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_4'),
(@HERALD_A,9,0,'$n has risen to the ranks of champion in our tournament.  We are proud to present $ghim:her; to you today.',14,100,8574,35304,2,'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_0'),
(@HERALD_A,10,0,'Champions on the tournament grounds speak highly of this $c.  Today we present, $n.',14,100,8574,35305,2,'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_1'),
(@HERALD_A,11,0,'One would be hard pressed to find a more steadfast champion than this $c.  Today we present, $n. ',14,100,8574,35306,2,'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_2'),
(@HERALD_A,12,0,'We offer a mighty champion, a capable $c, an honorable $r.  We present, $n.',14,100,8574,35307,2,'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_3'),
(@HERALD_A,13,0,'Many champions have fallen to the skills displayed by $n.  We are proud to present this formidable $c.',14,100,8574,35308,2,'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_4');

-- Jaina Proudmoore is missing her texts
DELETE FROM `creature_text` WHERE `entry`=34992 AND `groupid` IN (0,1);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(34992,0,0,'Of course they will.',12,100,35323,2,'Lady Jaina Proudmoore - SAY_JAINA_INTRO_1'),
(34992,1,0,'They''re worthy fighters, you''ll see.',12,100,35329,2,'Lady Jaina Proudmoore - SAY_JAINA_INTRO_2');

-- Most of the texts in instance should be zonewide
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` IN (34990,34995) AND `groupid`=50 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` IN (34990,34995) AND `groupid`=52 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry`=34994 AND `groupid` IN (0,2) AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` BETWEEN 34900 AND 34910 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry`=34996 AND `groupid` BETWEEN 50 AND 58 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` IN (@HERALD_A,@HERALD_H) AND `groupid` BETWEEN 0 AND 8 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` IN (34657,34701,34702,34703,34705,34883,34887,35569,35570,35571,35572,35617) AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry` IN (34928,35119);

--
-- Lesser Champions
--

-- Variables
SET @ORC_CHAMP := 35314;
SET @TROLL_CHAMP := 35323;
SET @TAUREN_CHAMP := 35325;
SET @BELF_CHAMP := 35326;
SET @UNDEAD_CHAMP := 35327;
SET @HUMAN_CHAMP := 35328;
SET @DWARF_CHAMP := 35329;
SET @DRAENEI_CHAMP := 35330;
SET @GNOME_CHAMP := 35331;
SET @NELF_CHAMP := 35332;

-- Each lesser champion had passiveAI set and had no scriptname assigned in database
UPDATE `creature_template` SET `AIName`='',`ScriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (@ORC_CHAMP,@TROLL_CHAMP,@TAUREN_CHAMP,@BELF_CHAMP,@UNDEAD_CHAMP,@HUMAN_CHAMP,@DWARF_CHAMP,@DRAENEI_CHAMP,@GNOME_CHAMP,@NELF_CHAMP);

--
-- Grand Champions
--

-- Variables
-- Normal mode
SET @MOKRA := 35572;
SET @ERESSEA := 35569;
SET @RUNOK := 35571;
SET @ZULTORE := 35570;
SET @VISCERI := 35617;
SET @JACOB := 34705;
SET @AMBROSE := 34702;
SET @COLOSOS := 34701;
SET @JAELYNE := 34657;
SET @LANA := 34703;
-- Heroic mode
SET @MOKRA_H := 36089;
SET @ERESSEA_H := 36085;
SET @RUNOK_H := 36090;
SET @ZULTORE_H := 36091;
SET @VISCERI_H := 36084;
SET @JACOB_H := 36088;
SET @AMBROSE_H := 36082;
SET @COLOSOS_H := 36083;
SET @JAELYNE_H := 36086;
SET @LANA_H := 36087;

-- None of the grand champions had correct unit flags set in database
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry` IN (@MOKRA,@ERESSEA,@RUNOK,@ZULTORE,@VISCERI,@JACOB,@AMBROSE,@COLOSOS,@JAELYNE,@LANA,@MOKRA_H,@ERESSEA_H,@RUNOK_H,@ZULTORE_H,@VISCERI_H,@JACOB_H,@AMBROSE_H,@COLOSOS_H,@JAELYNE_H,@LANA_H);

-- Achievement criteria scripts
-- for achievement IDs 3778, 4296, 4297, 4298

-- Variables
SET @CRITERIA_JACOB := 11420;
SET @CRITERIA_LANA := 12298;
SET @CRITERIA_COLOSOS := 12299;
SET @CRITERIA_AMBROSE := 12300;
SET @CRITERIA_JAELYNE := 12301;
SET @CRITERIA_MOKRA := 12302;
SET @CRITERIA_VISCERI := 12303;
SET @CRITERIA_RUNOK := 12304;
SET @CRITERIA_ERESSEA := 12305;
SET @CRITERIA_ZULTORE := 12306;
SET @CRITERIA_JACOB_H := 12310;
SET @CRITERIA_LANA_H := 12311;
SET @CRITERIA_COLOSOS_H := 12312;
SET @CRITERIA_AMBROSE_H := 12313;
SET @CRITERIA_JAELYNE_H := 12314;
SET @CRITERIA_MOKRA_H := 12318;
SET @CRITERIA_VISCERI_H := 12319;
SET @CRITERIA_RUNOK_H := 12320;
SET @CRITERIA_ERESSEA_H := 12321;
SET @CRITERIA_ZULTORE_H := 12322;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (@CRITERIA_JACOB,@CRITERIA_LANA,@CRITERIA_COLOSOS,@CRITERIA_AMBROSE,@CRITERIA_JAELYNE,@CRITERIA_MOKRA,@CRITERIA_VISCERI,@CRITERIA_RUNOK,@CRITERIA_ERESSEA,@CRITERIA_ZULTORE,@CRITERIA_JACOB_H,@CRITERIA_LANA_H,@CRITERIA_COLOSOS_H,@CRITERIA_AMBROSE_H,@CRITERIA_JAELYNE_H,@CRITERIA_MOKRA_H,@CRITERIA_VISCERI_H,@CRITERIA_RUNOK_H,@CRITERIA_ERESSEA_H,@CRITERIA_ZULTORE_H);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(@CRITERIA_JACOB, 11, 'achievement_toc_credit_jacob'),
(@CRITERIA_LANA, 11, 'achievement_toc_credit_lana'),
(@CRITERIA_COLOSOS, 11, 'achievement_toc_credit_colosos'),
(@CRITERIA_AMBROSE, 11, 'achievement_toc_credit_ambrose'),
(@CRITERIA_JAELYNE, 11, 'achievement_toc_credit_jaelyne'),
(@CRITERIA_MOKRA, 11, 'achievement_toc_credit_mokra'),
(@CRITERIA_VISCERI, 11, 'achievement_toc_credit_visceri'),
(@CRITERIA_RUNOK, 11, 'achievement_toc_credit_runok'),
(@CRITERIA_ERESSEA, 11, 'achievement_toc_credit_eressea'),
(@CRITERIA_ZULTORE, 11, 'achievement_toc_credit_zultore'),
(@CRITERIA_JACOB_H, 11, 'achievement_toc_credit_jacob_h'),
(@CRITERIA_LANA_H, 11, 'achievement_toc_credit_lana_h'),
(@CRITERIA_COLOSOS_H, 11, 'achievement_toc_credit_colosos_h'),
(@CRITERIA_AMBROSE_H, 11, 'achievement_toc_credit_ambrose_h'),
(@CRITERIA_JAELYNE_H, 11, 'achievement_toc_credit_jaelyne_h'),
(@CRITERIA_MOKRA_H, 11, 'achievement_toc_credit_mokra_h'),
(@CRITERIA_VISCERI_H, 11, 'achievement_toc_credit_visceri_h'),
(@CRITERIA_RUNOK_H, 11, 'achievement_toc_credit_runok_h'),
(@CRITERIA_ERESSEA_H, 11, 'achievement_toc_credit_eressea_h'),
(@CRITERIA_ZULTORE_H, 11, 'achievement_toc_credit_zultore_h');
