DELETE FROM `creature_template` WHERE entry = 1000001;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `femaleName`, `subname`, `minlevel`, `maxlevel`, `faction`, `npcflag`) VALUES ('1000001', '37719', 'Klarc March', '', 'Weapon seller', '110', '110', '35', '7');
UPDATE `creature_template` SET `HealthScalingExpansion` = '0' , `RequiredExpansion` = '6' , `npcflag` = '128' WHERE `entry` = '1000001';

DELETE FROM `npc_vendor` WHERE entry = 1000001;
-- Classe WAR /vendeur d'arme Prodi (NPC AP)
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '0', '128910');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '1', '128908');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '2', '128289');

-- Classe DEMONISTE / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '3', '128942');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '4', '128943');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '5', '128941');

-- Classe CHAMAN / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '6', '128935');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '7', '128911');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '8', '128819');

-- Classe VOLEUR / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '9', '128870');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '10', '128872');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '11', '128476');

-- Classe PRETRE / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '12', '128868');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '13', '128825');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '14', '128827');

-- Classe PALADIN / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '15', '128823');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '16', '128866');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '17', '120978');

-- Classe MOINE / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '18', '128938');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '19', '128937');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '20', '128940');

-- Classe MAGE / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '21', '127857');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '22', '128820');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '23', '128862');

-- Classe HUNT / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '24', '128861');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '25', '128808');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '26', '128826');

-- Classe DRUIDE/ NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '28', '128858');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '29', '128821');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '30', '128306');

-- Classe DH / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '31', '127829');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '32', '128832');

-- Classe DK / NPC AP
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '33', '128402');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '34', '128292');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES ('1000001', '35', '128403'); 