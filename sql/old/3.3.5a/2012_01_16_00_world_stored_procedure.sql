-- sp_dev_reguid procedure 
/*!50003 DROP PROCEDURE IF EXISTS `sp_dev_reguid` */;
DELIMITER ;;
/*!50003 CREATE*/
/*!50003 PROCEDURE `sp_dev_reguid`()
BEGIN

    DROP TABLE IF EXISTS `creature_temp`;
    CREATE TABLE IF NOT EXISTS `creature_temp` (
      `guid` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Global Unique Identifier',
      `id` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Creature Identifier',
      `map` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
      `spawnMask` tinyint(3) unsigned NOT NULL DEFAULT '1',
      `phaseMask` smallint(5) unsigned NOT NULL DEFAULT '1',
      `modelid` mediumint(8) unsigned NOT NULL DEFAULT '0',
      `equipment_id` mediumint(9) NOT NULL DEFAULT '0',
      `position_x` float NOT NULL DEFAULT '0',
      `position_y` float NOT NULL DEFAULT '0',
      `position_z` float NOT NULL DEFAULT '0',
      `orientation` float NOT NULL DEFAULT '0',
      `spawntimesecs` int(10) unsigned NOT NULL DEFAULT '120',
      `spawndist` float NOT NULL DEFAULT '0',
      `currentwaypoint` mediumint(8) unsigned NOT NULL DEFAULT '0',
      `curhealth` int(10) unsigned NOT NULL DEFAULT '1',
      `curmana` int(10) unsigned NOT NULL DEFAULT '0',
      `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0',
      `npcflag` int(10) unsigned NOT NULL DEFAULT '0',
      `unit_flags` int(10) unsigned NOT NULL DEFAULT '0',
      `dynamicflags` int(10) unsigned NOT NULL DEFAULT '0',
      `old_guid` int(10) unsigned NOT NULL DEFAULT '0',
      PRIMARY KEY (`guid`),
      KEY `idx_map` (`map`),
      KEY `idx_id` (`id`),
      KEY `idx_oldguid_tmp` (`old_guid`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature System' AUTO_INCREMENT=250001;

    ALTER TABLE `creature_addon` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `creature_formations` ADD COLUMN `new_guid_leader` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `creature_formations` ADD COLUMN `new_guid_member` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `game_event_creature` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `pool_creature` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `game_event_model_equip` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `game_event_npc_vendor` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `game_event_npcflag` ADD COLUMN `new_guid` INT(10) UNSIGNED NOT NULL;
    ALTER TABLE `smart_scripts` ADD COLUMN `new_guid` INT(10) NOT NULL;

    INSERT INTO `creature_temp`
        (
            `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`,
            `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`,
            `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`,
            `unit_flags`, `dynamicflags`, `old_guid`
        ) SELECT
            `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`,
            `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`,
            `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`,
            `unit_flags`, `dynamicflags`, `guid`
         FROM `creature` WHERE `guid` < 250001 ORDER BY `id` ASC;

    INSERT INTO `creature_temp`
        (
            `guid`,`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`,
            `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`,
            `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`,
            `unit_flags`, `dynamicflags`, `old_guid`
        ) SELECT
            `guid`,`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`,
            `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`,
            `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`,
            `unit_flags`, `dynamicflags`, `guid`
         FROM `creature` WHERE `guid` >= 250001 ORDER BY `id` ASC;

    UPDATE game_event_npc_vendor p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE game_event_npcflag p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE game_event_model_equip p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE creature_addon p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE creature_formations p
        INNER JOIN creature_temp pp
        ON p.leaderGUID = pp.old_guid
        SET p.new_guid_leader = pp.guid;
    UPDATE creature_formations p
        INNER JOIN creature_temp pp
        ON p.memberGUID = pp.old_guid
        SET p.new_guid_member = pp.guid;
    UPDATE game_event_creature p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE pool_creature p
        INNER JOIN creature_temp pp
        ON p.guid = pp.old_guid
        SET p.new_guid = pp.guid;
    UPDATE smart_scripts p
        INNER JOIN creature_temp pp
        ON p.entryorguid = pp.old_guid
        SET p.new_guid = -pp.guid
        WHERE
            entryorguid < 0 AND
            source_type = 0;

    DROP TABLE `creature`;
    ALTER TABLE `creature_temp` DROP COLUMN `old_guid`;
    RENAME TABLE `creature_temp` TO `creature`;

    ALTER TABLE game_event_npc_vendor DISABLE KEYS;
    UPDATE `game_event_npc_vendor` SET `guid`=`new_guid`;
    ALTER TABLE `game_event_npc_vendor` DROP COLUMN `new_guid`;
    ALTER TABLE game_event_npc_vendor ENABLE KEYS;

    ALTER TABLE game_event_npcflag DISABLE KEYS;
    UPDATE `game_event_npcflag` SET `guid`=`new_guid`;
    ALTER TABLE `game_event_npcflag` DROP COLUMN `new_guid`;
    ALTER TABLE game_event_npcflag ENABLE KEYS;

    ALTER TABLE game_event_model_equip DISABLE KEYS;
    UPDATE `game_event_model_equip` SET `guid`=`new_guid`;
    ALTER TABLE `game_event_model_equip` DROP COLUMN `new_guid`;
    ALTER TABLE game_event_model_equip ENABLE KEYS;

    ALTER TABLE `creature_addon` DROP PRIMARY KEY;
    UPDATE `creature_addon` SET `guid`=`new_guid`;
    ALTER TABLE `creature_addon` DROP COLUMN `new_guid`;
    ALTER TABLE `creature_addon` ADD PRIMARY KEY(`guid`);

    ALTER TABLE creature_formations DISABLE KEYS;
    UPDATE `creature_formations` SET leaderGUID = new_guid_leader;
    ALTER TABLE `creature_formations` DROP COLUMN `new_guid_leader`;
    UPDATE `creature_formations` SET memberGUID = new_guid_member;
    ALTER TABLE `creature_formations` DROP COLUMN `new_guid_member`;
    ALTER TABLE creature_formations ENABLE KEYS;

    ALTER TABLE `game_event_creature` DROP PRIMARY KEY;
    UPDATE `game_event_creature` SET guid = new_guid;
    ALTER TABLE `game_event_creature` DROP COLUMN `new_guid`;
    ALTER TABLE `game_event_creature` ADD PRIMARY KEY(`guid`, `eventEntry`);

    ALTER TABLE `pool_creature` DROP PRIMARY KEY;
    UPDATE `pool_creature` SET guid = new_guid;
    ALTER TABLE `pool_creature` DROP COLUMN `new_guid`;
    ALTER TABLE `pool_creature` ADD PRIMARY KEY(`guid`);

    ALTER TABLE `smart_scripts` DROP PRIMARY KEY;
    UPDATE `smart_scripts` SET `entryorguid` = `new_guid`
        WHERE entryorguid < 0 AND new_guid < 0 AND source_type = 0;
    ALTER TABLE `smart_scripts` DROP COLUMN `new_guid`;
    ALTER TABLE `smart_scripts` ADD PRIMARY KEY (`entryorguid`,`source_type`,`id`,`link`);

    END */;;
	