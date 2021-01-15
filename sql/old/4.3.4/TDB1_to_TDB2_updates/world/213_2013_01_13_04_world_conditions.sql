SET @EYE := 193058;
SET @MIRROR_SPELL := 57528;
SET @MIRROR_NPC := 31005;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = @EYE;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13,17) AND `SourceEntry`=@MIRROR_SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22,1,@EYE,1,0,9,0,13168,0,0,0,0,'','Execute SAI line only if player has quest active'),
(17,0,@MIRROR_SPELL,0,0,31,0,3,@MIRROR_NPC,0,0,0,'','Spell target Mirror npc');
