--
UPDATE `gameobject` SET `phaseMask`=`phaseMask`|4 WHERE `guid` IN (151102,151103,151104,151105,151106) AND `id` IN (202184,202347,202348,202349,202350);
UPDATE `creature` SET `phaseMask`=`phaseMask`|4|256 WHERE `guid`=79368 AND `id`=6491;
