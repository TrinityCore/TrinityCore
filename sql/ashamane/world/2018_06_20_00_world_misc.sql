UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=11266;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10665;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10714;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10727;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=5977) OR (`SpellMiscId`=6710) OR (`SpellMiscId`=6027) OR (`SpellMiscId`=6039);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5977, 10665, 0, 0, 0, 0, 0, 0, 20000, 26822), -- SpellId : 204255
(6710, 11266, 0, 0, 0, 0, 0, 0, 20000, 26822), -- SpellId : 203795
(6027, 10714, 0, 0, 0, 0, 0, 0, 2000, 26822), -- SpellId : 202137
(6039, 10727, 0, 0, 0, 0, 0, 0, 2000, 26822); -- SpellId : 204596

UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=93584; -- 93584 (Tideskorn Shieldmaiden)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=108927; -- 108927 (Gluttonous Raven)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=107803; -- 107803 (Wild Plains Runehorn)

UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=93584;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=107928;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=108927;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=97755;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=107803;

UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=45970;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=68916;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62719;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=22255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65457;
UPDATE `creature_model_info` SET `BoundingRadius`=1.847593, `VerifiedBuild`=26822 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65389;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=68157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4476369, `VerifiedBuild`=26822 WHERE `DisplayID`=62218;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=70286;

UPDATE `creature_equip_template` SET `ItemID2`=77408, `ItemID3`=0 WHERE (`CreatureID`=93584 AND `ID`=1); -- Tideskorn Shieldmaiden

UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=48706; -- Highlands Turkey
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags2`=33556480 WHERE `entry`=93584; -- Tideskorn Shieldmaiden
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108927; -- Gluttonous Raven
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=97755; -- Galecrested Eagle
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107803; -- Wild Plains Runehorn

UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=92072; -- Grapple Point

UPDATE `areatrigger_template` SET ScriptName = "at_dh_shattered_souls" WHERE Id = 10665;
