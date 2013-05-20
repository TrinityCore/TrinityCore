-- Hunterpet vendor
REPLACE INTO `creature_template` (`entry`, `modelid1`, `modelid3`, `name`, `gossip_menu_id`, `minlevel`, `faction_A`, `faction_H`, `npcflag`, `unit_class`, `ScriptName`) VALUES 
('100003', '25103', '25106', 'Beastmaster', '40009', '80', '35', '35', '1', '1', 'npc_hunterpetvendor');

REPLACE INTO `gossip_menu` (entry, text_id)
VALUES ('40009', '40009');

REPLACE INTO `npc_text` (ID, text0_0, text0_1, lang0, prob0, em0_0, em0_1, em0_2, em0_3, em0_4, em0_5, text1_0, text1_1, lang1, prob1, em1_0, em1_1, em1_2, em1_3, em1_4, em1_5, text2_0, text2_1, lang2, prob2, em2_0, em2_1, em2_2, em2_3, em2_4, em2_5, text3_0, text3_1, lang3, prob3, em3_0, em3_1, em3_2, em3_3, em3_4, em3_5, text4_0, text4_1, lang4, prob4, em4_0, em4_1, em4_2, em4_3, em4_4, em4_5, text5_0, text5_1, lang5, prob5, em5_0, em5_1, em5_2, em5_3, em5_4, em5_5, text6_0, text6_1, lang6, prob6, em6_0, em6_1, em6_2, em6_3, em6_4, em6_5, text7_0, text7_1, lang7, prob7, em7_0, em7_1, em7_2, em7_3, em7_4, em7_5, WDBVerified)
VALUES ('40009', 'Hi $N, Please choose a Category:', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

REPLACE INTO `gossip_menu` (entry, text_id)
VALUES ('40010', '40010');

REPLACE INTO `npc_text` (ID, text0_0, text0_1, lang0, prob0, em0_0, em0_1, em0_2, em0_3, em0_4, em0_5, text1_0, text1_1, lang1, prob1, em1_0, em1_1, em1_2, em1_3, em1_4, em1_5, text2_0, text2_1, lang2, prob2, em2_0, em2_1, em2_2, em2_3, em2_4, em2_5, text3_0, text3_1, lang3, prob3, em3_0, em3_1, em3_2, em3_3, em3_4, em3_5, text4_0, text4_1, lang4, prob4, em4_0, em4_1, em4_2, em4_3, em4_4, em4_5, text5_0, text5_1, lang5, prob5, em5_0, em5_1, em5_2, em5_3, em5_4, em5_5, text6_0, text6_1, lang6, prob6, em6_0, em6_1, em6_2, em6_3, em6_4, em6_5, text7_0, text7_1, lang7, prob7, em7_0, em7_1, em7_2, em7_3, em7_4, em7_5, WDBVerified)
VALUES ('40010', 'Sorry, you must be a Hunter to summon a creature.', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

REPLACE INTO `gossip_menu` (entry, text_id)
VALUES ('40011', '40011');

REPLACE INTO `npc_text` (ID, text0_0, text0_1, lang0, prob0, em0_0, em0_1, em0_2, em0_3, em0_4, em0_5, text1_0, text1_1, lang1, prob1, em1_0, em1_1, em1_2, em1_3, em1_4, em1_5, text2_0, text2_1, lang2, prob2, em2_0, em2_1, em2_2, em2_3, em2_4, em2_5, text3_0, text3_1, lang3, prob3, em3_0, em3_1, em3_2, em3_3, em3_4, em3_5, text4_0, text4_1, lang4, prob4, em4_0, em4_1, em4_2, em4_3, em4_4, em4_5, text5_0, text5_1, lang5, prob5, em5_0, em5_1, em5_2, em5_3, em5_4, em5_5, text6_0, text6_1, lang6, prob6, em6_0, em6_1, em6_2, em6_3, em6_4, em6_5, text7_0, text7_1, lang7, prob7, em7_0, em7_1, em7_2, em7_3, em7_4, em7_5, WDBVerified)
VALUES ('40011', 'Please choose a creature:', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

-- Elemental focus(shaman talent) correct proc.
DELETE FROM spell_proc_event WHERE entry = 16164;
INSERT INTO spell_proc_event (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES (16164, 0, 11, 2416967683, 4096, 0, 0, 2, 0, 0, 0);

-- Fix Dancing Rune Weapon.
DELETE FROM `spell_proc_event` where `entry` = 49028;
INSERT INTO `spell_proc_event` (entry, procFlags) VALUES
('49028','69652');

-- Fix Lifebloom.
DELETE FROM spell_bonus_data WHERE entry = 33778;
DELETE FROM spell_bonus_data WHERE entry = 33763;
INSERT INTO spell_bonus_data (entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus, comments) VALUES
(33778, 0, 0, 0, 0, 'Druid - Lifebloom final heal'),
(33763, 0.516, 0.0952, 0, 0, 'Druid - Lifebloom HoT(rank 1)');

-- ICC fixs...

   -- update immunity
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('36612', '37957', '37958', '37959'); -- Lod Mark'gar
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('36855', '38106', '38296', '38297'); -- Lady Deathwhisper
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('37813', '38402', '38582', '38583'); -- Deathbringer Saurfang
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('36627', '38390', '38549', '38550'); -- Rotface
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('36626', '37504', '37505', '37506'); -- Festergut
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('36678', '38431', '38585', '38586'); -- Professor Putricide
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('37562', '38602', '38760', '38761'); -- Gas Cloud
   UPDATE `creature_template` set `mechanic_immune_mask` = 617299803 where entry IN ('37697', '38604', '38758', '38759'); -- Volatile Ooze
   UPDATE `creature_template` SET `mechanic_immune_mask` = 617299803 where entry IN ('36980', '38320', '38321', '38322'); -- Ice Tombs / Sindragosa

   -- Rotface:
   -- remove conditions (target selection changed from TARGET_UNIT_NEARBY_ENTRY to TARGET_UNIT_TARGET_ANY so doesn't need it anymore)
    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=69508;
   /* backup data
   INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
   (13, 0, 69508, 0, 0, 18, 0, 1, 37986, 0, 0, 0, '', 'Rotface - Slime Spray');
   */

   -- Add script
   DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rotface_slime_spray';
   INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
   (69507, 'spell_rotface_slime_spray'),
   (71213, 'spell_rotface_slime_spray'),
   (73189, 'spell_rotface_slime_spray'),
   (73190, 'spell_rotface_slime_spray');

   -- Sindragosa:
   -- Fix spell 69762 Unchained Magic 
   -- Add internal cooldown with 1 seconds, so multi-spell spells will only apply one stack of triggered spell 69766 (i.e. Chain Heal)
   DELETE FROM `spell_proc_event` WHERE `entry` = 69762;
   INSERT INTO `spell_proc_event` (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
   (69762, 0, 0, 0, 0, 0, 81920, 0, 0, 0, 1);

-- Project Astranaar!

   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 6087; -- Astranaar Sentinel (79)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3894; -- Pelturas Whitemoon (124)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3959; -- Nantar (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3961; -- Malyinn (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3915; -- Dagri (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3888; -- Korra (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3691; -- Raene Wolfhunter (124)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3969; -- Fahran Silentblade (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 6738; -- Inkeeper Kimlya (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 10052; -- Maluressian (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3967; -- Aayandia Floralwind (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 11137; -- Xai'ander (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3962; -- Haljan Oakheart (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3954; -- Dalria (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3996; -- Faldreas Goeth'Shael (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 17106; -- Vindicator Palanaar (1638)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 4079; -- Sentinel Thenysil (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3952; -- Aeolynn (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3953; -- Tandaan Lightmane (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3958; -- Lardan (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3970; -- Llana (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3845; -- Sindrell Swiftfire (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 4267; -- Daelyshia (80)
   UPDATE creature_template SET faction_A = 35, faction_H = 35 WHERE entry = 3892;
   UPDATE gameobject_template SET faction = 0 WHERE entry = 142117; -- Astranaar mailbox

-- Transmogrification.
SET
@Entry = 190010,
@Name = "Warpweaver";

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(@Entry, 0, 0, 0, 0, 0, 19646, 0, 0, 0, @Name, 'Transmogrifier', NULL, 0, 80, 80, 2, 35, 35, 1, 1, 1.14286, 1, 0, 500, 500, 0, 350, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'NPC_Transmogrify', 0);

REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11100, 'Transmogrifications removed from equipped items', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11101, 'You have no transmogrified items equipped', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11102, '%s transmogrification removed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11103, 'No transmogrification on %s slot', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11104, '%s transmogrified', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11105, 'Selected items are not suitable', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11106, 'Selected item does not exist', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11107, 'Equipment slot is empty', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11108, 'Head', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11109, 'Shoulders', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11110, 'Shirt', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11111, 'Chest', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11112, 'Waist', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11113, 'Legs', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11114, 'Feet', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11115, 'Wrists', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11116, 'Hands', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11117, 'Back', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11118, 'Main hand', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11119, 'Off hand', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11120, 'Ranged', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11121, 'Tabard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11122, 'Back..', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11123, 'Remove all transmogrifications', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11124, 'Remove transmogrifications from all equipped items?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11125, 'Update menu', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11126, 'Remove transmogrification', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11127, 'Remove transmogrification from %s?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11128, 'Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\r\nDo you wish to continue?\r\n\r\n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11129, 'You don\'t have enough %ss', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Add Name Admin, GameMaster and Guard Announces.
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11669, '|cffffff00[|c1f4DF620Developer|r |c100FFFF0%s|c1f4DF620 Announces|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11668, '|cffffff00[|c1f4DF620Guard|r |c100FFFF0%s|c1f4DF620 Announces|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11667, '|cffffff00[|c1f4DF620GameMaster|r |c100FFFF0%s|c1f4DF620 Announces|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11666, '|cffffff00[|c1f4DF620Administrator|r |c100FFFF0%s|c1f4DF620 Announces|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

REPLACE INTO `command` (`name`, `security`, `help`) VALUES
('msgadm', 4, 'Syntax: .adm $announcement.\nSend an announcement to all online players, displaying the name of the sender.'),
('msgdev', 3, 'Syntax: .adm $announcement.\nSend an announcement to all online players, displaying the name of the sender.'),
('msggm', 3, 'Syntax: .adm $announcement.\nSend an announcement to all online players, displaying the name of the sender.'),
('msgguard', 1, 'Syntax: .msg $announcement.\nSend an announcement to all online players, displaying the name of the sender.');

-- Add AutoBanned Passive Anticheat System!
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11002, '|cFFFFFC00[ANTICHEAT]|cFF00FFFF[|cFF60FF00%s|cFF00FFFF] Banned for cheating!|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Removes Master's Call stun immunity.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 54216;
INSERT INTO `spell_linked_spell`(`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (54216,-56651,1,'Removes Master''s Call stun immunity');

-- Sap removes Stealth.
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type,
comment) VALUES 
(6770, -1784, 1, 'Sap(rank 1) removes Stealth'),
(2070, -1784, 1, 'Sap(rank 2) removes Stealth'),
(11297, -1784, 1, 'Sap(rank 3) removes Stealth'),
(51724, -1784, 1, 'Sap(rank 4) removes Stealth');

-- Priest: Shadowfiend, http://old.wowhead.com/spell=34433
DELETE FROM `spell_proc_event` WHERE `entry` = 28305;
INSERT INTO `spell_proc_event` VALUES (28305, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0);
-- Move Shadowfiend's Mana Leech Aura from spellscript to creature addon.
UPDATE `creature_template_addon` SET `auras`= '28305' WHERE `entry`=19668;

-- Npc Top 10 Arena Teams
DELETE FROM `creature_template` WHERE `entry` = 500009;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('500009', '0', '0', '0', '0', '0', '27164', '0', '0', '0', 'Top 10 Arena Teams', '', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', 'npc_arena_team_top', '1');

-- Fix Rogue T10 4p bonus
DELETE FROM spell_proc_event WHERE entry = 70803;
INSERT INTO `spell_proc_event` VALUES('70803', '0', '8', '4063232', '8', '0', '0', '0', '0', '0', '0');

-- Fix Illidan
UPDATE `creature_template` SET `unit_flags` = 33554690 WHERE `entry` = 23070; -- c eyebeam target
UPDATE `creature_template` SET `unit_flags` = 33685510, `ScriptName` = '' WHERE `entry` IN (23069, 23336, 23259); -- Demon Fire and Flame Crash, and blaze

-- Fix Zul'drak arena
UPDATE `creature_template` SET `ScriptName` = 'npc_vladof' WHERE `entry` =30022;
UPDATE `creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `entry` =30093;
UPDATE `creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `entry` =30110;

-- Mr.Maniek ! <3
UPDATE `creature_template` SET `ScriptName` = 'npc_maniek' WHERE `entry` = 91200;

-- Npc MMR Master
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('500010', '0', '0', '0', '0', '0', '7103', '0', '7103', '0', 'Might Johny', 'MMR Master', NULL, '0', '85', '85', '2', '35', '35', '1', '1', '1.14286', '1', '3', '600000', '600000', '0', '2000', '11', '1500', '2000', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '1', '50000', '1', '6740', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', 'npc_mmr_reset', '500009');
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES ('500010', 'Hi gladiator! I can reset your Matchmaking Rating to given values if only You are not team captain!', '', '0', '1', '0', '1', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '1');

-- Fix Val'kyr Shadowguard speed
UPDATE `creature_template` SET `speed_walk` = '0.642857' WHERE `entry` IN (36609, 39120, 39121, 39122);

-- Halion immunities
UPDATE creature_template SET mechanic_immune_mask = mechanic_immune_mask | 650854271 WHERE entry IN (
39863, 40142, -- 10 nm
39864, 40143, -- 25 nm
39944, 40144, -- 10 hc
39945, 40145  -- 25 hc
);
-- Halion damage multipliers
UPDATE creature_template SET dmg_multiplier = 70 WHERE entry IN (39863, 40142);  -- 10 nm
UPDATE creature_template SET dmg_multiplier = 100 WHERE entry IN (39864, 40143); -- 25 nm
UPDATE creature_template SET dmg_multiplier = 100 WHERE entry IN (39944, 40144); -- 10 hc
UPDATE creature_template SET dmg_multiplier = 170 WHERE entry IN (39945, 40145); -- 25 hc

-- Fix loot Trial of Champion
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195709;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195710;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195374;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195375;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195323;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195324;

-- Fix loot Trial of Crusader
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195631;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195632;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195633;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195635;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195668;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195667;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195666;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195665;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195672;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195671;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195670;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 195669;

-- Fix loot Halls of Reflection
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 202212;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 201710;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 202337;
UPDATE `gameobject_template` SET `flags` = '0' WHERE `gameobject_template`.`entry` = 202336;

-- Fix MMaps
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37955,38434,38435,38436); -- Blood-Queen Lana'thel (ICC)
-- UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37813,38402,38582,38583); -- Deathbringer Saurfang (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37533,38220); -- Rimefang (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37534,38219); -- Spinestalker (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (39747,39823); -- Saviana Ragefire (RS)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (10184,36538); -- Onyxia (Ony)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (24068,31655); -- Annhylde the Caller (UK)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (11583); -- Nefarian
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (27829); -- Ebon Gargyole

-- Fix priest bug (kills and honour) spell_priest_spirit_of_redemption.
-- Spell script assignment
SET @ENTRY := 27827;
DELETE FROM spell_script_names WHERE spell_id = @ENTRY;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(@ENTRY, 'spell_priest_spirit_of_redemption');

-- Update ICC: Rotface
-- Fix targetting for Ooze Flood ability in encounter Modermiene / Rotface in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 3 AND `SourceEntry` IN (69783, 69797, 69799, 69802) AND `ConditionTypeOrReference` = 33;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(13, 3, 69783, 0, 0, 33, 1, 0, 0, 0, 1, 0, '', 'Rotface - Ooze Flood, not self'),
(13, 3, 69797, 0, 0, 33, 1, 0, 0, 0, 1, 0, '', 'Rotface - Ooze Flood, not self'),
(13, 3, 69799, 0, 0, 33, 1, 0, 0, 0, 1, 0, '', 'Rotface - Ooze Flood, not self'),
(13, 3, 69802, 0, 0, 33, 1, 0, 0, 0, 1, 0, '', 'Rotface - Ooze Flood, not self');
-- Add immunities to Little Ooze / Big Ooze in encounter Modermiene / Rotface in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
UPDATE `creature_template` SET `mechanic_immune_mask` = 650853247 WHERE `entry` IN (36897, 36899, 38138, 38123);
-- Add interrupt immunity to mini bosses (Rimefang / Raufang / Spinestalker / Wirbelpirscher) in encounter Sindragosa in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
UPDATE `creature_template` SET `mechanic_immune_mask` = 650853247 WHERE `entry` IN (37533, 38220, 37534, 38219);
-- DB/NPCs: Little Ooze (Rotface in ICC) can not be taunted, 2012_09_10_06_world_creature_template.sql
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|256 WHERE `entry` IN (36897, 38138); -- Little Ooze
-- Set speed values to database for Valkyr Shadowguard in encounter The Lich King in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
UPDATE `creature_template` SET `speed_walk` = 0.642857, `speed_run` = 0.642857, `InhabitType` = 4 WHERE `entry` IN (36609, 39120, 39121, 39122);
-- Set speed values to database for Vile Spirits in encounter The Lich King in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
UPDATE `creature_template` SET `speed_walk` = 0.5, `speed_run` = 0.5, `InhabitType` = 4 WHERE `entry` IN (37799, 39284, 39285, 39286);

-- Fix Glyph of Succubus.
DELETE FROM `spell_script_names` WHERE `spell_id`=6358;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(6358,'spell_warl_seduction');

-- Revert [Warrior] T10 4P Bonus
-- Slam
DELETE FROM spell_script_names WHERE spell_id = 46916;
-- Execute
DELETE FROM spell_script_names WHERE spell_id = 52437;

-- Revert 'Implement Raise ally'
DELETE FROM creature_template WHERE entry = 30230;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(30230, 0, 0, 0, 0, 0, 24994, 24993, 24992, 24995, 'Risen Ally', '', '', 0, 1, 1, 0, 35, 35, 0, 0.8, 0.99206, 1, 0, 2, 2, 0, 24, 1, 2000, 0, 1, 0, 2048, 8, 40, 0, 0, 0, 0, 1, 1, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8388624, 0, '', 12340);

-- Spell threat entries fix
DELETE FROM `spell_threat` WHERE `entry` IN (52372,61411,53595,20187,48818,47520,47488,20243,12809,48568);
INSERT INTO `spell_threat` (`entry`, `flatMod`, `pctMod`, `apPctMod`) VALUES 
(52372, 0, 7.00, 0.0), -- Icy Touch
/*
(61411, 0, 3.00, 0.0), -- Shield of Righteousness
(53595, 0, 3.00, 0.0), -- Hammer of Righteousness
(20187, 0, 2.00, 0.0), -- Judgment of Righteousness
(48818, 0, 2.00, 0.0), -- Consecration */
(47520, 225, 1.00, 0.0), -- Cleave (Rank 8)
(47488, 770, 1.30, 0.0), -- Shield Slam (Rank 8)
(20243, 315, 1.00, 0.05), -- Devastate (Rank 1)
(12809, 0, 2.00, 0.0), -- Concussion Blow
(48568, 1031, 0.50, 0.0);  -- Lacerate (Rank 3)

-- Fix Shadowmeld.
DELETE FROM spell_script_names WHERE spell_id = 58984;
INSERT INTO spell_script_names VALUES (58984, 'spell_gen_shadowmeld');

-- Fix Sylvanas Music Box
DELETE FROM spell_script_names WHERE spell_id = 73331;
INSERT INTO spell_script_names VALUES ('73331', 'spell_item_sylvanas_music_box');

-- Implement Fast Arena Start
DELETE FROM `gameobject_template` WHERE `entry` = 42000;
INSERT INTO `gameobject_template` VALUES (42000, 10, 327, 'Arena Crystal', 'PVP', '', '', 0, 0, 1.5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'fast_arena_start', 12340);
DELETE FROM `gameobject` WHERE  `id`=42000;
INSERT INTO `gameobject` VALUES ('xxx', 42000, 562, 1, 1, 6287.79, 288.368, 5.26778, 3.91128, 0, 0, 0.926857, -0.375416, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 562, 1, 1, 6188.78, 235.324, 5.29393, 0.891424, 0, 0, 0.431101, 0.902304, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 559, 1, 1, 4090.01, 2873.47, 12.1158, 2.08915, 0, 0, 0.864712, 0.502267, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 572, 1, 1, 1297.43, 1597.66, 31.6135, 4.88125, 0, 0, 0.644959, -0.764217, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 572, 1, 1, 1274.79, 1732.94, 31.6048, 4.81449, 0, 0, 0.670103, -0.742268, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 617, 1, 1, 1352.68, 815.687, 15.2511, 0.401281, 0, 0, 0.199297, 0.979939, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 617, 1, 1, 1229.86, 761.566, 15.7332, 0.0471227, 0, 0, 0.0235592, 0.999722, 300, 0, 1);
INSERT INTO `gameobject` VALUES ('xxx', 42000, 559, 1, 1, 4023.85, 2967.25, 12.1642, 5.05796, 0, 0, 0.575005, -0.81815, 300, 0, 1);

-- Implement Fake Players
DELETE FROM trinity_string WHERE entry = 12003;
INSERT INTO trinity_string (`entry`,`content_default`) VALUES (12003, 'Player wishes to not be disturbed and cannot receive whisper messages.');
