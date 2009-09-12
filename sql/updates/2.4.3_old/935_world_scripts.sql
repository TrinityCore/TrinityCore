DELETE FROM `creature` WHERE `id`='17653';

UPDATE `gameobject_template` SET `flags`='4' WHERE `entry` IN ('181766','181823');
UPDATE `gameobject` SET `SpawnMask`='3',`state`='1' WHERE `id` IN ('181766','181823');

UPDATE `instance_template` SET `script`='instance_blood_furnace' WHERE `map`=542;
