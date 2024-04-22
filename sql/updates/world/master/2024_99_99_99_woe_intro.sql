SET @CGUID := 80000000;
SET @OGUID := 80000000;
SET @NPCTEXTID := 80000000;

-- Instance
UPDATE `instance_template` SET `script` = 'instance_well_of_eternity' WHERE `map` = 939;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 57864, 939, 5788, 5993, '2', 0, 0, 0, 0, 3242.23779296875, -4975.25537109375, 195.4101104736328125, 4.363323211669921875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 52485); -- Alurmi (Area: Courtyard of Lights - Difficulty: 0) CreateObject1 (Auras: 49414 - Generic Quest Invisibility 1)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '49414'); -- Alurmi - 49414 - Generic Quest Invisibility 1

UPDATE `creature_template` SET `ScriptName` = 'npc_woe_nozdormu' WHERE `entry` = 55624;
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=4196352 WHERE `entry`=55656; -- Dreadlord Defender
UPDATE `creature_template` SET `BaseAttackTime`=2001980, `unit_flags`=2181071616, `unit_flags2`=4194304, `unit_flags3`=1, `ScriptName`='boss_peroth_arn' WHERE `entry`=55085; -- Peroth'arn
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=4196352, `ScriptName`='npc_woe_legion_demon' WHERE `entry`=55503; -- Legion Demon
UPDATE `creature_template_addon` SET `VisFlags`=1 WHERE `entry`=57864; -- 57864 (Alurmi) - Generic Quest Invisibility 1
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=56389; -- Shadowcloak Illidan Helper Stalker PH
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=55154; -- Shadowcloak Helper Stalker PH
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2099200, `ScriptName`='npc_illidan_stormrage_courtyard_of_lights' WHERE `entry`=55500; -- Illidan Stormrage
UPDATE `creature_template` SET `speed_walk`=1.399999976158142089, `speed_run`=0.5, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=524289, `ScriptName` = 'npc_distract_demon_stalker' WHERE `entry`=58200; -- Distract Demon Stalker
UPDATE `creature_template` SET `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=54506; -- Well of Eternity Stalker
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=4196352 WHERE `entry`=55654; -- Corrupted Arcanist
UPDATE `creature_template` SET `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=54500; -- Legion Demon

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (58200,55154,56389,55500,55091));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(58200, 2, 0, 0, 1108, 0, 0, 0, 0, 0, 0, 0, 0, 52649), -- Distract Demon Stalker
(55154, 2, 0, 0, 1108, 536871168, 0, 0, 0, 0, 0, 0, 0, 52649), -- Shadowcloak Helper Stalker PH
(56389, 2, 0, 0, 1108, 536871168, 0, 0, 0, 0, 0, 0, 0, 52649), -- Shadowcloak Illidan Helper Stalker PH
(55500, 2, 0, 0, 1108, 268435456, 0, 0, 0, 0, 0, 0, 0, 52649), -- Illidan Stormrage
(55091, 2, 0, 0, 328, 536870912, 0, 0, 0, 0, 0, 0, 0, 52649); -- General Purpose Bunny JMF (Look 2 - Flying, Infinite AOI)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `StaticFlags3`=262144, `VerifiedBuild`=52649 WHERE (`Entry`=55532 AND `DifficultyID`=2); -- Illidan Stormrage
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52649 WHERE (`DifficultyID`=2 AND `Entry` IN (54969,56096,55503,54513,54500,54927,55656,54506,53488));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=52649 WHERE (`Entry`=57458 AND `DifficultyID`=2); -- Shadowbat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`DifficultyID`=2 AND `Entry` IN (56579,54589)); -- Enchanted Highmistress
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`DifficultyID`=2 AND `Entry` IN (54884,54882,54883)); -- Enchanted Magus
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=52649 WHERE (`Entry`=54853 AND `DifficultyID`=2); -- Queen Azshara
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=54747 AND `DifficultyID`=2); -- Eye of the Legion
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=54612 AND `DifficultyID`=2); -- Eternal Champion
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=55085 AND `DifficultyID`=2); -- Peroth'arn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=55624 AND `DifficultyID`=2); -- Nozdormu
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=55543 AND `DifficultyID`=2); -- Portal Connector 3 PH
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=55965 AND `DifficultyID`=2); -- Fel Crystal Stalker PH
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=55542 AND `DifficultyID`=2); -- Portal Connector 2 PH
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=55917 AND `DifficultyID`=2); -- Fel Crystal WoT PH
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1110, `StaticFlags1`=805306368, `VerifiedBuild`=52649 WHERE (`Entry`=57864 AND `DifficultyID`=2); -- Alurmi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=55541 AND `DifficultyID`=2); -- Portal Connector 1 PH

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=55624 AND `MenuID`=13412) OR (`CreatureID`=55500 AND `MenuID` IN (13359,13162, 13395));
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(55624, 13412, 52485), -- Nozdormu
(55500, 13359, 52485), -- Illidan Stormrage
(55500, 13162, 52485), -- Illidan Stormrage
(55500, 13395, 52649); -- Illidan Stormrage

