/*!50003 DROP PROCEDURE IF EXISTS `sp__generate_necromancer_equips`*/;

DELIMITER ;;

/*!50003 CREATE*/
/*!50003 PROCEDURE `sp__generate_necromancer_equips`()
BEGIN

DECLARE CLASS_NECROMANCER INT DEFAULT 18;

DECLARE NPCBOT_ENTRY_BEGIN INT DEFAULT 70575;
DECLARE NPCBOT_ENTRY_END INT DEFAULT 71000;

DECLARE NPCBOT_ENTRY_PET_NECROSKELETON INT DEFAULT 70580;

DECLARE cur_pos INT DEFAULT 0;
DECLARE myclass INT;
DECLARE myrace INT;
DECLARE item1 INT DEFAULT 0;
DECLARE item2 INT DEFAULT 0;
DECLARE item3 INT DEFAULT 0;

DELETE FROM `creature_equip_template` WHERE `CreatureID` BETWEEN NPCBOT_ENTRY_BEGIN AND NPCBOT_ENTRY_END;

SET cur_pos = NPCBOT_ENTRY_BEGIN;
WHILE cur_pos < NPCBOT_ENTRY_END DO
    SET myclass = (SELECT `class` FROM `creature_template_npcbot_extras` WHERE `entry` = cur_pos);
    SET myrace = (SELECT `race` FROM `creature_template_npcbot_extras` WHERE `entry` = cur_pos);

    IF myclass != 0 AND myrace != 0 THEN

        IF myclass = CLASS_NECROMANCER THEN
            SET item1 = 13937; -- staff
        END IF;

        INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`itemID1`,`itemID2`,`itemID3`,`VerifiedBuild`) VALUES (cur_pos,1,item1,item2,item3,-1);

    ELSEIF cur_pos = NPCBOT_ENTRY_PET_NECROSKELETON THEN
        SET item1 = 3935;
        SET item2 = 15648;
        SET item3 = 0;

        INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`itemID1`,`itemID2`,`itemID3`,`VerifiedBuild`) VALUES (cur_pos,1,item1,item2,item3,-1);

    END IF;

    SET cur_pos = cur_pos + 1;

END WHILE;

END */;;

DELIMITER ;

CALL `sp__generate_necromancer_equips`();

DROP PROCEDURE IF EXISTS `sp__generate_necromancer_equips`;
