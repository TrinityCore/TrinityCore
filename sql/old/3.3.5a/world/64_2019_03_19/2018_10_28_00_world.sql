-- Describe distance command argument
UPDATE `command` SET `help`='Syntax: .distance [link]\r\n\r\nDisplay the distance from your character to the selected unit or given creature, player or gameobject.' WHERE  `name`='distance';
-- Repurpose existing trinity_string for rotation info string
UPDATE `trinity_string` SET `content_default`='yaw: %f pitch: %f roll: %f' WHERE  `entry`=5074;
