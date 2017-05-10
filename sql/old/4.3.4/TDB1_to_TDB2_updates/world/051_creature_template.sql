UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=6 WHERE `subname` LIKE 'DeathKnight Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=11 WHERE `subname` LIKE 'Druid Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=3 WHERE `subname` LIKE 'Hunter Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=4 WHERE `subname` LIKE 'Rogue Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=8 WHERE `subname` LIKE 'Mage Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=2 WHERE `subname` LIKE 'Paladin Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=5 WHERE `subname` LIKE 'Priest Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=7 WHERE `subname` LIKE 'Shaman Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=1 WHERE `subname` LIKE 'Warrior Trainer';
UPDATE `creature_template` SET `npcflag`=`npcflag`|16|32, `trainer_class`=9 WHERE `subname` LIKE 'Warlock Trainer';

-- Fix Multiple Training Gossip Menus
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `option_text` LIKE '%Training%';
