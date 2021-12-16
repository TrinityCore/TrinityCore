-- Mage-Commander Evenstar
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26873;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = "29266" WHERE `entry` = 26873;

-- Slinkin the Demo-gnome
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27412;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = "29266" WHERE `entry` = 27412;

-- Skirmisher Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27457;

-- Slain Trapper
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 27479;

-- Westfall Infantry Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27481;

-- Dead Caribou
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27610;
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 27610;

-- Slaughtered Drakkari
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `dynamicflags` = 0 WHERE `entry` = 27613;

-- Venomspite Riding Bat
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27787;

-- Plunderbeard
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 27828;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = "29266" WHERE `entry` = 27828;

-- Destroyed Siege Tank
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28150;

-- Drakkari Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28162;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 28162;

-- Defeated Argent Footman
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28260;
UPDATE `creature_template_addon` SET `bytes1` = 0, `auras` = "29266 51133" WHERE `entry` = 28260;
-- Native model, 328 is disabled
UPDATE `creature` SET `modelid` = 19595 WHERE `id` = 28260;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 28259 WHERE `Id` = 51133;

-- Death Knight Initiate
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28390;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28392;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28393;

-- Dead Mam'toth Disciple
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28852;
UPDATE `creature_template_addon` SET `auras` = "52574 29266 52558" WHERE `entry` = 28852;
-- Native model, 169 is disabled
UPDATE `creature` SET `modelid` = 11686 WHERE `id` = 28852;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 28853 WHERE `Id` = 52558;

-- Scarlet Fleet Guardian
-- Scarlet Land Cannon
-- Scarlet Fleet Defender
-- Scarlet Cannon
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28884;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28885;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28886;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28887;

-- Scarlet Miner
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28891;

-- Scarlet Peasant
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28892;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 28892);
DELETE FROM `creature_template_addon` WHERE `entry` = 28892;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(28892,0,0,0,1,0,0,"29266");

-- Scarlet Gryphon
-- Scarlet Medic
-- Scarlet Infantryman
-- Scarlet Captain
-- Scarlet Inquisitor
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28893;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28895;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28896;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28898;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 29029;

-- Burr
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29454;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 29454);
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 29454;

-- Frostworg Carcass
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29543;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 29543);
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = "29266" WHERE `entry` = 29543;

-- Dead Frost Giant
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29544;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 29544);
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = "29266" WHERE `entry` = 29544;

-- Proto-Drake Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29545;

-- K3 Snow Runner
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 29546;

-- Dead Drakerider
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29571;

-- Field Corpse (Type A)
-- Field Corpse (Type B)
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 29916;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 29917;

-- Ravaged Cavedweller Worg
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 30177;

-- Dead Icemaw Bear
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 30292;
UPDATE `smart_scripts` SET `action_param2` = 2 WHERE `entryorguid` = 30292 AND `source_type` = 0 AND `id` = 0;

-- Forgotten Depths Slayer
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 30673;

-- Frostbrood Destroyer
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 30674;

-- Wrathgate
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` IN (31285,31292,31293,31294,31295,31296,31297,31298,31299,31308,31309);

-- Wrecked Demolisher
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 31868;

-- Wracked Prisoner
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 32275;
UPDATE `creature_addon` SET `auras` = "29266" WHERE `guid` IN (121056,121064,121070);

-- Corpse of the Fallen Worg
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 32569;

-- Wrecked Demolisher
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `unit_flags2` = `unit_flags2` &~ 1, `dynamicflags` = 0 WHERE `entry` = 33059;

-- Wrecked Siege Engine
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `unit_flags2` = `unit_flags2` &~ 1, `dynamicflags` = 0 WHERE `entry` = 33063;
