DELETE FROM script_texts WHERE entry BETWEEN -1000305 and -1000293;
INSERT INTO script_texts (entry, content_default, type, comment) VALUES
(-1000293, 'In Nagrand, food hunt ogre!', 0, 'LUMP_SAY0'),
(-1000294, 'You taste good with maybe a little salt and pepper.', 0, 'LUMP_SAY1'),
(-1000295, 'OK, OK! Lump give up!', 0, 'LUMP_DEFEAT'),

(-1000296, 'Warning! Emergency shutdown process initiated by $N. Shutdown will complete in two minutes.', 2, 'npc_manaforge_control_console - EMOTE_START'),
(-1000297, 'Emergency shutdown will complete in one minute.', 2, 'npc_manaforge_control_console - EMOTE_60'),
(-1000298, 'Emergency shutdown will complete in thirty seconds.', 2, 'npc_manaforge_control_console - EMOTE_30'),
(-1000299, 'Emergency shutdown will complete in ten seconds.', 2, 'npc_manaforge_control_console - EMOTE_10'),
(-1000300, 'Emergency shutdown complete.', 2, 'npc_manaforge_control_console - EMOTE_COMPLETE'),
(-1000301, 'Emergency shutdown aborted.', 2, 'npc_manaforge_control_console - EMOTE_ABORT'),

(-1000302, 'Saeed is currently engaged or awaiting orders to engage. You may check directly east of me and see if Saeed is ready for you. If he is not present then he is off fighting another battle. I recommend that you wait for him to return before attacking Dimensius.', 4, 'npc_professor_dabiri - WHISPER_DABIRI'),

(-1000303, 'is very weak', 2, 'mob_phase_hunter - EMOTE_WEAK'),

(-1000304, 'Bessy, is that you?', 0, 'npc_bessy- SAY_THADELL_1'),
(-1000305, 'Thank you for bringing back my Bessy, $N. I couldn\'t live without her!', 0, 'npc_bessy- SAY_THADELL_2');

