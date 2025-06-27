--
UPDATE `quest_template_addon` SET `SpecialFlags` = 1 WHERE `Id` = 13845;
DELETE FROM `conditions` WHERE `SourceEntry` = 46004 AND `SourceTypeOrReferenceId` = 10;
