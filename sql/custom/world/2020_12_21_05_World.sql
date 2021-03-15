-- more creature fixes

UPDATE `creature` SET `MovementType` = 0 WHERE `GUID` IN (142510, 142534, 142553);
UPDATE `creature` SET `phaseid` = 0 WHERE `phaseid` = 403;