/*!50003 DROP PROCEDURE IF EXISTS `sp__generate_npcbot_equips`*/;

DELIMITER ;;

/*!50003 CREATE*/
/*!50003 PROCEDURE `sp__generate_npcbot_equips`()
BEGIN

DECLARE CLASS_WARRIOR INT DEFAULT 1;
DECLARE CLASS_PALADIN INT DEFAULT 2;
DECLARE CLASS_HUNTER INT DEFAULT 3;
DECLARE CLASS_ROGUE INT DEFAULT 4;
DECLARE CLASS_PRIEST INT DEFAULT 5;
DECLARE CLASS_DEATH_KNIGHT INT DEFAULT 6;
DECLARE CLASS_SHAMAN INT DEFAULT 7;
DECLARE CLASS_MAGE INT DEFAULT 8;
DECLARE CLASS_WARLOCK INT DEFAULT 9;
DECLARE CLASS_DRUID INT DEFAULT 11;
DECLARE CLASS_BLADEMASTER INT DEFAULT 12;
DECLARE CLASS_SPHYNX INT DEFAULT 13;
DECLARE CLASS_ARCHMAGE INT DEFAULT 14;
DECLARE CLASS_DREADLORD INT DEFAULT 15;
DECLARE CLASS_SPELL_BREAKER INT DEFAULT 16;
DECLARE CLASS_DARK_RANGER INT DEFAULT 17;

DECLARE RACE_HUMAN INT DEFAULT 1;
DECLARE RACE_ORC INT DEFAULT 2;
DECLARE RACE_DWARF INT DEFAULT 3;
DECLARE RACE_NELF INT DEFAULT 4;
DECLARE RACE_UNDEAD INT DEFAULT 5;
DECLARE RACE_TAUREN INT DEFAULT 6;
DECLARE RACE_GNOME INT DEFAULT 7;
DECLARE RACE_TROLL INT DEFAULT 8;
DECLARE RACE_BELF INT DEFAULT 10;
DECLARE RACE_DRAENEI INT DEFAULT 11;

DECLARE NPCBOT_ENTRY_BEGIN INT DEFAULT 70001;
DECLARE NPCBOT_ENTRY_END INT DEFAULT 71000;

DECLARE NPCBOT_ENTRY_PET_DARK_MINION INT DEFAULT 70573;
DECLARE NPCBOT_ENTRY_PET_DARK_MINION_ELITE INT DEFAULT 70574;

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

        IF myclass = CLASS_WARRIOR THEN
            IF myrace = RACE_TAUREN THEN
                SET item1 = 2361; -- hammer
            ELSEIF myrace IN(RACE_DWARF,RACE_ORC) THEN
                SET item1 = 2483; -- axe
            ELSEIF TRUE THEN
                SET item1 = 2497; -- sword
            END IF;
        ELSEIF myclass = CLASS_PALADIN THEN
            SET item1 = 2488; -- gladius
            SET item3 = 0;
            IF myrace = RACE_BELF THEN
                SET item2 = 20841; -- sunstrider shield
            ELSE
                SET item2 = 7188;  -- stormwind guard shield
            END IF;
        ELSEIF myclass = CLASS_HUNTER THEN
            SET item1 = 12282;
            SET item2 = 0;
            SET item3 = 2506;
        ELSEIF myclass = CLASS_ROGUE THEN
            SET item3 = 25873;
            IF (cur_pos % 2) = 1 THEN
                SET item1 = 2092;
                SET item2 = 3296; -- daggers
            ELSE
                SET item1 = 2131;
                SET item2 = 2484; -- swords
            END IF;
        ELSEIF myclass = CLASS_PRIEST THEN
            SET item1 = 1388; -- short staff
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_DEATH_KNIGHT THEN
            SET item1 = 38633; -- dk axe
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_SHAMAN THEN
            SET item1 = 15903; -- claw
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_MAGE THEN
            SET item1 = 2132; -- staff
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_WARLOCK THEN
            SET item1 = 3661; -- staff
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_DRUID THEN
            SET item1 = 3327; -- staff
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_BLADEMASTER THEN
            SET item1 = 24044; -- blademaster polearm
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_SPHYNX THEN
            SET item1 = 5208; -- smoldering wand
            SET item2 = 5208;
            SET item3 = 0;
        ELSEIF myclass = CLASS_ARCHMAGE THEN
            SET item1 = 25917; -- white staff
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_DREADLORD THEN
            SET item1 = 0;
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_SPELL_BREAKER THEN
            SET item1 = 0;
            SET item2 = 0;
            SET item3 = 0;
        ELSEIF myclass = CLASS_DARK_RANGER THEN
            SET item1 = 20849; -- arcane forged shortsword (1.7 dps)
            SET item2 = 0;
            SET item3 = 34529; -- vengeful gladiator's longbow
        END IF;

        INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`itemID1`,`itemID2`,`itemID3`,`VerifiedBuild`) VALUES (cur_pos,1,item1,item2,item3,-1);

    ELSEIF cur_pos = NPCBOT_ENTRY_PET_DARK_MINION OR cur_pos = NPCBOT_ENTRY_PET_DARK_MINION_ELITE THEN
        SET item1 = 3935;
        SET item2 = 15648;
        SET item3 = 0;

        INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`itemID1`,`itemID2`,`itemID3`,`VerifiedBuild`) VALUES (cur_pos,1,item1,item2,item3,-1);

    END IF;

    SET cur_pos = cur_pos + 1;

END WHILE;

END */;;

DELIMITER ;

CALL `sp__generate_npcbot_equips`();

DROP PROCEDURE IF EXISTS `sp__generate_npcbot_equips`;
