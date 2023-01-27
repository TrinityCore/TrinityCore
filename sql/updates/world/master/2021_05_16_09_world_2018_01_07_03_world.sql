-- 
DELETE FROM `linked_respawn` WHERE `guid`=137752 AND `linkedguid`=137752 AND `linkType`=0;
UPDATE `trinity_string` SET `content_default`='NPC currently selected by player:
Name: %s
SpawnID: %s.
GUID: %s.
Entry: %u.
Faction: %u.
NPC Flags: %s.
DisplayID: %u (Native: %u).' WHERE `entry`=539;
