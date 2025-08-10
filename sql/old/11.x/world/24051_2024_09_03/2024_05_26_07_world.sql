-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry` IN (30962, 30662); -- Azure Spellbreaker
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry` IN (30661, 30961); -- Azure Invader
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags3`=524288 WHERE `entry` IN (30892, 30660); -- Portal Guardian
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=30666; -- Azure Captain
UPDATE `creature_template` SET `BaseAttackTime`=1500, `unit_flags3`=67633152 WHERE `entry` IN (30664, 30963); -- Azure Mage Slayer
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry` IN (30663, 30918); -- Azure Binder
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=30665; -- Veteran Mage Hunter
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=30695; -- Portal Keeper
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=32191; -- Azure Stalker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378, `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=30668; -- Azure Raider
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=30667; -- Azure Sorcerer
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=32174; -- Teleportation Portal (Elite)
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags3`=524288 WHERE `entry`=30893; -- Portal Keeper
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=30679; -- Teleportation Portal
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=30837; -- Defense System
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=31010; -- Azure Mage Slayer
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=30883; -- Dalaran Prison Event Controller
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=29316; -- Moragg
UPDATE `creature_template` SET `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=29314; -- Zuramat the Obliterator
UPDATE `creature_template` SET `unit_flags`=832 WHERE `entry`=29315; -- Erekem
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=29312; -- Lavanthor
UPDATE `creature_template` SET `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=29313; -- Ichoron
UPDATE `creature_template` SET `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=29266; -- Xevozz
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=31011; -- Teleportation Portal (Intro)
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=16777217 WHERE `entry`=83732; -- First Escaped Prisoner
UPDATE `creature_template` SET `unit_flags`=832 WHERE `entry`=29395; -- Erekem Guard
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=31008; -- Azure Invader
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=16777217 WHERE `entry`=83733; -- Second Escaped Prisoner
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags3`=524288 WHERE `entry`=29321; -- Ichor Globule
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=29271; -- Ethereal Sphere
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry` IN (29364, 29365); -- Void Sentry

DELETE FROM `creature_template_addon` WHERE `entry` IN (83732,83733);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(83732, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 83732 (First Escaped Prisoner)
(83733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 83733 (Second Escaped Prisoner)

UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=32174; -- 32174 (Teleportation Portal (Elite))
UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=30679; -- 30679 (Teleportation Portal)
UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=31011; -- 31011 (Teleportation Portal (Intro))

-- Difficulties
UPDATE `creature_template_difficulty` ctd
LEFT JOIN `creature_template_difficulty` ctd2 ON ctd.`Entry`=ctd2.`Entry`
SET
    ctd.`DamageModifier`=ctd2.`DamageModifier`,
    ctd.`LootID`=ctd2.`LootID`,
    ctd.`PickPocketLootID`=ctd2.`PickPocketLootID`,
    ctd.`SkinLootID`=ctd2.`SkinLootID`,
    ctd.`GoldMin`=ctd2.`GoldMin`,
    ctd.`GoldMax`=ctd2.`GoldMax`
WHERE ctd.`Entry` IN (30883,30658,30896,30857,31134,30962,30662,30661,30892,30666,30664,30663,30961,30665,30918,30963,30660,31079,30695,32191,30668,30667,32174,30893,30679,30837,31010,29276,29316,31118,29314,32204,29315,29312,29313,29266,29326,31007,31011,83732,29395,29425,31008,30659,83733,31009)
AND ctd.`DifficultyID`=0 AND ctd2.`DifficultyID`=1 AND ctd2.`Entry` IS NOT NULL;

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID` IN (1,23) AND `Entry` IN (30883,30658,30896,30857,31134,30962,30662,30661,30892,30666,30664,30663,30961,30665,30918,30963,30660,31079,30695,32191,30668,30667,32174,30893,30679,30837,31010,29276,29316,31118,29314,32204,29315,29312,29313,29266,29326,31007,31011,83732,29395,29425,31008,30659,83733,31009));

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=53488 AND `DifficultyID`=0); -- Summon Enabler Stalker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=31134 AND `DifficultyID`=0); -- 31134 (Cyanigosa) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30962 AND `DifficultyID`=0); -- 30962 (Azure Spellbreaker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30662 AND `DifficultyID`=0); -- 30662 (Azure Spellbreaker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30661 AND `DifficultyID`=0); -- 30661 (Azure Invader) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30892 AND `DifficultyID`=0); -- 30892 (Portal Guardian) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30666 AND `DifficultyID`=0); -- 30666 (Azure Captain) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30664 AND `DifficultyID`=0); -- 30664 (Azure Mage Slayer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30663 AND `DifficultyID`=0); -- 30663 (Azure Binder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30961 AND `DifficultyID`=0); -- 30961 (Azure Invader) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30665 AND `DifficultyID`=0); -- 30665 (Veteran Mage Hunter) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30918 AND `DifficultyID`=0); -- 30918 (Azure Binder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30963 AND `DifficultyID`=0); -- 30963 (Azure Mage Slayer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30660 AND `DifficultyID`=0); -- 30660 (Portal Guardian) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=31079 AND `DifficultyID`=0); -- 31079 (Azure Saboteur) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30695 AND `DifficultyID`=0); -- 30695 (Portal Keeper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=32191 AND `DifficultyID`=0); -- 32191 (Azure Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30668 AND `DifficultyID`=0); -- 30668 (Azure Raider) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30667 AND `DifficultyID`=0); -- 30667 (Azure Sorcerer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=32174 AND `DifficultyID`=0); -- 32174 (Teleportation Portal (Elite)) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30893 AND `DifficultyID`=0); -- 30893 (Portal Keeper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=30679 AND `DifficultyID`=0); -- 30679 (Teleportation Portal) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=30837 AND `DifficultyID`=0); -- 30837 (Defense System) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=31010 AND `DifficultyID`=0); -- 31010 (Azure Mage Slayer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=29276 AND `DifficultyID`=0); -- 29276 (Ethereal Summon Target) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54847 WHERE (`DifficultyID`=0 AND `Entry` IN (30883,4075,53488,14881,30896,2110,30857));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29316 AND `DifficultyID`=0); -- 29316 (Moragg) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=31118 AND `DifficultyID`=0); -- 31118 (Azure Raider) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29314 AND `DifficultyID`=0); -- 29314 (Zuramat the Obliterator) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=32204 AND `DifficultyID`=0); -- 32204 (Lieutenant Sinclari) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29315 AND `DifficultyID`=0); -- 29315 (Erekem) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29312 AND `DifficultyID`=0); -- 29312 (Lavanthor) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29313 AND `DifficultyID`=0); -- 29313 (Ichoron) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29266 AND `DifficultyID`=0); -- 29266 (Xevozz) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=29326 AND `DifficultyID`=0); -- 29326 (Ichoron Summon Target) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=0, `VerifiedBuild`=54847 WHERE (`Entry`=31007 AND `DifficultyID`=0); -- 31007 (Azure Binder)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=31011 AND `DifficultyID`=0); -- 31011 (Teleportation Portal (Intro)) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30658 AND `DifficultyID`=0); -- 30658 (Lieutenant Sinclari) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=83732 AND `DifficultyID`=0); -- 83732 (First Escaped Prisoner) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29395 AND `DifficultyID`=0); -- 29395 (Erekem Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=29425 AND `DifficultyID`=0); -- 29425 (Erekem Controller) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=31008 AND `DifficultyID`=0); -- 31008 (Azure Invader)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=30659 AND `DifficultyID`=0); -- 30659 (Violet Hold Guard)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=83733 AND `DifficultyID`=0); -- 83733 (Second Escaped Prisoner) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=0, `VerifiedBuild`=54847 WHERE (`Entry`=31009 AND `DifficultyID`=0); -- 31009 (Azure Spellbreaker)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29321 AND `DifficultyID`=0); -- 29321 (Ichor Globule) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29271 AND `DifficultyID`=0); -- 29271 (Ethereal Sphere)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `VerifiedBuild`=54847 WHERE (`Entry`=29364 AND `DifficultyID`=0); -- 29364 (Void Sentry)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=247, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=29365 AND `DifficultyID`=0); -- 29365 (Void Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34939 WHERE (`Entry`=30667 AND `DifficultyID`=2); -- Azure Sorcerer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32155 WHERE (`Entry`=29266 AND `DifficultyID`=2); -- Xevozz
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34922 WHERE (`Entry`=30664 AND `DifficultyID`=2); -- Azure Mage Slayer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32297 WHERE (`Entry`=29316 AND `DifficultyID`=2); -- Moragg
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35279 WHERE (`Entry`=30893 AND `DifficultyID`=2); -- Portal Keeper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35624 WHERE (`Entry`=31118 AND `DifficultyID`=2); -- Azure Raider
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32284 WHERE (`Entry`=29314 AND `DifficultyID`=2); -- Zuramat the Obliterator
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34901 WHERE (`Entry`=30660 AND `DifficultyID`=2); -- Portal Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35400 WHERE (`Entry`=31007 AND `DifficultyID`=2); -- Azure Binder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35299 WHERE (`Entry`=30918 AND `DifficultyID`=2); -- Azure Binder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34916 WHERE (`Entry`=30663 AND `DifficultyID`=2); -- Azure Binder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35660 WHERE (`Entry`=31134 AND `DifficultyID`=2); -- Cyanigosa
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34894 WHERE (`Entry`=30659 AND `DifficultyID`=2); -- Violet Hold Guard
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34927 WHERE (`Entry`=30665 AND `DifficultyID`=2); -- Veteran Mage Hunter
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35405 WHERE (`Entry`=31008 AND `DifficultyID`=2); -- Azure Invader
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35016 WHERE (`Entry`=30695 AND `DifficultyID`=2); -- Portal Keeper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35547 WHERE (`Entry`=31079 AND `DifficultyID`=2); -- Azure Saboteur
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35418 WHERE (`Entry`=31010 AND `DifficultyID`=2); -- Azure Mage Slayer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35410 WHERE (`Entry`=31009 AND `DifficultyID`=2); -- Azure Spellbreaker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34944 WHERE (`Entry`=30668 AND `DifficultyID`=2); -- Azure Raider
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35350 WHERE (`Entry`=30961 AND `DifficultyID`=2); -- Azure Invader
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34934 WHERE (`Entry`=30666 AND `DifficultyID`=2); -- Azure Captain
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=36738 WHERE (`Entry`=32204 AND `DifficultyID`=2); -- Lieutenant Sinclari
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34907 WHERE (`Entry`=30661 AND `DifficultyID`=2); -- Azure Invader
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=36710 WHERE (`Entry`=32191 AND `DifficultyID`=2); -- Azure Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32280 WHERE (`Entry`=29313 AND `DifficultyID`=2); -- Ichoron
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32446 WHERE (`Entry`=29395 AND `DifficultyID`=2); -- Erekem Guard
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32273 WHERE (`Entry`=29312 AND `DifficultyID`=2); -- Lavanthor
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34911 WHERE (`Entry`=30662 AND `DifficultyID`=2); -- Azure Spellbreaker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35360 WHERE (`Entry`=30963 AND `DifficultyID`=2); -- Azure Mage Slayer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32291 WHERE (`Entry`=29315 AND `DifficultyID`=2); -- Erekem
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35273 WHERE (`Entry`=30892 AND `DifficultyID`=2); -- Portal Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32386 WHERE (`Entry`=29364 AND `DifficultyID`=2); -- Void Sentry
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35273 WHERE (`Entry`=30892 AND `DifficultyID`=2); -- Portal Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32391 WHERE (`Entry`=29365 AND `DifficultyID`=2); -- Void Sentry
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32310 WHERE (`Entry`=29321 AND `DifficultyID`=2); -- Ichor Globule
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35355 WHERE (`Entry`=30962 AND `DifficultyID`=2); -- Azure Spellbreaker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=32164 WHERE (`Entry`=29271 AND `DifficultyID`=2); -- Ethereal Sphere
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54847 WHERE (`DifficultyID`=2 AND `Entry` IN (31134,30893,30695,31079,30666,32191,30668,30667,30660,31010,31118,29314,29313,29316,32204,29266,53488,29312,31008));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30662 AND `DifficultyID`=2); -- 30662 (Azure Spellbreaker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30661 AND `DifficultyID`=2); -- 30661 (Azure Invader) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30664 AND `DifficultyID`=2); -- 30664 (Azure Mage Slayer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30963 AND `DifficultyID`=2); -- 30963 (Azure Mage Slayer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30918 AND `DifficultyID`=2); -- 30918 (Azure Binder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30663 AND `DifficultyID`=2); -- 30663 (Azure Binder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30665 AND `DifficultyID`=2); -- 30665 (Veteran Mage Hunter) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30961 AND `DifficultyID`=2); -- 30961 (Azure Invader) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30892 AND `DifficultyID`=2); -- 30892 (Portal Guardian)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=29364 AND `DifficultyID`=2); -- 29364 (Void Sentry) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=29365 AND `DifficultyID`=2); -- 29365 (Void Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29321 AND `DifficultyID`=2); -- 29321 (Ichor Globule) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=30962 AND `DifficultyID`=2); -- 30962 (Azure Spellbreaker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1092, `VerifiedBuild`=54847 WHERE (`Entry`=29271 AND `DifficultyID`=2); -- 29271 (Ethereal Sphere) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29395 AND `DifficultyID`=2); -- 29395 (Erekem Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=29315 AND `DifficultyID`=2); -- 29315 (Erekem) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54847 WHERE (`Entry`=31007 AND `DifficultyID`=2); -- 31007 (Azure Binder) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54847 WHERE (`Entry`=31009 AND `DifficultyID`=2); -- 31009 (Azure Spellbreaker) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54847 WHERE (`Entry`=30659 AND `DifficultyID`=2); -- 30659 (Violet Hold Guard) - Sessile

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=31134 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(31134, 2, 0, 43823, 54847); -- Cyanigosa

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID` IN (27340, 14356, 27794, 27792, 27793, 27474, 27220, 27219, 27473, 16946, 24910, 1418, 27217, 27855, 27824, 27488, 27216, 10193, 27487, 27486, 16925, 44816, 25247, 20923, 27393, 27214, 18628, 25226, 27215, 1141, 25250);
UPDATE `creature_model_info` SET `BoundingRadius`=5.418732643127441406, `VerifiedBuild`=54847 WHERE `DisplayID`=20590;
UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID` IN (4606, 2176);
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=54847 WHERE `DisplayID`=28073;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=0.75, `VerifiedBuild`=54847 WHERE `DisplayID`=26208;
UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID`=23767;
UPDATE `creature_template_model` SET `VerifiedBuild`=54847 WHERE (`Idx`=0 AND `CreatureID` IN (30666,40165,31134,31010,32158,18379,31118,31079,32174,54423,29266,59072,356,29315,29425,30661,34337,83733,30837,54879,304,31007,30668,14881,30660,71486,30857,30892,30663,70356,31011,29313,30679,69066,32204,54741,2110,30962,30664,60941,31008,30918,53488,30662,30659,30665,64993,40625,29314,32191,68288,25064,30658,31009,29316,47654,4075,29276,30893,31698,40725,305,83732,29312,30667,35362,30896,56921,14505,29326,30963,28363,29395,30961,30695,65011,30883)) OR (`Idx`=1 AND `CreatureID` IN (40165,29425,83733,30837,14881,30857,53488,30659,30665,4075,29276,40725,83732,30896,29326)) OR (`Idx`=2 AND `CreatureID` IN (30659,30665,4075)) OR (`Idx`=3 AND `CreatureID`=30665);
UPDATE `creature_template_model` SET `VerifiedBuild`=54847 WHERE (`Idx`=0 AND `CreatureID` IN (29321,29271));
UPDATE `creature_template_model` SET `VerifiedBuild`=54847 WHERE (`Idx`=0 AND `CreatureID` IN (29364,308,29365,18362));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=54847 WHERE `entry` IN (191606, 191562, 191558, 214500, 191556, 191723, 191559, 191566, 191722, 191560, 191564, 193611, 191565, 191563, 193615, 191557);

UPDATE `gameobject_template_addon` SET `WorldEffectID`=3661 WHERE `entry`=193611; -- Activation Crystal
