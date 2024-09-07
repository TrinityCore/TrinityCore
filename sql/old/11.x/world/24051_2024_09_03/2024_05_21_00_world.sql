-- Normal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96754 AND `DifficultyID`=1); -- Harbaron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96756 AND `DifficultyID`=1); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96759 AND `DifficultyID`=0); -- Helya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97043 AND `DifficultyID`=1); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97097 AND `DifficultyID`=1); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97119 AND `DifficultyID`=1); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97163 AND `DifficultyID`=1); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97182 AND `DifficultyID`=1); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97185 AND `DifficultyID`=1); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97200 AND `DifficultyID`=1); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97365 AND `DifficultyID`=1); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (98363,100354,100360,100362)); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98693 AND `DifficultyID`=0); -- Shackled Servitor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98761 AND `DifficultyID`=0); -- Soul Fragment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98919 AND `DifficultyID`=1); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98973 AND `DifficultyID`=1) OR (`Entry`=114288 AND `DifficultyID`=0); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99033 AND `DifficultyID`=1); -- Helarjar Mistcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99188 AND `DifficultyID`=1); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99307 AND `DifficultyID`=1); -- Skjal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99801 AND `DifficultyID`=0); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102104 AND `DifficultyID`=1); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102375,114712)); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111221 AND `DifficultyID`=1); -- Xal'atath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111833 AND `DifficultyID`=1); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114289 AND `DifficultyID`=0); -- Skeletal Sorcerer

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (96759,97099,98363,98693,98761,99800,99801,99803,100188,100353,100354,100359,100360,100361,100362,101502,101504,101814,102306,114288,114289));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(96759, 1, 2, 2, 485, 805306624, 0, 0, 0, 0, 0, 0, 0, 54762), -- Helya
(97099, 1, 0, 0, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Swirling Pool
(98363, 1, 1, 1, 485, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(98693, 1, 1, 1, 485, 268435456, 0, 0, 0, 0, 0, 0, 0, 54762), -- Shackled Servitor
(98761, 1, 0, 0, 485, 268435456, 0, 0, 0, 0, 0, 0, 0, 54762), -- Soul Fragment
(99800, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(99801, 1, 1, 1, 485, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Destructor Tentacle
(99803, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Destructor Tentacle
(100188, 1, 1, 1, 1155, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- Piercing Tentacle
(100353, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(100354, 1, 1, 1, 485, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(100359, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(100360, 1, 1, 1, 485, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(100361, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(100362, 1, 1, 1, 485, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(101502, 1, 0, 0, 1155, 536870912, 0, 0, 0, 0, 0, 0, 0, 54762), -- Helya's Tentacle
(101504, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(101814, 1, 2, 2, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Grasping Tentacle
(102306, 1, 0, 0, 1155, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Swirling Pool
(114288, 1, 0, 0, 485, 268435456, 0, 0, 0, 0, 0, 0, 0, 54762), -- Skeletal Warrior
(114289, 1, 0, 0, 485, 268435456, 0, 0, 0, 0, 0, 0, 0, 54762); -- Skeletal Sorcerer

UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96754 AND `DifficultyID`=1); -- Harbaron
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96756 AND `DifficultyID`=1); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97043 AND `DifficultyID`=1); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97097 AND `DifficultyID`=1); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97119 AND `DifficultyID`=1); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=805306368, `VerifiedBuild`=54762 WHERE (`Entry`=97163 AND `DifficultyID`=1); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97182 AND `DifficultyID`=1); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97185 AND `DifficultyID`=1); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97200 AND `DifficultyID`=1); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=97208 AND `DifficultyID`=1); -- Spear
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97365 AND `DifficultyID`=1); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`DifficultyID`=1 AND `Entry` IN (98291,102326)); -- Seacursed Rower
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98919 AND `DifficultyID`=1); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98973 AND `DifficultyID`=1); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=98989 AND `DifficultyID`=1); -- Cosmic Scythe
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99033 AND `DifficultyID`=1); -- Helarjar Mistcaller
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99188 AND `DifficultyID`=1); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99307 AND `DifficultyID`=1); -- Skjal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=100733 AND `DifficultyID`=1); -- Charge
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=100839 AND `DifficultyID`=1); -- Cosmic Scythe
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=101013 AND `DifficultyID`=1); -- Captured Runecarver
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=102104 AND `DifficultyID`=1); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=102108 AND `DifficultyID`=1); -- Captured Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=1 AND `Entry` IN (102325,102327)); -- Seacursed Rower
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=102375 AND `DifficultyID`=1); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102742 AND `DifficultyID`=1); -- Fallen Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102769 AND `DifficultyID`=1); -- Decrepit Runecarver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102830 AND `DifficultyID`=1); -- Deceased Sorcerer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=102894 AND `DifficultyID`=1); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=102896 AND `DifficultyID`=1); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54762 WHERE (`DifficultyID`=1 AND `Entry` IN (103115,111374));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=54762 WHERE (`Entry`=111221 AND `DifficultyID`=1); -- Xal'atath
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=54762 WHERE (`Entry`=111833 AND `DifficultyID`=1); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=114712 AND `DifficultyID`=1); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `ContentTuningID`=877, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=188142 AND `DifficultyID`=1); -- Motion Sick Peon's Soul

