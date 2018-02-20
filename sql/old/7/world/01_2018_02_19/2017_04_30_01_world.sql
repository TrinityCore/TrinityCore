-- Wayward Fire Elemental
UPDATE `creature_template` SET `mingold`=1, `maxgold`=4 WHERE `entry`=37112;
DELETE FROM `creature_loot_template` WHERE `Entry`=37112;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37112,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37112,55973,0,90,0,1,1,1,2, 'Inert Elemental Speck'),
(37112,55983,0,10,0,1,1,1,2, 'Inert Elemental Scintilla');

-- Ragged Timber Wolf
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=704;
DELETE FROM `creature_loot_template` WHERE `Entry`=704;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(704,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(704,49748,0,100,1,1,1,1,1, 'Ragged Wolf Hide'),
(704,62328,0,50,0,1,1,1,2, 'Shed Fur'),
(704,3300,0,50,0,1,1,1,1, 'Rabbit''s Foot');

-- Player should have Trolling for Information: Troll Trigger Aura in Coldridge Valley if quest Trolling for Information is active
DELETE FROM `spell_area` WHERE `spell` IN (69991);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(69991,132,24489,0,0,0,2,1,8,0);

-- Felix Whindlebolt gossip option fix
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=10898;
