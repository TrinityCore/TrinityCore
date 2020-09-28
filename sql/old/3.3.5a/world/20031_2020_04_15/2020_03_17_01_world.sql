-- 
UPDATE `gameobject` SET `state`=1 WHERE `guid` IN (75162,75165);
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry` IN (179364,179365,179115,179117,176966,179116,176964);
DELETE FROM `gameobject` WHERE `guid` IN (7226,7228,7227,7229);
DELETE FROM `gameobject_addon` WHERE `guid` IN (7226,7228,7227,7229);