DELETE FROM `gossip_menu` WHERE (`MenuID`=13412 AND `TextID`=18851) OR (`MenuID`=13163 AND `TextID`=18551) OR (`MenuID`=13162 AND `TextID`=18550) OR (`MenuID`=13359 AND `TextID`=18551) OR (`MenuID`=13395 AND `TextID`=19024);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(13412, 18851, 52485), -- 55624 (Nozdormu)
(13163, 18551, 52485), -- 55500 (Illidan Stormrage)
(13162, 18550, 52485), -- 55500 (Illidan Stormrage)
(13359, 18551, 52485), -- 55500 (Illidan Stormrage)
(13395, 19024, 52649); -- 55500 (Illidan Stormrage)

DELETE FROM `npc_text` WHERE `ID` IN (18550, 18551, 19024);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(18551, 1, 0, 0, 0, 0, 0, 0, 0, 54226, 0, 0, 0, 0, 0, 0, 0, 52485), -- 55500 (Illidan Stormrage)
(18550, 1, 0, 0, 0, 0, 0, 0, 0, 54224, 0, 0, 0, 0, 0, 0, 0, 52485),
(19024, 1, 0, 0, 0, 0, 0, 0, 0, 56957, 0, 0, 0, 0, 0, 0, 0, 52485); -- 55500 (Illidan Stormrage)