-- Heroic
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (96754,96756,96759,97043,97097,97099,97119,97163,97182,97185,97200,97365,98246,98363,98693,98761,98919,98973,99033,99188,99307,99800,99801,99803,100188,100353,100354,100359,100360,101502,101504,101814,102104,102306,102375,114288,114289,114712));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(96754, 2, 6, 38, 1, 103217, 2097256, 128), -- Harbaron
(96756, 2, 6, 35, 0.000350554008036851, 103241, 2097256, 128), -- Ymiron, the Fallen King
(96759, 2, 6, 249.600006103515625, 1, 102839, 2097260, 128), -- Helya
(97043, 2, 6, 5.15000009536743164, 1, 103230, 2097224, 0), -- Seacursed Slaver
(97097, 2, 6, 6.5, 1, 103225, 270532680, 0), -- Helarjar Champion
(97099, 2, 6, 1, 1, 97598, 1024, 0), -- Swirling Pool
(97119, 2, 6, 1.5, 1, 103224, 2097224, 0), -- Shroud Hound
(97163, 2, 6, 0.800000011920928955, 1, 103237, 2097224, 0), -- Cursed Falke
(97182, 2, 6, 7.5, 1, 103226, 270532680, 0), -- Night Watch Mariner
(97185, 2, 6, 15, 1, 103233, 2097224, 0), -- The Grimewalker
(97200, 2, 6, 6.5, 1, 103229, 2097224, 0), -- Seacursed Soulkeeper
(97365, 2, 6, 4.75, 1, 103227, 270532680, 0), -- Seacursed Mistmender
(98246, 2, 6, 0.899999976158142089, 1, 117105, 2097224, 128), -- Risen Warrior
(98363, 2, 6, 4, 1, 103221, 104, 128), -- Grasping Tentacle
(98693, 2, 6, 1.299999952316284179, 1, 103218, 2097224, 128), -- Shackled Servitor
(98761, 2, 6, 0.5, 1, 102165, 2097224, 128), -- Soul Fragment
(98919, 2, 6, 4.25, 1, 103231, 270532680, 0), -- Seacursed Swiftblade
(98973, 2, 6, 1.10000002384185791, 0.065200001001358032, 103236, 2097224, 0), -- Skeletal Warrior
(99033, 2, 6, 5.5, 1, 103228, 270532680, 0), -- Helarjar Mistcaller
(99188, 2, 6, 5.25, 1, 103232, 2097224, 0), -- Waterlogged Soul Guard
(99307, 2, 6, 16, 1, 103234, 270532712, 0), -- Skjal
(99800, 2, 6, 1, 1, 100308, 0, 128), -- Grasping Tentacle
(99801, 2, 6, 4, 1, 103223, 2097256, 128), -- Destructor Tentacle
(99803, 2, 6, 1, 1, 100311, 0, 128), -- Destructor Tentacle
(100188, 2, 6, 1, 1, 100697, 0, 128), -- Piercing Tentacle
(100353, 2, 6, 1, 1, 100863, 0, 128), -- Grasping Tentacle
(100354, 2, 6, 4, 1, 103222, 104, 128), -- Grasping Tentacle
(100359, 2, 6, 1, 1, 100869, 0, 128), -- Grasping Tentacle
(100360, 2, 6, 4, 1, 103219, 104, 128), -- Grasping Tentacle
(101502, 2, 6, 1, 1, 102076, 0, 0), -- Helya's Tentacle
(101504, 2, 6, 1, 1, 102078, 0, 0), -- Grasping Tentacle
(101814, 2, 6, 1, 1, 102424, 0, 0), -- Grasping Tentacle
(102104, 2, 6, 5, 1, 103240, 2097224, 0), -- Enslaved Shieldmaiden
(102306, 2, 6, 1, 1, 103079, 1024, 0), -- Swirling Pool
(102375, 2, 6, 4, 140.25439453125, 103238, 2097224, 0), -- Runecarver Slave
(114288, 2, 6, 1.10000002384185791, 0.065200001001358032, 117624, 2097224, 0), -- Skeletal Warrior
(114289, 2, 6, 0.75, 1, 117627, 270532680, 0), -- Skeletal Sorcerer
(114712, 2, 6, 4, 140.25439453125, 118182, 2097224, 0); -- Runecarver Slave

UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=54762 WHERE (`Entry`=111221 AND `DifficultyID`=2); -- Xal'atath
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54762 WHERE (`Entry`=111374 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96754 AND `DifficultyID`=2); -- Harbaron
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96756 AND `DifficultyID`=2); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=96759 AND `DifficultyID`=2); -- Helya
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97043 AND `DifficultyID`=2); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97097 AND `DifficultyID`=2); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=2 AND `Entry` IN (97099,102306)); -- Swirling Pool
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97119 AND `DifficultyID`=2); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=805306368, `VerifiedBuild`=54762 WHERE (`Entry`=97163 AND `DifficultyID`=2); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97182 AND `DifficultyID`=2); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97185 AND `DifficultyID`=2); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97200 AND `DifficultyID`=2); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97365 AND `DifficultyID`=2); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98246 AND `DifficultyID`=2); -- Risen Warrior
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=2 AND `Entry` IN (98363,100354,100360)); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98693 AND `DifficultyID`=2); -- Shackled Servitor
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98761 AND `DifficultyID`=2); -- Soul Fragment
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98919 AND `DifficultyID`=2); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=2 AND `Entry` IN (98973,114288)); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99033 AND `DifficultyID`=2); -- Helarjar Mistcaller
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99188 AND `DifficultyID`=2); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99307 AND `DifficultyID`=2); -- Skjal
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=2 AND `Entry` IN (99800,100353,100359,101504,101814)); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=99801 AND `DifficultyID`=2); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=99803 AND `DifficultyID`=2); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1155, `VerifiedBuild`=54762 WHERE (`Entry`=100188 AND `DifficultyID`=2); -- Piercing Tentacle
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=101502 AND `DifficultyID`=2); -- Helya's Tentacle
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=102104 AND `DifficultyID`=2); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=2 AND `Entry` IN (102375,114712)); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=114289 AND `DifficultyID`=2); -- Skeletal Sorcerer

