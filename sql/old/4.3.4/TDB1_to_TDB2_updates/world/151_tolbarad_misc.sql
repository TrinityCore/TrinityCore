UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=47680;
DELETE FROM `creature_template_addon` WHERE `entry` IN (47680, 48356, 48251, 52015, 47659, 46643, 47130, 47183);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(47680, 0, 0x3000000, 0x1, 455, ''), -- Rustberg Gull
(48356, 0, 0x0, 0x1, 233, ''), -- Karosh
(48251, 0, 0x0, 0x1, 233, ''), -- Kevin Geissler
(52015, 0, 0x0, 0x1, 333, ''), -- Captain Jake Sones
(47659, 0, 0x0, 0x1, 234, ''), -- Apprehensive Worker
(46643, 0, 0x0, 0x1, 234, '33900'), -- Accursed Shipbuilder - Shroud of Death
(47130, 0, 0x0, 0x2, 214, ''), -- Crazed Guard
(47183, 0, 0x0, 0x1, 233, '33900'); -- Ghastly Worker - Shroud of Death


DELETE FROM `creature_addon` WHERE `guid` IN (5150, 5156, 5157, 5158, 5171, 5160, 5179, 5153, 5517, 5442, 5441, 5440, 5513, 5520, 5439, 5369, 5391, 5405, 5412, 5423, 5424);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(5150, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5156, 0, 0x0, 0x1, 234, ''), -- Baradin Recruit
(5157, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5158, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5171, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5160, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5179, 0, 0x0, 0x101, 333, ''), -- Baradin Guard
(5153, 0, 0x0, 0x1, 234, ''), -- Baradin Recruit
(5517, 0, 0x0, 0x1, 233, ''), -- Hellscream's Reach Recruit
(5442, 0, 0x0, 0x101, 333, ''), -- Hellscream Guard
(5441, 0, 0x0, 0x101, 333, ''), -- Hellscream Guard
(5440, 0, 0x0, 0x101, 333, ''), -- Hellscream Guard
(5513, 0, 0x0, 0x1, 233, ''), -- Hellscream's Reach Recruit
(5520, 0, 0x0, 0x101, 333, ''), -- Hellscream Guard
(5439, 0, 0x0, 0x1, 233, ''), -- Hellscream's Reach Recruit
(5369, 0, 0x0, 0x1, 69, '33900'), -- Ghastly Scavenger - Shroud of Death
(5391, 0, 0x0, 0x1, 133, '33900'), -- Ghastly Scavenger - Shroud of Death
(5405, 0, 0x0, 0x1, 69, '33900'), -- Ghastly Scavenger - Shroud of Death
(5412, 0, 0x0, 0x1, 69, '33900'), -- Ghastly Scavenger - Shroud of Death
(5423, 0, 0x0, 0x1, 133, '33900'), -- Ghastly Scavenger - Shroud of Death
(5424, 0, 0x0, 0x1, 133, '33900'); -- Ghastly Scavenger - Shroud of Death



DELETE FROM `creature_addon` WHERE `guid` IN (5173, 5174, 5544, 5545, 5543, 5549, 5548, 5038, 5234);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(5173, 0, 0x1, 0x101, ''), -- Baradin Guard
(5174, 0, 0x1, 0x101, ''), -- Baradin Guard
(5544, 0, 0x8, 0x1, ''), -- Baradin Recruit
(5545, 0, 0x8, 0x1, ''), -- Baradin Recruit
(5543, 0, 0x8, 0x1, ''), -- Baradin Recruit
(5549, 0, 0x8, 0x1, ''), -- Hellscream's Reach Recruit
(5548, 0, 0x8, 0x1, ''), -- Hellscream's Reach Recruit
(5038, 0, 0x3000000, 0x1, ''), -- Rustberg Gull
(5234, 0, 0x0, 0x1, ''); -- Crazed Guard


DELETE FROM `creature_equip_template` WHERE `entry` IN (47657, 47183, 47659, 47304, 47627, 47373, 47287, 47642, 46605, 47240, 48253, 48252, 48251, 50161, 47428, 46989, 47130, 46630, 47447, 46643, 46641, 46648, 46823, 46825, 46960, 46581, 48357, 48355, 46597, 48363, 48356, 50164, 45067, 45066);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(47657, 62229, 0, 0), -- Suspicious Villager
(47183, 15260, 13611, 0), -- Ghastly Worker
(47659, 768, 0, 0), -- Apprehensive Worker
(47304, 50043, 0, 0), -- Commander Largo
(47627, 11019, 11019, 0), -- Rustberg Bandit
(47373, 52526, 2081, 0), -- Warden's Sentry
(47287, 1469, 0, 0), -- Captain P. Harris
(47642, 45858, 0, 0), -- Rustberg Fisherman
(46605, 1469, 0, 0), -- Shipwrecked Sailor
(47240, 49684, 0, 0), -- Commander Marcus Johnson
(48253, 52526, 28754, 58173), -- Baradin Guard
(48252, 37, 0, 0), -- Baradin Recruit
(48251, 5956, 0, 0), -- Kevin Geissler
(50161, 17282, 0, 0), -- Dar Rummond
(47428, 42209, 2081, 0), -- Hellscream's Sentry
(46989, 2695, 0, 0), -- Crazed Soldier
(47130, 0, 0, 53569), -- Crazed Guard
(46630, 1911, 0, 0), -- Accursed Longshoreman
(47447, 29410, 0, 0), -- Keep Lord Farson
(46643, 5956, 0, 0), -- Accursed Shipbuilder
(46641, 0, 3757, 0), -- Ghastly Dockhand
(46648, 29408, 0, 52355), -- Foreman Wellson
(46823, 18596, 15512, 0), -- Restless Infantry
(46825, 5301, 0, 0), -- Restless Soldier
(46960, 1911, 0, 0), -- Ghastly Scavenger
(46581, 12890, 0, 0), -- Violated Corpse
(48357, 5956, 0, 0), -- Hellscream's Reach Recruit
(48355, 42209, 42561, 58173), -- Hellscream Guard
(46597, 56696, 0, 0), -- Skeletal Beastmaster
(48363, 47031, 0, 0), -- Captain Prug
(48356, 5956, 0, 0), -- Karosh
(50164, 17282, 0, 0), -- Tulgar Flamefist
(45067, 13337, 0, 0), -- Horde Spirit Guide
(45066, 12591, 0, 0); -- Alliance Spirit Guide


