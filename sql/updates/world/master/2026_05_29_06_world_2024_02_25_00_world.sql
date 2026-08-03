-- Fix wrong quest item condition for Dr. Terrible's "Building a Better Flesh Giant"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup` = 30409 AND `SourceEntry` = 42772;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 30409, 42772, 0, 0, 47, 0, 13042, 74, 0, 0, 0, 0, '', 'Dr. Terribles "Building a Better Flesh Giant" only drops if player has state_mask 74 Deep in the Bowels of The Underhalls'),
(1, 30409, 42772, 0, 0, 2, 0, 42772, 1, 1, 1, 0, 0, '', 'Dr. Terribles "Building a Better Flesh Giant" will drop only if the player doesn\'t have it already');
