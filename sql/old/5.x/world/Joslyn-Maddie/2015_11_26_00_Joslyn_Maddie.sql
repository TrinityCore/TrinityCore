
-- Fix chi-ji not being interuptable.

UPDATE `creature_template` SET `mechanic_immune_mask` = 752828415  WHERE `entry` = 71952 ;



-- makes the Beacon bunny actually cast beacon for more than half a second, to lazy for a real fix.

INSERT INTO `creature_template_addon` 
	SET
	`entry` = '71978' , 
	`path_id` = '0' , 
	`mount` = '0' , 
	`bytes1` = '0' , 
	`bytes2` = '0' , 
	`emote` = '0' , 
	`auras` = '144474';
	
	
