-- was "NPC currently selected by player: DB GUID: %u, current GUID: %u. Faction: %u..."
UPDATE `trinity_string` SET `content_default` = 'NPC currently selected by player: DB GUID: %u, %s. Faction: %u. npcFlags: %u. Entry: %u. DisplayID: %u (Native: %u).' WHERE `entry` = 539;