-- Mythic
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (96759,97099,98246,98363,98693,98761,98989,99033,99307,99800,99801,99803,100188,100353,100354,100359,100360,100361,100362,100733,100839,101502,101504,101814,102306,114288,114289));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(96759, 23, 6, 249.600006103515625, 1, 115330, 2097260, 128), -- Helya
(97099, 23, 6, 1, 1, 97598, 1024, 0), -- Swirling Pool
(98246, 23, 6, 0.899999976158142089, 1, 117106, 2097224, 128), -- Risen Warrior
(98363, 23, 6, 4, 1, 115313, 104, 128), -- Grasping Tentacle
(98693, 23, 6, 1.299999952316284179, 1, 115320, 2097224, 128), -- Shackled Servitor
(98761, 23, 6, 0.5, 1, 115333, 2097224, 128), -- Soul Fragment
(98989, 23, 6, 1, 1, 99495, 1024, 0), -- Cosmic Scythe
(99033, 23, 6, 5.5, 1, 115321, 270532680, 0), -- Helarjar Mistcaller
(99307, 23, 6, 16, 1, 115338, 270532712, 0), -- Skjal
(99800, 23, 6, 1, 1, 100308, 0, 128), -- Grasping Tentacle
(99801, 23, 6, 4, 1, 115322, 2097256, 128), -- Destructor Tentacle
(99803, 23, 6, 1, 1, 100311, 0, 128), -- Destructor Tentacle
(100188, 23, 6, 1, 1, 100697, 0, 128), -- Piercing Tentacle
(100353, 23, 6, 1, 1, 100863, 0, 128), -- Grasping Tentacle
(100354, 23, 6, 4, 1, 115328, 104, 128), -- Grasping Tentacle
(100359, 23, 6, 1, 1, 100869, 0, 128), -- Grasping Tentacle
(100360, 23, 6, 4, 1, 115334, 104, 128), -- Grasping Tentacle
(100361, 23, 6, 1, 1, 100871, 0, 128), -- Grasping Tentacle
(100362, 23, 6, 4, 1, 115319, 104, 128), -- Grasping Tentacle
(100733, 23, 6, 1, 1, 101244, 1024, 0), -- Charge
(100839, 23, 6, 1, 1, 101356, 1024, 0), -- Cosmic Scythe
(101502, 23, 6, 1, 1, 102076, 0, 0), -- Helya's Tentacle
(101504, 23, 6, 1, 1, 102078, 0, 0), -- Grasping Tentacle
(101814, 23, 6, 1, 1, 102424, 0, 0), -- Grasping Tentacle
(102306, 23, 6, 1, 1, 103079, 1024, 0), -- Swirling Pool
(114288, 23, 6, 1.10000002384185791, 0.065200001001358032, 117625, 2097224, 0), -- Skeletal Warrior
(114289, 23, 6, 0.75, 1, 117628, 270532680, 0); -- Skeletal Sorcerer

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=115314 WHERE (`Entry`=96754 AND `DifficultyID`=23); -- Harbaron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `ManaModifier`=0.000350554008036851, `CreatureDifficultyID`=115318 WHERE (`Entry`=96756 AND `DifficultyID`=23); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115311 WHERE (`Entry`=97043 AND `DifficultyID`=23); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115312 WHERE (`Entry`=97097 AND `DifficultyID`=23); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115331, `TypeFlags`=2097224 WHERE (`Entry`=97119 AND `DifficultyID`=23); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115325, `TypeFlags`=2097224 WHERE (`Entry`=97163 AND `DifficultyID`=23); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115324 WHERE (`Entry`=97182 AND `DifficultyID`=23); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115327 WHERE (`Entry`=97185 AND `DifficultyID`=23); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=115332 WHERE (`Entry`=97200 AND `DifficultyID`=23); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115336 WHERE (`Entry`=97365 AND `DifficultyID`=23); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115317 WHERE (`Entry`=98919 AND `DifficultyID`=23); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115329 WHERE (`Entry`=98973 AND `DifficultyID`=23); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115316 WHERE (`Entry`=99188 AND `DifficultyID`=23); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115335 WHERE (`Entry`=102104 AND `DifficultyID`=23); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115315 WHERE (`Entry`=102375 AND `DifficultyID`=23); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=118183 WHERE (`Entry`=114712 AND `DifficultyID`=23); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96754 AND `DifficultyID`=23); -- Harbaron
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=96756 AND `DifficultyID`=23); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97043 AND `DifficultyID`=23); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97097 AND `DifficultyID`=23); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97119 AND `DifficultyID`=23); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=54762 WHERE (`Entry`=97163 AND `DifficultyID`=23); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97182 AND `DifficultyID`=23); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97185 AND `DifficultyID`=23); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97200 AND `DifficultyID`=23); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=97208 AND `DifficultyID`=23); -- Spear
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=97365 AND `DifficultyID`=23); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (98291,102326)); -- Seacursed Rower
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98919 AND `DifficultyID`=23); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98973 AND `DifficultyID`=23); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99188 AND `DifficultyID`=23); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=101013 AND `DifficultyID`=23); -- Captured Runecarver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=102104 AND `DifficultyID`=23); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=102108 AND `DifficultyID`=23); -- Captured Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (102325,102327)); -- Seacursed Rower
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (102375,102894,114712)); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102742 AND `DifficultyID`=23); -- Fallen Shieldmaiden
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102769 AND `DifficultyID`=23); -- Decrepit Runecarver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=102830 AND `DifficultyID`=23); -- Deceased Sorcerer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=102896 AND `DifficultyID`=23); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (103115,111374));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=104906 AND `DifficultyID`=23); -- Captured Val'kyr
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=54762 WHERE (`Entry`=111221 AND `DifficultyID`=23); -- Xal'atath
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=54762 WHERE (`Entry`=111833 AND `DifficultyID`=23); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=120652 AND `DifficultyID`=23); -- Global Affix Stalker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=877, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=188142 AND `DifficultyID`=23); -- Motion Sick Peon's Soul
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=96759 AND `DifficultyID`=23); -- Helya
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (97099,102306)); -- Swirling Pool
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98246 AND `DifficultyID`=23); -- Risen Warrior
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (98363,100354,100360,100362)); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98693 AND `DifficultyID`=23); -- Shackled Servitor
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=98761 AND `DifficultyID`=23); -- Soul Fragment
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=98989 AND `DifficultyID`=23); -- Cosmic Scythe
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99033 AND `DifficultyID`=23); -- Helarjar Mistcaller
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=99307 AND `DifficultyID`=23); -- Skjal
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`DifficultyID`=23 AND `Entry` IN (99800,100353,100359,100361,101504,101814)); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=99801 AND `DifficultyID`=23); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=99803 AND `DifficultyID`=23); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1155, `VerifiedBuild`=54762 WHERE (`Entry`=100188 AND `DifficultyID`=23); -- Piercing Tentacle
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=100733 AND `DifficultyID`=23); -- Charge
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=100839 AND `DifficultyID`=23); -- Cosmic Scythe
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1155, `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=101502 AND `DifficultyID`=23); -- Helya's Tentacle
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=114288 AND `DifficultyID`=23); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=114289 AND `DifficultyID`=23); -- Skeletal Sorcerer
