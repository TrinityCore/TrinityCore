-- The Thunderspike
UPDATE `gameobject_template` SET `AIName`='',`ScriptName`='go_thunderspike',`data3`=0 WHERE `entry`=184729; -- data3 was `event_scripts`.`id`
DELETE FROM `event_scripts` WHERE `id`=13685;
