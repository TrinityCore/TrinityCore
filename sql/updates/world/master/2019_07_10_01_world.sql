-- 
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `map` IN (648) AND `guid`<389369);
DELETE FROM `creature` WHERE `map` IN (648) AND `guid`<389369;
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `map` IN (648) AND `guid`<238547);
DELETE FROM `gameobject` WHERE `map` IN (648) AND `guid`<238547;
