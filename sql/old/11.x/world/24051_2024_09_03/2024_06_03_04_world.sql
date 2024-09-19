-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27949; -- Alliance Commander
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27837; -- Nexus 70 - Buying Time Bunny
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=27101; -- Crystal Spike Initial Trigger
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `unit_flags3`=524289 WHERE `entry`=27099; -- Crystal Spike
UPDATE `creature_template` SET `unit_flags2`=2080, `unit_flags3`=524289 WHERE `entry`=27079; -- Crystal Spike Trigger
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26805; -- Alliance Cleric
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26802; -- Alliance Ranger
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26800; -- Alliance Berserker
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26794; -- Ormorok the Tree-Shaper
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=26792; -- Crystalline Protector
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=26782; -- Crystalline Keeper
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26763; -- Anomalus
UPDATE `creature_template` SET `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=26761; -- Crazed Mana-Wyrm
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=26737; -- Crazed Mana-Surge
UPDATE `creature_template` SET `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=26736; -- Azure Skyrazor
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26731; -- Grand Magus Telestra
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags3`=67108864 WHERE `entry`=26730; -- Mage Slayer
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26723; -- Keristrasza
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=26722; -- Azure Magus
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26716; -- Azure Warder
UPDATE `creature_template` SET `unit_flags2`=0, `unit_flags3`=524288 WHERE `entry`=32665; -- Crystalline Tangler
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26796; -- Commander Stoutbeard
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27947; -- Horde Commander
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26803; -- Horde Cleric
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26801; -- Horde Ranger
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26799; -- Horde Berserker
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=26798; -- Commander Kolurg

UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=26761; -- 26761 (Crazed Mana-Wyrm) - Permanent Feign Death
UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=26736; -- 26736 (Azure Skyrazor)

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
WHERE ctd.`Entry` IN (26798,27947,26803,26801,26799,26796,55537,55536,55535,27837,54638,55531,26793,28231,27949,27101,27099,27079,27048,26918,26805,26802,26800,26794,26792,26782,26763,26761,26746,26737,26736,26735,26734,26731,26730,26729,26728,26727,26723,26722,26716)
AND ctd.`DifficultyID`=0 AND ctd2.`DifficultyID`=1 AND ctd2.`Entry` IS NOT NULL;

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (26798,27947,26803,26801,26799,26796,55537,55536,55535,27837,54638,55531,26793,28231,27949,27101,27099,27079,27048,26918,26805,26802,26800,26794,26792,26782,26763,26761,26746,26737,26736,26735,26734,26731,26730,26729,26728,26727,26723,26722,26716));

DELETE FROM `creature_template_difficulty` WHERE `DifficultyID`=2 AND `Entry`=22515;
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(22515, 2, 0, 0, 2672, 536870912, 0, 0, 0, 0, 0, 0, 0, 54904); -- 22515 (World Trigger) - Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3, `ContentTuningID`=2671, `VerifiedBuild`=54904 WHERE (`Entry`=22515 AND `DifficultyID`=0); -- 22515 (World Trigger) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `VerifiedBuild`=54904 WHERE (`Entry`=55537 AND `DifficultyID`=0); -- 55537 (Image of Warmage Kaitlyn) - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `VerifiedBuild`=54904 WHERE (`Entry`=55536 AND `DifficultyID`=0); -- 55536 (Image of Warmage Kaitlyn) - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `VerifiedBuild`=54904 WHERE (`Entry`=55535 AND `DifficultyID`=0); -- 55535 (Image of Warmage Kaitlyn) - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=55531 AND `DifficultyID`=0); -- 55531 (Warmage Kaitlyn) - Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54904 WHERE (`Entry`=54638 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26793 AND `DifficultyID`=0); -- 26793 (Crystalline Frayer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28231 AND `DifficultyID`=0); -- 28231 (Crystalline Tender) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27949 AND `DifficultyID`=0); -- 27949 (Alliance Commander) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=47, `VerifiedBuild`=54904 WHERE (`Entry`=27837 AND `DifficultyID`=0); -- 27837 (Nexus 70 - Buying Time Bunny) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=536871168, `VerifiedBuild`=54904 WHERE (`Entry`=27101 AND `DifficultyID`=0); -- 27101 (Crystal Spike Initial Trigger) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=536871168, `VerifiedBuild`=54904 WHERE (`Entry`=27099 AND `DifficultyID`=0); -- 27099 (Crystal Spike) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=536871168, `VerifiedBuild`=54904 WHERE (`Entry`=27079 AND `DifficultyID`=0); -- 27079 (Crystal Spike Trigger) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=245, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=27048 AND `DifficultyID`=0); -- 27048 (Breath Caster) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `StaticFlags1`=805830912, `VerifiedBuild`=54904 WHERE (`Entry`=26918 AND `DifficultyID`=0); -- 26918 (Chaotic Rift) - Sessile, Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26805 AND `DifficultyID`=0); -- 26805 (Alliance Cleric) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26802 AND `DifficultyID`=0); -- 26802 (Alliance Ranger) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26800 AND `DifficultyID`=0); -- 26800 (Alliance Berserker) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26794 AND `DifficultyID`=0); -- 26794 (Ormorok the Tree-Shaper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26792 AND `DifficultyID`=0); -- 26792 (Crystalline Protector) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26782 AND `DifficultyID`=0); -- 26782 (Crystalline Keeper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26763 AND `DifficultyID`=0); -- 26763 (Anomalus) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=26761 AND `DifficultyID`=0); -- 26761 (Crazed Mana-Wyrm) - Sessile, Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26746 AND `DifficultyID`=0); -- 26746 (Crazed Mana-Wraith) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26737 AND `DifficultyID`=0); -- 26737 (Crazed Mana-Surge) - Sessile, Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=26736 AND `DifficultyID`=0); -- 26736 (Azure Skyrazor) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26735 AND `DifficultyID`=0); -- 26735 (Azure Scale-Binder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26734 AND `DifficultyID`=0); -- 26734 (Azure Enforcer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26731 AND `DifficultyID`=0); -- 26731 (Grand Magus Telestra) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26730 AND `DifficultyID`=0); -- 26730 (Mage Slayer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26729 AND `DifficultyID`=0); -- 26729 (Steward) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26728 AND `DifficultyID`=0); -- 26728 (Mage Hunter Initiate) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26727 AND `DifficultyID`=0); -- 26727 (Mage Hunter Ascendant) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26723 AND `DifficultyID`=0); -- 26723 (Keristrasza) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26722 AND `DifficultyID`=0); -- 26722 (Azure Magus) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26716 AND `DifficultyID`=0); -- 26716 (Azure Warder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26681 WHERE (`Entry`=26805 AND `DifficultyID`=2); -- Alliance Cleric
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=29715 WHERE (`Entry`=28231 AND `DifficultyID`=2); -- Crystalline Tender
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26476 WHERE (`Entry`=26734 AND `DifficultyID`=2); -- Azure Enforcer
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26456 WHERE (`Entry`=26729 AND `DifficultyID`=2); -- Steward
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26599 WHERE (`Entry`=26782 AND `DifficultyID`=2); -- Crystalline Keeper
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26481 WHERE (`Entry`=26735 AND `DifficultyID`=2); -- Azure Scale-Binder
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.192013502120971679, `CreatureDifficultyID`=26486 WHERE (`Entry`=26736 AND `DifficultyID`=2); -- Azure Skyrazor
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26445 WHERE (`Entry`=26727 AND `DifficultyID`=2); -- Mage Hunter Ascendant
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.78125, `CreatureDifficultyID`=26514 WHERE (`Entry`=26746 AND `DifficultyID`=2); -- Crazed Mana-Wraith
UPDATE `creature_template_difficulty` SET `HealthModifier`=40, `CreatureDifficultyID`=26631, `TypeFlags2`=128 WHERE (`Entry`=26794 AND `DifficultyID`=2); -- Ormorok the Tree-Shaper
UPDATE `creature_template_difficulty` SET `HealthModifier`=18.75, `CreatureDifficultyID`=26620 WHERE (`Entry`=26792 AND `DifficultyID`=2); -- Crystalline Protector
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26451 WHERE (`Entry`=26728 AND `DifficultyID`=2); -- Mage Hunter Initiate
UPDATE `creature_template_difficulty` SET `HealthModifier`=46.875, `CreatureDifficultyID`=26639, `TypeFlags2`=128 WHERE (`Entry`=26796 AND `DifficultyID`=2); -- Commander Stoutbeard
UPDATE `creature_template_difficulty` SET `HealthModifier`=18.75, `CreatureDifficultyID`=26428 WHERE (`Entry`=26722 AND `DifficultyID`=2); -- Azure Magus
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.076806001365184783, `CreatureDifficultyID`=26550, `TypeFlags`=1025 WHERE (`Entry`=26761 AND `DifficultyID`=2); -- Crazed Mana-Wyrm
UPDATE `creature_template_difficulty` SET `HealthModifier`=22.5, `CreatureDifficultyID`=26466, `TypeFlags2`=128 WHERE (`Entry`=26731 AND `DifficultyID`=2); -- Grand Magus Telestra
UPDATE `creature_template_difficulty` SET `HealthModifier`=18.75, `CreatureDifficultyID`=26415 WHERE (`Entry`=26716 AND `DifficultyID`=2); -- Azure Warder
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26492 WHERE (`Entry`=26737 AND `DifficultyID`=2); -- Crazed Mana-Surge
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.75, `CreatureDifficultyID`=27264 WHERE (`Entry`=27099 AND `DifficultyID`=2); -- Crystal Spike
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.84375, `CreatureDifficultyID`=26626 WHERE (`Entry`=26793 AND `DifficultyID`=2); -- Crystalline Frayer
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26668 WHERE (`Entry`=26802 AND `DifficultyID`=2); -- Alliance Ranger
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26461 WHERE (`Entry`=26730 AND `DifficultyID`=2); -- Mage Slayer
UPDATE `creature_template_difficulty` SET `HealthModifier`=4.21875, `CreatureDifficultyID`=26921 WHERE (`Entry`=26918 AND `DifficultyID`=2); -- Chaotic Rift
UPDATE `creature_template_difficulty` SET `HealthModifier`=40, `CreatureDifficultyID`=26557, `TypeFlags2`=128 WHERE (`Entry`=26763 AND `DifficultyID`=2); -- Anomalus
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.375, `CreatureDifficultyID`=26657 WHERE (`Entry`=26800 AND `DifficultyID`=2); -- Alliance Berserker
UPDATE `creature_template_difficulty` SET `HealthModifier`=47.5, `CreatureDifficultyID`=26433, `TypeFlags2`=128 WHERE (`Entry`=26723 AND `DifficultyID`=2); -- Keristrasza
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26793 AND `DifficultyID`=2); -- 26793 (Crystalline Frayer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28231 AND `DifficultyID`=2); -- 28231 (Crystalline Tender) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1094, `StaticFlags1`=536871168, `VerifiedBuild`=54904 WHERE (`Entry`=27099 AND `DifficultyID`=2); -- 27099 (Crystal Spike) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1094, `StaticFlags1`=805830912, `VerifiedBuild`=54904 WHERE (`Entry`=26918 AND `DifficultyID`=2); -- 26918 (Chaotic Rift) - Sessile, Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26805 AND `DifficultyID`=2); -- 26805 (Alliance Cleric) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26802 AND `DifficultyID`=2); -- 26802 (Alliance Ranger) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26800 AND `DifficultyID`=2); -- 26800 (Alliance Berserker) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26796 AND `DifficultyID`=2); -- 26796 (Commander Stoutbeard) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26794 AND `DifficultyID`=2); -- 26794 (Ormorok the Tree-Shaper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26792 AND `DifficultyID`=2); -- 26792 (Crystalline Protector) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26782 AND `DifficultyID`=2); -- 26782 (Crystalline Keeper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26763 AND `DifficultyID`=2); -- 26763 (Anomalus) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=26761 AND `DifficultyID`=2); -- 26761 (Crazed Mana-Wyrm) - Sessile, Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26746 AND `DifficultyID`=2); -- 26746 (Crazed Mana-Wraith) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26737 AND `DifficultyID`=2); -- 26737 (Crazed Mana-Surge) - Sessile, Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=26736 AND `DifficultyID`=2); -- 26736 (Azure Skyrazor) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26735 AND `DifficultyID`=2); -- 26735 (Azure Scale-Binder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26734 AND `DifficultyID`=2); -- 26734 (Azure Enforcer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26731 AND `DifficultyID`=2); -- 26731 (Grand Magus Telestra) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26730 AND `DifficultyID`=2); -- 26730 (Mage Slayer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26729 AND `DifficultyID`=2); -- 26729 (Steward) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26728 AND `DifficultyID`=2); -- 26728 (Mage Hunter Initiate) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26727 AND `DifficultyID`=2); -- 26727 (Mage Hunter Ascendant) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26723 AND `DifficultyID`=2); -- 26723 (Keristrasza) - Sessile, Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26722 AND `DifficultyID`=2); -- 26722 (Azure Magus) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1094, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26716 AND `DifficultyID`=2); -- 26716 (Azure Warder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=805306624, `VerifiedBuild`=54904 WHERE (`Entry`=32665 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26796 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27947 AND `DifficultyID`=0); -- 27947 (Horde Commander) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26803 AND `DifficultyID`=0); -- 26803 (Horde Cleric) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26801 AND `DifficultyID`=0); -- 26801 (Horde Ranger) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26799 AND `DifficultyID`=0); -- 26799 (Horde Berserker) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26803 AND `DifficultyID`=2); -- 26803 (Horde Cleric) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26801 AND `DifficultyID`=2); -- 26801 (Horde Ranger) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26799 AND `DifficultyID`=2); -- 26799 (Horde Berserker) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26798 AND `DifficultyID`=2); -- 26798 (Commander Kolurg) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=245, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=26798 AND `DifficultyID`=0);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=26792 AND `DifficultyID`=1);

DELETE FROM `creature_quest_currency` WHERE (`CurrencyId`=1166 AND `CreatureId` IN (26798,26796,26794,26731,26763,26723));
INSERT INTO `creature_quest_currency` (`CreatureId`, `CurrencyId`, `VerifiedBuild`) VALUES
(26798, 1166, 54904), -- Commander Kolurg - 1166
(26796, 1166, 54904), -- Commander Stoutbeard - 1166
(26794, 1166, 54904), -- Ormorok the Tree-Shaper - 1166
(26731, 1166, 54904), -- Grand Magus Telestra - 1166
(26763, 1166, 54904), -- Anomalus - 1166
(26723, 1166, 54904); -- Keristrasza - 1166

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=54904 WHERE `DisplayID` IN (39155, 25570, 27609, 24366, 19595, 23767, 25206, 24356, 24355, 24353, 26298, 27472, 27469, 26259, 42981, 27810, 14253, 14886, 24066, 24906, 24323, 24320, 24322, 24321, 24318, 24313, 24312, 24314, 24307, 25249, 25251);
UPDATE `creature_template_model` SET `VerifiedBuild`=54904 WHERE (`Idx`=0 AND `CreatureID` IN (28231,27837,26734,26792,22515,27048,26763,54638,26728,55536,26737,26716,26730,55535,29911,27101,27099,26736,26800,27079,26793,26802,26723,55537,26918,26805,26761,26729,55531,26735,27949,26794,26731,26722,26782,26746,26727)) OR (`Idx`=1 AND `CreatureID` IN (27837,22515,27048,54638,26728,26918,26729,26727)) OR (`Idx`=3 AND `CreatureID` IN (26728,26729,26727)) OR (`Idx`=2 AND `CreatureID` IN (26728,26729,26727));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=54904 WHERE `entry` IN (188537, 192788, 191016, 188527, 190174, 188526, 181030, 188528);

UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=192788; -- Berinand's Research

UPDATE `gameobject_questitem` SET `VerifiedBuild`=54904 WHERE (`GameObjectEntry`=192788 AND `Idx`=0);
