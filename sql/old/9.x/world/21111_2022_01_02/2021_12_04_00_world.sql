ALTER TABLE `areatrigger` ADD `ScriptName` varchar(64) NOT NULL DEFAULT '' AFTER `ShapeData5`;
ALTER TABLE `areatrigger_create_properties` ADD `ScriptName` varchar(64) NOT NULL DEFAULT '' AFTER `ShapeData5`;

UPDATE `areatrigger` SET `ScriptName`=COALESCE((SELECT att.`ScriptName` FROM `areatrigger_template` att WHERE att.`Id`=`AreaTriggerId` AND att.`IsServerSide`=`IsServerSide`), '');
UPDATE `areatrigger_create_properties` SET `ScriptName`=COALESCE((SELECT att.`ScriptName` FROM `areatrigger_template` att WHERE att.`Id`=`AreaTriggerId` AND att.`IsServerSide`=0), '');

ALTER TABLE `areatrigger_template` DROP `ScriptName`;
