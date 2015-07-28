-- Bring Down the Warbringer! (10603) quest fix by nelegalno Closes #7840
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=21287 AND `item`=30689; -- Razuun's Orders http://old.wowhead.com/item=30689

-- The Only Prescription (8620) quest fix by nelegalno
-- Closes #6653 (was changed to reopened but currently treated by github as closed)
-- Closes #7085

-- Chapter I:
-- Move Doctor Weavil on top of the bed
UPDATE `creature` SET `position_z` = 34.5277 WHERE `guid`=18614;

-- Chapter II:
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=6 WHERE (`entry`=8716 AND `item`=21104);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=10 WHERE (`entry`=8717 AND `item`=21104);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=4 WHERE (`entry`=12396 AND `item`=21104);

-- Chapter III:
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=6 WHERE (`entry`=7461 AND `item`=21105);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=6 WHERE (`entry`=7463 AND `item`=21105);

-- Chapter IV, V and VII:
DELETE FROM `gameobject` WHERE (`guid`=45065); -- Remove duplicate of GUID=4596
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6668,6669,6670) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
-- source: https://github.com/TrinityCore/TrinityCore/issues/6653#issuecomment-6956847 ( thanks frostmourne ) + http://thottbot.com/item=21107#comments:id=885246 + http://thottbot.com/item=21106#comments:id=1159575
(6668,0,0,'<Take this book for the good of Azeroth!>',1,1,0,0,0,0,NULL),
(6669,0,0,'<Take this book for the good of Azeroth!>',1,1,0,0,0,0,NULL),
(6670,0,0,'<Take this book for the good of Azeroth!>',1,1,0,0,0,0,NULL);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (180665,180666,180667);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (180665,180666,180667) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(180665,1,0,1,62,0,100,0,6669,0,0,0,56,21107,1,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - take book for quest - The Only Prescription'),
(180665,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - close gossip'),
(180666,1,0,1,62,0,100,0,6670,0,0,0,56,21106,1,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - take book for quest - The Only Prescription'),
(180666,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - close gossip'),
(180667,1,0,1,62,0,100,0,6668,0,0,0,56,21109,1,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - take book for quest - The Only Prescription'),
(180667,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Draconic for Dummies - close gossip');

-- Chapter VI:
-- Chapter VIII:
DELETE FROM `creature_loot_template` WHERE `entry`=10184 AND `item`=21108;
DELETE FROM `creature_loot_template` WHERE `entry`=11502 AND `item`=21110;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(10184,21108,100,1,0,1,1),
(11502,21110,100,1,0,1,1);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (6668,6669,6670);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=15552 AND `SourceEntry`=21130 AND `ConditionTypeOrReference`=8 AND `ConditionValue1`=8606;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=15552 AND `SourceEntry`=21103 AND `ConditionTypeOrReference`=9 AND `ConditionValue1`=8620;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=10184 AND `SourceEntry`=21108 AND `ConditionTypeOrReference`=9 AND `ConditionValue1`=8620;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=11502 AND `SourceEntry`=21110 AND `ConditionTypeOrReference`=9 AND `ConditionValue1`=8620;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,15552,21130,0,0,8,0,8606,0,0,0,0,'','Diary of Weavil will drop only when a player have Decoy! (8606) quest rewarded'),
(1,15552,21103,0,0,9,0,8620,0,0,0,0,'','Draconic for Dummies Chapter I will drop only when a player have The Only Prescription (8620) in their quest log'),
(1,10184,21108,0,0,9,0,8620,0,0,0,0,'','Draconic for Dummies Chapter VI will drop only when a player have The Only Prescription (8620) in their quest log'),
(1,11502,21110,0,0,9,0,8620,0,0,0,0,'','Draconic for Dummies Chapter VIII will drop only when a player have The Only Prescription (8620) in their quest log'),
(15,6668,0,0,0,9,0,8620,0,0,0,0,'',"Show gossip only if player have taken The Only Prescription (8620) quest"),
(15,6668,0,0,0,2,0,21109,1,1,1,0,'',"Show gossip only if player doesn't have the item"),
(15,6669,0,0,0,9,0,8620,0,0,0,0,'',"Show gossip only if player have taken The Only Prescription (8620) quest"),
(15,6669,0,0,0,2,0,21107,1,1,1,0,'',"Show gossip only if player doesn't have the item"),
(15,6670,0,0,0,9,0,8620,0,0,0,0,'',"Show gossip only if player have taken The Only Prescription (8620) quest"),
(15,6670,0,0,0,2,0,21106,1,1,1,0,'',"Show gossip only if player doesn't have the item");

-- Replace placeholder GO by correct GO and remove placeholder GO quest Thwart the Dark Conclave (10808) by aokromes closes #6773
UPDATE `gameobject` SET `id`=184750 WHERE `guid`=99983;
DELETE FROM `gameobject_template` WHERE `entry`=300121;

-- Blending In (11633) quest fix by nelegalno  closes #5980 closes #1004
-- Move Spire of Blood Scouted trigger to floor level so it's not outside LoS
UPDATE `creature` SET `position_z` = 131.750 WHERE `guid` = 85206;

-- Cloak of shadow should not provide immunity to Flare Closes #7856
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=31224 AND `spell_effect`=-1543 AND `type`=2;

-- Nergeld (30403) partial npc fix by nelegalno
-- Fix conditions
UPDATE `conditions` SET `ConditionValue1`=4595 WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=30403;
-- NPC Spells
UPDATE `creature_template` SET `spell1` = 56746, `spell2` = 56748, `spell3` = 56747, `spell4` = 60540 WHERE `entry` = 30403;

-- Fix Brann's Communicator Closes #5835 author gecko32
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=61122 AND `spell_effect`=55038;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(61122, 55038, 0, 'Contact Brann');

-- Fix Black Bruise proc Scaling author Vincent-Michael Closes #7040
-- Fix Warlock Death Coil SP Coeff. Closes #3584
DELETE FROM `spell_bonus_data` WHERE `entry` IN (6489,71878,71879);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(6489,0.2143,0,0,0,'Spell Power Coeff for Death Coil'),
(71878,0,0,0,0,'Item - Black Bruise: Heroic Necrotic Touch Proc'),
(71879,0,0,0,0,'Item - Black Bruise: Necrotic Touch Proc');

-- Fix proc for Elemental Focus author Warpten Closes #7769
DELETE FROM `spell_proc_event` WHERE `entry`=16164;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(16164, 0x1C, 0x0B, 0x98101417, 0x80043000, 0x00002004, 0x00010000, 0x00000002, 0, 100, 0);
