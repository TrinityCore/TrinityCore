-- conditions for spells used by Malygos
DELETE FROM `conditions` WHERE `SourceGroup`=0 AND `SourceEntry` IN (56263,55853,56505,56429,56152) AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (SourceTypeOrReferenceId,ConditionTypeOrReference,SourceGroup,SourceEntry,ConditionValue1,ConditionValue2) VALUES 
(13,18,0,55853,1,30090),
(13,18,0,56263,1,30090),
(13,18,0,56505,1,30334),
(13,18,0,56429,1,30334),
(13,18,0,56152,1,28859);
