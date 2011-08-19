CREATE TABLE `temp_auras` (
  `spell` MEDIUMINT(8) UNSIGNED NOT NULL
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DELIMITER %%

CREATE FUNCTION `ConvertAuras`(`auras` VARCHAR(1024))
RETURNS VARCHAR(1024) CHARSET utf8
DETERMINISTIC
BEGIN
  DECLARE tmp VARCHAR(1024);
  DECLARE curr VARCHAR(10);
  DECLARE k INT;
  DECLARE pos INT;
  DECLARE startp INT;

  SET @k = 0;
  SET @tmp = '';
  SET @startp = 1;
  SET @pos = LOCATE(' ', auras);

  DELETE FROM temp_auras;

  WHILE @pos > 0 DO
    IF @k = 0 THEN
      SET @curr = SUBSTR(auras, @startp, @pos - @startp);

      IF NOT EXISTS(SELECT spell FROM temp_auras WHERE spell = @curr) THEN
        SET @tmp = CONCAT(@tmp, @curr, ' ');
        INSERT INTO temp_auras VALUES(@curr);
      END IF;
    END IF;

    SET @k = 1-@k;
    SET @startp = @pos+1;
    SET @pos = LOCATE(' ', auras, @startp);
  END WHILE;

  SET @tmp = RTRIM(@tmp);
  RETURN @tmp;
END%%

DELIMITER ;

UPDATE `creature_addon` SET `auras` = REPLACE(`auras`, '  ', ' ');
UPDATE `creature_addon` SET `auras` = TRIM(`auras`);
UPDATE `creature_addon` SET `auras` = NULL WHERE `auras` = '';
UPDATE `creature_addon` SET `auras` = ConvertAuras(`auras`) WHERE `auras` IS NOT NULL;

DROP FUNCTION `ConvertAuras`;
DROP TABLE `temp_auras`;