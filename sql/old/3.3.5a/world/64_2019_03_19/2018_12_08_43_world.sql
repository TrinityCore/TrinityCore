-- 
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=6644 AND `OptionId`=1) OR (`MenuId`=6644 AND `OptionId`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionId`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
-- Gossip Menu Options for Andorgos
-- Needs Ouro Dead to show. Teleport destination xyzo Mapid: -8632.802, 2055.835, 108.859, 1.024, 531
(6644, 1, 0, 'Please teleport me to the final chamber.', 12851, 28153),
-- Needs the Twin Emporers Dead to show. Teleport destination xyzo Mapid: -8971.805, 1321.432, -104.249, 0.845, 531
(6644, 0, 0, 'Teleport me to the lair of the Twin Emperors, please.', 12849, 28153);

DELETE FROM `gossip_menu` WHERE  (`MenuId`=6766 AND `TextId`=8079) OR (`MenuId`=6765 AND `TextId`=8078) OR (`MenuId`=6767 AND `TextId`=8080) OR (`MenuId`=6644 AND `TextId`=8701);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
-- Gossip Menu that should be shown on Andorgos with Twin Emporers Dead. 
(6644, 8701, 28153), -- 15502 Note:Npctext 7899 is for when the Twin Emporers and Ouro are alive, 8702 is with Ouro dead.

-- Gossip Menus on Arygos, Caelestrasz, Merithra of the Dream when C'Thun is alive.
(6766, 8079, 28153), -- 15378 When dead uses Gossip Menu id 6795
(6765, 8078, 28153), -- 15379 When dead uses Gossip Menu id 6794
(6767, 8080, 28153); -- 15380 When dead uses Gossip Menu id 6793

-- C'thuns Grasp objects around Arygos, Caelestrasz, Merithra of the Dream (Blue Rings). Note: These should activate and dissapear upon C'thuns death, but do 'appear' again after the spawntimesecs.
DELETE FROM `gameobject` WHERE `guid` IN (6660,6663,6665);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,`position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(6660, 180745, 531, 0, 0, 1, 1, -8660.628, 2022.399, 108.5774, 3.647741, 0, 0, -0.9681473, 0.2503814, 7200, 255, 1, 28153),
(6663, 180745, 531, 0, 0, 1, 1, -8652.204, 2020.923, 108.5774, 0.2443456, 0, 0, 0.1218691, 0.9925462, 7200, 255, 1, 28153), 
(6665, 180745, 531, 0, 0, 1, 1, -8663.34, 2029.898, 108.5774, 4.450591, 0, 0, -0.7933531, 0.6087617, 7200, 255, 1, 28153);

-- https://wow.gamepedia.com/File:Kandrostrasz_AQ.JPG
-- Kandrostrasz has weapon sheathed
DELETE FROM `creature_addon` WHERE `guid` = 87529;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(87529, 0, 0, 0, 0, 0, '');
