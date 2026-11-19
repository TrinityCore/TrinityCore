RENAME TABLE `spell_areatrigger` TO `areatrigger_create_properties`;
RENAME TABLE `spell_areatrigger_circular` TO `areatrigger_create_properties_orbit`;
RENAME TABLE `spell_areatrigger_splines` TO `areatrigger_create_properties_spline_point`;
RENAME TABLE `spell_areatrigger_vertices` TO `areatrigger_create_properties_polygon_vertex`;

ALTER TABLE `areatrigger_create_properties`
  CHANGE `SpellMiscId` `Id` int(10) unsigned NOT NULL,
  ADD `Shape` tinyint(0) UNSIGNED NOT NULL DEFAULT '0' AFTER `TimeToTargetScale`,
  ADD `ShapeData0` float NOT NULL DEFAULT '0' AFTER `Shape`,
  ADD `ShapeData1` float NOT NULL DEFAULT '0' AFTER `ShapeData0`,
  ADD `ShapeData2` float NOT NULL DEFAULT '0' AFTER `ShapeData1`,
  ADD `ShapeData3` float NOT NULL DEFAULT '0' AFTER `ShapeData2`,
  ADD `ShapeData4` float NOT NULL DEFAULT '0' AFTER `ShapeData3`,
  ADD `ShapeData5` float NOT NULL DEFAULT '0' AFTER `ShapeData4`;

ALTER TABLE `areatrigger_create_properties_orbit`
  CHANGE `SpellMiscId` `AreaTriggerCreatePropertiesId` int(10) unsigned NOT NULL;

ALTER TABLE `areatrigger_create_properties_spline_point`
  CHANGE `SpellMiscId` `AreaTriggerCreatePropertiesId` int(10) unsigned NOT NULL;

ALTER TABLE `areatrigger_create_properties_polygon_vertex`
  CHANGE `SpellMiscId` `AreaTriggerCreatePropertiesId` int(10) unsigned NOT NULL;

ALTER TABLE `areatrigger`
  ADD `Shape` tinyint(0) UNSIGNED NOT NULL DEFAULT '0' AFTER `PhaseGroup`,
  ADD `ShapeData0` float NOT NULL DEFAULT '0' AFTER `Shape`,
  ADD `ShapeData1` float NOT NULL DEFAULT '0' AFTER `ShapeData0`,
  ADD `ShapeData2` float NOT NULL DEFAULT '0' AFTER `ShapeData1`,
  ADD `ShapeData3` float NOT NULL DEFAULT '0' AFTER `ShapeData2`,
  ADD `ShapeData4` float NOT NULL DEFAULT '0' AFTER `ShapeData3`,
  ADD `ShapeData5` float NOT NULL DEFAULT '0' AFTER `ShapeData4`;

UPDATE `areatrigger_create_properties` `acp`
  LEFT JOIN `areatrigger_template` `at` ON `acp`.`AreaTriggerId`=`at`.`Id` AND `at`.`IsServerSide`=FALSE
  SET `acp`.`Shape`=`at`.`Type`,
    `acp`.`ShapeData0`=`at`.`Data0`,
    `acp`.`ShapeData1`=`at`.`Data1`,
    `acp`.`ShapeData2`=`at`.`Data2`,
    `acp`.`ShapeData3`=`at`.`Data3`,
    `acp`.`ShapeData4`=`at`.`Data4`,
    `acp`.`ShapeData5`=`at`.`Data5`;

UPDATE `areatrigger` `a`
  LEFT JOIN `areatrigger_template` `at` ON `a`.`AreaTriggerId`=`at`.`Id` AND `at`.`IsServerSide`=TRUE
  SET `a`.`Shape`=`at`.`Type`,
    `a`.`ShapeData0`=`at`.`Data0`,
    `a`.`ShapeData1`=`at`.`Data1`,
    `a`.`ShapeData2`=`at`.`Data2`,
    `a`.`ShapeData3`=`at`.`Data3`,
    `a`.`ShapeData4`=`at`.`Data4`,
    `a`.`ShapeData5`=`at`.`Data5`;

DELETE FROM `areatrigger_template` WHERE `Id`=0 AND `IsServerSide`=FALSE;
