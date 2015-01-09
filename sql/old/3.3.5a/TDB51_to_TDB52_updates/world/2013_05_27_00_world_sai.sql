SET @SPELL := 31696;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry`=@SPELL;
