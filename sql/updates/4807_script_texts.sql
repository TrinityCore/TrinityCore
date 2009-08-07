DELETE FROM script_texts WHERE entry IN(-1590000,-1590001,-1590002);
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1590000, 'Emalon the Storm Watcher overcharges a Tempest Minion!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 3, 0, 0, 'emalon EMOTE_OVERCHARGE_TEMPEST_MINION'),
(-1590001, 'A Tempest Minion appears to defend Emalon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 3, 0, 0, 'emalon EMOTE_MINION_RESPAWN'),
(-1590002, 'Archavon the Stone Watcher goes into a berserker rage!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 2, 0, 0, 'archavon EMOTE_BERSERK');