DELETE FROM `gossip_menu_option` WHERE `MenuID`IN (13162, 13163) AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(13162, 39551, 0, 0, 'I am ready to be hidden by your shadowcloak.', 54246, 0, 0, 13163, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 52649),
(13163, 39656, 0, 0, 'Let\'s go!', 54247, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 52649);

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` = 57864);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(57864, 2, 3, 2, 1, 26030, 0, 0); -- Alurmi

DELETE FROM `creature_template_addon` WHERE `entry` IN (55654, 56389, 55500, 55154, 58200, 54506);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(55654, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '110048 107877'), -- 55654 (Corrupted Arcanist) - Corrupted Night Elf Eyes, Disciplined Caster
(56389, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '105924'), -- 56389 (Shadowcloak Illidan Helper Stalker PH) - Shadowcloak Illidan Stalker Cosmetic
(55500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '105915 42459'), -- Illidan Stormrage - 105915 - Shadowcloak
(55154, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '102951'), -- 55154 (Shadowcloak Helper Stalker PH) - Shadowcloak Stalker Cosmetic
(58200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 58200 (Distract Demon Stalker)
(54506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 54506 (Well of Eternity Stalker)

UPDATE `creature` SET `unit_flags` = 768, `StringId` = 'legion_demon_woe_intro' WHERE `guid` = 358739;
UPDATE `creature` SET `unit_flags` = 768, `StringId` = 'dreadlord_defender_woe_intro_1' WHERE `guid` = 358724;
UPDATE `creature` SET `unit_flags` = 768, `StringId` = 'dreadlord_defender_woe_intro_2' WHERE `guid` = 358728;
UPDATE `creature` SET `unit_flags` = 768, `StringId` = 'corrupted_arcanist_woe_intro' WHERE `guid` = 358730;
UPDATE `creature` SET `unit_flags` = 768 WHERE `guid` = 358741;
UPDATE `creature` SET `StringId` = 'wall_of_shadow_stalker' WHERE `guid` = 358752;
UPDATE `creature` SET `StringId` = 'crystal_1_creature' WHERE `guid` IN (358723, 358722, 358726);

-- Double spawn
DELETE FROM `creature` WHERE `guid` = 358830;
-- Illidan is summoned, not spawned
DELETE FROM `creature` WHERE `guid` IN (358828, 358831, 358834, 358838);

DELETE FROM `creature_text` WHERE `CreatureID` IN (55624, 55085, 55500);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(55624, 0, 0, 'I see you\'ve arrived. This is the eve of the sundering, when the collapse of the Well of Eternity fractured the continents of the world.', 12, 0, 100, 0, 0, 25961, 55271, 0, 'Nozdormu to Player'),
(55624, 1, 0, 'Here, we will snatch up the Dragon Soul before it is lost to the mists of time.', 12, 0, 100, 0, 0, 25962, 55304, 0, 'Nozdormu to Player'),
(55624, 2, 0, 'But first, you must bring down the protective wards of Azshara\'s Highborne lackeys. You will find them within the palace. I will scout on ahead.', 12, 0, 100, 0, 0, 25963, 55305, 0, 'Nozdormu to Player'),
(55624, 3, 0, 'Good luck, heroes!', 12, 0, 100, 0, 0, 25964, 55306, 0, 'Nozdormu to Player'),
(55085, 0, 0, 'He is near, lurking in the shadows... I can sense it.', 12, 0, 100, 0, 0, 26118, 54683, 2, 'Peroth\'arn to Player'),
(55085, 1, 0, 'You, Felguard.  Hold this area.', 12, 0, 100, 0, 0, 26120, 54685, 2, 'Peroth\'arn to Player'),
(55085, 2, 0, 'The rest of you, secure the courtyard.', 12, 0, 100, 0, 0, 26121, 54687, 2, 'Peroth\'arn to Player'),
(55500, 0, 0, 'Over here, in the shadows.', 12, 0, 100, 0, 0, 26076, 54274, 2, 'Illidan Stormrage to Player'),
(55500, 1, 0, 'I think we stand a better chance fighting alongside one another.', 12, 0, 100, 0, 0, 26525, 54277, 2, 'Illidan Stormrage to Player'),
(55500, 2, 0, 'Explain your presence.', 12, 0, 33, 0, 0, 26080, 54835, 2, 'Illidan Stormrage to Player'),
(55500, 2, 1, 'Talk with me now.', 12, 0, 33, 0, 0, 26523, 54836, 2, 'Illidan Stormrage to Player'),
(55500, 2, 2, 'Are you here to help?', 12, 0, 33, 0, 0, 26524, 54837, 2, 'Illidan Stormrage to Player'),
(55500, 3, 0, 'We now hide in shadows, hidden from our enemies.', 12, 0, 100, 0, 0, 26054, 54705, 2, 'Illidan Stormrage to Player'),
(55500, 4, 0, 'Come with me if you\'d like to live long enough to see me save this world!', 12, 0, 100, 0, 0, 26065, 54284, 2, 'Illidan Stormrage to Player'),
(55500, 5, 0, 'So many demons, not enough time.', 12, 0, 50, 0, 0, 26066, 54288, 2, 'Illidan Stormrage to Player'),
(55500, 5, 1, 'I\'ve seen a single Guardian Demon slaughter a hundred elves. Tread lightly.', 12, 0, 50, 0, 0, 26068, 54296, 2, 'Illidan Stormrage to Player'),
(55500, 6, 0, 'I will hold them back so we can get past. Be ready.', 12, 0, 100, 0, 0, 26063, 54297, 2, 'Illidan Stormrage to Player'),
(55500, 7, 0, 'My magic is fading. I\'m going through!', 12, 0, 100, 0, 0, 26064, 54299, 2, 'Illidan Stormrage to Illidan Stormrage'),
(55500, 8, 0, 'Attack. I don\'t like to be kept waiting.', 12, 0, 100, 0, 0, 26081, 54304, 2, 'Illidan Stormrage to Illidan Stormrage'),
(55500, 9, 0, 'My blades hunger.', 12, 0, 100, 0, 0, 26057, 54503, 2, 'Illidan Stormrage to Corrupted Arcanist'),
(55500, 9, 1, 'Death to the Legion!', 12, 0, 100, 0, 0, 26056, 54444, 2, 'Illidan Stormrage to Dreadlord Defender'),
(55500, 10, 0, 'Destroy the crystal so we can move on.', 12, 0, 100, 0, 0, 26103, 54468, 2, 'Illidan Stormrage to Dreadlord Defender'),
(55500, 11, 0, 'We\'re leaving. Stay close.', 12, 0, 100, 0, 0, 26055, 54511, 2, 'Illidan Stormrage to Player'),
(55500, 12, 0, 'They come endlessly from the palace.', 12, 0, 50, 0, 0, 26069, 54510, 2, 'Illidan Stormrage to Player'),
(55500, 12, 1, 'They will get what they deserve, in due time.', 12, 0, 50, 0, 0, 26067, 54292, 2, 'Illidan Stormrage to Player'),
(55500, 13, 0, 'I\'ll let you have the first kill.  Don\'t make me regret that.', 12, 0, 100, 0, 0, 26082, 54308, 2, 'Illidan Stormrage to Player'),
(55500, 15, 0, 'Smash the crystal. We need to move.', 12, 0, 100, 0, 0, 26104, 54709, 2, 'Illidan Stormrage to Dreadlord Defender'),
(55500, 16, 0, 'The stench of sulfur and brimstone... These portals are as foul as the demons themselves.', 12, 0, 100, 0, 0, 26070, 54512, 2, 'Illidan Stormrage to Player'),
(55500, 17, 0, 'Cut this one down from the shadows.', 12, 0, 100, 0, 0, 26071, 54514, 2, 'Illidan Stormrage to Player'),
(55500, 18, 0, 'Let us shut down this final portal and finish this.', 12, 0, 100, 0, 0, 26072, 54736, 2, 'Illidan Stormrage to Legion Demon'),
(55500, 19, 0, 'They stand unaware that their deaths are moments away.', 12, 0, 100, 0, 0, 26101, 54575, 2, 'Illidan Stormrage to Legion Demon'),
(55500, 20, 0, 'Destroy the portal energy focus!', 12, 0, 100, 0, 0, 26105, 54710, 2, 'Illidan Stormrage to Dreadlord Defender'),
(55500, 21, 0, 'The demons should all be leaving. We will be at the palace in no time.', 12, 0, 100, 0, 0, 26073, 54750, 2, 'Illidan Stormrage to Player'),
(55500, 22, 0, 'The demons are no longer pouring from the palace. We can move ahead.', 12, 0, 100, 0, 0, 26074, 54572, 2, 'Illidan Stormrage to Player'),
(55500, 23, 0, 'Too easy.', 12, 0, 100, 0, 0, 26075, 54573, 2, 'Illidan Stormrage to Player'),
(55500, 24, 0, 'Another demon, ready to be slaughtered.', 12, 0, 100, 0, 0, 26050, 54574, 2, 'Illidan Stormrage to Player'),
(55500, 25, 0, 'Waiting to attack...', 12, 0, 100, 0, 0, 26100, 54302, 2, 'Illidan Stormrage to Player'),
(55500, 26, 0, 'The hunter became the prey.', 12, 0, 100, 0, 0, 26051, 54838, 2, 'Illidan Stormrage to Peroth\'arn'),
(55500, 27, 0, 'You did well, but for now I must continue alone. Good hunting.', 12, 0, 100, 0, 0, 26052, 54839, 2, 'Illidan Stormrage to Player');

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=55500 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(55500, 56389, 0, 1, 'Illidan Stormrage - Shadowcloak Illidan Helper Stalker PH', 8, 0); -- Illidan Stormrage - Shadowcloak Illidan Helper Stalker PH

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=55500 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55500, 46598, 0, 0);

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`IN (7387, 7029, 7066, 7144);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7387, 'at_woe_nozdormu_intro'),
(7029, 'at_woe_perotharn_intro'),
(7066, 'at_woe_illidan_intro'),
(7144, 'at_woe_illidan_skip_talk');

