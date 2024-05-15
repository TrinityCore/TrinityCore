-- Fix some dberrors
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (43202,43203);
