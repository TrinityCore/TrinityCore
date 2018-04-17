UPDATE creature SET equipment_id=0 WHERE equipment_id IN (1,127);
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);