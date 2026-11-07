UPDATE `areatrigger` SET `AreaTriggerCreatePropertiesId`=45 WHERE `SpawnId`=56;
UPDATE `areatrigger` SET `SpawnId`=57, `AreaTriggerCreatePropertiesId`=45 WHERE `SpawnId`=100001;
UPDATE `areatrigger_create_properties` SET `AreaTriggerId`=57 WHERE `Id`=45 AND `IsCustom`=1;
UPDATE `areatrigger_create_properties_polygon_vertex` SET `AreaTriggerCreatePropertiesId`=45 WHERE `AreaTriggerCreatePropertiesId`=100000 AND `IsCustom`=1;
