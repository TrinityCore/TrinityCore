-- Remove Cursed Darkhound from spawn_group too 
DELETE FROM spawn_group WHERE `spawnType`=0 AND `spawnId`=45217;
