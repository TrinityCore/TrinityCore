DROP TABLE IF EXISTS `fake_items`;
CREATE TABLE `fake_items` (
  `guid` int(11) NOT NULL,
  `fakeEntry` int(11) NOT NULL,
  PRIMARY KEY (`guid`)
);

DELETE FROM `creature_template` WHERE `entry`=1900001;
DELETE FROM `locales_creature` WHERE `entry`=1900001;
DELETE FROM `gossip_menu` WHERE `entry`=51000;
DELETE FROM `gossip_menu` WHERE `text_id`=51000;
DELETE FROM `npc_text` WHERE `id`=51000;
DELETE FROM `locales_npc_text` WHERE `entry`=51000;

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(900006, 0, 0, 0, 0, 0, 18660, 18660, 0, 0, 'Искажающий пространство', '', 'Speak', 50000, 83, 83, 0, 35, 35, 1, 2, 2, 1.2, 2, 1420, 2140, 0, 1300, 300, 1500, 1500, 2, 2, 0, 0, 0, 0, 0, 0, 1140, 1710, 1200, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 1000, '', 0, 3, 100, 50, 10, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 'npc_transmogrify', 12340);

INSERT INTO locales_creature VALUES ('900006', '', '', '', '', '', '', '', 'Искажающий пространство', null, null, null, null, null, null, null, '');

INSERT INTO `gossip_menu` VALUES (51000, 51000);

INSERT INTO npc_text (ID, text0_0, em0_1) VALUES
(51000, 'Put in the first slot of bag item, that you want to transmogrify. In the second slot, put item with perfect display.', 0);

INSERT INTO locales_npc_text VALUES ('51000', null, null, null, null, null, null, null, 'Положите в первый слот рюкзака предмет, который вы хотите исказить. Во второй слот предмет, модель которого будет использована для трансмогрификации.', null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null);
