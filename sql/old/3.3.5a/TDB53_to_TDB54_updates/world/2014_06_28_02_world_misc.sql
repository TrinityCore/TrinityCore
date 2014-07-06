--
SET @CGUID:= 78207; -- needs 8

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (31406,32513);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
-- Alliance Bomber
(31406,31408,0,1,'Alliance Bomber Seat on Alliance Infra-green Bomber',8,0),
(31406,31407,1,1,'Alliance Turret Seat on Alliance Infra-green Bomber',8,0),
(31406,31409,2,1,'Alliance Engineering Seat on rides Alliance Infra-green Bomber',8,0),
(31406,32217,3,1,'Banner Bunny, Hanging, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32221,4,1,'Banner Bunny, Side, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32221,5,1,'Banner Bunny, Side, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32256,6,1,'Shield Visual Loc Bunny on Alliance Infra-green Bomber',8,0),
(31406,32274,7,0,'Alliance Bomber Pilot rides Alliance Infra-green Bomber',6,300),
-- Horde Bomber
(32513,31856,0,1,'Horde Bomber Seat on Horde Infra-green Bomber',8,0),
(32513,31840,1,1,'Horde Turret Seat on Horde Infra-green Bomber',8,0),
(32513,32152,2,1,'Horde Engineering Seat on rides Horde Infra-green Bomber',8,0),
(32513,32214,3,1,'Banner Bunny, Hanging, Horde on Horde Infra-green Bomber',8,0),
(32513,32215,4,1,'Banner Bunny, Side, Horde on Horde Infra-green Bomber',8,0),
(32513,32215,5,1,'Banner Bunny, Side, Horde on Horde Infra-green Bomber',8,0),
(32513,32256,6,1,'Shield Visual Loc Bunny on Horde Infra-green Bomber',8,0),
(32513,32317,7,0,'Horde Bomber Pilot rides Horde Infra-green Bomber',6,300);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (31406, 31408, 31407, 31409, 31856, 31840, 32152, 32513);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(31406,46598,1,0),
(31408,46598,1,0),
(31407,46598,1,0),
(31409,46598,1,0),
(31856,46598,1,0),
(31840,46598,1,0),
(32152,46598,1,0),
(32513,46598,1,0);

DELETE FROM `gossip_menu_option` WHERE menu_id = 10120 AND id = 0;
DELETE FROM `gossip_menu_option` WHERE menu_id = 10119 AND id = 0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(10120,0,0,'Give me a bomber!',1,1),
(10119,0,0,'Give me a bomber!',1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceGroup`=10120;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceGroup`=10119;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,10120,0,0,9,13373,0,0,0,'show gossip on quest 13373 taken'),
(15,10120,0,1,9,13374,0,0,0,'show gossip on quest 13374 taken'),
(15,10120,0,2,9,13376,0,0,0,'show gossip on quest 13376 taken'),
(15,10120,0,3,9,13406,0,0,0,'show gossip on quest 13406 taken'),
(15,10119,0,0,9,13381,0,0,0,'show gossip on quest 13381 taken'),
(15,10119,0,1,9,13404,0,0,0,'show gossip on quest 13404 taken'),
(15,10119,0,2,9,13380,0,0,0,'show gossip on quest 13380 taken'),
(15,10119,0,3,9,13382,0,0,0,'show gossip on quest 13382 taken');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry` IN (31648,31839);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31648,31839);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31648, 0, 0, 0, 62, 0,100,0, 10119, 0, 0, 0, 11, 59563, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Karen No - Gossip select - Cast Waiting for Bomber'),
(31839, 0, 0, 0, 62, 0,100,0, 10120, 0, 0, 0, 11, 59779, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rizzy Ratchwiggle - Gossip select - Cast Waiting for Bomber');

UPDATE creature_template SET `spell1`=59059, `spell4`=59194, `spell5`=59196, `spell6`=59193 WHERE `entry` IN (31408, 31856);
UPDATE creature_template SET `spell1`=64979, `spell2`=61313, `spell4`=59194, `spell5`=59196, `spell6`=59193 WHERE `entry` IN (31407, 31840);
UPDATE creature_template SET `spell1`=59061, `spell2`=61171, `spell4`=59194, `spell5`=59196, `spell6`=59193 WHERE `entry` IN (31409, 32152);

UPDATE creature_template SET `VehicleId`=273 WHERE `entry`=31406;
UPDATE creature_template SET `VehicleId`=274 WHERE `entry` IN (31408,31856);
UPDATE creature_template SET `VehicleId`=277 WHERE `entry` IN (31407,31840);
UPDATE creature_template SET `VehicleId`=278 WHERE `entry` IN (31409,32152);
UPDATE creature_template SET `VehicleId`=287 WHERE `entry`=32513;
UPDATE creature_template SET `Unit_flags`= 33554432, `unit_class`=8 WHERE `entry` IN (31407,31408,31409,31840,31856,32152);
UPDATE creature_template SET `npcflag`=16777216, `minlevel`=80, `maxlevel`=80 WHERE `entry` IN (31406,31407,31408,31409,31840,31856,32152,32513);

UPDATE creature_template SET `InhabitType`=4 WHERE `entry` IN (32513,31406);

DELETE FROM `creature` WHERE `id` IN (31648,32523,32524,32526,32525,31839,32529,32528);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`) VALUES
(@CGUID+0, 31648, 571, 1, 1, 0, 7624.19, 2059.96, 600.26, 3.18997,300),
(@CGUID+1, 32523, 571, 1, 1, 1, 7637.56, 2057.34, 600.26, 2.9082,300),
(@CGUID+2, 32524, 571, 1, 1, 1, 7632.78, 2052.75, 600.26, 2.07206,300),
(@CGUID+3, 32526, 571, 1, 1, 0, 7626.84, 2069.71, 600.26, 2.85573,300),
(@CGUID+4, 32525, 571, 1, 1, 0, 7622.21, 2071.61, 600.26, 2.01916,300),
(@CGUID+5, 31839, 571, 1, 1, 0, 7891.96, 2057.73, 600.26, 6.10727,300),
(@CGUID+6, 32529, 571, 1, 1, 0, 7888.79, 2066.53, 600.26, 0.333032,300),
(@CGUID+7, 32528, 571, 1, 1, 0, 7893.77, 2067.97, 600.26, 1.02339,300);
