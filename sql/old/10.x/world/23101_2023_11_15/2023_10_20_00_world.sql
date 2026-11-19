-- 
UPDATE `areatrigger` SET `ShapeData3`=`ShapeData0`, `ShapeData4`=`ShapeData1`, `ShapeData5`=`ShapeData2` WHERE `IsServerSide`=1 AND `AreaTriggerId` IN(1, 2);
UPDATE `areatrigger_template` SET `Data3`=`Data0`, `Data4`=`Data1`, `Data5`=`Data2` WHERE `IsServerSide`=1 AND `Id` IN(1, 2);
