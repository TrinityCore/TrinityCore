/* cs_debug.cpp */

SET @id = 300;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'debug';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'debug anim';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'debug areatriggers';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'debug arena';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'debug bg';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'debug entervehicle';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'debug getitemstate';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'debug getitemvalue';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'debug getvalue';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'debug hostil';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'debug itemexpire';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'debug lootrecipient';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'debug los';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'debug mod32value';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'debug moveflags';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'debug play';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'debug play cinematics';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'debug play movie';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'debug play sound';
UPDATE `command` SET `permission` = @id+19 WHERE `name` = 'debug send';
UPDATE `command` SET `permission` = @id+20 WHERE `name` = 'debug send buyerror';
UPDATE `command` SET `permission` = @id+21 WHERE `name` = 'debug send channelnotify';
UPDATE `command` SET `permission` = @id+22 WHERE `name` = 'debug send chatmessage';
UPDATE `command` SET `permission` = @id+23 WHERE `name` = 'debug send equiperror';
UPDATE `command` SET `permission` = @id+24 WHERE `name` = 'debug send largepacket';
UPDATE `command` SET `permission` = @id+25 WHERE `name` = 'debug send opcode';
UPDATE `command` SET `permission` = @id+26 WHERE `name` = 'debug send qinvalidmsg';
UPDATE `command` SET `permission` = @id+27 WHERE `name` = 'debug send qpartymsg';
UPDATE `command` SET `permission` = @id+28 WHERE `name` = 'debug send sellerror';
UPDATE `command` SET `permission` = @id+29 WHERE `name` = 'debug send setphaseshift';
UPDATE `command` SET `permission` = @id+30 WHERE `name` = 'debug send spellfail';
UPDATE `command` SET `permission` = @id+31 WHERE `name` = 'debug setaurastate';
UPDATE `command` SET `permission` = @id+32 WHERE `name` = 'debug setbit';
UPDATE `command` SET `permission` = @id+33 WHERE `name` = 'debug setitemvalue';
UPDATE `command` SET `permission` = @id+34 WHERE `name` = 'debug setvalue';
UPDATE `command` SET `permission` = @id+35 WHERE `name` = 'debug setvid';
UPDATE `command` SET `permission` = @id+36 WHERE `name` = 'debug spawnvehicle';
UPDATE `command` SET `permission` = @id+37 WHERE `name` = 'debug threat';
UPDATE `command` SET `permission` = @id+38 WHERE `name` = 'debug update';
UPDATE `command` SET `permission` = @id+39 WHERE `name` = 'debug uws';
UPDATE `command` SET `permission` = @id+40 WHERE `name` = 'wpgps';