-- GameObjects
UPDATE `gameobject` SET `state` = 0 WHERE `id` = 210234;
UPDATE `gameobject` SET `state` = 1 WHERE `guid` = 224470;
UPDATE `gameobject` SET `state` = 1 WHERE `guid` = 224472;
UPDATE `gameobject` SET `state` = 0 WHERE `id` = 210130;

UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry` IN (210000, 209997, 209998); -- Time Transit Device
UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=209937; -- Doodad_WoE_Palace_Doors01
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry`=210234; -- Large Firewall Door
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209366; -- Portal Energy Focus

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id` IN (105247, 105243, 103004, 110755, 110121, 110103, 104400);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(105247,'spell_woe_summon_fel_firewall_cosmetic_ph'),
(105243,'spell_woe_summon_fire_wall'),
(103004, 'spell_woe_shadowcloak'),
(110755, 'spell_woe_shadowcloak_dismount'),
(110121, 'spell_woe_distract_demon_missile'),
(110103, 'spell_woe_distract_demon_missile'),
(104400, 'spell_woe_wall_of_shadow');

DELETE FROM `serverside_spell` WHERE `Id` IN (110755, 110103) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(110755, 0, 0, 0, 0, (0x20000100), (0x10008800), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 327, 1, 0, 0, 0, -1, 0, 0, 0, 'Shadowcloak Dismount', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (0x1), 0),
(110103, 0, 0, 0, 0, (0x4000100), 0, 0, 0, 0, 0, 0, 0, 0, 0, (0x40), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 152, 0, 0, 0, -1, 0, 0, 0, 'Distract Demon Summon', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (0x1), 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (110755, 110103, 59632) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(110755, 0, 0, 6, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(110103, 0, 0, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58200, 3139, 0, 0, 0, 0, 0, 0, 46, 0),
(59632, 0, 0, 6, 61, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=110103;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 110103, 0, 0, 51, 0, 5, 54506, 0, 0, 0, 0, '', 'Spell \'Distract Demon Summon\' can only hit npc \'Well of Eternity Stalker\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=110121;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 110121, 0, 0, 51, 0, 5, 54506, 0, 0, 0, 0, '', 'Spell \'Distract Demon Missile\' can only hit npc \'Well of Eternity Stalker\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=104400;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 104400, 0, 0, 51, 0, 5, 55500, 0, 0, 0, 0, '', 'Spell \'Wall of Shadow\' can only hit npc \'Illidan Stormrage\'');

-- Waypoints
SET @ENTRY := 55656;
SET @PATHOFFSET := 0;
SET @PATH_DREADLORD_DEFENDER_1 := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_DREADLORD_DEFENDER_1;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_DREADLORD_DEFENDER_1, 1, 0, 'Well of Eternity Intro - Dreadlord Defender Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_DREADLORD_DEFENDER_1;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_DREADLORD_DEFENDER_1, 0, 3196.999, -4934.864, 190.3811, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 1, 3195.483, -4926.509, 194.1676, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 2, 3194.852, -4918.588, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 3, 3199.403, -4912.055, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 4, 3206.897, -4907.776, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 5, 3215.504, -4905.563, 194.1677, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 6, 3224.552, -4905.381, 190.6194, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 7, 3233.596, -4905.18, 185.7695, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 8, 3242.761, -4905.245, 180.9809, NULL, 0),
(@PATH_DREADLORD_DEFENDER_1, 9, 3249.303, -4905.292, 181.0348, NULL, 0);

SET @ENTRY := 55656;
SET @PATHOFFSET := 1;
SET @PATH_DREADLORD_DEFENDER_2 := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_DREADLORD_DEFENDER_2;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_DREADLORD_DEFENDER_2, 1, 0, 'Well of Eternity Intro - Dreadlord Defender Path 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_DREADLORD_DEFENDER_2;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_DREADLORD_DEFENDER_2, 0, 3189.994, -4935.834, 189.8608, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 1, 3188.416, -4926.269, 194.1676, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 2, 3188.998, -4914.624, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 3, 3195.964, -4905.876, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 4, 3205.412, -4900.862, 194.3566, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 5, 3215.362, -4898.493, 194.1677, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 6, 3224.41, -4898.311, 190.6954, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 7, 3233.646, -4898.109, 185.7427, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 8, 3242.812, -4898.174, 180.9809, NULL, 0),
(@PATH_DREADLORD_DEFENDER_2, 9, 3249.353, -4898.221, 180.9809, NULL, 0);

SET @ENTRY := 55654;
SET @PATHOFFSET := 0;
SET @PATH_CORRUPTED_ARCANIST := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_CORRUPTED_ARCANIST;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_CORRUPTED_ARCANIST, 1, 0, 'Well of Eternity Intro - Corrupted Arcanist Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_CORRUPTED_ARCANIST;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_CORRUPTED_ARCANIST, 0, 3197.919, -4941.1826, 189.7942, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 1, 3195.669, -4938.9326, 189.7942, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 2, 3193.669, -4935.4326, 189.7942, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 3, 3192.169, -4924.4326, 194.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 4, 3192.669, -4915.9326, 194.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 5, 3196.919, -4909.4326, 194.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 6, 3206.169, -4904.4326, 194.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 7, 3217.169, -4901.9326, 194.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 8, 3234.169, -4901.6826, 187.5442, NULL, 0),
(@PATH_CORRUPTED_ARCANIST, 9, 3252.863, -4901.7812, 180.9809, NULL, 0);

SET @ENTRY := 55503;
SET @PATHOFFSET := 0;
SET @PATH_LEGION_DEMON := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_LEGION_DEMON;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_LEGION_DEMON, 1, 0, 'Well of Eternity Intro - Legion Demon Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_LEGION_DEMON;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_LEGION_DEMON, 0, 3186.113, -4938.482, 189.5661, NULL, 0),
(@PATH_LEGION_DEMON, 1, 3193.363, -4939.232, 189.5661, NULL, 0),
(@PATH_LEGION_DEMON, 2, 3195.613, -4940.482, 189.5661, NULL, 0),
(@PATH_LEGION_DEMON, 3, 3196.917, -4942.767, 189.5242, NULL, 0);

-- Illidan paths
SET @ENTRY := 55500;
SET @PATHOFFSET := 0;
SET @PATH_ILLIDAN_INTRO := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_ILLIDAN_INTRO;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_ILLIDAN_INTRO, 1, 0, 'Well of Eternity - Illidan Intro Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_ILLIDAN_INTRO;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_ILLIDAN_INTRO, 0, 3176.041, -4876.092, 194.6482, NULL, 0),
(@PATH_ILLIDAN_INTRO, 1, 3182.291, -4879.842, 194.6482, NULL, 0),
(@PATH_ILLIDAN_INTRO, 2, 3188.541, -4884.592, 194.6482, NULL, 0),
(@PATH_ILLIDAN_INTRO, 3, 3193.041, -4891.592, 194.6482, NULL, 0),
(@PATH_ILLIDAN_INTRO, 4, 3194.407, -4898.674, 194.3566, NULL, 0);

SET @ENTRY := 55500;
SET @PATHOFFSET := 1;
SET @PATH_ILLIDAN_ESCORT := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_ILLIDAN_ESCORT;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_ILLIDAN_ESCORT, 1, 0, 'Well of Eternity - Illidan Escort Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_ILLIDAN_ESCORT;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_ILLIDAN_ESCORT, 0, 3202.834, -4895.062, 194.6102, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 1, 3210.013, -4895.25,  194.3639, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 2, 3212.345, -4895.312, 194.4206, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 3, 3217.845, -4895.812, 194.4206, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 4, 3246.165, -4895.874, 181.4172, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 5, 3255.317, -4898.928, 181.0766, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 6, 3284.379, -4899.672, 181.3266, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 7, 3291.629, -4898.922, 181.3266, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 8, 3293.629, -4899.672, 181.3266, NULL, 0),
(@PATH_ILLIDAN_ESCORT, 9, 3294.941, -4901.915, 181.0767, NULL, 0);

SET @ENTRY := 55500;
SET @PATHOFFSET := 2;
SET @PATH_ILLIDAN_CRYSTAL_1 := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH_ILLIDAN_CRYSTAL_1;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH_ILLIDAN_CRYSTAL_1, 1, 0, 'Well of Eternity - Illidan Path to crystal #1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH_ILLIDAN_CRYSTAL_1;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH_ILLIDAN_CRYSTAL_1, 0, 3299.646, -4905.302, 181.3267, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 1, 3303.896, -4914.052, 181.3267, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 2, 3308.850, -4924.189, 181.0767, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 3, 3309.388, -4929.150, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 4, 3309.138, -4936.400, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 5, 3306.638, -4944.650, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 6, 3303.388, -4953.150, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 7, 3300.138, -4961.900, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 8, 3297.138, -4970.900, 181.32675, NULL, 0),
(@PATH_ILLIDAN_CRYSTAL_1, 9, 3295.040, -4976.809, 181.07677, NULL, 0);
