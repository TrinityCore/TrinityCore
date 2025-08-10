SET @CGUID := 395711;
SET @OGUID := 239592;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15310; -- Jesper
UPDATE `creature_template` SET `gossip_menu_id`=11385, `minlevel`=60, `maxlevel`=60, `unit_flags`=32768 WHERE `entry`=40435; -- Headless Ghost
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51665; -- Celestine of the Harvest
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51666; -- Genn Greymane
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=51684; -- Wickerman Torch Point
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51699; -- Wickerman Reveler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51701; -- Greymane Retainer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=51702; -- Wickerman Crowd Bunny 01
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=51703; -- Wickerman Crowd Bunny 02
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=51705; -- Wickerman Crowd Bunny 03
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `speed_run`=1.385714292526245117, `unit_flags`=33554432, `unit_flags2`=67584, `VehicleId`=1555 WHERE `entry`=51710; -- Hag's Broom
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1.385714292526245117, `unit_flags`=33554432, `unit_flags2`=67584 WHERE `entry`=51836; -- Hag
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51934; -- Gretchen Fenlow
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51947; -- Gilnean Steed
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=52064; -- Keira
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `flags_extra`=`flags_extra`|128 WHERE `entry`=52067; -- General Purpose Bunny (All Phases)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=52497; -- Spanky
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=52548; -- Gertrude Fenlow
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53702; -- Stymie
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53728; -- Dorothy
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=53949; -- Anson Hastings
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=53950; -- Hired Courier
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=53954; -- Blood Spatter
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=53961; -- Blood Spatter (Small)
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `unit_flags`=33587200, `unit_flags3`=524288 WHERE `entry`=53965; -- Eerie Spider
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `flags_extra`=`flags_extra`|128 WHERE `entry`=53966; -- Spider Summoner (Ship)
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54021; -- Hudson Barnes
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54032; -- Dead Gang Member
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `flags_extra`=`flags_extra`|128 WHERE `entry`=54043; -- Spider Summoner (Catacombs)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=54072; -- Sanath Lim-yo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=512, `unit_flags3`=524288 WHERE `entry`=54114; -- Unleashed Void
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54118; -- Hudson Barnes
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54205; -- Ren Quickhand
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=109685; -- Pippi
UPDATE `creature_template` SET `gossip_menu_id`=23176, `minlevel`=60, `maxlevel`=60 WHERE `entry`=142656; -- Kalendormu

DELETE FROM `creature_template_addon` WHERE `entry` IN (15310, 40435, 51665, 51666, 51684, 51699, 51701, 51702, 51703, 51705, 51710, 51836, 51934, 52064, 52067, 52497, 52548, 53702, 53728, 53869, 53949, 53950, 53954, 53961, 53965, 53966, 54021, 54032, 54043, 54072, 54114, 54118, 54205, 109685, 142656);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15310, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15310 (Jesper)
(40435, 0, 0, 33554432, 257, 0, 0, 0, 0, 0, '33900'), -- 40435 (Headless Ghost) - Shroud of Death
(51665, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51665 (Celestine of the Harvest)
(51666, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51666 (Genn Greymane)
(51684, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51684 (Wickerman Torch Point)
(51699, 0, 0, 0, 1, 0, 0, 0, 0, 0, '95957'), -- 51699 (Wickerman Reveler)
(51701, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51701 (Greymane Retainer)
(51702, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51702 (Wickerman Crowd Bunny 01)
(51703, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51703 (Wickerman Crowd Bunny 02)
(51705, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51705 (Wickerman Crowd Bunny 03)
(51710, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '96010'), -- 51710 (Hag's Broom) - [DND] Hallow's End Event
(51836, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51836 (Hag)
(51934, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51934 (Gretchen Fenlow)
(52064, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 52064 (Keira)
(52067, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 52067 (General Purpose Bunny (All Phases))
(52497, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 52497 (Spanky) - Children's Costume Aura
(52548, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 52548 (Gertrude Fenlow)
(53702, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 53702 (Stymie) - Children's Costume Aura
(53728, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 53728 (Dorothy) - Children's Costume Aura
(53869, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53869 (Orphan Matron Seacole)
(53949, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53949 (Anson Hastings)
(53950, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 53950 (Hired Courier) - Permanent Feign Death
(53954, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266 28559'), -- 53954 (Blood Spatter) - Permanent Feign Death, Untrackable
(53961, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266 28559'), -- 53961 (Blood Spatter (Small)) - Permanent Feign Death, Untrackable
(53965, 0, 0, 0, 1, 0, 0, 0, 0, 0, '100512 100632'), -- 53965 (Eerie Spider) - Spider Invisibility 1, Spider Trail State
(53966, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 53966 (Spider Summoner (Ship))
(54021, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 54021 (Hudson Barnes)
(54032, 0, 0, 0, 1, 0, 0, 0, 0, 0, '100600 29266'), -- 54032 (Dead Gang Member) - Cripple State, Permanent Feign Death
(54043, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 54043 (Spider Summoner (Catacombs))
(54072, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 54072 (Sanath Lim-yo)
(54114, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 54114 (Unleashed Void)
(54118, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 54118 (Hudson Barnes)
(54205, 0, 0, 0, 1, 0, 0, 0, 0, 0, '100600 29266'), -- 54205 (Ren Quickhand) - Cripple State, Permanent Feign Death
(109685, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 109685 (Pippi) - Children's Costume Aura
(142656, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''); -- 142656 (Kalendormu)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (40435, 51684, 51702, 51703, 51705, 51710, 52067, 53966, 54043, 142656);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(40435, 2, 0, 0, 0, 0, 0, NULL),
(51684, 0, 0, 1, 1, 0, 0, NULL),
(51702, 0, 0, 1, 1, 0, 0, NULL),
(51703, 0, 0, 1, 1, 0, 0, NULL),
(51705, 0, 0, 1, 1, 0, 0, NULL),
(51710, 0, 0, 1, 0, 0, 0, NULL),
(52067, 0, 0, 1, 0, 0, 0, NULL),
(53966, 0, 0, 1, 0, 0, 0, NULL),
(54043, 0, 0, 1, 0, 0, 0, NULL),
(142656, 2, 0, 1, 1, 0, 0, NULL);

-- Vehicle data
DELETE FROM `vehicle_template_accessory` WHERE `entry`=51710;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(51710, 51836, 0, 1, 'Hag''s Broom - Hag', 8, 0); -- Hag's Broom - Hag

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=51710;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51710, 46598, 0, 0);
-- (51710, 75953, 1, 0); (InteractSpellID - Cannot be added because it prevents the accessory from mounting)

DELETE FROM `creature_template_spell` WHERE `CreatureID`=51710;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(51710, 0, 96026, 45745), -- Hag's Broom
(51710, 1, 96017, 45745); -- Hag's Broom

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuID` IN (11385, 12717, 12931, 12937, 23176, 23177);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11385, 15856, 45745), -- 40435 (Headless Ghost)
(12717, 17849, 45745), -- 52548 (Gertrude Fenlow)
(12931, 18189, 45745), -- 51934 (Gretchen Fenlow)
(12937, 18200, 45745), -- 53869 (Orphan Matron Seacole)
(23176, 35851, 45745), -- 142656 (Kalendormu)
(23177, 35852, 45745); -- 142656 (Kalendormu)

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE `MenuID`=8940 AND `TextID`=11961;
UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE `MenuID`=12705 AND `TextID`=17836;

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (11385, 23176) OR `MenuID`=12941 AND `OptionID`=1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11385, 0, 20, 'Queue for The Headless Horseman battle.', 40427, 0, 0, 0, 0, 0, NULL, 0, 45745),
(12941, 1, 0, 'Has anyone suspicious tried to list a crate of goods recently?', 52636, 0, 0, 0, 0, 0, NULL, 0, 45745),
(23176, 0, 0, 'What is a member of the Bronze Dragonflight doing here?', 160752, 0, 23177, 0, 0, 0, NULL, 0, 45745);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50794, `VerifiedBuild`=45745 WHERE `MenuID`=12717 AND `OptionID`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (12717, 12941);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12717,0,0,0,47,0,29054,10,0,0,0,0,'','Show gossip option if quest 29054 is active or completed'),
(15,12941,1,0,0,47,0,29398,8,0,0,0,0,'','Show gossip option if quest 29398 is active');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (15310, 51665, 51666, 51684, 51699, 51701, 51702, 51703, 51705, 51710, 51836, 51934, 51947, 52064, 52067, 52497, 52548, 53702, 53728, 53869, 53949, 53950, 53954, 53961, 53965, 53966, 54021, 54032, 54043, 54072, 54114, 54118, 54205, 109685, 142656, 181575);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(15310, 0, 0, 0, 425, 45745),
(51665, 0, 0, 0, 425, 45745),
(51666, 0, 0, 0, 425, 45745),
(51684, 0, 0, 0, 425, 45745),
(51699, 0, 0, 0, 425, 45745),
(51701, 0, 0, 0, 425, 45745),
(51702, 0, 0, 0, 425, 45745),
(51703, 0, 0, 0, 425, 45745),
(51705, 0, 0, 0, 425, 45745),
(51710, 0, 0, 0, 425, 45745),
(51836, 0, 0, 0, 425, 45745),
(51934, 0, 0, 0, 425, 45745),
(51947, 0, 0, 0, 425, 45745),
(52064, 0, 0, 0, 425, 45745),
(52067, 0, 0, 0, 425, 45745),
(52497, 0, 0, 0, 425, 45745),
(52548, 0, 0, 0, 425, 45745),
(53702, 0, 0, 0, 425, 45745),
(53728, 0, 0, 0, 425, 45745),
(53869, 0, 0, 0, 861, 45745),
(53949, 0, 0, 0, 861, 45745),
(53950, 0, 0, 0, 861, 45745),
(53954, 0, 0, 0, 861, 45745),
(53961, 0, 0, 0, 861, 45745),
(53965, 0, 0, 0, 81, 45745),
(53966, 0, 0, 0, 861, 45745),
(54021, 0, 0, 0, 861, 45745),
(54032, 0, 0, 0, 861, 45745),
(54043, 0, 0, 0, 861, 45745),
(54072, 0, 0, 0, 864, 45745),
(54114, 0, -1, -1, 861, 45745),
(54118, 0, 0, 0, 861, 45745),
(54205, 0, 0, 0, 861, 45745),
(109685, 0, 0, 0, 425, 45745),
(142656, 0, 0, 0, 425, 45745),
(181575, 0, 0, 0, 371, 45745);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45745 WHERE (`DifficultyID`=0 AND `Entry` IN (2442, 111190, 17804, 51348, 61165, 883, 42218, 68, 61080));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=45745 WHERE (`Idx`=0 AND `CreatureID` IN (39844,35362,15310,142656,111190,61080,109685,65011,308,39437,17804,51703,51934,51348,51705,51710,51702,51699,53728,51836,61165,47654,51684,52067,53702,52548,2442,39843,51665,304,51701,18362,51947,52497,181575,883,42218,53869,14505,22816,64993,40229,68,52064,305,71486)) OR (`Idx`=1 AND `CreatureID` IN (111190,61080,39437,51348,51699,52067,39843,68)) OR (`Idx`=2 AND `CreatureID` IN (39437,39843,68)) OR (`Idx`=3 AND `CreatureID`=68);

DELETE FROM `creature_model_info` WHERE `DisplayID`=102304;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(102304, 0.500797629356384277, 1, 0, 45745);

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (1060, 17250, 654, 347, 32729, 20024, 29467, 4626, 257, 3640, 38421, 23960, 37113, 37111, 38529, 29961, 38523, 87696, 37747, 37652);
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1, `VerifiedBuild`=45745 WHERE `DisplayID`=37960;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=45745 WHERE `DisplayID`=38519;

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=52497 AND `item`=49216 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=49215 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20573 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20574 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20568 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20567 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20572 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20571 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20570 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20569 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20564 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20563 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20566 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20565 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=49210 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=49212 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20391 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20392 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20561 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=20562 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=34003 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=34001 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=34002 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=34000 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=52497 AND `item`=69195 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69194 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69193 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69192 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69190 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69189 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69188 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=52497 AND `item`=69187 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53728 AND `item`=187997 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53728 AND `item`=167731 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53728 AND `item`=151614 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53728 AND `item`=122340 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53728 AND `item`=122338 AND `ExtendedCost`=5796 AND `type`=1) OR (`entry`=53728 AND `item`=151268 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53728 AND `item`=138990 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53728 AND `item`=128643 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53728 AND `item`=116828 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53728 AND `item`=33292 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=53728 AND `item`=163045 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53728 AND `item`=151270 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53728 AND `item`=151271 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53728 AND `item`=70722 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=53728 AND `item`=37011 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=53728 AND `item`=37604 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53728 AND `item`=37583 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53728 AND `item`=37584 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53728 AND `item`=37582 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53728 AND `item`=37585 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=139004 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=128644 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=128645 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=128646 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=116854 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=116853 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=116851 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=116850 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=116848 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20397 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20398 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20399 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20409 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20410 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20411 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20413 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53702 AND `item`=20414 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=109685 AND `item`=139036 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109685 AND `item`=116812 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=109685 AND `item`=116811 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109685 AND `item`=116810 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109685 AND `item`=151269 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109685 AND `item`=116801 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109685 AND `item`=116804 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109685 AND `item`=70908 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109685 AND `item`=33154 AND `ExtendedCost`=3545 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52497, 32, 49216, 0, 3404, 1, 0, 0, 45745), -- Worgen Male Mask
(52497, 31, 49215, 0, 3404, 1, 0, 0, 45745), -- Worgen Female Mask
(52497, 30, 20573, 0, 3404, 1, 0, 0, 45745), -- Undead Male Mask
(52497, 29, 20574, 0, 3404, 1, 0, 0, 45745), -- Undead Female Mask
(52497, 28, 20568, 0, 3404, 1, 0, 0, 45745), -- Troll Male Mask
(52497, 27, 20567, 0, 3404, 1, 0, 0, 45745), -- Troll Female Mask
(52497, 26, 20572, 0, 3404, 1, 0, 0, 45745), -- Tauren Male Mask
(52497, 25, 20571, 0, 3404, 1, 0, 0, 45745), -- Tauren Female Mask
(52497, 24, 20570, 0, 3404, 1, 0, 0, 45745), -- Orc Male Mask
(52497, 23, 20569, 0, 3404, 1, 0, 0, 45745), -- Orc Female Mask
(52497, 22, 20564, 0, 3404, 1, 0, 0, 45745), -- Night Elf Male Mask
(52497, 21, 20563, 0, 3404, 1, 0, 0, 45745), -- Night Elf Female Mask
(52497, 20, 20566, 0, 3404, 1, 0, 0, 45745), -- Human Male Mask
(52497, 19, 20565, 0, 3404, 1, 0, 0, 45745), -- Human Female Mask
(52497, 18, 49210, 0, 3404, 1, 0, 0, 45745), -- Goblin Male Mask
(52497, 17, 49212, 0, 3404, 1, 0, 0, 45745), -- Goblin Female Mask
(52497, 16, 20391, 0, 3404, 1, 0, 0, 45745), -- Gnome Male Mask
(52497, 15, 20392, 0, 3404, 1, 0, 0, 45745), -- Gnome Female Mask
(52497, 14, 20561, 0, 3404, 1, 0, 0, 45745), -- Dwarf Male Mask
(52497, 13, 20562, 0, 3404, 1, 0, 0, 45745), -- Dwarf Female Mask
(52497, 12, 34003, 0, 3404, 1, 0, 0, 45745), -- Draenei Male Mask
(52497, 11, 34001, 0, 3404, 1, 0, 0, 45745), -- Draenei Female Mask
(52497, 10, 34002, 0, 3404, 1, 0, 0, 45745), -- Blood Elf Male Mask
(52497, 9, 34000, 0, 3404, 1, 0, 0, 45745), -- Blood Elf Female Mask
(52497, 8, 69195, 0, 3403, 1, 0, 0, 45745), -- Vrykul Male Mask
(52497, 7, 69194, 0, 3403, 1, 0, 0, 45745), -- Vrykul Female Mask
(52497, 6, 69193, 0, 3403, 1, 0, 0, 45745), -- Ogre Male Mask
(52497, 5, 69192, 0, 3403, 1, 0, 0, 45745), -- Ogre Female Mask
(52497, 4, 69190, 0, 3403, 1, 0, 0, 45745), -- Naga Male Mask
(52497, 3, 69189, 0, 3403, 1, 0, 0, 45745), -- Naga Female Mask
(52497, 2, 69188, 0, 3403, 1, 0, 0, 45745), -- Murloc Male Mask
(52497, 1, 69187, 0, 3403, 1, 0, 0, 45745), -- Murloc Female Mask
(53728, 20, 187997, 0, 5797, 1, 0, 0, 45745), -- Eternal Heirloom Armor Casing
(53728, 19, 167731, 0, 5797, 1, 0, 0, 45745), -- Battle-Hardened Heirloom Armor Casing
(53728, 18, 151614, 0, 5797, 1, 0, 0, 45745), -- Weathered Heirloom Armor Casing
(53728, 17, 122340, 0, 5797, 1, 0, 0, 45745), -- Timeworn Heirloom Armor Casing
(53728, 16, 122338, 0, 5796, 1, 0, 0, 45745), -- Ancient Heirloom Armor Casing
(53728, 15, 151268, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Xavius"
(53728, 14, 138990, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Grommash"
(53728, 13, 128643, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Deathwing"
(53728, 12, 116828, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "The Lich King"
(53728, 11, 33292, 0, 3546, 1, 0, 0, 45745), -- Hallowed Helm
(53728, 10, 163045, 0, 3545, 1, 0, 0, 45745), -- Headless Horseman's Hearthstone
(53728, 9, 151270, 0, 3545, 1, 0, 0, 45745), -- Horse Tail Costume
(53728, 8, 151271, 0, 3545, 1, 0, 0, 45745), -- Horse Head Costume
(53728, 7, 70722, 0, 3546, 1, 0, 0, 45745), -- Little Wickerman
(53728, 6, 37011, 0, 3547, 1, 0, 0, 45745), -- Magic Broom
(53728, 5, 37604, 0, 3404, 1, 0, 0, 45745), -- Tooth Pick
(53728, 4, 37583, 0, 3404, 1, 0, 0, 45745), -- G.N.E.R.D.S.
(53728, 3, 37584, 0, 3404, 1, 0, 0, 45745), -- Soothing Spearmint Candy
(53728, 2, 37582, 0, 3404, 1, 0, 0, 45745), -- Pyroblast Cinnamon Ball
(53728, 1, 37585, 0, 3404, 1, 0, 0, 45745), -- Chewy Fel Taffy
(53702, 17, 139004, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Banshee
(53702, 16, 128644, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Wight
(53702, 15, 128645, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Gargoyle
(53702, 14, 128646, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Nerubian
(53702, 13, 116854, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Spider
(53702, 12, 116853, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Geist
(53702, 11, 116851, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Abomination
(53702, 10, 116850, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ghoul
(53702, 9, 116848, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Slime
(53702, 8, 20397, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Pirate
(53702, 7, 20398, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ninja
(53702, 6, 20399, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Leper Gnome
(53702, 5, 20409, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ghost
(53702, 4, 20410, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Bat
(53702, 3, 20411, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Skeleton
(53702, 2, 20413, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Random
(53702, 1, 20414, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Wisp
(109685, 9, 139036, 0, 3403, 1, 0, 0, 45745), -- Ominous Pet Treat
(109685, 8, 116812, 0, 3547, 1, 0, 0, 45745), -- "Yipp-Saron" Costume
(109685, 7, 116811, 0, 3403, 1, 0, 0, 45745), -- "Lil' Starlet" Costume
(109685, 6, 116810, 0, 3403, 1, 0, 0, 45745), -- "Mad Alchemist" Costume
(109685, 5, 151269, 0, 3545, 1, 0, 0, 45745), -- Naxxy
(109685, 4, 116801, 0, 3545, 1, 0, 0, 45745), -- Cursed Birman
(109685, 3, 116804, 0, 3545, 1, 0, 0, 45745), -- Widget the Departed
(109685, 2, 70908, 0, 3545, 1, 0, 0, 45745), -- Feline Familiar
(109685, 1, 33154, 0, 3545, 1, 0, 0, 45745); -- Sinister Squashling

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry`=190040; -- Candy Bucket
UPDATE `gameobject_template` SET `ContentTuningId`=864, `VerifiedBuild`=45745 WHERE `entry`=209072; -- Stolen Crate
UPDATE `gameobject_template` SET `ContentTuningId`=864, `VerifiedBuild`=45745 WHERE `entry`=209076; -- Anson's Crate

UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=180431; -- G_Pumpkin_01 scale 4.0
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=180433; -- The Wickerman
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=180701; -- Hay Bale 2
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=190040; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=207941; -- G_WitchHat_01 scale 2.0
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208186; -- Bonfire
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=208200; -- Stink Bomb Cloud
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=208218; -- Elwynn Fence
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=208219; -- Worgen Town Fence 03
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208395; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=209059; -- Blood Nettle

UPDATE `gameobject_questitem` SET `VerifiedBuild`=45745 WHERE `Idx`=0 AND `GameObjectEntry`=209059;

DELETE FROM `gameobject_loot_template` WHERE `Entry`=39847;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(39847, 71035, 0, 100, 1, 1, 0, 1, 1, 'Blood Nettle - Blood Nettle');

-- Quests
UPDATE `quest_template_addon` SET `PrevQuestId`=0 WHERE `ID`=29075;

DELETE FROM `quest_poi` WHERE (`QuestID`=29402 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=29402 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=29402 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=29402 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29402 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29402 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(29402, 0, 5, 32, 0, 0, 0, 84, 0, 0, 0, 0, 0, 598923, 0, 45745), -- Taking Precautions
(29402, 0, 4, 2, 252054, 71035, 0, 84, 0, 7, 0, 0, 0, 0, 0, 45745), -- Taking Precautions
(29402, 2, 3, 1, 252053, 3371, 0, 84, 0, 7, 0, 0, 0, 0, 0, 45745), -- Taking Precautions
(29402, 1, 2, 1, 252053, 3371, 0, 84, 0, 7, 0, 0, 0, 0, 0, 45745), -- Taking Precautions
(29402, 0, 1, 1, 252053, 3371, 0, 84, 0, 7, 0, 0, 0, 0, 0, 45745), -- Taking Precautions
(29402, 0, 0, -1, 0, 0, 0, 84, 0, 1, 0, 0, 0, 0, 0, 45745); -- Taking Precautions

UPDATE `quest_poi` SET `VerifiedBuild`=45745 WHERE (`QuestID`=29399 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29399 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29399 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29398 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29398 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29398 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29392 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29392 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29392 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29392 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8311 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29075 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29075 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29075 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29371 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29371 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29371 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29430 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29430 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29144 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=29144 AND `BlobIndex`=6 AND `Idx1`=7) OR (`QuestID`=29144 AND `BlobIndex`=5 AND `Idx1`=6) OR (`QuestID`=29144 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=29144 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=29144 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=29144 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29144 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29144 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29054 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29054 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29054 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29054 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=29402 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=29402 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=11) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=10) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=29402 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29402 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29402 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29402 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25255 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=25255 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25255 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25255 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25255 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25255 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25255 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(29402, 5, 0, -8532, 608, 103, 45745), -- Taking Precautions
(29402, 4, 11, -8295, 628, 0, 45745), -- Taking Precautions
(29402, 4, 10, -8336, 688, 0, 45745), -- Taking Precautions
(29402, 4, 9, -8308, 723, 0, 45745), -- Taking Precautions
(29402, 4, 8, -8262, 833, 0, 45745), -- Taking Precautions
(29402, 4, 7, -8170, 939, 0, 45745), -- Taking Precautions
(29402, 4, 6, -8102, 937, 79, 45745), -- Taking Precautions
(29402, 4, 5, -8069, 924, 72, 45745), -- Taking Precautions
(29402, 4, 4, -8054, 839, 70, 45745), -- Taking Precautions
(29402, 4, 3, -8054, 769, 71, 45745), -- Taking Precautions
(29402, 4, 2, -8056, 729, 70, 45745), -- Taking Precautions
(29402, 4, 1, -8168, 547, 69, 45745), -- Taking Precautions
(29402, 4, 0, -8218, 541, 73, 45745), -- Taking Precautions
(29402, 3, 11, -8524, 798, 0, 45745), -- Taking Precautions
(29402, 3, 10, -8527, 806, 0, 45745), -- Taking Precautions
(29402, 3, 9, -8529, 814, 0, 45745), -- Taking Precautions
(29402, 3, 8, -8527, 821, 0, 45745), -- Taking Precautions
(29402, 3, 7, -8522, 826, 0, 45745), -- Taking Precautions
(29402, 3, 6, -8512, 823, 0, 45745), -- Taking Precautions
(29402, 3, 5, -8507, 818, 0, 45745), -- Taking Precautions
(29402, 3, 4, -8504, 813, 0, 45745), -- Taking Precautions
(29402, 3, 3, -8504, 806, 0, 45745), -- Taking Precautions
(29402, 3, 2, -8504, 800, 0, 45745), -- Taking Precautions
(29402, 3, 1, -8511, 795, 0, 45745), -- Taking Precautions
(29402, 3, 0, -8517, 795, 0, 45745), -- Taking Precautions
(29402, 2, 11, -8871, 615, 0, 45745), -- Taking Precautions
(29402, 2, 10, -8874, 621, 0, 45745), -- Taking Precautions
(29402, 2, 9, -8876, 628, 0, 45745), -- Taking Precautions
(29402, 2, 8, -8877, 633, 0, 45745), -- Taking Precautions
(29402, 2, 7, -8877, 641, 0, 45745), -- Taking Precautions
(29402, 2, 6, -8869, 644, 0, 45745), -- Taking Precautions
(29402, 2, 5, -8858, 644, 0, 45745), -- Taking Precautions
(29402, 2, 4, -8854, 638, 0, 45745), -- Taking Precautions
(29402, 2, 3, -8849, 630, 0, 45745), -- Taking Precautions
(29402, 2, 2, -8849, 618, 0, 45745), -- Taking Precautions
(29402, 2, 1, -8854, 612, 0, 45745), -- Taking Precautions
(29402, 2, 0, -8861, 612, 0, 45745), -- Taking Precautions
(29402, 1, 11, -8969, 886, 0, 45745), -- Taking Precautions
(29402, 1, 10, -8970, 898, 0, 45745), -- Taking Precautions
(29402, 1, 9, -8970, 904, 0, 45745), -- Taking Precautions
(29402, 1, 8, -8967, 911, 0, 45745), -- Taking Precautions
(29402, 1, 7, -8962, 914, 0, 45745), -- Taking Precautions
(29402, 1, 6, -8944, 921, 0, 45745), -- Taking Precautions
(29402, 1, 5, -8941, 913, 0, 45745), -- Taking Precautions
(29402, 1, 4, -8939, 901, 0, 45745), -- Taking Precautions
(29402, 1, 3, -8939, 893, 0, 45745), -- Taking Precautions
(29402, 1, 2, -8944, 886, 0, 45745), -- Taking Precautions
(29402, 1, 1, -8952, 881, 0, 45745), -- Taking Precautions
(29402, 1, 0, -8959, 881, 0, 45745), -- Taking Precautions
(29402, 0, 0, -8532, 608, 103, 45745); -- Taking Precautions

UPDATE `quest_poi_points` SET `VerifiedBuild`=45745 WHERE (`QuestID`=29399 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29399 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29399 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29398 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29398 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29398 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29392 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29392 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29392 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29392 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29074 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8311 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29075 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29075 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29075 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29371 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29371 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29371 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29430 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29430 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29144 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29144 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29054 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29054 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29054 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29054 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (8311, 29054, 29075, 29144, 29371, 29398, 29399, 29402, 29430);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8311, 1, 1, 0, 0, 0, 0, 0, 0, 45745), -- Hallow's End Treats for Jesper!
(29054, 5, 1, 0, 0, 0, 0, 0, 0, 45745), -- Stink Bombs Away!
(29075, 70, 1, 0, 0, 0, 0, 0, 0, 45745), -- A Time to Gain
(29144, 5, 1, 0, 0, 0, 0, 0, 0, 45745), -- Clean Up in Stormwind
(29371, 70, 1, 0, 0, 0, 0, 0, 0, 45745), -- A Time to Lose
(29398, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Fencing the Goods
(29399, 1, 1, 0, 0, 0, 0, 0, 0, 45745), -- Shopping Around
(29402, 1, 1, 0, 0, 0, 0, 0, 0, 45745), -- Taking Precautions
(29430, 1, 1, 0, 0, 0, 0, 0, 0, 45745); -- A Friend in Need

UPDATE `quest_details` SET `VerifiedBuild`=45745 WHERE `ID` IN (29074, 29392);

DELETE FROM `quest_request_items` WHERE `ID` IN (29054, 29075, 29144, 29398, 29403, 29411);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29054, 0, 0, 0, 0, 'Bombs away, am I right?', 45745), -- Stink Bombs Away!
(29075, 0, 0, 0, 0, 'Have you released your burdens, $c?', 45745), -- A Time to Gain
(29144, 0, 0, 0, 0, 'Arcane magic... Works every time.', 45745), -- Clean Up in Stormwind
(29398, 0, 0, 0, 0, 'Why are you still pestering me?', 45745), -- Fencing the Goods
(29403, 0, 1, 0, 0, '', 45745), -- The Collector's Agent
(29411, 1, 0, 0, 0, 'Have you brought the crate as we discussed?', 0); -- What Now?

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Have you finished trick-or-treating yet? I wish I could go, but I don''t want to run into Deathwing.' WHERE `ID`=8311; -- Hallow's End Treats for Jesper!
UPDATE `quest_request_items` SET `VerifiedBuild`=45745 WHERE `ID`=29371; -- A Time to Lose
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=29402; -- Taking Precautions

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29054, 29074, 29075, 29144, 29392, 29398, 29399, 29402, 29403, 29411, 29413, 29430);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29054, 0, 0, 0, 0, 0, 0, 0, 0, 'That will show those foolish crones who the strongest is.$b$bTake these treats and treat yourself to something nice, $c.', 45745), -- Stink Bombs Away!
(29074, 0, 0, 0, 0, 0, 0, 0, 0, 'The Wickerman ceremony is a time honored tradition.  It is good to see the Alliance celebrating it once again.', 45745), -- A Season for Celebration
(29075, 1, 0, 0, 0, 0, 0, 0, 0, 'Do not let your burdens trouble you any longer.  Any time you are feeling burdened, remember the Wickerman.', 45745), -- A Time to Gain
(29144, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah, much better, $n.  Those crones in the Undercity have no idea how powerful we have become.  Now I suppose you would like a reward.', 45745), -- Clean Up in Stormwind
(29392, 0, 0, 0, 0, 0, 0, 0, 0, 'This courier won''t be meeting with his employer anytime soon and the crate he was hired to transport seems to have disappeared.', 45745), -- Missing Heirlooms
(29398, 1, 0, 0, 0, 0, 0, 0, 0, 'Keep your voice down and don''t let word of this get out or I''m finished as an auctioneer!', 45745), -- Fencing the Goods
(29399, 1, 1, 0, 0, 0, 0, 0, 0, 'Finally, Cutler''s given me something I can work with. Before I give up that information, I''m going to want to know who you''re working for.', 45745), -- Shopping Around
(29402, 1, 1, 0, 0, 0, 0, 0, 0, 'Sometimes, I think I should''ve followed my father into alchemy.$B$BThis concoction should protect us from the worst effects of carrying or handling the crate. Bottoms up!', 45745), -- Taking Precautions
(29403, 1, 1, 0, 0, 0, 0, 0, 0, 'Tendrils of dark power dance around the crate, but there''s no trace of Sanath Lim-yo. You can now claim the crate and return it to your employer.', 45745), -- The Collector's Agent
(29411, 1, 1, 0, 0, 0, 0, 0, 0, 'Ah, you did manage to get the crate before Archmage Xylem''s man could get it out of the city. Excellent!', 45745), -- What Now?
(29413, 0, 0, 0, 0, 0, 0, 0, 0, 'It''s been sought after, stolen, and sold. Anyone who tried to tap the magic held within has seen that power turn against him.$B$BYet, the crate itself appears unscathed and suffused with magical energy. From time to time, it shakes or bobs as if its contents were alive.$B$BIt seems to have an affinity for you and now, it''s yours.', 45745), -- The Creepy Crate
(29430, 0, 0, 0, 0, 0, 0, 0, 0, 'What do you want?$B$BI''m never going to finish my research, $r. It''s my life''s work, and now the courier with the experimental reagents I need is late!', 45745); -- A Friend in Need

UPDATE `quest_offer_reward` SET `VerifiedBuild`=45745 WHERE `ID`=12336;

DELETE FROM `creature_queststarter` WHERE (`id`=18927 AND `quest`=29074) OR (`id`=51665 AND `quest`=29075) OR (`id`=51934 AND `quest`=29430) OR (`id`=52064 AND `quest`=29371);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(18927, 29074, 45745), -- A Season for Celebration offered Human Commoner
(51665, 29075, 45745), -- A Time to Gain offered Celestine of the Harvest
(51934, 29430, 45745), -- A Friend in Need offered Gretchen Fenlow
(52064, 29371, 45745); -- A Time to Lose offered Keira

UPDATE `creature_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=54021 AND `quest`=29403) OR (`id`=15310 AND `quest`=8311) OR (`id`=51934 AND `quest` IN (29054,29144));

UPDATE `creature_questender` SET `VerifiedBuild`=45745 WHERE (`quest`=29411 AND `id` IN (53949,54118)) OR (`quest`=29402 AND `id`=54021) OR (`id`=51934 AND `quest` IN (29054,29144)) OR (`id`=15310 AND `quest`=8311) OR (`id`=51665 AND `quest`=29075) OR (`id`=52064 AND `quest`=29371) OR (`id`=51665 AND `quest`=29074) OR (`id`=53949 AND `quest`=29430);

DELETE FROM `game_event_creature_quest` WHERE (`id`=18927 AND `quest`=29074);
DELETE FROM `game_event_creature_quest` WHERE `id` IN (51665, 51934, 52064);

DELETE FROM `gameobject_queststarter` WHERE `id`=190040 AND `quest`=12336;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190040, 12336, 45745);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=209072 AND `quest`=29411);

UPDATE `gameobject_questender` SET `VerifiedBuild`=45745 WHERE (`id`=190040 AND `quest`=12336) OR (`id`=209076 AND `quest`=29413) OR (`id`=209072 AND `quest`=29403);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190040;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=29074;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,29074,0,0,12,0,12,0,0,0,0,0,'','Show quest 29074 only if event "Hallow''s End" is active');

-- Misc
DELETE FROM `spell_area` WHERE `spell` IN (100618, 100619, 100676) AND `area`=1519;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(100618, 1519, 29398, 0, 0, 0, 2, 3, 10, 0),
(100619, 1519, 29403, 0, 0, 0, 2, 3, 10, 0),
(100676, 1519, 29411, 0, 0, 0, 2, 3, 64, 0);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Stormwind Gate
(@CGUID+0, 15310, 0, 12, 7486, '0', 0, 0, 0, 0, -9105.97265625, 423.6475830078125, 93.85897064208984375, 5.148721218109130859, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Jesper (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+1, 51665, 0, 12, 7486, '0', 0, 0, 0, 1, -9108.685546875, 423.3663330078125, 94.07958984375, 5.131268024444580078, 120, 0, 0, 11791, 2434, 0, 0, 0, 0, 45745), -- Celestine of the Harvest (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+2, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9063.00390625, 379.848968505859375, 113.4407730102539062, 2.275387763977050781, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+3, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9057.9345703125, 381.177093505859375, 115.5440292358398437, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+4, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9065.1181640625, 375.09027099609375, 96.79581451416015625, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+5, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9064.8330078125, 375.711822509765625, 114.2770233154296875, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+6, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9061.6669921875, 379.90277099609375, 104.8144989013671875, 2.617993831634521484, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+7, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9064.1220703125, 377.586822509765625, 110.4320526123046875, 2.362124443054199218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+8, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9063.2783203125, 379.401031494140625, 108.6555557250976562, 2.443835258483886718, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+9, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9064.4931640625, 377.107635498046875, 106.8796844482421875, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+10, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9058.826171875, 383.576385498046875, 104.8242034912109375, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+11, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9060.56640625, 379.979156494140625, 101.1744766235351562, 2.356194496154785156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+12, 51684, 0, 12, 7486, '0', 0, 0, 0, 0, -9064.1025390625, 376.060760498046875, 102.225982666015625, 2.617993831634521484, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+13, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9087.3994140625, 394.9600830078125, 93.57122802734375, 5.131268024444580078, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+14, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9086.93359375, 389.214630126953125, 93.11346435546875, 5.026548385620117187, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+15, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9084.53515625, 393.48858642578125, 93.3961639404296875, 3.106686115264892578, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+16, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9086.884765625, 391.986328125, 93.36346435546875, 1.082104086875915527, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+17, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9075.28125, 400.930572509765625, 93.495391845703125, 4.86946868896484375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+18, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9085.923828125, 386.494781494140625, 92.98846435546875, 1.989675283432006835, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+19, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9078.287109375, 392.436737060546875, 93.0688323974609375, 1.727875947952270507, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+20, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9076.376953125, 399.03125, 93.66717529296875, 0.453785598278045654, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+21, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9078.6044921875, 395.171875, 93.70477294921875, 4.747295379638671875, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+22, 51699, 0, 12, 7486, '0', 0, 0, 0, 0, -9074.2412109375, 399.161468505859375, 93.723602294921875, 2.652900457382202148, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+23, 51701, 0, 12, 7486, '0', 0, 0, 0, 1, -9076.658203125, 384.513885498046875, 92.69788360595703125, 2.321287870407104492, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 45745), -- Greymane Retainer (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+24, 51701, 0, 12, 7486, '0', 0, 0, 0, 1, -9079.78125, 381.368072509765625, 92.6159820556640625, 2.408554315567016601, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 45745), -- Greymane Retainer (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+25, 51702, 0, 12, 7486, '0', 0, 0, 0, 0, -9072.8857421875, 394.75347900390625, 93.631591796875, 0.279252678155899047, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Crowd Bunny 01 (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+26, 51703, 0, 12, 7486, '0', 0, 0, 0, 0, -9079.060546875, 387.6944580078125, 92.71319580078125, 0.331612557172775268, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Crowd Bunny 02 (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+27, 51705, 0, 12, 7486, '0', 0, 0, 0, 0, -9074.9970703125, 390.14410400390625, 93.06845855712890625, 0.279252678155899047, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Crowd Bunny 03 (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+28, 51934, 0, 12, 7486, '0', 0, 0, 0, 0, -9117.248046875, 412.708343505859375, 93.94106292724609375, 3.159045934677124023, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Gretchen Fenlow (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+29, 51947, 0, 12, 7486, '0', 0, 0, 0, 0, -9103.763671875, 388.868072509765625, 93.20831298828125, 2.338741064071655273, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gilnean Steed (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+30, 51947, 0, 12, 7486, '0', 0, 0, 0, 0, -9099.0244140625, 394.223968505859375, 92.78414154052734375, 2.49582076072692871, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gilnean Steed (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+31, 52064, 0, 12, 7486, '0', 0, 0, 0, 1, -9110.669921875, 421.8038330078125, 94.15008544921875, 5.515240192413330078, 120, 0, 0, 11791, 2434, 0, 0, 0, 0, 45745), -- Keira (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+32, 52067, 0, 12, 7486, '0', 0, 0, 0, 0, -9104.0556640625, 393.982635498046875, 92.720489501953125, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- General Purpose Bunny (All Phases) (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+33, 52497, 0, 12, 7486, '0', 0, 0, 0, 0, -9098.09765625, 429.716827392578125, 93.298004150390625, 5.060554027557373046, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Spanky (Area: Stormwind Gate - Difficulty: 0) (Auras: 97135 - Children's Costume Aura, 97095 - Scary Tiki Mask)
(@CGUID+34, 52548, 0, 12, 7486, '0', 0, 0, 0, 0, -9114.6142578125, 417.368072509765625, 94.1620330810546875, 5.235987663269042968, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Gertrude Fenlow (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+35, 53702, 0, 12, 7486, '0', 0, 0, 0, 0, -9101.1181640625, 427.956024169921875, 93.43695831298828125, 5.179904937744140625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Stymie (Area: Stormwind Gate - Difficulty: 0) (Auras: 97135 - Children's Costume Aura, 97144 - Scary Pumpkin Mask)
(@CGUID+36, 53728, 0, 12, 7486, '0', 0, 0, 0, 0, -9099.439453125, 431.333343505859375, 93.56024169921875, 5.009094715118408203, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Dorothy (Area: Stormwind Gate - Difficulty: 0) (Auras: 97135 - Children's Costume Aura, 97134 - Scary Witch Hat)
(@CGUID+37, 53869, 0, 12, 7486, '0', 0, 0, 0, 0, -9105.0693359375, 427.119781494140625, 93.70990753173828125, 5.201081275939941406, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Orphan Matron Seacole (Area: Stormwind Gate - Difficulty: 0)
(@CGUID+38, 109685, 0, 12, 7486, '0', 0, 0, 0, 0, -9102.51953125, 428.09027099609375, 93.5450897216796875, 5.368412971496582031, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Pippi (Area: Stormwind Gate - Difficulty: 0) (Auras: 97135 - Children's Costume Aura, 100320 - Magical Mage Hat)
(@CGUID+39, 142656, 0, 12, 7486, '0', 0, 0, 0, 0, -9117.640625, 415.713531494140625, 93.84183502197265625, 5.849154949188232421, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Kalendormu (Area: Stormwind Gate - Difficulty: 0)
-- Stormwind City
(@CGUID+40, 40435, 0, 1519, 5148, '0', 0, 0, 0, 0, -8835.66015625, 639.55206298828125, 95.187744140625, 4.066617012023925781, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Headless Ghost (Area: Trade District - Difficulty: 0) (Auras: 33900 - Shroud of Death)
(@CGUID+41, 53949, 0, 1519, 5148, '0', 0, 0, 0, 1, -8866.138671875, 679.57989501953125, 97.98639678955078125, 4.607669353485107421, 120, 0, 0, 1604, 852, 0, 0, 0, 0, 45745), -- Anson Hastings (Area: Trade District - Difficulty: 0)
(@CGUID+42, 53950, 0, 1519, 4411, '0', 0, 0, 0, 0, -8514.9931640625, 1305.2100830078125, 6.181744098663330078, 1.535889744758605957, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Hired Courier (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+43, 53954, 0, 1519, 4411, '0', 0, 0, 0, 0, -8514.6142578125, 1305.486083984375, 6.182001113891601562, 5.619960308074951171, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Blood Spatter (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+44, 53954, 0, 1519, 4411, '0', 0, 0, 0, 0, -8514.8994140625, 1306.21875, 6.182374477386474609, 5.619960308074951171, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Blood Spatter (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+45, 53961, 0, 1519, 4411, '0', 0, 0, 0, 0, -8515.5068359375, 1306.439208984375, 6.182505607604980468, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Blood Spatter (Small) (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+46, 53961, 0, 1519, 4411, '0', 0, 0, 0, 0, -8515.6923828125, 1306.9774169921875, 6.18283843994140625, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Blood Spatter (Small) (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+47, 53961, 0, 1519, 4411, '0', 0, 0, 0, 0, -8514.935546875, 1306.7274169921875, 6.182691097259521484, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Blood Spatter (Small) (Area: Stormwind Harbor - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+48, 53966, 0, 1519, 4411, '0', 0, 0, 0, 0, -8515.3349609375, 1306.13720703125, 6.182314872741699218, 0, 120, 0, 0, 1604, 852, 0, 0, 0, 0, 45745), -- Spider Summoner (Ship) (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+49, 54021, 0, 1519, 5704, '0', 0, 0, 0, 0, -8532.001953125, 608.05902099609375, 102.960296630859375, 1.01229095458984375, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Hudson Barnes (Area: The Canals - Difficulty: 0)
(@CGUID+50, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8515.826171875, 758.65802001953125, 72.79593658447265625, 1.186823844909667968, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+51, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8502.107421875, 787.63018798828125, 87.39232635498046875, 0, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+52, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8494.158203125, 777.29168701171875, 72.79593658447265625, 4.258603572845458984, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+53, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8515.734375, 785.420166015625, 81.69933319091796875, 2.897246599197387695, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+54, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8524.859375, 793.55731201171875, 81.69793701171875, 0.48869219422340393, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+55, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8507.326171875, 800.40625, 81.69720458984375, 1.850049018859863281, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+56, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8473.623046875, 798.29168701171875, 81.69183349609375, 3.001966238021850585, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: The Canals - Difficulty: 0)
(@CGUID+57, 54032, 0, 1519, 5704, '0', 0, 0, 0, 0, -8456.97265625, 819.8992919921875, 81.694427490234375, 4.468042850494384765, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Gang Member (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+58, 54043, 0, 1519, 5704, '0', 0, 0, 0, 0, -8506.81640625, 820.20660400390625, 96.755279541015625, 5.393067359924316406, 120, 0, 0, 1604, 852, 0, 0, 0, 0, 45745), -- Spider Summoner (Catacombs) (Area: The Canals - Difficulty: 0)
(@CGUID+59, 54072, 0, 1519, 5704, '0', 0, 0, 0, 1, -8499.607421875, 759.5555419921875, 72.795928955078125, 0.471238881349563598, 120, 0, 0, 14739, 2434, 0, 0, 0, 0, 45745), -- Sanath Lim-yo (Area: The Canals - Difficulty: 0)
(@CGUID+60, 54118, 0, 1519, 5150, '0', 0, 0, 0, 0, -8383.53515625, 590.576416015625, 97.8619384765625, 1.099557399749755859, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Hudson Barnes (Area: Dwarven District - Difficulty: 0)
(@CGUID+61, 54205, 0, 1519, 5704, '0', 0, 0, 0, 0, -8496.6474609375, 761.65972900390625, 72.795928955078125, 3.839724302291870117, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745); -- Ren Quickhand (Area: The Canals - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+28);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+28, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''); -- 51934 (Gretchen Fenlow)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2702;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180037, 0, 12, 7486, '0', 0, 0, -9118.783203125, 419.34722900390625, 93.88652801513671875, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- Haybail 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+1, 180037, 0, 12, 7486, '0', 0, 0, -9110.6611328125, 429.72222900390625, 93.12786102294921875, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 45745), -- Haybail 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+2, 180038, 0, 12, 7486, '0', 0, 0, -9106.529296875, 432.263885498046875, 93.18706512451171875, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- Haybail 02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+3, 180410, 0, 12, 7486, '0', 0, 0, -9096.06640625, 432.467010498046875, 95.47092437744140625, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+4, 180410, 0, 12, 7486, '0', 0, 0, -9104.091796875, 430.076385498046875, 95.47092437744140625, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+5, 180410, 0, 12, 7486, '0', 0, 0, -9100.1962890625, 430.979156494140625, 95.40256500244140625, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+6, 180414, 0, 12, 7486, '0', 0, 0, -9119.3017578125, 412.4132080078125, 93.92376708984375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- Cauldron (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+7, 180415, 0, 12, 7486, '0', 0, 0, -9117.595703125, 412.1163330078125, 93.79441070556640625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+8, 180415, 0, 12, 7486, '0', 0, 0, -9118.1845703125, 413.993072509765625, 93.9696197509765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+9, 180415, 0, 12, 7486, '0', 0, 0, -9120.0888671875, 414.111114501953125, 94.01055145263671875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+10, 180415, 0, 12, 7486, '0', 0, 0, -9121.1474609375, 412.664947509765625, 94.01128387451171875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+11, 180415, 0, 12, 7486, '0', 0, 0, -9120.1201171875, 410.87847900390625, 93.64910125732421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+12, 180415, 0, 12, 7486, '0', 0, 0, -9118.5869140625, 410.732635498046875, 93.59493255615234375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+13, 180426, 0, 12, 7486, '0', 0, 0, -9091.8505859375, 417.109375, 111.1138076782226562, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+14, 180426, 0, 12, 7486, '0', 0, 0, -9106.642578125, 399.463531494140625, 111.6139068603515625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+15, 180426, 0, 12, 7486, '0', 0, 0, -9099.591796875, 407.727447509765625, 111.552276611328125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+16, 180426, 0, 12, 7486, '0', 0, 0, -9091.90625, 412.734375, 111.2841415405273437, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+17, 180426, 0, 12, 7486, '0', 0, 0, -9026.138671875, 380.114593505859375, 92.56472015380859375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+18, 180427, 0, 12, 7486, '0', 0, 0, -9101.095703125, 407.517364501953125, 92.59896087646484375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+19, 180427, 0, 12, 7486, '0', 0, 0, -9095.00390625, 404.048614501953125, 111.7063827514648437, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+20, 180427, 0, 12, 7486, '0', 0, 0, -9110.3193359375, 404.001739501953125, 111.8158798217773437, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+21, 180427, 0, 12, 7486, '0', 0, 0, -9106.001953125, 409.91839599609375, 122.5123062133789062, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+22, 180427, 0, 12, 7486, '0', 0, 0, -9112.419921875, 398, 111.7025985717773437, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+23, 180428, 0, 12, 7486, '0', 0, 0, -9116.25, 417.76910400390625, 93.86957550048828125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+24, 180428, 0, 12, 7486, '0', 0, 0, -9115.25390625, 419.2100830078125, 93.86255645751953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+25, 180428, 0, 12, 7486, '0', 0, 0, -9115.814453125, 418.560760498046875, 93.86072540283203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+26, 180431, 0, 12, 7486, '0', 0, 0, -9092.0283203125, 434.91839599609375, 122.6493911743164062, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+27, 180431, 0, 12, 7486, '0', 0, 0, -9107.638671875, 457.564239501953125, 99.79166412353515625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+28, 180433, 0, 12, 7486, '0', 0, 0, -9062.8525390625, 379.8194580078125, 93.17548370361328125, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- The Wickerman (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+29, 180471, 0, 12, 7486, '0', 0, 0, -9112.2568359375, 424.211822509765625, 97.31371307373046875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+30, 180471, 0, 12, 7486, '0', 0, 0, -9110.4375, 425.661468505859375, 97.386871337890625, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+31, 180472, 0, 12, 7486, '0', 0, 0, -9111.3544921875, 425.078125, 99.0186920166015625, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+32, 180523, 0, 12, 7486, '0', 0, 0, -9102.6044921875, 430.84375, 93.6756134033203125, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- Apple Bob (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+33, 180701, 0, 12, 7486, '0', 0, 0, -9066.34765625, 395.270843505859375, 93.038116455078125, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- Hay Bale 2 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+34, 195164, 0, 12, 7486, '0', 0, 0, -9067.81640625, 396.34375, 93.31272125244140625, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+35, 195164, 0, 12, 7486, '0', 0, 0, -9063.3056640625, 392.33160400390625, 92.69281005859375, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+36, 195164, 0, 12, 7486, '0', 0, 0, -9071.7275390625, 399.0538330078125, 93.68441009521484375, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+37, 195212, 0, 12, 7486, '0', 0, 0, -9116.154296875, 420.770843505859375, 93.6655426025390625, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+38, 195212, 0, 12, 7486, '0', 0, 0, -9092.4169921875, 385.8507080078125, 93.198150634765625, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+39, 195212, 0, 12, 7486, '0', 0, 0, -9107.5380859375, 428.888885498046875, 93.46044921875, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+40, 195212, 0, 12, 7486, '0', 0, 0, -9085.21875, 379.204864501953125, 92.40494537353515625, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+41, 195212, 0, 12, 7486, '0', 0, 0, -9072.544921875, 400.0850830078125, 93.520660400390625, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- Pumpkin (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+42, 208069, 0, 12, 7486, '0', 0, 0, -9100.45703125, 432.696197509765625, 93.55779266357421875, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- G_Pumpkin_02 Scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+43, 208072, 0, 12, 7486, '0', 0, 0, -9099.7783203125, 432.84027099609375, 94.29022216796875, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_Pumpkin_03 Scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+44, 208078, 0, 12, 7486, '0', 0, 0, -9099.3173828125, 433.149322509765625, 93.5729217529296875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 0.5 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+45, 208186, 0, 12, 7486, '0', 0, 0, -9083.12890625, 397.65277099609375, 93.6082611083984375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- Bonfire (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+46, 208210, 0, 12, 7486, '0', 0, 0, -9112.626953125, 426.6632080078125, 92.81131744384765625, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- Worgen Trellis (White) (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+47, 208211, 0, 12, 7486, '0', 0, 0, -9116.1611328125, 421.15277099609375, 92.1747283935546875, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- Worgen Trellis (Stand) (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+48, 208211, 0, 12, 7486, '0', 0, 0, -9106.892578125, 429.508697509765625, 92.1670074462890625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- Worgen Trellis (Stand) (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+49, 208211, 0, 12, 7486, '0', 0, 0, -9069.1826171875, 398.427093505859375, 93.6634063720703125, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- Worgen Trellis (Stand) (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+50, 208212, 0, 12, 7486, '0', 0, 0, -9100.3173828125, 432.298614501953125, 93.26026153564453125, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- Worgen Market Stall 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+51, 208213, 0, 12, 7486, '0', 0, 0, -9115.8076171875, 428.473968505859375, 92.8636627197265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+52, 208213, 0, 12, 7486, '0', 0, 0, -9101.7587890625, 391.755218505859375, 92.77898406982421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+53, 208213, 0, 12, 7486, '0', 0, 0, -9113.6943359375, 429.59722900390625, 92.6135406494140625, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+54, 208213, 0, 12, 7486, '0', 0, 0, -9125.0263671875, 412.5850830078125, 94.09922027587890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+55, 208213, 0, 12, 7486, '0', 0, 0, -9064.3349609375, 393.673614501953125, 92.74322509765625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+56, 208213, 0, 12, 7486, '0', 0, 0, -9062.7236328125, 393.817718505859375, 92.63564300537109375, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- Westfall Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+57, 208214, 0, 12, 7486, '0', 0, 0, -9117.390625, 417.416656494140625, 93.23050689697265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+58, 208214, 0, 12, 7486, '0', 0, 0, -9119.8642578125, 416.42535400390625, 93.1808624267578125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+59, 208214, 0, 12, 7486, '0', 0, 0, -9108.580078125, 415.385406494140625, 92.26682281494140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+60, 208214, 0, 12, 7486, '0', 0, 0, -9121.5517578125, 407.6007080078125, 92.20236968994140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+61, 208214, 0, 12, 7486, '0', 0, 0, -9101.591796875, 421.338531494140625, 91.93033599853515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+62, 208214, 0, 12, 7486, '0', 0, 0, -9122.486328125, 413.8663330078125, 93.17502593994140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+63, 208214, 0, 12, 7486, '0', 0, 0, -9122.625, 410.4375, 92.98593902587890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Northrend Torch 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+64, 208215, 0, 12, 7486, '0', 0, 0, -9113.8837890625, 423.201385498046875, 93.73236846923828125, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+65, 208215, 0, 12, 7486, '0', 0, 0, -9109.0830078125, 427.536468505859375, 93.44855499267578125, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+66, 208215, 0, 12, 7486, '0', 0, 0, -9121.47265625, 404.927093505859375, 92.53562164306640625, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+67, 208215, 0, 12, 7486, '0', 0, 0, -9095.3212890625, 393.946197509765625, 92.83895111083984375, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+68, 208215, 0, 12, 7486, '0', 0, 0, -9086.7763671875, 381.578125, 92.7762298583984375, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+69, 208215, 0, 12, 7486, '0', 0, 0, -9071.857421875, 403.689239501953125, 93.31462860107421875, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+70, 208215, 0, 12, 7486, '0', 0, 0, -9063.1611328125, 394.41839599609375, 92.651641845703125, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- Worgen Town Lamp 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+71, 208216, 0, 12, 7486, '0', 0, 0, -9101.62890625, 412.770843505859375, 92.50441741943359375, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+72, 208216, 0, 12, 7486, '0', 0, 0, -9094.095703125, 412.838531494140625, 92.1291961669921875, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+73, 208216, 0, 12, 7486, '0', 0, 0, -9102.42578125, 406.927093505859375, 92.6372222900390625, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+74, 208216, 0, 12, 7486, '0', 0, 0, -9090.9970703125, 421.9132080078125, 92.1296844482421875, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+75, 208216, 0, 12, 7486, '0', 0, 0, -9071.9892578125, 380.90625, 92.61814117431640625, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+76, 208216, 0, 12, 7486, '0', 0, 0, -9062.185546875, 385.126739501953125, 92.9355010986328125, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+77, 208216, 0, 12, 7486, '0', 0, 0, -9067.58203125, 386.197906494140625, 92.6453399658203125, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+78, 208216, 0, 12, 7486, '0', 0, 0, -9074.5, 382.336822509765625, 92.62985992431640625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+79, 208216, 0, 12, 7486, '0', 0, 0, -9065.794921875, 371.6319580078125, 93.1198883056640625, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+80, 208216, 0, 12, 7486, '0', 0, 0, -9072.22265625, 378.1875, 92.51285552978515625, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+81, 208216, 0, 12, 7486, '0', 0, 0, -9059.9892578125, 380.267364501953125, 93.60398101806640625, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- VR Straw Small 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+82, 208218, 0, 12, 7486, '0', 0, 0, -9096.69140625, 396.16839599609375, 92.63519287109375, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- Elwynn Fence (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+83, 208219, 0, 12, 7486, '0', 0, 0, -9090.9580078125, 387.65972900390625, 93.09214019775390625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- Worgen Town Fence 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+84, 208219, 0, 12, 7486, '0', 0, 0, -9067.9638671875, 398.4600830078125, 93.4190521240234375, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- Worgen Town Fence 03 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+85, 208220, 0, 12, 7486, '0', 0, 0, -9105.9130859375, 390.614593505859375, 92.6953887939453125, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- Worgen Water Trough (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+86, 208220, 0, 12, 7486, '0', 0, 0, -9100.984375, 396.052093505859375, 92.61457061767578125, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- Worgen Water Trough (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+87, 208221, 0, 12, 7486, '0', 0, 0, -9068.923828125, 397.8194580078125, 93.6302642822265625, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- Elwynn Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+88, 208221, 0, 12, 7486, '0', 0, 0, -9070.123046875, 398.977447509765625, 94.34395599365234375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- Elwynn Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+89, 208221, 0, 12, 7486, '0', 0, 0, -9070.09375, 398.795135498046875, 93.65976715087890625, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- Elwynn Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+90, 208221, 0, 12, 7486, '0', 0, 0, -9068.8369140625, 397.899322509765625, 94.3208770751953125, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Elwynn Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+91, 208221, 0, 12, 7486, '0', 0, 0, -9069.5205078125, 398.53125, 95.02689361572265625, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- Elwynn Hay Stack 01 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+92, 208222, 0, 12, 7486, '0', 0, 0, -9102.4658203125, 383.52777099609375, 93.77756500244140625, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- Worgen Stagecoach (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+93, 208223, 0, 12, 7486, '0', 0, 0, -9068.4736328125, 383.211822509765625, 88.3848114013671875, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Worgen Gallows 2 (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+94, 208394, 0, 12, 7486, '0', 0, 0, -9098.330078125, 432.439239501953125, 93.50778961181640625, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- Pile of Candy (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+95, 208394, 0, 12, 7486, '0', 0, 0, -9097.46875, 432.5625, 93.46176910400390625, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 45745), -- Pile of Candy (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+96, 208394, 0, 12, 7486, '0', 0, 0, -9096.7138671875, 432.248260498046875, 93.39715576171875, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- Pile of Candy (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+97, 208394, 0, 12, 7486, '0', 0, 0, -9096.97265625, 433.0069580078125, 93.4407958984375, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- Pile of Candy (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+98, 208395, 0, 12, 7486, '0', 0, 0, -9096.4970703125, 433.609375, 93.4280242919921875, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 45745), -- Candy Bucket (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+99, 208395, 0, 12, 7486, '0', 0, 0, -9097.97265625, 433.46527099609375, 93.5052337646484375, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- Candy Bucket (Area: Stormwind Gate - Difficulty: 0)
(@OGUID+100, 209139, 0, 12, 7486, '0', 0, 0, -9062.8525390625, 379.8194580078125, 93.17548370361328125, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- Wickerman (Area: Stormwind Gate - Difficulty: 0)
-- Stormwind City
(@OGUID+101, 180405, 0, 1519, 1617, '0', 0, 0, -8877.51953125, 543.02398681640625, 106.2829971313476562, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+102, 180405, 0, 1519, 1617, '0', 0, 0, -8858.3203125, 479.90301513671875, 113.2549972534179687, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+103, 180405, 0, 1519, 1617, '0', 0, 0, -8997.099609375, 501.587005615234375, 97.19609832763671875, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+104, 180405, 0, 1519, 1617, '0', 0, 0, -8908.900390625, 621.030029296875, 99.5260009765625, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+105, 180405, 0, 1519, 1617, '0', 0, 0, -8982.240234375, 483.9530029296875, 97.18890380859375, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+106, 180405, 0, 1519, 1617, '0', 0, 0, -8848.91015625, 546.41802978515625, 99.9998016357421875, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+107, 180405, 0, 1519, 1617, '0', 0, 0, -9031.1103515625, 474.47698974609375, 94.91570281982421875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+108, 180405, 0, 1519, 1617, '0', 0, 0, -9016.5302734375, 456.785003662109375, 95.00930023193359375, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+109, 180405, 0, 1519, 1617, '0', 0, 0, -8853.541015625, 584.3304443359375, 95.48654937744140625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+110, 180405, 0, 1519, 0, '0', 0, 0, -8768.580078125, 483.322998046875, 98.7714996337890625, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+111, 180405, 0, 1519, 0, '0', 0, 0, -8836.5361328125, 602.79351806640625, 95.79341888427734375, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+112, 180405, 0, 1519, 0, '0', 0, 0, -8850.115234375, 634.92462158203125, 98.20984649658203125, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+113, 180405, 0, 1519, 5148, '0', 0, 0, -8747.8603515625, 551.72198486328125, 100.4229965209960937, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+114, 180405, 0, 1519, 5148, '0', 0, 0, -8740.759765625, 559.47900390625, 100.5009994506835937, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+115, 180405, 0, 1519, 5148, '0', 0, 0, -8807.1796875, 646.36102294921875, 96.1927032470703125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+116, 180405, 0, 1519, 5148, '0', 0, 0, -8897.16015625, 639.3800048828125, 99.5386962890625, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+117, 180405, 0, 1519, 5148, '0', 0, 0, -8811.4296875, 659.17498779296875, 99.53260040283203125, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+118, 180405, 0, 1519, 5148, '0', 0, 0, -8855.8798828125, 664.22515869140625, 97.31143951416015625, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+119, 180405, 0, 1519, 5148, '0', 0, 0, -8705.1298828125, 588.9169921875, 99.954803466796875, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+120, 180405, 0, 1519, 5148, '0', 0, 0, -8853.580078125, 725.00299072265625, 99.920196533203125, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+121, 180405, 0, 1519, 5148, '0', 0, 0, -8843.7099609375, 729.135009765625, 100.1729965209960937, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+122, 180405, 0, 1519, 5148, '0', 0, 0, -8871.5595703125, 754.60797119140625, 99.13410186767578125, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+123, 180405, 0, 1519, 5148, '0', 0, 0, -8863.0302734375, 760.75299072265625, 99.6454010009765625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+124, 180405, 0, 1519, 5148, '0', 0, 0, -8715.0400390625, 727.114990234375, 100.3160018920898437, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+125, 180405, 0, 1519, 5148, '0', 0, 0, -8722.8203125, 736.48602294921875, 100.2789993286132812, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+126, 180405, 0, 1519, 5148, '0', 0, 0, -8744.8798828125, 719.010009765625, 100.7979965209960937, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+127, 180405, 0, 1519, 5148, '0', 0, 0, -8737.26953125, 709.38201904296875, 101.4889984130859375, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+128, 180405, 0, 1519, 5148, '0', 0, 0, -8720.8896484375, 520.78802490234375, 99.44219970703125, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+129, 180405, 0, 1519, 5148, '0', 0, 0, -8712.25, 526.4840087890625, 100.1129989624023437, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+130, 180405, 0, 1519, 5148, '0', 0, 0, -8707.8095703125, 467.37701416015625, 96.63179779052734375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Trade District - Difficulty: 0)
(@OGUID+131, 180405, 0, 1519, 5390, '0', 0, 0, -8678.349609375, 481.529998779296875, 97.16539764404296875, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+132, 180405, 0, 1519, 5390, '0', 0, 0, -8704.5595703125, 422.0889892578125, 99.27239990234375, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+133, 180405, 0, 1519, 5390, '0', 0, 0, -8681.98046875, 429.634002685546875, 99.6869964599609375, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+134, 180405, 0, 1519, 5390, '0', 0, 0, -8629.150390625, 547.44598388671875, 101.2600021362304687, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+135, 180405, 0, 1519, 5390, '0', 0, 0, -8613.01953125, 520.0780029296875, 106.3470001220703125, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+136, 180405, 0, 1519, 5390, '0', 0, 0, -8605.7802734375, 512.3489990234375, 106.345001220703125, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+137, 180405, 0, 1519, 5390, '0', 0, 0, -8585.9296875, 544.052001953125, 104.3779983520507812, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+138, 180405, 0, 1519, 5390, '0', 0, 0, -8580.58984375, 534.90997314453125, 104.6060028076171875, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+139, 180405, 0, 1519, 5390, '0', 0, 0, -8593.25, 597.50701904296875, 104.6360015869140625, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+140, 180405, 0, 1519, 5390, '0', 0, 0, -8600.2001953125, 452.592010498046875, 97.53420257568359375, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+141, 180405, 0, 1519, 5390, '0', 0, 0, -8621.400390625, 425.339996337890625, 103.7020034790039062, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+142, 180405, 0, 1519, 5390, '0', 0, 0, -8547.1796875, 452.65301513671875, 104.91400146484375, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+143, 180405, 0, 1519, 5390, '0', 0, 0, -8533.73046875, 464.670013427734375, 104.9069976806640625, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+144, 180405, 0, 1519, 5390, '0', 0, 0, -8496.240234375, 527.86798095703125, 100.4339981079101562, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+145, 180405, 0, 1519, 0, '0', 0, 0, -8667.419921875, 395.511993408203125, 104.3479995727539062, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+146, 180405, 0, 1519, 5390, '0', 0, 0, -8610.7197265625, 694.0159912109375, 103.4860000610351562, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+147, 180405, 0, 1519, 0, '0', 0, 0, -8500.830078125, 319.0989990234375, 138.05499267578125, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+148, 180405, 0, 1519, 0, '0', 0, 0, -8418.4501953125, 384.459991455078125, 138.05499267578125, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+149, 180405, 0, 1519, 5390, '0', 0, 0, -8404.849609375, 560.35101318359375, 92.117401123046875, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+150, 180405, 0, 1519, 5150, '0', 0, 0, -8391.1298828125, 571.35101318359375, 91.85970306396484375, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+151, 180405, 0, 1519, 5150, '0', 0, 0, -8475.009765625, 609.40301513671875, 95.2220001220703125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+152, 180405, 0, 1519, 5390, '0', 0, 0, -8517.83984375, 654.79998779296875, 103.0380020141601562, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+153, 180405, 0, 1519, 5390, '0', 0, 0, -8509.419921875, 660.7340087890625, 103.0370025634765625, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+154, 180405, 0, 1519, 5390, '0', 0, 0, -8527, 686.072998046875, 100.7570037841796875, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+155, 180405, 0, 1519, 5390, '0', 0, 0, -8535.759765625, 680.10198974609375, 100.753997802734375, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+156, 180405, 0, 1519, 5390, '0', 0, 0, -8423.76953125, 672.00897216796875, 94.7082977294921875, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+157, 180405, 0, 1519, 5390, '0', 0, 0, -8559.3798828125, 744.51702880859375, 101.7190017700195312, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+158, 180405, 0, 1519, 5314, '0', 0, 0, -8376.080078125, 676.13702392578125, 97.15460205078125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+159, 180405, 0, 1519, 5314, '0', 0, 0, -8360.9296875, 679.7860107421875, 97.15460205078125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+160, 180405, 0, 1519, 5314, '0', 0, 0, -8475.41015625, 796.09600830078125, 106.375, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+161, 180405, 0, 1519, 5150, '0', 0, 0, -8340.259765625, 629.73797607421875, 96.317596435546875, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+162, 180405, 0, 1519, 5150, '0', 0, 0, -8366.6396484375, 575.07098388671875, 97.003997802734375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+163, 180405, 0, 1519, 5150, '0', 0, 0, -8315.150390625, 592.15802001953125, 99.602203369140625, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+164, 180405, 0, 1519, 9171, '0', 0, 0, -8252.51953125, 874.51702880859375, 100.4209976196289062, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+165, 180405, 0, 1519, 9171, '0', 0, 0, -8239.3095703125, 887.70001220703125, 100.4209976196289062, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+166, 180405, 0, 1519, 9171, '0', 0, 0, -8266.4599609375, 888.9439697265625, 100.4209976196289062, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+167, 180405, 0, 1519, 9171, '0', 0, 0, -8256.1201171875, 895.9439697265625, 100.4209976196289062, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+168, 180405, 0, 1519, 5316, '0', 0, 0, -8277.98046875, 903.7340087890625, 100.4209976196289062, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+169, 180405, 0, 1519, 5316, '0', 0, 0, -8339.1796875, 939.63897705078125, 103.2509994506835937, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+170, 180405, 0, 1519, 5316, '0', 0, 0, -8378.1298828125, 915.32098388671875, 98.36409759521484375, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+171, 180405, 0, 1519, 5346, '0', 0, 0, -8286.6103515625, 986.41497802734375, 101.4520034790039062, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+172, 180405, 0, 1519, 5346, '0', 0, 0, -8299.240234375, 999.39599609375, 101.4520034790039062, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+173, 180405, 0, 1519, 5346, '0', 0, 0, -8384.830078125, 988.52301025390625, 101.5240020751953125, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+174, 180405, 0, 1519, 5346, '0', 0, 0, -8393.9501953125, 988.8060302734375, 101.7529983520507812, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+175, 180405, 0, 1519, 5346, '0', 0, 0, -8351.08984375, 1064.030029296875, 57.69990158081054687, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+176, 180405, 0, 1519, 5346, '0', 0, 0, -8470.26953125, 999.79498291015625, 79.15830230712890625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+177, 180405, 0, 1519, 5346, '0', 0, 0, -8455.8955078125, 1006.06378173828125, 59.47325515747070312, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+178, 180405, 0, 1519, 5346, '0', 0, 0, -8458.919921875, 852.38201904296875, 105.7860031127929687, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+179, 180405, 0, 1519, 5346, '0', 0, 0, -8462.4697265625, 861.18902587890625, 105.7860031127929687, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+180, 180405, 0, 1519, 5346, '0', 0, 0, -8494.98046875, 861.27398681640625, 109.3990020751953125, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+181, 180405, 0, 1519, 5346, '0', 0, 0, -8456.58984375, 839.20697021484375, 105.7860031127929687, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+182, 180405, 0, 1519, 5346, '0', 0, 0, -8456.599609375, 831.0159912109375, 105.7860031127929687, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+183, 180405, 0, 1519, 5346, '0', 0, 0, -8544.0498046875, 941.51202392578125, 97.7133026123046875, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+184, 180405, 0, 1519, 0, '0', 0, 0, -8561.4296875, 863.68597412109375, 101.21099853515625, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+185, 180405, 0, 1519, 5390, '0', 0, 0, -8672.73046875, 825.0830078125, 97.16320037841796875, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+186, 180405, 0, 1519, 8411, '0', 0, 0, -8723.3017578125, 931.66839599609375, 86.41471099853515625, 4.178538322448730468, 0, 0, -0.8685770034790039, 0.495554238557815551, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+187, 180405, 0, 1519, 8411, '0', 0, 0, -8750.607421875, 931.97393798828125, 86.81105804443359375, 2.688765525817871093, 0, 0, 0.974477767944335937, 0.224484086036682128, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+188, 180405, 0, 1519, 8411, '0', 0, 0, -8749.361328125, 959.91143798828125, 86.81103515625, 1.023726105690002441, 0, 0, 0.489802360534667968, 0.871833503246307373, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+189, 180405, 0, 1519, 8411, '0', 0, 0, -8878.240234375, 879.85400390625, 102.322998046875, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+190, 180405, 0, 1519, 8411, '0', 0, 0, -8852.91015625, 928.61981201171875, 102.0762100219726562, 2.35172128677368164, 0, 0, 0.923021316528320312, 0.384748816490173339, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+191, 180405, 0, 1519, 5390, '0', 0, 0, -8885.4697265625, 813.82501220703125, 93.7655029296875, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+192, 180405, 0, 1519, 5390, '0', 0, 0, -8723.8408203125, 960.21875, 86.81098175048828125, 5.897133350372314453, 0, 0, -0.19182968139648437, 0.981428265571594238, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+193, 180405, 0, 1519, 4411, '0', 0, 0, -8601.2197265625, 985.61602783203125, 98.311798095703125, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+194, 180405, 0, 1519, 4411, '0', 0, 0, -8549.9736328125, 997.95574951171875, 89.73064422607421875, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+195, 180405, 0, 1519, 5151, '0', 0, 0, -8618.0498046875, 786.38702392578125, 97.29399871826171875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+196, 180405, 0, 1519, 5151, '0', 0, 0, -8611.0400390625, 777.46197509765625, 97.290496826171875, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+197, 180405, 0, 1519, 8411, '0', 0, 0, -8857.53515625, 937.45660400390625, 102.0147628784179687, 2.386630058288574218, 0, 0, 0.929595947265625, 0.368580222129821777, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+198, 180405, 0, 1519, 5390, '0', 0, 0, -8945.3095703125, 761.84698486328125, 91.0619964599609375, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+199, 180405, 0, 1519, 5390, '0', 0, 0, -8969.5703125, 781.49700927734375, 96.23439788818359375, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: The Canals - Difficulty: 0)
(@OGUID+200, 180405, 0, 1519, 5154, '0', 0, 0, -8982.91015625, 851.98297119140625, 29.62059974670410156, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+201, 180405, 0, 1519, 5154, '0', 0, 0, -8992.1298828125, 844.5, 29.62059974670410156, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+202, 180405, 0, 1519, 5154, '0', 0, 0, -9004.759765625, 854.21197509765625, 105.589996337890625, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+203, 180405, 0, 1519, 5154, '0', 0, 0, -9010.0498046875, 847.07598876953125, 105.8639984130859375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+204, 180405, 0, 1519, 5154, '0', 0, 0, -9014.2900390625, 891.96002197265625, 29.62070083618164062, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+205, 180405, 0, 1519, 5154, '0', 0, 0, -9023.150390625, 884.03997802734375, 29.62070083618164062, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+206, 180405, 0, 1519, 4411, '0', 0, 0, -8545.9599609375, 1045.232421875, 61.05007553100585937, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+207, 180405, 0, 1519, 4411, '0', 0, 0, -8567.6533203125, 1077.9329833984375, 22.49529457092285156, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+208, 180405, 0, 1519, 4411, '0', 0, 0, -8350.994140625, 1092.8675537109375, 57.26215362548828125, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+209, 180405, 0, 1519, 4411, '0', 0, 0, -8057.8515625, 1609.6143798828125, 5.811275005340576171, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+210, 180405, 0, 1519, 4411, '0', 0, 0, -8330.1640625, 1255.3896484375, 8.967671394348144531, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+211, 180405, 0, 1519, 4411, '0', 0, 0, -8230.9501953125, 1243.260009765625, 6.478409767150878906, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+212, 180405, 0, 1519, 4411, '0', 0, 0, -8437.501953125, 1188.8692626953125, 9.193880081176757812, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+213, 180405, 0, 1519, 4411, '0', 0, 0, -8525.109375, 1152.0421142578125, 22.52658653259277343, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+214, 180405, 0, 1519, 4411, '0', 0, 0, -8553.9013671875, 1153.029296875, 22.20646476745605468, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+215, 180405, 0, 1519, 4411, '0', 0, 0, -8587.4755859375, 1191.9266357421875, 5.448372840881347656, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+216, 180405, 0, 1519, 4411, '0', 0, 0, -8534.6044921875, 1256.9539794921875, 8.359218597412109375, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+217, 180405, 0, 1519, 4411, '0', 0, 0, -8612.31640625, 1302.8414306640625, 5.646243095397949218, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+218, 180405, 0, 1519, 4411, '0', 0, 0, -8620.158203125, 1329.2789306640625, 19.42191505432128906, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+219, 180405, 0, 1519, 4411, '0', 0, 0, -8437.9970703125, 1220.632568359375, 5.630232810974121093, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+220, 180406, 0, 1519, 1617, '0', 0, 0, -8857.41015625, 506.915008544921875, 109.5999984741210937, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+221, 180406, 0, 1519, 1617, '0', 0, 0, -8976.5400390625, 565.64898681640625, 93.8621978759765625, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+222, 180406, 0, 1519, 1617, '0', 0, 0, -8915.2099609375, 490.165008544921875, 93.86119842529296875, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+223, 180406, 0, 1519, 1617, '0', 0, 0, -8892.1298828125, 630.98297119140625, 99.526702880859375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+224, 180406, 0, 1519, 1617, '0', 0, 0, -8854.419921875, 474.761993408203125, 113.2549972534179687, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+225, 180406, 0, 1519, 0, '0', 0, 0, -8792.23046875, 489.9010009765625, 98.440399169921875, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+226, 180406, 0, 1519, 0, '0', 0, 0, -8850.3388671875, 618.57659912109375, 97.423828125, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+227, 180406, 0, 1519, 0, '0', 0, 0, -8804.6220703125, 618.99835205078125, 96.773101806640625, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+228, 180406, 0, 1519, 5148, '0', 0, 0, -8842.6298828125, 642.8590087890625, 97.77490234375, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+229, 180406, 0, 1519, 5148, '0', 0, 0, -8878.8212890625, 649.31671142578125, 96.0216827392578125, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+230, 180406, 0, 1519, 5148, '0', 0, 0, -8728.4599609375, 564.73297119140625, 98.64679718017578125, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+231, 180406, 0, 1519, 5148, '0', 0, 0, -8813.419921875, 664.00897216796875, 99.53260040283203125, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+232, 180406, 0, 1519, 5148, '0', 0, 0, -8864.6337890625, 659.0897216796875, 96.521453857421875, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+233, 180406, 0, 1519, 5148, '0', 0, 0, -8758.669921875, 653.85400390625, 106.1309967041015625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+234, 180406, 0, 1519, 5148, '0', 0, 0, -8898.01953125, 722.67401123046875, 98.6864013671875, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+235, 180406, 0, 1519, 5148, '0', 0, 0, -8823.099609375, 750.39898681640625, 99.37139892578125, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+236, 180406, 0, 1519, 5148, '0', 0, 0, -8842.7099609375, 764.4169921875, 97.6649017333984375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+237, 180406, 0, 1519, 5148, '0', 0, 0, -8721.330078125, 697.73602294921875, 99.94139862060546875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+238, 180406, 0, 1519, 5148, '0', 0, 0, -8691.0498046875, 624.60198974609375, 101.1839981079101562, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+239, 180406, 0, 1519, 5148, '0', 0, 0, -8701.66015625, 549.4580078125, 99.076202392578125, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Trade District - Difficulty: 0)
(@OGUID+240, 180406, 0, 1519, 5390, '0', 0, 0, -8745.23046875, 414.25201416015625, 98.2071990966796875, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+241, 180406, 0, 1519, 5390, '0', 0, 0, -8653.8896484375, 498.441009521484375, 105.1320037841796875, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+242, 180406, 0, 1519, 5390, '0', 0, 0, -8590.0400390625, 506.281005859375, 105.3259963989257812, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+243, 180406, 0, 1519, 5390, '0', 0, 0, -8570.58984375, 516.6939697265625, 101.4690017700195312, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+244, 180406, 0, 1519, 5390, '0', 0, 0, -8645.9296875, 443.3909912109375, 104.2679977416992187, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+245, 180406, 0, 1519, 5149, '0', 0, 0, -8700.650390625, 391.467010498046875, 105.608001708984375, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Old Town - Difficulty: 0)
(@OGUID+246, 180406, 0, 1519, 5390, '0', 0, 0, -8571.7802734375, 621.25299072265625, 103.6019973754882812, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+247, 180406, 0, 1519, 0, '0', 0, 0, -8422.8798828125, 374.9010009765625, 138.05499267578125, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+248, 180406, 0, 1519, 0, '0', 0, 0, -8490.33984375, 321.183990478515625, 138.05499267578125, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+249, 180406, 0, 1519, 0, '0', 0, 0, -8431.4296875, 330.49798583984375, 144.9010009765625, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+250, 180406, 0, 1519, 5150, '0', 0, 0, -8463.1103515625, 564.2030029296875, 100.1660003662109375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Dwarven District - Difficulty: 0)
(@OGUID+251, 180406, 0, 1519, 5390, '0', 0, 0, -8450.419921875, 593.5360107421875, 101.3720016479492187, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+252, 180406, 0, 1519, 5390, '0', 0, 0, -8407.6103515625, 579.24700927734375, 92.91570281982421875, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+253, 180406, 0, 1519, 5390, '0', 0, 0, -8470.080078125, 641.89599609375, 94.3354034423828125, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+254, 180406, 0, 1519, 5390, '0', 0, 0, -8466.6103515625, 711.7860107421875, 101.4940032958984375, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+255, 180406, 0, 1519, 5390, '0', 0, 0, -8574, 729.73797607421875, 97.095001220703125, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+256, 180406, 0, 1519, 5390, '0', 0, 0, -8578.98046875, 725.90802001953125, 97.03589630126953125, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+257, 180406, 0, 1519, 5390, '0', 0, 0, -8366.0595703125, 678.4439697265625, 97.15460205078125, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+258, 180406, 0, 1519, 5150, '0', 0, 0, -8365.8701171875, 642.39801025390625, 96.141998291015625, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Dwarven District - Difficulty: 0)
(@OGUID+259, 180406, 0, 1519, 5150, '0', 0, 0, -8384.5400390625, 594.63897705078125, 97.77790069580078125, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Dwarven District - Difficulty: 0)
(@OGUID+260, 180406, 0, 1519, 5150, '0', 0, 0, -8324.240234375, 584.84698486328125, 99.602203369140625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Dwarven District - Difficulty: 0)
(@OGUID+261, 180406, 0, 1519, 5150, '0', 0, 0, -8328.0400390625, 607.375, 99.6053009033203125, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Dwarven District - Difficulty: 0)
(@OGUID+262, 180406, 0, 1519, 9171, '0', 0, 0, -8240.6796875, 880.69598388671875, 100.4209976196289062, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+263, 180406, 0, 1519, 9171, '0', 0, 0, -8258.8095703125, 877.8699951171875, 100.4209976196289062, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+264, 180406, 0, 1519, 9171, '0', 0, 0, -8249.0498046875, 897.42401123046875, 100.4209976196289062, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+265, 180406, 0, 1519, 9171, '0', 0, 0, -8270.76953125, 900.22698974609375, 100.4209976196289062, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+266, 180406, 0, 1519, 9171, '0', 0, 0, -8281.4599609375, 896.28802490234375, 100.4209976196289062, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+267, 180406, 0, 1519, 5316, '0', 0, 0, -8325.150390625, 932.4530029296875, 103.5619964599609375, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+268, 180406, 0, 1519, 5346, '0', 0, 0, -8332.6796875, 952.69097900390625, 103.05999755859375, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+269, 180406, 0, 1519, 5346, '0', 0, 0, -8394.31640625, 1029.344970703125, 68.38376617431640625, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+270, 180406, 0, 1519, 5346, '0', 0, 0, -8420.98046875, 910.51397705078125, 98.4123992919921875, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+271, 180406, 0, 1519, 5346, '0', 0, 0, -8443.0361328125, 1012.00677490234375, 80.9521484375, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+272, 180406, 0, 1519, 5346, '0', 0, 0, -8507.5, 931.64801025390625, 97.56020355224609375, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+273, 180406, 0, 1519, 5346, '0', 0, 0, -8509.5908203125, 970.04437255859375, 59.47861862182617187, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+274, 180406, 0, 1519, 5346, '0', 0, 0, -8490.91015625, 873.98297119140625, 109.305999755859375, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+275, 180406, 0, 1519, 5346, '0', 0, 0, -8536.25, 897.34722900390625, 109.7698287963867187, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+276, 180406, 0, 1519, 0, '0', 0, 0, -8486.3798828125, 828.00299072265625, 109.48699951171875, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+277, 180406, 0, 1519, 0, '0', 0, 0, -8518.4599609375, 787.48297119140625, 101.3570022583007812, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+278, 180406, 0, 1519, 0, '0', 0, 0, -8554.111328125, 766.86456298828125, 107.7607421875, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+279, 180406, 0, 1519, 5390, '0', 0, 0, -8616.01953125, 752.7030029296875, 96.9788970947265625, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+280, 180406, 0, 1519, 5390, '0', 0, 0, -8683.8203125, 775.8699951171875, 97.93250274658203125, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+281, 180406, 0, 1519, 5390, '0', 0, 0, -8665.8798828125, 776.427001953125, 101.7190017700195312, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+282, 180406, 0, 1519, 8411, '0', 0, 0, -8832.951171875, 926.046875, 91.24053955078125, 2.444442272186279296, 0, 0, 0.939860343933105468, 0.341559022665023803, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+283, 180406, 0, 1519, 8411, '0', 0, 0, -8830.3017578125, 919.09027099609375, 100.6258468627929687, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+284, 180406, 0, 1519, 5390, '0', 0, 0, -8618.9697265625, 861.90301513671875, 97.0240020751953125, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+285, 180406, 0, 1519, 5390, '0', 0, 0, -8661.0537109375, 964.44793701171875, 91.24069976806640625, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+286, 180406, 0, 1519, 5390, '0', 0, 0, -8584.2001953125, 965.54498291015625, 98.25029754638671875, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+287, 180406, 0, 1519, 4411, '0', 0, 0, -8571.1533203125, 1019.9495849609375, 96.731658935546875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+288, 180406, 0, 1519, 8411, '0', 0, 0, -8853.75, 955.421875, 103.7477569580078125, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+289, 180406, 0, 1519, 8411, '0', 0, 0, -8916.7001953125, 939.61102294921875, 117.1019973754882812, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+290, 180406, 0, 1519, 5390, '0', 0, 0, -8922.8095703125, 867.75201416015625, 101.875, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+291, 180406, 0, 1519, 5390, '0', 0, 0, -8935.3896484375, 781.82598876953125, 88.39189910888671875, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: The Canals - Difficulty: 0)
(@OGUID+292, 180406, 0, 1519, 5154, '0', 0, 0, -9041.259765625, 874.07598876953125, 110.1959991455078125, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+293, 180406, 0, 1519, 4411, '0', 0, 0, -8464.5400390625, 1041.949951171875, 61.05009841918945312, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+294, 180406, 0, 1519, 4411, '0', 0, 0, -8520.3408203125, 1113.595947265625, 20.5460968017578125, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+295, 180406, 0, 1519, 4411, '0', 0, 0, -8338.17578125, 1115.33984375, 57.26215362548828125, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+296, 180406, 0, 1519, 4411, '0', 0, 0, -8047.78564453125, 1418.91162109375, 2.685236930847167968, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+297, 180406, 0, 1519, 4411, '0', 0, 0, -8066.38818359375, 1581.84033203125, 2.67505192756652832, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+298, 180406, 0, 1519, 4411, '0', 0, 0, -8341.62890625, 1255.1871337890625, 8.978458404541015625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+299, 180406, 0, 1519, 4411, '0', 0, 0, -8229.880859375, 1258.989013671875, 8.364377021789550781, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+300, 180406, 0, 1519, 4411, '0', 0, 0, -8315.0361328125, 1187.0758056640625, 9.407729148864746093, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+301, 180406, 0, 1519, 4411, '0', 0, 0, -8535.6142578125, 1153.127197265625, 22.34057235717773437, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+302, 180406, 0, 1519, 4411, '0', 0, 0, -8598.138671875, 1142.2847900390625, 21.67487716674804687, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+303, 180406, 0, 1519, 4411, '0', 0, 0, -8599.416015625, 1297.216796875, 17.15379714965820312, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+304, 180406, 0, 1519, 4411, '0', 0, 0, -8636.041015625, 1271.890380859375, 5.642852783203125, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+305, 180406, 0, 1519, 4411, '0', 0, 0, -8660.7333984375, 1310.8892822265625, 19.42049789428710937, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+306, 180406, 0, 1519, 4411, '0', 0, 0, -8451.650390625, 1220.75, 5.638700008392333984, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+307, 180407, 0, 1519, 1617, '0', 0, 0, -8903.3603515625, 499.2030029296875, 93.86139678955078125, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+308, 180407, 0, 1519, 1617, '0', 0, 0, -8850.599609375, 523.6669921875, 105.9759979248046875, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+309, 180407, 0, 1519, 1617, '0', 0, 0, -8889.4033203125, 594.79669189453125, 95.7745361328125, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+310, 180407, 0, 1519, 1617, '0', 0, 0, -8862.5302734375, 572.22601318359375, 95.3755035400390625, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+311, 180407, 0, 1519, 1617, '0', 0, 0, -8870.919921875, 495.489990234375, 113.1309967041015625, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+312, 180407, 0, 1519, 1617, '0', 0, 0, -8963.75, 574.76898193359375, 93.84040069580078125, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+313, 180407, 0, 1519, 1617, '0', 0, 0, -8860.7802734375, 524.6090087890625, 107.7710037231445312, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+314, 180407, 0, 1519, 1617, '0', 0, 0, -8914.2099609375, 631, 99.52629852294921875, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+315, 180407, 0, 1519, 1617, '0', 0, 0, -8858.7197265625, 607.280029296875, 92.71829986572265625, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+316, 180407, 0, 1519, 0, '0', 0, 0, -8773.1103515625, 512.15997314453125, 98.70379638671875, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+317, 180407, 0, 1519, 5148, '0', 0, 0, -8873.70703125, 640.32855224609375, 96.0894317626953125, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+318, 180407, 0, 1519, 5148, '0', 0, 0, -8788.0205078125, 640.45880126953125, 96.1278228759765625, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+319, 180407, 0, 1519, 5148, '0', 0, 0, -8846.76953125, 652.2969970703125, 97.77490234375, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+320, 180407, 0, 1519, 5148, '0', 0, 0, -8742.2197265625, 508.045013427734375, 97.91320037841796875, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+321, 180407, 0, 1519, 5148, '0', 0, 0, -8861.625, 681.380859375, 97.90305328369140625, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+322, 180407, 0, 1519, 5148, '0', 0, 0, -8884.0400390625, 718.29498291015625, 98.94519805908203125, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+323, 180407, 0, 1519, 5148, '0', 0, 0, -8758.349609375, 745.7919921875, 100.1429977416992187, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+324, 180407, 0, 1519, 5148, '0', 0, 0, -8702.2001953125, 666.71197509765625, 100.6620025634765625, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+325, 180407, 0, 1519, 5148, '0', 0, 0, -8664.669921875, 563.6719970703125, 98.2776031494140625, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Trade District - Difficulty: 0)
(@OGUID+326, 180407, 0, 1519, 5390, '0', 0, 0, -8736.580078125, 444.290008544921875, 99.10479736328125, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+327, 180407, 0, 1519, 5390, '0', 0, 0, -8667.25, 453.985992431640625, 104.2679977416992187, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+328, 180407, 0, 1519, 5390, '0', 0, 0, -8599.5498046875, 565.780029296875, 103.6890029907226562, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+329, 180407, 0, 1519, 5390, '0', 0, 0, -8625.8203125, 456.18798828125, 102.6959991455078125, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+330, 180407, 0, 1519, 5390, '0', 0, 0, -8565.51953125, 477.384002685546875, 106.1220016479492187, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+331, 180407, 0, 1519, 5390, '0', 0, 0, -8635.1796875, 425.360992431640625, 103.5660018920898437, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+332, 180407, 0, 1519, 5390, '0', 0, 0, -8541.3603515625, 644.03802490234375, 101.6910018920898437, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+333, 180407, 0, 1519, 0, '0', 0, 0, -8479.66015625, 320.912994384765625, 138.05499267578125, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+334, 180407, 0, 1519, 0, '0', 0, 0, -8424.919921875, 364.42498779296875, 138.05499267578125, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+335, 180407, 0, 1519, 0, '0', 0, 0, -8443.41015625, 320.77301025390625, 144.8820037841796875, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+336, 180407, 0, 1519, 5150, '0', 0, 0, -8485.099609375, 574.655029296875, 97.579803466796875, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+337, 180407, 0, 1519, 5150, '0', 0, 0, -8406.01953125, 581.0570068359375, 92.95999908447265625, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+338, 180407, 0, 1519, 5390, '0', 0, 0, -8438.58984375, 622.42498779296875, 95.08249664306640625, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+339, 180407, 0, 1519, 5390, '0', 0, 0, -8542.2802734375, 743.37200927734375, 99.7910003662109375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+340, 180407, 0, 1519, 5390, '0', 0, 0, -8409.5, 674.280029296875, 100.634002685546875, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+341, 180407, 0, 1519, 5390, '0', 0, 0, -8407.08984375, 660.64599609375, 97.51180267333984375, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+342, 180407, 0, 1519, 5390, '0', 0, 0, -8564.669921875, 740.63397216796875, 101.7190017700195312, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+343, 180407, 0, 1519, 5314, '0', 0, 0, -8371.150390625, 677.19598388671875, 97.15460205078125, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+344, 180407, 0, 1519, 5150, '0', 0, 0, -8355.099609375, 644.8699951171875, 96.141998291015625, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+345, 180407, 0, 1519, 5150, '0', 0, 0, -8355.3603515625, 617.781005859375, 96.317596435546875, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+346, 180407, 0, 1519, 5150, '0', 0, 0, -8335.3896484375, 600.64202880859375, 99.61730194091796875, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+347, 180407, 0, 1519, 5150, '0', 0, 0, -8323.669921875, 664.74298095703125, 97.43019866943359375, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Dwarven District - Difficulty: 0)
(@OGUID+348, 180407, 0, 1519, 9171, '0', 0, 0, -8245.5595703125, 875.79901123046875, 100.4209976196289062, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+349, 180407, 0, 1519, 9171, '0', 0, 0, -8242.5498046875, 894.01702880859375, 100.4209976196289062, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+350, 180407, 0, 1519, 9171, '0', 0, 0, -8262.76953125, 896.48602294921875, 100.4209976196289062, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+351, 180407, 0, 1519, 9171, '0', 0, 0, -8262.0400390625, 884.18798828125, 100.4209976196289062, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+352, 180407, 0, 1519, 9171, '0', 0, 0, -8274.26953125, 892.80902099609375, 100.4209976196289062, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+353, 180407, 0, 1519, 5316, '0', 0, 0, -8318.23046875, 946.33001708984375, 103.40899658203125, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+354, 180407, 0, 1519, 5346, '0', 0, 0, -8491.1396484375, 976.70697021484375, 73.002197265625, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+355, 180407, 0, 1519, 5346, '0', 0, 0, -8480.099609375, 862.03802490234375, 109.3550033569335937, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+356, 180407, 0, 1519, 5390, '0', 0, 0, -8621.3603515625, 748.50701904296875, 96.93019866943359375, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+357, 180407, 0, 1519, 5390, '0', 0, 0, -8660.400390625, 780.5830078125, 101.7190017700195312, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+358, 180407, 0, 1519, 5151, '0', 0, 0, -8813.650390625, 782.625, 98.64260101318359375, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+359, 180407, 0, 1519, 5390, '0', 0, 0, -8785.515625, 880.95831298828125, 100.3386001586914062, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+360, 180407, 0, 1519, 5390, '0', 0, 0, -8614.0703125, 865.77099609375, 97.02339935302734375, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+361, 180407, 0, 1519, 5390, '0', 0, 0, -8640.7900390625, 930.96356201171875, 97.69040679931640625, 1.068250894546508789, 0, 0, 0.509088516235351562, 0.860714137554168701, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+362, 180407, 0, 1519, 5390, '0', 0, 0, -8591.16015625, 926.27398681640625, 99.6110992431640625, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+363, 180407, 0, 1519, 4411, '0', 0, 0, -8562.759765625, 1013.6099853515625, 89.73059844970703125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+364, 180407, 0, 1519, 4411, '0', 0, 0, -8545.2802734375, 987.81097412109375, 96.73169708251953125, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+365, 180407, 0, 1519, 8411, '0', 0, 0, -8902.4296875, 970.8489990234375, 120.9980010986328125, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+366, 180407, 0, 1519, 5390, '0', 0, 0, -8998.5, 805.66802978515625, 106.5019989013671875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: The Canals - Difficulty: 0)
(@OGUID+367, 180407, 0, 1519, 5154, '0', 0, 0, -8954.16015625, 880.91802978515625, 105.4680023193359375, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+368, 180407, 0, 1519, 4411, '0', 0, 0, -8509.7412109375, 1037.3822021484375, 59.43825149536132812, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+369, 180407, 0, 1519, 4411, '0', 0, 0, -8573.103515625, 1091.0931396484375, 22.47002410888671875, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+370, 180407, 0, 1519, 4411, '0', 0, 0, -8610.1298828125, 1080.6199951171875, 41.25510025024414062, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+371, 180407, 0, 1519, 4411, '0', 0, 0, -8394.728515625, 1066.714599609375, 31.93279647827148437, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+372, 180407, 0, 1519, 4411, '0', 0, 0, -8353.400390625, 1079.050048828125, 59.21979904174804687, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+373, 180407, 0, 1519, 4411, '0', 0, 0, -8058.95849609375, 1419.3212890625, 2.674053907394409179, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+374, 180407, 0, 1519, 4411, '0', 0, 0, -8075.69775390625, 1587.8681640625, 2.67614603042602539, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+375, 180407, 0, 1519, 4411, '0', 0, 0, -8313.9609375, 1393.4935302734375, 17.16427993774414062, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+376, 180407, 0, 1519, 4411, '0', 0, 0, -8229.916015625, 1270.460693359375, 8.362120628356933593, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+377, 180407, 0, 1519, 4411, '0', 0, 0, -8451.4599609375, 1193.61279296875, 8.788401603698730468, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+378, 180407, 0, 1519, 4411, '0', 0, 0, -8544.0888671875, 1153.2752685546875, 22.31786346435546875, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+379, 180407, 0, 1519, 4411, '0', 0, 0, -8596.58203125, 1152.296875, 22.54824256896972656, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+380, 180407, 0, 1519, 4411, '0', 0, 0, -8557.619140625, 1200.9000244140625, 8.148015022277832031, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+381, 180407, 0, 1519, 4411, '0', 0, 0, -8534.513671875, 1268.3277587890625, 8.364304542541503906, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+382, 180407, 0, 1519, 4411, '0', 0, 0, -8603.80859375, 1294.1529541015625, 17.16453361511230468, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+383, 180408, 0, 1519, 5148, '0', 0, 0, -8743.7802734375, 702.4840087890625, 103.4449996948242187, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Trade District - Difficulty: 0)
(@OGUID+384, 180408, 0, 1519, 5148, '0', 0, 0, -8736.169921875, 693.20501708984375, 103.4580001831054687, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Trade District - Difficulty: 0)
(@OGUID+385, 180408, 0, 1519, 5390, '0', 0, 0, -8755.3095703125, 403.677001953125, 109.805999755859375, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: The Canals - Difficulty: 0)
(@OGUID+386, 180408, 0, 1519, 5390, '0', 0, 0, -8765.25, 396.045013427734375, 109.805999755859375, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: The Canals - Difficulty: 0)
(@OGUID+387, 180408, 0, 1519, 5150, '0', 0, 0, -8476.099609375, 579.31402587890625, 101.4690017700195312, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+388, 180408, 0, 1519, 5390, '0', 0, 0, -8436.73046875, 617.72698974609375, 99.743896484375, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: The Canals - Difficulty: 0)
(@OGUID+389, 180408, 0, 1519, 5314, '0', 0, 0, -8374.2900390625, 679.83697509765625, 98.65309906005859375, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+390, 180408, 0, 1519, 5314, '0', 0, 0, -8402.7099609375, 615.7080078125, 98.8760986328125, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+391, 180408, 0, 1519, 5150, '0', 0, 0, -8331.849609375, 634.5469970703125, 99.80460357666015625, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+392, 180408, 0, 1519, 5346, '0', 0, 0, -8298.2412109375, 974.11456298828125, 105.6805191040039062, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+393, 180408, 0, 1519, 5346, '0', 0, 0, -8311.826171875, 987.34893798828125, 105.7079391479492187, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+394, 180408, 0, 1519, 4411, '0', 0, 0, -8421.5380859375, 1119.6893310546875, 25.32225608825683593, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+395, 180408, 0, 1519, 4411, '0', 0, 0, -8349.453125, 1107.082763671875, 58.55839157104492187, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+396, 180408, 0, 1519, 4411, '0', 0, 0, -8042.5712890625, 1607.4576416015625, 4.083640098571777343, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+397, 180408, 0, 1519, 4411, '0', 0, 0, -8304.3251953125, 1362.921630859375, 8.523809432983398437, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+398, 180408, 0, 1519, 4411, '0', 0, 0, -8368.4677734375, 1299.6090087890625, 8.521785736083984375, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+399, 180408, 0, 1519, 4411, '0', 0, 0, -8395.583984375, 1302.3131103515625, 8.515392303466796875, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+400, 180408, 0, 1519, 4411, '0', 0, 0, -8461.0078125, 1298.739990234375, 8.524527549743652343, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+401, 180410, 0, 1519, 1617, '0', 0, 0, -8872.8251953125, 611.51983642578125, 97.77857208251953125, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+402, 180410, 0, 1519, 5148, '0', 0, 0, -8825.9501953125, 651.905029296875, 104.2320022583007812, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+403, 180410, 0, 1519, 5148, '0', 0, 0, -8828.6396484375, 658.09197998046875, 104.1880035400390625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+404, 180410, 0, 1519, 5148, '0', 0, 0, -8818.849609375, 655.14801025390625, 104.2050018310546875, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+405, 180410, 0, 1519, 5148, '0', 0, 0, -8821.4296875, 661.31097412109375, 104.1839981079101562, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+406, 180410, 0, 1519, 5148, '0', 0, 0, -8857.861328125, 676.605712890625, 98.750274658203125, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+407, 180410, 0, 1519, 5148, '0', 0, 0, -8855.95703125, 673.77020263671875, 98.74332427978515625, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+408, 180410, 0, 1519, 5148, '0', 0, 0, -8859.69140625, 679.49163818359375, 98.72249603271484375, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+409, 180410, 0, 1519, 5148, '0', 0, 0, -8683.48046875, 499.114990234375, 102.2170028686523437, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Trade District - Difficulty: 0)
(@OGUID+410, 180410, 0, 1519, 5390, '0', 0, 0, -8669.7802734375, 442.87799072265625, 103.2819976806640625, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: The Canals - Difficulty: 0)
(@OGUID+411, 180410, 0, 1519, 5390, '0', 0, 0, -8688.150390625, 407.233001708984375, 106.2949981689453125, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: The Canals - Difficulty: 0)
(@OGUID+412, 180410, 0, 1519, 5150, '0', 0, 0, -8416.4501953125, 538.63702392578125, 96.27680206298828125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+413, 180410, 0, 1519, 5150, '0', 0, 0, -8418.7802734375, 541.40301513671875, 96.26490020751953125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+414, 180410, 0, 1519, 5150, '0', 0, 0, -8415.0595703125, 556.59600830078125, 96.27230072021484375, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+415, 180410, 0, 1519, 5150, '0', 0, 0, -8410.669921875, 551.23797607421875, 96.276397705078125, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+416, 180410, 0, 1519, 5150, '0', 0, 0, -8412.9296875, 553.95098876953125, 96.28130340576171875, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+417, 180410, 0, 1519, 5150, '0', 0, 0, -8366.259765625, 604.64202880859375, 98.58119964599609375, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+418, 180410, 0, 1519, 5150, '0', 0, 0, -8384.98046875, 589.7030029296875, 98.566497802734375, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+419, 180410, 0, 1519, 5346, '0', 0, 0, -8462.5595703125, 952.2860107421875, 99.98850250244140625, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+420, 180410, 0, 1519, 4411, '0', 0, 0, -8224.6298828125, 1189.9984130859375, 16.07274055480957031, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+421, 180410, 0, 1519, 4411, '0', 0, 0, -8241.1181640625, 1207.6448974609375, 16.08688926696777343, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+422, 180410, 0, 1519, 4411, '0', 0, 0, -8231.0361328125, 1200.03125, 16.08105850219726562, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+423, 180410, 0, 1519, 4411, '0', 0, 0, -8282.68359375, 1189.9400634765625, 16.07331466674804687, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+424, 180410, 0, 1519, 4411, '0', 0, 0, -8266.1611328125, 1207.6773681640625, 16.08650398254394531, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+425, 180410, 0, 1519, 4411, '0', 0, 0, -8276.2998046875, 1200.078857421875, 16.07948875427246093, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+426, 180410, 0, 1519, 4411, '0', 0, 0, -8550.09375, 1200.034912109375, 16.09880638122558593, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+427, 180410, 0, 1519, 4411, '0', 0, 0, -8498.44921875, 1189.75634765625, 16.09288978576660156, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+428, 180410, 0, 1519, 4411, '0', 0, 0, -8540.05078125, 1207.4698486328125, 16.1066436767578125, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+429, 180410, 0, 1519, 4411, '0', 0, 0, -8504.7294921875, 1199.7811279296875, 16.09804153442382812, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+430, 180410, 0, 1519, 4411, '0', 0, 0, -8514.828125, 1207.3519287109375, 16.10811424255371093, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+431, 180411, 0, 1519, 1617, '0', 0, 0, -8863.1337890625, 578.011962890625, 109.8249282836914062, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+432, 180411, 0, 1519, 1617, '0', 0, 0, -8891.5595703125, 593.5955810546875, 99.43108367919921875, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+433, 180411, 0, 1519, 1617, '0', 0, 0, -8924.5595703125, 544.50201416015625, 100.7679977416992187, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+434, 180411, 0, 1519, 1617, '0', 0, 0, -8898.9296875, 625.47100830078125, 103.0770034790039062, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+435, 180411, 0, 1519, 1617, '0', 0, 0, -8913.2099609375, 632.70501708984375, 103.3339996337890625, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+436, 180411, 0, 1519, 0, '0', 0, 0, -8838.6533203125, 607.5159912109375, 105.986419677734375, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+437, 180411, 0, 1519, 5148, '0', 0, 0, -8840.7900390625, 651.89801025390625, 100.7519989013671875, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Trade District - Difficulty: 0)
(@OGUID+438, 180411, 0, 1519, 5148, '0', 0, 0, -8855.0849609375, 662.44793701171875, 108.7031402587890625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Trade District - Difficulty: 0)
(@OGUID+439, 180411, 0, 1519, 5148, '0', 0, 0, -8900.4501953125, 639.510009765625, 101.9430007934570312, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Trade District - Difficulty: 0)
(@OGUID+440, 180411, 0, 1519, 5390, '0', 0, 0, -8710.08984375, 462.3330078125, 107.4889984130859375, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+441, 180411, 0, 1519, 5390, '0', 0, 0, -8616.1103515625, 418.1610107421875, 108.5380020141601562, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+442, 180411, 0, 1519, 5390, '0', 0, 0, -8655.169921875, 419.60101318359375, 108.43499755859375, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+443, 180411, 0, 1519, 5390, '0', 0, 0, -8626.169921875, 731.57598876953125, 103.4390029907226562, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+444, 180411, 0, 1519, 0, '0', 0, 0, -8422.73046875, 344.77801513671875, 163.375, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+445, 180411, 0, 1519, 0, '0', 0, 0, -8458.4697265625, 316.162994384765625, 161.8679962158203125, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+446, 180411, 0, 1519, 5390, '0', 0, 0, -8503.4296875, 567.5469970703125, 102.1760025024414062, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+447, 180411, 0, 1519, 5150, '0', 0, 0, -8440.8603515625, 607.8189697265625, 103.6110000610351562, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+448, 180411, 0, 1519, 5390, '0', 0, 0, -8434.3701171875, 658.09197998046875, 97.62039947509765625, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+449, 180411, 0, 1519, 5390, '0', 0, 0, -8447.76953125, 646.60400390625, 98.20059967041015625, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+450, 180411, 0, 1519, 5390, '0', 0, 0, -8547.8798828125, 747.91497802734375, 103.8300018310546875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+451, 180411, 0, 1519, 5314, '0', 0, 0, -8370.599609375, 663.26702880859375, 101.9879989624023437, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+452, 180411, 0, 1519, 5314, '0', 0, 0, -8360.330078125, 672.864990234375, 103.108001708984375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+453, 180411, 0, 1519, 5346, '0', 0, 0, -8300.91015625, 973.69097900390625, 109.345001220703125, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+454, 180411, 0, 1519, 5346, '0', 0, 0, -8373.1396484375, 937.6199951171875, 104.5530014038085937, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+455, 180411, 0, 1519, 5346, '0', 0, 0, -8376.8896484375, 979.81097412109375, 105.897003173828125, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+456, 180411, 0, 1519, 5346, '0', 0, 0, -8429.419921875, 930.8189697265625, 102.8909988403320312, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+457, 180411, 0, 1519, 5390, '0', 0, 0, -8654.009765625, 790.60797119140625, 102.1579971313476562, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+458, 180411, 0, 1519, 5390, '0', 0, 0, -8629.7431640625, 946.357666015625, 107.8028030395507812, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+459, 180411, 0, 1519, 5390, '0', 0, 0, -8600.0087890625, 969.5538330078125, 108.019012451171875, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- G_Ghost_01 (Area: The Canals - Difficulty: 0)
(@OGUID+460, 180411, 0, 1519, 4411, '0', 0, 0, -8579.7451171875, 985.91668701171875, 105.8384323120117187, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+461, 180411, 0, 1519, 5154, '0', 0, 0, -8913.650390625, 995.72198486328125, 127.3980026245117187, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+462, 180411, 0, 1519, 4411, '0', 0, 0, -8197.4189453125, 1190.3194580078125, 27.60082626342773437, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+463, 180411, 0, 1519, 4411, '0', 0, 0, -8292.453125, 1190.6910400390625, 27.69700813293457031, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+464, 180411, 0, 1519, 4411, '0', 0, 0, -8470.998046875, 1190.2379150390625, 27.60507965087890625, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+465, 180411, 0, 1519, 4411, '0', 0, 0, -8566.1630859375, 1189.7430419921875, 27.82406044006347656, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+466, 180411, 0, 1519, 4411, '0', 0, 0, -8598.140625, 1239.267333984375, 25.00390625, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+467, 180415, 0, 1519, 1617, '0', 0, 0, -8859.080078125, 505.462005615234375, 112.7689971923828125, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+468, 180415, 0, 1519, 1617, '0', 0, 0, -8859.3203125, 501.8280029296875, 112.8740005493164062, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+469, 180415, 0, 1519, 1617, '0', 0, 0, -8858.0595703125, 503.321014404296875, 112.78399658203125, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+470, 180415, 0, 1519, 1617, '0', 0, 0, -8858.4404296875, 503.837005615234375, 112.8130035400390625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+471, 180415, 0, 1519, 1617, '0', 0, 0, -8858.73046875, 504.82598876953125, 112.6360015869140625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+472, 180415, 0, 1519, 1617, '0', 0, 0, -8909.099609375, 619.05902099609375, 104.9000015258789062, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+473, 180415, 0, 1519, 1617, '0', 0, 0, -8858.240234375, 504.1510009765625, 112.7529983520507812, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+474, 180415, 0, 1519, 1617, '0', 0, 0, -8858.58984375, 502.162994384765625, 112.7809982299804687, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+475, 180415, 0, 1519, 1617, '0', 0, 0, -8858.23046875, 502.720001220703125, 112.6060028076171875, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+476, 180415, 0, 1519, 1617, '0', 0, 0, -8859.830078125, 501.45098876953125, 112.7180023193359375, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+477, 180415, 0, 1519, 1617, '0', 0, 0, -8859.2802734375, 502.204986572265625, 112.8249969482421875, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+478, 180415, 0, 1519, 1617, '0', 0, 0, -8907.4599609375, 619.95501708984375, 105.197998046875, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+479, 180415, 0, 1519, 1617, '0', 0, 0, -8908.16015625, 619.52398681640625, 105.1520004272460937, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+480, 180415, 0, 1519, 1617, '0', 0, 0, -8859.490234375, 505.410003662109375, 112.904998779296875, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+481, 180415, 0, 1519, 1617, '0', 0, 0, -8857.7099609375, 502.865997314453125, 112.9110031127929687, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+482, 180415, 0, 1519, 1617, '0', 0, 0, -8906.66015625, 620.41302490234375, 104.9820022583007812, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+483, 180415, 0, 1519, 1617, '0', 0, 0, -8901.08984375, 623.489990234375, 104.9680023193359375, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+484, 180415, 0, 1519, 1617, '0', 0, 0, -8915.6796875, 632.155029296875, 104.8949966430664062, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+485, 180415, 0, 1519, 1617, '0', 0, 0, -8901.6396484375, 623.1939697265625, 104.8420028686523437, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+486, 180415, 0, 1519, 1617, '0', 0, 0, -8899.25, 624.5050048828125, 105.0879974365234375, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+487, 180415, 0, 1519, 1617, '0', 0, 0, -8895.990234375, 626.25897216796875, 105.1039962768554687, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+488, 180415, 0, 1519, 1617, '0', 0, 0, -8896.83984375, 625.780029296875, 104.94000244140625, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+489, 180415, 0, 1519, 1617, '0', 0, 0, -8904.0400390625, 621.83697509765625, 104.8339996337890625, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+490, 180415, 0, 1519, 1617, '0', 0, 0, -8904.599609375, 621.572998046875, 105.1200027465820312, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+491, 180415, 0, 1519, 1617, '0', 0, 0, -8902.1103515625, 622.92901611328125, 105.1230010986328125, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+492, 180415, 0, 1519, 1617, '0', 0, 0, -8902.8095703125, 622.510009765625, 105.125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+493, 180415, 0, 1519, 1617, '0', 0, 0, -8899.8095703125, 624.16998291015625, 104.96099853515625, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+494, 180415, 0, 1519, 1617, '0', 0, 0, -8900.41015625, 623.843994140625, 105.1480026245117187, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+495, 180415, 0, 1519, 1617, '0', 0, 0, -8897.7001953125, 625.35601806640625, 105.0319976806640625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+496, 180415, 0, 1519, 1617, '0', 0, 0, -8898.7099609375, 624.79998779296875, 105.0889968872070312, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+497, 180415, 0, 1519, 1617, '0', 0, 0, -8894.259765625, 627.197998046875, 105.1279983520507812, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+498, 180415, 0, 1519, 1617, '0', 0, 0, -8895.1201171875, 626.76702880859375, 104.947998046875, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+499, 180415, 0, 1519, 1617, '0', 0, 0, -8905.4404296875, 621.1090087890625, 104.9560012817382812, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+500, 180415, 0, 1519, 1617, '0', 0, 0, -8906.01953125, 620.75299072265625, 105.128997802734375, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+501, 180415, 0, 1519, 1617, '0', 0, 0, -8903.400390625, 622.25299072265625, 104.8809967041015625, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+502, 180415, 0, 1519, 1617, '0', 0, 0, -8889.740234375, 629.6610107421875, 104.9000015258789062, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+503, 180415, 0, 1519, 1617, '0', 0, 0, -8909.650390625, 635.36297607421875, 104.884002685546875, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+504, 180415, 0, 1519, 1617, '0', 0, 0, -8893.4599609375, 627.6510009765625, 104.9710006713867187, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+505, 180415, 0, 1519, 1617, '0', 0, 0, -8912.7998046875, 633.58697509765625, 105.0609970092773437, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+506, 180415, 0, 1519, 1617, '0', 0, 0, -8911.9296875, 634.125, 104.8339996337890625, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+507, 180415, 0, 1519, 1617, '0', 0, 0, -8890.3603515625, 629.30902099609375, 105.134002685546875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+508, 180415, 0, 1519, 1617, '0', 0, 0, -8891.1201171875, 628.96197509765625, 105.1100006103515625, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+509, 180415, 0, 1519, 1617, '0', 0, 0, -8914.7802734375, 632.51397705078125, 105.0839996337890625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+510, 180415, 0, 1519, 1617, '0', 0, 0, -8914.169921875, 632.88201904296875, 104.8369979858398437, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+511, 180415, 0, 1519, 1617, '0', 0, 0, -8889.1201171875, 630.0260009765625, 105.0869979858398437, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+512, 180415, 0, 1519, 1617, '0', 0, 0, -8911.1904296875, 634.54302978515625, 105.1220016479492187, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+513, 180415, 0, 1519, 1617, '0', 0, 0, -8910.4501953125, 634.90802001953125, 105.13800048828125, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+514, 180415, 0, 1519, 1617, '0', 0, 0, -8891.98046875, 628.42498779296875, 104.8830032348632812, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+515, 180415, 0, 1519, 1617, '0', 0, 0, -8892.73046875, 628.01202392578125, 105.1200027465820312, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+516, 180415, 0, 1519, 1617, '0', 0, 0, -8913.5498046875, 633.23797607421875, 105.141998291015625, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+517, 180415, 0, 1519, 1617, '0', 0, 0, -8838.009765625, 493.436004638671875, 110.4560012817382812, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+518, 180415, 0, 1519, 1617, '0', 0, 0, -8837.7998046875, 493.511993408203125, 110.5759963989257812, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+519, 180415, 0, 1519, 1617, '0', 0, 0, -8888.2197265625, 630.385009765625, 105.0329971313476562, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+520, 180415, 0, 1519, 1617, '0', 0, 0, -8837.7998046875, 493.32501220703125, 110.7020034790039062, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+521, 180415, 0, 1519, 1617, '0', 0, 0, -8908.7900390625, 635.79498291015625, 105.108001708984375, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+522, 180415, 0, 1519, 1617, '0', 0, 0, -8907.9296875, 636.30902099609375, 104.8280029296875, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+523, 180415, 0, 1519, 1617, '0', 0, 0, -8822.009765625, 564.58697509765625, 94.56490325927734375, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+524, 180415, 0, 1519, 1617, '0', 0, 0, -8822.0498046875, 565.09698486328125, 94.56220245361328125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+525, 180415, 0, 1519, 1617, '0', 0, 0, -8821.01953125, 563.40802001953125, 94.5630035400390625, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+526, 180415, 0, 1519, 1617, '0', 0, 0, -8821.509765625, 563.69097900390625, 94.564300537109375, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+527, 180415, 0, 1519, 1617, '0', 0, 0, -8821.8896484375, 564.03802490234375, 94.5626983642578125, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+528, 180415, 0, 1519, 1617, '0', 0, 0, -8819.900390625, 563.5419921875, 94.56220245361328125, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+529, 180415, 0, 1519, 1617, '0', 0, 0, -8819.25, 564.9320068359375, 94.56369781494140625, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+530, 180415, 0, 1519, 1617, '0', 0, 0, -8819.5703125, 563.93902587890625, 94.56420135498046875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+531, 180415, 0, 1519, 1617, '0', 0, 0, -8820.4599609375, 563.375, 94.56330108642578125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+532, 180415, 0, 1519, 1617, '0', 0, 0, -8821.7197265625, 565.59002685546875, 94.56109619140625, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+533, 180415, 0, 1519, 1617, '0', 0, 0, -8819.2197265625, 564.40997314453125, 94.5612030029296875, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+534, 180415, 0, 1519, 1617, '0', 0, 0, -8819.3896484375, 565.530029296875, 94.561798095703125, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+535, 180415, 0, 1519, 1617, '0', 0, 0, -8820.349609375, 566.18597412109375, 94.56220245361328125, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+536, 180415, 0, 1519, 1617, '0', 0, 0, -8821.349609375, 566.00897216796875, 94.56189727783203125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+537, 180415, 0, 1519, 1617, '0', 0, 0, -8819.83984375, 565.885009765625, 94.5641021728515625, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+538, 180415, 0, 1519, 1617, '0', 0, 0, -8820.8603515625, 566.1409912109375, 94.56420135498046875, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+539, 180415, 0, 1519, 0, '0', 0, 0, -8881.9697265625, 637.9639892578125, 104.9160003662109375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+540, 180415, 0, 1519, 0, '0', 0, 0, -8882.150390625, 638.3280029296875, 105.0439987182617187, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+541, 180415, 0, 1519, 0, '0', 0, 0, -8881.66015625, 637.2550048828125, 104.7649993896484375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+542, 180415, 0, 1519, 0, '0', 0, 0, -8881.8203125, 637.6199951171875, 105.1139984130859375, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+543, 180415, 0, 1519, 0, '0', 0, 0, -8882.4599609375, 638.65802001953125, 104.7310028076171875, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+544, 180415, 0, 1519, 0, '0', 0, 0, -8882.759765625, 639.2919921875, 104.8160018920898437, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+545, 180415, 0, 1519, 5148, '0', 0, 0, -8883.009765625, 639.78802490234375, 104.9260025024414062, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+546, 180415, 0, 1519, 5148, '0', 0, 0, -8840.98046875, 645.6810302734375, 105.0360031127929687, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+547, 180415, 0, 1519, 5148, '0', 0, 0, -8840.8896484375, 645.1090087890625, 105.3300018310546875, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+548, 180415, 0, 1519, 5148, '0', 0, 0, -8841.91015625, 647.68902587890625, 105.3160018920898437, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+549, 180415, 0, 1519, 5148, '0', 0, 0, -8841.75, 647.04498291015625, 105.2180023193359375, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+550, 180415, 0, 1519, 5148, '0', 0, 0, -8841.4296875, 646.49298095703125, 105.3899993896484375, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+551, 180415, 0, 1519, 5148, '0', 0, 0, -8841.33984375, 646.02398681640625, 105.4469985961914062, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+552, 180415, 0, 1519, 5148, '0', 0, 0, -8858.4296875, 644.74798583984375, 97.16449737548828125, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+553, 180415, 0, 1519, 5148, '0', 0, 0, -8857.099609375, 645.38702392578125, 97.18060302734375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+554, 180415, 0, 1519, 5148, '0', 0, 0, -8855.4599609375, 648.0050048828125, 97.20529937744140625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+555, 180415, 0, 1519, 5148, '0', 0, 0, -8857.1201171875, 648.66497802734375, 99.15709686279296875, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+556, 180415, 0, 1519, 5148, '0', 0, 0, -8843.5400390625, 651.35400390625, 105.3740005493164062, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+557, 180415, 0, 1519, 5148, '0', 0, 0, -8860.580078125, 647.6300048828125, 100.6719970703125, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+558, 180415, 0, 1519, 5148, '0', 0, 0, -8858.3095703125, 647.5780029296875, 100.7040023803710937, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+559, 180415, 0, 1519, 5148, '0', 0, 0, -8859.4697265625, 647.11798095703125, 100.7480010986328125, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+560, 180415, 0, 1519, 5148, '0', 0, 0, -8855.98046875, 646.530029296875, 97.20240020751953125, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+561, 180415, 0, 1519, 5148, '0', 0, 0, -8842.7001953125, 649.15301513671875, 105.285003662109375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+562, 180415, 0, 1519, 5148, '0', 0, 0, -8861.6103515625, 645.3909912109375, 97.123199462890625, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+563, 180415, 0, 1519, 5148, '0', 0, 0, -8842.5400390625, 648.7659912109375, 105.3779983520507812, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+564, 180415, 0, 1519, 5148, '0', 0, 0, -8860.099609375, 644.76202392578125, 97.1490020751953125, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+565, 180415, 0, 1519, 5148, '0', 0, 0, -8857.8701171875, 646.97198486328125, 99.15509796142578125, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+566, 180415, 0, 1519, 5148, '0', 0, 0, -8859.41015625, 646.4110107421875, 99.11530303955078125, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+567, 180415, 0, 1519, 5148, '0', 0, 0, -8843.25, 650.85198974609375, 105.1399993896484375, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+568, 180415, 0, 1519, 5148, '0', 0, 0, -8855.4697265625, 649.56402587890625, 97.19699859619140625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+569, 180415, 0, 1519, 5148, '0', 0, 0, -8861.0703125, 647.13897705078125, 99.10900115966796875, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+570, 180415, 0, 1519, 5148, '0', 0, 0, -8857.830078125, 648.72100830078125, 100.76300048828125, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+571, 180415, 0, 1519, 5148, '0', 0, 0, -8842.1298828125, 648.23297119140625, 105.05999755859375, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+572, 180415, 0, 1519, 5148, '0', 0, 0, -8843.1201171875, 650.1300048828125, 105.3479995727539062, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+573, 180415, 0, 1519, 5148, '0', 0, 0, -8842.6796875, 649.64202880859375, 105.2639999389648437, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+574, 180415, 0, 1519, 5148, '0', 0, 0, -8862.73046875, 646.52099609375, 97.097503662109375, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+575, 180415, 0, 1519, 5148, '0', 0, 0, -8843.83984375, 652.01202392578125, 105.30999755859375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+576, 180415, 0, 1519, 5148, '0', 0, 0, -8860.5302734375, 649.83502197265625, 100.6529998779296875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+577, 180415, 0, 1519, 5148, '0', 0, 0, -8856.0400390625, 650.89202880859375, 97.16699981689453125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+578, 180415, 0, 1519, 5148, '0', 0, 0, -8861.0400390625, 648.75299072265625, 100.7099990844726562, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+579, 180415, 0, 1519, 5148, '0', 0, 0, -8863.26953125, 647.84698486328125, 97.08339691162109375, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+580, 180415, 0, 1519, 5148, '0', 0, 0, -8883.25, 640.20098876953125, 105.029998779296875, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+581, 180415, 0, 1519, 5148, '0', 0, 0, -8859.51953125, 650.31298828125, 100.7229995727539062, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+582, 180415, 0, 1519, 5148, '0', 0, 0, -8861.6904296875, 648.79498291015625, 99.0796966552734375, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+583, 180415, 0, 1519, 5148, '0', 0, 0, -8861.0595703125, 650.27801513671875, 99.0850982666015625, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+584, 180415, 0, 1519, 5148, '0', 0, 0, -8863.2900390625, 649.51702880859375, 97.060699462890625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+585, 180415, 0, 1519, 5148, '0', 0, 0, -8858.3603515625, 649.875, 100.69000244140625, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+586, 180415, 0, 1519, 5148, '0', 0, 0, -8857.75, 650.2969970703125, 99.13970184326171875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+587, 180415, 0, 1519, 5148, '0', 0, 0, -8857.16015625, 651.99102783203125, 97.15200042724609375, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+588, 180415, 0, 1519, 5148, '0', 0, 0, -8885.41015625, 644.22601318359375, 105.0849990844726562, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+589, 180415, 0, 1519, 5148, '0', 0, 0, -8862.6904296875, 650.8800048828125, 97.06839752197265625, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+590, 180415, 0, 1519, 5148, '0', 0, 0, -8812.4296875, 655.0050048828125, 99.33049774169921875, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+591, 180415, 0, 1519, 5148, '0', 0, 0, -8861.5595703125, 652.010009765625, 97.07720184326171875, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+592, 180415, 0, 1519, 5148, '0', 0, 0, -8811.900390625, 655.03497314453125, 99.48220062255859375, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+593, 180415, 0, 1519, 5148, '0', 0, 0, -8884.51953125, 642.58502197265625, 104.9530029296875, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+594, 180415, 0, 1519, 5148, '0', 0, 0, -8884.76953125, 643.08697509765625, 104.8939971923828125, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+595, 180415, 0, 1519, 5148, '0', 0, 0, -8813.1201171875, 656.52801513671875, 99.38500213623046875, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+596, 180415, 0, 1519, 5148, '0', 0, 0, -8813.23046875, 655.91998291015625, 99.53260040283203125, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+597, 180415, 0, 1519, 5148, '0', 0, 0, -8859.4404296875, 650.97900390625, 99.10320281982421875, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+598, 180415, 0, 1519, 5148, '0', 0, 0, -8883.4697265625, 640.74798583984375, 105.1139984130859375, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+599, 180415, 0, 1519, 5148, '0', 0, 0, -8860.2197265625, 652.6090087890625, 97.081298828125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+600, 180415, 0, 1519, 5148, '0', 0, 0, -8858.4697265625, 652.6090087890625, 97.11060333251953125, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+601, 180415, 0, 1519, 5148, '0', 0, 0, -8885.0302734375, 643.50299072265625, 104.8050003051757812, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+602, 180415, 0, 1519, 5148, '0', 0, 0, -8812.9697265625, 655.34600830078125, 99.47750091552734375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+603, 180415, 0, 1519, 5148, '0', 0, 0, -8883.8701171875, 641.38702392578125, 105.035003662109375, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+604, 180415, 0, 1519, 5148, '0', 0, 0, -8884.240234375, 641.968994140625, 105.0080032348632812, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+605, 180415, 0, 1519, 5148, '0', 0, 0, -8885.75, 644.73602294921875, 104.8550033569335937, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+606, 180415, 0, 1519, 5148, '0', 0, 0, -8812.7197265625, 656.92401123046875, 99.41190338134765625, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+607, 180415, 0, 1519, 5148, '0', 0, 0, -8814.5, 659.77398681640625, 99.20749664306640625, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+608, 180415, 0, 1519, 5148, '0', 0, 0, -8813.9697265625, 659.8060302734375, 99.1248016357421875, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+609, 180415, 0, 1519, 5148, '0', 0, 0, -8815.1904296875, 661.29901123046875, 99.37670135498046875, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+610, 180415, 0, 1519, 5148, '0', 0, 0, -8815.2802734375, 660.72198486328125, 99.32769775390625, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+611, 180415, 0, 1519, 5148, '0', 0, 0, -8814.7802734375, 660.83001708984375, 100.7610015869140625, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+612, 180415, 0, 1519, 5148, '0', 0, 0, -8815.0400390625, 660.114990234375, 99.252197265625, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+613, 180415, 0, 1519, 5148, '0', 0, 0, -8814.7900390625, 661.6939697265625, 99.508697509765625, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+614, 180415, 0, 1519, 5148, '0', 0, 0, -8817.3896484375, 665.49298095703125, 99.15670013427734375, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+615, 180415, 0, 1519, 5148, '0', 0, 0, -8817.150390625, 664.885009765625, 99.4272003173828125, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+616, 180415, 0, 1519, 5148, '0', 0, 0, -8816.6103515625, 664.54498291015625, 99.51039886474609375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+617, 180415, 0, 1519, 5148, '0', 0, 0, -8816.8896484375, 666.4639892578125, 99.45580291748046875, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+618, 180415, 0, 1519, 5148, '0', 0, 0, -8817.2900390625, 666.0679931640625, 99.4882965087890625, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+619, 180415, 0, 1519, 5148, '0', 0, 0, -8816.080078125, 664.57501220703125, 99.53260040283203125, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+620, 180415, 0, 1519, 5148, '0', 0, 0, -8797.0400390625, 678.10601806640625, 104.13800048828125, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+621, 180415, 0, 1519, 5148, '0', 0, 0, -8797.01953125, 678.34600830078125, 104.0179977416992187, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+622, 180415, 0, 1519, 5148, '0', 0, 0, -8796.900390625, 678.197998046875, 104.2519989013671875, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+623, 180415, 0, 1519, 5148, '0', 0, 0, -8796.900390625, 678.197998046875, 104.2519989013671875, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+624, 180415, 0, 1519, 5148, '0', 0, 0, -8797.5595703125, 679.34197998046875, 102.8199996948242187, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+625, 180415, 0, 1519, 5148, '0', 0, 0, -8896.4697265625, 642.64801025390625, 105.0770034790039062, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+626, 180415, 0, 1519, 5148, '0', 0, 0, -8899.330078125, 641.01702880859375, 104.8949966430664062, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+627, 180415, 0, 1519, 5148, '0', 0, 0, -8898.5, 641.47601318359375, 105.029998779296875, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+628, 180415, 0, 1519, 5148, '0', 0, 0, -8895.7802734375, 643.07598876953125, 105.0810012817382812, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+629, 180415, 0, 1519, 5148, '0', 0, 0, -8894.849609375, 643.5469970703125, 104.9079971313476562, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+630, 180415, 0, 1519, 5148, '0', 0, 0, -8897.919921875, 641.8389892578125, 105.0989990234375, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+631, 180415, 0, 1519, 5148, '0', 0, 0, -8897.26953125, 642.1810302734375, 104.9029998779296875, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+632, 180415, 0, 1519, 5148, '0', 0, 0, -8899.8896484375, 640.7550048828125, 105.1460037231445312, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+633, 180415, 0, 1519, 5148, '0', 0, 0, -8902.2900390625, 639.38702392578125, 104.9950027465820312, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+634, 180415, 0, 1519, 5148, '0', 0, 0, -8901.8203125, 639.65301513671875, 105.1409988403320312, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+635, 180415, 0, 1519, 5148, '0', 0, 0, -8904.1103515625, 638.34698486328125, 104.983001708984375, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+636, 180415, 0, 1519, 5148, '0', 0, 0, -8907.080078125, 636.7860107421875, 105.0940017700195312, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+637, 180415, 0, 1519, 5148, '0', 0, 0, -8906.2197265625, 637.21197509765625, 105.1309967041015625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+638, 180415, 0, 1519, 5148, '0', 0, 0, -8901.1201171875, 640.07598876953125, 105.1969985961914062, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+639, 180415, 0, 1519, 5148, '0', 0, 0, -8900.5302734375, 640.3330078125, 105.0029983520507812, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+640, 180415, 0, 1519, 5148, '0', 0, 0, -8903.509765625, 638.72900390625, 104.8649978637695312, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+641, 180415, 0, 1519, 5148, '0', 0, 0, -8902.83984375, 639.09197998046875, 105.1039962768554687, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+642, 180415, 0, 1519, 5148, '0', 0, 0, -8905.2197265625, 637.77301025390625, 104.8310012817382812, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+643, 180415, 0, 1519, 5148, '0', 0, 0, -8904.669921875, 638.072998046875, 104.930999755859375, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+644, 180415, 0, 1519, 5148, '0', 0, 0, -8865.86328125, 680.98046875, 99.04193878173828125, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+645, 180415, 0, 1519, 5148, '0', 0, 0, -8710.6298828125, 466.813995361328125, 99.343902587890625, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+646, 180415, 0, 1519, 5148, '0', 0, 0, -8709.080078125, 468.052001953125, 99.18689727783203125, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+647, 180415, 0, 1519, 5148, '0', 0, 0, -8685.08984375, 496.845001220703125, 100.1800003051757812, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+648, 180415, 0, 1519, 5148, '0', 0, 0, -8686.8701171875, 495.5679931640625, 100.115997314453125, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+649, 180415, 0, 1519, 5148, '0', 0, 0, -8680.8701171875, 500.2340087890625, 100.115997314453125, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: Trade District - Difficulty: 0)
(@OGUID+650, 180415, 0, 1519, 5390, '0', 0, 0, -8736.23046875, 447.407989501953125, 100.7610015869140625, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+651, 180415, 0, 1519, 5390, '0', 0, 0, -8735.7099609375, 449.321014404296875, 100.733001708984375, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+652, 180415, 0, 1519, 5390, '0', 0, 0, -8735.83984375, 442.011993408203125, 100.8339996337890625, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+653, 180415, 0, 1519, 5390, '0', 0, 0, -8735.51953125, 440.07598876953125, 100.8590011596679687, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+654, 180415, 0, 1519, 5390, '0', 0, 0, -8744.2802734375, 418.62298583984375, 101.589996337890625, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+655, 180415, 0, 1519, 5390, '0', 0, 0, -8710.51953125, 435.532989501953125, 101.8539962768554687, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+656, 180415, 0, 1519, 5390, '0', 0, 0, -8747.580078125, 416.058990478515625, 101.6989974975585937, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+657, 180415, 0, 1519, 5390, '0', 0, 0, -8749.1796875, 414.717010498046875, 101.542999267578125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+658, 180415, 0, 1519, 5390, '0', 0, 0, -8745.9697265625, 417.358001708984375, 101.7099990844726562, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+659, 180415, 0, 1519, 5390, '0', 0, 0, -8721.9599609375, 416.1409912109375, 98.88469696044921875, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+660, 180415, 0, 1519, 5390, '0', 0, 0, -8711.3603515625, 431.134002685546875, 101.9290008544921875, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+661, 180415, 0, 1519, 5390, '0', 0, 0, -8717.91015625, 419.506988525390625, 99.09929656982421875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+662, 180415, 0, 1519, 5390, '0', 0, 0, -8722.1796875, 414.197998046875, 98.8184967041015625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+663, 180415, 0, 1519, 5390, '0', 0, 0, -8719.1201171875, 416.766998291015625, 101.3980026245117187, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+664, 180415, 0, 1519, 5390, '0', 0, 0, -8719.6103515625, 418.959991455078125, 99.03130340576171875, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+665, 180415, 0, 1519, 5390, '0', 0, 0, -8711.75, 429.233001708984375, 101.8040008544921875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+666, 180415, 0, 1519, 5390, '0', 0, 0, -8721.169921875, 417.72198486328125, 98.93830108642578125, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+667, 180415, 0, 1519, 5390, '0', 0, 0, -8710.919921875, 433.22900390625, 101.9010009765625, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+668, 180415, 0, 1519, 5390, '0', 0, 0, -8712.1298828125, 427.135009765625, 101.9889984130859375, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+669, 180415, 0, 1519, 5390, '0', 0, 0, -8720.2001953125, 414.9320068359375, 101.3740005493164062, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+670, 180415, 0, 1519, 5390, '0', 0, 0, -8717.1796875, 417.410003662109375, 101.5319976806640625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+671, 180415, 0, 1519, 5390, '0', 0, 0, -8715.5400390625, 414.364990234375, 103.4069976806640625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+672, 180415, 0, 1519, 5390, '0', 0, 0, -8716.2197265625, 413.0830078125, 103.3550033569335937, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+673, 180415, 0, 1519, 5390, '0', 0, 0, -8715.919921875, 419.3070068359375, 99.14510345458984375, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+674, 180415, 0, 1519, 5390, '0', 0, 0, -8718.669921875, 416.0679931640625, 103.3679962158203125, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+675, 180415, 0, 1519, 5390, '0', 0, 0, -8717.650390625, 411.845001220703125, 101.3590011596679687, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+676, 180415, 0, 1519, 5390, '0', 0, 0, -8719.5400390625, 412.82501220703125, 101.2750015258789062, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+677, 180415, 0, 1519, 5390, '0', 0, 0, -8715.3203125, 416.39801025390625, 101.4980010986328125, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+678, 180415, 0, 1519, 5390, '0', 0, 0, -8721.7099609375, 412.5, 98.77660369873046875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+679, 180415, 0, 1519, 5390, '0', 0, 0, -8717.740234375, 412.6199951171875, 103.2939987182617187, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+680, 180415, 0, 1519, 5390, '0', 0, 0, -8717.2900390625, 416.52099609375, 103.417999267578125, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+681, 180415, 0, 1519, 5390, '0', 0, 0, -8716.01953125, 415.82501220703125, 103.4189987182617187, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+682, 180415, 0, 1519, 5390, '0', 0, 0, -8713.080078125, 416.927001953125, 99.163299560546875, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+683, 180415, 0, 1519, 5390, '0', 0, 0, -8714.259765625, 418.47198486328125, 99.150299072265625, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+684, 180415, 0, 1519, 5390, '0', 0, 0, -8718.98046875, 413.345001220703125, 103.2829971313476562, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+685, 180415, 0, 1519, 5390, '0', 0, 0, -8719.41015625, 414.738006591796875, 103.3050003051757812, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+686, 180415, 0, 1519, 5390, '0', 0, 0, -8714.66015625, 414.3489990234375, 101.516998291015625, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+687, 180415, 0, 1519, 5390, '0', 0, 0, -8715.66015625, 412.468994140625, 101.3769989013671875, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+688, 180415, 0, 1519, 5390, '0', 0, 0, -8720.400390625, 410.894012451171875, 98.7738037109375, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+689, 180415, 0, 1519, 5390, '0', 0, 0, -8718.830078125, 410.0830078125, 98.79239654541015625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+690, 180415, 0, 1519, 5390, '0', 0, 0, -8712.51953125, 415.2030029296875, 99.12999725341796875, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+691, 180415, 0, 1519, 5390, '0', 0, 0, -8716.7998046875, 409.845001220703125, 98.831298828125, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+692, 180415, 0, 1519, 5390, '0', 0, 0, -8714.990234375, 410.43798828125, 98.9011993408203125, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+693, 180415, 0, 1519, 5390, '0', 0, 0, -8694.8095703125, 436.790008544921875, 103.4000015258789062, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+694, 180415, 0, 1519, 5390, '0', 0, 0, -8696.73046875, 435.42401123046875, 103.3610000610351562, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+695, 180415, 0, 1519, 5390, '0', 0, 0, -8713.4296875, 411.7340087890625, 99.00080108642578125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+696, 180415, 0, 1519, 5390, '0', 0, 0, -8712.7197265625, 413.24700927734375, 99.06639862060546875, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+697, 180415, 0, 1519, 5390, '0', 0, 0, -8693.1103515625, 438.071014404296875, 103.1890029907226562, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+698, 180415, 0, 1519, 5390, '0', 0, 0, -8726.150390625, 393.85400390625, 102.0989990234375, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+699, 180415, 0, 1519, 5390, '0', 0, 0, -8683.5, 458.420013427734375, 104.1460037231445312, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+700, 180415, 0, 1519, 5390, '0', 0, 0, -8680.009765625, 461.329986572265625, 104.2440032958984375, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+701, 180415, 0, 1519, 5390, '0', 0, 0, -8691.51953125, 438.214996337890625, 103.3389968872070312, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+702, 180415, 0, 1519, 5390, '0', 0, 0, -8724.7099609375, 393.97198486328125, 102.003997802734375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+703, 180415, 0, 1519, 5390, '0', 0, 0, -8727.330078125, 392.4320068359375, 101.8479995727539062, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+704, 180415, 0, 1519, 5390, '0', 0, 0, -8674.1201171875, 483.639007568359375, 101.2310028076171875, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+705, 180415, 0, 1519, 5390, '0', 0, 0, -8690.23046875, 436.563995361328125, 103.2559967041015625, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+706, 180415, 0, 1519, 5390, '0', 0, 0, -8672.650390625, 484.7030029296875, 101.3440017700195312, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+707, 180415, 0, 1519, 5390, '0', 0, 0, -8678.2802734375, 462.70098876953125, 104.1190032958984375, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+708, 180415, 0, 1519, 5390, '0', 0, 0, -8681.6904296875, 459.8909912109375, 104.1449966430664062, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+709, 180415, 0, 1519, 5390, '0', 0, 0, -8691.7197265625, 410.6300048828125, 104.2289962768554687, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+710, 180415, 0, 1519, 5390, '0', 0, 0, -8675.5703125, 437.052001953125, 100.80999755859375, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+711, 180415, 0, 1519, 5390, '0', 0, 0, -8730.169921875, 389.019012451171875, 102.0589981079101562, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+712, 180415, 0, 1519, 5390, '0', 0, 0, -8728.6201171875, 390.8389892578125, 102.0810012817382812, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+713, 180415, 0, 1519, 5390, '0', 0, 0, -8692.9501953125, 412.12298583984375, 104.1760025024414062, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+714, 180415, 0, 1519, 5390, '0', 0, 0, -8674.169921875, 438.235992431640625, 100.88800048828125, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+715, 180415, 0, 1519, 5390, '0', 0, 0, -8690.51953125, 409.04998779296875, 104.3779983520507812, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+716, 180415, 0, 1519, 5390, '0', 0, 0, -8655.330078125, 481.447998046875, 105.7959976196289062, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+717, 180415, 0, 1519, 5390, '0', 0, 0, -8653.1904296875, 478.70098876953125, 105.7289962768554687, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+718, 180415, 0, 1519, 5390, '0', 0, 0, -8646.9599609375, 470.95001220703125, 105.8010025024414062, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+719, 180415, 0, 1519, 5390, '0', 0, 0, -8651.0498046875, 476.113006591796875, 105.80999755859375, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+720, 180415, 0, 1519, 5390, '0', 0, 0, -8649.009765625, 473.4320068359375, 105.8079986572265625, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+721, 180415, 0, 1519, 5390, '0', 0, 0, -8645.2802734375, 468.787994384765625, 105.6930007934570312, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+722, 180415, 0, 1519, 5390, '0', 0, 0, -8649.5, 447.64599609375, 106.0579986572265625, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+723, 180415, 0, 1519, 5390, '0', 0, 0, -8648.3896484375, 448.49798583984375, 105.8820037841796875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+724, 180415, 0, 1519, 5390, '0', 0, 0, -8643.6796875, 466.855987548828125, 105.8140029907226562, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+725, 180415, 0, 1519, 5390, '0', 0, 0, -8626.2197265625, 450.188995361328125, 104.2139968872070312, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+726, 180415, 0, 1519, 5390, '0', 0, 0, -8626.1103515625, 459.79901123046875, 103.8000030517578125, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+727, 180415, 0, 1519, 5390, '0', 0, 0, -8626.3603515625, 452.67401123046875, 104.1309967041015625, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+728, 180415, 0, 1519, 5390, '0', 0, 0, -8626.0400390625, 461.9580078125, 104.0149993896484375, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+729, 180415, 0, 1519, 5390, '0', 0, 0, -8615.8603515625, 446.95001220703125, 104.5449981689453125, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+730, 180415, 0, 1519, 5390, '0', 0, 0, -8612.8095703125, 447.118011474609375, 104.48699951171875, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+731, 180415, 0, 1519, 5390, '0', 0, 0, -8609.3203125, 446.99798583984375, 104.2440032958984375, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+732, 180415, 0, 1519, 5390, '0', 0, 0, -8624.26953125, 446.5360107421875, 104.6959991455078125, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+733, 180415, 0, 1519, 5390, '0', 0, 0, -8621.6396484375, 446.542999267578125, 104.6989974975585937, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+734, 180415, 0, 1519, 5390, '0', 0, 0, -8618.900390625, 446.7340087890625, 104.6009979248046875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+735, 180415, 0, 1519, 5390, '0', 0, 0, -8616.83984375, 421.944000244140625, 104.8339996337890625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+736, 180415, 0, 1519, 5390, '0', 0, 0, -8620.099609375, 419.27099609375, 104.8669967651367187, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+737, 180415, 0, 1519, 5390, '0', 0, 0, -8618.5, 420.571014404296875, 104.8430023193359375, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+738, 180415, 0, 1519, 5390, '0', 0, 0, -8621.51953125, 418.089996337890625, 104.8509979248046875, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+739, 180415, 0, 1519, 5390, '0', 0, 0, -8605.759765625, 401.790008544921875, 111.1800003051757812, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+740, 180415, 0, 1519, 5390, '0', 0, 0, -8631.6201171875, 410.363006591796875, 104.8209991455078125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+741, 180415, 0, 1519, 5390, '0', 0, 0, -8607.7197265625, 400.256988525390625, 111.2300033569335937, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+742, 180415, 0, 1519, 5390, '0', 0, 0, -8609.669921875, 398.8330078125, 111.1839981079101562, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+743, 180415, 0, 1519, 5390, '0', 0, 0, -8633.58984375, 408.85101318359375, 104.8010025024414062, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+744, 180415, 0, 1519, 5390, '0', 0, 0, -8628.419921875, 412.993011474609375, 104.852996826171875, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+745, 180415, 0, 1519, 5390, '0', 0, 0, -8629.98046875, 411.714996337890625, 104.8489990234375, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+746, 180415, 0, 1519, 5390, '0', 0, 0, -8521.9501953125, 415.27301025390625, 110.6959991455078125, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+747, 180415, 0, 1519, 5390, '0', 0, 0, -8511.75, 402.639007568359375, 117.3470001220703125, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+748, 180415, 0, 1519, 5390, '0', 0, 0, -8501.1201171875, 426.7449951171875, 112.5839996337890625, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+749, 180415, 0, 1519, 5390, '0', 0, 0, -8514.4599609375, 405.95098876953125, 116.3570022583007812, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+750, 180415, 0, 1519, 5390, '0', 0, 0, -8503.6201171875, 429.941009521484375, 110.66400146484375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+751, 180415, 0, 1519, 5390, '0', 0, 0, -8495.9697265625, 420.37701416015625, 116.46099853515625, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+752, 180415, 0, 1519, 5390, '0', 0, 0, -8524.6298828125, 418.454986572265625, 108.7269973754882812, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+753, 180415, 0, 1519, 5390, '0', 0, 0, -8516.900390625, 409.066009521484375, 114.4840011596679687, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+754, 180415, 0, 1519, 5390, '0', 0, 0, -8506.1298828125, 433.093994140625, 108.7570037841796875, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+755, 180415, 0, 1519, 5390, '0', 0, 0, -8527.509765625, 422.183990478515625, 107.7829971313476562, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+756, 180415, 0, 1519, 5390, '0', 0, 0, -8611.48046875, 397.3389892578125, 111.1780014038085937, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+757, 180415, 0, 1519, 5390, '0', 0, 0, -8498.5, 423.529998779296875, 114.5479965209960937, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+758, 180415, 0, 1519, 5390, '0', 0, 0, -8509.08984375, 436.7550048828125, 107.7829971313476562, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+759, 180415, 0, 1519, 5390, '0', 0, 0, -8519.490234375, 412.162994384765625, 112.5739974975585937, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+760, 180415, 0, 1519, 5390, '0', 0, 0, -8512.330078125, 398.3489990234375, 117.3180007934570312, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+761, 180415, 0, 1519, 5390, '0', 0, 0, -8493.48046875, 417.031005859375, 117.3460006713867187, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+762, 180415, 0, 1519, 5390, '0', 0, 0, -8513.7197265625, 393.269012451171875, 118.1279983520507812, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+763, 180415, 0, 1519, 5390, '0', 0, 0, -8489.23046875, 416.639007568359375, 117.3180007934570312, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+764, 180415, 0, 1519, 5390, '0', 0, 0, -8613.4404296875, 395.843994140625, 111.2360000610351562, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+765, 180415, 0, 1519, 5390, '0', 0, 0, -8615.4296875, 394.385009765625, 111.0770034790039062, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+766, 180415, 0, 1519, 5390, '0', 0, 0, -8519.7900390625, 381.766998291015625, 123.7779998779296875, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+767, 180415, 0, 1519, 5390, '0', 0, 0, -8517.349609375, 385.316009521484375, 121.7289962768554687, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+768, 180415, 0, 1519, 5390, '0', 0, 0, -8484.349609375, 416.89599609375, 118.0380020141601562, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+769, 180415, 0, 1519, 5390, '0', 0, 0, -8475.2802734375, 418.589996337890625, 121.8000030517578125, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+770, 180415, 0, 1519, 5390, '0', 0, 0, -8515.3603515625, 389.31298828125, 119.667999267578125, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+771, 180415, 0, 1519, 5390, '0', 0, 0, -8479.6796875, 417.436004638671875, 119.7020034790039062, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+772, 180415, 0, 1519, 5390, '0', 0, 0, -8529.9697265625, 372.406005859375, 127.0640029907226562, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+773, 180415, 0, 1519, 5390, '0', 0, 0, -8471.240234375, 420.154998779296875, 123.8479995727539062, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+774, 180415, 0, 1519, 5390, '0', 0, 0, -8526.669921875, 375.15301513671875, 127.0530014038085937, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+775, 180415, 0, 1519, 5390, '0', 0, 0, -8522.8896484375, 378.2449951171875, 125.9290008544921875, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+776, 180415, 0, 1519, 5390, '0', 0, 0, -8533.830078125, 369.572998046875, 127.0849990844726562, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+777, 180415, 0, 1519, 5390, '0', 0, 0, -8467.1904296875, 422.660003662109375, 126.0210037231445312, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+778, 180415, 0, 1519, 0, '0', 0, 0, -8653.849609375, 404.738006591796875, 105.48699951171875, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+779, 180415, 0, 1519, 0, '0', 0, 0, -8652.009765625, 406.154998779296875, 105.4339981079101562, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+780, 180415, 0, 1519, 5149, '0', 0, 0, -8686.66015625, 404.243011474609375, 104.2360000610351562, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+781, 180415, 0, 1519, 5149, '0', 0, 0, -8664.4404296875, 395.087005615234375, 106.26300048828125, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+782, 180415, 0, 1519, 5149, '0', 0, 0, -8663.3095703125, 396.12298583984375, 106.2519989013671875, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+783, 180415, 0, 1519, 5149, '0', 0, 0, -8681.599609375, 389.506988525390625, 105.4489974975585937, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+784, 180415, 0, 1519, 5149, '0', 0, 0, -8675.349609375, 386.368011474609375, 104.6780014038085937, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+785, 180415, 0, 1519, 5149, '0', 0, 0, -8677.580078125, 387.535003662109375, 104.9059982299804687, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+786, 180415, 0, 1519, 5149, '0', 0, 0, -8679.5703125, 388.5, 105.1539993286132812, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+787, 180415, 0, 1519, 5149, '0', 0, 0, -8728.2099609375, 375.415008544921875, 104.5660018920898437, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+788, 180415, 0, 1519, 5149, '0', 0, 0, -8718.2998046875, 369.3179931640625, 104.4459991455078125, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+789, 180415, 0, 1519, 5149, '0', 0, 0, -8716.669921875, 368.305999755859375, 104.4629974365234375, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+790, 180415, 0, 1519, 5149, '0', 0, 0, -8714.91015625, 367.264007568359375, 104.4599990844726562, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+791, 180415, 0, 1519, 5149, '0', 0, 0, -8726.9404296875, 374.641998291015625, 104.516998291015625, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+792, 180415, 0, 1519, 5149, '0', 0, 0, -8725.5595703125, 373.7860107421875, 104.53900146484375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+793, 180415, 0, 1519, 5149, '0', 0, 0, -8729.490234375, 376.207000732421875, 104.3069992065429687, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+794, 180415, 0, 1519, 5149, '0', 0, 0, -8712.1201171875, 339.57598876953125, 101.7429962158203125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+795, 180415, 0, 1519, 5149, '0', 0, 0, -8712.1396484375, 341.6510009765625, 101.6060028076171875, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+796, 180415, 0, 1519, 5149, '0', 0, 0, -8712.240234375, 343.6409912109375, 101.5790023803710937, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+797, 180415, 0, 1519, 5149, '0', 0, 0, -8712, 337.045013427734375, 101.4619979858398437, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+798, 180415, 0, 1519, 5149, '0', 0, 0, -8711.9697265625, 334.558990478515625, 101.733001708984375, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+799, 180415, 0, 1519, 5149, '0', 0, 0, -8720.9501953125, 320.904998779296875, 101.7089996337890625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+800, 180415, 0, 1519, 5149, '0', 0, 0, -8723.48046875, 320.561004638671875, 101.6949996948242187, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+801, 180415, 0, 1519, 5149, '0', 0, 0, -8730.669921875, 319.0360107421875, 101.7570037841796875, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+802, 180415, 0, 1519, 5149, '0', 0, 0, -8725.8798828125, 320.15301513671875, 101.6630020141601562, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+803, 180415, 0, 1519, 5149, '0', 0, 0, -8728.4501953125, 319.62799072265625, 101.6139984130859375, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+804, 180415, 0, 1519, 5149, '0', 0, 0, -8737.6103515625, 317.364990234375, 101.7269973754882812, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+805, 180415, 0, 1519, 5149, '0', 0, 0, -8735.3603515625, 317.915008544921875, 101.7819976806640625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+806, 180415, 0, 1519, 5149, '0', 0, 0, -8733.0400390625, 318.489990234375, 101.7259979248046875, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+807, 180415, 0, 1519, 5149, '0', 0, 0, -8795.240234375, 349.32501220703125, 108.9039993286132812, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+808, 180415, 0, 1519, 5149, '0', 0, 0, -8790.150390625, 349.87200927734375, 108.8560028076171875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+809, 180415, 0, 1519, 5149, '0', 0, 0, -8784.580078125, 340.32501220703125, 108.7789993286132812, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+810, 180415, 0, 1519, 5149, '0', 0, 0, -8785.8203125, 337.8330078125, 108.83599853515625, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+811, 180415, 0, 1519, 5149, '0', 0, 0, -8787.7900390625, 349.441009521484375, 108.8079986572265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+812, 180415, 0, 1519, 5149, '0', 0, 0, -8784, 343.22198486328125, 108.9260025024414062, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+813, 180415, 0, 1519, 5149, '0', 0, 0, -8792.7001953125, 349.813995361328125, 108.73699951171875, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+814, 180415, 0, 1519, 5149, '0', 0, 0, -8788.33984375, 335.365997314453125, 108.9769973754882812, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Old Town - Difficulty: 0)
(@OGUID+815, 180415, 0, 1519, 5390, '0', 0, 0, -8615.4599609375, 697.85400390625, 99.89150238037109375, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+816, 180415, 0, 1519, 5390, '0', 0, 0, -8615.490234375, 697.46197509765625, 100.0680007934570312, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+817, 180415, 0, 1519, 5390, '0', 0, 0, -8615.1904296875, 697.61798095703125, 99.789398193359375, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+818, 180415, 0, 1519, 5390, '0', 0, 0, -8452.4404296875, 433.9320068359375, 127.1070022583007812, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+819, 180415, 0, 1519, 5390, '0', 0, 0, -8506.5498046875, 370.5419921875, 122.1350021362304687, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+820, 180415, 0, 1519, 5390, '0', 0, 0, -8541.3798828125, 363.62799072265625, 127.128997802734375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+821, 180415, 0, 1519, 5390, '0', 0, 0, -8500.2197265625, 375.759002685546875, 118.2399978637695312, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+822, 180415, 0, 1519, 5390, '0', 0, 0, -8460.1298828125, 407.5469970703125, 124.1890029907226562, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+823, 180415, 0, 1519, 5390, '0', 0, 0, -8469.8798828125, 399.730987548828125, 118.2570037841796875, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+824, 180415, 0, 1519, 5390, '0', 0, 0, -8456.2099609375, 431.02801513671875, 127.08599853515625, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+825, 180415, 0, 1519, 5390, '0', 0, 0, -8460.0400390625, 428.0050048828125, 127.0630035400390625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+826, 180415, 0, 1519, 5390, '0', 0, 0, -8503.4296875, 373.194000244140625, 120.1920013427734375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+827, 180415, 0, 1519, 5390, '0', 0, 0, -8537.48046875, 366.5570068359375, 127.1070022583007812, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+828, 180415, 0, 1519, 5390, '0', 0, 0, -8513.3095703125, 365.256988525390625, 126.207000732421875, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+829, 180415, 0, 1519, 5390, '0', 0, 0, -8509.91015625, 367.8489990234375, 124.1790008544921875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+830, 180415, 0, 1519, 5390, '0', 0, 0, -8466.75, 402.3699951171875, 120.2020034790039062, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+831, 180415, 0, 1519, 5390, '0', 0, 0, -8463.2998046875, 405.082000732421875, 122.2829971313476562, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+832, 180415, 0, 1519, 5390, '0', 0, 0, -8463.4404296875, 425.197998046875, 127.0530014038085937, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+833, 180415, 0, 1519, 5390, '0', 0, 0, -8519.6396484375, 360.220001220703125, 127.2610015869140625, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+834, 180415, 0, 1519, 5390, '0', 0, 0, -8480.490234375, 377.462005615234375, 116.2770004272460937, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+835, 180415, 0, 1519, 5390, '0', 0, 0, -8482.669921875, 374.407989501953125, 116.3010025024414062, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+836, 180415, 0, 1519, 5390, '0', 0, 0, -8450.3701171875, 415.1929931640625, 127.2610015869140625, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+837, 180415, 0, 1519, 5390, '0', 0, 0, -8470.33984375, 382.1199951171875, 116.0630035400390625, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+838, 180415, 0, 1519, 5390, '0', 0, 0, -8447.6904296875, 415.1610107421875, 127.2610015869140625, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+839, 180415, 0, 1519, 5390, '0', 0, 0, -8520.2197265625, 357.343994140625, 127.2610015869140625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+840, 180415, 0, 1519, 5390, '0', 0, 0, -8444.16015625, 436.829986572265625, 127.1559982299804687, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+841, 180415, 0, 1519, 5390, '0', 0, 0, -8484.0498046875, 371.031005859375, 116.2870025634765625, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+842, 180415, 0, 1519, 5390, '0', 0, 0, -8516.25, 362.912994384765625, 127.1920013427734375, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+843, 180415, 0, 1519, 5390, '0', 0, 0, -8448.6298828125, 437.06298828125, 127.128997802734375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+844, 180415, 0, 1519, 5390, '0', 0, 0, -8473.830078125, 381.552001953125, 116.1269989013671875, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+845, 180415, 0, 1519, 5390, '0', 0, 0, -8477.2998046875, 380.07598876953125, 116.06500244140625, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+846, 180415, 0, 1519, 5390, '0', 0, 0, -8456.9296875, 410.240997314453125, 126.1760025024414062, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+847, 180415, 0, 1519, 5390, '0', 0, 0, -8453.8798828125, 412.555999755859375, 127.1920013427734375, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+848, 180415, 0, 1519, 5390, '0', 0, 0, -8541.8095703125, 358.954986572265625, 127.1569976806640625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+849, 180415, 0, 1519, 5390, '0', 0, 0, -8484.26953125, 364.287994384765625, 116.2819976806640625, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+850, 180415, 0, 1519, 5390, '0', 0, 0, -8535.48046875, 351.037994384765625, 127.2170028686523437, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+851, 180415, 0, 1519, 5390, '0', 0, 0, -8538.7998046875, 355.011993408203125, 127.1869964599609375, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+852, 180415, 0, 1519, 5390, '0', 0, 0, -8514.01953125, 350.985992431640625, 130.0919952392578125, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+853, 180415, 0, 1519, 5390, '0', 0, 0, -8484.51953125, 367.4580078125, 116.2919998168945312, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+854, 180415, 0, 1519, 5390, '0', 0, 0, -8444.8798828125, 411.334991455078125, 128.1540069580078125, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+855, 180415, 0, 1519, 5390, '0', 0, 0, -8437.6796875, 428.87200927734375, 127.2170028686523437, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+856, 180415, 0, 1519, 5390, '0', 0, 0, -8440.98046875, 432.829986572265625, 127.1869964599609375, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+857, 180415, 0, 1519, 5390, '0', 0, 0, -8463.419921875, 380.761993408203125, 116.1660003662109375, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+858, 180415, 0, 1519, 5390, '0', 0, 0, -8466.7197265625, 381.785003662109375, 116.0839996337890625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+859, 180415, 0, 1519, 5390, '0', 0, 0, -8517.23046875, 353.9110107421875, 128.110992431640625, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+860, 180415, 0, 1519, 5390, '0', 0, 0, -8439.580078125, 389.6510009765625, 136.9239959716796875, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+861, 180415, 0, 1519, 5390, '0', 0, 0, -8440.9404296875, 403.572998046875, 132.03900146484375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+862, 180415, 0, 1519, 5390, '0', 0, 0, -8442.75, 407.64599609375, 130.102996826171875, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+863, 180415, 0, 1519, 5390, '0', 0, 0, -8527.240234375, 340.766998291015625, 130.305999755859375, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+864, 180415, 0, 1519, 5390, '0', 0, 0, -8432.4296875, 421.7139892578125, 128.225006103515625, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+865, 180415, 0, 1519, 5390, '0', 0, 0, -8435.01953125, 425.2139892578125, 127.2310028076171875, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+866, 180415, 0, 1519, 5390, '0', 0, 0, -8483.0302734375, 360.855987548828125, 116.2389984130859375, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+867, 180415, 0, 1519, 5390, '0', 0, 0, -8510.3203125, 348.407989501953125, 132.05499267578125, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+868, 180415, 0, 1519, 5390, '0', 0, 0, -8502.16015625, 344.677001953125, 135.9429931640625, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+869, 180415, 0, 1519, 5390, '0', 0, 0, -8476.1396484375, 353.821014404296875, 137.1399993896484375, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+870, 180415, 0, 1519, 5390, '0', 0, 0, -8460.23046875, 378.6090087890625, 116.167999267578125, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+871, 180415, 0, 1519, 5390, '0', 0, 0, -8439.3701171875, 394.74700927734375, 135.9210052490234375, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+872, 180415, 0, 1519, 5390, '0', 0, 0, -8529.900390625, 344.139007568359375, 128.2400054931640625, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+873, 180415, 0, 1519, 5390, '0', 0, 0, -8439.849609375, 399.207000732421875, 133.9810028076171875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+874, 180415, 0, 1519, 5390, '0', 0, 0, -8532.5302734375, 347.444000244140625, 127.2310028076171875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+875, 180415, 0, 1519, 5390, '0', 0, 0, -8455.0595703125, 369.9530029296875, 137.1869964599609375, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+876, 180415, 0, 1519, 5390, '0', 0, 0, -8506.4501953125, 346.25, 133.9669952392578125, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+877, 180415, 0, 1519, 5390, '0', 0, 0, -8497.580078125, 343.631988525390625, 136.9239959716796875, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+878, 180415, 0, 1519, 5390, '0', 0, 0, -8461.8701171875, 354.37701416015625, 137.1649932861328125, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+879, 180415, 0, 1519, 5390, '0', 0, 0, -8455.23046875, 363.363006591796875, 137.06500244140625, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+880, 180415, 0, 1519, 5390, '0', 0, 0, -8454.8095703125, 366.7860107421875, 137.188995361328125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+881, 180415, 0, 1519, 5390, '0', 0, 0, -8517.01953125, 327.811004638671875, 137.13299560546875, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+882, 180415, 0, 1519, 5390, '0', 0, 0, -8519.7197265625, 331.269012451171875, 136.1360015869140625, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+883, 180415, 0, 1519, 5390, '0', 0, 0, -8424.6298828125, 411.97900390625, 134.225006103515625, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+884, 180415, 0, 1519, 5390, '0', 0, 0, -8427.16015625, 415.415008544921875, 132.1750030517578125, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+885, 180415, 0, 1519, 5390, '0', 0, 0, -8458.75, 356.885009765625, 137.1670074462890625, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+886, 180415, 0, 1519, 5390, '0', 0, 0, -8465.3203125, 352.8699951171875, 137.1510009765625, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+887, 180415, 0, 1519, 5390, '0', 0, 0, -8522.2802734375, 334.447998046875, 134.1719970703125, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+888, 180415, 0, 1519, 5390, '0', 0, 0, -8524.8095703125, 337.5889892578125, 132.2310028076171875, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+889, 180415, 0, 1519, 5390, '0', 0, 0, -8429.7998046875, 418.545013427734375, 130.2050018310546875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+890, 180415, 0, 1519, 5390, '0', 0, 0, -8456.5498046875, 359.9219970703125, 137.156005859375, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+891, 180415, 0, 1519, 5390, '0', 0, 0, -8419.48046875, 405.4639892578125, 137.13299560546875, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+892, 180415, 0, 1519, 5390, '0', 0, 0, -8422.08984375, 408.89801025390625, 136.147003173828125, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+893, 180415, 0, 1519, 5390, '0', 0, 0, -8468.849609375, 352.29901123046875, 137.1410064697265625, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+894, 180415, 0, 1519, 5390, '0', 0, 0, -8472.5498046875, 352.631988525390625, 137.1699981689453125, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+895, 180415, 0, 1519, 0, '0', 0, 0, -8449.3798828125, 333.52099609375, 139.4530029296875, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+896, 180415, 0, 1519, 0, '0', 0, 0, -8449.990234375, 334.239990234375, 138.9320068359375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+897, 180415, 0, 1519, 0, '0', 0, 0, -8441.5595703125, 338.535003662109375, 140.0410003662109375, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+898, 180415, 0, 1519, 0, '0', 0, 0, -8442.0498046875, 339.35101318359375, 139.503997802734375, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+899, 180415, 0, 1519, 0, '0', 0, 0, -8448.1796875, 332.118011474609375, 140.4709930419921875, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+900, 180415, 0, 1519, 0, '0', 0, 0, -8452.990234375, 337.795013427734375, 136.3719940185546875, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+901, 180415, 0, 1519, 0, '0', 0, 0, -8444.73046875, 343.220001220703125, 136.89300537109375, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+902, 180415, 0, 1519, 0, '0', 0, 0, -8450.5400390625, 334.885009765625, 138.462005615234375, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+903, 180415, 0, 1519, 0, '0', 0, 0, -8451.1904296875, 335.704986572265625, 137.89599609375, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+904, 180415, 0, 1519, 0, '0', 0, 0, -8442.6298828125, 340.115997314453125, 138.9770050048828125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+905, 180415, 0, 1519, 0, '0', 0, 0, -8443.16015625, 340.875, 138.46600341796875, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+906, 180415, 0, 1519, 0, '0', 0, 0, -8448.7900390625, 332.85198974609375, 139.9429931640625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+907, 180415, 0, 1519, 0, '0', 0, 0, -8441.0400390625, 337.829986572265625, 140.522003173828125, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+908, 180415, 0, 1519, 0, '0', 0, 0, -8445.26953125, 344.037994384765625, 136.3480072021484375, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+909, 180415, 0, 1519, 0, '0', 0, 0, -8451.8095703125, 336.444000244140625, 137.363006591796875, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+910, 180415, 0, 1519, 0, '0', 0, 0, -8452.3896484375, 337.165008544921875, 136.858001708984375, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+911, 180415, 0, 1519, 0, '0', 0, 0, -8443.6796875, 341.6610107421875, 137.94000244140625, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+912, 180415, 0, 1519, 0, '0', 0, 0, -8444.2001953125, 342.4320068359375, 137.4219970703125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+913, 180415, 0, 1519, 0, '0', 0, 0, -8447.6298828125, 331.4169921875, 140.957000732421875, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+914, 180415, 0, 1519, 0, '0', 0, 0, -8437.0400390625, 331.832000732421875, 144.5269927978515625, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+915, 180415, 0, 1519, 0, '0', 0, 0, -8437.5400390625, 332.605987548828125, 144.0359954833984375, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+916, 180415, 0, 1519, 0, '0', 0, 0, -8445.919921875, 329.3909912109375, 142.4149932861328125, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+917, 180415, 0, 1519, 0, '0', 0, 0, -8440.580078125, 337.0260009765625, 141.0460052490234375, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+918, 180415, 0, 1519, 0, '0', 0, 0, -8438.01953125, 333.3389892578125, 143.57000732421875, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+919, 180415, 0, 1519, 0, '0', 0, 0, -8443.5498046875, 326.639007568359375, 144.410003662109375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+920, 180415, 0, 1519, 0, '0', 0, 0, -8444.1396484375, 327.3330078125, 143.92999267578125, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+921, 180415, 0, 1519, 0, '0', 0, 0, -8439.0498046875, 334.79998779296875, 142.5449981689453125, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+922, 180415, 0, 1519, 0, '0', 0, 0, -8436.6201171875, 331.154998779296875, 144.949005126953125, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+923, 180415, 0, 1519, 0, '0', 0, 0, -8446.4501953125, 330.0889892578125, 141.938995361328125, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+924, 180415, 0, 1519, 0, '0', 0, 0, -8446.9697265625, 330.82501220703125, 141.45599365234375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+925, 180415, 0, 1519, 0, '0', 0, 0, -8438.5595703125, 334.105987548828125, 143.014007568359375, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+926, 180415, 0, 1519, 0, '0', 0, 0, -8444.73046875, 328.042999267578125, 143.4429931640625, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+927, 180415, 0, 1519, 0, '0', 0, 0, -8445.3095703125, 328.7139892578125, 142.9170074462890625, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+928, 180415, 0, 1519, 0, '0', 0, 0, -8439.51953125, 335.54998779296875, 142.048004150390625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+929, 180415, 0, 1519, 0, '0', 0, 0, -8440.0400390625, 336.285003662109375, 141.5500030517578125, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+930, 180415, 0, 1519, 0, '0', 0, 0, -8442.9697265625, 325.9840087890625, 144.871002197265625, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+931, 180415, 0, 1519, 5390, '0', 0, 0, -8499.5, 568.02301025390625, 101.0940017700195312, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+932, 180415, 0, 1519, 5390, '0', 0, 0, -8475.7998046875, 554.364990234375, 99.66680145263671875, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+933, 180415, 0, 1519, 5390, '0', 0, 0, -8474.2900390625, 556.3699951171875, 99.6990966796875, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+934, 180415, 0, 1519, 5390, '0', 0, 0, -8499.259765625, 567.81597900390625, 100.9359970092773437, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+935, 180415, 0, 1519, 5390, '0', 0, 0, -8499.2099609375, 568.35400390625, 100.7139968872070312, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+936, 180415, 0, 1519, 5150, '0', 0, 0, -8471.349609375, 560.18402099609375, 99.75, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+937, 180415, 0, 1519, 5150, '0', 0, 0, -8470, 562.135009765625, 99.6941986083984375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+938, 180415, 0, 1519, 5150, '0', 0, 0, -8472.76953125, 558.3590087890625, 99.698699951171875, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+939, 180415, 0, 1519, 5150, '0', 0, 0, -8410.2099609375, 538.8070068359375, 103.904998779296875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+940, 180415, 0, 1519, 5150, '0', 0, 0, -8415.58984375, 538.09600830078125, 99.22789764404296875, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+941, 180415, 0, 1519, 5150, '0', 0, 0, -8418.2197265625, 541.23797607421875, 99.21779632568359375, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+942, 180415, 0, 1519, 5150, '0', 0, 0, -8418, 540.98602294921875, 99.09079742431640625, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+943, 180415, 0, 1519, 5150, '0', 0, 0, -8419.150390625, 542.53302001953125, 99.14279937744140625, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+944, 180415, 0, 1519, 5150, '0', 0, 0, -8418.4404296875, 541.614990234375, 99.05809783935546875, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+945, 180415, 0, 1519, 5150, '0', 0, 0, -8412.009765625, 537.41998291015625, 103.8539962768554687, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+946, 180415, 0, 1519, 5150, '0', 0, 0, -8412.2197265625, 544.427001953125, 95.44840240478515625, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+947, 180415, 0, 1519, 5150, '0', 0, 0, -8415.8798828125, 538.1610107421875, 99.09549713134765625, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+948, 180415, 0, 1519, 5150, '0', 0, 0, -8420.1904296875, 560.6929931640625, 95.57379913330078125, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+949, 180415, 0, 1519, 5150, '0', 0, 0, -8415.490234375, 556.64898681640625, 99.20839691162109375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+950, 180415, 0, 1519, 5150, '0', 0, 0, -8415.3603515625, 556.385009765625, 99.12270355224609375, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+951, 180415, 0, 1519, 5150, '0', 0, 0, -8413.669921875, 554.72698974609375, 99.127197265625, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+952, 180415, 0, 1519, 5150, '0', 0, 0, -8411.1904296875, 544.73297119140625, 96.43450164794921875, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+953, 180415, 0, 1519, 5150, '0', 0, 0, -8413.2998046875, 553.89801025390625, 99.22879791259765625, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+954, 180415, 0, 1519, 5150, '0', 0, 0, -8411.1904296875, 544.73297119140625, 96.43450164794921875, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+955, 180415, 0, 1519, 5150, '0', 0, 0, -8421.599609375, 559.64898681640625, 95.53600311279296875, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+956, 180415, 0, 1519, 5150, '0', 0, 0, -8412.4501953125, 553.030029296875, 99.0010986328125, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+957, 180415, 0, 1519, 5390, '0', 0, 0, -8469.23046875, 599.91998291015625, 97.41069793701171875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+958, 180415, 0, 1519, 5390, '0', 0, 0, -8467.9296875, 598.302001953125, 97.36139678955078125, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+959, 180415, 0, 1519, 5150, '0', 0, 0, -8473.9296875, 605.85400390625, 97.394500732421875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+960, 180415, 0, 1519, 5150, '0', 0, 0, -8480.6201171875, 632.06298828125, 95.49069976806640625, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+961, 180415, 0, 1519, 5150, '0', 0, 0, -8480.919921875, 631.98602294921875, 95.5323028564453125, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+962, 180415, 0, 1519, 5390, '0', 0, 0, -8575.08984375, 721.84600830078125, 100.5540008544921875, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+963, 180415, 0, 1519, 5390, '0', 0, 0, -8576.0400390625, 722.8389892578125, 99.53179931640625, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+964, 180415, 0, 1519, 5390, '0', 0, 0, -8572.2197265625, 718.8070068359375, 103.2379989624023437, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+965, 180415, 0, 1519, 5390, '0', 0, 0, -8570.1298828125, 723.947998046875, 101.3909988403320312, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+966, 180415, 0, 1519, 5390, '0', 0, 0, -8573.099609375, 719.7919921875, 102.4020004272460937, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+967, 180415, 0, 1519, 5390, '0', 0, 0, -8574.080078125, 720.78802490234375, 101.4899978637695312, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+968, 180415, 0, 1519, 5390, '0', 0, 0, -8569.3203125, 722.79998779296875, 102.3499984741210937, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+969, 180415, 0, 1519, 5390, '0', 0, 0, -8568.6396484375, 721.74700927734375, 103.1930007934570312, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+970, 180415, 0, 1519, 5390, '0', 0, 0, -8440.169921875, 625.7030029296875, 98.010498046875, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+971, 180415, 0, 1519, 5390, '0', 0, 0, -8439.6201171875, 625.2550048828125, 97.85900115966796875, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+972, 180415, 0, 1519, 5390, '0', 0, 0, -8516.16015625, 736.53802490234375, 102.1320037841796875, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+973, 180415, 0, 1519, 5390, '0', 0, 0, -8439.490234375, 625.718994140625, 97.9739990234375, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+974, 180415, 0, 1519, 5390, '0', 0, 0, -8571.669921875, 726.3909912109375, 99.452301025390625, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+975, 180415, 0, 1519, 5390, '0', 0, 0, -8512.669921875, 739.28497314453125, 102.0500030517578125, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+976, 180415, 0, 1519, 5390, '0', 0, 0, -8512.4501953125, 738.7860107421875, 102.246002197265625, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+977, 180415, 0, 1519, 5390, '0', 0, 0, -8570.8896484375, 725.20697021484375, 100.4820022583007812, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+978, 180415, 0, 1519, 5390, '0', 0, 0, -8512.83984375, 738.87298583984375, 102.167999267578125, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+979, 180415, 0, 1519, 5390, '0', 0, 0, -8572.5, 727.65997314453125, 98.502197265625, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+980, 180415, 0, 1519, 5390, '0', 0, 0, -8577.0400390625, 723.96697998046875, 98.62000274658203125, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+981, 180415, 0, 1519, 5390, '0', 0, 0, -8412.7802734375, 659.302001953125, 99.2230987548828125, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+982, 180415, 0, 1519, 5390, '0', 0, 0, -8478.6396484375, 744.260009765625, 98.95999908447265625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+983, 180415, 0, 1519, 5390, '0', 0, 0, -8478.919921875, 744.75299072265625, 99.141998291015625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+984, 180415, 0, 1519, 5390, '0', 0, 0, -8488.599609375, 753.9949951171875, 99.55370330810546875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+985, 180415, 0, 1519, 5390, '0', 0, 0, -8418, 680.29498291015625, 96.4803009033203125, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+986, 180415, 0, 1519, 5390, '0', 0, 0, -8487.6396484375, 745.5830078125, 99.440399169921875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+987, 180415, 0, 1519, 5390, '0', 0, 0, -8496.48046875, 753.4739990234375, 98.87000274658203125, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+988, 180415, 0, 1519, 5390, '0', 0, 0, -8411.4599609375, 657.70697021484375, 99.226898193359375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+989, 180415, 0, 1519, 5390, '0', 0, 0, -8488.6103515625, 753.43402099609375, 99.56369781494140625, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+990, 180415, 0, 1519, 5390, '0', 0, 0, -8487.4296875, 745.13397216796875, 99.50730133056640625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+991, 180415, 0, 1519, 5390, '0', 0, 0, -8479.0595703125, 744.447998046875, 99.13919830322265625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+992, 180415, 0, 1519, 5390, '0', 0, 0, -8488.2802734375, 753.54901123046875, 99.69699859619140625, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+993, 180415, 0, 1519, 5390, '0', 0, 0, -8416.509765625, 681.4949951171875, 96.47029876708984375, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+994, 180415, 0, 1519, 5390, '0', 0, 0, -8563.3603515625, 741.47198486328125, 101.542999267578125, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+995, 180415, 0, 1519, 5390, '0', 0, 0, -8562.490234375, 742.06597900390625, 101.6019973754882812, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+996, 180415, 0, 1519, 5390, '0', 0, 0, -8561.5703125, 742.85101318359375, 101.6299972534179687, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+997, 180415, 0, 1519, 5390, '0', 0, 0, -8504.75, 761.2340087890625, 98.974700927734375, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+998, 180415, 0, 1519, 5390, '0', 0, 0, -8560.7197265625, 743.52099609375, 101.63800048828125, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+999, 180415, 0, 1519, 5390, '0', 0, 0, -8504.0498046875, 761.0159912109375, 99.01920318603515625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1000, 180415, 0, 1519, 5390, '0', 0, 0, -8558.0400390625, 745.91802978515625, 101.3610000610351562, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1001, 180415, 0, 1519, 5390, '0', 0, 0, -8556.9404296875, 747.46197509765625, 100.9280014038085937, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1002, 180415, 0, 1519, 5390, '0', 0, 0, -8566.650390625, 739.16802978515625, 101.0319976806640625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1003, 180415, 0, 1519, 5390, '0', 0, 0, -8505.0498046875, 769.65997314453125, 99.47480010986328125, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1004, 180415, 0, 1519, 5390, '0', 0, 0, -8553.9404296875, 750.875, 99.81800079345703125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1005, 180415, 0, 1519, 5390, '0', 0, 0, -8553.2001953125, 751.74298095703125, 99.51439666748046875, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1006, 180415, 0, 1519, 5390, '0', 0, 0, -8555.900390625, 748.68597412109375, 100.55999755859375, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1007, 180415, 0, 1519, 5390, '0', 0, 0, -8504.76953125, 769.99798583984375, 99.29010009765625, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1008, 180415, 0, 1519, 5390, '0', 0, 0, -8504.7099609375, 769.49798583984375, 99.47170257568359375, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1009, 180415, 0, 1519, 5390, '0', 0, 0, -8554.8896484375, 749.90997314453125, 100.1790008544921875, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1010, 180415, 0, 1519, 5314, '0', 0, 0, -8374.26953125, 675.79302978515625, 98.4176025390625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1011, 180415, 0, 1519, 5314, '0', 0, 0, -8369.26953125, 677.0560302734375, 98.35489654541015625, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1012, 180415, 0, 1519, 5314, '0', 0, 0, -8367.66015625, 677.37701416015625, 98.529296875, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1013, 180415, 0, 1519, 5314, '0', 0, 0, -8373.2900390625, 675.697998046875, 98.48619842529296875, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1014, 180415, 0, 1519, 5314, '0', 0, 0, -8372.7001953125, 676.6510009765625, 98.37039947509765625, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1015, 180415, 0, 1519, 5314, '0', 0, 0, -8374.58984375, 676.2919921875, 98.51629638671875, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1016, 180415, 0, 1519, 5314, '0', 0, 0, -8368.0302734375, 676.97900390625, 98.52610015869140625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1017, 180415, 0, 1519, 5314, '0', 0, 0, -8368.48046875, 677.38397216796875, 99.77120208740234375, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1018, 180415, 0, 1519, 5314, '0', 0, 0, -8386.33984375, 630.72900390625, 98.494903564453125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1019, 180415, 0, 1519, 5314, '0', 0, 0, -8389.169921875, 629.71197509765625, 96.0749969482421875, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1020, 180415, 0, 1519, 5314, '0', 0, 0, -8388.509765625, 631.280029296875, 96.0167999267578125, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1021, 180415, 0, 1519, 5314, '0', 0, 0, -8385.48046875, 633.40802001953125, 95.88990020751953125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1022, 180415, 0, 1519, 5390, '0', 0, 0, -8364.5, 678.66802978515625, 98.58350372314453125, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1023, 180415, 0, 1519, 5314, '0', 0, 0, -8363.3701171875, 678.08502197265625, 98.53620147705078125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1024, 180415, 0, 1519, 5314, '0', 0, 0, -8362.5703125, 679.09002685546875, 98.47389984130859375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1025, 180415, 0, 1519, 5314, '0', 0, 0, -8387.099609375, 632.65301513671875, 95.9297027587890625, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1026, 180415, 0, 1519, 5314, '0', 0, 0, -8363.6298828125, 678.60101318359375, 99.81780242919921875, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1027, 180415, 0, 1519, 5314, '0', 0, 0, -8387.1796875, 628.843994140625, 98.5420989990234375, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1028, 180415, 0, 1519, 5314, '0', 0, 0, -8389.169921875, 627.61602783203125, 96.1488037109375, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1029, 180415, 0, 1519, 5314, '0', 0, 0, -8383.509765625, 633.4110107421875, 95.8527984619140625, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1030, 180415, 0, 1519, 5314, '0', 0, 0, -8385.76953125, 630.14202880859375, 100.4020004272460937, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1031, 180415, 0, 1519, 5314, '0', 0, 0, -8384.3896484375, 631.58197021484375, 98.39849853515625, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1032, 180415, 0, 1519, 5314, '0', 0, 0, -8383, 630.17498779296875, 100.3440017700195312, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1033, 180415, 0, 1519, 5314, '0', 0, 0, -8384.33984375, 630.760009765625, 100.4219970703125, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1034, 180415, 0, 1519, 5314, '0', 0, 0, -8388.4404296875, 625.989990234375, 96.20050048828125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1035, 180415, 0, 1519, 5314, '0', 0, 0, -8382.51953125, 630.81597900390625, 98.42459869384765625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1036, 180415, 0, 1519, 5314, '0', 0, 0, -8385.7197265625, 627.47198486328125, 100.4940032958984375, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1037, 180415, 0, 1519, 5314, '0', 0, 0, -8386.2900390625, 628.80401611328125, 100.53399658203125, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1038, 180415, 0, 1519, 5314, '0', 0, 0, -8381.7900390625, 632.71697998046875, 95.8361968994140625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1039, 180415, 0, 1519, 5314, '0', 0, 0, -8365.23046875, 647.14898681640625, 104.2310028076171875, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1040, 180415, 0, 1519, 5314, '0', 0, 0, -8364.1103515625, 647.3280029296875, 104.5120010375976562, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1041, 180415, 0, 1519, 5314, '0', 0, 0, -8387.0703125, 624.61602783203125, 96.2220001220703125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1042, 180415, 0, 1519, 5314, '0', 0, 0, -8384.3896484375, 625.98602294921875, 98.5908966064453125, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1043, 180415, 0, 1519, 5314, '0', 0, 0, -8362.75, 647.7030029296875, 104.3239974975585937, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1044, 180415, 0, 1519, 5314, '0', 0, 0, -8382.98046875, 627.45001220703125, 100.4449996948242187, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1045, 180415, 0, 1519, 5314, '0', 0, 0, -8384.349609375, 626.87799072265625, 100.5670013427734375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1046, 180415, 0, 1519, 5314, '0', 0, 0, -8364.6201171875, 647.26202392578125, 104.3550033569335937, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1047, 180415, 0, 1519, 5314, '0', 0, 0, -8386.3603515625, 626.8070068359375, 98.63179779052734375, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1048, 180415, 0, 1519, 5314, '0', 0, 0, -8381.5498046875, 628.78497314453125, 98.44370269775390625, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1049, 180415, 0, 1519, 5314, '0', 0, 0, -8363.580078125, 647.43902587890625, 104.352996826171875, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1050, 180415, 0, 1519, 5314, '0', 0, 0, -8363.23046875, 647.5889892578125, 104.3740005493164062, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1051, 180415, 0, 1519, 5314, '0', 0, 0, -8380.349609375, 631.28302001953125, 95.8656005859375, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1052, 180415, 0, 1519, 5314, '0', 0, 0, -8382.3896484375, 628.85101318359375, 100.4629974365234375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1053, 180415, 0, 1519, 5314, '0', 0, 0, -8382.41015625, 626.75, 98.55899810791015625, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1054, 180415, 0, 1519, 5314, '0', 0, 0, -8379.6796875, 629.66302490234375, 95.9181976318359375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1055, 180415, 0, 1519, 5150, '0', 0, 0, -8379.669921875, 627.67401123046875, 95.9824981689453125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1056, 180415, 0, 1519, 5150, '0', 0, 0, -8385.3896484375, 623.9169921875, 96.20839691162109375, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1057, 180415, 0, 1519, 5150, '0', 0, 0, -8361.1904296875, 647.98797607421875, 104.4329986572265625, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1058, 180415, 0, 1519, 5150, '0', 0, 0, -8358.349609375, 648.82598876953125, 104.3379974365234375, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1059, 180415, 0, 1519, 5150, '0', 0, 0, -8359.2099609375, 648.625, 104.3960037231445312, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1060, 180415, 0, 1519, 5150, '0', 0, 0, -8359.919921875, 648.51202392578125, 104.4459991455078125, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1061, 180415, 0, 1519, 5150, '0', 0, 0, -8362.330078125, 647.677001953125, 104.4899978637695312, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1062, 180415, 0, 1519, 5150, '0', 0, 0, -8383.5400390625, 623.91998291015625, 96.15889739990234375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1063, 180415, 0, 1519, 5150, '0', 0, 0, -8381.73046875, 624.6090087890625, 96.10500335693359375, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1064, 180415, 0, 1519, 5150, '0', 0, 0, -8358.830078125, 648.73297119140625, 104.2020034790039062, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1065, 180415, 0, 1519, 5150, '0', 0, 0, -8359.599609375, 648.572998046875, 104.5189971923828125, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1066, 180415, 0, 1519, 5150, '0', 0, 0, -8360.6904296875, 648.14599609375, 104.3050003051757812, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1067, 180415, 0, 1519, 5150, '0', 0, 0, -8360.2197265625, 648.28802490234375, 104.3960037231445312, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1068, 180415, 0, 1519, 5150, '0', 0, 0, -8361.58984375, 647.93798828125, 104.3700027465820312, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1069, 180415, 0, 1519, 5150, '0', 0, 0, -8357.9404296875, 648.89801025390625, 104.220001220703125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1070, 180415, 0, 1519, 5150, '0', 0, 0, -8380.41015625, 625.96197509765625, 96.0511016845703125, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1071, 180415, 0, 1519, 5150, '0', 0, 0, -8374.0400390625, 614.76702880859375, 95.98960113525390625, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1072, 180415, 0, 1519, 5150, '0', 0, 0, -8373.3798828125, 613.40997314453125, 96.55010223388671875, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1073, 180415, 0, 1519, 5150, '0', 0, 0, -8381.66015625, 608.843994140625, 96.11150360107421875, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1074, 180415, 0, 1519, 5150, '0', 0, 0, -8372.650390625, 612.01898193359375, 97.1320037841796875, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1075, 180415, 0, 1519, 5150, '0', 0, 0, -8380.2998046875, 607.73297119140625, 96.75209808349609375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1076, 180415, 0, 1519, 5150, '0', 0, 0, -8332.8798828125, 660.739990234375, 98.1356964111328125, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1077, 180415, 0, 1519, 5150, '0', 0, 0, -8370.8896484375, 598.34197998046875, 98.90529632568359375, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1078, 180415, 0, 1519, 5150, '0', 0, 0, -8382.2099609375, 589.5889892578125, 98.89739990234375, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1079, 180415, 0, 1519, 5150, '0', 0, 0, -8367.169921875, 601.4320068359375, 98.8759002685546875, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1080, 180415, 0, 1519, 5150, '0', 0, 0, -8379.009765625, 606.6719970703125, 97.31749725341796875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1081, 180415, 0, 1519, 5150, '0', 0, 0, -8368.990234375, 599.8179931640625, 98.870697021484375, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1082, 180415, 0, 1519, 5150, '0', 0, 0, -8378.4697265625, 592.7030029296875, 98.890899658203125, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1083, 180415, 0, 1519, 5150, '0', 0, 0, -8380.33984375, 591.16302490234375, 98.874298095703125, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1084, 180415, 0, 1519, 5150, '0', 0, 0, -8365.1904296875, 574.27398681640625, 105.2620010375976562, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1085, 180415, 0, 1519, 5150, '0', 0, 0, -8361.2001953125, 577.2760009765625, 105.2919998168945312, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1086, 180415, 0, 1519, 5150, '0', 0, 0, -8363.2099609375, 575.7550048828125, 105.3069992065429687, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1087, 180415, 0, 1519, 5150, '0', 0, 0, -8359.48046875, 578.71502685546875, 105.3610000610351562, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1088, 180415, 0, 1519, 5150, '0', 0, 0, -8355.48046875, 581.68402099609375, 105.3470001220703125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1089, 180415, 0, 1519, 5150, '0', 0, 0, -8357.419921875, 580.23101806640625, 105.3330001831054687, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1090, 180415, 0, 1519, 5150, '0', 0, 0, -8339.2099609375, 601.71197509765625, 104.9530029296875, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1091, 180415, 0, 1519, 5150, '0', 0, 0, -8339.8603515625, 602.51702880859375, 104.9530029296875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1092, 180415, 0, 1519, 5150, '0', 0, 0, -8345.580078125, 612.29998779296875, 107.03399658203125, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1093, 180415, 0, 1519, 5150, '0', 0, 0, -8344.0400390625, 613.62298583984375, 106.8300018310546875, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1094, 180415, 0, 1519, 5150, '0', 0, 0, -8328.6201171875, 588.41802978515625, 105.1859970092773437, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1095, 180415, 0, 1519, 5150, '0', 0, 0, -8342.150390625, 615.0469970703125, 107.0070037841796875, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1096, 180415, 0, 1519, 5150, '0', 0, 0, -8329.330078125, 589.31597900390625, 105.1660003662109375, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1097, 180415, 0, 1519, 5150, '0', 0, 0, -8342.5703125, 614.75299072265625, 106.8160018920898437, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1098, 180415, 0, 1519, 5150, '0', 0, 0, -8336.6796875, 598.59002685546875, 105.2129974365234375, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1099, 180415, 0, 1519, 5150, '0', 0, 0, -8337.2802734375, 599.3189697265625, 105.0240020751953125, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1100, 180415, 0, 1519, 5150, '0', 0, 0, -8327.900390625, 610.77398681640625, 105.0670013427734375, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1101, 180415, 0, 1519, 5150, '0', 0, 0, -8326, 585.13897705078125, 104.9850006103515625, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1102, 180415, 0, 1519, 5150, '0', 0, 0, -8326.6904296875, 586, 105.0439987182617187, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1103, 180415, 0, 1519, 5150, '0', 0, 0, -8340.8603515625, 615.85198974609375, 106.9449996948242187, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1104, 180415, 0, 1519, 5150, '0', 0, 0, -8341.3603515625, 615.7239990234375, 106.852996826171875, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1105, 180415, 0, 1519, 5150, '0', 0, 0, -8334.76953125, 596.20001220703125, 105.1320037841796875, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1106, 180415, 0, 1519, 5150, '0', 0, 0, -8335.330078125, 596.92401123046875, 105.1790008544921875, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1107, 180415, 0, 1519, 5150, '0', 0, 0, -8324.76953125, 583.4739990234375, 105.0360031127929687, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1108, 180415, 0, 1519, 5150, '0', 0, 0, -8339.8603515625, 616.83502197265625, 106.9739990234375, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1109, 180415, 0, 1519, 5150, '0', 0, 0, -8339.3798828125, 617.02301025390625, 106.7050018310546875, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1110, 180415, 0, 1519, 5150, '0', 0, 0, -8333.0498046875, 593.99700927734375, 105.2300033569335937, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1111, 180415, 0, 1519, 5150, '0', 0, 0, -8338.7197265625, 617.875, 106.8570022583007812, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1112, 180415, 0, 1519, 5150, '0', 0, 0, -8338.16015625, 618.04901123046875, 107.0019989013671875, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1113, 180415, 0, 1519, 5150, '0', 0, 0, -8331.169921875, 591.6669921875, 105.09100341796875, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1114, 180415, 0, 1519, 5150, '0', 0, 0, -8331.73046875, 592.41802978515625, 104.9459991455078125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1115, 180415, 0, 1519, 5150, '0', 0, 0, -8344.33984375, 613.302001953125, 106.9919967651367187, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1116, 180415, 0, 1519, 5150, '0', 0, 0, -8336.9599609375, 619.1610107421875, 106.983001708984375, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1117, 180415, 0, 1519, 5150, '0', 0, 0, -8329.759765625, 589.9530029296875, 105.227996826171875, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1118, 180415, 0, 1519, 5150, '0', 0, 0, -8342.83984375, 614.26702880859375, 106.8629989624023437, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1119, 180415, 0, 1519, 5150, '0', 0, 0, -8343.3203125, 614.14801025390625, 107.0159988403320312, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1120, 180415, 0, 1519, 5150, '0', 0, 0, -8337.8095703125, 599.98602294921875, 105.1880035400390625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1121, 180415, 0, 1519, 5150, '0', 0, 0, -8338.4697265625, 600.79498291015625, 105.1959991455078125, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1122, 180415, 0, 1519, 5150, '0', 0, 0, -8327.3095703125, 586.72198486328125, 105.19000244140625, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1123, 180415, 0, 1519, 5150, '0', 0, 0, -8328.259765625, 611.47601318359375, 105.2020034790039062, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1124, 180415, 0, 1519, 5150, '0', 0, 0, -8327.849609375, 587.48297119140625, 105.2060012817382812, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1125, 180415, 0, 1519, 5150, '0', 0, 0, -8341.740234375, 615.39801025390625, 107.0400009155273437, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1126, 180415, 0, 1519, 5150, '0', 0, 0, -8336.0302734375, 597.74102783203125, 105.0550003051757812, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1127, 180415, 0, 1519, 5150, '0', 0, 0, -8325.3603515625, 584.24102783203125, 105.09100341796875, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1128, 180415, 0, 1519, 5150, '0', 0, 0, -8340.33984375, 616.5419921875, 106.9459991455078125, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1129, 180415, 0, 1519, 5150, '0', 0, 0, -8340.580078125, 616.3389892578125, 106.8629989624023437, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1130, 180415, 0, 1519, 5150, '0', 0, 0, -8333.650390625, 594.74700927734375, 105.0250015258789062, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1131, 180415, 0, 1519, 5150, '0', 0, 0, -8334.240234375, 595.51702880859375, 105.2020034790039062, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1132, 180415, 0, 1519, 5150, '0', 0, 0, -8339.099609375, 617.45501708984375, 106.9499969482421875, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1133, 180415, 0, 1519, 5150, '0', 0, 0, -8332.26953125, 593.10601806640625, 105.1910018920898437, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1134, 180415, 0, 1519, 5150, '0', 0, 0, -8344.740234375, 612.84197998046875, 106.75, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1135, 180415, 0, 1519, 5150, '0', 0, 0, -8332.66015625, 593.572998046875, 105.2050018310546875, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1136, 180415, 0, 1519, 5150, '0', 0, 0, -8345.2197265625, 612.6199951171875, 106.819000244140625, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1137, 180415, 0, 1519, 5150, '0', 0, 0, -8337.3701171875, 618.802001953125, 106.9300003051757812, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1138, 180415, 0, 1519, 5150, '0', 0, 0, -8337.8603515625, 618.5679931640625, 106.8489990234375, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1139, 180415, 0, 1519, 5150, '0', 0, 0, -8330.2900390625, 590.54498291015625, 105.0400009155273437, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1140, 180415, 0, 1519, 5150, '0', 0, 0, -8330.7001953125, 591.16998291015625, 105.1920013427734375, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1141, 180415, 0, 1519, 5150, '0', 0, 0, -8343.6103515625, 613.77801513671875, 106.8980026245117187, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1142, 180415, 0, 1519, 5150, '0', 0, 0, -8326.25, 608.781005859375, 105.0210037231445312, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1143, 180415, 0, 1519, 5150, '0', 0, 0, -8321.08984375, 602.11798095703125, 105.2020034790039062, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1144, 180415, 0, 1519, 5150, '0', 0, 0, -8320.25, 601.07098388671875, 105.154998779296875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1145, 180415, 0, 1519, 5150, '0', 0, 0, -8323.3603515625, 605.06597900390625, 105.2259979248046875, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1146, 180415, 0, 1519, 5150, '0', 0, 0, -8322.6298828125, 604.04498291015625, 105.0930023193359375, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1147, 180415, 0, 1519, 5150, '0', 0, 0, -8325.5703125, 607.9310302734375, 105.2119979858398437, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1148, 180415, 0, 1519, 5150, '0', 0, 0, -8327.3203125, 610.14202880859375, 105.21099853515625, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1149, 180415, 0, 1519, 5150, '0', 0, 0, -8326.8095703125, 609.447998046875, 104.8889999389648437, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1150, 180415, 0, 1519, 5150, '0', 0, 0, -8321.9599609375, 603.218994140625, 105.009002685546875, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1151, 180415, 0, 1519, 5150, '0', 0, 0, -8324.830078125, 606.93798828125, 105.1750030517578125, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1152, 180415, 0, 1519, 5150, '0', 0, 0, -8324.169921875, 606.06298828125, 105.0569992065429687, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1153, 180415, 0, 1519, 5150, '0', 0, 0, -8314.58984375, 594.0889892578125, 105.1729965209960937, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1154, 180415, 0, 1519, 5150, '0', 0, 0, -8316.1201171875, 595.91302490234375, 104.9990005493164062, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1155, 180415, 0, 1519, 5150, '0', 0, 0, -8317.9599609375, 598.33697509765625, 105.2229995727539062, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1156, 180415, 0, 1519, 5150, '0', 0, 0, -8317.25, 597.34002685546875, 105.2310028076171875, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1157, 180415, 0, 1519, 5150, '0', 0, 0, -8314.01953125, 593.29901123046875, 104.9840011596679687, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1158, 180415, 0, 1519, 5150, '0', 0, 0, -8313.2900390625, 592.41302490234375, 105.1910018920898437, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1159, 180415, 0, 1519, 5150, '0', 0, 0, -8315.3798828125, 595.09002685546875, 105.0370025634765625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1160, 180415, 0, 1519, 5150, '0', 0, 0, -8316.6904296875, 596.63397216796875, 105.1259994506835937, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1161, 180415, 0, 1519, 5150, '0', 0, 0, -8319.509765625, 600.12200927734375, 105.0569992065429687, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1162, 180415, 0, 1519, 5150, '0', 0, 0, -8318.7099609375, 599.14599609375, 105.1569976806640625, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1163, 180415, 0, 1519, 5150, '0', 0, 0, -8317.2197265625, 666.3909912109375, 98.1891021728515625, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1164, 180415, 0, 1519, 5150, '0', 0, 0, -8311.8896484375, 656.31097412109375, 98.18890380859375, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1165, 180415, 0, 1519, 5150, '0', 0, 0, -8312.0595703125, 659.69097900390625, 98.1891021728515625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1166, 180415, 0, 1519, 5150, '0', 0, 0, -8326.6103515625, 665.81298828125, 98.186798095703125, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1167, 180415, 0, 1519, 5150, '0', 0, 0, -8321.830078125, 667.2760009765625, 98.18900299072265625, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1168, 180415, 0, 1519, 5150, '0', 0, 0, -8330.2001953125, 662.99700927734375, 98.15399932861328125, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+1169, 180415, 0, 1519, 9171, '0', 0, 0, -8251.9404296875, 892.64599609375, 101.1539993286132812, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1170, 180415, 0, 1519, 9171, '0', 0, 0, -8251.73046875, 891.32501220703125, 101.4589996337890625, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1171, 180415, 0, 1519, 9171, '0', 0, 0, -8249.7802734375, 880.43597412109375, 101.4729995727539062, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1172, 180415, 0, 1519, 9171, '0', 0, 0, -8249.9599609375, 881.5260009765625, 101.625, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1173, 180415, 0, 1519, 9171, '0', 0, 0, -8243.3896484375, 889.77301025390625, 100.8860015869140625, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1174, 180415, 0, 1519, 9171, '0', 0, 0, -8244.759765625, 889.04901123046875, 101.177001953125, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1175, 180415, 0, 1519, 9171, '0', 0, 0, -8245.91015625, 881.1929931640625, 101.1910018920898437, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1176, 180415, 0, 1519, 9171, '0', 0, 0, -8244.75, 880.08197021484375, 100.88800048828125, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1177, 180415, 0, 1519, 9171, '0', 0, 0, -8244.009765625, 884.95098876953125, 101.1699981689453125, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1178, 180415, 0, 1519, 9171, '0', 0, 0, -8248.33984375, 890.78997802734375, 101.4749984741210937, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1179, 180415, 0, 1519, 9171, '0', 0, 0, -8246.4697265625, 885.26898193359375, 101.625, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1180, 180415, 0, 1519, 9171, '0', 0, 0, -8247.650390625, 882.864990234375, 101.625, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1181, 180415, 0, 1519, 9171, '0', 0, 0, -8254.669921875, 889.60797119140625, 101.4929962158203125, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1182, 180415, 0, 1519, 9171, '0', 0, 0, -8245.919921875, 888.42498779296875, 101.4800033569335937, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1183, 180415, 0, 1519, 9171, '0', 0, 0, -8252.1904296875, 894.21002197265625, 100.8639984130859375, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1184, 180415, 0, 1519, 9171, '0', 0, 0, -8255.0498046875, 886.48297119140625, 101.625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1185, 180415, 0, 1519, 9171, '0', 0, 0, -8254.419921875, 878.31097412109375, 100.8779983520507812, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1186, 180415, 0, 1519, 9171, '0', 0, 0, -8258.0703125, 881.97601318359375, 100.8949966430664062, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1187, 180415, 0, 1519, 9171, '0', 0, 0, -8251.51953125, 890.12200927734375, 101.5999984741210937, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1188, 180415, 0, 1519, 9171, '0', 0, 0, -8252.6796875, 881.88397216796875, 101.625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1189, 180415, 0, 1519, 9171, '0', 0, 0, -8247.0703125, 893.385009765625, 100.878997802734375, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1190, 180415, 0, 1519, 9171, '0', 0, 0, -8247.76953125, 892.010009765625, 101.1660003662109375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1191, 180415, 0, 1519, 9171, '0', 0, 0, -8249.2802734375, 877.62298583984375, 100.8830032348632812, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1192, 180415, 0, 1519, 9171, '0', 0, 0, -8249.5498046875, 879.1719970703125, 101.177001953125, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1193, 180415, 0, 1519, 9171, '0', 0, 0, -8248.8701171875, 889.77099609375, 101.5999984741210937, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1194, 180415, 0, 1519, 9171, '0', 0, 0, -8246.830078125, 882.07501220703125, 101.48699951171875, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1195, 180415, 0, 1519, 9171, '0', 0, 0, -8246.8701171875, 887.9310302734375, 101.625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1196, 180415, 0, 1519, 9171, '0', 0, 0, -8242.5302734375, 884.72198486328125, 100.8929977416992187, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1197, 180415, 0, 1519, 9171, '0', 0, 0, -8254.58984375, 883.83001708984375, 101.625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1198, 180415, 0, 1519, 9171, '0', 0, 0, -8245.33984375, 885.11798095703125, 101.4840011596679687, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1199, 180415, 0, 1519, 9171, '0', 0, 0, -8256.2197265625, 886.66998291015625, 101.4619979858398437, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1200, 180415, 0, 1519, 9171, '0', 0, 0, -8253.7802734375, 888.87200927734375, 101.625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1201, 180415, 0, 1519, 9171, '0', 0, 0, -8256.7900390625, 882.656005859375, 101.1669998168945312, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1202, 180415, 0, 1519, 9171, '0', 0, 0, -8255.5595703125, 883.31298828125, 101.4889984130859375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1203, 180415, 0, 1519, 9171, '0', 0, 0, -8257.490234375, 886.78497314453125, 101.1740036010742187, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1204, 180415, 0, 1519, 9171, '0', 0, 0, -8253.16015625, 880.8590087890625, 101.4629974365234375, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1205, 180415, 0, 1519, 9171, '0', 0, 0, -8253.740234375, 879.70697021484375, 101.1660003662109375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1206, 180415, 0, 1519, 9171, '0', 0, 0, -8255.6298828125, 890.54901123046875, 101.180999755859375, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1207, 180415, 0, 1519, 9171, '0', 0, 0, -8256.849609375, 891.61602783203125, 100.8730010986328125, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1208, 180415, 0, 1519, 9171, '0', 0, 0, -8259.150390625, 887.03497314453125, 100.86199951171875, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+1209, 180415, 0, 1519, 5316, '0', 0, 0, -8329.6103515625, 893.69598388671875, 98.68170166015625, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1210, 180415, 0, 1519, 5316, '0', 0, 0, -8325.83984375, 897.22198486328125, 98.9822998046875, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1211, 180415, 0, 1519, 5316, '0', 0, 0, -8333.650390625, 895.4580078125, 98.428802490234375, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1212, 180415, 0, 1519, 5316, '0', 0, 0, -8310.1396484375, 921.7340087890625, 98.63390350341796875, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1213, 180415, 0, 1519, 5316, '0', 0, 0, -8328.3798828125, 909.02099609375, 98.74970245361328125, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1214, 180415, 0, 1519, 5316, '0', 0, 0, -8328.25, 899.34698486328125, 101.2419967651367187, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1215, 180415, 0, 1519, 5316, '0', 0, 0, -8315.7197265625, 911.92498779296875, 98.7572021484375, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1216, 180415, 0, 1519, 5316, '0', 0, 0, -8333.0498046875, 900.51397705078125, 98.63210296630859375, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1217, 180415, 0, 1519, 5316, '0', 0, 0, -8300.3603515625, 903.75701904296875, 99.14600372314453125, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1218, 180415, 0, 1519, 5316, '0', 0, 0, -8304.330078125, 905.99298095703125, 99.11419677734375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1219, 180415, 0, 1519, 5316, '0', 0, 0, -8305.8896484375, 919.6610107421875, 99.04810333251953125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1220, 180415, 0, 1519, 5316, '0', 0, 0, -8326.16015625, 913.27099609375, 98.6277008056640625, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1221, 180415, 0, 1519, 5316, '0', 0, 0, -8327.9404296875, 899.34197998046875, 101.3860015869140625, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1222, 180415, 0, 1519, 5316, '0', 0, 0, -8319.3203125, 909.35797119140625, 98.8957977294921875, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1223, 180415, 0, 1519, 5316, '0', 0, 0, -8321.4697265625, 905.406005859375, 98.92690277099609375, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1224, 180415, 0, 1519, 5316, '0', 0, 0, -8328.080078125, 899.62799072265625, 101.1279983520507812, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1225, 180415, 0, 1519, 5316, '0', 0, 0, -8308.25, 908, 99.0198974609375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1226, 180415, 0, 1519, 5316, '0', 0, 0, -8311.9697265625, 909.968994140625, 98.855499267578125, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1227, 180415, 0, 1519, 5316, '0', 0, 0, -8295.2197265625, 913.8330078125, 98.89890289306640625, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1228, 180415, 0, 1519, 5316, '0', 0, 0, -8299.0703125, 915.635009765625, 99.33660125732421875, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1229, 180415, 0, 1519, 5316, '0', 0, 0, -8326.1103515625, 917.65802001953125, 98.47209930419921875, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1230, 180415, 0, 1519, 5316, '0', 0, 0, -8330.9599609375, 920.89202880859375, 98.384002685546875, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1231, 180415, 0, 1519, 5316, '0', 0, 0, -8313.83984375, 923.52801513671875, 98.49849700927734375, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1232, 180415, 0, 1519, 5316, '0', 0, 0, -8320.9697265625, 927.39398193359375, 98.28330230712890625, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1233, 180415, 0, 1519, 5316, '0', 0, 0, -8335.5498046875, 923.7860107421875, 98.23470306396484375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1234, 180415, 0, 1519, 5316, '0', 0, 0, -8317.1298828125, 925.3189697265625, 98.3927001953125, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1235, 180415, 0, 1519, 5316, '0', 0, 0, -8325.169921875, 929.6090087890625, 98.1531982421875, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1236, 180415, 0, 1519, 5316, '0', 0, 0, -8379, 912.26202392578125, 99.5948028564453125, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1237, 180415, 0, 1519, 5316, '0', 0, 0, -8328.6796875, 933.32098388671875, 97.97119903564453125, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1238, 180415, 0, 1519, 5316, '0', 0, 0, -8325.83984375, 938.9580078125, 97.9774017333984375, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1239, 180415, 0, 1519, 5316, '0', 0, 0, -8343.6796875, 928.21197509765625, 98.14240264892578125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1240, 180415, 0, 1519, 5316, '0', 0, 0, -8336.0400390625, 937.510009765625, 97.90350341796875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1241, 180415, 0, 1519, 5316, '0', 0, 0, -8375.9296875, 915.72698974609375, 99.438201904296875, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1242, 180415, 0, 1519, 5316, '0', 0, 0, -8348.5400390625, 930.35400390625, 98.13610076904296875, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1243, 180415, 0, 1519, 5316, '0', 0, 0, -8353.41015625, 932.46502685546875, 98.055999755859375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1244, 180415, 0, 1519, 5316, '0', 0, 0, -8348.48046875, 941.29901123046875, 97.62079620361328125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1245, 180415, 0, 1519, 5316, '0', 0, 0, -8372.6103515625, 924.21002197265625, 98.83480072021484375, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1246, 180415, 0, 1519, 5316, '0', 0, 0, -8383.6396484375, 913.8489990234375, 99.68340301513671875, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1247, 180415, 0, 1519, 5316, '0', 0, 0, -8370.5, 928.927001953125, 98.54599761962890625, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1248, 180415, 0, 1519, 5316, '0', 0, 0, -8361.0703125, 935.91998291015625, 98.07469940185546875, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1249, 180415, 0, 1519, 5316, '0', 0, 0, -8342.8701171875, 938.77301025390625, 97.7566986083984375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1250, 180415, 0, 1519, 5316, '0', 0, 0, -8383.73046875, 917.99700927734375, 99.49919891357421875, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1251, 180415, 0, 1519, 5316, '0', 0, 0, -8323.6796875, 943.28497314453125, 97.97650146484375, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1252, 180415, 0, 1519, 5316, '0', 0, 0, -8321.5703125, 947.760009765625, 97.95279693603515625, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1253, 180415, 0, 1519, 5316, '0', 0, 0, -8333.6396484375, 942.50897216796875, 97.8677978515625, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+1254, 180415, 0, 1519, 5346, '0', 0, 0, -8319.4501953125, 952.12799072265625, 98.10849761962890625, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1255, 180415, 0, 1519, 5346, '0', 0, 0, -8317.150390625, 956.98797607421875, 98.33679962158203125, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1256, 180415, 0, 1519, 5346, '0', 0, 0, -8314.9296875, 961.35198974609375, 98.50659942626953125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1257, 180415, 0, 1519, 5346, '0', 0, 0, -8331.4404296875, 947.0780029296875, 97.84380340576171875, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1258, 180415, 0, 1519, 5346, '0', 0, 0, -8322.7001953125, 965.1199951171875, 98.28459930419921875, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1259, 180415, 0, 1519, 5346, '0', 0, 0, -8291.6904296875, 989.92401123046875, 101.1139984130859375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1260, 180415, 0, 1519, 5346, '0', 0, 0, -8290.9599609375, 989, 101.3720016479492187, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1261, 180415, 0, 1519, 5346, '0', 0, 0, -8329.330078125, 951.35198974609375, 97.76149749755859375, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1262, 180415, 0, 1519, 5346, '0', 0, 0, -8290.76953125, 988.85797119140625, 101.3430023193359375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1263, 180415, 0, 1519, 5346, '0', 0, 0, -8327.1904296875, 955.7550048828125, 97.9394989013671875, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1264, 180415, 0, 1519, 5346, '0', 0, 0, -8324.91015625, 960.50701904296875, 98.1118011474609375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1265, 180415, 0, 1519, 5346, '0', 0, 0, -8296.8701171875, 995.50201416015625, 101.3280029296875, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1266, 180415, 0, 1519, 5346, '0', 0, 0, -8295.8701171875, 994.5419921875, 101.1480026245117187, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1267, 180415, 0, 1519, 5346, '0', 0, 0, -8366.2099609375, 948.46697998046875, 97.52989959716796875, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1268, 180415, 0, 1519, 5346, '0', 0, 0, -8293.2998046875, 992, 101.3850021362304687, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1269, 180415, 0, 1519, 5346, '0', 0, 0, -8293.08984375, 991.59002685546875, 101.2080001831054687, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1270, 180415, 0, 1519, 5346, '0', 0, 0, -8294.58984375, 992.90997314453125, 101.4039993286132812, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1271, 180415, 0, 1519, 5346, '0', 0, 0, -8294.4599609375, 992.62298583984375, 101.3160018920898437, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1272, 180415, 0, 1519, 5346, '0', 0, 0, -8360.8896484375, 946.0260009765625, 97.54810333251953125, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1273, 180415, 0, 1519, 5346, '0', 0, 0, -8296.7998046875, 995.00299072265625, 101.3339996337890625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1274, 180415, 0, 1519, 5346, '0', 0, 0, -8365.2001953125, 937.63201904296875, 97.954803466796875, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1275, 180415, 0, 1519, 5346, '0', 0, 0, -8368.3095703125, 934.0570068359375, 98.2447967529296875, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1276, 180415, 0, 1519, 5346, '0', 0, 0, -8292.7001953125, 991.447998046875, 101.2429962158203125, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1277, 180415, 0, 1519, 5346, '0', 0, 0, -8292.23046875, 990.3060302734375, 101.302001953125, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1278, 180415, 0, 1519, 5346, '0', 0, 0, -8294.73046875, 992.60797119140625, 101.0699996948242187, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1279, 180415, 0, 1519, 5346, '0', 0, 0, -8356.330078125, 944.12799072265625, 97.59100341796875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1280, 180415, 0, 1519, 5346, '0', 0, 0, -8371.740234375, 950.99798583984375, 97.54340362548828125, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1281, 180415, 0, 1519, 5346, '0', 0, 0, -8375.5498046875, 936.94097900390625, 98.2530975341796875, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1282, 180415, 0, 1519, 5346, '0', 0, 0, -8375.7802734375, 942.03497314453125, 98.05249786376953125, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1283, 180415, 0, 1519, 5346, '0', 0, 0, -8380.6904296875, 943.48602294921875, 98.31330108642578125, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1284, 180415, 0, 1519, 5346, '0', 0, 0, -8379.48046875, 926.989990234375, 98.78099822998046875, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1285, 180415, 0, 1519, 5346, '0', 0, 0, -8377.6103515625, 931.98101806640625, 98.5529022216796875, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1286, 180415, 0, 1519, 5346, '0', 0, 0, -8380.5703125, 954.864990234375, 97.4302978515625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1287, 180415, 0, 1519, 5346, '0', 0, 0, -8385.099609375, 944.114990234375, 98.3551025390625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1288, 180415, 0, 1519, 5346, '0', 0, 0, -8385.580078125, 977.48101806640625, 97.2129974365234375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1289, 180415, 0, 1519, 5346, '0', 0, 0, -8386.4296875, 958.16497802734375, 97.73130035400390625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1290, 180415, 0, 1519, 5346, '0', 0, 0, -8389.8701171875, 943.74102783203125, 98.39769744873046875, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1291, 180415, 0, 1519, 5346, '0', 0, 0, -8384.8203125, 983.531005859375, 97.005096435546875, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1292, 180415, 0, 1519, 5346, '0', 0, 0, -8398.4296875, 953.89801025390625, 98.3383026123046875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1293, 180415, 0, 1519, 5346, '0', 0, 0, -8394.6796875, 942.7760009765625, 98.53600311279296875, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1294, 180415, 0, 1519, 5346, '0', 0, 0, -8394.580078125, 984.1719970703125, 97.32649993896484375, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1295, 180415, 0, 1519, 5346, '0', 0, 0, -8395.080078125, 978.85797119140625, 97.47789764404296875, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1296, 180415, 0, 1519, 5346, '0', 0, 0, -8402.48046875, 939.5, 99.0142974853515625, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1297, 180415, 0, 1519, 5346, '0', 0, 0, -8407.9404296875, 947.82098388671875, 99.05500030517578125, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1298, 180415, 0, 1519, 5346, '0', 0, 0, -8398.6904296875, 941.29498291015625, 98.83899688720703125, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1299, 180415, 0, 1519, 5346, '0', 0, 0, -8402.5400390625, 951.24798583984375, 98.67040252685546875, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1300, 180415, 0, 1519, 5346, '0', 0, 0, -8412.099609375, 944.968994140625, 99.2270965576171875, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1301, 180415, 0, 1519, 5346, '0', 0, 0, -8411.3095703125, 934.030029296875, 99.41030120849609375, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1302, 180415, 0, 1519, 5346, '0', 0, 0, -8419.2998046875, 918.614990234375, 99.61810302734375, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1303, 180415, 0, 1519, 5346, '0', 0, 0, -8415.650390625, 912.7760009765625, 99.4597015380859375, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1304, 180415, 0, 1519, 5346, '0', 0, 0, -8415.08984375, 931.5360107421875, 99.52210235595703125, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1305, 180415, 0, 1519, 5346, '0', 0, 0, -8415.7001953125, 942.50299072265625, 99.34200286865234375, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1306, 180415, 0, 1519, 5346, '0', 0, 0, -8414.5703125, 908.2550048828125, 99.1864013671875, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1307, 180415, 0, 1519, 5346, '0', 0, 0, -8418.9404296875, 928.91802978515625, 99.657501220703125, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1308, 180415, 0, 1519, 5346, '0', 0, 0, -8421.7900390625, 922.39202880859375, 99.66139984130859375, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1309, 180415, 0, 1519, 5346, '0', 0, 0, -8423.08984375, 937.46502685546875, 99.59429931640625, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1310, 180415, 0, 1519, 5346, '0', 0, 0, -8419.58984375, 939.85601806640625, 99.4651031494140625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1311, 180415, 0, 1519, 5346, '0', 0, 0, -8420.8203125, 908.18902587890625, 98.977996826171875, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1312, 180415, 0, 1519, 5346, '0', 0, 0, -8422.5302734375, 926.4949951171875, 99.76239776611328125, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1313, 180415, 0, 1519, 5346, '0', 0, 0, -8429.9599609375, 919.29998779296875, 99.82140350341796875, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1314, 180415, 0, 1519, 5346, '0', 0, 0, -8423.990234375, 911.0679931640625, 99.3946990966796875, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1315, 180415, 0, 1519, 5346, '0', 0, 0, -8427.580078125, 915.85400390625, 99.9026031494140625, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1316, 180415, 0, 1519, 5346, '0', 0, 0, -8426.4599609375, 935.3060302734375, 99.67230224609375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1317, 180415, 0, 1519, 5314, '0', 0, 0, -8434.0498046875, 918.79998779296875, 100.0940017700195312, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+1318, 180415, 0, 1519, 5346, '0', 0, 0, -8443.5703125, 932.55401611328125, 99.62920379638671875, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1319, 180415, 0, 1519, 5346, '0', 0, 0, -8441.419921875, 929.8060302734375, 99.8264007568359375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1320, 180415, 0, 1519, 5346, '0', 0, 0, -8436.599609375, 928.57098388671875, 99.959197998046875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1321, 180415, 0, 1519, 5346, '0', 0, 0, -8438, 916.135009765625, 100.1389999389648437, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1322, 180415, 0, 1519, 5346, '0', 0, 0, -8433.400390625, 930.67498779296875, 99.83930206298828125, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1323, 180415, 0, 1519, 5346, '0', 0, 0, -8445.4697265625, 911.21697998046875, 100.4489974975585937, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1324, 180415, 0, 1519, 5346, '0', 0, 0, -8452.490234375, 929.3280029296875, 99.08550262451171875, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1325, 180415, 0, 1519, 5346, '0', 0, 0, -8454.8798828125, 932.531005859375, 98.70980072021484375, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1326, 180415, 0, 1519, 5346, '0', 0, 0, -8449.9599609375, 918.87701416015625, 100.1179962158203125, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1327, 180415, 0, 1519, 5346, '0', 0, 0, -8447.8095703125, 922.54498291015625, 99.86669921875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1328, 180415, 0, 1519, 5346, '0', 0, 0, -8455.5, 904.1939697265625, 100.1569976806640625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1329, 180415, 0, 1519, 5346, '0', 0, 0, -8463.2197265625, 909.9429931640625, 100.2020034790039062, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1330, 180415, 0, 1519, 5346, '0', 0, 0, -8459.580078125, 901.40997314453125, 100.0149993896484375, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1331, 180415, 0, 1519, 5346, '0', 0, 0, -8449.41015625, 940.05902099609375, 98.57109832763671875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1332, 180415, 0, 1519, 5346, '0', 0, 0, -8454.849609375, 888.468994140625, 100.6790008544921875, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1333, 180415, 0, 1519, 5346, '0', 0, 0, -8447.0400390625, 937.2969970703125, 98.98079681396484375, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1334, 180415, 0, 1519, 5346, '0', 0, 0, -8457.349609375, 935.83197021484375, 98.374298095703125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1335, 180415, 0, 1519, 5346, '0', 0, 0, -8450.080078125, 925.97601318359375, 99.50949859619140625, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1336, 180415, 0, 1519, 5346, '0', 0, 0, -8458.5, 913.14599609375, 99.96700286865234375, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1337, 180415, 0, 1519, 5346, '0', 0, 0, -8459.4697265625, 896.010009765625, 100.46600341796875, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1338, 180415, 0, 1519, 5346, '0', 0, 0, -8453.509765625, 916.46697998046875, 100.1060028076171875, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1339, 180415, 0, 1519, 5346, '0', 0, 0, -8457.099609375, 892.32098388671875, 100.4680023193359375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1340, 180415, 0, 1519, 5346, '0', 0, 0, -8449.580078125, 908.48602294921875, 100.542999267578125, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1341, 180415, 0, 1519, 5346, '0', 0, 0, -8469.2197265625, 912.5989990234375, 99.58370208740234375, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1342, 180415, 0, 1519, 5346, '0', 0, 0, -8467.4599609375, 909.39599609375, 99.8572998046875, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1343, 180415, 0, 1519, 5346, '0', 0, 0, -8456.919921875, 850.42498779296875, 112.2050018310546875, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1344, 180415, 0, 1519, 5346, '0', 0, 0, -8476.669921875, 858.01898193359375, 105.7860031127929687, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1345, 180415, 0, 1519, 5346, '0', 0, 0, -8466.1201171875, 850.21502685546875, 105.7860031127929687, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1346, 180415, 0, 1519, 5346, '0', 0, 0, -8473.3896484375, 857.6810302734375, 105.7860031127929687, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1347, 180415, 0, 1519, 5346, '0', 0, 0, -8464.4296875, 858.26397705078125, 105.7860031127929687, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1348, 180415, 0, 1519, 5346, '0', 0, 0, -8470.080078125, 853.76702880859375, 105.7860031127929687, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1349, 180415, 0, 1519, 5346, '0', 0, 0, -8452.7802734375, 848.74798583984375, 112.2829971313476562, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1350, 180415, 0, 1519, 5346, '0', 0, 0, -8477.4697265625, 853.59600830078125, 105.7119979858398437, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1351, 180415, 0, 1519, 5346, '0', 0, 0, -8469.33984375, 857.9219970703125, 105.7860031127929687, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1352, 180415, 0, 1519, 5346, '0', 0, 0, -8474.349609375, 853.49700927734375, 105.7860031127929687, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1353, 180415, 0, 1519, 5346, '0', 0, 0, -8465.849609375, 854.280029296875, 105.7860031127929687, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1354, 180415, 0, 1519, 5346, '0', 0, 0, -8469.7197265625, 842.54302978515625, 105.7860031127929687, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1355, 180415, 0, 1519, 5346, '0', 0, 0, -8470.259765625, 849.625, 105.7860031127929687, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1356, 180415, 0, 1519, 5346, '0', 0, 0, -8460.400390625, 847.625, 112.21099853515625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1357, 180415, 0, 1519, 5346, '0', 0, 0, -8464.41015625, 839.656005859375, 105.7860031127929687, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1358, 180415, 0, 1519, 5346, '0', 0, 0, -8474.26953125, 845.51702880859375, 105.7860031127929687, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1359, 180415, 0, 1519, 5346, '0', 0, 0, -8455.4501953125, 841.5360107421875, 112.2040023803710937, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1360, 180415, 0, 1519, 5346, '0', 0, 0, -8452, 844.4320068359375, 112.2559967041015625, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1361, 180415, 0, 1519, 5346, '0', 0, 0, -8477.830078125, 849.34197998046875, 105.7860031127929687, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1362, 180415, 0, 1519, 5346, '0', 0, 0, -8460.6904296875, 844.03497314453125, 105.9690017700195312, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1363, 180415, 0, 1519, 5346, '0', 0, 0, -8460.0302734375, 843.93798828125, 106.2099990844726562, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1364, 180415, 0, 1519, 5346, '0', 0, 0, -8461.080078125, 846.51397705078125, 105.9690017700195312, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1365, 180415, 0, 1519, 5346, '0', 0, 0, -8460.509765625, 846.79998779296875, 106.2099990844726562, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1366, 180415, 0, 1519, 5346, '0', 0, 0, -8468.759765625, 838.8330078125, 105.7860031127929687, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1367, 180415, 0, 1519, 5346, '0', 0, 0, -8470.3701171875, 845.84600830078125, 105.66400146484375, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1368, 180415, 0, 1519, 5346, '0', 0, 0, -8466.2900390625, 846.43402099609375, 105.7860031127929687, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1369, 180415, 0, 1519, 5346, '0', 0, 0, -8465.4404296875, 843.40301513671875, 105.7860031127929687, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1370, 180415, 0, 1519, 5346, '0', 0, 0, -8459.4404296875, 843.89398193359375, 106.404998779296875, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1371, 180415, 0, 1519, 5346, '0', 0, 0, -8459.6201171875, 843.14202880859375, 112.2060012817382812, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1372, 180415, 0, 1519, 5346, '0', 0, 0, -8474.2998046875, 849.3699951171875, 105.7860031127929687, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1373, 180415, 0, 1519, 5346, '0', 0, 0, -8535.5302734375, 898.905029296875, 107.9970016479492187, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1374, 180415, 0, 1519, 5346, '0', 0, 0, -8459.9296875, 847.0360107421875, 106.404998779296875, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1375, 180415, 0, 1519, 5346, '0', 0, 0, -8535.0302734375, 900.2139892578125, 107.608001708984375, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1376, 180415, 0, 1519, 5346, '0', 0, 0, -8473.740234375, 842.25, 105.7860031127929687, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1377, 180415, 0, 1519, 5346, '0', 0, 0, -8487.919921875, 842.1719970703125, 106.589996337890625, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1378, 180415, 0, 1519, 5346, '0', 0, 0, -8476.25, 837.447998046875, 105.7860031127929687, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1379, 180415, 0, 1519, 5346, '0', 0, 0, -8491.400390625, 845.12701416015625, 106.5469970703125, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1380, 180415, 0, 1519, 5346, '0', 0, 0, -8493.25, 845.010009765625, 106.5920028686523437, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1381, 180415, 0, 1519, 5346, '0', 0, 0, -8467.490234375, 834.65301513671875, 105.7860031127929687, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1382, 180415, 0, 1519, 5346, '0', 0, 0, -8463, 835.802001953125, 105.7860031127929687, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1383, 180415, 0, 1519, 5346, '0', 0, 0, -8488.6396484375, 843.48297119140625, 106.552001953125, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1384, 180415, 0, 1519, 5346, '0', 0, 0, -8489.9501953125, 844.60101318359375, 106.5759963989257812, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1385, 180415, 0, 1519, 5346, '0', 0, 0, -8460.990234375, 832.22198486328125, 105.7860031127929687, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1386, 180415, 0, 1519, 5346, '0', 0, 0, -8490.400390625, 842.760009765625, 108.7170028686523437, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1387, 180415, 0, 1519, 5346, '0', 0, 0, -8492.169921875, 843.36602783203125, 108.753997802734375, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1388, 180415, 0, 1519, 5346, '0', 0, 0, -8472.830078125, 838.39599609375, 105.7860031127929687, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1389, 180415, 0, 1519, 5346, '0', 0, 0, -8493.01953125, 839.5689697265625, 110.4189987182617187, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1390, 180415, 0, 1519, 5346, '0', 0, 0, -8493.6904296875, 840.781005859375, 110.4690017700195312, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1391, 180415, 0, 1519, 5346, '0', 0, 0, -8489.3798828125, 837.572998046875, 106.5830001831054687, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1392, 180415, 0, 1519, 5346, '0', 0, 0, -8490.6796875, 839.8590087890625, 110.4160003662109375, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1393, 180415, 0, 1519, 5346, '0', 0, 0, -8474.990234375, 833.33697509765625, 105.7860031127929687, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1394, 180415, 0, 1519, 5346, '0', 0, 0, -8491.83984375, 838.45098876953125, 108.7559967041015625, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1395, 180415, 0, 1519, 5346, '0', 0, 0, -8490.1396484375, 839.35400390625, 108.7429962158203125, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1396, 180415, 0, 1519, 5346, '0', 0, 0, -8536.8798828125, 895.62298583984375, 108.0279998779296875, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1397, 180415, 0, 1519, 5346, '0', 0, 0, -8492.1201171875, 842.63201904296875, 110.4739990234375, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1398, 180415, 0, 1519, 5346, '0', 0, 0, -8537.33984375, 894.447998046875, 107.6520004272460937, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1399, 180415, 0, 1519, 5346, '0', 0, 0, -8490.8603515625, 842.17401123046875, 110.41400146484375, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1400, 180415, 0, 1519, 5346, '0', 0, 0, -8493.830078125, 842.52099609375, 108.707000732421875, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1401, 180415, 0, 1519, 5346, '0', 0, 0, -8493.240234375, 842.01702880859375, 110.4199981689453125, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1402, 180415, 0, 1519, 5346, '0', 0, 0, -8471.33984375, 834.03997802734375, 105.7860031127929687, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1403, 180415, 0, 1519, 5346, '0', 0, 0, -8494.4404296875, 840.75299072265625, 108.7139968872070312, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1404, 180415, 0, 1519, 5346, '0', 0, 0, -8496.169921875, 841.47900390625, 106.5719985961914062, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1405, 180415, 0, 1519, 5346, '0', 0, 0, -8488.2802734375, 838.9010009765625, 106.5849990844726562, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1406, 180415, 0, 1519, 5346, '0', 0, 0, -8487.76953125, 840.3489990234375, 106.572998046875, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1407, 180415, 0, 1519, 5346, '0', 0, 0, -8491.76953125, 839.23297119140625, 110.4800033569335937, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1408, 180415, 0, 1519, 5346, '0', 0, 0, -8469.1298828125, 830.07598876953125, 105.7860031127929687, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1409, 180415, 0, 1519, 5346, '0', 0, 0, -8489.51953125, 841.00897216796875, 108.7620010375976562, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1410, 180415, 0, 1519, 5346, '0', 0, 0, -8490.2802734375, 840.98797607421875, 110.4639968872070312, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1411, 180415, 0, 1519, 5346, '0', 0, 0, -8494.5, 844.32098388671875, 106.4420013427734375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1412, 180415, 0, 1519, 5346, '0', 0, 0, -8465.5703125, 830.8800048828125, 105.7860031127929687, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1413, 180415, 0, 1519, 5346, '0', 0, 0, -8495.650390625, 842.96002197265625, 106.5960006713867187, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1414, 180415, 0, 1519, 5346, '0', 0, 0, -8493.9296875, 837.156005859375, 106.572998046875, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1415, 180415, 0, 1519, 5346, '0', 0, 0, -8495.3095703125, 838.36602783203125, 106.5589981079101562, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1416, 180415, 0, 1519, 5346, '0', 0, 0, -8493.5400390625, 839.07598876953125, 108.75, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1417, 180415, 0, 1519, 5346, '0', 0, 0, -8496.0703125, 839.71002197265625, 106.5770034790039062, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1418, 180415, 0, 1519, 5346, '0', 0, 0, -8473.1396484375, 829.39801025390625, 105.78399658203125, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1419, 180415, 0, 1519, 5346, '0', 0, 0, -8490.740234375, 836.8699951171875, 106.6050033569335937, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1420, 180415, 0, 1519, 5346, '0', 0, 0, -8492.509765625, 836.75299072265625, 106.589996337890625, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1421, 180415, 0, 1519, 0, '0', 0, 0, -8565.5, 906.39202880859375, 100.3629989624023437, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1422, 180415, 0, 1519, 0, '0', 0, 0, -8566.1201171875, 908.14599609375, 100.3209991455078125, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1423, 180415, 0, 1519, 0, '0', 0, 0, -8566.2001953125, 902.822998046875, 100.3960037231445312, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1424, 180415, 0, 1519, 0, '0', 0, 0, -8565.490234375, 904.50897216796875, 100.391998291015625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1425, 180415, 0, 1519, 0, '0', 0, 0, -8568.900390625, 906.99298095703125, 104.7080001831054687, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1426, 180415, 0, 1519, 0, '0', 0, 0, -8569.349609375, 900.76898193359375, 100.4169998168945312, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1427, 180415, 0, 1519, 0, '0', 0, 0, -8568.2900390625, 907.5469970703125, 102.766998291015625, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1428, 180415, 0, 1519, 0, '0', 0, 0, -8567.5400390625, 901.48602294921875, 100.4110031127929687, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1429, 180415, 0, 1519, 0, '0', 0, 0, -8568.2802734375, 905.65802001953125, 104.7880020141601562, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1430, 180415, 0, 1519, 0, '0', 0, 0, -8568.900390625, 904.1810302734375, 104.766998291015625, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1431, 180415, 0, 1519, 0, '0', 0, 0, -8567.48046875, 905.62701416015625, 102.8290023803710937, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1432, 180415, 0, 1519, 0, '0', 0, 0, -8568.2802734375, 903.59197998046875, 102.785003662109375, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1433, 180415, 0, 1519, 0, '0', 0, 0, -8567.58984375, 909.59002685546875, 100.3249969482421875, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1434, 180415, 0, 1519, 4411, '0', 0, 0, -8570.2197265625, 902.76397705078125, 102.8199996948242187, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1435, 180415, 0, 1519, 4411, '0', 0, 0, -8569.25, 910.260009765625, 100.2990036010742187, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1436, 180415, 0, 1519, 4411, '0', 0, 0, -8570.3095703125, 903.64398193359375, 104.8199996948242187, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1437, 180415, 0, 1519, 0, '0', 0, 0, -8571.580078125, 906.93798828125, 104.6699981689453125, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1438, 180415, 0, 1519, 0, '0', 0, 0, -8571.2099609375, 910.26202392578125, 100.2900009155273437, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1439, 180415, 0, 1519, 4411, '0', 0, 0, -8571.650390625, 904.31298828125, 104.8040008544921875, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1440, 180415, 0, 1519, 4411, '0', 0, 0, -8571.2998046875, 900.76702880859375, 100.384002685546875, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1441, 180415, 0, 1519, 0, '0', 0, 0, -8570.150390625, 908.37799072265625, 102.76300048828125, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1442, 180415, 0, 1519, 0, '0', 0, 0, -8570.2001953125, 907.54901123046875, 104.75, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1443, 180415, 0, 1519, 4411, '0', '0', 0, -8572.169921875, 905.63702392578125, 104.78900146484375, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1444, 180415, 0, 1519, 4411, '0', 0, 0, -8572.150390625, 903.59698486328125, 102.8170013427734375, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1445, 180415, 0, 1519, 4411, '0', 0, 0, -8574.25, 902.875, 100.4199981689453125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1446, 180415, 0, 1519, 4411, '0', 0, 0, -8574.9296875, 904.46002197265625, 100.3690032958984375, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1447, 180415, 0, 1519, 4411, '0', 0, 0, -8574.9697265625, 906.51202392578125, 100.3550033569335937, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1448, 180415, 0, 1519, 0, '0', 0, 0, -8572.1201171875, 907.58697509765625, 102.7509994506835937, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1449, 180415, 0, 1519, 4411, '0', 0, 0, -8572.98046875, 901.56097412109375, 100.3249969482421875, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1450, 180415, 0, 1519, 4411, '0', 0, 0, -8574.2900390625, 908.16802978515625, 100.3160018920898437, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1451, 180415, 0, 1519, 4411, '0', 0, 0, -8572.9404296875, 909.51202392578125, 100.26300048828125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1452, 180415, 0, 1519, 4411, '0', 0, 0, -8573.0400390625, 905.68902587890625, 102.8209991455078125, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1453, 180415, 0, 1519, 0, '0', 0, 0, -8552.982421875, 765.46527099609375, 107.3615036010742187, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1454, 180415, 0, 1519, 0, '0', 0, 0, -8556.1298828125, 769.31768798828125, 106.9352798461914062, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1455, 180415, 0, 1519, 0, '0', 0, 0, -8555.330078125, 768.26214599609375, 107.3162689208984375, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1456, 180415, 0, 1519, 0, '0', 0, 0, -8552.1298828125, 764.39410400390625, 106.9785003662109375, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+1457, 180415, 0, 1519, 5151, '0', 0, 0, -8571.099609375, 736.90802001953125, 98.810302734375, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 45745), -- CandleBlack01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+1458, 180415, 0, 1519, 5151, '0', 0, 0, -8569.8203125, 737.5570068359375, 99.5005035400390625, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- CandleBlack01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+1459, 180415, 0, 1519, 5151, '0', 0, 0, -8573.169921875, 735.88201904296875, 97.817596435546875, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+1460, 180415, 0, 1519, 5151, '0', 0, 0, -8568.25, 738.36602783203125, 100.1920013427734375, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+1461, 180415, 0, 1519, 5151, '0', 0, 0, -8572.1298828125, 736.36297607421875, 98.32230377197265625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Cathedral Square - Difficulty: 0)
(@OGUID+1462, 180415, 0, 1519, 5390, '0', 0, 0, -8612.5302734375, 746.77398681640625, 101.63800048828125, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1463, 180415, 0, 1519, 5390, '0', 0, 0, -8612.9501953125, 747.48297119140625, 101.0029983520507812, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1464, 180415, 0, 1519, 5390, '0', 0, 0, -8614.849609375, 751.06097412109375, 97.96779632568359375, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1465, 180415, 0, 1519, 5390, '0', 0, 0, -8614.3701171875, 750.125, 98.7462005615234375, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1466, 180415, 0, 1519, 5390, '0', 0, 0, -8618.48046875, 745.5780029296875, 99.53289794921875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1467, 180415, 0, 1519, 5390, '0', 0, 0, -8619.259765625, 746.2760009765625, 98.7462005615234375, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1468, 180415, 0, 1519, 5390, '0', 0, 0, -8616.4404296875, 743.70697021484375, 101.63800048828125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1469, 180415, 0, 1519, 5390, '0', 0, 0, -8617.0498046875, 744.24102783203125, 101.0029983520507812, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1470, 180415, 0, 1519, 5390, '0', 0, 0, -8613.8603515625, 749.21197509765625, 99.53289794921875, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1471, 180415, 0, 1519, 5390, '0', 0, 0, -8620.01953125, 747.00201416015625, 97.96779632568359375, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1472, 180415, 0, 1519, 5390, '0', 0, 0, -8617.8095703125, 744.98101806640625, 100.1969985961914062, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1473, 180415, 0, 1519, 5390, '0', 0, 0, -8613.419921875, 748.42901611328125, 100.1969985961914062, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1474, 180415, 0, 1519, 5390, '0', 0, 0, -8638.2900390625, 758.52301025390625, 98.2864990234375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1475, 180415, 0, 1519, 5390, '0', 0, 0, -8639.9296875, 759.37799072265625, 98.27809906005859375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1476, 180415, 0, 1519, 5390, '0', 0, 0, -8636.3203125, 758.26898193359375, 98.295501708984375, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1477, 180415, 0, 1519, 5390, '0', 0, 0, -8634.4697265625, 758.82598876953125, 98.3018035888671875, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1478, 180415, 0, 1519, 5390, '0', 0, 0, -8632.830078125, 760.07501220703125, 98.29509735107421875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1479, 180415, 0, 1519, 5390, '0', 0, 0, -8641.75, 762.83697509765625, 98.28170013427734375, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1480, 180415, 0, 1519, 5390, '0', 0, 0, -8641.490234375, 764.74102783203125, 98.27989959716796875, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1481, 180415, 0, 1519, 5390, '0', 0, 0, -8631.9697265625, 761.75201416015625, 98.30159759521484375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1482, 180415, 0, 1519, 5390, '0', 0, 0, -8641.23046875, 761.09600830078125, 98.1988983154296875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1483, 180415, 0, 1519, 5390, '0', 0, 0, -8632.830078125, 760.07501220703125, 98.29509735107421875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1484, 180415, 0, 1519, 5390, '0', 0, 0, -8640.599609375, 766.4840087890625, 98.2261962890625, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1485, 180415, 0, 1519, 5390, '0', 0, 0, -8631.73046875, 763.7139892578125, 98.29250335693359375, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1486, 180415, 0, 1519, 5390, '0', 0, 0, -8671.8701171875, 769.52801513671875, 97.9933013916015625, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1487, 180415, 0, 1519, 5390, '0', 0, 0, -8632.23046875, 765.46197509765625, 98.2969970703125, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1488, 180415, 0, 1519, 5390, '0', 0, 0, -8638.9697265625, 767.71697998046875, 98.24859619140625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1489, 180415, 0, 1519, 5390, '0', 0, 0, -8671, 770.40997314453125, 98.5037994384765625, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1490, 180415, 0, 1519, 5390, '0', 0, 0, -8635.1103515625, 768.02398681640625, 98.17189788818359375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1491, 180415, 0, 1519, 5390, '0', 0, 0, -8633.5498046875, 767.16302490234375, 98.25910186767578125, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1492, 180415, 0, 1519, 5390, '0', 0, 0, -8686.5498046875, 775.39398193359375, 100.93499755859375, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1493, 180415, 0, 1519, 5390, '0', 0, 0, -8661.7900390625, 779.5689697265625, 101.634002685546875, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1494, 180415, 0, 1519, 5390, '0', 0, 0, -8637.2900390625, 768.32098388671875, 98.212799072265625, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1495, 180415, 0, 1519, 5390, '0', 0, 0, -8667.169921875, 774.87799072265625, 101.0970001220703125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1496, 180415, 0, 1519, 5390, '0', 0, 0, -8664.58984375, 777.4169921875, 101.6579971313476562, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1497, 180415, 0, 1519, 5390, '0', 0, 0, -8670.1796875, 771.34698486328125, 99.06819915771484375, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1498, 180415, 0, 1519, 5390, '0', 0, 0, -8686.240234375, 775.3590087890625, 100.76300048828125, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1499, 180415, 0, 1519, 5390, '0', 0, 0, -8663.7001953125, 778.0830078125, 101.621002197265625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1500, 180415, 0, 1519, 5390, '0', 0, 0, -8662.75, 778.86602783203125, 101.6330032348632812, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1501, 180415, 0, 1519, 5390, '0', 0, 0, -8669.259765625, 772.375, 99.60230255126953125, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1502, 180415, 0, 1519, 5390, '0', 0, 0, -8668.26953125, 773.52801513671875, 100.3679962158203125, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1503, 180415, 0, 1519, 5390, '0', 0, 0, -8652.4404296875, 785.0689697265625, 97.9795989990234375, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1504, 180415, 0, 1519, 5390, '0', 0, 0, -8655.900390625, 783.0469970703125, 99.78800201416015625, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1505, 180415, 0, 1519, 5390, '0', 0, 0, -8654.76953125, 783.75299072265625, 99.19049835205078125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1506, 180415, 0, 1519, 5390, '0', 0, 0, -8653.650390625, 784.32501220703125, 98.6194000244140625, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1507, 180415, 0, 1519, 5390, '0', 0, 0, -8658.4599609375, 781.73602294921875, 101.0230026245117187, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1508, 180415, 0, 1519, 5390, '0', 0, 0, -8657.0703125, 782.41802978515625, 100.3519973754882812, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1509, 180415, 0, 1519, 5390, '0', 0, 0, -8662.9296875, 805.00701904296875, 99.92350006103515625, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1510, 180415, 0, 1519, 5390, '0', 0, 0, -8663.0400390625, 805.27301025390625, 100.0459976196289062, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1511, 180415, 0, 1519, 5390, '0', 0, 0, -8663.3603515625, 805.4530029296875, 100.1009979248046875, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1512, 180415, 0, 1519, 8411, '0', 0, 0, -8879.16015625, 870.9310302734375, 102.5640029907226562, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1513, 180415, 0, 1519, 8411, '0', 0, 0, -8876.5498046875, 870.64599609375, 104.1330032348632812, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1514, 180415, 0, 1519, 8411, '0', 0, 0, -8877.3798828125, 875.30902099609375, 103.3629989624023437, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1515, 180415, 0, 1519, 8411, '0', 0, 0, -8875.150390625, 870.41998291015625, 104.7710037231445312, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1516, 180415, 0, 1519, 8411, '0', 0, 0, -8878.48046875, 875.49102783203125, 102.595001220703125, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1517, 180415, 0, 1519, 8411, '0', 0, 0, -8875.900390625, 875.0560302734375, 104.1620025634765625, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1518, 180415, 0, 1519, 8411, '0', 0, 0, -8874.5703125, 874.83001708984375, 104.7639999389648437, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1519, 180415, 0, 1519, 8411, '0', 0, 0, -8877.8603515625, 870.81402587890625, 103.4209976196289062, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1520, 180415, 0, 1519, 5390, '0', 0, 0, -8887.169921875, 806.5050048828125, 94.186798095703125, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1521, 180415, 0, 1519, 5390, '0', 0, 0, -8886.01953125, 806.23297119140625, 95.0951995849609375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1522, 180415, 0, 1519, 5390, '0', 0, 0, -8883.080078125, 810.75897216796875, 96.0988006591796875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1523, 180415, 0, 1519, 5390, '0', 0, 0, -8884.4599609375, 811.16802978515625, 95.3267974853515625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1524, 180415, 0, 1519, 5390, '0', 0, 0, -8881.7197265625, 810.40301513671875, 96.76039886474609375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1525, 180415, 0, 1519, 5390, '0', 0, 0, -8882.7802734375, 805.5, 96.8130035400390625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1526, 180415, 0, 1519, 5390, '0', 0, 0, -8885.8896484375, 811.46697998046875, 94.2494964599609375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1527, 180415, 0, 1519, 5390, '0', 0, 0, -8884.23046875, 805.8060302734375, 96.12860107421875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1528, 180415, 0, 1519, 5390, '0', 0, 0, -8622.8095703125, 867.780029296875, 101.0749969482421875, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1529, 180415, 0, 1519, 5390, '0', 0, 0, -8623.6103515625, 868.99298095703125, 102.0879974365234375, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1530, 180415, 0, 1519, 5390, '0', 0, 0, -8620.4404296875, 864.12799072265625, 98.22910308837890625, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1531, 180415, 0, 1519, 5390, '0', 0, 0, -8621.150390625, 865.38702392578125, 99.18389892578125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1532, 180415, 0, 1519, 5390, '0', 0, 0, -8624.3095703125, 870.17901611328125, 102.93499755859375, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1533, 180415, 0, 1519, 5390, '0', 0, 0, -8620.7099609375, 872.98602294921875, 102.9079971313476562, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1534, 180415, 0, 1519, 5390, '0', 0, 0, -8622.01953125, 866.61297607421875, 100.141998291015625, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1535, 180415, 0, 1519, 5390, '0', 0, 0, -8617.919921875, 869.96197509765625, 100.1409988403320312, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1536, 180415, 0, 1519, 5390, '0', 0, 0, -8616.830078125, 868.77398681640625, 99.1717987060546875, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1537, 180415, 0, 1519, 5390, '0', 0, 0, -8615.83984375, 867.71697998046875, 98.22519683837890625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1538, 180415, 0, 1519, 5390, '0', 0, 0, -8619.7900390625, 871.95001220703125, 101.944000244140625, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1539, 180415, 0, 1519, 5390, '0', 0, 0, -8618.900390625, 870.97900390625, 101.16400146484375, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1540, 180415, 0, 1519, 4411, '0', 0, 0, -8553.349609375, 1014.19317626953125, 91.05899810791015625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1541, 180415, 0, 1519, 4411, '0', 0, 0, -8544.78125, 1009.37530517578125, 91.05899810791015625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1542, 180415, 0, 1519, 4411, '0', 0, 0, -8547.80859375, 1007.1317138671875, 91.05899810791015625, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1543, 180415, 0, 1519, 4411, '0', 0, 0, -8550.283203125, 1016.5714111328125, 91.05899810791015625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1544, 180415, 0, 1519, 4411, '0', 0, 0, -8563.626953125, 1011.73309326171875, 95.70896148681640625, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1545, 180415, 0, 1519, 4411, '0', 0, 0, -8551.421875, 1007.50128173828125, 91.05899810791015625, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1546, 180415, 0, 1519, 4411, '0', 0, 0, -8552.4384765625, 997.26910400390625, 95.96730804443359375, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1547, 180415, 0, 1519, 4411, '0', 0, 0, -8553.7099609375, 1010.57659912109375, 91.05899810791015625, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1548, 180415, 0, 1519, 4411, '0', 0, 0, -8546.7216796875, 1016.0272216796875, 91.10066986083984375, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1549, 180415, 0, 1519, 4411, '0', 0, 0, -8544.3623046875, 1013.18212890625, 91.05899810791015625, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1550, 180415, 0, 1519, 8411, '0', 0, 0, -8888.861328125, 1015.02947998046875, 133.4301300048828125, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1551, 180415, 0, 1519, 8411, '0', 0, 0, -8888.611328125, 1017.82989501953125, 138.8144073486328125, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- CandleBlack01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+1552, 180415, 0, 1519, 5390, '0', 0, 0, -8975.0595703125, 766.8699951171875, 97.7382965087890625, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1553, 180415, 0, 1519, 5390, '0', 0, 0, -8974, 768.78302001953125, 96.69680023193359375, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1554, 180415, 0, 1519, 5390, '0', 0, 0, -8974.599609375, 767.78997802734375, 97.3047027587890625, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1555, 180415, 0, 1519, 5390, '0', 0, 0, -8979.1298828125, 768.81597900390625, 97.8878021240234375, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1556, 180415, 0, 1519, 5390, '0', 0, 0, -8978.509765625, 769.9429931640625, 97.365997314453125, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1557, 180415, 0, 1519, 5390, '0', 0, 0, -8978.0400390625, 770.9320068359375, 96.7931976318359375, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1558, 180415, 0, 1519, 5390, '0', 0, 0, -8984.48046875, 849.83697509765625, 29.62059974670410156, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: The Canals - Difficulty: 0)
(@OGUID+1559, 180415, 0, 1519, 5154, '0', 0, 0, -8985, 849.38397216796875, 29.44919967651367187, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1560, 180415, 0, 1519, 5154, '0', 0, 0, -8985.0302734375, 849.8699951171875, 29.4029998779296875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1561, 180415, 0, 1519, 5154, '0', 0, 0, -8988.990234375, 846.50701904296875, 29.22789955139160156, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1562, 180415, 0, 1519, 5154, '0', 0, 0, -8987.5, 858.9320068359375, 125.7170028686523437, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1563, 180415, 0, 1519, 5154, '0', 0, 0, -8984.7998046875, 860.5570068359375, 124.9599990844726562, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1564, 180415, 0, 1519, 5154, '0', 0, 0, -8979.0498046875, 878.53497314453125, 120.6610031127929687, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1565, 180415, 0, 1519, 5154, '0', 0, 0, -8978.8603515625, 868.4840087890625, 122.6880035400390625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1566, 180415, 0, 1519, 5154, '0', 0, 0, -8980.3896484375, 865.47100830078125, 123.4380035400390625, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1567, 180415, 0, 1519, 5154, '0', 0, 0, -8985.669921875, 865.843994140625, 123.8470001220703125, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1568, 180415, 0, 1519, 5154, '0', 0, 0, -8984.25, 868.50201416015625, 122.90899658203125, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1569, 180415, 0, 1519, 5154, '0', 0, 0, -8982.1298828125, 862.5689697265625, 124.1740036010742187, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1570, 180415, 0, 1519, 5154, '0', 0, 0, -8978.25, 875.1939697265625, 121.3330001831054687, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1571, 180415, 0, 1519, 5154, '0', 0, 0, -8978.41015625, 871.98297119140625, 121.9840011596679687, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1572, 180415, 0, 1519, 5154, '0', 0, 0, -8987.6201171875, 864.09600830078125, 124.7399978637695312, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1573, 180415, 0, 1519, 5154, '0', 0, 0, -8983.6904296875, 871.6810302734375, 121.9469985961914062, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1574, 180415, 0, 1519, 5154, '0', 0, 0, -8990.240234375, 862.468994140625, 125.8270034790039062, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1575, 180415, 0, 1519, 5154, '0', 0, 0, -8983.66015625, 874.88201904296875, 120.9940032958984375, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1576, 180415, 0, 1519, 5154, '0', 0, 0, -8984.7099609375, 877.58697509765625, 120.2360000610351562, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1577, 180415, 0, 1519, 5154, '0', 0, 0, -8984.5703125, 887.22198486328125, 118.8040008544921875, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1578, 180415, 0, 1519, 5154, '0', 0, 0, -8980.23046875, 881.8070068359375, 120.0230026245117187, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1579, 180415, 0, 1519, 5154, '0', 0, 0, -8990.349609375, 858.218994140625, 126.4729995727539062, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1580, 180415, 0, 1519, 5154, '0', 0, 0, -8982.01953125, 884.86602783203125, 119.3639984130859375, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1581, 180415, 0, 1519, 5154, '0', 0, 0, -8986.26953125, 880.52801513671875, 119.3389968872070312, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1582, 180415, 0, 1519, 5154, '0', 0, 0, -8988.3203125, 882.58001708984375, 118.68499755859375, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1583, 180415, 0, 1519, 5154, '0', 0, 0, -8996.76953125, 858.66998291015625, 128.238006591796875, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1584, 180415, 0, 1519, 5154, '0', 0, 0, -8990.7197265625, 884.8179931640625, 117.9010009765625, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1585, 180415, 0, 1519, 5154, '0', 0, 0, -8994.1904296875, 886.09600830078125, 117.1269989013671875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1586, 180415, 0, 1519, 5154, '0', 0, 0, -8986.8203125, 889.61602783203125, 118.266998291015625, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1587, 180415, 0, 1519, 5154, '0', 0, 0, -8989.7001953125, 891.37200927734375, 117.7099990844726562, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1588, 180415, 0, 1519, 5154, '0', 0, 0, -8995.349609375, 862.2550048828125, 128.074005126953125, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1589, 180415, 0, 1519, 5154, '0', 0, 0, -8997.509765625, 863.2449951171875, 129.0279998779296875, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1590, 180415, 0, 1519, 5154, '0', 0, 0, -8992.98046875, 861.85797119140625, 126.8519973754882812, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1591, 180415, 0, 1519, 5154, '0', 0, 0, -8993.599609375, 858.10101318359375, 127.375, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1592, 180415, 0, 1519, 5154, '0', 0, 0, -8992.669921875, 892.22601318359375, 117.2450027465820312, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1593, 180415, 0, 1519, 5154, '0', 0, 0, -8995.98046875, 893.33502197265625, 116.7089996337890625, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1594, 180415, 0, 1519, 5154, '0', 0, 0, -9001.9296875, 886.8330078125, 115.4369964599609375, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1595, 180415, 0, 1519, 5154, '0', 0, 0, -9002.0498046875, 862.40301513671875, 129.805999755859375, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1596, 180415, 0, 1519, 5154, '0', 0, 0, -8997.759765625, 887.41497802734375, 116.2939987182617187, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1597, 180415, 0, 1519, 5154, '0', 0, 0, -9008.8701171875, 858.20501708984375, 107.0999984741210937, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1598, 180415, 0, 1519, 5154, '0', 0, 0, -9006.58984375, 855.85198974609375, 105.9459991455078125, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1599, 180415, 0, 1519, 5154, '0', 0, 0, -8999.7001953125, 864.635009765625, 129.7819976806640625, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1600, 180415, 0, 1519, 5154, '0', 0, 0, -8999.4697265625, 860.27801513671875, 129.20599365234375, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1601, 180415, 0, 1519, 5154, '0', 0, 0, -9003.2197265625, 893.47698974609375, 115.589996337890625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1602, 180415, 0, 1519, 5154, '0', 0, 0, -8999.8203125, 894.3590087890625, 116.0839996337890625, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1603, 180415, 0, 1519, 5154, '0', 0, 0, -9013.51953125, 865.280029296875, 109.6060028076171875, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1604, 180415, 0, 1519, 5154, '0', 0, 0, -9005.4404296875, 886.04998779296875, 114.7060012817382812, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1605, 180415, 0, 1519, 5154, '0', 0, 0, -9012.509765625, 849.55401611328125, 106.3379974365234375, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1606, 180415, 0, 1519, 5154, '0', 0, 0, -9012.8203125, 862.70098876953125, 109.0449981689453125, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1607, 180415, 0, 1519, 5154, '0', 0, 0, -9011.16015625, 860.50897216796875, 108.19000244140625, 1.256635904312133789, 0, 0, 0.587784767150878906, 0.809017360210418701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1608, 180415, 0, 1519, 5154, '0', 0, 0, -9014.4501953125, 868.25701904296875, 110.2289962768554687, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1609, 180415, 0, 1519, 5154, '0', 0, 0, -9007.1103515625, 892.56097412109375, 115.0199966430664062, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1610, 180415, 0, 1519, 5154, '0', 0, 0, -9015.0703125, 852.09002685546875, 107.2440032958984375, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1611, 180415, 0, 1519, 5154, '0', 0, 0, -9011.7197265625, 881.385009765625, 113.0680007934570312, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1612, 180415, 0, 1519, 5154, '0', 0, 0, -9008.73046875, 884.13702392578125, 113.9059982299804687, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1613, 180415, 0, 1519, 5154, '0', 0, 0, -9021.580078125, 863.760009765625, 109.8730010986328125, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1614, 180415, 0, 1519, 5154, '0', 0, 0, -9015.1298828125, 871.36102294921875, 110.8649978637695312, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1615, 180415, 0, 1519, 5154, '0', 0, 0, -9013.7099609375, 877.59698486328125, 112.1699981689453125, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1616, 180415, 0, 1519, 5154, '0', 0, 0, -9019.8603515625, 857.72100830078125, 108.9919967651367187, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1617, 180415, 0, 1519, 5154, '0', 0, 0, -9014.4599609375, 874.38702392578125, 111.5139999389648437, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1618, 180415, 0, 1519, 5154, '0', 0, 0, -9020.75, 860.74298095703125, 109.4390029907226562, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1619, 180415, 0, 1519, 5154, '0', 0, 0, -9014.6396484375, 888.61602783203125, 113.7529983520507812, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1620, 180415, 0, 1519, 5154, '0', 0, 0, -9017.5, 854.66497802734375, 108.1070022583007812, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1621, 180415, 0, 1519, 5154, '0', 0, 0, -9011.0400390625, 891.59698486328125, 114.4240036010742187, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1622, 180415, 0, 1519, 5154, '0', 0, 0, -9020.3701171875, 882.5419921875, 112.5410003662109375, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1623, 180415, 0, 1519, 5154, '0', 0, 0, -9022.41015625, 866.96502685546875, 110.319000244140625, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1624, 180415, 0, 1519, 5154, '0', 0, 0, -9017.1103515625, 890.364990234375, 29.4300994873046875, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1625, 180415, 0, 1519, 5154, '0', 0, 0, -9022.5302734375, 874.27801513671875, 111.3669967651367187, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1626, 180415, 0, 1519, 5154, '0', 0, 0, -9021.2900390625, 886.8179931640625, 29.62059974670410156, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1627, 180415, 0, 1519, 5154, '0', 0, 0, -9017.7197265625, 885.47900390625, 113.1220016479492187, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1628, 180415, 0, 1519, 5154, '0', 0, 0, -9023.2900390625, 870.54998779296875, 110.8170013427734375, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1629, 180415, 0, 1519, 5154, '0', 0, 0, -9021.5400390625, 878.15997314453125, 111.9219970703125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1630, 180415, 0, 1519, 5154, '0', 0, 0, -9021.099609375, 886.49298095703125, 29.22410011291503906, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1631, 180415, 0, 1519, 5154, '0', 0, 0, -8908.71875, 1025.720458984375, 129.674072265625, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1632, 180415, 0, 1519, 5154, '0', 0, 0, -8990.9501953125, 963.90301513671875, 116.339996337890625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1633, 180415, 0, 1519, 5154, '0', 0, 0, -8989.150390625, 964.02301025390625, 116.2559967041015625, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1634, 180415, 0, 1519, 5154, '0', 0, 0, -8984.9697265625, 964.1810302734375, 116.2990036010742187, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1635, 180415, 0, 1519, 5154, '0', 0, 0, -8890.1005859375, 1022.640625, 145.22381591796875, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1636, 180415, 0, 1519, 5154, '0', 0, 0, -8983.23046875, 964.17498779296875, 116.2710037231445312, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1637, 180415, 0, 1519, 5154, '0', 0, 0, -8987, 964.12799072265625, 116.3010025024414062, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1638, 180415, 0, 1519, 5154, '0', 0, 0, -9002.490234375, 960.70501708984375, 116.595001220703125, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1639, 180415, 0, 1519, 5154, '0', 0, 0, -8996.2998046875, 963.46697998046875, 116.5410003662109375, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1640, 180415, 0, 1519, 5154, '0', 0, 0, -8895.330078125, 1028.7708740234375, 137.7728271484375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1641, 180415, 0, 1519, 5154, '0', 0, 0, -8898.6806640625, 1029.25, 136.816802978515625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1642, 180415, 0, 1519, 5154, '0', 0, 0, -8905.7099609375, 1027.75, 134.739501953125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1643, 180415, 0, 1519, 5154, '0', 0, 0, -8997.7197265625, 963.25701904296875, 116.5999984741210937, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1644, 180415, 0, 1519, 5154, '0', 0, 0, -8992.830078125, 963.73101806640625, 116.417999267578125, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1645, 180415, 0, 1519, 5154, '0', 0, 0, -8994.66015625, 963.60601806640625, 116.4940032958984375, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1646, 180415, 0, 1519, 5154, '0', 0, 0, -8999.240234375, 962.739990234375, 116.6309967041015625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1647, 180415, 0, 1519, 5154, '0', 0, 0, -9000.7802734375, 961.77099609375, 116.5970001220703125, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1648, 180415, 0, 1519, 5154, '0', 0, 0, -8891.3095703125, 1024.8697509765625, 142.6809539794921875, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1649, 180415, 0, 1519, 5154, '0', 0, 0, -9008.01953125, 954.56097412109375, 116.5250015258789062, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1650, 180415, 0, 1519, 5154, '0', 0, 0, -9010.0302734375, 951.27099609375, 116.5780029296875, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1651, 180415, 0, 1519, 5154, '0', 0, 0, -9009.16015625, 952.98101806640625, 116.5540008544921875, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1652, 180415, 0, 1519, 5154, '0', 0, 0, -9005.419921875, 958.11798095703125, 116.5530014038085937, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1653, 180415, 0, 1519, 5154, '0', 0, 0, -9006.759765625, 956.2760009765625, 116.5770034790039062, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1654, 180415, 0, 1519, 5154, '0', 0, 0, -9004.0400390625, 959.48297119140625, 116.589996337890625, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+1655, 180415, 0, 1519, 4411, '0', 0, 0, -8561.2666015625, 1124.2620849609375, 19.7376861572265625, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1656, 180415, 0, 1519, 4411, '0', 0, 0, -8534.064453125, 1126.33837890625, 19.62818336486816406, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1657, 180415, 0, 1519, 4411, '0', 0, 0, -8535.8505859375, 1126.2786865234375, 19.5198516845703125, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1658, 180415, 0, 1519, 4411, '0', 0, 0, -8514.33203125, 1113.611572265625, 19.36572265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1659, 180415, 0, 1519, 4411, '0', 0, 0, -8557.478515625, 1126.050537109375, 19.85025215148925781, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1660, 180415, 0, 1519, 4411, '0', 0, 0, -8559.73046875, 1125.7939453125, 19.77348899841308593, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1661, 180415, 0, 1519, 4411, '0', 0, 0, -8531.96484375, 1126.33837890625, 19.68105316162109375, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1662, 180415, 0, 1519, 4411, '0', 0, 0, -8514.609375, 1115.791015625, 19.38722419738769531, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1663, 180415, 0, 1519, 4411, '0', 0, 0, -8514.6552734375, 1118.0826416015625, 19.45361518859863281, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1664, 180415, 0, 1519, 4411, '0', 0, 0, -8527.58203125, 1126.3035888671875, 19.66450691223144531, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1665, 180415, 0, 1519, 4411, '0', 0, 0, -8514.8896484375, 1123.810546875, 19.16261863708496093, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1666, 180415, 0, 1519, 4411, '0', 0, 0, -8514.689453125, 1120.439697265625, 19.28572654724121093, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1667, 180415, 0, 1519, 4411, '0', 0, 0, -8529.8095703125, 1126.466552734375, 19.73398399353027343, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1668, 180415, 0, 1519, 4411, '0', 0, 0, -8459.03515625, 1090.5859375, 20.138763427734375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1669, 180415, 0, 1519, 4411, '0', 0, 0, -8456.412109375, 1088.28515625, 20.09352302551269531, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1670, 180415, 0, 1519, 4411, '0', 0, 0, -8487.974609375, 1114.8248291015625, 19.56627082824707031, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1671, 180415, 0, 1519, 4411, '0', 0, 0, -8454.4189453125, 1088.393310546875, 20.10154914855957031, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1672, 180415, 0, 1519, 4411, '0', 0, 0, -8458.7177734375, 1088.2745361328125, 20.13652420043945312, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1673, 180415, 0, 1519, 4411, '0', 0, 0, -8452.16015625, 1088.3062744140625, 20.14149856567382812, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1674, 180415, 0, 1519, 4411, '0', 0, 0, -8445.8779296875, 1088.15673828125, 20.1173858642578125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1675, 180415, 0, 1519, 4411, '0', 0, 0, -8429.73828125, 1089.32421875, 20.14235877990722656, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1676, 180415, 0, 1519, 4411, '0', 0, 0, -8447.873046875, 1088.3585205078125, 20.14618873596191406, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1677, 180415, 0, 1519, 4411, '0', 0, 0, -8450.0966796875, 1088.322265625, 20.10743141174316406, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1678, 180415, 0, 1519, 4411, '0', 0, 0, -8413.8876953125, 1090.1822509765625, 20.21195411682128906, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1679, 180415, 0, 1519, 4411, '0', 0, 0, -8427.9345703125, 1089.280517578125, 20.13240814208984375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1680, 180415, 0, 1519, 4411, '0', 0, 0, -8425.740234375, 1089.363037109375, 20.08494186401367187, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1681, 180415, 0, 1519, 4411, '0', 0, 0, -8414.0361328125, 1092.43408203125, 20.07137680053710937, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1682, 180415, 0, 1519, 4411, '0', 0, 0, -8423.6103515625, 1089.4246826171875, 20.14505767822265625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1683, 180415, 0, 1519, 4411, '0', 0, 0, -8421.359375, 1089.431396484375, 20.109619140625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1684, 180415, 0, 1519, 4411, '0', 0, 0, -8416.1826171875, 1089.935791015625, 20.26366615295410156, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1685, 180415, 0, 1519, 4411, '0', 0, 0, -8436.6904296875, 1129.4154052734375, 20.0018768310546875, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1686, 180415, 0, 1519, 4411, '0', 0, 0, -8428.330078125, 1129.2664794921875, 19.96050643920898437, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1687, 180415, 0, 1519, 4411, '0', 0, 0, -8379.1162109375, 1111.4791259765625, 19.79901504516601562, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1688, 180415, 0, 1519, 4411, '0', 0, 0, -8412.576171875, 1128.87890625, 19.87590980529785156, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1689, 180415, 0, 1519, 4411, '0', 0, 0, -8412.5009765625, 1126.8515625, 19.87930870056152343, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1690, 180415, 0, 1519, 4411, '0', 0, 0, -8450.3876953125, 1128.7747802734375, 19.97925758361816406, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1691, 180415, 0, 1519, 4411, '0', 0, 0, -8452.515625, 1128.9366455078125, 19.96131134033203125, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1692, 180415, 0, 1519, 4411, '0', 0, 0, -8430.595703125, 1129.412353515625, 20.01185035705566406, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1693, 180415, 0, 1519, 4411, '0', 0, 0, -8379.0673828125, 1113.6788330078125, 19.98053932189941406, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1694, 180415, 0, 1519, 4411, '0', 0, 0, -8432.619140625, 1129.362060546875, 19.96075630187988281, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1695, 180415, 0, 1519, 4411, '0', 0, 0, -8414.7822265625, 1129.093994140625, 19.97401237487792968, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1696, 180415, 0, 1519, 4411, '0', 0, 0, -8448.203125, 1129.0279541015625, 19.96889495849609375, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1697, 180415, 0, 1519, 4411, '0', 0, 0, -8379.0087890625, 1119.9068603515625, 20.09073066711425781, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1698, 180415, 0, 1519, 4411, '0', 0, 0, -8454.7822265625, 1128.9405517578125, 20.0008392333984375, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1699, 180415, 0, 1519, 4411, '0', 0, 0, -8379, 1115.7691650390625, 19.94405555725097656, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1700, 180415, 0, 1519, 4411, '0', 0, 0, -8434.8076171875, 1129.2977294921875, 20.00479507446289062, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1701, 180415, 0, 1519, 4411, '0', 0, 0, -8379.060546875, 1117.957763671875, 20.06096649169921875, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1702, 180415, 0, 1519, 4411, '0', 0, 0, -8456.59765625, 1129, 19.97743606567382812, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1703, 180415, 0, 1519, 4411, '0', 0, 0, -8462.9111328125, 1128.8966064453125, 19.99684333801269531, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1704, 180415, 0, 1519, 4411, '0', 0, 0, -8443.3515625, 1142.1068115234375, 20.00641059875488281, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1705, 180415, 0, 1519, 4411, '0', 0, 0, -8377.8408203125, 1127.859130859375, 19.92161178588867187, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1706, 180415, 0, 1519, 4411, '0', 0, 0, -8427.2763671875, 1146.6236572265625, 19.86591148376464843, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1707, 180415, 0, 1519, 4411, '0', 0, 0, -8427.982421875, 1144.5875244140625, 20.0165557861328125, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1708, 180415, 0, 1519, 4411, '0', 0, 0, -8350.595703125, 1129.59765625, 19.78011322021484375, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1709, 180415, 0, 1519, 4411, '0', 0, 0, -8465.0986328125, 1129.0948486328125, 19.96479034423828125, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1710, 180415, 0, 1519, 4411, '0', 0, 0, -8441.1025390625, 1141.9049072265625, 19.95985031127929687, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1711, 180415, 0, 1519, 4411, '0', 0, 0, -8430.3291015625, 1143.9752197265625, 20.19532966613769531, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1712, 180415, 0, 1519, 4411, '0', 0, 0, -8377.7080078125, 1130.1297607421875, 19.72336578369140625, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1713, 180415, 0, 1519, 4411, '0', 0, 0, -8375.6015625, 1130.2803955078125, 19.74116706848144531, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1714, 180415, 0, 1519, 4411, '0', 0, 0, -8352.8076171875, 1129.61572265625, 19.83290863037109375, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1715, 180415, 0, 1519, 4411, '0', 0, 0, -8354.681640625, 1129.6607666015625, 19.78548622131347656, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1716, 180415, 0, 1519, 4411, '0', 0, 0, -8467.125, 1129.186767578125, 19.90551185607910156, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1717, 180415, 0, 1519, 4411, '0', 0, 0, -8469.4365234375, 1129.228759765625, 19.98625564575195312, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1718, 180415, 0, 1519, 4411, '0', 0, 0, -8445.5, 1142.2144775390625, 19.96640396118164062, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1719, 180415, 0, 1519, 4411, '0', 0, 0, -8348.5712890625, 1129.3951416015625, 19.82221412658691406, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1720, 180415, 0, 1519, 4411, '0', 0, 0, -8346.2880859375, 1129.3489990234375, 19.78516578674316406, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1721, 180415, 0, 1519, 4411, '0', 0, 0, -8307.951171875, 1155.4976806640625, 19.56041908264160156, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1722, 180415, 0, 1519, 4411, '0', 0, 0, -8309.3994140625, 1127.38525390625, 20.1759033203125, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1723, 180415, 0, 1519, 4411, '0', 0, 0, -8351.9931640625, 1157.3489990234375, 19.868896484375, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1724, 180415, 0, 1519, 4411, '0', 0, 0, -8351.849609375, 1153.1514892578125, 20.03406715393066406, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1725, 180415, 0, 1519, 4411, '0', 0, 0, -8307.8486328125, 1148.9693603515625, 19.88795280456542968, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1726, 180415, 0, 1519, 4411, '0', 0, 0, -8349.4892578125, 1141.9139404296875, 20.16535568237304687, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1727, 180415, 0, 1519, 4411, '0', 0, 0, -8300.9169921875, 1127.0247802734375, 19.91248512268066406, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1728, 180415, 0, 1519, 4411, '0', 0, 0, -8298.4013671875, 1126.9132080078125, 20.01203155517578125, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1729, 180415, 0, 1519, 4411, '0', 0, 0, -8307.8623046875, 1153.216796875, 19.71404075622558593, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1730, 180415, 0, 1519, 4411, '0', 0, 0, -8307.826171875, 1151.4073486328125, 19.86797332763671875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1731, 180415, 0, 1519, 4411, '0', 0, 0, -8307.4521484375, 1127.1904296875, 20.01272201538085937, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1732, 180415, 0, 1519, 4411, '0', 0, 0, -8307.98828125, 1159.784423828125, 19.2546844482421875, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1733, 180415, 0, 1519, 4411, '0', 0, 0, -8307.98046875, 1157.5421142578125, 19.52761268615722656, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1734, 180415, 0, 1519, 4411, '0', 0, 0, -8352.02734375, 1159.6282958984375, 19.91952896118164062, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1735, 180415, 0, 1519, 4411, '0', 0, 0, -8352.05859375, 1155.3834228515625, 19.99600791931152343, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1736, 180415, 0, 1519, 4411, '0', 0, 0, -8351.64453125, 1148.9635009765625, 20.0665130615234375, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1737, 180415, 0, 1519, 4411, '0', 0, 0, -8351.923828125, 1151.301025390625, 20.04386329650878906, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1738, 180415, 0, 1519, 4411, '0', 0, 0, -8296.1962890625, 1126.8697509765625, 20.15884017944335937, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1739, 180415, 0, 1519, 4411, '0', 0, 0, -8296.0048828125, 1124.651123046875, 20.07935333251953125, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1740, 180415, 0, 1519, 4411, '0', 0, 0, -8351.8564453125, 1144.1470947265625, 20.20614433288574218, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1741, 180415, 0, 1519, 4411, '0', 0, 0, -8305.267578125, 1127.15673828125, 19.99942398071289062, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1742, 180415, 0, 1519, 4411, '0', 0, 0, -8351.6826171875, 1141.8489990234375, 19.82120895385742187, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1743, 180415, 0, 1519, 4411, '0', 0, 0, -8303.193359375, 1126.974365234375, 19.97508811950683593, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1744, 180415, 0, 1519, 4411, '0', 0, 0, -8286.4208984375, 1153.3597412109375, 19.69989013671875, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1745, 180415, 0, 1519, 4411, '0', 0, 0, -8286.4794921875, 1151.5035400390625, 19.74312210083007812, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1746, 180415, 0, 1519, 4411, '0', 0, 0, -8286.3076171875, 1159.859619140625, 19.758941650390625, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1747, 180415, 0, 1519, 4411, '0', 0, 0, -8286.3876953125, 1157.6243896484375, 19.65444374084472656, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1748, 180415, 0, 1519, 4411, '0', 0, 0, -8286.462890625, 1155.5535888671875, 19.65576171875, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1749, 180415, 0, 1519, 4411, '0', 0, 0, -8041.8291015625, 1620.920166015625, 4.344945907592773437, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1750, 180415, 0, 1519, 4411, '0', 0, 0, -8042.5537109375, 1620.066162109375, 4.330189228057861328, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1751, 180415, 0, 1519, 4411, '0', 0, 0, -8040.4443359375, 1618.2147216796875, 4.020081043243408203, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1752, 180415, 0, 1519, 4411, '0', 0, 0, -8040.01806640625, 1622.7818603515625, 4.353181838989257812, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1753, 180415, 0, 1519, 4411, '0', 0, 0, -8038.015625, 1621.0355224609375, 4.268586158752441406, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1754, 180415, 0, 1519, 4411, '0', 0, 0, -8039.03466796875, 1621.9495849609375, 4.3162841796875, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1755, 180415, 0, 1519, 4411, '0', 0, 0, -8041.58251953125, 1619.1734619140625, 4.147182941436767578, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1756, 180415, 0, 1519, 4411, '0', 0, 0, -8040.91162109375, 1621.83642578125, 4.348523139953613281, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1757, 180415, 0, 1519, 4411, '0', 0, 0, -8038.87353515625, 1620.07080078125, 4.199732780456542968, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1758, 180415, 0, 1519, 4411, '0', 0, 0, -8039.74853515625, 1619.0401611328125, 4.107827186584472656, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1759, 180415, 0, 1519, 4411, '0', 0, 0, -8334.0595703125, 1192.359375, 6.706246852874755859, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1760, 180415, 0, 1519, 4411, '0', 0, 0, -8449.5947265625, 1142.3333740234375, 19.97266578674316406, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1761, 180415, 0, 1519, 4411, '0', 0, 0, -8456.357421875, 1142.0032958984375, 20.16004753112792968, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1762, 180415, 0, 1519, 4411, '0', 0, 0, -8447.693359375, 1142.0792236328125, 20.00888252258300781, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1763, 180415, 0, 1519, 4411, '0', 0, 0, -8458.1708984375, 1142.0889892578125, 20.05169486999511718, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1764, 180415, 0, 1519, 4411, '0', 0, 0, -8471.3564453125, 1129.3631591796875, 19.97810554504394531, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1765, 180415, 0, 1519, 4411, '0', 0, 0, -8468.0234375, 1145.2918701171875, 19.63709831237792968, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1766, 180415, 0, 1519, 4411, '0', 0, 0, -8480.435546875, 1129.0853271484375, 19.85925102233886718, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1767, 180415, 0, 1519, 4411, '0', 0, 0, -8460.359375, 1142.0692138671875, 19.98189163208007812, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1768, 180415, 0, 1519, 4411, '0', 0, 0, -8462.4345703125, 1142.29541015625, 19.793914794921875, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1769, 180415, 0, 1519, 4411, '0', 0, 0, -8467.9892578125, 1151.7840576171875, 19.57544898986816406, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1770, 180415, 0, 1519, 4411, '0', 0, 0, -8464.658203125, 1142.3450927734375, 19.73567390441894531, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1771, 180415, 0, 1519, 4411, '0', 0, 0, -8467.8173828125, 1149.5826416015625, 19.76023292541503906, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1772, 180415, 0, 1519, 4411, '0', 0, 0, -8467.8779296875, 1147.5927734375, 19.78599357604980468, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1773, 180415, 0, 1519, 4411, '0', 0, 0, -8478.2001953125, 1129.2723388671875, 19.76607322692871093, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1774, 180415, 0, 1519, 4411, '0', 0, 0, -8482.5107421875, 1129.1572265625, 20.07769203186035156, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1775, 180415, 0, 1519, 4411, '0', 0, 0, -8496.501953125, 1148.4093017578125, 19.74759674072265625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1776, 180415, 0, 1519, 4411, '0', 0, 0, -8487.8505859375, 1119.2066650390625, 19.78320884704589843, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1777, 180415, 0, 1519, 4411, '0', 0, 0, -8487.5361328125, 1123.3951416015625, 19.72113990783691406, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1778, 180415, 0, 1519, 4411, '0', 0, 0, -8498.0986328125, 1141.2545166015625, 19.58205986022949218, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1779, 180415, 0, 1519, 4411, '0', 0, 0, -8496.455078125, 1144.2691650390625, 19.63583183288574218, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1780, 180415, 0, 1519, 4411, '0', 0, 0, -8496.5341796875, 1146.4068603515625, 19.73383522033691406, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1781, 180415, 0, 1519, 4411, '0', 0, 0, -8487.8623046875, 1116.9036865234375, 19.66290092468261718, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1782, 180415, 0, 1519, 4411, '0', 0, 0, -8487.7080078125, 1121.25, 19.84128952026367187, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1783, 180415, 0, 1519, 4411, '0', 0, 0, -8484.6455078125, 1129.164306640625, 19.61669349670410156, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1784, 180415, 0, 1519, 4411, '0', 0, 0, -8517.4150390625, 1125.883056640625, 19.17713165283203125, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1785, 180415, 0, 1519, 4411, '0', 0, 0, -8496.6748046875, 1152.4969482421875, 19.63500404357910156, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1786, 180415, 0, 1519, 4411, '0', 0, 0, -8500.345703125, 1141.2281494140625, 19.78377151489257812, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1787, 180415, 0, 1519, 4411, '0', 0, 0, -8515.0830078125, 1125.90673828125, 19.07520484924316406, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1788, 180415, 0, 1519, 4411, '0', 0, 0, -8502.34765625, 1141.2393798828125, 19.83345985412597656, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1789, 180415, 0, 1519, 4411, '0', 0, 0, -8504.5517578125, 1141.083984375, 19.88371658325195312, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1790, 180415, 0, 1519, 4411, '0', 0, 0, -8496.7392578125, 1150.6639404296875, 19.67436027526855468, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1791, 180415, 0, 1519, 4411, '0', 0, 0, -8552.3232421875, 1142.927490234375, 19.86188888549804687, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1792, 180415, 0, 1519, 4411, '0', 0, 0, -8550.169921875, 1142.989990234375, 20.04150009155273437, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1793, 180415, 0, 1519, 4411, '0', 0, 0, -8548.2998046875, 1142.77001953125, 20.07180023193359375, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1794, 180415, 0, 1519, 4411, '0', 0, 0, -8554.33984375, 1143.010009765625, 19.98299980163574218, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1795, 180415, 0, 1519, 4411, '0', 0, 0, -8560.419921875, 1152.7247314453125, 19.64844703674316406, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1796, 180415, 0, 1519, 4411, '0', 0, 0, -8560.29296875, 1150.50341796875, 19.60041236877441406, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1797, 180415, 0, 1519, 4411, '0', 0, 0, -8560.2021484375, 1148.320068359375, 19.6298065185546875, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1798, 180415, 0, 1519, 4411, '0', 0, 0, -8556.6259765625, 1143.1024169921875, 19.76190376281738281, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1799, 180415, 0, 1519, 4411, '0', 0, 0, -8559.98046875, 1146.19921875, 19.47005653381347656, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- CandleBlack01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1800, 180425, 0, 1519, 1617, '0', 0, 0, -8906.5498046875, 620.364990234375, 100.7139968872070312, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1801, 180425, 0, 1519, 1617, '0', 0, 0, -8901.259765625, 623.25701904296875, 100.7139968872070312, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1802, 180425, 0, 1519, 1617, '0', 0, 0, -8904.0703125, 621.72698974609375, 100.7139968872070312, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1803, 180425, 0, 1519, 1617, '0', 0, 0, -8893.6103515625, 627.39898681640625, 100.7139968872070312, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1804, 180425, 0, 1519, 1617, '0', 0, 0, -8898.7998046875, 624.5830078125, 100.7139968872070312, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1805, 180425, 0, 1519, 1617, '0', 0, 0, -8896.0498046875, 626.0419921875, 100.7139968872070312, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1806, 180425, 0, 1519, 1617, '0', 0, 0, -8911.16015625, 634.69598388671875, 100.7139968872070312, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1807, 180425, 0, 1519, 1617, '0', 0, 0, -8913.509765625, 633.40997314453125, 100.7139968872070312, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1808, 180425, 0, 1519, 1617, '0', 0, 0, -8908.240234375, 636.21002197265625, 100.7139968872070312, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+1809, 180425, 0, 1519, 5148, '0', 0, 0, -8808.9501953125, 645.88397216796875, 96.07700347900390625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1810, 180425, 0, 1519, 5148, '0', 0, 0, -8859.23046875, 644.739990234375, 97.14959716796875, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1811, 180425, 0, 1519, 5148, '0', 0, 0, -8857.6904296875, 644.7860107421875, 97.16320037841796875, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1812, 180425, 0, 1519, 5148, '0', 0, 0, -8858.48046875, 646.42901611328125, 99.136199951171875, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1813, 180425, 0, 1519, 5148, '0', 0, 0, -8860.9501953125, 644.7659912109375, 97.13919830322265625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1814, 180425, 0, 1519, 5148, '0', 0, 0, -8855.4501953125, 648.8330078125, 97.1923980712890625, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1815, 180425, 0, 1519, 5148, '0', 0, 0, -8860.0703125, 647.135009765625, 100.7389984130859375, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1816, 180425, 0, 1519, 5148, '0', 0, 0, -8857.830078125, 648.05401611328125, 100.7679977416992187, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1817, 180425, 0, 1519, 5148, '0', 0, 0, -8863.25, 647.0260009765625, 97.0792999267578125, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1818, 180425, 0, 1519, 5148, '0', 0, 0, -8857.150390625, 647.7919921875, 99.16860198974609375, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1819, 180425, 0, 1519, 5148, '0', 0, 0, -8862.1796875, 645.96502685546875, 97.110198974609375, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1820, 180425, 0, 1519, 5148, '0', 0, 0, -8858.8095703125, 647.12701416015625, 100.759002685546875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1821, 180425, 0, 1519, 5148, '0', 0, 0, -8861.669921875, 647.77398681640625, 99.0941009521484375, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1822, 180425, 0, 1519, 5148, '0', 0, 0, -8856.5498046875, 645.92498779296875, 97.1808013916015625, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1823, 180425, 0, 1519, 5148, '0', 0, 0, -8855.4501953125, 647.0989990234375, 97.203399658203125, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1824, 180425, 0, 1519, 5148, '0', 0, 0, -8860.3603515625, 646.43902587890625, 99.1260986328125, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1825, 180425, 0, 1519, 5148, '0', 0, 0, -8861.009765625, 648.0830078125, 100.71600341796875, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1826, 180425, 0, 1519, 5148, '0', 0, 0, -8863.2900390625, 648.73297119140625, 97.0635986328125, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1827, 180425, 0, 1519, 5148, '0', 0, 0, -8861.01953125, 649.34698486328125, 100.7060012817382812, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1828, 180425, 0, 1519, 5148, '0', 0, 0, -8861.66015625, 649.61297607421875, 99.0800018310546875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1829, 180425, 0, 1519, 5148, '0', 0, 0, -8856.6103515625, 651.47100830078125, 97.15350341796875, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1830, 180425, 0, 1519, 5148, '0', 0, 0, -8858.48046875, 650.97601318359375, 99.12220001220703125, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1831, 180425, 0, 1519, 5148, '0', 0, 0, -8857.1796875, 649.635009765625, 99.1537017822265625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1832, 180425, 0, 1519, 5148, '0', 0, 0, -8855.4794921875, 650.3367919921875, 97.18316650390625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1833, 180425, 0, 1519, 5148, '0', 0, 0, -8857.83984375, 649.36602783203125, 100.7580032348632812, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1834, 180425, 0, 1519, 5148, '0', 0, 0, -8858.7900390625, 650.3189697265625, 100.7350006103515625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1835, 180425, 0, 1519, 5148, '0', 0, 0, -8859.5595703125, 648.74102783203125, 103.9229965209960937, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1836, 180425, 0, 1519, 5148, '0', 0, 0, -8860.0595703125, 650.29498291015625, 100.7139968872070312, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1837, 180425, 0, 1519, 5148, '0', 0, 0, -8857.7099609375, 652.58502197265625, 97.119903564453125, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1838, 180425, 0, 1519, 5148, '0', 0, 0, -8861.0595703125, 652.5679931640625, 97.05930328369140625, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1839, 180425, 0, 1519, 5148, '0', 0, 0, -8859.330078125, 652.62799072265625, 97.0847015380859375, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1840, 180425, 0, 1519, 5148, '0', 0, 0, -8863.2900390625, 650.25299072265625, 97.05249786376953125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1841, 180425, 0, 1519, 5148, '0', 0, 0, -8862.1201171875, 651.50201416015625, 97.05210113525390625, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1842, 180425, 0, 1519, 5148, '0', 0, 0, -8860.330078125, 650.98797607421875, 99.09169769287109375, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1843, 180425, 0, 1519, 5148, '0', 0, 0, -8812.6298828125, 655.57501220703125, 100.875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1844, 180425, 0, 1519, 5148, '0', 0, 0, -8816.9404296875, 665.56298828125, 100.8649978637695312, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1845, 180425, 0, 1519, 5148, '0', 0, 0, -8808.669921875, 690.10101318359375, 101.983001708984375, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1846, 180425, 0, 1519, 5148, '0', 0, 0, -8856.123046875, 671.73748779296875, 98.875274658203125, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1847, 180425, 0, 1519, 5148, '0', 0, 0, -8900.650390625, 640.31597900390625, 100.7139968872070312, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1848, 180425, 0, 1519, 5148, '0', 0, 0, -8905.76953125, 637.56298828125, 100.7139968872070312, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1849, 180425, 0, 1519, 5148, '0', 0, 0, -8903.1103515625, 639.02398681640625, 100.7139968872070312, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1850, 180425, 0, 1519, 5148, '0', 0, 0, -8866.1396484375, 680.926513671875, 99.062774658203125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1851, 180425, 0, 1519, 5148, '0', 0, 0, -8679.5302734375, 501.25299072265625, 100.259002685546875, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1852, 180425, 0, 1519, 5148, '0', 0, 0, -8709.9697265625, 467.4739990234375, 99.42099761962890625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1853, 180425, 0, 1519, 5148, '0', 0, 0, -8687.5400390625, 494.90301513671875, 100.2610015869140625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1854, 180425, 0, 1519, 5148, '0', 0, 0, -8708.5400390625, 468.531005859375, 99.42099761962890625, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1855, 180425, 0, 1519, 5148, '0', 0, 0, -8685.98046875, 496.154998779296875, 100.2610015869140625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1856, 180425, 0, 1519, 5148, '0', 0, 0, -8711.26953125, 466.235992431640625, 99.42099761962890625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- SkullCandle01 (Area: Trade District - Difficulty: 0)
(@OGUID+1857, 180425, 0, 1519, 5390, '0', 0, 0, -8735.9404296875, 448.364990234375, 101.0250015258789062, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1858, 180425, 0, 1519, 5390, '0', 0, 0, -8735.41015625, 450.285003662109375, 101.0630035400390625, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1859, 180425, 0, 1519, 5390, '0', 0, 0, -8735.490234375, 439.186004638671875, 101.0029983520507812, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1860, 180425, 0, 1519, 5390, '0', 0, 0, -8735.6796875, 440.9530029296875, 100.9879989624023437, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1861, 180425, 0, 1519, 5390, '0', 0, 0, -8743.4404296875, 419.3280029296875, 101.7900009155273437, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1862, 180425, 0, 1519, 5390, '0', 0, 0, -8710.2802734375, 436.57501220703125, 102.0459976196289062, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1863, 180425, 0, 1519, 5390, '0', 0, 0, -8749.8095703125, 414.186004638671875, 101.7809982299804687, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1864, 180425, 0, 1519, 5390, '0', 0, 0, -8748.3701171875, 415.365997314453125, 101.785003662109375, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1865, 180425, 0, 1519, 5390, '0', 0, 0, -8746.7900390625, 416.6510009765625, 101.78900146484375, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1866, 180425, 0, 1519, 5390, '0', 0, 0, -8745.08984375, 418.02099609375, 101.7900009155273437, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1867, 180425, 0, 1519, 5390, '0', 0, 0, -8718.8603515625, 419.589996337890625, 99.05999755859375, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1868, 180425, 0, 1519, 5390, '0', 0, 0, -8721.8603515625, 417.1090087890625, 98.91539764404296875, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1869, 180425, 0, 1519, 5390, '0', 0, 0, -8711.490234375, 430.196014404296875, 102.0510025024414062, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1870, 180425, 0, 1519, 5390, '0', 0, 0, -8711.099609375, 432.269012451171875, 102.0490036010742187, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1871, 180425, 0, 1519, 5390, '0', 0, 0, -8712.3798828125, 426.196014404296875, 102.0469970703125, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1872, 180425, 0, 1519, 5390, '0', 0, 0, -8710.7099609375, 434.32598876953125, 102.0479965209960937, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1873, 180425, 0, 1519, 5390, '0', 0, 0, -8711.900390625, 428.191009521484375, 102.0510025024414062, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1874, 180425, 0, 1519, 5390, '0', 0, 0, -8720.4296875, 418.319000244140625, 98.97840118408203125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1875, 180425, 0, 1519, 5390, '0', 0, 0, -8722.0498046875, 415.1719970703125, 98.854400634765625, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1876, 180425, 0, 1519, 5390, '0', 0, 0, -8719.990234375, 416.014007568359375, 101.3509979248046875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1877, 180425, 0, 1519, 5390, '0', 0, 0, -8716.8603515625, 419.406005859375, 99.12129974365234375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1878, 180425, 0, 1519, 5390, '0', 0, 0, -8718.3095703125, 417.490997314453125, 101.4430007934570312, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1879, 180425, 0, 1519, 5390, '0', 0, 0, -8716.01953125, 417.269012451171875, 101.5029983520507812, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1880, 180425, 0, 1519, 5390, '0', 0, 0, -8717.51953125, 414.412994384765625, 107.0630035400390625, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1881, 180425, 0, 1519, 5390, '0', 0, 0, -8715.4599609375, 415.12200927734375, 103.430999755859375, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1882, 180425, 0, 1519, 5390, '0', 0, 0, -8716.5595703125, 416.4320068359375, 103.4359970092773437, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1883, 180425, 0, 1519, 5390, '0', 0, 0, -8713.669921875, 417.704986572265625, 99.15779876708984375, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1884, 180425, 0, 1519, 5390, '0', 0, 0, -8714.919921875, 419.2239990234375, 99.15940093994140625, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1885, 180425, 0, 1519, 5390, '0', 0, 0, -8719.51953125, 414.02801513671875, 103.2819976806640625, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1886, 180425, 0, 1519, 5390, '0', 0, 0, -8718.4501953125, 412.683990478515625, 103.2750015258789062, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1887, 180425, 0, 1519, 5390, '0', 0, 0, -8718.8095703125, 412.006988525390625, 101.272003173828125, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1888, 180425, 0, 1519, 5390, '0', 0, 0, -8720.25, 413.764007568359375, 101.279998779296875, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1889, 180425, 0, 1519, 5390, '0', 0, 0, -8721.0400390625, 411.707000732421875, 98.78790283203125, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1890, 180425, 0, 1519, 5390, '0', 0, 0, -8714.5595703125, 415.488006591796875, 101.4950027465820312, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1891, 180425, 0, 1519, 5390, '0', 0, 0, -8717.990234375, 416.540008544921875, 103.3980026245117187, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1892, 180425, 0, 1519, 5390, '0', 0, 0, -8716.9404296875, 412.552001953125, 103.31500244140625, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1893, 180425, 0, 1519, 5390, '0', 0, 0, -8715.599609375, 413.608001708984375, 103.384002685546875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1894, 180425, 0, 1519, 5390, '0', 0, 0, -8712.4404296875, 416.156005859375, 99.1623992919921875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1895, 180425, 0, 1519, 5390, '0', 0, 0, -8719.2900390625, 415.511993408203125, 103.3310012817382812, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1896, 180425, 0, 1519, 5390, '0', 0, 0, -8714.83984375, 413.2139892578125, 101.4219970703125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1897, 180425, 0, 1519, 5390, '0', 0, 0, -8716.580078125, 411.811004638671875, 101.31500244140625, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1898, 180425, 0, 1519, 5390, '0', 0, 0, -8722.2900390625, 413.2139892578125, 98.7758026123046875, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1899, 180425, 0, 1519, 5390, '0', 0, 0, -8719.849609375, 410.1719970703125, 98.75299835205078125, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1900, 180425, 0, 1519, 5390, '0', 0, 0, -8695.76953125, 436.2659912109375, 103.4619979858398437, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1901, 180425, 0, 1519, 5390, '0', 0, 0, -8714.1796875, 411.118011474609375, 98.95749664306640625, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1902, 180425, 0, 1519, 5390, '0', 0, 0, -8712.83984375, 412.238006591796875, 99.040802001953125, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1903, 180425, 0, 1519, 5390, '0', 0, 0, -8694.0400390625, 437.436004638671875, 103.477996826171875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1904, 180425, 0, 1519, 5390, '0', 0, 0, -8717.8701171875, 409.941009521484375, 98.81099700927734375, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1905, 180425, 0, 1519, 5390, '0', 0, 0, -8712.599609375, 414.32598876953125, 99.09960174560546875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1906, 180425, 0, 1519, 5390, '0', 0, 0, -8697.6396484375, 434.816009521484375, 103.4670028686523437, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1907, 180425, 0, 1519, 5390, '0', 0, 0, -8715.8798828125, 409.7340087890625, 98.85009765625, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1908, 180425, 0, 1519, 5390, '0', 0, 0, -8692.16015625, 438.834991455078125, 103.4850006103515625, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1909, 180425, 0, 1519, 5390, '0', 0, 0, -8672.0498046875, 485.302001953125, 101.4020004272460937, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1910, 180425, 0, 1519, 5390, '0', 0, 0, -8680.8896484375, 460.62200927734375, 104.352996826171875, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1911, 180425, 0, 1519, 5390, '0', 0, 0, -8677.23046875, 463.566009521484375, 104.3590011596679687, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1912, 180425, 0, 1519, 5390, '0', 0, 0, -8674.8798828125, 483.165008544921875, 101.4020004272460937, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1913, 180425, 0, 1519, 5390, '0', 0, 0, -8689.5703125, 435.739990234375, 103.4449996948242187, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1914, 180425, 0, 1519, 5390, '0', 0, 0, -8682.650390625, 459.1719970703125, 104.3440017700195312, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1915, 180425, 0, 1519, 5390, '0', 0, 0, -8684.3603515625, 457.834991455078125, 104.3470001220703125, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1916, 180425, 0, 1519, 5390, '0', 0, 0, -8673.3798828125, 484.302001953125, 101.4020004272460937, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1917, 180425, 0, 1519, 5390, '0', 0, 0, -8690.990234375, 437.531005859375, 103.4580001831054687, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1918, 180425, 0, 1519, 5390, '0', 0, 0, -8679.2001953125, 461.9840087890625, 104.3560028076171875, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1919, 180425, 0, 1519, 5390, '0', 0, 0, -8725.51953125, 394.592010498046875, 102.1299972534179687, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1920, 180425, 0, 1519, 5390, '0', 0, 0, -8726.7001953125, 393.239990234375, 102.1259994506835937, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1921, 180425, 0, 1519, 5390, '0', 0, 0, -8727.9697265625, 391.5989990234375, 102.1309967041015625, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1922, 180425, 0, 1519, 5390, '0', 0, 0, -8691.1796875, 409.9169921875, 104.3799972534179687, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1923, 180425, 0, 1519, 5390, '0', 0, 0, -8674.83984375, 437.697998046875, 101.1100006103515625, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1924, 180425, 0, 1519, 5390, '0', 0, 0, -8673.509765625, 438.743011474609375, 101.1100006103515625, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1925, 180425, 0, 1519, 5390, '0', 0, 0, -8729.33984375, 389.95001220703125, 102.1299972534179687, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1926, 180425, 0, 1519, 5390, '0', 0, 0, -8724.0703125, 393.363006591796875, 102.134002685546875, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1927, 180425, 0, 1519, 5390, '0', 0, 0, -8693.51953125, 412.79901123046875, 104.3779983520507812, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1928, 180425, 0, 1519, 5390, '0', 0, 0, -8692.3798828125, 411.386993408203125, 104.3779983520507812, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1929, 180425, 0, 1519, 5390, '0', 0, 0, -8676.2802734375, 436.542999267578125, 101.1100006103515625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1930, 180425, 0, 1519, 5390, '0', 0, 0, -8656.490234375, 483.040008544921875, 105.8779983520507812, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1931, 180425, 0, 1519, 5390, '0', 0, 0, -8654.150390625, 480.0469970703125, 105.8870010375976562, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1932, 180425, 0, 1519, 5390, '0', 0, 0, -8649.9697265625, 474.805999755859375, 105.8830032348632812, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1933, 180425, 0, 1519, 5390, '0', 0, 0, -8652.0703125, 477.37200927734375, 105.8949966430664062, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1934, 180425, 0, 1519, 5390, '0', 0, 0, -8647.8203125, 472.135009765625, 105.8799972534179687, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1935, 180425, 0, 1519, 5390, '0', 0, 0, -8644.3095703125, 467.802001953125, 105.8679962158203125, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1936, 180425, 0, 1519, 5390, '0', 0, 0, -8645.9599609375, 469.7030029296875, 105.8929977416992187, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1937, 180425, 0, 1519, 5390, '0', 0, 0, -8650.0400390625, 447.212005615234375, 106.1090011596679687, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1938, 180425, 0, 1519, 5390, '0', 0, 0, -8647.849609375, 448.99700927734375, 106.1090011596679687, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1939, 180425, 0, 1519, 5390, '0', 0, 0, -8648.9599609375, 448.113006591796875, 106.1090011596679687, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1940, 180425, 0, 1519, 5390, '0', 0, 0, -8642.9501953125, 466.0260009765625, 105.8779983520507812, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1941, 180425, 0, 1519, 5390, '0', 0, 0, -8625.98046875, 462.89898681640625, 104.1240005493164062, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1942, 180425, 0, 1519, 5390, '0', 0, 0, -8626.2197265625, 448.944000244140625, 104.5419998168945312, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1943, 180425, 0, 1519, 5390, '0', 0, 0, -8626.259765625, 451.3280029296875, 104.2939987182617187, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1944, 180425, 0, 1519, 5390, '0', 0, 0, -8626.01953125, 460.803985595703125, 104.108001708984375, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1945, 180425, 0, 1519, 5390, '0', 0, 0, -8617.26953125, 446.865997314453125, 104.7139968872070312, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1946, 180425, 0, 1519, 5390, '0', 0, 0, -8625.3095703125, 446.657989501953125, 104.8130035400390625, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1947, 180425, 0, 1519, 5390, '0', 0, 0, -8610.9697265625, 447.12298583984375, 104.5839996337890625, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1948, 180425, 0, 1519, 5390, '0', 0, 0, -8620.2900390625, 446.555999755859375, 104.7679977416992187, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1949, 180425, 0, 1519, 5390, '0', 0, 0, -8607.66015625, 446.863006591796875, 104.5009994506835937, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1950, 180425, 0, 1519, 5390, '0', 0, 0, -8614.3603515625, 447.053985595703125, 104.6480026245117187, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1951, 180425, 0, 1519, 5390, '0', 0, 0, -8623.1298828125, 446.47900390625, 104.7990036010742187, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1952, 180425, 0, 1519, 5390, '0', 0, 0, -8617.73046875, 421.20001220703125, 104.8389968872070312, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1953, 180425, 0, 1519, 5390, '0', 0, 0, -8619.4599609375, 419.805999755859375, 104.839996337890625, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1954, 180425, 0, 1519, 5390, '0', 0, 0, -8620.7998046875, 418.709991455078125, 104.8649978637695312, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1955, 180425, 0, 1519, 5390, '0', 0, 0, -8622.1796875, 417.595001220703125, 104.839996337890625, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1956, 180425, 0, 1519, 5390, '0', 0, 0, -8616.0400390625, 422.532989501953125, 104.8239974975585937, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1957, 180425, 0, 1519, 5390, '0', 0, 0, -8604.8203125, 402.579986572265625, 111.3239974975585937, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1958, 180425, 0, 1519, 5390, '0', 0, 0, -8629.1796875, 412.375, 104.8649978637695312, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1959, 180425, 0, 1519, 5390, '0', 0, 0, -8630.6904296875, 411.06298828125, 104.832000732421875, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1960, 180425, 0, 1519, 5390, '0', 0, 0, -8632.5, 409.662994384765625, 104.84100341796875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1961, 180425, 0, 1519, 5390, '0', 0, 0, -8608.6904296875, 399.555999755859375, 111.3259963989257812, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1962, 180425, 0, 1519, 5390, '0', 0, 0, -8606.7001953125, 401.069000244140625, 111.3489990234375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1963, 180425, 0, 1519, 5390, '0', 0, 0, -8627.7197265625, 413.5830078125, 104.839996337890625, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1964, 180425, 0, 1519, 5390, '0', 0, 0, -8610.58984375, 398.0570068359375, 111.30999755859375, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1965, 180425, 0, 1519, 5390, '0', 0, 0, -8614.4599609375, 395.136993408203125, 111.2450027465820312, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1966, 180425, 0, 1519, 5390, '0', 0, 0, -8612.4296875, 396.579986572265625, 111.2979965209960937, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1967, 180425, 0, 1519, 5390, '0', 0, 0, -8616.3203125, 393.686004638671875, 111.2129974365234375, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+1968, 180425, 0, 1519, 0, '0', 0, 0, -8652.830078125, 405.4110107421875, 105.5419998168945312, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+1969, 180425, 0, 1519, 0, '0', 0, 0, -8651.259765625, 406.697998046875, 105.5670013427734375, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+1970, 180425, 0, 1519, 5149, '0', 0, 0, -8664.98046875, 394.60198974609375, 106.31500244140625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1971, 180425, 0, 1519, 5149, '0', 0, 0, -8685.8896484375, 403.207000732421875, 104.3769989013671875, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1972, 180425, 0, 1519, 5149, '0', 0, 0, -8663.830078125, 395.563995361328125, 106.31500244140625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1973, 180425, 0, 1519, 5149, '0', 0, 0, -8662.759765625, 396.553985595703125, 106.31500244140625, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1974, 180425, 0, 1519, 5149, '0', 0, 0, -8682.5400390625, 390.058990478515625, 105.6350021362304687, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1975, 180425, 0, 1519, 5149, '0', 0, 0, -8676.4697265625, 386.9320068359375, 104.8949966430664062, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1976, 180425, 0, 1519, 5149, '0', 0, 0, -8680.580078125, 389.037994384765625, 105.3980026245117187, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1977, 180425, 0, 1519, 5149, '0', 0, 0, -8678.76953125, 388.1199951171875, 105.1760025024414062, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1978, 180425, 0, 1519, 5149, '0', 0, 0, -8717.5595703125, 368.8179931640625, 104.5739974975585937, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1979, 180425, 0, 1519, 5149, '0', 0, 0, -8715.7802734375, 367.785003662109375, 104.5810012817382812, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1980, 180425, 0, 1519, 5149, '0', 0, 0, -8714.1298828125, 366.802001953125, 104.589996337890625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1981, 180425, 0, 1519, 5149, '0', 0, 0, -8727.6298828125, 375.0419921875, 104.5810012817382812, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1982, 180425, 0, 1519, 5149, '0', 0, 0, -8726.240234375, 374.214996337890625, 104.5839996337890625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1983, 180425, 0, 1519, 5149, '0', 0, 0, -8724.8095703125, 373.3699951171875, 104.5869979858398437, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1984, 180425, 0, 1519, 5149, '0', 0, 0, -8728.849609375, 375.77099609375, 104.5780029296875, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1985, 180425, 0, 1519, 5149, '0', 0, 0, -8730.1904296875, 376.579986572265625, 104.5879974365234375, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1986, 180425, 0, 1519, 5149, '0', 0, 0, -8712.2197265625, 344.625, 101.8310012817382812, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1987, 180425, 0, 1519, 5149, '0', 0, 0, -8712.169921875, 342.667999267578125, 101.8310012817382812, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1988, 180425, 0, 1519, 5149, '0', 0, 0, -8712.0400390625, 338.342010498046875, 101.8310012817382812, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1989, 180425, 0, 1519, 5149, '0', 0, 0, -8711.9501953125, 335.779998779296875, 101.8310012817382812, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1990, 180425, 0, 1519, 5149, '0', 0, 0, -8712.1201171875, 340.709991455078125, 101.8310012817382812, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1991, 180425, 0, 1519, 5149, '0', 0, 0, -8711.900390625, 333.436004638671875, 101.8310012817382812, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1992, 180425, 0, 1519, 5149, '0', 0, 0, -8722.1904296875, 320.7449951171875, 101.8310012817382812, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1993, 180425, 0, 1519, 5149, '0', 0, 0, -8724.7802734375, 320.438995361328125, 101.8310012817382812, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1994, 180425, 0, 1519, 5149, '0', 0, 0, -8729.6904296875, 319.3489990234375, 101.8310012817382812, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1995, 180425, 0, 1519, 5149, '0', 0, 0, -8727.4501953125, 319.9219970703125, 101.8310012817382812, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1996, 180425, 0, 1519, 5149, '0', 0, 0, -8731.8896484375, 318.832000732421875, 101.8310012817382812, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1997, 180425, 0, 1519, 5149, '0', 0, 0, -8736.76953125, 317.704986572265625, 101.8310012817382812, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1998, 180425, 0, 1519, 5149, '0', 0, 0, -8738.83984375, 317.162994384765625, 101.8310012817382812, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+1999, 180425, 0, 1519, 5149, '0', 0, 0, -8734.240234375, 318.239990234375, 101.8310012817382812, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2000, 180425, 0, 1519, 5149, '0', 0, 0, -8786.7900390625, 348.85101318359375, 109.0189971923828125, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2001, 180425, 0, 1519, 5149, '0', 0, 0, -8784.080078125, 344.8489990234375, 109.0189971923828125, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2002, 180425, 0, 1519, 5149, '0', 0, 0, -8784.2802734375, 341.54901123046875, 109.0189971923828125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2003, 180425, 0, 1519, 5149, '0', 0, 0, -8791.4296875, 350.029998779296875, 109.0189971923828125, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2004, 180425, 0, 1519, 5149, '0', 0, 0, -8793.91015625, 349.64801025390625, 109.0189971923828125, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2005, 180425, 0, 1519, 5149, '0', 0, 0, -8784.8798828125, 339.18798828125, 109.0189971923828125, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2006, 180425, 0, 1519, 5149, '0', 0, 0, -8787.0498046875, 336.360992431640625, 109.0189971923828125, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2007, 180425, 0, 1519, 5149, '0', 0, 0, -8788.9404296875, 349.720001220703125, 109.0189971923828125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- SkullCandle01 (Area: Old Town - Difficulty: 0)
(@OGUID+2008, 180425, 0, 1519, 5390, '0', 0, 0, -8616.5400390625, 698.78497314453125, 98.63800048828125, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2009, 180425, 0, 1519, 5390, '0', 0, 0, -8615.6796875, 698.66497802734375, 98.64550018310546875, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2010, 180425, 0, 1519, 5390, '0', 0, 0, -8483.5595703125, 372.9429931640625, 116.3369979858398437, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2011, 180425, 0, 1519, 5390, '0', 0, 0, -8484.4404296875, 369.4320068359375, 116.365997314453125, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2012, 180425, 0, 1519, 5390, '0', 0, 0, -8478.98046875, 378.92401123046875, 116.3479995727539062, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2013, 180425, 0, 1519, 5390, '0', 0, 0, -8475.349609375, 381.0159912109375, 116.3479995727539062, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2014, 180425, 0, 1519, 5390, '0', 0, 0, -8481.83984375, 375.92498779296875, 116.3280029296875, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2015, 180425, 0, 1519, 5390, '0', 0, 0, -8472.1796875, 381.9840087890625, 116.365997314453125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2016, 180425, 0, 1519, 5390, '0', 0, 0, -8468.5400390625, 382.131988525390625, 116.3499984741210937, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2017, 180425, 0, 1519, 5390, '0', 0, 0, -8465.0703125, 381.407989501953125, 116.358001708984375, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2018, 180425, 0, 1519, 5390, '0', 0, 0, -8484.51953125, 365.720001220703125, 116.3570022583007812, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2019, 180425, 0, 1519, 5390, '0', 0, 0, -8455.4404296875, 372.09698486328125, 137.251007080078125, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2020, 180425, 0, 1519, 5390, '0', 0, 0, -8474.259765625, 352.97601318359375, 137.2299957275390625, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2021, 180425, 0, 1519, 5390, '0', 0, 0, -8477.66015625, 354.394012451171875, 137.2169952392578125, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2022, 180425, 0, 1519, 5390, '0', 0, 0, -8461.490234375, 379.8590087890625, 116.3669967651367187, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2023, 180425, 0, 1519, 5390, '0', 0, 0, -8454.8203125, 368.5, 137.259002685546875, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2024, 180425, 0, 1519, 5390, '0', 0, 0, -8483.8896484375, 362.196014404296875, 116.365997314453125, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2025, 180425, 0, 1519, 5390, '0', 0, 0, -8455.759765625, 361.230987548828125, 137.233001708984375, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2026, 180425, 0, 1519, 5390, '0', 0, 0, -8470.5498046875, 352.22698974609375, 137.24200439453125, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2027, 180425, 0, 1519, 5390, '0', 0, 0, -8460.2099609375, 355.35101318359375, 137.2440032958984375, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2028, 180425, 0, 1519, 5390, '0', 0, 0, -8454.8203125, 364.811004638671875, 137.238006591796875, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2029, 180425, 0, 1519, 5390, '0', 0, 0, -8463.7099609375, 353.360992431640625, 137.2230072021484375, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2030, 180425, 0, 1519, 5390, '0', 0, 0, -8466.8095703125, 352.3330078125, 137.2209930419921875, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2031, 180425, 0, 1519, 5390, '0', 0, 0, -8457.580078125, 358.239990234375, 137.240997314453125, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2032, 180425, 0, 1519, 5390, '0', 0, 0, -8473.5, 557.17498779296875, 99.8162994384765625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2033, 180425, 0, 1519, 5390, '0', 0, 0, -8498.91015625, 568.50201416015625, 101.0940017700195312, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2034, 180425, 0, 1519, 5390, '0', 0, 0, -8474.83984375, 555.35198974609375, 99.81690216064453125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2035, 180425, 0, 1519, 5390, '0', 0, 0, -8476.3896484375, 553.281005859375, 99.82700347900390625, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2036, 180425, 0, 1519, 5150, '0', 0, 0, -8470.6103515625, 561.25201416015625, 99.81390380859375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2037, 180425, 0, 1519, 5150, '0', 0, 0, -8472, 559.26397705078125, 99.818603515625, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2038, 180425, 0, 1519, 5150, '0', 0, 0, -8469.2900390625, 562.885009765625, 99.816497802734375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2039, 180425, 0, 1519, 5150, '0', 0, 0, -8411.240234375, 538.06298828125, 103.9530029296875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2040, 180425, 0, 1519, 5150, '0', 0, 0, -8414.2900390625, 538.00299072265625, 96.22299957275390625, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2041, 180425, 0, 1519, 5150, '0', 0, 0, -8422.3095703125, 559.0830078125, 95.64969635009765625, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2042, 180425, 0, 1519, 5150, '0', 0, 0, -8412.8603515625, 536.72601318359375, 103.9540023803710937, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2043, 180425, 0, 1519, 5150, '0', 0, 0, -8419.4599609375, 561.343994140625, 95.64969635009765625, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2044, 180425, 0, 1519, 5150, '0', 0, 0, -8411.240234375, 544.97900390625, 96.60140228271484375, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2045, 180425, 0, 1519, 5150, '0', 0, 0, -8420.8896484375, 560.2239990234375, 95.64969635009765625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2046, 180425, 0, 1519, 5390, '0', 0, 0, -8469.8095703125, 600.76202392578125, 97.4738006591796875, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2047, 180425, 0, 1519, 5390, '0', 0, 0, -8468.4296875, 599.0360107421875, 97.46179962158203125, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2048, 180425, 0, 1519, 5390, '0', 0, 0, -8467.3701171875, 597.60601806640625, 97.45459747314453125, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2049, 180425, 0, 1519, 5150, '0', 0, 0, -8474.759765625, 606.9110107421875, 97.45880126953125, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2050, 180425, 0, 1519, 5390, '0', 0, 0, -8480.5703125, 632.53802490234375, 95.6511993408203125, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2051, 180425, 0, 1519, 5390, '0', 0, 0, -8515.7998046875, 736.73602294921875, 102.3119964599609375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2052, 180425, 0, 1519, 5390, '0', 0, 0, -8415.7197265625, 681.9949951171875, 96.5189971923828125, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2053, 180425, 0, 1519, 5390, '0', 0, 0, -8418.66015625, 679.70697021484375, 96.5189971923828125, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2054, 180425, 0, 1519, 5390, '0', 0, 0, -8492.2998046875, 749.36602783203125, 99.19210052490234375, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2055, 180425, 0, 1519, 5390, '0', 0, 0, -8482.9501953125, 740.68402099609375, 100.871002197265625, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2056, 180425, 0, 1519, 5390, '0', 0, 0, -8417.2197265625, 680.85198974609375, 96.5189971923828125, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2057, 180425, 0, 1519, 5390, '0', 0, 0, -8483.900390625, 749.62799072265625, 99.56259918212890625, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2058, 180425, 0, 1519, 5390, '0', 0, 0, -8475.0703125, 740.19598388671875, 99.20349884033203125, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2059, 180425, 0, 1519, 5390, '0', 0, 0, -8500.0302734375, 756.781005859375, 99.5373992919921875, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2060, 180425, 0, 1519, 5390, '0', 0, 0, -8412.0595703125, 658.57598876953125, 99.32140350341796875, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2061, 180425, 0, 1519, 5390, '0', 0, 0, -8500.1396484375, 765.06298828125, 99.56710052490234375, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2062, 180425, 0, 1519, 5390, '0', 0, 0, -8492.5400390625, 757.3489990234375, 99.57019805908203125, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2063, 180425, 0, 1519, 5390, '0', 0, 0, -8509.150390625, 766.010009765625, 99.1031036376953125, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2064, 180425, 0, 1519, 5314, '0', 0, 0, -8373.7802734375, 676.07098388671875, 100.03900146484375, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2065, 180425, 0, 1519, 5314, '0', 0, 0, -8389.169921875, 630.63702392578125, 96.13179779052734375, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2066, 180425, 0, 1519, 5314, '0', 0, 0, -8389.1904296875, 628.71197509765625, 96.18630218505859375, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2067, 180425, 0, 1519, 5314, '0', 0, 0, -8386.4296875, 633.39801025390625, 95.97789764404296875, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2068, 180425, 0, 1519, 5314, '0', 0, 0, -8384.5302734375, 633.35101318359375, 95.92769622802734375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2069, 180425, 0, 1519, 5314, '0', 0, 0, -8385.5400390625, 631.5, 98.4539031982421875, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2070, 180425, 0, 1519, 5314, '0', 0, 0, -8387.7998046875, 632.05902099609375, 96.03510284423828125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2071, 180425, 0, 1519, 5314, '0', 0, 0, -8387.1103515625, 629.87200927734375, 98.5381011962890625, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2072, 180425, 0, 1519, 5314, '0', 0, 0, -8389.16015625, 626.71197509765625, 96.27300262451171875, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2073, 180425, 0, 1519, 5314, '0', 0, 0, -8383.259765625, 631.48101806640625, 98.41400146484375, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2074, 180425, 0, 1519, 5314, '0', 0, 0, -8384.25, 628.94598388671875, 104.4919967651367187, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2075, 180425, 0, 1519, 5314, '0', 0, 0, -8381.0400390625, 632.0260009765625, 95.931396484375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2076, 180425, 0, 1519, 5314, '0', 0, 0, -8383.580078125, 630.76397705078125, 100.417999267578125, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2077, 180425, 0, 1519, 5314, '0', 0, 0, -8382.3701171875, 629.5889892578125, 100.4369964599609375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2078, 180425, 0, 1519, 5314, '0', 0, 0, -8387.1103515625, 627.625, 98.61640167236328125, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2079, 180425, 0, 1519, 5314, '0', 0, 0, -8382.5, 633.3179931640625, 95.8730010986328125, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2080, 180425, 0, 1519, 5314, '0', 0, 0, -8386.2802734375, 628.0419921875, 100.55999755859375, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2081, 180425, 0, 1519, 5314, '0', 0, 0, -8386.25, 629.59698486328125, 100.5059967041015625, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2082, 180425, 0, 1519, 5314, '0', 0, 0, -8385.1103515625, 630.76202392578125, 100.4449996948242187, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2083, 180425, 0, 1519, 5314, '0', 0, 0, -8381.669921875, 629.89398193359375, 98.44110107421875, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2084, 180425, 0, 1519, 5314, '0', 0, 0, -8383.58984375, 626.91802978515625, 100.552001953125, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2085, 180425, 0, 1519, 5314, '0', 0, 0, -8385.150390625, 626.88702392578125, 100.51300048828125, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2086, 180425, 0, 1519, 5314, '0', 0, 0, -8379.7001953125, 630.64398193359375, 95.968902587890625, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2087, 180425, 0, 1519, 5314, '0', 0, 0, -8382.3798828125, 628.03302001953125, 100.490997314453125, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2088, 180425, 0, 1519, 5314, '0', 0, 0, -8387.76953125, 625.27398681640625, 96.2790985107421875, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2089, 180425, 0, 1519, 5314, '0', 0, 0, -8385.5, 626.04998779296875, 98.6425018310546875, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2090, 180425, 0, 1519, 5314, '0', 0, 0, -8386.400390625, 623.95001220703125, 96.31999969482421875, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2091, 180425, 0, 1519, 5314, '0', 0, 0, -8381.6904296875, 627.66302490234375, 98.51889801025390625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2092, 180425, 0, 1519, 5314, '0', 0, 0, -8383.2802734375, 626.05902099609375, 98.58740234375, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2093, 180425, 0, 1519, 5150, '0', 0, 0, -8381.08984375, 625.260009765625, 96.1649017333984375, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2094, 180425, 0, 1519, 5150, '0', 0, 0, -8379.6904296875, 626.72100830078125, 96.1013031005859375, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2095, 180425, 0, 1519, 5150, '0', 0, 0, -8384.4296875, 623.9110107421875, 96.27300262451171875, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2096, 180425, 0, 1519, 5150, '0', 0, 0, -8379.6904296875, 628.6939697265625, 96.03130340576171875, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2097, 180425, 0, 1519, 5150, '0', 0, 0, -8382.4501953125, 623.91497802734375, 96.21579742431640625, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2098, 180425, 0, 1519, 5150, '0', 0, 0, -8369.9697265625, 599.09002685546875, 98.94589996337890625, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2099, 180425, 0, 1519, 5150, '0', 0, 0, -8377.7900390625, 605.62799072265625, 97.8227996826171875, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2100, 180425, 0, 1519, 5150, '0', 0, 0, -8377.4697265625, 593.47601318359375, 98.91619873046875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2101, 180425, 0, 1519, 5150, '0', 0, 0, -8381.2099609375, 590.41998291015625, 98.9208984375, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2102, 180425, 0, 1519, 5150, '0', 0, 0, -8368.080078125, 600.64398193359375, 98.9203033447265625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2103, 180425, 0, 1519, 5150, '0', 0, 0, -8371.8203125, 610.33197021484375, 97.83249664306640625, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2104, 180425, 0, 1519, 5150, '0', 0, 0, -8366.2197265625, 602.05902099609375, 98.90529632568359375, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2105, 180425, 0, 1519, 5150, '0', 0, 0, -8371.91015625, 597.50701904296875, 98.91590118408203125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2106, 180425, 0, 1519, 5150, '0', 0, 0, -8383.080078125, 588.927001953125, 98.90540313720703125, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2107, 180425, 0, 1519, 5150, '0', 0, 0, -8379.400390625, 591.89398193359375, 98.942596435546875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2108, 180425, 0, 1519, 5150, '0', 0, 0, -8331.6103515625, 661.76898193359375, 98.14550018310546875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2109, 180425, 0, 1519, 5150, '0', 0, 0, -8364.2001953125, 575.06298828125, 105.3209991455078125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2110, 180425, 0, 1519, 5150, '0', 0, 0, -8362.2099609375, 576.50701904296875, 105.3740005493164062, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2111, 180425, 0, 1519, 5150, '0', 0, 0, -8360.330078125, 577.9639892578125, 105.3860015869140625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2112, 180425, 0, 1519, 5150, '0', 0, 0, -8366.0703125, 573.56097412109375, 105.2900009155273437, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2113, 180425, 0, 1519, 5150, '0', 0, 0, -8358.3603515625, 579.50701904296875, 105.4029998779296875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2114, 180425, 0, 1519, 5150, '0', 0, 0, -8354.5400390625, 582.4840087890625, 105.3990020751953125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2115, 180425, 0, 1519, 5150, '0', 0, 0, -8356.5, 580.96002197265625, 105.427001953125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2116, 180425, 0, 1519, 5150, '0', 0, 0, -8328.3701171875, 587.85198974609375, 100.792999267578125, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2117, 180425, 0, 1519, 5150, '0', 0, 0, -8330.3896484375, 590.39202880859375, 100.792999267578125, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2118, 180425, 0, 1519, 5150, '0', 0, 0, -8335.8095703125, 597.21197509765625, 100.792999267578125, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2119, 180425, 0, 1519, 5150, '0', 0, 0, -8334.0302734375, 594.989990234375, 100.792999267578125, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2120, 180425, 0, 1519, 5150, '0', 0, 0, -8330.3896484375, 590.39202880859375, 100.792999267578125, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2121, 180425, 0, 1519, 5150, '0', 0, 0, -8332.1796875, 592.62200927734375, 100.792999267578125, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2122, 180425, 0, 1519, 5150, '0', 0, 0, -8326.6298828125, 585.718994140625, 100.792999267578125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2123, 180425, 0, 1519, 5150, '0', 0, 0, -8324.2099609375, 606.41497802734375, 100.792999267578125, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2124, 180425, 0, 1519, 5150, '0', 0, 0, -8322.51953125, 604.23297119140625, 100.792999267578125, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2125, 180425, 0, 1519, 5150, '0', 0, 0, -8320.6201171875, 601.8800048828125, 100.792999267578125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2126, 180425, 0, 1519, 5150, '0', 0, 0, -8315.08984375, 594.88702392578125, 100.792999267578125, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2127, 180425, 0, 1519, 5150, '0', 0, 0, -8316.83984375, 597.1090087890625, 100.792999267578125, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2128, 180425, 0, 1519, 5150, '0', 0, 0, -8318.830078125, 599.62200927734375, 100.792999267578125, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2129, 180425, 0, 1519, 5150, '0', 0, 0, -8318.9404296875, 667.02801513671875, 98.188201904296875, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2130, 180425, 0, 1519, 5150, '0', 0, 0, -8311.8095703125, 658.08001708984375, 98.1880035400390625, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2131, 180425, 0, 1519, 5150, '0', 0, 0, -8324, 667.1300048828125, 98.18890380859375, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2132, 180425, 0, 1519, 5150, '0', 0, 0, -8328.3603515625, 664.677001953125, 98.17400360107421875, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- SkullCandle01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2133, 180425, 0, 1519, 5316, '0', 0, 0, -8327.23046875, 894.63201904296875, 98.96099853515625, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2134, 180425, 0, 1519, 5316, '0', 0, 0, -8331.5595703125, 894.552001953125, 98.6365966796875, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2135, 180425, 0, 1519, 5316, '0', 0, 0, -8306.4599609375, 906.96002197265625, 99.1620025634765625, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2136, 180425, 0, 1519, 5316, '0', 0, 0, -8310.23046875, 908.95098876953125, 99.045196533203125, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2137, 180425, 0, 1519, 5316, '0', 0, 0, -8320.3203125, 907.5260009765625, 98.97769927978515625, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2138, 180425, 0, 1519, 5316, '0', 0, 0, -8298.1396484375, 902.39599609375, 99.14849853515625, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2139, 180425, 0, 1519, 5316, '0', 0, 0, -8324.650390625, 899.4429931640625, 99.12709808349609375, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2140, 180425, 0, 1519, 5316, '0', 0, 0, -8312.080078125, 922.61798095703125, 98.61080169677734375, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2141, 180425, 0, 1519, 5316, '0', 0, 0, -8334.7001953125, 897.4320068359375, 98.58280181884765625, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2142, 180425, 0, 1519, 5316, '0', 0, 0, -8327.1796875, 911.26702880859375, 98.74669647216796875, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2143, 180425, 0, 1519, 5316, '0', 0, 0, -8313.8896484375, 910.89398193359375, 98.94229888916015625, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2144, 180425, 0, 1519, 5316, '0', 0, 0, -8318.330078125, 911.29302978515625, 98.91100311279296875, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2145, 180425, 0, 1519, 5316, '0', 0, 0, -8302.25, 904.79498291015625, 99.281097412109375, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2146, 180425, 0, 1519, 5316, '0', 0, 0, -8308.2197265625, 920.8330078125, 98.65579986572265625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2147, 180425, 0, 1519, 5316, '0', 0, 0, -8297.0498046875, 914.77301025390625, 98.9611968994140625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2148, 180425, 0, 1519, 5316, '0', 0, 0, -8325.33984375, 915.25, 98.6363983154296875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2149, 180425, 0, 1519, 5316, '0', 0, 0, -8328.5498046875, 919.26397705078125, 98.50679779052734375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2150, 180425, 0, 1519, 5316, '0', 0, 0, -8331.6796875, 903.3800048828125, 98.77120208740234375, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2151, 180425, 0, 1519, 5316, '0', 0, 0, -8293.1904296875, 912.9310302734375, 98.88919830322265625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2152, 180425, 0, 1519, 5316, '0', 0, 0, -8322.8798828125, 928.35797119140625, 98.29540252685546875, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2153, 180425, 0, 1519, 5316, '0', 0, 0, -8333.330078125, 922.4169921875, 98.375396728515625, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2154, 180425, 0, 1519, 5316, '0', 0, 0, -8315.400390625, 924.405029296875, 98.51619720458984375, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2155, 180425, 0, 1519, 5316, '0', 0, 0, -8318.9599609375, 926.3179931640625, 98.41290283203125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2156, 180425, 0, 1519, 5316, '0', 0, 0, -8327.3603515625, 935.78802490234375, 98.1436004638671875, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2157, 180425, 0, 1519, 5316, '0', 0, 0, -8337.349609375, 924.8070068359375, 98.23110198974609375, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2158, 180425, 0, 1519, 5316, '0', 0, 0, -8376.8798828125, 913.2659912109375, 99.5861968994140625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2159, 180425, 0, 1519, 5316, '0', 0, 0, -8327.4697265625, 930.76702880859375, 98.1613006591796875, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2160, 180425, 0, 1519, 5316, '0', 0, 0, -8324.83984375, 941.0560302734375, 98.07610321044921875, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2161, 180425, 0, 1519, 5316, '0', 0, 0, -8340.08984375, 937.50299072265625, 97.86699676513671875, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2162, 180425, 0, 1519, 5316, '0', 0, 0, -8334.7998046875, 940.11602783203125, 97.9683990478515625, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2163, 180425, 0, 1519, 5316, '0', 0, 0, -8346.0703125, 929.2760009765625, 98.21109771728515625, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2164, 180425, 0, 1519, 5316, '0', 0, 0, -8350.7802734375, 931.30401611328125, 98.1548004150390625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2165, 180425, 0, 1519, 5316, '0', 0, 0, -8374.759765625, 918.46197509765625, 99.2631988525390625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2166, 180425, 0, 1519, 5316, '0', 0, 0, -8345.7998046875, 940.13702392578125, 97.6793975830078125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2167, 180425, 0, 1519, 5316, '0', 0, 0, -8358.98046875, 935.010009765625, 98.14330291748046875, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2168, 180425, 0, 1519, 5316, '0', 0, 0, -8382.6298828125, 920.82098388671875, 99.41989898681640625, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2169, 180425, 0, 1519, 5316, '0', 0, 0, -8384.7099609375, 915.614990234375, 99.742401123046875, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2170, 180425, 0, 1519, 5316, '0', 0, 0, -8381.490234375, 913.08001708984375, 99.77230072021484375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2171, 180425, 0, 1519, 5316, '0', 0, 0, -8371.5703125, 926.60400390625, 98.78260040283203125, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2172, 180425, 0, 1519, 5316, '0', 0, 0, -8322.8095703125, 945.155029296875, 98.0348968505859375, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2173, 180425, 0, 1519, 5316, '0', 0, 0, -8332.4599609375, 944.85101318359375, 97.908599853515625, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2174, 180425, 0, 1519, 5346, '0', 0, 0, -8316.01953125, 959.10601806640625, 98.49320220947265625, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2175, 180425, 0, 1519, 5346, '0', 0, 0, -8318.080078125, 954.83502197265625, 98.32900238037109375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2176, 180425, 0, 1519, 5346, '0', 0, 0, -8320.580078125, 949.7919921875, 98.13970184326171875, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2177, 180425, 0, 1519, 5346, '0', 0, 0, -8300.7275390625, 976.18231201171875, 103.11962890625, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2178, 180425, 0, 1519, 5346, '0', 0, 0, -8323.830078125, 962.92498779296875, 98.26329803466796875, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2179, 180425, 0, 1519, 5346, '0', 0, 0, -8330.4501953125, 949.09002685546875, 97.8656005859375, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2180, 180425, 0, 1519, 5346, '0', 0, 0, -8328.26953125, 953.614990234375, 97.90450286865234375, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2181, 180425, 0, 1519, 5346, '0', 0, 0, -8314.28515625, 977.9930419921875, 102.0492401123046875, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2182, 180425, 0, 1519, 5346, '0', 0, 0, -8306.4306640625, 970.1336669921875, 101.7167205810546875, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2183, 180425, 0, 1519, 5346, '0', 0, 0, -8326.1103515625, 958.1090087890625, 98.07399749755859375, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2184, 180425, 0, 1519, 5346, '0', 0, 0, -8353.4501953125, 942.9429931640625, 97.6985015869140625, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2185, 180425, 0, 1519, 5346, '0', 0, 0, -8308.98828125, 984.18231201171875, 103.0530166625976562, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2186, 180425, 0, 1519, 5346, '0', 0, 0, -8363.009765625, 936.70697021484375, 98.09819793701171875, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2187, 180425, 0, 1519, 5346, '0', 0, 0, -8367.2998046875, 936.177001953125, 98.17169952392578125, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2188, 180425, 0, 1519, 5346, '0', 0, 0, -8363.26953125, 947.260009765625, 97.58049774169921875, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2189, 180425, 0, 1519, 5346, '0', 0, 0, -8358.5498046875, 945.14801025390625, 97.62640380859375, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2190, 180425, 0, 1519, 5346, '0', 0, 0, -8369.33984375, 931.70501708984375, 98.4541015625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2191, 180425, 0, 1519, 5346, '0', 0, 0, -8368.9501953125, 949.66302490234375, 97.61009979248046875, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2192, 180425, 0, 1519, 5346, '0', 0, 0, -8376.5703125, 934.62701416015625, 98.4680023193359375, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2193, 180425, 0, 1519, 5346, '0', 0, 0, -8376.759765625, 953.3590087890625, 97.52970123291015625, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2194, 180425, 0, 1519, 5346, '0', 0, 0, -8374.6796875, 939.28302001953125, 98.178802490234375, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2195, 180425, 0, 1519, 5346, '0', 0, 0, -8378.2099609375, 942.8590087890625, 98.25980377197265625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2196, 180425, 0, 1519, 5346, '0', 0, 0, -8378.650390625, 929.36602783203125, 98.80059814453125, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2197, 180425, 0, 1519, 5346, '0', 0, 0, -8382.990234375, 943.87298583984375, 98.4141998291015625, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2198, 180425, 0, 1519, 5346, '0', 0, 0, -8387.669921875, 944.07598876953125, 98.40450286865234375, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2199, 180425, 0, 1519, 5346, '0', 0, 0, -8383.5, 956.60601806640625, 97.71219635009765625, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2200, 180425, 0, 1519, 5346, '0', 0, 0, -8385.1796875, 980.35198974609375, 97.20729827880859375, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2201, 180425, 0, 1519, 5346, '0', 0, 0, -8384.4404296875, 986.04302978515625, 97.13189697265625, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2202, 180425, 0, 1519, 5346, '0', 0, 0, -8400.490234375, 952.6409912109375, 98.56600189208984375, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2203, 180425, 0, 1519, 5346, '0', 0, 0, -8392.0498046875, 943.23101806640625, 98.52459716796875, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2204, 180425, 0, 1519, 5346, '0', 0, 0, -8394.3095703125, 986.72198486328125, 97.40760040283203125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2205, 180425, 0, 1519, 5346, '0', 0, 0, -8394.9296875, 981.42498779296875, 97.5475006103515625, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2206, 180425, 0, 1519, 5346, '0', 0, 0, -8405.0400390625, 938.28997802734375, 99.19570159912109375, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2207, 180425, 0, 1519, 5346, '0', 0, 0, -8404.509765625, 950.0889892578125, 98.76799774169921875, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2208, 180425, 0, 1519, 5346, '0', 0, 0, -8400.419921875, 940.46002197265625, 98.9683990478515625, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2209, 180425, 0, 1519, 5346, '0', 0, 0, -8410.08984375, 946.29498291015625, 99.223602294921875, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2210, 180425, 0, 1519, 5346, '0', 0, 0, -8417.2099609375, 930.03802490234375, 99.66249847412109375, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2211, 180425, 0, 1519, 5346, '0', 0, 0, -8418.1396484375, 908.16497802734375, 99.1139984130859375, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2212, 180425, 0, 1519, 5346, '0', 0, 0, -8416.83984375, 914.7449951171875, 99.7014007568359375, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2213, 180425, 0, 1519, 5346, '0', 0, 0, -8417.6396484375, 941.21697998046875, 99.47679901123046875, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2214, 180425, 0, 1519, 5346, '0', 0, 0, -8413.919921875, 943.79302978515625, 99.3363037109375, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2215, 180425, 0, 1519, 5346, '0', 0, 0, -8409.7197265625, 935.1199951171875, 99.42340087890625, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2216, 180425, 0, 1519, 5346, '0', 0, 0, -8413.1396484375, 932.8489990234375, 99.53510284423828125, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2217, 180425, 0, 1519, 5346, '0', 0, 0, -8414.1904296875, 910.44598388671875, 99.271697998046875, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2218, 180425, 0, 1519, 5346, '0', 0, 0, -8420.7802734375, 927.66802978515625, 99.77480316162109375, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2219, 180425, 0, 1519, 5346, '0', 0, 0, -8423.0703125, 924.25299072265625, 99.766998291015625, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2220, 180425, 0, 1519, 5346, '0', 0, 0, -8420.75, 920.71002197265625, 99.77469635009765625, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2221, 180425, 0, 1519, 5346, '0', 0, 0, -8421.5703125, 938.64202880859375, 99.58730316162109375, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2222, 180425, 0, 1519, 5346, '0', 0, 0, -8422.9697265625, 909.3590087890625, 99.2490997314453125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2223, 180425, 0, 1519, 5346, '0', 0, 0, -8426.080078125, 913.72900390625, 99.901397705078125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2224, 180425, 0, 1519, 5346, '0', 0, 0, -8428.1904296875, 934.16302490234375, 99.79470062255859375, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2225, 180425, 0, 1519, 5346, '0', 0, 0, -8428.650390625, 917.41302490234375, 99.90509796142578125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2226, 180425, 0, 1519, 5346, '0', 0, 0, -8424.8701171875, 936.37200927734375, 99.70240020751953125, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2227, 180425, 0, 1519, 5314, '0', 0, 0, -8435.900390625, 917.5570068359375, 100.21099853515625, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2228, 180425, 0, 1519, 5314, '0', 0, 0, -8432.3896484375, 919.8330078125, 100.2080001831054687, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2229, 180425, 0, 1519, 5346, '0', 0, 0, -8435.01953125, 929.61297607421875, 99.94190216064453125, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2230, 180425, 0, 1519, 5346, '0', 0, 0, -8431.759765625, 931.75201416015625, 99.8697967529296875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2231, 180425, 0, 1519, 5346, '0', 0, 0, -8442.5498046875, 931.20697021484375, 99.81099700927734375, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2232, 180425, 0, 1519, 5346, '0', 0, 0, -8443.7099609375, 912.41302490234375, 100.48699951171875, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2233, 180425, 0, 1519, 5346, '0', 0, 0, -8440.23046875, 928.239990234375, 99.9676971435546875, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2234, 180425, 0, 1519, 5346, '0', 0, 0, -8438, 927.6090087890625, 99.9871978759765625, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2235, 180425, 0, 1519, 5346, '0', 0, 0, -8455.98046875, 890.41302490234375, 100.7419967651367187, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2236, 180425, 0, 1519, 5346, '0', 0, 0, -8444.73046875, 933.98797607421875, 99.6454010009765625, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2237, 180425, 0, 1519, 5346, '0', 0, 0, -8450.58984375, 941.3330078125, 98.54360198974609375, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2238, 180425, 0, 1519, 5346, '0', 0, 0, -8457.5498046875, 902.83697509765625, 100.16400146484375, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2239, 180425, 0, 1519, 5346, '0', 0, 0, -8456.1201171875, 934.14202880859375, 98.61679840087890625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2240, 180425, 0, 1519, 5346, '0', 0, 0, -8448.9599609375, 924.11798095703125, 99.69930267333984375, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2241, 180425, 0, 1519, 5346, '0', 0, 0, -8459.9501953125, 912.0889892578125, 100.0500030517578125, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2242, 180425, 0, 1519, 5346, '0', 0, 0, -8457.01953125, 914.1300048828125, 100.0569992065429687, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2243, 180425, 0, 1519, 5346, '0', 0, 0, -8448.2802734375, 938.66998291015625, 98.8896026611328125, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2244, 180425, 0, 1519, 5346, '0', 0, 0, -8460.6103515625, 897.89801025390625, 100.569000244140625, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2245, 180425, 0, 1519, 5346, '0', 0, 0, -8458.330078125, 894.21002197265625, 100.572998046875, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2246, 180425, 0, 1519, 5314, '0', 0, 0, -8447.7197265625, 909.71002197265625, 100.5719985961914062, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2247, 180425, 0, 1519, 5346, '0', 0, 0, -8453.8798828125, 905.24102783203125, 100.15899658203125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2248, 180425, 0, 1519, 5346, '0', 0, 0, -8451.1904296875, 927.45697021484375, 99.3470001220703125, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2249, 180425, 0, 1519, 5346, '0', 0, 0, -8453.740234375, 930.95697021484375, 98.966796875, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2250, 180425, 0, 1519, 5346, '0', 0, 0, -8451.849609375, 917.64599609375, 100.1429977416992187, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2251, 180425, 0, 1519, 5346, '0', 0, 0, -8448.2001953125, 920.155029296875, 100.141998291015625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2252, 180425, 0, 1519, 5346, '0', 0, 0, -8468.259765625, 911.02099609375, 99.82689666748046875, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2253, 180425, 0, 1519, 5346, '0', 0, 0, -8464.8095703125, 908.73297119140625, 100.2770004272460937, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2254, 180425, 0, 1519, 5346, '0', 0, 0, -8470.08984375, 914.3060302734375, 99.57959747314453125, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2255, 180425, 0, 1519, 5346, '0', 0, 0, -8490.5595703125, 845.16802978515625, 106.6490020751953125, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2256, 180425, 0, 1519, 5346, '0', 0, 0, -8492.25, 845.072998046875, 106.6630020141601562, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2257, 180425, 0, 1519, 5346, '0', 0, 0, -8487.8203125, 841.135009765625, 106.66400146484375, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2258, 180425, 0, 1519, 5346, '0', 0, 0, -8494.009765625, 844.89202880859375, 106.6460037231445312, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2259, 180425, 0, 1519, 5346, '0', 0, 0, -8487.990234375, 842.95501708984375, 106.634002685546875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2260, 180425, 0, 1519, 5346, '0', 0, 0, -8489.240234375, 843.989990234375, 106.6490020751953125, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2261, 180425, 0, 1519, 5346, '0', 0, 0, -8489.66015625, 842.114990234375, 108.7770004272460937, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2262, 180425, 0, 1519, 5346, '0', 0, 0, -8491.16015625, 843.406005859375, 108.7770004272460937, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2263, 180425, 0, 1519, 5346, '0', 0, 0, -8492.7802734375, 842.531005859375, 110.4970016479492187, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2264, 180425, 0, 1519, 5346, '0', 0, 0, -8487.7099609375, 839.52301025390625, 106.6620025634765625, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2265, 180425, 0, 1519, 5346, '0', 0, 0, -8492.48046875, 839.2080078125, 110.4970016479492187, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2266, 180425, 0, 1519, 5346, '0', 0, 0, -8493.599609375, 840.1199951171875, 110.4970016479492187, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2267, 180425, 0, 1519, 5346, '0', 0, 0, -8491.4296875, 842.67901611328125, 110.4970016479492187, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2268, 180425, 0, 1519, 5346, '0', 0, 0, -8490.349609375, 841.71697998046875, 110.4970016479492187, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2269, 180425, 0, 1519, 5346, '0', 0, 0, -8489.48046875, 840.11102294921875, 108.7770004272460937, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2270, 180425, 0, 1519, 5346, '0', 0, 0, -8495.099609375, 843.63397216796875, 106.6490020751953125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2271, 180425, 0, 1519, 5346, '0', 0, 0, -8496.2099609375, 842.27398681640625, 106.6480026245117187, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2272, 180425, 0, 1519, 5346, '0', 0, 0, -8493.150390625, 843.24102783203125, 108.7770004272460937, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2273, 180425, 0, 1519, 5346, '0', 0, 0, -8488.7998046875, 838.26898193359375, 106.6480026245117187, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2274, 180425, 0, 1519, 5346, '0', 0, 0, -8490.259765625, 840.39398193359375, 110.4970016479492187, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2275, 180425, 0, 1519, 5346, '0', 0, 0, -8491.169921875, 839.2969970703125, 110.4970016479492187, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2276, 180425, 0, 1519, 5346, '0', 0, 0, -8494.4501953125, 841.71197509765625, 108.7760009765625, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2277, 180425, 0, 1519, 5346, '0', 0, 0, -8493.7197265625, 841.47198486328125, 110.4970016479492187, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2278, 180425, 0, 1519, 5346, '0', 0, 0, -8490.7900390625, 838.58502197265625, 108.7770004272460937, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2279, 180425, 0, 1519, 5346, '0', 0, 0, -8491.6201171875, 836.78802490234375, 106.6660003662109375, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2280, 180425, 0, 1519, 5346, '0', 0, 0, -8496.1201171875, 840.58697509765625, 106.6610031127929687, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2281, 180425, 0, 1519, 5346, '0', 0, 0, -8493.349609375, 836.66302490234375, 106.647003173828125, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2282, 180425, 0, 1519, 5346, '0', 0, 0, -8494.6298828125, 837.7449951171875, 106.628997802734375, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2283, 180425, 0, 1519, 5346, '0', 0, 0, -8489.9296875, 836.93402099609375, 106.6409988403320312, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2284, 180425, 0, 1519, 5346, '0', 0, 0, -8496.009765625, 838.87701416015625, 106.628997802734375, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2285, 180425, 0, 1519, 5346, '0', 0, 0, -8494.3203125, 839.71502685546875, 108.7519989013671875, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2286, 180425, 0, 1519, 5346, '0', 0, 0, -8492.740234375, 838.41302490234375, 108.7770004272460937, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2287, 180425, 0, 1519, 0, '0', 0, 0, -8565.4697265625, 903.5679931640625, 100.483001708984375, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2288, 180425, 0, 1519, 0, '0', 0, 0, -8566.8203125, 902.20098876953125, 100.4899978637695312, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2289, 180425, 0, 1519, 0, '0', 0, 0, -8565.48046875, 907.50897216796875, 100.4240036010742187, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2290, 180425, 0, 1519, 0, '0', 0, 0, -8565.4697265625, 905.47900390625, 100.4560012817382812, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2291, 180425, 0, 1519, 0, '0', 0, 0, -8567.4697265625, 904.447998046875, 102.8820037841796875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2292, 180425, 0, 1519, 0, '0', 0, 0, -8568.2900390625, 906.35601806640625, 104.8249969482421875, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2293, 180425, 0, 1519, 0, '0', 0, 0, -8569.099609375, 902.8060302734375, 102.8809967041015625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2294, 180425, 0, 1519, 0, '0', 0, 0, -8567.509765625, 906.7340087890625, 102.8479995727539062, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2295, 180425, 0, 1519, 0, '0', 0, 0, -8569.08984375, 908.29998779296875, 102.822998046875, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2296, 180425, 0, 1519, 0, '0', 0, 0, -8568.2998046875, 910.26898193359375, 100.3870010375976562, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2297, 180425, 0, 1519, 0, '0', 0, 0, -8566.7998046875, 908.84600830078125, 100.3949966430664062, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2298, 180425, 0, 1519, 0, '0', 0, 0, -8568.2900390625, 904.87298583984375, 104.8460006713867187, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2299, 180425, 0, 1519, 0, '0', 0, 0, -8569.48046875, 903.64898681640625, 104.8629989624023437, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2300, 180425, 0, 1519, 0, '0', 0, 0, -8568.25, 900.75897216796875, 100.496002197265625, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2301, 180425, 0, 1519, 4411, '0', 0, 0, -8569.5, 907.5, 104.805999755859375, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2302, 180425, 0, 1519, 4411, '0', 0, 0, -8570.2900390625, 900.7760009765625, 100.5100021362304687, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2303, 180425, 0, 1519, 0, '0', 0, 0, -8571.3203125, 902.8590087890625, 102.8990020751953125, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2304, 180425, 0, 1519, 0, '0', 0, 0, -8570.1904296875, 910.31298828125, 100.3590011596679687, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2305, 180425, 0, 1519, 0, '0', 0, 0, -8572.1396484375, 904.81597900390625, 104.8420028686523437, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2306, 180425, 0, 1519, 0, '0', 0, 0, -8570.9697265625, 903.6510009765625, 104.8610000610351562, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2307, 180425, 0, 1519, 0, '0', 0, 0, -8571.01953125, 907.5260009765625, 104.8040008544921875, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2308, 180425, 0, 1519, 0, '0', 0, 0, -8571.3603515625, 908.26702880859375, 102.8199996948242187, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2309, 180425, 0, 1519, 0, '0', 0, 0, -8574.9501953125, 903.56298828125, 100.4729995727539062, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2310, 180425, 0, 1519, 0, '0', 0, 0, -8572.9697265625, 906.67498779296875, 102.8420028686523437, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2311, 180425, 0, 1519, 0, '0', 0, 0, -8572.2001953125, 900.7969970703125, 100.5199966430664062, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2312, 180425, 0, 1519, 0, '0', 0, 0, -8574.9697265625, 905.572998046875, 100.444000244140625, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2313, 180425, 0, 1519, 0, '0', 0, 0, -8573.669921875, 902.280029296875, 100.496002197265625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2314, 180425, 0, 1519, 0, '0', 0, 0, -8573.580078125, 908.87200927734375, 100.4000015258789062, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2315, 180425, 0, 1519, 0, '0', 0, 0, -8572.2001953125, 910.25701904296875, 100.3820037841796875, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2316, 180425, 0, 1519, 4411, '0', 0, 0, -8572.1796875, 906.3590087890625, 104.819000244140625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2317, 180425, 0, 1519, 4411, '0', 0, 0, -8572.9697265625, 904.41497802734375, 102.875, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2318, 180425, 0, 1519, 0, '0', 0, 0, -8574.9697265625, 907.49798583984375, 100.4160003662109375, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+2319, 180425, 0, 1519, 5390, '0', 0, 0, -8637.23046875, 758.4110107421875, 98.374603271484375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2320, 180425, 0, 1519, 5390, '0', 0, 0, -8639.33984375, 758.70098876953125, 98.362701416015625, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2321, 180425, 0, 1519, 5390, '0', 0, 0, -8635.330078125, 758.19598388671875, 98.3668975830078125, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2322, 180425, 0, 1519, 5390, '0', 0, 0, -8641.8701171875, 761.85797119140625, 98.3332977294921875, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2323, 180425, 0, 1519, 5390, '0', 0, 0, -8641.330078125, 765.885009765625, 98.3511962890625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2324, 180425, 0, 1519, 5390, '0', 0, 0, -8633.5, 759.58001708984375, 98.3585968017578125, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2325, 180425, 0, 1519, 5390, '0', 0, 0, -8641.6396484375, 763.7860107421875, 98.33879852294921875, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2326, 180425, 0, 1519, 5390, '0', 0, 0, -8631.6796875, 764.69097900390625, 98.35250091552734375, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2327, 180425, 0, 1519, 5390, '0', 0, 0, -8632.1396484375, 760.68597412109375, 98.3282012939453125, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2328, 180425, 0, 1519, 5390, '0', 0, 0, -8631.8896484375, 762.81402587890625, 98.33899688720703125, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2329, 180425, 0, 1519, 5390, '0', 0, 0, -8639.7900390625, 767.17901611328125, 98.34369659423828125, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2330, 180425, 0, 1519, 5390, '0', 0, 0, -8686.4697265625, 774.9429931640625, 101, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2331, 180425, 0, 1519, 5390, '0', 0, 0, -8634.1103515625, 767.9219970703125, 98.3271026611328125, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2332, 180425, 0, 1519, 5390, '0', 0, 0, -8636.1103515625, 768.16497802734375, 98.33380126953125, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2333, 180425, 0, 1519, 5390, '0', 0, 0, -8632.900390625, 766.343994140625, 98.3419036865234375, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2334, 180425, 0, 1519, 5390, '0', 0, 0, -8638.150390625, 768.36102294921875, 98.335296630859375, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2335, 180425, 0, 1519, 8411, '0', 0, 0, -8873.419921875, 870.25299072265625, 105.3270034790039062, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- SkullCandle01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2336, 180425, 0, 1519, 8411, '0', 0, 0, -8872.8896484375, 874.50201416015625, 105.3270034790039062, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- SkullCandle01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2337, 180425, 0, 1519, 5390, '0', 0, 0, -8880.259765625, 809.93798828125, 97.4384002685546875, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2338, 180425, 0, 1519, 5390, '0', 0, 0, -8881.33984375, 805.25299072265625, 97.43540191650390625, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2339, 180425, 0, 1519, 8411, '0', 0, 0, -8888.7099609375, 1016.40997314453125, 126.8130035400390625, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2340, 180425, 0, 1519, 5390, '0', 0, 0, -8975.9501953125, 765.6090087890625, 98.34320068359375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2341, 180425, 0, 1519, 5390, '0', 0, 0, -8979.83984375, 767.68798828125, 98.34040069580078125, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- SkullCandle01 (Area: The Canals - Difficulty: 0)
(@OGUID+2342, 180425, 0, 1519, 5154, '0', 0, 0, -8989.4296875, 845.96697998046875, 29.62070083618164062, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2343, 180425, 0, 1519, 5154, '0', 0, 0, -8978.33984375, 876.77398681640625, 121.1169967651367187, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2344, 180425, 0, 1519, 5154, '0', 0, 0, -8979.7099609375, 866.73101806640625, 123.2360000610351562, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2345, 180425, 0, 1519, 5154, '0', 0, 0, -8978.5595703125, 870.052001953125, 122.4739990234375, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2346, 180425, 0, 1519, 5154, '0', 0, 0, -8981.2099609375, 863.9530029296875, 123.9120025634765625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2347, 180425, 0, 1519, 5154, '0', 0, 0, -8983.7900390625, 869.97698974609375, 122.535003662109375, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2348, 180425, 0, 1519, 5154, '0', 0, 0, -8978.349609375, 873.635009765625, 121.76300048828125, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2349, 180425, 0, 1519, 5154, '0', 0, 0, -8985.009765625, 867.156005859375, 123.509002685546875, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2350, 180425, 0, 1519, 5154, '0', 0, 0, -8983.6103515625, 861.4169921875, 124.733001708984375, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2351, 180425, 0, 1519, 5154, '0', 0, 0, -8986.2900390625, 859.32598876953125, 125.5120010375976562, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2352, 180425, 0, 1519, 5154, '0', 0, 0, -8989.080078125, 858.50299072265625, 126.2490005493164062, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2353, 180425, 0, 1519, 5154, '0', 0, 0, -8986.5703125, 864.84600830078125, 124.3990020751953125, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2354, 180425, 0, 1519, 5154, '0', 0, 0, -8980.8798828125, 883.177001953125, 119.8369979858398437, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2355, 180425, 0, 1519, 5154, '0', 0, 0, -8983.58984375, 873.22900390625, 121.5999984741210937, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2356, 180425, 0, 1519, 5154, '0', 0, 0, -8987.400390625, 881.593994140625, 119.0979995727539062, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2357, 180425, 0, 1519, 5154, '0', 0, 0, -8988.759765625, 863.155029296875, 125.3389968872070312, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2358, 180425, 0, 1519, 5154, '0', 0, 0, -8985.3798828125, 879.13397216796875, 119.865997314453125, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2359, 180425, 0, 1519, 5154, '0', 0, 0, -8984.2197265625, 876.322998046875, 120.697998046875, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2360, 180425, 0, 1519, 5154, '0', 0, 0, -8983.2099609375, 885.98297119140625, 119.2089996337890625, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2361, 180425, 0, 1519, 5154, '0', 0, 0, -8991.919921875, 857.84002685546875, 126.9929962158203125, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2362, 180425, 0, 1519, 5154, '0', 0, 0, -8979.51953125, 879.93597412109375, 120.4980010986328125, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2363, 180425, 0, 1519, 5154, '0', 0, 0, -8989.5498046875, 883.822998046875, 118.3759994506835937, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2364, 180425, 0, 1519, 5154, '0', 0, 0, -8992.490234375, 885.489990234375, 117.6139984130859375, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2365, 180425, 0, 1519, 5154, '0', 0, 0, -8991.650390625, 862.10101318359375, 126.4759979248046875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2366, 180425, 0, 1519, 5154, '0', 0, 0, -8985.6103515625, 888.3330078125, 118.6660003662109375, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2367, 180425, 0, 1519, 5154, '0', 0, 0, -8998.330078125, 859.46197509765625, 128.899993896484375, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2368, 180425, 0, 1519, 5154, '0', 0, 0, -8994.23046875, 861.989990234375, 127.5849990844726562, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2369, 180425, 0, 1519, 5154, '0', 0, 0, -8996.330078125, 862.61602783203125, 128.675994873046875, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2370, 180425, 0, 1519, 5154, '0', 0, 0, -8995.1904296875, 858.29901123046875, 127.9189987182617187, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2371, 180425, 0, 1519, 5154, '0', 0, 0, -8991.1796875, 891.75701904296875, 117.5879974365234375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2372, 180425, 0, 1519, 5154, '0', 0, 0, -8988.0400390625, 890.67498779296875, 118.0960006713867187, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2373, 180425, 0, 1519, 5154, '0', 0, 0, -9000.259765625, 887.21197509765625, 115.878997802734375, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2374, 180425, 0, 1519, 5154, '0', 0, 0, -9007.7001953125, 856.96697998046875, 106.615997314453125, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2375, 180425, 0, 1519, 5154, '0', 0, 0, -8997.7197265625, 893.89801025390625, 116.529998779296875, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2376, 180425, 0, 1519, 5154, '0', 0, 0, -8996.16015625, 886.781005859375, 116.7779998779296875, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2377, 180425, 0, 1519, 5154, '0', 0, 0, -9009.98046875, 859.3280029296875, 107.73699951171875, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2378, 180425, 0, 1519, 5154, '0', 0, 0, -8994.330078125, 892.78497314453125, 117.09100341796875, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2379, 180425, 0, 1519, 5154, '0', 0, 0, -9000.98046875, 861.281005859375, 129.740997314453125, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2380, 180425, 0, 1519, 5154, '0', 0, 0, -8998.669921875, 863.88702392578125, 129.59100341796875, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2381, 180425, 0, 1519, 5154, '0', 0, 0, -9005.1396484375, 893.052001953125, 115.4209976196289062, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2382, 180425, 0, 1519, 5154, '0', 0, 0, -9010.33984375, 882.625, 113.555999755859375, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2383, 180425, 0, 1519, 5154, '0', 0, 0, -9013.76953125, 850.89801025390625, 106.9120025634765625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2384, 180425, 0, 1519, 5154, '0', 0, 0, -9007.400390625, 885.42401123046875, 114.3799972534179687, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2385, 180425, 0, 1519, 5154, '0', 0, 0, -9011.990234375, 861.46197509765625, 108.7249984741210937, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2386, 180425, 0, 1519, 5154, '0', 0, 0, -9003.900390625, 886.427001953125, 115.1449966430664062, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2387, 180425, 0, 1519, 5154, '0', 0, 0, -9001.4296875, 893.97900390625, 115.9599990844726562, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2388, 180425, 0, 1519, 5154, '0', 0, 0, -9013.150390625, 863.885009765625, 109.4120025634765625, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2389, 180425, 0, 1519, 5154, '0', 0, 0, -9014.7900390625, 869.76202392578125, 110.6439971923828125, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2390, 180425, 0, 1519, 5154, '0', 0, 0, -9013.9697265625, 866.6669921875, 110.0120010375976562, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2391, 180425, 0, 1519, 5154, '0', 0, 0, -9014.83984375, 872.8280029296875, 111.28900146484375, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2392, 180425, 0, 1519, 5154, '0', 0, 0, -9014.16015625, 875.89898681640625, 111.9319992065429687, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2393, 180425, 0, 1519, 5154, '0', 0, 0, -9013.0498046875, 890.0830078125, 114.1689987182617187, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2394, 180425, 0, 1519, 5154, '0', 0, 0, -9021.1396484375, 862.16802978515625, 109.7559967041015625, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2395, 180425, 0, 1519, 5154, '0', 0, 0, -9008.9599609375, 892.13702392578125, 114.8509979248046875, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2396, 180425, 0, 1519, 5154, '0', 0, 0, -9016.26953125, 887.0159912109375, 113.529998779296875, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2397, 180425, 0, 1519, 5154, '0', 0, 0, -9018.66015625, 855.86102294921875, 108.6190032958984375, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2398, 180425, 0, 1519, 5154, '0', 0, 0, -9013.1201171875, 879.6939697265625, 112.7080001831054687, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2399, 180425, 0, 1519, 5154, '0', 0, 0, -9020.240234375, 859.00299072265625, 109.2900009155273437, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2400, 180425, 0, 1519, 5154, '0', 0, 0, -9016.26953125, 853.43402099609375, 107.7919998168945312, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2401, 180425, 0, 1519, 5154, '0', 0, 0, -9019.0498046875, 884.322998046875, 112.9789962768554687, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2402, 180425, 0, 1519, 5154, '0', 0, 0, -9022.9697265625, 872.43597412109375, 111.2040023803710937, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2403, 180425, 0, 1519, 5154, '0', 0, 0, -9021.51953125, 886.4169921875, 29.62070083618164062, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2404, 180425, 0, 1519, 5154, '0', 0, 0, -9022.8798828125, 868.53497314453125, 110.6460037231445312, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2405, 180425, 0, 1519, 5154, '0', 0, 0, -9022.0400390625, 876.0780029296875, 111.7389984130859375, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2406, 180425, 0, 1519, 5154, '0', 0, 0, -9021.0302734375, 880.093994140625, 112.3030014038085937, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2407, 180425, 0, 1519, 5154, '0', 0, 0, -9016.6796875, 890.29901123046875, 29.62070083618164062, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2408, 180425, 0, 1519, 5154, '0', 0, 0, -9022, 865.2919921875, 110.194000244140625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2409, 180425, 0, 1519, 5154, '0', 0, 0, -8890.73046875, 1023.67999267578125, 126.8130035400390625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2410, 180425, 0, 1519, 5154, '0', 0, 0, -8907.4697265625, 1026.6400146484375, 126.8130035400390625, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2411, 180425, 0, 1519, 5154, '0', 0, 0, -8897.0703125, 1029.1400146484375, 126.8130035400390625, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 45745), -- SkullCandle01 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2412, 180426, 0, 1519, 1617, '0', 0, 0, -8868.4267578125, 589.201416015625, 110.4854583740234375, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2413, 180426, 0, 1519, 1617, '0', 0, 0, -8866.7431640625, 590.37677001953125, 109.8223037719726562, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2414, 180426, 0, 1519, 1617, '0', 0, 0, -8866.826171875, 590.55731201171875, 109.528961181640625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2415, 180426, 0, 1519, 1617, '0', 0, 0, -8866.919921875, 590.6199951171875, 113.1200027465820312, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2416, 180426, 0, 1519, 1617, '0', 0, 0, -8866.689453125, 590.46527099609375, 108.6035690307617187, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2417, 180426, 0, 1519, 1617, '0', 0, 0, -8866.7275390625, 590.40802001953125, 108.5781173706054687, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2418, 180426, 0, 1519, 1617, '0', 0, 0, -8868.2568359375, 592.171875, 108.4288711547851562, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2419, 180426, 0, 1519, 1617, '0', 0, 0, -8866.6923828125, 590.53125, 109.9772109985351562, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2420, 180426, 0, 1519, 1617, '0', 0, 0, -8864.7919921875, 591.75, 109.959808349609375, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2421, 180426, 0, 1519, 1617, '0', 0, 0, -8865.2763671875, 591.8211669921875, 108.950897216796875, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- Bat01 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2422, 180426, 0, 1519, 5390, '0', 0, 0, -8724.7197265625, 440.212005615234375, 110.2659988403320312, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2423, 180426, 0, 1519, 5390, '0', 0, 0, -8724.009765625, 439.52398681640625, 110.2570037841796875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2424, 180426, 0, 1519, 5390, '0', 0, 0, -8723.33984375, 442.2080078125, 111.5810012817382812, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2425, 180426, 0, 1519, 5390, '0', 0, 0, -8725.669921875, 407.60400390625, 107.9879989624023437, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2426, 180426, 0, 1519, 5390, '0', 0, 0, -8727.73046875, 407.02801513671875, 111.26300048828125, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2427, 180426, 0, 1519, 5390, '0', 0, 0, -8726.2197265625, 405.178985595703125, 110.444000244140625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2428, 180426, 0, 1519, 5390, '0', 0, 0, -8711.58984375, 409.334991455078125, 107.1740036010742187, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2429, 180426, 0, 1519, 5390, '0', 0, 0, -8707.0595703125, 407.57598876953125, 108.4300003051757812, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2430, 180426, 0, 1519, 5390, '0', 0, 0, -8707.9697265625, 409.464996337890625, 110.3199996948242187, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- Bat01 (Area: The Canals - Difficulty: 0)
(@OGUID+2431, 180426, 0, 1519, 5314, '0', 0, 0, -8386.3095703125, 630.2139892578125, 108.2699966430664062, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2432, 180426, 0, 1519, 5314, '0', 0, 0, -8383.9697265625, 628.75201416015625, 112.214996337890625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2433, 180426, 0, 1519, 5314, '0', 0, 0, -8382.8701171875, 626.74700927734375, 108.3300018310546875, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2434, 180426, 0, 1519, 5314, '0', 0, 0, -8383, 626.4110107421875, 108.4160003662109375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Bat01 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2435, 180426, 0, 1519, 5150, '0', 0, 0, -8355.0302734375, 631.26702880859375, 108.2559967041015625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- Bat01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2436, 180426, 0, 1519, 5150, '0', 0, 0, -8351.990234375, 634.81298828125, 107.5979995727539062, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- Bat01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2437, 180426, 0, 1519, 5150, '0', 0, 0, -8350.240234375, 633.66802978515625, 107.6129989624023437, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- Bat01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2438, 180426, 0, 1519, 5150, '0', 0, 0, -8349.740234375, 636.30902099609375, 107.6129989624023437, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- Bat01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2439, 180426, 0, 1519, 5150, '0', 0, 0, -8350.6796875, 630.4219970703125, 107.6309967041015625, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- Bat01 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2440, 180427, 0, 1519, 0, '0', 0, 0, -8823.19140625, 624.09027099609375, 111.6143875122070312, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2441, 180427, 0, 1519, 0, '0', 0, 0, -8822.9267578125, 627.28125, 113.2567901611328125, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2442, 180427, 0, 1519, 0, '0', 0, 0, -8822.66015625, 628.37298583984375, 114.1110000610351562, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2443, 180427, 0, 1519, 0, '0', 0, 0, -8820.650390625, 627.68597412109375, 115.042999267578125, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2444, 180427, 0, 1519, 0, '0', 0, 0, -8824.138671875, 628.16668701171875, 111.0650177001953125, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2445, 180427, 0, 1519, 0, '0', 0, 0, -8821.6982421875, 625.529541015625, 112.8369979858398437, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2446, 180427, 0, 1519, 0, '0', 0, 0, -8824.48828125, 626.263916015625, 115.6350479125976562, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2447, 180427, 0, 1519, 0, '0', 0, 0, -8821.3505859375, 628.5242919921875, 112.5537261962890625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2448, 180427, 0, 1519, 0, '0', 0, 0, -8822.9423828125, 627.170166015625, 110.6205215454101562, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+2449, 180427, 0, 1519, 5148, '0', 0, 0, -8822.2255859375, 630.09722900390625, 113.5167236328125, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Bat02 (Area: Trade District - Difficulty: 0)
(@OGUID+2450, 180428, 0, 1519, 1617, '0', 0, 0, -8848.3603515625, 507.761993408203125, 109.615997314453125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2451, 180428, 0, 1519, 5148, '0', 0, 0, -8872.4501953125, 676.86187744140625, 97.90305328369140625, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Trade District - Difficulty: 0)
(@OGUID+2452, 180428, 0, 1519, 5148, '0', 0, 0, -8664.2802734375, 507.196014404296875, 101.2829971313476562, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Trade District - Difficulty: 0)
(@OGUID+2453, 180428, 0, 1519, 5390, '0', 0, 0, -8507.259765625, 547.49798583984375, 97.8632965087890625, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2454, 180428, 0, 1519, 5149, '0', 0, 0, -8750.169921875, 375.093994140625, 101.0449981689453125, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Old Town - Difficulty: 0)
(@OGUID+2455, 180428, 0, 1519, 5150, '0', 0, 0, -8420.1796875, 543.56402587890625, 95.44840240478515625, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2456, 180428, 0, 1519, 5150, '0', 0, 0, -8466.7900390625, 625.65997314453125, 93.92659759521484375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2457, 180428, 0, 1519, 5314, '0', 0, 0, -8372.900390625, 682.83197021484375, 98.65309906005859375, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2458, 180429, 0, 1519, 1617, '0', 0, 0, -8847.669921875, 508.72698974609375, 112.457000732421875, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2459, 180429, 0, 1519, 1617, '0', 0, 0, -8968.078125, 497.26910400390625, 119.800537109375, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2460, 180429, 0, 1519, 5148, '0', 0, 0, -8762.169921875, 658.05401611328125, 108.19000244140625, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Trade District - Difficulty: 0)
(@OGUID+2461, 180429, 0, 1519, 5148, '0', 0, 0, -8808.8095703125, 691.04498291015625, 103.0270004272460937, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Trade District - Difficulty: 0)
(@OGUID+2462, 180429, 0, 1519, 5148, '0', 0, 0, -8873.669921875, 680.00701904296875, 98.65290069580078125, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Trade District - Difficulty: 0)
(@OGUID+2463, 180429, 0, 1519, 5390, '0', 0, 0, -8676.26953125, 485.113006591796875, 104.5490036010742187, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2464, 180429, 0, 1519, 5390, '0', 0, 0, -8734.3896484375, 391.694000244140625, 99.37969970703125, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2465, 180429, 0, 1519, 5390, '0', 0, 0, -8657.41015625, 505.295013427734375, 102.8489990234375, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2466, 180429, 0, 1519, 5390, '0', 0, 0, -8627.240234375, 463.468994140625, 104.2379989624023437, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2467, 180429, 0, 1519, 5390, '0', 0, 0, -8509.2099609375, 547.68597412109375, 101.5889968872070312, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2468, 180429, 0, 1519, 5149, '0', 0, 0, -8712.0302734375, 362.506988525390625, 104.4039993286132812, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Old Town - Difficulty: 0)
(@OGUID+2469, 180429, 0, 1519, 5149, '0', 0, 0, -8719.2802734375, 364.990997314453125, 104.3830032348632812, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Old Town - Difficulty: 0)
(@OGUID+2470, 180429, 0, 1519, 5149, '0', 0, 0, -8726.9599609375, 367.2030029296875, 104.1439971923828125, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Old Town - Difficulty: 0)
(@OGUID+2471, 180429, 0, 1519, 5149, '0', 0, 0, -8732.25, 372.52801513671875, 104.21099853515625, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Old Town - Difficulty: 0)
(@OGUID+2472, 180429, 0, 1519, 5390, '0', 0, 0, -8605.41015625, 696.802001953125, 98.676300048828125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2473, 180429, 0, 1519, 5150, '0', 0, 0, -8417.0703125, 557.13397216796875, 96.37259674072265625, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2474, 180429, 0, 1519, 5150, '0', 0, 0, -8465.6201171875, 625.48797607421875, 97.16770172119140625, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Dwarven District - Difficulty: 0)
(@OGUID+2475, 180429, 0, 1519, 5390, '0', 0, 0, -8413.080078125, 680.03997802734375, 99.42669677734375, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2476, 180429, 0, 1519, 5314, '0', 0, 0, -8378.4501953125, 678.88397216796875, 99.75730133056640625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2477, 180429, 0, 1519, 5314, '0', 0, 0, -8376.9599609375, 679.92401123046875, 98.65309906005859375, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2478, 180429, 0, 1519, 5390, '0', 0, 0, -8636.3095703125, 763.5780029296875, 106.4110031127929687, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2479, 180429, 0, 1519, 5390, '0', 0, 0, -8682.6796875, 777.8800048828125, 100.660003662109375, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2480, 180429, 0, 1519, 5390, '0', 0, 0, -8881.8798828125, 824.83001708984375, 96.7006988525390625, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: The Canals - Difficulty: 0)
(@OGUID+2481, 180429, 0, 1519, 5154, '0', 0, 0, -9034.7197265625, 882.35198974609375, 112.2220001220703125, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2482, 180429, 0, 1519, 5154, '0', 0, 0, -8921.7900390625, 966.5, 118.602996826171875, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2483, 180429, 0, 1519, 5154, '0', 0, 0, -9014.009765625, 958.375, 119.3860015869140625, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- G_WitchHat_01 scale 0.5 (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2484, 180431, 0, 1519, 1617, '0', 0, 0, -8675.6103515625, 637.97198486328125, 98.91989898681640625, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2485, 180431, 0, 1519, 1617, '0', 0, 0, -8947.0400390625, 543.66668701171875, 117.9991226196289062, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2486, 180431, 0, 1519, 1617, '0', 0, 0, -8733.830078125, 383.446014404296875, 114.9919967651367187, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2487, 180431, 0, 1519, 1617, '0', 0, 0, -8931.080078125, 523.22918701171875, 118.0772628784179687, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2488, 180431, 0, 1519, 1617, '0', 0, 0, -8766.2001953125, 386.239990234375, 114.9919967651367187, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2489, 180431, 0, 1519, 1617, '0', 0, 0, -8910.4599609375, 792.093994140625, 102.839996337890625, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2490, 180431, 0, 1519, 1617, '0', 0, 0, -8681.8095703125, 581.5360107421875, 98.91719818115234375, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2491, 180431, 0, 1519, 0, '0', 0, 0, -8510.6103515625, 321.04901123046875, 135.7100067138671875, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: 0 - Difficulty: 0)
(@OGUID+2492, 180431, 0, 1519, 0, '0', 0, 0, -8578.1904296875, 786.23602294921875, 145.490997314453125, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: 0 - Difficulty: 0)
(@OGUID+2493, 180431, 0, 1519, 0, '0', 0, 0, -8459.650390625, 591.22100830078125, 106.5800018310546875, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: 0 - Difficulty: 0)
(@OGUID+2494, 180431, 0, 1519, 0, '0', 0, 0, -8601.099609375, 815.593994140625, 144.2610015869140625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: 0 - Difficulty: 0)
(@OGUID+2495, 180431, 0, 1519, 5148, '0', 0, 0, -8431.0400390625, 352.779998779296875, 135.910003662109375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Trade District - Difficulty: 0)
(@OGUID+2496, 180431, 0, 1519, 5148, '0', 0, 0, -8415.400390625, 398.15301513671875, 135.7100067138671875, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Trade District - Difficulty: 0)
(@OGUID+2497, 180431, 0, 1519, 5148, '0', 0, 0, -8465.2900390625, 323.566009521484375, 135.9120025634765625, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Trade District - Difficulty: 0)
(@OGUID+2498, 180431, 0, 1519, 5397, '0', 0, 0, -8206.78125, 1112.76171875, 74.21324920654296875, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2499, 180431, 0, 1519, 9171, '0', 0, 0, -8253.82421875, 1203.78515625, 24.26126861572265625, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2500, 180431, 0, 1519, 9171, '0', 0, 0, -8132.82568359375, 1235.3883056640625, 54.4760589599609375, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2501, 180431, 0, 1519, 9171, '0', 0, 0, -8215.140625, 1245.4820556640625, 17.3520355224609375, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2502, 180431, 0, 1519, 5316, '0', 0, 0, -8544.1083984375, 1106.2508544921875, 23.67501449584960937, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2503, 180431, 0, 1519, 5316, '0', 0, 0, -8610.330078125, 1112.7100830078125, 25.37889480590820312, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2504, 180431, 0, 1519, 5346, '0', 0, 0, -8153.18994140625, 1279.2008056640625, 55.16509628295898437, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2505, 180431, 0, 1519, 5346, '0', 0, 0, -8274.8876953125, 1301.0423583984375, 8.513222694396972656, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2506, 180431, 0, 1519, 5346, '0', 0, 0, -8527.5322265625, 1203.58935546875, 24.28193855285644531, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2507, 180431, 0, 1519, 5346, '0', 0, 0, -8306.802734375, 1302.5751953125, 8.516176223754882812, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2508, 180431, 0, 1519, 5346, '0', 0, 0, -8123.27197265625, 1321.197509765625, 54.99076461791992187, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2509, 180431, 0, 1519, 4411, '0', 0, 0, -8091.08154296875, 1366.6627197265625, 55.11731338500976562, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2510, 180431, 0, 1519, 4411, '0', 0, 0, -8042.79248046875, 1365.368896484375, 54.47701263427734375, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2511, 180431, 0, 1519, 4411, '0', 0, 0, -8044.19091796875, 1337.7421875, 7.799363136291503906, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2512, 180431, 0, 1519, 4411, '0', 0, 0, -8062.8427734375, 1624.8101806640625, 53.78834915161132812, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2513, 180431, 0, 1519, 4411, '0', 0, 0, -8048.6552734375, 1658.8914794921875, 53.8226470947265625, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2514, 180471, 0, 1519, 0, '0', 0, 0, -8808.5595703125, 617.4110107421875, 101.1279983520507812, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+2515, 180471, 0, 1519, 5148, '0', 0, 0, -8798.3203125, 625.6820068359375, 101.1200027465820312, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Trade District - Difficulty: 0)
(@OGUID+2516, 180471, 0, 1519, 5148, '0', 0, 0, -8860.1005859375, 661.86285400390625, 100.9490127563476562, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Trade District - Difficulty: 0)
(@OGUID+2517, 180471, 0, 1519, 4411, '0', 0, 0, -8199.5048828125, 1194.451416015625, 7.82195901870727539, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2518, 180471, 0, 1519, 4411, '0', 0, 0, -8212.94140625, 1194.4478759765625, 7.726465225219726562, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2519, 180471, 0, 1519, 4411, '0', 0, 0, -8294.47265625, 1194.560791015625, 7.659937858581542968, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2520, 180471, 0, 1519, 4411, '0', 0, 0, -8307.796875, 1194.529541015625, 7.646907806396484375, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2521, 180471, 0, 1519, 4411, '0', 0, 0, -8354.248046875, 1194.4913330078125, 7.71483612060546875, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2522, 180471, 0, 1519, 4411, '0', 0, 0, -8367.6474609375, 1194.1666259765625, 7.844985008239746093, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2523, 180471, 0, 1519, 4411, '0', 0, 0, -8426.8876953125, 1194.1649169921875, 7.871457099914550781, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2524, 180471, 0, 1519, 4411, '0', 0, 0, -8413.482421875, 1194.078125, 7.815581798553466796, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2525, 180471, 0, 1519, 4411, '0', 0, 0, -8568.3232421875, 1194.5240478515625, 7.608767986297607421, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2526, 180471, 0, 1519, 4411, '0', 0, 0, -8581.740234375, 1194.3199462890625, 7.690979957580566406, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2527, 180471, 0, 1519, 4411, '0', 0, 0, -8486.7412109375, 1194.3836669921875, 7.648921012878417968, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2528, 180471, 0, 1519, 4411, '0', 0, 0, -8473.3564453125, 1194.388916015625, 7.639770030975341796, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2529, 180472, 0, 1519, 0, '0', 0, 0, -8832.6748046875, 608.79473876953125, 99.90030670166015625, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+2530, 180523, 0, 1519, 5148, '0', 0, 0, -8860.0087890625, 674.44964599609375, 98.62528228759765625, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- Apple Bob (Area: Trade District - Difficulty: 0)
(@OGUID+2531, 190040, 0, 1519, 5148, '0', 0, 0, -8868.4677734375, 671.550048828125, 97.90305328369140625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- Candy Bucket (Area: Trade District - Difficulty: 0)
(@OGUID+2532, 207941, 0, 1519, 1617, '0', 0, 0, -9014.439453125, 491.8350830078125, 113.01654052734375, 0.041934803128242492, -0.2709670066833496, -0.02792263031005859, 0.013899803161621093, 0.962083160877227783, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2533, 207941, 0, 1519, 1617, '0', 0, 0, -8984.701171875, 515.888916015625, 117.8699417114257812, 6.193559169769287109, -0.18053054809570312, 0.021940231323242187, -0.04150295257568359, 0.982448399066925048, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2534, 207941, 0, 1519, 1617, '0', 0, 0, -8946.732421875, 527.16668701171875, 117.7123184204101562, 5.426842689514160156, 0.146994590759277343, -0.08044242858886718, -0.40746307373046875, 0.897716820240020751, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2535, 207941, 0, 1519, 1617, '0', 0, 0, -8996.171875, 469.18402099609375, 118.0076828002929687, 4.166365623474121093, -0.10196256637573242, 0.166020393371582031, -0.85560131072998046, 0.479569882154464721, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2536, 207941, 0, 1519, 1617, '0', 0, 0, -8966.0537109375, 492.15625, 115.5300064086914062, 4.643191337585449218, -0.17319250106811523, 0.189394950866699218, -0.70618724822998046, 0.659873783588409423, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2537, 207941, 0, 1519, 5390, '0', 0, 0, -8509.857421875, 1040.8680419921875, 78.7204132080078125, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: The Canals - Difficulty: 0)
(@OGUID+2538, 207941, 0, 1519, 5390, '0', 0, 0, -8410.580078125, 1039.638916015625, 80.66770172119140625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- G_WitchHat_01 scale 2.0 (Area: The Canals - Difficulty: 0)
(@OGUID+2539, 208200, 0, 1519, 1617, '0', 0, 0, -8863.8017578125, 495.6842041015625, 139.6806640625, 2.96634221076965332, 0, 0, 0.996163368225097656, 0.087513089179992675, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2540, 208200, 0, 1519, 1617, '0', 0, 0, -8979.798828125, 552.89239501953125, 93.9832763671875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2541, 208200, 0, 1519, 0, '0', 0, 0, -8774.904296875, 469.8819580078125, 97.8048248291015625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2542, 208200, 0, 1519, 5148, '0', 0, 0, -8794.5712890625, 661.45660400390625, 99.51605987548828125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2543, 208200, 0, 1519, 5148, '0', 0, 0, -8788.65625, 681.310791015625, 102.2081680297851562, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2544, 208200, 0, 1519, 5148, '0', 0, 0, -8951.607421875, 564.38018798828125, 93.80486297607421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2545, 208200, 0, 1519, 5148, '0', 0, 0, -8914.390625, 712.3680419921875, 97.8031463623046875, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2546, 208200, 0, 1519, 5148, '0', 0, 0, -8896.69140625, 736.60589599609375, 96.89354705810546875, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2547, 208200, 0, 1519, 5148, '0', 0, 0, -8871.2294921875, 761.05902099609375, 96.80912017822265625, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2548, 208200, 0, 1519, 5148, '0', 0, 0, -8716.4775390625, 736.44964599609375, 97.816680908203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2549, 208200, 0, 1519, 5148, '0', 0, 0, -8686.50390625, 696.53302001953125, 97.8075103759765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2550, 208200, 0, 1519, 5148, '0', 0, 0, -8665.216796875, 555.30902099609375, 97.0092315673828125, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2551, 208200, 0, 1519, 5390, '0', 0, 0, -8755.4306640625, 391.166656494140625, 101.05584716796875, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2552, 208200, 0, 1519, 5390, '0', 0, 0, -8685.5087890625, 440.5, 99.4211883544921875, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2553, 208200, 0, 1519, 5390, '0', 0, 0, -8674.158203125, 456.357635498046875, 99.69423675537109375, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2554, 208200, 0, 1519, 5390, '0', 0, 0, -8572.6298828125, 607.13018798828125, 103.04180908203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2555, 208200, 0, 1519, 5390, '0', 0, 0, -8587.6982421875, 573.96527099609375, 102.9899063110351562, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2556, 208200, 0, 1519, 5390, '0', 0, 0, -8570.4130859375, 534.96527099609375, 101.6621475219726562, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2557, 208200, 0, 1519, 5390, '0', 0, 0, -8535.9775390625, 462.635406494140625, 104.7054672241210937, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2558, 208200, 0, 1519, 5390, '0', 0, 0, -8530.9580078125, 488.348968505859375, 101.3557205200195312, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2559, 208200, 0, 1519, 5390, '0', 0, 0, -8502.3955078125, 531.9461669921875, 97.884307861328125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2560, 208200, 0, 1519, 5390, '0', 0, 0, -8521.4375, 432.607635498046875, 105.5919036865234375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2561, 208200, 0, 1519, 5390, '0', 0, 0, -8512.2724609375, 407.66839599609375, 114.6888275146484375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2562, 208200, 0, 1519, 5149, '0', 0, 0, -8680.265625, 397.770843505859375, 102.8208999633789062, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2563, 208200, 0, 1519, 5149, '0', 0, 0, -8732.0888671875, 356.921875, 101.54779052734375, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2564, 208200, 0, 1519, 5149, '0', 0, 0, -8775.1826171875, 361.22222900390625, 102.1217269897460937, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2565, 208200, 0, 1519, 5390, '0', 0, 0, -8628.8544921875, 653.01214599609375, 100.2357177734375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2566, 208200, 0, 1519, 5390, '0', 0, 0, -8581.0361328125, 659.63018798828125, 97.76206207275390625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2567, 208200, 0, 1519, 5390, '0', 0, 0, -8663.064453125, 666.0242919921875, 100.4435806274414062, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2568, 208200, 0, 1519, 5390, '0', 0, 0, -8525.6455078125, 597, 101.5036392211914062, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2569, 208200, 0, 1519, 5390, '0', 0, 0, -8617.875, 707.1492919921875, 96.79084014892578125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2570, 208200, 0, 1519, 5390, '0', 0, 0, -8449.486328125, 414.81597900390625, 127.3631591796875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2571, 208200, 0, 1519, 5390, '0', 0, 0, -8538.8125, 352.22222900390625, 127.3596725463867187, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2572, 208200, 0, 1519, 5390, '0', 0, 0, -8465.326171875, 518.55731201171875, 97.44629669189453125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2573, 208200, 0, 1519, 5390, '0', 0, 0, -8466.3408203125, 346.102447509765625, 135.559173583984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2574, 208200, 0, 1519, 5390, '0', 0, 0, -8443.01953125, 379.31597900390625, 135.6985626220703125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2575, 208200, 0, 1519, 5390, '0', 0, 0, -8424.08203125, 398.036468505859375, 135.70953369140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2576, 208200, 0, 1519, 0, '0', 0, 0, -8507.0712890625, 323.932281494140625, 135.7095489501953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2577, 208200, 0, 1519, 5150, '0', 0, 0, -8484.310546875, 567.0711669921875, 97.63311004638671875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2578, 208200, 0, 1519, 5150, '0', 0, 0, -8448.201171875, 579.545166015625, 94.70218658447265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2579, 208200, 0, 1519, 5150, '0', 0, 0, -8395.794921875, 577.91839599609375, 91.90716552734375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2580, 208200, 0, 1519, 5150, '0', 0, 0, -8474.265625, 616.62847900390625, 94.77588653564453125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2581, 208200, 0, 1519, 5390, '0', 0, 0, -8508.8955078125, 650.2899169921875, 100.4284515380859375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2582, 208200, 0, 1519, 5390, '0', 0, 0, -8536.2451171875, 688.71527099609375, 97.73018646240234375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2583, 208200, 0, 1519, 5390, '0', 0, 0, -8457.857421875, 635.3836669921875, 92.14090728759765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2584, 208200, 0, 1519, 5390, '0', 0, 0, -8478.26953125, 699.25518798828125, 99.906982421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2585, 208200, 0, 1519, 5390, '0', 0, 0, -8490.4111328125, 723.21527099609375, 98.2725067138671875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2586, 208200, 0, 1519, 5390, '0', 0, 0, -8429.5537109375, 623.77606201171875, 95.580322265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2587, 208200, 0, 1519, 5390, '0', 0, 0, -8420.125, 669.7413330078125, 94.86358642578125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2588, 208200, 0, 1519, 5314, '0', 0, 0, -8384.923828125, 657.16668701171875, 95.09046173095703125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Stormwind Lake - Difficulty: 0)
(@OGUID+2589, 208200, 0, 1519, 5150, '0', 0, 0, -8378.28125, 621.8211669921875, 95.281524658203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2590, 208200, 0, 1519, 5150, '0', 0, 0, -8348.955078125, 636.435791015625, 95.28574371337890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Dwarven District - Difficulty: 0)
(@OGUID+2591, 208200, 0, 1519, 0, '0', 0, 0, -8553.8056640625, 902.4774169921875, 100.1356277465820312, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2592, 208200, 0, 1519, 0, '0', 0, 0, -8569.1181640625, 916.9375, 99.0742645263671875, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2593, 208200, 0, 1519, 0, '0', 0, 0, -8572.6787109375, 873.02606201171875, 99.0214996337890625, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2594, 208200, 0, 1519, 0, '0', 0, 0, -8559.138671875, 762.592041015625, 98.7698516845703125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2595, 208200, 0, 1519, 5390, '0', 0, 0, -8591.22265625, 725.09552001953125, 96.78870391845703125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2596, 208200, 0, 1519, 5390, '0', 0, 0, -8609.4423828125, 758.45489501953125, 97.00072479248046875, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2597, 208200, 0, 1519, 5390, '0', 0, 0, -8654.0380859375, 750.76214599609375, 96.89575958251953125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2598, 208200, 0, 1519, 5390, '0', 0, 0, -8730.455078125, 769.263916015625, 98.27042388916015625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2599, 208200, 0, 1519, 5390, '0', 0, 0, -8635.955078125, 791.4444580078125, 96.92075347900390625, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2600, 208200, 0, 1519, 5390, '0', 0, 0, -8731.1474609375, 810.9288330078125, 97.36168670654296875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2601, 208200, 0, 1519, 5390, '0', 0, 0, -8710.904296875, 859.31597900390625, 97.29990386962890625, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2602, 208200, 0, 1519, 8411, '0', 0, 0, -8814.8837890625, 884.57464599609375, 98.64136505126953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2603, 208200, 0, 1519, 8411, '0', 0, 0, -8646.767578125, 830.94097900390625, 96.72496795654296875, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2604, 208200, 0, 1519, 5390, '0', 0, 0, -8888.8349609375, 882.638916015625, 101.55670166015625, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2605, 208200, 0, 1519, 5390, '0', 0, 0, -8664.3349609375, 894.98614501953125, 97.65045928955078125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2606, 208200, 0, 1519, 5390, '0', 0, 0, -8605.9619140625, 863.19097900390625, 96.9263916015625, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2607, 208200, 0, 1519, 5390, '0', 0, 0, -8625.1357421875, 916.94793701171875, 99.12198638916015625, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2608, 208200, 0, 1519, 5390, '0', 0, 0, -8600.2392578125, 901.451416015625, 98.15106964111328125, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2609, 208200, 0, 1519, 8411, '0', 0, 0, -8852.857421875, 941.78472900390625, 102.9796829223632812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2610, 208200, 0, 1519, 8411, '0', 0, 0, -8915.669921875, 950.63018798828125, 117.4099273681640625, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Lion's Rest - Difficulty: 0)
(@OGUID+2611, 208200, 0, 1519, 5390, '0', 0, 0, -8922.0908203125, 895.80206298828125, 106.0434036254882812, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2612, 208200, 0, 1519, 5390, '0', 0, 0, -8932.7431640625, 827.8524169921875, 100.3244400024414062, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2613, 208200, 0, 1519, 5148, '0', 0, 0, -8814.626953125, 618.05902099609375, 94.8343963623046875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2614, 208200, 0, 1519, 5154, '0', 0, 0, -9036.029296875, 853.078125, 107.1087417602539062, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2615, 208200, 0, 1519, 5154, '0', 0, 0, -8912.1298828125, 984.20489501953125, 121.7687530517578125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2616, 208200, 0, 1519, 5154, '0', 0, 0, -9009.470703125, 945.701416015625, 116.6879730224609375, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2617, 208200, 0, 1519, 5154, '0', 0, 0, -8835.98828125, 908.2725830078125, 98.21422576904296875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2618, 208200, 0, 1519, 5390, '0', 0, 0, -8932.7255859375, 774.44268798828125, 88.757720947265625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2619, 208200, 0, 1519, 5154, '0', 0, 0, -8897.966796875, 841.21527099609375, 97.85141754150390625, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2620, 208200, 0, 1519, 5154, '0', 0, 0, -8993.53125, 789.81427001953125, 104.0222015380859375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2621, 208200, 0, 1519, 5154, '0', 0, 0, -8961.2158203125, 861.890625, 105.7953033447265625, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2622, 208200, 0, 1519, 5154, '0', 0, 0, -8977.923828125, 960.1475830078125, 116.5874710083007812, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2623, 208200, 0, 1519, 5390, '0', 0, 0, -8704.6220703125, 464.01910400390625, 96.37821197509765625, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2624, 208200, 0, 1519, 5390, '0', 0, 0, -8723.56640625, 439.229156494140625, 97.76073455810546875, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2625, 208200, 0, 1519, 5390, '0', 0, 0, -8708.080078125, 410.0538330078125, 98.8643035888671875, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2626, 208200, 0, 1519, 5390, '0', 0, 0, -8732.685546875, 403.963531494140625, 97.93048858642578125, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2627, 208200, 0, 1519, 5390, '0', 0, 0, -8661.4306640625, 495.171875, 100.8976821899414062, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2628, 208200, 0, 1519, 5149, '0', 0, 0, -8633.888671875, 443.498260498046875, 102.5660324096679687, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2629, 208200, 0, 1519, 5149, '0', 0, 0, -8637.8955078125, 468.21875, 102.3682785034179687, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2630, 208200, 0, 1519, 5149, '0', 0, 0, -8647.20703125, 426.229156494140625, 101.6851882934570312, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2631, 208200, 0, 1519, 5149, '0', 0, 0, -8536.4619140625, 445.376739501953125, 105.3920364379882812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2632, 208200, 0, 1519, 5390, '0', 0, 0, -8627.21875, 767.56768798828125, 97.22624969482421875, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2633, 208200, 0, 1519, 5154, '0', 0, 0, -9003.080078125, 824.6649169921875, 105.2118606567382812, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2634, 208200, 0, 1519, 5154, '0', 0, 0, -8942.83203125, 954.9375, 117.107147216796875, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2635, 208200, 0, 1519, 5148, '0', 0, 0, -8841.138671875, 548.67706298828125, 96.6541595458984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2636, 208200, 0, 1519, 5149, '0', 0, 0, -8743.2900390625, 497.2882080078125, 96.81397247314453125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2637, 208200, 0, 1519, 1617, '0', 0, 0, -9033.9375, 459.2569580078125, 93.05583953857421875, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2638, 208200, 0, 1519, 5149, '0', 0, 0, -8617.1337890625, 525.23614501953125, 103.0858917236328125, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2639, 208200, 0, 1519, 5390, '0', 0, 0, -8826.6630859375, 813.76214599609375, 98.997711181640625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2640, 208200, 0, 1519, 0, '0', 0, 0, -9007.236328125, 483.02777099609375, 96.554229736328125, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+2641, 208200, 0, 1519, 5390, '0', 0, 0, -8809.3037109375, 576.17706298828125, 95.35125732421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2642, 208200, 0, 1519, 5148, '0', 0, 0, -8917.03125, 493.239593505859375, 93.8916778564453125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2643, 208200, 0, 1519, 1617, '0', 0, 0, -8985.4375, 492.552093505859375, 96.5129852294921875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2644, 208200, 0, 1519, 1617, '0', 0, 0, -9052.72265625, 435.23089599609375, 93.05583953857421875, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Valley of Heroes - Difficulty: 0)
(@OGUID+2645, 208200, 0, 1519, 5149, '0', 0, 0, -8585.2900390625, 481.84375, 104.3071365356445312, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Old Town - Difficulty: 0)
(@OGUID+2646, 208200, 0, 1519, 5390, '0', 0, 0, -8871.669921875, 575.078125, 93.6687469482421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2647, 208200, 0, 1519, 5154, '0', 0, 0, -8988.607421875, 851.01043701171875, 106.2628021240234375, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2648, 208200, 0, 1519, 5154, '0', 0, 0, -9007.2080078125, 903.60418701171875, 106.2579269409179687, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2649, 208200, 0, 1519, 5390, '0', 0, 0, -8819.388671875, 791.27081298828125, 97.22974395751953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2650, 208200, 0, 1519, 5148, '0', 0, 0, -8713.830078125, 519.33160400390625, 97.2005767822265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Trade District - Difficulty: 0)
(@OGUID+2651, 208200, 0, 1519, 5154, '0', 0, 0, -8800.9365234375, 766.1268310546875, 96.3380126953125, 1.924021124839782714, 0, 0, 0.820343017578125, 0.571871757507324218, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2652, 208200, 0, 1519, 5390, '0', 0, 0, -8801.1630859375, 882.3529052734375, 99.164215087890625, 0.154616773128509521, 0, 0, 0.077231407165527343, 0.997013211250305175, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: The Canals - Difficulty: 0)
(@OGUID+2653, 209034, 0, 1519, 4411, '0', 0, 0, -8515.001953125, 1305.795166015625, 6.09877634048461914, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- Courier Sword (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2654, 209059, 0, 1519, 5150, '0', 0, 0, -8267.4931640625, 677.44793701171875, 87.61673736572265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Dwarven District - Difficulty: 0)
(@OGUID+2655, 209059, 0, 1519, 5150, '0', 0, 0, -8247.73828125, 713.16143798828125, 77.28516387939453125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Dwarven District - Difficulty: 0)
(@OGUID+2656, 209059, 0, 1519, 5150, '0', 0, 0, -8234.06640625, 687.62152099609375, 71.282257080078125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Dwarven District - Difficulty: 0)
(@OGUID+2657, 209059, 0, 1519, 0, '0', 0, 0, -8202.97265625, 639.546875, 70.2944488525390625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: 0 - Difficulty: 0)
(@OGUID+2658, 209059, 0, 1519, 0, '0', 0, 0, -8170.7724609375, 594.546875, 72.55561065673828125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: 0 - Difficulty: 0)
(@OGUID+2659, 209059, 0, 1519, 0, '0', 0, 0, -8170.13525390625, 626.04168701171875, 69.2185516357421875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: 0 - Difficulty: 0)
(@OGUID+2660, 209059, 0, 1519, 5316, '0', 0, 0, -8081.6875, 589.7586669921875, 74.3907928466796875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2661, 209059, 0, 1519, 5316, '0', 0, 0, -8050.67529296875, 653.373291015625, 76.39299774169921875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2662, 209059, 0, 1519, 5316, '0', 0, 0, -8066.59033203125, 641.34722900390625, 71.9976348876953125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2663, 209059, 0, 1519, 5316, '0', 0, 0, -8098.095703125, 701.17535400390625, 69.86002349853515625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2664, 209059, 0, 1519, 5316, '0', 0, 0, -8153.61279296875, 767.44268798828125, 72.15294647216796875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2665, 209059, 0, 1519, 5316, '0', 0, 0, -8054.56591796875, 729.26910400390625, 68.32425689697265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2666, 209059, 0, 1519, 5316, '0', 0, 0, -8032.71728515625, 664.279541015625, 77.97415924072265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Olivia's Pond - Difficulty: 0)
(@OGUID+2667, 209059, 0, 1519, 5397, '0', 0, 0, -8030.72216796875, 753.26043701171875, 68.03456878662109375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2668, 209059, 0, 1519, 5397, '0', 0, 0, -8164.203125, 776.1007080078125, 76.89075469970703125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2669, 209059, 0, 1519, 5397, '0', 0, 0, -8003.658203125, 715.38018798828125, 75.07135009765625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2670, 209059, 0, 1519, 5397, '0', 0, 0, -8031.578125, 720.63543701171875, 68.5219268798828125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2671, 209059, 0, 1519, 5397, '0', 0, 0, -8052.51416015625, 815.06597900390625, 67.3348541259765625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2672, 209059, 0, 1519, 5397, '0', 0, 0, -8007.78662109375, 769.515625, 69.13167572021484375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2673, 209059, 0, 1519, 5397, '0', 0, 0, -8046.66845703125, 800.232666015625, 66.9988555908203125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2674, 209059, 0, 1519, 5397, '0', 0, 0, -8026.0849609375, 777.23785400390625, 66.65221405029296875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2675, 209059, 0, 1519, 5397, '0', 0, 0, -8019.91650390625, 802.5086669921875, 68.22495269775390625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2676, 209059, 0, 1519, 5397, '0', 0, 0, -8037.75537109375, 847.49652099609375, 66.18456268310546875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2677, 209059, 0, 1519, 5397, '0', 0, 0, -8083.939453125, 832.68231201171875, 70.044677734375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2678, 209059, 0, 1519, 5397, '0', 0, 0, -8109.15625, 831.9617919921875, 74.74655914306640625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2679, 209059, 0, 1519, 5397, '0', 0, 0, -8042.265625, 866.83856201171875, 66.416900634765625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2680, 209059, 0, 1519, 5397, '0', 0, 0, -7963.49658203125, 825.59722900390625, 82.38146209716796875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2681, 209059, 0, 1519, 5397, '0', 0, 0, -8166.84033203125, 796.29864501953125, 74.35816192626953125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2682, 209059, 0, 1519, 5397, '0', 0, 0, -8011.15966796875, 881.0625, 64.75502777099609375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2683, 209059, 0, 1519, 5397, '0', 0, 0, -8109.74853515625, 882.359375, 75.08420562744140625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: The Wollerton Stead - Difficulty: 0)
(@OGUID+2684, 209059, 0, 1519, 9171, '0', 0, 0, -8189.48095703125, 819.61114501953125, 70.4376220703125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2685, 209059, 0, 1519, 9171, '0', 0, 0, -8195.03515625, 879.9305419921875, 69.99567413330078125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2686, 209059, 0, 1519, 9171, '0', 0, 0, -8214.4462890625, 856.86114501953125, 72.41144561767578125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2687, 209059, 0, 1519, 9171, '0', 0, 0, -8153.02099609375, 898.47222900390625, 73.25392913818359375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2688, 209059, 0, 1519, 9171, '0', 0, 0, -8107.74462890625, 902.80206298828125, 72.53740692138671875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2689, 209059, 0, 1519, 9171, '0', 0, 0, -8159.0224609375, 922.30731201171875, 70.67058563232421875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2690, 209059, 0, 1519, 9171, '0', 0, 0, -8207.2099609375, 772.37677001953125, 73.281768798828125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2691, 209059, 0, 1519, 9171, '0', 0, 0, -8244.73828125, 767.90106201171875, 78.76136016845703125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind Embassy - Difficulty: 0)
(@OGUID+2692, 209059, 0, 1519, 5398, '0', 0, 0, -8068.46728515625, 949.83331298828125, 71.8757171630859375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind City Outskirts - Difficulty: 0)
(@OGUID+2693, 209059, 0, 1519, 5398, '0', 0, 0, -8055.91845703125, 982.31597900390625, 71.22203826904296875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- Blood Nettle (Area: Stormwind City Outskirts - Difficulty: 0)
(@OGUID+2694, 209064, 0, 1519, 5390, '0', 0, 0, -8496.0400390625, 762.54339599609375, 79.47483062744140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: The Canals - Difficulty: 0)
(@OGUID+2695, 209064, 0, 1519, 0, '0', 0, 0, -8463.513671875, 810.76214599609375, 81.61014556884765625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+2696, 209064, 0, 1519, 0, '0', 0, 0, -8507.640625, 803.625, 82.271392822265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+2697, 209064, 0, 1519, 0, '0', 0, 0, -8520.982421875, 792.95831298828125, 81.6150360107421875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+2698, 209064, 0, 1519, 0, '0', 0, 0, -8486.248046875, 795.951416015625, 81.60652923583984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+2699, 209065, 0, 1519, 5390, '0', 0, 0, -8499.1845703125, 761.22222900390625, 72.602783203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning 2 (Area: The Canals - Difficulty: 0)
(@OGUID+2700, 209072, 0, 1519, 5390, '0', 0, 0, -8498.607421875, 760.45831298828125, 72.71259307861328125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- Stolen Crate (Area: The Canals - Difficulty: 0)
(@OGUID+2701, 209076, 0, 1519, 5148, '0', 0, 0, -8865.2470703125, 679.08160400390625, 97.9030609130859375, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- Anson's Crate (Area: Trade District - Difficulty: 0)
(@OGUID+2702, 209076, 0, 1519, 5150, '0', 0, 0, -8384.1142578125, 592.23785400390625, 97.77840423583984375, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745); -- Anson's Crate (Area: Dwarven District - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` IN (@OGUID+2701, @OGUID+2702);
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2701, 0, 0, 0, 1, 16, 1500, 0, 0), -- Anson's Crate
(@OGUID+2702, 0, 0, 0, 1, 16, 1500, 0, 0); -- Anson's Crate

-- Human Commoner spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN 850253 AND 850262;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, 850253),
(12, 850254),
(12, 850255),
(12, 850256),
(12, 850257),
(12, 850258),
(12, 850259),
(12, 850260),
(12, 850261),
(12, 850262);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0), 
(12, @CGUID+1), 
(12, @CGUID+2), 
(12, @CGUID+3), 
(12, @CGUID+4), 
(12, @CGUID+5), 
(12, @CGUID+6), 
(12, @CGUID+7), 
(12, @CGUID+8), 
(12, @CGUID+9), 
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15),
(12, @CGUID+16),
(12, @CGUID+17),
(12, @CGUID+18),
(12, @CGUID+19),
(12, @CGUID+20),
(12, @CGUID+21),
(12, @CGUID+22),
(12, @CGUID+23),
(12, @CGUID+24),
(12, @CGUID+25),
(12, @CGUID+26),
(12, @CGUID+27),
(12, @CGUID+28),
(12, @CGUID+29),
(12, @CGUID+30),
(12, @CGUID+31),
(12, @CGUID+32),
(12, @CGUID+33),
(12, @CGUID+34),
(12, @CGUID+35),
(12, @CGUID+36),
(12, @CGUID+37),
(12, @CGUID+38),
(12, @CGUID+39),
(12, @CGUID+40),
(12, @CGUID+41),
(12, @CGUID+42),
(12, @CGUID+43),
(12, @CGUID+44),
(12, @CGUID+45),
(12, @CGUID+46),
(12, @CGUID+47),
(12, @CGUID+48),
(12, @CGUID+49),
(12, @CGUID+50),
(12, @CGUID+51),
(12, @CGUID+52),
(12, @CGUID+53),
(12, @CGUID+54),
(12, @CGUID+55),
(12, @CGUID+56),
(12, @CGUID+57),
(12, @CGUID+58),
(12, @CGUID+59),
(12, @CGUID+60),
(12, @CGUID+61);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+2702;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46),
(12, @OGUID+47),
(12, @OGUID+48),
(12, @OGUID+49),
(12, @OGUID+50),
(12, @OGUID+51),
(12, @OGUID+52),
(12, @OGUID+53),
(12, @OGUID+54),
(12, @OGUID+55),
(12, @OGUID+56),
(12, @OGUID+57),
(12, @OGUID+58),
(12, @OGUID+59),
(12, @OGUID+60),
(12, @OGUID+61),
(12, @OGUID+62),
(12, @OGUID+63),
(12, @OGUID+64),
(12, @OGUID+65),
(12, @OGUID+66),
(12, @OGUID+67),
(12, @OGUID+68),
(12, @OGUID+69),
(12, @OGUID+70),
(12, @OGUID+71),
(12, @OGUID+72),
(12, @OGUID+73),
(12, @OGUID+74),
(12, @OGUID+75),
(12, @OGUID+76),
(12, @OGUID+77),
(12, @OGUID+78),
(12, @OGUID+79),
(12, @OGUID+80),
(12, @OGUID+81),
(12, @OGUID+82),
(12, @OGUID+83),
(12, @OGUID+84),
(12, @OGUID+85),
(12, @OGUID+86),
(12, @OGUID+87),
(12, @OGUID+88),
(12, @OGUID+89),
(12, @OGUID+90),
(12, @OGUID+91),
(12, @OGUID+92),
(12, @OGUID+93),
(12, @OGUID+94),
(12, @OGUID+95),
(12, @OGUID+96),
(12, @OGUID+97),
(12, @OGUID+98),
(12, @OGUID+99),
(12, @OGUID+100),
(12, @OGUID+101),
(12, @OGUID+102),
(12, @OGUID+103),
(12, @OGUID+104),
(12, @OGUID+105),
(12, @OGUID+106),
(12, @OGUID+107),
(12, @OGUID+108),
(12, @OGUID+109),
(12, @OGUID+110),
(12, @OGUID+111),
(12, @OGUID+112),
(12, @OGUID+113),
(12, @OGUID+114),
(12, @OGUID+115),
(12, @OGUID+116),
(12, @OGUID+117),
(12, @OGUID+118),
(12, @OGUID+119),
(12, @OGUID+120),
(12, @OGUID+121),
(12, @OGUID+122),
(12, @OGUID+123),
(12, @OGUID+124),
(12, @OGUID+125),
(12, @OGUID+126),
(12, @OGUID+127),
(12, @OGUID+128),
(12, @OGUID+129),
(12, @OGUID+130),
(12, @OGUID+131),
(12, @OGUID+132),
(12, @OGUID+133),
(12, @OGUID+134),
(12, @OGUID+135),
(12, @OGUID+136),
(12, @OGUID+137),
(12, @OGUID+138),
(12, @OGUID+139),
(12, @OGUID+140),
(12, @OGUID+141),
(12, @OGUID+142),
(12, @OGUID+143),
(12, @OGUID+144),
(12, @OGUID+145),
(12, @OGUID+146),
(12, @OGUID+147),
(12, @OGUID+148),
(12, @OGUID+149),
(12, @OGUID+150),
(12, @OGUID+151),
(12, @OGUID+152),
(12, @OGUID+153),
(12, @OGUID+154),
(12, @OGUID+155),
(12, @OGUID+156),
(12, @OGUID+157),
(12, @OGUID+158),
(12, @OGUID+159),
(12, @OGUID+160),
(12, @OGUID+161),
(12, @OGUID+162),
(12, @OGUID+163),
(12, @OGUID+164),
(12, @OGUID+165),
(12, @OGUID+166),
(12, @OGUID+167),
(12, @OGUID+168),
(12, @OGUID+169),
(12, @OGUID+170),
(12, @OGUID+171),
(12, @OGUID+172),
(12, @OGUID+173),
(12, @OGUID+174),
(12, @OGUID+175),
(12, @OGUID+176),
(12, @OGUID+177),
(12, @OGUID+178),
(12, @OGUID+179),
(12, @OGUID+180),
(12, @OGUID+181),
(12, @OGUID+182),
(12, @OGUID+183),
(12, @OGUID+184),
(12, @OGUID+185),
(12, @OGUID+186),
(12, @OGUID+187),
(12, @OGUID+188),
(12, @OGUID+189),
(12, @OGUID+190),
(12, @OGUID+191),
(12, @OGUID+192),
(12, @OGUID+193),
(12, @OGUID+194),
(12, @OGUID+195),
(12, @OGUID+196),
(12, @OGUID+197),
(12, @OGUID+198),
(12, @OGUID+199),
(12, @OGUID+200),
(12, @OGUID+201),
(12, @OGUID+202),
(12, @OGUID+203),
(12, @OGUID+204),
(12, @OGUID+205),
(12, @OGUID+206),
(12, @OGUID+207),
(12, @OGUID+208),
(12, @OGUID+209),
(12, @OGUID+210),
(12, @OGUID+211),
(12, @OGUID+212),
(12, @OGUID+213),
(12, @OGUID+214),
(12, @OGUID+215),
(12, @OGUID+216),
(12, @OGUID+217),
(12, @OGUID+218),
(12, @OGUID+219),
(12, @OGUID+220),
(12, @OGUID+221),
(12, @OGUID+222),
(12, @OGUID+223),
(12, @OGUID+224),
(12, @OGUID+225),
(12, @OGUID+226),
(12, @OGUID+227),
(12, @OGUID+228),
(12, @OGUID+229),
(12, @OGUID+230),
(12, @OGUID+231),
(12, @OGUID+232),
(12, @OGUID+233),
(12, @OGUID+234),
(12, @OGUID+235),
(12, @OGUID+236),
(12, @OGUID+237),
(12, @OGUID+238),
(12, @OGUID+239),
(12, @OGUID+240),
(12, @OGUID+241),
(12, @OGUID+242),
(12, @OGUID+243),
(12, @OGUID+244),
(12, @OGUID+245),
(12, @OGUID+246),
(12, @OGUID+247),
(12, @OGUID+248),
(12, @OGUID+249),
(12, @OGUID+250),
(12, @OGUID+251),
(12, @OGUID+252),
(12, @OGUID+253),
(12, @OGUID+254),
(12, @OGUID+255),
(12, @OGUID+256),
(12, @OGUID+257),
(12, @OGUID+258),
(12, @OGUID+259),
(12, @OGUID+260),
(12, @OGUID+261),
(12, @OGUID+262),
(12, @OGUID+263),
(12, @OGUID+264),
(12, @OGUID+265),
(12, @OGUID+266),
(12, @OGUID+267),
(12, @OGUID+268),
(12, @OGUID+269),
(12, @OGUID+270),
(12, @OGUID+271),
(12, @OGUID+272),
(12, @OGUID+273),
(12, @OGUID+274),
(12, @OGUID+275),
(12, @OGUID+276),
(12, @OGUID+277),
(12, @OGUID+278),
(12, @OGUID+279),
(12, @OGUID+280),
(12, @OGUID+281),
(12, @OGUID+282),
(12, @OGUID+283),
(12, @OGUID+284),
(12, @OGUID+285),
(12, @OGUID+286),
(12, @OGUID+287),
(12, @OGUID+288),
(12, @OGUID+289),
(12, @OGUID+290),
(12, @OGUID+291),
(12, @OGUID+292),
(12, @OGUID+293),
(12, @OGUID+294),
(12, @OGUID+295),
(12, @OGUID+296),
(12, @OGUID+297),
(12, @OGUID+298),
(12, @OGUID+299),
(12, @OGUID+300),
(12, @OGUID+301),
(12, @OGUID+302),
(12, @OGUID+303),
(12, @OGUID+304),
(12, @OGUID+305),
(12, @OGUID+306),
(12, @OGUID+307),
(12, @OGUID+308),
(12, @OGUID+309),
(12, @OGUID+310),
(12, @OGUID+311),
(12, @OGUID+312),
(12, @OGUID+313),
(12, @OGUID+314),
(12, @OGUID+315),
(12, @OGUID+316),
(12, @OGUID+317),
(12, @OGUID+318),
(12, @OGUID+319),
(12, @OGUID+320),
(12, @OGUID+321),
(12, @OGUID+322),
(12, @OGUID+323),
(12, @OGUID+324),
(12, @OGUID+325),
(12, @OGUID+326),
(12, @OGUID+327),
(12, @OGUID+328),
(12, @OGUID+329),
(12, @OGUID+330),
(12, @OGUID+331),
(12, @OGUID+332),
(12, @OGUID+333),
(12, @OGUID+334),
(12, @OGUID+335),
(12, @OGUID+336),
(12, @OGUID+337),
(12, @OGUID+338),
(12, @OGUID+339),
(12, @OGUID+340),
(12, @OGUID+341),
(12, @OGUID+342),
(12, @OGUID+343),
(12, @OGUID+344),
(12, @OGUID+345),
(12, @OGUID+346),
(12, @OGUID+347),
(12, @OGUID+348),
(12, @OGUID+349),
(12, @OGUID+350),
(12, @OGUID+351),
(12, @OGUID+352),
(12, @OGUID+353),
(12, @OGUID+354),
(12, @OGUID+355),
(12, @OGUID+356),
(12, @OGUID+357),
(12, @OGUID+358),
(12, @OGUID+359),
(12, @OGUID+360),
(12, @OGUID+361),
(12, @OGUID+362),
(12, @OGUID+363),
(12, @OGUID+364),
(12, @OGUID+365),
(12, @OGUID+366),
(12, @OGUID+367),
(12, @OGUID+368),
(12, @OGUID+369),
(12, @OGUID+370),
(12, @OGUID+371),
(12, @OGUID+372),
(12, @OGUID+373),
(12, @OGUID+374),
(12, @OGUID+375),
(12, @OGUID+376),
(12, @OGUID+377),
(12, @OGUID+378),
(12, @OGUID+379),
(12, @OGUID+380),
(12, @OGUID+381),
(12, @OGUID+382),
(12, @OGUID+383),
(12, @OGUID+384),
(12, @OGUID+385),
(12, @OGUID+386),
(12, @OGUID+387),
(12, @OGUID+388),
(12, @OGUID+389),
(12, @OGUID+390),
(12, @OGUID+391),
(12, @OGUID+392),
(12, @OGUID+393),
(12, @OGUID+394),
(12, @OGUID+395),
(12, @OGUID+396),
(12, @OGUID+397),
(12, @OGUID+398),
(12, @OGUID+399),
(12, @OGUID+400),
(12, @OGUID+401),
(12, @OGUID+402),
(12, @OGUID+403),
(12, @OGUID+404),
(12, @OGUID+405),
(12, @OGUID+406),
(12, @OGUID+407),
(12, @OGUID+408),
(12, @OGUID+409),
(12, @OGUID+410),
(12, @OGUID+411),
(12, @OGUID+412),
(12, @OGUID+413),
(12, @OGUID+414),
(12, @OGUID+415),
(12, @OGUID+416),
(12, @OGUID+417),
(12, @OGUID+418),
(12, @OGUID+419),
(12, @OGUID+420),
(12, @OGUID+421),
(12, @OGUID+422),
(12, @OGUID+423),
(12, @OGUID+424),
(12, @OGUID+425),
(12, @OGUID+426),
(12, @OGUID+427),
(12, @OGUID+428),
(12, @OGUID+429),
(12, @OGUID+430),
(12, @OGUID+431),
(12, @OGUID+432),
(12, @OGUID+433),
(12, @OGUID+434),
(12, @OGUID+435),
(12, @OGUID+436),
(12, @OGUID+437),
(12, @OGUID+438),
(12, @OGUID+439),
(12, @OGUID+440),
(12, @OGUID+441),
(12, @OGUID+442),
(12, @OGUID+443),
(12, @OGUID+444),
(12, @OGUID+445),
(12, @OGUID+446),
(12, @OGUID+447),
(12, @OGUID+448),
(12, @OGUID+449),
(12, @OGUID+450),
(12, @OGUID+451),
(12, @OGUID+452),
(12, @OGUID+453),
(12, @OGUID+454),
(12, @OGUID+455),
(12, @OGUID+456),
(12, @OGUID+457),
(12, @OGUID+458),
(12, @OGUID+459),
(12, @OGUID+460),
(12, @OGUID+461),
(12, @OGUID+462),
(12, @OGUID+463),
(12, @OGUID+464),
(12, @OGUID+465),
(12, @OGUID+466),
(12, @OGUID+467),
(12, @OGUID+468),
(12, @OGUID+469),
(12, @OGUID+470),
(12, @OGUID+471),
(12, @OGUID+472),
(12, @OGUID+473),
(12, @OGUID+474),
(12, @OGUID+475),
(12, @OGUID+476),
(12, @OGUID+477),
(12, @OGUID+478),
(12, @OGUID+479),
(12, @OGUID+480),
(12, @OGUID+481),
(12, @OGUID+482),
(12, @OGUID+483),
(12, @OGUID+484),
(12, @OGUID+485),
(12, @OGUID+486),
(12, @OGUID+487),
(12, @OGUID+488),
(12, @OGUID+489),
(12, @OGUID+490),
(12, @OGUID+491),
(12, @OGUID+492),
(12, @OGUID+493),
(12, @OGUID+494),
(12, @OGUID+495),
(12, @OGUID+496),
(12, @OGUID+497),
(12, @OGUID+498),
(12, @OGUID+499),
(12, @OGUID+500),
(12, @OGUID+501),
(12, @OGUID+502),
(12, @OGUID+503),
(12, @OGUID+504),
(12, @OGUID+505),
(12, @OGUID+506),
(12, @OGUID+507),
(12, @OGUID+508),
(12, @OGUID+509),
(12, @OGUID+510),
(12, @OGUID+511),
(12, @OGUID+512),
(12, @OGUID+513),
(12, @OGUID+514),
(12, @OGUID+515),
(12, @OGUID+516),
(12, @OGUID+517),
(12, @OGUID+518),
(12, @OGUID+519),
(12, @OGUID+520),
(12, @OGUID+521),
(12, @OGUID+522),
(12, @OGUID+523),
(12, @OGUID+524),
(12, @OGUID+525),
(12, @OGUID+526),
(12, @OGUID+527),
(12, @OGUID+528),
(12, @OGUID+529),
(12, @OGUID+530),
(12, @OGUID+531),
(12, @OGUID+532),
(12, @OGUID+533),
(12, @OGUID+534),
(12, @OGUID+535),
(12, @OGUID+536),
(12, @OGUID+537),
(12, @OGUID+538),
(12, @OGUID+539),
(12, @OGUID+540),
(12, @OGUID+541),
(12, @OGUID+542),
(12, @OGUID+543),
(12, @OGUID+544),
(12, @OGUID+545),
(12, @OGUID+546),
(12, @OGUID+547),
(12, @OGUID+548),
(12, @OGUID+549),
(12, @OGUID+550),
(12, @OGUID+551),
(12, @OGUID+552),
(12, @OGUID+553),
(12, @OGUID+554),
(12, @OGUID+555),
(12, @OGUID+556),
(12, @OGUID+557),
(12, @OGUID+558),
(12, @OGUID+559),
(12, @OGUID+560),
(12, @OGUID+561),
(12, @OGUID+562),
(12, @OGUID+563),
(12, @OGUID+564),
(12, @OGUID+565),
(12, @OGUID+566),
(12, @OGUID+567),
(12, @OGUID+568),
(12, @OGUID+569),
(12, @OGUID+570),
(12, @OGUID+571),
(12, @OGUID+572),
(12, @OGUID+573),
(12, @OGUID+574),
(12, @OGUID+575),
(12, @OGUID+576),
(12, @OGUID+577),
(12, @OGUID+578),
(12, @OGUID+579),
(12, @OGUID+580),
(12, @OGUID+581),
(12, @OGUID+582),
(12, @OGUID+583),
(12, @OGUID+584),
(12, @OGUID+585),
(12, @OGUID+586),
(12, @OGUID+587),
(12, @OGUID+588),
(12, @OGUID+589),
(12, @OGUID+590),
(12, @OGUID+591),
(12, @OGUID+592),
(12, @OGUID+593),
(12, @OGUID+594),
(12, @OGUID+595),
(12, @OGUID+596),
(12, @OGUID+597),
(12, @OGUID+598),
(12, @OGUID+599),
(12, @OGUID+600),
(12, @OGUID+601),
(12, @OGUID+602),
(12, @OGUID+603),
(12, @OGUID+604),
(12, @OGUID+605),
(12, @OGUID+606),
(12, @OGUID+607),
(12, @OGUID+608),
(12, @OGUID+609),
(12, @OGUID+610),
(12, @OGUID+611),
(12, @OGUID+612),
(12, @OGUID+613),
(12, @OGUID+614),
(12, @OGUID+615),
(12, @OGUID+616),
(12, @OGUID+617),
(12, @OGUID+618),
(12, @OGUID+619),
(12, @OGUID+620),
(12, @OGUID+621),
(12, @OGUID+622),
(12, @OGUID+623),
(12, @OGUID+624),
(12, @OGUID+625),
(12, @OGUID+626),
(12, @OGUID+627),
(12, @OGUID+628),
(12, @OGUID+629),
(12, @OGUID+630),
(12, @OGUID+631),
(12, @OGUID+632),
(12, @OGUID+633),
(12, @OGUID+634),
(12, @OGUID+635),
(12, @OGUID+636),
(12, @OGUID+637),
(12, @OGUID+638),
(12, @OGUID+639),
(12, @OGUID+640),
(12, @OGUID+641),
(12, @OGUID+642),
(12, @OGUID+643),
(12, @OGUID+644),
(12, @OGUID+645),
(12, @OGUID+646),
(12, @OGUID+647),
(12, @OGUID+648),
(12, @OGUID+649),
(12, @OGUID+650),
(12, @OGUID+651),
(12, @OGUID+652),
(12, @OGUID+653),
(12, @OGUID+654),
(12, @OGUID+655),
(12, @OGUID+656),
(12, @OGUID+657),
(12, @OGUID+658),
(12, @OGUID+659),
(12, @OGUID+660),
(12, @OGUID+661),
(12, @OGUID+662),
(12, @OGUID+663),
(12, @OGUID+664),
(12, @OGUID+665),
(12, @OGUID+666),
(12, @OGUID+667),
(12, @OGUID+668),
(12, @OGUID+669),
(12, @OGUID+670),
(12, @OGUID+671),
(12, @OGUID+672),
(12, @OGUID+673),
(12, @OGUID+674),
(12, @OGUID+675),
(12, @OGUID+676),
(12, @OGUID+677),
(12, @OGUID+678),
(12, @OGUID+679),
(12, @OGUID+680),
(12, @OGUID+681),
(12, @OGUID+682),
(12, @OGUID+683),
(12, @OGUID+684),
(12, @OGUID+685),
(12, @OGUID+686),
(12, @OGUID+687),
(12, @OGUID+688),
(12, @OGUID+689),
(12, @OGUID+690),
(12, @OGUID+691),
(12, @OGUID+692),
(12, @OGUID+693),
(12, @OGUID+694),
(12, @OGUID+695),
(12, @OGUID+696),
(12, @OGUID+697),
(12, @OGUID+698),
(12, @OGUID+699),
(12, @OGUID+700),
(12, @OGUID+701),
(12, @OGUID+702),
(12, @OGUID+703),
(12, @OGUID+704),
(12, @OGUID+705),
(12, @OGUID+706),
(12, @OGUID+707),
(12, @OGUID+708),
(12, @OGUID+709),
(12, @OGUID+710),
(12, @OGUID+711),
(12, @OGUID+712),
(12, @OGUID+713),
(12, @OGUID+714),
(12, @OGUID+715),
(12, @OGUID+716),
(12, @OGUID+717),
(12, @OGUID+718),
(12, @OGUID+719),
(12, @OGUID+720),
(12, @OGUID+721),
(12, @OGUID+722),
(12, @OGUID+723),
(12, @OGUID+724),
(12, @OGUID+725),
(12, @OGUID+726),
(12, @OGUID+727),
(12, @OGUID+728),
(12, @OGUID+729),
(12, @OGUID+730),
(12, @OGUID+731),
(12, @OGUID+732),
(12, @OGUID+733),
(12, @OGUID+734),
(12, @OGUID+735),
(12, @OGUID+736),
(12, @OGUID+737),
(12, @OGUID+738),
(12, @OGUID+739),
(12, @OGUID+740),
(12, @OGUID+741),
(12, @OGUID+742),
(12, @OGUID+743),
(12, @OGUID+744),
(12, @OGUID+745),
(12, @OGUID+746),
(12, @OGUID+747),
(12, @OGUID+748),
(12, @OGUID+749),
(12, @OGUID+750),
(12, @OGUID+751),
(12, @OGUID+752),
(12, @OGUID+753),
(12, @OGUID+754),
(12, @OGUID+755),
(12, @OGUID+756),
(12, @OGUID+757),
(12, @OGUID+758),
(12, @OGUID+759),
(12, @OGUID+760),
(12, @OGUID+761),
(12, @OGUID+762),
(12, @OGUID+763),
(12, @OGUID+764),
(12, @OGUID+765),
(12, @OGUID+766),
(12, @OGUID+767),
(12, @OGUID+768),
(12, @OGUID+769),
(12, @OGUID+770),
(12, @OGUID+771),
(12, @OGUID+772),
(12, @OGUID+773),
(12, @OGUID+774),
(12, @OGUID+775),
(12, @OGUID+776),
(12, @OGUID+777),
(12, @OGUID+778),
(12, @OGUID+779),
(12, @OGUID+780),
(12, @OGUID+781),
(12, @OGUID+782),
(12, @OGUID+783),
(12, @OGUID+784),
(12, @OGUID+785),
(12, @OGUID+786),
(12, @OGUID+787),
(12, @OGUID+788),
(12, @OGUID+789),
(12, @OGUID+790),
(12, @OGUID+791),
(12, @OGUID+792),
(12, @OGUID+793),
(12, @OGUID+794),
(12, @OGUID+795),
(12, @OGUID+796),
(12, @OGUID+797),
(12, @OGUID+798),
(12, @OGUID+799),
(12, @OGUID+800),
(12, @OGUID+801),
(12, @OGUID+802),
(12, @OGUID+803),
(12, @OGUID+804),
(12, @OGUID+805),
(12, @OGUID+806),
(12, @OGUID+807),
(12, @OGUID+808),
(12, @OGUID+809),
(12, @OGUID+810),
(12, @OGUID+811),
(12, @OGUID+812),
(12, @OGUID+813),
(12, @OGUID+814),
(12, @OGUID+815),
(12, @OGUID+816),
(12, @OGUID+817),
(12, @OGUID+818),
(12, @OGUID+819),
(12, @OGUID+820),
(12, @OGUID+821),
(12, @OGUID+822),
(12, @OGUID+823),
(12, @OGUID+824),
(12, @OGUID+825),
(12, @OGUID+826),
(12, @OGUID+827),
(12, @OGUID+828),
(12, @OGUID+829),
(12, @OGUID+830),
(12, @OGUID+831),
(12, @OGUID+832),
(12, @OGUID+833),
(12, @OGUID+834),
(12, @OGUID+835),
(12, @OGUID+836),
(12, @OGUID+837),
(12, @OGUID+838),
(12, @OGUID+839),
(12, @OGUID+840),
(12, @OGUID+841),
(12, @OGUID+842),
(12, @OGUID+843),
(12, @OGUID+844),
(12, @OGUID+845),
(12, @OGUID+846),
(12, @OGUID+847),
(12, @OGUID+848),
(12, @OGUID+849),
(12, @OGUID+850),
(12, @OGUID+851),
(12, @OGUID+852),
(12, @OGUID+853),
(12, @OGUID+854),
(12, @OGUID+855),
(12, @OGUID+856),
(12, @OGUID+857),
(12, @OGUID+858),
(12, @OGUID+859),
(12, @OGUID+860),
(12, @OGUID+861),
(12, @OGUID+862),
(12, @OGUID+863),
(12, @OGUID+864),
(12, @OGUID+865),
(12, @OGUID+866),
(12, @OGUID+867),
(12, @OGUID+868),
(12, @OGUID+869),
(12, @OGUID+870),
(12, @OGUID+871),
(12, @OGUID+872),
(12, @OGUID+873),
(12, @OGUID+874),
(12, @OGUID+875),
(12, @OGUID+876),
(12, @OGUID+877),
(12, @OGUID+878),
(12, @OGUID+879),
(12, @OGUID+880),
(12, @OGUID+881),
(12, @OGUID+882),
(12, @OGUID+883),
(12, @OGUID+884),
(12, @OGUID+885),
(12, @OGUID+886),
(12, @OGUID+887),
(12, @OGUID+888),
(12, @OGUID+889),
(12, @OGUID+890),
(12, @OGUID+891),
(12, @OGUID+892),
(12, @OGUID+893),
(12, @OGUID+894),
(12, @OGUID+895),
(12, @OGUID+896),
(12, @OGUID+897),
(12, @OGUID+898),
(12, @OGUID+899),
(12, @OGUID+900),
(12, @OGUID+901),
(12, @OGUID+902),
(12, @OGUID+903),
(12, @OGUID+904),
(12, @OGUID+905),
(12, @OGUID+906),
(12, @OGUID+907),
(12, @OGUID+908),
(12, @OGUID+909),
(12, @OGUID+910),
(12, @OGUID+911),
(12, @OGUID+912),
(12, @OGUID+913),
(12, @OGUID+914),
(12, @OGUID+915),
(12, @OGUID+916),
(12, @OGUID+917),
(12, @OGUID+918),
(12, @OGUID+919),
(12, @OGUID+920),
(12, @OGUID+921),
(12, @OGUID+922),
(12, @OGUID+923),
(12, @OGUID+924),
(12, @OGUID+925),
(12, @OGUID+926),
(12, @OGUID+927),
(12, @OGUID+928),
(12, @OGUID+929),
(12, @OGUID+930),
(12, @OGUID+931),
(12, @OGUID+932),
(12, @OGUID+933),
(12, @OGUID+934),
(12, @OGUID+935),
(12, @OGUID+936),
(12, @OGUID+937),
(12, @OGUID+938),
(12, @OGUID+939),
(12, @OGUID+940),
(12, @OGUID+941),
(12, @OGUID+942),
(12, @OGUID+943),
(12, @OGUID+944),
(12, @OGUID+945),
(12, @OGUID+946),
(12, @OGUID+947),
(12, @OGUID+948),
(12, @OGUID+949),
(12, @OGUID+950),
(12, @OGUID+951),
(12, @OGUID+952),
(12, @OGUID+953),
(12, @OGUID+954),
(12, @OGUID+955),
(12, @OGUID+956),
(12, @OGUID+957),
(12, @OGUID+958),
(12, @OGUID+959),
(12, @OGUID+960),
(12, @OGUID+961),
(12, @OGUID+962),
(12, @OGUID+963),
(12, @OGUID+964),
(12, @OGUID+965),
(12, @OGUID+966),
(12, @OGUID+967),
(12, @OGUID+968),
(12, @OGUID+969),
(12, @OGUID+970),
(12, @OGUID+971),
(12, @OGUID+972),
(12, @OGUID+973),
(12, @OGUID+974),
(12, @OGUID+975),
(12, @OGUID+976),
(12, @OGUID+977),
(12, @OGUID+978),
(12, @OGUID+979),
(12, @OGUID+980),
(12, @OGUID+981),
(12, @OGUID+982),
(12, @OGUID+983),
(12, @OGUID+984),
(12, @OGUID+985),
(12, @OGUID+986),
(12, @OGUID+987),
(12, @OGUID+988),
(12, @OGUID+989),
(12, @OGUID+990),
(12, @OGUID+991),
(12, @OGUID+992),
(12, @OGUID+993),
(12, @OGUID+994),
(12, @OGUID+995),
(12, @OGUID+996),
(12, @OGUID+997),
(12, @OGUID+998),
(12, @OGUID+999),
(12, @OGUID+1000),
(12, @OGUID+1001),
(12, @OGUID+1002),
(12, @OGUID+1003),
(12, @OGUID+1004),
(12, @OGUID+1005),
(12, @OGUID+1006),
(12, @OGUID+1007),
(12, @OGUID+1008),
(12, @OGUID+1009),
(12, @OGUID+1010),
(12, @OGUID+1011),
(12, @OGUID+1012),
(12, @OGUID+1013),
(12, @OGUID+1014),
(12, @OGUID+1015),
(12, @OGUID+1016),
(12, @OGUID+1017),
(12, @OGUID+1018),
(12, @OGUID+1019),
(12, @OGUID+1020),
(12, @OGUID+1021),
(12, @OGUID+1022),
(12, @OGUID+1023),
(12, @OGUID+1024),
(12, @OGUID+1025),
(12, @OGUID+1026),
(12, @OGUID+1027),
(12, @OGUID+1028),
(12, @OGUID+1029),
(12, @OGUID+1030),
(12, @OGUID+1031),
(12, @OGUID+1032),
(12, @OGUID+1033),
(12, @OGUID+1034),
(12, @OGUID+1035),
(12, @OGUID+1036),
(12, @OGUID+1037),
(12, @OGUID+1038),
(12, @OGUID+1039),
(12, @OGUID+1040),
(12, @OGUID+1041),
(12, @OGUID+1042),
(12, @OGUID+1043),
(12, @OGUID+1044),
(12, @OGUID+1045),
(12, @OGUID+1046),
(12, @OGUID+1047),
(12, @OGUID+1048),
(12, @OGUID+1049),
(12, @OGUID+1050),
(12, @OGUID+1051),
(12, @OGUID+1052),
(12, @OGUID+1053),
(12, @OGUID+1054),
(12, @OGUID+1055),
(12, @OGUID+1056),
(12, @OGUID+1057),
(12, @OGUID+1058),
(12, @OGUID+1059),
(12, @OGUID+1060),
(12, @OGUID+1061),
(12, @OGUID+1062),
(12, @OGUID+1063),
(12, @OGUID+1064),
(12, @OGUID+1065),
(12, @OGUID+1066),
(12, @OGUID+1067),
(12, @OGUID+1068),
(12, @OGUID+1069),
(12, @OGUID+1070),
(12, @OGUID+1071),
(12, @OGUID+1072),
(12, @OGUID+1073),
(12, @OGUID+1074),
(12, @OGUID+1075),
(12, @OGUID+1076),
(12, @OGUID+1077),
(12, @OGUID+1078),
(12, @OGUID+1079),
(12, @OGUID+1080),
(12, @OGUID+1081),
(12, @OGUID+1082),
(12, @OGUID+1083),
(12, @OGUID+1084),
(12, @OGUID+1085),
(12, @OGUID+1086),
(12, @OGUID+1087),
(12, @OGUID+1088),
(12, @OGUID+1089),
(12, @OGUID+1090),
(12, @OGUID+1091),
(12, @OGUID+1092),
(12, @OGUID+1093),
(12, @OGUID+1094),
(12, @OGUID+1095),
(12, @OGUID+1096),
(12, @OGUID+1097),
(12, @OGUID+1098),
(12, @OGUID+1099),
(12, @OGUID+1100),
(12, @OGUID+1101),
(12, @OGUID+1102),
(12, @OGUID+1103),
(12, @OGUID+1104),
(12, @OGUID+1105),
(12, @OGUID+1106),
(12, @OGUID+1107),
(12, @OGUID+1108),
(12, @OGUID+1109),
(12, @OGUID+1110),
(12, @OGUID+1111),
(12, @OGUID+1112),
(12, @OGUID+1113),
(12, @OGUID+1114),
(12, @OGUID+1115),
(12, @OGUID+1116),
(12, @OGUID+1117),
(12, @OGUID+1118),
(12, @OGUID+1119),
(12, @OGUID+1120),
(12, @OGUID+1121),
(12, @OGUID+1122),
(12, @OGUID+1123),
(12, @OGUID+1124),
(12, @OGUID+1125),
(12, @OGUID+1126),
(12, @OGUID+1127),
(12, @OGUID+1128),
(12, @OGUID+1129),
(12, @OGUID+1130),
(12, @OGUID+1131),
(12, @OGUID+1132),
(12, @OGUID+1133),
(12, @OGUID+1134),
(12, @OGUID+1135),
(12, @OGUID+1136),
(12, @OGUID+1137),
(12, @OGUID+1138),
(12, @OGUID+1139),
(12, @OGUID+1140),
(12, @OGUID+1141),
(12, @OGUID+1142),
(12, @OGUID+1143),
(12, @OGUID+1144),
(12, @OGUID+1145),
(12, @OGUID+1146),
(12, @OGUID+1147),
(12, @OGUID+1148),
(12, @OGUID+1149),
(12, @OGUID+1150),
(12, @OGUID+1151),
(12, @OGUID+1152),
(12, @OGUID+1153),
(12, @OGUID+1154),
(12, @OGUID+1155),
(12, @OGUID+1156),
(12, @OGUID+1157),
(12, @OGUID+1158),
(12, @OGUID+1159),
(12, @OGUID+1160),
(12, @OGUID+1161),
(12, @OGUID+1162),
(12, @OGUID+1163),
(12, @OGUID+1164),
(12, @OGUID+1165),
(12, @OGUID+1166),
(12, @OGUID+1167),
(12, @OGUID+1168),
(12, @OGUID+1169),
(12, @OGUID+1170),
(12, @OGUID+1171),
(12, @OGUID+1172),
(12, @OGUID+1173),
(12, @OGUID+1174),
(12, @OGUID+1175),
(12, @OGUID+1176),
(12, @OGUID+1177),
(12, @OGUID+1178),
(12, @OGUID+1179),
(12, @OGUID+1180),
(12, @OGUID+1181),
(12, @OGUID+1182),
(12, @OGUID+1183),
(12, @OGUID+1184),
(12, @OGUID+1185),
(12, @OGUID+1186),
(12, @OGUID+1187),
(12, @OGUID+1188),
(12, @OGUID+1189),
(12, @OGUID+1190),
(12, @OGUID+1191),
(12, @OGUID+1192),
(12, @OGUID+1193),
(12, @OGUID+1194),
(12, @OGUID+1195),
(12, @OGUID+1196),
(12, @OGUID+1197),
(12, @OGUID+1198),
(12, @OGUID+1199),
(12, @OGUID+1200),
(12, @OGUID+1201),
(12, @OGUID+1202),
(12, @OGUID+1203),
(12, @OGUID+1204),
(12, @OGUID+1205),
(12, @OGUID+1206),
(12, @OGUID+1207),
(12, @OGUID+1208),
(12, @OGUID+1209),
(12, @OGUID+1210),
(12, @OGUID+1211),
(12, @OGUID+1212),
(12, @OGUID+1213),
(12, @OGUID+1214),
(12, @OGUID+1215),
(12, @OGUID+1216),
(12, @OGUID+1217),
(12, @OGUID+1218),
(12, @OGUID+1219),
(12, @OGUID+1220),
(12, @OGUID+1221),
(12, @OGUID+1222),
(12, @OGUID+1223),
(12, @OGUID+1224),
(12, @OGUID+1225),
(12, @OGUID+1226),
(12, @OGUID+1227),
(12, @OGUID+1228),
(12, @OGUID+1229),
(12, @OGUID+1230),
(12, @OGUID+1231),
(12, @OGUID+1232),
(12, @OGUID+1233),
(12, @OGUID+1234),
(12, @OGUID+1235),
(12, @OGUID+1236),
(12, @OGUID+1237),
(12, @OGUID+1238),
(12, @OGUID+1239),
(12, @OGUID+1240),
(12, @OGUID+1241),
(12, @OGUID+1242),
(12, @OGUID+1243),
(12, @OGUID+1244),
(12, @OGUID+1245),
(12, @OGUID+1246),
(12, @OGUID+1247),
(12, @OGUID+1248),
(12, @OGUID+1249),
(12, @OGUID+1250),
(12, @OGUID+1251),
(12, @OGUID+1252),
(12, @OGUID+1253),
(12, @OGUID+1254),
(12, @OGUID+1255),
(12, @OGUID+1256),
(12, @OGUID+1257),
(12, @OGUID+1258),
(12, @OGUID+1259),
(12, @OGUID+1260),
(12, @OGUID+1261),
(12, @OGUID+1262),
(12, @OGUID+1263),
(12, @OGUID+1264),
(12, @OGUID+1265),
(12, @OGUID+1266),
(12, @OGUID+1267),
(12, @OGUID+1268),
(12, @OGUID+1269),
(12, @OGUID+1270),
(12, @OGUID+1271),
(12, @OGUID+1272),
(12, @OGUID+1273),
(12, @OGUID+1274),
(12, @OGUID+1275),
(12, @OGUID+1276),
(12, @OGUID+1277),
(12, @OGUID+1278),
(12, @OGUID+1279),
(12, @OGUID+1280),
(12, @OGUID+1281),
(12, @OGUID+1282),
(12, @OGUID+1283),
(12, @OGUID+1284),
(12, @OGUID+1285),
(12, @OGUID+1286),
(12, @OGUID+1287),
(12, @OGUID+1288),
(12, @OGUID+1289),
(12, @OGUID+1290),
(12, @OGUID+1291),
(12, @OGUID+1292),
(12, @OGUID+1293),
(12, @OGUID+1294),
(12, @OGUID+1295),
(12, @OGUID+1296),
(12, @OGUID+1297),
(12, @OGUID+1298),
(12, @OGUID+1299),
(12, @OGUID+1300),
(12, @OGUID+1301),
(12, @OGUID+1302),
(12, @OGUID+1303),
(12, @OGUID+1304),
(12, @OGUID+1305),
(12, @OGUID+1306),
(12, @OGUID+1307),
(12, @OGUID+1308),
(12, @OGUID+1309),
(12, @OGUID+1310),
(12, @OGUID+1311),
(12, @OGUID+1312),
(12, @OGUID+1313),
(12, @OGUID+1314),
(12, @OGUID+1315),
(12, @OGUID+1316),
(12, @OGUID+1317),
(12, @OGUID+1318),
(12, @OGUID+1319),
(12, @OGUID+1320),
(12, @OGUID+1321),
(12, @OGUID+1322),
(12, @OGUID+1323),
(12, @OGUID+1324),
(12, @OGUID+1325),
(12, @OGUID+1326),
(12, @OGUID+1327),
(12, @OGUID+1328),
(12, @OGUID+1329),
(12, @OGUID+1330),
(12, @OGUID+1331),
(12, @OGUID+1332),
(12, @OGUID+1333),
(12, @OGUID+1334),
(12, @OGUID+1335),
(12, @OGUID+1336),
(12, @OGUID+1337),
(12, @OGUID+1338),
(12, @OGUID+1339),
(12, @OGUID+1340),
(12, @OGUID+1341),
(12, @OGUID+1342),
(12, @OGUID+1343),
(12, @OGUID+1344),
(12, @OGUID+1345),
(12, @OGUID+1346),
(12, @OGUID+1347),
(12, @OGUID+1348),
(12, @OGUID+1349),
(12, @OGUID+1350),
(12, @OGUID+1351),
(12, @OGUID+1352),
(12, @OGUID+1353),
(12, @OGUID+1354),
(12, @OGUID+1355),
(12, @OGUID+1356),
(12, @OGUID+1357),
(12, @OGUID+1358),
(12, @OGUID+1359),
(12, @OGUID+1360),
(12, @OGUID+1361),
(12, @OGUID+1362),
(12, @OGUID+1363),
(12, @OGUID+1364),
(12, @OGUID+1365),
(12, @OGUID+1366),
(12, @OGUID+1367),
(12, @OGUID+1368),
(12, @OGUID+1369),
(12, @OGUID+1370),
(12, @OGUID+1371),
(12, @OGUID+1372),
(12, @OGUID+1373),
(12, @OGUID+1374),
(12, @OGUID+1375),
(12, @OGUID+1376),
(12, @OGUID+1377),
(12, @OGUID+1378),
(12, @OGUID+1379),
(12, @OGUID+1380),
(12, @OGUID+1381),
(12, @OGUID+1382),
(12, @OGUID+1383),
(12, @OGUID+1384),
(12, @OGUID+1385),
(12, @OGUID+1386),
(12, @OGUID+1387),
(12, @OGUID+1388),
(12, @OGUID+1389),
(12, @OGUID+1390),
(12, @OGUID+1391),
(12, @OGUID+1392),
(12, @OGUID+1393),
(12, @OGUID+1394),
(12, @OGUID+1395),
(12, @OGUID+1396),
(12, @OGUID+1397),
(12, @OGUID+1398),
(12, @OGUID+1399),
(12, @OGUID+1400),
(12, @OGUID+1401),
(12, @OGUID+1402),
(12, @OGUID+1403),
(12, @OGUID+1404),
(12, @OGUID+1405),
(12, @OGUID+1406),
(12, @OGUID+1407),
(12, @OGUID+1408),
(12, @OGUID+1409),
(12, @OGUID+1410),
(12, @OGUID+1411),
(12, @OGUID+1412),
(12, @OGUID+1413),
(12, @OGUID+1414),
(12, @OGUID+1415),
(12, @OGUID+1416),
(12, @OGUID+1417),
(12, @OGUID+1418),
(12, @OGUID+1419),
(12, @OGUID+1420),
(12, @OGUID+1421),
(12, @OGUID+1422),
(12, @OGUID+1423),
(12, @OGUID+1424),
(12, @OGUID+1425),
(12, @OGUID+1426),
(12, @OGUID+1427),
(12, @OGUID+1428),
(12, @OGUID+1429),
(12, @OGUID+1430),
(12, @OGUID+1431),
(12, @OGUID+1432),
(12, @OGUID+1433),
(12, @OGUID+1434),
(12, @OGUID+1435),
(12, @OGUID+1436),
(12, @OGUID+1437),
(12, @OGUID+1438),
(12, @OGUID+1439),
(12, @OGUID+1440),
(12, @OGUID+1441),
(12, @OGUID+1442),
(12, @OGUID+1443),
(12, @OGUID+1444),
(12, @OGUID+1445),
(12, @OGUID+1446),
(12, @OGUID+1447),
(12, @OGUID+1448),
(12, @OGUID+1449),
(12, @OGUID+1450),
(12, @OGUID+1451),
(12, @OGUID+1452),
(12, @OGUID+1453),
(12, @OGUID+1454),
(12, @OGUID+1455),
(12, @OGUID+1456),
(12, @OGUID+1457),
(12, @OGUID+1458),
(12, @OGUID+1459),
(12, @OGUID+1460),
(12, @OGUID+1461),
(12, @OGUID+1462),
(12, @OGUID+1463),
(12, @OGUID+1464),
(12, @OGUID+1465),
(12, @OGUID+1466),
(12, @OGUID+1467),
(12, @OGUID+1468),
(12, @OGUID+1469),
(12, @OGUID+1470),
(12, @OGUID+1471),
(12, @OGUID+1472),
(12, @OGUID+1473),
(12, @OGUID+1474),
(12, @OGUID+1475),
(12, @OGUID+1476),
(12, @OGUID+1477),
(12, @OGUID+1478),
(12, @OGUID+1479),
(12, @OGUID+1480),
(12, @OGUID+1481),
(12, @OGUID+1482),
(12, @OGUID+1483),
(12, @OGUID+1484),
(12, @OGUID+1485),
(12, @OGUID+1486),
(12, @OGUID+1487),
(12, @OGUID+1488),
(12, @OGUID+1489),
(12, @OGUID+1490),
(12, @OGUID+1491),
(12, @OGUID+1492),
(12, @OGUID+1493),
(12, @OGUID+1494),
(12, @OGUID+1495),
(12, @OGUID+1496),
(12, @OGUID+1497),
(12, @OGUID+1498),
(12, @OGUID+1499),
(12, @OGUID+1500),
(12, @OGUID+1501),
(12, @OGUID+1502),
(12, @OGUID+1503),
(12, @OGUID+1504),
(12, @OGUID+1505),
(12, @OGUID+1506),
(12, @OGUID+1507),
(12, @OGUID+1508),
(12, @OGUID+1509),
(12, @OGUID+1510),
(12, @OGUID+1511),
(12, @OGUID+1512),
(12, @OGUID+1513),
(12, @OGUID+1514),
(12, @OGUID+1515),
(12, @OGUID+1516),
(12, @OGUID+1517),
(12, @OGUID+1518),
(12, @OGUID+1519),
(12, @OGUID+1520),
(12, @OGUID+1521),
(12, @OGUID+1522),
(12, @OGUID+1523),
(12, @OGUID+1524),
(12, @OGUID+1525),
(12, @OGUID+1526),
(12, @OGUID+1527),
(12, @OGUID+1528),
(12, @OGUID+1529),
(12, @OGUID+1530),
(12, @OGUID+1531),
(12, @OGUID+1532),
(12, @OGUID+1533),
(12, @OGUID+1534),
(12, @OGUID+1535),
(12, @OGUID+1536),
(12, @OGUID+1537),
(12, @OGUID+1538),
(12, @OGUID+1539),
(12, @OGUID+1540),
(12, @OGUID+1541),
(12, @OGUID+1542),
(12, @OGUID+1543),
(12, @OGUID+1544),
(12, @OGUID+1545),
(12, @OGUID+1546),
(12, @OGUID+1547),
(12, @OGUID+1548),
(12, @OGUID+1549),
(12, @OGUID+1550),
(12, @OGUID+1551),
(12, @OGUID+1552),
(12, @OGUID+1553),
(12, @OGUID+1554),
(12, @OGUID+1555),
(12, @OGUID+1556),
(12, @OGUID+1557),
(12, @OGUID+1558),
(12, @OGUID+1559),
(12, @OGUID+1560),
(12, @OGUID+1561),
(12, @OGUID+1562),
(12, @OGUID+1563),
(12, @OGUID+1564),
(12, @OGUID+1565),
(12, @OGUID+1566),
(12, @OGUID+1567),
(12, @OGUID+1568),
(12, @OGUID+1569),
(12, @OGUID+1570),
(12, @OGUID+1571),
(12, @OGUID+1572),
(12, @OGUID+1573),
(12, @OGUID+1574),
(12, @OGUID+1575),
(12, @OGUID+1576),
(12, @OGUID+1577),
(12, @OGUID+1578),
(12, @OGUID+1579),
(12, @OGUID+1580),
(12, @OGUID+1581),
(12, @OGUID+1582),
(12, @OGUID+1583),
(12, @OGUID+1584),
(12, @OGUID+1585),
(12, @OGUID+1586),
(12, @OGUID+1587),
(12, @OGUID+1588),
(12, @OGUID+1589),
(12, @OGUID+1590),
(12, @OGUID+1591),
(12, @OGUID+1592),
(12, @OGUID+1593),
(12, @OGUID+1594),
(12, @OGUID+1595),
(12, @OGUID+1596),
(12, @OGUID+1597),
(12, @OGUID+1598),
(12, @OGUID+1599),
(12, @OGUID+1600),
(12, @OGUID+1601),
(12, @OGUID+1602),
(12, @OGUID+1603),
(12, @OGUID+1604),
(12, @OGUID+1605),
(12, @OGUID+1606),
(12, @OGUID+1607),
(12, @OGUID+1608),
(12, @OGUID+1609),
(12, @OGUID+1610),
(12, @OGUID+1611),
(12, @OGUID+1612),
(12, @OGUID+1613),
(12, @OGUID+1614),
(12, @OGUID+1615),
(12, @OGUID+1616),
(12, @OGUID+1617),
(12, @OGUID+1618),
(12, @OGUID+1619),
(12, @OGUID+1620),
(12, @OGUID+1621),
(12, @OGUID+1622),
(12, @OGUID+1623),
(12, @OGUID+1624),
(12, @OGUID+1625),
(12, @OGUID+1626),
(12, @OGUID+1627),
(12, @OGUID+1628),
(12, @OGUID+1629),
(12, @OGUID+1630),
(12, @OGUID+1631),
(12, @OGUID+1632),
(12, @OGUID+1633),
(12, @OGUID+1634),
(12, @OGUID+1635),
(12, @OGUID+1636),
(12, @OGUID+1637),
(12, @OGUID+1638),
(12, @OGUID+1639),
(12, @OGUID+1640),
(12, @OGUID+1641),
(12, @OGUID+1642),
(12, @OGUID+1643),
(12, @OGUID+1644),
(12, @OGUID+1645),
(12, @OGUID+1646),
(12, @OGUID+1647),
(12, @OGUID+1648),
(12, @OGUID+1649),
(12, @OGUID+1650),
(12, @OGUID+1651),
(12, @OGUID+1652),
(12, @OGUID+1653),
(12, @OGUID+1654),
(12, @OGUID+1655),
(12, @OGUID+1656),
(12, @OGUID+1657),
(12, @OGUID+1658),
(12, @OGUID+1659),
(12, @OGUID+1660),
(12, @OGUID+1661),
(12, @OGUID+1662),
(12, @OGUID+1663),
(12, @OGUID+1664),
(12, @OGUID+1665),
(12, @OGUID+1666),
(12, @OGUID+1667),
(12, @OGUID+1668),
(12, @OGUID+1669),
(12, @OGUID+1670),
(12, @OGUID+1671),
(12, @OGUID+1672),
(12, @OGUID+1673),
(12, @OGUID+1674),
(12, @OGUID+1675),
(12, @OGUID+1676),
(12, @OGUID+1677),
(12, @OGUID+1678),
(12, @OGUID+1679),
(12, @OGUID+1680),
(12, @OGUID+1681),
(12, @OGUID+1682),
(12, @OGUID+1683),
(12, @OGUID+1684),
(12, @OGUID+1685),
(12, @OGUID+1686),
(12, @OGUID+1687),
(12, @OGUID+1688),
(12, @OGUID+1689),
(12, @OGUID+1690),
(12, @OGUID+1691),
(12, @OGUID+1692),
(12, @OGUID+1693),
(12, @OGUID+1694),
(12, @OGUID+1695),
(12, @OGUID+1696),
(12, @OGUID+1697),
(12, @OGUID+1698),
(12, @OGUID+1699),
(12, @OGUID+1700),
(12, @OGUID+1701),
(12, @OGUID+1702),
(12, @OGUID+1703),
(12, @OGUID+1704),
(12, @OGUID+1705),
(12, @OGUID+1706),
(12, @OGUID+1707),
(12, @OGUID+1708),
(12, @OGUID+1709),
(12, @OGUID+1710),
(12, @OGUID+1711),
(12, @OGUID+1712),
(12, @OGUID+1713),
(12, @OGUID+1714),
(12, @OGUID+1715),
(12, @OGUID+1716),
(12, @OGUID+1717),
(12, @OGUID+1718),
(12, @OGUID+1719),
(12, @OGUID+1720),
(12, @OGUID+1721),
(12, @OGUID+1722),
(12, @OGUID+1723),
(12, @OGUID+1724),
(12, @OGUID+1725),
(12, @OGUID+1726),
(12, @OGUID+1727),
(12, @OGUID+1728),
(12, @OGUID+1729),
(12, @OGUID+1730),
(12, @OGUID+1731),
(12, @OGUID+1732),
(12, @OGUID+1733),
(12, @OGUID+1734),
(12, @OGUID+1735),
(12, @OGUID+1736),
(12, @OGUID+1737),
(12, @OGUID+1738),
(12, @OGUID+1739),
(12, @OGUID+1740),
(12, @OGUID+1741),
(12, @OGUID+1742),
(12, @OGUID+1743),
(12, @OGUID+1744),
(12, @OGUID+1745),
(12, @OGUID+1746),
(12, @OGUID+1747),
(12, @OGUID+1748),
(12, @OGUID+1749),
(12, @OGUID+1750),
(12, @OGUID+1751),
(12, @OGUID+1752),
(12, @OGUID+1753),
(12, @OGUID+1754),
(12, @OGUID+1755),
(12, @OGUID+1756),
(12, @OGUID+1757),
(12, @OGUID+1758),
(12, @OGUID+1759),
(12, @OGUID+1760),
(12, @OGUID+1761),
(12, @OGUID+1762),
(12, @OGUID+1763),
(12, @OGUID+1764),
(12, @OGUID+1765),
(12, @OGUID+1766),
(12, @OGUID+1767),
(12, @OGUID+1768),
(12, @OGUID+1769),
(12, @OGUID+1770),
(12, @OGUID+1771),
(12, @OGUID+1772),
(12, @OGUID+1773),
(12, @OGUID+1774),
(12, @OGUID+1775),
(12, @OGUID+1776),
(12, @OGUID+1777),
(12, @OGUID+1778),
(12, @OGUID+1779),
(12, @OGUID+1780),
(12, @OGUID+1781),
(12, @OGUID+1782),
(12, @OGUID+1783),
(12, @OGUID+1784),
(12, @OGUID+1785),
(12, @OGUID+1786),
(12, @OGUID+1787),
(12, @OGUID+1788),
(12, @OGUID+1789),
(12, @OGUID+1790),
(12, @OGUID+1791),
(12, @OGUID+1792),
(12, @OGUID+1793),
(12, @OGUID+1794),
(12, @OGUID+1795),
(12, @OGUID+1796),
(12, @OGUID+1797),
(12, @OGUID+1798),
(12, @OGUID+1799),
(12, @OGUID+1800),
(12, @OGUID+1801),
(12, @OGUID+1802),
(12, @OGUID+1803),
(12, @OGUID+1804),
(12, @OGUID+1805),
(12, @OGUID+1806),
(12, @OGUID+1807),
(12, @OGUID+1808),
(12, @OGUID+1809),
(12, @OGUID+1810),
(12, @OGUID+1811),
(12, @OGUID+1812),
(12, @OGUID+1813),
(12, @OGUID+1814),
(12, @OGUID+1815),
(12, @OGUID+1816),
(12, @OGUID+1817),
(12, @OGUID+1818),
(12, @OGUID+1819),
(12, @OGUID+1820),
(12, @OGUID+1821),
(12, @OGUID+1822),
(12, @OGUID+1823),
(12, @OGUID+1824),
(12, @OGUID+1825),
(12, @OGUID+1826),
(12, @OGUID+1827),
(12, @OGUID+1828),
(12, @OGUID+1829),
(12, @OGUID+1830),
(12, @OGUID+1831),
(12, @OGUID+1832),
(12, @OGUID+1833),
(12, @OGUID+1834),
(12, @OGUID+1835),
(12, @OGUID+1836),
(12, @OGUID+1837),
(12, @OGUID+1838),
(12, @OGUID+1839),
(12, @OGUID+1840),
(12, @OGUID+1841),
(12, @OGUID+1842),
(12, @OGUID+1843),
(12, @OGUID+1844),
(12, @OGUID+1845),
(12, @OGUID+1846),
(12, @OGUID+1847),
(12, @OGUID+1848),
(12, @OGUID+1849),
(12, @OGUID+1850),
(12, @OGUID+1851),
(12, @OGUID+1852),
(12, @OGUID+1853),
(12, @OGUID+1854),
(12, @OGUID+1855),
(12, @OGUID+1856),
(12, @OGUID+1857),
(12, @OGUID+1858),
(12, @OGUID+1859),
(12, @OGUID+1860),
(12, @OGUID+1861),
(12, @OGUID+1862),
(12, @OGUID+1863),
(12, @OGUID+1864),
(12, @OGUID+1865),
(12, @OGUID+1866),
(12, @OGUID+1867),
(12, @OGUID+1868),
(12, @OGUID+1869),
(12, @OGUID+1870),
(12, @OGUID+1871),
(12, @OGUID+1872),
(12, @OGUID+1873),
(12, @OGUID+1874),
(12, @OGUID+1875),
(12, @OGUID+1876),
(12, @OGUID+1877),
(12, @OGUID+1878),
(12, @OGUID+1879),
(12, @OGUID+1880),
(12, @OGUID+1881),
(12, @OGUID+1882),
(12, @OGUID+1883),
(12, @OGUID+1884),
(12, @OGUID+1885),
(12, @OGUID+1886),
(12, @OGUID+1887),
(12, @OGUID+1888),
(12, @OGUID+1889),
(12, @OGUID+1890),
(12, @OGUID+1891),
(12, @OGUID+1892),
(12, @OGUID+1893),
(12, @OGUID+1894),
(12, @OGUID+1895),
(12, @OGUID+1896),
(12, @OGUID+1897),
(12, @OGUID+1898),
(12, @OGUID+1899),
(12, @OGUID+1900),
(12, @OGUID+1901),
(12, @OGUID+1902),
(12, @OGUID+1903),
(12, @OGUID+1904),
(12, @OGUID+1905),
(12, @OGUID+1906),
(12, @OGUID+1907),
(12, @OGUID+1908),
(12, @OGUID+1909),
(12, @OGUID+1910),
(12, @OGUID+1911),
(12, @OGUID+1912),
(12, @OGUID+1913),
(12, @OGUID+1914),
(12, @OGUID+1915),
(12, @OGUID+1916),
(12, @OGUID+1917),
(12, @OGUID+1918),
(12, @OGUID+1919),
(12, @OGUID+1920),
(12, @OGUID+1921),
(12, @OGUID+1922),
(12, @OGUID+1923),
(12, @OGUID+1924),
(12, @OGUID+1925),
(12, @OGUID+1926),
(12, @OGUID+1927),
(12, @OGUID+1928),
(12, @OGUID+1929),
(12, @OGUID+1930),
(12, @OGUID+1931),
(12, @OGUID+1932),
(12, @OGUID+1933),
(12, @OGUID+1934),
(12, @OGUID+1935),
(12, @OGUID+1936),
(12, @OGUID+1937),
(12, @OGUID+1938),
(12, @OGUID+1939),
(12, @OGUID+1940),
(12, @OGUID+1941),
(12, @OGUID+1942),
(12, @OGUID+1943),
(12, @OGUID+1944),
(12, @OGUID+1945),
(12, @OGUID+1946),
(12, @OGUID+1947),
(12, @OGUID+1948),
(12, @OGUID+1949),
(12, @OGUID+1950),
(12, @OGUID+1951),
(12, @OGUID+1952),
(12, @OGUID+1953),
(12, @OGUID+1954),
(12, @OGUID+1955),
(12, @OGUID+1956),
(12, @OGUID+1957),
(12, @OGUID+1958),
(12, @OGUID+1959),
(12, @OGUID+1960),
(12, @OGUID+1961),
(12, @OGUID+1962),
(12, @OGUID+1963),
(12, @OGUID+1964),
(12, @OGUID+1965),
(12, @OGUID+1966),
(12, @OGUID+1967),
(12, @OGUID+1968),
(12, @OGUID+1969),
(12, @OGUID+1970),
(12, @OGUID+1971),
(12, @OGUID+1972),
(12, @OGUID+1973),
(12, @OGUID+1974),
(12, @OGUID+1975),
(12, @OGUID+1976),
(12, @OGUID+1977),
(12, @OGUID+1978),
(12, @OGUID+1979),
(12, @OGUID+1980),
(12, @OGUID+1981),
(12, @OGUID+1982),
(12, @OGUID+1983),
(12, @OGUID+1984),
(12, @OGUID+1985),
(12, @OGUID+1986),
(12, @OGUID+1987),
(12, @OGUID+1988),
(12, @OGUID+1989),
(12, @OGUID+1990),
(12, @OGUID+1991),
(12, @OGUID+1992),
(12, @OGUID+1993),
(12, @OGUID+1994),
(12, @OGUID+1995),
(12, @OGUID+1996),
(12, @OGUID+1997),
(12, @OGUID+1998),
(12, @OGUID+1999),
(12, @OGUID+2000),
(12, @OGUID+2001),
(12, @OGUID+2002),
(12, @OGUID+2003),
(12, @OGUID+2004),
(12, @OGUID+2005),
(12, @OGUID+2006),
(12, @OGUID+2007),
(12, @OGUID+2008),
(12, @OGUID+2009),
(12, @OGUID+2010),
(12, @OGUID+2011),
(12, @OGUID+2012),
(12, @OGUID+2013),
(12, @OGUID+2014),
(12, @OGUID+2015),
(12, @OGUID+2016),
(12, @OGUID+2017),
(12, @OGUID+2018),
(12, @OGUID+2019),
(12, @OGUID+2020),
(12, @OGUID+2021),
(12, @OGUID+2022),
(12, @OGUID+2023),
(12, @OGUID+2024),
(12, @OGUID+2025),
(12, @OGUID+2026),
(12, @OGUID+2027),
(12, @OGUID+2028),
(12, @OGUID+2029),
(12, @OGUID+2030),
(12, @OGUID+2031),
(12, @OGUID+2032),
(12, @OGUID+2033),
(12, @OGUID+2034),
(12, @OGUID+2035),
(12, @OGUID+2036),
(12, @OGUID+2037),
(12, @OGUID+2038),
(12, @OGUID+2039),
(12, @OGUID+2040),
(12, @OGUID+2041),
(12, @OGUID+2042),
(12, @OGUID+2043),
(12, @OGUID+2044),
(12, @OGUID+2045),
(12, @OGUID+2046),
(12, @OGUID+2047),
(12, @OGUID+2048),
(12, @OGUID+2049),
(12, @OGUID+2050),
(12, @OGUID+2051),
(12, @OGUID+2052),
(12, @OGUID+2053),
(12, @OGUID+2054),
(12, @OGUID+2055),
(12, @OGUID+2056),
(12, @OGUID+2057),
(12, @OGUID+2058),
(12, @OGUID+2059),
(12, @OGUID+2060),
(12, @OGUID+2061),
(12, @OGUID+2062),
(12, @OGUID+2063),
(12, @OGUID+2064),
(12, @OGUID+2065),
(12, @OGUID+2066),
(12, @OGUID+2067),
(12, @OGUID+2068),
(12, @OGUID+2069),
(12, @OGUID+2070),
(12, @OGUID+2071),
(12, @OGUID+2072),
(12, @OGUID+2073),
(12, @OGUID+2074),
(12, @OGUID+2075),
(12, @OGUID+2076),
(12, @OGUID+2077),
(12, @OGUID+2078),
(12, @OGUID+2079),
(12, @OGUID+2080),
(12, @OGUID+2081),
(12, @OGUID+2082),
(12, @OGUID+2083),
(12, @OGUID+2084),
(12, @OGUID+2085),
(12, @OGUID+2086),
(12, @OGUID+2087),
(12, @OGUID+2088),
(12, @OGUID+2089),
(12, @OGUID+2090),
(12, @OGUID+2091),
(12, @OGUID+2092),
(12, @OGUID+2093),
(12, @OGUID+2094),
(12, @OGUID+2095),
(12, @OGUID+2096),
(12, @OGUID+2097),
(12, @OGUID+2098),
(12, @OGUID+2099),
(12, @OGUID+2100),
(12, @OGUID+2101),
(12, @OGUID+2102),
(12, @OGUID+2103),
(12, @OGUID+2104),
(12, @OGUID+2105),
(12, @OGUID+2106),
(12, @OGUID+2107),
(12, @OGUID+2108),
(12, @OGUID+2109),
(12, @OGUID+2110),
(12, @OGUID+2111),
(12, @OGUID+2112),
(12, @OGUID+2113),
(12, @OGUID+2114),
(12, @OGUID+2115),
(12, @OGUID+2116),
(12, @OGUID+2117),
(12, @OGUID+2118),
(12, @OGUID+2119),
(12, @OGUID+2120),
(12, @OGUID+2121),
(12, @OGUID+2122),
(12, @OGUID+2123),
(12, @OGUID+2124),
(12, @OGUID+2125),
(12, @OGUID+2126),
(12, @OGUID+2127),
(12, @OGUID+2128),
(12, @OGUID+2129),
(12, @OGUID+2130),
(12, @OGUID+2131),
(12, @OGUID+2132),
(12, @OGUID+2133),
(12, @OGUID+2134),
(12, @OGUID+2135),
(12, @OGUID+2136),
(12, @OGUID+2137),
(12, @OGUID+2138),
(12, @OGUID+2139),
(12, @OGUID+2140),
(12, @OGUID+2141),
(12, @OGUID+2142),
(12, @OGUID+2143),
(12, @OGUID+2144),
(12, @OGUID+2145),
(12, @OGUID+2146),
(12, @OGUID+2147),
(12, @OGUID+2148),
(12, @OGUID+2149),
(12, @OGUID+2150),
(12, @OGUID+2151),
(12, @OGUID+2152),
(12, @OGUID+2153),
(12, @OGUID+2154),
(12, @OGUID+2155),
(12, @OGUID+2156),
(12, @OGUID+2157),
(12, @OGUID+2158),
(12, @OGUID+2159),
(12, @OGUID+2160),
(12, @OGUID+2161),
(12, @OGUID+2162),
(12, @OGUID+2163),
(12, @OGUID+2164),
(12, @OGUID+2165),
(12, @OGUID+2166),
(12, @OGUID+2167),
(12, @OGUID+2168),
(12, @OGUID+2169),
(12, @OGUID+2170),
(12, @OGUID+2171),
(12, @OGUID+2172),
(12, @OGUID+2173),
(12, @OGUID+2174),
(12, @OGUID+2175),
(12, @OGUID+2176),
(12, @OGUID+2177),
(12, @OGUID+2178),
(12, @OGUID+2179),
(12, @OGUID+2180),
(12, @OGUID+2181),
(12, @OGUID+2182),
(12, @OGUID+2183),
(12, @OGUID+2184),
(12, @OGUID+2185),
(12, @OGUID+2186),
(12, @OGUID+2187),
(12, @OGUID+2188),
(12, @OGUID+2189),
(12, @OGUID+2190),
(12, @OGUID+2191),
(12, @OGUID+2192),
(12, @OGUID+2193),
(12, @OGUID+2194),
(12, @OGUID+2195),
(12, @OGUID+2196),
(12, @OGUID+2197),
(12, @OGUID+2198),
(12, @OGUID+2199),
(12, @OGUID+2200),
(12, @OGUID+2201),
(12, @OGUID+2202),
(12, @OGUID+2203),
(12, @OGUID+2204),
(12, @OGUID+2205),
(12, @OGUID+2206),
(12, @OGUID+2207),
(12, @OGUID+2208),
(12, @OGUID+2209),
(12, @OGUID+2210),
(12, @OGUID+2211),
(12, @OGUID+2212),
(12, @OGUID+2213),
(12, @OGUID+2214),
(12, @OGUID+2215),
(12, @OGUID+2216),
(12, @OGUID+2217),
(12, @OGUID+2218),
(12, @OGUID+2219),
(12, @OGUID+2220),
(12, @OGUID+2221),
(12, @OGUID+2222),
(12, @OGUID+2223),
(12, @OGUID+2224),
(12, @OGUID+2225),
(12, @OGUID+2226),
(12, @OGUID+2227),
(12, @OGUID+2228),
(12, @OGUID+2229),
(12, @OGUID+2230),
(12, @OGUID+2231),
(12, @OGUID+2232),
(12, @OGUID+2233),
(12, @OGUID+2234),
(12, @OGUID+2235),
(12, @OGUID+2236),
(12, @OGUID+2237),
(12, @OGUID+2238),
(12, @OGUID+2239),
(12, @OGUID+2240),
(12, @OGUID+2241),
(12, @OGUID+2242),
(12, @OGUID+2243),
(12, @OGUID+2244),
(12, @OGUID+2245),
(12, @OGUID+2246),
(12, @OGUID+2247),
(12, @OGUID+2248),
(12, @OGUID+2249),
(12, @OGUID+2250),
(12, @OGUID+2251),
(12, @OGUID+2252),
(12, @OGUID+2253),
(12, @OGUID+2254),
(12, @OGUID+2255),
(12, @OGUID+2256),
(12, @OGUID+2257),
(12, @OGUID+2258),
(12, @OGUID+2259),
(12, @OGUID+2260),
(12, @OGUID+2261),
(12, @OGUID+2262),
(12, @OGUID+2263),
(12, @OGUID+2264),
(12, @OGUID+2265),
(12, @OGUID+2266),
(12, @OGUID+2267),
(12, @OGUID+2268),
(12, @OGUID+2269),
(12, @OGUID+2270),
(12, @OGUID+2271),
(12, @OGUID+2272),
(12, @OGUID+2273),
(12, @OGUID+2274),
(12, @OGUID+2275),
(12, @OGUID+2276),
(12, @OGUID+2277),
(12, @OGUID+2278),
(12, @OGUID+2279),
(12, @OGUID+2280),
(12, @OGUID+2281),
(12, @OGUID+2282),
(12, @OGUID+2283),
(12, @OGUID+2284),
(12, @OGUID+2285),
(12, @OGUID+2286),
(12, @OGUID+2287),
(12, @OGUID+2288),
(12, @OGUID+2289),
(12, @OGUID+2290),
(12, @OGUID+2291),
(12, @OGUID+2292),
(12, @OGUID+2293),
(12, @OGUID+2294),
(12, @OGUID+2295),
(12, @OGUID+2296),
(12, @OGUID+2297),
(12, @OGUID+2298),
(12, @OGUID+2299),
(12, @OGUID+2300),
(12, @OGUID+2301),
(12, @OGUID+2302),
(12, @OGUID+2303),
(12, @OGUID+2304),
(12, @OGUID+2305),
(12, @OGUID+2306),
(12, @OGUID+2307),
(12, @OGUID+2308),
(12, @OGUID+2309),
(12, @OGUID+2310),
(12, @OGUID+2311),
(12, @OGUID+2312),
(12, @OGUID+2313),
(12, @OGUID+2314),
(12, @OGUID+2315),
(12, @OGUID+2316),
(12, @OGUID+2317),
(12, @OGUID+2318),
(12, @OGUID+2319),
(12, @OGUID+2320),
(12, @OGUID+2321),
(12, @OGUID+2322),
(12, @OGUID+2323),
(12, @OGUID+2324),
(12, @OGUID+2325),
(12, @OGUID+2326),
(12, @OGUID+2327),
(12, @OGUID+2328),
(12, @OGUID+2329),
(12, @OGUID+2330),
(12, @OGUID+2331),
(12, @OGUID+2332),
(12, @OGUID+2333),
(12, @OGUID+2334),
(12, @OGUID+2335),
(12, @OGUID+2336),
(12, @OGUID+2337),
(12, @OGUID+2338),
(12, @OGUID+2339),
(12, @OGUID+2340),
(12, @OGUID+2341),
(12, @OGUID+2342),
(12, @OGUID+2343),
(12, @OGUID+2344),
(12, @OGUID+2345),
(12, @OGUID+2346),
(12, @OGUID+2347),
(12, @OGUID+2348),
(12, @OGUID+2349),
(12, @OGUID+2350),
(12, @OGUID+2351),
(12, @OGUID+2352),
(12, @OGUID+2353),
(12, @OGUID+2354),
(12, @OGUID+2355),
(12, @OGUID+2356),
(12, @OGUID+2357),
(12, @OGUID+2358),
(12, @OGUID+2359),
(12, @OGUID+2360),
(12, @OGUID+2361),
(12, @OGUID+2362),
(12, @OGUID+2363),
(12, @OGUID+2364),
(12, @OGUID+2365),
(12, @OGUID+2366),
(12, @OGUID+2367),
(12, @OGUID+2368),
(12, @OGUID+2369),
(12, @OGUID+2370),
(12, @OGUID+2371),
(12, @OGUID+2372),
(12, @OGUID+2373),
(12, @OGUID+2374),
(12, @OGUID+2375),
(12, @OGUID+2376),
(12, @OGUID+2377),
(12, @OGUID+2378),
(12, @OGUID+2379),
(12, @OGUID+2380),
(12, @OGUID+2381),
(12, @OGUID+2382),
(12, @OGUID+2383),
(12, @OGUID+2384),
(12, @OGUID+2385),
(12, @OGUID+2386),
(12, @OGUID+2387),
(12, @OGUID+2388),
(12, @OGUID+2389),
(12, @OGUID+2390),
(12, @OGUID+2391),
(12, @OGUID+2392),
(12, @OGUID+2393),
(12, @OGUID+2394),
(12, @OGUID+2395),
(12, @OGUID+2396),
(12, @OGUID+2397),
(12, @OGUID+2398),
(12, @OGUID+2399),
(12, @OGUID+2400),
(12, @OGUID+2401),
(12, @OGUID+2402),
(12, @OGUID+2403),
(12, @OGUID+2404),
(12, @OGUID+2405),
(12, @OGUID+2406),
(12, @OGUID+2407),
(12, @OGUID+2408),
(12, @OGUID+2409),
(12, @OGUID+2410),
(12, @OGUID+2411),
(12, @OGUID+2412),
(12, @OGUID+2413),
(12, @OGUID+2414),
(12, @OGUID+2415),
(12, @OGUID+2416),
(12, @OGUID+2417),
(12, @OGUID+2418),
(12, @OGUID+2419),
(12, @OGUID+2420),
(12, @OGUID+2421),
(12, @OGUID+2422),
(12, @OGUID+2423),
(12, @OGUID+2424),
(12, @OGUID+2425),
(12, @OGUID+2426),
(12, @OGUID+2427),
(12, @OGUID+2428),
(12, @OGUID+2429),
(12, @OGUID+2430),
(12, @OGUID+2431),
(12, @OGUID+2432),
(12, @OGUID+2433),
(12, @OGUID+2434),
(12, @OGUID+2435),
(12, @OGUID+2436),
(12, @OGUID+2437),
(12, @OGUID+2438),
(12, @OGUID+2439),
(12, @OGUID+2440),
(12, @OGUID+2441),
(12, @OGUID+2442),
(12, @OGUID+2443),
(12, @OGUID+2444),
(12, @OGUID+2445),
(12, @OGUID+2446),
(12, @OGUID+2447),
(12, @OGUID+2448),
(12, @OGUID+2449),
(12, @OGUID+2450),
(12, @OGUID+2451),
(12, @OGUID+2452),
(12, @OGUID+2453),
(12, @OGUID+2454),
(12, @OGUID+2455),
(12, @OGUID+2456),
(12, @OGUID+2457),
(12, @OGUID+2458),
(12, @OGUID+2459),
(12, @OGUID+2460),
(12, @OGUID+2461),
(12, @OGUID+2462),
(12, @OGUID+2463),
(12, @OGUID+2464),
(12, @OGUID+2465),
(12, @OGUID+2466),
(12, @OGUID+2467),
(12, @OGUID+2468),
(12, @OGUID+2469),
(12, @OGUID+2470),
(12, @OGUID+2471),
(12, @OGUID+2472),
(12, @OGUID+2473),
(12, @OGUID+2474),
(12, @OGUID+2475),
(12, @OGUID+2476),
(12, @OGUID+2477),
(12, @OGUID+2478),
(12, @OGUID+2479),
(12, @OGUID+2480),
(12, @OGUID+2481),
(12, @OGUID+2482),
(12, @OGUID+2483),
(12, @OGUID+2484),
(12, @OGUID+2485),
(12, @OGUID+2486),
(12, @OGUID+2487),
(12, @OGUID+2488),
(12, @OGUID+2489),
(12, @OGUID+2490),
(12, @OGUID+2491),
(12, @OGUID+2492),
(12, @OGUID+2493),
(12, @OGUID+2494),
(12, @OGUID+2495),
(12, @OGUID+2496),
(12, @OGUID+2497),
(12, @OGUID+2498),
(12, @OGUID+2499),
(12, @OGUID+2500),
(12, @OGUID+2501),
(12, @OGUID+2502),
(12, @OGUID+2503),
(12, @OGUID+2504),
(12, @OGUID+2505),
(12, @OGUID+2506),
(12, @OGUID+2507),
(12, @OGUID+2508),
(12, @OGUID+2509),
(12, @OGUID+2510),
(12, @OGUID+2511),
(12, @OGUID+2512),
(12, @OGUID+2513),
(12, @OGUID+2514),
(12, @OGUID+2515),
(12, @OGUID+2516),
(12, @OGUID+2517),
(12, @OGUID+2518),
(12, @OGUID+2519),
(12, @OGUID+2520),
(12, @OGUID+2521),
(12, @OGUID+2522),
(12, @OGUID+2523),
(12, @OGUID+2524),
(12, @OGUID+2525),
(12, @OGUID+2526),
(12, @OGUID+2527),
(12, @OGUID+2528),
(12, @OGUID+2529),
(12, @OGUID+2530),
(12, @OGUID+2531),
(12, @OGUID+2532),
(12, @OGUID+2533),
(12, @OGUID+2534),
(12, @OGUID+2535),
(12, @OGUID+2536),
(12, @OGUID+2537),
(12, @OGUID+2538),
(12, @OGUID+2539),
(12, @OGUID+2540),
(12, @OGUID+2541),
(12, @OGUID+2542),
(12, @OGUID+2543),
(12, @OGUID+2544),
(12, @OGUID+2545),
(12, @OGUID+2546),
(12, @OGUID+2547),
(12, @OGUID+2548),
(12, @OGUID+2549),
(12, @OGUID+2550),
(12, @OGUID+2551),
(12, @OGUID+2552),
(12, @OGUID+2553),
(12, @OGUID+2554),
(12, @OGUID+2555),
(12, @OGUID+2556),
(12, @OGUID+2557),
(12, @OGUID+2558),
(12, @OGUID+2559),
(12, @OGUID+2560),
(12, @OGUID+2561),
(12, @OGUID+2562),
(12, @OGUID+2563),
(12, @OGUID+2564),
(12, @OGUID+2565),
(12, @OGUID+2566),
(12, @OGUID+2567),
(12, @OGUID+2568),
(12, @OGUID+2569),
(12, @OGUID+2570),
(12, @OGUID+2571),
(12, @OGUID+2572),
(12, @OGUID+2573),
(12, @OGUID+2574),
(12, @OGUID+2575),
(12, @OGUID+2576),
(12, @OGUID+2577),
(12, @OGUID+2578),
(12, @OGUID+2579),
(12, @OGUID+2580),
(12, @OGUID+2581),
(12, @OGUID+2582),
(12, @OGUID+2583),
(12, @OGUID+2584),
(12, @OGUID+2585),
(12, @OGUID+2586),
(12, @OGUID+2587),
(12, @OGUID+2588),
(12, @OGUID+2589),
(12, @OGUID+2590),
(12, @OGUID+2591),
(12, @OGUID+2592),
(12, @OGUID+2593),
(12, @OGUID+2594),
(12, @OGUID+2595),
(12, @OGUID+2596),
(12, @OGUID+2597),
(12, @OGUID+2598),
(12, @OGUID+2599),
(12, @OGUID+2600),
(12, @OGUID+2601),
(12, @OGUID+2602),
(12, @OGUID+2603),
(12, @OGUID+2604),
(12, @OGUID+2605),
(12, @OGUID+2606),
(12, @OGUID+2607),
(12, @OGUID+2608),
(12, @OGUID+2609),
(12, @OGUID+2610),
(12, @OGUID+2611),
(12, @OGUID+2612),
(12, @OGUID+2613),
(12, @OGUID+2614),
(12, @OGUID+2615),
(12, @OGUID+2616),
(12, @OGUID+2617),
(12, @OGUID+2618),
(12, @OGUID+2619),
(12, @OGUID+2620),
(12, @OGUID+2621),
(12, @OGUID+2622),
(12, @OGUID+2623),
(12, @OGUID+2624),
(12, @OGUID+2625),
(12, @OGUID+2626),
(12, @OGUID+2627),
(12, @OGUID+2628),
(12, @OGUID+2629),
(12, @OGUID+2630),
(12, @OGUID+2631),
(12, @OGUID+2632),
(12, @OGUID+2633),
(12, @OGUID+2634),
(12, @OGUID+2635),
(12, @OGUID+2636),
(12, @OGUID+2637),
(12, @OGUID+2638),
(12, @OGUID+2639),
(12, @OGUID+2640),
(12, @OGUID+2641),
(12, @OGUID+2642),
(12, @OGUID+2643),
(12, @OGUID+2644),
(12, @OGUID+2645),
(12, @OGUID+2646),
(12, @OGUID+2647),
(12, @OGUID+2648),
(12, @OGUID+2649),
(12, @OGUID+2650),
(12, @OGUID+2651),
(12, @OGUID+2652),
(12, @OGUID+2653),
(12, @OGUID+2654),
(12, @OGUID+2655),
(12, @OGUID+2656),
(12, @OGUID+2657),
(12, @OGUID+2658),
(12, @OGUID+2659),
(12, @OGUID+2660),
(12, @OGUID+2661),
(12, @OGUID+2662),
(12, @OGUID+2663),
(12, @OGUID+2664),
(12, @OGUID+2665),
(12, @OGUID+2666),
(12, @OGUID+2667),
(12, @OGUID+2668),
(12, @OGUID+2669),
(12, @OGUID+2670),
(12, @OGUID+2671),
(12, @OGUID+2672),
(12, @OGUID+2673),
(12, @OGUID+2674),
(12, @OGUID+2675),
(12, @OGUID+2676),
(12, @OGUID+2677),
(12, @OGUID+2678),
(12, @OGUID+2679),
(12, @OGUID+2680),
(12, @OGUID+2681),
(12, @OGUID+2682),
(12, @OGUID+2683),
(12, @OGUID+2684),
(12, @OGUID+2685),
(12, @OGUID+2686),
(12, @OGUID+2687),
(12, @OGUID+2688),
(12, @OGUID+2689),
(12, @OGUID+2690),
(12, @OGUID+2691),
(12, @OGUID+2692),
(12, @OGUID+2693),
(12, @OGUID+2694),
(12, @OGUID+2695),
(12, @OGUID+2696),
(12, @OGUID+2697),
(12, @OGUID+2698),
(12, @OGUID+2699),
(12, @OGUID+2700),
(12, @OGUID+2701),
(12, @OGUID+2702);
