--
UPDATE `gameobject_template` SET `ScriptName`='go_suppression_device' WHERE `entry`=179784;

-- Confirmed by classic sniffs, not changing faction results in an unusable gob
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=179784;
