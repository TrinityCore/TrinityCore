-- Leviathan Doors
DELETE FROM `gameobject` WHERE `id` = '194905';
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
('35528','194905','603','1','1','401.308','-13.8236','409.524','3.14159','0','0','0','1','180','255','0');

-- Thorim's Hammer
DELETE FROM `conditions` WHERE `SourceEntry` = 62911;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('13','0','62911','0','18','1','33365','0','0','',"Thorim Hammer");

-- Mimiron's Inferno
DELETE FROM `conditions` WHERE `SourceEntry` = 62909;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('13','0','62909','0','18','1','33370','0','0','',"Mimiron Inferno");

-- Hodir's Fury
DELETE FROM `conditions` WHERE `SourceEntry` = 62533;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('13','0','62533','0','18','1','33212','0','0','',"Hodirs Fury");

-- Freya's Ward
DELETE FROM `conditions` WHERE `SourceEntry` = 62906;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('13','0','62906','0','18','1','33367','0','0','',"Freya Ward");


UPDATE `creature_template` SET `speed_walk` = 2 WHERE `entry` IN (33370, 33212);
DELETE FROM creature WHERE guid IN (137479, 137480);

-- Boom Bot
DELETE FROM `smart_scripts` WHERE (`entryorguid`=33836);
INSERT INTO `smart_scripts` VALUES 
(33836, 0, 0, 1, 9, 0, 100, 1, 0, 2, 0, 0, 11, 63801, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Boom Bot - Explode'),
(33836, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Boom Bot - despawn');

-- Creatures and Gameobjects 25 man spawn
UPDATE `creature` SET `spawnMask` = 3 WHERE `map` = 603;
UPDATE `gameobject` SET `spawnMask` = 3 WHERE `map` = 603;

-- .tele Uld
DELETE FROM `game_tele` WHERE `name` = "Uld";
INSERT INTO `game_tele` VALUES
(NULL, 9347.78, -1114.88, 1245.09, 6.278, 571, 'Uld');

-- Salvaged Chopper has no heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 0 WHERE `entry` = 33062;

DELETE FROM `creature` WHERE `id` IN (33060, 33062, 33109);

-- Flame Leviathan
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235 WHERE `entry` IN (33113, 34003);

-- Mimiron
UPDATE `creature_template` SET `exp` = 0 WHERE `entry` IN (33432, 34106);
UPDATE `creature_template` SET `difficulty_entry_1` = 34114 WHERE `entry` = 33855;

-- remove Chest spawned
DELETE FROM `gameobject` WHERE `id` IN (195046, 195047, 194307, 194308);


DELETE FROM creature WHERE id = 33167;
UPDATE `creature_template` SET `modelid1` = 11686, `modelid2` = 0 WHERE `entry` IN (33364, 33369, 33108, 33366);

DELETE FROM vehicle_accessory WHERE entry = 33113 AND seat_id IN (0, 1);
INSERT INTO vehicle_accessory VALUES 
(33113, 33114, 0, 1, "Flame Leviathan"),
(33113, 33114, 1, 1, "Flame Leviathan");

UPDATE creature_model_info SET bounding_radius = 15, combat_reach = 10 WHERE modelid IN (29158, 29159, 29160);
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` = 33264; -- TODO
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_flame_leviathan_defense_cannon' WHERE `entry` = 33139;

-- Mimiron modelids
UPDATE `creature_model_info` SET `bounding_radius` = 0.775, `combat_reach` = 7 WHERE `modelid` = 28831;
UPDATE `creature_model_info` SET `bounding_radius` = 0.775, `combat_reach` = 5 WHERE `modelid` = 28841;
UPDATE `creature_model_info` SET `bounding_radius` = 0.775, `combat_reach` = 4 WHERE `modelid` = 28979;

-- Flame Leviathan
UPDATE `creature_template` SET `mingold` = 1450000, `maxgold` = 1750000 WHERE `entry` = 33113;
UPDATE `creature_template` SET `mingold` = 2450000, `maxgold` = 2750000 WHERE `entry` = 34003;
-- Razorscale
UPDATE `creature_template` SET `mingold` = 1450000, `maxgold` = 1750000 WHERE `entry` = 33186;
UPDATE `creature_template` SET `mingold` = 2450000, `maxgold` = 2750000 WHERE `entry` = 33724;
-- Ignis
UPDATE `creature_template` SET `mingold` = 1450000, `maxgold` = 1750000 WHERE `entry` = 33118;
UPDATE `creature_template` SET `mingold` = 2450000, `maxgold` = 2750000 WHERE `entry` = 33190;
UPDATE `creature_template` SET `mechanic_immune_mask` = 536872986 WHERE `entry` IN (34234, 34235, 33237, 34105);
-- Magma Rager
UPDATE `creature_template` SET `mechanic_immune_mask` = 131072 WHERE `entry` IN (34086, 34201);
-- Robots
UPDATE `creature_template` SET `mechanic_immune_mask` = 8405008 WHERE `entry` IN (34085, 34186, 34274, 34268, 34272, 34270);
-- XT-002
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235 WHERE `entry` IN (33293, 33885, 33329, 33995);
UPDATE `creature_template` SET `mingold` = 3450000, `maxgold` = 3750000 WHERE entry = 33885;
UPDATE `creature_template` SET `mingold` = 1450000, `maxgold` = 1750000 WHERE entry = 33293;
-- Lightning charged dwarf
UPDATE `creature_template` SET `equipment_id` = 870, `mechanic_immune_mask` = 5 WHERE `entry` = 34237;
UPDATE `creature_template` SET `equipment_id` = 870, `mechanic_immune_mask` = 5 WHERE `entry` = 34199;
-- Hardened Iron Golem
UPDATE `creature_template` SET `mingold` = 24200, `maxgold` = 26200, `mechanic_immune_mask` = 64 WHERE `entry` = 34229;
UPDATE `creature_template` SET `mingold` = 14200, `maxgold` = 16200, `mechanic_immune_mask` = 64 WHERE `entry` = 34190;
-- Iron Mender
UPDATE `creature_template` SET `mingold` = 24200, `maxgold` = 26200, `mechanic_immune_mask` = 1 WHERE `entry` = 34236;
UPDATE `creature_template` SET `mingold` = 14200, `maxgold` = 16200, `mechanic_immune_mask` = 1 WHERE `entry` = 34198;
-- Runed Etched
UPDATE `creature_template` SET `mingold` = 24200, `maxgold` = 26200, `mechanic_immune_mask` = 64 WHERE `entry` = 34245;
UPDATE `creature_template` SET `mingold` = 14200, `maxgold` = 16200, `mechanic_immune_mask` = 64 WHERE `entry` = 34196;
-- Chamber Overseer
UPDATE `creature_template` SET `mingold` = 14600, `maxgold` = 18200, `mechanic_immune_mask` = 33554496 WHERE `entry` = 34226;
UPDATE `creature_template` SET `mingold` = 14600, `maxgold` = 18200, `mechanic_immune_mask` = 33554496 WHERE `entry` = 34197;
-- Storm Tempered Keeper
UPDATE `creature_template` SET `mingold` = 271000, `maxgold` = 276000, `mechanic_immune_mask` = 545260304 WHERE `entry` IN (33700, 33723);
UPDATE `creature_template` SET `mingold` = 71000, `maxgold` = 76000, `mechanic_immune_mask` = 545260304 WHERE `entry` IN (33699, 33722);
-- Auriaya
UPDATE `creature_template` SET `mingold` = 1460000, `maxgold` = 1520000, `mechanic_immune_mask` = 617299807 WHERE `entry` = 33515;
UPDATE `creature_template` SET `mingold` = 3460000, `maxgold` = 3520000, `mechanic_immune_mask` = 617299807, `flags_extra` = 1 WHERE `entry` = 34175;
-- Sanctum Sentry
UPDATE `creature_template` SET `baseattacktime` = 1500, `speed_walk` = 1.66667, `flags_extra` = 1 WHERE `entry` IN (34014, 34166);
-- Champion of Hodir
UPDATE `creature_template` SET `mingold` = 371000, `maxgold` = 376000, `mechanic_immune_mask` = 545267736 WHERE `entry` = 34139;
UPDATE `creature_template` SET `mingold` = 171000, `maxgold` = 176000, `mechanic_immune_mask` = 545267736 WHERE `entry` = 34133;
-- Winter revenant
UPDATE `creature_template` SET `mingold` = 171000, `maxgold` = 176000, `mechanic_immune_mask` = 2128 WHERE `entry` = 34141;
UPDATE `creature_template` SET `mingold` = 71000, `maxgold` = 76000, `mechanic_immune_mask` = 2128 WHERE `entry` = 34134;
-- Winter Rumbler
UPDATE `creature_template` SET `mingold` = 30300, `maxgold` = 32000, `mechanic_immune_mask` = 33554432 WHERE `entry` = 34142;
UPDATE `creature_template` SET `mingold` = 10300, `maxgold` = 12000, `mechanic_immune_mask` = 33554432 WHERE `entry` = 34135;
-- Arachnopod
UPDATE `creature_template` SET `mingold` = 205000, `maxgold` = 225000, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34214;
UPDATE `creature_template` SET `mingold` = 105000, `maxgold` = 125000, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34183;
-- Clockwork
UPDATE `creature_template` SET `mingold` = 17200, `maxgold` = 17600, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34184;
UPDATE `creature_template` SET `mingold` = 27200, `maxgold` = 27600, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34219;
-- Boomer XP-500
UPDATE `creature_template` SET `mechanic_immune_mask` = 8405008 WHERE `entry` = 34216;
UPDATE `creature_template` SET `mechanic_immune_mask` = 8405008 WHERE `entry` = 34192;
-- Trash
UPDATE `creature_template` SET `mechanic_immune_mask` = 8405008 WHERE `entry` = 34191;
UPDATE `creature_template` SET `mechanic_immune_mask` = 8405008 WHERE `entry` = 34217;
-- Clockwork sapper
UPDATE `creature_template` SET `mingold` = 37000, `maxgold` = 38200, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34220;
UPDATE `creature_template` SET `mingold` = 17000, `maxgold` = 18200, `mechanic_immune_mask` = 8405008 WHERE `entry` = 34193;
-- Elders
UPDATE `creature_template` SET `mingold` = 625000, `maxgold` = 665000, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` IN (32914, 32913, 33391);
UPDATE `creature_template` SET `mingold` = 1805000, `maxgold` = 1855000, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` IN (33393, 33392, 33391);
-- Freya trash
UPDATE `creature_template` SET `mingold` = 625000, `maxgold` = 655000 WHERE `entry` = 33732;
UPDATE `creature_template` SET `mingold` = 75000, `maxgold` = 95000 WHERE `entry` = 33731;
UPDATE `creature_template` SET `mingold` = 125000, `maxgold` = 155000 WHERE `entry` IN (33733, 33734);
UPDATE `creature_template` SET `mingold` = 125000, `maxgold` = 155000 WHERE `entry` IN (33741, 33729);
UPDATE `creature_template` SET `mingold` = 125000, `maxgold` = 155000 WHERE `entry` IN (33735, 33737);
-- Dark Rune Thunderer, Ravager
UPDATE `creature_template` SET `baseattacktime` = 1500, `mechanic_immune_mask` = 545259541 WHERE `entry` IN (33754, 33755);
UPDATE `creature_template` SET `baseattacktime` = 1500, `mingold` = 71000, `maxgold` = 76000, `mechanic_immune_mask` = 545259541 WHERE `entry` = 33757;
UPDATE `creature_template` SET `baseattacktime` = 1500, `mingold` = 71000, `maxgold` = 76000, `mechanic_immune_mask` = 545259541 WHERE `entry` = 33758;
-- Twilight mobs
UPDATE `creature_template` SET `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 570425425 WHERE `entry` IN (33818, 33822, 33824, 33823);
UPDATE `creature_template` SET `mingold` = 272000, `maxgold` = 276000, `mechanic_immune_mask` = 570425425 WHERE `entry` = 33827;
UPDATE `creature_template` SET `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 570425425 WHERE `entry` = 33828;
UPDATE `creature_template` SET `baseattacktime` = 1000, `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 570425425 WHERE `entry` = 33831;
UPDATE `creature_template` SET `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 570425425 WHERE `entry` = 33832;
UPDATE `creature_template` SET `mingold` = 76000, `maxgold` = 79000, `mechanic_immune_mask` = 33554512 WHERE `entry` = 33773;
UPDATE `creature_template` SET `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 8388625 WHERE `entry` = 33830;
UPDATE `creature_template` SET `mingold` = 72000, `maxgold` = 76000, `mechanic_immune_mask` = 8388625 WHERE `entry` = 33829;
UPDATE `creature_template` SET `mingold` = 41000, `maxgold` = 46000, `mechanic_immune_mask` = 8519697 WHERE `entry` = 33839;
-- Hodir
UPDATE `creature_template` SET `mingold` = 0, `maxgold` = 0 WHERE `entry` IN (32845, 32846);
-- General Vezax
UPDATE `creature_template` SET `mingold` = 3450000, `maxgold` = 3750000, `mechanic_immune_mask` = 617299803, `flags_extra` = 257 WHERE `entry` = 33449;
UPDATE `creature_template` SET `mingold` = 1450000, `maxgold` = 1750000 WHERE `entry` = 33271;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235 WHERE `entry` = 33789;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 256 WHERE `entry` = 33524;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 256 WHERE `entry` = 34152;

-- XT-002 correct vehicle id
UPDATE `creature_template` SET `VehicleId` = 353 WHERE `entry` = 33293;
-- XT-002 Hearth
DELETE FROM `vehicle_accessory` WHERE `entry` = 33293;
INSERT INTO `vehicle_accessory` VALUES 
(33293, 33329, 0, 1, "XT-002 Hearth");
-- Gravity Bomb
DELETE FROM spell_script_names WHERE spell_id IN (63025, 64233);
INSERT INTO spell_script_names VALUES 
(63025, "spell_xt002_gravity_bomb"),
(64233, "spell_xt002_gravity_bomb");