SET @Axe := 22;
SET @Broom := 393;
SET @Mace := 79;
SET @Pick := 40;
SET @RollingPin := 837;
SET @WorkWrench := 47657;

UPDATE `creature` SET `equipment_id`=@Axe WHERE `guid`=4972;
UPDATE `creature` SET `equipment_id`=@Axe WHERE `guid`=4988;
UPDATE `creature` SET `equipment_id`=@Axe WHERE `guid`=4996;
UPDATE `creature` SET `equipment_id`=@Broom WHERE `guid`=4965;
UPDATE `creature` SET `equipment_id`=@Broom WHERE `guid`=5011;
UPDATE `creature` SET `equipment_id`=@Mace WHERE `guid`=4978;
UPDATE `creature` SET `equipment_id`=@Pick WHERE `guid`=5010;
UPDATE `creature` SET `equipment_id`=@RollingPin WHERE `guid`=4930;
UPDATE `creature` SET `equipment_id`=@RollingPin WHERE `guid`=4974;
UPDATE `creature` SET `equipment_id`=@WorkWrench WHERE `guid`=4987;


UPDATE `creature_template` SET `equipment_id`=47183 WHERE `entry`=47183;
UPDATE `creature_template` SET `equipment_id`=47659 WHERE `entry`=47659;
UPDATE `creature_template` SET `equipment_id`=47304 WHERE `entry`=47304;
UPDATE `creature_template` SET `equipment_id`=47627 WHERE `entry`=47627;
UPDATE `creature_template` SET `equipment_id`=47373 WHERE `entry`=47373;
UPDATE `creature_template` SET `equipment_id`=47287 WHERE `entry`=47287;
UPDATE `creature_template` SET `equipment_id`=47642 WHERE `entry`=47642;
UPDATE `creature_template` SET `equipment_id`=46605 WHERE `entry`=46605;
UPDATE `creature_template` SET `equipment_id`=47240 WHERE `entry`=47240;
UPDATE `creature_template` SET `equipment_id`=48253 WHERE `entry`=48253;
UPDATE `creature_template` SET `equipment_id`=48252 WHERE `entry`=48252;
UPDATE `creature_template` SET `equipment_id`=48251 WHERE `entry`=48251;
UPDATE `creature_template` SET `equipment_id`=50161 WHERE `entry`=50161;
UPDATE `creature_template` SET `equipment_id`=47428 WHERE `entry`=47428;
UPDATE `creature_template` SET `equipment_id`=46989 WHERE `entry`=46989;
UPDATE `creature_template` SET `equipment_id`=47130 WHERE `entry`=47130;
UPDATE `creature_template` SET `equipment_id`=46630 WHERE `entry`=46630;
UPDATE `creature_template` SET `equipment_id`=47447 WHERE `entry`=47447;
UPDATE `creature_template` SET `equipment_id`=46643 WHERE `entry`=46643;
UPDATE `creature_template` SET `equipment_id`=46641 WHERE `entry`=46641;
UPDATE `creature_template` SET `equipment_id`=46648 WHERE `entry`=46648;
UPDATE `creature_template` SET `equipment_id`=46823 WHERE `entry`=46823;
UPDATE `creature_template` SET `equipment_id`=46825 WHERE `entry`=46825;
UPDATE `creature_template` SET `equipment_id`=46960 WHERE `entry`=46960;
UPDATE `creature_template` SET `equipment_id`=46581 WHERE `entry`=46581;
UPDATE `creature_template` SET `equipment_id`=48357 WHERE `entry`=48357;
UPDATE `creature_template` SET `equipment_id`=48355 WHERE `entry`=48355;
UPDATE `creature_template` SET `equipment_id`=46597 WHERE `entry`=46597;
UPDATE `creature_template` SET `equipment_id`=48363 WHERE `entry`=48363;
UPDATE `creature_template` SET `equipment_id`=48356 WHERE `entry`=48356;
UPDATE `creature_template` SET `equipment_id`=50164 WHERE `entry`=50164;
UPDATE `creature_template` SET `equipment_id`=45067 WHERE `entry`=45067;
UPDATE `creature_template` SET `equipment_id`=45066 WHERE `entry`=45066;
