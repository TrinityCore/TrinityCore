UPDATE `trinity_string` SET `content_default`='Player |cffff0000%s|r kicked by |cffff0000%s|r. Reason: |cffff0000%s|r.' WHERE (`entry`='282');  
UPDATE `command` SET `help`='Syntax: .kick [$charactername] [$reason]\r\n\r\nKick the given character name from the world with or without reason. If no character name is provided then the selected player (except for yourself) will be kicked. If no reason is provided, default is \"No Reason\".' WHERE (`name`='kick');

