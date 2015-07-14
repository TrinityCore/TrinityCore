--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (13410, 13411);
UPDATE `quest_template_addon` SET `AllowableClasses`=32 WHERE `id` IN (13410, 13411);
