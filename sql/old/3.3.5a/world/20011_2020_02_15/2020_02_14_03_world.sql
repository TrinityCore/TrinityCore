-- Cat Figurine SAI
SET @ENTRY := 13873;
UPDATE `gameobject_template` SET `AIName`="", `ScriptName`='' WHERE `entry`=@ENTRY;
