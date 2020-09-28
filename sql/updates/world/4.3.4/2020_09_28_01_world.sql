UPDATE `creature_loot_template` SET `MinCount`= 2, `MaxCount`= 2 WHERE `Entry`= 47775 AND `Reference`= 477750;
DELETE FROM `reference_loot_template` WHERE `Entry`= 511021;
DELETE FROM `creature_loot_template` WHERE `Reference`= 511021;
