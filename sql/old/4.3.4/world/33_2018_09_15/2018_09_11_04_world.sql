-- Celestine of the Harvest trainer
UPDATE `creature_template` SET `gossip_menu_id`= 11829, `npcflag`= 51, `unit_class`= 2, `unit_flags`= 32768 WHERE `entry`= 44396;
DELETE FROM `npc_trainer` WHERE `ID`= 44396;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`, `Index`) VALUES
(44396, -200011, 0, 0, 0, 0, 0);
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 1, `OptionType`= 16, `OptionBroadcastTextID`= 8271 WHERE `MenuID`= 11829 AND `OptionID`= 1;

-- Adding Cataclysm event entries
DELETE FROM `game_event` WHERE `eventEntry` IN (77, 78, 79, 80, 81);
INSERT INTO `game_event` (`eventEntry`, `occurence`, `length`, `holiday`, `description`) VALUES
(77, 1440, 1440, 0, 'Cataclysm Pre-Launch Deathwing Event'),
(78, 180, 180, 0, 'Dragonwrath Stormwind Event'),
(79, 180, 180, 0, 'Dragonwrath Orgrimmar Event'),
(80, 1440, 1440, 0, 'Nefarian''s Head Stormwind'),
(81, 1440, 1440, 0, 'Nefarian''s Head Orgrimmar');

-- Assigning some creatures to it
DELETE FROM `game_event_creature` WHERE `guid` IN (307108, 314353, 383796, 310826);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(78, 307108),
(3, 314353),
(77, 383796),
(81, 310826);

DELETE FROM `game_event_gameobject` WHERE `guid` IN (307108, 314353);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(80, 220136),
(80, 211533);

DELETE FROM `gameobject` WHERE `guid`= 218806;
DELETE FROM `gameobject_addon` WHERE `guid`= 218806;
