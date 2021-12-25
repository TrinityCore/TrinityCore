-- Mana Wyrm (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `dynamicflags`=0, `VerifiedBuild`=40120 WHERE `entry`=15274; 

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15274 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=16217;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 54931 AND 54983;

-- Springpaw Cub (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15366;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15366 AND `Idx`=0;

UPDATE `creature_model_info` SET `BoundingRadius`=0.560572, `VerifiedBuild`=40120 WHERE `DisplayID`=15507;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 55135 AND 55164;

-- Springpaw Lynx (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15372;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15372 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15506;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 55177 AND 55197;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid` IN (145366,145367,145368);

-- Feral Tender (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15294;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15294 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15485;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 55000 AND 55052;

-- Tender (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15271;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15271 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15484;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 54861 AND 54909;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 375647 AND 375651;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=85647;

-- Arcane Wraith (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `dynamicflags`=0, `VerifiedBuild`=40120 WHERE `entry`=15273; 

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15273 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15438;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 54910 AND 54930;

-- Tainted Arcane Wraith (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20,  `VerifiedBuild`=40120 WHERE `entry`=15298;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15298 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15406;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=622, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 55056 AND 55060;

-- Felendren the Banished (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15367;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15367 AND `Idx`=0;

UPDATE `creature_questitem` SET `VerifiedBuild`=40120 WHERE `CreatureEntry`=15367 AND `Idx`=0;

UPDATE `creature_text` SET `Sound`=8506 WHERE `CreatureID`=15367 AND `GroupID`=0 AND `ID`=0;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `curhealth`=1244, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid`=55165;
