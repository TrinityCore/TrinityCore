-- Add spell target for Throw Ingredient
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51025;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `Comment`) VALUES
(13,1,51025,0,31,3,28240,0,0, 'Throw Ingredient can be casted on Finklestein''s Cauldron Bunny');
