SET @JOVAAN := 21633; -- Deathbringer Jovaan
SET @TRIGGER := 4548; -- Smart Trigger
SET @DEVICE := 184833;-- Legion Communication Device
SET @GO_INFERNAL := 184834;-- Gobject that needs to be despawned during the script
SET @GO_INFERNAL2 := 184835;-- Gobject that needs to be despawned during the script
SET @EVENTID := 13852; -- From spell_dbc id 37492

DELETE FROM event_scripts WHERE id =@EVENTID;
INSERT INTO event_scripts (id, command, datalong, datalong2, x, y, z, o) VALUES
(@EVENTID, 10, @JOVAAN, 57000, -3310.995, 2951.892, 171.2171, 5.5355);

DELETE FROM areatrigger_scripts WHERE entry=@TRIGGER;
DELETE FROM smart_scripts WHERE entryorguid=@TRIGGER AND source_type=2;

UPDATE gameobject_template SET AIName ='' WHERE entry =@DEVICE;
DELETE FROM smart_scripts WHERE source_type=1 AND entryorguid =@DEVICE;

DELETE FROM smart_scripts WHERE entryorguid=@JOVAAN AND source_type=0;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@JOVAAN,0,0,1,11,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Spellcast Etheral Teleport'),
(@JOVAAN,0,1,2,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,14,25737,@GO_INFERNAL,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Set Data GO'),
(@JOVAAN,0,2,3,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,14,25738,@GO_INFERNAL2,0,0,0,0,0,'Deathbringer Jovaan - Just summoned Set Data GO'),
(@JOVAAN,0,3,0,61,0,100,0,0,0,0,0,53,0,@JOVAAN,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Start WP movement'),
(@JOVAAN,0,4,5,40,0,100,0,4,@JOVAAN,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Pause 45 seconds'),
(@JOVAAN,0,5,0,61,0,100,0,0,0,0,0,80,@JOVAAN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Run Script');
