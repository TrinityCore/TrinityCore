-- NPC entry 29665 (Pazik "The Pick" Prylock), 29725 (Benik Boltshear) and 29728 (Walter Soref)
SET @MENU_ID := 9823;
SET @Pazik  := 29665;
SET @Benik  := 29725;
SET @Walter := 29728;

UPDATE `creature_template` SET `npcflag`=(`npcflag`&~1) WHERE `entry` IN (@Benik,@Pazik,@Walter);
UPDATE `creature` SET `npcflag`=(`npcflag`&~1) WHERE `id` IN (@Benik,@Pazik,@Walter);

UPDATE `creature_template` SET `AIName` = '', `ScriptName`= ''  WHERE `entry` IN (@Pazik,@Benik,@Walter);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (@Pazik,@Benik,@Walter);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= @MENU_ID;
